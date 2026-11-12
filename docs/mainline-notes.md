# Mainline variant: research notes

State of the A733 outside the vendor tree, checked on 2026-11-12, and how it
maps onto the empty slots of this repository (`patches/index.json`,
`bootloader/sources.json`). Revisions are full or short commit ids read from
the repositories on that date. Nothing here was run on the board.

## Summary

| Slot in this repo | State | Candidate |
|---|---|---|
| `kernel/version.json` (7.3.4) | pinned | matches the base of patch stack A exactly |
| `patches/` | empty | stack A: 379 patches in 104 series on 7.3.4 |
| second kernel track (latest LTS) | no structure yet | nixpkgs longterm is 6.18.63; no single stack covers 6.18 and 7.3 |
| `bootloader/sources.json` `tf-a` | null | not in upstream TF-A; two out-of-tree ports |
| `bootloader/sources.json` `u-boot` | null | not in upstream U-Boot; two trees |
| `bootloader/sources.json` `boot0` | null | see "Boot chain": boot0 does not load a raw `u-boot-sunxi-with-spl.bin` |
| Zero 3W device tree, mainline bindings | does not exist anywhere | to be written from the vendor device tree |
| AIC8800 Wi-Fi on a mainline kernel | no in-tree driver | out-of-tree module |

## Upstream status

- **Linux**: A733 not merged as a platform. Series on linux-sunxi during 2026: CCU and PRCM (Junhui Liu, v3, 2026-09-04),
  DMA (Yuanshen Cao, v4, 2026-08-26), RTC CCU (v7, 2026-07-23), pinctrl (Andre Przywara), SoC and Cubie A7S device tree
  (Enzo Adriano, 2026-06). Stack A's `patches/series` marks six series as applied for 7.4, pinctrl among them: they drop
  out of `patches/` when `kernel-bump` reaches 7.4.
- **U-Boot**: `MACH_SUN60I_A733` is absent from master. Yixun Lan's series "sunxi: Add support for A733 SoC" is at v3
  (2026-01-13), reviewed by Andre Przywara. It relies on vendor code for DRAM init: there is no open DRAM driver.
- **TF-A**: `plat/allwinner/` on master `d70b52d` (2026-11-11) has `sun50i_a64`, `sun50i_h6`, `sun50i_h616`,
  `sun50i_r329`, `sun50i_a133`. No A733, no A523. No A733 series was found on review.trustedfirmware.org by search.
- **nixpkgs** (nixos-unstable): `linux_default` = 6.18 (6.18.63), `linux_latest` = 7.3 (7.3.4), testing 7.4-rc2.
  No A733 U-Boot package. `ubootOrangePiZero3` is the **H618** Orange Pi Zero 3 and `ubootRadxaZero3W` is RK3566:
  neither is this board.

## Kernel patch stacks

| | Stack A: `DockSeed/a7s-linux-mainline` | Stack B: `jonas5/Allwinner-A733-kernel` |
|---|---|---|
| Revision read | `da00673e098b` | `b15a2800ffd6` |
| Base | Linux 7.3.4 | linux-6.18.y |
| Form | 379 patches, 104 series, one directory per series, order in `patches/series`; each series has author, version, upstream state and lore link in a comment | one 10 892-line patch plus about 20 add-on patches and out-of-tree drivers under `drivers/extra/` |
| Boards | Radxa Cubie A7S only | Orange Pi 4 Pro (validated), Cubie A7A/A7S; lists the Zero 3W as awaiting hardware |
| Works (per its README) | pinctrl, clocks, power domains, PMIC, SD/eMMC, Ethernet, USB 2/3, PCIe/NVMe, DMA, IOMMU, thermal, cpufreq, CPU idle, display, DP over USB-C, GPU | broad; includes an AIC8800D80 SDIO fix, NPU and VPU patches |
| Missing | AIC8800 Wi-Fi, video decode, G2D, camera; suspend disabled | not assessed |
| Binaries in repo | none | PowerVR firmware, a Radxa bootloader image |
| Licence | GPL-2.0-only | GPL-2.0-or-later |
| Maturity | first commit 2026-11-03, one author; per its README, not reviewed by kernel developers | first commit 2026-08-18, one author, daily changes |

Mapping onto `patches/`:
- Stack A fits `kernel/version.json` as pinned and the `index.json` schema: the comment above each series gives `origin`,
  and its ordering (bindings, drivers, device tree, defconfig) gives the order. Import it with a script, not by hand.
- Suggested layers: `base` = pinctrl, CCU/PRCM, power domains, PMIC, MMC, USB, PCIe, DMA, IOMMU, thermal, cpufreq, watchdog;
  `optional` = display, DP, GPU, audio, NPU, camera and device-tree-only items.
- Its board patches (`a733-a7s-*`, `a733-board`) describe the Cubie A7S. They are a model for the Zero 3W device tree, not a substitute.
- Stacks A and B use different drivers and bindings. Using A on 7.3 and B on 6.18 means two device trees for one board.

## Boot chain

Two working chains exist for A733 boards. They are not interchangeable, and the current `bootloader/` layout
(boot0 raw at an offset, then `u-boot-sunxi-with-spl.bin` raw at an offset) matches neither as it stands.

**Chain 1: SPL with the DRAM blob, no boot0** (`DockSeed/a733-bootchain`, `b6f6872be250`, tested on Cubie A7S)

```
BROM -> U-Boot SPL (vendor ddr.bin linked in) -> BL31 (TF-A from source, SRAM 0x62000) -> U-Boot -> kernel
```

- One file, `u-boot-sunxi-with-spl.bin` (about 1.2 MiB), at **128 KiB** (sector 256). First partition at 16 MiB or later.
- U-Boot: `radxa/u-boot` branch `u-boot-dlan17`, commit `9da4b3e82d64` (v2026.07 + 73 commits), plus 18 patches. UEFI and extlinux work; `boot_targets = fel mmc_auto nvme0 usb0 pxe dhcp`.
- TF-A: upstream master `3d425f4f4598` plus 17 patches (A733 platform on upstream Allwinner code, generic GIC, PSCI CPU_ON and CPU_SUSPEND, A76 errata).
- Only binary: `awbin/a733/ddr.bin` from `radxa-pkg/u-boot-dlan17` commit `b1cec0a90c79`, sha256 `d89804f404f2eef6ef5b03d82a310ef0906c4db8ded760be221b131f5c813a05`, 232 409 bytes, no licence text.
  Its README asks not to publish built output, because the blob has no redistribution grant. That applies to Cachix and Releases too.
- No boot0, no boot_package, no SCP, no packing tool.
- U-Boot starts the watchdog and hands it over running: the kernel device tree must drive `WDT_CPUS`, or the board resets about 16 s into boot.
- Open question for this board: whether Radxa's `ddr.bin` trains the Zero 3W's LPDDR5. Untested.

**Chain 2: vendor boot0 loading mainline U-Boot** (`dlan17/a733`, `boot-sdcard.md`, `0feb1a77f9b1`, written for Cubie A7A)

- boot0 at sector 256 (the BROM reads 8 KiB and 128 KiB).
- boot0 loads a **`boot_package.fex`** from sector 32800 (16 400 KiB), not a raw U-Boot image. The package is built with the vendor
  `dragonsecboot` from two items: U-Boot with SPL, prefixed by the first 1600 bytes of the vendor U-Boot binary as header with the
  load address at offset `0x2c` patched to `0x48000000`, and the FIT (`u-boot-sunxi-with-spl.fit.fit`) as the `dtb` item.
- U-Boot: `dlan17/u-boot`, branches `allwinner/A733/boot-2026.04` (`c85cef956235`), `allwinner/A733/boot` (`24da4dae7637`), `allwinner/A733/next` (`165f07a69706`).
- TF-A: `dlan17/trusted-firmware-a`, branch `A733` (`f4c0b0dba78a`), `PLAT=sun60i_a733`.
- This repository already has what the chain needs on the vendor side: the Zero 3W boot0 (known to train this board's DRAM),
  `dragonsecboot` and `vendor/boot-package.nix`.

Consequences for `bootloader/`:
- Chain 1 needs no `boot0` entry and one raw write at 128 KiB, plus patch lists for TF-A and U-Boot and the blob as a fixed-output fetch.
- Chain 2 needs a packing step between U-Boot and the image, at 16 400 KiB, and boot0 at 8 or 128 KiB.
- `sdImage.firmwarePartitionOffset = 32` (MiB) is compatible with both.
- Neither tree has a Zero 3W defconfig or U-Boot device tree. SD on `mmc0` and UART0 are the minimum.
- Bring-up can be done over FEL and from a spare card: the board boots from SD first, so a bad boot chain does not brick it.

## Board facts that matter here

- LPDDR5, microSD, two USB-C (one with DP alt mode), mini HDMI, PCIe 3.0 x1 on FPC, AIC8800 Wi-Fi and Bluetooth.
- **No wired Ethernet.** Until an AIC8800 module builds against the mainline kernels, network on a mainline image means a USB Ethernet adapter (`r8152`, `ax88179`).
- The only description of the board's wiring is the vendor device tree, `sun60i-a733-orangepi-zero3w.dts` in the vendor kernel pinned under `vendor/`.

## Easy to get wrong

- `ubootOrangePiZero3` in nixpkgs is the H618 Orange Pi Zero 3. `ubootRadxaZero3W` is RK3566. Neither is this board.
- The A733 is not in upstream Linux, U-Boot or TF-A: no nixpkgs package and no upstream defconfig exist.
- Vendor boot0 loads a packed `boot_package.fex` at 16 400 KiB, not a raw `u-boot-sunxi-with-spl.bin`.
- The BROM reads the first stage at 8 KiB and at 128 KiB.
- The Zero 3W has no wired Ethernet, and no mainline kernel has an AIC8800 driver.
- No mainline-style device tree for the Zero 3W exists. The vendor device tree is the wiring reference.
- The two community kernel stacks (7.3 and 6.18) use different bindings: one device tree does not serve both.
- A boot chain built with Radxa's `ddr.bin` contains a blob with no redistribution grant: keep it out of Cachix and Releases.
- Revisions here are dated. Re-check them before pinning.

## Open decisions

These are the maintainer's, not the implementer's:

- which patch stack feeds `patches/`, and how the LTS track gets its patches;
- which boot chain the mainline variants use (chain 1 or chain 2);
- anything that changes what is published: images, cache contents, binaries in the tree.

## Upstreaming

- `nixos-hardware` (see its `radxa/` and `rockchip/` modules) takes hardware that mainline Linux and nixpkgs packages support. Nothing here qualifies yet.
  Its pattern is worth keeping in mind for later: board module -> SoC module -> family module, firmware as a package option, image hook writing it.
- Order that makes sense: device tree for the Zero 3W to linux-sunxi, U-Boot board file once A733 lands there, then a nixpkgs U-Boot package and a nixos-hardware module.
- Tow-Boot is not an option: last commit 2025-01-17, U-Boot 2023.07, Allwinner support ends at A64/H5.

## Sources

- https://github.com/DockSeed/a7s-linux-mainline
- https://github.com/DockSeed/a733-bootchain
- https://github.com/jonas5/Allwinner-A733-kernel
- https://github.com/dlan17/a733 , https://github.com/dlan17/u-boot , https://github.com/dlan17/trusted-firmware-a
- https://lists.denx.de/pipermail/u-boot/2026-January/607457.html
- https://github.com/ARM-software/arm-trusted-firmware (master, `plat/allwinner/`)
- https://github.com/NixOS/nixos-hardware/tree/master/radxa
- https://www.cnx-software.com/2026/04/15/orange-pi-zero-3w-an-allwinner-a733-sbc-in-raspberry-pi-zero-form-factor/
