// rea decompile_all
// name: FUN_00056dd8
// address: 0x56dd8
// body: available
// range: 0x56dd8-0x56e41 inclusive
// range: 0x56e46-0x56ee7 inclusive
// range: 0x56eec-0x57037 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00056dd8(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  iVar8 = DAT_0005705c;
  uVar1 = *(uint *)(param_1 + 0x18);
  uVar3 = (uVar1 & 0x3fff) >> 0xc;
  uVar11 = uVar1 & 0xf;
  uVar7 = (uVar1 & 0xfff) >> 4;
  uVar1 = (uVar1 & 0xffff) >> 0xe;
  uVar4 = (*(uint *)(param_1 + 0x1c) & 0x7fff) >> 0xc;
  if (uVar4 == 7) {
    uVar4 = 2;
  }
  else {
    uVar4 = (uint)(uVar4 == 1);
  }
  uVar9 = uVar1 << 8;
  uVar10 = uVar9 | uVar1 << 0x10;
  param_2 = param_2 * 0x400000;
  *(uint *)(param_2 + DAT_0005705c) = uVar10 | uVar1 << 0x18;
  iVar6 = DAT_00057038;
  if (*(int *)(DAT_00057038 + 4) != 0) {
    *(undefined4 *)(param_2 + iVar8) = 0;
  }
  iVar8 = DAT_00057060;
  switch(uVar11) {
  case 8:
    uVar10 = uVar1 | 0x1f1f1f00;
    break;
  case 9:
    uVar10 = uVar1 | 0x1f1f0000 | uVar9;
    break;
  case 10:
    *(uint *)(param_2 + DAT_00057060) = uVar1 | 0x1f000000 | uVar9 | uVar1 << 0x10;
    if (*(int *)(iVar6 + 4) != 0) {
      uVar10 = 0x1f000000;
      break;
    }
    goto LAB_00056e56;
  default:
    uVar10 = uVar1 << 0x18 | uVar1 | uVar10;
  }
  *(uint *)(param_2 + iVar8) = uVar10;
LAB_00056e56:
  iVar8 = DAT_00057064;
  if (uVar1 == 2) {
    uVar5 = 0x101;
  }
  else {
    uVar5 = 0x3f3f;
    if (uVar1 == 1) {
      uVar5 = 0x3f01;
    }
  }
  *(undefined4 *)(param_2 + DAT_00057064) = uVar5;
  if (*(int *)(iVar6 + 4) != 0) {
    if (uVar1 == 2) {
      uVar5 = 0x909;
    }
    else {
      uVar5 = 0x3f3f;
      if (uVar1 == 1) {
        uVar5 = 0x3f09;
      }
    }
    *(undefined4 *)(param_2 + iVar8) = uVar5;
  }
  iVar8 = DAT_00057068;
  uVar9 = uVar11 - 3;
  uVar10 = uVar9 + uVar1;
  if (uVar3 == 3) {
    uVar10 = uVar10 * 0x100 | uVar10 * 0x10000 | uVar10;
LAB_00056ea8:
    *(uint *)(param_2 + iVar8) = uVar10;
  }
  else {
    *(uint *)(param_2 + DAT_00057068) = uVar10 | 0x3f0000 | uVar10 * 0x100;
    if (*(int *)(iVar6 + 4) != 0) {
      uVar10 = uVar9 | 0x3f0000 | uVar9 * 0x100;
      goto LAB_00056ea8;
    }
  }
  iVar6 = DAT_0005706c;
  iVar8 = DAT_00057040;
  iVar2 = uVar1 + uVar3 + uVar11;
  uVar1 = iVar2 - 6;
  uVar10 = uVar1 | uVar1 * 0x100;
  uVar3 = uVar10 | uVar1 * 0x10000;
  *(uint *)(param_2 + DAT_0005703c) = uVar10;
  uVar11 = uVar3 | uVar1 * 0x1000000;
  *(uint *)(param_2 + iVar8) = uVar11;
  *(uint *)(param_2 + iVar8 + -4) = uVar11;
  iVar8 = iVar8 + -0xc;
  *(uint *)(param_2 + iVar6) = uVar11;
  switch(uVar7) {
  case 0xe:
    uVar3 = 0x1f1f1f1f;
    break;
  case 0xf:
    if ((*(ushort *)(param_1 + 0x7a) & 7) - 1 < 2) {
      uVar11 = uVar1 + uVar4 | DAT_00057044;
      *(uint *)(param_2 + iVar6) = uVar3 | (uVar1 + uVar4) * 0x1000000;
      *(uint *)(param_2 + iVar8) = uVar11;
      uVar3 = iVar2 + 7;
      goto LAB_00056f6e;
    }
    uVar3 = uVar1 | DAT_00057044;
    break;
  case 0x10:
    if ((*(ushort *)(param_1 + 0x7a) & 7) == 1) {
      *(uint *)(param_2 + iVar8) = DAT_00057054 | uVar1 + uVar4 | (uVar1 + uVar4) * 0x100;
      iVar6 = *(int *)(param_1 + 4);
      iVar8 = iVar6;
      if (iVar6 == 9) {
        uVar4 = 3;
        iVar8 = DAT_00057058;
      }
      if (iVar6 == 9) {
        *(uint *)(param_2 + iVar8) = uVar4;
      }
      uVar3 = iVar2 + 8;
      goto LAB_00056f6e;
    }
    uVar11 = uVar10 | DAT_00057054;
LAB_00056fe0:
    *(uint *)(param_2 + iVar8) = uVar11;
    goto LAB_00056f76;
  case 0x11:
    if ((*(ushort *)(param_1 + 0x7a) & 7) == 1) {
      uVar3 = iVar2 + 9;
      *(uint *)(param_2 + iVar8) =
           uVar1 | 0x1f000000 | (uVar4 + uVar1) * 0x100 | (uVar4 + uVar1) * 0x10000;
      goto LAB_00056f6e;
    }
    uVar3 = uVar3 | 0x1f000000;
    break;
  default:
    if ((*(ushort *)(param_1 + 0x7a) & 7) != 1) goto LAB_00056fe0;
    *(uint *)(param_2 + iVar8) = (uVar1 + uVar4) * 0x1000000 | (uVar1 + uVar4) * 0x10000 | uVar10;
    uVar3 = (uVar7 - 8) + iVar2;
LAB_00056f6e:
    *(uint *)(param_2 + DAT_00057048) = uVar3 | 0x3f00;
    goto LAB_00056f76;
  }
  *(uint *)(param_2 + iVar8) = uVar3;
LAB_00056f76:
  if (*(int *)(param_1 + 0x1c) << 0x13 < 0) {
    if ((*(ushort *)(param_1 + 0x7a) & 7) - 1 < 2) goto LAB_00056f96;
    uVar1 = iVar2 + (uVar7 - 6) | 0x3f00;
  }
  else {
    uVar1 = 0x3f3f;
  }
  *(uint *)(param_2 + DAT_00057048) = uVar1;
LAB_00056f96:
  iVar8 = DAT_0005704c;
  if (*(int *)(param_1 + 4) == 9) {
    *(undefined4 *)(param_2 + DAT_0005704c) = DAT_00057050;
    *(undefined4 *)(param_2 + iVar8 + 4) = 0;
  }
  return;
}

