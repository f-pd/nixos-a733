# Writes the files the manufacturer's U-Boot needs for one NixOS generation:
# <boot>/boot.scr and <boot>/nixos/{uImage,uInitrd,dtbs}.
#
# Usage: install-a733-vendor-boot <toplevel> [<boot directory>, default /boot]
#
# Only the generation passed in is bootable: there is no menu of older
# generations. Rolling back means switching to an older generation from a
# running system, or rewriting /boot from another machine.
{
  writeShellApplication,
  coreutils,
  ubootTools,
  gnused,
  lib,
  deviceTree,
  overlays ? [ ],
}:
let
  # The manufacturer's overlays are named sun60i-a733-<name>.dtbo.
  overlayFile = name: "allwinner/overlay/sun60i-a733-${name}.dtbo";

  # U-Boot's hush rejects an empty for list, so no overlays means no loop.
  overlayScript = lib.optionalString (overlays != [ ]) ''
    setenv load_addr 0x43100000
    for overlay_file in ${lib.concatStringsSep " " overlays}; do
      if load ''${devtype} ''${devnum}:''${distro_bootpart} ''${load_addr} ''${prefix}nixos/dtbs/allwinner/overlay/sun60i-a733-''${overlay_file}.dtbo; then
        echo "nixos-a733: applying overlay ''${overlay_file}"
        fdt apply ''${load_addr} || echo "nixos-a733: overlay ''${overlay_file} failed to apply"
      fi
    done
  '';
in
writeShellApplication {
  name = "install-a733-vendor-boot";
  runtimeInputs = [
    coreutils
    ubootTools
    gnused
  ];
  text = ''
    toplevel=$(readlink -f "$1")
    boot=''${2:-/boot}

    tmp=$(mktemp -d "$boot/.nixos-a733.XXXXXX")
    trap 'rm -rf "$tmp"' EXIT

    mkdir -p "$tmp/nixos/dtbs/$(dirname ${deviceTree})"
    cp "$toplevel/dtbs/${deviceTree}" "$tmp/nixos/dtbs/${deviceTree}"

    ${lib.optionalString (overlays != [ ]) ''mkdir -p "$tmp/nixos/dtbs/allwinner/overlay"''}
    ${lib.concatMapStrings (name: ''
      if [ ! -e "$toplevel/dtbs/${overlayFile name}" ]; then
        echo "install-a733-vendor-boot: no overlay ${name} (${overlayFile name}) in this kernel" >&2
        exit 1
      fi
      cp "$toplevel/dtbs/${overlayFile name}" "$tmp/nixos/dtbs/${overlayFile name}"
    '') overlays}

    # Same load and entry address the manufacturer uses.
    mkimage -A arm -O linux -T kernel -C none -a 0x41000000 -e 0x41000000 \
      -n "NixOS kernel" -d "$toplevel/kernel" "$tmp/nixos/uImage" > /dev/null
    mkimage -A arm -O linux -T ramdisk -C none \
      -n "NixOS initrd" -d "$toplevel/initrd" "$tmp/nixos/uInitrd" > /dev/null

    sed -e "s|@init@|$toplevel/init|" \
        -e "s|@kernelParams@|$(cat "$toplevel/kernel-params")|" \
        -e "s|@deviceTree@|${deviceTree}|" \
        ${./boot.cmd} > "$tmp/boot.cmd.in"
    # The overlay block spans several lines: splice it in with a read loop.
    while IFS= read -r line; do
      if [ "$line" = "@overlays@" ]; then
        cat ${builtins.toFile "a733-overlays.cmd" overlayScript}
      else
        printf '%s\n' "$line"
      fi
    done < "$tmp/boot.cmd.in" > "$tmp/boot.cmd"
    rm "$tmp/boot.cmd.in"
    mkimage -C none -A arm -T script -d "$tmp/boot.cmd" "$tmp/boot.scr" > /dev/null

    # Replace the old files only once the new ones are complete.
    rm -rf "$boot/nixos.old"
    [ -d "$boot/nixos" ] && mv "$boot/nixos" "$boot/nixos.old"
    mv "$tmp/nixos" "$boot/nixos"
    mv "$tmp/boot.cmd" "$boot/boot.cmd"
    mv "$tmp/boot.scr" "$boot/boot.scr"
    rm -rf "$boot/nixos.old"
    sync
  '';
}
