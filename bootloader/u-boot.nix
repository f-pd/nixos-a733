# U-Boot for the A733, built from source with TF-A embedded.
{
  lib,
  buildUBoot,
  fetchgit,
  tf-a,
}:
let
  src = (lib.importJSON ./sources.json).u-boot;
in
(buildUBoot {
  inherit (src) defconfig;
  version = "a733-${builtins.substring 0 7 src.rev}";
  src = fetchgit {
    inherit (src) url rev hash;
  };
  extraMakeFlags = [ "BL31=${tf-a}/bl31.bin" ];
  extraMeta.platforms = [ "aarch64-linux" ];
  filesToInstall = [ "u-boot-sunxi-with-spl.bin" ];
}).overrideAttrs
  (old: {
    passthru = (old.passthru or { }) // {
      inherit (src) sdOffsetKiB;
    };
  })
