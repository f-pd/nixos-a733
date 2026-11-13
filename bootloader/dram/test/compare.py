#!/usr/bin/env python3
# SPDX-License-Identifier: GPL-2.0-or-later
"""Compare a harness run with a reference operation script.

usage: compare.py <ops-*.tsv> <boot0 file> <harness output>

Two comparisons, both stop at the first difference:
 1. the register writes against the output of docs/dram-init/expand_ops.py;
 2. writes, delays, PMIC calls and the return value, in order, against the
    events the script lists.
"""
import os
import subprocess
import sys


def script_events(path):
    """Events of a script in order; a write is only marked, not expanded."""
    events = []
    phase = ""
    with open(path) as f:
        next(f)
        for lineno, line in enumerate(f, 2):
            op, block, addr, value, extra = (line.rstrip("\n").split("\t") + [""] * 5)[:5]
            where = "%s:%d (%s)" % (os.path.basename(path), lineno, phase)
            if op == "PHASE":
                phase = block
            elif op == "DELAY":
                events.append(("D %d" % int(value), where))
            elif op == "PMIC":
                events.append(("P %s %d" % (block, int(value)), where))
            elif op == "END":
                ret = [t for t in (block, addr, value, extra) if t.startswith("ret=")][0]
                events.append(("R %d" % int(ret[4:]), where))
            elif op in ("W16", "W32", "RMW16", "RMW32"):
                events.append(("W", where))
            elif op in ("LOAD16", "ZERO16"):
                events += [("W", where)] * int(value)
    return events


def first_difference(kind, expected, actual, where):
    for i, (e, a) in enumerate(zip(expected, actual)):
        if e != a:
            return "%s %d differs at %s:\n  expected %s\n  actual   %s" % (
                kind, i + 1, where(i), e, a)
    if len(expected) != len(actual):
        i = min(len(expected), len(actual))
        return "%s count differs: expected %d, actual %d; first extra at %s" % (
            kind, len(expected), len(actual), where(i))
    return None


def main():
    ops, boot0, run = sys.argv[1:4]
    here = os.path.dirname(os.path.abspath(__file__))
    expand = os.path.join(here, "..", "..", "..", "docs", "dram-init", "expand_ops.py")

    expected_writes = subprocess.run(
        [sys.executable, expand, ops, boot0], check=True,
        capture_output=True, text=True).stdout.splitlines()
    actual = open(run).read().splitlines()
    actual_writes = [l[2:] for l in actual if l.startswith("W ")]

    events = script_events(ops)
    write_where = [w for e, w in events if e == "W"]

    def where_write(i):
        return write_where[i] if i < len(write_where) else "end of script"

    err = first_difference("write", expected_writes, actual_writes, where_write)
    if err:
        sys.exit("FAIL %s\n%s" % (os.path.basename(ops), err))

    # Same again with delays, PMIC calls and the return value in place.
    it = iter(expected_writes)
    expected_events = [("W " + next(it)) if e == "W" else e for e, w in events]

    def where_event(i):
        return events[i][1] if i < len(events) else "end of script"

    err = first_difference("event", expected_events, actual, where_event)
    if err:
        sys.exit("FAIL %s\n%s" % (os.path.basename(ops), err))

    others = len(actual) - len(actual_writes)
    print("PASS %s: %d writes; %d delays, PMIC calls and return value" % (
        os.path.basename(ops), len(actual_writes), others))


if __name__ == "__main__":
    main()
