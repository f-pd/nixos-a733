#!/bin/sh
# FEL bring-up cycle: SPL (DRAM), host USB reset, BL31 + U-Boot, start BL31.
# usage: chain.sh <on|off> [extra "addr file" pairs written to DRAM before the start]
set -e
W=$(dirname "$0"); F=$W/sunxi-tools/sunxi-fel; V=$1; shift
timeout 30 $F spl $W/out-$V/spl/sunxi-spl.bin 2>/dev/null || true
sleep 7; $W/usbreset >/dev/null; sleep 2
timeout 8 $F version
# never write 0x47000..0x48c00 here: the boot ROM's FEL code keeps its stack there
timeout 60 $F write 0x40000000 $W/bl31.bin
timeout 60 $F write 0x4a000000 $W/out-$V/u-boot.bin
while [ $# -ge 2 ]; do echo "write $2 -> $1"; timeout 600 $F write $1 $2; shift 2; done
timeout 20 $F reset64 0x40000000
