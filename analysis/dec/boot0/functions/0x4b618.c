// rea decompile_all
// name: FUN_0004b618
// address: 0x4b618
// body: available
// range: 0x4b618-0x4b72d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_0004b618(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (*(int *)(param_1 + 4) == 8) {
    uVar3 = *(uint *)(param_1 + 100);
    iVar5 = ((*(uint *)(param_1 + 0x58) & 0xfffffff) >> 0x14) * 10;
    iVar4 = (uVar3 & 0xff) * 10;
    if (iVar4 == 0) {
      iVar4 = 0x44c;
    }
    if ((uVar3 & 0x200000) == 0) {
      if (iVar5 == 0) {
        iVar5 = 0x294;
      }
    }
    else if (iVar5 == 0) {
      iVar5 = 800;
    }
    if (-1 < (int)(uVar3 << 0xb)) {
      iVar2 = FUN_0005d72c(DAT_0004b73c,iVar4,1);
      goto LAB_0004b68e;
    }
    iVar2 = FUN_0005d72c(DAT_0004b730,iVar4,1);
  }
  else {
    if (*(int *)(param_1 + 4) != 9) {
      return 0;
    }
    iVar5 = ((*(uint *)(param_1 + 100) & 0xffff) >> 8) * 10;
    if (iVar5 == 0) {
      iVar5 = 500;
    }
    iVar6 = ((*(uint *)(param_1 + 0x58) & 0xfffffff) >> 0x14) * 10;
    if (iVar6 == 0) {
      iVar6 = 0x438;
    }
    uVar3 = *(uint *)(param_1 + 0x58) & 0x10000;
    iVar4 = iVar5;
    if ((*(uint *)(param_1 + 100) & 0x100000) == 0) {
      if (uVar3 == 0) {
        iVar2 = FUN_0005d72c(DAT_0004b73c,iVar6,1);
      }
      else {
        iVar2 = FUN_0005d72c(DAT_0004b73c,0x4b0,1);
        iVar6 = 0x4b0;
      }
      iVar6 = FUN_0005d72c(DAT_0004b734,iVar6,1);
      iVar2 = iVar2 + iVar6;
LAB_0004b68e:
      uVar1 = DAT_0004b740;
      goto LAB_0004b666;
    }
    if (uVar3 == 0) {
      iVar2 = FUN_0005d72c(DAT_0004b730,iVar6,1);
    }
    else {
      iVar2 = FUN_0005d72c(DAT_0004b730,0x4b0,1);
      iVar6 = 0x4b0;
    }
    iVar6 = FUN_0005d72c(DAT_0004b744,iVar6,1);
    iVar2 = iVar2 + iVar6;
  }
  uVar1 = DAT_0004b734;
LAB_0004b666:
  iVar5 = FUN_0005d72c(uVar1,iVar5,1);
  if (iVar5 + iVar2 == 0) {
    FUN_0004993c(DAT_0004b748,iVar4);
    return iVar4;
  }
  FUN_0004993c(DAT_0004b738);
  return 0;
}

