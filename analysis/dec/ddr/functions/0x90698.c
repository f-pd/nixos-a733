// rea decompile_all
// name: FUN_00090698
// address: 0x90698
// body: available
// range: 0x90698-0x90731 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_00090698(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  local_24 = param_2;
  uStack_20 = param_3;
  uStack_1c = param_4;
  iVar3 = FUN_00090424();
  puVar2 = DAT_0009074c;
  piVar1 = DAT_00090734;
  if (iVar3 == 0) {
    local_24 = iVar3;
    if (*DAT_00090734 == 0) {
      iVar3 = FUN_00093460(*DAT_0009074c,DAT_00090738);
      if (iVar3 < 0) {
        FUN_00092a80(3,DAT_0009073c);
      }
      else {
        iVar5 = FUN_00090320(&local_24);
        if (iVar5 != 0) {
          FUN_00092a80(3,DAT_00090740);
          return iVar5;
        }
        FUN_000929d4(&uStack_20,DAT_00090744,local_24);
        uVar6 = *puVar2;
        uVar4 = FUN_000903e0();
        iVar3 = FUN_000934c0(uVar6,iVar3,&uStack_20,uVar4);
        if (-1 < iVar3) {
          uVar4 = FUN_000903e0();
          *param_1 = uVar4;
          *piVar1 = 1;
          return 0;
        }
        FUN_00092a80(3,DAT_00090748,&uStack_20);
      }
    }
    else {
      uVar4 = FUN_000903e0();
      *param_1 = uVar4;
      iVar3 = 0;
    }
  }
  else {
    iVar3 = 0;
    uVar4 = FUN_000903e0();
    *param_1 = uVar4;
  }
  return iVar3;
}

