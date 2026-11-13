// rea decompile_all
// name: FUN_0004b2e8
// address: 0x4b2e8
// body: available
// range: 0x4b2e8-0x4b47b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0004b2e8(void)

{
  char cVar1;
  byte bVar2;
  sbyte sVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  uint uVar13;
  uint uVar14;
  int local_38 [5];
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  
  iVar11 = DAT_0004b480;
  local_38[0] = *DAT_0004b47c;
  local_38[1] = DAT_0004b47c[1];
  local_38[2] = DAT_0004b47c[2];
  local_38[3] = DAT_0004b47c[3];
  local_38[4] = DAT_0004b47c[4];
  iStack_24 = DAT_0004b47c[5];
  iStack_20 = DAT_0004b47c[6];
  iStack_1c = DAT_0004b47c[7];
  if (*(int *)(DAT_0004b480 + 0x94) < 0) goto LAB_0004b3a6;
  uVar4 = FUN_000495f0(DAT_0004b484);
  iVar5 = FUN_000495ce(iVar11 + 0x348,DAT_0004b484,uVar4);
  if (iVar5 != 0) {
    FUN_0004993c(DAT_0004b4a0);
    return 0xffffffff;
  }
  FUN_0004a5cc(iVar11 + 0x354,6,1);
  cVar1 = *(char *)(iVar11 + 0x350);
  if (cVar1 == '\x01') {
    uVar8 = 0;
    uVar13 = 0;
    iVar5 = iVar11;
    do {
      if (*(byte *)(iVar5 + 0x354) != 0) {
        uVar13 = uVar13 | ((1 << *(sbyte *)(iVar5 + 0x355) &
                           *(uint *)((uint)*(byte *)(iVar5 + 0x354) * 0x80 + 0x2000010)) >>
                          *(sbyte *)(iVar5 + 0x355)) << (uVar8 & 0xff);
      }
      uVar8 = uVar8 + 1;
      iVar5 = iVar5 + 8;
    } while (uVar8 != 4);
    uVar8 = 0;
LAB_0004b368:
    iVar5 = 0xf;
  }
  else {
    uVar13 = 0;
    if (cVar1 != '\0') {
      bVar2 = *(byte *)(iVar11 + 0x351);
      uVar8 = FUN_0004b1bc(bVar2 & 0xf);
      piVar9 = local_38;
      do {
        uVar14 = uVar13 + 1;
        if (uVar8 < (uint)(piVar9[1] + *piVar9) >> 1) break;
        piVar9 = piVar9 + 1;
        uVar13 = uVar14;
      } while (uVar14 != 7);
      if (cVar1 == '\x03') {
        iVar5 = 0;
        do {
          uVar8 = (uint)*(byte *)(iVar11 + iVar5 * 8 + 0x354);
          if (uVar8 != 0) {
            sVar3 = *(sbyte *)(iVar11 + iVar5 * 8 + 0x355);
            uVar8 = (1 << sVar3 & *(uint *)(uVar8 * 0x80 + 0x2000010)) >> sVar3;
            break;
          }
          iVar5 = iVar5 + 1;
          uVar8 = 0;
        } while (iVar5 != 4);
      }
      else {
        if (cVar1 != '\x04') goto LAB_0004b452;
        iVar5 = FUN_0004b1bc(bVar2 >> 4);
        uVar8 = (uint)(iVar5 - 0x6f6U < 0x25);
      }
      FUN_0004993c(DAT_0004b498,0xf);
      goto LAB_0004b368;
    }
LAB_0004b452:
    uVar8 = 0;
    iVar5 = 7;
  }
  iVar10 = uVar13 + uVar8 * 8;
  if (iVar10 != 0) {
    iVar6 = (iVar10 + -1) * 0x80;
    if (*(int *)(iVar11 + iVar6 + 0x374) == 0) {
      FUN_0004993c(DAT_0004b488,iVar10);
      iVar10 = 0;
    }
    else {
      thunk_FUN_00047d1c(DAT_0004b49c,iVar6 + 0x374 + iVar11,0x80);
    }
  }
  iVar7 = 1;
  iVar6 = 0;
  do {
    if (*(int *)(iVar11 + iVar6 * 0x80 + 0x374) != 0) {
      iVar7 = iVar7 + 1;
    }
    iVar6 = iVar6 + 1;
  } while (iVar5 != iVar6);
  FUN_0004993c(DAT_0004b48c,iVar7,iVar10);
LAB_0004b3a6:
  uVar13 = FUN_000498c0();
  uVar4 = DAT_0004b494;
  if (3 < uVar13) {
    iVar11 = 0;
    puVar12 = DAT_0004b490;
    do {
      puVar12 = puVar12 + 1;
      iVar5 = iVar11 + 1;
      FUN_0004993c(uVar4,iVar11,*puVar12);
      iVar11 = iVar5;
    } while (iVar5 != 0x20);
  }
  return 0;
}

