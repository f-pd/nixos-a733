// rea decompile_all
// name: FUN_000914d8
// address: 0x914d8
// body: available
// range: 0x914d8-0x91629 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_000914d8(undefined4 param_1,uint param_2,int param_3,int param_4,int param_5)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  byte bVar10;
  uint uVar11;
  byte local_29 [5];
  
  iVar9 = 0;
  while( true ) {
    if (param_5 <= iVar9) {
      return -1;
    }
    uVar3 = FUN_00092bc6(param_4);
    iVar4 = FUN_00092b8c(param_1,param_4,uVar3);
    puVar2 = DAT_0009162c;
    if (iVar4 == 0) break;
    iVar9 = iVar9 + 1;
    param_4 = param_4 + 0x6c;
  }
  if (param_4 == 0) {
    return -1;
  }
  if ((param_2 != 0) && (uVar8 = *(uint *)(param_4 + 0x10), uVar8 != 0)) {
    if (uVar8 <= param_2) {
      uVar8 = param_2;
      if (*(uint *)(param_4 + 0x14) <= param_2) {
        uVar8 = *(uint *)(param_4 + 0x14);
      }
    }
    iVar9 = FUN_000913c8(*DAT_0009162c,*(undefined1 *)(param_4 + 0x18),local_29);
    if (iVar9 != 0) {
      return -1;
    }
    bVar1 = *(byte *)(param_4 + 0x1c);
    bVar10 = local_29[0] & ~bVar1;
    uVar6 = 0;
    uVar7 = 0;
    local_29[0] = bVar10;
    while( true ) {
      uVar11 = uVar6 & 0xff;
      iVar9 = param_4 + uVar11 * 0x10;
      uVar5 = *(uint *)(iVar9 + 0x30);
      if (uVar5 == 0) break;
      iVar9 = *(int *)(iVar9 + 0x2c);
      if (uVar8 <= uVar5) {
        uVar5 = uVar8;
LAB_000915d6:
        iVar9 = FUN_000a3750(uVar5 - iVar9);
        local_29[0] = bVar10 | (byte)(uVar7 + iVar9 << (*(uint *)(param_4 + 0x28) & 0xff));
        if (*(int *)(param_4 + (uVar11 + 3) * 0x10 + 8) != 0) {
          local_29[0] = bVar1 ^ local_29[0];
        }
        break;
      }
      uVar6 = uVar6 + 1;
      if (uVar8 < *(uint *)(param_4 + uVar11 * 0x10 + 0x3c)) goto LAB_000915d6;
      iVar9 = FUN_000a3750((uVar5 + *(int *)(param_4 + (uVar11 + 3) * 0x10 + 4)) - iVar9);
      uVar7 = uVar7 + iVar9 & 0xff;
    }
    iVar9 = FUN_00091418(*puVar2,*(undefined1 *)(param_4 + 0x18),local_29[0]);
    if (iVar9 != 0) {
      return -1;
    }
  }
  puVar2 = DAT_0009162c;
  if (param_3 < 0) {
    return 0;
  }
  iVar9 = FUN_000913c8(*DAT_0009162c,*(undefined1 *)(param_4 + 0x20),local_29);
  if (iVar9 != 0) {
    return -1;
  }
  bVar1 = (byte)(1 << (*(uint *)(param_4 + 0x24) & 0xff));
  if (param_3 == 0) {
    local_29[0] = local_29[0] & ~bVar1;
  }
  else {
    local_29[0] = local_29[0] | bVar1;
  }
  iVar9 = FUN_00091418(*puVar2,*(undefined1 *)(param_4 + 0x20),local_29[0]);
  return -(uint)(iVar9 != 0);
}

