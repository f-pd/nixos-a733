#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Check the layout of the mainline firmware image for A733 boards.

usage: check-firmware.py <u-boot-sunxi-with-spl.bin> [--header-only]

The file is written to the card at 128 KiB. Checked:
 - the eGON header the boot ROM reads: magic, length, checksum, and the SPL
   signature U-Boot adds;
 - the SPL is small enough to be loaded over FEL as well;
 - the FIT image sits where the SPL looks for it, 0x4a000 into the file;
 - the FIT holds U-Boot and BL31 at their load addresses, BL31 is entered
   first, and there is no SCP image;
 - the file ends before the first partition.

--header-only checks just the eGON header, for any eGON image.
"""
import struct
import sys

SD_OFFSET = 128 * 1024              # where the file goes on the card
FIRST_PARTITION = 32 * 1024 * 1024  # sdImage.firmwarePartitionOffset
EGON_STAMP = 0x5F0A6C39
SPL_LOAD_ADDR = 0x47000
FEL_SCRATCH_ADDR = 0x71000          # sunxi-fel keeps its own data from here
FIT_OFFSET = 0x4A000
UBOOT_LOAD = 0x4A000000
BL31_LOAD = 0x40000000

FDT_MAGIC = 0xD00DFEED
FDT_BEGIN_NODE, FDT_END_NODE, FDT_PROP, FDT_NOP, FDT_END = 1, 2, 3, 4, 9

errors = []


def check(ok, text):
    print(("ok    " if ok else "FAIL  ") + text)
    if not ok:
        errors.append(text)


def egon(data):
    """Check the eGON header at the start of data; return the SPL length."""
    magic = data[4:12]
    check(magic == b"eGON.BT0", "eGON magic (%r)" % magic)
    stored, length = struct.unpack_from("<II", data, 12)
    check(0 < length <= len(data) and length % 4 == 0,
          "SPL length 0x%x is inside the file" % length)
    if not 0 < length <= len(data) or length % 4:
        return 0
    words = struct.unpack_from("<%dI" % (length // 4), data, 0)
    total = (sum(words) - stored + EGON_STAMP) & 0xFFFFFFFF
    check(total == stored, "eGON checksum 0x%08x (computed 0x%08x)" % (stored, total))
    return length


def fdt_nodes(blob):
    """Flatten a device tree blob into {path: {property: bytes}}."""
    (magic, _total, off_struct, off_strings, _rsv, _ver, _comp, _cpu,
     _size_strings, _size_struct) = struct.unpack_from(">10I", blob, 0)
    assert magic == FDT_MAGIC
    nodes, path, pos = {}, [], off_struct
    while True:
        (token,) = struct.unpack_from(">I", blob, pos)
        pos += 4
        if token == FDT_BEGIN_NODE:
            end = blob.index(b"\0", pos)
            path.append(blob[pos:end].decode())
            nodes["/".join(path) or "/"] = {}
            pos = (end + 4) & ~3
        elif token == FDT_END_NODE:
            path.pop()
        elif token == FDT_PROP:
            length, nameoff = struct.unpack_from(">II", blob, pos)
            pos += 8
            end = blob.index(b"\0", off_strings + nameoff)
            name = blob[off_strings + nameoff:end].decode()
            nodes["/".join(path) or "/"][name] = blob[pos:pos + length]
            pos = (pos + length + 3) & ~3
        elif token == FDT_END:
            return nodes
        elif token != FDT_NOP:
            raise ValueError("bad device tree token %d" % token)


def cell(prop):
    return int.from_bytes(prop, "big")


def text(prop):
    return prop.rstrip(b"\0").decode()


def fit(data):
    magic, total = struct.unpack_from(">II", data, FIT_OFFSET)
    check(magic == FDT_MAGIC, "FIT image at 0x%x into the file" % FIT_OFFSET)
    if magic != FDT_MAGIC:
        return
    check(FIT_OFFSET + total <= len(data), "FIT structure (0x%x bytes) is inside the file" % total)
    nodes = fdt_nodes(data[FIT_OFFSET:FIT_OFFSET + total])
    images = {p.split("/")[2]: v for p, v in nodes.items()
              if p.startswith("/images/") and p.count("/") == 2}
    print("      FIT images: " + ", ".join(sorted(images)))

    check("uboot" in images and cell(images["uboot"].get("load", b"")) == UBOOT_LOAD,
          "U-Boot is loaded to 0x%x" % UBOOT_LOAD)
    atf = images.get("atf", {})
    check(cell(atf.get("load", b"")) == BL31_LOAD and cell(atf.get("entry", b"")) == BL31_LOAD,
          "BL31 is loaded to and entered at 0x%x" % BL31_LOAD)
    check("scp" not in images, "no SCP image")
    check(any(text(v.get("type", b"")) == "flat_dt" for v in images.values()),
          "a device tree for U-Boot")

    # External data: every image must lie inside the file.
    data_start = (FIT_OFFSET + total + 3) & ~3
    for name, props in sorted(images.items()):
        if "data-size" in props:
            off = cell(props.get("data-offset", b""))
            size = cell(props["data-size"])
            check(data_start + off + size <= len(data),
                  "image %s (0x%x bytes) is inside the file" % (name, size))
        else:
            check(len(props.get("data", b"")) > 0, "image %s has data" % name)

    configs = [v for p, v in nodes.items()
               if p.startswith("/configurations/") and p.count("/") == 2]
    check(bool(configs) and all(text(c.get("firmware", b"")) == "atf" for c in configs),
          "every configuration starts BL31 first")
    check(all("uboot" in text(c.get("loadables", b"")).split("\0") for c in configs),
          "every configuration loads U-Boot")


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    header_only = "--header-only" in sys.argv
    if len(args) != 1:
        sys.exit(__doc__)
    data = open(args[0], "rb").read()
    print("%s: %d bytes" % (args[0], len(data)))

    length = egon(data)
    if not header_only:
        check(data[0x14:0x17] == b"SPL", "SPL signature, header version %d" % data[0x17])
        check(SPL_LOAD_ADDR + length <= FEL_SCRATCH_ADDR,
              "SPL (0x%x bytes) ends below 0x%x: loadable over FEL, %d bytes to spare"
              % (length, FEL_SCRATCH_ADDR, FEL_SCRATCH_ADDR - SPL_LOAD_ADDR - length))
        check(length <= FIT_OFFSET, "SPL ends before the FIT image")
        fit(data)
        check(SD_OFFSET + len(data) <= FIRST_PARTITION,
              "ends at %d KiB on the card, before the first partition at %d KiB"
              % ((SD_OFFSET + len(data) + 1023) // 1024, FIRST_PARTITION // 1024))

    if errors:
        sys.exit("%d check(s) failed" % len(errors))
    print("all checks passed")


if __name__ == "__main__":
    main()
