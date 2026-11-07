# Kernel options on top of the arm64 defconfig and the NixOS common config.
# Only options that exist in mainline go here: options introduced by the A733
# patches belong next to them, gated on the patch being applied.
{ lib }:
with lib.kernel;
{
  ARCH_SUNXI = yes;

  # Serial console on UART0 (ttyS0, 115200 baud)
  SERIAL_8250 = yes;
  SERIAL_8250_CONSOLE = yes;
  SERIAL_8250_DW = yes;

  # SD card and root filesystem
  MMC = yes;
  MMC_SUNXI = yes;
  BTRFS_FS = yes;
}
