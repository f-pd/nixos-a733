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

  # Each make call of the configure phase (oldconfig, kernel.release) takes
  # seconds. A Kconfig loop would otherwise run until the CI job is killed.
  configureTimeout = "10m";
in
(linuxManualConfig (
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

    kernelPatches = [
      {
        # The touch screen Kconfig sources "gt9xx_secondary//Kconfig". Make
        # cannot find that path as a prerequisite of include/config/auto.conf
        # in an out of tree build, so it regenerates the config forever.
        name = "ctp-kconfig-double-slash";
        patch = ./patches/ctp-kconfig-double-slash.patch;
      }
    ];

    # A path, so the config is read at evaluation time without building anything.
    configfile = ./kernel/sun60iw2-a733.config;

    extraMeta = {
      description = "Orange Pi 6.6 kernel for the Allwinner A733";
      platforms = [ "aarch64-linux" ];
    };
  }
)).overrideAttrs
  (old: {
    preConfigure = (old.preConfigure or "") + ''
      make() { timeout ${configureTimeout} "$(type -P make)" "$@"; }
    '';
    preBuild = ''
      unset -f make
    ''
    + (old.preBuild or "");
  })
