# SD card image for A733 boards: the NixOS sd-image with the boot chain
# written before the first partition. For the mainline chain that is one
# file, u-boot-sunxi-with-spl.bin (SPL, BL31 and U-Boot), at 128 KiB.
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

  uboot = pkgs.callPackage ../bootloader/u-boot.nix {
    tf-a = pkgs.callPackage ../bootloader/tf-a.nix { };
    dramPayload = pkgs.callPackage ../bootloader/dram-payload.nix { };
  };

  pinnedBlobs = lib.optional (pinned "u-boot" && pinned "tf-a") {
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
    defaultText = lib.literalMD "U-Boot with SPL and BL31, once pinned in `bootloader/sources.json`";
    description = ''
      Raw blobs written before the first partition, in order. The mainline
      chain has one, u-boot-sunxi-with-spl.bin at 128 KiB. Empty while the
      boot chain is not pinned in bootloader/sources.json, in which case
      the image is not bootable.
    '';
  };

  config = {
    # enableAllHardware asks the initrd for modules this kernel may not build.
    hardware.enableAllHardware = lib.mkForce false;

    sdImage = {
      # Room for the boot chain before the firmware partition.
      firmwarePartitionOffset = lib.mkDefault 32;
      # The partition stays empty unless boot logs are written to it.
      populateFirmwareCommands = lib.optionalString (config.hardware.a733.bootLog.enable or false) ''
        cp ${./boot-log-readme.txt} firmware/README-a733-boot-log.txt
      '';
      # mkDefault keeps this unevaluated when another loader replaces it.
      populateRootCommands = lib.mkDefault ''
        mkdir -p ./files/boot
        ${config.boot.loader.generic-extlinux-compatible.populateCmd} \
          -c ${config.system.build.toplevel} -d ./files/boot
      '';
      postBuildCommands = lib.concatMapStrings writeBlob cfg.bootBlobs;
    };

    warnings = lib.optional (cfg.bootBlobs == [ ]) ''
      hardware.a733.sdImage.bootBlobs is empty: the SD image has no boot
      chain and will not boot until it is pinned.
    '';
  };
}
