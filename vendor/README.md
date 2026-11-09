# Vendor variant

NixOS on what Orange Pi ships for the Zero 3W: their kernel, boot chain,
firmware and drivers, matching their Debian image. Their binaries are taken as
they are here. The mainline variants, latest LTS and latest stable, must reach
the same hardware support with official, community or source-built components
only.

Everything is pinned in `sources.json`:

| Piece | Source | Built from source |
|-------|--------|-------------------|
| Kernel 6.6.98 | `orangepi-xunlong/linux-orangepi`, branch `orange-pi-6.6-sun60iw2` | yes |
| U-Boot 2018.05 | `orangepi-xunlong/u-boot-orangepi`, branch `v2018.05-sun60iw2` | yes, 32-bit |
| boot0 | `orangepi-build`, `boot0_sdcard_orangepizero3w.fex` | no, binary |
| BL31 | `orangepi-build`, `monitor.fex` | no, binary |
| SCP firmware | `orangepi-build`, `scp.fex` | no, binary |
| Packing tools | `orangepi-build`, `script`, `update_dtb`, `update_uboot`, `dragonsecboot` | no, static x86-64 binaries, run under qemu-user elsewhere |
| AIC8800D80 Wi-Fi and Bluetooth firmware | `orangepi-xunlong/firmware`, `aic8800d80/` | no, binary |
| `hciattach_opi` | `orangepi-build`, `blobs/bt/hciattach/hciattach_opi_arm64` | no, arm64 binary |
| libcedarc, libAWIspApi, gst-omx | `orangepi-xunlong/rk-rootfs-build`, branch `sun60iw2_packages` | no, arm64 Debian packages |

## Hardware options

All under `hardware.a733.vendor`, on by default unless noted:

| Option | What it does | Manufacturer equivalent |
|--------|--------------|-------------------------|
| `wifi.enable` | AIC8800 firmware, `aic8800_fdrv` | `MODULES=` in the board config |
| `bluetooth.enable` | `aic8800_btlpm`, wakes the core and runs `hciattach_opi -n -s 1500000 /dev/ttyS1 aic`, BlueZ | `orangepi-hardware-optimization` |
| `video.enable` | Cedar video engine (`libcedarc`: decoders, H.264 and H.265 encoders, OpenMAX), camera ISP library, GStreamer `omx` plugin, `/etc/cedarc.conf`, device permissions | `libcedarc`, `libAWIspApi`, `gst-omx` packages and `99-t527-permissions.rules` |
| `usbHost` | USB-C in host mode | `orangepi-hardware-optimization` |
| `overlays` (default none) | device tree overlays applied by U-Boot, e.g. `[ "uart2" "i2c1" ]` | `overlays=` in `orangepiEnv.txt` |

The kernel command line adds the manufacturer's `swiotlb=65536` and
`consoleblank=0`. Firmware is installed uncompressed: this kernel has no
`CONFIG_FW_LOADER_COMPRESS`.

`kernel/sun60iw2-a733.config` is the manufacturer's
`linux-sun60iw2-current-a733.config` with what systemd needs turned on:
`FHANDLE`, `TMPFS_POSIX_ACL`, `CRYPTO_USER_API`, `CRYPTO_USER_API_HASH`.

The manufacturer's Makefiles assume a build inside the source tree, while Nix
builds in a separate directory. Two fixes in `patches/` make them work there:

- `ctp-kconfig-double-slash.patch`: the touch screen Kconfig includes
  `gt9xx_secondary//Kconfig`, a path make cannot match, so the configuration
  was regenerated in an endless loop;
- `ve-codec-out-of-tree.patch`: the video engine includes `codec/Makefile` and
  its headers through `$(src)` and `$(PWD)`; both now go through `$(srctree)`.

Each make call of the configure phase is limited to 10 minutes, so a loop like
that fails the build instead of running until the CI job times out.

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
