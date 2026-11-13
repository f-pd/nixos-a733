// rea decompile_all
// name: FUN_000561a0
// address: 0x561a0
// body: available
// range: 0x561a0-0x562a1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000561a0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  ushort uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  
  iVar1 = DAT_000562a4;
  uVar5 = 0;
  if ((*(uint *)(param_1 + 0x78) & 0x40) == 0) {
    uVar8 = 1;
  }
  else {
    uVar8 = 2;
  }
  while (iVar7 = DAT_000562a8, (uVar5 & 0xffff) < uVar8) {
    *(undefined4 *)(uVar5 * 0x400000 + iVar1) = 0;
    uVar5 = uVar5 + 1;
  }
  uVar5 = 0;
  while (iVar1 = DAT_000562ac, (uVar5 & 0xffff) < uVar8) {
    *(undefined4 *)(uVar5 * 0x400000 + iVar7) = 0;
    uVar5 = uVar5 + 1;
  }
  uVar4 = 0;
  while( true ) {
    iVar7 = DAT_000562a4;
    if (uVar8 <= uVar4) break;
    iVar7 = (uint)uVar4 * 0x400000;
    *(uint *)(iVar7 + iVar1) = *(uint *)(iVar7 + iVar1) & 0xffff3fff | 0x4000;
    uVar4 = uVar4 + 1;
  }
  uVar4 = 0;
  while( true ) {
    puVar3 = DAT_000562d4;
    puVar6 = DAT_000562b8;
    if (uVar8 <= uVar4) break;
    *(undefined4 *)((uint)uVar4 * 0x400000 + iVar7) = 1;
    uVar4 = uVar4 + 1;
  }
  for (uVar4 = 0; uVar4 < uVar8; uVar4 = uVar4 + 1) {
    do {
    } while (-1 < *(int *)(DAT_000562b0 + (uint)uVar4 * 0x400000) << 0x1f);
  }
  if (uVar8 == 2) {
    *DAT_000562b4 = 0x8002;
    *puVar6 = 0xffffffff;
    puVar6 = DAT_000562bc;
    *DAT_000562bc = 0x8002;
    puVar6[0x4000] = 0x8002;
    puVar6 = DAT_000562c0;
    *DAT_000562c0 = 0xffffffff;
    puVar6[0x4000] = 0xffffffff;
    puVar6 = DAT_000562c4;
    *DAT_000562c4 = 2;
    puVar6[-0xeb] = 2;
    puVar6[-0x6b] = 2;
    uVar9 = DAT_000562cc;
    uVar2 = DAT_000562c8;
    uRam02023a04 = 0xffffffff;
    uRam02023c04 = 0xffffffff;
    uRam02023e04 = 0xffffffff;
    uRam02024004 = 0xffffffff;
    uRam02024204 = 0xffffffff;
    uRam02024490 = DAT_000562c8;
    puVar6[-0xe9] = DAT_000562cc;
    puVar6[-0x6a] = uVar2;
    puVar6 = DAT_000562d0;
  }
  else {
    *DAT_000562d4 = 1;
    puVar3[0x80] = 1;
    puVar6 = DAT_000562d8;
    uVar9 = 3;
    *DAT_000562d8 = 3;
    puVar6 = puVar6 + 0x4000;
  }
  *puVar6 = uVar9;
  return;
}

