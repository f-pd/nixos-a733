# a733-info: the welcome screen of nixos-a733 (modules/welcome.nix).
#
#   a733-info              hardware, versions, network and services
#   a733-info --issue      the same under the header (pride snowflake, and
#                          beside it the system in short) with the first boot
#                          instructions, as an agetty issue file, on stdout
#   a733-info --logo       the header, its colours turning, left on screen
#   a733-info --logo-still the same, still
#   a733-info --new-slogan pick another slogan for the next --issue
#   a733-info --intro TTY  the header of the issue file, its colours turning,
#                          on TTY just before agetty prints it in place
#
# Set by welcome.nix before this text: COMPONENTS, SLOGANS, NIXOS_VERSION,
# NIXOS_RELEASE, MODULES, BLOB_OFFSETS, UBOOT_BUILT, PROMPT_COLOURS, CACHE.

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

# The NixOS snowflake in the colours of the pride flag: one colour per
# lambda, clockwise from the top right one. Two pixels per character, drawn
# with half blocks; a digit is the lambda that covers the pixel. Rasterized
# from nix-snowflake.svg of nixos-icons.
FLAKE=(
  "........555......0000....000........"
  "........5555.....0000...0000........"
  "........5555......0000..0000........"
  ".........5555.....000000000........."
  ".........5555......00000000........."
  "..........5555.....0000000.........."
  ".....555555555555555000000.........."
  "....555555555555555500000.....11...."
  "....555555555555555550000.....11...."
  "....55555555555555555.0000...1111..."
  "..........4444........00000..1111..."
  ".........4444..........0000.1111...."
  "........44444..........000011111...."
  "........4444............0001111....."
  "44444444444..............01111111111"
  "44444444444..............11111111111"
  "44444444444..............11111111111"
  "44444444443..............11111111111"
  ".....4444333............1111........"
  "....444443333..........11111........"
  "....4444.3333..........1111........."
  "...4444..33333........1111.........."
  "...4444...3333.22222222222222222...."
  "....44.....333322222222222222222...."
  "....44.....333332222222222222222...."
  "..........333333222222222222222....."
  "..........3333333.....2222.........."
  ".........33333333......2222........."
  ".........333333333.....2222........."
  "........3333..3333......2222........"
  "........3333...3333.....2222........"
  "........333....3333......222........"
)
FLAKE_ROWS=$((${#FLAKE[@]} / 2))
FLAKE_COLS=${#FLAKE[0]}

# ---------------------------------------------------------------- colours

# Foreground and background sequences of the six colours, in the richest
# form the terminal takes: 24-bit, 256 colours or the 16 every terminal
# knows (which have no orange: cyan takes its place).
FG=()
BG=()
palette() {
  local c rgb
  FG=()
  BG=()
  case $1 in
    truecolor)
      for rgb in "228;3;3" "255;140;0" "255;237;0" "0;160;60" "36;100;255" "150;60;210"; do
        FG+=("${ESC}[38;2;${rgb}m")
        BG+=("${ESC}[48;2;${rgb}m")
      done
      ;;
    256)
      for c in 196 208 226 34 27 129; do
        FG+=("${ESC}[38;5;${c}m")
        BG+=("${ESC}[48;5;${c}m")
      done
      ;;
    *)
      for c in 1 3 2 6 4 5; do
        FG+=("${ESC}[3${c}m")
        BG+=("${ESC}[4${c}m")
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

# FRAME[shift,row]: a row of the snowflake with the colours turned by shift
# lambdas. Six frames make a whole turn; computed once, as the animation has
# to be cheap on the CPU and on a 115200 baud serial line, which is why a
# colour sequence is only sent when the colour changes.
declare -A FRAME=()
flake_frames() {
  local s y x t b top bot out fg bg want_fg want_bg ch
  for ((s = 0; s < 6; s++)); do
    for ((y = 0; y < FLAKE_ROWS; y++)); do
      top=${FLAKE[2 * y]}
      bot=${FLAKE[2 * y + 1]}
      out=""
      fg=""
      bg=""
      for ((x = 0; x < FLAKE_COLS; x++)); do
        t=${top:x:1}
        b=${bot:x:1}
        want_fg=$fg
        want_bg=""
        if [ "$t" = . ] && [ "$b" = . ]; then
          ch=" "
        elif [ "$t" = "$b" ]; then
          ch="█" want_fg=${FG[(t + s) % 6]}
        elif [ "$b" = . ]; then
          ch="▀" want_fg=${FG[(t + s) % 6]}
        elif [ "$t" = . ]; then
          ch="▄" want_fg=${FG[(b + s) % 6]}
        else
          ch="▀" want_fg=${FG[(t + s) % 6]} want_bg=${BG[(b + s) % 6]}
        fi
        if [ "$want_bg" != "$bg" ]; then
          if [ -z "$want_bg" ]; then out+="${ESC}[49m"; else out+=$want_bg; fi
          bg=$want_bg
        fi
        if [ "$want_fg" != "$fg" ]; then
          out+=$want_fg
          fg=$want_fg
        fi
        out+=$ch
      done
      FRAME[$s,$y]="$out$R"
    done
  done
}

# What stands to the right of the snowflake, one line per row of it.
SIDE=()
side_text() {
  local ip ssh host sl i
  host=$(cat /proc/sys/kernel/hostname)
  ip=$(ip -4 -o addr show scope global 2> /dev/null | awk '{ sub(/\/.*/, "", $4); print $4 " (" $2 ")"; exit }')
  if systemctl is-active -q sshd.service 2> /dev/null; then
    ssh=$(ok "ssh <user>@$host")
  elif ! has_password; then
    ssh=$(off "after the first login")
  else
    ssh=$(off "$(systemctl is-active sshd.service 2> /dev/null)")
  fi
  sl=$(slogan_text)
  SIDE=(
    ""
    "$B$NIXOS_RELEASE$R"
    "${DIM}Allwinner A733 · $(board)$R"
    "$DIM────────────────────────────────────$R"
    "$(side_row Host "$host")"
    "$(side_row Image "nixos-a733 $(component nixos-a733)")"
    "$(side_row Kernel "$(uname -r)")"
    "$(side_row CPU "$(cpu_short)")"
    "$(side_row Memory "$(memory)")"
    "$(side_row Address "${ip:-none yet}")"
    "$(side_row SSH "$ssh")"
    ""
    "${sl:+$MAGENTA$sl$R}"
    ""
  )
  local swatch=""
  for ((i = 0; i < 6; i++)); do
    swatch+="${FG[i]}███"
  done
  SIDE+=("$swatch$R")
}

side_row() {
  printf '%s%-8s%s %s' "$BLUE" "$1" "$R" "$2"
}

# The snowflake and, on a terminal wide enough, the text beside it.
# FULL=no redraws only the snowflake, over the rows printed before.
header() {
  local shift=$1 full=${2:-yes} y line
  for ((y = 0; y < FLAKE_ROWS; y++)); do
    line="  ${FRAME[$shift,$y]}"
    if [ "$full" = yes ] && [ "$WIDE" = yes ]; then
      line+="  ${SIDE[y]}"
    fi
    printf '%s%s' "$line" "$NL"
  done
}

# The colours turn around the snowflake TURNS times, and stop where the
# still picture has them, on the same rows: nothing is swapped at the end.
header_animate() {
  local turns=$1 delay=$2 f
  printf '%s[?25l' "$ESC"
  header 0
  for ((f = 1; f <= turns * 6; f++)); do
    sleep "$delay"
    printf '%s[%dA' "$ESC" "$FLAKE_ROWS"
    header $((f % 6)) no
  done
  printf '%s[?25h' "$ESC"
}

NL=$'\n'
WIDE=yes
# The header with the snowflake is shown above the overview.
HEADER=no

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

# "8 cores, up to 2.0 GHz"
cpu_short() {
  local n max
  n=$(nproc 2> /dev/null)
  max=$(cat /sys/devices/system/cpu/cpu*/cpufreq/cpuinfo_max_freq 2> /dev/null | sort -n | tail -n 1)
  if [ -n "$max" ]; then
    awk -v n="$n" -v k="$max" 'BEGIN { printf "%d cores, up to %.1f GHz", n, k / 1000000 }'
  else
    echo "$n cores"
  fi
}

component() {
  awk -F= -v n="$1" '$1 == n { sub(/^[^=]*=/, ""); print; exit }' "$COMPONENTS"
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
  [ "$HEADER" = yes ] || row Board "$(board)"
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
  [ "$HEADER" = yes ] || row Hostname "$(cat /proc/sys/kernel/hostname)"
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
  # The radio command of the vendor module: Wi-Fi and Bluetooth stay off
  # until the user confirms the antenna is connected.
  if [ -x /run/current-system/sw/bin/radio ]; then
    if [ -e /var/lib/a733-radio/on ]; then
      row Radio "$(ok on) ${DIM}Wi-Fi and Bluetooth; radio off turns them off$R"
    else
      row Radio "$(off off) ${DIM}Wi-Fi and Bluetooth$R"
      printf '  %sWithout an antenna, transmitting can damage the radio. Connect it, log in\n' "$DIM"
      printf '  here and run %sradio on%s%s, then %snmtui%s%s to join a network.%s\n' "$B" "$R" "$DIM" "$B" "$R" "$DIM" "$R"
    fi
  elif [ $any = no ]; then
    printf '  %sNo address yet: plug in a USB Ethernet adapter, or set up Wi-Fi in your configuration.%s\n' "$DIM" "$R"
  fi
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
slogan_text() {
  local cache=$CACHE/slogan
  [ -r "$SLOGANS" ] || return 0
  if [ ! -s "$cache" ] && mkdir -p "$CACHE" 2> /dev/null; then
    shuf -n 1 "$SLOGANS" > "$cache"
  fi
  cat "$cache" 2> /dev/null || shuf -n 1 "$SLOGANS"
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

# The header: snowflake and the text beside it, ready to print.
prepare() {
  local cols
  palette "$1"
  flake_frames
  cols=$(stty size 2> /dev/null | awk '{ print $2 }')
  [ "${cols:-80}" -ge 80 ] || WIDE=no
  [ "$WIDE" = no ] || side_text
}

case ${1:-} in
  --issue)
    # agetty reads backslash escapes in issue files: keep ours literal.
    prepare "$PROMPT_COLOURS"
    [ "$WIDE" = yes ] && HEADER=yes
    {
      echo
      header 0
      overview
      instructions
      echo
    } | sed 's/\\/\\\\/g'
    ;;
  --new-slogan)
    rm -f "$CACHE/slogan"
    ;;
  --intro)
    # Before the login prompt, on its terminal: the header as the issue file
    # has it, animated, from where agetty is about to print. agetty starts
    # with a newline, the issue file with an empty line; at the end the
    # cursor goes back up, and agetty prints the same header over it.
    tty=${2:?a733-info --intro needs a terminal device}
    prepare "$PROMPT_COLOURS"
    NL=$'\r\n'
    {
      printf '\r\n\r\n'
      header_animate 2 0.05
      printf '%s[%dA\r' "$ESC" $((FLAKE_ROWS + 2))
    } > "$tty"
    ;;
  --logo | --logo-still)
    # After a login, in as many colours as the terminal has.
    prepare "$(colour_mode)"
    echo
    if [ "$1" = --logo ]; then
      header_animate 2 0.06
    else
      header 0
    fi
    printf '  %sa733-info%s hardware, versions, network and services\n\n' "$B" "$R"
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
