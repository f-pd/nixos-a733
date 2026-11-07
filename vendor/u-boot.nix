# The manufacturer's U-Boot 2018.05, built from source. It runs in 32-bit
# mode, so it is built with an armv7 cross compiler.
{
  lib,
  pkgsCross,
  fetchFromGitHub,
}:
let
  src = (lib.importJSON ./sources.json).u-boot;

  # Newer compilers reject what a 2018 tree takes for granted.
  oldCodeFlags = lib.concatStringsSep " " [
    "-fcommon"
    "-std=gnu11"
    "-Wno-error=implicit-function-declaration"
    "-Wno-error=implicit-int"
    "-Wno-error=int-conversion"
    "-Wno-error=incompatible-pointer-types"
    "-Wno-error=address-of-packed-member"
  ];
in
(pkgsCross.armv7l-hf-multiplatform.buildUBoot {
  inherit (src) defconfig;
  version = "2018.05-sun60iw2-${builtins.substring 0 7 src.rev}";

  src = fetchFromGitHub {
    inherit (src)
      owner
      repo
      rev
      hash
      ;
  };

  filesToInstall = [ "u-boot.bin" ];
  extraMeta.platforms = [ "armv7l-linux" ];
}).overrideAttrs
  (old: {
    env = (old.env or { }) // {
      NIX_CFLAGS_COMPILE = oldCodeFlags;
      NIX_CFLAGS_COMPILE_FOR_BUILD = oldCodeFlags;
    };
  })
