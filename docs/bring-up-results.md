# First session with the board: results

2026-11-13, Orange Pi Zero 3W, 12 GiB, over FEL with a serial adapter, no card in the slot.
The plan is `docs/bring-up.md`; this is what happened. Logs are in `docs/bring-up-logs/`.

Firmware: `develop` at `0e5027e`. It was not built with Nix: U-Boot was cross-compiled in a
Debian container (gcc 14.2) from the pinned revision with the five patches (for the power-off test, with `CONFIG_SYSRESET_PSCI=y` added), `BL31` taken from
the `bl31.elf` of the CI artifact, the DRAM payload packed from the vendor boot0 with
`bootloader/dram/tools/payload-pack`. The kernel and the device tree are the ones CI built,
fetched from the binary cache.

## What works

| Step | Result |
|---|---|
| Vendor boot (step 0) | boot0 selects parameter block 5, trains at 1165, 816, 408 and 2040 MHz, finds 12288 MiB |
| SPL over FEL (step 2) | all lines of the table in `bring-up.md` appear in order: PMIC answers, `oscillator select 2`, `strap at 1313 mV, index 5`, four times `Training result is = 7`, `DRAM SIZE (MiB) = 12288`, `DRAM simple test OK` |
| The same without `SUNXI_A733_VENDOR_CLOCKS` | the same result. The CPU PLLs, the system supply and the bus clock switch make no difference to DRAM init |
| DRAM from the computer | 4 MiB of random data written to `0x42000000` over FEL and read back identical |
| BL31 in DRAM | starts at `0x40000000`, detects the A733, finds U-Boot's device tree |
| U-Boot | reaches the prompt; EHCI and OHCI start; `reset` restarts the board through the watchdog |
| Kernel 7.3.4 with the Zero 3W device tree | started with `booti` from DRAM: eight cores come up through PSCI, the AXP318W is found, the pin controllers, the RTC and the SD controller probe. It stops at the root mount, as it must with no initrd and no card |
| Memory up to 12 GiB | from the U-Boot prompt, five different words written at `0x60000000`, `0xc0000000`, `0x140000000`, `0x240000000` and `0x33ffffff0` read back unchanged: no aliasing between them, although U-Boot itself counts 2 GiB |
| `poweroff` through the PMIC | with `CONFIG_SYSRESET_PSCI=y` in U-Boot: after `poweroff ...` the console is silent and the board is gone from USB. `reset` still works with that option. No LED was watched |
| Reboot from the kernel | `panic=-1` restarts the board, which comes back in FEL |

## What does not

**The SPL does not return to FEL.** `return_to_fel` in `arch/arm/cpu/armv8/fel_utils.S` has no
case for the A733 and writes the hotplug entry to the address of older SoCs. The boot ROM
starts over and enters FEL again, but answers no USB request until the computer resets the
port (`libusb_reset_device`). So `sunxi-fel spl` reports a timeout and `sunxi-fel uboot`
cannot work. DRAM stays trained across that restart. Open: the address of the A733's hotplug
flag and entry.

**U-Boot shows `DRAM: 2 GiB` when started this way.** It reads the size from the SPL header
in SRAM, and the boot ROM's restart clears it. A boot from the card keeps the header; that
was not tried.

**Never write to `0x47000`–`0x48c00` over FEL.** The boot ROM's FEL code has its stack there.
One write of 96 bytes to `0x47000` stopped FEL until the next power cycle.

**`poweroff` in U-Boot did nothing** with the defconfig as it was: it printed `poweroff ...`
and returned to the prompt, because `CONFIG_SYSRESET_PSCI` was off and the call never reached
BL31. The defconfig now sets it (U-Boot patch 0004).

Smaller findings in the kernel log:

- `sun50i-cpufreq-nvmem: probe ... failed with error -2`;
- `7025000.pinctrl: supply vcc-pl not found, using dummy regulator`: the device tree lacks
  the supply of bank PL.

## How the chain was started

`sunxi-fel` is branch `A733` of `dlan17/sunxi-tools` (`6362299`). With the board in FEL:

```
sunxi-fel spl sunxi-spl.bin             # trains DRAM; the tool then times out
# wait 7 s, reset the USB port from the computer, then:
sunxi-fel write 0x40000000 bl31.bin
sunxi-fel write 0x4a000000 u-boot.bin   # U-Boot with its device tree appended
sunxi-fel write 0x50000000 Image
sunxi-fel write 0x4fa00000 sun60i-a733-orangepi-zero3w.dtb
sunxi-fel reset64 0x40000000
```

At the U-Boot prompt:

```
setenv bootargs console=ttyS0,115200 earlycon=uart8250,mmio32,0x02500000 loglevel=8 panic=-1
booti 0x50000000 - 0x4fa00000
```

The 75 MiB kernel takes about three minutes to write over FEL.

## Not done

- Step 4, the firmware from a card, and with it `Trying to boot from MMC1` and the card clock.
- Step 5, the generic image.
- Memory above 2 GiB under the kernel, and a memory test longer than five words.
- USB devices in U-Boot: only the root hubs were seen.
- A firmware built by Nix on the board.
