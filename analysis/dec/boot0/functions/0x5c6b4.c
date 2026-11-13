// rea decompile_all
// name: FUN_0005c6b4
// address: 0x5c6b4
// body: available
// range: 0x5c6b4-0x5c797 inclusive
// range: 0x5c79c-0x5c8ff inclusive
// range: 0x5c90a-0x5c977 inclusive
// range: 0x5c9b8-0x5cbd9 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_0005c6b4(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  bool bVar9;
  undefined4 local_24c [4];
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_234;
  int local_230;
  uint local_22c;
  uint local_228;
  uint local_224;
  uint local_220;
  uint local_21c;
  undefined1 auStack_218 [160];
  byte local_178;
  char local_169;
  byte local_165;
  byte local_158;
  uint local_144;
  byte local_138;
  
  local_24c[0] = *DAT_0005c978;
  local_24c[1] = DAT_0005c978[1];
  local_24c[2] = DAT_0005c978[2];
  local_24c[3] = DAT_0005c978[3];
  local_23c = DAT_0005c978[4];
  local_21c = 0;
  if ((*(uint *)(param_1 + 0x50) & 0x10) == 0) {
    local_238 = 2;
  }
  else {
    local_238 = 10;
  }
  local_234 = 7;
  local_230 = 0;
  uVar2 = FUN_0005b324(param_1,&local_238);
  if (uVar2 != 0) {
    uVar3 = *(uint *)(param_1 + 0x30);
    uVar7 = DAT_0005c97c;
    goto LAB_0005c6f4;
  }
  thunk_FUN_00047d1c(param_1 + 0x70,&local_22c,0x10);
  if (-1 < *(int *)(param_1 + 0x50) << 0x1b) {
    local_238 = 3;
    local_230 = *(int *)(param_1 + 0x80) << 0x10;
    local_234 = 0x15;
    local_21c = uVar2;
    uVar2 = FUN_0005b324(param_1,&local_238,0);
    if (uVar2 != 0) {
      uVar3 = *(uint *)(param_1 + 0x30);
      uVar7 = DAT_0005c980;
      goto LAB_0005c6f4;
    }
    if (*(int *)(param_1 + 0x28) << 0xe < 0) {
      *(uint *)(param_1 + 0x80) = local_22c >> 0x10;
    }
  }
  local_238 = 9;
  local_234 = 7;
  local_21c = 0;
  local_230 = *(int *)(param_1 + 0x80) << 0x10;
  uVar2 = FUN_0005b324(param_1,&local_238);
  FUN_0005b948(param_1,1000);
  if (uVar2 != 0) {
    uVar3 = *(uint *)(param_1 + 0x30);
    uVar7 = DAT_0005c984;
    goto LAB_0005c6f4;
  }
  *(uint *)(param_1 + 0x60) = local_22c;
  *(uint *)(param_1 + 100) = local_228;
  *(uint *)(param_1 + 0x68) = local_224;
  *(uint *)(param_1 + 0x6c) = local_220;
  if (*(int *)(param_1 + 0x28) == 0x10000) {
    switch((local_22c & 0x3fffffff) >> 0x1a) {
    case 1:
      uVar2 = DAT_0005c994;
      break;
    case 2:
      uVar2 = DAT_0005c998;
      break;
    case 3:
      uVar2 = DAT_0005c99c;
      break;
    case 4:
      uVar2 = DAT_0005c9a0;
      break;
    default:
      uVar2 = DAT_0005c988;
    }
    *(uint *)(param_1 + 0x28) = uVar2;
  }
  bVar9 = -1 < *(int *)(param_1 + 0x28) << 0xe;
  if (bVar9) {
    local_220 = (local_220 & 0x3ffffff) >> 0x16;
  }
  *(int *)(param_1 + 0x8c) =
       *(int *)(DAT_0005c98c + ((local_22c & 0x7f) >> 3) * 4 + 0x24) *
       *(int *)(DAT_0005c98c + (local_22c & 7) * 4 + 100);
  uVar2 = 1 << ((local_228 & 0xfffff) >> 0x10);
  if (bVar9) {
    *(int *)(param_1 + 0x94) = 1 << (local_220 & 0xff);
  }
  *(uint *)(param_1 + 0x90) = uVar2;
  if (!bVar9) {
    *(uint *)(param_1 + 0x94) = uVar2;
  }
  if (*(int *)(param_1 + 0x40) == 0) {
    uVar5 = (local_228 & 0x3ff) << 2 | local_224 >> 0x1e;
    uVar3 = (local_224 & 0x3ffff) >> 0xf;
  }
  else {
    uVar5 = (local_228 & 0x3f) << 0x10 | local_224 >> 0x10;
    uVar3 = 8;
  }
  uVar6 = uVar5 + 1;
  iVar8 = uVar3 + 2;
  lVar1 = (ulonglong)(uVar6 << iVar8) * (ulonglong)uVar2;
  *(int *)(param_1 + 0xa0) = (int)lVar1;
  *(uint *)(param_1 + 0xa4) =
       (int)((ulonglong)lVar1 >> 0x20) +
       uVar2 * ((uint)(0xfffffffe < uVar5) << iVar8 | uVar6 << (uVar3 - 0x1e & 0xff) |
               uVar6 >> (0x20U - iVar8 & 0xff)) + (uVar6 << iVar8) * ((int)uVar2 >> 0x1f);
  if (0x200 < (int)uVar2) {
    *(undefined4 *)(param_1 + 0x90) = 0x200;
  }
  if (0x200 < *(uint *)(param_1 + 0x94)) {
    *(undefined4 *)(param_1 + 0x94) = 0x200;
  }
  uVar2 = *(uint *)(param_1 + 0x50) & 0x10;
  if (uVar2 == 0) {
    local_238 = 7;
    local_234 = 0x1d;
    local_230 = *(int *)(param_1 + 0x80) << 0x10;
    local_21c = uVar2;
    uVar2 = FUN_0005b324(param_1,&local_238);
    if (uVar2 != 0) {
      uVar7 = DAT_0005c990;
      goto LAB_0005c878;
    }
  }
  if (-1 < *(int *)(param_1 + 0x28) << 0xe) {
    iVar8 = FUN_0005c5d0(param_1,DAT_0005c9a4,1);
    if (iVar8 < 0) {
      FUN_000498e4(DAT_0005c9a8);
    }
    FUN_0005d404(*(undefined4 *)(param_1 + 0x30));
  }
  FUN_0005c5b8(param_1,DAT_0005c9ac);
  *(undefined4 *)(param_1 + 0x98) = 1;
  *(undefined4 *)(param_1 + 0x84) = 0xff;
  if ((int)(*(uint *)(param_1 + 0x28) << 0xe) < 0) {
LAB_0005c966:
    uVar2 = FUN_0005bf34(param_1);
  }
  else {
    if (DAT_0005c9b0 < *(uint *)(param_1 + 0x28)) {
      iVar8 = FUN_0005bd6c(param_1,auStack_218);
      if (iVar8 == 0) {
        switch(local_158) {
        case 0:
          uVar2 = DAT_0005c9a0;
          break;
        case 1:
          uVar2 = DAT_0005cbdc;
          break;
        case 2:
          uVar2 = DAT_0005cbe0;
          break;
        case 3:
          uVar2 = DAT_0005cbe4;
          break;
        default:
          goto switchD_0005c8fc_caseD_4;
        case 5:
          uVar2 = DAT_0005cbe8;
          break;
        case 6:
          uVar2 = DAT_0005cbec;
          break;
        case 7:
          uVar2 = DAT_0005cbf0;
          break;
        case 8:
          uVar2 = DAT_0005cbf4;
        }
        *(uint *)(param_1 + 0x28) = uVar2;
      }
switchD_0005c8fc_caseD_4:
      if ((1 < local_158) && (iVar8 == 0)) {
        uVar3 = ((int)local_144 >> 0x1f) << 9 | local_144 >> 0x17;
        uVar2 = ((int)local_144 >> 0x1f & 0x7fffffU) >> 0xb;
        bVar9 = uVar2 == 0;
        if (uVar2 == 0) {
          bVar9 = ((local_144 & 0x7fffff) >> 0xb | uVar3 << 0xc) < 0x801;
        }
        if (!bVar9) {
          *(uint *)(param_1 + 0xa0) = local_144 << 9;
          *(uint *)(param_1 + 0xa4) = uVar3;
        }
      }
      if (local_169 == '\0') {
        iVar8 = ((*(uint *)(param_1 + 0x68) & 0x3ff) >> 5) + 1;
        iVar8 = ((*(uint *)(param_1 + 0x68) & 0x7fff) >> 10) * iVar8 + iVar8;
      }
      else {
        iVar8 = (uint)local_138 << 0x13;
      }
      *(int *)(param_1 + 0x98) = iVar8;
      if ((int)((uint)local_178 << 0x1f) < 0) {
        *(uint *)(param_1 + 0x84) = (uint)local_165;
      }
      if (*(int *)(param_1 + 0x28) << 0xe < 0) goto LAB_0005c966;
    }
    uVar2 = FUN_0005bed0(param_1);
  }
  if (uVar2 != 0) {
    uVar3 = *(uint *)(param_1 + 0x30);
    uVar7 = DAT_0005c9b4;
    goto LAB_0005c6f4;
  }
  uVar2 = FUN_0005bdac(param_1);
  if (uVar2 != 0) {
    uVar7 = DAT_0005cbf8;
LAB_0005c878:
    FUN_000498e4(uVar7);
    return uVar2;
  }
  uVar5 = *(uint *)(param_1 + 0x4c) & *(uint *)(param_1 + 0x50);
  uVar2 = uVar5 & 0x40;
  *(uint *)(param_1 + 0x4c) = uVar5;
  uVar3 = *(uint *)(param_1 + 0x28) & 0x20000;
  if (uVar2 == 0) {
    if (uVar3 == 0) {
      if (*(int *)(param_1 + 0x104) == 2) {
        *(undefined4 *)(param_1 + 0x104) = 1;
      }
      else {
        *(undefined4 *)(param_1 + 0x104) = 0;
      }
      goto LAB_0005ca24;
    }
LAB_0005ca48:
    if ((int)(uVar5 << 0x1d) < 0) {
      local_238 = 0x37;
      local_234 = 0x15;
      local_21c = 0;
      local_230 = *(int *)(param_1 + 0x80) << 0x10;
      uVar2 = FUN_0005b324(param_1,&local_238);
      if (uVar2 != 0) {
        uVar4 = *(undefined4 *)(param_1 + 0x30);
        uVar7 = DAT_0005cc00;
        goto LAB_0005ca72;
      }
      local_238 = 6;
      local_234 = 0x15;
      local_230 = 2;
      local_21c = uVar2;
      uVar2 = FUN_0005b324(param_1,&local_238,0);
      if (uVar2 != 0) {
        uVar4 = *(undefined4 *)(param_1 + 0x30);
        uVar7 = DAT_0005cc04;
        goto LAB_0005ca72;
      }
      *(undefined4 *)(param_1 + 0x44) = 4;
      FUN_0005c080(param_1);
    }
    if (*(int *)(param_1 + 0x4c) << 0x1f < 0) {
      uVar7 = DAT_0005cc08;
    }
    else {
      uVar7 = DAT_0005cc0c;
    }
  }
  else {
    if (uVar3 != 0) goto LAB_0005ca48;
LAB_0005ca24:
    if ((int)(uVar5 << 0x1c) < 0) {
      if (uVar2 == 0) {
        uVar2 = FUN_0005bdc8(param_1,1,0xb7,2);
        if (uVar2 != 0) {
          uVar4 = *(undefined4 *)(param_1 + 0x30);
          uVar7 = DAT_0005cc18;
          goto LAB_0005ca72;
        }
      }
      else {
        uVar2 = FUN_0005bdc8(param_1,1,0xb7,6);
        if (uVar2 != 0) {
LAB_0005ca3e:
          uVar4 = *(undefined4 *)(param_1 + 0x30);
          uVar7 = DAT_0005cbfc;
LAB_0005ca72:
          FUN_000498e4(uVar7,uVar4);
          return uVar2;
        }
      }
      uVar7 = 8;
LAB_0005cafa:
      *(undefined4 *)(param_1 + 0x44) = uVar7;
      FUN_0005c080(param_1);
    }
    else if ((int)(uVar5 << 0x1d) < 0) {
      if (uVar2 == 0) {
        uVar7 = 1;
      }
      else {
        uVar7 = 5;
      }
      uVar2 = FUN_0005bdc8(param_1,1,0xb7,uVar7);
      if (uVar2 != 0) goto LAB_0005ca3e;
      uVar7 = 4;
      goto LAB_0005cafa;
    }
    iVar8 = *(int *)(param_1 + 0x4c);
    if ((iVar8 << 0x19 < 0) || ((iVar8 << 0x1f < 0 && (iVar8 << 0x1e < 0)))) {
      uVar7 = DAT_0005cc14;
    }
    else {
      uVar7 = DAT_0005cc1c;
    }
  }
  *(undefined4 *)(param_1 + 0x8c) = uVar7;
  FUN_0005c5b8(param_1,*(undefined4 *)(param_1 + 0x8c));
  *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(param_1 + 0x90);
  *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xa0) >> 9 | *(int *)(param_1 + 0xa4) << 0x17;
  uVar2 = *(uint *)(param_1 + 0x28);
  if (-1 < (int)(uVar2 << 0xe)) {
    if (uVar2 == DAT_0005cbdc) {
      uVar7 = DAT_0005cc4c;
    }
    else if (uVar2 < DAT_0005cbdc) {
      if (uVar2 == DAT_0005cbdc - 0x1f) {
        uVar7 = DAT_0005cc44;
      }
      else if (uVar2 < DAT_0005cbdc - 0x1f) {
        if (uVar2 == DAT_0005cbdc - 0x2f) {
          uVar7 = DAT_0005cc30;
        }
        else if (uVar2 == DAT_0005cbdc - 0x2d) {
          uVar7 = DAT_0005cc40;
        }
        else {
LAB_0005caf4:
          uVar7 = DAT_0005cc10;
        }
      }
      else if (uVar2 == DAT_0005cc20) {
        uVar7 = DAT_0005cc48;
      }
      else {
        if (uVar2 != DAT_0005cc20 + 0x10) goto LAB_0005caf4;
        uVar7 = DAT_0005cc24;
      }
    }
    else if (uVar2 == DAT_0005cbe8) {
      uVar7 = DAT_0005cc54;
    }
    else if (uVar2 < DAT_0005cbe8) {
      if (uVar2 == DAT_0005cbe8 - 2) {
        uVar7 = DAT_0005cc50;
      }
      else {
        if (uVar2 != DAT_0005cbe8 - 1) goto LAB_0005caf4;
        uVar7 = DAT_0005cc28;
      }
    }
    else if (uVar2 == DAT_0005cbf0) {
      uVar7 = DAT_0005cc58;
    }
    else if (uVar2 == DAT_0005cbf0 + 1) {
      uVar7 = DAT_0005cc5c;
    }
    else {
      if (uVar2 != DAT_0005cbf0 - 0xb) goto LAB_0005caf4;
      uVar7 = DAT_0005cc2c;
    }
    FUN_000498e4(uVar7);
  }
  FUN_000498e4(DAT_0005cc34,local_24c[*(int *)(param_1 + 0x104)],*(undefined4 *)(param_1 + 0x44));
  FUN_000498e4(DAT_0005cc38,*(undefined4 *)(param_1 + 0x48));
  uVar3 = *(uint *)(param_1 + 0xec) >> 0xb;
  uVar2 = 0;
  uVar7 = DAT_0005cc3c;
LAB_0005c6f4:
  FUN_000498e4(uVar7,uVar3);
  return uVar2;
}

