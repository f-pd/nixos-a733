// rea decompile_all
// name: FUN_0005c5d0
// address: 0x5c5d0
// body: available
// range: 0x5c5d0-0x5c68f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0005c5d0(int param_1,byte *param_2,undefined4 param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  
  iVar3 = DAT_0005c6b0;
  pbVar2 = DAT_0005c694;
  pbVar1 = DAT_0005c690;
  iVar8 = 0;
  iVar6 = param_1;
  pbVar5 = param_2;
  do {
    iVar4 = FUN_0005ba1c(param_1,param_2,0x5fb8,param_3,iVar6,pbVar5);
    if (iVar4 < 0) {
      if (iVar8 == 3) {
        pbVar7 = pbVar2;
      }
      else {
        pbVar7 = pbVar1;
      }
      FUN_0004993c(DAT_0005c69c,DAT_0005c698,0x32f,pbVar7);
      FUN_0005b2dc(param_2);
LAB_0005c610:
      if (iVar8 == 3) goto LAB_0005c614;
    }
    else {
      iVar6 = *(int *)(param_2 + 0x14);
      if (iVar6 == iVar3) {
        iVar4 = 0;
        iVar6 = *(int *)(param_2 + 0x18);
        param_2[0x18] = 0;
        param_2[0x19] = 0;
        param_2[0x1a] = 0;
        param_2[0x1b] = 0;
        for (pbVar5 = param_2; param_2 + *(int *)(param_2 + 0x1c) != pbVar5; pbVar5 = pbVar5 + 1) {
          iVar4 = iVar4 + (uint)*pbVar5;
        }
        if (iVar4 == iVar6) {
          FUN_000498e4(DAT_0005c6ac);
          return 0;
        }
        if (iVar8 == 3) {
          pbVar5 = pbVar2;
        }
        else {
          pbVar5 = pbVar1;
        }
        FUN_0004993c(DAT_0005c6a4,DAT_0005c698,0x345);
        goto LAB_0005c610;
      }
      if (iVar8 == 3) {
        pbVar7 = pbVar2;
      }
      else {
        pbVar7 = pbVar1;
      }
      FUN_0004993c(DAT_0005c6a8,DAT_0005c698,0x34e,pbVar7);
      if (iVar8 == 3) {
        FUN_0005b2dc(param_2);
LAB_0005c614:
        FUN_000498e4(DAT_0005c6a0);
        return 0xffffffff;
      }
    }
    iVar8 = iVar8 + 1;
  } while( true );
}

