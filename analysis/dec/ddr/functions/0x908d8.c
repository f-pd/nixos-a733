// rea decompile_all
// name: FUN_000908d8
// address: 0x908d8
// body: available
// range: 0x908d8-0x90937 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_000908d8(uint param_1,uint param_2,int param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  if (((*DAT_00090938 == 0) || (param_1 < (uint)DAT_00090938[1])) ||
     ((uint)DAT_00090938[2] < param_1)) {
    if (((DAT_00090938[4] == 0) || (param_1 < (uint)DAT_00090938[5])) ||
       ((uint)DAT_00090938[6] < param_1)) {
      uVar1 = DAT_0009093c;
      param_2 = param_1;
      goto LAB_00090908;
    }
    iVar3 = 1;
  }
  else {
    iVar3 = 0;
  }
  if (param_2 < 0x20) {
    piVar5 = DAT_00090938 + iVar3 * 4;
    iVar3 = *piVar5;
    iVar2 = piVar5[1];
    iVar4 = piVar5[2];
    iVar6 = piVar5[3];
    param_4[4] = param_3;
    param_4[5] = param_1;
    param_4[6] = param_2;
    *param_4 = iVar3;
    param_4[1] = iVar2;
    param_4[2] = iVar4;
    param_4[3] = iVar6;
    return 0;
  }
  uVar1 = DAT_00090940;
LAB_00090908:
  FUN_00092a80(3,uVar1,param_2,DAT_00090938,param_4);
  return 0xffffffea;
}

