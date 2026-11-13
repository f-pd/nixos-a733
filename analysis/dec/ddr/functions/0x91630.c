// rea decompile_all
// name: FUN_00091630
// address: 0x91630
// body: available
// range: 0x91630-0x916c5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00091630(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  
  puVar1 = DAT_000916c8;
  iVar3 = FUN_00093460(*DAT_000916c8,DAT_000916cc,param_3,param_4,param_4);
  uVar2 = DAT_000916d0;
  if (-1 < iVar3) {
    for (iVar3 = FUN_0009323a(*puVar1); 0 < iVar3; iVar3 = FUN_00093252(*puVar1,iVar3)) {
      iVar4 = FUN_000932e0(*puVar1,iVar3,0);
      if (iVar4 != 0) {
        uVar6 = *(uint *)(iVar4 + 8);
        uVar5 = FUN_00093146(*puVar1,uVar6 >> 0x18 | uVar6 << 0x18 | ((uVar6 & 0xffff) >> 8) << 0x10
                                     | ((uVar6 & 0xffffff) >> 0x10) << 8);
        uVar6 = *(uint *)(iVar4 + 0xc);
        uVar6 = uVar6 >> 0x18 | uVar6 << 0x18 | ((uVar6 & 0xffff) >> 8) << 0x10 |
                ((uVar6 & 0xffffff) >> 0x10) << 8;
        if (uVar6 != 0) {
          FUN_00092a80(3,uVar2,uVar5,uVar6);
          FUN_000914a8(0,param_1,uVar5,uVar6);
        }
      }
    }
  }
  return 0;
}

