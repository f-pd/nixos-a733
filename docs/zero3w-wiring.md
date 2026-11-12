# Orange Pi Zero 3W: wiring inventory

How the board is wired, per peripheral: pins, supplies, clocks and control lines. It is the input
for a mainline-style device tree, whichever patch stack is chosen.

The wiring is taken from the manufacturer's schematic for board revision V1.2 (the maintainer's
unit). The vendor device tree is used for what a schematic does not hold: controller addresses,
interrupts, clock and reset identifiers. Where the two disagree, the schematic is followed and the
difference is listed. Nothing here was measured or run on the board.

## Sources

| Short name | File | Where |
|---|---|---|
| sheet N | `OPI ZERO 3W V1_2 Schematic Diagram.pdf`, 18 sheets | `docs/board/` |
| V1.5 sheet N | `OPi_ZERO_3W_V1_5-DSN.pdf`, 18 sheets, same sheet list, with more annotations | `docs/board/` |
| pin drawing | "Pin Definition" on the product page, orangepi.org, board marked v1.2, read 2026-11-12 | not copied |
| dts:N | `sun60i-a733-orangepi-zero3w.dts`, line N | `orangepi-xunlong/linux-orangepi` @ `2ac08e8c7cdc` (pinned in `vendor/sources.json`), sha256 `31145367f604fd756f2c6a67447e5134e4be0ad5fae87672cfaa9b7c6d055a39` |
| dtsi:N | `sun60iw2p1.dtsi`, line N | same directory, sha256 `1c7313f655bdc4d018201664adcb1fa1d100280388b8975e193ebbfc6ad4ddfa` |
| `sys_config.fex` | boot configuration | `vendor/blobs/orangepi-build/.../sys_config/` |

Names such as `CLK_UART0` are the vendor clock and reset identifiers; they identify the clock, the
mainline bindings use other names and numbers.

## What was read, and how

| Sheet | Subject | V1.2 | V1.5 |
|---|---|---|---|
| 2 | power sequence | not used | drawing; a reference sequence, superseded here by sheet 6 |
| 5 | boot and power pads, LED, fan | drawing | text |
| 6 | PMIC and rails | drawing | drawing (left half) |
| 9 | SoC GPIO | drawing | drawing |
| 11 | USB Type-C ports | drawing | text |
| 12 | microSD | drawing | text |
| 14 | Wi-Fi and Bluetooth | drawing | drawing |
| 16 | PCIe | drawing | text |
| 18 | 40-pin header | drawing | text |
| 1, 3, 4, 7, 8, 10, 13, 15, 17 | block diagram, eMMC, UFS, DRAM, SoC system, analog and high speed, cameras, HDMI, LCD | text only | text only |

"Text only" means part names, net names, sheet cross-references and notes were read, not the
connections. Statements below that rest on a text-only sheet say so.

Differences found between V1.2 and V1.5 on the sheets read as drawings:

- Sheet 14: V1.5 adds R1129 (0 Ohm, marked not fitted) from `AP-CK32K-OUT` to the module's LPO pin,
  and marks R61 as not fitted. See "Wi-Fi and Bluetooth".
- Sheet 6: V1.5 draws the loads of DCDC8 and the set voltage of every output; V1.2 draws DCDC8 with
  a "1.8V" label and no loads. The other outputs have the same loads in both.
- Sheets 9: same nets on the same pads.

## Where the vendor device tree does not match the board

The vendor tree declares `compatible = "xunlong,orangepi-4-pro"` (dts:9): it was copied from the
Orange Pi 4 Pro tree.

| Subject | Vendor tree | Schematic | For a mainline tree |
|---|---|---|---|
| Main crystal | fixed clock `dcxo24M`, 24 MHz (dtsi:342) | Y1 is 26 MHz, "USE 26M", "default 26M" (sheet 8, text) | 26 MHz, or detected; confirm on the board |
| Charger PMIC | AXP515 at `0x34` with battery and USB supplies (dts:1957) | not on the board; the only PMIC is U1 (sheet 6) | leave it out |
| External RTC | HYM8563 at `0x51` on S_TWI2, SoC RTC disabled (dts:2670, dts:2565) | not on the board; 32.768 kHz crystal Y2 on the SoC (sheet 8, text) | use the SoC RTC |
| S_TWI2 pins | PL10, PL11 (dts:1248) | PL10, PL11 are `SBU1-DC`, `SBU2-DC`; S-TWI2 is on PL4, PL5, header pins 28 and 27 (sheets 9, 18) | S_TWI2 on PL4, PL5 |
| USB1 | `usbc1`, `ehci1`, `ohci1` enabled | USB1 D+ and D- reach no connector (sheets 10, 11, text) | leave it disabled |
| LRADC keys | five keys enabled (dts:3319) | no keys; the ADC inputs carry strapping nets (sheet 10, text) | leave it out |
| Rail assignment | Wi-Fi on `bldo5` and `cldo1`, PCIe on `bldo1` and `dcdc1`, USB on `aldo1`, SD and fan on `dc1sw2`, and so on | those LDO outputs have no load; see "PMIC and rails" (sheet 6) | take supplies from sheet 6, not from the tree |
| Fan supply | `dc1sw2`, 3.3 V (dts:1527) | `VCC-5V` through 1 Ohm (sheet 5) | 5 V |
| PCIe | wake only, PD21; supplies `bldo1`, `dcdc1` | four control lines on PD20 to PD23; connector powered from `VCC-5V` (sheets 9, 16) | see "PCIe" |
| Bluetooth reset | `bt_rst_n` on PM2 (dts:2972) | PM2 is net `AP_WAKE_WL`, which reaches the module's `BT_RST_N` through R61 and its pin 24 through R1130 (sheet 14) | see "Wi-Fi and Bluetooth" |
| Type-C controller | label `husb311`, compatible `fcs,fusb302` | U4 is an FUSB302MPX (sheet 11) | `fcs,fusb302` |
| PMIC name | `x-powers,axp8191` at `0x36` | U1 is marked AXP318 (sheet 6) | one part, two names; output names match |

Optional hardware: eMMC (`sdc2`) and UFS footprints are unpopulated by default (product page;
sheets 3, 4). The touchscreen of the tree (`twi12`, PK22, PK23) is on the LCD connector and exists
only with a panel attached (sheet 9: `TP_RST`, `TP_INT`).

## PMIC and rails

- PMIC U1, AXP318 (`x-powers,axp8191` in the tree), on S_TWI0: PL0 `PMU-SCK`, PL1 `PMU-SDA`
  (sheet 9), address `0x36`, 400 kHz, interrupt on the SoC NMI pin (`AP-NMI`; `intc-nmi@7010320`,
  GIC SPI 188). S_TWI0: `twi@7083000`, GIC SPI 203, `CLK_R_TWI0`, `RST_BUS_R_TWI0` (dtsi:1956).
- `PMU-PWRON` goes to the `PWRON` pad through 1 kOhm (sheet 5).

Loads per output (sheet 6; set voltages and DCDC8 loads from V1.5 sheet 6):

| Output | Voltage | Loads |
|---|---|---|
| DCDC1 | 3.3 V | `VCC-3V3-WIFI`, `VCC_3V3_EXT` (header pins 1, 17), `VCC_3V3_CSI`, `VCC-CARD`; optional `VCC_3V3_EMMC`, `VCC-LCD` |
| SWOUT2 (switch on DCDC1) | 3.3 V | `VCC-IO` (bank PB), `VCC-PD`, `VCC-PE`, `VCC-PL`, `VCC33-USB`, `VCC33-18-USB`, `VCC33-USB-2`, `VCC33-18-USB-2` |
| SWOUT1 (switch on DCDC1) | 3.3 V | none |
| DCDC2 | 0.8 V | `VDD-SYS`, `VDD-VE`, `VDD-COMB0`, `VDD08-HDMI`, `VDD-DRAM`, `VDD08-UFS` |
| DCDC3 | 0.8 V to 1 V | `VDD-CPUB` (two Cortex-A76) |
| DCDC4 | 0.8 V to 0.96 V | `VDD-GPU` |
| DCDC5 | 0.8 V to 1 V | `VDD-CPUL` (six Cortex-A55) |
| DCDC6 | 0.5 V (LPDDR5) | `VCC-DRAML`, `VCC-VDDQ` |
| DCDC7 | 1.05 V (LPDDR5) | `VCC-DRAM` |
| DCDC8 | 1.8 V | `VCC-PC`, `VCC-PG`, `VCC-PH`, `VCC-PJ`, `VCC-PK`, `VCC-PM`, `VCC-MCSI`, `VCC-EFUSE`, `VCCIO_1V8_WIFI`, `VDD18-LPDDR`; optional eMMC and UFS I/O |
| DCDC9 | 1.22 V | input of the ELDO group; UFS I/O |
| CLDO2 | 1.8 V | `VCC18-HDMI`, `VCC-LVDS0` |
| CLDO3 | 1.8 V | `AVCC`, `VCC-PLL`, `VCC-CPU-PLL`, `VCC-DCXO`, `VDD18-DRAM` |
| CLDO5 | 1.8 V | `VCC18-PF` (microSD 1.8 V signalling), `AVDD-H-COMB0` |
| ELDO1 | 1.078 V | `VCC09-VDD2L` (LPDDR5) |
| ELDO6 | 0.8 V | `VDD-CPUS`, `VDD-USB` |
| DLDO6 | 2.5 V | UFS, optional |
| RTC LDO | 1.8 V | `VCC-RTC` |

The other outputs (ALDO1 to 6, BLDO1 to 5, CLDO1, CLDO4, DLDO1 to 5, ELDO2 to 5) have no load drawn.

GPIO bank voltages (sheet 9): PB, PD, PE, PL at 3.3 V; PC, PG, PH, PJ, PK, PM at 1.8 V; PF 3.3 V or
1.8 V (`VCC-IO` and `VCC18-PF`).

Vendor tree cross-check: it agrees on `dcdc3` for `cpu6`, `dcdc5` for `cpu0`, `dcdc4` for the GPU,
`dcdc2` for HDMI and NPU, `cldo2` for HDMI, `cldo5` for the microSD 1.8 V level. Its other supply
references point at outputs with no load.

## Pin summary

| Pad | Net | Use | Source |
|---|---|---|---|
| PB9, PB10 | `CPUX-TX`, `CPUX-RX` | UART0 console; header pins 8, 10 through 1 kOhm, with ESD diodes | sheets 9, 18 |
| PF0 to PF5 | `SDC0-D1`, `CMD`, `CLK`, `D0`, `D3`, `D2` | microSD; `sys_config.fex` swaps CMD and D0 (PF1 = D0, PF3 = CMD) | sheet 9 |
| PF6 | `SDC0-DET` | microSD card detect, low with a card | sheets 9, 12 |
| PG0, PG1, PG2 to PG5 | `WL-SDIO-CLK`, `CMD`, `D0` to `D3` | Wi-Fi SDIO | sheet 9 |
| PG6, PG7, PG8, PG9 | UART1 TX, RX, RTS, CTS (nets `BT-UART-RX`, `TX`, `CTS`, `RTS`) | Bluetooth UART | sheet 9 |
| PG11 to PG14 | `I2S1_BCLK`, `LRCK`, `DOUT0`, `DIN0` | Bluetooth audio | sheet 9 |
| PD5 | `FAN_EN_PWM` | fan, PWM0 channel 5 | sheets 5, 9 |
| PD20, PD21, PD22, PD23 | `PCIE-CLKREQn`, `PCIE-WAKEn`, `PCIE-PERSTn`, `PCIE_PWREN_H` | PCIe | sheets 9, 16 |
| PE7, PE8 | `TWI11_SCK`, `SDA` | camera connectors | sheet 9 |
| PE14, PE15 | `TWI9_SCK`, `SDA` | camera connectors | sheet 9 |
| PH15, PH16 | `BOARD-ID-SEL-GPIO`, `DDR-PARA-SEL-GPIO` | strapping, read at boot | sheet 9 |
| PJ22, PJ23, PJ25, PJ27 | `LCD_PWR_EN`, `LCD_RST`, `PWM1-7`, `LCD_TE` | LCD connector | sheet 9 |
| PK22, PK23, PK24, PK25 | `TP_RST`, `TP_INT`, `TWI12-SCK`, `SDA` | touch panel on the LCD connector | sheet 9 |
| PL0, PL1 | `PMU-SCK`, `PMU-SDA` | S_TWI0 to the PMIC | sheet 9 |
| PL7 | `PWM_LED1` | LED, high = on | sheets 5, 9 |
| PL8 | `TYPEC_EN` | VBUS switch of the data port, high = on | sheets 9, 11 |
| PL9 | `TYPEC_CC_INT` | FUSB302 interrupt, low active | sheets 9, 11 |
| PL10, PL11 | `SBU1-DC`, `SBU2-DC` | SBU bias on the data port | sheets 9, 11 |
| PL12, PL13 | `S_TWI1_SCK`, `SDA` | S_TWI1 to the FUSB302 | sheets 9, 11 |
| PM0 | `WL-WAKE-AP` | Wi-Fi wakes host | sheets 9, 14 |
| PM1 | `WL-REG-ON` | Wi-Fi enable, high = on | sheets 9, 14 |
| PM2 | `AP_WAKE_WL` | see "Wi-Fi and Bluetooth" | sheets 9, 14 |
| PM3 | `AP-WAKE-BT` | host wakes Bluetooth | sheets 9, 14 |
| PM4 | `BT-WAKE-AP` | Bluetooth wakes host | sheets 9, 14 |

The remaining header pads are in "40-pin header".

## Per peripheral

### UART0 (console)

- PB9 TX, PB10 RX, each through 1 kOhm (R82, R83) to header pins 8 and 10; ground on pin 6
  (sheet 18). 115200 baud (`README.md`).
- Controller: `uart@2500000`, GIC SPI 2, FIFO 64, `CLK_UART0`, `RST_BUS_UART0` (dtsi:1621).
- The vendor tree leaves the pin group empty (dts:537) and relies on the boot chain; `sys_config.fex`
  sets PB9 and PB10 to function 2. A mainline tree must name the pins.

### microSD

- PF0 to PF5, 4-bit, 33 Ohm in series on the clock (sheet 9).
  The pad functions are fixed in the SoC, so the order of CMD and D0 does not change the pin group.
- Card detect: the socket's switch drives transistor Q1, whose output reaches PF6 through 1 kOhm;
  PF6 is low with a card inserted (sheet 12).
- Card supply `VCC-CARD` from DCDC1, always on, through 1 Ohm; no switch (sheets 6, 12).
- I/O level: bank PF from `VCC-IO` (3.3 V) or `VCC18-PF` (CLDO5, 1.8 V) (sheets 6, 9).
- Controller: `sdmmc@4020000`, GIC SPI 161; clocks `sys24M`, `CLK_PLL_PERI1_400M`,
  `CLK_PLL_PERI1_300M`, `CLK_SMHC0`, `CLK_BUS_SMHC0`, `CLK_STORE_AHB_GATE`, `CLK_MBUS_STORE_GATE`,
  `CLK_MSI_LITE1`; reset `RST_BUS_SMHC0` (dtsi:4490).
- Vendor tree settings: UHS SDR50, DDR50, SDR104, `max-frequency` 150 MHz, clock pin drive
  strength 30, others 10 (dts:1623, dtsi:1013).

### Wi-Fi and Bluetooth

Module U5, `CDW-20800D8-00` (reported to be an AIC8800D80), on a footprint shared with the Quectel
FCS960K (sheet 14).

- Supplies: `VCC-3V3-WIFI` (DCDC1) to VBAT through a ferrite bead; `VCCIO_1V8_WIFI` (DCDC8) to VDDIO.
  Both rails are always on.
- SDIO on PG0 to PG5, 1.8 V; footprints for 47 kOhm pull-ups marked "design for test".
- `WL-REG-ON` (PM1) to the module's `WL_REG_ON`, 100 kOhm pull-down, high = on.
- `WL-WAKE-AP` (PM0) from the module's `WL_HOST_WAKE`.
- Bluetooth UART on PG6 to PG9 with RTS and CTS, crossed at the SoC; 10 kOhm pull-ups on RX and TX.
- `AP-WAKE-BT` (PM3) to `BT_WAKE`; `BT-WAKE-AP` (PM4) from `BT_HOST_WAKE`.
- Bluetooth audio: I2S1 on PG11 to PG14 to the module's PCM pins.
- `AP_WAKE_WL` (PM2) is drawn to two module pins through 0 Ohm resistors: `BT_RST_N` (pin 34) through
  R61, and pin 24 (`LPO` on this module) through R1130. V1.5 marks R61 as not fitted and labels the
  pair as a compatibility option for the FCS960K. Which of the two is fitted on a V1.2 board is not
  stated: to check on the board. The vendor tree uses PM2 as Bluetooth reset, active low.
- 32 kHz clock: `AP-CK32K-OUT` (the SoC's `X32KFOUT`) arrives on sheet 14 and is connected to
  nothing on V1.2. The module gets no external 32 kHz clock.
- Controllers: SDIO `sdmmc@4021000`, GIC SPI 162, `CLK_SMHC1`, `CLK_BUS_SMHC1`, `RST_BUS_SMHC1`
  (dtsi:4545); UART1 `uart@2501000`, GIC SPI 3, FIFO 256, `CLK_UART1`, `RST_BUS_UART1` (dtsi:1633).
- Vendor tree settings: SDIO up to SDR104, `max-frequency` 208 MHz, SDIO interrupt, power kept in
  suspend (dts:1654). MAC addresses come from the vendor `addr_mgt` node; mainline has no equivalent.

### USB

- Power port (16-pin Type-C): `VCC-5V` in, USB0 D+ and D-, CC1 and CC2 each to ground through
  5.1 kOhm. A sink with no controller; USB 2.0 only (sheet 11).
- Data port (24-pin Type-C, "TypeC DP Port"): USB2 D+ and D-, the four COMB0 lanes (USB 3 and
  DisplayPort), SBU, CC (sheet 11).
  - VBUS from `VCC-5V` through switch U3 (SY6280), enabled by `TYPEC_EN` (PL8), 100 kOhm pull-down.
  - CC controller U4, FUSB302MPX, on S_TWI1 (PL12, PL13; 2.2 kOhm pull-ups to `VCC-PL`), interrupt
    PL9 with 4.7 kOhm pull-up, supplied from `VCC-PL`, VCONN from `VCC-5V`. Address `0x22` in the tree.
  - DisplayPort AUX is AC-coupled to SBU1 and SBU2; `SBU1-DC` (PL10) and `SBU2-DC` (PL11) bias the
    SBU lines through 100 kOhm.
- USB1 reaches no connector.
- Controllers (dtsi): `usbc0` = `udc@4100000`, `ehci0@4101000`, `ohci0@4101400`, GIC SPI 156 to 158,
  `CLK_USB_REF`, `CLK_USB0_DEVICE`, `CLK_USB0_EHCI`, `CLK_USB0_OHCI`, `CLK_USB_SYS_AHB_GATE`,
  `CLK_MSI_LITE2`, `RST_USB_0_*`. `usbc2` = DWC3 `xhci2@6a00000`, GIC SPI 155, `CLK_USB2_MF`,
  `CLK_USB2_U2_REF`, `CLK_USB2_SUSPEND`, `RST_USB_2`, power domain `SUN60IW2_PCK_USB2`; PHYs
  `phy@6b00000` and `combo0_usb` in `serdes@6c00000` (`CLK_SERDES_PHY_CFG`, `RST_BUS_SERDES`).
- Vendor tree: connector node with dual data and power role, sink 5 V up to 2 A, source 5 V up to
  1.2 A, DisplayPort alternate mode (dts:2578).

### HDMI

- Sheet 15 was read as text only: mini HDMI connector, `HSCL`, `HSDA`, `HCEC`, `HHPD` on dedicated
  SoC pins, connector 5 V from `VCC-5V` through a diode.
- Supplies: `VDD08-HDMI` (DCDC2), `VCC18-HDMI` (CLDO2) (sheet 6).
- Controller: `hdmi0@5520000`, GIC SPI 61, power domain `SUN60IW2_PCK_VO1`; clocks `CLK_HDMI_REF`,
  `CLK_HDMI`, `CLK_HDMI_SFR`, `CLK_HDCP_ESM`, `CLK_DCXO`; resets `RST_BUS_HDMI_SUB`,
  `RST_BUS_HDMI_MAIN`, `RST_BUS_HDMI_HDCP` (dtsi:4287).

### PCIe

- 16-contact FPC connector plus two shell contacts (sheet 16): `VCC-5V` on contacts 1 and 2, the
  reference clock pair, one RX and one TX pair, then `PCIE_PWREN_H` (PD23), `PCIE-WAKEn` (PD21),
  `PCIE-CLKREQn` (PD20), `PCIE-PERSTn` (PD22).
- The board has no 3.3 V switch for PCIe: `PCIE_PWREN_H` is a signal for the board on the other end
  of the cable. The reference clock is biased from DCDC2.
- Controller: `pcie@6000000`, one lane, `max-link-speed = 3`, power domain `SUN60IW2_PCK_PCIE`,
  GIC SPI 152, 153, 136 to 143; `CLK_PCIE0_AUX`, `CLK_PCIE0_AXI_SLV`, `CLK_ITS_PCIE0_A`;
  `RST_BUS_PCIE0`, `RST_BUS_PCIE0_PWRUP`, `RST_BUS_ITS_PCIE0`; PHY `combo1_pcie` (dtsi:5046).

### Fan

- Two-contact connector `FAN`: FAN+ from `VCC-5V` through 1 Ohm; FAN- switched to ground by
  transistor Q2 (WNM2021), gate driven by `FAN_EN_PWM` (PD5, PWM0 channel 5) (sheet 5).
- Vendor tree: `pwm-fan`, period 25 µs (40 kHz), five levels, cooling device of both CPU thermal
  zones (dts:1527).

### LED

- One LED, LED1 (red). It is fed from DCDC1 through 10 kOhm and from `PWM_LED1` (PL7) through
  1 kOhm: dim whenever the board is powered, bright with PL7 high (sheet 5).
- Vendor tree: `status_led`, GPIO, active high, heartbeat (dts:73).

### Pads

- `BOOT`: the SoC's FEL line through 1 kOhm. `PWRON`: the PMIC's power key input through 1 kOhm.
  One ground pad (sheet 5). No buttons and no reset pad. H1 to H4 are the mounting holes, grounded.

### Watchdog

- Not a board item. `watchdog@2050000`, `allwinner,wdt-v103`, GIC SPI 106, no clock or reset listed
  (dtsi:1388); the vendor board file does not touch it. It matters with boot chain 1, which hands
  the watchdog over running (`docs/mainline-notes.md`).

### Clocks

- Y1, 26 MHz, on the SoC's DCXO pins; Y2, 32.768 kHz, on the SoC's RTC pins (sheet 8, text only).
- The vendor tree declares 24 MHz for the same oscillator. See the table of differences.

### 40-pin header

Sheet 18, which agrees with the pin drawing on every pin.

| Pin | Pad | Schematic net | Pin drawing | Pin | Pad | Schematic net | Pin drawing |
|---|---|---|---|---|---|---|---|
| 1 | | 3.3 V (`VCC_3V3_EXT`, 0.5 A) | | 2 | | 5 V | |
| 3 | PB3 | `EXT_TWI0_SDA` | TWI0_SDA | 4 | | 5 V | |
| 5 | PB2 | `EXT_TWI0_SCK` | TWI0_SCK | 6 | | GND | |
| 7 | PB4 | `I2S0-MCLK` | PWM0_0 | 8 | PB9 | `CPUX-TX` | UART0_TX |
| 9 | | GND | | 10 | PB10 | `CPUX-RX` | UART0_RX |
| 11 | PB0 | `PB0` | UART2_TX | 12 | PB5 | `I2S0-BCLK` | |
| 13 | PB1 | `PB1` | UART2_RX | 14 | | GND | |
| 15 | PE11 | `PE11` | | 16 | PL2 | `PL2` (S-PWM0 channel 0) | UART7_TX |
| 17 | | 3.3 V | | 18 | PL3 | `PL3` (S-PWM0 channel 1, infrared) | UART7_RX |
| 19 | PE2 | `SPI3_MOSI` | TWI2_SDA, SPI3_MOSI | 20 | | GND | |
| 21 | PE3 | `SPI3_MISO` | TWI3_SCK, SPI3_MISO | 22 | PD0 | `PD0` | |
| 23 | PE1 | `SPI3_CLK` | UART6_RX, TWI2_SCK, SPI3_CLK | 24 | PE0 | `SPI3_CS0` | SPI3_CS0, UART6_TX |
| 25 | | GND | | 26 | PE4 | `SPI3_CS1` | SPI3_CS1, TWI3_SDA |
| 27 | PL5 | `PL5` (S-TWI2 SDA) | | 28 | PL4 | `PL4` (S-TWI2 SCK) | |
| 29 | PE12 | `UART1-TX` | | 30 | | GND | |
| 31 | PE13 | `UART1-RX` | | 32 | PD1 | `PD1` | PWM0_1 |
| 33 | PD3 | `PD3` | PWM0_3 | 34 | | GND | |
| 35 | PB6 | `I2S0-LRCLK` | PWM0_8 | 36 | PD2 | `PD2` | PWM0_2 |
| 37 | PD4 | `PD4` | PWM0_4 | 38 | PB8 | `I2S0-DIN0` | TWI1_SDA |
| 39 | | GND | | 40 | PB7 | `I2S0-DOUT0` | TWI1_SCL, PWM0_9 |

TWI0 has 4.7 kOhm pull-ups to `VCC-IO` on the board (sheet 9). Bank PL is 3.3 V, so are PB, PD, PE.

## To confirm on the board

From the vendor image, before anything else is flashed:

| Question | How |
|---|---|
| Oscillator frequency, 24 or 26 MHz | `dmesg`, `/sys/kernel/debug/clk/clk_summary` |
| Set voltage of each PMIC output, against the table above | `/sys/kernel/debug/regulator/regulator_summary` |
| Whether PM2 resets Bluetooth (R61 fitted) | toggle PM2 with the module running; or look for R61 and R1130 near U5 |
| Nothing answers at `0x34` and `0x51` | `i2cdetect` on S_TWI0 and S_TWI2 |
| Pin mux in use | `/sys/kernel/debug/pinctrl/*/pinmux-pins` |
| Which tree the image boots | `/sys/firmware/devicetree/base/compatible`; keep a copy of `/sys/firmware/fdt` |

Still to read as drawings: sheets 8, 10, 13, 15, 17 (SoC system pins, analog and high speed, cameras,
HDMI, LCD).
