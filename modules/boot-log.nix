# Boot logs on the FAT partition of the SD card, for boards without a serial
# adapter at hand: take the card out, put it in any computer and read the
# text files at the top of the FAT partition (FIRMWARE).
#
# - a733-uboot.txt, a733-uboot-env.txt: written by the vendor boot.scr;
# - a733-initrd-*.txt: kernel log and journal of stage 1, refreshed every few
#   seconds until the root file system is switched to;
# - a733-system-*.txt: the same for the booted system, plus the failed units,
#   refreshed for the first minutes after boot.
{
  config,
  lib,
  pkgs,
  ...
}:
let
  cfg = config.hardware.a733.bootLog;

  partition = "/dev/disk/by-label/${config.sdImage.firmwarePartitionName or "FIRMWARE"}";
  mountPoint = "/run/a733-boot-log";

  # Run under systemd, with mount, umount, dmesg, journalctl and systemctl in
  # PATH. Every pass mounts the partition, writes the files and unmounts it,
  # so the card can be pulled out at any time. A stop (switch to the real
  # root, shutdown) is handled once the current command is done, so the
  # partition is never left mounted.
  dump = stage: rounds: interval: ''
    trap 'umount ${mountPoint} 2>/dev/null; exit 0' TERM
    for _ in $(seq 60); do
      [ -e ${partition} ] && break
      sleep 1
    done
    mkdir -p ${mountPoint}
    for round in $(seq ${toString rounds}); do
      if mount -t vfat ${partition} ${mountPoint}; then
        {
          echo "nixos-a733 ${stage}: pass $round of ${toString rounds}, uptime $(cut -d' ' -f1 /proc/uptime) s"
          echo "kernel command line: $(cat /proc/cmdline)"
        } > ${mountPoint}/a733-${stage}-status.txt
        dmesg > ${mountPoint}/a733-${stage}-dmesg.txt 2>&1 || true
        journalctl -b -o short-monotonic --no-pager > ${mountPoint}/a733-${stage}-journal.txt 2>&1 || true
        systemctl list-units --failed --no-pager --no-legend > ${mountPoint}/a733-${stage}-failed.txt 2>&1 || true
        umount ${mountPoint}
      fi
      sleep ${toString interval} &
      wait $!
    done
  '';
in
{
  options.hardware.a733.bootLog.enable = lib.mkEnableOption ''
    copies of the kernel log and the journal, from stage 1 and from the booted
    system, on the FAT partition of the SD card, readable on any computer
  '';

  config = lib.mkIf cfg.enable {
    boot.initrd.systemd.extraBin.dmesg = "${pkgs.util-linux}/bin/dmesg";

    # Stage 1 is where a missing driver or root file system leaves no other
    # trace. Stopped by the switch to the real root.
    boot.initrd.systemd.services.a733-boot-log = {
      description = "Copy the stage 1 boot log to the FAT partition";
      wantedBy = [ "initrd.target" ];
      after = [ "systemd-udevd.service" ];
      before = [ "initrd-switch-root.target" ];
      conflicts = [ "initrd-switch-root.target" ];
      unitConfig.DefaultDependencies = false;
      script = dump "initrd" 60 5;
    };

    systemd.services.a733-boot-log = {
      description = "Copy the boot log to the FAT partition";
      wantedBy = [ "sysinit.target" ];
      after = [ "local-fs.target" ];
      unitConfig.DefaultDependencies = false;
      conflicts = [ "shutdown.target" ];
      before = [ "shutdown.target" ];
      path = [
        pkgs.util-linux
        config.systemd.package
      ];
      script = dump "system" 20 15;
    };
  };
}
