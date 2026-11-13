// rea decompile_all
// name: FUN_00057f44
// address: 0x57f44
// body: available
// range: 0x57f44-0x57fb9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00057f44(uint param_1,uint param_2,uint param_3,uint param_4,undefined4 param_5,int param_6
                 )

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_00057fbc;
  if (param_3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (*DAT_00057fbc & 0xf) << 0x14;
  }
  *(uint *)((DAT_00057fbc[1] + 0xa02180) * 0x10) =
       (param_3 & 1) << 0x1b | (param_4 & 1) << 0x1a | 0x80000 | param_6 << 0x1f | uVar2;
  *(undefined4 *)(puVar1[1] * 0x10 + DAT_00057fc0) = 0;
  if (param_4 != 0) {
    *(undefined4 *)(puVar1[1] * 0x10 + DAT_00057fc4) = param_5;
  }
  if (param_3 == 0) {
    *(uint *)(puVar1[1] * 0x10 + DAT_00057fc8) = (param_1 & 1) << 0x18 | param_2 & 0xffffff;
  }
  else {
    *puVar1 = *puVar1 + 1;
  }
  puVar1[1] = puVar1[1] + 1;
  return;
}

