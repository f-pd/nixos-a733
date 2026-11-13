# FEL bring-up helpers

What the first session with the board used (`docs/bring-up-results.md`), for a computer
without Nix. They are session tools, kept so the work can be picked up again; the supported
build is `nix build .#firmware`.

| File | Use |
|---|---|
| `prepare.sh <workdir> <bl31.elf>` | builds `sunxi-fel` (A733 branch) and `usbreset`, packs the DRAM payload from the vendor boot0, fetches and patches U-Boot |
| `build-u-boot.sh` | cross-builds U-Boot in a Debian container; the command is printed by `prepare.sh` |
| `chain.sh on [addr file]...` | run in the work directory with the board in FEL: SPL, USB port reset, BL31 and U-Boot to DRAM, optional extra files, start |
| `ucmd.py <uart log> <seconds> <command>...` | sends lines to the U-Boot prompt; `UART_DEV` names the serial port. A second process has to be logging the port to `<uart log>` |
| `usbreset.c` | resets the USB port of the board in FEL (`1f3a:efe8`), needed after the SPL returns |

The work directory holds the PHY training firmware: do not publish it.
