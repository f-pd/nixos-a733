# boot0 and boot_package.fex as the manufacturer builds them: U-Boot gets the
# board's sys_config merged in, then U-Boot, BL31 (monitor.fex) and the SCP
# firmware are packed with dragonsecboot.
#
# The packing tools are static x86-64 binaries: on any other machine they run
# under qemu-user.
{
  lib,
  stdenvNoCC,
  callPackage,
  buildPackages,
  dtc,
  dos2unix,
}:
let
  files = callPackage ./files.nix { };
  uboot = callPackage ./u-boot.nix { };

  onX86 = stdenvNoCC.buildPlatform.isx86_64;
  run = lib.optionalString (!onX86) "${buildPackages.qemu-user}/bin/qemu-x86_64 ";
in
stdenvNoCC.mkDerivation {
  pname = "a733-vendor-boot";
  inherit (uboot) version;

  dontUnpack = true;

  nativeBuildInputs = [
    dtc
    dos2unix
  ];

  buildPhase = ''
    runHook preBuild

    install -m 755 ${files.script} script
    install -m 755 ${files.update_dtb} update_dtb
    install -m 755 ${files.update_uboot} update_uboot
    install -m 755 ${files.dragonsecboot} dragonsecboot

    install -m 644 ${uboot}/u-boot.bin u-boot.fex
    install -m 644 ${files.monitor} monitor.fex
    install -m 644 ${files.scp} scp.fex
    install -m 644 ${files."sys_config.fex"} sys_config.fex
    install -m 644 ${files."boot_package.cfg"} boot_package.cfg

    dtc -p 2048 -W no-unit_address_vs_reg -@ -O dtb -o sunxi.fex -b 0 ${files."u-boot.dts"}

    unix2dos sys_config.fex
    ${run}./script sys_config.fex
    ${run}./update_dtb sunxi.fex 4096
    ${run}./update_uboot -no_merge u-boot.fex sys_config.bin

    unix2dos boot_package.cfg
    ${run}./dragonsecboot -pack boot_package.cfg

    runHook postBuild
  '';

  installPhase = ''
    runHook preInstall
    mkdir -p $out
    install -m 644 ${files.boot0} $out/boot0_sdcard.fex
    install -m 644 boot_package.fex $out/boot_package.fex
    runHook postInstall
  '';

  passthru = { inherit uboot files; };

  meta.platforms = lib.platforms.linux;
}
