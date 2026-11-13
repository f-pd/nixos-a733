// rea decompile_all
// name: FUN_00057a4c
// address: 0x57a4c
// body: available
// range: 0x57a4c-0x57b5b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Ghidra Listing reports a terminal call at 0x57b52 to 0x48d80 FUN_00048d80 (external=false, thunk=false, hasNoReturn=false); fallthrough is excluded by Ghidra's flow model. The reason for the terminal flow is not established by this observation.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00057a4c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  
  puVar5 = DAT_00057b78;
  puVar4 = DAT_00057b68;
  puVar3 = DAT_00057b64;
  puVar2 = DAT_00057b60;
  puVar1 = DAT_00057b5c;
  *DAT_00057b5c = *DAT_00057b5c & 0x7fffffff | 0x8000000;
  *puVar2 = *puVar2 & 0xfffffffe;
  *puVar2 = *puVar2 & 0xfffeffff;
  *puVar3 = *puVar3 & 0xfffeffff;
  *puVar3 = *puVar3 & 0xfffffffe;
  *puVar3 = *puVar3 | 0x10000;
  *puVar3 = *puVar3 | 1;
  *puVar4 = *puVar4 & 0xffffd9ff | 0x100;
  FUN_00048fa8();
  *puVar4 = *puVar4 & 0xfffffeff | 0x2600;
  puVar4 = DAT_00057b6c;
  DataMemoryBarrier(0x1f);
  *puVar5 = *puVar5 & 0x7fffffff;
  *puVar4 = *puVar4 & 0x7fffffff | 0x8000000;
  FUN_00048d80(5);
  FUN_0004b7a0(*param_1,puVar5);
  puVar5 = DAT_00057b74;
  if (*DAT_00057b70 == '\0') {
    uVar6 = *puVar4 & 0xffffffe0 | 3;
  }
  else {
    uVar6 = *puVar4 & 0xffffffe0 | 1;
  }
  *puVar4 = uVar6 | 0x8000000;
  *puVar4 = *puVar4 & 0xf8ffffff | 0x8000000;
  *puVar3 = *puVar3 | 0x10000;
  *puVar3 = *puVar3 | 1;
  *puVar1 = *puVar1 & 0xf8ffffff | 0x89000000;
  *puVar2 = *puVar2 | 0x10000;
  *puVar2 = *puVar2 | 1;
  *puVar5 = *puVar5 & 0xf8ffffff | 0xcb000000;
  *puVar4 = *puVar4 | 0x88000000;
  FUN_00048d80(5,puVar5,puVar4,param_4);
  return;
}

