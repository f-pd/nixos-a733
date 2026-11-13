// rea decompile_all
// name: FUN_00049ab4
// address: 0x49ab4
// body: available
// range: 0x49ab4-0x49b8f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00049ab4(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = DAT_00049b90;
  *(undefined1 *)(DAT_00049b90 + 0x800) = 1;
  FUN_0005dab0();
  iVar5 = 0;
  iVar2 = FUN_0005da04(1);
  do {
    iVar6 = iVar5 * 0x200;
    iVar3 = iVar2 + -8 + iVar5;
    iVar5 = iVar5 + 1;
    FUN_0005db08(iVar3,1,iVar1 + iVar6);
  } while (iVar5 != 4);
  uVar4 = FUN_000495f0(DAT_00049b94);
  iVar2 = FUN_000495ce(DAT_00049b90,DAT_00049b94,uVar4);
  iVar5 = *(int *)(DAT_00049b98 + 0xc);
  if (iVar2 == 0) {
    if (*(int *)(iVar1 + 0x14) == iVar5) {
      iVar6 = FUN_00049a44(DAT_00049b90,0x800,*(undefined4 *)(iVar1 + 0xc));
      iVar2 = 0;
      if (-1 < iVar6) {
        do {
          iVar6 = FUN_0005d9d8(iVar2);
          iVar3 = *(int *)(iVar1 + iVar2 + 0x600);
          if (iVar6 != iVar3) {
            FUN_0004993c(DAT_00049ba8,iVar3,iVar6);
            uVar4 = DAT_00049bac;
            goto LAB_00049b78;
          }
          iVar2 = iVar2 + 4;
        } while (iVar2 != 0x10);
        goto LAB_00049b88;
      }
      uVar4 = DAT_00049bb8;
    }
    else {
      FUN_0004993c(DAT_00049bb0);
      uVar4 = DAT_00049bb4;
    }
LAB_00049b78:
    FUN_0004993c(uVar4);
  }
  else {
    FUN_0004993c(DAT_00049b9c,DAT_00049b90);
  }
  iVar6 = 0;
  thunk_FUN_00047c40(DAT_00049b90,0,0x800);
  thunk_FUN_00047d1c(DAT_00049ba4,DAT_00049ba0,0x80);
  uVar4 = DAT_00049b94;
  iVar2 = DAT_00049b90;
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) | 1;
  FUN_000495a8(iVar2,uVar4);
  *(int *)(iVar1 + 0x14) = iVar5;
  do {
    uVar4 = FUN_0005d9d8(iVar6);
    iVar2 = iVar1 + iVar6;
    iVar6 = iVar6 + 4;
    *(undefined4 *)(iVar2 + 0x600) = uVar4;
  } while (iVar6 != 0x10);
LAB_00049b88:
  *(undefined1 *)(iVar1 + 0x800) = 0;
  return;
}

