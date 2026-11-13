#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-3.0-or-later
"""Expand an operation script (ops-*.tsv) into the flat list of register writes it stands for.

usage: expand_ops.py ops-12g.tsv path/to/boot0_sdcard_orangepizero3w.fex > expected.txt

Output: one line per write, "<absolute address hex> <size in bytes> <value hex>", in order.
The boot0 file is used only as the source of the PHY payload (see docs/dram-init-spec.md).
"""
import sys, hashlib

BASES = {"PHY": 0x0A900000, "CTL0": 0x0A100000, "CTL1": 0x0A500000, "GLUE": 0x0A020000,
         "CCU": 0x02002000, "SYS2": 0x02020000, "SYSCFG": 0x03000000, "PRCM": 0x07010000, "ABS": 0}
PAYLOAD_OFFSET, PAYLOAD_END = 0x196B0, 0x3AE98
PAYLOAD_SHA256 = "a05762aeb0b42c09a2c09d473490325b1445ef97fda0535c28afcdb34507a25a"

def absaddr(block, off):
    return BASES[block] + (off << 1 if block == "PHY" else off)

def main():
    ops, boot0 = sys.argv[1], sys.argv[2]
    payload = open(boot0, "rb").read()[PAYLOAD_OFFSET:PAYLOAD_END]
    if hashlib.sha256(payload).hexdigest() != PAYLOAD_SHA256:
        sys.exit("payload sha256 mismatch: wrong boot0 file")
    out = sys.stdout
    with open(ops) as f:
        next(f)
        for line in f:
            op, block, addr, value, extra = (line.rstrip("\n").split("\t") + [""] * 5)[:5]
            if op in ("W16", "W32"):
                out.write("%08x %d %x\n" % (absaddr(block, int(addr, 16)), int(op[1:]) // 8, int(value, 16)))
            elif op in ("RMW16", "RMW32"):
                written = [t for t in extra.split() if t.startswith("written=")][0][8:]
                out.write("%08x %d %x\n" % (absaddr(block, int(addr, 16)), int(op[3:]) // 8, int(written, 16)))
            elif op == "ZERO16":
                a = int(addr, 16)
                for i in range(int(value)):
                    out.write("%08x 2 0\n" % absaddr(block, a + i))
            elif op == "LOAD16":
                a = int(addr, 16); off = int(extra.split("+")[1], 16)
                for i in range(int(value)):
                    out.write("%08x 2 %x\n" % (absaddr(block, a + i), int.from_bytes(payload[off + 2 * i:off + 2 * i + 2], "little")))

if __name__ == "__main__":
    main()
