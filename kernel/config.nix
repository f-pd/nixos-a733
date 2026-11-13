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

  # From here on: options of the base patches (patches/base), which always
  # apply. Needed before any module can load: clocks, pins, the PMIC and its
  # regulators, the RTC, the power domains, PCIe.
  SUN60I_A733_CCU = yes;
  SUN60I_A733_R_CCU = yes;
  SUN60I_A733_CPU_CCU = yes;
  SUN60I_A733_SERDES_CCU = yes;
  PINCTRL_SUN60I_A733 = yes;
  PINCTRL_SUN55I_A523_R = yes;
  MFD_AXP20X_I2C = yes;
  REGULATOR_AXP20X = yes;
  RTC_DRV_SUN6I = yes;
  SUN55I_PCK600 = yes;
  NVMEM_SUNXI_SID = yes;
  PCIE_SUN60I_A733 = yes;

  # The rest of the board, as modules: USB 2 and 3 with their PHYs, the
  # Type-C controller of the Zero 3W, the PCIe PHY, PWM, the watchdog.
  PHY_SUN4I_USB = module;
  USB_MUSB_SUNXI = module;
  PHY_SUN60I_A733_USB2 = module;
  PHY_SUN60I_A733_COMBO = module;
  PHY_SUN60I_A733_PCIE_COMBO = module;
  USB_DWC3 = module;
  USB_DWC3_GENERIC_PLAT = module;
  TYPEC = module;
  TYPEC_TCPM = module;
  TYPEC_FUSB302 = module;
  PWM_SUN8I = module;
  SUNXI_WATCHDOG = module;
}
