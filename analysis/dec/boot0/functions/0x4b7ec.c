// rea decompile_all
// name: FUN_0004b7ec
// address: 0x4b7ec
// body: available
// range: 0x4b7ec-0x4b95f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Ghidra Listing reports a terminal call at 0x4b8b4 to 0x48d80 FUN_00048d80 (external=false, thunk=false, hasNoReturn=false); fallthrough is excluded by Ghidra's flow model. The reason for the terminal flow is not established by this observation.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0004b7ec(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  
  iVar3 = DAT_0004b960;
  uVar6 = param_2 + 1;
  uVar1 = 0;
  while (iVar5 = DAT_0004b964, (uVar1 & 0xffff) < uVar6) {
    *(undefined4 *)(uVar1 * 0x400000 + iVar3) = 0;
    uVar1 = uVar1 + 1;
  }
  uVar2 = 0;
  while( true ) {
    iVar3 = DAT_0004b964;
    if (uVar6 <= uVar2) break;
    iVar3 = (uint)uVar2 * 0x400000;
    *(uint *)(iVar3 + iVar5) = *(uint *)(iVar3 + iVar5) | 0x1001;
    uVar2 = uVar2 + 1;
  }
  uVar2 = 0;
  while( true ) {
    iVar5 = DAT_0004b960;
    if (uVar6 <= uVar2) break;
    iVar5 = (uint)uVar2 * 0x400000;
    *(uint *)(iVar5 + iVar3) = *(uint *)(iVar5 + iVar3) | 0x20;
    uVar2 = uVar2 + 1;
  }
  uVar2 = 0;
  while( true ) {
    if (uVar6 <= uVar2) break;
    *(undefined4 *)((uint)uVar2 * 0x400000 + iVar5) = 1;
    uVar2 = uVar2 + 1;
  }
  for (uVar2 = 0; uVar2 < uVar6; uVar2 = uVar2 + 1) {
    do {
    } while (-1 < *(int *)(DAT_0004b968 + (uint)uVar2 * 0x400000) << 0x1f);
  }
  for (uVar1 = 0; (uVar1 & 0xffff) < uVar6; uVar1 = uVar1 + 1) {
    do {
    } while (-1 < *(int *)(DAT_0004b96c + uVar1 * 0x400000) << 0x1f);
  }
  FUN_00048d80(0x32);
  *DAT_0004b970 = *DAT_0004b970 | 1;
  FUN_00048d80(2000);
  iVar3 = DAT_0004b960;
  uVar1 = 0;
  while (iVar5 = DAT_0004b964, (uVar1 & 0xffff) < uVar6) {
    *(undefined4 *)(uVar1 * 0x400000 + iVar3) = 0;
    uVar1 = uVar1 + 1;
  }
  uVar2 = 0;
  while( true ) {
    iVar3 = DAT_0004b974;
    if (uVar6 <= uVar2) break;
    iVar3 = (uint)uVar2 * 0x400000;
    *(uint *)(iVar3 + iVar5) = *(uint *)(iVar3 + iVar5) & 0xffffffdf;
    uVar2 = uVar2 + 1;
  }
  uVar2 = 0;
  while( true ) {
    if (uVar6 <= uVar2) break;
    iVar5 = (uint)uVar2 * 0x400000;
    *(uint *)(iVar5 + iVar3) = *(uint *)(iVar5 + iVar3) & 0xfffff7ff;
    uVar2 = uVar2 + 1;
  }
  for (uVar1 = 0; (uVar1 & 0xffff) < uVar6; uVar1 = uVar1 + 1) {
    puVar4 = (uint *)(DAT_0004b978 + uVar1 * 0x400000);
    do {
    } while ((*puVar4 & 0x30) != 0);
    do {
    } while ((*puVar4 & 3) != 1);
  }
  FUN_00048d80(0x32);
  iVar3 = DAT_0004b964;
  uVar2 = 0;
  while( true ) {
    iVar5 = DAT_0004b960;
    if (uVar6 <= uVar2) break;
    iVar5 = (uint)uVar2 * 0x400000;
    *(uint *)(iVar5 + iVar3) = *(uint *)(iVar5 + iVar3) & 0xfffffffe;
    uVar2 = uVar2 + 1;
  }
  uVar2 = 0;
  while( true ) {
    if (uVar6 <= uVar2) break;
    *(undefined4 *)((uint)uVar2 * 0x400000 + iVar5) = 1;
    uVar2 = uVar2 + 1;
  }
  for (uVar1 = 0; (uVar1 & 0xffff) < uVar6; uVar1 = uVar1 + 1) {
    do {
    } while (-1 < *(int *)(DAT_0004b968 + uVar1 * 0x400000) << 0x1f);
  }
  FUN_00048d80(2,DAT_0004b968,uVar1,param_4);
  return;
}

