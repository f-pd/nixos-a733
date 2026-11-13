// rea decompile_all
// name: FUN_00047b80
// address: 0x47b80
// body: available
// range: 0x47b80-0x47c1b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00047b80(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 in_cr0;
  undefined4 in_cr7;
  undefined4 in_cr14;
  
  DataMemoryBarrier(0xf);
  uVar2 = coprocessor_movefromRt(0xf,1,1,in_cr0,in_cr0);
  uVar4 = uVar2 >> 0x17 & 0xe;
  if (uVar4 != 0) {
    uVar8 = 0;
    do {
      if (1 < (uVar2 >> (uVar8 + (uVar8 >> 1) & 0xff) & 7)) {
        coprocessor_moveto(0xf,2,0,uVar8,in_cr0,in_cr0);
        InstructionSynchronizationBarrier(0xf);
        uVar3 = coprocessor_movefromRt(0xf,1,0,in_cr0,in_cr0);
        uVar5 = uVar3 >> 3 & 0x3ff;
        uVar6 = uVar5;
        do {
          uVar7 = uVar3 >> 0xd & 0x7fff;
          do {
            coprocessor_moveto(0xf,0,2,uVar8 | uVar6 << LZCOUNT(uVar5) | uVar7 << (uVar3 & 7) + 4,
                               in_cr7,in_cr14);
            bVar1 = 0 < (int)uVar7;
            uVar7 = uVar7 - 1;
          } while (bVar1);
          bVar1 = 0 < (int)uVar6;
          uVar6 = uVar6 - 1;
        } while (bVar1);
      }
      uVar8 = uVar8 + 2;
    } while ((int)uVar8 < (int)uVar4);
  }
  coprocessor_moveto(0xf,2,0,0,in_cr0,in_cr0);
  DataSynchronizationBarrier(0xe);
  InstructionSynchronizationBarrier(0xf);
  return;
}

