// rea decompile_all
// name: FUN_00093bf4
// address: 0x93bf4
// body: available
// range: 0x93bf4-0x93db7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00093bf4(int param_1)

{
  byte bVar1;
  ushort *puVar2;
  undefined1 *puVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  byte *pbVar8;
  ushort uVar9;
  undefined1 *puVar10;
  byte *pbVar11;
  ushort *puVar12;
  ushort *puVar13;
  undefined1 auStack_f8 [8];
  undefined1 auStack_f0 [8];
  undefined1 auStack_e8 [8];
  undefined1 auStack_e0 [8];
  undefined1 auStack_d8 [8];
  undefined1 auStack_d0 [8];
  undefined1 auStack_c8 [8];
  undefined1 auStack_c0 [8];
  undefined1 auStack_b8 [8];
  undefined1 auStack_b0 [8];
  undefined1 auStack_a8 [8];
  undefined1 auStack_a0 [8];
  undefined1 auStack_98 [8];
  undefined1 auStack_90 [8];
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [8];
  undefined1 local_78 [8];
  undefined1 local_70 [8];
  undefined1 local_68 [8];
  undefined1 local_60 [8];
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [8];
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [8];
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [8];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [12];
  
  puVar3 = auStack_f8;
  FUN_00092c40(auStack_f8,DAT_00093db8,8);
  FUN_00092c40(auStack_f0,DAT_00093dbc);
  FUN_00092c40(auStack_e8,DAT_00093dc0,8);
  FUN_00092c40(auStack_e0,DAT_00093dc4,8);
  FUN_00092c40(auStack_d8,DAT_00093dc8,8);
  FUN_00092c40(auStack_d0,DAT_00093dcc,8);
  FUN_00092c40(auStack_c8,DAT_00093dd0,8);
  FUN_00092c40(auStack_c0,DAT_00093dd4,8);
  FUN_00092c40(auStack_b8,DAT_00093dd8,8);
  FUN_00092c40(auStack_b0,DAT_00093ddc,8);
  FUN_00092c40(auStack_a8,DAT_00093de0,8);
  FUN_00092c40(auStack_a0,DAT_00093de4,8);
  FUN_00092c40(auStack_98,DAT_00093de8,8);
  FUN_00092c40(auStack_90,DAT_00093dec,8);
  FUN_00092c40(auStack_88,DAT_00093df0,8);
  FUN_00092c40(auStack_80,DAT_00093df4,8);
  FUN_00092c40(local_78,DAT_00093df8,8);
  FUN_00092c40(local_70,DAT_00093dfc,8);
  FUN_00092c40(local_68,DAT_00093e00,8);
  FUN_00092c40(local_60,DAT_00093e04,8);
  FUN_00092c40(auStack_58,DAT_00093e08,8);
  FUN_00092c40(auStack_50,DAT_00093e0c,8);
  FUN_00092c40(auStack_48,DAT_00093e10,8);
  FUN_00092c40(auStack_40,DAT_00093e14,8);
  FUN_00092c40(auStack_38,DAT_00093e18,8);
  FUN_00092c40(auStack_30,DAT_00093e1c,8);
  FUN_00092c40(auStack_28,DAT_00093e20,8);
  FUN_00092c40(auStack_20,DAT_00093e24,8);
  puVar2 = DAT_00093e2c;
  uVar9 = *(ushort *)(param_1 + 0x66) & 0xf;
  if (*(int *)(param_1 + 4) != 8) {
    if (uVar9 == 1) {
      puVar10 = auStack_20;
      puVar7 = auStack_28;
      puVar5 = auStack_30;
      puVar3 = auStack_38;
    }
    else {
      puVar10 = auStack_40;
      puVar7 = auStack_48;
      puVar5 = auStack_50;
      puVar3 = auStack_58;
    }
    goto LAB_00093d3e;
  }
  if ((*(ushort *)(param_1 + 0x66) & 0xf) != 0) {
    if (uVar9 == 1) {
      puVar10 = auStack_c0;
      puVar7 = auStack_c8;
      puVar5 = auStack_d0;
      puVar3 = auStack_d8;
      goto LAB_00093d3e;
    }
    if (uVar9 == 2) {
      puVar10 = auStack_a0;
      puVar7 = auStack_a8;
      puVar5 = auStack_b0;
      puVar3 = auStack_b8;
      goto LAB_00093d3e;
    }
    if (uVar9 == 3) {
      puVar10 = auStack_80;
      puVar7 = auStack_88;
      puVar5 = auStack_90;
      puVar3 = auStack_98;
      goto LAB_00093d3e;
    }
    if (uVar9 == 4) {
      puVar10 = local_60;
      puVar7 = local_68;
      puVar5 = local_70;
      puVar3 = local_78;
      goto LAB_00093d3e;
    }
  }
  puVar10 = auStack_e0;
  puVar7 = auStack_e8;
  puVar5 = auStack_f0;
LAB_00093d3e:
  pbVar4 = puVar3 + -1;
  pbVar6 = puVar5 + -1;
  pbVar8 = puVar7 + -1;
  pbVar11 = puVar10 + -1;
  puVar12 = DAT_00093e28;
  do {
    pbVar4 = pbVar4 + 1;
    pbVar6 = pbVar6 + 1;
    bVar1 = *pbVar6;
    *puVar12 = (ushort)*pbVar4;
    puVar12[0x1000] = (ushort)bVar1;
    pbVar8 = pbVar8 + 1;
    puVar12[0x2000] = (ushort)*pbVar8;
    puVar13 = puVar12 + 0x3000;
    pbVar11 = pbVar11 + 1;
    puVar12 = puVar12 + 1;
    *puVar13 = (ushort)*pbVar11;
  } while (puVar12 != puVar2);
  return;
}

