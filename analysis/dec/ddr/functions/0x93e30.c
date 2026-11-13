// rea decompile_all
// name: FUN_00093e30
// address: 0x93e30
// body: available
// range: 0x93e30-0x93ef9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00093e30(int param_1)

{
  ushort *puVar1;
  ushort uVar2;
  undefined2 uVar3;
  byte *pbVar4;
  byte bStack_68;
  byte abStack_67 [95];
  
  pbVar4 = &bStack_68;
  FUN_00092c40(&bStack_68,DAT_00093efc,0xe);
  FUN_00092c40(abStack_67 + 0xf,DAT_00093f00,0xe);
  FUN_00092c40(abStack_67 + 0x1f,DAT_00093f04,0xe);
  FUN_00092c40(abStack_67 + 0x2f,DAT_00093f08,0xe);
  FUN_00092c40(abStack_67 + 0x3f,DAT_00093f0c,0xe);
  FUN_00092c40(abStack_67 + 0x4f,DAT_00093f10,0xe);
  if (*(int *)(param_1 + 4) != 8) {
    uVar3 = 3;
    pbVar4 = abStack_67 + 0x4f;
    goto LAB_00093e96;
  }
  uVar2 = *(ushort *)(param_1 + 0x66) & 0xf;
  if ((*(ushort *)(param_1 + 0x66) & 0xf) != 0) {
    if (uVar2 == 1) {
      uVar3 = 5;
      pbVar4 = abStack_67 + 0xf;
      goto LAB_00093e96;
    }
    if (uVar2 == 2) {
      uVar3 = 0;
      pbVar4 = abStack_67 + 0x1f;
      goto LAB_00093e96;
    }
    if (uVar2 == 3) {
      pbVar4 = abStack_67 + 0x2f;
      uVar3 = 3;
      goto LAB_00093e96;
    }
    if (uVar2 == 4) {
      uVar3 = 0;
      pbVar4 = abStack_67 + 0x3f;
      goto LAB_00093e96;
    }
  }
  uVar3 = 5;
LAB_00093e96:
  *DAT_00093f14 = uVar3;
  puVar1 = DAT_00093f18;
  *DAT_00093f18 = (ushort)pbVar4[1];
  puVar1[1] = (ushort)pbVar4[2];
  puVar1[2] = (ushort)pbVar4[3];
  puVar1[3] = (ushort)pbVar4[4];
  puVar1[4] = (ushort)pbVar4[5];
  puVar1[5] = (ushort)pbVar4[6];
  puVar1[0xfff] = (ushort)pbVar4[7];
  puVar1[0x1000] = (ushort)pbVar4[8];
  puVar1[0x1001] = (ushort)pbVar4[9];
  puVar1[0x1002] = (ushort)pbVar4[10];
  puVar1[0x1003] = (ushort)pbVar4[0xb];
  puVar1[0x1004] = (ushort)pbVar4[0xc];
  *DAT_00093f1c = (ushort)pbVar4[0xd];
  return;
}

