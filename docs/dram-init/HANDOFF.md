# Handoff: clean-room DRAM init for the Allwinner A733

This is the brief for whoever implements our own DRAM initialisation for the Orange Pi Zero 3W.
It is written by the side that analysed the vendor binaries. The implementer has not seen them
and must keep it that way.

## What to build

A DRAM initialisation library for the A733 that performs the sequence described in
`docs/dram-init-spec.md`, for the four memory fits of the Orange Pi Zero 3W, and a host-side
test that proves it issues the same register writes as the reference scripts.

Scope of this piece of work:

- `bootloader/dram/`: the library, in freestanding C (C11, `stdint.h` and `stddef.h` only), with
  no dependency on U-Boot headers so that it builds and runs on a workstation.
- A platform interface the library calls, supplied by the user of the library: 16- and 32-bit
  register read and write, a wait-for-condition primitive, a microsecond delay, a function to
  set a PMIC rail in mV, a logging function, and a function returning the strap index.
- The PHY payload is passed in as a pointer and a length. It is never part of the source tree.
- Selection of the parameter block from the strap index; power; clocks; controller setup; the
  PHY configuration; firmware load; the mailbox; post-training steps; the timing adjustment
  after training (by its formulas, not by copying script values); DFI handover; read-back; size
  computation; the memory test; the return value in MiB.
- `bootloader/dram/test/`: a harness with a register model as in "Reference model" of the spec,
  which runs the library for each memory fit, records every write as
  `<address hex> <size> <value hex>`, and compares it with the output of
  `docs/dram-init/expand_ops.py` for `ops-4g.tsv`, `ops-6g.tsv`, `ops-8g.tsv` and `ops-12g.tsv`.
  One command runs all four and fails on the first difference. Delays and PMIC calls are
  checked against the scripts too.
- A short `bootloader/dram/README.md`: layout, how to run the test, what is and is not verified.

Not in scope: the U-Boot SPL board port and the glue that calls the library from it, LPDDR4,
single-channel operation, the rank and size scan, and anything that needs the board.

## Rules

1. Work only from `docs/dram-init-spec.md`, the files in `docs/dram-init/` (not
   `docs/dram-init/method/`, which is the analysis tooling and is of no use to you), the rest of
   this repository, and public sources: the U-Boot and TF-A drivers for the Synopsys PHY, NXP's
   i.MX 95 OEI, JEDEC LPDDR5 documents, Allwinner's published `spl-pub` code.
2. Do not disassemble, decompile, emulate or otherwise inspect `boot0` or `ddr.bin`, and do not
   look for or read analysis output of them anywhere on this machine. In particular, stay out of
   `/home/fulgidus/Documents/a733-re`.
3. The boot0 file in `vendor/blobs/` may be used for one thing: as the opaque source of the
   payload bytes for the test, through `expand_ops.py` and the offsets the spec gives.
4. Write the code as a driver, not as a replay of the script: named steps, loops over channels,
   byte lanes and Pstates, tables for what is tabular. Values that the spec derives from
   parameters or from frequency should be computed where the spec gives the rule; where it
   does not, per-fit tables taken from the scripts are acceptable, and the README lists them as
   such.
5. If the spec is unclear or seems wrong, do not guess from the scripts in a way that hides
   the gap: record the question in `bootloader/dram/README.md` under "Open questions".
6. Licence of the new code: GPL-2.0-or-later, with SPDX headers, so that it can be used from
   U-Boot. No vendor code, no vendor comments, no firmware bytes in the tree.

## Acceptance

- The four comparisons pass: the library's writes equal the expanded scripts, in order and in
  value, for 4, 6, 8 and 12 GiB.
- The library builds warning-free with `-Wall -Wextra -Werror` for the host, and for
  `arm-none-eabi` or `aarch64` if a cross compiler is at hand (not required).
- No file added contains bytes of the payload.

Passing the comparison shows equivalence with the vendor driver under the reference model. It
does not show that DRAM trains on the board: say so in the README.

## Practical notes

- Start from branch `feature/dram-init-spec`; work on `feature/dram-init`.
- Commit messages follow the style of `git log`. No attribution lines of any kind.
- This machine has no global git identity. Use the identity of the existing commits for your
  commits (`git log -1 --format='%an <%ae>'`), passed with `git -c user.name=… -c user.email=…`,
  without changing any git configuration.
- Do not push, do not merge into `develop`, do not open a pull request. Report when the test
  passes; the analysis side reviews and merges.
- A C compiler and Python 3 are available. Nix is not installed on this machine.
