// rea decompile_all
// name: FUN_00048f38
// address: 0x48f38
// body: available
// range: 0x48f38-0x48f97 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00048f38(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_00048f9c;
  uVar1 = DAT_00048f98;
  DataMemoryBarrier(0x1f);
  *DAT_00048f9c = DAT_00048f98;
  DataMemoryBarrier(0x1f);
  puVar2[0x80] = uVar1;
  puVar2 = DAT_00048fa0;
  DataMemoryBarrier(0x1f);
  *DAT_00048fa0 = 0x3f;
  DataMemoryBarrier(0x1f);
  puVar2[0x80] = 0x7f;
  DataMemoryBarrier(0x1f);
  puVar2[0x100] = 0xf;
  puVar2 = DAT_00048fa4;
  DataMemoryBarrier(0x1f);
  *DAT_00048fa4 = 0xf1;
  DataMemoryBarrier(0x1f);
  puVar2[0x80] = 0xf1;
  DataMemoryBarrier(0x1f);
  puVar2[-0x802] = 1;
  DataMemoryBarrier(0x1f);
  puVar2[-0x782] = 1;
  return 0;
}

