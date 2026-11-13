// rea decompile_all
// name: FUN_000491b8
// address: 0x491b8
// body: available
// range: 0x491b8-0x49483 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_000491b8(undefined4 param_1,uint param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 local_30;
  uint local_2c;
  uint local_28;
  uint uStack_24;
  
  local_30 = param_1;
  local_2c = param_2;
  local_28 = param_3;
  uStack_24 = param_4;
  FUN_00049082(DAT_00049484,0x18);
  FUN_00049082(DAT_00049488,0x18);
  FUN_00049082(DAT_0004948c,0x18);
  FUN_00049082(DAT_00049490,0x18);
  FUN_00049082(DAT_00049494,0x18);
  FUN_00049082(DAT_00049498,0x18);
  FUN_00049082(DAT_0004949c,0x18);
  FUN_00049082(DAT_000494a0,0x18);
  FUN_00049082(DAT_000494a4,0x18);
  FUN_00049082(DAT_000494a8,0x18);
  FUN_00049082(DAT_000494ac,0x18);
  FUN_00049082(DAT_000494b0,0x18);
  FUN_00049082(DAT_000494b4,0x18);
  puVar3 = DAT_00049500;
  puVar2 = DAT_000494fc;
  puVar8 = DAT_000494c0;
  puVar1 = DAT_000494bc;
  DataMemoryBarrier(0x1f);
  uVar5 = *DAT_000494b8 & 0x4000;
  if (uVar5 == 0) {
    uVar4 = *DAT_000494b8 & 0x8000;
    if (uVar4 == 0) {
      local_30 = 0x14;
      local_2c = uVar4;
      local_28 = uVar4;
      uStack_24 = uVar4;
      FUN_00049098(DAT_000494c0,&local_30);
      local_30 = 0x2a;
      local_2c = uVar4;
      local_28 = uVar4;
      uStack_24 = uVar4;
      FUN_00049114(puVar8,&local_30);
      DataMemoryBarrier(0x1f);
      puVar7 = puVar8 + 0x400;
      FUN_0004993c(DAT_000494f0,*puVar8);
      local_30 = 0x14;
      local_2c = uVar4;
      local_28 = uVar4;
      uStack_24 = uVar4;
      FUN_00049098(puVar7,&local_30);
      local_30 = 0x2a;
      local_2c = uVar4;
      local_28 = uVar4;
      uStack_24 = uVar4;
      FUN_00049114(puVar7,&local_30);
      DataMemoryBarrier(0x1f);
      puVar8 = puVar8 + 0x800;
      FUN_0004993c(DAT_000494f4,*puVar7);
      local_30 = 0x14;
      local_2c = uVar4;
      local_28 = uVar4;
      uStack_24 = uVar4;
      FUN_00049098(puVar8,&local_30);
      local_30 = 0x1f;
      local_2c = uVar4;
      local_28 = uVar4;
      uStack_24 = uVar4;
      FUN_00049114(puVar8,&local_30);
      DataMemoryBarrier(0x1f);
      FUN_0004993c(DAT_000494f8,*puVar8);
    }
    else {
      local_30 = 0x14;
      local_2c = uVar5;
      local_28 = uVar5;
      uStack_24 = uVar5;
      FUN_00049098(DAT_000494c0,&local_30);
      local_30 = 0x27;
      local_2c = uVar5;
      local_28 = uVar5;
      uStack_24 = uVar5;
      FUN_00049114(DAT_000494c0,&local_30);
      local_30 = 0x14;
      local_2c = uVar5;
      local_28 = uVar5;
      uStack_24 = uVar5;
      FUN_00049098(DAT_000494c4,&local_30);
      local_30 = 0x27;
      local_2c = uVar5;
      local_28 = uVar5;
      uStack_24 = uVar5;
      FUN_00049114(DAT_000494c4,&local_30);
      local_30 = 0x14;
      local_2c = uVar5;
      local_28 = uVar5;
      uStack_24 = uVar5;
      FUN_00049098(DAT_000494c8,&local_30);
      local_30 = 0x1e;
      local_2c = uVar5;
      local_28 = uVar5;
      uStack_24 = uVar5;
      FUN_00049114(DAT_000494c8,&local_30);
    }
    uVar5 = DAT_000494cc;
    DataMemoryBarrier(0x1f);
    DataMemoryBarrier(0x1f);
    *puVar2 = *puVar2 & DAT_000494cc | 0x3000000;
    FUN_00048d80(0x14);
    DataMemoryBarrier(0x1f);
    DataMemoryBarrier(0x1f);
    *puVar3 = *puVar3 & uVar5 | 0x3000000;
    FUN_00048d80(0x14);
    DataMemoryBarrier(0x1f);
    DataMemoryBarrier(0x1f);
    *puVar1 = *puVar1 & uVar5 | 0x3000000;
    FUN_00048d80(0x14);
  }
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *DAT_000494d0 = *DAT_000494d0 & 0xfcffffe0;
  puVar1 = DAT_000494d8;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *DAT_000494d4 = *DAT_000494d4 & 0xf8ffffff | 0x4000000;
  iVar6 = DAT_000494dc;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *puVar1 = *puVar1 & 0x7fffffe0 | 0x8000000;
  do {
    uVar5 = *puVar1;
    DataMemoryBarrier(0x1f);
    FUN_00048d80(1);
    if (-1 < (int)(uVar5 << 4)) goto LAB_00049362;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  FUN_0004993c(DAT_000494e0);
LAB_00049362:
  iVar6 = DAT_000494dc;
  puVar2 = DAT_000494d8;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *puVar1 = *puVar1 & 0xf8ffffff | 0x8b000000;
  do {
    uVar5 = *puVar2;
    DataMemoryBarrier(0x1f);
    FUN_00048d80(1);
    if (-1 < (int)(uVar5 << 4)) goto LAB_00049394;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  FUN_0004993c(DAT_000494e4);
LAB_00049394:
  puVar1 = DAT_000494e8;
  FUN_0004b114();
  uVar5 = *puVar1;
  DataMemoryBarrier(0x1f);
  if ((int)(uVar5 << 0x1f) < 0) {
    DataMemoryBarrier(0x1f);
    *puVar1 = uVar5 & 0xffffbffe | 0x16aa0000;
    DataMemoryBarrier(0x1f);
    DataMemoryBarrier(0x1f);
    *puVar1 = *puVar1 | 0xc;
    FUN_00048d80(0x32);
    DataMemoryBarrier(0x1f);
    uVar5 = DAT_000494ec | *puVar1;
  }
  else {
    uVar5 = uVar5 | 0xc;
  }
  DataMemoryBarrier(0x1f);
  *puVar1 = uVar5;
  return;
}

