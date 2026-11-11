# A friendly first contact: a random slogan above the login prompt, fastfetch
# after it (serial console, local console and SSH), Tokyo Night colours, the
# starship prompt, the usual comfort tools and aliases, and a guided first
# login.
#
# First login: while root has an empty password, the login prompt makes root
# choose one. Root is then asked whether the terminal has a Nerd Font, and to
# create the main user. SSH stays off until an account has a password.
{
  config,
  lib,
  pkgs,
  ...
}:
let
  cfg = config.hardware.a733.welcome;

  # Nix strings have no escape for the ESC character.
  esc = builtins.fromJSON ''"\u001b"'';

  # Tokyo Night as 24-bit colour sequences, for the tools that take them.
  blue = "38;2;122;162;247";
  magenta = "38;2;187;154;247";

  hasPassword = pkgs.writeShellScript "a733-has-password" ''
    exec ${lib.getExe pkgs.gnugrep} -q '^[^:]*:\$' /etc/shadow
  '';

  # The answer to the Nerd Font question: "yes" or "no".
  iconsFile = "/var/lib/a733-welcome/icons";

  # Run at every interactive root login. Each question is asked until it has
  # an answer, so it is safe to interrupt: it asks again at the next root
  # login, and the same user name picks up an account left half made.
  firstLogin = pkgs.writeShellScript "a733-first-login" ''
    if [ ! -e ${iconsFile} ]; then
      echo
      printf '   \uf07b   \ue0b0   \uf313\n'
      read -r -p "Do you see three icons above (folder, arrow, snowflake)? [y/N] " answer || exit 1
      mkdir -p ${dirOf iconsFile}
      case "$answer" in
        [yYsS]*) echo yes ;;
        *) echo no ;;
      esac > ${iconsFile}
    fi

    if ! awk -F: '
      NR == FNR { if ($2 ~ /^\$/) set[$1]; next }
      $3 >= 1000 && $3 < 30000 && ($1 in set) { found = 1 }
      END { exit !found }
    ' /etc/shadow /etc/passwd; then
      echo
      echo "Create your main user: it can use sudo. Ctrl-C skips this for now."
      while :; do
        read -r -p "User name: " name || exit 1
        id -u "$name" > /dev/null 2>&1 || useradd -m -G wheel "$name" || continue
        passwd "$name" && break
      done
      ${lib.optionalString config.services.openssh.enable "systemctl start sshd.service"}
    fi
  '';

  slogans = pkgs.writeText "a733-slogans" ''
    Siamo tutti antifascisti
    1312
    161
    Eat the rich
    No war but class war
    Make greed a sin again
    Fuck god and cum hard
    Trans rights are human rights
    Be gay, do crime
  '';

  # A new slogan under the greeting every time a login prompt starts.
  slogan = pkgs.writeShellScript "a733-slogan" ''
    PATH=${pkgs.coreutils}/bin
    mkdir -p /run/issue.d
    printf '\033[1;35m%s\033[0m\n\n' "$(shuf -n 1 ${slogans})" > /run/issue.d/a733-slogan.issue
  '';

  btopConf = pkgs.writeText "btop.conf" ''
    color_theme = "tokyo-night"
  '';
in
{
  options.hardware.a733.welcome.enable = lib.mkEnableOption ''
    a slogan above the login prompt, fastfetch after it, Tokyo Night colours,
    the starship prompt, comfort tools and aliases, and a guided first login
    that sets the root password and creates the main user
  '';

  config = lib.mkIf cfg.enable {
    environment.systemPackages = with pkgs; [
      fastfetch
      btop
      eza
      bat
      git
      curl
      wget
      tmux
      ripgrep
      fd
      tree
      file
    ];

    # Only for graphical programs on the board: on the serial console and
    # over SSH the font is the one of the terminal at the other end.
    fonts.packages = [ pkgs.nerd-fonts.jetbrains-mono ];

    programs.starship.enable = true;

    # The aliases of the CachyOS shell configuration, minus the pacman ones,
    # with the listing ones as on the author's laptop. The icons of eza come
    # from EZA_ICONS_AUTO, set at login.
    environment.shellAliases = {
      ls = "eza";
      ll = "eza -la --git";
      la = "eza -a";
      lt = "eza --tree --level=2";
      ltt = "eza --tree";
      "l." = "eza -a | grep -e '^\\.'";
      cat = "bat";
      ".." = "cd ..";
      "..." = "cd ../..";
      "...." = "cd ../../..";
      "....." = "cd ../../../..";
      "......" = "cd ../../../../..";
      grep = "grep --color=auto";
      dir = "dir --color=auto";
      vdir = "vdir --color=auto";
      tarnow = "tar -acf ";
      untar = "tar -zxvf ";
      wget = "wget -c ";
      psmem = "ps auxf | sort -nr -k 4";
      psmem10 = "ps auxf | sort -nr -k 4 | head -10";
      jctl = "journalctl -p 3 -xb";
    };

    # Tokyo Night as the 16 colours of the local console (HDMI). A serial or
    # SSH session shows the 16 colours of the terminal at the other end.
    console.colors = [
      "1a1b26"
      "f7768e"
      "9ece6a"
      "e0af68"
      "7aa2f7"
      "bb9af7"
      "7dcfff"
      "a9b1d6"
      "414868"
      "f7768e"
      "9ece6a"
      "e0af68"
      "7aa2f7"
      "bb9af7"
      "7dcfff"
      "c0caf5"
    ];

    # bat has no Tokyo Night theme: this one uses the terminal's 16 colours.
    environment.variables.BAT_THEME = "ansi";

    # Above the login prompt. Plain 16-colour sequences: every serial
    # terminal understands them.
    services.getty.greetingLine = "${esc}[1;34mNixOS ${config.system.nixos.release} on Allwinner A733${esc}[0m (\\m) - \\l";

    # "-": a failure here must never keep the login prompt from starting.
    systemd.services."getty@".serviceConfig.ExecStartPre = "-${slogan}";
    systemd.services."serial-getty@".serviceConfig.ExecStartPre = "-${slogan}";

    environment.etc."xdg/fastfetch/config.jsonc".text = builtins.toJSON {
      logo.color = {
        "1" = blue;
        "2" = magenta;
      };
      display.color = {
        keys = blue;
        title = magenta;
      };
      # A short list: the default one counts the packages in the Nix store,
      # which takes seconds on an SD card.
      modules = [
        "title"
        "separator"
        "os"
        "host"
        "kernel"
        "uptime"
        "cpu"
        "memory"
        "disk"
        "localip"
        "break"
        "colors"
      ];
    };

    environment.loginShellInit = ''
      if [ -t 0 ]; then
        # A serial login starts with TERM=vt220, which turns colours off.
        [ "$TERM" = vt220 ] && export TERM=xterm-256color
        # btop only reads its theme from the user's own configuration.
        [ -e ~/.config/btop/btop.conf ] || install -Dm644 ${btopConf} ~/.config/btop/btop.conf
        [ "$(id -u)" = 0 ] && ${firstLogin}
        # Icons only with a Nerd Font, and never on the local console, which
        # cannot show them.
        if [ "$TERM" != linux ] && grep -qsx yes ${iconsFile}; then
          export EZA_ICONS_AUTO=1
          export STARSHIP_CONFIG=${pkgs.starship}/share/starship/presets/tokyo-night.toml
        else
          export STARSHIP_CONFIG=${pkgs.starship}/share/starship/presets/plain-text-symbols.toml
        fi
        fastfetch
      fi
    '';

    # An expired password: login asks for a new one before it lets root in,
    # and keeps asking at every login until one is set.
    systemd.services.a733-expire-empty-root-password = {
      description = "Make root choose a password at the first login";
      wantedBy = [ "multi-user.target" ];
      before = [ "systemd-user-sessions.service" ];
      serviceConfig.Type = "oneshot";
      path = [
        pkgs.gnugrep
        pkgs.shadow
      ];
      script = ''
        if grep -q '^root::' /etc/shadow; then
          chage -d 0 root
        fi
      '';
    };

    # No SSH while no account has a password. The first login starts it.
    systemd.services.sshd.serviceConfig.ExecCondition =
      lib.mkIf config.services.openssh.enable hasPassword;
  };
}
