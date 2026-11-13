# DRAM init on the A733: how boot0 and `ddr.bin` work

A behavioural description of the two existing DRAM initialisers for the Allwinner A733, written
so that our own can be implemented from it (`SPEC.md` D2). It fixes the architecture, the data
formats, the sequence, and, in `docs/dram-init/`, every register write of the sequence for the
four memory fits of the Orange Pi Zero 3W. `docs/dram-init/HANDOFF.md` is the brief for the
implementation.

## Method and rules

- 2026-11-13. Static analysis of both binaries, then emulation of boot0's DRAM routine on a
  workstation against a model of the registers. Nothing was run on the board, so nothing here
  is confirmed on hardware. Details in "Method, tools and licences".
- Each statement is marked **O** (observed in the binary), **I** (inferred, with the reason) or
  **U** (unknown).
- This document holds no code, pseudocode or bytes from either binary, apart from the DRAM
  parameter words, which are configuration data that Radxa also publishes in a device tree.
- Clean-room rule for the implementation: whoever writes our DRAM init works from this document
  and from public sources only (see "Public references"), not from the decompiled output. The
  decompiled output and working notes stay outside this repository.

## The two binaries

| | boot0 | `ddr.bin` |
|---|---|---|
| File | `boot0_sdcard_orangepizero3w.fex` (`vendor/sources.json`) | `awbin/a733/ddr.bin`, `radxa-pkg/u-boot-dlan17` @ `b1cec0a90c79` |
| sha256 | `829ea8e3…7fabe3` | `d89804f4…813a05` |
| Size | 245 760 bytes | 232 409 bytes |
| Load address | `0x47000` (**O**, header) | `0x90000` (**I**, from its own BSS and string pointers) |
| Role | complete first-stage loader: DRAM init, then loads and starts the next stage | DRAM init called by U-Boot SPL; can also act as a loader |
| Build identity | commit `4721ad08`, MMC driver dated 2025-10-16 | "SPL-2.0 preboot", `853efe0f-dirty`, 2026-06-17 |
| DRAM driver | "V0.6034" | same strings and the same register usage |
| Configuration | fields in its own header | a flattened device tree appended at file offset `0x38040` |

The central finding: **both contain the same DRAM driver and one identical block of 137 192
bytes of data** (boot0 file offsets `0x196b0`–`0x3ae98`, `ddr.bin` `0x16738`–`0x37f20`) (**O**).
That block is more than half of each file and holds the firmware images that are loaded into
the DRAM PHY (see "PHY firmware").

## Hardware blocks involved

| Block | Base | What it is |
|---|---|---|
| DRAM controller, channel 0 | `0x0A100000` | Synopsys DesignWare DDR controller (**I**) |
| DRAM controller, channel 1 | `0x0A500000` | second instance, same layout, `+0x400000` (**O**) |
| DRAM PHY | `0x0A900000` | Synopsys DesignWare LPDDR5/4 PHY, 16-bit registers at `base + (address << 1)` (**I**) |
| Allwinner DRAM glue | `0x0A020000` | clock gates, resets and channel enables around the two (**O**, names **U**) |
| CCU | `0x02002000` | DDR PLL at `+0x20`, DRAM clock at `+0xC00`, gate and reset at `+0xC0C`, three more at `+0x580`–`+0x588` (**O**) |
| PRCM side | `0x07010250` | bit 0 is set once power and clocks are up; likely a pad hold release (**I**) |
| System control | `0x03000160` | bit 8 set, low byte of `+0x168` cleared at the very start (**O**, purpose **U**) |
| PMIC | TWI on the R domain | rails `dcdc6`, `dcdc7`, `dcdc8`, `eldo1`, `eldo2` (**O**) |

Why Synopsys (**I**): the controller is driven through a mode-register interface at `+0x10080`,
`+0x10084`, `+0x10090`, a software-programming handshake at `+0x10C80`/`+0x10C84`, a DFI
handshake at `+0x10510`/`+0x10514`, and status at `+0x10014`: the DesignWare DDRCTL layout
(MRCTRL0, MRCTRL1, MRSTAT, SWCTL, SWSTAT, DFIMISC, DFISTAT, STAT in the channel-0 register
block). The PHY is driven exactly as the public `dwc_ddrphy` protocol describes: firmware copied
to the instruction memory at PHY address `0x50000` and data memory at `0x58000`, the
`0xD0000` mux select, the `9, 1, 0` write sequence to `0xD0099` to start the firmware, a
mailbox at `0xD0004`/`0xD0031`/`0xD0032`/`0xD0034`, and the value `0x07` meaning "training
completed". The messages speak of "Pstate" training, which is that PHY's term.

## DRAM parameters

Both drivers take one block of 32 little-endian words (128 bytes).

Where it comes from:

- boot0: words at header offset `0x38`. An extension, tagged `DRAM.ext` at `0x348`, holds up to
  15 alternative blocks of 128 bytes starting at `0x374` (**O**).
- `ddr.bin`: properties `para0`…`paraN` of node `/dram` in its device tree (**O**).

Selection of the block (**O**):

| Mode | boot0 (`DRAM.ext` byte at `0x350`) | `ddr.bin` (`/dram_select`, `select-mode`) |
|---|---|---|
| none | 0: the header block | 0: `para0` |
| GPIO | 1: up to four GPIO levels form the index | 1 |
| ADC | 2: one GPADC channel, compared against eight thresholds | 2 |
| both | 3 or 4: ADC index plus 8 × a GPIO or second ADC bit | 3: `adc_idx + 8 × gpio_idx` |

The Zero 3W boot0 uses mode 2 on GPADC channel 1. The thresholds are the midpoints of
163, 382, 608, 811, 1050, 1315, 1569, 1800. Index 0 keeps the header block; index *n* copies
alternative block *n* over it, unless that block is empty. The Zero 3W image fills blocks 1, 2
and 5. So one boot0 serves several memory fits of the same board, told apart by a resistor
strap on an ADC pin (**O**, sizes from the emulated run):

| Strap index | Block | Clock | Word 6 | Word 30 | Size | Script |
|---|---|---|---|---|---|---|
| 0 | header | 2400 MHz | `0xa0fa` | `0x65` | 4096 MiB | `ops-4g.tsv` |
| 1 | 1 | 2400 MHz | `0xa10a` | `0x10065` | 6144 MiB | `ops-6g.tsv` |
| 2 | 2 | 2040 MHz | `0xa10a` | `0x65` | 8192 MiB | `ops-8g.tsv` |
| 5 | 5 | 2040 MHz | `0xa11a` | `0x10065` | 12288 MiB | `ops-12g.tsv` |

Any other index falls back to the header block. That the 12 GiB board reads index 5 is **I**
(it is the only 12 GiB block); the vendor boot log prints the selection and would confirm it.

The words, for the Zero 3W header block and Radxa's `para0`:

| Word | Zero 3W | Radxa `para0` | Meaning |
|---|---|---|---|
| 0 | 2400 | 2400 | DRAM clock in MHz (**O**) |
| 1 | 9 | 9 | type: 8 LPDDR4, 9 LPDDR5 (**O**, printed) |
| 2–4 | `0x0e0e0e0e` `0x0f0f0f0f` `0xec030e0f` | same | drive strength and termination codes (**I**) |
| 6 | `0xa0fa` | `0xa0fa` | "para1": address geometry; the autoscan rewrites it (**O**) |
| 7 | `0x1001` | `0x1001` | "para2": low nibble selects bus width class, bit 12 two ranks; the size in MiB is stored in the upper half afterwards (**O**) |
| 11 | 6 | 6 | **U** |
| 15 | `0x14` | `0x13` | **U**, differs |
| 16 | `0x44` | `0x44` | **U** |
| 18 | `0x28` | `0x2e` | low byte feeds the LPDDR4 per-byte table; **U** for LPDDR5, differs |
| 20 | 6 | 6 | **U** |
| 22 | `0x4040` | `0x4040` | bits 20–27: second rail voltage in 10 mV steps, 0 means default; bit 16: force 1200 mV (**O**) |
| 24 | `0x170b0703` | same | one clock divider per Pstate, a byte each (**O**, see below) |
| 25 | `0x3800` | `0x3800` | bits 8–15: first rail voltage in 10 mV steps (here 560 mV); bit 20: use the second rail set (**O**) |
| 26 | `0x3514` | `0x3514` | low 7 bits: a reference level code (**I**) |
| 27 | `0x325f0000` | same | flags; bits 29–31 control write-back of trained values (**O**) |
| 30 | `0x65` | `0x65` | "tpr13", feature flags (**O**, see below) |
| 32–50 | written by the driver | | per-byte-lane results read back from the PHY (**O**) |

The two blocks differ in words 15 and 18 only. That answers part of the open question in
`docs/boot-chain-options.md`: Radxa's default parameters are close to this board's but not
identical, and the meaning of the two differing words is not yet known.

Flags in word 30 (**O**): bit 0 skips the whole scan of step 2; bit 2 trains four Pstates
instead of one; bit 6 enables the second controller channel; bit 14 skips only the rank and
width part of the scan; bit 15 marks the scan as already done; bits 16–18 select a three-quarter size (12 GiB style) memory; bit 24
enables a low-power mode on the controller. With `0x65` the Zero 3W uses both channels, four
Pstates, and no rank scan.

Pstate frequencies (**O**): `clock × 4 / (divider + 1)`, so `0x03, 0x07, 0x0b, 0x17` give
2400, 1200, 800 and 400 MHz.

## Sequence

### 1. Power

For LPDDR5 with the first rail set (**O**): `dcdc7` and `eldo1` to the second voltage
(default 1080 mV, or 1200 mV if forced), then `dcdc6` to the first voltage (560 mV here). The
alternative rail set uses `dcdc8`, `eldo2` and `eldo1`. LPDDR4 uses `dcdc7` or `dcdc8` and
`dcdc6` with other defaults. This matches the rails named in `docs/zero3w-wiring.md`. A failure
to set a rail aborts the init.

### 2. Rank, width and size scan

Skipped on the Zero 3W by the flags. When run (**O**): the driver initialises with trial
geometries (two ranks, then one), then writes an address-dependent pattern at the base of
memory (`0x40000000`) and looks for the address bit at which the pattern aliases, for rows,
columns and ranks in turn, and stores the result in word 6.

### 3. Clocks and resets

In order (**O**): hold the DRAM clock and both module resets; release the bus gate; program
the DDR PLL to `24 MHz × N` with `N = clock / 24`, enable it, wait for lock, enable the
output; select the PLL as DRAM clock source with a divider that depends on a chip-revision
flag; release the resets; enable the three clocks at `+0x580`–`+0x588`.

### 4. Glue and controller

(**O**) Configure the glue for one or two channels and for LPDDR4 or LPDDR5; set the pad
hold bit at `0x07010250`; wait 10 ms. Then, per channel: write the static controller
configuration (memory type and rank in the master register, DFI timing, address map, a table of
JEDEC timing values chosen by frequency, mode register values). Then release the controller
and PHY resets through the glue in two steps, 1 µs apart.

### 5. PHY configuration and training, per Pstate

For each trained Pstate, in the order 1, 2, 3 and then 0 (**O**):

1. Write the PHY's static configuration for that frequency (PLL settings chosen by a frequency
   table, impedance and reference settings from the parameter words, per-byte-lane settings).
2. Write the message block and the firmware data into the PHY data memory and zero the rest,
   with the message block fields filled from the parameters. The firmware code itself is
   copied into the PHY instruction memory once, before the first Pstate.
3. Program the pin swap: 8 bytes per byte lane and 14 bytes for the command bus, chosen from
   built-in tables by the low nibble of the upper half of word 25. This is board routing
   information.
4. Start the firmware and wait on the mailbox. The result word is printed. Anything other
   than `0x07` is a failure and aborts the init.
5. Run the post-training step that loads the PHY's own initialisation sequence for that
   Pstate.

After the last Pstate, unless disabled, per-byte reference values from the parameter block
(words 32 onward) are written into the PHY's sequence memory for every Pstate.

### 6. Handover to the controller

(**O**) Per channel: start the DFI initialisation and wait for its completion bit; set the
pad hold bit again; wait 2 ms; clear the self-refresh and power-down requests; wait until the
controller reports normal operating mode; enable the address remap and the three-quarter size
handling when the flags ask for it; enable low-power mode when flagged. For LPDDR5 a further
per-channel step programs periodic retraining.

### 7. Read-back, size and test

(**O**) Trained values are read from the four byte lanes and from mode registers of both ranks
and stored in the parameter block. The size in MiB is computed from words 6 and 7 as a power of
two, times three quarters when flagged, and stored in the upper half of word 7. A write and
read-back test at the base and at the half-size offset decides success. The init returns the
size in MiB, or 0.

## PHY firmware

The shared 137 192-byte block contains, at least (**O**, offsets in boot0):

| Offset | Size | Use |
|---|---|---|
| `0x1979c` | 51 672 bytes | LPDDR4 firmware, copied to PHY address `0x50000` (not exercised here) |
| `0x27fee` | 64 160 bytes | LPDDR5 firmware, copied once to PHY address `0x50000`; the rest up to `0x58000` is zeroed |
| `0x27ab8` | 1 334 bytes | LPDDR5 firmware data, copied to PHY address `0x58235` before each training run |
| others | | tables for LPDDR4 and small fragments |

The scripts refer to this block as `payload` (boot0 bytes `0x196b0`–`0x3ae98`, sha256
`a05762ae…07a25a`), by offset, so that no firmware content is reproduced in this repository.
The PHY data memory at `0x58000` is rewritten before each of the four training runs: the
message block (about 80 words, listed in the scripts as plain writes), the firmware data, and
zeros.

This firmware runs on the processor inside the PHY, not on the ARM cores. It is Synopsys'
training firmware (**I**), which is what performs the actual training.

**Consequence for D2.** A DRAM init written here can replace all the ARM code of boot0 and
`ddr.bin`. It cannot replace this firmware: the training algorithm lives in it, and it has to
match this PHY. "No vendor binary in the boot chain" is therefore not reachable for the DRAM
PHY firmware; what is reachable is "no vendor code running on the ARM cores, and one firmware
image loaded into the PHY". Other platforms with the same PHY family are in the same position
(NXP ships these images as separate firmware files). The image has no redistribution grant, so
it would be extracted from boot0 at build time, as the vendor variant already does with boot0
itself.

## What else boot0 does

Outside DRAM init (**O**, order as executed):

1. Sets up the stack, clears BSS, initialises a timer and the UART named in its header
   (port at `0xb8`, pins at `0xbc`), prints a banner and its commit id.
2. Checks a flag in the RTC domain and the UART for the character `2`; either diverts to FEL.
3. Checks for a key press through the GPADC for up to 3 s.
4. Probes the PMIC and sets the DRAM rails, runs the DRAM init, optionally overrides the size
   from header offset `0x318`.
5. Sets up memory protection for the secure world, and a heap at `0x40800000`, 16 MiB.
6. Initialises SD or eMMC, reads the boot package, checks magic and checksum, and locates its
   items by name: U-Boot, the monitor (TF-A), an optional secure OS, a device tree, optionally
   others.
7. Writes DRAM size, the DRAM parameter block, boot medium and UART settings into fixed
   offsets of the loaded U-Boot image, and a 2048-byte "bootpara" record at U-Boot base
   `+0x1ff000`.
8. Jumps to the monitor if present, giving it the U-Boot and secure OS addresses; otherwise to
   the secure OS or straight to U-Boot.

The header itself (**O**): branch instruction, magic `eGON.BT0`, a checksum over the whole file
computed with the constant `0x5F0A6C39` in the checksum field, the length, the load address at
`0x1c` and `0x20`.

Most of this non-DRAM code corresponds to Allwinner's `spl-pub` loader, whose source Allwinner
publishes under the GPL (**I**, from the strings); only the DRAM library is shipped without
source. None of it is needed by our chain, where U-Boot SPL does these jobs.

## What `ddr.bin` does differently

(**O**) Same DRAM driver, but board data comes from the appended device tree: UART, the R-domain
TWI and PMIC, the two GPIO controllers, MMC pins, the GPADC, six parameter blocks (`para0`–`3`,
`7`, `10`) and the selection rule (mode 3: GPADC channel 1 plus one GPIO). If a valid
"bootpara" record with a matching checksum is already present it is reused. When called as
"preboot" it returns the DRAM size in MiB to its caller; otherwise it continues as a loader
like boot0. On any failure it enters FEL.

Its parameter blocks include a 2040 MHz LPDDR5 pair and an LPDDR4 block at 1800 MHz. Whether
any of them fits the Zero 3W's memory, and how the Zero 3W's ADC strap maps onto Radxa's
selection, is **U**.

## Operation scripts

`docs/dram-init/ops-<size>.tsv` hold the complete, ordered sequence boot0's driver performs for
each memory fit: about 15 000 operations each, standing for 178 215 register writes. Columns:
`op`, `block`, `addr`, `value`, `extra`.

| op | Meaning |
|---|---|
| `PHASE` | entry into a step of the sequence; `block` holds its name. A reading aid, not an action |
| `MSG` | text the vendor driver prints at that point. Not an action |
| `PMIC` | set rail `block` to `value` mV |
| `DELAY` | wait `value` microseconds |
| `W32`, `W16` | write `value` (hex) |
| `RMW32` | read, clear the bits of `clear=`, set the bits of `set=`, write back. `written=` is the value written under the reference model below. `derived` marks a value computed from other registers (see "Timing adjustment after training") |
| `READ` | a read whose value is used later or ignored (status, read-back) |
| `WAIT` | poll until a condition holds (table below); `exit_on=` is the value that ended the poll in the emulation |
| `LOAD16` | write `value` consecutive 16-bit words taken from the payload at the offset in `extra` |
| `ZERO16` | write `value` consecutive 16-bit zero words |

Blocks and address forms:

| block | Absolute address |
|---|---|
| `PHY` | `0x0A900000 + (addr << 1)`, 16-bit registers |
| `CTL0`, `CTL1` | `0x0A100000 + addr`, `0x0A500000 + addr` |
| `GLUE` | `0x0A020000 + addr` |
| `CCU` | `0x02002000 + addr` |
| `SYS2` | `0x02020000 + addr` |
| `SYSCFG` | `0x03000000 + addr` |
| `PRCM` | `0x07010000 + addr` |

`docs/dram-init/expand_ops.py` expands a script into the flat list of writes. The four
expansions were checked to be identical, write for write, to the emulated traces.

### Reference model

The scripts were recorded under this model, and an implementation tested against them must use
the same one:

- every register starts at 0 and a read returns the last value written to it;
- a poll ends at once, without changing the stored value;
- a read of PHY `0xD0032` returns `0x07` and of `0xD0034` returns 0 (training reports success);
- consequently every trained value, mode register read-back and status reads as whatever was
  last written there, usually 0.

On hardware those reads return real values, and the writes that depend on them will differ.

### Waits

| Register | Condition |
|---|---|
| `CCU` `+0x20` | bit 28 set (PLL locked) |
| `CTLn` `+0x10c84` | bit 0 equal to the value just written to `+0x10c80` |
| `CTLn` `+0x10514` | bit 0 set (DFI initialisation complete) |
| `CTLn` `+0x10014` | bits 4–5 clear, then bits 0–1 equal to 1 (normal mode) |
| `CTLn` `+0x10090` | bit 0 clear, before a mode register access |
| `CTLn` `+0x10080` | bit 31 clear, after starting a mode register access |
| `CTLn` `+0x10b88` | bits 25–26 equal to 3, then bits 28–29 equal to 3 |
| `PHY` `0xD0004` | bit 0 clear: a message is waiting. After acknowledging, bit 0 set again |

### Mailbox

(**O**) To run the firmware: write 1 to `0xD0000`; write 9, then 1, then 0 to `0xD0099`; write
1 to `0xD0031` and to `0xD0033`. Wait for a message; read it from `0xD0032` and `0xD0034`;
acknowledge by writing 0 to `0xD0031`, waiting for bit 0 of `0xD0004` to rise, and writing 1 to
`0xD0031`. Then write 1 to `0xD0099`. The vendor driver reads a single message and treats
`0x07` as success; it does not handle intermediate messages.

### Mode register access

(**O**) Write of register *r* with value *v* on channel *n*: wait for `+0x10090` bit 0 clear;
write `0x10` to `+0x10080` (first rank); write `(r << 8) | v` to `+0x10084`; write
`0x80000010` to `+0x10080`; wait for bit 31 clear; repeat with `0x20` and `0x80000020` for the
second rank. A read uses `(1 << (rank + 4)) | 1` in `+0x10080`, `r << 8` in `+0x10084`, the same
start bit, and takes the result from bits 8–15 of `GLUE` `+0x2c` (channel 0) or `+0x40`
(channel 1).

### Timing adjustment after training

(**O**, LPDDR5, once per channel, phase `ctl_lp5_post`.) With the PHY mux at 0 the driver reads
twelve result words from the PHY data memory, `0x58013`–`0x58018` and `0x58020`–`0x58026`.
Write hi(x) and lo(x) for the two bytes of word `0x580xx`:

- A = max(hi(18), lo(18), lo(26), hi(25))
- B = max(hi(13), lo(13)); C = max(lo(21), hi(20))
- D = max(hi(14), lo(15), hi(22), lo(22))
- E = max(hi(16), lo(17), hi(24), lo(24))
- F = max(hi(15), lo(14)); G = max(hi(21), lo(23))
- H = max(hi(17), lo(16)); I = max(lo(25), hi(23))

Then, with the controller's programming handshake opened (`+0x10c80` = 0) and each sum
saturating at the field's maximum:

| Register | Change |
|---|---|
| `+0xd04` | bits 8–15 += A; bits 0–7 += max(B, C) |
| `+0xd08` | bits 8–15 += D; bits 0–7 += E |
| `+0x8` | bits 8–15 += max(F, G); bits 0–7 += max(H, I) |
| `+0x60` | bits 16–23 += D |
| `+0x24` | bits 0–7 += E |
| `+0x584` | bits 16–20 += A |
| `+0x588` | bits 16–21 = `((PHY 0x1002a & 0x1f) >> 1) + ((((PHY 0x20004 & 0xf) + 1) >> 3) << 2) + 0x15` |

Before this the driver sets bit 0 of `+0x10b84` and waits on `+0x10b88`; afterwards it closes
the handshake and clears that bit. These are the PHY's reported delay differences between
ranks and between read and write, added to the controller's turnaround timings.

### Frequency-change script

(**O**, phase `dfs_setup`, when bit 2 of word 30 is set.) The driver fills a table in the glue
block at `+0x1d0c`, 16 bytes per entry, with a list of register operations (register offset,
value, mask, write or wait) for each Pstate. It is a script for hardware-driven frequency
changes at run time. The scripts list it as plain writes to `GLUE` `+0x1d0c` onward. Its
entry format is not decoded further here; boot does not depend on it.

### Read-back

(**O**, phase `readback`.) With the PHY mux at 0, for each of the four byte lanes and nine
registers per lane (`0x1004e`–`0x1084e` and the same at `+1`, lane stride `0x1000`), the low 7
bits are packed into words 32–49 of the parameter block. Mode registers 14 and, for LPDDR5,
15 are read on both channels and ranks into words 50 and 51, between a write of 5 and a
write of 4 to mode register 16. The block is then handed to the next stage.

## Method, tools and licences

How this was obtained, in order:

1. Strings, header fields and the embedded device tree were read from the files directly
   (`strings`, `xxd`, `dtc`, Python).
2. Both files were decompiled as raw AArch32 images with Ghidra 12.2 driven by REA 6.9.0
   (`rea decompile-all`): 225 functions of boot0, 153 of `ddr.bin`. Three boot0 functions were
   too large for the decompiler.
3. The identical 137 192-byte block was found by comparing the two files.
4. boot0's DRAM routine (entry `0x49bdc`) was run under Unicorn 2.1.4 with the parameter block
   of each memory fit. Memory-mapped registers were modelled as in "Reference model"; the
   console, delay and PMIC routines were replaced by logging stubs. Every access was logged.
5. Each run was repeated with every register read returning the complement of the first run's
   value. Comparing the two separates constants from read-modify-write, bit by bit.
6. The logs were normalised into the operation scripts, and the scripts were expanded again
   and compared with the logs.
7. A sweep flipping each bit of each parameter word and recording which writes change is in
   `docs/dram-init/sensitivity.tsv`, where complete.

The scripts used for steps 4 to 7 are in `docs/dram-init/method/`. They need the two binaries
and the decompiler output, which are not in this repository.

| Item | Origin | Licence |
|---|---|---|
| `boot0_sdcard_orangepizero3w.fex` | `orangepi-xunlong/orangepi-build` @ `7f24222b` | none stated for the binary; no source for the DRAM library |
| `ddr.bin` | `radxa-pkg/u-boot-dlan17` @ `b1cec0a90c79` | none stated; its README asks not to redistribute built output |
| PHY firmware inside both | Synopsys (**I**) | proprietary, no grant known |
| Ghidra 12.2 | NSA | Apache-2.0 |
| REA (`rea-agents` 6.9.0) | `morluto/rea` | MIT |
| Unicorn 2.1.4 | unicorn-engine | GPL-2.0 |
| `dtc`, Python 3 | | GPL-2.0-or-later, PSF |

Nothing from the two binaries is reproduced here except configuration values: the DRAM
parameter words and the values written to registers. The register values are what any driver
for this hardware has to write; whether publishing them raises a question for this project is
the maintainer's call and was accepted on 2026-11-13.

## Limits

- Only the paths the Zero 3W takes were run: LPDDR5, two channels, four Pstates, no scan.
  LPDDR4, single channel and the rank and size scan are described from the code only.
- The model reports training success. What the firmware does, and every value that depends on
  its results, is unverified until it runs on the board.
- The meaning of most parameter words is known only as far as the sensitivity sweep and the
  code show which registers they reach.
- The glue registers at `0x0A020000` and the frequency-change table are unnamed.
- Timing: delays are those the vendor driver requests; nothing was measured.

## Public references for the implementation

- U-Boot `drivers/ddr/imx/phy/` and TF-A `drivers/st/ddr/phy/`: open implementations of the
  same PHY protocol (firmware load, mailbox, message block) for LPDDR4 and DDR4.
- NXP's i.MX 95 OEI: open LPDDR5 bring-up with the same PHY family.
- Allwinner's published `spl-pub` sources for everything around the DRAM library.
- `DockSeed/a733-bootchain` and `dlan17` trees: how U-Boot SPL calls `ddr.bin` on the A733.
