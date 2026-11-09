# The manufacturer's prebuilt Debian packages, each fetched at the pinned
# commit of their sun60iw2_packages branch and checked against its own hash.
{ lib, fetchurl }:
let
  packages = (lib.importJSON ./sources.json).packages;
in
lib.mapAttrs (
  name: file:
  fetchurl {
    name = "a733-vendor-${baseNameOf file.path}";
    url = "https://raw.githubusercontent.com/${packages.owner}/${packages.repo}/${packages.rev}/${file.path}";
    inherit (file) hash;
  }
) packages.files
