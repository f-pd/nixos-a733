// rea decompile_all
// name: FUN_00049bdc
// address: 0x49bdc
// body: available
// range: 0x49bdc-0x49ced inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint FUN_00049bdc(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar5;
  uint *puVar4;
  
  FUN_0004993c(DAT_00049cf0,DAT_00049cf4,param_3,param_4,param_1,param_2,param_3);
  puVar4 = DAT_00049cf8;
  *DAT_00049cf8 = *DAT_00049cf8 | 0x100;
  puVar4[2] = puVar4[2] & 0xffffff00;
  if (((param_2[1] == 8) && (-1 < (int)param_2[0x17])) && (-1 < (int)(param_2[0x1b] << 2))) {
    uVar3 = param_2[0x1a] & 0x7f;
    puVar4 = param_2 + 0x20;
    do {
      puVar5 = puVar4 + 1;
      *puVar4 = uVar3 << 0x10 | uVar3 << 8 | uVar3 | uVar3 << 0x18;
      puVar4 = puVar5;
    } while (puVar5 != param_2 + 0x32);
    uVar3 = (uint)*(byte *)(param_2 + 0x12);
    param_2[0x32] = uVar3 << 0x10 | uVar3 << 8 | uVar3 | uVar3 << 0x18;
  }
  iVar1 = FUN_0004b618(param_2);
  if ((iVar1 != 0) &&
     (((int)(param_2[0x1e] << 0x1f) < 0 || (iVar1 = FUN_00057e44(param_2), iVar1 != 0)))) {
    FUN_0004993c(DAT_00049cfc,*param_2);
    FUN_0004993c(DAT_00049d00,param_2[1]);
    iVar1 = FUN_00057b7c(param_2);
    if (iVar1 == 0) {
      FUN_0004993c(DAT_00049d04);
    }
    else {
      if ((-1 < (int)param_2[0x17]) && ((int)(param_2[0x1b] << 2) < 0)) {
        FUN_000576e4(param_2);
        if (-1 < (int)(param_2[0x1b] << 1)) {
          param_2[0x1b] = param_2[0x1b] & 0xdfffffff;
        }
      }
      if ((int)param_2[7] < 0) {
        uVar3 = (param_2[7] & 0x7fffffff) >> 0x10;
      }
      else {
        uVar3 = FUN_0004b74c(param_2);
        FUN_0004993c(DAT_00049d0c,uVar3);
        param_2[7] = (uint)*(ushort *)(param_2 + 7) | uVar3 << 0x10;
      }
      FUN_0004993c(DAT_00049d08,uVar3,param_2[6],param_2[7],param_2[0x1e]);
      uVar2 = uVar3;
      if (0x1000 < uVar3) {
        uVar2 = 0x1000;
      }
      iVar1 = FUN_0004b4cc(uVar2);
      if (iVar1 == 0) {
        return uVar3;
      }
    }
  }
  return 0;
}

