// rea decompile_all
// name: FUN_000570d4
// address: 0x570d4
// body: available
// range: 0x570d4-0x57213 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000570d4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = param_2 * 0x400000;
  uVar3 = FUN_0005708c();
  iVar1 = DAT_00057214;
  iVar4 = FUN_00057070(uVar3,param_2);
  if (*(int *)(iVar4 + 4) == 9) {
    uVar6 = *(uint *)(iVar7 + DAT_00057218) & 0xfffffeff | 1;
  }
  else {
    uVar6 = 0;
  }
  *(uint *)(iVar7 + DAT_00057218) = uVar6;
  iVar2 = DAT_0005721c;
  *(uint *)(iVar7 + DAT_0005721c) = *(uint *)(iVar7 + DAT_0005721c) & 0xffffffc0;
  *(uint *)(iVar7 + iVar2 + -0xc) = *(uint *)(iVar7 + iVar2 + -0xc) & 0xffffff00 | 0x800;
  *(uint *)(iVar7 + iVar2 + 0x37c) = *(uint *)(iVar7 + iVar2 + 0x37c) & 0xffff7fff | 0xc0000000;
  uVar6 = *(uint *)(iVar7 + iVar2 + 0xf4);
  if (*(int *)(iVar4 + 4) == 9) {
    uVar6 = uVar6 & 0xdfffffff;
  }
  else {
    uVar6 = uVar6 | 0x20000000;
  }
  *(uint *)(iVar7 + iVar2 + 0xf4) = uVar6 | 0x80000000;
  iVar2 = DAT_00057220;
  *(uint *)(iVar7 + DAT_00057220) = *(uint *)(iVar7 + DAT_00057220) | 1;
  uVar6 = *(uint *)(iVar7 + iVar2 + 0x78) & 0xff00ff00;
  if (*(int *)(iVar4 + 4) == 9) {
    uVar6 = uVar6 | 0xc000c0;
  }
  else {
    uVar6 = uVar6 | 0xc0;
  }
  *(uint *)(iVar7 + iVar2 + 0x78) = uVar6;
  *(uint *)(iVar7 + DAT_00057224) = *(uint *)(iVar7 + DAT_00057224) | 1;
  iVar2 = DAT_0005722c;
  *(undefined4 *)(iVar7 + DAT_00057228) = 0;
  *(uint *)(iVar7 + iVar2) = *(uint *)(iVar7 + iVar2) & 0xfffffe | 0x25000000;
  *(uint *)(iVar7 + iVar2 + -0x310) = *(uint *)(iVar7 + iVar2 + -0x310) | 1;
  *(uint *)(iVar7 + iVar1) = *(uint *)(iVar7 + iVar1) & 0xfffcffff | 0x10015;
  uVar3 = FUN_00056dd8(iVar4,param_2);
  FUN_000562dc(uVar3,param_2);
  iVar2 = DAT_00057234;
  iVar4 = DAT_00057230;
  if (*(int *)(param_1 + 4) == 9) {
    *(uint *)(iVar7 + DAT_00057230) = *(uint *)(iVar7 + DAT_00057230) & 0xfffffffe;
    *(undefined4 *)(iVar7 + iVar2) = 0;
    piVar5 = (int *)(iVar4 + 0x100 + iVar7);
    *(uint *)(iVar7 + iVar1) = *(uint *)(iVar7 + iVar1) & 0xfffcffee | 0x10004;
    *(undefined4 *)(iVar7 + iVar2) = 1;
    do {
    } while (-1 < *piVar5 << 0x1f);
    *(undefined4 *)(iVar7 + iVar2) = 0;
    *(uint *)(iVar7 + iVar1) = *(uint *)(iVar7 + iVar1) & 0xfffcfffe | 0x10014;
    *(undefined4 *)(iVar7 + iVar2) = 1;
    do {
    } while (-1 < *piVar5 << 0x1f);
  }
  return;
}

