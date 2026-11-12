# Research

Status as of 2026-11-12. Each item: answer, evidence, consequence. The Debian and Talos items of the
earlier revision are gone with those flavors (SPEC v0.3).

| # | Status | Summary |
|---|---|---|
| R1 | closed | Vendor kernel = `orangepi-xunlong/linux-orangepi` branch `orange-pi-6.6-sun60iw2`, 6.6.98. Reference only, not used |
| R2 | closed | Vendor boot chain: boot0 + boot_package (U-Boot 2018.05 aarch32, TF-A 2.5 blob, SCP blob). Reference and fallback only |
| R3 | closed | `orangepi-build` has the board and family config; source of blobs and of the vendor device tree |
| R4 | closed for now | A733 not in mainline Linux or U-Boot; series under review; two out-of-tree kernel stacks exist |
| R6 | partial | Board facts collected from reviews; RAM size and DRAM parameters to confirm on the unit |
| R9 | closed | TF-A upstream has no A733 platform; two out-of-tree ports exist |
| R10 | closed | A source-built firmware chain exists for a sibling board (Cubie A7S); needs a Zero 3W port |
| R11 | closed | disko works as is once firmware sits at 128 KiB; no GPT tricks needed |
| R12 | closed | nixpkgs: `linux_default` 6.18.63, `linux_latest` 7.3.4, `pkgs.lix` present, extlinux builder lists specialisations |

---

## R1 to R3: vendor stack (reference)

- Kernel: `orangepi-xunlong/linux-orangepi`, branch `orange-pi-6.6-sun60iw2`, HEAD `2ac08e8c` (2026-11-06), version 6.6.98 while upstream 6.6.y is at 6.6.162.
- Config: `orangepi-build/external/config/kernel/linux-sun60iw2-current-a733.config`.
- Device tree: `allwinner/sun60i-a733-orangepi-zero3w.dtb` (vendor bindings). It is the only description of the board's wiring: the input for our own device tree.
- U-Boot: `orangepi-xunlong/u-boot-orangepi` branch `v2018.05-sun60iw2`, `sun60iw2p1_t736_defconfig`, aarch32, no EFI.
- Layout: `boot0_sdcard.fex` at 8 KiB; `boot_package.fex` (u-boot + monitor + scp) at 16 400 KiB = sector 32800; rootfs at 32 MiB; MBR.
- Blobs in `orangepi-build` `external/packages/pack-uboot/sun60iw2/bin/`: `boot0_sdcard_orangepizero3w.fex` (and a `_1800M` variant), `monitor.fex` (TF-A v2.5 debug, `-dirty`), `scp.fex`. No licence file.
- Console `ttyS0,115200`, earlycon `sunxi-uart,0x02500000`. Wi-Fi/BT modules `aic8800_fdrv`, `aic8800_btlpm`.
- Armbian added the Zero 3W on 2026-07-06 (armbian/build#10103) on the same vendor kernel and blobs.

## R4: mainline status

U-Boot:
- Yixun Lan, "sunxi: Add support for A733 SoC", v3 2026-01-13, reviewed by Andre Przywara. Not merged: `MACH_SUN60I_A733` is absent from U-Boot master (checked 2026-11-12), and nixpkgs 26.05 (U-Boot 2026.04) has no A733 package.
- Dev branches: `dlan17/u-boot` `allwinner/A733/next`, `allwinner/A733/boot-2026.04`.
- `ubootOrangePiZero3` in nixpkgs is the **H618** Orange Pi Zero 3, a different board. `ubootRadxaZero3W` is RK3566.

Kernel (linux-sunxi, under review during 2026): CCU + PRCM (Junhui Liu, v3 2026-09-04), DMA (Yuanshen Cao, v4 2026-08-26),
RTC CCU (v7 2026-07-23), pinctrl (Andre Przywara, RFC 2025-08), SoC + Cubie A7S DTS (Enzo Adriano, 2026-06).

Out-of-tree kernel stacks:

| | Stack A: `DockSeed/a7s-linux-mainline` | Stack B: `jonas5/Allwinner-A733-kernel` |
|---|---|---|
| Base | Linux 7.3.4 | linux-6.18.y |
| Form | ~125 patches with a `series` file, each with author and upstream state | one 10 892-line patch + about 20 add-on patches + out-of-tree drivers |
| Boards | Radxa Cubie A7S (tested) | Orange Pi 4 Pro (validated), Cubie A7A/A7S; Zero 3W "awaiting hardware" |
| Works | pinctrl, clocks, power domains, PMIC, SD/eMMC, Ethernet, USB 2/3, PCIe/NVMe, DMA, IOMMU, thermal, cpufreq, display, DP over USB-C, GPU (firmware missing from linux-firmware) | broad, incl. AIC8800 SDIO fix, NPU, VPU patches |
| Missing | AIC8800 Wi-Fi, video decode, G2D, camera, suspend | not assessed in detail |
| Blobs | none; refuses to release if anything but kernel is in the tarball | PowerVR firmware and a Radxa bootloader binary in the repo |
| Licence | GPL-2.0-only | GPL-2.0-or-later |
| Age | first commit 2026-11-03, 19 commits, one author | first commit 2026-08-18, 140 commits, pseudonymous author, daily changes |
| Notes | patches written with an AI assistant, not yet reviewed by kernel developers (stated in README); reproducible build, checkpatch gate | daily image builds in GitHub Actions |

Consequence: `latest` (7.3) maps onto stack A and `lts` (6.18) onto stack B, but the two use different drivers and
bindings. One stack for both tracks is the cleaner target (SPEC D1). Neither has a Zero 3W device tree: that is our work.

## R6: board facts

- LPDDR5 at 4800 MT/s, variants 1 to 16 GB; microSD; optional eMMC footprint; Wi-Fi 6 + BT 5.4 (AIC8800); two USB-C (one with DP alt mode); mini HDMI; PCIe 3.0 x1 on an FPC connector.
- **No wired Ethernet** (the older Zero 3 had it). Network at bring-up = USB Ethernet adapter.
- To confirm on the unit: detected RAM, which boot0 variant the vendor image uses, DRAM parameters.

## R9: TF-A

- Upstream master (`d70b52d`, 2026-11-11): `plat/allwinner/` = `sun50i_a64`, `sun50i_h6`, `sun50i_h616`, `sun50i_r329`, `sun50i_a133`. No A733, no A523.
- No A733 series found on review.trustedfirmware.org by search (absence not proven).
- Out of tree: `dlan17/trusted-firmware-a` branch `A733` (`PLAT=sun60i_a733`); `DockSeed/a733-bootchain` carries 17 patches on upstream master `3d425f4f` (A733 platform on upstream Allwinner code and the generic GIC driver, PSCI CPU_ON/CPU_SUSPEND, A76 errata).
- BL31 load address: SRAM `0x62000`.

## R10: firmware chain without vendor boot0

`DockSeed/a733-bootchain` (GPL-2.0, last commit 2026-11-04), for the Cubie A7S:

```
BROM -> U-Boot SPL (vendor DRAM blob ddr.bin) -> BL31 (TF-A from source) -> U-Boot -> kernel
```

- Output: one `u-boot-sunxi-with-spl.bin` (about 1.2 MiB) written at **128 KiB** (sector 256, where the BROM also looks); first partition at 16 MiB or later.
- U-Boot = Radxa's tree (v2026.07 + 73 commits) + 18 patches. `boot_targets = fel mmc_auto nvme0 usb0 pxe dhcp`. UEFI boot of another distribution's image was tested; extlinux is the documented path.
- No boot0, no boot_package, no SCP, no ARISC start, no Allwinner packer.
- Only blob: `awbin/a733/ddr.bin` from `radxa-pkg/u-boot-dlan17` (commit `b1cec0a9`, sha256 `d89804f4...13a05`), closed, no redistribution grant: built outputs must not be published.
- U-Boot starts the watchdog and hands it to Linux; without a device tree that drives `WDT_CPUS` the board resets about 16 s into boot.
- Tested on two Cubie A7S units (6 and 8 GiB LPDDR5). Not tested: eMMC boot, suspend, any other board.

Alternative documented by Yixun Lan (`dlan17/a733`, `boot-sdcard.md`): vendor boot0 at sector 256 + `boot_package.fex` at sector 32800
containing mainline U-Boot, packed with the vendor `dragonsecboot` tool. Keeps boot0 (known to train the board's DRAM) at the price of the packer.

Consequence: the target chain is portable to the Zero 3W with a board defconfig and DTS. The open question is whether Radxa's
`ddr.bin` trains the Zero 3W's LPDDR5; if not, Orange Pi's boot0 is the fallback SPL.

## R11: disko

Checked at `nix-community/disko` `1dd30c2` (2026-11-10):
- `lib/types/gpt.nix` creates the table with `sgdisk --clear` and exposes no option for the entry count. Hooks exist (`preCreateHook`, `postCreateHook`) and `disko.imageBuilder.extraPostVM` runs after the image is built.
- `lib/types/table.nix` (MBR) prints a deprecation warning: do not build on it.
- A 128-entry GPT occupies sectors 1 to 33 (up to 17 KiB). Firmware at 128 KiB does not collide, so the Tow-Boot trick (48 entries, for an SPL at 8 KiB) is unnecessary. It would only matter if boot0 had to stay at 8 KiB.
- The Radxa layout (`rockchip/disko.nix`) starts the ESP at 16 MiB and uses bcachefs; ours starts at 64 MiB and uses btrfs.
- Image builds run in a QEMU VM. Fallback without a VM: nixpkgs `image.repart`.

## R12: nixpkgs facts

- `pkgs/top-level/linux-kernels.nix` (nixos-unstable): `linux_default = linux_6_18`, `linux_latest = linux_7_3`; `kernels-org.json`: 6.18.63 (lts), 7.3.4, testing 7.4-rc2.
- `generic-extlinux-compatible`'s builder adds one entry per specialisation: the second kernel track can be a fallback boot entry.
- `pkgs.lix` exists (`lixPackageSets.stable.lix`).
- Tow-Boot (Nix-packaged U-Boot distribution): last commit 2025-01-17, U-Boot 2023.07, Allwinner support stops at A64/H5. Not usable; its idea (firmware separate from the OS, EFI enabled) is what the target chain gives us.

## Still open

- Hardware: serial console, vendor image dump, DRAM parameters, RAM size.
- Whether stack A backports to 6.18 at reasonable cost (D1).
- AIC8800 SDIO driver source and firmware licence for an out-of-tree module on both tracks.
- Whether 7.4 becomes the next longterm kernel.
