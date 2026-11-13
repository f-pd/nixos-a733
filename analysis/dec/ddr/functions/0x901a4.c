// rea decompile_all
// name: FUN_000901a4
// address: 0x901a4
// body: available
// range: 0x901a4-0x9023f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_000901a4(uint *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  
  uVar4 = FUN_00093508(DAT_00090244,DAT_00090240,6);
  uVar3 = DAT_00090254;
  uVar2 = DAT_00090244;
  uVar1 = DAT_00090240;
  if ((int)uVar4 < 1) {
    FUN_00092a80(3,DAT_00090248,DAT_00090240);
  }
  else {
    if ((int)uVar4 < 5) {
      uVar7 = 0;
      uVar6 = 0;
      do {
        iVar5 = FUN_00093590(uVar2,uVar1,&local_38,uVar6);
        if (iVar5 < 0) {
          FUN_00092a80(3,DAT_00090250,uVar6);
          return 0xfffffffb;
        }
        FUN_00090ad8(&local_38);
        FUN_00090ad0(local_38,uStack_34,&local_3c);
        FUN_00092a80(3,uVar3,local_3c);
        if (local_3c != 0) {
          uVar7 = uVar7 | 1 << (uVar6 & 0xff);
        }
        uVar6 = uVar6 + 1;
      } while (uVar4 != uVar6);
      *param_1 = uVar7;
      return 0;
    }
    FUN_00092a80(3,DAT_0009024c,4,DAT_00090240);
  }
  return 0xffffffea;
}

