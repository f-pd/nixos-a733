# The PHY training firmware the DRAM library loads into the DRAM PHY: the
# ranges of the payload it reads, cut out of the manufacturer's boot0 by the
# offsets in docs/dram-init-spec.md.
#
# The firmware has no redistribution grant. The output is marked "nopublish"
# and must not reach a binary cache or a release; the CI push filter keys on
# that word. With zero = true the output has the same size and holds zeros
# only: for builds that are published, such as the SPL handed to analysis.
{
  lib,
  stdenv,
  callPackage,
  zero ? false,
}:
let
  files = callPackage ../vendor/files.nix { };
  source = if zero then "none" else files.boot0;
  mode = lib.optionalString zero "zero";
in
stdenv.mkDerivation {
  pname = "a733-dram-payload" + (if zero then "-zero" else "-nopublish");
  version = "1";

  src = ./dram;

  buildPhase = ''
    runHook preBuild
    make build/payload-pack
    build/payload-pack ${source} a733-dram-payload.bin ${mode}
    runHook postBuild
  '';

  installPhase = ''
    runHook preInstall
    install -Dm444 a733-dram-payload.bin $out/a733-dram-payload.bin
    runHook postInstall
  '';

  passthru = { inherit zero; };

  meta.platforms = [ "aarch64-linux" ];
}
