# a733-info: the welcome screen of nixos-a733 (modules/welcome.nix).
#
#   a733-info              hardware, versions, network and services
#   a733-info --issue      the same with the rainbow logo and the first boot
#                          instructions, as an agetty issue file, on stdout
#   a733-info --logo       the rainbow logo, animated, left on screen
#   a733-info --logo-still the same, not animated
#   a733-info --new-slogan pick another slogan for the next --issue
#   a733-info --intro TTY  the rainbow logo animated on TTY, then erased: the
#                          static one of the issue file takes its place
#
# Set by welcome.nix before this text: COMPONENTS, SLOGANS, NIXOS_VERSION,
# MODULES, BLOB_OFFSETS, UBOOT_BUILT, CACHE.

# A display script: a fact that cannot be read is left out, it must never
# stop the rest. writeShellApplication turns these on.
set +o errexit +o nounset +o pipefail

export LC_ALL=C.UTF-8

ESC=$'\e'
R="${ESC}[0m"
B="${ESC}[1m"
DIM="${ESC}[2m"
RED="${ESC}[1;31m"
GREEN="${ESC}[1;32m"
YELLOW="${ESC}[1;33m"
BLUE="${ESC}[1;34m"
MAGENTA="${ESC}[1;35m"

LOGO=(
  "███╗   ██╗██╗██╗  ██╗ ██████╗ ███████╗"
  "████╗  ██║██║╚██╗██╔╝██╔═══██╗██╔════╝"
  "██╔██╗ ██║██║ ╚███╔╝ ██║   ██║███████╗"
  "██║╚██╗██║██║ ██╔██╗ ██║   ██║╚════██║"
  "██║ ╚████║██║██╔╝ ██╗╚██████╔╝███████║"
  "╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝"
)

# ---------------------------------------------------------------- colours

# The rainbow as foreground colour sequences, in the richest form the
# terminal takes: 24-bit, 256 colours, or the 16 every terminal knows.
PALETTE=()
palette() {
  local mode=$1 h region f q t r g b
  PALETTE=()
  case $mode in
    truecolor)
      for ((h = 0; h < 360; h += 10)); do
        region=$((h / 60))
        f=$(((h % 60) * 255 / 60))
        q=$((255 - f))
        t=$f
        case $region in
          0) r=255 g=$t b=0 ;;
          1) r=$q g=255 b=0 ;;
          2) r=0 g=255 b=$t ;;
          3) r=0 g=$q b=255 ;;
          4) r=$t g=0 b=255 ;;
          *) r=255 g=0 b=$q ;;
        esac
        PALETTE+=("${ESC}[1;38;2;${r};${g};${b}m")
      done
      ;;
    256)
      for c in 196 202 208 214 220 226 190 154 118 82 46 47 48 49 50 51 45 39 33 27 21 57 93 129 165 201 200 199 198 197; do
        PALETTE+=("${ESC}[1;38;5;${c}m")
      done
      ;;
    *)
      for c in 31 33 32 36 34 35; do
        PALETTE+=("${ESC}[1;${c}m")
      done
      ;;
  esac
}

colour_mode() {
  case ${COLORTERM:-} in
    truecolor | 24bit) echo truecolor && return ;;
  esac
  case ${TERM:-} in
    *256color* | *direct*) echo 256 ;;
    *) echo 16 ;;
  esac
}

# Where each letter of the logo starts: N I X O S.
LETTERS=(0 10 13 21 30)

# One frame of the logo, the colours moved by $1 steps: a diagonal rainbow,
# or with 16 colours one colour per letter, or it turns into confetti.
logo_frame() {
  local shift=$1 n=${#PALETTE[@]} y x l line out
  for y in "${!LOGO[@]}"; do
    line=${LOGO[y]}
    out=""
    if ((n <= 6)); then
      for l in "${!LETTERS[@]}"; do
        x=${LETTERS[l]}
        out+="${PALETTE[((l + n * 100 - shift) % n)]}${line:x:${LETTERS[l + 1]:-${#line}} - x}"
      done
    else
      for ((x = 0; x < ${#line}; x += 2)); do
        out+="${PALETTE[((x / 2 + y + n * 100 - shift) % n)]}${line:x:2}"
      done
    fi
    printf '  %s%s\n' "$out" "$R"
  done
}

# The rainbow running through the logo, about a second and a half.
logo_animate() {
  local frames=$1 delay=$2 erase=$3 f rows=${#LOGO[@]}
  printf '%s[?25l' "$ESC"
  trap 'printf "%s[0m%s[?25h" "$ESC" "$ESC"' RETURN
  for ((f = 0; f < frames; f++)); do
    ((f > 0)) && printf '%s[%dA' "$ESC" "$rows"
    logo_frame "$f"
    sleep "$delay"
  done
  if [ "$erase" = yes ]; then
    printf '%s[%dA%s[J' "$ESC" "$rows" "$ESC"
  fi
  printf '%s[?25h' "$ESC"
}

# ---------------------------------------------------------------- facts

row() {
  printf '  %s%-16s%s %s\n' "$BLUE" "$1" "$R" "$2"
}

section() {
  printf '\n %s▌ %s%s\n' "$MAGENTA" "$1" "$R"
}

ok() { printf '%s●%s %s' "$GREEN" "$R" "$1"; }
off() { printf '%s○%s %s' "$YELLOW" "$R" "$1"; }
bad() { printf '%s✗%s %s' "$RED" "$R" "$1"; }

human_kib() {
  awk -v k="$1" 'BEGIN {
    split("KiB MiB GiB TiB", u)
    i = 1
    while (k >= 1024 && i < 4) { k /= 1024; i++ }
    printf (k < 10 ? "%.1f %s" : "%.0f %s"), k, u[i]
  }'
}

board() {
  local model=""
  [ -r /proc/device-tree/model ] && model=$(tr -d '\0' < /proc/device-tree/model)
  echo "${model:-unknown board}"
}

# "8 cores: 2× Cortex-A76 @ 2.0 GHz, 6× Cortex-A55 @ 1.8 GHz"
cpu() {
  local dir part max name total=0
  declare -A count=() freq=()
  for dir in /sys/devices/system/cpu/cpu[0-9]*; do
    [ -d "$dir" ] || continue
    total=$((total + 1))
    part=$(awk -v n="${dir##*cpu}" '
      /^processor/ { p = $NF }
      /^CPU part/ && p == n { print $NF; exit }
    ' /proc/cpuinfo)
    max=$(cat "$dir/cpufreq/cpuinfo_max_freq" 2> /dev/null || echo 0)
    part=${part:-?}
    count[$part]=$((${count[$part]:-0} + 1))
    ((max > ${freq[$part]:-0})) && freq[$part]=$max
  done
  local out="" sep=""
  while read -r part; do
    case $part in
      0xd03) name=Cortex-A53 ;;
      0xd05) name=Cortex-A55 ;;
      0xd08) name=Cortex-A72 ;;
      0xd0b) name=Cortex-A76 ;;
      0xd41) name=Cortex-A78 ;;
      *) name="core $part" ;;
    esac
    out+="$sep${count[$part]}× $name"
    if ((${freq[$part]:-0} > 0)); then
      out+=" @ $(awk -v k="${freq[$part]}" 'BEGIN { printf "%.1f GHz", k / 1000000 }')"
    fi
    sep=", "
  done < <(printf '%s\n' "${!count[@]}" | sort)
  echo "$total cores: $out"
}

memory() {
  local total swap
  total=$(awk '/^MemTotal:/ { print $2 }' /proc/meminfo)
  swap=$(awk '/^SwapTotal:/ { print $2 }' /proc/meminfo)
  if ((swap > 0)); then
    echo "$(human_kib "$total") RAM, $(human_kib "$swap") swap"
  else
    echo "$(human_kib "$total") RAM"
  fi
}

# The disk the root file system is on, with what kind of card it is.
root_disk() {
  local source disk kind="" size used
  source=$(findmnt -no SOURCE / 2> /dev/null)
  disk=$(lsblk -no PKNAME "$source" 2> /dev/null | head -n 1)
  [ -n "$disk" ] || return 0
  case $(cat "/sys/block/$disk/device/type" 2> /dev/null) in
    SD) kind="microSD " ;;
    MMC) kind="eMMC " ;;
  esac
  case $disk in
    sd*) kind="USB " ;;
    nvme*) kind="NVMe " ;;
  esac
  size=$(lsblk -dno SIZE "/dev/$disk" 2> /dev/null | tr -d ' ')
  used=$(df -h --output=used,size,pcent / 2> /dev/null | awk 'NR == 2 { print $1 " of " $2 " used (" $3 ")" }')
  echo "$kind$size /dev/$disk, root $used"
}

drivers() {
  local m out="" sep=""
  for m in $MODULES; do
    if [ -d "/sys/module/$m" ]; then
      out+="$sep$(ok "$m")"
    else
      out+="$sep$(bad "$m")"
    fi
    sep="  "
  done
  [ -n "$out" ] && echo "$out"
}

# The version string in the U-Boot actually written on the card, which may
# be older or newer than the one this system was built with. Read once per
# boot, as root, and kept in $CACHE for everyone else.
uboot() {
  local cache=$CACHE/u-boot found="" source disk off
  if [ ! -e "$cache" ] && [ "$(id -u)" = 0 ]; then
    source=$(findmnt -no SOURCE / 2> /dev/null)
    disk=$(lsblk -no PKNAME "$source" 2> /dev/null | head -n 1)
    if [ -n "$disk" ] && [ -r "/dev/$disk" ]; then
      for off in $BLOB_OFFSETS; do
        found=$(dd if="/dev/$disk" bs=1K skip="$off" count=4096 status=none 2> /dev/null |
          grep -a -o -m 1 'U-Boot 20[0-9][0-9]\.[0-9][0-9][^ ]*' | head -n 1)
        [ -n "$found" ] && break
      done
    fi
    mkdir -p "$CACHE"
    echo "${found#U-Boot }" > "$cache"
  fi
  found=$(cat "$cache" 2> /dev/null)
  if [ -n "$found" ]; then
    echo "$found"
  else
    echo "$UBOOT_BUILT"
  fi
}

# ---------------------------------------------------------------- sections

hardware() {
  section Hardware
  row Board "$(board)"
  row CPU "$(cpu)"
  row Memory "$(memory)"
  local disk
  disk=$(root_disk)
  [ -n "$disk" ] && row Storage "$disk"
  local d
  d=$(drivers)
  [ -n "$d" ] && row Drivers "$d"
  if [ -d /sys/class/bluetooth/hci0 ]; then
    row Bluetooth "$(ok hci0)"
  fi
}

software() {
  section Software
  local name version
  while IFS='=' read -r name version; do
    [ "$name" = nixos-a733 ] && row nixos-a733 "$version"
  done < "$COMPONENTS"
  row NixOS "$NIXOS_VERSION"
  row Kernel "$(uname -r)"
  [ -n "$BLOB_OFFSETS$UBOOT_BUILT" ] && row U-Boot "$(uboot)"
  while IFS='=' read -r name version; do
    [ "$name" = nixos-a733 ] || row "$name" "$version"
  done < "$COMPONENTS"
}

network() {
  section Network
  local any=no dir i kind state addr ssid
  row Hostname "$(cat /proc/sys/kernel/hostname)"
  for dir in /sys/class/net/*; do
    i=${dir##*/}
    [ "$i" = lo ] && continue
    kind=Ethernet
    [ -e "$dir/device" ] || kind=virtual
    [ -d "$dir/wireless" ] || [ -e "$dir/phy80211" ] && kind=Wi-Fi
    [ "$(readlink -f "$dir/device/subsystem" 2> /dev/null)" = /sys/bus/usb ] && kind="USB $kind"
    state=$(cat "$dir/operstate" 2> /dev/null)
    addr=$(ip -4 -o addr show dev "$i" 2> /dev/null | awk '{ sub(/\/.*/, "", $4); printf "%s%s", s, $4; s = " " }')
    # Virtual interfaces only when they carry an address (a VPN, a bridge).
    [ -e "$dir/device" ] || [ -n "$addr" ] || continue
    ssid=""
    if [ "$kind" = Wi-Fi ] || [ "$kind" = "USB Wi-Fi" ]; then
      ssid=$(iw dev "$i" link 2> /dev/null | sed -n 's/^[[:space:]]*SSID: //p')
      [ -n "$ssid" ] && ssid=" \"$ssid\""
    fi
    if [ -n "$addr" ]; then
      any=yes
      row "$i" "$(ok "$B$addr$R") $DIM$kind$ssid$R"
    elif [ "$state" = up ]; then
      row "$i" "$(off "no address yet") $DIM$kind$ssid$R"
    else
      row "$i" "$(off "$state") $DIM$kind$R"
    fi
  done
  local route
  route=$(ip -4 route show default 2> /dev/null | awk '{ print "via " $3 " (" $5 ")"; exit }')
  if [ -n "$route" ]; then
    row Internet "$(ok "$route")"
  else
    row Internet "$(off "no default route")"
  fi
  [ $any = yes ] || printf '  %sNo address yet: plug in a USB Ethernet adapter, or set up Wi-Fi in your configuration.%s\n' "$DIM" "$R"
}

services() {
  section Services
  local running failed ssh
  if systemctl is-active -q sshd.service; then
    ssh=$(ok "listening on port 22")
  elif ! has_password; then
    ssh=$(off "starts once an account has a password")
  else
    ssh=$(off "$(systemctl is-active sshd.service 2> /dev/null)")
  fi
  row SSH "$ssh"
  running=$(systemctl list-units --type=service --state=running --no-legend --plain 2> /dev/null |
    awk '{ print $1 }' |
    grep -v -E '^(getty@|serial-getty@|autovt@|user@|user-runtime-dir@|systemd-|dbus|nscd|a733-|sshd)' |
    sed 's/\.service$//' | sort | paste -sd ' ')
  [ -n "$running" ] && row Running "$(echo "$running" | fold -s -w 58 | sed '2,$s/^/                   /')"
  failed=$(systemctl list-units --failed --no-legend --plain 2> /dev/null | awk '{ print $1 }' | paste -sd ' ')
  if [ -n "$failed" ]; then
    row Failed "$(bad "$failed")"
    printf '  %sDetails: systemctl status <unit>, or journalctl -b -p 3%s\n' "$DIM" "$R"
  else
    row Failed "$(ok none)"
  fi
}

# ---------------------------------------------------------------- first boot

# Some account can log in with a password.
has_password() {
  [ -r /etc/shadow ] || return 0
  grep -q '^[^:]*:\$' /etc/shadow
}

# A normal user with a password exists.
has_user() {
  [ -r /etc/shadow ] || return 0
  awk -F: '
    NR == FNR { if ($2 ~ /^\$/) set[$1]; next }
    $3 >= 1000 && $3 < 30000 && ($1 in set) { found = 1 }
    END { exit !found }
  ' /etc/shadow /etc/passwd
}

instructions() {
  local ip
  ip=$(ip -4 -o addr show scope global 2> /dev/null | awk '{ sub(/\/.*/, "", $4); print $4; exit }')
  if ! has_password || ! has_user; then
    printf '\n %s▌ First boot%s\n' "$YELLOW" "$R"
    printf '  %s1.%s Log in as %sroot%s. It has no password yet: none is asked.\n' "$YELLOW" "$R" "$B" "$R"
    printf '  %s2.%s Choose the root password when asked (type it twice).\n' "$YELLOW" "$R"
    printf '  %s3.%s Say whether you see icons (Nerd Font), then create your own user:\n' "$YELLOW" "$R"
    printf '     it can use %ssudo%s. Ctrl-C skips a question until the next root login.\n' "$B" "$R"
    printf '  %s4.%s SSH starts once that is done: %sssh <user>@%s%s\n' "$YELLOW" "$R" "$B" "${ip:-<board address>}" "$R"
  else
    printf '\n  Log in with your user%s. %sa733-info%s shows this screen again.\n' \
      "${ip:+, here or with ssh <user>@$ip}" "$B" "$R"
  fi
}

# A new slogan each time a login prompt starts (--new-slogan), the same one
# while it waits: a refresh redraws the prompt only when something changed.
slogan() {
  local cache=$CACHE/slogan
  [ -r "$SLOGANS" ] || return 0
  if [ ! -s "$cache" ] && mkdir -p "$CACHE" 2> /dev/null; then
    shuf -n 1 "$SLOGANS" > "$cache"
  fi
  printf '\n  %s%s%s\n' "$MAGENTA" "$(cat "$cache" 2> /dev/null || shuf -n 1 "$SLOGANS")" "$R"
}

tips() {
  printf '\n  %sa733-info%s this overview   %sbtop%s system monitor   %sjctl%s errors of this boot\n' \
    "$B" "$R" "$B" "$R" "$B" "$R"
}

overview() {
  hardware
  software
  network
  services
}

# ---------------------------------------------------------------- main

case ${1:-} in
  --issue)
    # agetty reads backslash escapes in issue files: keep ours literal.
    {
      palette 16
      echo
      logo_frame 0
      printf '  %s%s%s\n' "$DIM" "on Allwinner A733 · $(board)" "$R"
      overview
      instructions
      slogan
      echo
    } | sed 's/\\/\\\\/g'
    ;;
  --new-slogan)
    rm -f "$CACHE/slogan"
    ;;
  --intro)
    # Before the login prompt: plain 16 colours, which every serial terminal
    # understands, erased at the end for the logo of the issue file.
    tty=${2:?a733-info --intro needs a terminal device}
    palette 16
    logo_animate 18 0.06 yes > "$tty"
    ;;
  --logo | --logo-still)
    # Not on a terminal narrower than the logo.
    cols=$(stty size 2> /dev/null | awk '{ print $2 }')
    ((${cols:-80} >= 42)) || exit 0
    palette "$(colour_mode)"
    echo
    if [ "$1" = --logo ]; then
      logo_animate 40 0.03 no
    else
      logo_frame 0
    fi
    ;;
  "" | --info)
    overview
    tips
    echo
    ;;
  *)
    echo "usage: a733-info [--issue | --logo | --logo-still | --new-slogan | --intro TTY]" >&2
    exit 1
    ;;
esac
