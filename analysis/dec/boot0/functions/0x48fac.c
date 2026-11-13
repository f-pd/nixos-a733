// rea decompile_all
// name: FUN_00048fac
// address: 0x48fac
// body: available
// range: 0x48fac-0x4902b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00048fac(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_0005d9f0();
  uVar3 = DAT_00049034;
  if (iVar2 == 1) {
    DataMemoryBarrier(0x1f);
    *DAT_0004902c = DAT_00049030;
    FUN_0004993c(uVar3);
  }
  FUN_0005d744(0);
  iVar2 = FUN_0005d9f0();
  if (iVar2 == 0) {
    DataMemoryBarrier(0x1f);
    uVar3 = DAT_0004903c;
  }
  else {
    iVar2 = FUN_0005d9f0();
    if (iVar2 != 1) goto LAB_00048fe2;
    DataMemoryBarrier(0x1f);
    uVar3 = DAT_00049048;
  }
  puVar1 = DAT_00049038;
  *DAT_00049038 = uVar3;
  DataMemoryBarrier(0x1f);
  *puVar1 = uVar3;
LAB_00048fe2:
  if ((*(byte *)(DAT_00049040 + 0x28) & 0xf) == 2) {
    FUN_0004993c(DAT_00049044);
    uVar3 = 0x348;
  }
  else {
    uVar3 = 800;
  }
  FUN_0005d714(uVar3);
  FUN_000491b8();
  FUN_0005d744(0);
  FUN_0004b2e8();
  FUN_00048f10();
  return 0;
}

