# The manufacturer's U-Boot 2018.05, built from source the way orangepi-build
# builds it: with Linaro GCC 7.4.1 arm-linux-gnueabi (32-bit, soft float).
#
# Built with the nixpkgs GCC for armv7l hard float, this tree hangs on the
# board right after the "CPU=... PLL6=..." line, before the interrupt
# controller comes up. Built with the Linaro compiler it boots (v0.2.0 image,
# checked on the serial console).
#
# Linaro only published that compiler for x86-64 hosts, so this is an
# x86_64-linux derivation: on an aarch64 machine it comes from the binary
# cache, or builds under emulation (extra-platforms = x86_64-linux with
# qemu-user registered in binfmt_misc).
{
  lib,
  path,
  fetchFromGitHub,
  fetchurl,
}:
let
  src = (lib.importJSON ./sources.json).u-boot;

  x86 = import path { system = "x86_64-linux"; };

  tarball = "gcc-linaro-7.4.1-2019.02-x86_64_arm-linux-gnueabi.tar.xz";

  linaro = x86.stdenvNoCC.mkDerivation {
    pname = "gcc-linaro-arm-linux-gnueabi";
    version = "7.4.1-2019.02";

    # releases.linaro.org is retired. The Armbian mirrors are where
    # orangepi-build downloads its toolchains from; Linaro's own archive
    # bucket is the last resort.
    src = fetchurl {
      urls = [
        "https://dl.armbian.com/_toolchain/${tarball}"
        "https://mirrors.tuna.tsinghua.edu.cn/armbian-releases/_toolchain/${tarball}"
        "https://mirrors.bfsu.edu.cn/armbian-releases/_toolchain/${tarball}"
        "https://publishing-ie-linaro-org.s3.amazonaws.com/releases/components/toolchain/binaries/7.4-2019.02/arm-linux-gnueabi/${tarball}"
      ];
      hash = "sha256-Qsyy7ZnWW3CQSZ5vWtZcTJSua9Ai3s/qEC1QEJVXx9I=";
    };

    nativeBuildInputs = [ x86.autoPatchelfHook ];
    buildInputs = [
      x86.stdenv.cc.cc.lib
      x86.zlib
    ];

    # The tree also holds the ARM target libraries: leave them as they are.
    dontStrip = true;

    installPhase = ''
      runHook preInstall
      mkdir -p $out
      cp -r . $out
      # gdb is the only program that needs Python 2 and ncurses 5.
      rm $out/bin/arm-linux-gnueabi-gdb
      runHook postInstall
    '';

    meta.platforms = [ "x86_64-linux" ];
  };

  # Newer host compilers reject what a 2018 tree takes for granted.
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
(x86.buildUBoot {
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
  extraMeta.platforms = [ "x86_64-linux" ];

  # compile_uboot in orangepi-build sets these after the defconfig.
  extraConfig = ''
    CONFIG_LOCALVERSION="-orangepi"
    CONFIG_BOOTDELAY=1
  '';
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
    makeFlags =
      map (
        flag: if flag == "HOSTCFLAGS=-fcommon" then "HOSTCFLAGS=-O2 -fomit-frame-pointer -fcommon" else flag
      ) old.makeFlags
      ++ [ "CROSS_COMPILE=arm-linux-gnueabi-" ];

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
      linaro
      x86.xxd
    ];

    # Only the host tools go through the nixpkgs compiler.
    env = (old.env or { }) // {
      NIX_CFLAGS_COMPILE = oldCodeFlags;
    };
  })
