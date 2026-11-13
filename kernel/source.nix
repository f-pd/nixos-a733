# Latest stable kernel.org tarball with the A733 patches applied in two layers.
#
# base:     must apply. A failure stops the build.
# optional: applied when it applies cleanly, skipped otherwise. Skipped patches
#           are listed in .a733-optional-skipped at the root of the tree, which
#           CI turns into an issue.
{
  lib,
  stdenvNoCC,
  fetchurl,
  patch,
  writeText,
}:
let
  pin = lib.importJSON ./version.json;
  patches = import ../patches { inherit lib; };

  # One line per patch, store path and name. The lists go through files:
  # with a few hundred patches the commands no longer fit in the builder's
  # environment.
  series =
    layer: list:
    writeText "linux-a733-patches-${layer}" (lib.concatMapStrings (p: "${p.path} ${p.file}\n") list);
  baseSeries = series "base" patches.base;
  optionalSeries = series "optional" patches.optional;
in
stdenvNoCC.mkDerivation {
  pname = "linux-a733-source";
  inherit (pin) version;

  src = fetchurl {
    url = "mirror://kernel/linux/kernel/v${lib.versions.major pin.version}.x/linux-${pin.version}.tar.xz";
    inherit (pin) hash;
  };

  nativeBuildInputs = [ patch ];

  patchPhase = ''
    runHook prePatch
    : > .a733-optional-skipped
    while read -r path file; do
      echo "a733: applying base patch $file"
      patch -p1 --batch --forward < "$path"
    done < ${baseSeries}
    while read -r path file; do
      if patch -p1 --batch --forward --dry-run --silent < "$path" > /dev/null 2>&1; then
        echo "a733: applying optional patch $file"
        patch -p1 --batch --forward --silent < "$path"
      else
        echo "a733: skipping optional patch $file, it does not apply"
        echo "$file" >> .a733-optional-skipped
      fi
    done < ${optionalSeries}
    find . -name '*.orig' -delete

    # The board is arm64 and nothing else: drop every other architecture from
    # the tree. arch/arm stays because arm64 device trees include its dtsi.
    find arch -mindepth 1 -maxdepth 1 -type d ! -name arm64 ! -name arm -exec rm -rf {} +
    runHook postPatch
  '';

  dontConfigure = true;
  dontBuild = true;
  dontFixup = true;

  installPhase = ''
    runHook preInstall
    cp -r . $out
    runHook postInstall
  '';

  passthru = {
    inherit (pin) version;
    patchIndex = patches.all;
  };
}
