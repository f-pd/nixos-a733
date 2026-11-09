# pvrsrvkm, the kernel module of the PowerVR BXM GPU, built out of tree from
# the vendor kernel's bsp/modules/gpu the way orangepi-build does
# (make -C bsp/modules/gpu with LICHEE_* variables), against the vendor
# kernel's build tree.
{
  lib,
  stdenv,
  kernel,
  python3,
  perl,
}:
let
  kdir = "${kernel.dev}/lib/modules/${kernel.modDirVersion}/build";
  ko = "img-bxm/linux/rogue_km/binary_sunxi_linux_nulldrmws_release/target_aarch64/kbuild/pvrsrvkm.ko";
in
stdenv.mkDerivation {
  pname = "a733-vendor-pvrsrvkm";
  inherit (kernel) version src;

  nativeBuildInputs = kernel.moduleBuildDependencies ++ [
    python3
    perl
  ];

  hardeningDisable = [
    "pic"
    "format"
  ];

  # The DDK build lives in the kernel source but is built on its own.
  postUnpack = ''
    sourceRoot="$sourceRoot/bsp/modules/gpu"
  '';

  postPatch = ''
    patchShebangs .
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

  installPhase = ''
    runHook preInstall
    install -D -m 644 ${ko} $out/lib/modules/${kernel.modDirVersion}/extra/pvrsrvkm.ko
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
