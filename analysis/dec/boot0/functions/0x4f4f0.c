// rea decompile_all
// name: FUN_0004f4f0
// address: 0x4f4f0
// body: available
// range: 0x4f4f0-0x4f4fd inclusive
// range: 0x58ba8-0x58e3b inclusive
// range: 0x58eac-0x59067 inclusive
// range: 0x59d00-0x59dfd inclusive
// range: 0x59e28-0x5a0cb inclusive
// range: 0x5a15c-0x5a1bf inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0004f4f0(uint param_1,uint *param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  short *psVar12;
  int iVar13;
  int iVar14;
  ushort *puVar15;
  ushort uVar16;
  ushort *puVar17;
  uint uVar18;
  uint uVar19;
  undefined2 *puVar20;
  ushort *puVar21;
  undefined2 uVar22;
  undefined2 uVar23;
  undefined2 *puVar24;
  undefined2 *puVar25;
  uint uVar26;
  uint uVar27;
  ushort *puVar28;
  short *psVar30;
  short *psVar29;
  undefined2 *puVar31;
  uint uVar32;
  ushort uVar33;
  uint uVar34;
  
  if (param_2[1] != 8) {
    uVar32 = (*param_2 & 0x7fff) << 1;
    if ((int)(param_2[0x1e] << 0x1d) < 0) {
      uVar16 = FUN_00048038((*param_2 & 0x7fff) << 3,
                            (param_2[0x18] >> ((param_1 & 0x1f) << 3) & 0x1f) + 1);
      uVar32 = (uint)uVar16;
    }
    uVar22 = (undefined2)uVar32;
    if (uVar32 < 0x640) {
      uVar22 = 0x640;
    }
    *DAT_00059e00 = 0;
    thunk_FUN_00048d80(1);
    puVar25 = DAT_00059e04;
    *DAT_00059e04 = 0;
    puVar25[1] = 0;
    uVar34 = param_2[0x1e];
    uVar32 = uVar34 & 4;
    if (uVar32 == 0) {
      uVar23 = 0x30;
LAB_00059d56:
      *DAT_00059e08 = uVar23;
    }
    else {
      if (param_1 == 0) {
        uVar23 = 0xa0;
        goto LAB_00059d56;
      }
      if (param_1 == 1) {
        uVar23 = 0x91;
        goto LAB_00059d56;
      }
      if (param_1 == 2) {
        uVar23 = 0x82;
        goto LAB_00059d56;
      }
      if (param_1 == 3) {
        uVar23 = 0x83;
        goto LAB_00059d56;
      }
    }
    puVar25 = DAT_00059e10;
    *DAT_00059e0c = uVar22;
    *puVar25 = 4;
    puVar25[1] = 4;
    puVar25[2] = 0;
    puVar25[3] = 0;
    uVar19 = param_2[0x1b];
    uVar26 = uVar19 & 0x1fffffff;
    if (uVar26 >> 0x10 == 0) {
      *DAT_00059e14 = 799;
      param_2[0x1b] = uVar19 | 0x31f0000;
    }
    else {
      *DAT_00059e14 = (short)(uVar26 >> 0x10);
    }
    uVar26 = param_2[0x1b];
    *DAT_00059e18 = 0xff;
    puVar25 = DAT_00059e1c;
    uVar22 = 0;
    *DAT_00059e1c = 0;
    puVar25[1] = 2;
    puVar25[2] = 0;
    puVar25[3] = 0;
    if ((int)uVar26 < 0) {
      uVar22 = 0xf;
    }
    puVar25[4] = uVar22;
    puVar25 = DAT_00059e20;
    *DAT_00059e20 = 0;
    puVar25[1] = 0;
    puVar25[2] = 0;
    uVar19 = param_2[7] & 0x1000;
    if ((param_2[7] & 1) == 0) {
      if (uVar19 == 0) {
        uVar22 = 0x120;
      }
      else {
        uVar22 = 800;
      }
    }
    else if (uVar19 == 0) {
      uVar22 = 0x110;
    }
    else {
      uVar22 = 0x310;
    }
    *DAT_00059e24 = uVar22;
    puVar25 = DAT_0005a0d0;
    puVar20 = DAT_0005a0cc;
    do {
      puVar31 = puVar20 + 1;
      *puVar20 = 0;
      puVar24 = DAT_0005a0d4;
      puVar20 = puVar31;
    } while (puVar31 != puVar25);
    if ((uVar34 & 0x40) == 0) {
      *puVar31 = 0;
      uVar22 = 0;
    }
    else {
      *puVar31 = 0x1000;
      if (uVar19 == 0) {
        uVar22 = 1;
      }
      else {
        uVar22 = 3;
      }
    }
    *puVar24 = uVar22;
    puVar17 = DAT_0005a0dc;
    puVar21 = DAT_0005a0d8;
    do {
      puVar28 = puVar21 + 1;
      *puVar21 = 0;
      puVar21 = puVar28;
    } while (puVar28 != puVar17);
    uVar16 = (ushort)param_2[9] | (ushort)param_2[9] << 8;
    *puVar28 = uVar16;
    puVar17 = DAT_0005a0e0;
    *DAT_0005a0e0 = uVar16;
    uVar16 = (ushort)param_2[10] | (ushort)param_2[10] << 8;
    puVar17[1] = uVar16;
    puVar17[2] = uVar16;
    uVar16 = (ushort)param_2[0xb] | (ushort)param_2[0xb] << 8;
    puVar17[3] = uVar16;
    puVar17[4] = uVar16;
    puVar17[5] = 0x5454;
    puVar17[6] = 0x5454;
    uVar16 = (ushort)param_2[0xf] | (ushort)param_2[0xf] << 8;
    puVar17[7] = uVar16;
    puVar17[8] = uVar16;
    uVar16 = (ushort)param_2[0x10] | (ushort)param_2[0x10] << 8;
    puVar17[9] = uVar16;
    puVar17[10] = uVar16;
    uVar16 = (ushort)param_2[0x11] | (ushort)param_2[0x11] << 8;
    puVar17[0xb] = uVar16;
    puVar17[0xc] = uVar16;
    puVar15 = DAT_0005a1cc;
    puVar28 = DAT_0005a1c8;
    puVar21 = DAT_0005a1c4;
    puVar17 = DAT_0005a0e4;
    uVar34 = uVar26 & 0x20000000;
    if ((int)param_2[0x17] < 0) {
      if ((uVar34 == 0) && ((uVar32 == 0 || (param_1 == 0)))) {
        uVar19 = param_2[0x32];
        uVar2 = (ushort)uVar19;
        *DAT_0005a1d0 = uVar2;
        uVar16 = (ushort)(uVar19 >> 0x10);
        *puVar21 = uVar16;
        if ((int)uVar26 < 0) {
          *puVar28 = uVar2;
        }
        else {
          uVar16 = (ushort)(param_2[0x33] >> 0x10);
          *puVar28 = (ushort)param_2[0x33];
        }
      }
      else {
        uVar16 = (ushort)param_2[0x12] | (ushort)param_2[0x12] << 8;
        *DAT_0005a1d0 = uVar16;
        *puVar21 = uVar16;
        *puVar28 = uVar16;
      }
      *puVar15 = uVar16;
    }
    else if (uVar34 != 0) {
      uVar16 = (ushort)param_2[0x12] | (ushort)param_2[0x12] << 8;
      *DAT_0005a0e4 = uVar16;
      puVar17[1] = uVar16;
      puVar17[2] = uVar16;
      puVar17[3] = uVar16;
    }
    puVar21 = DAT_0005a0ec;
    puVar17 = DAT_0005a0e8;
    uVar16 = (ushort)param_2[0x13] | (ushort)param_2[0x13] << 8;
    puVar28 = DAT_0005a0ec + 0x1a;
    *DAT_0005a0e8 = uVar16;
    puVar17[1] = uVar16;
    puVar17 = DAT_0005a0f0;
    uVar16 = (ushort)param_2[0x14] | 0x2800 | (ushort)param_2[0x14] << 8;
    *DAT_0005a0f0 = uVar16;
    puVar17[1] = uVar16;
    puVar17[2] = 0x1c1c;
    puVar17[3] = 0x1c1c;
    puVar17[4] = 0x1010;
    puVar17[5] = 0x1010;
    puVar17[6] = 0x202;
    puVar17[7] = 0x202;
    puVar17[8] = 0;
    puVar17[9] = 0;
    uVar16 = (ushort)param_2[0x15] | (ushort)param_2[0x15] << 8;
    *puVar21 = uVar16;
    puVar21[1] = uVar16;
    puVar25 = DAT_0005a0f4;
    *DAT_0005a0f4 = 0;
    puVar25[1] = 0;
    puVar25[2] = 0;
    puVar25[3] = 0;
    puVar25[4] = 0;
    puVar25[5] = 0;
    puVar25[6] = 0;
    puVar25[7] = 0;
    puVar21[10] = 0x404;
    puVar21[0xb] = 0x404;
    puVar17 = DAT_0005a0f8;
    do {
      puVar21 = puVar17 + 1;
      *puVar17 = 0;
      puVar17 = puVar21;
    } while (puVar21 != puVar28);
    *puVar21 = 0x6060;
    *DAT_0005a0fc = 0x6060;
    if (uVar34 == 0) {
LAB_0005a0c6:
      *DAT_0005a100 = 1;
    }
    else if (uVar32 == 0) {
      *DAT_0005a100 = 0;
    }
    else {
      if (param_1 != 0) goto LAB_0005a0c6;
      *DAT_0005a100 = 0;
    }
    puVar25 = DAT_0005a108;
    puVar20 = DAT_0005a104;
    do {
      puVar24 = puVar20 + 1;
      *puVar20 = 0;
      puVar20 = puVar24;
    } while (puVar24 != puVar25);
    *puVar24 = 0x2e;
    puVar25 = DAT_0005a10c;
    *DAT_0005a10c = 0x50;
    puVar25[1] = 0;
    puVar25[2] = 0;
    puVar20 = DAT_0005a1c0;
    if (uVar32 == 0) {
      *DAT_0005a1c0 = 0;
      uVar22 = 0;
    }
    else {
      if (param_1 == 0) {
        puVar25[3] = 0x58;
        puVar25[4] = 0x287;
        goto LAB_00059fb8;
      }
      if (param_1 == 1) {
        *DAT_0005a1c0 = 0x458;
        uVar22 = 0x687;
      }
      else if (param_1 == 2) {
        *DAT_0005a1c0 = 0x858;
        uVar22 = 0xa87;
      }
      else {
        if (param_1 != 3) goto LAB_00059fb8;
        *DAT_0005a1c0 = 0xc58;
        uVar22 = 0xe87;
      }
    }
    puVar20[1] = uVar22;
LAB_00059fb8:
    psVar12 = DAT_0005a114;
    puVar25 = DAT_0005a110;
    *DAT_0005a110 = 0;
    puVar25[1] = 0;
    puVar25[2] = 0;
    puVar25[3] = 0;
    puVar25[4] = 0;
    puVar25[5] = 0;
    *DAT_0005a118 = 0xf01;
    bVar1 = *DAT_0005a11c;
    *psVar12 = ((ushort)bVar1 * 4 + -1) * 0x100;
    psVar12 = DAT_0005a120;
    *DAT_0005a120 = (ushort)bVar1 * 4 + -5;
    psVar29 = DAT_0005a124;
    do {
      psVar30 = psVar29 + 1;
      *psVar29 = 0;
      psVar29 = psVar30;
    } while (psVar30 != psVar12 + 0x182);
    *psVar30 = 0x500;
    puVar25 = DAT_0005a12c;
    puVar20 = DAT_0005a128;
    do {
      puVar24 = puVar20 + 1;
      *puVar20 = 0;
      puVar20 = puVar24;
    } while (puVar24 != puVar25);
    *puVar24 = 0x715d;
    puVar25 = DAT_0005a130;
    *DAT_0005a130 = 0xce;
    puVar20 = DAT_0005a134;
    puVar25 = puVar25 + 1;
    do {
      puVar31 = puVar25 + 1;
      *puVar25 = 0;
      puVar24 = DAT_0005a138;
      puVar25 = puVar31;
    } while (puVar31 != puVar20);
    *puVar31 = 4;
    puVar25 = DAT_0005a13c;
    do {
      puVar20 = puVar25 + 1;
      *puVar25 = 0;
      iVar13 = DAT_0005a140;
      puVar25 = puVar20;
    } while (puVar20 != puVar24);
    *puVar20 = 4;
    puVar20 = DAT_0005a14c;
    iVar14 = DAT_0005a148;
    puVar25 = DAT_0005a144;
    *DAT_0005a144 = 0;
    puVar25[1] = 0;
    puVar25[2] = 0;
    puVar25[3] = 0;
    puVar25[4] = 0;
    puVar25[5] = 0;
    puVar25[6] = 0;
    puVar25 = DAT_0005a150;
    do {
      puVar31 = puVar25 + 1;
      *puVar25 = *(undefined2 *)(iVar13 + ((int)puVar25 + iVar14 >> 1) * 2);
      puVar24 = DAT_0005a154;
      puVar25 = puVar31;
    } while (puVar31 != puVar20);
    do {
      puVar25 = puVar31 + 1;
      *puVar31 = 0;
      puVar31 = puVar25;
    } while (puVar25 != puVar24);
    *DAT_0005a158 = 1;
    return;
  }
  uVar32 = (*param_2 & 0x7fff) << 1;
  if ((int)(param_2[0x1e] << 0x1d) < 0) {
    uVar16 = FUN_00048038((*param_2 & 0x7fff) << 3,
                          (param_2[0x18] >> ((param_1 & 0x1f) << 3) & 0x1f) + 1);
    uVar32 = (uint)uVar16;
  }
  uVar22 = (undefined2)uVar32;
  if (uVar32 < 0x640) {
    uVar22 = 0x640;
  }
  *DAT_00058e3c = 0;
  thunk_FUN_00048d80(1);
  puVar25 = DAT_00058e40;
  uVar32 = param_2[0x1e];
  *DAT_00058e40 = 0;
  puVar25[1] = 0;
  if ((uVar32 & 4) == 0) {
    uVar23 = 0x30;
LAB_00058cdc:
    *DAT_00058e7c = uVar23;
  }
  else {
    if (param_1 != 0) {
      if (param_1 == 1) {
        uVar23 = 0x91;
      }
      else if (param_1 == 2) {
        uVar23 = 0x82;
      }
      else {
        if (param_1 != 3) goto LAB_00058c06;
        uVar23 = 0x83;
      }
      goto LAB_00058cdc;
    }
    puVar25[2] = 0xa0;
  }
LAB_00058c06:
  *DAT_00058e44 = uVar22;
  if (*DAT_00058e48 == '\0') {
    uVar22 = 4;
  }
  else {
    uVar22 = 2;
  }
  *DAT_00058e4c = uVar22;
  puVar25 = DAT_00058e54;
  *DAT_00058e50 = 4;
  puVar20 = DAT_00058e58;
  *DAT_00058e58 = 0;
  puVar20[1] = 0;
  uVar26 = param_2[0x1b];
  uVar34 = uVar26 & 0x1fffffff;
  if (uVar34 >> 0x10 == 0) {
    *puVar25 = 799;
    param_2[0x1b] = uVar26 | 0x21f0000;
  }
  else {
    *puVar25 = (short)(uVar34 >> 0x10);
  }
  *DAT_00058e5c = 0xff;
  puVar25 = DAT_00058e60;
  *DAT_00058e60 = 0;
  puVar25[1] = 2;
  puVar25[2] = 0;
  puVar25[3] = 0;
  puVar25[4] = 0;
  puVar25[5] = 0;
  puVar25[6] = 0;
  puVar25[7] = 0;
  uVar34 = param_2[7] & 0x1000;
  if ((param_2[7] & 1) == 0) {
    if (uVar34 == 0) {
      uVar22 = 0x120;
    }
    else {
      uVar22 = 800;
    }
  }
  else if (uVar34 == 0) {
    uVar22 = 0x110;
  }
  else {
    uVar22 = 0x310;
  }
  *DAT_00058e64 = uVar22;
  puVar17 = DAT_00058e6c;
  puVar25 = DAT_00058e68;
  uVar18 = param_2[0x1b];
  *DAT_00058e68 = 0;
  puVar25[1] = 0;
  uVar18 = uVar18 & 0x20000000;
  puVar25[2] = 0;
  puVar25[3] = 0;
  puVar25[4] = 0;
  puVar25[5] = 0;
  uVar26 = param_2[10];
  uVar19 = param_2[9];
  uVar3 = (ushort)uVar19 | (ushort)uVar26 << 8;
  *DAT_00058e70 = uVar3;
  uVar7 = param_2[0xc];
  uVar8 = param_2[0xb];
  uVar4 = (ushort)uVar8 | (ushort)uVar7 << 8;
  *DAT_00058e74 = uVar4;
  uVar9 = param_2[0x10];
  uVar10 = param_2[0xf];
  uVar16 = (ushort)param_2[0x11];
  uVar2 = (ushort)uVar10 | (ushort)uVar9 << 8;
  *DAT_00058e78 = uVar2;
  puVar28 = DAT_00058e94;
  puVar21 = DAT_00058e90;
  if (uVar18 == 0) {
    uVar27 = param_2[0x32];
  }
  else {
    uVar27 = param_2[0x12];
  }
  *puVar17 = uVar16 | (ushort)(uVar27 << 8);
  uVar27 = param_2[0x13];
  uVar11 = param_2[0x14];
  uVar5 = (ushort)uVar27 | (ushort)uVar11 << 8;
  *puVar21 = uVar5;
  uVar6 = (ushort)param_2[0x15];
  *puVar28 = uVar6;
  puVar28[1] = uVar3;
  *DAT_00058e98 = uVar4;
  puVar17 = DAT_00058e9c;
  *DAT_00058e9c = uVar2;
  if (uVar18 == 0) {
    uVar2 = (ushort)param_2[0x32] & 0xff00;
  }
  else {
    uVar2 = (ushort)(param_2[0x12] << 8);
  }
  puVar17[1] = uVar2 | uVar16;
  puVar17 = DAT_00058e80;
  *DAT_00058e80 = uVar5;
  puVar25 = DAT_00058e84;
  puVar17[1] = uVar6;
  *puVar25 = 0;
  puVar25[1] = 0;
  puVar25[2] = 0;
  puVar25[3] = 0;
  puVar25[4] = 0;
  puVar25[5] = 0;
  puVar20 = DAT_00058e88;
  if ((uVar32 & 0x40) == 0) {
    puVar25[6] = 0;
    *puVar20 = 0;
  }
  else {
    puVar25[6] = 0x1000;
    if (uVar34 == 0) {
      uVar22 = 1;
    }
    else {
      uVar22 = 3;
    }
    *puVar20 = uVar22;
  }
  puVar21 = DAT_00058ea4;
  puVar17 = DAT_00058ea0;
  puVar25 = DAT_00058e8c;
  *DAT_00058e8c = 0;
  puVar25[1] = 0;
  puVar25[2] = 0;
  puVar25[3] = 0;
  puVar25[4] = 0;
  puVar28 = DAT_00058ea8;
  uVar2 = (ushort)uVar19 << 8;
  puVar25[5] = uVar2;
  uVar3 = (ushort)uVar26 | (ushort)uVar8 << 8;
  *puVar17 = uVar3;
  uVar4 = (ushort)uVar7 | (ushort)uVar10 << 8;
  uVar16 = (ushort)uVar9 | uVar16 << 8;
  *puVar21 = uVar4;
  uVar5 = (ushort)uVar27 << 8;
  puVar21[1] = uVar16;
  if (uVar18 == 0) {
    uVar33 = (ushort)*(byte *)((int)param_2 + 0xca);
  }
  else {
    uVar33 = (ushort)param_2[0x12];
  }
  *puVar28 = uVar5 | uVar33;
  puVar17 = DAT_000590c0;
  uVar6 = (ushort)uVar11 | uVar6 << 8;
  *DAT_000590c0 = uVar6;
  puVar17[1] = uVar2;
  puVar17 = DAT_00059068;
  *DAT_00059068 = uVar3;
  puVar17[1] = uVar4;
  puVar17[2] = uVar16;
  puVar21 = DAT_0005906c;
  if (uVar18 == 0) {
    uVar16 = (ushort)*(byte *)((int)param_2 + 0xcb);
  }
  else {
    uVar16 = (ushort)param_2[0x12];
  }
  puVar17[3] = uVar5 | uVar16;
  puVar17 = DAT_00059070;
  *DAT_00059070 = uVar6;
  puVar17 = puVar17 + 1;
  do {
    puVar28 = puVar17 + 1;
    *puVar17 = 0;
    puVar17 = puVar28;
  } while (puVar28 != puVar21);
  uVar32 = param_2[0x1e];
  if (uVar18 == 0) {
LAB_0005901a:
    *puVar28 = 0x100;
  }
  else if ((uVar32 & 4) == 0) {
    *puVar28 = 0;
  }
  else {
    if (param_1 != 0) goto LAB_0005901a;
    *puVar28 = 0;
  }
  bVar1 = *DAT_00059074;
  *DAT_00059078 = (bVar1 - 2) * 0x100;
  psVar12 = DAT_0005907c;
  *DAT_0005907c = bVar1 - 2;
  psVar12[1] = 0;
  psVar12[2] = 0;
  psVar12[3] = 0x1e;
  psVar12[4] = 0x28;
  psVar12[5] = 0;
  psVar12[6] = 0;
  puVar25 = DAT_00059080;
  if ((uVar32 & 4) == 0) {
    *DAT_00059080 = 0;
    uVar22 = 0;
  }
  else if (param_1 == 0) {
    *DAT_00059080 = 0x38;
    uVar22 = 0x24a;
  }
  else if (param_1 == 1) {
    *DAT_00059080 = 0x438;
    uVar22 = 0x64a;
  }
  else if (param_1 == 2) {
    *DAT_00059080 = 0x838;
    uVar22 = 0xa4a;
  }
  else {
    if (param_1 != 3) goto LAB_00058f52;
    *DAT_00059080 = 0xc38;
    uVar22 = 0xe4a;
  }
  puVar25[1] = uVar22;
LAB_00058f52:
  puVar25 = DAT_00059084;
  uVar22 = 0;
  *DAT_00059084 = 0;
  puVar25[1] = 0;
  puVar25[2] = 0;
  puVar25[3] = 0;
  puVar25[4] = 0;
  puVar25[5] = 0;
  puVar25[6] = 1;
  puVar20 = DAT_00059088;
  puVar25 = puVar25 + 7;
  do {
    puVar24 = puVar25 + 1;
    *puVar25 = 0;
    puVar25 = puVar24;
  } while (puVar24 != puVar20);
  uVar16 = *(ushort *)((int)param_2 + 0x66) & 0xf;
  if (((*(ushort *)((int)param_2 + 0x66) & 0xf) < 2) || (uVar16 == 4)) {
    uVar22 = 0x300;
  }
  else if (uVar16 == 3) {
    uVar22 = 0xc00;
  }
  *DAT_0005908c = uVar22;
  *puVar20 = 0x200;
  puVar25 = DAT_00059094;
  puVar20 = DAT_00059090;
  do {
    puVar31 = puVar20 + 1;
    *puVar20 = 0;
    puVar24 = DAT_00059098;
    puVar20 = puVar31;
  } while (puVar31 != puVar25);
  *puVar31 = 0x715d;
  *DAT_0005909c = 0xce;
  puVar25 = DAT_000590a0;
  do {
    puVar20 = puVar25 + 1;
    *puVar25 = 0;
    iVar13 = DAT_000590a4;
    puVar25 = puVar20;
  } while (puVar20 != puVar24);
  *puVar20 = 4;
  iVar14 = DAT_000590ac;
  puVar25 = DAT_000590a8;
  *DAT_000590a8 = 0x400;
  puVar25[1] = 0;
  puVar20 = DAT_000590b0;
  puVar25[2] = 0;
  puVar25[3] = 0;
  puVar25[4] = 0;
  puVar25[5] = 0;
  puVar25[6] = 0;
  puVar25[7] = 0;
  puVar25 = DAT_000590b4;
  do {
    puVar31 = puVar25 + 1;
    *puVar25 = *(undefined2 *)(iVar13 + ((int)puVar25 + iVar14 >> 1) * 2);
    puVar24 = DAT_000590b8;
    puVar25 = puVar31;
  } while (puVar31 != puVar20);
  do {
    puVar25 = puVar31 + 1;
    *puVar31 = 0;
    puVar31 = puVar25;
  } while (puVar25 != puVar24);
  *DAT_000590bc = 1;
  return;
}

