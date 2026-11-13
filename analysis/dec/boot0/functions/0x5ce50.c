// rea decompile_all
// name: FUN_0005ce50
// address: 0x5ce50
// body: available
// range: 0x5ccbc-0x5ce17 inclusive
// range: 0x5ce50-0x5ce69 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_0005ce50(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  *(int *)(DAT_0005ce6c + param_1 * 4) = param_2;
  if (*(int *)(param_2 + 0xe8) == 0) {
    *(undefined4 *)(param_2 + 0xe8) = 0xffff;
  }
  if (*(int *)(param_2 + 0x2c) == 0) {
    iVar5 = (**(code **)(param_2 + 0xb0))();
    iVar2 = DAT_0005ce4c;
    uVar3 = DAT_0005ce24;
    iVar1 = DAT_0005ce20;
    if (iVar5 == 0) {
      *(undefined4 *)(param_2 + 0x44) = 1;
      FUN_0005c080(param_2);
      FUN_0005c5b8(param_2,1);
      while (iVar5 = FUN_0005bb44(param_2), iVar5 == 0) {
        *(undefined4 *)(param_2 + 0x88) = 0;
        iVar5 = *(int *)(iVar2 + 0x74);
        if (iVar5 == iVar1) {
          FUN_000498e4(DAT_0005ce2c);
          FUN_0005cc60(param_2);
          iVar5 = FUN_0005bb80(param_2);
          if (iVar5 != 0) {
            uVar4 = *(undefined4 *)(param_2 + 0x30);
            uVar3 = DAT_0005ce30;
LAB_0005cd54:
            FUN_000498e4(uVar3,uVar4);
            FUN_000498e4(DAT_0005ce34,*(undefined4 *)(param_2 + 0x30));
            return -0x11;
          }
LAB_0005cdf6:
          iVar5 = FUN_0005c6b4(param_2);
          if (iVar5 != 0) {
            FUN_000498e4(DAT_0005ce34,*(undefined4 *)(param_2 + 0x30));
            *(undefined4 *)(param_2 + 0x2c) = 0;
            return iVar5;
          }
          uVar4 = *(undefined4 *)(param_2 + 0x30);
          *(undefined4 *)(param_2 + 0x2c) = 1;
          iVar5 = 0;
          uVar3 = DAT_0005ce48;
          goto LAB_0005cce4;
        }
        if (iVar5 == 0x8000000) {
          FUN_000498e4(DAT_0005ce38);
          iVar5 = FUN_0005bc7c(param_2);
          if (iVar5 != 0) {
            uVar4 = *(undefined4 *)(param_2 + 0x30);
            uVar3 = DAT_0005ce3c;
            goto LAB_0005cd54;
          }
          goto LAB_0005cdf6;
        }
        if (*(int *)(param_2 + 0x30) != 2) {
          FUN_000498e4(DAT_0005ce40,iVar5);
          FUN_000498e4(DAT_0005ce2c,*(undefined4 *)(param_2 + 0x30));
          FUN_0005cc60(param_2);
          iVar5 = FUN_0005bb80(param_2);
          if (iVar5 != 0) {
            FUN_000498e4(DAT_0005ce38,*(undefined4 *)(param_2 + 0x30));
            iVar5 = FUN_0005bc7c(param_2);
            if (iVar5 != 0) {
              uVar4 = *(undefined4 *)(param_2 + 0x30);
              uVar3 = DAT_0005ce44;
              goto LAB_0005cd54;
            }
          }
          goto LAB_0005cdf6;
        }
        FUN_000498e4(uVar3,iVar5);
        FUN_000498e4(DAT_0005ce38,*(undefined4 *)(param_2 + 0x30));
        iVar5 = FUN_0005bc7c(param_2);
        if (iVar5 == 0) goto LAB_0005cdf6;
        FUN_000498e4(DAT_0005ce3c,*(undefined4 *)(param_2 + 0x30));
        FUN_000498e4(DAT_0005ce34,*(undefined4 *)(param_2 + 0x30));
        *(undefined1 *)(iVar2 + 0x75) = 0;
        *(undefined1 *)(iVar2 + 0x74) = 1;
        *(undefined1 *)(iVar2 + 0x76) = 0;
        *(undefined1 *)(iVar2 + 0x77) = 8;
      }
      uVar4 = *(undefined4 *)(param_2 + 0x30);
      uVar3 = DAT_0005ce28;
    }
    else {
      uVar4 = *(undefined4 *)(param_2 + 0x30);
      uVar3 = DAT_0005ce1c;
    }
LAB_0005cce4:
    FUN_000498e4(uVar3,uVar4);
  }
  else {
    iVar5 = 0;
    FUN_000498e4(DAT_0005ce18,*(undefined4 *)(param_2 + 0x30));
  }
  return iVar5;
}

