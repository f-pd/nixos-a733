# Trusted Firmware-A for the A733, built from source.
{
  lib,
  buildArmTrustedFirmware,
  fetchgit,
}:
let
  src = (lib.importJSON ./sources.json).tf-a;
in
buildArmTrustedFirmware {
  inherit (src) platform;
  version = "a733-${builtins.substring 0 7 src.rev}";
  src = fetchgit {
    inherit (src) url rev hash;
  };
  extraMeta.platforms = [ "aarch64-linux" ];
  filesToInstall = [ "build/${src.platform}/release/bl31.bin" ];
}
