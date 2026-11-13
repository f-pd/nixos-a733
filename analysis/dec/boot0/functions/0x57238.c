// rea decompile_all
// name: FUN_00057238
// address: 0x57238
// body: available
// range: 0x57238-0x572ef inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00057238(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = DAT_000572fc;
  if (*(int *)(param_1 + 4) == 8) {
    iVar1 = param_2 * 0x400000;
    *(uint *)(iVar1 + DAT_000572f0) = DAT_000572f8 | DAT_000572f4 & *(uint *)(iVar1 + DAT_000572f0);
    *(uint *)(iVar1 + iVar2) = DAT_00057300 & *(uint *)(iVar1 + iVar2) | 0x2000;
    *(uint *)(iVar1 + iVar2 + 8) = *(uint *)(iVar1 + iVar2 + 8) & 0xc0c0c0c0 | 0x4040c3e;
    *(undefined4 *)(iVar1 + DAT_00057304) = DAT_00057308;
    uVar3 = *(uint *)(iVar1 + 0xa100c88) & 0xff0000 | 0x1e000046;
    *(uint *)(iVar1 + 0xa100c88) = uVar3;
    *(uint *)(iVar1 + 0xa200c88) = uVar3;
    *(uint *)(iVar1 + 0xa300c88) = uVar3;
    *(uint *)(iVar1 + 0xa400c88) = uVar3;
    *(undefined4 *)(iVar1 + 0xa100c00) = 0xff;
    *(undefined4 *)(iVar1 + 0xa200c00) = 0xff;
    *(undefined4 *)(iVar1 + 0xa300c00) = 0xff;
  }
  else {
    if (*(int *)(param_1 + 4) != 9) {
      return;
    }
    iVar2 = param_2 * 0x400000;
    *(undefined4 *)(iVar2 + DAT_000572f0) = DAT_0005730c;
    *(undefined4 *)(iVar2 + 0xa100c00) = 0xff;
    *(undefined4 *)(iVar2 + 0xa200c00) = 0xff;
    *(undefined4 *)(iVar2 + 0xa300c00) = 0xff;
  }
  *(undefined4 *)(param_2 * 0x400000 + 0xa400c00) = 0xff;
  return;
}

