// rea decompile_all
// name: FUN_00048dfc
// address: 0x48dfc
// body: available
// range: 0x48dfc-0x48e8b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00048dfc(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 in_cr0;
  undefined4 in_cr1;
  undefined4 in_cr2;
  undefined4 in_cr3;
  undefined4 in_cr7;
  undefined4 in_cr8;
  
  if (0x7ff < param_1) {
    param_1 = 0x800;
  }
  iVar1 = param_1 * 0x100000;
  *(undefined4 *)(iVar1 + 0x3ff00000) = 0xdee;
  uVar5 = 0x100000;
  puVar3 = (uint *)(iVar1 + 0x3ff00004);
  do {
    uVar2 = uVar5 | 0xde2;
    uVar5 = uVar5 + 0x100000;
    *puVar3 = uVar2;
    puVar3 = puVar3 + 1;
  } while (uVar5 != 0x40000000);
  uVar5 = 0x40000000;
  puVar3 = (uint *)(iVar1 + 0x3ff01000);
  do {
    uVar2 = uVar5 | 0xdee;
    uVar5 = uVar5 + 0x100000;
    puVar4 = puVar3 + 1;
    *puVar3 = uVar2;
    puVar3 = puVar4;
  } while (uVar5 != 0);
  coprocessor_moveto(0xf,0,0,0,in_cr8,in_cr7);
  uVar5 = (uint)(iVar1 + 0x3ff00000) | 0x13;
  coprocessor_moveto(0xf,0,0,uVar5,in_cr2,in_cr0);
  coprocessor_moveto(0xf,0,1,uVar5,in_cr2,in_cr0);
  coprocessor_moveto(0xf,0,0,0x55555555,in_cr3,in_cr0);
  InstructionSynchronizationBarrier(0xf);
  FUN_00048dae(uVar5,uVar2,puVar4,0x55555555);
  uVar5 = coprocessor_movefromRt(0xf,0,0,in_cr1,in_cr0);
  FUN_00048d80(100);
  coprocessor_moveto(0xf,0,0,uVar5 & 0xfffffffb | 0x1001,in_cr1,in_cr0);
  InstructionSynchronizationBarrier(0xf);
  return;
}

