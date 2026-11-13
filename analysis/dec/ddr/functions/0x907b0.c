// rea decompile_all
// name: FUN_000907b0
// address: 0x907b0
// body: available
// range: 0x907b0-0x907b7 inclusive
// range: 0xa01e0-0xa02f1 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_000907b0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar5;
  uint *puVar4;
  
  FUN_00092a38(DAT_000a02f4,DAT_000a02f8,param_3,param_4,0,param_1,param_3);
  puVar4 = DAT_000a02fc;
  *DAT_000a02fc = *DAT_000a02fc | 0x100;
  puVar4[2] = puVar4[2] & 0xffffff00;
  if (((param_1[1] == 8) && (-1 < (int)param_1[0x17])) && (-1 < (int)(param_1[0x1b] << 2))) {
    uVar3 = param_1[0x1a] & 0x7f;
    puVar4 = param_1 + 0x20;
    do {
      puVar5 = puVar4 + 1;
      *puVar4 = uVar3 << 0x10 | uVar3 << 8 | uVar3 | uVar3 << 0x18;
      puVar4 = puVar5;
    } while (puVar5 != param_1 + 0x32);
    uVar3 = (uint)*(byte *)(param_1 + 0x12);
    param_1[0x32] = uVar3 << 0x10 | uVar3 << 8 | uVar3 | uVar3 << 0x18;
  }
  iVar1 = FUN_00093890(param_1);
  if ((iVar1 != 0) &&
     (((int)(param_1[0x1e] << 0x1f) < 0 || (iVar1 = FUN_000a0148(param_1), iVar1 != 0)))) {
    FUN_00092a38(DAT_000a0300,*param_1);
    FUN_00092a38(DAT_000a0304,param_1[1]);
    iVar1 = FUN_0009fe7c(param_1);
    if (iVar1 == 0) {
      FUN_00092a38(DAT_000a0308);
    }
    else {
      if ((-1 < (int)param_1[0x17]) && ((int)(param_1[0x1b] << 2) < 0)) {
        FUN_0009f9e4(param_1);
        if (-1 < (int)(param_1[0x1b] << 1)) {
          param_1[0x1b] = param_1[0x1b] & 0xdfffffff;
        }
      }
      if ((int)param_1[7] < 0) {
        uVar3 = (param_1[7] & 0x7fffffff) >> 0x10;
      }
      else {
        uVar3 = FUN_000939c4(param_1);
        FUN_00092a38(DAT_000a0310,uVar3);
        param_1[7] = (uint)*(ushort *)(param_1 + 7) | uVar3 << 0x10;
      }
      FUN_00092a38(DAT_000a030c,uVar3,param_1[6],param_1[7],param_1[0x1e]);
      uVar2 = uVar3;
      if (0x1000 < uVar3) {
        uVar2 = 0x1000;
      }
      iVar1 = FUN_00093744(uVar2);
      if (iVar1 == 0) {
        return uVar3;
      }
    }
  }
  return 0;
}

