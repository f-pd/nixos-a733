// rea decompile_all
// name: FUN_00097768
// address: 0x97768
// body: available
// range: 0x97768-0x97775 inclusive
// range: 0xa1018-0xa12ab inclusive
// range: 0xa131c-0xa14d7 inclusive
// range: 0xa2170-0xa226d inclusive
// range: 0xa2298-0xa253b inclusive
// range: 0xa25cc-0xa262f inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00097768(uint param_1,uint *param_2)

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
      uVar16 = FUN_000a3750((*param_2 & 0x7fff) << 3,
                            (param_2[0x18] >> ((param_1 & 0x1f) << 3) & 0x1f) + 1);
      uVar32 = (uint)uVar16;
    }
    uVar22 = (undefined2)uVar32;
    if (uVar32 < 0x640) {
      uVar22 = 0x640;
    }
    *DAT_000a2270 = 0;
    thunk_FUN_00091a8c(1);
    puVar25 = DAT_000a2274;
    *DAT_000a2274 = 0;
    puVar25[1] = 0;
    uVar34 = param_2[0x1e];
    uVar32 = uVar34 & 4;
    if (uVar32 == 0) {
      uVar23 = 0x30;
LAB_000a21c6:
      *DAT_000a2278 = uVar23;
    }
    else {
      if (param_1 == 0) {
        uVar23 = 0xa0;
        goto LAB_000a21c6;
      }
      if (param_1 == 1) {
        uVar23 = 0x91;
        goto LAB_000a21c6;
      }
      if (param_1 == 2) {
        uVar23 = 0x82;
        goto LAB_000a21c6;
      }
      if (param_1 == 3) {
        uVar23 = 0x83;
        goto LAB_000a21c6;
      }
    }
    puVar25 = DAT_000a2280;
    *DAT_000a227c = uVar22;
    *puVar25 = 4;
    puVar25[1] = 4;
    puVar25[2] = 0;
    puVar25[3] = 0;
    uVar19 = param_2[0x1b];
    uVar26 = uVar19 & 0x1fffffff;
    if (uVar26 >> 0x10 == 0) {
      *DAT_000a2284 = 799;
      param_2[0x1b] = uVar19 | 0x31f0000;
    }
    else {
      *DAT_000a2284 = (short)(uVar26 >> 0x10);
    }
    uVar26 = param_2[0x1b];
    *DAT_000a2288 = 0xff;
    puVar25 = DAT_000a228c;
    uVar22 = 0;
    *DAT_000a228c = 0;
    puVar25[1] = 2;
    puVar25[2] = 0;
    puVar25[3] = 0;
    if ((int)uVar26 < 0) {
      uVar22 = 0xf;
    }
    puVar25[4] = uVar22;
    puVar25 = DAT_000a2290;
    *DAT_000a2290 = 0;
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
    *DAT_000a2294 = uVar22;
    puVar25 = DAT_000a2540;
    puVar20 = DAT_000a253c;
    do {
      puVar31 = puVar20 + 1;
      *puVar20 = 0;
      puVar24 = DAT_000a2544;
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
    puVar17 = DAT_000a254c;
    puVar21 = DAT_000a2548;
    do {
      puVar28 = puVar21 + 1;
      *puVar21 = 0;
      puVar21 = puVar28;
    } while (puVar28 != puVar17);
    uVar16 = (ushort)param_2[9] | (ushort)param_2[9] << 8;
    *puVar28 = uVar16;
    puVar17 = DAT_000a2550;
    *DAT_000a2550 = uVar16;
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
    puVar15 = DAT_000a263c;
    puVar28 = DAT_000a2638;
    puVar21 = DAT_000a2634;
    puVar17 = DAT_000a2554;
    uVar34 = uVar26 & 0x20000000;
    if ((int)param_2[0x17] < 0) {
      if ((uVar34 == 0) && ((uVar32 == 0 || (param_1 == 0)))) {
        uVar19 = param_2[0x32];
        uVar2 = (ushort)uVar19;
        *DAT_000a2640 = uVar2;
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
        *DAT_000a2640 = uVar16;
        *puVar21 = uVar16;
        *puVar28 = uVar16;
      }
      *puVar15 = uVar16;
    }
    else if (uVar34 != 0) {
      uVar16 = (ushort)param_2[0x12] | (ushort)param_2[0x12] << 8;
      *DAT_000a2554 = uVar16;
      puVar17[1] = uVar16;
      puVar17[2] = uVar16;
      puVar17[3] = uVar16;
    }
    puVar21 = DAT_000a255c;
    puVar17 = DAT_000a2558;
    uVar16 = (ushort)param_2[0x13] | (ushort)param_2[0x13] << 8;
    puVar28 = DAT_000a255c + 0x1a;
    *DAT_000a2558 = uVar16;
    puVar17[1] = uVar16;
    puVar17 = DAT_000a2560;
    uVar16 = (ushort)param_2[0x14] | 0x2800 | (ushort)param_2[0x14] << 8;
    *DAT_000a2560 = uVar16;
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
    puVar25 = DAT_000a2564;
    *DAT_000a2564 = 0;
    puVar25[1] = 0;
    puVar25[2] = 0;
    puVar25[3] = 0;
    puVar25[4] = 0;
    puVar25[5] = 0;
    puVar25[6] = 0;
    puVar25[7] = 0;
    puVar21[10] = 0x404;
    puVar21[0xb] = 0x404;
    puVar17 = DAT_000a2568;
    do {
      puVar21 = puVar17 + 1;
      *puVar17 = 0;
      puVar17 = puVar21;
    } while (puVar21 != puVar28);
    *puVar21 = 0x6060;
    *DAT_000a256c = 0x6060;
    if (uVar34 == 0) {
LAB_000a2536:
      *DAT_000a2570 = 1;
    }
    else if (uVar32 == 0) {
      *DAT_000a2570 = 0;
    }
    else {
      if (param_1 != 0) goto LAB_000a2536;
      *DAT_000a2570 = 0;
    }
    puVar25 = DAT_000a2578;
    puVar20 = DAT_000a2574;
    do {
      puVar24 = puVar20 + 1;
      *puVar20 = 0;
      puVar20 = puVar24;
    } while (puVar24 != puVar25);
    *puVar24 = 0x2e;
    puVar25 = DAT_000a257c;
    *DAT_000a257c = 0x50;
    puVar25[1] = 0;
    puVar25[2] = 0;
    puVar20 = DAT_000a2630;
    if (uVar32 == 0) {
      *DAT_000a2630 = 0;
      uVar22 = 0;
    }
    else {
      if (param_1 == 0) {
        puVar25[3] = 0x58;
        puVar25[4] = 0x287;
        goto LAB_000a2428;
      }
      if (param_1 == 1) {
        *DAT_000a2630 = 0x458;
        uVar22 = 0x687;
      }
      else if (param_1 == 2) {
        *DAT_000a2630 = 0x858;
        uVar22 = 0xa87;
      }
      else {
        if (param_1 != 3) goto LAB_000a2428;
        *DAT_000a2630 = 0xc58;
        uVar22 = 0xe87;
      }
    }
    puVar20[1] = uVar22;
LAB_000a2428:
    psVar12 = DAT_000a2584;
    puVar25 = DAT_000a2580;
    *DAT_000a2580 = 0;
    puVar25[1] = 0;
    puVar25[2] = 0;
    puVar25[3] = 0;
    puVar25[4] = 0;
    puVar25[5] = 0;
    *DAT_000a2588 = 0xf01;
    bVar1 = *DAT_000a258c;
    *psVar12 = ((ushort)bVar1 * 4 + -1) * 0x100;
    psVar12 = DAT_000a2590;
    *DAT_000a2590 = (ushort)bVar1 * 4 + -5;
    psVar29 = DAT_000a2594;
    do {
      psVar30 = psVar29 + 1;
      *psVar29 = 0;
      psVar29 = psVar30;
    } while (psVar30 != psVar12 + 0x182);
    *psVar30 = 0x500;
    puVar25 = DAT_000a259c;
    puVar20 = DAT_000a2598;
    do {
      puVar24 = puVar20 + 1;
      *puVar20 = 0;
      puVar20 = puVar24;
    } while (puVar24 != puVar25);
    *puVar24 = 0x715d;
    puVar25 = DAT_000a25a0;
    *DAT_000a25a0 = 0xce;
    puVar20 = DAT_000a25a4;
    puVar25 = puVar25 + 1;
    do {
      puVar31 = puVar25 + 1;
      *puVar25 = 0;
      puVar24 = DAT_000a25a8;
      puVar25 = puVar31;
    } while (puVar31 != puVar20);
    *puVar31 = 4;
    puVar25 = DAT_000a25ac;
    do {
      puVar20 = puVar25 + 1;
      *puVar25 = 0;
      iVar13 = DAT_000a25b0;
      puVar25 = puVar20;
    } while (puVar20 != puVar24);
    *puVar20 = 4;
    puVar20 = DAT_000a25bc;
    iVar14 = DAT_000a25b8;
    puVar25 = DAT_000a25b4;
    *DAT_000a25b4 = 0;
    puVar25[1] = 0;
    puVar25[2] = 0;
    puVar25[3] = 0;
    puVar25[4] = 0;
    puVar25[5] = 0;
    puVar25[6] = 0;
    puVar25 = DAT_000a25c0;
    do {
      puVar31 = puVar25 + 1;
      *puVar25 = *(undefined2 *)(iVar13 + ((int)puVar25 + iVar14 >> 1) * 2);
      puVar24 = DAT_000a25c4;
      puVar25 = puVar31;
    } while (puVar31 != puVar20);
    do {
      puVar25 = puVar31 + 1;
      *puVar31 = 0;
      puVar31 = puVar25;
    } while (puVar25 != puVar24);
    *DAT_000a25c8 = 1;
    return;
  }
  uVar32 = (*param_2 & 0x7fff) << 1;
  if ((int)(param_2[0x1e] << 0x1d) < 0) {
    uVar16 = FUN_000a3750((*param_2 & 0x7fff) << 3,
                          (param_2[0x18] >> ((param_1 & 0x1f) << 3) & 0x1f) + 1);
    uVar32 = (uint)uVar16;
  }
  uVar22 = (undefined2)uVar32;
  if (uVar32 < 0x640) {
    uVar22 = 0x640;
  }
  *DAT_000a12ac = 0;
  thunk_FUN_00091a8c(1);
  puVar25 = DAT_000a12b0;
  uVar32 = param_2[0x1e];
  *DAT_000a12b0 = 0;
  puVar25[1] = 0;
  if ((uVar32 & 4) == 0) {
    uVar23 = 0x30;
LAB_000a114c:
    *DAT_000a12ec = uVar23;
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
        if (param_1 != 3) goto LAB_000a1076;
        uVar23 = 0x83;
      }
      goto LAB_000a114c;
    }
    puVar25[2] = 0xa0;
  }
LAB_000a1076:
  *DAT_000a12b4 = uVar22;
  if (*DAT_000a12b8 == '\0') {
    uVar22 = 4;
  }
  else {
    uVar22 = 2;
  }
  *DAT_000a12bc = uVar22;
  puVar25 = DAT_000a12c4;
  *DAT_000a12c0 = 4;
  puVar20 = DAT_000a12c8;
  *DAT_000a12c8 = 0;
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
  *DAT_000a12cc = 0xff;
  puVar25 = DAT_000a12d0;
  *DAT_000a12d0 = 0;
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
  *DAT_000a12d4 = uVar22;
  puVar17 = DAT_000a12dc;
  puVar25 = DAT_000a12d8;
  uVar18 = param_2[0x1b];
  *DAT_000a12d8 = 0;
  puVar25[1] = 0;
  uVar18 = uVar18 & 0x20000000;
  puVar25[2] = 0;
  puVar25[3] = 0;
  puVar25[4] = 0;
  puVar25[5] = 0;
  uVar26 = param_2[10];
  uVar19 = param_2[9];
  uVar3 = (ushort)uVar19 | (ushort)uVar26 << 8;
  *DAT_000a12e0 = uVar3;
  uVar7 = param_2[0xc];
  uVar8 = param_2[0xb];
  uVar4 = (ushort)uVar8 | (ushort)uVar7 << 8;
  *DAT_000a12e4 = uVar4;
  uVar9 = param_2[0x10];
  uVar10 = param_2[0xf];
  uVar16 = (ushort)param_2[0x11];
  uVar2 = (ushort)uVar10 | (ushort)uVar9 << 8;
  *DAT_000a12e8 = uVar2;
  puVar28 = DAT_000a1304;
  puVar21 = DAT_000a1300;
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
  *DAT_000a1308 = uVar4;
  puVar17 = DAT_000a130c;
  *DAT_000a130c = uVar2;
  if (uVar18 == 0) {
    uVar2 = (ushort)param_2[0x32] & 0xff00;
  }
  else {
    uVar2 = (ushort)(param_2[0x12] << 8);
  }
  puVar17[1] = uVar2 | uVar16;
  puVar17 = DAT_000a12f0;
  *DAT_000a12f0 = uVar5;
  puVar25 = DAT_000a12f4;
  puVar17[1] = uVar6;
  *puVar25 = 0;
  puVar25[1] = 0;
  puVar25[2] = 0;
  puVar25[3] = 0;
  puVar25[4] = 0;
  puVar25[5] = 0;
  puVar20 = DAT_000a12f8;
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
  puVar21 = DAT_000a1314;
  puVar17 = DAT_000a1310;
  puVar25 = DAT_000a12fc;
  *DAT_000a12fc = 0;
  puVar25[1] = 0;
  puVar25[2] = 0;
  puVar25[3] = 0;
  puVar25[4] = 0;
  puVar28 = DAT_000a1318;
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
  puVar17 = DAT_000a1530;
  uVar6 = (ushort)uVar11 | uVar6 << 8;
  *DAT_000a1530 = uVar6;
  puVar17[1] = uVar2;
  puVar17 = DAT_000a14d8;
  *DAT_000a14d8 = uVar3;
  puVar17[1] = uVar4;
  puVar17[2] = uVar16;
  puVar21 = DAT_000a14dc;
  if (uVar18 == 0) {
    uVar16 = (ushort)*(byte *)((int)param_2 + 0xcb);
  }
  else {
    uVar16 = (ushort)param_2[0x12];
  }
  puVar17[3] = uVar5 | uVar16;
  puVar17 = DAT_000a14e0;
  *DAT_000a14e0 = uVar6;
  puVar17 = puVar17 + 1;
  do {
    puVar28 = puVar17 + 1;
    *puVar17 = 0;
    puVar17 = puVar28;
  } while (puVar28 != puVar21);
  uVar32 = param_2[0x1e];
  if (uVar18 == 0) {
LAB_000a148a:
    *puVar28 = 0x100;
  }
  else if ((uVar32 & 4) == 0) {
    *puVar28 = 0;
  }
  else {
    if (param_1 != 0) goto LAB_000a148a;
    *puVar28 = 0;
  }
  bVar1 = *DAT_000a14e4;
  *DAT_000a14e8 = (bVar1 - 2) * 0x100;
  psVar12 = DAT_000a14ec;
  *DAT_000a14ec = bVar1 - 2;
  psVar12[1] = 0;
  psVar12[2] = 0;
  psVar12[3] = 0x1e;
  psVar12[4] = 0x28;
  psVar12[5] = 0;
  psVar12[6] = 0;
  puVar25 = DAT_000a14f0;
  if ((uVar32 & 4) == 0) {
    *DAT_000a14f0 = 0;
    uVar22 = 0;
  }
  else if (param_1 == 0) {
    *DAT_000a14f0 = 0x38;
    uVar22 = 0x24a;
  }
  else if (param_1 == 1) {
    *DAT_000a14f0 = 0x438;
    uVar22 = 0x64a;
  }
  else if (param_1 == 2) {
    *DAT_000a14f0 = 0x838;
    uVar22 = 0xa4a;
  }
  else {
    if (param_1 != 3) goto LAB_000a13c2;
    *DAT_000a14f0 = 0xc38;
    uVar22 = 0xe4a;
  }
  puVar25[1] = uVar22;
LAB_000a13c2:
  puVar25 = DAT_000a14f4;
  uVar22 = 0;
  *DAT_000a14f4 = 0;
  puVar25[1] = 0;
  puVar25[2] = 0;
  puVar25[3] = 0;
  puVar25[4] = 0;
  puVar25[5] = 0;
  puVar25[6] = 1;
  puVar20 = DAT_000a14f8;
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
  *DAT_000a14fc = uVar22;
  *puVar20 = 0x200;
  puVar25 = DAT_000a1504;
  puVar20 = DAT_000a1500;
  do {
    puVar31 = puVar20 + 1;
    *puVar20 = 0;
    puVar24 = DAT_000a1508;
    puVar20 = puVar31;
  } while (puVar31 != puVar25);
  *puVar31 = 0x715d;
  *DAT_000a150c = 0xce;
  puVar25 = DAT_000a1510;
  do {
    puVar20 = puVar25 + 1;
    *puVar25 = 0;
    iVar13 = DAT_000a1514;
    puVar25 = puVar20;
  } while (puVar20 != puVar24);
  *puVar20 = 4;
  iVar14 = DAT_000a151c;
  puVar25 = DAT_000a1518;
  *DAT_000a1518 = 0x400;
  puVar25[1] = 0;
  puVar20 = DAT_000a1520;
  puVar25[2] = 0;
  puVar25[3] = 0;
  puVar25[4] = 0;
  puVar25[5] = 0;
  puVar25[6] = 0;
  puVar25[7] = 0;
  puVar25 = DAT_000a1524;
  do {
    puVar31 = puVar25 + 1;
    *puVar25 = *(undefined2 *)(iVar13 + ((int)puVar25 + iVar14 >> 1) * 2);
    puVar24 = DAT_000a1528;
    puVar25 = puVar31;
  } while (puVar31 != puVar20);
  do {
    puVar25 = puVar31 + 1;
    *puVar31 = 0;
    puVar31 = puVar25;
  } while (puVar25 != puVar24);
  *DAT_000a152c = 1;
  return;
}

