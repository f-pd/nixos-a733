// rea decompile_all
// name: FUN_00092e50
// address: 0x92e50
// body: available
// range: 0x92e50-0x92f0b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4
FUN_00092e50(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int extraout_r2;
  int extraout_r2_00;
  undefined4 extraout_r2_01;
  int extraout_r2_02;
  int extraout_r2_03;
  int extraout_r2_04;
  int extraout_r2_05;
  int extraout_r2_06;
  int extraout_r2_07;
  uint extraout_r3;
  uint extraout_r3_00;
  uint extraout_r3_01;
  uint extraout_r3_02;
  bool bVar6;
  undefined8 uVar7;
  
  if (((uint)param_1 & 7) != 0) {
    return 0xffffffed;
  }
  iVar1 = FUN_00092e20(*param_1,param_2,param_1,0,param_4);
  if (iVar1 != DAT_00092f0c) {
    return 0xfffffff7;
  }
  uVar2 = FUN_00092e20(*(undefined4 *)(extraout_r2 + 0x14));
  if (((uVar2 < 2) || (uVar3 = FUN_00092e20(*(undefined4 *)(extraout_r2_00 + 0x18)), 0x11 < uVar3))
     || (uVar2 < uVar3)) {
    return 0xfffffff6;
  }
  uVar3 = FUN_00092e3e(extraout_r2_01);
  uVar4 = FUN_00092e20(*(undefined4 *)(extraout_r2_02 + 4));
  if (((uVar3 <= uVar4) && (-1 < (int)uVar4)) &&
     ((uVar4 = FUN_00092e20(*(undefined4 *)(extraout_r2_03 + 0x10)), uVar3 <= uVar4 &&
      (uVar4 <= extraout_r3)))) {
    uVar4 = FUN_00092e20(*(undefined4 *)(extraout_r2_04 + 8));
    if (uVar2 < 0x11) {
      if (uVar4 < uVar3) {
        return 0xfffffff8;
      }
      bVar6 = uVar4 <= extraout_r3_00;
      iVar1 = extraout_r2_05;
    }
    else {
      uVar7 = FUN_00092e20(*(undefined4 *)(extraout_r2_05 + 0x24),uVar4);
      uVar4 = (uint)((ulonglong)uVar7 >> 0x20);
      if (uVar4 < uVar3) {
        return 0xfffffff8;
      }
      if (extraout_r3_01 < uVar4) {
        return 0xfffffff8;
      }
      if (CARRY4((uint)uVar7,uVar4)) {
        return 0xfffffff8;
      }
      bVar6 = (uint)uVar7 + uVar4 <= extraout_r3_01;
      iVar1 = extraout_r2_06;
    }
    if (bVar6) {
      uVar5 = FUN_00092e20(*(undefined4 *)(iVar1 + 0xc),uVar4);
      uVar7 = FUN_00092e20(*(undefined4 *)(extraout_r2_07 + 0x20),uVar5);
      uVar2 = (uint)((ulonglong)uVar7 >> 0x20);
      if (((uVar3 <= uVar2) && (uVar2 <= extraout_r3_02)) && (!CARRY4(uVar2,(uint)uVar7))) {
        if (extraout_r3_02 < uVar2 + (uint)uVar7) {
          return 0xfffffff8;
        }
        return 0;
      }
    }
  }
  return 0xfffffff8;
}

