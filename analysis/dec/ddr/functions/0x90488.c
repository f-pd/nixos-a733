// rea decompile_all
// name: FUN_00090488
// address: 0x90488
// body: available
// range: 0x90488-0x9053f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00090488(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  *DAT_00090540 = DAT_00090544;
  iVar3 = FUN_00092574();
  if (iVar3 == 0) {
    FUN_00092a5c(DAT_00090548);
    FUN_00092a80(3,DAT_00090554,DAT_00090550,DAT_00090558,DAT_0009054c,param_2);
    iVar3 = thunk_FUN_00092044();
    if ((iVar3 == 0) && (iVar3 = FUN_00090164(), puVar1 = DAT_0009055c, iVar3 == 0)) {
      FUN_00090484();
      iVar3 = FUN_00090750(puVar1);
      if (iVar3 == 0) {
        FUN_00092a80(3,DAT_00090560,*puVar1);
        iVar3 = FUN_00090650();
        if (iVar3 != 0) {
          FUN_00090668();
          return *puVar1;
        }
        uVar4 = FUN_00091ebc(thunk_FUN_00090004);
        uVar2 = DAT_00090560;
        *puVar1 = uVar4;
        FUN_00092a80(3,uVar2,uVar4);
        FUN_00092cf4(0x40800000,0x1000000);
        iVar3 = FUN_00091ed0(*puVar1);
        if (iVar3 == 0) {
          FUN_00090692();
          FUN_000905a4(DAT_00090564);
          FUN_000925ec();
          FUN_00090694();
          FUN_00091f80();
          FUN_00092600();
          FUN_00092a80(3,DAT_00090568);
        }
      }
    }
  }
  FUN_00092a80(3,DAT_0009056c);
  FUN_0009018c();
  return 0;
}

