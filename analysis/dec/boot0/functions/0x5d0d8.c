// rea decompile_all
// name: FUN_0005d0d8
// address: 0x5d0d8
// body: available
// range: 0x5d0d8-0x5d175 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0005d0d8(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  iVar2 = FUN_00048d6c();
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *(uint *)(*param_1 + 4) = *(uint *)(*param_1 + 4) | 0x80000000;
  DataMemoryBarrier(0x1f);
  *(undefined4 *)(*param_1 + 0x18) = DAT_0005d178;
  do {
    DataMemoryBarrier(0x1f);
    if (-1 < *(int *)(*param_1 + 0x18)) break;
    uVar3 = FUN_00048d6c();
  } while (uVar3 < iVar2 + 0xfffffU);
  DataMemoryBarrier(0x1f);
  if (*(int *)(*param_1 + 0x18) < 0) {
    FUN_000498e4(DAT_0005d17c,param_1[1]);
    puVar1 = DAT_0005d180;
    DataMemoryBarrier(0x1f);
    *DAT_0005d180 = 0;
    DataMemoryBarrier(0x1f);
    DataMemoryBarrier(0x1f);
    FUN_000498e4(DAT_0005d184,*puVar1,puVar1[3],puVar1,param_4);
    uVar4 = 0xffffffff;
  }
  else {
    DataMemoryBarrier(0x1f);
    DataMemoryBarrier(0x1f);
    iVar2 = *param_1;
    *(uint *)(iVar2 + 4) = *(uint *)(*param_1 + 4) & 0x7fffffff;
    DataMemoryBarrier(0x1f);
    DataMemoryBarrier(0x1f);
    uVar4 = 0;
    *(undefined4 *)(*param_1 + 0x38) = *(undefined4 *)(iVar2 + 0x38);
  }
  return uVar4;
}

