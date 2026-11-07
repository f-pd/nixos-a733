# SD card image for A733 boards: the NixOS sd-image with boot0 and U-Boot
# (TF-A inside) written at their offsets, before the first partition.
{
  config,
  lib,
  pkgs,
  modulesPath,
  ...
}:
let
  cfg = config.hardware.a733.sdImage;

  sources = lib.importJSON ../bootloader/sources.json;
  pinned = name: sources.${name}.hash != null;

  boot0 = pkgs.callPackage ../bootloader/boot0.nix { };
  uboot = pkgs.callPackage ../bootloader/u-boot.nix {
    tf-a = pkgs.callPackage ../bootloader/tf-a.nix { };
  };

  pinnedBlobs =
    lib.optional (pinned "boot0") {
      name = "boot0";
      file = boot0;
      offsetKiB = sources.boot0.sdOffsetKiB;
    }
    ++ lib.optional (pinned "u-boot" && pinned "tf-a") {
      name = "u-boot";
      file = "${uboot}/u-boot-sunxi-with-spl.bin";
      offsetKiB = sources.u-boot.sdOffsetKiB;
    };

  writeBlob = blob: ''
    echo "a733: writing ${blob.name} at ${toString blob.offsetKiB} KiB"
    dd if=${blob.file} of=$img bs=1K seek=${toString blob.offsetKiB} conv=notrunc status=none
  '';
in
{
  imports = [ "${modulesPath}/installer/sd-card/sd-image.nix" ];

  options.hardware.a733.sdImage.bootBlobs = lib.mkOption {
    type = lib.types.listOf (
      lib.types.submodule {
        options = {
          name = lib.mkOption { type = lib.types.str; };
          file = lib.mkOption { type = lib.types.path; };
          offsetKiB = lib.mkOption { type = lib.types.ints.unsigned; };
        };
      }
    );
    default = pinnedBlobs;
    defaultText = lib.literalMD "boot0 and U-Boot, once pinned in `bootloader/sources.json`";
    description = ''
      Raw blobs written before the first partition, in order: boot0 first,
      then U-Boot. Empty until the boot chain is pinned in
      bootloader/sources.json, in which case the image is not bootable.
    '';
  };

  config = {
    # enableAllHardware asks the initrd for modules this kernel may not build.
    hardware.enableAllHardware = lib.mkForce false;

    sdImage = {
      # Room for boot0 and U-Boot before the firmware partition.
      firmwarePartitionOffset = lib.mkDefault 32;
      populateFirmwareCommands = "";
      populateRootCommands = ''
        mkdir -p ./files/boot
        ${config.boot.loader.generic-extlinux-compatible.populateCmd} \
          -c ${config.system.build.toplevel} -d ./files/boot
      '';
      postBuildCommands = lib.concatMapStrings writeBlob cfg.bootBlobs;
    };

    warnings = lib.optional (cfg.bootBlobs == [ ]) ''
      hardware.a733.sdImage.bootBlobs is empty: the SD image has no boot0 and
      no U-Boot and will not boot until the boot chain is pinned.
    '';
  };
}
