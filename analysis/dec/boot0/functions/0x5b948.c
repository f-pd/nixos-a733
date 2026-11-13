// rea decompile_all
// name: FUN_0005b948
// address: 0x5b948
// body: available
// range: 0x5b948-0x5b9bb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_0005b948(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  undefined4 local_38;
  undefined4 uStack_34;
  int local_30;
  uint local_2c;
  undefined4 local_1c;
  
  uVar1 = DAT_0005b9bc;
  local_38 = 0xd;
  uStack_34 = 0x15;
  local_30 = *(int *)(param_1 + 0x80) << 0x10;
  local_1c = 0;
  do {
    iVar2 = FUN_0005b324(param_1,&local_38,0);
    if (iVar2 != 0) {
      FUN_000498e4(DAT_0005b9c0,*(undefined4 *)(param_1 + 0x30));
      return iVar2;
    }
    if ((int)(local_2c << 0x17) < 0) {
      if (param_2 == 0) {
        FUN_000498e4(DAT_0005b9c8,*(undefined4 *)(param_1 + 0x30));
        return -0x13;
      }
      return 0;
    }
    FUN_00048da4(1);
    if ((local_2c & uVar1) != 0) {
      FUN_000498e4(DAT_0005b9c4,*(undefined4 *)(param_1 + 0x30));
      return -0x12;
    }
    bVar3 = param_2 != 0;
    param_2 = param_2 + -1;
  } while (bVar3);
  return 0;
}

