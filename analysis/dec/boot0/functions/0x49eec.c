// rea decompile_all
// name: FUN_00049eec
// address: 0x49eec
// body: available
// range: 0x49eec-0x49f33 inclusive
// range: 0x49f58-0x49fe3 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_00049eec(int param_1,int param_2,uint *param_3,undefined4 param_4)

{
  uint *puVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  *param_3 = 0xfffffff8;
  puVar1 = (uint *)FUN_00049e68(param_1,param_2,4,0xfffffff8,param_4);
  if (puVar1 != (uint *)0x0) {
    uVar5 = *puVar1;
    iVar6 = param_2 + 4;
    uVar7 = uVar5 >> 0x18 | uVar5 << 0x18 | ((uVar5 & 0xffff) >> 8) << 0x10 |
            ((uVar5 & 0xffffff) >> 0x10) << 8;
    *param_3 = 0xfffffff5;
    uVar5 = uVar7 - 1;
    uVar4 = uVar5;
    iVar3 = iVar6;
    switch(uVar5) {
    case 0:
      do {
        iVar6 = iVar3 + 1;
        pbVar2 = (byte *)FUN_00049e68(param_1,iVar3,1,uVar4,param_4);
        if (pbVar2 == (byte *)0x0) {
          return 9;
        }
        uVar4 = (uint)*pbVar2;
        uVar5 = 0;
        iVar3 = iVar6;
      } while (uVar4 != 0);
      break;
    case 1:
    case 3:
    case 8:
      break;
    case 2:
      puVar1 = (uint *)FUN_00049e68(param_1,iVar6,4,uVar5,param_4);
      if (puVar1 == (uint *)0x0) {
        return 9;
      }
      uVar5 = *puVar1;
      uVar4 = *(uint *)(param_1 + 0x14);
      uVar5 = uVar5 >> 0x18 | uVar5 << 0x18 | ((uVar5 & 0xffff) >> 8) << 0x10 |
              ((uVar5 & 0xffffff) >> 0x10) << 8;
      iVar6 = uVar5 + param_2 + 0xc;
      if ((((uVar4 >> 0x18 | uVar4 << 0x18 | ((uVar4 & 0xffff) >> 8) << 0x10 |
            ((uVar4 & 0xffffff) >> 0x10) << 8) < 0x10) && (7 < uVar5)) &&
         (uVar5 = (param_2 + 0xc) * 0x20000000, uVar5 != 0)) {
        iVar6 = iVar6 + 4;
      }
      break;
    default:
      goto LAB_00049f88;
    }
    iVar3 = FUN_00049e68(param_1,param_2,iVar6 - param_2,uVar5,param_4);
    if (iVar3 != 0) {
      *param_3 = iVar6 + 3U & 0xfffffffc;
      return uVar7;
    }
  }
LAB_00049f88:
  return 9;
}

