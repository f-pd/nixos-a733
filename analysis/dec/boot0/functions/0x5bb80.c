// rea decompile_all
// name: FUN_0005bb80
// address: 0x5bb80
// body: available
// range: 0x5bb80-0x5bc61 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_0005bb80(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  bool bVar7;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  uint local_34;
  undefined4 local_24;
  
  uVar1 = DAT_0005bc78;
  iVar4 = DAT_0005bc70;
  iVar6 = 1000;
  do {
    local_40 = 0x37;
    local_3c = 0x15;
    local_38 = 0;
    local_24 = 0;
    iVar2 = FUN_0005b324(param_1,&local_40);
    if (iVar2 != 0) {
      uVar5 = *(undefined4 *)(param_1 + 0x30);
      uVar3 = DAT_0005bc64;
LAB_0005bbb2:
      FUN_000498e4(uVar3,uVar5);
      return iVar2;
    }
    local_40 = 0x29;
    local_3c = 1;
    local_38 = 0;
    if (-1 < *(int *)(param_1 + 0x50) << 0x1b) {
      local_38 = uVar1 & *(uint *)(param_1 + 0x24);
    }
    if (*(int *)(param_1 + 0x28) == iVar4) {
      local_38 = local_38 | 0x40000000;
    }
    iVar2 = FUN_0005b324(param_1,&local_40,0);
    if (iVar2 != 0) {
      uVar5 = *(undefined4 *)(param_1 + 0x30);
      uVar3 = DAT_0005bc68;
      goto LAB_0005bbb2;
    }
    FUN_00048da4(1);
    if ((int)local_34 < 0) {
      if (iVar6 != 0) {
        if (*(int *)(param_1 + 0x28) != DAT_0005bc70) {
          *(int *)(param_1 + 0x28) = DAT_0005bc70 + -0x10;
        }
        if (*(int *)(param_1 + 0x50) << 0x1b < 0) {
          local_40 = 0x3a;
          local_3c = 1;
          local_38 = 0;
          local_24 = 0;
          iVar4 = FUN_0005b324(param_1,&local_40);
          if (iVar4 != 0) {
            FUN_000498e4(DAT_0005bc74,*(undefined4 *)(param_1 + 0x30));
            return iVar4;
          }
        }
        *(uint *)(param_1 + 0x54) = local_34;
        *(uint *)(param_1 + 0x40) = (local_34 & 0x7fffffff) >> 0x1e;
        *(undefined4 *)(param_1 + 0x80) = 0;
        return 0;
      }
      goto LAB_0005bc06;
    }
    bVar7 = iVar6 == 0;
    iVar6 = iVar6 + -1;
    if (bVar7) {
LAB_0005bc06:
      FUN_000498e4(DAT_0005bc6c,*(undefined4 *)(param_1 + 0x30));
      return -0x11;
    }
  } while( true );
}

