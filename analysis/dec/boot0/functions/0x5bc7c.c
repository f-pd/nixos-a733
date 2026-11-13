// rea decompile_all
// name: FUN_0005bc7c
// address: 0x5bc7c
// body: available
// range: 0x5bc7c-0x5bd5d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_0005bc7c(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  undefined4 local_40;
  undefined4 uStack_3c;
  uint local_38;
  uint local_34;
  int local_24;
  
  FUN_0005bb44();
  local_40 = 1;
  uStack_3c = 1;
  local_38 = 0;
  local_24 = 0;
  iVar2 = FUN_0005b324(param_1,&local_40);
  uVar1 = DAT_0005bd68;
  iVar3 = iVar2;
  if (iVar2 == 0) {
    iVar4 = 10000;
    FUN_00048da4(1);
    do {
      local_40 = 1;
      uStack_3c = 1;
      if (*(int *)(param_1 + 0x50) << 0x1b < 0) {
        local_38 = 0;
      }
      else {
        local_38 = local_34 & uVar1 & *(uint *)(param_1 + 0x24) | local_34 & 0x60000000;
      }
      if (*(int *)(param_1 + 0x50) << 0x1a < 0) {
        local_38 = local_38 | 0x40000000;
      }
      local_24 = iVar2;
      iVar3 = FUN_0005b324(param_1,&local_40,0);
      if (iVar3 != 0) goto LAB_0005bca0;
      FUN_00048da4(1);
      if ((int)local_34 < 0) {
        if (iVar4 != 0) {
          if (*(int *)(param_1 + 0x50) << 0x1b < 0) {
            local_40 = 0x3a;
            uStack_3c = 1;
            local_38 = iVar3;
            local_24 = iVar3;
            iVar3 = FUN_0005b324(param_1,&local_40,0);
            if (iVar3 != 0) {
              return iVar3;
            }
          }
          *(undefined4 *)(param_1 + 0x28) = 0x10000;
          *(uint *)(param_1 + 0x54) = local_34;
          *(uint *)(param_1 + 0x40) = (local_34 & 0x7fffffff) >> 0x1e;
          *(undefined4 *)(param_1 + 0x80) = 1;
          return 0;
        }
        break;
      }
      bVar5 = iVar4 != 0;
      iVar4 = iVar4 + -1;
    } while (bVar5);
    iVar3 = -0x11;
    FUN_000498e4(DAT_0005bd64,*(undefined4 *)(param_1 + 0x30));
  }
  else {
LAB_0005bca0:
    FUN_000498e4(DAT_0005bd60,*(undefined4 *)(param_1 + 0x30));
  }
  return iVar3;
}

