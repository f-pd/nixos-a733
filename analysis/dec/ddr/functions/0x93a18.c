// rea decompile_all
// name: FUN_00093a18
// address: 0x93a18
// body: available
// range: 0x93a18-0x93a5b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_00093a18(uint param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)((ulonglong)param_1 * (ulonglong)DAT_00093a5c >> 0x24);
  *param_2 = DAT_00093a60 & *param_2 | 0x1000000 | (uVar2 - 1) * 0x100;
  uVar1 = *param_2;
  *param_2 = uVar1 | 0xc0000000;
  *param_2 = uVar1 | 0xe0000000;
  FUN_00091a8c(0x14);
  do {
  } while (-1 < (int)(*param_2 << 3));
  *param_2 = uVar1 | 0xe8000000;
  return uVar2 * 0x18;
}

