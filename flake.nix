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
        default = {
          imports = [
            self.nixosModules.hardware
            self.nixosModules.sd-image
          ];
        };
      };

      # Minimal bootable image: serial console login only, no users, no SSH.
      nixosConfigurations.generic = lib.nixosSystem {
        modules = [
          { nixpkgs.hostPlatform = system; }
          self.nixosModules.default
          ./images/generic.nix
        ];
      };

      # Bootloader pieces are exported only once their sources are pinned in
      # bootloader/sources.json, so evaluation never trips over a placeholder.
      packages.${system} = {
        kernel-source = pkgs.callPackage ./kernel/source.nix { };
        kernel = pkgs.callPackage ./kernel { };
        sd-image-generic = generic.system.build.sdImage;
      }
      // lib.optionalAttrs (pinned "boot0") {
        boot0 = pkgs.callPackage ./bootloader/boot0.nix { };
      }
      // lib.optionalAttrs (pinned "tf-a") {
        tf-a = pkgs.callPackage ./bootloader/tf-a.nix { };
      }
      // lib.optionalAttrs (pinned "u-boot" && pinned "tf-a") {
        uboot = pkgs.callPackage ./bootloader/u-boot.nix {
          tf-a = self.packages.${system}.tf-a;
        };
      };

      formatter.${system} = pkgs.nixfmt-tree;
      formatter.x86_64-linux = nixpkgs.legacyPackages.x86_64-linux.nixfmt-tree;
    };
}
