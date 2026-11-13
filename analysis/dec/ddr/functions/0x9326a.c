// rea decompile_all
// name: FUN_0009326a
// address: 0x9326a
// body: available
// range: 0x9326a-0x932df inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_0009326a(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int *param_5,
                int *param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = FUN_0009323a();
  do {
    if (iVar1 < 0) {
LAB_00093282:
      if (param_5 != (int *)0x0) {
        *param_5 = iVar1;
      }
      return 0;
    }
    iVar2 = FUN_00093110(param_1,iVar1,param_5);
    if (iVar2 == 0) {
      iVar1 = -0xd;
      goto LAB_00093282;
    }
    uVar3 = FUN_000930da(*(undefined4 *)(iVar2 + 8));
    uVar3 = FUN_00093146(param_1,uVar3);
    iVar4 = FUN_00092bc6();
    if ((iVar4 == param_4) && (iVar4 = FUN_00092c50(uVar3,param_3,param_4), iVar4 == 0)) {
      if (param_6 == (int *)0x0) {
        return iVar2;
      }
      *param_6 = iVar1;
      return iVar2;
    }
    iVar1 = FUN_00093252(param_1,iVar1);
  } while( true );
}

