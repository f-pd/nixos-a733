// rea decompile_all
// name: FUN_0005dc30
// address: 0x5dc30
// body: available
// range: 0x5db38-0x5dc09 inclusive
// range: 0x5dc30-0x5dc35 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0005dc30(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  int local_38 [5];
  
  thunk_FUN_00047c40(local_38,0,0x10);
  *(undefined4 *)(DAT_0005dc0c + 4) = DAT_0005dc10;
  uVar3 = FUN_0005da64();
  iVar4 = FUN_0005dab0();
  uVar6 = DAT_0005dc2c;
  iVar2 = DAT_0005dc28;
  iVar1 = DAT_0005dc14;
  if (iVar4 == 0) {
    local_38[0] = FUN_0005da24(1);
    local_38[1] = FUN_0005da44(1);
    iVar4 = 0;
    do {
      iVar8 = local_38[iVar4];
      if (iVar8 == 0) {
        uVar6 = 4;
        goto LAB_0005db94;
      }
      iVar5 = FUN_0005baa8(uVar3,iVar8,0x40,DAT_0005dc14);
      if (iVar5 == 0) {
LAB_0005db92:
        uVar6 = 3;
        goto LAB_0005db94;
      }
      if (*(int *)(iVar1 + 0x10) == iVar2) {
        uVar9 = *(uint *)(iVar1 + 0x24);
        if ((0x8000 < uVar9) &&
           (iVar8 = FUN_0005baa8(uVar3,iVar8 + 0x40,uVar9 - 0x7e01 >> 9,uVar6), iVar8 == 0))
        goto LAB_0005db92;
        iVar8 = FUN_00049990(iVar1,uVar9);
        if (iVar8 == 0) break;
        uVar7 = DAT_0005dc24;
      }
      else {
        uVar7 = DAT_0005dc20;
      }
      iVar4 = iVar4 + 1;
      FUN_0004993c(uVar7);
    } while (iVar4 != 4);
    FUN_0005d6ac(uVar3,DAT_0005dc1c,0x10);
    uVar7 = 0;
  }
  else {
    uVar6 = 2;
LAB_0005db94:
    uVar7 = 0xffffffff;
    FUN_0004993c(DAT_0005dc18,uVar6);
    FUN_0005d6ac(uVar3,DAT_0005dc1c,0x10);
  }
  return uVar7;
}

