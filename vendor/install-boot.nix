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
  deviceTree,
}:
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

    # Same load and entry address the manufacturer uses.
    mkimage -A arm -O linux -T kernel -C none -a 0x41000000 -e 0x41000000 \
      -n "NixOS kernel" -d "$toplevel/kernel" "$tmp/nixos/uImage" > /dev/null
    mkimage -A arm -O linux -T ramdisk -C none \
      -n "NixOS initrd" -d "$toplevel/initrd" "$tmp/nixos/uInitrd" > /dev/null

    sed -e "s|@init@|$toplevel/init|" \
        -e "s|@kernelParams@|$(cat "$toplevel/kernel-params")|" \
        -e "s|@deviceTree@|${deviceTree}|" \
        ${./boot.cmd} > "$tmp/boot.cmd"
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
