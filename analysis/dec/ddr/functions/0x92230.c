// rea decompile_all
// name: FUN_00092230
// address: 0x92230
// body: available
// range: 0x92230-0x924fb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00092230(void)

{
  uint *puVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  undefined4 local_38;
  uint local_34;
  uint local_30;
  uint uStack_2c;
  
  FUN_00092a80(3,DAT_000924fc);
  FUN_000920e6(DAT_00092500,0x1000000);
  FUN_000920e6(DAT_00092504,0x1000000);
  FUN_000920e6(DAT_00092508,0x1000000);
  FUN_000920e6(DAT_0009250c,0x1000000);
  FUN_000920e6(DAT_00092510,0x1000000);
  FUN_000920e6(DAT_00092514,0x1000000);
  FUN_000920e6(DAT_00092518,0x1000000);
  FUN_000920e6(DAT_0009251c,0x1000000);
  FUN_000920e6(DAT_00092520,0x1000000);
  FUN_000920e6(DAT_00092524,0x1000000);
  FUN_000920e6(DAT_00092528,0x1000000);
  FUN_000920e6(DAT_0009252c,0x1000000);
  FUN_000920e6(DAT_00092530,0x1000000);
  puVar4 = DAT_00092570;
  puVar2 = DAT_00092540;
  puVar1 = DAT_0009253c;
  puVar7 = DAT_00092538;
  DataMemoryBarrier(0x1f);
  uVar9 = *DAT_00092534 & 0x4000;
  if (uVar9 == 0) {
    uVar6 = *DAT_00092534 & 0x8000;
    if (uVar6 == 0) {
      local_38 = 0x14;
      local_34 = uVar6;
      local_30 = uVar6;
      uStack_2c = uVar6;
      FUN_000920f8(DAT_00092538,&local_38);
      local_38 = 0x2a;
      local_34 = uVar6;
      local_30 = uVar6;
      uStack_2c = uVar6;
      FUN_00092180(puVar7,&local_38);
      puVar3 = DAT_00092544;
      DataMemoryBarrier(0x1f);
      FUN_00092a80(3,DAT_00092548,*puVar7);
      local_38 = 0x14;
      local_34 = uVar6;
      local_30 = uVar6;
      uStack_2c = uVar6;
      FUN_000920f8(puVar3,&local_38);
      local_38 = 0x2a;
      local_34 = uVar6;
      local_30 = uVar6;
      uStack_2c = uVar6;
      FUN_00092180(puVar3,&local_38);
      DataMemoryBarrier(0x1f);
      puVar7 = puVar3 + 0x400;
      FUN_00092a80(3,DAT_0009254c,*puVar3);
      local_38 = 0x14;
      local_34 = uVar6;
      local_30 = uVar6;
      uStack_2c = uVar6;
      FUN_000920f8(puVar7,&local_38);
      local_38 = 0x1f;
      local_34 = uVar6;
      local_30 = uVar6;
      uStack_2c = uVar6;
      FUN_00092180(puVar7,&local_38);
      uVar5 = *puVar7;
    }
    else {
      local_38 = 0x14;
      local_34 = uVar9;
      local_30 = uVar9;
      uStack_2c = uVar9;
      FUN_000920f8(DAT_00092538,&local_38);
      local_38 = 0x27;
      local_34 = uVar9;
      local_30 = uVar9;
      uStack_2c = uVar9;
      FUN_00092180(puVar7,&local_38);
      puVar3 = DAT_00092544;
      DataMemoryBarrier(0x1f);
      FUN_00092a80(3,DAT_00092548,*puVar7);
      local_38 = 0x14;
      local_34 = uVar9;
      local_30 = uVar9;
      uStack_2c = uVar9;
      FUN_000920f8(puVar3,&local_38);
      local_38 = 0x27;
      local_34 = uVar9;
      local_30 = uVar9;
      uStack_2c = uVar9;
      FUN_00092180(puVar3,&local_38);
      DataMemoryBarrier(0x1f);
      puVar7 = puVar3 + 0x400;
      FUN_00092a80(3,DAT_0009254c,*puVar3);
      local_38 = 0x14;
      local_34 = uVar9;
      local_30 = uVar9;
      uStack_2c = uVar9;
      FUN_000920f8(puVar7,&local_38);
      local_38 = 0x1e;
      local_34 = uVar9;
      local_30 = uVar9;
      uStack_2c = uVar9;
      FUN_00092180(puVar7,&local_38);
      uVar5 = *puVar7;
    }
    DataMemoryBarrier(0x1f);
    FUN_00092a80(3,DAT_00092550,uVar5);
    uVar9 = DAT_00092554;
    DataMemoryBarrier(0x1f);
    DataMemoryBarrier(0x1f);
    *puVar4 = *puVar4 & DAT_00092554 | 0x3000000;
    FUN_00091a8c(0x14,0);
    DataMemoryBarrier(0x1f);
    DataMemoryBarrier(0x1f);
    *puVar1 = *puVar1 & uVar9 | 0x3000000;
    FUN_00091a8c(0x14,0);
    DataMemoryBarrier(0x1f);
    DataMemoryBarrier(0x1f);
    *puVar2 = *puVar2 & uVar9 | 0x3000000;
    FUN_00091a8c(0x14,0);
  }
  puVar1 = DAT_0009255c;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *DAT_00092558 = *DAT_00092558 & 0xfcffffe0;
  iVar8 = DAT_00092560;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *puVar1 = *puVar1 & 0x7fffffe0 | 0x8000000;
  do {
    uVar9 = *puVar1;
    DataMemoryBarrier(0x1f);
    FUN_00091a8c(1,0);
    if (-1 < (int)(uVar9 << 4)) goto LAB_00092428;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  FUN_00092a80(3,DAT_00092564);
LAB_00092428:
  iVar8 = DAT_00092560;
  puVar2 = DAT_0009255c;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *puVar1 = *puVar1 & 0xf8ffffff | 0x8b000000;
  do {
    uVar9 = *puVar2;
    DataMemoryBarrier(0x1f);
    FUN_00091a8c(1,0);
    if (-1 < (int)(uVar9 << 4)) goto LAB_0009245e;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  FUN_00092a80(3,DAT_00092568);
LAB_0009245e:
  FUN_00092a80(3,DAT_0009256c);
  return 0;
}

