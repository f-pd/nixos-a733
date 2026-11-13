// rea decompile_all
// name: FUN_0005d940
// address: 0x5d940
// body: available
// range: 0x5d940-0x5d9c5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0005d940(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  char cVar4;
  undefined4 uStack_c;
  
  uStack_c = param_2;
  iVar1 = FUN_0004af20(DAT_0005d9c8,0x36,param_3,param_4,param_1);
  if (iVar1 == 0) {
    iVar1 = FUN_0004af2a(0x36,0xe,(int)&uStack_c + 2);
    if (iVar1 == 0) {
      if (uStack_c._2_1_ == '\x03') {
        FUN_0004af2a(0x36,0x10,(int)&uStack_c + 3);
        uStack_c = uStack_c | 0x8000000;
        FUN_0004af3e(0x36,0x10);
        cVar3 = '\x13';
        do {
          FUN_0004af2a(0x36,cVar3,(int)&uStack_c + 3);
          cVar4 = cVar3 + '\x01';
          uStack_c = uStack_c | 0x80000000;
          FUN_0004af3e(0x36,cVar3);
          cVar3 = cVar4;
        } while (cVar4 != '\x1b');
        return 0xe;
      }
      uVar2 = DAT_0005d9d4;
    }
    else {
      uVar2 = DAT_0005d9d0;
    }
  }
  else {
    uVar2 = DAT_0005d9cc;
  }
  FUN_0004993c(uVar2);
  return 0xffffffff;
}

