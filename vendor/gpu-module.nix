# pvrsrvkm, the kernel module of the PowerVR BXM GPU, built out of tree from
# the vendor kernel's bsp/modules/gpu the way orangepi-build does
# (make -C bsp/modules/gpu with LICHEE_* variables), against the vendor
# kernel's build tree.
{
  lib,
  stdenv,
  buildPackages,
  kernel,
  python3,
  perl,
  which,
}:
let
  kdir = "${kernel.dev}/lib/modules/${kernel.modDirVersion}/build";
  ko = "img-bxm/linux/rogue_km/binary_sunxi_linux_nulldrmws_release/target_aarch64/kbuild/pvrsrvkm.ko";
in
stdenv.mkDerivation {
  pname = "a733-vendor-pvrsrvkm";
  inherit (kernel) version src;

  # which: the DDK finds echo and python3 through it.
  nativeBuildInputs = kernel.moduleBuildDependencies ++ [
    python3
    perl
    which
  ];

  hardeningDisable = [
    "pic"
    "format"
  ];

  # The DDK build lives in the kernel source but is built on its own.
  postUnpack = ''
    sourceRoot="$sourceRoot/bsp/modules/gpu"
  '';

  # The DDK's kbuild Makefile declares every target .SECONDARY, which make
  # 4.4 refuses next to the kernel's .NOTINTERMEDIATE: the kernel already
  # keeps those files, so the line only has to go.
  #
  # The manufacturer committed the output of one of their builds,
  # binary_sunxi_linux_nulldrmws_release, with symlinks to absolute paths on
  # their machine: the DDK keeps existing links, so it has to go.
  postPatch = ''
    rm -rf img-bxm/linux/rogue_km/binary_sunxi_linux_nulldrmws_release
    patchShebangs .
    substituteInPlace img-bxm/linux/rogue_km/build/linux/kbuild/Makefile.template \
      --replace-fail $'\n.SECONDARY:\n' $'\n'
  '';

  dontConfigure = true;

  # The DDK takes its tools as LICHEE_TOOLCHAIN_PATH/LICHEE_CROSS_COMPILER
  # and hardcodes /usr/bin/gcc for host tools: give it the build's own.
  makeFlags = [
    "LICHEE_KERN_DIR=${kdir}"
    "LICHEE_PLATFORM=linux"
    "LICHEE_TOOLCHAIN_PATH=${stdenv.cc}/bin"
    "LICHEE_CROSS_COMPILER=${stdenv.cc.targetPrefix}"
    "CROSS_COMPILE=${stdenv.cc.targetPrefix}"
    "ARCH=arm64"
    "HOST_CC=${stdenv.cc.targetPrefix}cc"
    "HOST_CXX=${stdenv.cc.targetPrefix}c++"
    "KERNEL_CC=${stdenv.cc.targetPrefix}cc"
    "KERNEL_LD=${stdenv.cc.targetPrefix}ld"
    "KERNEL_NM=${stdenv.cc.targetPrefix}nm"
    "KERNEL_OBJCOPY=${stdenv.cc.targetPrefix}objcopy"
  ];

  buildFlags = [ "build" ];

  # The DDK does not run modules_install, so the module is signed here the
  # way kbuild's cmd_sign does for every NixOS module: kmodigest appends the
  # signature and writes the pvrsrvkm.ko.cer aggregateModules expects. Debug
  # symbols go first, and no later strip may touch the signed file.
  dontStrip = true;

  installPhase = ''
    runHook preInstall
    dest=$out/lib/modules/${kernel.modDirVersion}/extra
    install -D -m 644 ${ko} $dest/pvrsrvkm.ko
    ${stdenv.cc.targetPrefix}strip --strip-debug $dest/pvrsrvkm.ko
    ${lib.getExe buildPackages.kmodigest} $dest/pvrsrvkm.ko
    runHook postInstall
  '';

  meta = {
    description = "PowerVR BXM GPU kernel module for the A733 vendor kernel";
    license = with lib.licenses; [
      gpl2Only
      mit
    ];
    platforms = [ "aarch64-linux" ];
  };
}
