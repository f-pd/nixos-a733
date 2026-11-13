// rea decompile_all
// name: FUN_00093508
// address: 0x93508
// body: available
// range: 0x93508-0x93577 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00093508(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined8 uVar3;
  
  puVar1 = DAT_0009357c;
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {
    FUN_00092a80(3,DAT_00093578);
  }
  else {
    iVar2 = FUN_00093460(*DAT_0009357c,param_1,param_3,param_4,param_1,param_2,param_3);
    if (iVar2 < 0) {
      FUN_00092a80(3,DAT_00093580,iVar2);
    }
    else {
      iVar2 = FUN_000934c0(*puVar1,iVar2,param_2,0);
      if (iVar2 < 0) {
        FUN_00092a80(3,DAT_00093588,DAT_00093584,param_1,param_2,iVar2);
      }
      else {
        uVar3 = FUN_000a39ac(iVar2,param_3);
        if ((int)((ulonglong)uVar3 >> 0x20) == 0) {
          return (int)uVar3;
        }
        FUN_00092a80(3,DAT_0009358c,iVar2,param_3);
      }
    }
  }
  return 0xffffffff;
}

