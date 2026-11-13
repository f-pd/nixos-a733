# Hardware support for Allwinner A733 boards.
{
  config,
  lib,
  pkgs,
  ...
}:
let
  cfg = config.hardware.a733;
in
{
  options.hardware.a733 = {
    kernel = lib.mkOption {
      type = lib.types.package;
      default = pkgs.callPackage ../kernel { };
      defaultText = lib.literalExpression "pkgs.callPackage ../kernel { }";
      description = "Kernel to boot: latest stable with the A733 patches.";
    };

    deviceTree = lib.mkOption {
      type = lib.types.nullOr lib.types.str;
      default = "allwinner/sun60i-a733-orangepi-zero3w.dtb";
      description = ''
        Device tree blob to boot with, relative to the kernel's dtbs directory.
        The default is the Orange Pi Zero 3W tree of the base patches.
      '';
    };

    components = lib.mkOption {
      type = lib.types.attrsOf lib.types.str;
      default = { };
      example = {
        "PowerVR driver" = "24.2.6603887";
      };
      description = ''
        Versions of the components the system is built from, by name, for
        the welcome screen (hardware.a733.welcome). The kernel, NixOS and
        U-Boot are shown on their own.
      '';
    };

    drivers = lib.mkOption {
      type = lib.types.listOf lib.types.str;
      default = [ ];
      example = [ "pvrsrvkm" ];
      description = ''
        Kernel modules the welcome screen (hardware.a733.welcome) shows as
        loaded or missing.
      '';
    };

    ubootVersion = lib.mkOption {
      type = lib.types.nullOr lib.types.str;
      default = null;
      description = ''
        Version of the U-Boot the system is built with, shown by the welcome
        screen when the one on the card cannot be read.
      '';
    };

    useBinaryCache = lib.mkOption {
      type = lib.types.bool;
      default = true;
      description = ''
        Use the nixos-a733 Cachix cache, so the board downloads the kernel
        built by CI instead of compiling it. Hits only happen when the host
        uses the same nixpkgs revision as this flake.
      '';
    };
  };

  config = {
    hardware.a733.components.nixos-a733 = lib.fileContents ../VERSION;

    boot.kernelPackages = lib.mkDefault (pkgs.linuxPackagesFor cfg.kernel);

    # ttyS0 last: it becomes /dev/console, so boot messages land on the UART.
    boot.kernelParams = [
      "console=tty1"
      "console=ttyS0,115200"
    ];

    boot.loader.grub.enable = lib.mkDefault false;
    boot.loader.generic-extlinux-compatible.enable = lib.mkDefault true;

    boot.initrd.availableKernelModules = [
      "mmc_block"
      "usb_storage"
      "uas"
    ];

    hardware.deviceTree = lib.mkIf (cfg.deviceTree != null) {
      enable = true;
      name = cfg.deviceTree;
    };

    nix.settings = lib.mkIf cfg.useBinaryCache {
      extra-substituters = [ "https://nixos-a733.cachix.org" ];
      extra-trusted-public-keys = [
        "nixos-a733.cachix.org-1:rMgMVYYwVjmvg4b8FX59uavFlLCqP0YuR6O8NXgqcWY="
      ];
    };
  };
}
