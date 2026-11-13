// rea decompile_all
// name: FUN_0004b1bc
// address: 0x4b1bc
// body: available
// range: 0x4b1bc-0x4b227 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_0004b1bc(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  int local_2c [3];
  
  iVar1 = DAT_0004b22c;
  local_2c[0] = param_2;
  local_2c[1] = param_3;
  local_2c[2] = param_4;
  iVar2 = FUN_00048d58();
  while( true ) {
    iVar4 = 0;
    iVar6 = 0;
    do {
      iVar3 = FUN_0004b174(param_1);
      uVar7 = FUN_000482b0(iVar3 * 0x708,0xfff);
      iVar3 = (int)uVar7;
      local_2c[iVar6] = iVar3;
      iVar6 = iVar6 + 1;
      iVar4 = iVar4 + iVar3;
    } while (iVar6 != 3);
    iVar5 = (int)((ulonglong)((longlong)iVar4 * (longlong)iVar1) >> 0x20) - (iVar4 >> 0x1f);
    iVar6 = iVar5 - local_2c[0];
    if (iVar6 < 0) {
      iVar6 = -iVar6;
    }
    if (iVar6 < 5) break;
    iVar4 = FUN_00048d58(iVar3,(int)((ulonglong)uVar7 >> 0x20),
                         (int)((longlong)iVar4 * (longlong)iVar1));
    if (1999 < (uint)(iVar4 - iVar2)) {
      FUN_0004993c(DAT_0004b228);
      return iVar5;
    }
  }
  return iVar5;
}

