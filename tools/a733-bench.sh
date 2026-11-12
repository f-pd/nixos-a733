#!/usr/bin/env bash
# a733-bench: the same measurements on any A733 image, so NixOS (vendor or
# mainline) can be compared with the manufacturer's Debian. Each test runs
# only when its tool is there and prints one result line; nothing is skipped
# silently. On Debian:
#   apt install sysbench fio clinfo clpeak vulkan-tools gstreamer1.0-tools
# Usage: a733-bench [output file]   (default: a733-bench-<host>-<date>.txt)
set -u

out=${1:-a733-bench-$(hostname)-$(date +%Y%m%d-%H%M).txt}
exec > >(tee "$out") 2>&1

have() { command -v "$1" > /dev/null; }
section() { printf '\n== %s\n' "$1"; }
skip() { echo "skipped: $1"; }

section system
uname -r
grep -m1 -i 'model name\|^Hardware' /proc/cpuinfo || true
nproc
free -m | sed -n 2p
for z in /sys/class/thermal/thermal_zone*; do
  [ -e "$z/temp" ] && echo "$(cat "$z/type") $(($(cat "$z/temp") / 1000)) C"
done
for p in /sys/devices/system/cpu/cpufreq/policy*; do
  [ -e "$p/cpuinfo_max_freq" ] && echo "$(basename "$p") max $(($(cat "$p/cpuinfo_max_freq") / 1000)) MHz, governor $(cat "$p/scaling_governor")"
done

section "drivers loaded"
for m in pvrsrvkm aic8800_fdrv aic8800_btlpm aw_nna_vip; do
  if [ -e "/sys/module/$m" ]; then echo "$m yes"; else echo "$m no"; fi
done
ls /dev/dri /dev/cedar_dev 2> /dev/null || true

section cpu
if have sysbench; then
  sysbench cpu --threads=1 --time=10 run | grep 'events per second'
  sysbench cpu --threads="$(nproc)" --time=10 run | grep 'events per second'
else skip "sysbench"; fi

section memory
if have sysbench; then
  sysbench memory --memory-block-size=1M --memory-total-size=8G run | grep 'transferred'
else skip "sysbench"; fi

section storage
if have fio; then
  f=$(mktemp -p "${TMPDIR:-/var/tmp}" a733-bench.XXXXXX)
  fio --name=seq --filename="$f" --size=256M --rw=read --bs=1M --direct=1 --output-format=terse | cut -d';' -f7 | sed 's/^/seq read KiB\/s /'
  fio --name=rnd --filename="$f" --size=256M --rw=randread --bs=4k --direct=1 --runtime=20 --output-format=terse | cut -d';' -f8 | sed 's/^/4k random read IOPS /'
  rm -f "$f"
else skip "fio"; fi

section "gpu: vulkan"
if have vulkaninfo; then
  vulkaninfo --summary 2> /dev/null | grep -E 'deviceName|driverInfo|apiVersion' || echo "no Vulkan device"
else skip "vulkaninfo"; fi

section "gpu: opencl"
if have clinfo; then
  clinfo -l 2> /dev/null || echo "no OpenCL platform"
else skip "clinfo"; fi
if have clpeak; then
  clpeak --global-bandwidth --compute-sp --compute-hp 2>&1 | grep -E 'Device:|Float|Half|float ' || true
else skip "clpeak"; fi

section "video engine: H.264 1080p encode"
if have gst-launch-1.0 && gst-inspect-1.0 omxh264videoenc > /dev/null 2>&1; then
  start=$(date +%s.%N)
  gst-launch-1.0 -q videotestsrc num-buffers=600 \
    ! video/x-raw,format=NV12,width=1920,height=1080,framerate=60/1 \
    ! omxh264videoenc ! fakesink sync=false
  end=$(date +%s.%N)
  awk -v s="$start" -v e="$end" 'BEGIN { printf "600 frames in %.1f s, %.0f fps\n", e - s, 600 / (e - s) }'
else skip "gst-launch-1.0 or omxh264videoenc"; fi

section "npu: vendor sample network"
if have vpm_run; then
  sample=$(dirname "$(readlink -f "$(command -v vpm_run)")")/../share/a733-npu/vpm_run
  [ -d "$sample" ] || sample=/opt/vpm_run
  # A writable copy: vpm_run may write its outputs next to the sample.
  d=$(mktemp -d)
  cp -r "$sample"/. "$d"
  (cd "$d" && vpm_run sample.txt 2>&1 | grep -iE 'time|fps|profil' | head -5)
  rm -rf "$d"
else skip "vpm_run"; fi

section "after the run"
for z in /sys/class/thermal/thermal_zone*; do
  [ -e "$z/temp" ] && echo "$(cat "$z/type") $(($(cat "$z/temp") / 1000)) C"
done
echo "saved to $out"
