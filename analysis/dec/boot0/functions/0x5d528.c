// rea decompile_all
// name: FUN_0005d528
// address: 0x5d528
// body: available
// range: 0x5d528-0x5d66f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0005d528(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = DAT_0005d670;
  iVar4 = DAT_0005d670 + 0xa0;
  FUN_000498e4(DAT_0005d678,DAT_0005d674);
  iVar4 = param_1 * 0x108 + iVar4;
  thunk_FUN_00047c40(iVar4,0);
  iVar5 = param_1 * 0x34 + iVar1;
  thunk_FUN_00047c40(iVar5,0);
  *(int *)(iVar5 + 0x28) = iVar4;
  if (param_1 < 2) {
    *(undefined4 *)(iVar5 + 0x24) = 1;
  }
  else if (param_1 == 2) {
    *(undefined4 *)(iVar1 + 0x8c) = 4;
  }
  FUN_000495a8(iVar4,DAT_0005d67c);
  iVar3 = param_1 * 0x108 + iVar1;
  *(undefined4 *)(iVar3 + 0x148) = DAT_0005d680;
  uVar2 = DAT_0005d684;
  *(int *)(iVar3 + 0xc0) = iVar5;
  *(undefined4 *)(iVar3 + 0x14c) = uVar2;
  *(undefined4 *)(iVar3 + 0x150) = DAT_0005d688;
  *(undefined4 *)(iVar3 + 0x154) = DAT_0005d68c;
  *(undefined4 *)(iVar3 + 0xc4) = 0xfe0000;
  if (param_2 < 4) {
    uVar2 = 0x23;
  }
  else {
    uVar2 = 0x27;
  }
  *(undefined4 *)(iVar3 + 0xf0) = uVar2;
  if ((param_1 == 2) && (param_2 == 8)) {
    *(uint *)(iVar1 + 0x300) = *(uint *)(iVar1 + 0x300) | 0xc;
  }
  iVar5 = DAT_0005d690;
  iVar3 = param_1 * 0x108 + iVar1;
  *(int *)(iVar3 + 0xd4) = DAT_0005d690;
  *(uint *)(iVar3 + 0xd0) = param_1;
  *(int *)(iVar3 + 0xd8) = iVar5 + 49600000;
  *(int *)(iVar3 + 0xdc) = iVar5 + 49600000;
  iVar5 = iVar1 + param_1 * 0x34;
  *(undefined4 *)(iVar5 + 0x20) = 0x42000000;
  iVar3 = (param_1 + 0x4020) * 0x1000;
  *(int *)(iVar1 + param_1 * 0x34) = iVar3;
  *(int *)(iVar5 + 0x14) = iVar3 + 0x200;
  iVar3 = DAT_0005d694 + param_1 * 0x10;
  *(int *)(iVar5 + 8) = iVar3;
  *(int *)(iVar5 + 0xc) = iVar3;
  if (param_1 == 0) {
    *(undefined4 *)(iVar1 + 0x10) = DAT_0005d698;
  }
  else {
    if (param_1 != 2) {
      FUN_000498e4(DAT_0005d6a4,param_1);
      uVar2 = DAT_0005d6a8;
      goto LAB_0005d656;
    }
    *(undefined4 *)(iVar1 + 0x78) = DAT_0005d6a0;
  }
  *(uint *)(param_1 * 0x34 + iVar1 + 4) = param_1;
  FUN_0005d188(param_1,param_3,param_4);
  iVar4 = FUN_0005ce50(param_1,iVar4);
  if (-1 < iVar4) {
    return *(undefined4 *)(param_1 * 0x108 + iVar1 + 0x18c);
  }
  uVar2 = DAT_0005d69c;
LAB_0005d656:
  FUN_000498e4(uVar2,param_1);
  return 0xffffffff;
}

