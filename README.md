# nixos-a733

NixOS board support for Allwinner A733 boards, starting with the Orange Pi
Zero 3W: the latest stable kernel.org kernel with the A733 patches, U-Boot and
TF-A built from source, a NixOS hardware module and an SD image generator.

This repository is generic: it holds no host configuration. A host imports the
modules below from its own flake and builds its own image.

> Status: the vendor variant (the manufacturer's kernel, boot chain, firmware
> and drivers) builds and is published under Releases. The mainline variants
> are not in yet: the A733 kernel patches and the device tree are still to
> come. The open boot chain (U-Boot SPL with our own DRAM init, TF-A, U-Boot)
> builds in CI and has not run on a board yet: see
> [docs/boot-chain-bases.md](docs/boot-chain-bases.md) and
> [docs/bring-up.md](docs/bring-up.md).

## Builds

Component versions in each build, read from the repository. The latest
release is what `main` holds; `develop` is what the next one will ship.

[![release](https://img.shields.io/github/v/release/f-pd/nixos-a733?label=latest%20release)](https://github.com/f-pd/nixos-a733/releases/latest)
[![build](https://img.shields.io/github/actions/workflow/status/f-pd/nixos-a733/build.yml?branch=develop&label=develop%20build)](https://github.com/f-pd/nixos-a733/actions/workflows/build.yml)

### Vendor

The manufacturer's kernel, boot chain, firmware and drivers: see [vendor/README.md](vendor/README.md).

| Component | Latest release | develop |
|-----------|----------------|---------|
| NixOS | ![nixpkgs](https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fraw.githubusercontent.com%2Ff-pd%2Fnixos-a733%2Fmain%2Fflake.lock&query=%24.nodes.nixpkgs.original.ref&label=nixpkgs&color=5277C3) | ![nixpkgs](https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fraw.githubusercontent.com%2Ff-pd%2Fnixos-a733%2Fdevelop%2Fflake.lock&query=%24.nodes.nixpkgs.original.ref&label=nixpkgs&color=5277C3) |
| Kernel | ![linux](https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fraw.githubusercontent.com%2Ff-pd%2Fnixos-a733%2Fmain%2Fvendor%2Fsources.json&query=%24.kernel.version&label=linux&color=FCC624) | ![linux](https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fraw.githubusercontent.com%2Ff-pd%2Fnixos-a733%2Fdevelop%2Fvendor%2Fsources.json&query=%24.kernel.version&label=linux&color=FCC624) |
| U-Boot | ![u-boot](https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fraw.githubusercontent.com%2Ff-pd%2Fnixos-a733%2Fmain%2Fvendor%2Fsources.json&query=%24%5B%27u-boot%27%5D.version&label=u-boot&color=orange) | ![u-boot](https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fraw.githubusercontent.com%2Ff-pd%2Fnixos-a733%2Fdevelop%2Fvendor%2Fsources.json&query=%24%5B%27u-boot%27%5D.version&label=u-boot&color=orange) |
| Wi-Fi/BT firmware | ![aic8800d80](https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fraw.githubusercontent.com%2Ff-pd%2Fnixos-a733%2Fmain%2Fvendor%2Fsources.json&query=%24.firmware.version&label=aic8800d80&color=blue) | ![aic8800d80](https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fraw.githubusercontent.com%2Ff-pd%2Fnixos-a733%2Fdevelop%2Fvendor%2Fsources.json&query=%24.firmware.version&label=aic8800d80&color=blue) |
| Video engine | ![libcedarc](https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fraw.githubusercontent.com%2Ff-pd%2Fnixos-a733%2Fmain%2Fvendor%2Fsources.json&query=%24.packages.files.libcedarc.version&label=libcedarc&color=blue) | ![libcedarc](https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fraw.githubusercontent.com%2Ff-pd%2Fnixos-a733%2Fdevelop%2Fvendor%2Fsources.json&query=%24.packages.files.libcedarc.version&label=libcedarc&color=blue) |
| GStreamer OMX | ![gst-omx](https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fraw.githubusercontent.com%2Ff-pd%2Fnixos-a733%2Fmain%2Fvendor%2Fsources.json&query=%24.packages.files%5B%27gst-omx%27%5D.version&label=gst-omx&color=blue) | ![gst-omx](https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fraw.githubusercontent.com%2Ff-pd%2Fnixos-a733%2Fdevelop%2Fvendor%2Fsources.json&query=%24.packages.files%5B%27gst-omx%27%5D.version&label=gst-omx&color=blue) |
| Camera ISP | ![libAWIspApi](https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fraw.githubusercontent.com%2Ff-pd%2Fnixos-a733%2Fmain%2Fvendor%2Fsources.json&query=%24.packages.files.libAWIspApi.version&label=libAWIspApi&color=blue) | ![libAWIspApi](https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fraw.githubusercontent.com%2Ff-pd%2Fnixos-a733%2Fdevelop%2Fvendor%2Fsources.json&query=%24.packages.files.libAWIspApi.version&label=libAWIspApi&color=blue) |
| NPU runtime | ![viplite](https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fraw.githubusercontent.com%2Ff-pd%2Fnixos-a733%2Fmain%2Fvendor%2Fsources.json&query=%24.packages.npuVersion&label=viplite&color=blue) | ![viplite](https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fraw.githubusercontent.com%2Ff-pd%2Fnixos-a733%2Fdevelop%2Fvendor%2Fsources.json&query=%24.packages.npuVersion&label=viplite&color=blue) |
| GPU drivers | ![powervr](https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fraw.githubusercontent.com%2Ff-pd%2Fnixos-a733%2Fmain%2Fvendor%2Fsources.json&query=%24.packages.files.gpu.version&label=powervr&color=blue) | ![powervr](https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fraw.githubusercontent.com%2Ff-pd%2Fnixos-a733%2Fdevelop%2Fvendor%2Fsources.json&query=%24.packages.files.gpu.version&label=powervr&color=blue) |

### Mainline

Latest LTS and latest stable kernel.org kernels with the A733 patches: not available yet.

Firmware: `nix build .#firmware` gives `u-boot-sunxi-with-spl.bin`, to be written at 128 KiB
of the card, and `sunxi-spl.bin` for FEL. It is built from source except for the training
firmware of the DRAM PHY, which the build cuts out of the manufacturer's boot0: the result is
for your own board and is not published. Untested on hardware.

## Layout

| Path | What it holds |
|------|---------------|
| `kernel/` | `version.json` (pinned release), patched source, kernel build and config |
| `patches/` | A733 patches in two layers, `base/` and `optional/`, listed in `index.json` |
| `bootloader/` | the mainline boot chain: TF-A and U-Boot pinned in `sources.json`, our patches for them in `patches/`, the DRAM init library in `dram/` |
| `modules/` | `hardware.nix` (kernel, console, device tree), `sd-image.nix`, `boot-log.nix` and `welcome.nix` |
| `images/` | the generic image configuration |
| `vendor/` | the vendor variant: the manufacturer's kernel, U-Boot, firmware and drivers; their files are copied in `vendor/blobs/`, with their origin |
| `ci/` | scripts used by the workflows |
| `docs/` | `mainline-notes.md`: state of A733 support outside the vendor tree and how it maps onto `patches/` and `bootloader/`; `boot-chain-bases.md`: how the mainline firmware is put together; `bring-up.md`: the first session with the board; `dram-init-spec.md`: how the vendor DRAM init works; `zero3w-wiring.md`: how the Zero 3W is wired, per peripheral; `board/`: the manufacturer's schematics, drawings and manual |
| `tools/` | `a733-bench.sh`, installed on the generic images as `a733-bench` |

## Flake outputs

| Output | Description |
|--------|-------------|
| `packages.aarch64-linux.kernel` | latest stable kernel with the patches applied |
| `packages.aarch64-linux.kernel-source` | patched source tree, with `.a733-optional-skipped` |
| `packages.aarch64-linux.tf-a` | BL31, built from source |
| `packages.aarch64-linux.firmware` (also `uboot`) | the mainline firmware: SPL with our DRAM init, BL31 and U-Boot in `u-boot-sunxi-with-spl.bin`; also `sunxi-spl.bin` for FEL and the SPL's ELF. Holds the DRAM PHY firmware: not for publishing |
| `packages.aarch64-linux.dram-payload` | the DRAM PHY firmware, cut out of the manufacturer's boot0. Not for publishing |
| `packages.aarch64-linux.spl-zero-payload` | the same build with zeros in place of that firmware: what CI uploads |
| `packages.aarch64-linux.sd-image-generic` | minimal image: root login on the serial console, guided first login |
| `packages.aarch64-linux.kernel-vendor`, `boot-vendor` | the manufacturer's 6.6 kernel and boot chain |
| `packages.aarch64-linux.sd-image-vendor` | the minimal image on the manufacturer's kernel and boot chain |
| `nixosModules.hardware` | kernel, console on `ttyS0` at 115200 baud, device tree, binary cache |
| `nixosModules.sd-image` | SD image with the boot chain written before the first partition |
| `nixosModules.vendor` | `hardware.a733.vendor.enable`: switch to the manufacturer's kernel and boot chain |
| `nixosModules.boot-log` | `hardware.a733.bootLog.enable`: boot logs on the FAT partition |
| `nixosModules.welcome` | `hardware.a733.welcome.enable`: slogans, fastfetch, Tokyo Night, starship, comfort tools and aliases, guided first login |
| `nixosModules.default` | all of the above |

## Using it from a host flake

```nix
{
  inputs = {
    nixos-a733.url = "github:f-pd/nixos-a733";
    # Follow this flake's nixpkgs: the kernel is only fetched from the binary
    # cache when it is built from the same nixpkgs revision as in CI.
    nixpkgs.follows = "nixos-a733/nixpkgs";
  };

  outputs = { nixpkgs, nixos-a733, ... }: {
    nixosConfigurations.myboard = nixpkgs.lib.nixosSystem {
      modules = [
        { nixpkgs.hostPlatform = "aarch64-linux"; }
        nixos-a733.nixosModules.default
        ./configuration.nix
      ];
    };
  };
}
```

The image is then `nixosConfigurations.myboard.config.system.build.sdImage`.

## Binary cache

CI pushes every build to [nixos-a733.cachix.org](https://nixos-a733.cachix.org):

```
substituter: https://nixos-a733.cachix.org
public key:  nixos-a733.cachix.org-1:rMgMVYYwVjmvg4b8FX59uavFlLCqP0YuR6O8NXgqcWY=
```

`nixosModules.hardware` adds it to the board's Nix settings
(`hardware.a733.useBinaryCache`, on by default).

## CI

| Workflow | When | What |
|----------|------|------|
| `ci` | every push and pull request | evaluates the flake, checks formatting, runs the DRAM library against the reference scripts; builds no derivation |
| `build` | push to `main` or `develop` touching the build, or by hand | builds the vendor image (kept as an artifact), the mainline firmware (layout checked; the SPL without the DRAM PHY firmware kept as an artifact) and, once base patches exist, the mainline kernel and image, on native ARM runners, pushing to Cachix except what holds firmware without a redistribution grant |
| `release` | push to `main`, or by hand on `develop` | on `main`, publishes the version in `VERSION` as a GitHub Release, tag `v<VERSION>`, with the vendor SD image and its checksum, and skips versions already released; on `develop`, publishes a pre-release `v<next minor>-dev.<run>` to try on the board, never marked as latest |
| `kernel-bump` | nightly and by hand | pins a new kernel.org stable release on `develop` and starts `build` |

A base patch that no longer applies fails the build and opens an issue. An
optional patch that no longer applies is left out, the build goes on, and an
issue lists what was skipped.

## Download

Ready SD images are on the
[Releases](https://github.com/f-pd/nixos-a733/releases) page. To write one:

```
sha256sum -c nixos-a733-vendor-v0.3.2.img.zst.sha256
zstd -dc nixos-a733-vendor-v0.3.2.img.zst | sudo dd of=/dev/sdX bs=4M conv=fsync status=progress
```

Pre-releases (`v<x.y.z>-dev.<n>`) are images from `develop`, published to be
tried on the board before a release. Builds of `develop` also keep the image
as a workflow artifact for 30 days.

## Serial console

UART0 on the 40-pin header: pin 6 ground, pin 8 TX, pin 10 RX, 115200 baud,
`ttyS0`.

## First login

The generic images turn on `hardware.a733.welcome.enable`
(`modules/welcome.nix`, `modules/welcome-info.sh`).

Above the login prompt, on the serial console and on HDMI:

- the NixOS snowflake in the colours of the pride flag, one per lambda. Each
  time the prompt appears the colours turn around it twice and stop where
  they stay: the animation is drawn on the very rows the prompt then prints.
  Beside it the system in short: release, board, host, image, kernel, CPU,
  memory, address, SSH, the slogan;
- the hardware: CPU cores and clocks, memory, storage, the manufacturer's
  drivers (loaded or missing), Bluetooth;
- the versions: nixos-a733, NixOS, kernel, the U-Boot actually on the card
  (read from it, or the one the system is built with), kernel sources, boot
  blobs, firmware, GPU, video and NPU drivers;
- the network: each interface with its address and Wi-Fi network, the
  default route;
- the services: SSH, what is running, what failed;
- until the first login is done, what to do.

The snowflake takes 256 colours, which nearly every terminal has; one
that lacks them shows it without colours.
`hardware.a733.welcome.promptColours = "16"` works on any terminal, with
cyan in place of orange.

The screen is refreshed every 30 seconds while the prompt waits, and redrawn
when something changed (an address, a service). `a733-info` shows the same
overview once logged in.

The first login:

- Log in as `root` on the serial console or on HDMI. Root has no password
  yet, so none is asked, and the login prompt makes you choose one. You are
  then asked whether your terminal shows Nerd Font icons, and for the name
  and the password of the main user, which can use `sudo`. Ctrl-C skips a
  question until the next root login.
- With a Nerd Font, `eza` shows icons and the `starship` prompt uses its
  Tokyo Night preset; without, both stay plain text, as they always do on the
  HDMI console. To change the answer: `echo yes > /var/lib/a733-welcome/icons`
  (or `no`), then log in again.
- Wi-Fi and Bluetooth are off: they share the antenna, and transmitting
  without it can burn the radio's amplifiers. The board has no Ethernet, so
  the welcome screen says so. Connect the antenna, log in on the serial console
  or HDMI, run `radio on` and confirm, then `nmtui` to join a network. The
  radio then stays on across reboots until `radio off`.
- SSH starts once an account has a password, so not before the first login.
  Root cannot log in over SSH with a password; the main user can.
- After every login, SSH included: the snowflake and the system in short
  again, in as many colours as the terminal has (24-bit, 256 or 16).
  `hardware.a733.welcome.animation = false` keeps the snowflake still, here
  and above the prompt. `fastfetch` is still there for a longer list.
- Colours are Tokyo Night: the palette of the HDMI console, `btop` and
  `fastfetch`. Other tools use the 16 colours of your terminal, so on the
  serial console and over SSH they follow your terminal's theme.
- Installed: `a733-info`, `fastfetch`, `btop`, `starship`, `eza`, `bat`,
  `git`, `curl`, `wget`, `tmux`, `ripgrep`, `fd`, `tree`, `file`, the
  JetBrains Mono Nerd Font, with the shell aliases of CachyOS (`ls`, `ll`,
  `cat`, `..` and so on).

A host's own configuration can add lines to the versions with
`hardware.a733.components` and to the drivers with `hardware.a733.drivers`.

## Benchmark

`a733-bench` runs the same measurements on any image and saves them to a
text file: CPU and memory (`sysbench`), SD card (`fio`), the GPU through
Vulkan and OpenCL (`vulkaninfo`, `clinfo`, `clpeak`), the video engine (H.264
1080p encode with `omxh264videoenc`), the NPU (the manufacturer's sample
network with `vpm_run`), temperatures before and after. A test whose tool or
driver is missing says `skipped`. To compare with the manufacturer's Debian,
copy `tools/a733-bench.sh` there and install its tools first (the list is at
the top of the script).

`btop` cannot show this GPU: it reads only NVIDIA, AMD, Intel and Apple GPUs.
The PowerVR driver exposes its frequency through devfreq
(`/sys/class/devfreq/*gpu*/cur_freq`) and its state in debugfs
(`/sys/kernel/debug/pvr/`).

## Boot logs without a serial adapter

The generic images write how far the boot got to the FAT partition of the SD
card (`FIRMWARE`, the first partition), which any computer can read. Power the
board off after a minute or two, put the card in a computer and open:

| File | Written by | What it says |
|------|------------|--------------|
| `a733-uboot.txt` | U-Boot (`boot.scr`) | script found, kernel, initrd and device tree loaded, overlays, kernel started |
| `a733-uboot-env.txt` | U-Boot | the whole U-Boot environment |
| `a733-initrd-*.txt` | stage 1 | status, kernel log, journal: root file system and driver problems |
| `a733-system-*.txt` | the booted system | the same plus the failed units, refreshed for five minutes |

No `a733-uboot.txt` means U-Boot never ran `boot.scr`: boot0, U-Boot or the
card itself. `a733-uboot.txt` without `a733-initrd-*` files means the kernel
did not get as far as stage 1. The status LED blinks in a heartbeat pattern
while the kernel runs, and the console is also on HDMI (`tty1`).

`hardware.a733.bootLog.enable` turns the Linux part on for a host's own image;
`boot.scr` of the vendor variant always writes its file.

## Branches

Git flow: `main` holds releases, `develop` is the integration branch, work
happens on `feature/*`, fixes on `bugfix/*` and `hotfix/*`. A release goes
through `release/x.y.z`, where `VERSION` is set, is merged into `main` and back
into `develop`; the merge into `main` publishes it.

## License

GPL-3.0, see [LICENSE](LICENSE).
