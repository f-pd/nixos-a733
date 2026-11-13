// rea decompile_all
// name: FUN_000907b8
// address: 0x907b8
// body: available
// range: 0x907b8-0x907eb inclusive
// range: 0x907f0-0x9084b inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 6259351869dfa8b75c2ae9860dfec54e0318bc0486c2a4aee8e716831b3e4bb9
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_000907b8(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined8 uVar10;
  
  piVar4 = DAT_0009084c;
  do {
    if (piVar4 == DAT_00090850) {
LAB_000907d0:
      uVar1 = DAT_00090854;
LAB_000907d2:
      FUN_00092a80(3,uVar1);
      return 0xffffffea;
    }
    if (param_1[3] == *piVar4) {
      piVar4 = (int *)piVar4[1];
      if (piVar4 != (int *)0x0) {
        switch(param_1[4]) {
        case 0:
          iVar2 = piVar4[2];
          iVar6 = piVar4[3];
          iVar8 = piVar4[4];
          iVar7 = piVar4[1];
          break;
        case 1:
          iVar2 = piVar4[6];
          iVar6 = piVar4[7];
          iVar8 = piVar4[8];
          iVar7 = piVar4[5];
          break;
        case 2:
          iVar2 = piVar4[10];
          iVar6 = piVar4[0xb];
          iVar8 = piVar4[0xc];
          iVar7 = piVar4[9];
          break;
        case 3:
          iVar2 = piVar4[0xe];
          iVar6 = piVar4[0xf];
          iVar8 = piVar4[0x10];
          iVar7 = piVar4[0xd];
          break;
        default:
          uVar1 = DAT_00090858;
          goto LAB_000907d2;
        }
        uVar9 = param_1[5];
        iVar5 = piVar4[0x11];
        if (10 < uVar9) {
          uVar9 = uVar9 - 0xb;
        }
        iVar3 = iVar5 * uVar9 + *param_1 + *piVar4;
        param_1[8] = iVar3;
        param_1[9] = iVar8;
        uVar10 = FUN_000a39ac(param_1[6],iVar2,iVar3,iVar5,param_4);
        param_1[10] = iVar7 + (int)uVar10 * 4;
        param_1[0xb] = iVar6 * (int)((ulonglong)uVar10 >> 0x20);
        return 0;
      }
      goto LAB_000907d0;
    }
    piVar4 = piVar4 + 2;
  } while( true );
}

