# First session with the board: mainline firmware bring-up

A plan for the first time the mainline firmware meets an Orange Pi Zero 3W. It has not been
done: every expectation below comes from reading code, not from a board. Read
`docs/boot-chain-bases.md` first, in particular "Not known": most ways this can stop are
listed there.

The board cannot be bricked by this. It boots from the microSD card first, there is no
firmware in on-board flash, and FEL loads code into RAM only. Removing the card and inserting
the vendor card is the way back at any point.

## What you need

- The board, its power supply, and a USB-C cable to a computer for FEL.
- A 3.3 V USB serial adapter on the 40-pin header: pin 6 ground, pin 8 board TX, pin 10 board
  RX (`README.md`, "Serial console"). Without it nothing below can be observed.
- Two microSD cards: the vendor image (the released `nixos-a733-vendor` image, known to boot)
  and a spare one.
- A way to short the `BOOT` pad to ground while powering on: the board has no buttons, `BOOT`
  is the SoC's FEL line on a test pad next to a ground pad (`docs/zero3w-wiring.md`, sheet 5).
- `sunxi-fel` with A733 support. Upstream sunxi-tools does not have it yet: build branch `A733`
  of `github.com/dlan17/sunxi-tools` (the SoC entry was added there on 2026-11-06).

## Step 0: record the vendor boot

Before anything else, boot the vendor card with the serial adapter attached and save the whole
log. It is the reference for everything after:

- that the adapter, the pins and the terminal work, and at which baud rate;
- the lines of boot0's DRAM init: `DRAM CLK`, the four `DRAM Pstate ... training` lines,
  `Actual DRAM SIZE`, and the line that names the selected parameter block;
- the size the vendor chain finds.

Serial settings: 115200 baud, 8 data bits, no parity, one stop bit, no flow control. The
crystal is 26 MHz, but that does not change the baud rate: the boot ROM's reference PLL makes
24 MHz of it, and the console, like boot0's, divides that (`docs/dram-init-spec.md`,
"Reference clock").

## Step 1: build

On an aarch64 machine with Nix, or on x86-64 with aarch64 emulation:

```
nix build .#firmware -o firmware
python3 ci/check-firmware.py firmware/u-boot-sunxi-with-spl.bin
```

`firmware/` then holds `u-boot-sunxi-with-spl.bin` (for the card), `sunxi-spl.bin` (the SPL
alone, for FEL), and `u-boot-spl` with its map (the SPL's ELF). These files hold the PHY
training firmware: they are for your own board, not for publishing.

If the board's memory strap cannot be trusted yet (step 2 shows it), build with the parameter
block fixed. The index is in `docs/dram-init-spec.md`: 0 for 4 GiB, 1 for 6 GiB, 2 for 8 GiB,
5 for 12 GiB. Add `CONFIG_SUNXI_A733_DRAM_STRAP=5` to the defconfig in the U-Boot patch, or
set it with `extraConfig` of the derivation.

One more switch for this session. Before DRAM init the SPL sets the system supply, starts the
CPU PLLs and switches the bus clock, as boot0 does (`docs/boot-chain-bases.md`, the table of
what boot0 does). If the SPL stops between `DRAM:` and the strap line, or the console turns
to garbage there, build with these steps left out and try again:

```
# CONFIG_SUNXI_A733_VENDOR_CLOCKS is not set
```

in `configs/orangepi_zero3w_defconfig` (U-Boot patch 0004), or the same line through
`extraConfig`. The SPL then runs on the clocks the boot ROM left, as the first version of
this firmware did. Say which of the two builds a log comes from.

## Step 2: the SPL alone, over FEL

This is the first and most informative test: it runs DRAM init and nothing else, without
touching a card.

1. Remove the card. Hold `BOOT` to ground, apply power, release. The board enumerates as a
   USB device (`1f3a:efe8`).
2. `sunxi-fel version` should name the A733 (SoC ID `0x1903`). If the tool does not know the
   SoC, it is the wrong build of sunxi-tools.
3. Start the serial capture, then: `sunxi-fel -v spl firmware/sunxi-spl.bin`

Expected on the serial console, in this order:

| Output | Meaning |
|---|---|
| `U-Boot SPL 2026.07...` | the BROM loaded the SPL and the switch to AArch64 worked |
| `DRAM:` | the SPL reached DRAM init |
| `DRAM: dcdc2 code 0x1e, was 0x..` | the PMIC answered; the system supply is at 800 mV. `was` is what the PMIC had |
| `DRAM: oscillator select 2` | bits 14–15 of `0x07090160`: 2 is 26 MHz, what the schematic says. 0 or 3 would be 24 MHz, 1 is 19.2 MHz |
| `DRAM: strap at <n> mV, index <i>` | the CPU PLLs locked and the bus clock switched without a message; the memory strap was read. Compare `<i>` with the block the vendor log names |
| `DRAM: dcdc7 <mV> mV: code 0x.., was 0x.., on` and the same for `eldo1`, `dcdc6` | each rail: what is asked for, what the PMIC had. `eldo1 1080 mV` has code `0x17`, which is 1075 mV, as in the vendor loader |
| `DRAM_VCC set to (mV) 560`, `DRAM CLK (MHz) = 2040` or `2400` | the parameter block in use |
| `Training result is = 7`, `DRAM Pstate trained, frequency (MHz) ...`, four times | the PHY firmware trained each Pstate; 7 is success |
| `DRAM SIZE (MiB) = ...`, `DRAM simple test OK` | size and memory test |
| ` <size> MiB` | the SPL accepted the result |

After that the SPL returns to FEL: `sunxi-fel` reports success and the board stays in FEL
mode. With DRAM up, `sunxi-fel` can read and write it; a quick check is to write a file to
`0x42000000` and read it back.

Where it can stop, and what that says:

| Last output | Likely cause | What to capture |
|---|---|---|
| nothing at all | serial wiring; or the SPL was not started: too large for the tool, the early stack at `0x90000` is not usable, or the AArch64 switch failed | the full `sunxi-fel -v` output |
| garbage from the first character | serial settings or wiring: the vendor log of step 0 says whether the adapter works | the settings used |
| text, then garbage or silence after `DRAM: oscillator select` | the CPU PLLs or the bus clock switch: build without `SUNXI_A733_VENDOR_CLOCKS` | the last readable line |
| `DRAM: system supply setup failed` | the PMIC answered at first contact but not here | the line and the ones before it |
| `DRAM: CPU PLL <n> does not lock, CPU clocks left alone` | not a stop: the SPL goes on with the cores on the boot ROM's clock. The factor or the sequence is wrong for this board | the line, the oscillator line |
| `DRAM: bus clock update does not finish` | not a stop either; the register did not take the update | the line |
| `DRAM: no answer from the PMIC` or `unexpected PMIC, ID 0x..` | R_TWI0 (pins, clock gate, the polling driver), or not an AXP318W | the line; the vendor log's PMIC lines |
| `DRAM: no reading from the memory strap` | the GPADC gave no data | build with the strap index fixed and go on |
| `DRAM: <rail>: PMIC read failed` | R_TWI0: pins, clock gate, or the polling driver | the error code in the line; the vendor log's PMIC lines |
| the `was 0x..` values differ from the codes asked for | not a failure: it shows what the PMIC had. Compare with the vendor's voltages before trusting the new ones | all three lines |
| `DRAM: timeout waiting on register 0x...` | the address says where: `0x2002020` the DDR PLL lock, `0xa1.....` or `0xa5.....` a controller, `0xa9.....` the PHY | the address, and everything printed before it |
| `Training result is = <not 7>` | the PHY firmware ran and failed: wrong parameter block, rails, or a difference from the vendor sequence on real hardware | the number, the Pstate, the strap line |
| `DRAM: simple test failed` | training reported success but memory does not hold data | everything |
| ` 0 MiB` and a hang | DRAM init returned failure; the line above says why | everything |

If training fails with the strap read from the board, repeat with the index fixed to the block
the vendor log names. If it then trains, the strap reading is the problem, not the DRAM init.

## Step 3: U-Boot over FEL

With step 2 working, the rest of the chain can be tried without a card:

```
sunxi-fel -v uboot firmware/u-boot-sunxi-with-spl.bin
```

`sunxi-fel` runs the SPL, loads the images of the FIT (BL31 to `0x40000000`, U-Boot to
`0x4a000000`) and starts BL31. Whether the tool finds the FIT in this image is not verified:
it sits `0x4a000` into the file, not right behind the SPL. If it does not, the card is the
next step.

Expected: after the SPL's output, `NOTICE:  BL31: v2.12...` and the lines of the Allwinner
platform, then `U-Boot 2026.07...`, `DRAM:  12 GiB` (or the board's size), the USB scan
(`Bus usb@4101000: USB EHCI 1.00`), and a prompt.

At the prompt:

- `reset` should restart the board through the watchdog.
- `poweroff`, where U-Boot has the command (it is not in every build; Linux's `poweroff` in
  step 5 goes the same way), should turn the board off through the PMIC: the LED goes dark,
  and power has to be removed and applied again to start. If the board stays on, BL31 prints
  why on the console.
- USB: only the port the board is powered through is driven, so a keyboard or a stick needs
  a hub or adapter that feeds power into that port (`docs/boot-chain-bases.md`, "USB in
  U-Boot"). `usb tree` lists what is found.

| Stops after | Likely cause |
|---|---|
| the SPL's output, no `BL31` | the tool did not load or start the FIT images; BL31 in DRAM does not start on this SoC |
| `BL31` lines, no `U-Boot` | BL31's setup of the cores or the GIC, or the jump to `0x4a000000` |
| `U-Boot` banner, then a hang | the device tree: PMIC, MMC; or the USB scan that runs before the prompt. To rule USB out, build without `CONFIG_USB_KEYBOARD` (no scan before the prompt) |

## Step 4: from the card

```
sudo dd if=firmware/u-boot-sunxi-with-spl.bin of=/dev/sdX bs=1K seek=128 conv=fsync
```

on the spare card (any partition table whose first partition starts at 32 MiB or later; an
image built by this flake has that). Insert, power on without `BOOT`.

Expected: the same SPL output as in step 2, then `Trying to boot from MMC1`, then BL31 and
U-Boot as in step 3. In U-Boot: `mmc info`, `mmc part`, `bdinfo` (the DRAM size and the
reserved 256 KiB at `0x40000000`).

| Stops after | Likely cause |
|---|---|
| nothing on serial, though step 2 worked | the BROM did not accept the image: offset on the card, or the eGON header. `ci/check-firmware.py` checks the header; check the card with `dd ... skip=128 count=1 \| xxd \| head` for `eGON.BT0` at byte 4 |
| the SPL's DRAM output, then `Trying to boot from MMC1` and an error or a hang | the card: the SPL clocks it from the 24 MHz oscillator as boot0 does; pins, gate and reset are U-Boot's |
| U-Boot starts but `mmc info` fails or is slow | U-Boot proper takes faster card clocks from PLL_PERI0, which nobody on this chain programs ("Not known", item 2) |
| `mmc_load_image_raw_sector: mmc block read error` or a bad FIT | the SPL looks for the FIT at sector `0x250` + 240 from the start of the card's image offset; compare with `ci/check-firmware.py` |

## What to send back

For any stop, the things that make it diagnosable from a distance:

1. The complete serial log from power-on, as text, with the baud rate used.
2. The complete vendor boot log of step 0.
3. The output of `sunxi-fel -v ...` for FEL runs.
4. The commit of this repository the firmware was built from, and whether the strap index
   was fixed.
5. If DRAM init timed out: the register address in the message.

With DRAM working and the board in FEL mode, registers can be read from the computer:
`sunxi-fel readl 0x02002020` (DDR PLL), `sunxi-fel readl 0x020020a0` (PLL_PERI0, for the card
clock question). After a vendor boot stopped at the U-Boot prompt, `md.l` at the same
addresses gives the values the vendor chain leaves, which is what our chain has to match.

## Back to the vendor card

Power off, swap the card for the vendor card, power on. Nothing the mainline firmware does
persists across a power cycle: PMIC rail settings are volatile, and nothing is written to
flash. If a rail was set wrongly, a power cycle restores the PMIC's own defaults.

## Step 5: the kernel

Only with step 4 working. `nix build .#sd-image-generic` builds the whole card: the firmware
at 128 KiB and NixOS on Linux 7.3.4 with the A733 patches and the board's device tree
(`docs/kernel-zero3w.md`). Like the firmware, this image holds the PHY training firmware and
is for your own board.

Write it to the spare card and boot. Expected: the SPL, BL31 and U-Boot as before, the
extlinux menu, `Starting kernel ...`, then kernel messages on the same console and a login
prompt. The device tree was written from the schematic and compiled, nothing more, so expect
it to stop somewhere:

| Stops after | Likely cause | What to capture |
|---|---|---|
| `Starting kernel ...`, nothing more | the console (`console=ttyS0,115200`, UART0 in the tree), or the memory BL31 occupies. Add `earlycon` to the kernel command line at the extlinux prompt | the U-Boot output up to that line |
| kernel messages, then silence around the clock or regulator lines | a rail or clock the kernel turned off: the tree names only three PMIC outputs, all always on, and leaves the rest alone, but an unused clock can still be gated | the last 50 lines; retry with `clk_ignore_unused pd_ignore_unused` |
| `Waiting for root device` | the card: controller, pins, card detect (PF6, low with a card). `broken-cd` in place of `cd-gpios` tells the two apart | the `mmc` lines of the log |
| a login prompt | the tree is good enough to work from. `dmesg`, `/sys/kernel/debug/clk/clk_summary`, `/sys/kernel/debug/regulator/regulator_summary` and `lsusb` are the next things to save | all four |

The kernel's device tree reserves `0x40000000` to `0x40040000` for BL31, and U-Boot does not
hand over a running watchdog (`docs/boot-chain-bases.md`).
