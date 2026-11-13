// rea decompile_all
// name: FUN_0005d404
// address: 0x5d404
// body: available
// range: 0x5d404-0x5d505 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Removing unreachable block (ram,0x0005d438) */
/* WARNING: Removing unreachable block (ram,0x0005d468) */

undefined4 FUN_0005d404(int param_1,undefined4 param_2,undefined4 param_3)

{
  ulonglong uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined1 local_1a;
  undefined1 local_19;
  
  iVar6 = DAT_0005d508;
  uVar7 = (uint)*(byte *)(DAT_0005d508 + 0x65);
  FUN_0005d1f0(param_1,1,2,&local_19,&local_1a,param_2,param_3);
  *(undefined4 *)(param_1 * 0x108 + DAT_0005d50c + 0xd8) = DAT_0005d510;
  uVar3 = FUN_0005d1f0(param_1,2,2,&local_19,&local_1a,param_2,param_3);
  uVar1 = (ulonglong)uVar3;
  *(undefined4 *)(param_1 * 0x108 + DAT_0005d50c + 0xdc) = DAT_0005d510;
  uVar3 = DAT_0005d514;
  iVar5 = DAT_0005d50c;
  if (uVar7 != 0) {
    iVar8 = param_1 * 0x108 + DAT_0005d50c;
    if (uVar7 < (uint)((ulonglong)*(uint *)(iVar8 + 0xdc) * (ulonglong)DAT_0005d514 >> 0x32)) {
      *(uint *)(iVar8 + 0xdc) = uVar7 * DAT_0005d518;
    }
    iVar5 = param_1 * 0x108 + iVar5;
    uVar1 = (ulonglong)*(uint *)(iVar5 + 0xd8) * (ulonglong)uVar3;
    if (uVar7 < (uint)(uVar1 >> 0x32)) {
      *(uint *)(iVar5 + 0xd8) = DAT_0005d518 * uVar7;
    }
  }
  uVar4 = (undefined4)uVar1;
  if ((DAT_0005d51c & *(uint *)(iVar6 + 0x6c)) != DAT_0005d520) {
    uVar4 = FUN_000498e4(DAT_0005d524);
    uVar2 = DAT_0005d510;
    iVar6 = param_1 * 0x108 + DAT_0005d50c;
    *(undefined4 *)(iVar6 + 0xd8) = DAT_0005d510;
    *(undefined4 *)(iVar6 + 0xdc) = uVar2;
  }
  return uVar4;
}

