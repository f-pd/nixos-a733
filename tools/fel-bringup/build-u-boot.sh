#!/bin/sh
# Cross-builds U-Boot for the Orange Pi Zero 3W inside a Debian container, for a
# host without Nix. Run from prepare.sh's work directory, mounted at /w:
#   docker run --rm -e OWNER=$(id -u):$(id -g) -v "$PWD":/w debian:trixie-slim sh /w/build-u-boot.sh
# Expects /w/u-boot (patched source), /w/bl31.bin, /w/payload.bin. Output: /w/out-on.
set -e
export DEBIAN_FRONTEND=noninteractive
apt-get update -qq && apt-get install -y -qq --no-install-recommends gcc gcc-aarch64-linux-gnu libc6-dev make bison flex bc libssl-dev libgnutls28-dev uuid-dev swig python3 python3-dev python3-setuptools python3-pyelftools python3-libfdt device-tree-compiler ca-certificates >/dev/null
cd /w/u-boot; O=/w/out-on
make -s O=$O CROSS_COMPILE=aarch64-linux-gnu- orangepi_zero3w_defconfig
make -s -j"$(nproc)" O=$O CROSS_COMPILE=aarch64-linux-gnu- BL31=/w/bl31.bin A733_DRAM_PAYLOAD=/w/payload.bin 2>&1 | tail -8
ls -l $O/u-boot-sunxi-with-spl.bin $O/spl/sunxi-spl.bin $O/u-boot.bin
chown -R "$OWNER" $O
