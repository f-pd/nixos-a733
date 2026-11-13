// rea decompile_all
// name: FUN_000562dc
// address: 0x562dc
// body: available
// range: 0x562dc-0x563bf inclusive
// range: 0x563c4-0x5667f inclusive
// range: 0x56684-0x56941 inclusive
// range: 0x5694c-0x56d9b inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000562dc(uint *param_1,int param_2)

{
  char cVar1;
  short sVar2;
  char *pcVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint *puVar13;
  uint *puVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  uint local_11c;
  uint local_118;
  uint local_114;
  uint local_110;
  int local_10c;
  uint local_108;
  uint local_104;
  uint local_100;
  uint local_fc;
  uint local_f8;
  uint local_f4;
  uint local_f0;
  uint local_ec;
  uint local_e8;
  uint local_e4;
  uint local_e0;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  uint local_cc;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  uint local_bc;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  int local_a4;
  int local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  int local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  int local_60;
  int local_5c;
  int local_58;
  uint local_50;
  int local_4c;
  uint local_48;
  uint local_44;
  int local_40;
  uint local_3c;
  int local_38;
  uint local_34;
  
  param_2 = param_2 * 0x400000;
  iVar17 = 3;
  puVar13 = (uint *)(param_2 + DAT_000563c0);
  iVar18 = 3;
  uVar20 = param_1[1];
  local_70 = 3;
  local_6c = 3;
  puVar14 = (uint *)(param_2 + DAT_000563c0 + -0x7f0);
  local_e4 = 3;
  local_108 = 8;
  local_e0 = 100;
  local_11c = 0;
  local_74 = 0;
  local_ac = 0;
  local_78 = 0;
  local_b0 = 0xf;
  local_7c = 0xf;
  local_10c = 0x1c;
  local_118 = 2;
  local_34 = 2;
  local_80 = 2;
  local_110 = 4;
  local_b4 = 4;
  local_38 = 0x20;
  local_40 = 8;
  local_3c = 8;
  local_44 = 8;
  local_48 = 2;
  local_84 = 4;
  local_b8 = 4;
  local_e8 = 4;
  local_88 = 3;
  local_bc = 8;
  local_8c = 0x1b;
  local_ec = 0xc;
  uVar5 = 0x3c;
  local_114 = 10;
  local_50 = 100;
  local_4c = 100;
  local_94 = 0x8c;
  local_f0 = 0x80;
  local_c4 = 10;
  local_c0 = 0x62;
  local_104 = 6;
  local_f8 = 0xe;
  local_c8 = 0x10;
  local_9c = 6;
  local_98 = 0x14;
  local_d0 = 2;
  uVar19 = 1;
  local_a0 = 2;
  local_d4 = 0;
  local_fc = 0;
  uVar4 = 10;
  uVar16 = 0;
  local_100 = 3;
  local_f4 = 3;
  local_cc = 3;
  local_a4 = 3;
  local_d8 = 1;
  local_58 = 1;
  local_60 = 0;
  local_5c = 0;
  do {
    if (iVar17 == -1) {
      return;
    }
    if ((param_1[0x1e] & 5) != 5) {
      iVar17 = 0;
    }
    if ((int)(param_1[0x1e] << 0x1d) < 0) {
      if (uVar20 == 8) {
        uVar10 = param_1[0x18];
        uVar16 = *param_1 << 2;
      }
      else {
        if (uVar20 != 9) goto LAB_000563f6;
        uVar10 = param_1[0x18];
        uVar16 = *param_1;
      }
      if (iVar17 == 0) {
        uVar10 = uVar10 & 0x1f;
      }
      else if (iVar17 == 1) {
        uVar10 = (uVar10 & 0x1fff) >> 8;
      }
      else if (iVar17 == 2) {
        uVar10 = (uVar10 & 0x1fffff) >> 0x10;
      }
      else {
        uVar10 = (uVar10 & 0x1fffffff) >> 0x18;
      }
      uVar16 = FUN_00048038(uVar16,uVar10 + 1);
    }
    else if (uVar20 == 8) {
      uVar16 = *param_1;
    }
    else if (uVar20 == 9) {
      uVar16 = *param_1 >> 2;
    }
LAB_000563f6:
    if (uVar20 == 8) {
      uVar4 = FUN_0004b4a8(0x28,uVar16);
      local_c8 = (uint)uVar4;
      uVar4 = FUN_0004b4a8(10,uVar16);
      local_f4 = (uint)uVar4;
      local_cc = local_f4;
      if (local_f4 < 4) {
        local_cc = 4;
      }
      uVar4 = FUN_0004b4a8(0x12,uVar16);
      local_9c = (uint)uVar4;
      if (local_9c < 4) {
        local_9c = 4;
      }
      uVar4 = FUN_0004b4a8(8,uVar16);
      local_c4 = (uint)uVar4;
      if (local_c4 < 5) {
        local_c4 = 5;
      }
      if (local_f4 < 8) {
        local_f4 = 8;
      }
      uVar4 = FUN_0004b4a8(0x15,uVar16);
      local_104 = (uint)uVar4;
      if (local_104 < 4) {
        local_104 = 4;
      }
      uVar4 = FUN_0004b4a8(0x2a,uVar16);
      local_f8 = (uint)uVar4;
      if (local_f8 < 3) {
        local_f8 = 3;
      }
      local_98 = local_f8 + local_104 & 0xffff;
      uVar19 = FUN_0004b4a8(0xf40,uVar16);
      local_c0 = (uVar19 & 0x1fffff) >> 5;
      uVar4 = FUN_0004b4a8(0x17c,uVar16);
      local_f0 = (uint)uVar4;
      uVar4 = FUN_0004b4a8(0x184,uVar16);
      local_110 = (uint)uVar4;
      if (local_110 < 2) {
        local_110 = 2;
      }
      uVar4 = FUN_0004b4a8(0x5a,uVar16);
      local_94 = (uint)uVar4;
      local_a0 = 8;
LAB_000564be:
      uVar4 = FUN_0004b4a8(0xe,uVar16);
      if (uVar4 < 10) {
        uVar4 = 10;
      }
      uVar5 = FUN_0004b4a8(8,uVar16);
      uVar19 = (uint)uVar5;
      local_d0 = uVar19;
      if (uVar19 < 4) {
        local_d0 = 4;
      }
      uVar5 = FUN_0004b4a8(2,uVar16);
      uVar10 = (uint)uVar5;
      local_e4 = uVar10;
      if (uVar10 < 3) {
        local_e4 = 3;
      }
      local_84 = uVar19;
      if (uVar19 < 5) {
        local_84 = 5;
      }
      uVar5 = FUN_0004b4a8(0xf,uVar16);
      local_88 = (uint)uVar5;
      if (local_88 < 4) {
        local_88 = 4;
      }
      local_8c = local_c0 * 0x4800 >> 0x10;
      uVar6 = FUN_0004b4a8(3,uVar16);
      if (uVar16 < 0x42b) {
        local_10c = 0x14;
LAB_00056d4a:
        iVar18 = 4;
      }
      else {
        if (uVar16 < 0x536) {
          local_10c = 0x16;
          goto LAB_00056d4a;
        }
        if (uVar16 < 0x641) {
          iVar18 = 6;
          local_10c = 0x18;
        }
        else if (uVar16 < 0x74b) {
          iVar18 = 6;
          local_10c = 0x1a;
        }
        else {
          iVar18 = 8;
          local_10c = 0x1c;
        }
      }
      uVar5 = FUN_0004b4a8(0x28,uVar16);
      if (uVar5 < 8) {
        uVar5 = 8;
      }
      uVar7 = FUN_0004b4a8(1000,uVar16);
      local_e0 = (uint)uVar7;
      uVar7 = FUN_0004b4a8(0x1e,uVar16);
      local_108 = (uint)uVar7;
      if (local_108 < 8) {
        local_108 = 8;
      }
      uVar7 = FUN_0004b4a8(0x32,uVar16);
      local_70 = (uint)uVar7;
      *(undefined1 *)(DAT_00056680 + 8) = 0x24;
      if (local_70 < 3) {
        local_70 = 3;
      }
      if (uVar19 < 8) {
        uVar19 = 8;
      }
      param_1[9] = param_1[9] | 0x74;
      param_1[10] = param_1[10] & 0xffffff80 | 0x3f;
      local_e8 = ((uVar6 + 0x34) - uVar10) - iVar18 & 0xffff;
      local_bc = local_f4 + 0x1b & 0xffff;
      local_fc = uVar6 + 0x36 + uVar19 & 0xffff;
      local_d4 = uVar19 + 0x43 & 0xffff;
      local_78 = (iVar18 + local_10c) - 7U & 0xffff;
      uVar19 = 0xe;
      local_ac = uVar10 + 7 & 0xffff;
      iVar18 = FUN_0004b4a8(1,uVar16);
      local_11c = 9U - iVar18 & 0xffff;
      iVar18 = 0x24;
      if (local_11c < 4) {
        local_11c = 4;
      }
      local_b4 = 4;
      local_ec = 0x43;
      local_100 = 0x10;
      local_a4 = 0x12;
      local_d8 = 0x1f;
      local_b8 = local_e4;
      local_74 = local_fc;
    }
    else if (uVar20 == 9) {
      iVar15 = *(int *)(DAT_00056944 + 4);
      if (iVar15 == 0) {
        local_a0 = 4;
      }
      else {
        local_a0 = 2;
      }
      uVar5 = FUN_0004b4a8(0x14,uVar16);
      local_c8 = (uint)uVar5;
      uVar5 = FUN_0004b4a8(5,uVar16);
      local_84 = (uint)uVar5;
      local_cc = local_84;
      if (local_84 < 2) {
        local_cc = 2;
      }
      uVar5 = FUN_0004b4a8(0x12,uVar16);
      local_9c = (uint)uVar5;
      if (local_9c < 2) {
        local_9c = 2;
      }
      uVar19 = FUN_0004b4a8(7,uVar16);
      uVar10 = param_1[0x1b];
      uVar19 = uVar19 & 0xffff;
      local_c4 = uVar19;
      if (uVar19 < 3) {
        local_c4 = 3;
      }
      if ((int)uVar10 < 0) {
        uVar8 = 0xe;
      }
      else {
        uVar8 = 0xc;
      }
      uVar5 = FUN_0004b4a8(uVar8,uVar16);
      if (iVar15 != 0) {
        uVar5 = FUN_0004b4a8(0xe,uVar16);
      }
      local_f4 = (uint)uVar5;
      if (local_f4 < 4) {
        local_f4 = 4;
      }
      uVar6 = FUN_0004b4a8(8,uVar16);
      local_114 = (uint)uVar6;
      local_118 = local_114;
      if (local_114 < 2) {
        local_118 = 2;
      }
      if (iVar15 == 0) {
        local_100 = local_118;
      }
      else {
        local_100 = local_118 + 2 & 0xffff;
      }
      uVar5 = FUN_0004b4a8(0x15,uVar16);
      local_104 = (uint)uVar5;
      if (local_104 < 2) {
        local_104 = 2;
      }
      uVar5 = FUN_0004b4a8(0x2a,uVar16);
      local_f8 = (uint)uVar5;
      if (local_f8 < 3) {
        local_f8 = 3;
      }
      local_98 = local_f8 + local_104 & 0xffff;
      uVar12 = FUN_0004b4a8(0xf42,uVar16);
      local_c0 = uVar12 >> 5 & 0xffff;
      uVar5 = FUN_0004b4a8(0x17c,uVar16);
      local_f0 = (uint)uVar5;
      local_110 = local_f0 + local_118 & 0xffff;
      uVar5 = FUN_0004b4a8(DAT_00056948,uVar16);
      uVar9 = uVar5 & 0x3ff;
      if ((uVar5 & 0x3ff) != 0) {
        uVar9 = 1;
      }
      local_4c = uVar9 + (uVar5 >> 10);
      uVar5 = FUN_0004b4a8(0x104,uVar16);
      local_50 = (uint)uVar5;
      uVar5 = FUN_0004b4a8(0x5a,uVar16);
      local_94 = (uint)uVar5;
      uVar5 = FUN_0004b4a8(3,uVar16);
      local_80 = (uint)uVar5;
      local_48 = local_cc + 1 & 0xffff;
      uVar19 = uVar19 & ~((int)uVar10 >> 0x20);
      if ((int)uVar10 < 0) {
        uVar19 = local_114;
      }
      if (uVar19 < 4) {
        uVar19 = 4;
      }
      iVar18 = FUN_0004b4a8(10,uVar16);
      local_d0 = iVar18 + 1U & 0xffff;
      if (iVar15 == 0) {
        local_38 = 0x10;
      }
      else {
        local_38 = 8;
      }
      if (local_84 < 3) {
        local_84 = 3;
      }
      uVar5 = FUN_0004b4a8(0xf,uVar16);
      local_88 = (uint)uVar5;
      if (local_88 < 2) {
        local_88 = 2;
      }
      local_8c = (uVar12 >> 5 & 0xffff) * 9 >> 5;
      uVar12 = FUN_0004b4a8(1,uVar16);
      uVar5 = FUN_0004b4a8(0x28,uVar16);
      if (uVar5 < 8) {
        uVar5 = 8;
      }
      iVar18 = FUN_0004b4a8(6000,uVar16);
      local_e0 = iVar18 + 10U & 0xffff;
      uVar7 = FUN_0004b4a8(0x1e,uVar16);
      local_6c = (uint)uVar7;
      local_108 = local_6c;
      if (local_6c < 4) {
        local_108 = 4;
      }
      uVar7 = FUN_0004b4a8(0x32,uVar16);
      local_70 = (uint)uVar7;
      if (local_70 < 3) {
        local_70 = 3;
      }
      if (-1 < (int)uVar10) {
        iVar18 = 0xd;
      }
      else {
        iVar18 = 0xe;
      }
      *(char *)(DAT_00056944 + 8) = (char)iVar18;
      if (-1 < (int)uVar10) {
        iVar11 = 0x15;
      }
      else {
        iVar11 = 0x16;
      }
      local_d8 = iVar18 * 4 - 5U & 0xffff;
      param_1[9] = param_1[9] | 0x80;
      param_1[10] = param_1[10] | 0x88;
      if (iVar15 == 0) {
        local_bc = local_f4 + 0xb;
        local_e8 = iVar18 + 3;
      }
      else {
        param_1[0xb] = param_1[0xb] & 0xffffffe7 | 0x10;
        local_e8 = iVar18 - 3U & 0xffff;
        local_bc = local_f4 + 9;
      }
      local_ec = iVar11 + 10;
      local_7c = iVar18 + 3;
      local_bc = local_bc & 0xffff;
      local_44 = uVar19 + 9 & 0xffff;
      local_11c = local_c8 + 0xb + iVar18 & 0xffff;
      if (iVar15 == 0) {
        local_7c = iVar18 + 5;
        local_b0 = 0xc;
      }
      else {
        local_b0 = 10;
      }
      local_40 = iVar18 + 1;
      if (local_114 < 4) {
        uVar6 = 4;
      }
      sVar2 = (short)local_100 + uVar6 + (short)iVar18;
      if (iVar15 == 0) {
        uVar7 = sVar2 + 6;
      }
      else {
        uVar7 = sVar2 + 4;
      }
      local_fc = (uint)uVar7;
      sVar2 = uVar6 + 7 + (short)iVar11;
      if (iVar15 == 0) {
        uVar6 = sVar2 + 4;
      }
      else {
        uVar6 = sVar2 + 2;
      }
      local_d4 = (uint)uVar6;
      uVar10 = (uVar12 & 0xffff) >> 2;
      local_78 = local_80 + 7 & 0xffff;
      uVar19 = 0x17;
      local_ac = uVar10 + 0xb;
      local_74 = uVar10 + 2 + local_e8 & 0xffff;
      local_10c = 10;
      local_b4 = 2;
      local_e4 = 3;
      local_b8 = 2;
      local_a4 = 7;
      local_5c = 3;
      local_58 = 3;
      local_60 = 5;
      local_3c = local_ec;
      local_34 = local_d0;
    }
    else if (uVar20 == 8) goto LAB_000564be;
    iVar15 = iVar17 * 0x100000 + param_2;
    *(uint *)(iVar15 + 0xa100000) = local_f8 | local_c8 << 0x10 | local_ec << 0x18 | local_8c << 8;
    *(uint *)(iVar15 + 0xa100004) = local_98 | local_c4 << 0x10 | local_100 << 8;
    *(uint *)(iVar15 + 0xa100008) = iVar18 << 0x10 | local_a4 << 0x18 | local_bc | local_e8 << 8;
    *(uint *)(iVar15 + 0xa10000c) = local_fc << 8 | (uint)uVar4 << 0x10 | local_d4;
    *(uint *)(iVar15 + 0xa100010) = local_a0 << 0x10 | local_9c << 0x18 | local_104 | local_cc << 8;
    *(uint *)(iVar15 + 0xa100014) = local_84 << 0x10 | local_b8 << 0x18 | local_d0 | local_88 << 8;
    *(uint *)(iVar15 + 0xa100018) = local_c4 + 2;
    *(uint *)(iVar15 + 0xa10001c) = local_80;
    *(uint *)(iVar15 + 0xa100024) = local_44 | 0x20000 | local_48 << 8;
    *(uint *)(iVar15 + 0xa100030) = local_e4 << 0x10;
    *(uint *)(iVar15 + 0xa100034) = local_b4 | local_38 << 0x10 | local_10c << 0x18;
    *(uint *)(iVar15 + 0xa100038) = local_110 | (uint)uVar5 << 0x10;
    *(uint *)(iVar15 + 0xa10005c) = local_34 | local_4c << 0x10;
    uVar10 = local_b0;
    if (uVar20 == 9) {
      uVar10 = local_3c;
    }
    *(uint *)(iVar15 + 0xa100060) = local_7c << 8 | local_40 << 0x10 | local_b0;
    pcVar3 = DAT_00056d9c;
    if (uVar20 == 9) {
      uVar12 = local_118;
    }
    else {
      uVar12 = local_100 | 0x20000;
      uVar10 = local_ec;
    }
    *(uint *)(iVar15 + 0xa100064) = uVar12 | uVar10 << 8;
    *(undefined4 *)(iVar15 + 0xa100078) = DAT_00056da0;
    *(undefined4 *)(iVar15 + 0xa100080) = 0;
    cVar1 = *pcVar3;
    if (cVar1 == '\0') {
      uVar10 = *(uint *)(iVar15 + 0xa100d00) | 1;
    }
    else {
      uVar10 = *(uint *)(iVar15 + 0xa100d00) & 0xfffffffe;
    }
    *(uint *)(iVar15 + 0xa100d00) = uVar10;
    if (iVar17 == 0) {
      uVar10 = *puVar13;
      if (uVar20 == 9) {
        uVar10 = uVar10 & 0x3fffffff;
      }
      if (uVar20 == 9) {
        uVar10 = uVar10 | 0x40000000;
      }
      if (*DAT_00056da4 != 0) {
        uVar10 = uVar10 | 0xc0000000;
      }
      uVar12 = FUN_0004b4a8(2000,uVar16 >> 2);
      uVar9 = FUN_0004b4a8(DAT_00056da8,uVar16 >> 2);
      *puVar13 = (uVar9 >> 10) + 1 & 0xffff | uVar10 & 0xfc00e000 | ((uVar12 >> 10) + 1) * 0x10000;
      *puVar14 = *puVar14 & 0xfffffffe;
    }
    if (uVar20 == 8) {
      *(uint *)(iVar15 + 0xa100500) = param_1[10] | param_1[9] << 0x10;
      *(uint *)(iVar15 + 0xa100504) = param_1[0x11] | param_1[0xb] << 0x10;
      *(uint *)(iVar15 + 0xa100508) = param_1[0x10] | param_1[0xf] << 0x10;
      if ((param_1[0x1b] & 0x20000000) == 0) {
        uVar10 = (uint)(byte)param_1[0x32];
      }
      else {
        uVar10 = param_1[0x12];
      }
      *(uint *)(iVar15 + 0xa10050c) = uVar10 | param_1[0x15] << 0x10;
    }
    uVar10 = *(uint *)(iVar15 + 0xa100d04) & 0xffff0000;
    if (uVar20 == 9) {
      uVar10 = local_ac | uVar10 | local_78 << 8;
    }
    else {
      uVar10 = local_ac + 0x10 | local_78 << 8 | uVar10;
    }
    *(uint *)(iVar15 + 0xa100d04) = uVar10;
    *(uint *)(iVar15 + 0xa100d08) =
         *(uint *)(iVar15 + 0xa100d08) & 0xffff0000 | local_11c | local_74 << 8;
    *(undefined4 *)(iVar15 + 0xa100d0c) = DAT_00056dac;
    if (uVar20 == 9) {
      *(undefined4 *)(iVar15 + 0xa1005a0) = DAT_00056db0;
      *(undefined4 *)(iVar15 + 0xa1005a4) = 0x201;
      *(undefined4 *)(iVar15 + 0xa1005a8) = DAT_00056db4;
      *(undefined4 *)(iVar15 + 0xa1005ac) = DAT_00056db8;
      *(undefined4 *)(iVar15 + 0xa1005b0) = 0x97;
      *(undefined4 *)(iVar15 + 0xa1005b8) = 0x147;
      uVar10 = uVar19 | 0x3000000;
LAB_00056c10:
      uVar10 = uVar10 | 0x200;
    }
    else {
      if (cVar1 != '\0') {
        uVar10 = uVar19 | 0x4000000;
        goto LAB_00056c10;
      }
      uVar10 = uVar19 | 0x2000200;
    }
    *(uint *)(iVar15 + 0xa100580) = uVar10 | local_d8 << 0x10;
    if (uVar20 == 9) {
      uVar8 = DAT_00056dd4;
    }
    else {
      uVar8 = DAT_00056dbc;
      if (cVar1 != '\0') {
        uVar8 = DAT_00056dc0;
      }
    }
    *(undefined4 *)(iVar15 + 0xa100584) = uVar8;
    if (uVar20 == 9) {
      uVar10 = uVar19 | 0x180000;
    }
    else if (cVar1 == '\0') {
      uVar10 = uVar19 | 0x1f0000;
    }
    else {
      uVar10 = uVar19 | 0x3e0000;
    }
    *(uint *)(iVar15 + 0xa100588) = local_d8 << 8 | uVar10;
    *(uint *)(iVar15 + 0xa100590) = (local_5c + -1) * 0x40000 | (local_60 + -1) * 0x4000000 | 0x411;
    *(uint *)(iVar15 + 0xa100594) = DAT_00056dc4 | local_58 << 0x12;
    *(uint *)(iVar15 + 0xa100600) = DAT_00056dc8 & *(uint *)(iVar15 + 0xa100600) | local_c0;
    *(uint *)(iVar15 + 0xa100604) =
         *(uint *)(iVar15 + 0xa100604) & 0xf000f000 | local_f0 | local_f0 << 0x10;
    *(uint *)(iVar15 + 0xa100608) =
         local_94 << 0x10 | local_114 << 0x18 | *(uint *)(iVar15 + 0xa100608) & 0xffff;
    *(uint *)(iVar15 + 0xa100650) = *(uint *)(iVar15 + 0xa100650) & 0xfffff000 | local_50;
    *(uint *)(iVar15 + 0xa100800) = local_e0 | local_108 << 0x10;
    *(uint *)(iVar15 + 0xa100804) = local_70 << 0x14 | 0x100;
    if (uVar20 == 9) {
      *(uint *)(iVar15 + 0xa100808) = local_6c;
      *(undefined4 *)(iVar15 + 0xa100a80) = 0x1f74;
      *(undefined4 *)(iVar15 + 0xa100b00) = DAT_00056dcc;
      *(undefined4 *)(iVar15 + 0xa100b04) = DAT_00056dd0;
      *(undefined4 *)(iVar15 + 0xa100b08) = 0x33;
      *(undefined4 *)(iVar15 + 0xa100b80) = 0x170000;
    }
    iVar17 = iVar17 + -1;
    FUN_00048d80(0x14);
  } while( true );
}

