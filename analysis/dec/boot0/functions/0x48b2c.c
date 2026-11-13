// rea decompile_all
// name: FUN_00048b2c
// address: 0x48b2c
// body: available
// range: 0x48b2c-0x48c93 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


ulonglong FUN_00048b2c(undefined4 param_1,uint param_2,uint param_3,uint param_4)

{
  uint extraout_r2;
  uint uVar1;
  uint extraout_r3;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint unaff_r5;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint extraout_r12;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  undefined8 uVar15;
  
  uVar15 = CONCAT44(param_2,param_1);
  uVar11 = 0x7ff;
  uVar5 = param_2 >> 0x14 & 0x7ff;
  bVar12 = uVar5 == 0;
  if (!bVar12) {
    unaff_r5 = param_4 >> 0x14 & 0x7ff;
    bVar12 = unaff_r5 == 0;
  }
  if (!bVar12) {
    bVar12 = uVar5 == 0x7ff;
  }
  if (!bVar12) {
    bVar12 = unaff_r5 == 0x7ff;
  }
  if (bVar12) {
    uVar15 = FUN_00048c9a();
    param_3 = extraout_r2;
    param_4 = extraout_r3;
    uVar11 = extraout_r12;
  }
  uVar7 = (uint)((ulonglong)uVar15 >> 0x20);
  uVar9 = (uint)uVar15;
  iVar6 = uVar5 - unaff_r5;
  if (param_3 == 0 && (param_4 & 0xfffff) == 0) {
    uVar5 = (uVar7 ^ param_4) & 0x80000000 | uVar7 & 0xfffff;
    bVar13 = SCARRY4(iVar6,uVar11 >> 1);
    uVar7 = iVar6 + (uVar11 >> 1);
    bVar12 = (int)uVar7 < 0;
    bVar14 = uVar7 == 0;
    if (!bVar14 && bVar12 == bVar13) {
      bVar13 = SBORROW4(uVar11,uVar7);
      bVar12 = (int)(uVar11 - uVar7) < 0;
      bVar14 = uVar11 == uVar7;
    }
    if (!bVar14 && bVar12 == bVar13) {
      return CONCAT44(uVar5 | uVar7 * 0x100000,uVar9);
    }
    uVar5 = uVar5 | 0x100000;
    uVar2 = 0;
    bVar14 = SBORROW4(uVar7,1);
    uVar7 = uVar7 - 1;
    bVar12 = uVar7 == 0;
    uVar11 = uVar7;
  }
  else {
    uVar2 = (param_4 & 0xfffff) << 8 | 0x10000000 | param_3 >> 0x18;
    uVar11 = param_3 << 8;
    uVar8 = (uVar7 & 0xfffff) << 8 | 0x10000000 | uVar9 >> 0x18;
    uVar9 = uVar9 * 0x100;
    uVar5 = (uVar7 ^ param_4) & 0x80000000;
    bVar12 = uVar2 <= uVar8;
    if (uVar8 == uVar2) {
      bVar12 = uVar11 <= uVar9;
    }
    iVar6 = iVar6 + (uint)bVar12;
    uVar7 = iVar6 + 0x3fd;
    if (bVar12 == false) {
      uVar2 = uVar2 >> 1;
      uVar11 = (uint)((param_3 >> 0x18 & 1) != 0) << 0x1f | (param_3 & 0xffffff) << 7;
    }
    uVar10 = uVar9 - uVar11;
    uVar8 = (uVar8 - uVar2) - (uint)(uVar9 < uVar11);
    uVar3 = uVar2 >> 1;
    uVar1 = (uint)((uVar2 & 1) != 0) << 0x1f | uVar11 >> 1;
    uVar9 = 0x100000;
    uVar11 = 0x80000;
    while( true ) {
      bVar12 = uVar1 <= uVar10;
      if (uVar3 < uVar8 || uVar8 - uVar3 < (uint)bVar12) {
        uVar10 = uVar10 - uVar1;
        uVar9 = uVar9 | uVar11;
        uVar8 = (uVar8 - uVar3) - (uint)!bVar12;
      }
      uVar4 = uVar3 >> 1;
      uVar2 = (uint)((uVar3 & 1) != 0) << 0x1f | uVar1 >> 1;
      bVar12 = uVar2 <= uVar10;
      if (uVar4 < uVar8 || uVar8 - uVar4 < (uint)bVar12) {
        uVar10 = uVar10 - uVar2;
        uVar9 = uVar9 | uVar11 >> 1;
        uVar8 = (uVar8 - uVar4) - (uint)!bVar12;
      }
      uVar1 = uVar3 >> 2;
      uVar4 = (uint)((uVar4 & 1) != 0) << 0x1f | uVar2 >> 1;
      bVar12 = uVar4 <= uVar10;
      if (uVar1 < uVar8 || uVar8 - uVar1 < (uint)bVar12) {
        uVar10 = uVar10 - uVar4;
        uVar9 = uVar9 | uVar11 >> 2;
        uVar8 = (uVar8 - uVar1) - (uint)!bVar12;
      }
      uVar3 = uVar3 >> 3;
      uVar1 = (uint)((uVar1 & 1) != 0) << 0x1f | uVar4 >> 1;
      bVar12 = uVar1 <= uVar10;
      if (uVar3 < uVar8 || uVar8 - uVar3 < (uint)bVar12) {
        uVar10 = uVar10 - uVar1;
        uVar9 = uVar9 | uVar11 >> 3;
        uVar8 = (uVar8 - uVar3) - (uint)!bVar12;
      }
      uVar2 = uVar8 | uVar10;
      if (uVar2 == 0) break;
      uVar8 = uVar8 << 4 | uVar10 >> 0x1c;
      uVar10 = uVar10 << 4;
      uVar3 = uVar3 << 3 | uVar1 >> 0x1d;
      uVar1 = (uVar4 >> 1) << 3;
      uVar11 = uVar11 >> 4;
      if (uVar11 == 0) {
        if ((uVar5 & 0x100000) != 0) goto LAB_00048c4a;
        uVar5 = uVar5 | uVar9;
        uVar9 = 0;
        uVar11 = 0x80000000;
      }
    }
    if ((uVar5 & 0x100000) == 0) {
      uVar5 = uVar5 | uVar9;
      uVar9 = 0;
    }
LAB_00048c4a:
    bVar13 = 0xfc < uVar7;
    bVar14 = SBORROW4(uVar7,0xfd);
    uVar4 = iVar6 + 0x300;
    bVar12 = uVar4 == 0;
    uVar11 = uVar4;
    if (bVar13 && !bVar12) {
      bVar13 = 0x6ff < uVar4;
      bVar14 = SBORROW4(uVar4,0x700);
      uVar11 = iVar6 - 0x400;
      bVar12 = uVar4 == 0x700;
    }
    if (!bVar13 || bVar12) {
      bVar12 = uVar3 <= uVar8;
      if (uVar8 == uVar3) {
        bVar12 = uVar1 <= uVar10;
      }
      if (uVar8 == uVar3 && uVar10 == uVar1) {
        bVar12 = (uVar9 & 1) != 0;
      }
      return CONCAT44(uVar5 + uVar7 * 0x100000 + (uint)CARRY4(uVar9,(uint)bVar12),uVar9 + bVar12);
    }
  }
  if (!bVar12 && (int)uVar11 < 0 == bVar14) {
    return (ulonglong)(uVar5 & 0x80000000 | 0x7ff00000) << 0x20;
  }
  if ((int)uVar7 < -0x35) {
    return (ulonglong)(uVar5 & 0x80000000) << 0x20;
  }
  uVar11 = -uVar7;
  uVar8 = uVar11 - 0x20;
  if (0x1f < (int)uVar11) {
    uVar7 = uVar9 >> (uVar8 & 0xff) | uVar5 << (0x20 - uVar8 & 0xff);
    uVar11 = (uVar5 >> (uVar8 & 0xff) & ~((uVar5 & 0x80000000) >> (uVar8 & 0xff))) -
             ((int)uVar7 >> 0x1f);
    if ((uVar2 == 0 && uVar9 << (0x20 - uVar8 & 0xff) == 0) && (uVar7 & 0x7fffffff) == 0) {
      uVar11 = uVar11 & ~(uVar7 >> 0x1f);
    }
    return CONCAT44(uVar5,uVar11) & 0x80000000ffffffff;
  }
  if (uVar11 - 0x14 == 0 || (int)uVar8 < -0xc) {
    uVar8 = uVar9 << (uVar7 + 0x20 & 0xff);
    uVar9 = uVar9 >> (uVar11 & 0xff) | uVar5 << (uVar7 + 0x20 & 0xff);
    uVar7 = uVar9 + -((int)uVar8 >> 0x1f);
    if (uVar2 == 0 && (uVar8 & 0x7fffffff) == 0) {
      uVar7 = uVar7 & ~(uVar8 >> 0x1f);
    }
    return CONCAT44((uVar5 & 0x80000000) +
                    ((uVar5 & 0x7fffffff) >> (uVar11 & 0xff)) +
                    (uint)CARRY4(uVar9,-((int)uVar8 >> 0x1f)),uVar7);
  }
  uVar11 = 0xc - (uVar11 - 0x14);
  uVar7 = uVar9 << (uVar11 & 0xff);
  uVar11 = uVar9 >> (0x20 - uVar11 & 0xff) | uVar5 << (uVar11 & 0xff);
  uVar9 = uVar11 + -((int)uVar7 >> 0x1f);
  if (uVar2 == 0 && (uVar7 & 0x7fffffff) == 0) {
    uVar9 = uVar9 & ~(uVar7 >> 0x1f);
  }
  return CONCAT44((uVar5 & 0x80000000) + (uint)CARRY4(uVar11,-((int)uVar7 >> 0x1f)),uVar9);
}

