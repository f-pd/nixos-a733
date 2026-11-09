# The PowerVR BXM GPU user space and firmware from the manufacturer's
# xserver-xorg-img-bxm package:
#
#   lib/firmware/rgx.{fw,sh}.36.56.104.183   GPU firmware, loaded by pvrsrvkm
#   lib/libVK_IMG.so, share/vulkan/icd.d     Vulkan driver and its ICD file
#   lib/libPVROCL.so, etc/OpenCL/vendors     OpenCL driver and its ICD file
#   lib/libsrv_um.so, libusc.so, ...         the services they share
#   lib/libEGL.so, libGLESv2.so, lib/dri     their Mesa fork for EGL and GLES
#
# Left out: their Xorg, modesetting driver, LightDM unit and the generic
# Vulkan and OpenCL loaders, which come from nixpkgs.
{
  lib,
  stdenv,
  callPackage,
  autoPatchelfHook,
  dpkg,
  libdrm,
  expat,
  zlib,
  systemdLibs,
  libX11,
  libxcb,
  libxshmfence,
}:
let
  debs = callPackage ./packages.nix { };
in
stdenv.mkDerivation {
  pname = "a733-vendor-gpu";
  version = "24.2.6603887";

  dontUnpack = true;

  nativeBuildInputs = [
    autoPatchelfHook
    dpkg
  ];

  buildInputs = [
    stdenv.cc.cc.lib
    libdrm
    expat
    zlib
    systemdLibs
    libX11
    libxcb
    libxshmfence
  ];

  appendRunpaths = [ "${placeholder "out"}/lib" ];

  installPhase = ''
    runHook preInstall

    dpkg-deb -x ${debs.gpu} root

    mkdir -p $out/lib/firmware $out/lib/dri
    cp -a root/lib/firmware/rgx.* $out/lib/firmware/

    for lib in GLESv1_CM_PVR_MESA GLESv2_PVR_MESA PVROCL PVRScopeServices VK_IMG \
               glslcompiler pvr_dri_support srv_um sutu_display ufwriter usc; do
      cp -a root/usr/lib/lib$lib.so* $out/lib/
    done
    for lib in EGL GLESv1_CM GLESv2 gbm glapi pvr_mesa_wsi; do
      cp -a root/usr/local/lib/lib$lib.so* $out/lib/
    done
    cp -a root/usr/local/lib/dri/*.so $out/lib/dri/

    mkdir -p $out/share/vulkan/icd.d $out/etc/OpenCL/vendors
    cat > $out/share/vulkan/icd.d/img_icd.aarch64.json <<EOF
    {
        "file_format_version": "1.0.0",
        "ICD": {
            "library_path": "$out/lib/libVK_IMG.so.1",
            "api_version": "1.3.277"
        }
    }
    EOF
    echo "$out/lib/libPVROCL.so.1" > $out/etc/OpenCL/vendors/pvr.icd

    runHook postInstall
  '';

  meta = {
    description = "PowerVR BXM GPU firmware, Vulkan, OpenCL and EGL/GLES drivers for the A733";
    license = lib.licenses.unfree;
    platforms = [ "aarch64-linux" ];
  };
}
