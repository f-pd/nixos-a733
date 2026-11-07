# The manufacturer's 6.6 kernel, built from source with its own config.
#
# kernel/sun60iw2-a733.config is linux-sun60iw2-current-a733.config from
# orangepi-build at the pinned commit, with the options systemd needs turned
# on: FHANDLE, TMPFS_POSIX_ACL, CRYPTO_USER_API and CRYPTO_USER_API_HASH.
{
  lib,
  linuxManualConfig,
  fetchFromGitHub,
  ...
}@args:
let
  src = (lib.importJSON ./sources.json).kernel;
in
linuxManualConfig (
  (removeAttrs args [
    "lib"
    "linuxManualConfig"
    "fetchFromGitHub"
  ])
  // {
    inherit (src) version;
    modDirVersion = src.version;

    src = fetchFromGitHub {
      inherit (src)
        owner
        repo
        rev
        hash
        ;
    };

    # A path, so the config is read at evaluation time without building anything.
    configfile = ./kernel/sun60iw2-a733.config;

    extraMeta = {
      description = "Orange Pi 6.6 kernel for the Allwinner A733";
      platforms = [ "aarch64-linux" ];
    };
  }
)
