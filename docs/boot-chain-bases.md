# Mainline boot chain: bases, layout and what is ours

How the firmware for the Orange Pi Zero 3W is put together (`SPEC.md` D2, D7, section 3.3):
which trees it is built from and why, what our patches change, where things sit in memory and
on the card, and what is not known yet. Trees were read on 2026-11-13. Nothing here has run on
the board; `docs/bring-up.md` is the plan for the first session with it.

```
BROM -> U-Boot SPL (our DRAM library, PHY training firmware) -> BL31 (TF-A) -> U-Boot
```

One file, `u-boot-sunxi-with-spl.bin`, at 128 KiB on the card.

## Bases

The maintainer's rule: the most reliable existing branch is the base, our own patches go on
top, and third-party patch sets are read, not imported (D7).

### U-Boot: `radxa/u-boot`, branch `u-boot-dlan17`, `d79733d67cc5`

| Candidate | State on 2026-11-13 | Verdict |
|---|---|---|
| upstream master | no `MACH_SUN60I_A733`; the series that adds it is at v3 since 2026-01 | nothing to build on |
| `dlan17/u-boot`, `allwinner/A733/boot-2026.04`, `boot`, `next` | the development branches of the series' author; rebased, three of them, each for a different way of booting | moving targets |
| `radxa/u-boot`, `u-boot-dlan17` | v2026.07 with the A733 work on top, maintained by the board vendor (last commit 2026-11-11), the base of the one chain known to boot an A733 board without boot0 (`DockSeed/a733-bootchain`, two Cubie A7S) | **base** |

It has what the port needs and nothing else has in one place: the A733 clock, pin, MMC and
GPADC code, the AXP318W tables, the eGON and FIT handling for this SoC, and two A733 boards to
model a third on.

What it does not have, and our patches add: a way to boot without the DRAM blob. In that tree
the SPL carries Radxa's `ddr.bin`; an AArch32 hook copies it to SRAM and runs it before the
SPL proper starts, and the SPL only reads the size it returned.

### TF-A: `dlan17/trusted-firmware-a`, branch `A733`, `f4c0b0dba78a`

| Candidate | State on 2026-11-13 | Verdict |
|---|---|---|
| upstream master | no A733 platform, no A523 either | would mean writing the platform |
| `DockSeed/a733-bootchain` | upstream master plus 17 patches; a patch set, not a branch, and D7 rules out importing it | reference |
| `dlan17/trusted-firmware-a`, `A733` | TF-A v2.12 (2025-01), Jernej Skrabec's unmerged A523 series, one commit adding the A733 (2025-09); "tested only with power on/off" by its author; what `dlan17/a733` documents for booting an A7A | **base** |

It is the only branch with the platform. Its weaknesses are on record: fourteen months old,
three of its commits are marked as hacks or to be cleaned by their author, PSCI beyond CPU on
and off is untested, and it has none of the A76 errata work of the DockSeed set. It is enough
to reach U-Boot and to bring up the cores; before the chain is trusted for anything else the
errata and the power management need our own patches, with the DockSeed set as reference.

## Our patches

In `bootloader/patches/`, applied by the derivations in the order of `bootloader/sources.json`.

| Patch | What it does |
|---|---|
| U-Boot 0001 | `SUNXI_A733_DRAM_SOURCE`: the boot hook no longer copies and runs a blob, it only switches to AArch64. BL31 moves to DRAM (`0x40000000`) and the SCP image goes, for an SPL built that way |
| U-Boot 0002 | builds the DRAM library into the SPL and implements its platform interface: register access, polling with a 5 s timeout, delays, the DRAM rails on the AXP318W through a small polling driver for R_TWI0, the memory strap on GPADC channel 1. Links the PHY firmware from the file named by `A733_DRAM_PAYLOAD` |
| U-Boot 0003 | the board: `orangepi_zero3w_defconfig` and `sun60i-a733-orangepi-zero3w.dts` (UART0 on PB9/PB10, microSD on mmc0, PMIC on R_TWI0, from `docs/zero3w-wiring.md`) |
| TF-A 0001 | BL31 runs from DRAM by default on the A733, as on the H616 |

The DRAM library itself is not a patch: `bootloader/u-boot.nix` copies `bootloader/dram/include`
and `src` into `arch/arm/mach-sunxi/a733_dram/` of the U-Boot tree, so there is one copy of it,
the one `make -C bootloader/dram check` tests.

## The PHY training firmware

The DRAM PHY trains with firmware that runs inside the PHY (`docs/dram-init-spec.md`, "PHY
firmware"). It cannot be replaced and has no redistribution grant.

- `bootloader/dram-payload.nix` cuts it out of the manufacturer's boot0 at build time: the
  eight ranges the LPDDR5 path reads, 72 678 bytes, by the offsets of the specification.
- The SPL links that file (`a733_dram_payload` to `a733_dram_payload_end`). It is never in
  the tree.
- Every derivation that holds it has `nopublish` in its name: the payload, the firmware.
  The Cachix push filter of the three workflows drops those paths; images were already
  dropped. Nothing of it is uploaded as a workflow artifact or attached to a release.
- `spl-zero-payload` is the same SPL with zeros in place of the firmware. That one is
  uploaded by CI, ELF and map included.

## Memory layout

| What | Where | Source |
|---|---|---|
| SPL image, as the BROM loads it | SRAM `0x47000`; code from `0x47060` | U-Boot `SPL_TEXT_BASE`, FEL tool `spl_addr` |
| SPL size limit | `0x29000` from `0x47060`, so the image ends below `0x71000` | `SPL_MAX_SIZE` in our defconfig; the FEL tool keeps its own data from `0x71000` |
| SPL early stack, with the pre-DRAM heap below it | down from `0x90000` | `SPL_STACK` in our defconfig; see "Not known" |
| SPL BSS, stack and heap after DRAM init | DRAM `0x4ff80000`, `0x4fe00000` | as in the base tree |
| FIT, as read from the card | DRAM `0x47a00000` | as in the base tree |
| BL31 | DRAM `0x40000000`, 256 KiB reserved | TF-A `SUNXI_BL31_IN_DRAM`, U-Boot `SUNXI_BL31_BASE` |
| U-Boot | DRAM `0x4a000000` | as in the base tree |

Why BL31 moved: the base trees put it in SRAM at `0x62000`. Their SPL is done with DRAM before
it starts and the blob's copy in the image is dead weight by then. Ours runs DRAM init from
SRAM and its image, with the PHY firmware, covers `0x62000`: loading BL31 there would
overwrite the SPL while it runs.

Consequence for the kernel: the first 256 KiB of DRAM belong to BL31. TF-A adds a
`reserved-memory` node to the device tree it finds at U-Boot's address, which covers U-Boot.
The kernel's own device tree needs the same reservation (`0x40000000`, `0x40000`), as the H616
trees have.

## On the card

| Item | Offset | Notes |
|---|---|---|
| GPT | 0 to 17 KiB | |
| `u-boot-sunxi-with-spl.bin` | 128 KiB (sector 256) | the BROM looks for an eGON image at 8 KiB and at 128 KiB |
| FIT inside it | `0x4a000` into the file | U-Boot `SYS_MMCSD_RAW_MODE_U_BOOT_SECTOR=0x250`, binman `min-size` of the SPL blob |
| first partition | 32 MiB | `sdImage.firmwarePartitionOffset` |

`ci/check-firmware.py` checks this on the built file: eGON magic, length and checksum, the SPL
signature, the SPL size against the FEL limit, the FIT at `0x4a000`, U-Boot and BL31 at their
addresses with BL31 entered first, no SCP image, and the end of the file before the first
partition.

## Watchdog

`SPEC.md` 3.3 says U-Boot hands a running watchdog to Linux. That described the DockSeed
chain, which has a patch to start it. The base tree does not start the watchdog
(`WATCHDOG_AUTOSTART` is off for sunxi) and our port leaves it that way for bring-up: a
board that resets 16 s into a boot that is being debugged over serial helps nobody. When the
kernel device tree drives `WDT_CPUS`, turning the autostart on is one line in the defconfig;
until then the chain hands over no running watchdog.

## Verification without the board

| Check | Where | Shows |
|---|---|---|
| `make -C bootloader/dram check` | CI on every push, and locally | the library issues the register writes of the reference scripts, with the whole and with the packed payload |
| flake evaluation | CI on every push | the derivations and the image module evaluate |
| firmware build | CI job `firmware` of `build.yml` | the patches apply, the SPL links with the library and fits its limit |
| `ci/check-firmware.py` | same job | the image layout above |
| SPL with zero payload | artifact `a733-spl-zero-payload` of the same job | lets the analysis side run the SPL's DRAM path against the register model |

None of this shows that the board boots.

## Not known

Facts the chain depends on and that neither the public trees nor our documents settle. They
are asked of the analysis side where it can know them; the rest waits for the board.

1. **Clocks before DRAM init.** U-Boot skips its clock setup on the A733 ("skip clock init for
   A733 for now"): in the base tree the blob runs first and, being a cut-down boot0, very
   likely sets up the PLLs. Our SPL runs no blob. Its MMC driver takes the card clock from
   PLL_PERI0 as it finds it (`CCU + 0xa0`); if the BROM leaves that PLL off, the SPL trains
   DRAM and then fails to read the FIT. FEL does not need the card, so DRAM init can be tried
   before this is settled.
2. **AXP318W encodings.** The rail tables are those of the base tree. For ELDO1 they say
   500 mV plus 25 mV steps, in which the 1080 mV the vendor driver asks for does not exist
   (the schematic says 1.078 V); the glue rounds down to 1075 mV. It logs the value each
   rail had before, writes only if that differs, and refuses anything above 700 mV on DCDC6
   and 1250 mV on the others.
3. **Memory strap.** The glue reads GPADC channel 1 as the base tree's GPADC code does and
   takes the reading as millivolts of 1800 mV full scale. Whether the GPADC needs a clock gate
   or reset first, and the unit of the thresholds, are not confirmed. No reading stops the
   init; a wrong reading selects the wrong memory fit. `CONFIG_SUNXI_A733_DRAM_STRAP` sets the
   index by hand (the 12 GiB board is index 5).
4. **SRAM extent.** The early stack sits below `0x90000`. The base tree's SPL image may reach
   that far and its blob runs from `0x90000`, so the BROM loads there and the memory exists.
   Whether the BROM keeps anything of its own there in FEL mode is not known.
5. **Crystal.** The schematic says 26 MHz. U-Boot assumes 24 MHz for the UART divisor, the
   timer and the delays. If the SoC does not normalise the clock, the console runs at 124 800
   baud instead of 115 200 and every delay is 8 % short.
6. **R_TWI0 clock.** The polling driver sets its divider for 100 kHz from a 24 MHz bus clock;
   the actual bus clock is not known. Any plausible value gives a rate the PMIC accepts.
7. **What else the vendor loader sets up.** boot0 and `ddr.bin` do more than DRAM (secure
   memory setup, pad voltage settings). Whether BL31 or U-Boot rely on any of it is not known.
8. **TF-A on this board.** The branch was tested by its author for power on and off on a
   Radxa board; BL31 in DRAM on the A733 has not run anywhere.
