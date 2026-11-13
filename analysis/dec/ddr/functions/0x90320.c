// rea decompile_all
// name: FUN_00090320
// address: 0x90320
// body: available
// range: 0x90320-0x90371 inclusive
// range: 0x90376-0x903c3 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_00090320(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_1c;
  int local_18;
  int iStack_14;
  
  puVar1 = DAT_000903c4;
  if (param_1 == (int *)0x0) {
    return -0x16;
  }
  *param_1 = 0;
  local_1c = param_2;
  local_18 = param_3;
  iStack_14 = param_4;
  iVar2 = FUN_00093460(*puVar1,DAT_000903c8,param_3,0,param_1);
  if (iVar2 < 0) {
    FUN_00092a80(3,DAT_000903cc,DAT_000903c8);
    return iVar2;
  }
  iVar3 = FUN_000934c0(*puVar1,iVar2,DAT_000903d0,&local_1c);
  if (iVar3 < 0) {
    uVar4 = DAT_000903d4;
    uVar5 = DAT_000903d0;
LAB_0009035c:
    FUN_00092a80(3,uVar4,uVar5);
    return -0x16;
  }
  switch(local_1c) {
  case 0:
    return 0;
  case 1:
    iVar2 = FUN_000901a4(param_1);
    break;
  case 2:
    iVar2 = FUN_00090258(iVar2,param_1);
    break;
  case 3:
    local_18 = 0;
    iStack_14 = 0;
    iVar3 = FUN_000901a4(&local_18);
    if ((iVar3 == 0) && (iVar3 = FUN_00090258(iVar2,&iStack_14), iVar3 == 0)) {
      *param_1 = iStack_14 + local_18 * 8;
      FUN_00092a80(3,DAT_000903d8);
    }
    return iVar3;
  default:
    uVar4 = DAT_000903dc;
    uVar5 = local_1c;
    goto LAB_0009035c;
  }
  return iVar2;
}

