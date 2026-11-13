// rea decompile_all
// name: FUN_0004b4cc
// address: 0x4b4cc
// body: available
// range: 0x4b4cc-0x4b53f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0004b4cc(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = DAT_0004b544;
  iVar4 = DAT_0004b540;
  param_1 = param_1 >> 1;
  piVar2 = (int *)&DAT_40000000;
  for (iVar3 = 0; iVar3 != param_2; iVar3 = iVar3 + 1) {
    *piVar2 = iVar3 + iVar4;
    piVar2[param_1 * 0x40000] = iVar3 + iVar1;
    piVar2 = piVar2 + 1;
  }
  iVar4 = 0;
  piVar2 = (int *)&DAT_40000000;
  while( true ) {
    if (iVar3 == iVar4) {
      FUN_0004993c(DAT_0004b548);
      return 0;
    }
    if (iVar4 + DAT_0004b544 != piVar2[param_1 * 0x40000]) break;
    if (iVar4 + DAT_0004b540 != *piVar2) {
      FUN_0004993c(DAT_0004b54c);
      return 1;
    }
    iVar4 = iVar4 + 1;
    piVar2 = piVar2 + 1;
  }
  FUN_0004993c(DAT_0004b54c,piVar2[param_1 * 0x40000],iVar4 + DAT_0004b544,
               piVar2 + param_1 * 0x40000,param_4);
  FUN_0004993c(DAT_0004b550);
  return 1;
}

