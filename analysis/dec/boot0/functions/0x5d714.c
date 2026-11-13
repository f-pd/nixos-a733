// rea decompile_all
// name: FUN_0005d714
// address: 0x5d714
// body: available
// range: 0x5d714-0x5d727 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Removing unreachable block (ram,0x0005d88e) */

int FUN_0005d714(uint param_1)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  byte bVar12;
  byte abStack_29 [5];
  
  uVar2 = DAT_0005d938;
  iVar5 = DAT_0005d8b0;
  if (*DAT_0005d728 != 0xe) {
    return -1;
  }
  iVar9 = 0;
  while( true ) {
    iVar8 = iVar9 * 0x6c + iVar5;
    uVar3 = FUN_000495f0(iVar8);
    iVar4 = FUN_000495ce(uVar2,iVar8,uVar3);
    if (iVar4 == 0) break;
    iVar9 = iVar9 + 1;
    if (iVar9 == 0x24) {
      return -1;
    }
  }
  if (iVar8 == 0) {
    return -1;
  }
  if ((0 < (int)param_1) && (uVar6 = *(uint *)(iVar8 + 0x10), uVar6 != 0)) {
    if (param_1 < uVar6) {
      param_1 = uVar6;
    }
    else if (*(uint *)(iVar8 + 0x14) <= param_1) {
      param_1 = *(uint *)(iVar8 + 0x14);
    }
    iVar5 = FUN_0004af2a(0x36,*(undefined1 *)(iVar8 + 0x18),abStack_29);
    if (iVar5 != 0) {
      return -1;
    }
    bVar1 = *(byte *)(iVar8 + 0x1c);
    bVar12 = abStack_29[0] & ~bVar1;
    uVar6 = 0;
    uVar10 = 0;
    abStack_29[0] = bVar12;
    while( true ) {
      uVar11 = uVar6 & 0xff;
      uVar7 = *(uint *)(iVar8 + uVar11 * 0x10 + 0x30);
      if (uVar7 == 0) break;
      if ((uVar7 < param_1) && (param_1 < *(uint *)(iVar8 + uVar11 * 0x10 + 0x3c))) {
        param_1 = uVar7;
      }
      iVar9 = iVar8 + (uVar11 + 3) * 0x10;
      iVar5 = *(int *)(uVar11 * 0x10 + iVar8 + 0x2c);
      uVar6 = uVar6 + 1;
      if (param_1 <= uVar7) {
        iVar5 = FUN_00048038(param_1 - iVar5);
        abStack_29[0] = bVar12 | (byte)(uVar10 + iVar5 << (*(uint *)(iVar8 + 0x28) & 0xff));
        if (*(int *)(iVar9 + 8) != 0) {
          abStack_29[0] = bVar1 ^ abStack_29[0];
        }
        break;
      }
      iVar5 = FUN_00048038((uVar7 + *(int *)(iVar9 + 4)) - iVar5);
      uVar10 = uVar10 + iVar5 & 0xff;
    }
    iVar5 = FUN_0004af3e(0x36,*(undefined1 *)(iVar8 + 0x18),abStack_29[0]);
    if (iVar5 != 0) {
      return -1;
    }
  }
  iVar5 = FUN_0004af2a(0x36,*(undefined1 *)(iVar8 + 0x20),abStack_29);
  if (iVar5 == 0) {
    abStack_29[0] = (byte)(1 << (*(uint *)(iVar8 + 0x24) & 0xff)) | abStack_29[0];
    iVar5 = FUN_0004af3e(0x36,*(undefined1 *)(iVar8 + 0x20),abStack_29[0]);
    return -(uint)(iVar5 != 0);
  }
  return -1;
}

