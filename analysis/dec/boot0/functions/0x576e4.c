// rea decompile_all
// name: FUN_000576e4
// address: 0x576e4
// body: available
// range: 0x576e4-0x57897 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000576e4(int param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort uVar4;
  ushort *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  ushort *puVar11;
  
  puVar5 = DAT_0005789c;
  *DAT_00057898 = 0;
  puVar10 = (uint *)(param_1 + 0x80);
  puVar11 = DAT_000578a0;
  do {
    uVar4 = puVar11[1];
    *puVar10 = (puVar11[0x1000] & 0x7f) << 8 | (puVar11[0x2000] & 0x7f) << 0x10 | *puVar11 & 0x7f |
               (puVar11[0x3000] & 0x7f) << 0x18;
    puVar3 = puVar11 + 0x1001;
    puVar1 = puVar11 + 0x2001;
    puVar2 = puVar11 + 0x3001;
    puVar11 = puVar11 + 0x100;
    puVar10[9] = (*puVar3 & 0x7f) << 8 | (*puVar1 & 0x7f) << 0x10 | uVar4 & 0x7f |
                 (*puVar2 & 0x7f) << 0x18;
    puVar10 = puVar10 + 1;
  } while (puVar11 != puVar5);
  if (*(int *)(param_1 + 4) == 9) {
    FUN_0004b554(0,0x10,5);
    FUN_0004b554(1,0x10,5);
  }
  if (*(int *)(param_1 + 4) == 8) {
    FUN_0004b554(0,0xd,200);
    FUN_0004b554(1,0xd,200);
  }
  uVar6 = FUN_0004b5ac(param_1,0,0,0xe);
  iVar7 = FUN_0004b5ac(param_1,0,1,0xe);
  iVar8 = FUN_0004b5ac(param_1,1,0,0xe);
  iVar9 = FUN_0004b5ac(param_1,1,1,0xe);
  *(uint *)(param_1 + 200) = uVar6 | iVar8 << 0x10 | iVar7 << 8 | iVar9 << 0x18;
  if (*(int *)(param_1 + 4) == 9) {
    uVar6 = FUN_0004b5ac(param_1,0,0,0xf);
    iVar7 = FUN_0004b5ac(param_1,0,1,0xf);
    iVar8 = FUN_0004b5ac(param_1,1,0,0xf);
    iVar9 = FUN_0004b5ac(param_1,1,1,0xf);
    *(uint *)(param_1 + 0xcc) = uVar6 | iVar8 << 0x10 | iVar7 << 8 | iVar9 << 0x18;
  }
  if (*(int *)(param_1 + 4) == 9) {
    FUN_0004b554(0,0x10,4);
    FUN_0004b554(1,0x10,4);
  }
  if (*(int *)(param_1 + 4) == 8) {
    FUN_0004b554(0,0xd,0x80);
    FUN_0004b554(1,0xd,0x80);
  }
  *DAT_00057898 = 1;
  return;
}

