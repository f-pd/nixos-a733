# A friendly first contact: above the login prompt the NixOS snowflake in
# the colours of the pride flag (they turn around it each time the prompt
# appears, and stop where they stay) with the system in short beside it,
# then the hardware, the versions of what is installed, the network, the
# services, the first boot instructions, refreshed while the prompt waits.
# After the login the snowflake again (serial console, local console and
# SSH). Also Tokyo Night colours, the starship prompt, the usual comfort
# tools and aliases, and a guided first login.
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

  # Declared in hardware.nix; "or" keeps this module usable without it.
  hw = config.hardware.a733;
  hwComponents = hw.components or { };
  hwDrivers = hw.drivers or [ ];
  hwUboot = hw.ubootVersion or null;

  components = pkgs.writeText "a733-components" (
    lib.concatStrings (lib.mapAttrsToList (name: version: "${name}=${version}\n") hwComponents)
  );

  # The welcome screen itself: modules/welcome-info.sh.
  info = pkgs.writeShellApplication {
    name = "a733-info";
    runtimeInputs = with pkgs; [
      coreutils
      gawk
      gnugrep
      gnused
      util-linux
      iproute2
      iw
      procps
      config.systemd.package
    ];
    text = ''
      COMPONENTS=${components}
      SLOGANS=${slogans}
      NIXOS_VERSION=${lib.escapeShellArg "${config.system.nixos.version} (${config.system.nixos.codeName})"}
      NIXOS_RELEASE=${lib.escapeShellArg "NixOS ${config.system.nixos.release} (${config.system.nixos.codeName})"}
      PROMPT_COLOURS=${cfg.promptColours}
      MODULES=${lib.escapeShellArg (toString hwDrivers)}
      BLOB_OFFSETS=${lib.escapeShellArg (toString (map (b: b.offsetKiB) (hw.sdImage.bootBlobs or [ ])))}
      UBOOT_BUILT=${lib.escapeShellArg (if hwUboot == null then "" else hwUboot)}
      CACHE=/run/a733-welcome
    ''
    + builtins.readFile ./welcome-info.sh;
  };

  issueFile = "/run/issue.d/a733-welcome.issue";

  # Write the issue file again; with "reload", make the waiting login prompts
  # show it if it changed.
  writeIssue = pkgs.writeShellScript "a733-issue" ''
    PATH=${pkgs.coreutils}/bin:${pkgs.diffutils}/bin:${pkgs.util-linux}/bin
    mkdir -p ${dirOf issueFile}
    # The slogan file of 0.3.0, until the next reboot empties /run.
    rm -f ${dirOf issueFile}/a733-slogan.issue
    # agetty only reads the files ending in .issue.
    new=$(mktemp ${issueFile}.XXXXXX) || exit 0
    if ! ${lib.getExe info} --issue > "$new"; then
      rm -f "$new"
      exit 0
    fi
    if cmp -s "$new" ${issueFile}; then
      rm -f "$new"
    else
      chmod 644 "$new"
      mv "$new" ${issueFile}
      [ "$1" = reload ] && agetty --reload
    fi
    exit 0
  '';

  # Before each login prompt: the screen, then the logo animation on that
  # terminal. Bounded in time: the prompt must come whatever happens.
  beforePrompt = pkgs.writeShellScript "a733-before-prompt" ''
    ${lib.getExe info} --new-slogan
    ${pkgs.coreutils}/bin/timeout 20 ${writeIssue}
    ${lib.optionalString cfg.animation "${pkgs.coreutils}/bin/timeout 10 ${lib.getExe info} --intro /dev/$1"}
    exit 0
  '';

  btopConf = pkgs.writeText "btop.conf" ''
    color_theme = "tokyo-night"
  '';
in
{
  options.hardware.a733.welcome = {
    enable = lib.mkEnableOption ''
      a welcome screen above the login prompt (pride snowflake, hardware,
      versions, network, services, first boot instructions), the snowflake
      after it, Tokyo Night colours, the starship prompt, comfort
      tools and aliases, and a guided first login that sets the root password
      and creates the main user
    '';

    promptColours = lib.mkOption {
      type = lib.types.enum [
        "16"
        "256"
        "truecolor"
      ];
      default = "256";
      description = ''
        Colours of the snowflake above the login prompt, where the terminal
        at the other end of the serial line is not known. 256 colours give
        the pride flag; terminals that lack them show the snowflake without
        colours. "16" works everywhere, with cyan in place of orange.
      '';
    };

    animation = lib.mkOption {
      type = lib.types.bool;
      default = true;
      description = ''
        Turn the colours around the snowflake before the login prompt and
        after each interactive login. Off, the snowflake stays still.
      '';
    };
  };

  config = lib.mkIf cfg.enable {
    environment.systemPackages = with pkgs; [
      info
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

    # Everything above the login prompt comes from ${issueFile}. The
    # default /etc/issue points to nixos-help, and documentation is off in
    # the generic images.
    environment.etc.issue = lib.mkForce { text = ""; };

    # "-": a failure here must never keep the login prompt from starting.
    systemd.services."getty@".serviceConfig.ExecStartPre = "-${beforePrompt} %I";
    systemd.services."serial-getty@".serviceConfig.ExecStartPre = "-${beforePrompt} %I";

    # The screen changes while the prompt waits: the network comes up,
    # services start, the first login is done over SSH.
    systemd.services.a733-welcome-refresh = {
      description = "Refresh the welcome screen above the login prompts";
      serviceConfig = {
        Type = "oneshot";
        ExecStart = "${pkgs.coreutils}/bin/timeout 20 ${writeIssue} reload";
      };
    };
    systemd.timers.a733-welcome-refresh = {
      wantedBy = [ "timers.target" ];
      timerConfig = {
        OnBootSec = "20s";
        OnUnitActiveSec = "30s";
      };
    };

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
        "gpu"
        "memory"
        "swap"
        "disk"
        "localip"
        "wifi"
        "users"
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
        ${if cfg.animation then "a733-info --logo" else "a733-info --logo-still"}
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
