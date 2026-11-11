# Generic image: boots to a root login on the serial console. The first login
# sets the root password and creates the main user (modules/welcome.nix); SSH
# starts after that. Meant for first boot and for anyone with an A733 board;
# real hosts build their own image from their own config.
{ lib, ... }:
{
  networking.hostName = "nixos-a733";

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
