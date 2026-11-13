// rea decompile_all
// name: FUN_0004a990
// address: 0x4a990
// body: available
// range: 0x4a990-0x4a9eb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0004a990(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = DAT_0004a9ec;
  iVar3 = 0;
  do {
    iVar1 = FUN_0004a95c(iVar3);
    if (iVar1 != 0) {
      FUN_0004993c(uVar2,iVar3,iVar1);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 8);
  iVar1 = FUN_0004a95c(2);
  iVar3 = DAT_0004a9fc;
  if (iVar1 == DAT_0004a9f0) {
    uVar2 = DAT_0004a9f4;
  }
  else {
    if (iVar1 != DAT_0004a9f8) {
      return 0;
    }
    FUN_0004a940(2,DAT_0004aa00);
    do {
      FUN_00048da4(0x96);
      iVar1 = FUN_0004a95c(2);
    } while (iVar1 != iVar3);
    uVar2 = DAT_0004aa04;
  }
  FUN_0004993c(uVar2);
  return 1;
}

