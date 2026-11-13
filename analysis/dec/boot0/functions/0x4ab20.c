// rea decompile_all
// name: FUN_0004ab20
// address: 0x4ab20
// body: available
// range: 0x4ab20-0x4ac75 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_0004ab20(undefined4 param_1,undefined4 param_2,int param_3,undefined1 *param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  bool bVar6;
  undefined4 uVar7;
  undefined4 local_24;
  
  piVar1 = DAT_0004ac78;
  if (DAT_0004ac78[1] == 0) {
    return -4;
  }
  uVar7 = param_1;
  local_24 = param_2;
  iVar2 = FUN_0004aa48();
  if ((iVar2 != 0) || (iVar2 = FUN_0004aa88(param_1,0), iVar2 != 0)) goto LAB_0004ab8c;
  if (param_3 < 3) {
    if (param_3 == 2) {
      iVar2 = 1;
    }
    else {
      iVar2 = 0;
    }
  }
  else {
    iVar2 = 2;
  }
  puVar3 = (undefined1 *)(iVar2 + (int)&local_24);
  do {
    puVar4 = puVar3 + -1;
    iVar2 = FUN_0004aa10(*puVar3);
    if (iVar2 != 0) goto LAB_0004ab8c;
    puVar3 = puVar4;
  } while ((int)puVar4 - (int)&local_24 != -1);
  iVar5 = *piVar1;
  *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | 0x20;
  iVar2 = 0xffff;
  do {
    bVar6 = iVar2 == 0;
    iVar2 = iVar2 + -1;
    if (bVar6) goto LAB_0004ab88;
  } while (-1 < *(int *)(iVar5 + 0xc) << 0x1c);
  if (iVar2 != 0) {
    if (*(int *)(iVar5 + 0x10) != 0x10) {
      iVar2 = -0x10;
      goto LAB_0004ab8c;
    }
    iVar2 = FUN_0004aa88(param_1,1,*(int *)(iVar5 + 0xc),0x10,uVar7);
    if (iVar2 != 0) goto LAB_0004ab8c;
    if (param_5 == 1) {
      *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | 8;
      iVar2 = 0xffff;
      do {
        bVar6 = iVar2 == 0;
        iVar2 = iVar2 + -1;
        if (bVar6) goto LAB_0004ab88;
      } while (-1 < *(int *)(iVar5 + 0xc) << 0x1c);
      if (iVar2 != 0) {
        *param_4 = (char)*(undefined4 *)(iVar5 + 8);
        if (*(int *)(iVar5 + 0x10) != 0x58) {
          iVar2 = -0x58;
          goto LAB_0004ab8c;
        }
        goto LAB_0004ac28;
      }
    }
    else {
      puVar3 = param_4;
      while( true ) {
        if (param_5 - 1U <= (uint)((int)puVar3 - (int)param_4)) {
          *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) & 0xfb;
          *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | 8;
          iVar2 = 0xffff;
          goto LAB_0004abdc;
        }
        *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | 0xc;
        iVar2 = 0xffff;
        do {
          bVar6 = iVar2 == 0;
          iVar2 = iVar2 + -1;
          if (bVar6) goto LAB_0004ab88;
        } while (-1 < *(int *)(iVar5 + 0xc) << 0x1c);
        if (iVar2 == 0) break;
        *puVar3 = (char)*(undefined4 *)(iVar5 + 8);
        iVar2 = 0xffff;
        do {
          bVar6 = iVar2 == 0;
          iVar2 = iVar2 + -1;
          if (bVar6) goto LAB_0004ab88;
        } while (*(int *)(iVar5 + 0x10) != 0x50);
        puVar3 = puVar3 + 1;
        if (iVar2 == 0) break;
      }
    }
  }
  goto LAB_0004ab88;
  while (-1 < *(int *)(iVar5 + 0xc) << 0x1c) {
LAB_0004abdc:
    bVar6 = iVar2 == 0;
    iVar2 = iVar2 + -1;
    if (bVar6) goto LAB_0004ab88;
  }
  if (iVar2 != 0) {
    param_4[param_5 - 1U] = (char)*(undefined4 *)(iVar5 + 8);
    iVar2 = 100;
    do {
      bVar6 = iVar2 == 0;
      iVar2 = iVar2 + -1;
      if (bVar6) goto LAB_0004ab88;
    } while (*(int *)(iVar5 + 0x10) != 0x58);
    if (iVar2 != 0) {
LAB_0004ac28:
      iVar2 = 0;
      goto LAB_0004ab8c;
    }
  }
LAB_0004ab88:
  iVar2 = -4;
LAB_0004ab8c:
  FUN_0004aad4();
  return iVar2;
}

