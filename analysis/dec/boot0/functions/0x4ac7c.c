// rea decompile_all
// name: FUN_0004ac7c
// address: 0x4ac7c
// body: available
// range: 0x4ac7c-0x4ad25 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0004ac7c(undefined4 param_1,undefined4 param_2,int param_3,byte *param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  undefined1 *puVar6;
  undefined1 *puVar5;
  undefined4 uVar7;
  bool bVar8;
  undefined4 local_1c;
  
  piVar1 = DAT_0004ad28;
  if (DAT_0004ad28[1] == 0) {
    uVar7 = 0xfffffffc;
  }
  else {
    local_1c = param_2;
    iVar2 = FUN_0004aa48();
    if ((iVar2 == 0) && (iVar2 = FUN_0004aa88(param_1,0), iVar2 == 0)) {
      if (param_3 < 3) {
        if (param_3 == 2) {
          iVar2 = 1;
        }
        else {
          iVar2 = 0;
        }
      }
      else {
        iVar2 = 2;
      }
      puVar6 = (undefined1 *)(iVar2 + (int)&local_1c);
      do {
        puVar5 = puVar6 + -1;
        iVar2 = FUN_0004aa10(*puVar6);
        if (iVar2 != 0) goto LAB_0004ac9a;
        puVar6 = puVar5;
      } while ((int)puVar5 - (int)&local_1c != -1);
      iVar2 = *piVar1;
      pbVar4 = param_4;
      while( true ) {
        uVar7 = 0;
        if (param_4 + param_5 == pbVar4) goto LAB_0004ac9e;
        *(uint *)(iVar2 + 8) = (uint)*pbVar4;
        *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | 8;
        iVar3 = 0xffff;
        do {
          bVar8 = iVar3 == 0;
          iVar3 = iVar3 + -1;
          if (bVar8) goto LAB_0004ac9a;
        } while (-1 < *(int *)(iVar2 + 0xc) << 0x1c);
        if (iVar3 == 0) break;
        iVar3 = 0xffff;
        do {
          bVar8 = iVar3 == 0;
          iVar3 = iVar3 + -1;
          if (bVar8) goto LAB_0004ac9a;
        } while (*(int *)(iVar2 + 0x10) != 0x28);
        pbVar4 = pbVar4 + 1;
        if (iVar3 == 0) break;
      }
    }
LAB_0004ac9a:
    uVar7 = 0xffffffff;
LAB_0004ac9e:
    FUN_0004aad4();
  }
  return uVar7;
}

