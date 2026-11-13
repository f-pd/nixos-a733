// rea decompile_all
// name: FUN_0005dc80
// address: 0x5dc80
// body: available
// range: 0x5dc80-0x5df69 inclusive
// range: 0x5dfcc-0x5e0fd inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4
FUN_0005dc80(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,undefined4 param_6,
            int *param_7)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint local_34;
  uint local_30;
  
  puVar1 = DAT_0005df6c;
  FUN_00049aa8();
  iVar2 = FUN_00049d30(DAT_0005df70);
  FUN_00049066();
  uVar3 = DAT_0005df74;
  *puVar1 = 0xffffffff;
  uVar3 = FUN_000495f0(uVar3);
  iVar4 = FUN_000495ce(iVar2,DAT_0005df74,uVar3);
  if (iVar4 == 0) {
    *puVar1 = 0x11;
  }
  iVar9 = 0;
  local_30 = 0;
  iVar4 = iVar2 + 0x40;
  do {
    if (*(uint *)(iVar2 + 0x20) <= local_30) {
      FUN_00049074();
      return 0;
    }
    if (*(int *)(iVar4 + 0x4c) == 3) {
      iVar5 = FUN_0005dc5e(*(uint *)(iVar4 + 0x40) >> 9);
      uVar3 = FUN_000495f0(iVar4);
      iVar6 = FUN_000495ce(iVar4,DAT_0005df78,uVar3);
      if (iVar6 == 0) {
        *param_1 = iVar5;
LAB_0005dd06:
        uVar7 = *(uint *)(iVar4 + 0x40);
        uVar8 = *(int *)(iVar4 + 0x44) + 0x1ff;
        goto LAB_0005dd10;
      }
      uVar3 = FUN_000495f0(iVar4);
      iVar6 = FUN_000495ce(iVar4,DAT_0005df7c,uVar3);
      if (iVar6 == 0) {
LAB_0005dd26:
        iVar9 = FUN_0005e13c(param_1,param_2,param_3,param_4,param_5,param_6,param_7,iVar4,iVar2);
      }
      else {
        uVar3 = FUN_000495f0(iVar4);
        iVar6 = FUN_000495ce(iVar4,DAT_0005df80,uVar3);
        if (iVar6 == 0) goto LAB_0005dd26;
        uVar3 = FUN_000495f0(iVar4);
        iVar6 = FUN_000495ce(iVar4,DAT_0005df84,uVar3);
        if (iVar6 == 0) goto LAB_0005dd26;
        iVar6 = FUN_000495ce(iVar4,DAT_0005df88,6);
        if (iVar6 == 0) {
          iVar6 = *(int *)(iVar4 + 0x44);
          uVar7 = *(uint *)(iVar4 + 0x40);
          *param_2 = iVar5;
          FUN_0005dc3c(uVar7 >> 9,iVar6 + 0x1ffU >> 9,iVar5);
          uVar3 = FUN_00049aa8();
          thunk_FUN_00047d1c(iVar5 + 0x2c,uVar3,0x80);
          iVar5 = iVar5 + 0xec;
LAB_0005dda8:
          thunk_FUN_00047d1c(iVar5,DAT_0005df8c,8);
        }
        else {
          iVar6 = FUN_000495ce(iVar4,DAT_0005df90,8);
          if (iVar6 == 0) {
            iVar6 = *(int *)(iVar4 + 0x44);
            uVar7 = *(uint *)(iVar4 + 0x40);
            *param_3 = iVar5;
            FUN_0005dc3c(uVar7 >> 9,iVar6 + 0x1ffU >> 9,iVar5);
            uVar3 = FUN_00049aa8();
            thunk_FUN_00047d1c(iVar5 + 0x30,uVar3,0x80);
            *(undefined4 *)(iVar5 + 0x2c) = *DAT_0005df94;
LAB_0005dde6:
            iVar5 = iVar5 + 0x24;
            goto LAB_0005dda8;
          }
          iVar6 = FUN_000495ce(iVar4,DAT_0005df98,4);
          if (iVar6 == 0) {
            iVar5 = iVar2 + 0x40;
            for (local_34 = 0; local_34 < *(uint *)(iVar2 + 0x20); local_34 = local_34 + 1) {
              iVar6 = FUN_000495ce(iVar5,DAT_0005df9c,4);
              if (iVar6 == 0) {
                if (*(uint *)(iVar5 + 0x44) < 0x40001) {
                  FUN_0005dc3c(*(uint *)(iVar5 + 0x40) >> 9,*(uint *)(iVar5 + 0x44) + 0x1ff >> 9,
                               DAT_0005dfa4);
                }
                else {
                  FUN_0004993c(DAT_0005dfa8);
                }
                break;
              }
              iVar5 = iVar5 + 0x170;
            }
            if (local_34 == *(uint *)(iVar2 + 0x20)) {
              FUN_0004993c(DAT_0005dfac);
            }
            uVar7 = *(uint *)(iVar4 + 0x40);
            uVar8 = 0x268;
            iVar5 = DAT_0005dfa4;
LAB_0005de82:
            FUN_0005dc3c(uVar7 >> 9,uVar8,iVar5);
            goto LAB_0005de88;
          }
          iVar6 = FUN_000495ce(iVar4,DAT_0005df9c,0x40);
          if (iVar6 == 0) {
            iVar6 = *param_3;
            iVar5 = *param_1 + 0x200000;
            *DAT_0005dfa0 = iVar5;
            iVar6 = FUN_00049d30(iVar6);
            *(int *)(iVar6 + 0xb0) = iVar5;
            *param_7 = iVar5;
            goto LAB_0005dd06;
          }
          uVar3 = FUN_000495f0(DAT_0005dfb4);
          iVar6 = FUN_000495ce(iVar4,DAT_0005dfb4,uVar3);
          if (iVar6 == 0) goto LAB_0005dd26;
          uVar3 = FUN_000495f0(DAT_0005dfb8);
          iVar6 = FUN_000495ce(iVar4,DAT_0005dfb8,uVar3);
          if (iVar6 == 0) goto LAB_0005dd26;
          uVar3 = FUN_000495f0(DAT_0005dfbc);
          iVar6 = FUN_000495ce(iVar4,DAT_0005dfbc,uVar3);
          if (iVar6 == 0) goto LAB_0005dd26;
          iVar6 = FUN_000495ce(iVar4,DAT_0005dfc0,5);
          if (iVar6 == 0) {
            uVar7 = *(uint *)(iVar4 + 0x40);
            uVar8 = *(int *)(iVar4 + 0x44) + 0x1ff;
            iVar5 = *param_1 + 0x100000;
LAB_0005dd10:
            uVar8 = uVar8 >> 9;
            goto LAB_0005de82;
          }
          iVar6 = FUN_000495ce(iVar4,DAT_0005dfc4,5);
          if (iVar6 == 0) {
            iVar5 = *param_1;
            *(undefined4 *)(iVar5 + 0x300000) = *(undefined4 *)(iVar4 + 0x44);
            FUN_0005dc3c(*(uint *)(iVar4 + 0x40) >> 9,*(int *)(iVar4 + 0x44) + 0x1ffU >> 9,
                         iVar5 + 0x300010);
            FUN_00049a80(1);
          }
          else {
            iVar6 = FUN_000495ce(iVar4,DAT_0005dfc8,0x40);
            if (iVar6 == 0) {
              iVar6 = *(int *)(iVar4 + 0x44);
              uVar7 = *(uint *)(iVar4 + 0x40);
              *param_5 = iVar5;
              FUN_0005dc3c(uVar7 >> 9,iVar6 + 0x1ffU >> 9,iVar5);
              iVar6 = FUN_000495ce(iVar5 + 4,DAT_0005dfc8,7);
              if (iVar6 == 0) goto LAB_0005dde6;
            }
            else {
              iVar6 = FUN_000495ce(iVar4,DAT_0005e100,0x40);
              if (((iVar6 == 0) || (iVar6 = FUN_000495ce(iVar4,DAT_0005e104,0x40), iVar6 == 0)) ||
                 (iVar6 = FUN_000495ce(iVar4,DAT_0005e108,0x40), iVar6 == 0)) goto LAB_0005dd26;
              iVar6 = FUN_000495ce(iVar4,DAT_0005e10c,5);
              if ((iVar6 == 0) || (iVar6 = FUN_000495ce(iVar4,DAT_0005e110,6), iVar6 == 0)) {
                *param_4 = iVar5;
                goto LAB_0005dd06;
              }
              iVar6 = FUN_000495ce(iVar4,DAT_0005e114,0xd);
              if (iVar6 == 0) {
                FUN_0004993c(DAT_0005e118,0x43000000);
                thunk_FUN_00047d1c(0x43000000,local_30 * 0x170 + iVar2 + 0x84,4);
                uVar7 = *(uint *)(iVar4 + 0x40);
                uVar8 = *(int *)(iVar4 + 0x44) + 0x1ff;
                iVar5 = DAT_0005e11c;
                goto LAB_0005dd10;
              }
              iVar6 = FUN_000495ce(iVar4,DAT_0005e120,8);
              if (iVar6 == 0) {
                thunk_FUN_00047d1c(iVar5,local_30 * 0x170 + iVar2 + 0x84,4);
                FUN_0005dc3c(*(uint *)(iVar4 + 0x40) >> 9,*(int *)(iVar4 + 0x44) + 0x1ffU >> 9,
                             0x50000000);
                FUN_00049d32(0x50000000);
                FUN_0004af60(DAT_0005e120);
              }
              else {
                iVar5 = FUN_000495ce(iVar4,DAT_0005e124,9);
                if (((iVar5 == 0) || (iVar5 = FUN_000495ce(iVar4,DAT_0005e128,8), iVar5 == 0)) ||
                   ((iVar5 = FUN_000495ce(iVar4,DAT_0005e12c,10), iVar5 == 0 ||
                    (((iVar5 = FUN_000495ce(iVar4,DAT_0005e130,9), iVar5 == 0 ||
                      (iVar5 = FUN_000495ce(iVar4,DAT_0005e134,0xb), iVar5 == 0)) ||
                     (iVar5 = FUN_000495ce(iVar4,DAT_0005e138,10), iVar5 == 0))))))
                goto LAB_0005dd26;
              }
            }
          }
        }
      }
LAB_0005de88:
      if (iVar9 != 0) {
        FUN_0004993c(DAT_0005dfb0,iVar4);
      }
    }
    iVar4 = iVar4 + 0x170;
    local_30 = local_30 + 1;
  } while( true );
}

