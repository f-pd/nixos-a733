// rea decompile_all
// name: FUN_00049990
// address: 0x49990
// body: available
// range: 0x49990-0x499f5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00049990(int *param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  FUN_00048dbc();
  param_2 = param_2 >> 2;
  iVar6 = param_1[5];
  iVar5 = 0;
  param_1[5] = DAT_000499f8;
  uVar1 = param_2;
  piVar3 = param_1;
  do {
    uVar1 = uVar1 - 4;
    iVar5 = iVar5 + *piVar3 + piVar3[1] + piVar3[2] + piVar3[3];
    piVar3 = piVar3 + 4;
  } while (3 < uVar1);
  piVar4 = param_1 + ((param_2 - 4 >> 2) + 1) * 4;
  piVar3 = piVar4 + (param_2 & 3);
  for (; piVar4 != piVar3; piVar4 = piVar4 + 1) {
    iVar5 = iVar5 + *piVar4;
  }
  param_1[5] = iVar6;
  FUN_00048dd8();
  uVar2 = 0;
  if (iVar5 != iVar6) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

