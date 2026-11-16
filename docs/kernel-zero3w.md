# Mainline kernel for the Orange Pi Zero 3W

What the `latest` kernel track is built from, what its device tree for the board describes,
and what is left. Nothing here has run on the board: the patches apply, the tree compiles
with `dtc`, and CI builds the kernel and the image. `docs/bring-up.md`, step 5, is the plan
for the first boot.

## Base: an assumption to be confirmed

`SPEC.md` D1 recommends patch stack A, `DockSeed/a7s-linux-mainline`, as the single base and
is still open. This work uses it, so that there is something to build and review. If the
maintainer decides otherwise, `patches/` is regenerated from another stack and the board's
device tree is rewritten for its bindings; nothing else depends on the choice.

| Item | Value |
|---|---|
| Kernel | Linux 7.3.4 (`kernel/version.json`), the release the stack is written for |
| Stack | `DockSeed/a7s-linux-mainline` @ `da00673e098b`, 379 patches, GPL-2.0-only, tested by its author on the Radxa Cubie A7S only |
| Vendored as | `patches/base/` (245) and `patches/optional/` (134), unchanged, with their authors' trailers; `patches/index.json` names the origin of each |
| Ours | three patches at the end of the base layer: the board's compatible, `sun60i-a733-orangepi-zero3w.dts`, and the CPU and DSU operating points for it |

`SPEC.md` D7 keeps third-party *boot chain* patches out of the tree. For the kernel, section 6
of the same document says patch stacks are vendored, and that is what this is.

### The two layers

The build applies every base patch, then every optional one, and skips an optional patch
that does not apply (`kernel/source.nix`). The stack is one series in one order, so the split
has to respect it: `patches/import-stack.py` sends the display, GPU, video, camera, NPU and
audio series to the optional layer, plus five series that are not multimedia but are written
on top of those and need the context they leave (the crypto engine, the Cubie's EEPROM, the
ADC, the header pin groups, a second set of bank supplies). With that split all 379 apply to
7.3.4 in layer order; `import-stack.py --check <kernel tree>` repeats the test.

Our device tree is in the base layer, so it only refers to nodes the base layer provides.
That is why it has no HDMI, GPU or ADC yet.

### Refreshing the stack

```
git clone https://github.com/DockSeed/a7s-linux-mainline
python3 patches/import-stack.py a7s-linux-mainline --check <unpacked linux-7.3.4, in git>
```

The script rewrites the imported files and their index entries and keeps ours.

## The device tree

Written from `docs/zero3w-wiring.md` (schematic V1.2) with the bindings of the stack, on the
model of its Cubie A7S tree.

| Described | How |
|---|---|
| Console | UART0 on PB9, PB10 |
| Oscillator | 26 MHz |
| BL31 | `reserved-memory`, `0x40000000`, 256 KiB, `no-map` |
| microSD | `mmc0`, 4 bit, card detect on PF6 (low with a card), card supply from DCDC1; 3.3 V signalling only |
| PMIC | AXP318W at `0x36` on `r_i2c0`, interrupt on NMI. Three outputs are named, always on, at the schematic's voltage: DCDC1 (3.3 V), DCDC8 (1.8 V), SWOUT2 (`VCC-IO`). Every other output is left as the boot chain set it |
| Pin bank supplies | PB, PD, PE, PF from SWOUT2; PC, PG, PH, PJ, PK, PM from DCDC8; PL not named (it carries the PMIC's own bus) |
| Type-C data port | FUSB302 at `0x22` on `r_i2c1` (PL12, PL13), interrupt PL9, VBUS switch on PL8; USB host on the DWC3 (`usb3`), its USB 2 PHY and the combo PHY with orientation switching |
| Type-C power port | USB0 as a peripheral |
| PCIe | one lane, reset on PD22, `PCIE_PWREN_H` (PD23) as the adapter's supply enable |
| LED | PL7, heartbeat |
| CPU and DSU frequency scaling | a third patch: DCDC5 (`vdd-cpul`, the six Cortex-A55 and the DSU) and DCDC3 (`vdd-cpub`, the two Cortex-A76), 800 to 1050 mV, with the SoC's operating point tables. Not run on the board yet: the first boot with it changes core voltages |

Left out, and why:

| Not described | Reason |
|---|---|
| Wi-Fi and Bluetooth (AIC8800D80 on SDIO and UART1) | no mainline driver; the stack has no node for the second MMC controller or UART1 either |
| HDMI | the stack drives DisplayPort, not HDMI |
| DisplayPort on the data port, GPU, audio, video engine | optional layer; they need a second, optional device tree patch on top of ours |
| UHS modes of the card | need bank PF at 1.8 V from CLDO5; the stack has the pin states for it, the board side is not written |
| Fan (PWM0 channel 5 on PD5) | the stack has the PWM driver but no pin group for that pin |
| 32 kHz crystal | marked optional in the schematic; whether Y2 is fitted has to be seen on the board |
| Header functions, cameras, LCD, touch | nothing to attach yet |
| Inputs of the PMIC's regulator groups | the schematic sheet was not read for them |

## Kernel configuration

`kernel/config.nix`: the arm64 defconfig and the NixOS common configuration, plus what the
board needs before modules can load (the four clock controllers, the two pin controllers, the
PMIC and its regulators, the RTC, the power domains, the SID, PCIe) built in, and USB, the
Type-C controller, PWM and the watchdog as modules. Suspend is not turned off here although
the stack's own configuration does that because suspend resets the board: do not suspend.

## What CI shows

The `mainline` job of `build.yml` patches the source, lists optional patches that did not
apply, builds the kernel, checks that `dtbs/allwinner/sun60i-a733-orangepi-zero3w.dtb` is
in it, and builds the generic image with the firmware at 128 KiB. The image holds the PHY
training firmware, so it is neither cached nor uploaded.

## Left to do

1. Boot it (`docs/bring-up.md`, step 5) and correct the tree from what the board says.
2. D1: confirm the stack.
3. A second device tree patch in the optional layer: DisplayPort on the data port, GPU.
4. CPU frequency scaling, once the PMIC's voltages are read back on the board.
5. Wi-Fi: an out-of-tree AIC8800 driver as a NixOS module, and the SDIO and UART1 nodes.
6. HDMI: no driver in the stack.
7. The `lts` track (D1): nothing done.
