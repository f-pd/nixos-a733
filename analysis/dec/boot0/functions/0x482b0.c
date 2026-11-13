// rea decompile_all
// name: FUN_000482b0
// address: 0x482b0
// body: available
// range: 0x482b0-0x482f1 inclusive
// range: 0x48502-0x48543 inclusive
// range: 0x48d4c-0x48d57 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


ulonglong FUN_000482b0(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  if (param_2 == 0) {
    uVar2 = FUN_00049d10(8);
    return (ulonglong)uVar2;
  }
  uVar3 = param_1 ^ param_2;
  uVar2 = param_2;
  if ((int)param_2 < 0) {
    uVar2 = -param_2;
  }
  if (uVar2 - 1 == 0) {
    if ((int)param_2 < 0) {
      param_1 = -param_1;
    }
    return CONCAT44(uVar2,param_1);
  }
  uVar1 = param_1;
  if ((int)param_1 < 0) {
    uVar1 = -param_1;
  }
  if (uVar2 < uVar1) {
    if ((uVar2 & uVar2 - 1) != 0) {
                    /* WARNING: Could not recover jumptable at 0x000482f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar4 = (*(code *)((0x1f - (LZCOUNT(uVar2) - LZCOUNT(uVar1))) * 0x10 + 0x482f8))(0);
      return uVar4;
    }
    uVar1 = uVar1 >> (0x1fU - LZCOUNT(uVar2) & 0xff);
    if ((int)uVar3 < 0) {
      uVar1 = -uVar1;
    }
    return CONCAT44(uVar2,uVar1);
  }
  if (uVar1 < uVar2) {
    param_1 = 0;
  }
  if (uVar1 == uVar2) {
    param_1 = (int)uVar3 >> 0x1f | 1;
  }
  return CONCAT44(uVar2,param_1);
}

