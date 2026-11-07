{
  lib,
  callPackage,
  buildLinux,
  ...
}@args:
let
  src = callPackage ./source.nix { };
in
buildLinux (
  (removeAttrs args [
    "callPackage"
    "buildLinux"
  ])
  // {
    inherit src;
    inherit (src) version;
    modDirVersion = lib.versions.pad 3 src.version;

    # The A733 patches live in the source tree already: see source.nix.
    kernelPatches = [ ];

    structuredExtraConfig = import ./config.nix { inherit lib; };

    extraMeta = {
      description = "Latest stable Linux kernel with Allwinner A733 patches";
      platforms = [ "aarch64-linux" ];
    };
  }
)
