# The manufacturer's hciattach, which knows the "aic" protocol of the
# AIC8800 Bluetooth core. It is a prebuilt arm64 binary that needs only libc.
{
  lib,
  stdenv,
  callPackage,
  autoPatchelfHook,
}:
let
  files = callPackage ./files.nix { };
in
stdenv.mkDerivation {
  pname = "a733-vendor-hciattach";
  version = "0";

  dontUnpack = true;

  nativeBuildInputs = [ autoPatchelfHook ];

  installPhase = ''
    runHook preInstall
    install -D -m 755 ${files.hciattach_opi} $out/bin/hciattach_opi
    runHook postInstall
  '';

  meta = {
    description = "Orange Pi hciattach with AIC8800 support";
    license = lib.licenses.unfree;
    platforms = [ "aarch64-linux" ];
    mainProgram = "hciattach_opi";
  };
}
