// rea decompile_all
// name: FUN_00057b7c
// address: 0x57b7c
// body: available
// range: 0x578a4-0x57a1d inclusive
// range: 0x57b7c-0x57b8d inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00057b7c(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 unaff_r4;
  int iVar8;
  
  FUN_00057a4c();
  puVar2 = DAT_00057a24;
  puVar1 = DAT_00057a20;
  if ((*(uint *)(param_1 + 0x78) & 0x40) == 0) {
    iVar8 = 1;
  }
  else {
    iVar8 = 2;
  }
  *DAT_00057a20 = *DAT_00057a20 & 0xffffffeb;
  *puVar1 = *puVar1 & 0xffffffd7;
  if (iVar8 == 2) {
    uVar7 = *puVar1 & 0xffffc0c0 | 0x2728;
  }
  else {
    uVar7 = *puVar1 & 0xffffc0c0 | 0x2208;
  }
  *puVar1 = uVar7;
  puVar3 = DAT_00057a28;
  uVar7 = *puVar2 & 0xfffffffc;
  if (iVar8 == 2) {
    uVar7 = uVar7 | 2;
  }
  if (*(int *)(param_1 + 4) == 9) {
    uVar7 = uVar7 | 1;
  }
  *puVar2 = uVar7;
  puVar4 = DAT_00057a2c;
  *puVar3 = 0x103;
  *puVar4 = 0x13ff;
  puVar4[1] = 0x103;
  *DAT_00057a30 = 0x13ff;
  *puVar3 = 0x107;
  puVar4[1] = 0x107;
  *DAT_00057a34 = *DAT_00057a34 | 1;
  FUN_00048d80(10000);
  FUN_00057238(param_1,0);
  if (*(int *)(param_1 + 4) == 9) {
    *DAT_00057a38 = *DAT_00057a38 | 1;
  }
  puVar3 = DAT_00057a3c;
  *DAT_00057a3c = 2;
  FUN_000570d4(param_1,0,2,puVar3,unaff_r4);
  if (iVar8 == 2) {
    FUN_00057238(param_1,1);
    if (*(int *)(param_1 + 4) == 9) {
      *DAT_00057a40 = *DAT_00057a40 | 1;
    }
    puVar3 = DAT_00057a44;
    *DAT_00057a44 = 2;
    FUN_000570d4(param_1,1,2,puVar3,unaff_r4);
  }
  if (iVar8 == 2) {
    uVar7 = *puVar1 & 0xffffffef | 0x14;
  }
  else {
    uVar7 = *puVar1 & 0xffffffef | 4;
  }
  *puVar1 = uVar7;
  *puVar1 = *puVar1 & 0xfffffffe | 2;
  FUN_00048d80(1);
  *puVar1 = *puVar1 | 3;
  FUN_00048d80(1);
  iVar5 = FUN_00055990(param_1);
  uVar6 = 0;
  if (iVar5 != 0) {
    if ((*(int *)(param_1 + 4) == 9) && (FUN_00057310(param_1,0), iVar8 == 2)) {
      FUN_00057310(param_1,1);
    }
    FUN_0004b7ec(param_1,iVar8 + -1);
    FUN_000561a0(param_1);
    puVar1 = DAT_00057a48;
    if ((*(int *)(param_1 + 0x78) << 7 < 0) && (*DAT_00057a48 = *DAT_00057a48 | 0x11, iVar8 == 2)) {
      puVar1[0x100000] = puVar1[0x100000] | 0x11;
    }
    if (*(int *)(param_1 + 0x78) << 0x1d < 0) {
      FUN_000581b4(param_1,1,0);
    }
    uVar6 = 1;
  }
  return uVar6;
}

