// rea decompile_all
// name: FUN_00057b8e
// address: 0x57b8e
// body: available
// range: 0x57b8e-0x57dc7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00057b8e(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  if ((*(int *)(param_1 + 4) == 4) || (*(int *)(param_1 + 4) == 9)) {
    uVar6 = 0xb0eb;
  }
  else {
    uVar6 = 0x30eb;
  }
  *(undefined4 *)(param_1 + 0x18) = uVar6;
  uVar8 = *(uint *)(param_1 + 0x18);
  iVar10 = *(int *)(param_1 + 0x78);
  if ((*(uint *)(param_1 + 0x1c) & 0xf) == 0) {
    iVar9 = 2;
  }
  else {
    iVar9 = 1;
  }
  iVar1 = FUN_00057b7c(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = 0;
  puVar5 = (undefined4 *)&DAT_40000000;
  do {
    if (iVar1 << 0x1f < 0) {
      puVar3 = puVar5;
    }
    else {
      puVar3 = (undefined4 *)~(uint)puVar5;
    }
    *puVar5 = puVar3;
    DataSynchronizationBarrier(0xf);
    iVar1 = iVar1 + 1;
    puVar5 = puVar5 + 1;
  } while (iVar1 != 0x10);
  uVar4 = 0x40000000;
  iVar1 = 0;
  do {
    if (iVar1 << 0x1f < 0) {
      uVar7 = uVar4;
    }
    else {
      uVar7 = ~uVar4;
    }
    if (uVar7 != *(uint *)(uVar4 + 0x80)) {
      uVar4 = 0x40000000;
      iVar1 = 0;
      goto LAB_00057d0a;
    }
    iVar1 = iVar1 + 1;
    uVar4 = uVar4 + 4;
  } while (iVar1 != 0x10);
  iVar1 = 1;
  goto LAB_00057c08;
  while( true ) {
    iVar1 = iVar1 + 1;
    uVar4 = uVar4 + 4;
    if (iVar1 == 0x10) break;
LAB_00057d0a:
    if (iVar1 << 0x1f < 0) {
      uVar7 = uVar4;
    }
    else {
      uVar7 = ~uVar4;
    }
    if (uVar7 != *(uint *)(uVar4 + 0x100)) break;
  }
  if (*(int *)(param_1 + 4) == 4) {
    iVar1 = 2;
  }
  else if (*(int *)(param_1 + 4) == 9) {
    iVar1 = 2;
  }
  else {
    iVar1 = 0;
  }
LAB_00057c08:
  uVar4 = 7;
  iVar9 = (((uVar8 & 0xffff) >> 0xe) - ((iVar10 << 0x19) >> 0x1f)) + iVar9;
  do {
    uVar8 = 0x40000000;
    iVar10 = 0;
    while( true ) {
      if (iVar10 << 0x1f < 0) {
        uVar7 = uVar8;
      }
      else {
        uVar7 = ~uVar8;
      }
      if (*(uint *)(uVar8 + (1 << (iVar9 + uVar4 & 0xff))) != uVar7) break;
      iVar10 = iVar10 + 1;
      uVar8 = uVar8 + 4;
      if (iVar10 == 0x10) goto LAB_00057c42;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 != 0xb);
LAB_00057c42:
  iVar10 = 0;
  uVar8 = 0x40000000;
  do {
    if (iVar10 << 0x1f < 0) {
      uVar7 = uVar8;
    }
    else {
      uVar7 = ~uVar8;
    }
    if (*(uint *)((1 << (iVar9 + 0xdU & 0xff)) + uVar8) != uVar7) {
      iVar10 = 3;
      goto LAB_00057c6a;
    }
    iVar10 = iVar10 + 1;
    uVar8 = uVar8 + 4;
  } while (iVar10 != 0x10);
  iVar10 = 2;
LAB_00057c6a:
  if ((*(int *)(param_1 + 4) == 4) || (*(int *)(param_1 + 4) == 9)) {
    uVar6 = 0x6118;
  }
  else {
    uVar6 = 0x2118;
  }
  *(undefined4 *)(param_1 + 0x18) = uVar6;
  uVar8 = *(uint *)(param_1 + 0x18);
  iVar9 = *(int *)(param_1 + 0x78);
  if ((*(uint *)(param_1 + 0x1c) & 0xf) == 0) {
    iVar11 = 2;
  }
  else {
    iVar11 = 1;
  }
  iVar2 = FUN_00057b7c(param_1);
  if (iVar2 != 0) {
    iVar2 = 0;
    puVar5 = (undefined4 *)&DAT_40000000;
    do {
      if (iVar2 << 0x1f < 0) {
        puVar3 = puVar5;
      }
      else {
        puVar3 = (undefined4 *)~(uint)puVar5;
      }
      *puVar5 = puVar3;
      DataSynchronizationBarrier(0xf);
      iVar2 = iVar2 + 1;
      puVar5 = puVar5 + 1;
    } while (iVar2 != 0x10);
    iVar2 = 0xc;
    iVar11 = ((((uVar8 & 0xffff) >> 0xe) + 10) - ((iVar9 << 0x19) >> 0x1f)) + iVar11;
    do {
      uVar8 = 0x40000000;
      iVar9 = 0;
      while( true ) {
        if (iVar9 << 0x1f < 0) {
          uVar7 = uVar8;
        }
        else {
          uVar7 = ~uVar8;
        }
        if (*(uint *)((1 << (iVar11 + iVar2 & 0xffU)) + uVar8) != uVar7) break;
        iVar9 = iVar9 + 1;
        uVar8 = uVar8 + 4;
        if (iVar9 == 0x10) goto LAB_00057cee;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 0x11);
    if ((*(int *)(param_1 + 4) == 4) || (*(int *)(param_1 + 4) == 9)) {
      uVar6 = 0x6128;
    }
    else {
      uVar6 = 0x2128;
    }
    *(undefined4 *)(param_1 + 0x18) = uVar6;
    iVar9 = FUN_00057b7c(param_1);
    if (iVar9 != 0) {
      iVar9 = 0;
      puVar5 = (undefined4 *)&DAT_40000000;
      do {
        if (iVar9 << 0x1f < 0) {
          puVar3 = puVar5;
        }
        else {
          puVar3 = (undefined4 *)~(uint)puVar5;
        }
        *puVar5 = puVar3;
        DataSynchronizationBarrier(0xf);
        iVar9 = iVar9 + 1;
        puVar5 = puVar5 + 1;
      } while (iVar9 != 0x10);
      uVar8 = 0x40000000;
      if (_DAT_40000000 == -0x40000001) {
        iVar9 = 0;
        do {
          if (iVar9 << 0x1f < 0) {
            uVar7 = uVar8;
          }
          else {
            uVar7 = ~uVar8;
          }
          if (*(uint *)((1 << (iVar11 + 0x11U & 0xff)) + uVar8) != uVar7) goto LAB_00057cee;
          iVar9 = iVar9 + 1;
          uVar8 = uVar8 + 4;
        } while (iVar9 != 0x10);
        iVar2 = 0x12;
      }
LAB_00057cee:
      *(uint *)(param_1 + 0x18) = uVar4 | iVar1 << 0xe | iVar10 << 0xc | iVar2 << 4;
      return 1;
    }
  }
  return 0;
}

