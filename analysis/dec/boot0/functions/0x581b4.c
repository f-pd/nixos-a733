// rea decompile_all
// name: FUN_000581b4
// address: 0x581b4
// body: available
// range: 0x581b4-0x58557 inclusive
// range: 0x5859c-0x5895d inclusive
// range: 0x5899c-0x58b7b inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000581b4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  puVar2 = DAT_00058598;
  iVar4 = *(int *)(param_1 + 4);
  *DAT_00058598 = 0;
  puVar2[1] = 0;
  FUN_00057eb8(1,1,DAT_00058558,0,0xffffff00,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_0005855c,0,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_00058560,1,0xfffffff8,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_00058560,1,0xfffffff8,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_00058560,1,0xfffffff8,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058564,2,0xfffffffd,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_00058568,0x36000000,0xc9ffffff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_0005856c,4,0xfffffffb,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058570,0x20000,0xfffdffff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_00058574,0,0xfffdffff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058578,0,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_0005857c,0x80000000,0x7fffffff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058580,0,0xffffffef,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_00058584,0,0xfffffffd,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058580,0,0xffefffff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_00058584,0,0xfffffffb,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058558,0,0xfffffdff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058558,0x8800,0xffff77ff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_00058560,0x1000,0xffff8fff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058564,1,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_00058568,0x30000000,0xcfffffff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058588,0,0xfffffffe,param_3,param_4,0,0,0);
  uVar5 = DAT_0005858c;
  puVar2[4] = puVar2[1];
  FUN_00057eb8(1,1,uVar5,0,0xffffe0ff,param_3,param_4,0,1,0);
  FUN_00057eb8(1,1,DAT_00058588,1,0xfffffffe,param_3,param_4,0,0,0);
  if (iVar4 == 8) {
    FUN_00058094(0xd,param_3,param_4,200,200,200,200);
    FUN_00057eb8(1,1,DAT_00058558,0,0xffff7fff,param_3,param_4,0,0,0);
    FUN_00057eb8(1,0,DAT_00058560,0x2000,0xffff8fff,param_3,param_4,0,0,0);
  }
  else if (iVar4 == 9) {
    uVar5 = *DAT_00058ba4;
    FUN_00058094(0x10,param_3,param_4,uVar5,uVar5,uVar5,uVar5);
  }
  FUN_00057eb8(1,1,DAT_00058588,0,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_0005858c,0,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058588,1,0xfffffffe,param_3,param_4,0,0,0);
  piVar1 = DAT_00058590;
  FUN_00057eb8(1,1,DAT_00058594,0,0xffff7fff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058588,0,0xfffffffe,param_3,param_4,0,0,0);
  iVar3 = *piVar1;
  puVar2[5] = *puVar2;
  FUN_00058048(iVar3 << 0xe,0);
  FUN_00058048(*piVar1 << 0xe,1);
  FUN_00058048(*piVar1 << 0xe,2);
  FUN_00057ea4(*piVar1 << 0xe);
  FUN_00057fcc(1,1,DAT_00058960,0xffff3fff,param_3,param_4,0);
  FUN_00058048(0,0);
  FUN_00058048(1);
  FUN_00058048(2);
  FUN_00057ea4(3);
  FUN_00057fcc(1,1,DAT_00058964,0xffffffe0,param_3,param_4,0);
  FUN_00057eb8(1,1,DAT_00058960,0x20,0xffffffdf,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058968,1,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_0005896c,0,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00058048((*(uint *)(param_1 + 0x60) & 0x1f) << 0x13 | 0x501,0);
  FUN_00058048((*(uint *)(param_1 + 0x60) & 0x1f00) << 0xb | 0xd09,1);
  FUN_00058048((*(ushort *)(param_1 + 0x62) & 0x1f) << 0x13 | 0x1511,2);
  FUN_00057ea4((*(byte *)(param_1 + 99) & 0x1f) << 0x13 | 0x1d19);
  FUN_00057f44(0,0,1,1,200,0);
  FUN_00057eb8(1,1,DAT_00058970,0x10,0xffffffef,1,200,0,0,0);
  FUN_00057eb8(1,1,DAT_00058968,0,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058960,0,0xffffffdf,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058968,1,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058974,0,0xffff7fff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_0005896c,1,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058968,0,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058960,1,0xfffffffe,1,200,0,0,0);
  FUN_00057eb8(1,1,DAT_00058978,1,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058968,1,0xfffffffe,param_3,param_4,0,0,0);
  if (iVar4 == 8) {
    FUN_00057eb8(1,1,DAT_0005897c,0x8000,0xffff77ff,param_3,param_4,0,0,0);
    FUN_00057eb8(1,0,DAT_00058980,0x3000,0xffff8fff,param_3,param_4,0,0,0);
  }
  FUN_00057eb8(1,1,DAT_00058984,0x10000,0xfffeffff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_00058988,0,0xfffeffff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058968,0,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058978,0,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058968,1,0xfffffffe,param_3,param_4,0,0,0);
  if (iVar4 == 9) {
    FUN_00057eb8(1,0,DAT_0005898c,0,0xfffffffe,param_3,param_4,0,0,0);
    uVar5 = DAT_00058998;
    FUN_00057eb8(1,1,DAT_00058990,0x30,0,param_3,param_4,0,0,0);
    FUN_00057eb8(1,1,DAT_00058994,0,uVar5,param_3,param_4,0,0,0);
    FUN_00057eb8(1,1,DAT_00058990,0x80000000,0x7fffffff,param_3,param_4,0,0,0);
    FUN_00057eb8(1,0,DAT_00058990,0,0x7fffffff,param_3,param_4,0,0,0);
    FUN_00057eb8(1,0,DAT_0005898c,0,0xfffffffe,param_3,param_4,0,0,0);
    FUN_00057eb8(1,1,DAT_00058990,0x30,0,param_3,param_4,0,0,0);
    FUN_00057eb8(1,1,DAT_00058994,0xb12,uVar5,param_3,param_4,0,0,0);
    FUN_00057eb8(1,1,DAT_00058b7c,0x80000000,0x7fffffff,param_3,param_4,0,0,0);
    FUN_00057eb8(1,0,DAT_00058b7c,0,0x7fffffff,param_3,param_4,0,0,0);
    FUN_00057eb8(1,0,DAT_00058b80,0,0xfffffffe,param_3,param_4,0,0,0);
    FUN_00057eb8(1,1,DAT_00058b7c,0x30,0,param_3,param_4,0,0,0);
    FUN_00057eb8(1,1,DAT_00058b84,0,uVar5,param_3,param_4,0,0,0);
    FUN_00057eb8(1,1,DAT_00058b7c,0x80000000,0x7fffffff,param_3,param_4,0,0,0);
    FUN_00057eb8(1,0,DAT_00058b7c,0,0x7fffffff,param_3,param_4,0,0,0);
    FUN_00057eb8(1,1,DAT_00058b88,0,0xfffff7ff,param_3,param_4,0,0,0);
  }
  FUN_00057eb8(1,1,DAT_00058b88,0,0xffff7fff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_00058b8c,0,0xffff8fff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058b90,0,0xffefffef,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058b94,0,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058b94,0,0xfffffffd,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058b98,0,0xfffffffb,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058b9c,0,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058ba0,0x80000000,0x7fffffff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058b88,0,0xfffffdff,param_3,param_4,1,0,0);
  return;
}

