#!/bin/sh
# Fills a work directory with what chain.sh needs, on a host without Nix.
# usage: prepare.sh <workdir> <bl31.elf>     (bl31.elf: from the CI artifact a733-spl-zero-payload)
# Needs git, jq, cc, libusb-1.0, zlib and libfdt headers, llvm-objcopy, docker.
set -e
R=$(cd "$(dirname "$0")/../.." && pwd); W=$1; BL31=$2
mkdir -p "$W"; cp "$R"/tools/fel-bringup/chain.sh "$R"/tools/fel-bringup/ucmd.py "$R"/tools/fel-bringup/build-u-boot.sh "$W"/
cc -o "$W/usbreset" "$R/tools/fel-bringup/usbreset.c" $(pkg-config --cflags --libs libusb-1.0)
[ -d "$W/sunxi-tools" ] || git clone -q --depth 1 -b A733 https://github.com/dlan17/sunxi-tools "$W/sunxi-tools"
make -s -C "$W/sunxi-tools" sunxi-fel
make -s -C "$R/bootloader/dram" build/payload-pack
"$R/bootloader/dram/build/payload-pack" "$(find "$R/vendor/blobs" -name 'boot0_sdcard_orangepizero3w.fex')" "$W/payload.bin"
llvm-objcopy -O binary "$BL31" "$W/bl31.bin"
if [ ! -d "$W/u-boot" ]; then
	git init -q "$W/u-boot"; cd "$W/u-boot"
	git remote add origin https://github.com/radxa/u-boot
	git fetch -q --depth 1 origin "$(jq -r '."u-boot".rev' "$R/bootloader/sources.json")"; git checkout -q FETCH_HEAD
	for p in $(jq -r '."u-boot".patches[]' "$R/bootloader/sources.json"); do patch -p1 --batch -s < "$R/bootloader/patches/u-boot/$p"; done
	mkdir -p arch/arm/mach-sunxi/a733_dram
	cp -r "$R/bootloader/dram/include" "$R/bootloader/dram/src" arch/arm/mach-sunxi/a733_dram/
fi
echo "now: cd $W && docker run --rm -e OWNER=$(id -u):$(id -g) -v \"\$PWD\":/w debian:trixie-slim sh /w/build-u-boot.sh"
