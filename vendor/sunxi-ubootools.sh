#!/usr/bin/env bash
# Stand-in for the manufacturer's scripts/sunxi_ubootools, a dynamically
# linked x86-64 binary that cannot run in the build sandbox. The U-Boot
# Makefile only calls its ubootlength command, which:
#
#   1. rounds the size of u-boot-nodtb.bin up to a multiple of 4,
#   2. checks the "uboot" magic at offset 4 of the boot header,
#   3. writes the rounded size, 32-bit little-endian, at offset 0x4f0.
#
# boot0 reads that field to know how much of U-Boot to load.
set -euo pipefail

if [ "$#" -ne 2 ] || [ "$1" != ubootlength ]; then
  echo "sunxi-ubootools: only 'ubootlength <file>' is implemented" >&2
  exit 1
fi

file=$2

if ! printf 'uboot\0' | cmp -s - <(dd if="$file" bs=1 skip=4 count=6 status=none); then
  echo "sunxi-ubootools: $file has no uboot magic at offset 4" >&2
  exit 1
fi

size=$(stat -c %s "$file")
length=$(((size + 3) / 4 * 4))
truncate -s "$length" "$file"

printf "$(printf '\\%03o\\%03o\\%03o\\%03o' \
  $((length & 255)) $((length >> 8 & 255)) $((length >> 16 & 255)) $((length >> 24 & 255)))" |
  dd of="$file" bs=1 seek=$((0x4f0)) conv=notrunc status=none

echo "sunxi-ubootools: uboot length 0x$(printf '%x' "$length") written to $file"
