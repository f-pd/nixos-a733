// rea decompile_all
// name: FUN_00092a80
// address: 0x92a80
// body: available
// range: 0x92a80-0x92afd inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00092a80(int param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  undefined8 uVar4;
  undefined1 auStack_134 [8];
  undefined1 *local_12c;
  undefined1 *local_128;
  undefined4 local_124;
  undefined1 local_120 [255];
  undefined1 uStack_21;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  pcVar3 = param_2;
  while( true ) {
    if (*pcVar3 != '\n') break;
    pcVar3 = pcVar3 + 1;
  }
  uStack_8 = param_3;
  uStack_4 = param_4;
  for (iVar2 = 0; iVar2 != (int)pcVar3 - (int)param_2; iVar2 = iVar2 + 1) {
    local_120[iVar2] = 10;
  }
  uVar4 = FUN_00091a7a();
  FUN_00092a00(local_120 + iVar2,0x100 - iVar2,DAT_00092b00);
  iVar2 = FUN_00092bc6(local_120);
  local_128 = &uStack_21;
  local_12c = local_120 + iVar2;
  local_124 = DAT_00092b04;
  uVar1 = FUN_0009267c(auStack_134,pcVar3,&uStack_8,DAT_00092b04,uVar4,&uStack_8);
  *local_12c = 0;
  if (param_1 << 0x1f < 0) {
    FUN_00092a5c(local_120);
  }
  return uVar1;
}

