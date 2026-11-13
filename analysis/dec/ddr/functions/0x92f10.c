// rea decompile_all
// name: FUN_00092f10
// address: 0x92f10
// body: available
// range: 0x92f10-0x92f57 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_00092f10(int param_1)

{
  uint uVar1;
  uint extraout_r2;
  uint extraout_r2_00;
  int extraout_r3;
  int extraout_r3_00;
  int extraout_r3_01;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  lVar4 = FUN_00092e20(*(undefined4 *)(param_1 + 8));
  uVar1 = (uint)((ulonglong)lVar4 >> 0x20);
  uVar3 = (uint)lVar4 + uVar1;
  if ((lVar4 < 0) || (CARRY4((uint)lVar4,uVar1))) {
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    if ((!CARRY4(uVar3,extraout_r2)) &&
       (uVar1 = FUN_00092e20(*(undefined4 *)(param_1 + 4)), iVar2 = extraout_r3,
       uVar3 + extraout_r2 <= uVar1)) {
      uVar5 = FUN_00092e20(*(undefined4 *)(param_1 + 0x14));
      uVar1 = (uint)((ulonglong)uVar5 >> 0x20);
      if (((uint)uVar5 < 0x11) ||
         ((iVar2 = extraout_r3_00, !CARRY4(uVar1,extraout_r2_00) &&
          (uVar5 = FUN_00092e20(*(undefined4 *)(param_1 + 0x24),uVar1 + extraout_r2_00),
          iVar2 = extraout_r3_01, (uint)((ulonglong)uVar5 >> 0x20) <= (uint)uVar5)))) {
        iVar2 = param_1 + uVar3;
      }
    }
  }
  return iVar2;
}

