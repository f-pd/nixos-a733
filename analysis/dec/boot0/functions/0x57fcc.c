// rea decompile_all
// name: FUN_00057fcc
// address: 0x57fcc
// body: available
// range: 0x57fcc-0x58039 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00057fcc(uint param_1,uint param_2,uint param_3,undefined4 param_4,uint param_5,
                 undefined4 param_6,int param_7)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = DAT_00058040;
  puVar1 = DAT_0005803c;
  *(uint *)((DAT_0005803c[1] + 0xa02180) * 0x10) =
       (*DAT_0005803c & 0xf) << 0x14 | 0x8000000 | param_3 & 0x7fff | (param_2 & 1) << 0x10 |
       param_3 >> 1 & 0x8000 | (param_1 & 3) << 0x11 | param_7 << 0x1f | (param_5 & 1) << 0x1a;
  *(undefined4 *)(puVar1[1] * 0x10 + iVar2) = param_4;
  if (param_5 != 0) {
    *(undefined4 *)(puVar1[1] * 0x10 + DAT_00058044) = param_6;
  }
  puVar1[1] = puVar1[1] + 1;
  *puVar1 = *puVar1 + 1;
  return;
}

