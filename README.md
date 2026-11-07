# nixos-a733

NixOS board support for Allwinner A733 boards, starting with the Orange Pi
Zero 3W: the latest stable kernel.org kernel with the A733 patches, U-Boot and
TF-A built from source, a NixOS hardware module and an SD image generator.

This repository is generic: it holds no host configuration. A host imports the
modules below from its own flake and builds its own image.

> Status: skeleton. The kernel is pinned and evaluates; the A733 patches, the
> device tree and the boot chain are not in yet, so no image boots.

## Layout

| Path | What it holds |
|------|---------------|
| `kernel/` | `version.json` (pinned release), patched source, kernel build and config |
| `patches/` | A733 patches in two layers, `base/` and `optional/`, listed in `index.json` |
| `bootloader/` | boot0, TF-A and U-Boot, pinned in `sources.json` |
| `modules/` | `hardware.nix` (kernel, console, device tree) and `sd-image.nix` |
| `images/` | the generic image configuration |
| `ci/` | scripts used by the workflows |

## Flake outputs

| Output | Description |
|--------|-------------|
| `packages.aarch64-linux.kernel` | latest stable kernel with the patches applied |
| `packages.aarch64-linux.kernel-source` | patched source tree, with `.a733-optional-skipped` |
| `packages.aarch64-linux.boot0` | boot0 extracted from the official image, hash checked (once pinned) |
| `packages.aarch64-linux.tf-a`, `uboot` | boot chain built from source (once pinned) |
| `packages.aarch64-linux.sd-image-generic` | minimal image: root login on the serial console only |
| `nixosModules.hardware` | kernel, console on `ttyS0` at 115200 baud, device tree, binary cache |
| `nixosModules.sd-image` | SD image with boot0 and U-Boot written before the first partition |
| `nixosModules.default` | both modules |

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
| `build` | push to `main` or `develop` touching the build, or by hand | builds kernel, boot chain and generic image on native ARM runners, pushes to Cachix |
| `kernel-bump` | nightly and by hand | pins a new kernel.org stable release on `develop` and starts `build` |

A base patch that no longer applies fails the build and opens an issue. An
optional patch that no longer applies is left out, the build goes on, and an
issue lists what was skipped.

## Serial console

UART0 on the 40-pin header: pin 6 ground, pin 8 TX, pin 10 RX, 115200 baud,
`ttyS0`.

## Branches

Git flow: `main` holds releases, `develop` is the integration branch, work
happens on `feature/*`, fixes on `bugfix/*` and `hotfix/*`.

## License

GPL-3.0, see [LICENSE](LICENSE).
