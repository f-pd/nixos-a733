# The manufacturer's prebuilt packages and files from the sun60iw2_packages
# branch, kept in vendor/blobs/rk-rootfs-build at their paths in that branch.
{ lib }:
let
  packages = (lib.importJSON ./sources.json).packages;
in
lib.mapAttrs (
  name: file:
  import ./blob.nix {
    repo = packages.repo;
    inherit (file) path hash;
  }
) packages.files
