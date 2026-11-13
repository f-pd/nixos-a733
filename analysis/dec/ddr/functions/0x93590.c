// rea decompile_all
// name: FUN_00093590
// address: 0x93590
// body: available
// range: 0x93590-0x93645 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00093590(undefined4 param_1,undefined4 param_2,undefined4 *param_3,uint param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int extraout_r2;
  int extraout_r3;
  int extraout_r3_00;
  int extraout_r3_01;
  int extraout_r3_02;
  int extraout_r3_03;
  undefined8 uVar5;
  uint local_1c;
  
  local_1c = param_4;
  uVar2 = FUN_00093508(param_1,param_2,6,param_4,param_1,param_2,param_3);
  puVar1 = DAT_00093658;
  if (((int)uVar2 < 0) || (uVar2 <= param_4)) {
    FUN_00092a80(3,DAT_00093648,param_4);
  }
  else {
    iVar3 = FUN_00093460(*DAT_00093658,param_1);
    if (iVar3 < 0) {
      FUN_00092a80(3,DAT_0009364c,iVar3);
    }
    else {
      uVar5 = FUN_00093344(*puVar1,iVar3,param_2,&local_1c);
      iVar3 = (int)uVar5;
      if ((iVar3 != 0) && (-1 < (int)local_1c)) {
        uVar4 = FUN_00093504(*(undefined4 *)(iVar3 + param_4 * 0x18),(int)((ulonglong)uVar5 >> 0x20)
                             ,param_4 * 6,iVar3);
        *param_3 = uVar4;
        uVar5 = FUN_00093504(*(undefined4 *)(extraout_r3 + (extraout_r2 + 1) * 4),
                             (extraout_r2 + 1) * 4);
        param_3[1] = (int)uVar5;
        uVar4 = FUN_00093504(*(undefined4 *)(extraout_r3_00 + (int)((ulonglong)uVar5 >> 0x20) + 4));
        param_3[2] = uVar4;
        uVar4 = FUN_00093504(*(undefined4 *)(extraout_r3_01 + 8));
        param_3[3] = uVar4;
        uVar4 = FUN_00093504(*(undefined4 *)(extraout_r3_02 + 0xc));
        param_3[4] = uVar4;
        uVar4 = FUN_00093504(*(undefined4 *)(extraout_r3_03 + 0x10));
        param_3[5] = uVar4;
        return 0;
      }
      FUN_00092a80(3,DAT_00093654,DAT_00093650,param_1,param_2,local_1c);
    }
  }
  return 0xffffffff;
}

