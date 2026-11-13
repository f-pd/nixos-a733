// rea decompile_all
// name: FUN_00092574
// address: 0x92574
// body: available
// range: 0x92574-0x925d3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_00092574(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  FUN_00090690(DAT_000925d4);
  uVar3 = DAT_000925e4;
  uVar2 = DAT_000925dc;
  puVar1 = DAT_000925d8;
  *DAT_000925d8 = 0x40000;
  puVar1[1] = 0x30000;
  puVar1[2] = thunk_FUN_00090004;
  puVar1[3] = 0x40000;
  puVar1[4] = &DAT_000b0000;
  puVar1[5] = 0x40800000;
  puVar1[6] = 0x1000000;
  puVar1[7] = 0;
  puVar1[8] = uVar2;
  puVar1[9] = 0x800;
  uVar2 = DAT_000925e0;
  puVar1[10] = uVar3;
  puVar1[0xb] = uVar2;
  iVar4 = FUN_000920da();
  if ((iVar4 == 0) && (iVar4 = FUN_000909a4(), iVar4 == 0)) {
    FUN_0009005c();
  }
  return iVar4;
}

