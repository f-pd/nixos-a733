// rea decompile_all
// name: FUN_000977f4
// address: 0x977f4
// body: available
// range: 0x977f4-0x97801 inclusive
// range: 0xa1534-0xa155d inclusive
// range: 0xa2644-0xa266d inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000977f4(int param_1)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  
  puVar4 = DAT_000a2678;
  iVar3 = DAT_000a2674;
  puVar5 = DAT_000a1568;
  iVar1 = DAT_000a1564;
  if (*(int *)(param_1 + 4) == 8) {
    puVar4 = DAT_000a1560;
    do {
      puVar6 = puVar4 + 1;
      *puVar4 = *(undefined2 *)(iVar1 + ((uint)(puVar4 + -0x54d0000) & 0xfffffffe));
      puVar2 = DAT_000a156c;
      puVar4 = puVar6;
    } while (puVar6 != puVar5);
    do {
      puVar5 = puVar6 + 1;
      *puVar6 = 0;
      puVar6 = puVar5;
    } while (puVar5 != puVar2);
    return;
  }
  puVar5 = DAT_000a2670;
  do {
    puVar6 = puVar5 + 1;
    *puVar5 = *(undefined2 *)(iVar3 + ((uint)(puVar5 + -0x54d0000) & 0xfffffffe));
    puVar2 = DAT_000a267c;
    puVar5 = puVar6;
  } while (puVar6 != puVar4);
  do {
    puVar5 = puVar6 + 1;
    *puVar6 = 0;
    puVar6 = puVar5;
  } while (puVar5 != puVar2);
  return;
}

