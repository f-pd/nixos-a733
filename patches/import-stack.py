#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-2.0-or-later
"""Vendor a kernel patch stack into patches/.

Usage: import-stack.py <checkout of the stack> [--check <kernel tree>]

The stack is a directory with patches/series naming one patch per line, as
https://github.com/DockSeed/a7s-linux-mainline has it. Every patch is copied
unchanged to patches/base/ or patches/optional/ under a numbered name that
keeps the order of the series, and patches/index.json is rewritten: the
imported entries first, then the entries of local/ (our own patches, kept
as they are).

Which series go to the optional layer is the list OPTIONAL below. The build
applies all base patches and then all optional ones, so an optional patch
must not be needed by a later base patch. --check applies the two layers in
that order to a kernel tree (a scratch git checkout of the pinned release)
and fails on the first patch that does not apply.
"""

import json
import os
import re
import shutil
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))

# Series directories of the stack that are not needed to boot, reach the
# network or use storage: display, GPU, video, camera, NPU, audio.
OPTIONAL = {
    "a733-ccu-audio",
    "a733-audio",
    "a733-audio-pll-boot",
    "a733-ccu-audio-rates",
    "sun4i-i2s-pause",
    "sun4i-i2s-h6-cache",
    "sun4i-i2s-clk-rate",
    "a733-ccu-gpu",
    "a733-ccu-gpu-pll",
    "pvr-recovery",
    "a733-gpu",
    "a733-gpu-opp",
    "a733-pck600-gpu-core",
    "a733-display",
    "a733-dp",
    "a733-dp-attach",
    "a733-dp-usb",
    "a733-dp-audio",
    "a733-display-s2idle",
    "a733-de-iommu",
    "a733-de-vi1",
    "a733-mixer-blend",
    "a733-ccu-edp-tv",
    "sun4i-drm-teardown",
    "sun4i-tv-defer",
    "sun4i-crtc-disable-planes",
    "drm-dp-crc-stop",
    "a733-npu",
    "etnaviv-unbind-flop",
    "etnaviv-remove-rpm",
    "a733-ve-base",
    "a733-g2d-base",
    "a733-di-base",
    "a733-csi-isp-base",
    # Not multimedia, but written on top of the series above: their hunks
    # need the context those leave, so they cannot be in the base layer.
    "a733-crypto-engine",
    "a733-eeprom-a7s",
    "a733-adc",
    "a733-header",
    "a733-a7s-bank-supplies-2",
}


def read_series(stack):
    with open(os.path.join(stack, "patches", "series")) as f:
        return [l.strip() for l in f if l.strip() and not l.startswith("#")]


def subject(path):
    with open(path, errors="replace") as f:
        text = f.read(8192)
    m = re.search(r"^Subject: (.*(?:\n[ \t].*)*)", text, re.M)
    s = re.sub(r"\s+", " ", m.group(1)) if m else os.path.basename(path)
    return re.sub(r"^\[PATCH[^\]]*\]\s*", "", s)


def main():
    args = sys.argv[1:]
    check = None
    if "--check" in args:
        i = args.index("--check")
        check = args[i + 1]
        del args[i : i + 2]
    if len(args) != 1:
        sys.exit(__doc__)
    stack = args[0]

    url = subprocess.check_output(
        ["git", "-C", stack, "remote", "get-url", "origin"], text=True
    ).strip()
    url = re.sub(r"\.git$", "", url)
    commit = subprocess.check_output(
        ["git", "-C", stack, "rev-parse", "HEAD"], text=True
    ).strip()

    index_path = os.path.join(HERE, "index.json")
    with open(index_path) as f:
        old = json.load(f)["patches"]
    local = [e for e in old if not e.get("stack")]
    for e in old:
        if e.get("stack"):
            os.remove(os.path.join(HERE, e["layer"], e["file"]))

    entries = []
    for n, rel in enumerate(read_series(stack), 1):
        series, name = rel.split("/", 1)
        layer = "optional" if series in OPTIONAL else "base"
        src = os.path.join(stack, "patches", rel)
        file = "%04d-%s--%s" % (n, series, name)
        os.makedirs(os.path.join(HERE, layer), exist_ok=True)
        shutil.copyfile(src, os.path.join(HERE, layer, file))
        entries.append(
            {
                "file": file,
                "layer": layer,
                "origin": "%s/blob/%s/patches/%s" % (url, commit, rel),
                "description": subject(src),
                "stack": series,
            }
        )

    patches = entries + local
    with open(index_path, "w") as f:
        json.dump({"patches": patches}, f, indent=2, ensure_ascii=False)
        f.write("\n")
    print(
        "%d imported (%d base, %d optional), %d local"
        % (
            len(entries),
            sum(e["layer"] == "base" for e in entries),
            sum(e["layer"] == "optional" for e in entries),
            len(local),
        )
    )

    if check:
        failed = 0
        for layer in ("base", "optional"):
            for e in patches:
                if e["layer"] != layer:
                    continue
                p = os.path.join(HERE, layer, e["file"])
                r = subprocess.run(
                    ["patch", "-p1", "--batch", "--forward", "--silent", "-i", p],
                    cwd=check,
                    capture_output=True,
                    text=True,
                )
                if r.returncode:
                    failed += 1
                    print("FAIL %s/%s\n%s" % (layer, e["file"], r.stdout[:400]))
                    if layer == "base":
                        sys.exit(1)
        print("check: %d optional patches do not apply" % failed)
        sys.exit(1 if failed else 0)


if __name__ == "__main__":
    main()
