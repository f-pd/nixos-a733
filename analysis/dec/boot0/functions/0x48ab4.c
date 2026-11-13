// rea decompile_all
// name: FUN_00048ab4
// address: 0x48ab4
// body: available
// range: 0x48a74-0x48b2b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


ulonglong FUN_00048ab4(uint param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint unaff_r4;
  uint uVar4;
  uint uVar5;
  uint in_r12;
  bool bVar6;
  
  uVar4 = in_r12 & param_4 >> 0x14;
  if (unaff_r4 == in_r12 || uVar4 == in_r12) {
    bVar1 = (param_2 & 0x7fffffff) == 0;
    bVar6 = param_1 == 0 && bVar1;
    uVar5 = param_4;
    uVar2 = param_3;
    if (param_1 != 0 || !bVar1) {
      bVar6 = param_3 == 0 && (param_4 & 0x7fffffff) == 0;
      uVar5 = param_2;
      uVar2 = param_1;
    }
    uVar3 = uVar5;
    if (((bVar6) || ((unaff_r4 == in_r12 && (uVar2 != 0 || (uVar5 & 0xfffff) != 0)))) ||
       ((uVar4 == in_r12 &&
        (uVar2 = param_3, uVar3 = param_4, param_3 != 0 || (param_4 & 0xfffff) != 0)))) {
      return CONCAT44(uVar3,uVar2) | 0x7ff8000000000000;
    }
    return (ulonglong)((uVar5 ^ param_4) & 0x80000000 | 0x7ff00000) << 0x20;
  }
  bVar1 = (param_2 & 0x7fffffff) == 0;
  bVar6 = param_1 == 0 && bVar1;
  if (param_1 != 0 || !bVar1) {
    bVar6 = param_3 == 0 && (param_4 & 0x7fffffff) == 0;
  }
  if (bVar6) {
    return (ulonglong)((param_2 ^ param_4) & 0x80000000) << 0x20;
  }
  if (unaff_r4 == 0) {
    uVar5 = param_2 & 0x80000000;
    do {
      uVar2 = param_1 & 0x80000000;
      param_1 = param_1 << 1;
      param_2 = param_2 * 2 + (uint)(uVar2 != 0);
    } while ((param_2 & 0x100000) == 0);
    param_2 = param_2 | uVar5;
    if (uVar4 != 0) {
      return CONCAT44(param_2,param_1);
    }
  }
  do {
    uVar4 = param_3 & 0x80000000;
    param_3 = param_3 << 1;
    param_4 = param_4 * 2 + (uint)(uVar4 != 0);
  } while ((param_4 & 0x100000) == 0);
  return CONCAT44(param_2,param_1);
}

