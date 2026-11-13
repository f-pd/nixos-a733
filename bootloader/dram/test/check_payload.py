#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-2.0-or-later
"""Check that nothing here carries bytes of the PHY firmware payload.

usage: check_payload.py <boot0 file> <file or directory>...

boot0 is used only as the opaque source of the payload, at the offsets the
specification gives. Every file is searched, as it is, for runs of payload
bytes; pass the built library to cover the tables as the compiler lays them
out. A run counts when it is WINDOW bytes long and not trivial (few distinct
byte values, as in padding or zero fill). The longest run of register values
of the reference scripts that also occurs in the payload by coincidence is 18
bytes, so the window is above that.
"""
import os
import sys

PAYLOAD_OFFSET, PAYLOAD_END = 0x196B0, 0x3AE98
WINDOW = 32
MIN_DISTINCT = 8


def files(paths):
    for p in paths:
        if os.path.isdir(p):
            for root, _, names in os.walk(p):
                for n in sorted(names):
                    yield os.path.join(root, n)
        elif os.path.exists(p):
            yield p


def main():
    payload = open(sys.argv[1], "rb").read()[PAYLOAD_OFFSET:PAYLOAD_END]
    windows = set()
    for i in range(len(payload) - WINDOW + 1):
        w = payload[i:i + WINDOW]
        if len(set(w)) >= MIN_DISTINCT:
            windows.add(w)

    bad = 0
    count = 0
    for path in files(sys.argv[2:]):
        data = open(path, "rb").read()
        count += 1
        for i in range(len(data) - WINDOW + 1):
            if data[i:i + WINDOW] in windows:
                print("FAIL %s: %d payload bytes at offset %d" % (path, WINDOW, i))
                bad += 1
                break
    if bad:
        sys.exit(1)
    print("PASS no payload bytes in %d files (window %d bytes)" % (count, WINDOW))


if __name__ == "__main__":
    main()
