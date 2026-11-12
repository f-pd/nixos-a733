# Orange Pi Zero 3W: wiring inventory

What the vendor device tree says about how the board is wired, per peripheral: pins, regulators,
PMIC rails, clocks, resets and GPIOs. It is the input for a mainline-style device tree, whichever
patch stack is chosen. Nothing here was measured or run on the board.

## Sources

| File | Where | sha256 |
|---|---|---|
| `sun60i-a733-orangepi-zero3w.dts` (board, 4100 lines) | `orangepi-xunlong/linux-orangepi` @ `2ac08e8c7cdc` (the revision pinned in `vendor/sources.json`), `arch/arm64/boot/dts/allwinner/` | `31145367f604fd756f2c6a67447e5134e4be0ad5fae87672cfaa9b7c6d055a39` |
| `sun60iw2p1.dtsi` (SoC, 5098 lines) | same directory | `1c7313f655bdc4d018201664adcb1fa1d100280388b8975e193ebbfc6ad4ddfa` |
| `sys_config.fex` | `vendor/blobs/orangepi-build/external/packages/pack-uboot/sun60iw2/bin/sys_config/` | pinned in `vendor/sources.json` |

"dts:N" below is a line of the board file, "dtsi:N" a line of the SoC file. Names such as `CLK_UART0`
are the vendor clock and reset identifiers (`dt-bindings/clock/sun60iw2-ccu.h` and friends); they
identify the clock, the mainline bindings use other names and numbers.

## Read this first: how far to trust the vendor tree

- The board file declares `compatible = "xunlong,orangepi-4-pro"` (dts:9). It was derived from the
  Orange Pi 4 Pro tree and not cleaned up.
- It enables hardware the Zero 3W is not known to have: an 8-bit eMMC on `sdc2`, a PWM fan, a Goodix
  touchscreen, five LRADC keys, a battery charger (AXP515) with a battery table.
- It leaves out things a mainline tree needs: the UART0 pins are empty strings, the PCIe node has no
  reset GPIO, the Wi-Fi module has no 3.3 V supply, and no regulator carries a set voltage.
- Consequence: an entry that is `okay` here is a claim to confirm on the board, not a fact. The last
  section lists what to confirm and how.

## Pin summary

`pio` is the main controller (`pinctrl@2000000`, banks PB to PK), `r_pio` the always-on one
(`pinctrl@7025000`, banks PL and PM).

| Pin | Use | Source |
|---|---|---|
| PB9, PB10 | UART0 TX, RX (console), mux 2 | `sys_config.fex` `[uart_para]`; not in the dts |
| PF0 to PF5 | microSD: D1, D0, CLK, CMD, D3, D2 | dtsi:1013, `sys_config.fex` `[card0_boot_para]` |
| PF6 | microSD card detect, active low, pull-up | dts:1625 |
| PG0 | SDIO Wi-Fi clock | dtsi:1070 |
| PG1 to PG5 | SDIO Wi-Fi CMD and D0 to D3 (order not given) | dtsi:1056 |
| PG6 to PG9 | UART1 to Bluetooth (four pins: data and flow control, order not given) | dts:549 |
| PD5 | PWM0 channel 5, fan | dts:669, dts:1527 |
| PD21 | PCIe wake, active high | dts:1797 |
| PK22, PK23 | touchscreen reset, interrupt | dts:1878 |
| PK24, PK25 | TWI12 | dts:897 |
| PE7, PE8 | TWI11 | dts:885 |
| PE14, PE15 | TWI9 | dts:873 |
| PL0, PL1 | S_TWI0 to both PMICs | dts:1224 |
| PL7 | status LED, active high | dts:75 |
| PL8 | USB-C VBUS enable (fixed regulator), active high | dts:16 |
| PL9 | USB-C controller interrupt, active low, pull-up | dts:1217, dts:2584 |
| PL10, PL11 | S_TWI2 to the RTC | dts:1248 |
| PL12, PL13 | S_TWI1 to the USB-C controller | dts:1236 |
| PM0 | Wi-Fi host wake, active high | dts:2961 |
| PM1 | Wi-Fi enable (`wlan_regon`), active high | dts:2960 |
| PM2 | Bluetooth reset, active low | dts:2972 |
| PM3 | Bluetooth wake, active high | dts:2979 |
| PM4 | Bluetooth host wake, active high | dts:2980 |
| NMI | interrupt of both PMICs (`intc-nmi@7010320`, GIC SPI 188) | dtsi:408 |

PM4 is also `test-gpios` of the vendor `pinctrl_test` node (dtsi:1614); that node is test code.

## Per peripheral

### UART0 (console)

- Controller: `uart@2500000`, GIC SPI 2, FIFO 64, clock `CLK_UART0`, reset `RST_BUS_UART0` (dtsi:1621).
- Pins: the board file sets `pins = "", ""` (dts:537), so the vendor kernel relies on the pin mux the
  boot chain left behind. `sys_config.fex` gives PB9 (TX) and PB10 (RX), function 2.
- A mainline tree must name the pins itself. No supply is listed.

### microSD (`sdc0`)

- Controller: `sdmmc@4020000`, GIC SPI 161 (dtsi:4490).
- Clocks: `sys24M`, `CLK_PLL_PERI1_400M`, `CLK_PLL_PERI1_300M`, `CLK_SMHC0`, `CLK_BUS_SMHC0`,
  `CLK_STORE_AHB_GATE`, `CLK_MBUS_STORE_GATE`, `CLK_MSI_LITE1`. Reset `RST_BUS_SMHC0`.
- Pins: PF0 to PF5, 4-bit; clock pin PF2 at drive strength 30, the others at 10, all pull-up.
  Two pin states, 3.3 V and 1.8 V (`power-source`), for UHS signalling.
- Card detect: PF6, active low, pull-up.
- Supplies: card power `dc1sw2` (switch fed by `dcdc1`); I/O at 3.3 V from `dc1sw2`, at 1.8 V from `cldo5`.
- Modes claimed: high speed, UHS SDR50, DDR50, SDR104; `max-frequency` 150 MHz.

### AIC8800 Wi-Fi (SDIO on `sdc1`)

- Controller: `sdmmc@4021000`, GIC SPI 162 (dtsi:4545). Clocks as `sdc0` with `CLK_SMHC1` and
  `CLK_BUS_SMHC1`; reset `RST_BUS_SMHC1`.
- Pins: PG0 (clock, drive strength 20), PG1 to PG5 (drive strength 10), all pull-up, 4-bit.
- Node properties: SDIO only, SDIO interrupt, keeps power in suspend, UHS up to SDR104,
  `max-frequency` 208 MHz, no signal voltage switching (`sunxi-dis-signal-vol-sw`), no supply properties.
- Power and control come from the vendor `rfkill` node (dts:2944), not from the MMC node:
  - `wlan_power = "axp8191-bldo5", "axp8191-cldo1"`, both at 1.8 V; the comment reads `vcc-pg/vcc-pm`,
    so these look like the I/O rails of banks PG and PM, not the module's main supply;
  - enable PM1 (active high), host wake PM0 (active high, wake-up source);
  - `wlan_busnum = 1`; no clock is listed (no 32 kHz reference in the tree).
- The module's 3.3 V supply is not described. Two fixed regulators that would do it are commented
  out (dts:26 and dts:38): `wifi_power_en` on PB4 and `wifi_chip_en` on PM1.
- MAC addresses come from the vendor `addr_mgt` node (dts:2936); mainline has no equivalent.

### AIC8800 Bluetooth (UART1)

- Controller: `uart@2501000`, GIC SPI 3, FIFO 256, clock `CLK_UART1`, reset `RST_BUS_UART1` (dtsi:1633).
- Pins: PG6 to PG9, function `uart1`.
- Control: reset PM2 (active low), wake PM3, host wake PM4 (`btlpm`, `uart_index = 1`).
- Power: same two rails as Wi-Fi (`bldo5`, `cldo1`, 1.8 V).

### USB

Three controllers are enabled. The tree does not say which physical USB-C connector each one reaches.

| Node | Address | Role | Clocks and resets |
|---|---|---|---|
| `usbc0`: `udc`, `ehci0`, `ohci0` | `0x4100000`, `0x4101000`, `0x4101400`; GIC SPI 156, 157, 158 | USB 2.0 dual role (`usb_port_type = 2`) | `CLK_USB_REF`, `CLK_USB0_DEVICE`, `CLK_USB0_EHCI`, `CLK_USB0_OHCI`, `CLK_USB`, `CLK_USB_SYS_AHB_GATE`, `CLK_MSI_LITE2`; `RST_USB_0_DEVICE`, `RST_USB_0_EHCI`, `RST_USB_0_OHCI`, `RST_USB_0_PHY_RSTN` |
| `usbc1`: `ehci1`, `ohci1` | `0x4200000`; GIC SPI 159 | USB 2.0 host, wake-up source | `CLK_USB_REF`, `CLK_USB1_EHCI`, `CLK_USB_SYS_AHB_GATE`, `CLK_MSI_LITE2`; `RST_USB_1_EHCI`, `RST_USB_1_PHY_RSTN` |
| `usbc2`: `xhci2` (DWC3) | `0x6a00000`; GIC SPI 155 | USB 3 dual role, default host, role switch | `CLK_USB2_MF`, `CLK_USB2_U2_REF`, `CLK_USB2_SUSPEND` (24 MHz); `RST_USB_2`; power domain `SUN60IW2_PCK_USB2` |

- `usbc0`: VBUS detection through the PMIC (`usb_det_vbus_gpio = "axp_ctrl"`), no ID GPIO, detect I/O
  supply `aldo1`. All three USB 2.0 nodes carry `phy_range = <0x188>`.
- `usbc2` PHYs: `u2phy` (`phy@6b00000`) and `combo0_usb` inside the `serdes` block (`serdes@6c00000`,
  1.8 V from `cldo5`, clocks `CLK_SERDES_PHY_CFG`, `CLK_RTC_DCXO_SERDES0`, `CLK_RTC_DCXO_SERDES1`,
  `CLK_USB2_U3_UTMI`, `CLK_USB2_U2_PIPE`, reset `RST_BUS_SERDES`).
- Type-C port controller: on S_TWI1 (PL12, PL13, 400 kHz) at address `0x22`. The node is labelled
  `husb311` but its compatible is `fcs,fusb302` (dts:2580): which chip is fitted is not settled by the tree.
  Interrupt PL9 (active low). VBUS: fixed 5 V regulator `usb0-vbus` enabled by PL8 (active high).
- Connector node: dual data role, dual power role, tries sink first; sink 5 V up to 2 A, source 5 V up
  to 1.2 A; DisplayPort alternate mode (SVID `0xff01`).
- DisplayPort over USB-C: `phy_switcher` (dts:400) switches `combo0_dp` and `combo0_usb` with the plug
  orientation. Its AUX GPIOs (PL12, PL13) are commented out and collide with S_TWI1.

### PMICs (S_TWI0: PL0, PL1, 400 kHz, clock `CLK_R_TWI0`, reset `RST_BUS_R_TWI0`)

- `pmu@36`: AXP8191 (`x-powers,axp8191`), the main regulator. Interrupt: NMI. Power key child
  `x-powers,axp2101-pek`.
- `pmu@34`: AXP515 (`x-powers,axp515`), charger and USB power path: power key, USB power supply
  (`pmu_usb_typec_used = 1`), battery supply with a 7085 mAh table, `drivevbus` regulator. Interrupt: NMI.
  A battery charger on this board is unexpected; see the first section.

AXP8191 rails. The tree gives each rail its full range only, never a set voltage: the working
voltages are set by the boot chain and must be read from the running vendor system.

| Rail | Always on | Consumers named in the tree |
|---|---|---|
| `dcdc1` | yes | PCIe 3.3 V; input of `dc1sw1` and `dc1sw2` |
| `dcdc2` | yes | HDMI, NPU, eDP |
| `dcdc3` | yes | `cpu6` (second CPU cluster) |
| `dcdc4` | yes | GPU |
| `dcdc5` | yes | `cpu0` (first CPU cluster), DSU |
| `dcdc6`, `dcdc7`, `dcdc9` | yes | none named |
| `dcdc8` | yes | TWI12 |
| `rtcldo` | yes, fixed 1.8 V | none named |
| `aldo1` | yes | USB0 VBUS detect I/O, TWI0 |
| `aldo5` | no | audio codec AC101 (disabled) |
| `bldo1` | no | PCIe 1.8 V, TWI2, TWI3, TWI9 |
| `bldo2` | no | DSI panel (disabled), TWI7 |
| `bldo4` | no | audio codec AC101 (disabled) |
| `bldo5` | no | Wi-Fi and Bluetooth, 1.8 V |
| `cldo1` | yes | Wi-Fi and Bluetooth, 1.8 V |
| `cldo2` | yes | HDMI |
| `cldo3` | yes | none (eMMC supply, commented out) |
| `cldo5` | yes | microSD 1.8 V signalling, `serdes` 1.8 V |
| `dldo1` | yes | SID (efuse), 1.8 V |
| `eldo1`, `eldo6` | yes | none named |
| `dc1sw1` | yes | panels and Ethernet PHY (all disabled) |
| `dc1sw2` | yes | microSD power and 3.3 V I/O, fan, TWI5, TWI11 |
| `aldo2` to `aldo4`, `aldo6`, `bldo3`, `cldo4`, `dldo2` to `dldo6`, `eldo2` to `eldo5` | no | none named |

### HDMI

- Controller: `hdmi0@5520000`, GIC SPI 61, power domain `SUN60IW2_PCK_VO1` (dtsi:4287).
- Clocks: `CLK_HDMI_REF` (CEC), `CLK_HDMI`, `CLK_HDMI_SFR` (24 MHz), `CLK_HDCP_ESM`, `CLK_DCXO` (RTC CCU).
  Resets: `RST_BUS_HDMI_SUB`, `RST_BUS_HDMI_MAIN`, `RST_BUS_HDMI_HDCP`.
- Supplies: `dcdc2` and `cldo2`.
- DDC: the controller's own adapter (`hdmi_ddc_index = 20`), no TWI pins. CEC enabled. No hot-plug
  GPIO and no 5 V enable GPIO in the tree.
- Pixel clock from the PHY PLL (`hdmi_clock_source = 0`); on-board termination (`hdmi_resistor_select = 1`).
- Input: display engine `tcon3`. HDMI audio through `hdmi_codec`.

### PCIe

- Controller: `pcie@6000000` (`allwinner,sunxi-pcie-v300-rc`), one lane, `max-link-speed = 3`,
  power domain `SUN60IW2_PCK_PCIE` (dtsi:5046). GIC SPI 152 (sii), 153 (MSI), 136 to 143 (eDMA).
- Clocks: `CLK_PCIE0_AUX`, `CLK_PCIE0_AXI_SLV`, `CLK_ITS_PCIE0_A`. Resets: `RST_BUS_PCIE0`,
  `RST_BUS_PCIE0_PWRUP`, `RST_BUS_ITS_PCIE0`.
- PHY: `combo1_pcie` in the `serdes` block (1.8 V from `cldo5`).
- Board side (dts:1794): wake PD21 (active high), 1.8 V from `bldo1`, 3.3 V from `dcdc1`.
- Not described: reset (PERST#) GPIO, clock request, a switch for the connector's 3.3 V.

### LED

- One GPIO LED, `status_led`: PL7, active high, heartbeat trigger (dts:73).

### Buttons

- No `gpio-keys` node. Power key through the PMIC (`axp2101-pek` on the AXP8191, `axp515-pek` on the AXP515).
- LRADC (`lradc@2524000`, GIC SPI 37, `CLK_LRADC`, `RST_BUS_LRADC`) is enabled with five keys
  (key codes 115, 114, 139, 28, 172): probably inherited, to confirm.

### Watchdog

- `watchdog@2050000`, `allwinner,wdt-v103`, GIC SPI 106, no clock or reset listed (dtsi:1388).
  The board file does not touch it.
- For the mainline tree this is the node to get right with boot chain 1, which hands the watchdog
  over running (see `docs/mainline-notes.md`).

### Clocks and time

- 24 MHz crystal (`dcxo24M`), 32 kHz from the RTC CCU (`rtc_ccu@7090000`), 16 MHz internal RC.
- SoC RTC (`rtc@7090000`) is disabled; an external HYM8563 sits on S_TWI2 (PL10, PL11) at `0x51`
  and outputs `xin32k` (dts:2670).

### Enabled in the tree, relevance to this board unconfirmed

| Node | What it claims |
|---|---|
| `sdc2` | 8-bit eMMC on PC0 to PC16, HS400, no supplies |
| `fan0` | PWM fan on PWM0 channel 5 (PD5), 25 kHz, supply `dc1sw2`, used by both CPU thermal zones |
| `twi12` + `touchscreen@14` | Goodix GT9271 on PK24, PK25; interrupt PK23, reset PK22 |
| `twi9`, `twi11` | buses on PE14, PE15 (100 kHz) and PE7, PE8 (400 kHz), no devices |
| `gpadc0` | 8 channels enabled |
| `npu`, `gpu`, `de`, `vo0`, `vo1`, `tv0`, `tv1`, `mipi0`, `vind0` | display, GPU, NPU and camera blocks |
| `ufs` | present at the end of the file (dts:4094) |

Disabled in the tree: Ethernet (`gmac0`), eDP and DSI panels, AC101 and ES8388 audio codecs, infrared
receiver, LED strip controller, UART2, 3, 5, 6, 7, 8, TWI0, 1, 2, 3, 5, 7, 8.

The 40-pin header is not described as such: its signals are the disabled UART, TWI, SPI, PWM and I2S
pin groups in `&pio`.

## To confirm on the board

From the vendor image, before anything else is flashed:

| Question | How |
|---|---|
| Which tree the board really boots | `cat /sys/firmware/devicetree/base/compatible`, keep a copy of `/sys/firmware/fdt` |
| Rail voltages and which rails are on | `/sys/kernel/debug/regulator/regulator_summary` |
| Pin mux in use, UART0 pins included | `/sys/kernel/debug/pinctrl/*/pinmux-pins` |
| GPIO lines held and their levels | `/sys/kernel/debug/gpio` |
| Is an AXP515 present at `0x34`, an RTC at `0x51`, a Type-C controller at `0x22` | `dmesg`, `i2cdetect` on the three S_TWI buses |
| Is there an eMMC, a fan, a touchscreen | `dmesg`, `lsblk`; visual check of the board |
| Which USB-C connector is `usbc0`, `usbc1`, `usbc2` | plug a device in each, read `dmesg` |
| Wi-Fi module supply and 32 kHz clock | schematic if Orange Pi publishes one; otherwise the regulator and clock summaries |
| PCIe reset line | schematic; `/sys/kernel/debug/gpio` with a device on the FPC connector |
