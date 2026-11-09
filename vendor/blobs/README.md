# Manufacturer files

Copies of every file the vendor variant takes from Orange Pi, so the build
does not depend on their repositories staying as they are: a pinned commit
that is force-pushed away or deleted upstream would make the build impossible
to reproduce.

Each file sits at `<repository>/<path in that repository>`, exactly as it is
at the pinned commit. `sources.json` holds the same repository, commit, path
and SHA-256: `vendor/blob.nix` adds the file to the store under that hash,
and evaluation fails if a file here no longer matches it.

These are the manufacturer's binaries, redistributed as Orange Pi publishes
them; they are not covered by this repository's GPL-3.0 licence. The mainline
variants use none of them.

To update a file: take it from the upstream repository at the new commit,
replace it here at the same path, and update the commit and hash in
`sources.json` in the same commit.

The kernel and U-Boot sources are not copied: they are fetched from
`orangepi-xunlong/linux-orangepi` and `orangepi-xunlong/u-boot-orangepi` at the
commits in `sources.json`.

## orangepi-build

[`orangepi-xunlong/orangepi-build`](https://github.com/orangepi-xunlong/orangepi-build) at commit [`7f24222b928e`](https://github.com/orangepi-xunlong/orangepi-build/tree/7f24222b928eab94780f2af03289ce527e07241e)

| File | Used for | SHA-256 (SRI) |
|------|----------|---------------|
| `external/packages/pack-uboot/sun60iw2/bin/boot0_sdcard_orangepizero3w.fex` | first-stage loader the boot ROM runs, written at 8 KiB on the card | `sha256-gp6o47ZdcaAvLQ4JS8Bz3joQhp+Uj2LbSdvwI9B/q+M=` |
| `external/packages/pack-uboot/sun60iw2/bin/monitor.fex` | BL31, the ARM trusted firmware packed into boot_package | `sha256-ivFrhq6OLv9jSj68p2qM3zwQs1QDh1c9RsPXhVRbJjI=` |
| `external/packages/pack-uboot/sun60iw2/bin/scp.fex` | firmware of the power management coprocessor, packed into boot_package | `sha256-B+a5digQGWPnlE4BKUjEvfch+RS600es19+96J20J0k=` |
| `external/packages/pack-uboot/sun60iw2/bin/boot_package.cfg` | list of what dragonsecboot packs into boot_package | `sha256-Cb1D9o5UwHRrUTCjrPN/04GR2Rh+Mp4reHEVYbb52Rg=` |
| `external/packages/pack-uboot/sun60iw2/bin/sys_config/sys_config.fex` | board configuration merged into U-Boot | `sha256-61mII9lH+jnQzyECBRuSHRD0GyZTgQO5+jombGpIaik=` |
| `external/packages/pack-uboot/sun60iw2/bin/dts/u-boot-current.dts` | U-Boot device tree, compiled and merged into U-Boot | `sha256-vY4ydAvBwlUy8oyueGDGHwdQbfxTpnLZcm0v1+px/ww=` |
| `external/packages/pack-uboot/tools/script` | x86-64 tool: compiles sys_config.fex | `sha256-wceQ/6pDKq7QbmqYTBXYBG+YnrtLMrzIS0uBB2ceLa0=` |
| `external/packages/pack-uboot/tools/update_dtb` | x86-64 tool: pads the U-Boot device tree | `sha256-ZxlqacJKNkDskT495NHY7qYobtwHTKlCYO+n4sXFMI4=` |
| `external/packages/pack-uboot/tools/update_uboot` | x86-64 tool: merges sys_config into U-Boot | `sha256-6YrurlOcopLeqGbgJkVvWtg4iME72JdDMyIFKwifkOc=` |
| `external/packages/pack-uboot/tools/dragonsecboot` | x86-64 tool: packs boot_package.fex | `sha256-5fkHZQSgzN4pxZeLz8NBwcWsAtlHxHuEml6NJkM1RfY=` |
| `external/packages/blobs/bt/hciattach/hciattach_opi_arm64` | attaches the AIC8800 Bluetooth core on ttyS1 | `sha256-Xwwvele3UVawkYXNsPDuF4ZFk68q+GPPJzEVxhXKj1s=` |

## firmware

[`orangepi-xunlong/firmware`](https://github.com/orangepi-xunlong/firmware) at commit [`dc163b0ed2e0`](https://github.com/orangepi-xunlong/firmware/tree/dc163b0ed2e0272d9ee31977a0e0a04884f0ae61)

| File | Used for | SHA-256 (SRI) |
|------|----------|---------------|
| `aic8800d80/aic_userconfig_8800d80.txt` | AIC8800D80 Wi-Fi and Bluetooth firmware | `sha256-mV27nk8uexnbg4KR9SvjmvmrZzrVGycMmIIWzP8acg4=` |
| `aic8800d80/fmacfw_8800d80_h_u02.bin` | AIC8800D80 Wi-Fi and Bluetooth firmware | `sha256-ro1UjflsEyxEX4iLkeq17wPBmZG4ve9PwS6/y/n5U+c=` |
| `aic8800d80/fmacfw_8800d80_u02.bin` | AIC8800D80 Wi-Fi and Bluetooth firmware | `sha256-VbWiCGWsp80u2q4XM6NtpF0rCykGC8JD2OnsIS4Tn2w=` |
| `aic8800d80/fmacfwbt_8800d80_u02.bin` | AIC8800D80 Wi-Fi and Bluetooth firmware | `sha256-79S/Yi5repK9JkxkvLkAKi4pP4lBt/2JHKTdaRVkjLY=` |
| `aic8800d80/fw_adid_8800d80_u02.bin` | AIC8800D80 Wi-Fi and Bluetooth firmware | `sha256-pSbL0C/NxJXwSfOta1kzywjNmEsWeQxxagYNWC/uGlY=` |
| `aic8800d80/fw_patch_8800d80_u02.bin` | AIC8800D80 Wi-Fi and Bluetooth firmware | `sha256-StTu3k00fEXtYbI1COeEPciE8OQRv5V/lUEAAdDPxNA=` |
| `aic8800d80/fw_patch_table_8800d80_u02.bin` | AIC8800D80 Wi-Fi and Bluetooth firmware | `sha256-X/GEEF/cTEZ54CZBj02ik+/sjfAqOjyiLO5yPBffSmA=` |
| `aic8800d80/lmacfw_rf_8800d80_u02.bin` | AIC8800D80 Wi-Fi and Bluetooth firmware | `sha256-Tose+12bspmq+VDWol48px1C4BLUL9PsO0l1nMZLOLI=` |

## rk-rootfs-build

[`orangepi-xunlong/rk-rootfs-build`](https://github.com/orangepi-xunlong/rk-rootfs-build) at commit [`7b6d78d4f5ea`](https://github.com/orangepi-xunlong/rk-rootfs-build/tree/7b6d78d4f5eaefd5456777fbea5057a0876e8f4d)

| File | Used for | SHA-256 (SRI) |
|------|----------|---------------|
| `bullseye/libcedarc/libcedarc-dev_2.0.0_arm64.deb` | Cedar video engine: hardware decoders, H.264/H.265 encoders, OpenMAX | `sha256-wZGP0JP6NiWCIu4/9Z9ElibPD+2aANTwqv5+24i3Mo0=` |
| `bullseye/libAWIspApi/libAWIspApi_602_1.0.0_arm64.deb` | camera image signal processor library | `sha256-UectLTfZuq0nsHALEu58EXZgFZp68R1LNLJglhi27jE=` |
| `bullseye/gst-omx-generic1.0/gstreamer1.0-omx-allwinner_1.18.3-1.1_arm64.deb` | GStreamer OpenMAX plugin for the Cedar components | `sha256-FKJAhcJ9wrQ/xf0gJtpxegOh9AVOzTacj9NDcplc3KY=` |
| `bullseye/gst-omx-generic1.0/gstreamer1.0-omx-allwinner-config_1.18.3-1.1_arm64.deb` | configuration of that plugin | `sha256-h5khNVp9tHZoIfxnOVsEt/o/gEIRpIWcECCzIFqJ+R0=` |
| `npu/usr/lib/libVIPhal.so` | NPU runtime and samples | `sha256-ZIREomoa6uwBgsC6NIt6RTE0uMzfgoKiEc5MD15eUaA=` |
| `npu/usr/lib/libNBGlinker.so` | NPU runtime and samples | `sha256-3pO7Sn2Gr2e8TKWX0SIoubIbBiYBsY8zyjA5Oir0qEI=` |
| `npu/usr/include/vip_lite.h` | NPU runtime and samples | `sha256-M/7o+YUhDLNPFLfisGFAluaXJxj4fYEHSXUh1WHZ30E=` |
| `npu/usr/include/vip_lite_common.h` | NPU runtime and samples | `sha256-2AchboN23kcp3gdOyxuRzVzKsnnvGFQ6zTrbYbGhUY4=` |
| `npu/opt/vpm_run/vpm_run` | NPU runtime and samples | `sha256-286jJmBw1RpOCzqsGVQIFNBl83J6YEXuluJflGQ3FAc=` |
| `npu/opt/vpm_run/readme.txt` | NPU runtime and samples | `sha256-xLBPS7hif4m0b8r4DtWV6mlk9SPr1b0Jan0EglSGrqQ=` |
| `npu/opt/vpm_run/sample.txt` | NPU runtime and samples | `sha256-1LFwI+kKmVYXNSQOW6TegJDVH5nl1rfdaLkzavtJABc=` |
| `npu/opt/vpm_run/input_0.dat` | NPU runtime and samples | `sha256-04wiwgB9sxRXLJ3f61E6nz0R7Jno3uwPZbyRSBUC8bk=` |
| `npu/opt/vpm_run/network_binary.nb` | NPU runtime and samples | `sha256-/A1Qvchj5N/HTu9trZ00ZVxWDnWaL0JpeaAcUF+puV8=` |
| `npu/opt/yolov5/model/yolov5.nb` | NPU runtime and samples | `sha256-bGyyYfQfzHdBNLkNDh8qF2dc1toejxxtK2FGDP1YQVg=` |
| `bullseye/xserver/xserver-xorg-img-bxm_1.21.1-2_arm64.deb` | PowerVR BXM firmware, Vulkan, OpenCL and EGL/GLES drivers | `sha256-yOYG2xq96kCluX95BeqGkBtQxf4bdqVTVqtw3eMwTDo=` |
