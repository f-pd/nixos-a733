{
  description = "NixOS board support for Allwinner A733 boards (Orange Pi Zero 3W)";

  nixConfig = {
    extra-substituters = [ "https://nixos-a733.cachix.org" ];
    extra-trusted-public-keys = [
      "nixos-a733.cachix.org-1:rMgMVYYwVjmvg4b8FX59uavFlLCqP0YuR6O8NXgqcWY="
    ];
  };

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs =
    { self, nixpkgs }:
    let
      inherit (nixpkgs) lib;

      system = "aarch64-linux";
      pkgs = nixpkgs.legacyPackages.${system};

      sources = lib.importJSON ./bootloader/sources.json;
      pinned = name: sources.${name}.hash or null != null;

      generic = self.nixosConfigurations.generic.config;
    in
    {
      nixosModules = {
        hardware = ./modules/hardware.nix;
        sd-image = ./modules/sd-image.nix;
        vendor = ./modules/vendor.nix;
        boot-log = ./modules/boot-log.nix;
        welcome = ./modules/welcome.nix;
        default = {
          imports = [
            self.nixosModules.hardware
            self.nixosModules.sd-image
            self.nixosModules.vendor
            self.nixosModules.boot-log
            self.nixosModules.welcome
          ];
        };
      };

      # Minimal bootable image: the first login sets the root password and
      # creates the main user; SSH starts after that.
      nixosConfigurations.generic = lib.nixosSystem {
        modules = [
          { nixpkgs.hostPlatform = system; }
          self.nixosModules.default
          ./images/generic.nix
        ];
      };

      # Phase 3: the same image on the manufacturer's kernel and boot chain.
      nixosConfigurations.generic-vendor = lib.nixosSystem {
        modules = [
          { nixpkgs.hostPlatform = system; }
          self.nixosModules.default
          ./images/generic-vendor.nix
        ];
      };

      # The mainline boot chain: BL31 and U-Boot with our DRAM init, in one
      # file for the SD card. "firmware" and "dram-payload" hold the PHY
      # training firmware and are for local use only; "spl-zero-payload" is
      # the same SPL with zeros in its place.
      packages.${system} = {
        kernel-source = pkgs.callPackage ./kernel/source.nix { };
        kernel = pkgs.callPackage ./kernel { };
        sd-image-generic = generic.system.build.sdImage;

        kernel-vendor = pkgs.callPackage ./vendor/kernel.nix { };
        boot-vendor = pkgs.callPackage ./vendor/boot-package.nix { };
        # The GPU module and drivers on their own; gpu-vendor is unfree, so
        # this nixpkgs allows it by name only.
        gpu-vendor =
          (import nixpkgs {
            inherit system;
            config.allowUnfreePredicate = pkg: nixpkgs.lib.getName pkg == "a733-vendor-gpu";
          }).callPackage
            ./vendor/gpu.nix
            { };
        gpu-module-vendor =
          (pkgs.linuxPackagesFor (pkgs.callPackage ./vendor/kernel.nix { })).callPackage
            ./vendor/gpu-module.nix
            { };
        sd-image-vendor = self.nixosConfigurations.generic-vendor.config.system.build.sdImage;
      }
      // lib.optionalAttrs (pinned "tf-a") {
        tf-a = pkgs.callPackage ./bootloader/tf-a.nix { };
      }
      // lib.optionalAttrs (pinned "u-boot" && pinned "tf-a") rec {
        dram-payload = pkgs.callPackage ./bootloader/dram-payload.nix { };
        uboot = pkgs.callPackage ./bootloader/u-boot.nix {
          tf-a = self.packages.${system}.tf-a;
          dramPayload = dram-payload;
        };
        firmware = uboot;
        spl-zero-payload = pkgs.callPackage ./bootloader/u-boot.nix {
          tf-a = self.packages.${system}.tf-a;
          dramPayload = pkgs.callPackage ./bootloader/dram-payload.nix { zero = true; };
        };
      };

      formatter.${system} = pkgs.nixfmt-tree;
      formatter.x86_64-linux = nixpkgs.legacyPackages.x86_64-linux.nixfmt-tree;
    };
}
