// rea decompile_all
// name: FUN_0005cc60
// address: 0x5cc60
// body: available
// range: 0x5cc60-0x5ccad inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_0005cc60(int param_1)

{
  int iVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  char local_24;
  undefined4 local_14;
  
  local_30 = 8;
  local_14 = 0;
  if ((DAT_0005ccb0 & *(uint *)(param_1 + 0x24)) == 0) {
    local_28 = 0xaa;
  }
  else {
    local_28 = 0x1aa;
  }
  local_2c = 0x15;
  iVar1 = FUN_0005b324(param_1,&local_30);
  if (iVar1 == 0) {
    if (local_24 == -0x56) {
      *(undefined4 *)(param_1 + 0x28) = DAT_0005ccb8;
    }
    else {
      iVar1 = -0x11;
    }
  }
  else {
    FUN_000498e4(DAT_0005ccb4,*(undefined4 *)(param_1 + 0x30));
  }
  return iVar1;
}

