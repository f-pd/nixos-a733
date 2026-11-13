// rea decompile_all
// name: FUN_000496b4
// address: 0x496b4
// body: available
// range: 0x496b4-0x4988b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_000496b4(int *param_1,byte *param_2,int *param_3)

{
  byte bVar1;
  uint uVar2;
  undefined1 *puVar3;
  char *pcVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  char *pcVar8;
  undefined4 uVar9;
  bool bVar10;
  int local_38;
  char local_34;
  undefined1 local_33 [15];
  
  do {
    bVar1 = *param_2;
    if (bVar1 == 0) {
      return 0;
    }
    piVar6 = param_3;
    if (bVar1 == 0x25) {
      uVar2 = (uint)param_2[1];
      iVar5 = 0;
      if (uVar2 == 0x2d) {
        uVar2 = (uint)param_2[2];
        param_2 = param_2 + 3;
      }
      else {
        param_2 = param_2 + 2;
      }
      bVar10 = uVar2 == 0x30;
      if (bVar10) {
        uVar2 = (uint)*param_2;
        param_2 = param_2 + 1;
      }
      if (uVar2 - 0x30 < 10) {
        while (uVar2 - 0x30 < 10) {
          iVar5 = iVar5 * 10 + uVar2 + -0x30;
          uVar2 = (uint)*param_2;
          param_2 = param_2 + 1;
        }
      }
      if (uVar2 == 0x6c) {
        uVar2 = (uint)*param_2;
        param_2 = param_2 + 1;
      }
      *param_1 = (int)&local_34;
      *(undefined1 *)(param_1 + 1) = 0;
      if (uVar2 == 100) {
LAB_00049782:
        local_38 = *param_3;
        piVar6 = param_3 + 1;
        if ((uVar2 == 100) && (local_38 < 0)) {
          local_38 = -local_38;
          *param_1 = (int)local_33;
          local_34 = '-';
        }
        if (local_38 == 0) {
          puVar3 = (undefined1 *)*param_1;
          *param_1 = (int)(puVar3 + 1);
          *puVar3 = 0x30;
LAB_000497b2:
          piVar6 = param_3 + 1;
          *(undefined1 *)(param_1 + 1) = 1;
        }
        else {
          iVar7 = 10;
          uVar2 = DAT_00049894;
          do {
            FUN_00049682(param_1,&local_38,uVar2);
            iVar7 = iVar7 + -1;
            uVar2 = (uint)((ulonglong)uVar2 * (ulonglong)DAT_0004988c >> 0x23);
          } while (iVar7 != 0);
        }
LAB_000497da:
        pcVar8 = &local_34;
      }
      else {
        if (uVar2 < 0x65) {
          if (uVar2 == 0x25) {
            local_34 = '%';
            *param_1 = (int)local_33;
          }
          else if (uVar2 == 99) {
            iVar7 = *param_3;
            piVar6 = param_3 + 1;
            *param_1 = (int)local_33;
            local_34 = (char)iVar7;
          }
          else if (uVar2 == 0) {
            return 0;
          }
          goto LAB_000497da;
        }
        if (uVar2 != 0x73) {
          if (uVar2 < 0x74) {
            if (uVar2 == 0x70) {
              piVar6 = param_3 + 1;
              while ((*(byte *)(DAT_00049890 + (uint)*param_2) & 7) != 0) {
                param_2 = param_2 + 1;
              }
            }
          }
          else {
            if (uVar2 == 0x75) goto LAB_00049782;
            if (uVar2 == 0x78) {
              local_38 = *param_3;
              piVar6 = param_3 + 1;
              if (local_38 == 0) {
                *param_1 = (int)local_33;
                local_34 = '0';
                goto LAB_000497b2;
              }
              iVar7 = 8;
              uVar2 = 0x10000000;
              do {
                FUN_00049682(param_1,&local_38,uVar2);
                iVar7 = iVar7 + -1;
                uVar2 = uVar2 >> 4;
              } while (iVar7 != 0);
            }
          }
          goto LAB_000497da;
        }
        piVar6 = param_3 + 1;
        pcVar8 = (char *)*param_3;
      }
      *(undefined1 *)*param_1 = 0;
      *param_1 = (int)pcVar8;
      while (pcVar4 = (char *)*param_1, *param_1 = (int)(pcVar4 + 1), *pcVar4 != '\0') {
        if (iVar5 == 0) goto LAB_00049872;
        iVar5 = iVar5 + -1;
      }
      if (bVar10) {
        uVar9 = 0x30;
      }
      else {
        uVar9 = 0x20;
      }
      while (bVar10 = iVar5 != 0, iVar5 = iVar5 + -1, bVar10) {
        (*(code *)param_1[3])(param_1,uVar9);
      }
LAB_00049872:
      if (pcVar8 != (char *)0x0) {
        for (; *pcVar8 != '\0'; pcVar8 = pcVar8 + 1) {
          (*(code *)param_1[3])(param_1);
        }
      }
    }
    else {
      if (bVar1 == 10) {
        (*(code *)param_1[3])(param_1,0xd);
      }
      param_2 = param_2 + 1;
      (*(code *)param_1[3])(param_1,bVar1);
    }
    param_3 = piVar6;
  } while( true );
}

