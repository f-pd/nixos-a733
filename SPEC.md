# NixOS-A733: Spec

> Repo: `github.com/f-pd/nixos-a733` · Status: draft v0.3 · 2026-11-12
> Supersedes v0.2 (Debian and Talos flavors: both dropped). Evidence: `docs/research.md`, `docs/supply-chain-audit.md`.

A Nix flake that builds NixOS for **Allwinner A733 (`sun60iw2`)** boards, starting with the
**Orange Pi Zero 3W**, from upstream kernels plus an A733 patch stack, on two kernel tracks:

- **`lts`**: the current longterm kernel of nixpkgs (`linuxPackages`, today 6.18.y) + A733 patches.
- **`latest`**: the newest stable kernel of nixpkgs (`linuxPackages_latest`, today 7.3.y) + A733 patches.

No vendor kernel. Firmware is built from source, DRAM init included: no open one exists for the A733 yet, so this project writes it (§3.3, D2).

---

## 1. Goals / non-goals

### Goals
1. Both tracks follow nixpkgs: a kernel bump is `nix flake update`, the A733 patches are applied by the build.
2. Everything is a Nix derivation: kernel, device tree, firmware, image. No hand-run scripts.
3. Module layout mirrors `nixos-hardware` (`radxa/` + `rockchip/` pattern) so that upstreaming later is a copy (§11).
4. The board updates in place from the flake and can roll back (NixOS generations; `lts` as fallback boot entry).
5. No dependency that we cannot replace: every third-party input is pinned, and patch stacks are vendored (§6).
6. Nothing without a redistribution grant is published by this project (§5).

### Non-goals (for now)
- Other SoC families. Other A733 boards are welcome later (one board module each).
- GPU, NPU, video decode, camera. Display output (HDMI/eDP status dashboards) is a later phase, not bring-up.
- Suspend to RAM (needs closed E902 firmware; the box is always-on anyway).
- The services themselves (Tor bridge or relay, Unbound, AdGuard Home, Home Assistant, Frigate, local models; D6): they live in a host configuration, not in the hardware layer.

---

## 2. Known facts (verified 2026-11-12)

| Item | Value |
|---|---|
| Board | Orange Pi Zero 3W: A733 (2×A76 + 6×A55), LPDDR5, microSD, **no wired Ethernet**, Wi-Fi/BT AIC8800, 2×USB-C, mini HDMI, PCIe 3.0 x1 on FPC |
| nixpkgs kernels (nixos-unstable) | `linux_default` = 6.18 (6.18.63, LTS), `linux_latest` = 7.3 (7.3.4), testing 7.4-rc2 |
| Mainline kernel A733 | Not merged: CCU/PRCM, DMA, RTC, pinctrl, DTS series under review on linux-sunxi |
| Mainline U-Boot A733 | Not merged (`MACH_SUN60I_A733` absent in master). Yixun Lan's series at v3 (2026-01) |
| Upstream TF-A A733 | **Not present**: `plat/allwinner/` has a64, h6, h616, r329, a133 only (master `d70b52d`, 2026-11-11). Out of tree: `dlan17/trusted-firmware-a` branch `A733`; `DockSeed/a733-bootchain` (upstream master + 17 patches) |
| Kernel stack A | `DockSeed/a7s-linux-mainline`: ~125 patches on 7.3.4, upstream-style bindings, GPL-2.0-only, no blobs, checkpatch-clean, extlinux boot. Tested on Radxa Cubie A7S only. No AIC8800 Wi-Fi |
| Kernel stack B | `jonas5/Allwinner-A733-kernel`: one 10.9k-line patch on 6.18.y + extras (incl. AIC8800 SDIO fix), validated on Orange Pi 4 Pro, Zero 3W "awaiting hardware". Ships blobs in-repo |
| Firmware chain (reference layout) | `DockSeed/a733-bootchain`: `BROM -> U-Boot SPL (+ vendor ddr.bin) -> BL31 (TF-A from source) -> U-Boot (UEFI + extlinux)`. One file, `u-boot-sunxi-with-spl.bin`, at **128 KiB** (sector 256); first partition at 16 MiB or later. No boot0, no boot_package, no SCP, no packer tool |
| Firmware chain (vendor) | `boot0` at 8 KiB (or 128 KiB) + `boot_package.fex` at 16 400 KiB (sector 32800), U-Boot 2018.05 aarch32, no EFI |
| Console | `ttyS0,115200` |
| Zero 3W device tree | Exists only in the vendor 6.6 tree (vendor bindings). No mainline-style DTS anywhere yet |

---

## 3. Architecture

### 3.1 Flake layout

```
flake.nix                      # nixosModules, packages, nixosConfigurations.example, checks
modules/
  allwinner/default.nix        # hardware.allwinner: platformFirmware, firmware offset, console
  allwinner/a733/default.nix   # hardware.allwinner.a733: enable, kernelTrack, patch series
  orangepi/zero3w/default.nix  # dtb name, firmware package, board quirks
  disko/sd.nix                 # SD image layout (GPT, firmware gap, boot, root)
pkgs/
  linux-a733/                  # patches/<track>/series + patches, applied via boot.kernelPatches
  dts/                         # sun60i-a733-orangepi-zero3w.dts (ours)
  uboot-orangepi-zero3w/       # U-Boot + SPL
  tfa-a733/                    # BL31, upstream TF-A + pinned patches
  a733-ddr-blob/               # fixed-output fetch, unfree, never cached publicly
  aic8800-sdio/                # out-of-tree Wi-Fi module (later phase)
docs/
```

Board module, in the Radxa style (about 20 lines): imports the SoC module, sets
`hardware.allwinner.a733.enable = true`, `platformFirmware = pkgs.ubootOrangePiZero3W`,
`hardware.deviceTree.name = "allwinner/sun60i-a733-orangepi-zero3w.dtb"`.
All settings use `lib.mkDefault` (nixos-hardware rule).

### 3.2 Kernel tracks

- `hardware.allwinner.a733.kernelTrack = "latest" | "lts"` selects `pkgs.linuxPackages_latest` or `pkgs.linuxPackages` and the matching patch series.
- A NixOS **specialisation** carries the other track in the same system closure, so both kernels are boot-menu entries
  (the extlinux builder lists specialisations). Default entry: `latest`. Fallback entry: `lts`.
- A patch that no longer applies after a bump fails the build: the bump PR is labelled `needs-human`, nothing is deployed.
- **One patch stack per track** (D1): stack A on `latest`, stack B on `lts`. Their bindings differ, so the board has
  one device tree per stack; a fix to the board's wiring goes into both.
- Config: nixpkgs' arm64 config plus a small A733 fragment (`structuredExtraConfig`), with an assertion list like stack A's.

### 3.3 Firmware

- Target chain: U-Boot SPL with our own DRAM init, BL31 from TF-A source, U-Boot with EFI and extlinux. One output file, written at sector 256. No vendor code runs on the ARM cores: no boot0, no `ddr.bin`. One vendor binary remains, the training firmware that runs inside the DRAM PHY (`docs/dram-init-spec.md`): the build cuts it out of boot0, and nothing that holds it is published (§5).
- State (2026-11-13): the chain builds in CI from `bootloader/` and its image layout is checked; run on a Zero 3W over FEL up to the kernel's root mount, not yet from a card. Bases, layout and open points: `docs/boot-chain-bases.md`. First session with the board: `docs/bring-up.md`, results in `docs/bring-up-results.md`.
- DRAM init is written here, after studying how the two existing ones work: Orange Pi's boot0 (known to train this board) and Radxa's `ddr.bin`. Both are study material only (§5).
- Needs a Zero 3W port: U-Boot defconfig + board DTS (SD on `mmc0`, UART0, USB). The port is our own code: the out-of-tree TF-A and U-Boot patches are a reference, not an import (D7).
- There is no boot0 fallback: a chain that ships Orange Pi's boot0 is not an option for the mainline variants.
- Bring-up is done over **FEL** (USB) and from a spare SD card. The board boots from SD first, so a bad firmware cannot brick it.
- The vendor image stays on a second card as reference and recovery.
- Firmware is not updated automatically. `nix build .#firmware` plus an explicit flash command.
- Watchdog: the chain as built does not start it, so nothing running is handed to Linux during bring-up. For an always-on box it is to be started by U-Boot once the kernel device tree drives `WDT_CPUS`; from then on a kernel that does not drive it resets about 16 s into boot.
- BL31 runs from the first 256 KiB of DRAM: the kernel device tree must reserve `0x40000000` to `0x40040000`.

### 3.4 Disk image (disko)

Verified against disko `1dd30c2` (2026-11-10):
- The `gpt` type has no option for the number of partition entries, and the MBR `table` type is deprecated.
  **Neither is needed**: with firmware at 128 KiB, a standard 128-entry GPT (ends at 17 KiB) does not collide.
- `disko.imageBuilder.extraPostVM` writes the firmware into the image, as in `rockchip/default.nix`.
- Layout: GPT; gap up to **64 MiB** (covers both the target chain and the vendor chain's boot_package at 16 400 KiB);
  `boot` vfat 512 MiB (ESP type, mounted at `/boot`); `root` **btrfs** (zstd), not bcachefs (it left the mainline tree).
- Boot loader: `generic-extlinux-compatible` first (also what stack A is tested with). `systemd-boot` becomes possible once UEFI is proven on this board.
- Fallback if the VM-based image build is too slow under emulation: nixpkgs `image.repart` (systemd-repart, GPT, no VM, no extra dependency).
- The NVMe drive (USB enclosure or PCIe FPC) gets its own disko layout in the host configuration: btrfs with subvolumes and snapshots for service data.

### 3.5 Board-specific constraints

- **Network**: no Ethernet port, and neither kernel stack has a mainline Wi-Fi driver. Bring-up and the first production
  setup use a **USB Ethernet adapter** (mainline `r8152`/`ax88179`). AIC8800 Wi-Fi is an out-of-tree module, built per
  track, and is allowed to break on `latest` without blocking a release.
- Everything on the SD card: firmware, `/boot` and the root (D3). NVMe for `/nix` and service data is a possible later step, not planned.

---

## 4. Build, CI, updates

- CI runs `nix flake check` and builds, per track: kernel, dtb, firmware, system closure, image. The pipeline is plain `nix build`, so the forge is replaceable (D4).
- Weekly bot: `nix flake update` -> PR -> build both tracks -> merge if green (kernel point releases), human review for kernel minor bumps and firmware pins.
- Own binary cache for our outputs (kernel builds are the expensive part). The DRAM blob, the firmware and full images are **excluded** from any public cache.
- Board: `system.autoUpgrade` from a `stable` ref of the flake, `nixos-rebuild boot` + reboot window. Rollback = previous generation, or the `lts` entry.
- `stable` moves only after the candidate booted on real hardware (manual at first, hardware-in-the-loop later).
- Nix implementation: Lix (`pkgs.lix`) on the board and in CI where practical. No Determinate Nix, installer or FlakeHub (§6).

---

## 5. Blobs and licensing

| Blob | Origin | Licence | Policy |
|---|---|---|---|
| `ddr.bin` (DRAM init, AArch32) | `radxa-pkg/u-boot-dlan17`, pinned by sha256 | none, no redistribution grant | study material only: not in the built chain, never published |
| `boot0_sdcard_orangepizero3w.fex` | `orangepi-xunlong/orangepi-build`, pinned by sha256 | none | same, except as the source of the DRAM PHY firmware below |
| DRAM PHY training firmware (72 678 bytes of boot0) | cut out of boot0 at build time by documented offsets | none | built into the SPL locally; never in the tree, never in a cache, a release or a CI artifact |
| AIC8800 firmware | vendor | to check | same until checked |

- The project publishes the **recipe** (flake, patches, device tree). Users build their own firmware and image locally.
- No released artifact contains a blob. A firmware-less root image may be published later.
- Our own code: GPL-3.0. Kernel patches GPL-2.0, U-Boot patches GPL-2.0-or-later, TF-A patches BSD-3-Clause, each as upstream.
- Vendor monitor (TF-A 2.5 `-dirty`), SCP and the Allwinner packer are not used at all on the target chain.

---

## 6. Supply chain choices

From `docs/supply-chain-audit.md`:

| Area | Choice | Why |
|---|---|---|
| Nix implementation | Lix | Community-governed fork; avoids Determinate Systems' downstream |
| nixpkgs | keep, pin, own cache for our outputs | No practical alternative; governance is unstable but the tree keeps merging |
| Patch stacks, bootchain | **vendor into this repo**, pinned by commit | Both are days-to-months old, single maintainer, no promise of continuity |
| disko | keep; `image.repart` as documented fallback | Active, small surface |
| Forge / CI | GitHub and GitHub Actions (D4); the pipeline stays plain `nix build` | GitHub is Microsoft: accepted |
| DNS filtering | AdGuard Home in front of Unbound (D6) | AdGuard Home is one company's product: accepted |
| Vendor software | none at runtime | Orange Pi kernel 6.6.98 lags, blobs unlicensed |

---

## 7. Testing

### In CI (no hardware)
- Both kernels build; every patch applies with no fuzz; config assertions hold; `dtbs_check` on the board dtb.
- Firmware: blob sha256, output size fits before the first partition, BL31 address and version strings as expected.
- Image: partition offsets, firmware bytes at sector 256, `/boot` contains kernel + dtb + extlinux entries for both tracks.
- `nix flake check`, formatting.

### On hardware
- Serial log to login prompt on both tracks; 12 GB RAM seen; SD, USB (dock, Ethernet adapter, NVMe enclosure); reboot and poweroff; watchdog.
- Later: self-hosted runner + SD mux + switchable power, gating `stable`.

---

## 8. Phases and exit criteria

| Phase | Scope | Exit criteria |
|---|---|---|
| **0 Research** | this spec, audit, hardware prep | Serial console wired; vendor image booted once and dumped (boot0, running device tree, boot log) |
| **1 Firmware** | U-Boot + TF-A + DRAM init for Zero 3W | U-Boot prompt over serial from SD; full RAM detected; SD readable; FEL path documented |
| **2 `latest` boots** | stack A + Zero 3W device tree | NixOS login on serial with kernel 7.3.y; SD, USB, USB Ethernet work; no watchdog reset |
| **3 `lts` + image** | second track, disko image, specialisation | One image boots both tracks from the menu; CI builds both |
| **4 Automation** | update bot, cache, auto-upgrade | A kernel point release reaches the board with no human action; rollback tested |
| **5 Board features** | AIC8800 Wi-Fi, NVMe over PCIe, HDMI/eDP | Each feature works on at least one track; `latest` breakage of Wi-Fi does not block releases |
| **6 Upstream** | §11 | Device tree posted to linux-sunxi; U-Boot board posted; nixpkgs/nixos-hardware PRs when mainline lands |

---

## 9. Risks

| Risk | Impact | Mitigation |
|---|---|---|
| Writing LPDDR5 init and training for the A733 takes longer than planned, or cannot be completed from what the two blobs show | No mainline firmware, phase 1 stalls | Study boot0 and `ddr.bin` first; compare DRAM parameters from the vendor image; the vendor variant keeps the board usable meanwhile |
| Stack A is tested on one board (Cubie A7S), 9 days old, AI-assisted, unreviewed by kernel developers | Bugs on our board | Vendor it; port board-specific patches to a Zero 3W device tree; keep `lts` as fallback entry |
| No single stack covers 6.18 and 7.3 | Two device trees | D1 |
| No Wi-Fi driver in mainline; board has no Ethernet | Box unreachable | USB Ethernet as primary link; Wi-Fi out of tree |
| Patch stack breaks on every kernel minor | `latest` stalls | Bot flags, `lts` keeps the box patched; upstream merges shrink the stack over time |
| nixpkgs governance vacuum (core team disbanded 2026-08) | Slower security handling, policy churn | Pin, review bumps, keep the option to cherry-pick security fixes onto our pin |
| Upstream repos vanish or rewrite history | Unbuildable | Vendored patches, mirrored source bundles, fixed-output hashes |
| VM-based image build slow on CI | Long pipeline | `image.repart` fallback |
| Blob redistribution | Legal | §5: recipe only |

---

## 10. Open decisions

- [x] **D1 Patch stack per track.** Decided 2026-11-13: `latest` = the newest stable kernel + stack A (DockSeed). `lts` = every longterm kernel that kernel.org still maintains and that has an A733 patch stack: today that is 6.18 + stack B (jonas5). Two stacks mean two device trees for the board; that cost is accepted. Older longterm kernels (6.12, 6.6 and before) have no A733 stack and are not built until one exists. State: `patches/` holds stack A and the Zero 3W device tree written for it (`docs/kernel-zero3w.md`), run on the board on 2026-11-13; stack B is not imported and has no Zero 3W device tree yet.
- [x] **D2 Firmware path.** Decided 2026-11-13: the whole boot chain is ours, built from source, with no vendor binary. U-Boot SPL with a DRAM init written here, after studying boot0 and Radxa's `ddr.bin`. No boot0 fallback.
- [x] **D3 Root location.** Decided 2026-11-13: root on the SD card. Root on NVMe may come later; it is not expected.
- [x] **D4 Forge and CI.** Decided 2026-11-13: stay on GitHub and GitHub Actions. No migration.
- [x] **D5 Repo name.** `nixos-a733`.
- [x] **D7 Boot chain patches.** Decided 2026-11-13: the Radxa and DockSeed TF-A and U-Boot patches are a reference for writing our own port and are not imported. Once ours exist they are dropped; they are still watched for security fixes that concern the hardware.
- [x] **D6 Services of the host.** Decided 2026-11-13: AdGuard Home for filtering, Unbound behind it with DoT and DoH upstreams only, a Tor bridge or relay, Home Assistant, Frigate. They live in the host configuration (§1).
- [x] Flavors: NixOS only. Debian and Talos dropped.
- [x] Kernel: two tracks, `lts` and `latest`, both with A733 patches. No vendor kernel.
- [x] Filesystem: btrfs.
- [x] License for our own code: GPL-3.0.

---

## 11. Upstreaming plan

Nothing here is upstreamable to nixos-hardware or nixpkgs today: both accept mainline-supported hardware only, and the A733 is not in mainline Linux, U-Boot or TF-A.

1. **Now**: test and report on the Zero 3W (`Tested-by` on linux-sunxi series; the jonas5 stack lists the Zero 3W as awaiting hardware). Few people can test this board.
2. **After Phase 2**: post `sun60i-a733-orangepi-zero3w.dts` to linux-sunxi on top of the pending A733 DTS series.
3. **When U-Boot merges A733**: U-Boot board file + defconfig; then `ubootOrangePiZero3W` in nixpkgs (model: `ubootOrangePiZero3`, which is the H618 board, not ours). The DRAM blob keeps it out of nixpkgs until an open DRAM driver exists.
4. **When the kernel side lands**: `orangepi/zero3w` + `allwinner/a733` modules to nixos-hardware. Radxa sells A733 boards, so a shared SoC module is likely to be welcome.
