# Firmware for the AIC8800D80 Wi-Fi and Bluetooth chip on the Zero 3W, from
# the manufacturer's firmware repository at the pinned commit, kept in
# vendor/blobs/firmware/aic8800d80. The drivers
# load it with request_firmware as aic8800d80/<file>, so it goes in
# hardware.firmware.
{
  lib,
  stdenvNoCC,
}:
let
  src = (lib.importJSON ./sources.json).firmware;

  fetch =
    name: hash:
    import ./blob.nix {
      repo = src.repo;
      path = "aic8800d80/${name}";
      name = "a733-vendor-aic8800d80-${name}";
      inherit hash;
    };
in
stdenvNoCC.mkDerivation {
  pname = "a733-vendor-aic8800d80-firmware";
  version = builtins.substring 0 7 src.rev;

  dontUnpack = true;

  installPhase = ''
    runHook preInstall
    mkdir -p $out/lib/firmware/aic8800d80
    ${lib.concatStrings (
      lib.mapAttrsToList (name: hash: ''
        install -m 644 ${fetch name hash} $out/lib/firmware/aic8800d80/${name}
      '') src.aic8800d80
    )}
    runHook postInstall
  '';

  meta = {
    description = "AIC8800D80 Wi-Fi and Bluetooth firmware for the Orange Pi Zero 3W";
    license = lib.licenses.unfreeRedistributableFirmware;
    platforms = lib.platforms.linux;
  };
}
