// rea decompile_all
// name: FUN_000909a4
// address: 0x909a4
// body: available
// range: 0x909a4-0x90a89 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_000909a4(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34 [4];
  
  uVar3 = DAT_00090ab4;
  puVar2 = DAT_00090ab0;
  piVar1 = DAT_00090a90;
  iVar9 = 0;
  local_34[0] = *DAT_00090a8c;
  local_34[1] = DAT_00090a8c[1];
  local_34[2] = DAT_00090a8c[2];
  FUN_00092c30(DAT_00090a90,0,0x20);
  FUN_00092c30(&local_3c,0,8);
  do {
    iVar8 = local_34[iVar9];
    if ((iVar8 == 0) || (iVar9 == 2)) {
      if (*DAT_00090a90 == 0) {
        uVar3 = 0;
        if (DAT_00090a90[4] == 0) {
          FUN_00092a80(3,DAT_00090a94);
          uVar3 = 0xffffffed;
        }
      }
      else {
        uVar3 = 0;
      }
      return uVar3;
    }
    iVar4 = FUN_00093460(*puVar2,iVar8);
    if (iVar4 < 0) {
      FUN_00092a80(3,DAT_00090a98,iVar8,iVar4);
    }
    else {
      iVar5 = FUN_000934c0(*puVar2,iVar4,uVar3,&local_44);
      uVar7 = DAT_00090aa0;
      if (iVar5 < 0) {
        uVar7 = DAT_00090a9c;
      }
      else {
        uVar6 = *puVar2;
        piVar1[iVar9 * 4] = local_44;
        iVar5 = FUN_000934c0(uVar6,iVar4,uVar7,&local_3c);
        uVar7 = DAT_00090aa8;
        if (iVar5 < 0) {
          uVar7 = DAT_00090aa4;
        }
        else {
          uVar6 = *puVar2;
          piVar1[iVar9 * 4 + 1] = local_3c;
          piVar1[iVar9 * 4 + 2] = local_38;
          iVar4 = FUN_000934c0(uVar6,iVar4,uVar7,&local_40);
          if (-1 < iVar4) {
            piVar1[iVar9 * 4 + 3] = local_40;
            goto LAB_00090a1c;
          }
          uVar7 = DAT_00090aac;
        }
      }
      FUN_00092a80(3,uVar7,iVar8);
    }
LAB_00090a1c:
    iVar9 = iVar9 + 1;
  } while( true );
}

