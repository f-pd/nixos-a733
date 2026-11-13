#!/bin/sh
# Puts the two analysed binaries where the scripts expect them (analysis/blobs/).
# boot0 is the copy already in this repository; ddr.bin is fetched and checked.
set -eu
cd "$(dirname "$0")"
mkdir -p blobs
cp ../vendor/blobs/orangepi-build/external/packages/pack-uboot/sun60iw2/bin/boot0_sdcard_orangepizero3w.fex blobs/boot0.bin
curl -fsSL -o blobs/ddr.bin https://raw.githubusercontent.com/radxa-pkg/u-boot-dlan17/b1cec0a90c79/awbin/a733/ddr.bin
echo "d89804f404f2eef6ef5b03d82a310ef0906c4db8ded760be221b131f5c813a05  blobs/ddr.bin" | sha256sum -c -
echo "829ea8e3b65d71a02f2d0e094bc073de3a10869f948f62db49dbf023d07fabe3  blobs/boot0.bin" | sha256sum -c -
