// rea decompile_all
// name: FUN_00091088
// address: 0x91088
// body: available
// range: 0x91088-0x910fd inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_00091088(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined2 local_44;
  undefined1 auStack_40 [48];
  
  local_4c = 0;
  uStack_48 = 0;
  local_44 = 0;
  FUN_000929d4(&local_4c,DAT_00091100,param_1);
  iVar1 = FUN_0009133c(&local_4c,0,3);
  if (-1 < iVar1) {
    FUN_00091a8c(10,0);
    iVar1 = FUN_000912c8(&local_4c,0,3);
    if (-1 < iVar1) {
      iVar1 = FUN_0009365c(&local_4c,DAT_00091104,auStack_40,2);
      if (iVar1 == 2) {
        iVar2 = FUN_00090b5c(auStack_40,2);
        iVar1 = 0;
        if (iVar2 != 0) {
          return -1;
        }
      }
      else if (iVar1 < 0) {
        return iVar1;
      }
      if (*(code **)(DAT_00091108 + 4) != (code *)0x0) {
        iVar1 = (**(code **)(DAT_00091108 + 4))(param_1,param_2);
      }
    }
  }
  return iVar1;
}

