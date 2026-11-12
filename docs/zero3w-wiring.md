# Orange Pi Zero 3W: wiring inventory

How the board is wired, per peripheral: pins, regulators, PMIC rails, clocks, resets and GPIOs.
It is the input for a mainline-style device tree, whichever patch stack is chosen. The pins come
from the vendor device tree; every entry was then compared with the manufacturer's schematic.
Nothing here was measured or run on the board.

## Sources

| Source | Where | Identification |
|---|---|---|
| `sun60i-a733-orangepi-zero3w.dts` (board, 4100 lines) | `orangepi-xunlong/linux-orangepi` @ `2ac08e8c7cdc` (pinned in `vendor/sources.json`), `arch/arm64/boot/dts/allwinner/` | sha256 `31145367f604fd756f2c6a67447e5134e4be0ad5fae87672cfaa9b7c6d055a39` |
| `sun60iw2p1.dtsi` (SoC, 5098 lines) | same directory | sha256 `1c7313f655bdc4d018201664adcb1fa1d100280388b8975e193ebbfc6ad4ddfa` |
| `sys_config.fex` | `vendor/blobs/orangepi-build/external/packages/pack-uboot/sun60iw2/bin/sys_config/` | pinned in `vendor/sources.json` |
| Schematic `OPi_ZERO_3W_V1_5-DSN.pdf`, 18 sheets | "Schematic" folder linked from the board's download page on orangepi.org | document title `OPI ZERO 3W V1_5_20260409`, author `xunlong`; its title blocks read `V1.2` |
| Position diagram `OPi_ZERO_3W_V1_5` | same folder | sha256 `634bcc7f7b02858ceaef1bc9bd9abf7fa90f23d18c442548e14a7f1f53254068` |
| Product page | orangepi.org, "OrangePi Zero 3W" | read 2026-11-12 |

"dts:N" is a line of the board file, "dtsi:N" a line of the SoC file, "sheet N" a sheet of the
schematic. Names such as `CLK_UART0` are the vendor clock and reset identifiers; they identify the
clock, the mainline bindings use other names and numbers.

## What was checked, and what was not

- The schematic was read as text only (part names, net names, sheet cross-references, notes).
  The drawings were not viewed: the download of the PDF was refused by the host ("quota exceeded")
  on 2026-11-12.
- So the schematic confirms which parts are fitted, which signals exist and which sheets they join.
  It does not confirm here on which SoC pin a net sits. Pin numbers below come from the vendor tree,
  which runs on the board in the vendor image; the 40-pin header pins also agree with `README.md`.
- "Schematic: agrees" below means the part or net is in the schematic under that function.
  "Schematic: differs" and "not in the schematic" are spelled out in the next section.
- Open item: read the drawings to tie each net to its pin (Wi-Fi control lines and PCIe first).

## Where the vendor tree and the schematic disagree

The board file declares `compatible = "xunlong,orangepi-4-pro"` (dts:9): it was copied from the
Orange Pi 4 Pro tree. These are the places where it does not describe this board.

| Subject | Vendor tree | Schematic | Consequence for a mainline tree |
|---|---|---|---|
| Main crystal | fixed clock `dcxo24M`, 24 MHz (dtsi:342) | Y1 is a 26 MHz crystal; notes "USE 26M", "default 26M" (sheet 8) | the oscillator frequency must be 26 MHz, or detected; confirm on the board |
| Charger PMIC | AXP515 at `0x34` on S_TWI0 with battery and USB supplies (dts:1957) | no such part; the only PMIC is U1 | leave it out |
| External RTC | HYM8563 at `0x51` on S_TWI2, SoC RTC disabled (dts:2670, dts:2565) | no such part; S-TWI2 goes to the 40-pin header; a 32.768 kHz crystal (Y2) is on the SoC | use the SoC RTC |
| USB1 | `usbc1`, `ehci1`, `ohci1` enabled | USB1 D+ and D- leave the SoC on no net | leave it disabled |
| LRADC keys | five keys enabled (dts:3319) | no key; the ADC inputs carry strapping nets (boot select, DDR parameters, board ID, LCD select) | leave it out |
| Bluetooth reset | `bt_rst_n` on PM2 (dts:2972) | five nets on PM0 to PM4: `WL-REG-ON`, `WL-WAKE-AP`, `AP_WAKE_WL`, `BT-WAKE-AP`, `AP-WAKE-BT`; none is a Bluetooth reset | PM2 is probably `AP_WAKE_WL`; settle it on the drawing |
| Wi-Fi 32 kHz clock | none listed | `AP-CK32K-OUT` from the SoC to the module's low-power clock input (sheets 8, 14) | the module needs the SoC's 32 kHz output enabled |
| Wi-Fi supplies | two 1.8 V rails by name, no 3.3 V | `VCC-3V3-WIFI` (module supply) and `VCCIO_1V8_WIFI` (I/O) | describe both |
| PCIe control | wake only (PD21) | `PCIE-PERSTn`, `PCIE-CLKREQn`, `PCIE-WAKEn`, `PCIE_PWREN_H` (sheets 9, 16) | reset, clock request and a power enable exist; pins to read from the drawing |
| Type-C controller | label `husb311`, compatible `fcs,fusb302` | U4 is an FUSB302MPX | the compatible is right, the label is not |
| PMIC name | `x-powers,axp8191` at `0x36` | U1 is an AXP318 | one part, two names; rail names match (DCDC1 to 9, ALDO, BLDO, CLDO, DLDO, ELDO, two switches) |
| Status LED | GPIO PL7 | net `PWM_LED`, annotated "PWM0-7", high = on | polarity agrees; it can be driven as GPIO or PWM |

Present in the tree and optional on the board, per the schematic and the product page:
eMMC (`sdc2`) and UFS (`ufs`) footprints are unpopulated by default; the touchscreen (`twi12`,
`TP_RST`, `TP_INT`) is on the LCD connector and exists only with a panel attached; TWI9 and TWI11
go to the two camera connectors.

## Pin summary

`pio` is the main controller (`pinctrl@2000000`, banks PB to PK), `r_pio` the always-on one
(`pinctrl@7025000`, banks PL and PM).

| Pin | Use | Source |
|---|---|---|
| PB9, PB10 | UART0 TX, RX (console), mux 2. On the 40-pin header: pin 8 (TX), pin 10 (RX), ground on pin 6 | `sys_config.fex` `[uart_para]`, `README.md`; not in the dts |
| PF0 to PF5 | microSD: D1, D0, CLK, CMD, D3, D2 | dtsi:1013, `sys_config.fex` `[card0_boot_para]` |
| PF6 | microSD card detect, active low, pull-up | dts:1625 |
| PG0 | SDIO Wi-Fi clock | dtsi:1070 |
| PG1 to PG5 | SDIO Wi-Fi CMD and D0 to D3 (order not given) | dtsi:1056 |
| PG6 to PG9 | UART1 to Bluetooth (four pins: data and flow control, order not given) | dts:549 |
| PD5 | fan speed, PWM0 channel 5 | dts:669, dts:1527 |
| PD21 | PCIe wake, active high | dts:1797 |
| PK22, PK23 | touchscreen reset, interrupt | dts:1878 |
| PK24, PK25 | TWI12 | dts:897 |
| PE7, PE8 | TWI11 | dts:885 |
| PE14, PE15 | TWI9 | dts:873 |
| PL0, PL1 | S_TWI0 to the PMIC | dts:1224 |
| PL7 | status LED, active high | dts:75 |
| PL8 | USB-C VBUS enable (fixed regulator), active high | dts:16 |
| PL9 | USB-C controller interrupt, active low, pull-up | dts:1217, dts:2584 |
| PL10, PL11 | S_TWI2 (40-pin header; the RTC of the tree is not fitted) | dts:1248 |
| PL12, PL13 | S_TWI1 to the USB-C controller | dts:1236 |
| PM0 | Wi-Fi host wake, active high | dts:2961 |
| PM1 | Wi-Fi enable (`wlan_regon`), active high | dts:2960 |
| PM2 | Bluetooth reset, active low, per the tree; the schematic disagrees | dts:2972 |
| PM3 | Bluetooth wake, active high | dts:2979 |
| PM4 | Bluetooth host wake, active high | dts:2980 |
| NMI | PMIC interrupt (`intc-nmi@7010320`, GIC SPI 188) | dtsi:408 |

PM4 is also `test-gpios` of the vendor `pinctrl_test` node (dtsi:1614); that node is test code.

## Per peripheral

### UART0 (console)

- Controller: `uart@2500000`, GIC SPI 2, FIFO 64, clock `CLK_UART0`, reset `RST_BUS_UART0` (dtsi:1621).
- Pins: the board file sets `pins = "", ""` (dts:537), so the vendor kernel relies on the pin mux the
  boot chain left behind. `sys_config.fex` gives PB9 (TX) and PB10 (RX), function 2.
- PB9 and PB10 are SoC pad names, not header positions. On the 40-pin header the console is
  pin 8 (TX), pin 10 (RX) and pin 6 (ground), 115200 baud (`README.md`).
- A mainline tree must name the pins itself. No supply is listed.
- Schematic: agrees. Nets `CPUX-TX` and `CPUX-RX` go to the 40-pin header, marked "CPU DEBUG" (sheets 9, 18).

### microSD (`sdc0`)

- Controller: `sdmmc@4020000`, GIC SPI 161 (dtsi:4490).
- Clocks: `sys24M`, `CLK_PLL_PERI1_400M`, `CLK_PLL_PERI1_300M`, `CLK_SMHC0`, `CLK_BUS_SMHC0`,
  `CLK_STORE_AHB_GATE`, `CLK_MBUS_STORE_GATE`, `CLK_MSI_LITE1`. Reset `RST_BUS_SMHC0`.
- Pins: PF0 to PF5, 4-bit; clock pin PF2 at drive strength 30, the others at 10, all pull-up.
  Two pin states, 3.3 V and 1.8 V (`power-source`), for UHS signalling.
- Card detect: PF6, active low, pull-up.
- Supplies: card power `dc1sw2` (switch fed by `dcdc1`); I/O at 3.3 V from `dc1sw2`, at 1.8 V from `cldo5`.
- Modes claimed: high speed, UHS SDR50, DDR50, SDR104; `max-frequency` 150 MHz.
- Schematic: agrees. Nets `SDC0-CLK`, `SDC0-CMD`, `SDC0-D0` to `SDC0-D3` and `SDC0-DET`; card supply
  `VCC-CARD` in the rail group fed by switch 2 of DCDC1; `VCC18-PF` on CLDO5 (sheets 2, 6, 12).

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
- Schematic: the module is U5, `CDW-20800D8-00`, on a footprint shared with the Quectel FCS960K.
  SDIO nets `WL-SDIO-CLK`, `WL-SDIO-CMD`, `WL-SDIO-D0` to `D3` agree. Supplies, 32 kHz clock and
  control lines differ from the tree: see the table above. `VCC-PM` is on CLDO1 (sheet 2), which
  agrees with the tree naming `cldo1`.

### AIC8800 Bluetooth (UART1)

- Controller: `uart@2501000`, GIC SPI 3, FIFO 256, clock `CLK_UART1`, reset `RST_BUS_UART1` (dtsi:1633).
- Pins: PG6 to PG9, function `uart1`.
- Control: reset PM2 (active low), wake PM3, host wake PM4 (`btlpm`, `uart_index = 1`).
- Power: same two rails as Wi-Fi (`bldo5`, `cldo1`, 1.8 V).
- Schematic: agrees on the UART with flow control (`BT-UART-TX`, `RX`, `RTS`, `CTS`, crossed at the
  SoC) and on the wake lines. It adds Bluetooth audio on I2S1 (`I2S1_BCLK`, `LRCK`, `DIN0`, `DOUT0`).
  No reset net: see the table above.

### USB

Three controllers are enabled in the tree. The schematic says which connector each one reaches:

- Power connector (16-pin Type-C, "DC 5V" input): USB0 D+ and D-, that is `usbc0`, USB 2.0 only.
  Its CC pins go to two 5.1 kOhm resistors (R47, R48): it is a sink, with no controller.
- Data connector (24-pin Type-C, "TypeC DP Port"): USB2 D+ and D- plus the four COMB0 lanes, SBU and
  CC, that is `usbc2` and DisplayPort. CC goes to the FUSB302 (U4); VBUS is switched by U3, a SY6280,
  enabled by net `TYPEC_EN`.
- USB1 (`usbc1`) is not connected.

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
  `husb311` but its compatible is `fcs,fusb302` (dts:2580); the part fitted is an FUSB302.
  Interrupt PL9 (active low). VBUS: fixed 5 V regulator `usb0-vbus` enabled by PL8 (active high).
- Connector node: dual data role, dual power role, tries sink first; sink 5 V up to 2 A, source 5 V up
  to 1.2 A; DisplayPort alternate mode (SVID `0xff01`).
- DisplayPort over USB-C: `phy_switcher` (dts:400) switches `combo0_dp` and `combo0_usb` with the plug
  orientation. Its AUX GPIOs (PL12, PL13) are commented out and collide with S_TWI1.
- Schematic: agrees on S_TWI1 to the controller (`S_TWI1_SCK`, `S_TWI1_SDA`), on its interrupt
  (`TYPEC_CC_INT`) and on the VBUS enable (`TYPEC_EN`). It also has two GPIO nets for the AUX
  polarity, `SBU1-DC` and `SBU2-DC`, which the tree does not use.

### PMIC (S_TWI0: PL0, PL1, 400 kHz, clock `CLK_R_TWI0`, reset `RST_BUS_R_TWI0`)

- `pmu@36`: `x-powers,axp8191`, the main regulator; the schematic calls the part AXP318 (U1).
  Interrupt: NMI (`AP-NMI`). Power key child `x-powers,axp2101-pek`; the schematic has a `PWRON` pad.
- `pmu@34`: AXP515 charger with battery and USB supplies. Not on the board: see the table above.
- Schematic: agrees on the bus (`PMU-SCK`, `PMU-SDA`) and on these rail uses: DCDC3 for the big
  CPU cluster (`VDD-CPUB`), DCDC5 for the little cluster (`VDD-CPUL`), DCDC4 for the GPU, DCDC2 for
  `VDD-SYS`, NPU and the 0.8 V of HDMI, DCDC1 feeding both switches.

Rails. The tree gives each rail its full range only, never a set voltage. The schematic has the
set voltages on sheets 2 and 6, but tying each value to its rail needs the drawing; until then,
read them from the running vendor system.

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
- Schematic: agrees. `HSCL`, `HSDA`, `HCEC` and `HHPD` are dedicated SoC pins; the connector's 5 V
  comes from `VCC-5V` through a diode, with no enable (sheets 10, 15).

### PCIe

- Controller: `pcie@6000000` (`allwinner,sunxi-pcie-v300-rc`), one lane, `max-link-speed = 3`,
  power domain `SUN60IW2_PCK_PCIE` (dtsi:5046). GIC SPI 152 (sii), 153 (MSI), 136 to 143 (eDMA).
- Clocks: `CLK_PCIE0_AUX`, `CLK_PCIE0_AXI_SLV`, `CLK_ITS_PCIE0_A`. Resets: `RST_BUS_PCIE0`,
  `RST_BUS_PCIE0_PWRUP`, `RST_BUS_ITS_PCIE0`.
- PHY: `combo1_pcie` in the `serdes` block (1.8 V from `cldo5`).
- Board side (dts:1794): wake PD21 (active high), 1.8 V from `bldo1`, 3.3 V from `dcdc1`.
- Not described in the tree: reset (PERST#), clock request, power enable. The schematic has all
  three as GPIO nets: see the table above.

### Fan

- Two-wire fan on the board, speed set by PWM: `pwm-fan` node (dts:1527) on PWM0 channel 5, pin PD5,
  period 25 µs (40 kHz), supply `dc1sw2`.
- Schematic: agrees. Two-pin connector `FAN` switched by transistor Q2 (WNM2021), driven by net
  `FAN_EN_PWM`, annotated "PWM0-5" (sheets 5, 9). The product page lists a "2PIN Fan interface".
- Five levels (`cooling-levels = <0 50 102 170 255>`); it is the cooling device of both CPU thermal zones.

### LED

- One GPIO LED, `status_led`: PL7, active high, heartbeat trigger (dts:73).
- Schematic: one LED (LED1) on net `PWM_LED`, high = on.

### Buttons

- The board has no buttons. The schematic has through-hole pads (H1 to H4) for power-on (`PWRON`),
  boot mode (`BOOT`, the FEL line) and reset (`AP-RESET`); the product page shows no key.
- The tree has no `gpio-keys` node. Its power key child of the PMIC matches the `PWRON` pad.
- The LRADC keys of the tree are not on the board: see the table above.

### Watchdog

- `watchdog@2050000`, `allwinner,wdt-v103`, GIC SPI 106, no clock or reset listed (dtsi:1388).
  The board file does not touch it.
- For the mainline tree this is the node to get right with boot chain 1, which hands the watchdog
  over running (see `docs/mainline-notes.md`).

### Clocks and time

- Main crystal: the tree declares 24 MHz (`dcxo24M`), the schematic fits 26 MHz (Y1). See the table above.
- 32.768 kHz crystal (Y2) on the SoC; the tree takes 32 kHz from the RTC CCU (`rtc_ccu@7090000`).
  16 MHz internal RC.
- RTC: the tree disables the SoC RTC (`rtc@7090000`) and declares an HYM8563 that is not on the board.

### Other nodes enabled in the tree

| Node | What it claims | Schematic |
|---|---|---|
| `sdc2` | 8-bit eMMC on PC0 to PC16, HS400, no supplies | footprint, unpopulated by default (sheet 3) |
| `ufs` | UFS host (dts:4094) | footprint, unpopulated by default (sheet 4) |
| `twi12` + `touchscreen@14` | Goodix GT9271 on PK24, PK25; interrupt PK23, reset PK22 | on the LCD connector, with `LCD_RST`, `LCD_PWR_EN` and backlight `PWM1-7` (sheet 17) |
| `twi9`, `twi11` | buses on PE14, PE15 (100 kHz) and PE7, PE8 (400 kHz), no devices | camera connectors (sheet 13) |
| `gpadc0` | 8 channels enabled | ADC inputs carry strapping nets (sheet 10) |
| `npu`, `gpu`, `de`, `vo0`, `vo1`, `tv0`, `tv1`, `mipi0`, `vind0` | display, GPU, NPU and camera blocks | SoC blocks; DSI and two CSI connectors are on the board |

Disabled in the tree: Ethernet (`gmac0`), eDP and DSI panels, AC101 and ES8388 audio codecs, infrared
receiver, LED strip controller, UART2, 3, 5, 6, 7, 8, TWI0, 1, 2, 3, 5, 7, 8. None of those parts
is in the schematic; the buses are the 40-pin header signals.

### 40-pin header

From the "Pin Definition" drawing on the product page (orangepi.org, board marked v1.2, read
2026-11-12). It agrees with `README.md` on the console pins.

| Pin | Pad | Functions | Pin | Pad | Functions |
|---|---|---|---|---|---|
| 1 | 3.3 V | | 2 | 5 V | |
| 3 | PB3 | TWI0_SDA | 4 | 5 V | |
| 5 | PB2 | TWI0_SCK | 6 | GND | |
| 7 | PB4 | PWM0_0 | 8 | PB9 | UART0_TX (console) |
| 9 | GND | | 10 | PB10 | UART0_RX (console) |
| 11 | PB0 | UART2_TX | 12 | PB5 | |
| 13 | PB1 | UART2_RX | 14 | GND | |
| 15 | PE11 | | 16 | PL2 | UART7_TX |
| 17 | 3.3 V | | 18 | PL3 | UART7_RX |
| 19 | PE2 | TWI2_SDA, SPI3_MOSI | 20 | GND | |
| 21 | PE3 | TWI3_SCK, SPI3_MISO | 22 | PD0 | |
| 23 | PE1 | UART6_RX, TWI2_SCK, SPI3_CLK | 24 | PE0 | SPI3_CS0, UART6_TX |
| 25 | GND | | 26 | PE4 | SPI3_CS1, TWI3_SDA |
| 27 | PL5 | | 28 | PL4 | |
| 29 | PE12 | | 30 | GND | |
| 31 | PE13 | | 32 | PD1 | PWM0_1 |
| 33 | PD3 | PWM0_3 | 34 | GND | |
| 35 | PB6 | PWM0_8 | 36 | PD2 | PWM0_2 |
| 37 | PD4 | PWM0_4 | 38 | PB8 | TWI1_SDA |
| 39 | GND | | 40 | PB7 | TWI1_SCL, PWM0_9 |

The schematic text (sheet 18, document V1.5) names I2S0 and S-TWI2 on this header and does not
name PE12 or PE13; whether that is a difference between board revisions is not settled.

## To confirm on the board

From the vendor image, before anything else is flashed:

| Question | How |
|---|---|
| Oscillator frequency, 24 or 26 MHz | `dmesg` and `/sys/kernel/debug/clk/clk_summary` (`dcxo`, `hosc`) |
| Rail voltages and which rails are on | `/sys/kernel/debug/regulator/regulator_summary` |
| Pin mux in use (UART0 on PB9 and PB10 expected) | `/sys/kernel/debug/pinctrl/*/pinmux-pins` |
| GPIO lines held and their levels, PM0 to PM4 first | `/sys/kernel/debug/gpio` |
| Nothing answers at `0x34` (AXP515) and `0x51` (RTC) | `dmesg`, `i2cdetect` on S_TWI0 and S_TWI2 |
| Which tree the image boots | `cat /sys/firmware/devicetree/base/compatible`, keep a copy of `/sys/firmware/fdt` |

From the schematic drawings: the SoC pin of each Wi-Fi and Bluetooth control net, of the four PCIe
control nets, of `SBU1-DC` and `SBU2-DC`, and the set voltage of each rail.
