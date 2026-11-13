// rea decompile_all
// name: FUN_0004af60
// address: 0x4af60
// body: available
// range: 0x4af60-0x4b0bd inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_0004af60(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  uint uVar11;
  int local_58;
  int local_54;
  uint local_50;
  int local_4c;
  undefined1 auStack_48 [36];
  
  local_54 = 1;
  uVar10 = *DAT_0004b0c0;
  iVar3 = FUN_0004a454(uVar10,DAT_0004b0c4);
  if (iVar3 < 0) {
    FUN_0004993c(DAT_0004b0cc,DAT_0004b0c8,DAT_0004b0c4);
    iVar4 = iVar3;
  }
  else {
    iVar4 = FUN_0004a470(uVar10,iVar3);
    if (iVar4 == 0) {
      iVar4 = -1;
      FUN_0004993c(DAT_0004b0d0,DAT_0004b0c8,DAT_0004b0c4);
    }
    else {
      iVar4 = FUN_0004a498(uVar10,iVar3,DAT_0004b0d4,&local_50);
      piVar1 = DAT_0004b10c;
      if (iVar4 < 0) {
        uVar10 = DAT_0004b0d8;
        puVar9 = DAT_0004b0c4;
LAB_0004afc2:
        FUN_0004993c(uVar10,DAT_0004b0c8,puVar9);
      }
      else {
        for (uVar11 = 0; piVar2 = DAT_0004b10c, uVar11 < local_50; uVar11 = uVar11 + 1) {
          FUN_00049910(auStack_48,DAT_0004b0dc,uVar11);
          iVar5 = FUN_0004a24a(uVar10,iVar3,auStack_48);
          if (iVar5 < 0) {
            FUN_0004993c(DAT_0004b0e0,DAT_0004b0c8,auStack_48);
            return iVar5;
          }
          uVar6 = FUN_0004a37e(uVar10,iVar5,DAT_0004b0e4,&local_58);
          if (local_58 < 0) {
            puVar9 = auStack_48;
            uVar10 = DAT_0004b0e8;
            goto LAB_0004afc2;
          }
          uVar7 = FUN_000495f0(DAT_0004b0ec);
          iVar8 = FUN_000495ce(uVar6,DAT_0004b0ec,uVar7);
          if (iVar8 == 0) {
            uVar6 = FUN_0004a37e(uVar10,iVar5,DAT_0004b0f0,&local_58);
            if (local_58 < 0) {
              puVar9 = auStack_48;
              uVar10 = DAT_0004b0f4;
              goto LAB_0004afc2;
            }
            uVar7 = FUN_000495f0(param_1);
            iVar8 = FUN_000495ce(uVar6,param_1,uVar7);
            if (iVar8 == 0) {
              iVar4 = FUN_0004a498(uVar10,iVar5,DAT_0004b0fc,DAT_0004b0f8);
              if ((iVar4 < 0) ||
                 (iVar4 = FUN_0004a498(uVar10,iVar5,DAT_0004b104,&local_4c), uVar6 = DAT_0004b108,
                 iVar4 < 0)) {
                puVar9 = auStack_48;
                uVar10 = DAT_0004b100;
                goto LAB_0004afc2;
              }
              *piVar1 = local_4c;
              piVar1[1] = 0;
              iVar4 = FUN_0004a498(uVar10,iVar5,uVar6,&local_54);
            }
          }
        }
        iVar4 = 0;
        if (*DAT_0004b10c == 0 && DAT_0004b10c[1] == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = DAT_0004b110;
        }
        DAT_0004b10c[3] = iVar3;
        if (local_54 == 1) {
          piVar2[3] = piVar2[3] | 0x80000000;
        }
      }
    }
  }
  return iVar4;
}

