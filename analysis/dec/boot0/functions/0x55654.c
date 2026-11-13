// rea decompile_all
// name: FUN_00055654
// address: 0x55654
// body: available
// range: 0x55654-0x55921 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00055654(uint *param_1)

{
  byte bVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  uint uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  ushort uVar11;
  ushort uVar12;
  uint uVar13;
  uint uVar14;
  
  uVar8 = *param_1;
  uVar13 = param_1[1];
  if (uVar8 < 0x1a9) {
LAB_000557aa:
    uVar9 = 0x123e;
    uVar10 = 0x502;
  }
  else if (uVar8 < 0x20a) {
LAB_000557b4:
    uVar9 = 0x123e;
    uVar10 = 0x402;
  }
  else if (uVar8 < 0x272) {
LAB_000557be:
    uVar9 = 0x123e;
    uVar10 = 0x302;
  }
  else {
    if (uVar8 < 0x351) goto LAB_000557aa;
    if (uVar8 < 0x413) goto LAB_000557b4;
    if (uVar8 < 0x4e3) goto LAB_000557be;
    if (uVar8 < 0x6a1) goto LAB_000557aa;
    if (uVar8 < 0x825) goto LAB_000557b4;
    if (uVar8 < 0x9c5) goto LAB_000557be;
    uVar10 = 0x601;
    uVar9 = 0x1c3e;
    if (uVar8 < 0xa8d) {
      uVar10 = 0x701;
    }
  }
  uVar14 = param_1[0x1e];
  uVar8 = param_1[7];
  *DAT_00055924 = uVar10;
  puVar6 = DAT_00055988;
  puVar5 = DAT_00055984;
  puVar2 = DAT_00055928;
  uVar8 = uVar8 & 0x1000;
  *DAT_00055928 = uVar9;
  puVar2[0x3d] = 0x101;
  puVar2[0x15] = 2;
  if (uVar13 == 9) {
    puVar2[0x5a] = 1;
  }
  puVar7 = DAT_0005598c;
  *DAT_0005592c = 0;
  puVar2 = DAT_00055930;
  *DAT_00055930 = 0xff;
  puVar2[0x243] = 0x808;
  puVar2[0x246] = 9;
  if (uVar13 == 9) {
    *DAT_00055934 = 0x26;
    puVar2[0x26b] = 0;
  }
  else {
    *DAT_00055934 = 0x129;
    puVar2[0x26b] = 1;
  }
  puVar4 = DAT_00055940;
  puVar3 = DAT_0005593c;
  puVar2 = DAT_00055938;
  *DAT_00055938 = 3;
  puVar2[10] = 0;
  puVar2 = DAT_00055944;
  if ((uVar14 & 0x40) == 0) {
    if (uVar8 == 0) {
      uVar9 = 0x280;
    }
    else if (uVar13 == 9) {
      uVar9 = 0x80;
    }
    else {
      uVar9 = 0;
    }
    *puVar5 = uVar9;
    *puVar6 = uVar9;
    *puVar7 = uVar9;
    uVar9 = 0x7ff;
  }
  else {
    if (uVar8 == 0) {
      uVar9 = 0x280;
    }
    else if (uVar13 == 9) {
      uVar9 = 0x80;
    }
    else {
      uVar9 = 0;
    }
    *puVar5 = uVar9;
    *puVar6 = uVar9;
    *puVar7 = uVar9;
  }
  *puVar3 = uVar9;
  *puVar4 = uVar9;
  uVar11 = *(ushort *)((int)param_1 + 0x66);
  *puVar2 = uVar9;
  puVar5 = DAT_00055950;
  puVar2 = DAT_0005594c;
  uVar12 = uVar11 & 0xf;
  *DAT_00055948 = 0;
  puVar7 = DAT_00055958;
  puVar6 = DAT_00055954;
  if (uVar8 == 0) {
    if (uVar13 == 9) {
      uVar10 = 0x91d;
      *puVar2 = 0x91d;
      uVar9 = 0x911;
      goto LAB_000557a2;
    }
    if (((uVar11 & 0xf) < 2) || (uVar12 == 4)) {
      uVar10 = 0x50d;
      *puVar2 = 0x50d;
      uVar9 = 0x501;
      goto LAB_00055802;
    }
    uVar10 = 0x501;
    *puVar2 = 0x501;
    uVar9 = 0x50d;
LAB_000558cc:
    *puVar5 = uVar9;
    if (uVar12 == 3) goto LAB_00055804;
  }
  else {
    if (uVar13 != 9) {
      if ((1 < (uVar11 & 0xf)) && (uVar12 != 4)) {
        uVar10 = 0x703;
        *puVar2 = 0x703;
        uVar9 = 0x70f;
        goto LAB_000558cc;
      }
      uVar10 = 0x70f;
      *puVar2 = 0x70f;
      uVar9 = 0x703;
LAB_00055802:
      *puVar5 = uVar9;
LAB_00055804:
      *puVar6 = uVar9;
      *puVar7 = uVar10;
      goto LAB_00055808;
    }
    uVar10 = 0xb3f;
    *puVar2 = 0xb3f;
    uVar9 = 0xb33;
LAB_000557a2:
    *puVar5 = uVar9;
  }
  *puVar6 = uVar10;
  *puVar7 = uVar9;
LAB_00055808:
  uVar8 = uVar14 & 4;
  if (uVar8 != 0) {
    *DAT_0005595c = 2;
  }
  puVar2 = DAT_00055960;
  *DAT_00055960 = 0x6000;
  puVar2[1] = 0xa9;
  puVar2[2] = 0x8000;
  bVar1 = *DAT_00055964;
  uVar11 = (ushort)bVar1;
  if (bVar1 == 0) {
    if (uVar8 == 0) {
      uVar9 = 5;
    }
    else {
      uVar9 = 0x5555;
    }
  }
  else {
    uVar9 = 0;
  }
  *DAT_00055968 = uVar9;
  puVar2 = DAT_0005596c;
  *DAT_0005596c = 0x4000;
  if (bVar1 == 0) {
    if (uVar8 == 0) {
      uVar9 = 2;
    }
    else {
      uVar9 = 0x2222;
    }
  }
  else {
    uVar9 = 0;
  }
  puVar2[1] = uVar9;
  puVar2 = DAT_00055970;
  *DAT_00055970 = 0xf000;
  puVar2[2] = 0x6000;
  puVar2[3] = 0xa9;
  puVar2[4] = 0x8000;
  if (bVar1 == 0) {
    puVar2[5] = 0;
  }
  else {
    puVar2[5] = 5;
  }
  puVar2 = DAT_00055974;
  *DAT_00055974 = 0x4000;
  if (bVar1 != 0) {
    uVar11 = 2;
  }
  puVar2[1] = uVar11;
  puVar2 = DAT_00055978;
  *DAT_00055978 = 0xf000;
  puVar2[-0x2f800] = 0xf;
  puVar2 = DAT_0005597c;
  if (uVar13 == 9) {
    uVar9 = 0;
  }
  else {
    uVar9 = 0x400;
  }
  *DAT_0005597c = uVar9;
  puVar2[0x1000] = uVar9;
  puVar2[0x2000] = uVar9;
  puVar2[0x3000] = uVar9;
  if ((uVar14 & 0x40) == 0) {
    uVar9 = 1;
  }
  else {
    uVar9 = 3;
  }
  *DAT_00055980 = uVar9;
  return;
}

