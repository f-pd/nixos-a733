// rea decompile_all
// name: FUN_0005d1f0
// address: 0x5d1f0
// body: available
// range: 0x5d1f0-0x5d38f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_0005d1f0(int param_1,uint param_2,uint param_3,undefined1 *param_4,undefined1 *param_5)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar6 = DAT_0005d394;
  iVar5 = *(int *)(param_1 * 0x34 + DAT_0005d390 + 0x24);
  if (param_1 != 2) {
    if ((param_1 != 0) || (iVar5 != 1)) goto LAB_0005d37e;
    if ((param_2 < 2) && (param_3 < 3)) {
      *param_4 = 0;
      *param_5 = 0;
      return 0;
    }
    iVar6 = 1;
    uVar2 = DAT_0005d3a8;
    uVar1 = DAT_0005d390;
    goto LAB_0005d27a;
  }
  if (iVar5 != 4) {
LAB_0005d37e:
    FUN_000498e4(DAT_0005d3ac);
    return 0xffffffff;
  }
  if (*(int *)(DAT_0005d394 + 0x14) == DAT_0005d398) {
    uVar1 = (uint)*(byte *)(DAT_0005d394 + 0x60);
  }
  else {
    uVar1 = 0;
  }
  if ((uVar1 & 1) == 0) {
    if ((uVar1 & 2) == 0) {
      if (4 < param_2) {
        FUN_000498e4(DAT_0005d3a4,2,param_2,param_3,param_4);
        return 0xffffffff;
      }
      iVar6 = DAT_0005d394 + (param_2 * 2 + (param_3 >> 2)) * 4;
      iVar5 = (param_3 & 3) << 3;
      uVar7 = *(uint *)(iVar6 + 0x30) >> iVar5;
      uVar1 = uVar7 & 0xff;
      uVar3 = (undefined1)uVar7;
      if ((uVar1 == 0xff) || (uVar1 == 0)) {
        if (param_2 == 0) {
          if (param_3 < 2) {
LAB_0005d360:
            uVar7 = 0;
            uVar1 = uVar7;
            goto LAB_0005d31c;
          }
LAB_0005d310:
          FUN_000498e4(DAT_0005d39c,param_3,param_2,iVar5,param_4);
        }
        else {
          if (param_2 == 1) {
            if (param_3 < 2) goto LAB_0005d360;
            if (param_3 == 2) {
              uVar1 = 0xf;
              uVar7 = 0;
              goto LAB_0005d31c;
            }
            goto LAB_0005d310;
          }
          if (param_2 == 2) {
            if (param_3 < 2) {
              uVar3 = 0;
              uVar7 = 0;
            }
            else {
              FUN_000498e4(DAT_0005d39c,param_3,2,iVar5,param_4);
              uVar7 = 0xffffffff;
            }
            goto LAB_0005d346;
          }
          FUN_000498e4(DAT_0005d3a0,param_2,*(undefined1 *)(iVar6 + 0x32),iVar5,param_4);
        }
        uVar7 = 0xffffffff;
      }
      else {
        uVar7 = 0;
        if (param_2 == 2) {
LAB_0005d346:
          uVar4 = 1;
          goto LAB_0005d348;
        }
        uVar7 = 0;
      }
LAB_0005d31c:
      uVar3 = (undefined1)uVar1;
      uVar4 = 0;
LAB_0005d348:
      *param_4 = uVar4;
      *param_5 = uVar3;
      return uVar7;
    }
    if (param_2 == 0) goto LAB_0005d23a;
    if (param_2 == 1) {
      if (param_3 < 2) goto LAB_0005d25e;
      if (param_3 == 2) {
        *param_4 = *(undefined1 *)(DAT_0005d394 + 0x61);
        uVar3 = *(undefined1 *)(iVar6 + 0x62);
LAB_0005d2a0:
        *param_5 = uVar3;
        return 0;
      }
      goto LAB_0005d272;
    }
    if (param_2 != 2) goto LAB_0005d276;
    if (1 < param_3) {
      if (param_3 == 2) {
        *param_4 = *(undefined1 *)(DAT_0005d394 + 99);
        uVar3 = *(undefined1 *)(iVar6 + 100);
        goto LAB_0005d2a0;
      }
      uVar2 = 2;
      goto LAB_0005d24a;
    }
  }
  else {
    if (param_2 != 0) {
      if (param_2 != 1) {
LAB_0005d276:
        uVar2 = DAT_0005d3a0;
LAB_0005d27a:
        FUN_000498e4(uVar2,param_2,uVar1,iVar6,param_4);
        return 0xffffffff;
      }
      if (param_3 < 2) {
LAB_0005d25e:
        uVar3 = 3;
        *param_4 = 0;
        goto LAB_0005d244;
      }
      if (param_3 == 2) {
        uVar3 = 4;
        *param_4 = 0;
        goto LAB_0005d244;
      }
LAB_0005d272:
      uVar2 = 1;
      goto LAB_0005d24a;
    }
LAB_0005d23a:
    if (1 < param_3) {
      uVar2 = 0;
LAB_0005d24a:
      FUN_000498e4(DAT_0005d39c,param_3,uVar2,DAT_0005d394,param_4);
      return 0xffffffff;
    }
  }
  uVar3 = 2;
  *param_4 = 0;
LAB_0005d244:
  *param_5 = uVar3;
  return 0;
}

