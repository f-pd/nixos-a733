# Trusted Firmware-A for the A733, built from source: BL31, which the SPL
# loads to the start of DRAM.
{
  lib,
  buildArmTrustedFirmware,
  fetchFromGitHub,
}:
let
  src = (lib.importJSON ./sources.json).tf-a;
in
buildArmTrustedFirmware {
  inherit (src) platform;
  version = "a733-${builtins.substring 0 7 src.rev}";
  src = fetchFromGitHub {
    inherit (src) owner repo;
    inherit (src) rev hash;
  };
  patches = map (patch: ./patches/tf-a + "/${patch}") src.patches;
  # The branch is older than the compiler: its warnings are not errors here.
  extraMakeFlags = [ "E=0" ];
  extraMeta.platforms = [ "aarch64-linux" ];
  filesToInstall = [
    "build/${src.platform}/release/bl31.bin"
    "build/${src.platform}/release/bl31/bl31.elf"
  ];
}
