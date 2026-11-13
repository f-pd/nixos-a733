// rea decompile_all
// name: FUN_00092044
// address: 0x92044
// body: available
// range: 0x9201c-0x9203d inclusive
// range: 0x92044-0x920ab inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_00092044(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = FUN_00091fbc();
  iVar4 = FUN_000916d4(uVar3,0xe,0);
  uVar2 = DAT_000920b0;
  puVar1 = DAT_000920ac;
  if (iVar4 == 0) {
    DataMemoryBarrier(0x1f);
    *DAT_000920ac = DAT_000920b0;
    DataMemoryBarrier(0x1f);
    *puVar1 = uVar2;
    FUN_0009147c(uVar3,0xe,800);
    FUN_000914a8(uVar3,0xe,DAT_000920b4,0x438);
    FUN_000914a8(uVar3,0xe,DAT_000920b8,0x438);
    FUN_000914a8(uVar3,0xe,DAT_000920bc,0x230);
    iVar4 = FUN_00092230();
    if (iVar4 == 0) {
      DataMemoryBarrier(0x1f);
      DataMemoryBarrier(0x1f);
      *DAT_00092040 = *DAT_00092040 | 1;
      return 0;
    }
  }
  return iVar4;
}

