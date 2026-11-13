// rea decompile_all
// name: FUN_00092f58
// address: 0x92f58
// body: available
// range: 0x92f58-0x92f91 inclusive
// range: 0x92fb8-0x93021 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_00092f58(int param_1,int param_2,uint *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  uint extraout_r2;
  uint uVar5;
  uint extraout_r3;
  int iVar6;
  undefined8 uVar7;
  
  *param_3 = 0xfffffff8;
  puVar1 = (undefined4 *)FUN_00092f10(param_1,param_2,4,0xfffffff8,param_4);
  if (puVar1 != (undefined4 *)0x0) {
    iVar6 = param_2 + 4;
    iVar2 = FUN_00092e20(*puVar1);
    *param_3 = 0xfffffff5;
    uVar5 = iVar2 - 1;
    iVar4 = iVar6;
    switch(uVar5) {
    case 0:
      do {
        iVar6 = iVar4 + 1;
        pbVar3 = (byte *)FUN_00092f10(param_1,iVar4,1,uVar5,param_4);
        if (pbVar3 == (byte *)0x0) {
          return 9;
        }
        uVar5 = (uint)*pbVar3;
        iVar4 = iVar6;
      } while (uVar5 != 0);
      break;
    case 1:
    case 3:
    case 8:
      break;
    case 2:
      puVar1 = (undefined4 *)FUN_00092f10(param_1,iVar6,4,uVar5,param_4);
      if (puVar1 == (undefined4 *)0x0) {
        return 9;
      }
      uVar7 = FUN_00092e20(*puVar1);
      iVar6 = (int)uVar7 + param_2 + 0xc;
      uVar5 = FUN_00092e20(*(undefined4 *)(param_1 + 0x14),(int)((ulonglong)uVar7 >> 0x20),
                           (int)uVar7);
      if (((uVar5 < 0x10) && (7 < extraout_r2)) && ((extraout_r3 & 7) != 0)) {
        iVar6 = iVar6 + 4;
      }
      break;
    default:
      goto LAB_00092fea;
    }
    iVar4 = FUN_00092f10(param_1,param_2,iVar6 - param_2);
    if (iVar4 != 0) {
      *param_3 = iVar6 + 3U & 0xfffffffc;
      return iVar2;
    }
  }
LAB_00092fea:
  return 9;
}

