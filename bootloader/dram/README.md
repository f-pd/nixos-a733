# DRAM initialisation for the Allwinner A733

Our own DRAM init for the Orange Pi Zero 3W (`SPEC.md` D2), written from
`docs/dram-init-spec.md` and the reference scripts in `docs/dram-init/`, without sight of the
vendor binaries. It covers what the Zero 3W uses: LPDDR5, two channels, two ranks, four
Pstates, and the four memory fits of 4, 6, 8 and 12 GiB.

**Status: equivalent to the vendor driver under the reference model, not run on a board.** The
test shows that the library issues the same register writes, delays and PMIC calls as the
vendor driver does when every register reads back what was written and training reports
success. It does not show that DRAM trains on hardware.

## Layout

| Path | Contents |
|---|---|
| `include/a733_dram.h` | The interface: platform callbacks, parameter block, entry points |
| `src/dram_init.c` | The sequence, the order of the Pstates, the memory test |
| `src/dram_para.c` | Parameter blocks by strap index, checks, Pstate frequencies, size |
| `src/dram_clock.c` | PMIC rails, DDR PLL, DRAM clock, gates and resets, glue block |
| `src/dram_ctl.c` | The two controllers: static setup, address map, timing per Pstate, mode registers, timing adjustment after training, DFI handover, remap, frequency-change script |
| `src/dram_phy.c` | PHY: table runner, the save list in the PHY's sequence memory, firmware load, per-Pstate configuration, final step |
| `src/dram_train.c` | Message block, pin swap, mailbox, post-training step, read-back |
| `src/dram_io.c` | Register helpers over the platform callbacks |
| `src/dram_freq_table.c`, `src/dram_fields.h` | One row of values per Pstate frequency |
| `src/dram_ctl_tables.c`, `src/dram_phy_tables.c`, `src/dram_phy_final_tables.c` | Register tables |
| `test/harness.c` | The reference model: runs the library and prints every write, delay and PMIC call |
| `test/compare.py` | Compares a run with a reference script |
| `test/check_payload.py` | Checks that no file here carries bytes of the PHY firmware |
| `tools/payload-pack.c` | Host tool: packs the payload ranges the library reads, for an SPL |

The library is freestanding C11 and uses `stdint.h` and `stddef.h` only. It reaches the
hardware through `struct a733_dram_ops`: 16- and 32-bit register read and write, wait for a
condition, microsecond delay, set a PMIC rail in mV, log, strap index. The PHY firmware payload
(the 137 192-byte block of the specification) is passed in as a pointer and a length and is
not part of this tree. The library takes from it, at the offsets the reference scripts give:
the firmware code and data, five short runs of the message block, and the two long sequence
tables of the final PHY step (PHY `0x41388`, 2256 words, and `0x9002e`, 1290 words).

The payload can also be passed packed: only the ranges the library reads, 72 678 bytes, in
the order of `a733_dram_payload_ranges[]`. `make tools` builds `build/payload-pack`, which cuts
them out of a boot0 file; an SPL links that file instead of the whole block. Its output is
firmware without a redistribution grant: it is never committed or published.

`a733_dram_init()` reads the strap, selects the parameter block and returns the size in MiB,
or 0. `a733_dram_init_para()` does the same with a block the caller supplies.

## Test

```
make -C bootloader/dram check
```

For each fit this runs the harness with the strap index of that fit (4 GiB: 0, 6 GiB: 1,
8 GiB: 2, 12 GiB: 5) and compares:

1. every register write, as `<address hex> <size> <value hex>`, with the output of
   `docs/dram-init/expand_ops.py` for `ops-<fit>.tsv`;
2. the same list with the delays, the PMIC calls and the return value in their places, with
   the `DELAY`, `PMIC` and `END` lines of the script.

It stops at the first difference and names the script line. Last, `check_payload.py` searches
the built library and every file here for runs of 32 payload bytes (the longest run of plain
register values in the scripts that is also in the payload, by coincidence, is 18 bytes).

The harness takes the payload from the boot0 file under `vendor/blobs/`, at the offsets the
specification gives; `BOOT0=` overrides the path. `CROSS_COMPILE=` builds the library with
another gcc (`make lib`).

## What is computed and what is a table

Computed from the parameter block:

- the parameter block from the strap index;
- rail voltages from words 22 and 25;
- PLL factor from the clock (`clock / 24`);
- Pstate frequencies and clock dividers from word 24 (`clock * 4 / (divider + 1)`);
- the PHY register that takes the frequency divided by four;
- the message block fields that copy the low byte of words 15 and 18, and the Pstate number;
- the save list: every record, its place, and the record counts given to the PHY;
- mode register accesses;
- the timing adjustment after training, by the formulas of the specification;
- the clock words of the frequency-change parameters;
- read-back packing, size, and the size field of word 7.

Loops rather than lists: channels, ranks, Pstates, byte lanes, bits of a lane, command/address
groups. The PHY tables hold one entry per register and say which loop it is in.

Tables taken from the scripts, because the specification gives no rule:

| Table | Indexed by | Contents |
|---|---|---|
| `dram_freq_table` | Pstate frequency in MHz: 2400, 1200, 800, 400, 2040, 1165, 816, 408 | 24 controller timing registers, the refresh register of Pstate 0, 13 PHY registers (PLL and clock-dependent settings), 6 message block words |
| `ctl_addrmaps` in `dram_ctl.c` | row field of word 6 and the three-quarter flag | three address map registers, one row per fit |
| `para_*` in `dram_para.c` | strap index | the four parameter blocks, as listed in the specification |
| `swap_ac`, `swap_dq` in `dram_train.c` | pin swap table 0 only | board routing |
| `ctl_timing_ops`, `phy_*`, `dfs_seg*`, `remap_writes`, `msg_block` | none: the same for all four fits | static register values |

A frequency that has no row, a geometry that has no address map, and every configuration the
Zero 3W does not use (LPDDR4, one channel, one rank, the scan, the second rail set, other pin
swap tables, low-power mode) is refused with a message and a return value of 0, not guessed.

The table files were produced from the scripts with throwaway tooling: constant positions
became table entries, positions that differ between frequencies became fields of the frequency
row, and repetitions over byte lanes, bits and command/address groups were folded into loops.
The comparison is what checks them.

## What is and is not verified

Verified by `make check`, for all four fits: order and value of all 178 215 register writes
(178 217 for 6 GiB), the 31 delays, the 3 PMIC calls, the return value. Also that the library
builds with `-std=c11 -Wall -Wextra -Werror -ffreestanding`; this was done with gcc for the
host and with clang for the host, `aarch64-none-elf` and `arm-none-eabi` (compile only).

Not verified:

- anything on hardware: that the PLL locks, that the firmware starts, that training succeeds;
- every path that depends on a value read back: the timing adjustment with non-zero training
  results, the read-back packing, the mode register reads, the failure paths and timeouts;
- which registers the vendor driver reads, and how often: the test compares writes only;
- what the wait conditions are beyond the table in the specification;
- the memory test, which is not in the scripts: it follows the specification (16 words);
- frequencies, geometries and parameter values other than those of the four fits.

## Open questions

For the analysis side. Where the scripts and the specification disagree the library follows
the scripts, since the test is against them. Settled on 2026-11-13 and no longer listed: the
four parameter blocks, the PHY register in the `+0x588` formula, the memory test, and the long
sequence tables, which come from the payload.

1. **Values that follow the clock or the block.** Several values are the same for all Pstates
   of a fit and differ between the 2400 MHz and the 2040 MHz fits: controller `+0x60`, `+0x64`,
   `+0x580`, `+0x588`, PHY `0x4107c`, `0x41084`, message block words `0x5800e`, `0x58041`,
   `0x58081`, `0x58082`. The two pairs of blocks differ in the clock and in words 20, 22, 24
   and 27, so the scripts cannot tell which of these the values come from. They are in the
   frequency rows, which is right only as long as a clock goes with one set of those words.
2. **Timing rules.** The specification says the JEDEC timing values are chosen by frequency
   and the PHY PLL settings by a frequency table, without the rules or the table bounds. Eight
   frequencies are known and no others are accepted. The message block word `0x58003` is twice
   the Pstate frequency except on Pstate 3, where it is 1600 for both 400 and 408 MHz.
3. **Message block and parameters.** Only the copies of words 15 and 18 are computed. Which
   other message block words come from the parameter block (word `0x58008` = `0x125f` looks
   like word 27 without its top bits, and stays `0x125f` when word 27 is `0xb25f0000`) is not
   stated, so they are constants.
4. **Firmware data.** The specification's table gives the LPDDR5 firmware data as 1334 bytes
   at boot0 `0x27ab8`, copied to PHY `0x58235`. The scripts load 9 words to `0x5822d` from
   `payload+0x1efe9` and 666 words to `0x58236` from `payload+0xe40a`, which writes the same
   values. The library follows the scripts.
5. **Address map.** The three registers that differ per fit (`+0x3001c`, `+0x30004`, and
   `+0x30030`, written for 6 GiB only) are a table of four rows. The pattern suggests a rule
   (one more byte of `+0x3001c` in use per row bit; with the three-quarter flag the two top row
   bits move up by one and the rank select moves down by two), but it does not explain
   `+0x30030`.
6. **Size.** The specification says the size is a power of two from words 6 and 7. The library
   uses column bits (word 6 bits 0–3), row bits (4–11), bank bits (12–13, plus 2), 16-bit
   words, ranks (word 7 bit 12) and channels (word 30 bit 6), which gives the four sizes. The
   meaning of word 6 bits 14–15 is not known.
7. **Read-back.** The specification says the low 7 bits of 72 PHY registers are packed into
   words 32–49, and mode registers 14 and 15 into words 50 and 51, without the layout. The
   library puts four values in a word, one per byte, in the order read. Nothing in the scripts
   depends on it.
8. **Reference values after the last Pstate.** Step 5 of the specification ends with per-byte
   reference values from words 32 onward being written into the PHY's sequence memory "unless
   disabled". No such writes can be told apart in the scripts; the library does not do it.
   Word 27 bits 29–31, which the specification says control this, differ between the 2400 MHz
   and the 2040 MHz blocks.
9. **Initial clock divider.** The specification says the first divider of the DRAM clock
   depends on a chip-revision flag. The scripts show 3, which is also the divider of
   Pstate 0; the library uses the Pstate 0 divider and reads no revision.
10. **Reads and waits.** After opening the controller's programming handshake in the timing
    adjustment the script shows a read of `+0x10c84` without a wait; the library waits for
    bit 0 clear there, as the table of waits says, and nowhere else after writing 0. The
    mailbox wait is shown in the scripts against `0xd0032`; the library waits on `0xd0004`
    bit 0 as the specification says and then reads `0xd0032` and `0xd0034`.
11. **Save list constants.** The post-training step gives the PHY start and length of the
    parts of the save list at `0xc0108`–`0xc010e`. Start and length of the head and of the
    main part are computed; `0xc010c` = `0xe0` and `0xc010b` = `0x287` are constants whose
    meaning is not known, and `0xc010f` is not written.
12. **Save list.** The specification does not describe the save list (PHY `0xa0000` +
    Pstate × `0x1000`): the record format and the pairing of even and odd registers in
    `src/dram_phy.c` are read off the scripts, where they hold for every record.
