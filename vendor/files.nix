# The files used from orangepi-build, each fetched at the pinned commit and
# checked against its own hash.
{ lib, fetchurl }:
let
  build = (lib.importJSON ./sources.json).build;
in
lib.mapAttrs (
  name: file:
  fetchurl {
    name = "a733-vendor-${baseNameOf file.path}";
    url = "https://raw.githubusercontent.com/${build.owner}/${build.repo}/${build.rev}/${file.path}";
    inherit (file) hash;
  }
) build.files
