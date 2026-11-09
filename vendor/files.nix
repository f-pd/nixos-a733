# The files used from orangepi-build, kept in vendor/blobs/orangepi-build at
# the paths they have in that repository at the pinned commit.
{ lib }:
let
  build = (lib.importJSON ./sources.json).build;
in
lib.mapAttrs (
  name: file:
  import ./blob.nix {
    repo = build.repo;
    inherit (file) path hash;
  }
) build.files
