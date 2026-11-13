// rea decompile_all
// name: FUN_0004f57c
// address: 0x4f57c
// body: available
// range: 0x4f57c-0x4f589 inclusive
// range: 0x590c4-0x590ed inclusive
// range: 0x5a1d4-0x5a1fd inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0004f57c(int param_1)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  
  puVar4 = DAT_0005a208;
  iVar3 = DAT_0005a204;
  puVar5 = DAT_000590f8;
  iVar1 = DAT_000590f4;
  if (*(int *)(param_1 + 4) == 8) {
    puVar4 = DAT_000590f0;
    do {
      puVar6 = puVar4 + 1;
      *puVar4 = *(undefined2 *)(iVar1 + ((uint)(puVar4 + -0x54d0000) & 0xfffffffe));
      puVar2 = DAT_000590fc;
      puVar4 = puVar6;
    } while (puVar6 != puVar5);
    do {
      puVar5 = puVar6 + 1;
      *puVar6 = 0;
      puVar6 = puVar5;
    } while (puVar5 != puVar2);
    return;
  }
  puVar5 = DAT_0005a200;
  do {
    puVar6 = puVar5 + 1;
    *puVar5 = *(undefined2 *)(iVar3 + ((uint)(puVar5 + -0x54d0000) & 0xfffffffe));
    puVar2 = DAT_0005a20c;
    puVar5 = puVar6;
  } while (puVar6 != puVar4);
  do {
    puVar5 = puVar6 + 1;
    *puVar6 = 0;
    puVar6 = puVar5;
  } while (puVar5 != puVar2);
  return;
}

