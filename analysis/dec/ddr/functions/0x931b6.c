// rea decompile_all
// name: FUN_000931b6
// address: 0x931b6
// body: available
// range: 0x931b6-0x93239 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_000931b6(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int local_20;
  int local_1c;
  
  local_20 = param_1;
  local_1c = param_2;
  iVar1 = FUN_00092e50();
  if (iVar1 == 0) {
    local_20 = 0;
    for (; -1 < param_2; param_2 = FUN_0009306c(param_1,param_2,&local_20)) {
      if (local_20 < 0) {
        return -1;
      }
      if ((((local_20 == 1) && (iVar1 = FUN_00093156(param_1,param_2,&local_1c), iVar1 != 0)) &&
          (param_4 <= local_1c)) && (iVar2 = FUN_00092c50(iVar1,param_3,param_4), iVar2 == 0)) {
        if (*(char *)(iVar1 + param_4) == '\0') {
          return param_2;
        }
        iVar2 = FUN_00092cd8(param_3,0x40,param_4);
        if ((iVar2 == 0) && (*(char *)(iVar1 + param_4) == '@')) {
          return param_2;
        }
      }
    }
    iVar1 = param_2;
    if (local_20 < 0) {
      iVar1 = -1;
    }
  }
  return iVar1;
}

