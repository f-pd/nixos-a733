# Generic image: boots to a root login on the serial console and nothing more.
# No users, no SSH, no network services. Meant for first boot and for anyone
# with an A733 board; real hosts build their own image from their own config.
{ lib, ... }:
{
  networking.hostName = "nixos-a733";

  # Empty root password, usable only where getty runs: the local consoles.
  users.mutableUsers = true;
  users.users.root.initialHashedPassword = "";

  services.openssh.enable = false;

  documentation.enable = false;

  system.stateVersion = lib.trivial.release;
}
