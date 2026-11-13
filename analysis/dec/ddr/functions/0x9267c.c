// rea decompile_all
// name: FUN_0009267c
// address: 0x9267c
// body: available
// range: 0x9267c-0x929c3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


char * FUN_0009267c(int *param_1,byte *param_2,int *param_3)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  char *pcVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  byte bVar11;
  int *piVar12;
  char *pcVar13;
  char *pcVar14;
  bool bVar15;
  bool bVar16;
  longlong lVar17;
  int local_58;
  int local_50;
  int local_4c;
  undefined4 *local_48;
  undefined4 uStack_44;
  char local_40;
  undefined1 auStack_3f [27];
  
  bVar11 = 1;
  pcVar14 = (char *)0x0;
  do {
    while( true ) {
      bVar1 = *param_2;
      if (bVar1 == 0) {
        return pcVar14;
      }
      if (bVar1 == 0x25) break;
      if (bVar1 == 10) {
        (*(code *)param_1[4])(param_1,0xd);
        pcVar14 = pcVar14 + 1;
      }
      param_2 = param_2 + 1;
      pcVar14 = pcVar14 + 1;
      (*(code *)param_1[4])(param_1,bVar1);
    }
    uVar3 = (uint)param_2[1];
    if (uVar3 == 0x2d) {
      uVar3 = (uint)param_2[2];
      param_2 = param_2 + 3;
    }
    else {
      param_2 = param_2 + 2;
    }
    bVar15 = uVar3 == 0x30;
    if (bVar15) {
      uVar3 = (uint)*param_2;
      param_2 = param_2 + 1;
    }
    local_58 = 0;
    if (uVar3 - 0x30 < 10) {
      while (uVar3 - 0x30 < 10) {
        local_58 = local_58 * 10 + uVar3 + -0x30;
        uVar3 = (uint)*param_2;
        param_2 = param_2 + 1;
      }
    }
    if (uVar3 == 0x6c) {
      uVar3 = (uint)*param_2;
      if (uVar3 != 0x6c) goto LAB_000926f2;
      uVar3 = (uint)param_2[1];
      iVar5 = 1;
      param_2 = param_2 + 2;
      bVar16 = false;
    }
    else if (uVar3 == 0x7a) {
      uVar3 = (uint)*param_2;
LAB_000926f2:
      param_2 = param_2 + 1;
      iVar5 = 0;
      bVar16 = true;
    }
    else {
      iVar5 = 0;
      bVar16 = false;
    }
    pcVar13 = &local_40;
    *param_1 = (int)pcVar13;
    *(undefined1 *)(param_1 + 1) = 0;
    if (uVar3 == 100) {
LAB_000927ae:
      if (iVar5 == 0) {
        bVar11 = bVar11 + 1;
        piVar12 = param_3 + 1;
        local_50 = *param_3;
        uVar10 = DAT_000929cc;
        if (bVar16) {
          uVar9 = 0;
          local_4c = iVar5;
          if (uVar3 == 100) {
LAB_000929a8:
            if (-1 < local_50) goto LAB_00092812;
LAB_000929b2:
            local_50 = -local_50;
            puVar6 = (undefined1 *)*param_1;
            *param_1 = (int)(puVar6 + 1);
            *puVar6 = 0x2d;
            local_4c = local_50 >> 0x1f;
          }
        }
        else {
          uVar9 = 0;
          local_4c = 0;
          if (uVar3 == 100) {
LAB_00092812:
            if ((iVar5 == 0 && !bVar16) && (local_50 < 0)) goto LAB_000929b2;
          }
        }
      }
      else {
        if ((bool)(bVar11 & 1)) {
          param_3 = param_3 + 1;
        }
        local_50 = *param_3;
        local_4c = param_3[1];
        piVar12 = param_3 + 2;
        if (uVar3 == 100) {
          if (local_4c < 0) {
            bVar16 = local_50 != 0;
            local_50 = -local_50;
            local_4c = -local_4c - (uint)bVar16;
            *param_1 = (int)auStack_3f;
            local_40 = '-';
          }
          else if (bVar16) {
            bVar11 = 0;
            uVar10 = DAT_000929c4;
            uVar9 = DAT_000929c8;
            goto LAB_000929a8;
          }
        }
        bVar11 = 0;
        uVar10 = DAT_000929c4;
        uVar9 = DAT_000929c8;
      }
      lVar17 = CONCAT44(uVar9,uVar10);
      if (local_4c == 0 && local_50 == 0) {
        puVar6 = (undefined1 *)*param_1;
        *param_1 = (int)(puVar6 + 1);
        *puVar6 = 0x30;
LAB_00092800:
        *(undefined1 *)(param_1 + 1) = 1;
      }
      else {
        do {
          uVar10 = (undefined4)((ulonglong)lVar17 >> 0x20);
          FUN_00092634(param_1,&local_50,(int)lVar17,uVar10);
          lVar17 = FUN_000a41b4((int)lVar17,uVar10,10,0);
        } while (lVar17 != 0);
      }
    }
    else if (uVar3 < 0x65) {
      if (uVar3 == 0x25) {
        local_40 = '%';
        *param_1 = (int)auStack_3f;
      }
      else {
        if (uVar3 == 99) {
          iVar5 = *param_3;
          piVar12 = param_3 + 1;
          *param_1 = (int)auStack_3f;
          bVar11 = bVar11 + 1;
          local_40 = (char)iVar5;
          goto LAB_00092868;
        }
        if (uVar3 == 0) {
          return pcVar14;
        }
      }
LAB_00092766:
      piVar12 = param_3;
    }
    else if (uVar3 == 0x73) {
      piVar12 = param_3 + 1;
      bVar11 = bVar11 + 1;
      pcVar13 = (char *)*param_3;
      if ((char *)*param_3 == (char *)0x0) {
        pcVar13 = DAT_000929d0;
      }
    }
    else {
      if (0x73 < uVar3) {
        if (uVar3 == 0x75) goto LAB_000927ae;
        if (uVar3 != 0x78) goto LAB_00092766;
        if (iVar5 == 0) {
          local_50 = *param_3;
          piVar12 = param_3 + 1;
          bVar11 = bVar11 + 1;
          uVar8 = 0x10000000;
          uVar3 = 0;
          local_4c = iVar5;
        }
        else {
          uVar3 = 0x10000000;
          if ((bool)(bVar11 & 1)) {
            param_3 = param_3 + 1;
          }
          bVar11 = 0;
          local_50 = *param_3;
          piVar12 = param_3 + 2;
          uVar8 = 0;
          local_4c = param_3[1];
        }
        if (local_4c != 0 || local_50 != 0) {
          do {
            FUN_00092634(param_1,&local_50,uVar8,uVar3);
            uVar4 = uVar3 >> 4;
            uVar8 = uVar8 >> 4 | uVar3 << 0x1c;
            uVar3 = uVar4;
          } while (uVar8 != 0 || uVar4 != 0);
          goto LAB_00092868;
        }
        *param_1 = (int)auStack_3f;
        local_40 = '0';
        goto LAB_00092800;
      }
      if (uVar3 != 0x70) goto LAB_00092766;
      piVar12 = param_3 + 1;
      local_48 = (undefined4 *)*param_3;
      uStack_44 = 0;
      if ((*param_2 == 0x61) && (param_2[1] == 0x70)) {
        local_48 = (undefined4 *)*local_48;
      }
      iVar5 = 8;
      uVar3 = 0x10000000;
      do {
        FUN_00092634(param_1,&local_48,uVar3,0);
        uVar3 = uVar3 >> 4;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      bVar11 = bVar11 + 1;
      pbVar2 = param_2;
      do {
        do {
          param_2 = pbVar2;
          pbVar2 = param_2 + 1;
        } while ((*param_2 & 0xffffffdf) - 0x41 < 0x1a);
      } while (*param_2 - 0x30 < 10);
      pcVar13 = &local_40;
    }
LAB_00092868:
    *(undefined1 *)*param_1 = 0;
    *param_1 = (int)pcVar13;
    while (pcVar7 = (char *)*param_1, *param_1 = (int)(pcVar7 + 1), *pcVar7 != '\0') {
      if (local_58 == 0) goto LAB_00092976;
      local_58 = local_58 + -1;
    }
    iVar5 = local_58;
    if (bVar15) {
      uVar10 = 0x30;
    }
    else {
      uVar10 = 0x20;
    }
    while (bVar15 = iVar5 != 0, iVar5 = iVar5 + -1, bVar15) {
      (*(code *)param_1[4])(param_1,uVar10);
    }
    pcVar14 = pcVar14 + local_58;
LAB_00092976:
    iVar5 = (int)pcVar14 - (int)pcVar13;
    while( true ) {
      pcVar14 = pcVar13 + iVar5;
      param_3 = piVar12;
      if (*pcVar13 == '\0') break;
      (*(code *)param_1[4])(param_1);
      pcVar13 = pcVar13 + 1;
    }
  } while( true );
}

