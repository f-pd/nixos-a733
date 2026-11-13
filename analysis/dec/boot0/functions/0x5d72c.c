// rea decompile_all
// name: FUN_0005d72c
// address: 0x5d72c
// body: available
// range: 0x5d72c-0x5d73d inclusive
// range: 0x5d760-0x5d8ad inclusive
// range: 0x5d93c-0x5d93f inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_0005d72c(undefined4 param_1,uint param_2,int param_3)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  byte bVar11;
  byte local_29 [5];
  
  iVar4 = DAT_0005d8b0;
  if (*DAT_0005d740 != 0xe) {
    return -1;
  }
  iVar8 = 0;
  while( true ) {
    iVar7 = iVar8 * 0x6c + iVar4;
    uVar2 = FUN_000495f0(iVar7);
    iVar3 = FUN_000495ce(param_1,iVar7,uVar2);
    if (iVar3 == 0) break;
    iVar8 = iVar8 + 1;
    if (iVar8 == 0x24) {
      return -1;
    }
  }
  if (iVar7 == 0) {
    return -1;
  }
  if ((0 < (int)param_2) && (uVar5 = *(uint *)(iVar7 + 0x10), uVar5 != 0)) {
    if (param_2 < uVar5) {
      param_2 = uVar5;
    }
    else if (*(uint *)(iVar7 + 0x14) <= param_2) {
      param_2 = *(uint *)(iVar7 + 0x14);
    }
    iVar4 = FUN_0004af2a(0x36,*(undefined1 *)(iVar7 + 0x18),local_29);
    if (iVar4 != 0) {
      return -1;
    }
    bVar1 = *(byte *)(iVar7 + 0x1c);
    bVar11 = local_29[0] & ~bVar1;
    uVar5 = 0;
    uVar9 = 0;
    local_29[0] = bVar11;
    while( true ) {
      uVar10 = uVar5 & 0xff;
      uVar6 = *(uint *)(iVar7 + uVar10 * 0x10 + 0x30);
      if (uVar6 == 0) break;
      if ((uVar6 < param_2) && (param_2 < *(uint *)(iVar7 + uVar10 * 0x10 + 0x3c))) {
        param_2 = uVar6;
      }
      iVar8 = iVar7 + (uVar10 + 3) * 0x10;
      iVar4 = *(int *)(uVar10 * 0x10 + iVar7 + 0x2c);
      uVar5 = uVar5 + 1;
      if (param_2 <= uVar6) {
        iVar4 = FUN_00048038(param_2 - iVar4);
        local_29[0] = bVar11 | (byte)(uVar9 + iVar4 << (*(uint *)(iVar7 + 0x28) & 0xff));
        if (*(int *)(iVar8 + 8) != 0) {
          local_29[0] = bVar1 ^ local_29[0];
        }
        break;
      }
      iVar4 = FUN_00048038((uVar6 + *(int *)(iVar8 + 4)) - iVar4);
      uVar9 = uVar9 + iVar4 & 0xff;
    }
    iVar4 = FUN_0004af3e(0x36,*(undefined1 *)(iVar7 + 0x18),local_29[0]);
    if (iVar4 != 0) {
      return -1;
    }
  }
  if (param_3 < 0) {
    return 0;
  }
  iVar4 = FUN_0004af2a(0x36,*(undefined1 *)(iVar7 + 0x20),local_29);
  if (iVar4 != 0) {
    return -1;
  }
  bVar1 = (byte)(1 << (*(uint *)(iVar7 + 0x24) & 0xff));
  if (param_3 == 0) {
    local_29[0] = local_29[0] & ~bVar1;
  }
  else {
    local_29[0] = bVar1 | local_29[0];
  }
  iVar4 = FUN_0004af3e(0x36,*(undefined1 *)(iVar7 + 0x20),local_29[0]);
  return -(uint)(iVar4 != 0);
}

