// rea decompile_all
// name: FUN_0004ae28
// address: 0x4ae28
// body: available
// range: 0x4ad2c-0x4adfd inclusive
// range: 0x4ae28-0x4aed9 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0004ae28(int param_1,int param_2)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  uint *puVar7;
  uint uVar8;
  undefined4 unaff_lr;
  
  piVar1 = DAT_0004aedc;
  *DAT_0004aedc = param_1;
  FUN_0004a5cc(piVar1[2],2,1);
  puVar7 = DAT_0004aee4;
  puVar2 = DAT_0004aee0;
  uVar5 = param_1 + 0xfdaf0000U >> 10;
  if (uVar5 < 6) {
    DataMemoryBarrier(0x1f);
    DataMemoryBarrier(0x1f);
    *DAT_0004aee0 = 1 << (uVar5 + 0x10 & 0xff) | *DAT_0004aee0;
    uVar8 = *puVar2;
    DataMemoryBarrier(0x1f);
    puVar7 = puVar2;
  }
  else {
    uVar5 = param_1 + 0xf8f7d000U >> 10;
    DataMemoryBarrier(0x1f);
    uVar8 = 1 << (uVar5 + 0x10 & 0xff);
    DataMemoryBarrier(0x1f);
    *DAT_0004aee4 = *DAT_0004aee4 & ~uVar8;
    DataMemoryBarrier(0x1f);
    DataMemoryBarrier(0x1f);
    *puVar7 = uVar8 | *puVar7;
    uVar8 = *puVar7;
    DataMemoryBarrier(0x1f);
  }
  uVar5 = 1 << (uVar5 & 0xff);
  DataMemoryBarrier(0x1f);
  *puVar7 = uVar8 & ~uVar5;
  FUN_00048da4();
  DataMemoryBarrier(0x1f);
  *puVar7 = uVar8 | uVar5;
  piVar1 = DAT_0004ae00;
  iVar4 = *DAT_0004ae00;
  *(undefined4 *)(iVar4 + 0x18) = 1;
  iVar3 = 0x10000;
  do {
    if (*(int *)(iVar4 + 0x18) == 0) break;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if ((*(uint *)(iVar4 + 0x20) & 0x30) != 0x30) {
    iVar3 = 10;
    *(undefined4 *)(iVar4 + 0x20) = 5;
    FUN_00048d80(500);
    do {
      iVar4 = *piVar1;
      if (*(int *)(iVar4 + 0x20) << 0x1e < 0) break;
      *(uint *)(iVar4 + 0x20) = *(uint *)(iVar4 + 0x20) | 8;
      *(uint *)(iVar4 + 0x20) = *(uint *)(iVar4 + 0x20) | 2;
      FUN_00048d80(1000);
      iVar4 = *piVar1;
      *(uint *)(iVar4 + 0x20) = *(uint *)(iVar4 + 0x20) & 0xfffffff7;
      *(uint *)(iVar4 + 0x20) = *(uint *)(iVar4 + 0x20) & 0xfffffffd;
      FUN_00048d80(1000);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *(undefined4 *)(*piVar1 + 0x20) = 0;
    FUN_00048d80(500);
  }
  uVar5 = 0;
  iVar6 = (int)((longlong)param_2 * (longlong)DAT_0004ae04 >> 0x26) - (param_2 >> 0x1f);
  iVar4 = 1;
  iVar3 = iVar6;
  if (399 < iVar6) {
    iVar3 = 400;
  }
  if (iVar3 < 100) {
    iVar3 = 100;
  }
  if (iVar6 < 0x65) {
    uVar8 = 1;
  }
  else {
    uVar8 = 0;
  }
  while (uVar5 < uVar8) {
    iVar4 = iVar4 << 1;
    uVar5 = 1;
  }
  iVar6 = *piVar1;
  iVar3 = FUN_000482b0(0x960,iVar4 * iVar3,uVar5,iVar4,unaff_r4,unaff_r5,unaff_r6,unaff_lr);
  *(uint *)(iVar6 + 0x14) = uVar8 | (iVar3 + -1) * 8;
  *(uint *)(iVar6 + 0xc) = *(uint *)(iVar6 + 0xc) | 0x40;
  *(undefined4 *)(iVar6 + 0x1c) = 0;
  return;
}

