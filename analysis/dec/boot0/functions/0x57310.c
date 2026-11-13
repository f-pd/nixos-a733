// rea decompile_all
// name: FUN_00057310
// address: 0x57310
// body: available
// range: 0x57310-0x57601 inclusive
// range: 0x57650-0x576d3 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00057310(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 *puVar3;
  uint *puVar4;
  int iVar5;
  ushort *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int *piVar18;
  uint uVar19;
  bool bVar20;
  
  puVar3 = DAT_00057608;
  param_2 = param_2 * 0x400000;
  iVar9 = *(int *)(param_1 + 4);
  *DAT_00057604 = 0;
  *puVar3 = 3;
  if (*DAT_0005760c >> 8 < (*DAT_0005760c & 0xff)) {
    uVar10 = (uint)(byte)*DAT_0005760c;
  }
  else {
    uVar10 = (uint)(*DAT_0005760c >> 8);
  }
  if ((*DAT_00057614 & 0xff) < *DAT_00057610 >> 8) {
    uVar8 = (uint)(*DAT_00057610 >> 8);
  }
  else {
    uVar8 = *DAT_00057614 & 0xff;
  }
  if (uVar10 < uVar8) {
    uVar10 = uVar8;
  }
  if (*DAT_0005761c >> 8 < (*DAT_0005761c & 0xff)) {
    uVar8 = (uint)(byte)*DAT_0005761c;
  }
  else {
    uVar8 = (uint)(*DAT_0005761c >> 8);
  }
  bVar20 = (*DAT_00057618 & 0xff) < *DAT_00057620 >> 8;
  if (bVar20) {
    uVar1 = *DAT_00057620;
  }
  else {
    uVar1 = *DAT_00057618;
  }
  if (bVar20) {
    uVar11 = (uint)(uVar1 >> 8);
  }
  else {
    uVar11 = uVar1 & 0xff;
  }
  bVar20 = *DAT_00057628 >> 8 <= (*DAT_00057624 & 0xff);
  if (bVar20) {
    uVar1 = *DAT_00057624;
  }
  else {
    uVar1 = *DAT_00057628;
  }
  if (bVar20) {
    uVar14 = uVar1 & 0xff;
  }
  else {
    uVar14 = (uint)(uVar1 >> 8);
  }
  if (*DAT_0005762c >> 8 < (*DAT_0005762c & 0xff)) {
    uVar12 = (uint)(byte)*DAT_0005762c;
  }
  else {
    uVar12 = (uint)(*DAT_0005762c >> 8);
  }
  if (uVar14 < uVar12) {
    uVar14 = uVar12;
  }
  bVar20 = *DAT_00057634 >> 8 <= (*DAT_00057630 & 0xff);
  if (bVar20) {
    uVar1 = *DAT_00057630;
  }
  else {
    uVar1 = *DAT_00057634;
  }
  if (bVar20) {
    uVar12 = uVar1 & 0xff;
  }
  else {
    uVar12 = (uint)(uVar1 >> 8);
  }
  if (*DAT_00057640 >> 8 < (*DAT_00057640 & 0xff)) {
    uVar19 = (uint)(byte)*DAT_00057640;
  }
  else {
    uVar19 = (uint)(*DAT_00057640 >> 8);
  }
  if (uVar12 < uVar19) {
    uVar12 = uVar19;
  }
  if (*DAT_00057624 >> 8 < (*DAT_00057628 & 0xff)) {
    uVar1 = *DAT_00057628;
  }
  else {
    uVar1 = *DAT_00057624;
  }
  if (*DAT_00057624 >> 8 < (*DAT_00057628 & 0xff)) {
    uVar19 = (uint)(byte)uVar1;
  }
  else {
    uVar19 = (uint)(uVar1 >> 8);
  }
  bVar20 = *DAT_00057618 >> 8 <= (*DAT_00057644 & 0xff);
  if (bVar20) {
    uVar1 = *DAT_00057644;
  }
  else {
    uVar1 = *DAT_00057618;
  }
  if (bVar20) {
    uVar17 = uVar1 & 0xff;
  }
  else {
    uVar17 = (uint)(uVar1 >> 8);
  }
  if (*DAT_00057630 >> 8 < (*DAT_00057634 & 0xff)) {
    uVar1 = *DAT_00057634;
  }
  else {
    uVar1 = *DAT_00057630;
  }
  if (*DAT_00057630 >> 8 < (*DAT_00057634 & 0xff)) {
    uVar13 = uVar1 & 0xff;
  }
  else {
    uVar13 = (uint)(uVar1 >> 8);
  }
  bVar20 = (*DAT_00057610 & 0xff) < *DAT_00057644 >> 8;
  if (bVar20) {
    uVar1 = *DAT_00057644;
  }
  else {
    uVar1 = *DAT_00057610;
  }
  *puVar3 = 0;
  iVar5 = DAT_00057648;
  if (bVar20) {
    uVar1 = uVar1 >> 8;
  }
  uVar16 = (uint)uVar1;
  if (!bVar20) {
    uVar16 = uVar16 & 0xff;
  }
  *DAT_00057604 = 1;
  puVar4 = DAT_00057638;
  if (iVar9 == 9) {
    *(uint *)(param_2 + iVar5) = *(uint *)(param_2 + iVar5) | 1;
  }
  do {
  } while ((*puVar4 & 0x7ffffff) >> 0x19 != 3);
  do {
  } while ((*puVar4 & 0x3fffffff) >> 0x1c != 3);
  piVar18 = (int *)(DAT_0005764c + param_2);
  *(undefined4 *)(param_2 + DAT_0005763c) = 0;
  do {
  } while (*piVar18 << 0x1f < 0);
  uVar15 = *(uint *)(param_2 + 0xa100d04) & 0xffff0000;
  if (iVar9 == 9) {
    uVar7 = ((*(uint *)(param_2 + 0xa100d04) & 0xffff) >> 8) + uVar10;
    if (0xfe < uVar7) {
      uVar7 = 0xff;
    }
    uVar15 = uVar15 | uVar7 << 8;
    if (uVar8 < uVar11) {
      uVar8 = uVar11;
    }
    uVar8 = uVar8 + (*(uint *)(param_2 + 0xa100d04) & 0xff);
    if (uVar8 < 0x100) {
      uVar15 = uVar15 | uVar8;
    }
    else {
      uVar15 = uVar15 | 0xff;
    }
  }
  *(uint *)(param_2 + 0xa100d04) = uVar15;
  uVar8 = *(uint *)(param_2 + 0xa100d08) & 0xffff0000;
  if (iVar9 == 9) {
    uVar15 = uVar12 + (*(uint *)(param_2 + 0xa100d08) & 0xff);
    uVar11 = ((*(uint *)(param_2 + 0xa100d08) & 0xffff) >> 8) + uVar14;
    if (0xfe < uVar11) {
      uVar11 = 0xff;
    }
    uVar8 = uVar8 | uVar11 << 8;
    if (uVar15 < 0x100) {
      uVar8 = uVar8 | uVar15;
    }
    else {
      uVar8 = uVar8 | 0xff;
    }
  }
  *(uint *)(param_2 + 0xa100d08) = uVar8;
  uVar8 = *(uint *)(param_2 + 0xa100008) & 0xffff0000;
  if (iVar9 == 9) {
    if (uVar19 < uVar17) {
      uVar19 = uVar17;
    }
    uVar19 = ((*(uint *)(param_2 + 0xa100008) & 0xffff) >> 8) + uVar19;
    if (0xfe < uVar19) {
      uVar19 = 0xff;
    }
    uVar8 = uVar8 | uVar19 << 8;
    if (uVar13 < uVar16) {
      uVar13 = uVar16;
    }
    uVar13 = uVar13 + (*(uint *)(param_2 + 0xa100008) & 0xff);
    if (uVar13 < 0x100) {
      uVar8 = uVar8 | uVar13;
    }
    else {
      uVar8 = uVar8 | 0xff;
    }
  }
  *(uint *)(param_2 + 0xa100008) = uVar8;
  uVar8 = *(uint *)(param_2 + 0xa100060) & 0xff00ffff;
  if (iVar9 == 9) {
    uVar14 = ((*(uint *)(param_2 + 0xa100060) & 0xffffff) >> 0x10) + uVar14;
    if (0xfe < uVar14) {
      uVar14 = 0xff;
    }
    uVar8 = uVar8 | uVar14 << 0x10;
  }
  *(uint *)(param_2 + 0xa100060) = uVar8;
  uVar8 = *(uint *)(param_2 + 0xa100024) & 0xffffff00;
  if (iVar9 == 9) {
    uVar12 = uVar12 + (*(uint *)(param_2 + 0xa100024) & 0xff);
    if (uVar12 < 0x100) {
      uVar8 = uVar8 | uVar12;
    }
    else {
      uVar8 = uVar8 | 0xff;
    }
  }
  *(uint *)(param_2 + 0xa100024) = uVar8;
  uVar8 = *(uint *)(param_2 + 0xa100584) & 0xffe0ffff;
  if (iVar9 == 9) {
    uVar10 = ((*(uint *)(param_2 + 0xa100584) & 0xffffff) >> 0x10) + uVar10;
    if (0x1e < uVar10) {
      uVar10 = 0x1f;
    }
    uVar8 = uVar8 | uVar10 << 0x10;
  }
  *(uint *)(param_2 + 0xa100584) = uVar8;
  puVar6 = DAT_000576d8;
  puVar3 = DAT_000576d4;
  *DAT_000576d4 = 0;
  uVar1 = *DAT_000576dc;
  uVar2 = *puVar6;
  *puVar3 = 1;
  uVar10 = *(uint *)(param_2 + 0xa100588) & 0xffc0ffff;
  if (iVar9 == 9) {
    uVar10 = uVar10 | (((uVar2 & 0x1f) >> 1) + ((uVar1 & 0xf) + 1 >> 3) * 4 + 0x15) * 0x10000;
  }
  *(uint *)(param_2 + 0xa100588) = uVar10;
  *(undefined4 *)(param_2 + DAT_000576e0) = 1;
  do {
  } while (-1 < *piVar18 << 0x1f);
  *(uint *)(param_2 + iVar5) = *(uint *)(param_2 + iVar5) & 0xfffffffe;
  return;
}

