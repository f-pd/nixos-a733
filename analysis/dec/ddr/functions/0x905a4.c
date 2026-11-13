// rea decompile_all
// name: FUN_000905a4
// address: 0x905a4
// body: available
// range: 0x90414-0x9041d inclusive
// range: 0x905a4-0x90609 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Ghidra Listing reports a terminal call at 0x9041a to 0x92c40 FUN_00092c40 (external=false, thunk=false, hasNoReturn=false); fallthrough is excluded by Ghidra's flow model. The reason for the terminal flow is not established by this observation.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000905a4(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_00090690(DAT_0009060c);
  if (param_1[3] != 0) {
    return;
  }
  iVar2 = *param_1;
  if (iVar2 == 0) {
    FUN_00092a80(3,DAT_00090610);
  }
  else {
    *(undefined4 *)(iVar2 + 0x4f4) = *(undefined4 *)(DAT_00090614 + 0x24);
    *(undefined4 *)(iVar2 + 0x4f8) = *DAT_00090618;
    if (param_1[1] != 0) {
      *(undefined1 *)(iVar2 + 0x4e9) = 1;
    }
    if (param_1[2] != 0) {
      *(undefined1 *)(iVar2 + 0x4e8) = 1;
    }
    uVar1 = FUN_00090570();
    *(undefined4 *)(iVar2 + 0xe4) = uVar1;
    *(undefined4 *)(iVar2 + 0xb8) = 0;
  }
  FUN_000903e8();
  FUN_00092c40(*param_1 + 0x1ff000,DAT_00090420,0x800,param_4);
  return;
}

