# The manufacturer's NPU runtime (VIPLite) for the A733 neural processing unit,
# driven by the aw_nna_vip kernel module of the vendor kernel:
#
#   lib/libVIPhal.so, lib/libNBGlinker.so   the runtime
#   include/vip_lite*.h                     its headers
#   bin/vpm_run                             the manufacturer's network runner
#   share/a733-npu/vpm_run                  its sample network and input
#   share/a733-npu/yolov5.nb                the YOLOv5 model of their demo
#
# Their yolov5 demo binary is left out: it links Debian's OpenCV 4.5.
{
  lib,
  stdenv,
  callPackage,
  autoPatchelfHook,
}:
let
  files = callPackage ./packages.nix { };
in
stdenv.mkDerivation {
  pname = "a733-vendor-npu";
  version = "0";

  dontUnpack = true;

  nativeBuildInputs = [ autoPatchelfHook ];

  installPhase = ''
    runHook preInstall

    install -D -m 755 ${files.npu-libVIPhal} $out/lib/libVIPhal.so
    install -D -m 755 ${files.npu-libNBGlinker} $out/lib/libNBGlinker.so
    install -D -m 644 ${files."npu-vip_lite.h"} $out/include/vip_lite.h
    install -D -m 644 ${files."npu-vip_lite_common.h"} $out/include/vip_lite_common.h
    install -D -m 755 ${files.npu-vpm_run} $out/bin/vpm_run

    share=$out/share/a733-npu
    install -D -m 644 ${files.npu-vpm_run-readme} $share/vpm_run/readme.txt
    install -D -m 644 ${files.npu-vpm_run-sample} $share/vpm_run/sample.txt
    install -D -m 644 ${files.npu-vpm_run-input} $share/vpm_run/input_0.dat
    install -D -m 644 ${files.npu-vpm_run-network} $share/vpm_run/network_binary.nb
    install -D -m 644 ${files.npu-yolov5-model} $share/yolov5.nb

    runHook postInstall
  '';

  meta = {
    description = "Allwinner VIPLite NPU runtime for the A733";
    license = lib.licenses.unfree;
    platforms = [ "aarch64-linux" ];
  };
}
