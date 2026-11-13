// rea decompile_all
// name: FUN_0004a5cc
// address: 0x4a5cc
// body: available
// range: 0x4a5cc-0x4a92d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_0004a5cc(int param_1,uint param_2,int param_3)

{
  byte bVar1;
  bool bVar2;
  byte *pbVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint local_50;
  uint local_4c;
  uint *local_48;
  uint *local_44;
  uint local_40;
  uint local_38;
  uint local_34;
  
  local_40 = 0;
  do {
    if (local_40 == param_2) {
      return 0xffffffff;
    }
    uVar12 = (uint)*(byte *)(param_1 + local_40 * 8);
    iVar15 = param_1 + local_40 * 8;
    local_40 = local_40 + 1;
  } while (uVar12 == 0);
  bVar1 = *(byte *)(iVar15 + 1);
  uVar14 = (uint)bVar1;
  iVar5 = (uint)(bVar1 >> 3) * 4;
  if (uVar12 < 0xc) {
    iVar9 = (uVar12 + 0x3ffff) * 0x80;
    iVar7 = iVar9 + 0xb0;
    iVar5 = iVar5 + iVar9;
    puVar4 = (uint *)(iVar5 + 0x80);
    puVar6 = (uint *)(iVar5 + 0xa0);
    local_44 = (uint *)(iVar9 + 0x90);
  }
  else {
    iVar9 = uVar12 * 0x30;
    iVar5 = iVar9 + iVar5;
    puVar4 = (uint *)(DAT_0004a930 + iVar5);
    iVar7 = DAT_0004a934 + iVar9;
    puVar6 = (uint *)(DAT_0004a938 + iVar5);
    local_44 = (uint *)(DAT_0004a93c + iVar9);
  }
  local_48 = (uint *)(iVar7 + (uint)(bVar1 >> 4) * 4);
  DataMemoryBarrier(0x1f);
  local_50 = *local_48;
  DataMemoryBarrier(0x1f);
  uVar11 = *puVar6;
  DataMemoryBarrier(0x1f);
  local_4c = *local_44;
  DataMemoryBarrier(0x1f);
  iVar5 = (uVar14 & 7) << 2;
  uVar10 = *puVar4 & ~(0xf << iVar5);
  if (param_3 != 0) {
    uVar10 = uVar10 | (*(byte *)(iVar15 + 2) & 0xf) << iVar5;
  }
  if (-1 < *(char *)(iVar15 + 3)) {
    iVar7 = (uVar14 & 0xf) << 1;
    local_50 = ((int)*(char *)(iVar15 + 3) & 3U) << iVar7 | local_50 & ~(3 << iVar7);
  }
  if (-1 < *(char *)(iVar15 + 4)) {
    uVar11 = ((int)*(char *)(iVar15 + 4) & 3U) << iVar5 | uVar11 & ~(3 << iVar5);
  }
  if ((*(char *)(iVar15 + 2) == '\x01') && (-1 < *(char *)(iVar15 + 5))) {
    local_4c = ((int)*(char *)(iVar15 + 5) & 1U) << uVar14 | local_4c & ~(1 << uVar14);
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  pbVar3 = (byte *)(param_1 + local_40 * 8);
  local_38 = (uint)(bVar1 >> 3);
  local_34 = (uint)(bVar1 >> 4);
  for (; local_40 < param_2; local_40 = local_40 + 1) {
    uVar14 = (uint)*pbVar3;
    bVar1 = pbVar3[1];
    uVar16 = (uint)bVar1;
    if (uVar14 == 0) break;
    uVar8 = (uint)(bVar1 >> 4);
    uVar13 = (uint)(bVar1 >> 3);
    if ((local_34 == uVar8) && (uVar12 == uVar14)) {
      if (local_38 != uVar13) {
        DataMemoryBarrier(0x1f);
        *puVar4 = uVar10;
        if (0xb < uVar14) {
          puVar4 = (uint *)0x30;
          local_38 = DAT_0004a930;
        }
        iVar15 = (uVar14 + 0x3ffff) * 0x80;
        if (uVar14 < 0xc) {
          iVar5 = iVar15 + 0x80;
        }
        else {
          iVar5 = (int)puVar4 * uVar14 + local_38;
        }
        puVar4 = (uint *)(iVar5 + uVar13 * 4);
        uVar10 = *puVar4;
        DataMemoryBarrier(0x1f);
        DataMemoryBarrier(0x1f);
        iVar15 = iVar15 + 0xa0;
        *puVar6 = uVar11;
        puVar6 = (uint *)(iVar15 + uVar13 * 4);
        uVar11 = *(uint *)(iVar15 + uVar13 * 4);
        DataMemoryBarrier(0x1f);
      }
    }
    else {
      DataMemoryBarrier(0x1f);
      *puVar4 = uVar10;
      DataMemoryBarrier(0x1f);
      *local_48 = local_50;
      DataMemoryBarrier(0x1f);
      *puVar6 = uVar11;
      if (bVar2) {
        DataMemoryBarrier(0x1f);
        *local_44 = local_4c;
      }
      if (uVar14 < 0xc) {
        iVar5 = (uVar14 + 0x3ffff) * 0x80;
        iVar15 = uVar13 * 4 + iVar5;
        puVar4 = (uint *)(iVar15 + 0x80);
        local_44 = (uint *)(iVar5 + 0x90);
        puVar6 = (uint *)(iVar15 + 0xa0);
        local_48 = (uint *)(uVar8 * 4 + iVar5 + 0xb0);
      }
      else {
        iVar5 = uVar14 * 0x30;
        iVar15 = uVar13 * 4 + iVar5;
        puVar4 = (uint *)(iVar15 + DAT_0004a930);
        local_48 = (uint *)(iVar5 + DAT_0004a934 + uVar8 * 4);
        puVar6 = (uint *)(iVar15 + 0x7024dd4);
        local_44 = (uint *)(iVar5 + 0x7024e50);
      }
      uVar10 = *puVar4;
      DataMemoryBarrier(0x1f);
      local_50 = *local_48;
      DataMemoryBarrier(0x1f);
      uVar11 = *puVar6;
      DataMemoryBarrier(0x1f);
      local_4c = *local_44;
      DataMemoryBarrier(0x1f);
      bVar2 = false;
    }
    uVar12 = (uint)(char)pbVar3[2];
    iVar15 = (uVar16 & 7) << 2;
    if ((-1 < (int)uVar12) && (uVar10 = uVar10 & ~(0xf << iVar15), param_3 != 0)) {
      uVar10 = uVar10 | (uVar12 & 0xf) << iVar15;
    }
    if (-1 < (char)pbVar3[3]) {
      iVar5 = (uVar16 & 0xf) << 1;
      local_50 = ((int)(char)pbVar3[3] & 3U) << iVar5 | local_50 & ~(3 << iVar5);
    }
    if (-1 < (char)pbVar3[4]) {
      uVar11 = ((int)(char)pbVar3[4] & 3U) << iVar15 | uVar11 & ~(3 << iVar15);
    }
    if ((uVar12 == 1) && (-1 < (char)pbVar3[5])) {
      local_4c = ((int)(char)pbVar3[5] & 1U) << uVar16 | local_4c & ~(1 << uVar16);
      bVar2 = true;
    }
    pbVar3 = pbVar3 + 8;
    uVar12 = uVar14;
    local_38 = uVar13;
    local_34 = uVar8;
  }
  if (puVar4 != (uint *)0x0) {
    DataMemoryBarrier(0x1f);
    *puVar4 = uVar10;
    DataMemoryBarrier(0x1f);
    *local_48 = local_50;
    DataMemoryBarrier(0x1f);
    *puVar6 = uVar11;
    if (bVar2) {
      DataMemoryBarrier(0x1f);
      *local_44 = local_4c;
    }
  }
  return 0;
}

