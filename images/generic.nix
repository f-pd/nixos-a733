# Generic image: boots to a root login on the serial console. The first login
# sets the root password and creates the main user (modules/welcome.nix); SSH
# starts after that. Meant for first boot and for anyone with an A733 board;
# real hosts build their own image from their own config.
{ lib, pkgs, ... }:
{
  networking.hostName = "nixos-a733";

  # nmtui to join a Wi-Fi network once "radio on" has loaded the driver.
  networking.networkmanager.enable = true;

  # The same measurements on every image, Debian included: tools/a733-bench.sh.
  environment.systemPackages = [
    (pkgs.writeShellApplication {
      name = "a733-bench";
      # Each test reports its own failure and the run goes on.
      bashOptions = [ "nounset" ];
      runtimeInputs = with pkgs; [
        sysbench
        fio
        clinfo
        clpeak
        vulkan-tools
        gst_all_1.gstreamer
      ];
      # videotestsrc and fakesink; the omx plugin comes from GST_PLUGIN_PATH_1_0.
      runtimeEnv.GST_PLUGIN_SYSTEM_PATH_1_0 = lib.makeSearchPath "lib/gstreamer-1.0" [
        pkgs.gst_all_1.gstreamer.out
        pkgs.gst_all_1.gst-plugins-base
      ];
      text = builtins.readFile ../tools/a733-bench.sh;
    })
  ];

  # Empty root password, usable only where getty runs: the local consoles.
  # The welcome module makes the first login replace it, and holds SSH back
  # until then.
  users.mutableUsers = true;
  users.users.root.initialHashedPassword = "";
  hardware.a733.welcome.enable = true;

  services.openssh.enable = true;

  documentation.enable = false;

  # Boot logs on the FAT partition: the image is often tried without a serial
  # adapter, and this is then the only way to see how far it got.
  hardware.a733.bootLog.enable = true;

  system.stateVersion = lib.trivial.release;
}
