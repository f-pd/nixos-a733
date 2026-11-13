// rea decompile_all
// name: FUN_00090258
// address: 0x90258
// body: available
// range: 0x90258-0x90303 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_00090258(undefined4 param_1,uint *param_2)

{
  ushort uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  ushort *puVar6;
  uint uVar7;
  uint local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c [2];
  
  puVar2 = DAT_00090304;
  iVar3 = FUN_000934c0(*DAT_00090304,param_1,DAT_00090308,&local_28);
  if (iVar3 < 0) {
    uVar5 = DAT_00090308;
  }
  else {
    iVar3 = FUN_000934c0(*puVar2,param_1,DAT_00090310,&local_20);
    if (iVar3 < 0) {
      uVar5 = DAT_00090310;
    }
    else {
      iVar3 = FUN_0009347a(*puVar2,local_20);
      if (iVar3 < 0) {
        return iVar3;
      }
      iVar3 = FUN_000934c0(*puVar2,iVar3,DAT_00090314,&local_24);
      if (-1 < iVar3) {
        iVar3 = FUN_000918e4(0,local_24);
        if (iVar3 != 0) {
          FUN_00092a80(3,DAT_00090318);
          return -5;
        }
        FUN_00091900(0,local_24,local_28 & 0xf,local_1c);
        uVar7 = 0;
        puVar6 = DAT_0009031c;
        do {
          uVar1 = *puVar6;
          uVar4 = uVar7 & 0xff;
          puVar6 = puVar6 + 1;
          if (local_1c[0] < (uint)*puVar6 + (uint)uVar1 >> 1) goto LAB_00090300;
          uVar7 = uVar7 + 1;
        } while (uVar7 != 7);
        uVar4 = 7;
LAB_00090300:
        *param_2 = uVar4;
        return 0;
      }
      uVar5 = DAT_00090314;
    }
  }
  FUN_00092a80(3,DAT_0009030c,uVar5);
  return -0x16;
}

