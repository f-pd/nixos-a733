// rea decompile_all
// name: FUN_0005e158
// address: 0x5e158
// body: available
// range: 0x5e158-0x5e3e7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0005e158(void)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  undefined1 uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined2 local_46;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c [2];
  
  iVar11 = DAT_0005e3e8;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c[0] = 0;
  local_46 = 0;
  FUN_00049a9c();
  uVar12 = *(undefined4 *)(iVar11 + 0xb8);
  FUN_0004a4ec(uVar12,iVar11 + 0xbc,6);
  FUN_000498e4(DAT_0005e3ec);
  FUN_0004993c(DAT_0005e3f0);
  FUN_0004993c(DAT_0005e3f4,iVar11 + 0x2f8);
  FUN_00049898(*(undefined1 *)(iVar11 + 0x34),0);
  iVar7 = FUN_00048fac();
  if (iVar7 == 0) {
    iVar7 = FUN_0004a990();
    if (iVar7 == 0) {
      iVar7 = FUN_0004b290(&local_46);
      if (iVar7 == 0) {
        if (*(int *)(iVar11 + 0xcc) != 0) {
          FUN_0004a5cc(iVar11 + 0xd0,5,1);
        }
        iVar7 = FUN_00049a5c();
        if (iVar7 == 0x32) {
          uVar12 = DAT_0005e3fc;
        }
        else {
          FUN_00049ab4();
          uVar8 = FUN_00049aa8();
          iVar7 = FUN_00049bdc(0,uVar8);
          piVar1 = DAT_0005e404;
          if (iVar7 == 0) {
            uVar12 = DAT_0005e400;
          }
          else {
            if (*(int *)(iVar11 + 0x318) != 0) {
              iVar7 = *(int *)(iVar11 + 0x318);
            }
            *DAT_0005e404 = iVar7;
            iVar9 = FUN_00049a5c();
            if (iVar9 != 0x32) {
              if (iVar9 == 100) {
                FUN_00049898(8,1);
                FUN_0004993c(DAT_0005e40c);
              }
              else if (iVar9 == 0x71) {
                FUN_0004993c(DAT_0005e420);
                FUN_00049898(0,1);
              }
              FUN_00048dfc(iVar7);
              FUN_00049d14(0x40800000,0x1000000);
              iVar10 = FUN_00049050();
              if ((iVar10 == 0) && (iVar10 = FUN_0005dc30(&local_44), iVar10 == 0)) {
                FUN_0005dc80(&local_44,&local_40,&local_3c,&local_38,&local_34,&local_30,local_2c);
                iVar4 = local_3c;
                iVar3 = local_40;
                iVar10 = local_44;
                uVar2 = local_46;
                if ((local_38 == 0) && (local_44 != 0)) {
                  FUN_00049da0(local_44 + 0x1ff000);
                  uVar8 = *(undefined4 *)(DAT_0005e410 + 0x24);
                  *(int *)(iVar10 + 0x4f8) = iVar7;
                  *(undefined4 *)(iVar10 + 0x4f4) = uVar8;
                  uVar8 = FUN_00049aa8();
                  thunk_FUN_00047d1c(iVar10 + 0x30,uVar8,0x80);
                  if (iVar4 != 0) {
                    *(undefined1 *)(iVar10 + 0x4e9) = 1;
                  }
                  if (iVar3 != 0) {
                    *(undefined1 *)(iVar10 + 0x4e8) = 1;
                    uVar8 = *(undefined4 *)(iVar11 + 0x32c);
                    *(int *)(iVar3 + 0xc) = iVar7;
                    *(char *)(iVar3 + 0x10c) = (char)uVar12;
                    *(undefined4 *)(iVar3 + 0x10) = uVar8;
                  }
                  bVar5 = FUN_00049a90(0xff);
                  *(byte *)(iVar10 + 0x4ea) = bVar5 | *(byte *)(iVar10 + 0x4ea);
                  FUN_0005da7c(iVar10);
                  uVar8 = DAT_0005e414;
                  *(undefined4 *)(iVar10 + 0xb8) = uVar12;
                  thunk_FUN_00047d1c(iVar10 + 0xbc,uVar8,0x10);
                  *(short *)(iVar10 + 0x502) = (short)iVar9;
                  *(undefined2 *)(iVar10 + 0x500) = 0;
                  *(undefined2 *)(iVar10 + 0x504) = uVar2;
                  uVar6 = FUN_000498cc();
                  *(undefined1 *)(iVar10 + 0x507) = uVar6;
                  iVar11 = FUN_0005dc74();
                  if (iVar11 != -1) {
                    uVar12 = FUN_0005dc74();
                    *(undefined4 *)(iVar10 + 0xe0) = uVar12;
                  }
                  *(char *)(iVar10 + 0x4eb) = (char)piVar1[1];
                }
                iVar11 = FUN_00049bbc(local_44,local_40,local_3c,local_38,local_34,local_30);
                if (iVar11 == 0) {
                  FUN_00048e8c();
                  iVar11 = local_3c;
                  if (local_3c == 0) {
                    if (local_40 == 0) {
                      if (local_38 == 0) {
                        FUN_0004993c(DAT_0005e42c,local_44);
                        iVar11 = local_44;
                      }
                      else {
                        FUN_0004993c(DAT_0005e428);
                        iVar11 = local_38;
                      }
                      FUN_00048ec6(iVar11);
                    }
                    else {
                      FUN_0004993c(DAT_0005e424,local_40,local_44);
                      FUN_00048ed2(local_40,local_44);
                    }
                  }
                  else {
                    *(int *)(local_3c + 0x18) = local_40;
                    *(int *)(local_3c + 0x10) = local_44;
                    uVar12 = FUN_0004af58();
                    thunk_FUN_00047d1c(iVar11 + 0xb8,uVar12,0x10);
                    FUN_0004993c(DAT_0005e418,local_3c,local_44,local_40);
                    FUN_00048ee0(local_3c);
                  }
                  FUN_0004993c(DAT_0005e41c);
                  do {
                    /* WARNING: Do nothing block with infinite loop */
                  } while( true );
                }
              }
              goto LAB_0005e1b8;
            }
            FUN_00049898(3,0);
            uVar12 = DAT_0005e408;
          }
        }
        FUN_0004993c(uVar12);
      }
    }
    else {
      FUN_0004aa08();
    }
  }
LAB_0005e1b8:
  FUN_0004993c(DAT_0005e3f8);
  FUN_00049062();
  FUN_00049504();
  FUN_00048e8c();
  FUN_00048da4(10);
  FUN_00048ec6(0x20);
  return;
}

