// rea decompile_all
// name: FUN_0005bed0
// address: 0x5bed0
// body: available
// range: 0x5be20-0x5bebf inclusive
// range: 0x5bed0-0x5bee9 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_0005bed0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_218 [185];
  char local_15f;
  byte local_154;
  
  *(undefined4 *)(param_1 + 0x4c) = 0;
  if ((*(int *)(param_1 + 0x50) << 0x1b < 0) || (*(uint *)(param_1 + 0x28) <= DAT_0005beec)) {
    return 0;
  }
  *(undefined4 *)(param_1 + 0x4c) = 0xc;
  iVar1 = FUN_0005bd6c(param_1,auStack_218);
  uVar3 = DAT_0005becc;
  if (iVar1 == 0) {
    iVar4 = 6;
    do {
      iVar1 = FUN_0005bdc8(param_1,1,0xb9);
      if (iVar1 == 0) {
        iVar1 = FUN_0005bd6c(param_1,auStack_218);
        if (iVar1 == 0) {
          if (local_15f == '\0') {
            return 0;
          }
          if ((local_154 & 3) == 0) {
            *(undefined4 *)(param_1 + 0x104) = 0;
            *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 1;
            return 0;
          }
          if ((local_154 & 0xc) == 0) {
            uVar3 = 1;
          }
          else {
            *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x40;
            uVar3 = 2;
          }
          *(undefined4 *)(param_1 + 0x104) = uVar3;
          *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 3;
          return 0;
        }
        uVar2 = *(undefined4 *)(param_1 + 0x30);
        uVar3 = DAT_0005bec8;
        goto LAB_0005be3c;
      }
      FUN_000498e4(uVar3);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    uVar2 = *(undefined4 *)(param_1 + 0x30);
    uVar3 = DAT_0005bec4;
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x30);
    uVar3 = DAT_0005bec0;
  }
LAB_0005be3c:
  FUN_000498e4(uVar3,uVar2);
  return iVar1;
}

