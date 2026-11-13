// rea decompile_all
// name: FUN_000911e0
// address: 0x911e0
// body: available
// range: 0x911e0-0x912a9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_000911e0(undefined4 param_1,uint param_2,int *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int extraout_r2;
  int extraout_r3;
  int extraout_r3_00;
  int extraout_r3_01;
  int extraout_r3_02;
  uint local_1c;
  
  puVar1 = DAT_000912ac;
  local_1c = param_2;
  iVar2 = FUN_00093460(*DAT_000912ac,param_1,param_3,param_4,param_1);
  if (iVar2 < 0) {
    FUN_00092a80(3,DAT_000912b0,param_1);
  }
  else {
    iVar2 = FUN_00093344(*puVar1,iVar2,DAT_000912b4,&local_1c);
    uVar5 = param_2 * 0x14 + 0x14;
    if ((iVar2 == 0) || (local_1c < uVar5)) {
      FUN_00092a80(3,DAT_000912b8);
    }
    else {
      iVar6 = uVar5 + iVar2;
      uVar5 = FUN_000911da(*(undefined4 *)(iVar6 + -0x14),local_1c,iVar6,iVar2);
      if (uVar5 < 3) {
        iVar2 = *(int *)(DAT_000912c0 + uVar5 * 4);
        if (iVar2 != 0) {
          iVar6 = param_2 * 5 + 1;
          iVar3 = FUN_000911da(*(undefined4 *)(extraout_r3 + iVar6 * 4),DAT_000912c0,iVar6 * 4);
          iVar6 = extraout_r3_00 + extraout_r2;
          if (iVar3 == -1) {
            *param_3 = 0;
          }
          else {
            *param_3 = iVar3 + iVar2;
            if (iVar3 + iVar2 != 0) {
              iVar6 = FUN_000911da(*(undefined4 *)(iVar6 + 4));
              param_3[1] = iVar6;
              iVar6 = extraout_r3_02;
            }
          }
          iVar6 = FUN_000911da(*(undefined4 *)(iVar6 + 8));
          if (iVar6 == -2) {
            param_3[2] = 0;
            return 0;
          }
          param_3[2] = iVar2 + iVar6;
          if (iVar2 + iVar6 == 0) {
            return 0;
          }
          iVar2 = FUN_000911da(*(undefined4 *)(extraout_r3_01 + 0xc));
          param_3[3] = iVar2;
          return 0;
        }
        uVar4 = DAT_000912c4;
      }
      else {
        uVar4 = DAT_000912bc;
      }
      FUN_00092a80(3,uVar4,uVar5);
    }
    iVar2 = -0x16;
  }
  return iVar2;
}

