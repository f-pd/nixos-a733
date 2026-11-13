// rea decompile_all
// name: FUN_00092180
// address: 0x92180
// body: available
// range: 0x92180-0x9222b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Ghidra Listing reports a terminal call at 0x92228 to 0x91a8c FUN_00091a8c (external=false, thunk=false, hasNoReturn=false); fallthrough is excluded by Ghidra's flow model. The reason for the terminal flow is not established by this observation.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00092180(uint *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  param_1[7] = param_1[7] & 0xfcffffff;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *param_1 = *param_1 & 0xf7ffffff;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *param_1 = *param_1 & 0xdfffffff;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *param_1 = param_2[3] << 0x10 | param_2[1] << 0x14 | param_2[2] | *param_2 << 8 |
             DAT_0009222c & *param_1;
  FUN_00091a8c(0x14,0);
  uVar1 = FUN_000920e6(param_1,0x20000000);
  FUN_000920e6(uVar1,0x4000000);
  do {
    DataMemoryBarrier(0x1f);
  } while ((int)(*param_1 << 5) < 0);
  iVar2 = 3;
  do {
    do {
      DataMemoryBarrier(0x1f);
    } while (-1 < (int)(*param_1 << 3));
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_00091a8c(0x14,0);
  FUN_000920e6(param_1,0x8000000);
  FUN_00091a8c(0x14,0);
  return;
}

