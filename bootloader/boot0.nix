# boot0 extracted from the official Orange Pi image.
#
# This is a fixed-output derivation: its hash is pinned in sources.json, so if
# the extracted bytes ever change the build fails instead of shipping them.
{
  lib,
  stdenvNoCC,
  fetchurl,
  xz,
  p7zip,
}:
let
  src = (lib.importJSON ./sources.json).boot0;
in
stdenvNoCC.mkDerivation {
  pname = "a733-boot0";
  version = "vendor";

  image = fetchurl {
    inherit (src.image) url hash;
  };

  nativeBuildInputs = [
    xz
    p7zip
  ];

  dontUnpack = true;

  buildPhase = ''
    runHook preBuild
    case "$image" in
      *.xz) xz -dc "$image" > image.img ;;
      *.7z) 7z e -so "$image" > image.img ;;
      *) cp "$image" image.img ;;
    esac
    dd if=image.img of=boot0.bin bs=1 \
      skip=${toString src.offsetBytes} count=${toString src.sizeBytes} status=none
    runHook postBuild
  '';

  installPhase = ''
    runHook preInstall
    cp boot0.bin $out
    runHook postInstall
  '';

  outputHashMode = "flat";
  outputHash = src.hash;

  passthru.sdOffsetKiB = src.sdOffsetKiB;
}
