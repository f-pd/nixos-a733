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
    # buildUBoot also swaps a dtc warning flag for one that only recent U-Boot
    # trees carry, and fails on this 2018 tree. Keep only the shebang fixes,
    # and point the manufacturer's SHELL:=/bin/bash at the build's bash.
    postPatch = ''
      # scripts/sunxi_ubootools is a dynamically linked x86-64 binary; the
      # script does the same ubootlength step and runs on any build host.
      install -m 755 ${./sunxi-ubootools.sh} scripts/sunxi_ubootools

      patchShebangs tools
      patchShebangs scripts
      substituteInPlace Makefile --replace-fail "SHELL:=/bin/bash" "SHELL:=$(type -P bash)"

      # The Makefile unpacks the manufacturer's prebuilt toolchains from
      # ../tools/toolchain unless their directories exist. Nix provides the
      # compiler, so the empty directories are enough.
      mkdir -p ../tools/toolchain/riscv64-linux-x86_64-20200528 \
        ../tools/toolchain/gcc-linaro-7.2.1-2017.11-x86_64_arm-linux-gnueabi
    '';

    # buildUBoot sets HOSTCFLAGS=-fcommon, which replaces the tree's own
    # HOSTCFLAGS and drops -O2. This tree relies on the optimizer to remove the
    # FIT signing code it does not link, so mkimage fails to link without it.
    #
    # The manufacturer also adds a global -Werror, written for GCC 7. Newer GCC
    # warns about this tree (array-bounds on fixed addresses, attributes), so
    # KCFLAGS, appended last, keeps the warnings but not as errors.
    makeFlags =
      map (
        flag: if flag == "HOSTCFLAGS=-fcommon" then "HOSTCFLAGS=-O2 -fomit-frame-pointer -fcommon" else flag
      ) old.makeFlags
      ++ [ "KCFLAGS=-Wno-error" ];

    # The Makefile runs sunxi_ubootools through $(shell) and ignores its
    # result, so check the length field boot0 relies on.
    postBuild = (old.postBuild or "") + ''
      want=$(stat -c %s u-boot-nodtb.bin)
      got=$(od -An -t u4 -j $((0x4f0)) -N 4 u-boot.bin | tr -d ' ')
      if [ "$got" != "$want" ]; then
        echo "u-boot.bin: length field is $got, u-boot-nodtb.bin is $want bytes" >&2
        exit 1
      fi
      echo "u-boot.bin: length field $got matches u-boot-nodtb.bin"
    '';

    # board/sunxi/sunxi_challenge.c is generated with xxd.
    nativeBuildInputs = old.nativeBuildInputs ++ [
      pkgsCross.armv7l-hf-multiplatform.buildPackages.xxd
    ];

    env = (old.env or { }) // {
      NIX_CFLAGS_COMPILE = oldCodeFlags;
      NIX_CFLAGS_COMPILE_FOR_BUILD = oldCodeFlags;
    };
  })
