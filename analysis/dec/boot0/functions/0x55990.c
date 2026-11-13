// rea decompile_all
// name: FUN_00055990
// address: 0x55990
// body: available
// range: 0x55990-0x55a83 inclusive
// range: 0x55a90-0x55e25 inclusive
// range: 0x55e3c-0x56147 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_00055990(int *param_1)

{
  undefined2 *puVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  byte local_50;
  byte local_4c;
  byte local_48;
  byte local_44;
  byte local_40;
  byte local_3c;
  byte local_38;
  byte local_34;
  byte local_30;
  byte local_2c;
  
  FUN_00055654();
  FUN_0004f57c(param_1);
  puVar3 = DAT_0005615c;
  puVar1 = DAT_00055a84;
  if ((param_1[0x1e] & 4U) == 0) {
    FUN_0004f58c(0,param_1);
    FUN_0004f500(0,param_1);
    FUN_0004f4f0(0,param_1);
    *puVar3 = 0;
    FUN_0004bbb8(param_1);
    FUN_0004b97c(param_1);
    *puVar3 = 1;
    iVar4 = FUN_0004f47c(0);
    FUN_0004993c(DAT_00056160,0,*param_1);
    if (iVar4 != 7) {
      FUN_0004993c(DAT_00056164,0,iVar4);
      return 0;
    }
    FUN_0004bca8(0,param_1);
  }
  else {
    uVar15 = 1;
    do {
      FUN_0004f58c(uVar15,param_1);
      FUN_0004f500(uVar15,param_1);
      FUN_0004f4f0(uVar15,param_1);
      *puVar1 = 0;
      FUN_0004bbb8(param_1);
      FUN_0004b97c(param_1);
      *puVar1 = 1;
      iVar4 = FUN_0004f47c(uVar15);
      uVar5 = FUN_00048038(*param_1 << 2,((uint)param_1[0x18] >> ((uVar15 & 0x1f) << 3) & 0x1f) + 1)
      ;
      FUN_0004993c(DAT_00055a88,uVar15,uVar5);
      if (iVar4 != 7) goto LAB_00055a0e;
      uVar18 = uVar15 + 1;
      FUN_0004bca8(uVar15,param_1);
      uVar15 = uVar18;
    } while (uVar18 != 4);
    FUN_0004f58c(0,param_1);
    FUN_0004f500(0,param_1);
    FUN_0004f4f0(0,param_1);
    *puVar1 = 0;
    FUN_0004bbb8(param_1);
    FUN_0004b97c(param_1);
    *puVar1 = 1;
    iVar4 = FUN_0004f47c(0);
    uVar5 = FUN_00048038(*param_1 << 2,(param_1[0x18] & 0x1fU) + 1);
    FUN_0004993c(DAT_00055a88,0,uVar5);
    if (iVar4 != 7) {
      uVar15 = 0;
LAB_00055a0e:
      FUN_0004993c(DAT_00055a8c,uVar15,iVar4);
      return 0;
    }
    FUN_0004bca8(0,param_1);
    if ((param_1[0x1b] & 0x20000000U) == 0) {
      iVar23 = param_1[0x20];
      iVar22 = param_1[0x29];
      iVar4 = 0;
      if (param_1[1] == 9) {
        iVar4 = 0x1e8;
      }
      *DAT_00055e28 = 0;
      iVar2 = DAT_00055e2c;
      iVar25 = param_1[0x21];
      iVar24 = param_1[0x2a];
      *(ushort *)(iVar4 + DAT_00055e2c) = (ushort)iVar23 & 0xff;
      *(ushort *)(iVar4 + iVar2 + 2) = (ushort)iVar22 & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 4) = 0x8027;
      iVar2 = DAT_00055e30;
      *(undefined2 *)(iVar4 + DAT_00055e30) = 0x18;
      *(ushort *)(iVar4 + iVar2 + 2) = (ushort)iVar25 & 0xff;
      *(ushort *)(iVar4 + iVar2 + 4) = (ushort)iVar24 & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 6) = 0x80a7;
      iVar6 = param_1[0x22];
      *(undefined2 *)(iVar4 + iVar2 + 8) = 0x18;
      local_50 = (byte)iVar6;
      *(ushort *)(iVar4 + iVar2 + 10) = (ushort)local_50;
      iVar7 = param_1[0x2b];
      local_4c = (byte)iVar7;
      *(ushort *)(iVar4 + iVar2 + 0xc) = (ushort)local_4c;
      *(undefined2 *)(iVar4 + iVar2 + 0xe) = 0x8127;
      iVar8 = param_1[0x23];
      *(undefined2 *)(iVar4 + iVar2 + 0x10) = 0x18;
      local_48 = (byte)iVar8;
      *(ushort *)(iVar4 + iVar2 + 0x12) = (ushort)local_48;
      iVar9 = param_1[0x2c];
      local_44 = (byte)iVar9;
      *(ushort *)(iVar4 + iVar2 + 0x14) = (ushort)local_44;
      *(undefined2 *)(iVar4 + iVar2 + 0x16) = 0x81a7;
      iVar10 = param_1[0x24];
      *(undefined2 *)(iVar4 + iVar2 + 0x18) = 0x18;
      iVar21 = param_1[0x2f];
      local_40 = (byte)iVar10;
      iVar20 = param_1[0x27];
      iVar19 = param_1[0x30];
      *(ushort *)(iVar4 + iVar2 + 0x1a) = (ushort)local_40;
      iVar11 = param_1[0x2d];
      local_3c = (byte)iVar11;
      *(ushort *)(iVar4 + iVar2 + 0x1c) = (ushort)local_3c;
      *(undefined2 *)(iVar4 + iVar2 + 0x1e) = 0x8227;
      iVar12 = param_1[0x25];
      *(undefined2 *)(iVar4 + iVar2 + 0x20) = 0x18;
      local_38 = (byte)iVar12;
      *(ushort *)(iVar4 + iVar2 + 0x22) = (ushort)local_38;
      iVar13 = param_1[0x2e];
      local_34 = (byte)iVar13;
      *(ushort *)(iVar4 + iVar2 + 0x24) = (ushort)local_34;
      *(undefined2 *)(iVar4 + iVar2 + 0x26) = 0x82a7;
      iVar14 = param_1[0x26];
      *(undefined2 *)(iVar4 + iVar2 + 0x28) = 0x18;
      local_30 = (byte)iVar14;
      *(ushort *)(iVar4 + iVar2 + 0x2a) = (ushort)local_30;
      *(ushort *)(iVar4 + iVar2 + 0x2c) = (ushort)iVar21 & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 0x2e) = 0x8327;
      *(undefined2 *)(iVar4 + iVar2 + 0x30) = 0x18;
      *(ushort *)(iVar4 + iVar2 + 0x32) = (ushort)iVar20 & 0xff;
      *(ushort *)(iVar4 + iVar2 + 0x34) = (ushort)iVar19 & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 0x36) = 0x83a7;
      *(undefined2 *)(iVar4 + iVar2 + 0x38) = 0x18;
      iVar16 = param_1[0x28];
      local_2c = (byte)iVar16;
      *(ushort *)(iVar4 + DAT_00055e34) = (ushort)local_2c;
      iVar2 = DAT_00055e38;
      iVar17 = param_1[0x31];
      *(ushort *)(iVar4 + DAT_00055e38) = (ushort)iVar17 & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 2) = 0x8427;
      *(undefined2 *)(iVar4 + iVar2 + 4) = 0x18;
      *(ushort *)(iVar4 + iVar2 + 6) = (ushort)((uint)iVar23 >> 8) & 0xff;
      *(ushort *)(iVar4 + iVar2 + 8) = (ushort)((uint)iVar22 >> 8) & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 10) = 0x8827;
      *(undefined2 *)(iVar4 + iVar2 + 0xc) = 0x18;
      *(ushort *)(iVar4 + iVar2 + 0xe) = (ushort)((uint)iVar25 >> 8) & 0xff;
      *(ushort *)(iVar4 + iVar2 + 0x10) = (ushort)((uint)iVar24 >> 8) & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 0x12) = 0x88a7;
      *(undefined2 *)(iVar4 + iVar2 + 0x14) = 0x18;
      *(ushort *)(iVar4 + iVar2 + 0x16) = (ushort)((uint)iVar6 >> 8) & 0xff;
      *(ushort *)(iVar4 + iVar2 + 0x18) = (ushort)((uint)iVar7 >> 8) & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 0x1a) = 0x8927;
      *(undefined2 *)(iVar4 + iVar2 + 0x1c) = 0x18;
      *(ushort *)(iVar4 + iVar2 + 0x1e) = (ushort)((uint)iVar8 >> 8) & 0xff;
      *(ushort *)(iVar4 + iVar2 + 0x20) = (ushort)((uint)iVar9 >> 8) & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 0x22) = 0x89a7;
      *(undefined2 *)(iVar4 + iVar2 + 0x24) = 0x18;
      *(ushort *)(iVar4 + iVar2 + 0x26) = (ushort)((uint)iVar10 >> 8) & 0xff;
      *(ushort *)(iVar4 + iVar2 + 0x28) = (ushort)((uint)iVar11 >> 8) & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 0x2a) = 0x8a27;
      *(undefined2 *)(iVar4 + iVar2 + 0x2c) = 0x18;
      *(ushort *)(iVar4 + iVar2 + 0x2e) = (ushort)((uint)iVar12 >> 8) & 0xff;
      *(ushort *)(iVar4 + iVar2 + 0x30) = (ushort)((uint)iVar13 >> 8) & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 0x32) = 0x8aa7;
      *(undefined2 *)(iVar4 + iVar2 + 0x34) = 0x18;
      *(ushort *)(iVar4 + iVar2 + 0x36) = (ushort)((uint)iVar14 >> 8) & 0xff;
      *(ushort *)(iVar4 + iVar2 + 0x38) = (ushort)((uint)iVar21 >> 8) & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 0x3a) = 0x8b27;
      *(undefined2 *)(iVar4 + iVar2 + 0x3c) = 0x18;
      *(ushort *)(iVar4 + iVar2 + 0x3e) = (ushort)((uint)iVar20 >> 8) & 0xff;
      *(ushort *)(iVar4 + iVar2 + 0x40) = (ushort)((uint)iVar19 >> 8) & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 0x42) = 0x8ba7;
      *(undefined2 *)(iVar4 + iVar2 + 0x44) = 0x18;
      *(ushort *)(iVar4 + iVar2 + 0x46) = (ushort)((uint)iVar16 >> 8) & 0xff;
      *(ushort *)(iVar4 + iVar2 + 0x48) = (ushort)((uint)iVar17 >> 8) & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 0x4a) = 0x8c27;
      *(undefined2 *)(iVar4 + iVar2 + 0x4c) = 0x18;
      *(ushort *)(iVar4 + iVar2 + 0x4e) = (ushort)((uint)iVar23 >> 0x10) & 0xff;
      *(ushort *)(iVar4 + iVar2 + 0x50) = (ushort)((uint)iVar22 >> 0x10) & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 0x52) = 0x9027;
      *(undefined2 *)(iVar4 + iVar2 + 0x54) = 0x18;
      *(ushort *)(iVar4 + iVar2 + 0x56) = (ushort)((uint)iVar25 >> 0x10) & 0xff;
      *(ushort *)(iVar4 + iVar2 + 0x58) = (ushort)((uint)iVar24 >> 0x10) & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 0x5a) = 0x90a7;
      *(undefined2 *)(iVar4 + iVar2 + 0x5c) = 0x18;
      *(ushort *)(iVar4 + iVar2 + 0x5e) = (ushort)((uint)iVar6 >> 0x10) & 0xff;
      *(ushort *)(iVar4 + iVar2 + 0x60) = (ushort)((uint)iVar7 >> 0x10) & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 0x62) = 0x9127;
      *(undefined2 *)(iVar4 + iVar2 + 100) = 0x18;
      *(ushort *)(iVar4 + iVar2 + 0x66) = (ushort)((uint)iVar8 >> 0x10) & 0xff;
      *(ushort *)(iVar4 + iVar2 + 0x68) = (ushort)((uint)iVar9 >> 0x10) & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 0x6a) = 0x91a7;
      *(undefined2 *)(iVar4 + iVar2 + 0x6c) = 0x18;
      *(ushort *)(iVar4 + iVar2 + 0x6e) = (ushort)((uint)iVar10 >> 0x10) & 0xff;
      *(ushort *)(iVar4 + iVar2 + 0x70) = (ushort)((uint)iVar11 >> 0x10) & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 0x72) = 0x9227;
      *(undefined2 *)(iVar4 + iVar2 + 0x74) = 0x18;
      *(ushort *)(iVar4 + iVar2 + 0x76) = (ushort)((uint)iVar12 >> 0x10) & 0xff;
      *(ushort *)(iVar4 + iVar2 + 0x78) = (ushort)((uint)iVar13 >> 0x10) & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 0x7a) = 0x92a7;
      *(undefined2 *)(iVar4 + iVar2 + 0x7c) = 0x18;
      *(ushort *)(iVar4 + iVar2 + 0x7e) = (ushort)((uint)iVar14 >> 0x10) & 0xff;
      *(ushort *)(iVar4 + iVar2 + 0x80) = (ushort)((uint)iVar21 >> 0x10) & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 0x82) = 0x9327;
      *(undefined2 *)(iVar4 + iVar2 + 0x84) = 0x18;
      *(ushort *)(iVar4 + iVar2 + 0x86) = (ushort)((uint)iVar20 >> 0x10) & 0xff;
      *(ushort *)(iVar4 + iVar2 + 0x88) = (ushort)((uint)iVar19 >> 0x10) & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 0x8a) = 0x93a7;
      *(undefined2 *)(iVar4 + iVar2 + 0x8c) = 0x18;
      *(ushort *)(iVar4 + iVar2 + 0x8e) = (ushort)((uint)iVar16 >> 0x10) & 0xff;
      *(ushort *)(iVar4 + iVar2 + 0x90) = (ushort)((uint)iVar17 >> 0x10) & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 0x92) = 0x9427;
      *(undefined2 *)(iVar4 + iVar2 + 0x94) = 0x18;
      *(ushort *)(iVar4 + iVar2 + 0x96) = (ushort)(byte)((uint)iVar23 >> 0x18);
      *(ushort *)(iVar4 + DAT_00056168) = (ushort)(byte)((uint)iVar22 >> 0x18);
      iVar22 = DAT_0005616c;
      *(undefined2 *)(iVar4 + DAT_0005616c) = 0x9827;
      *(undefined2 *)(iVar4 + iVar22 + 2) = 0x18;
      *(ushort *)(iVar4 + iVar22 + 4) = (ushort)(byte)((uint)iVar25 >> 0x18);
      *(ushort *)(iVar4 + DAT_00056170) = (ushort)(byte)((uint)iVar24 >> 0x18);
      iVar22 = DAT_00056174;
      *(undefined2 *)(iVar4 + DAT_00056174) = 0x98a7;
      *(undefined2 *)(iVar4 + iVar22 + 2) = 0x18;
      iVar22 = DAT_00056178;
      *(ushort *)(iVar4 + DAT_00056178) = (ushort)(byte)((uint)iVar6 >> 0x18);
      *(ushort *)(iVar4 + iVar22 + 2) = (ushort)(byte)((uint)iVar7 >> 0x18);
      iVar22 = DAT_0005617c;
      *(undefined2 *)(iVar4 + DAT_0005617c) = 0x9927;
      *(undefined2 *)(iVar4 + iVar22 + 2) = 0x18;
      iVar22 = DAT_00056180;
      *(ushort *)(iVar4 + DAT_00056180) = (ushort)(byte)((uint)iVar8 >> 0x18);
      *(ushort *)(iVar4 + iVar22 + 2) = (ushort)(byte)((uint)iVar9 >> 0x18);
      iVar22 = DAT_00056184;
      *(undefined2 *)(iVar4 + DAT_00056184) = 0x99a7;
      *(undefined2 *)(iVar4 + iVar22 + 2) = 0x18;
      iVar22 = DAT_00056188;
      *(ushort *)(iVar4 + DAT_00056188) = (ushort)(byte)((uint)iVar10 >> 0x18);
      *(ushort *)(iVar4 + iVar22 + 2) = (ushort)(byte)((uint)iVar11 >> 0x18);
      iVar22 = DAT_0005618c;
      *(undefined2 *)(iVar4 + DAT_0005618c) = 0x9a27;
      iVar23 = DAT_00056190;
      *(undefined2 *)(iVar4 + iVar22 + 2) = 0x18;
      *(ushort *)(iVar4 + iVar23) = (ushort)(byte)((uint)iVar12 >> 0x18);
      *(ushort *)(iVar4 + iVar23 + 2) = (ushort)(byte)((uint)iVar13 >> 0x18);
      iVar22 = DAT_00056194;
      *(undefined2 *)(iVar4 + DAT_00056194) = 0x9aa7;
      iVar23 = DAT_00056198;
      *(undefined2 *)(iVar4 + iVar22 + 2) = 0x18;
      *(ushort *)(iVar4 + iVar23) = (ushort)(byte)((uint)iVar14 >> 0x18);
      *(ushort *)(iVar4 + DAT_0005619c) = (ushort)(byte)((uint)iVar21 >> 0x18);
      iVar22 = DAT_00056148;
      *(undefined2 *)(iVar4 + DAT_00056148) = 0x9b27;
      *(undefined2 *)(iVar4 + iVar22 + 2) = 0x18;
      *(ushort *)(iVar4 + iVar22 + 4) = (ushort)(byte)((uint)iVar20 >> 0x18);
      *(ushort *)(iVar4 + DAT_0005614c) = (ushort)(byte)((uint)iVar19 >> 0x18);
      iVar22 = DAT_00056150;
      *(undefined2 *)(iVar4 + DAT_00056150) = 0x9ba7;
      *(undefined2 *)(iVar4 + iVar22 + 2) = 0x18;
      *(ushort *)(iVar4 + iVar22 + 4) = (ushort)(byte)((uint)iVar16 >> 0x18);
      *(ushort *)(iVar4 + DAT_00056154) = (ushort)(byte)((uint)iVar17 >> 0x18);
      iVar22 = DAT_00056158;
      *(undefined2 *)(iVar4 + DAT_00056158) = 0x9c27;
      *(undefined2 *)(iVar4 + iVar22 + 2) = 0x18;
      *DAT_0005615c = 1;
    }
  }
  FUN_0004f46c(param_1);
  return 1;
}

