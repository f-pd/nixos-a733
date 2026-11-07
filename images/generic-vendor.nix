# Phase 3 test image: the generic image on the manufacturer's kernel and boot
# chain. Boots to a root login on the serial console.
{
  imports = [ ./generic.nix ];

  hardware.a733.vendor.enable = true;
}
