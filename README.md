# nixos-a733

NixOS board support for Allwinner A733 boards, starting with the Orange Pi
Zero 3W: the latest stable kernel.org kernel with the A733 patches, U-Boot and
TF-A built from source, a NixOS hardware module and an SD image generator.

This repository is generic: it holds no host configuration. A host imports the
modules below from its own flake and builds its own image.

> Status: skeleton. The mainline kernel is pinned and evaluates; the A733
> patches, the device tree and the open boot chain are not in yet. Meanwhile
> `sd-image-vendor` boots NixOS on the manufacturer's kernel and boot chain:
> see [vendor/README.md](vendor/README.md).

## Layout

| Path | What it holds |
|------|---------------|
| `kernel/` | `version.json` (pinned release), patched source, kernel build and config |
| `patches/` | A733 patches in two layers, `base/` and `optional/`, listed in `index.json` |
| `bootloader/` | boot0, TF-A and U-Boot, pinned in `sources.json` |
| `modules/` | `hardware.nix` (kernel, console, device tree) and `sd-image.nix` |
| `images/` | the generic image configuration |
| `vendor/` | phase 3 only: the manufacturer's kernel, U-Boot and boot blobs |
| `ci/` | scripts used by the workflows |

## Flake outputs

| Output | Description |
|--------|-------------|
| `packages.aarch64-linux.kernel` | latest stable kernel with the patches applied |
| `packages.aarch64-linux.kernel-source` | patched source tree, with `.a733-optional-skipped` |
| `packages.aarch64-linux.boot0` | boot0 extracted from the official image, hash checked (once pinned) |
| `packages.aarch64-linux.tf-a`, `uboot` | boot chain built from source (once pinned) |
| `packages.aarch64-linux.sd-image-generic` | minimal image: root login on the serial console only |
| `packages.aarch64-linux.kernel-vendor`, `boot-vendor` | the manufacturer's 6.6 kernel and boot chain |
| `packages.aarch64-linux.sd-image-vendor` | the minimal image on the manufacturer's kernel and boot chain |
| `nixosModules.hardware` | kernel, console on `ttyS0` at 115200 baud, device tree, binary cache |
| `nixosModules.sd-image` | SD image with boot0 and U-Boot written before the first partition |
| `nixosModules.vendor` | `hardware.a733.vendor.enable`: switch to the manufacturer's kernel and boot chain |
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
| `ci` | every push and pull request | evaluates the flake, checks formatting, builds nothing |
| `build` | push to `main` or `develop` touching the build, or by hand | builds the vendor image (kept as an artifact) and, once base patches exist, the mainline kernel and image, on native ARM runners, pushing to Cachix |
| `release` | a `v*` tag on `main` | publishes a GitHub Release with the vendor SD image and its checksum |
| `kernel-bump` | nightly and by hand | pins a new kernel.org stable release on `develop` and starts `build` |

A base patch that no longer applies fails the build and opens an issue. An
optional patch that no longer applies is left out, the build goes on, and an
issue lists what was skipped.

## Download

Ready SD images are on the
[Releases](https://github.com/f-pd/nixos-a733/releases) page. To write one:

```
sha256sum -c nixos-a733-vendor-v0.1.0.img.zst.sha256
zstd -dc nixos-a733-vendor-v0.1.0.img.zst | sudo dd of=/dev/sdX bs=4M conv=fsync status=progress
```

Builds of `develop` also keep the image as a workflow artifact for 30 days.

## Serial console

UART0 on the 40-pin header: pin 6 ground, pin 8 TX, pin 10 RX, 115200 baud,
`ttyS0`.

## Branches

Git flow: `main` holds releases, `develop` is the integration branch, work
happens on `feature/*`, fixes on `bugfix/*` and `hotfix/*`. A release goes
through `release/x.y.z`, is merged into `main`, tagged `vx.y.z` and merged
back into `develop`; the tag publishes the image.

## License

GPL-3.0, see [LICENSE](LICENSE).
