// rea decompile_all
// name: FUN_0004b5ac
// address: 0x4b5ac
// body: available
// range: 0x4b5ac-0x4b601 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_0004b5ac(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  
  iVar1 = DAT_0004b608;
  iVar4 = param_2 * 0x400000;
  do {
  } while (*(int *)(DAT_0004b604 + iVar4) << 0x1f < 0);
  uVar2 = 1 << (param_3 + 4U & 0xff);
  *(uint *)(iVar4 + DAT_0004b608) = uVar2 | 1;
  *(int *)(iVar4 + DAT_0004b60c) = param_4 << 8;
  *(uint *)(iVar4 + iVar1) = uVar2 | 0x80000001;
  do {
  } while (*(int *)(iVar4 + iVar1) < 0);
  if ((*(int *)(param_1 + 4) == 8) && (param_2 == 1)) {
    uVar2 = *DAT_0004b610 & 0xff;
  }
  else {
    if (param_2 == 0) {
      puVar3 = DAT_0004b614;
    }
    else {
      puVar3 = DAT_0004b610;
    }
    uVar2 = (*puVar3 & 0xffff) >> 8;
  }
  return uVar2;
}

