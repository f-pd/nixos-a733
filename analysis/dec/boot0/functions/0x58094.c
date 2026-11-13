// rea decompile_all
// name: FUN_00058094
// address: 0x58094
// body: available
// range: 0x58094-0x58199 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00058094(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4,byte param_5,
                 uint param_6,uint param_7)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = DAT_0005819c;
  iVar4 = 0;
  do {
    iVar3 = iVar4;
    if (param_1 == 0xd) {
      puVar1[2] = *puVar1;
      if (iVar4 == 2) {
        uVar2 = param_5 | 0xd00;
      }
      else {
        uVar2 = param_4;
        if (iVar4 != 3) {
          if (iVar4 == 1) {
            uVar2 = param_6;
          }
          else {
            iVar3 = 0;
            uVar2 = param_7;
          }
        }
        uVar2 = uVar2 & 0xff | 0xd00;
      }
LAB_000580cc:
      FUN_00058048(uVar2,iVar3);
    }
    else if (param_1 == 0x10) {
      puVar1[2] = *puVar1;
      if (iVar4 == 2) {
        uVar2 = param_5 | 0x1000;
      }
      else {
        uVar2 = param_4;
        if (iVar4 != 3) {
          if (iVar4 == 1) {
            uVar2 = param_6;
          }
          else {
            iVar3 = 0;
            uVar2 = param_7;
          }
        }
        uVar2 = uVar2 & 0xff | 0x1000;
      }
      goto LAB_000580cc;
    }
    iVar4 = iVar4 + 1;
    if (iVar4 == 4) {
      DAT_0005819c[3] = DAT_0005819c[1];
      FUN_00057fcc(1,1,DAT_000581a4,DAT_000581a0,param_2,param_3,0);
      FUN_00057eb8(1,1,DAT_000581ac,(param_1 & 0xf) << 0xc | 0xf0,DAT_000581a8,param_2,param_3,0,0,0
                  );
      FUN_00057eb8(1,1,DAT_000581ac,0x80000000,0x7fffffff,param_2,param_3,0,0,0);
      FUN_00057eb8(1,0,DAT_000581b0,0,0xfffffffe,param_2,param_3,0,0,0);
      return;
    }
  } while( true );
}

