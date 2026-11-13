// rea decompile_all
// name: FUN_0004a454
// address: 0x4a454
// body: available
// range: 0x4a3cc-0x4a46d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_0004a454(undefined4 param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined4 unaff_r4;
  char *pcVar4;
  undefined4 unaff_r5;
  char *pcVar5;
  
  iVar3 = FUN_000495f0(param_2);
  iVar1 = FUN_00049dcc();
  if (iVar1 == 0) {
    pcVar5 = param_2 + iVar3;
    pcVar2 = param_2;
    if (*param_2 != '/') {
      pcVar2 = (char *)FUN_00049656(param_2,0x2f,iVar3,*param_2,unaff_r4,unaff_r5);
      if (pcVar2 == (char *)0x0) {
        pcVar2 = pcVar5;
      }
      else {
      }
      iVar1 = FUN_0004a3a0(param_1,param_2,(int)pcVar2 - (int)param_2);
      if (iVar1 == 0) {
        return -5;
      }
      iVar1 = FUN_0004a454(param_1,iVar1);
    }
    while (pcVar2 < pcVar5) {
      pcVar4 = pcVar2;
      while( true ) {
        pcVar2 = pcVar4 + 1;
        if (*pcVar4 != '/') break;
        pcVar4 = pcVar2;
        if (pcVar2 == pcVar5) {
          return iVar1;
        }
      }
      pcVar2 = (char *)FUN_00049656(pcVar4,0x2f,(int)pcVar5 - (int)pcVar4,*pcVar4,unaff_r4,unaff_r5)
      ;
      if (pcVar2 == (char *)0x0) {
        pcVar2 = pcVar5;
      }
      else {
      }
      iVar1 = FUN_0004a1c6(param_1,iVar1,pcVar4,(int)pcVar2 - (int)pcVar4);
      if (iVar1 < 0) {
        return iVar1;
      }
    }
  }
  return iVar1;
}

