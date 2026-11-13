// rea decompile_all
// name: FUN_00091ed0
// address: 0x91ed0
// body: available
// range: 0x91ed0-0x91f7b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00091ed0(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 in_cr0;
  undefined4 in_cr1;
  undefined4 in_cr2;
  undefined4 in_cr3;
  undefined4 in_cr5;
  undefined4 in_cr6;
  undefined4 in_cr7;
  undefined4 in_cr8;
  
  FUN_00090690(DAT_00091f7c);
  if (0x7ff < param_1) {
    param_1 = 0x800;
  }
  iVar3 = (param_1 - 1) * 0x100000;
  puVar2 = (uint *)(iVar3 + 0x40000000);
  for (puVar1 = puVar2; puVar1 != (uint *)(iVar3 + 0x40004000); puVar1 = puVar1 + 1) {
    *puVar1 = (int)puVar1 * 0x40000 | 0xde2;
  }
  *puVar2 = 0xdea;
  puVar1 = (uint *)(iVar3 + 0x40001000);
  for (uVar4 = 0x400; uVar4 < param_1 + 0x400; uVar4 = uVar4 + 1) {
    *puVar1 = uVar4 << 0x14 | 0xdea;
    puVar1 = puVar1 + 1;
  }
  coprocessor_moveto(0xf,0,0,0,in_cr8,in_cr7);
  coprocessor_moveto(0xf,0,0,0,in_cr8,in_cr6);
  coprocessor_moveto(0xf,0,0,0,in_cr8,in_cr5);
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  coprocessor_moveto(0xf,0,0,(uint)puVar2 | 0x13,in_cr2,in_cr0);
  coprocessor_moveto(0xf,0,1,0,in_cr2,in_cr0);
  coprocessor_moveto(0xf,0,0,0x55555555,in_cr3,in_cr0);
  InstructionSynchronizationBarrier(0xf);
  uVar4 = coprocessor_movefromRt(0xf,0,0,in_cr1,in_cr0);
  FUN_00091a8c(100,0,(uint)puVar2 | 0x13,0x55555555);
  coprocessor_moveto(0xf,0,0,uVar4 & 0xfffffffb | 0x1001,in_cr1,in_cr0);
  InstructionSynchronizationBarrier(0xf);
  return 0;
}

