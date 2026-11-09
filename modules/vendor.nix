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
    inherit (cfg) overlays;
  };
  firmware = pkgs.callPackage ../vendor/firmware.nix { };
  hciattach = pkgs.callPackage ../vendor/hciattach.nix { };
  media = pkgs.callPackage ../vendor/media.nix { };
  npu = pkgs.callPackage ../vendor/npu.nix { };
  gpu = pkgs.callPackage ../vendor/gpu.nix { };
  gpuModule = config.boot.kernelPackages.callPackage ../vendor/gpu-module.nix { };
  # Only the Vulkan and OpenCL ICD files go to /run/opengl-driver: the
  # package's own libEGL and libgbm would collide with Mesa's there.
  gpuIcds = pkgs.runCommand "a733-vendor-gpu-icds" { } ''
    mkdir -p $out/share/vulkan $out/etc/OpenCL
    ln -s ${gpu}/share/vulkan/icd.d $out/share/vulkan/icd.d
    ln -s ${gpu}/etc/OpenCL/vendors $out/etc/OpenCL/vendors
  '';

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
  options.hardware.a733.vendor = {
    enable = lib.mkEnableOption ''
      the manufacturer's 6.6 kernel, U-Boot 2018.05, boot blobs, firmware and
      drivers, pinned in vendor/sources.json
    '';

    wifi.enable = lib.mkOption {
      type = lib.types.bool;
      default = true;
      description = "AIC8800 Wi-Fi: its firmware and the aic8800_fdrv driver.";
    };

    bluetooth.enable = lib.mkOption {
      type = lib.types.bool;
      default = true;
      description = ''
        AIC8800 Bluetooth on ttyS1, attached at boot the way the
        manufacturer's orangepi-hardware-optimization does it, with BlueZ.
      '';
    };

    video.enable = lib.mkOption {
      type = lib.types.bool;
      default = true;
      description = ''
        The hardware video engine as the manufacturer's image sets it up:
        libcedarc (decoders, H.264 and H.265 encoders, OpenMAX components),
        the camera ISP library, the GStreamer omx plugin and the device
        permissions from their udev rules. GStreamer finds the plugin through
        GST_PLUGIN_PATH_1_0, set for login sessions; a service that uses it
        needs the same variable in its environment.
      '';
    };

    npu.enable = lib.mkOption {
      type = lib.types.bool;
      default = true;
      description = ''
        The NPU runtime (VIPLite: libVIPhal, libNBGlinker, vpm_run) for the
        aw_nna_vip kernel module, as the manufacturer's image installs it.
      '';
    };

    gpu.enable = lib.mkOption {
      type = lib.types.bool;
      # Off until the pvrsrvkm build is proven in CI.
      default = false;
      description = ''
        The PowerVR BXM GPU: the pvrsrvkm module built from the vendor
        kernel's bsp/modules/gpu, its firmware, and the manufacturer's Vulkan,
        OpenCL and EGL/GLES drivers, registered through hardware.graphics.
      '';
    };

    usbHost = lib.mkOption {
      type = lib.types.bool;
      default = true;
      description = ''
        Put the USB-C port in host mode at boot, as the manufacturer's image
        does. Off leaves the controller in its default OTG role.
      '';
    };

    overlays = lib.mkOption {
      type = lib.types.listOf lib.types.str;
      default = [ ];
      example = [
        "uart2"
        "i2c1"
        "spi3-cs0-cs1-spidev"
        "pwm1"
      ];
      description = ''
        Device tree overlays applied by U-Boot at boot, by name without the
        sun60i-a733- prefix: the overlays= setting of the manufacturer's
        orangepiEnv.txt. They come from the kernel's
        arch/arm64/boot/dts/allwinner/overlay; a name that does not exist
        fails the boot loader installation.
      '';
    };
  };

  config = lib.mkIf cfg.enable {
    hardware.a733.kernel = kernel;
    hardware.a733.deviceTree = sources.kernel.deviceTree;

    # The manufacturer's U-Boot reads boot.scr, not extlinux.conf.
    boot.loader.generic-extlinux-compatible.enable = false;
    system.build.installBootLoader = "${lib.getExe installBoot}";
    system.boot.loader.id = "a733-vendor";

    # From the manufacturer's boot-sun60iw2.cmd. Its cgroup_enable and
    # swapaccount flags are left out: they only mean something on cgroup v1.
    boot.kernelParams = [
      # Early output on UART0.
      "earlyprintk=sunxi-uart,0x02500000"
      # The manufacturer's drivers expect clocks nobody claims to stay on.
      "clk_ignore_unused"
      # The DMA bounce buffer size their drivers are tuned for.
      "swiotlb=65536"
      "consoleblank=0"
    ];

    # Only the manufacturer's binaries this module installs, by name.
    nixpkgs.config.allowUnfreePredicate =
      pkg:
      builtins.elem (lib.getName pkg) [
        "a733-vendor-aic8800d80-firmware"
        "a733-vendor-hciattach"
        "a733-vendor-media"
        "a733-vendor-npu"
        "a733-vendor-gpu"
      ];

    hardware.firmware =
      lib.optional (cfg.wifi.enable || cfg.bluetooth.enable) firmware ++ lib.optional cfg.gpu.enable gpu;
    # NixOS picks zstd from the kernel version, but this kernel is built
    # without CONFIG_FW_LOADER_COMPRESS and cannot load compressed firmware.
    hardware.firmwareCompression = "none";

    # MODULES="aic8800_fdrv aic8800_btlpm" in the manufacturer's board config.
    boot.kernelModules =
      lib.optional cfg.wifi.enable "aic8800_fdrv"
      ++ lib.optional cfg.bluetooth.enable "aic8800_btlpm"
      ++ lib.optional cfg.gpu.enable "pvrsrvkm";

    boot.extraModulePackages = lib.mkIf cfg.gpu.enable [ gpuModule ];

    # Vulkan and OpenCL find the ICD files through /run/opengl-driver.
    hardware.graphics = lib.mkIf cfg.gpu.enable {
      enable = true;
      extraPackages = [ gpuIcds ];
    };

    hardware.bluetooth.enable = lib.mkIf cfg.bluetooth.enable (lib.mkDefault true);

    systemd.services.a733-bluetooth = lib.mkIf cfg.bluetooth.enable {
      description = "Attach the AIC8800 Bluetooth core on ttyS1";
      wantedBy = [ "bluetooth.target" ];
      before = [ "bluetooth.service" ];
      after = [ "systemd-modules-load.service" ];
      # aic8800_btlpm creates btwrite; writing 1 wakes the Bluetooth core.
      preStart = ''
        for _ in $(seq 30); do
          [ -e /proc/bluetooth/sleep/btwrite ] && break
          sleep 1
        done
        echo 1 > /proc/bluetooth/sleep/btwrite
      '';
      serviceConfig = {
        ExecStart = "${lib.getExe hciattach} -n -s 1500000 /dev/ttyS1 aic";
        Restart = "on-failure";
        RestartSec = 5;
      };
    };

    environment.systemPackages = lib.optional cfg.video.enable media ++ lib.optional cfg.npu.enable npu;
    environment.pathsToLink = lib.mkIf cfg.video.enable [ "/lib/gstreamer-1.0" ];
    environment.sessionVariables = lib.mkIf cfg.video.enable {
      GST_PLUGIN_PATH_1_0 = [ "/run/current-system/sw/lib/gstreamer-1.0" ];
    };
    # libcdc_base reads /etc/cedarc.conf; gst-omx looks for its config in
    # the XDG config directories.
    environment.etc = lib.mkIf cfg.video.enable {
      "cedarc.conf".source = "${media}/etc/cedarc.conf";
      "xdg/gstomx-allwinner.conf".source = "${media}/etc/xdg/gstomx-allwinner.conf";
    };
    # The manufacturer's 99-t527-permissions.rules.
    services.udev.extraRules = lib.mkIf cfg.video.enable ''
      KERNEL=="system", SUBSYSTEM=="dma_heap", GROUP="video", MODE="0660"
      KERNEL=="reserved", SUBSYSTEM=="dma_heap", GROUP="video", MODE="0660"
      KERNEL=="sunxi_soc_info", MODE="0666"
      KERNEL=="renderD128", SUBSYSTEM=="drm", MODE="0666"
      KERNEL=="cedar_dev", MODE="0666"
      KERNEL=="cedar_dev_ve2", MODE="0666"
      KERNEL=="g2d", MODE="0666"
    '';

    systemd.services.a733-usb-host = lib.mkIf cfg.usbHost {
      description = "Put the USB-C port in host mode";
      wantedBy = [ "multi-user.target" ];
      unitConfig.ConditionPathExists = "/sys/devices/platform/soc@3000000/10.usbc0/otg_role";
      serviceConfig = {
        Type = "oneshot";
        RemainAfterExit = true;
        ExecStart = "${pkgs.runtimeShell} -c 'echo usb_host > /sys/devices/platform/soc@3000000/10.usbc0/otg_role'";
      };
    };

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

    assertions = [
      {
        assertion =
          config.hardware.firmwareCompression == "none" || kernel.config.isEnabled "FW_LOADER_COMPRESS";
        message = "vendor kernel: compressed firmware needs CONFIG_FW_LOADER_COMPRESS";
      }
    ]
    ++ map (option: {
      assertion = kernel.config.isEnabled option;
      message = "vendor kernel: CONFIG_${option} must be enabled in vendor/kernel/sun60iw2-a733.config";
    }) required;
  };
}
