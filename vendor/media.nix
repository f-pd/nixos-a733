# The manufacturer's hardware video stack, as their image installs it:
#
#   libcedarc    the Cedar video engine: hardware decoders, the H.264 and H.265
#                encoders and their OpenMAX IL components, on /dev/cedar_dev
#   libAWIspApi  the camera image signal processor library
#   gst-omx      the GStreamer OpenMAX plugin for those components, with the
#                manufacturer's gstomx-allwinner.conf
#
# Prebuilt arm64 Debian binaries. The libraries open each other by name
# (libOmxCore loads libOmxVdec and libOmxVenc, libvideoengine loads the
# decoders), so their own lib directory is added to every RUNPATH.
{
  lib,
  stdenv,
  callPackage,
  autoPatchelfHook,
  dpkg,
  glib,
  gst_all_1,
}:
let
  debs = callPackage ./packages.nix { };
in
stdenv.mkDerivation {
  pname = "a733-vendor-media";
  version = "2.0.0";

  dontUnpack = true;

  nativeBuildInputs = [
    autoPatchelfHook
    dpkg
  ];

  buildInputs = [
    glib
    gst_all_1.gstreamer
    gst_all_1.gst-plugins-base
  ];

  appendRunpaths = [ "${placeholder "out"}/lib" ];

  installPhase = ''
    runHook preInstall

    for deb in ${debs.libcedarc} ${debs.libAWIspApi} ${debs.gst-omx} ${debs.gst-omx-config}; do
      dpkg-deb -x "$deb" root
    done

    mkdir -p $out/lib $out/lib/gstreamer-1.0 $out/etc/xdg
    cp -a root/usr/lib/aarch64-linux-gnu/*.so* $out/lib/
    cp -a root/usr/lib/aarch64-linux-gnu/gstreamer-1.0/*.so $out/lib/gstreamer-1.0/
    install -m 644 root/etc/cedarc.conf $out/etc/cedarc.conf

    # The plugin config points at the Debian library path.
    substitute root/etc/xdg/gstomx-allwinner.conf $out/etc/xdg/gstomx-allwinner.conf \
      --replace-fail /usr/lib/aarch64-linux-gnu/libOmxCore.so $out/lib/libOmxCore.so

    runHook postInstall
  '';

  meta = {
    description = "Allwinner Cedar video engine, ISP library and GStreamer OpenMAX plugin for the A733";
    license = lib.licenses.unfree;
    platforms = [ "aarch64-linux" ];
  };
}
