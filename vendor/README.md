# Manufacturer boot chain (phase 3)

Temporary: boots NixOS on the Orange Pi kernel and boot chain, built from the
Orange Pi sources, to prove NixOS itself works on the board before moving to
the mainline kernel and the open boot chain. The whole directory goes away
once that is done.

Everything is pinned in `sources.json`:

| Piece | Source | Built from source |
|-------|--------|-------------------|
| Kernel 6.6.98 | `orangepi-xunlong/linux-orangepi`, branch `orange-pi-6.6-sun60iw2` | yes |
| U-Boot 2018.05 | `orangepi-xunlong/u-boot-orangepi`, branch `v2018.05-sun60iw2` | yes, 32-bit |
| boot0 | `orangepi-build`, `boot0_sdcard_orangepizero3w.fex` | no, binary |
| BL31 | `orangepi-build`, `monitor.fex` | no, binary |
| SCP firmware | `orangepi-build`, `scp.fex` | no, binary |
| Packing tools | `orangepi-build`, `script`, `update_dtb`, `update_uboot`, `dragonsecboot` | no, static x86-64 binaries, run under qemu-user elsewhere |

`kernel/sun60iw2-a733.config` is the manufacturer's
`linux-sun60iw2-current-a733.config` with what systemd needs turned on:
`FHANDLE`, `TMPFS_POSIX_ACL`, `CRYPTO_USER_API`, `CRYPTO_USER_API_HASH`.

## SD card layout

| Offset | Content |
|--------|---------|
| 8 KiB | boot0 |
| 16400 KiB | boot_package: U-Boot, BL31, SCP |
| 32 MiB | FAT partition, unused |
| after it | root partition, ext4, marked bootable |

The manufacturer's U-Boot runs in 32-bit mode and does not boot an arm64
kernel from `extlinux.conf`, so `/boot/boot.scr` loads `/boot/nixos/uImage`,
`uInitrd` and the device tree with `bootm`, as the Orange Pi images do.
Only the current generation is bootable: there is no boot menu.

## Using it

```sh
nix build .#sd-image-vendor
zstd -dc result/sd-image/*.img.zst | sudo dd of=/dev/sdX bs=4M conv=fsync status=progress
```

Then connect to UART0 (pin 6 ground, pin 8 TX, pin 10 RX, 115200 baud) and
log in as root with an empty password.
