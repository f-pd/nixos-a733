// rea decompile_all
// name: FUN_0005d6e4
// address: 0x5d6e4
// body: available
// range: 0x5d6e4-0x5d6f5 inclusive
// range: 0x5d8f4-0x5d92b inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0005d6e4(undefined4 param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  if (*DAT_0005d6f8 != 0xe) {
    return 0xffffffff;
  }
  uStack_c = param_2;
  uStack_8 = param_3;
  iVar1 = FUN_0004af2a(0x36,0x50,(int)&uStack_c + 3,0xe,param_1);
  if (iVar1 == 0) {
    if ((int)((uStack_c >> 0x18) << 0x1f) < 0) {
      uVar2 = 2;
    }
    else {
      uVar2 = 0;
      if (-1 < (int)((uStack_c >> 0x18) << 0x1e)) {
        if ((uStack_c & 0x4000000) == 0) {
          uVar2 = 0xffffffff;
        }
        else {
          uVar2 = 1;
        }
      }
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

