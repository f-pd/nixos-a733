// rea decompile_all
// name: FUN_00091de0
// address: 0x91de0
// body: available
// range: 0x91de0-0x91ebb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00091de0(uint *param_1,uint param_2,uint param_3)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  uint *puVar6;
  uint *puVar7;
  bool bVar8;
  
  uVar3 = (uint)param_1 & 3;
  if (uVar3 != 0) {
    uVar2 = param_3 - 4;
    if ((int)param_3 < 4) goto LAB_00091e84;
    uVar1 = (undefined1)param_2;
    puVar6 = param_1;
    if (uVar3 < 2) {
      puVar6 = (uint *)((int)param_1 + 1);
      *(undefined1 *)param_1 = uVar1;
    }
    puVar7 = puVar6;
    if (uVar3 < 3) {
      puVar7 = (uint *)((int)puVar6 + 1);
      *(undefined1 *)puVar6 = uVar1;
    }
    param_1 = (uint *)((int)puVar7 + 1);
    *(undefined1 *)puVar7 = uVar1;
    param_3 = uVar2 + uVar3;
  }
  param_2 = param_2 | param_2 << 8;
  param_2 = param_2 | param_2 << 0x10;
  if (0xf < (int)param_3) {
    bVar8 = param_3 == 0x60;
    if ((int)param_3 >= 0x61) {
      bVar8 = ((uint)param_1 & 0x1f) == 0;
    }
    uVar3 = param_3;
    if (!bVar8 && ((int)param_3 < 0x61 && (int)(param_3 - 0x60) < 0) == SBORROW4(param_3,0x60)) {
      uVar4 = 0x20 - ((uint)param_1 & 0x1f);
      uVar3 = param_3 - uVar4;
      uVar2 = ((uint)param_1 & 0x1f) * -0x10000000;
      puVar6 = param_1;
      if ((bool)((byte)(uVar4 >> 4) & 1)) {
        *param_1 = param_2;
        param_1[1] = param_2;
        param_1[2] = param_2;
        param_1[3] = param_2;
        puVar6 = param_1 + 4;
      }
      if ((int)uVar2 < 0) {
        *puVar6 = param_2;
        puVar6[1] = param_2;
        puVar6 = puVar6 + 2;
      }
      param_1 = puVar6;
      if ((uVar2 & 0x40000000) != 0) {
        param_1 = puVar6 + 1;
        *puVar6 = param_2;
      }
    }
    do {
      param_3 = uVar3 - 0x40;
      if (0x3f < (int)uVar3) {
        *param_1 = param_2;
        param_1[1] = param_2;
        param_1[2] = param_2;
        param_1[3] = param_2;
        param_1[4] = param_2;
        param_1[5] = param_2;
        param_1[6] = param_2;
        param_1[7] = param_2;
        param_1[8] = param_2;
        param_1[9] = param_2;
        param_1[10] = param_2;
        param_1[0xb] = param_2;
        param_1[0xc] = param_2;
        param_1[0xd] = param_2;
        param_1[0xe] = param_2;
        param_1[0xf] = param_2;
        param_1 = param_1 + 0x10;
      }
      bVar8 = 0x3f < (int)uVar3;
      uVar3 = param_3;
    } while (param_3 != 0 && bVar8);
    if (param_3 == 0) {
      return;
    }
    if ((param_3 & 0x20) != 0) {
      *param_1 = param_2;
      param_1[1] = param_2;
      param_1[2] = param_2;
      param_1[3] = param_2;
      param_1[4] = param_2;
      param_1[5] = param_2;
      param_1[6] = param_2;
      param_1[7] = param_2;
      param_1 = param_1 + 8;
    }
    if ((param_3 & 0x10) != 0) {
      *param_1 = param_2;
      param_1[1] = param_2;
      param_1[2] = param_2;
      param_1[3] = param_2;
      param_1 = param_1 + 4;
    }
  }
  puVar6 = param_1;
  if ((param_3 & 8) != 0) {
    *param_1 = param_2;
    param_1[1] = param_2;
    puVar6 = param_1 + 2;
  }
  uVar2 = param_3;
  param_1 = puVar6;
  if ((param_3 & 4) != 0) {
    param_1 = puVar6 + 1;
    *puVar6 = param_2;
  }
LAB_00091e84:
  uVar1 = (undefined1)param_2;
  if ((uVar2 & 2) != 0) {
    puVar5 = (undefined1 *)((int)param_1 + 1);
    *(undefined1 *)param_1 = uVar1;
    param_1 = (uint *)((int)param_1 + 2);
    *puVar5 = uVar1;
  }
  if ((uVar2 & 1) != 0) {
    *(undefined1 *)param_1 = uVar1;
  }
  return;
}

