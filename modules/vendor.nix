# Phase 3: boot NixOS with the manufacturer's kernel and boot chain.
#
# Replaces the mainline kernel, extlinux and the open boot chain with what
# Orange Pi ships, built from their sources. Meant to prove that NixOS itself
# boots on the board before the kernel is swapped for mainline.
{
  config,
  lib,
  pkgs,
  ...
}:
let
  cfg = config.hardware.a733.vendor;

  sources = lib.importJSON ../vendor/sources.json;
  kernel = pkgs.callPackage ../vendor/kernel.nix { };
  bootPackage = pkgs.callPackage ../vendor/boot-package.nix { };
  installBoot = pkgs.callPackage ../vendor/install-boot.nix {
    inherit (sources.kernel) deviceTree;
  };

  # What systemd and NixOS need from the kernel. DMIID is left out: it needs
  # EFI, which this kernel does not have and the board does not use.
  required = [
    "DEVTMPFS"
    "CGROUPS"
    "INOTIFY_USER"
    "SIGNALFD"
    "TIMERFD"
    "EPOLL"
    "NET"
    "SYSFS"
    "PROC_FS"
    "FHANDLE"
    "CRYPTO_USER_API_HASH"
    "CRYPTO_HMAC"
    "CRYPTO_SHA256"
    "AUTOFS_FS"
    "TMPFS_POSIX_ACL"
    "TMPFS_XATTR"
    "SECCOMP"
    "BLK_DEV_INITRD"
    "RD_ZSTD"
  ];
in
{
  options.hardware.a733.vendor.enable = lib.mkEnableOption ''
    the manufacturer's 6.6 kernel, U-Boot 2018.05 and boot blobs, built from
    the Orange Pi sources pinned in vendor/sources.json
  '';

  config = lib.mkIf cfg.enable {
    hardware.a733.kernel = kernel;
    hardware.a733.deviceTree = sources.kernel.deviceTree;

    # The manufacturer's U-Boot reads boot.scr, not extlinux.conf.
    boot.loader.generic-extlinux-compatible.enable = false;
    system.build.installBootLoader = "${lib.getExe installBoot}";
    system.boot.loader.id = "a733-vendor";

    boot.kernelParams = [
      # Early output on UART0, as the manufacturer's boot script sets it.
      "earlyprintk=sunxi-uart,0x02500000"
      # The manufacturer's drivers expect clocks nobody claims to stay on.
      "clk_ignore_unused"
    ];

    # The NixOS default initrd modules assume a distribution kernel: this one
    # builds what the board needs into the image and lacks the rest (dm_mod).
    boot.initrd.includeDefaultModules = false;
    boot.initrd.allowMissingModules = true;

    hardware.a733.sdImage.bootBlobs = lib.mkForce [
      {
        name = "boot0";
        file = "${bootPackage}/boot0_sdcard.fex";
        offsetKiB = sources.sdLayout.boot0OffsetKiB;
      }
      {
        name = "boot_package";
        file = "${bootPackage}/boot_package.fex";
        offsetKiB = sources.sdLayout.bootPackageOffsetKiB;
      }
    ];

    sdImage.populateRootCommands = lib.mkForce ''
      mkdir -p ./files/boot
      ${lib.getExe installBoot} ${config.system.build.toplevel} ./files/boot
    '';

    assertions = map (option: {
      assertion = kernel.config.isEnabled option;
      message = "vendor kernel: CONFIG_${option} must be enabled in vendor/kernel/sun60iw2-a733.config";
    }) required;
  };
}
