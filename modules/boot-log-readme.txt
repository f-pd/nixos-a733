nixos-a733 boot logs
====================

The board writes how far it got into this partition, so a boot can be
followed without a serial adapter. Power the board off, put the card in any
computer and open these files:

a733-uboot.txt          U-Boot: boot script found, kernel, initrd and device
                        tree loaded, kernel started. Missing: U-Boot never
                        ran boot.scr (boot0, U-Boot or the card itself).
a733-uboot-env.txt      The whole U-Boot environment.
a733-initrd-status.txt  Stage 1 (initrd): the kernel runs and systemd started.
a733-initrd-dmesg.txt   Kernel log during stage 1.
a733-initrd-journal.txt Journal during stage 1: root file system problems.
a733-system-*.txt       The same once NixOS itself has booted, refreshed for
                        the first five minutes, with the failed units.

The status LED blinks in a heartbeat pattern while the kernel runs.
