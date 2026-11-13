# U-Boot for the Orange Pi Zero 3W, built from source: the SPL with our DRAM
# library, BL31 and U-Boot in one file, u-boot-sunxi-with-spl.bin.
#
# The library sources are copied into the tree from ./dram, so there is one
# copy of them. The SPL links the PHY training firmware (dramPayload): unless
# that is the zero-filled stand-in, the result is marked "nopublish" and must
# not reach a binary cache or a release.
{
  lib,
  buildUBoot,
  fetchFromGitHub,
  tf-a,
  dramPayload,
}:
let
  src = (lib.importJSON ./sources.json).u-boot;
in
(buildUBoot {
  inherit (src) defconfig;
  version = "a733-${builtins.substring 0 7 src.rev}";
  src = fetchFromGitHub {
    inherit (src) owner repo;
    inherit (src) rev hash;
  };
  extraPatches = map (patch: ./patches/u-boot + "/${patch}") src.patches;
  extraMakeFlags = [
    "BL31=${tf-a}/bl31.bin"
    "A733_DRAM_PAYLOAD=${dramPayload}/a733-dram-payload.bin"
  ];
  extraMeta.platforms = [ "aarch64-linux" ];
  filesToInstall = [
    "u-boot-sunxi-with-spl.bin"
    "spl/sunxi-spl.bin"
    "spl/u-boot-spl"
    "spl/u-boot-spl.map"
    ".config"
  ];
}).overrideAttrs
  (old: {
    pname = old.pname + (if dramPayload.zero then "-zero-payload" else "-nopublish");

    postPatch = (old.postPatch or "") + ''
      cp -r ${./dram/include} arch/arm/mach-sunxi/a733_dram/include
      cp -r ${./dram/src} arch/arm/mach-sunxi/a733_dram/src
      chmod -R u+w arch/arm/mach-sunxi/a733_dram
    '';

    passthru = (old.passthru or { }) // {
      inherit (src) sdOffsetKiB;
    };
  })
