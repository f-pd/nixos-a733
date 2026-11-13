// rea decompile_all
// name: FUN_0004f46c
// address: 0x4f46c
// body: available
// range: 0x4f46c-0x4f479 inclusive
// range: 0x59100-0x59403 inclusive
// range: 0x594cc-0x597a1 inclusive
// range: 0x59858-0x59afb inclusive
// range: 0x59b50-0x59cc3 inclusive
// range: 0x5a210-0x5a511 inclusive
// range: 0x5a5e4-0x5a8cb inclusive
// range: 0x5a9a0-0x5ac71 inclusive
// range: 0x5ad2c-0x5af47 inclusive
// range: 0x5af80-0x5b249 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_0004f46c(int param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  int iVar7;
  int iVar8;
  undefined2 uVar9;
  undefined2 *puVar10;
  undefined2 *puVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  undefined2 *puVar15;
  int iVar16;
  undefined2 *puVar17;
  undefined2 *puVar18;
  undefined2 *puVar19;
  int iVar20;
  uint uVar21;
  undefined2 auStack_48 [11];
  undefined2 local_32;
  
  if (*(int *)(param_1 + 4) == 8) {
    thunk_FUN_00047c40(auStack_48,0,0x20);
    local_32 = 0x1b00;
    iVar12 = *(int *)(param_1 + 4);
    *DAT_00059404 = 0;
    thunk_FUN_00048d80(1);
    iVar20 = DAT_0005940c;
    puVar11 = DAT_00059408;
    uVar21 = *(uint *)(param_1 + 0x1c);
    *DAT_00059408 = 0;
    puVar11[1] = 0;
    puVar11[2] = 0;
    puVar11[3] = 0;
    puVar11[4] = 0;
    puVar11[5] = 0;
    puVar11[6] = 0;
    puVar11[7] = 0;
    puVar17 = DAT_00059b3c;
    puVar10 = DAT_00059414;
    iVar8 = DAT_00059410;
    if ((uVar21 & 0x1000) == 0) {
      puVar11 = DAT_00059b38;
      do {
        puVar18 = puVar11 + 1;
        *puVar11 = *(undefined2 *)(((int)puVar11 + iVar8 & 0xfffffffeU) + iVar20 + 0xd1a);
        puVar10 = DAT_00059b4c;
        iVar7 = DAT_00059b48;
        iVar16 = DAT_00059b44;
        puVar11 = puVar18;
      } while (puVar18 != puVar17);
      puVar11 = DAT_00059b40;
      do {
        puVar17 = puVar11 + 1;
        *puVar11 = *(undefined2 *)(((int)puVar11 + iVar7 & 0xfffffffeU) + iVar16 + -0x1e);
        puVar11 = puVar17;
      } while (puVar17 != puVar10);
    }
    else {
      puVar11 = puVar11 + 0x188;
      do {
        puVar18 = puVar11 + 1;
        *puVar11 = *(undefined2 *)(iVar20 + ((int)puVar11 + iVar8 >> 1) * 2);
        puVar17 = DAT_00059420;
        iVar16 = DAT_0005941c;
        puVar11 = puVar18;
      } while (puVar18 != puVar10);
      puVar11 = DAT_00059418;
      do {
        puVar10 = puVar11 + 1;
        *puVar11 = *(undefined2 *)(((int)puVar11 + iVar16 & 0xfffffffeU) + iVar20 + 0x480);
        puVar11 = puVar10;
      } while (puVar10 != puVar17);
    }
    puVar17 = DAT_0005942c;
    puVar10 = DAT_00059428;
    puVar11 = DAT_00059424;
    *DAT_00059424 = 0x600;
    puVar11[-0x400cb] = 0;
    puVar11[-0x400c7] = 0x58;
    puVar11[-0x400c3] = 99;
    puVar19 = DAT_00059438;
    puVar18 = DAT_00059434;
    puVar11 = DAT_00059430;
    *DAT_00059430 = 0x1e;
    puVar11[1] = 0x1e;
    puVar15 = DAT_0005943c;
    puVar11 = puVar11 + 0x6dd;
    if ((uVar21 & 0x1000) == 0) {
      *puVar10 = 199;
      *puVar17 = 0xde;
      *puVar18 = 0x105;
      *puVar19 = 0x127;
      *puVar11 = 0x146;
      uVar9 = 0xe4;
    }
    else {
      *puVar10 = 0xcf;
      *puVar17 = 0xe6;
      *puVar18 = 0x10d;
      *puVar19 = 0x12f;
      *puVar11 = 0x14e;
      uVar9 = 0xec;
    }
    *puVar15 = uVar9;
    puVar10 = DAT_00059444;
    puVar11 = DAT_00059440;
    *DAT_00059440 = 0;
    puVar11[1] = 0;
    puVar11[2] = 0;
    puVar11[3] = 0;
    puVar11[-0x7057a] = 0;
    puVar17 = DAT_00059448;
    *DAT_00059448 = 1;
    puVar17[0x67] = 0xe;
    uVar13 = *(uint *)(param_1 + 0x78);
    uVar14 = uVar13 & 4;
    if (uVar14 == 0) {
      *puVar10 = 0x19;
      puVar11[-0x70578] = 0x26;
    }
    else {
      *puVar10 = 1;
      puVar11[-0x70578] = 0xe;
    }
    puVar10 = DAT_00059450;
    puVar11 = DAT_0005944c;
    *DAT_0005944c = 1;
    puVar17 = puVar11 + 0x68;
    puVar11[0x67] = 0xe;
    if (uVar14 == 0) {
      *puVar10 = 0x19;
      *puVar17 = 0x26;
    }
    else {
      *puVar10 = 1;
      *puVar17 = 0xe;
    }
    puVar10 = DAT_00059458;
    puVar11 = DAT_00059454;
    *DAT_00059454 = 0xf;
    puVar17 = puVar11 + 0x68;
    puVar11[0x67] = 0x13;
    if (uVar14 == 0) {
      *puVar10 = 0x27;
      *puVar17 = 0x2b;
    }
    else {
      *puVar10 = 0xf;
      *puVar17 = 0x13;
    }
    puVar10 = DAT_00059460;
    puVar11 = DAT_0005945c;
    *DAT_0005945c = 0xf;
    puVar17 = puVar11 + 0x68;
    puVar11[0x67] = 0x13;
    if (uVar14 == 0) {
      *puVar10 = 0x27;
      *puVar17 = 0x2b;
    }
    else {
      *puVar10 = 0xf;
      *puVar17 = 0x13;
    }
    puVar10 = DAT_00059468;
    puVar11 = DAT_00059464;
    *DAT_00059464 = 0x14;
    puVar17 = puVar11 + 0x68;
    puVar11[0x67] = 0x18;
    if (uVar14 == 0) {
      *puVar10 = 0x2c;
      *puVar17 = 0x30;
    }
    else {
      *puVar10 = 0x14;
      *puVar17 = 0x18;
    }
    puVar10 = DAT_00059470;
    puVar11 = DAT_0005946c;
    *DAT_0005946c = 0x14;
    puVar17 = puVar11 + 0x68;
    puVar11[0x67] = 0x18;
    if (uVar14 == 0) {
      *puVar10 = 0x2c;
      *puVar17 = 0x30;
    }
    else {
      *puVar10 = 0x14;
      *puVar17 = 0x18;
    }
    puVar2 = DAT_000594b8;
    puVar10 = DAT_00059478;
    puVar11 = DAT_00059474;
    *DAT_00059474 = 0x31;
    puVar11[0x67] = 0x30;
    puVar11[1] = 0x33;
    *puVar10 = 0x32;
    puVar10[-0x66] = 0x31;
    puVar10[1] = 0x30;
    puVar4 = DAT_000594c0;
    puVar3 = DAT_000594bc;
    puVar11 = DAT_0005947c;
    *DAT_0005947c = 0x33;
    puVar11[0x67] = 0x32;
    puVar11[1] = 0x31;
    puVar11[0x68] = 0x31;
    puVar11[2] = 0x33;
    puVar11[0x69] = 0x33;
    puVar11[3] = 0x31;
    puVar11[0x6a] = 0x31;
    puVar6 = DAT_000594c8;
    puVar5 = DAT_000594c4;
    puVar17 = DAT_00059480;
    *DAT_00059480 = 0x33;
    puVar17[0x67] = 0x33;
    puVar15 = DAT_0005948c;
    puVar19 = DAT_00059488;
    puVar18 = DAT_00059484;
    *DAT_00059484 = 0x32;
    puVar18[0x67] = 0x32;
    puVar17[2] = 0x34;
    puVar17[0x69] = 0x34;
    puVar17[3] = 0x32;
    puVar17[0x6a] = 0x32;
    puVar1 = DAT_00059494;
    puVar18 = DAT_00059490;
    *DAT_00059490 = 0x34;
    puVar18[0x67] = 0x34;
    puVar18 = DAT_00059498;
    *DAT_00059498 = 0x35;
    puVar18[0x67] = 0x35;
    puVar18[1] = 0x35;
    puVar18[0x68] = 0x35;
    puVar18[2] = 0x35;
    puVar18[0x69] = 0x35;
    puVar18[3] = 0x35;
    puVar18[0x6a] = 0x35;
    puVar18 = DAT_0005949c;
    *DAT_0005949c = 0x36;
    puVar18[0x67] = 0x36;
    puVar18[1] = 0x36;
    puVar18[0x68] = 0x36;
    puVar18[2] = 0x36;
    puVar18[0x69] = 0x36;
    puVar18[3] = 0x36;
    puVar18[0x6a] = 0x36;
    puVar17[0xd] = 0x37;
    puVar17[0x74] = 0x36;
    puVar17[0xe] = 0x37;
    puVar17[0x75] = 0x36;
    puVar17[0xf] = 0x37;
    puVar17[0x76] = 0x36;
    puVar17[0x10] = 0x37;
    puVar17[0x77] = 0x36;
    *DAT_000594a0 = 0x37;
    puVar18 = DAT_00059cc4;
    puVar17 = DAT_000594a4;
    if ((uVar21 & 0x1000) == 0) {
      *puVar2 = 0x4a;
      *puVar3 = 0x37;
      *puVar4 = 0x4a;
      *puVar5 = 0x37;
      *puVar6 = 0x4a;
      *puVar18 = 0x37;
      *puVar19 = 0x4a;
      *puVar15 = 0x4b;
      *puVar1 = 0x4a;
      puVar10[-0x4b] = 0x4b;
      puVar18[0x69] = 0x4a;
      puVar18[3] = 0x4b;
      puVar18[0x6a] = 0x4a;
      puVar18[4] = 0x4b;
      puVar18[0x6b] = 0x4a;
      *DAT_00059cc8 = 0x4b;
      puVar18[0x6c] = 0x51;
      puVar18[6] = 0x4b;
      puVar18[0x6d] = 0x51;
      puVar18[7] = 0x4b;
      puVar18[0x6e] = 0x51;
      puVar18[8] = 0x4b;
      *DAT_00059ccc = 0x51;
      *DAT_00059cd0 = 0x52;
      puVar18[0x70] = 0x56;
      puVar18[10] = 0x52;
      puVar18[0x71] = 0x56;
      puVar18[0xb] = 0x52;
      puVar18[0x72] = 0x56;
      puVar18[0xc] = 0x52;
      *DAT_00059cd4 = 0x56;
      *DAT_00059cd8 = 0x57;
      puVar18[0x74] = 0x5c;
      puVar18[0xe] = 0x57;
      puVar18[0x75] = 0x5c;
      puVar18[0xf] = 0x57;
      puVar18[0x76] = 0x5c;
      puVar18[0x10] = 0x57;
      *DAT_00059cdc = 0x5c;
      *DAT_00059ce0 = 0x5d;
      puVar18[0x78] = 0x62;
      puVar18[0x12] = 0x5d;
      puVar18[0x79] = 0x62;
      puVar18[0x13] = 0x5d;
      puVar18[0x7a] = 0x62;
      puVar18[0x14] = 0x5d;
      *DAT_00059ce4 = 0x62;
      *DAT_00059ce8 = 99;
      puVar18[0x7c] = 0x67;
      puVar18[0x16] = 99;
      puVar18[0x7d] = 0x67;
      puVar18[0x17] = 99;
      puVar18[0x7e] = 0x67;
      puVar18[0x18] = 99;
      *DAT_00059cec = 0x67;
      puVar18[0x19] = 0x68;
      puVar18[0x80] = 0x67;
      puVar18[0x1a] = 0x68;
      puVar18[0x81] = 0x67;
      puVar18[0x1b] = 0x68;
      puVar18[0x82] = 0x67;
      puVar18[0x1c] = 0x68;
      puVar18[0x83] = 0x67;
      *DAT_00059cf0 = 0x68;
      puVar18[0x84] = 0x6c;
      puVar18[0x1e] = 0x68;
      puVar18[0x85] = 0x6c;
      puVar18[0x1f] = 0x68;
      puVar18[0x86] = 0x6c;
      puVar18[0x20] = 0x68;
      puVar11 = DAT_00059cf4;
      *DAT_00059cf4 = 0x6c;
      puVar11[0x210f1] = 0x4b00;
      puVar11[0x210f5] = 0;
      puVar18[0x21190] = 0x7b00;
      puVar18[0x21194] = 0;
      puVar18[0x211a8] = 0x4b00;
      puVar11 = DAT_00059cf8;
      *DAT_00059cf8 = 0;
      puVar11[0x14] = 0x7b00;
      *DAT_00059cfc = 0;
    }
    else {
      *puVar2 = 0x49;
      *puVar3 = 0x37;
      *puVar4 = 0x49;
      *puVar5 = 0x37;
      *puVar6 = 0x49;
      *puVar17 = 0x37;
      *puVar19 = 0x49;
      *puVar15 = 0x4a;
      *puVar1 = 0x4f;
      puVar10[-0x4b] = 0x4a;
      puVar17[0x69] = 0x4f;
      puVar17[3] = 0x4a;
      puVar17[0x6a] = 0x4f;
      puVar17[4] = 0x4a;
      *DAT_000594a8 = 0x4f;
      *DAT_000594ac = 0x50;
      puVar17[0x6c] = 0x59;
      puVar17[6] = 0x50;
      puVar17[0x6d] = 0x59;
      puVar17[7] = 0x50;
      puVar17[0x6e] = 0x59;
      puVar17[8] = 0x50;
      *DAT_000594b0 = 0x59;
      *DAT_000594b4 = 0x5a;
      puVar17[0x70] = 0x62;
      puVar17[10] = 0x5a;
      puVar17[0x71] = 0x62;
      puVar17[0xb] = 0x5a;
      puVar17[0x72] = 0x62;
      puVar17[0xc] = 0x5a;
      *DAT_000597a4 = 0x62;
      *DAT_000597a8 = 99;
      puVar17[0x74] = 0x68;
      puVar17[0xe] = 99;
      puVar17[0x75] = 0x68;
      puVar17[0xf] = 99;
      puVar17[0x76] = 0x68;
      puVar17[0x10] = 99;
      *DAT_000597ac = 0x68;
      *DAT_000597b0 = 0x69;
      puVar17[0x78] = 0x6e;
      puVar17[0x12] = 0x69;
      puVar17[0x79] = 0x6e;
      puVar17[0x13] = 0x69;
      puVar17[0x7a] = 0x6e;
      puVar17[0x14] = 0x69;
      *DAT_000597b4 = 0x6e;
      *DAT_000597b8 = 0x6f;
      puVar17[0x7c] = 0x73;
      puVar17[0x16] = 0x6f;
      puVar17[0x7d] = 0x73;
      puVar17[0x17] = 0x6f;
      puVar17[0x7e] = 0x73;
      puVar17[0x18] = 0x6f;
      *DAT_000597bc = 0x73;
      puVar17[0x19] = 0x74;
      puVar17[0x80] = 0x73;
      puVar17[0x1a] = 0x74;
      puVar17[0x81] = 0x73;
      puVar17[0x1b] = 0x74;
      puVar17[0x82] = 0x73;
      puVar17[0x1c] = 0x74;
      puVar17[0x83] = 0x73;
      *DAT_000597c0 = 0x74;
      puVar17[0x84] = 0x78;
      puVar17[0x1e] = 0x74;
      puVar17[0x85] = 0x78;
      puVar17[0x1f] = 0x74;
      puVar17[0x86] = 0x78;
      puVar17[0x20] = 0x74;
      puVar10 = DAT_000597c4;
      *DAT_000597c4 = 0x78;
      puVar17 = DAT_000597c8;
      puVar10[0x21151] = 0x4b00;
      *puVar17 = 0;
      puVar11[0x21208] = 0x7b00;
      puVar11[0x2120c] = 0;
      puVar11[0x21220] = 0x4b00;
      puVar11 = DAT_000597cc;
      *DAT_000597cc = 0;
      puVar11[0x14] = 0x7b00;
      *DAT_000597d0 = 0;
    }
    iVar20 = DAT_000597dc;
    puVar10 = DAT_000597d8;
    puVar11 = DAT_000597d4;
    if (iVar12 == 8) {
      puVar17 = DAT_000597d4;
      do {
        puVar19 = puVar17 + 1;
        *puVar17 = *(undefined2 *)((int)auStack_48 + ((int)puVar17 + iVar20 & 0xfffffffeU));
        iVar8 = DAT_000597e4;
        puVar18 = DAT_000597e0;
        puVar17 = puVar19;
      } while (puVar19 != puVar10);
      *DAT_000597e0 = 0xd800;
      uVar14 = uVar21 & 0x1000;
      if (uVar14 == 0) {
        *puVar11 = 0x2066;
        uVar9 = 0x1e01;
        puVar11 = DAT_000597e8;
      }
      else {
        *puVar11 = 0x20e6;
        uVar9 = 0x1e03;
        puVar11 = DAT_000597e8;
      }
      DAT_000597e8 = puVar11;
      puVar18[1] = uVar9;
      do {
        puVar18 = puVar19 + 1;
        *puVar19 = *(undefined2 *)((int)auStack_48 + ((int)puVar19 + iVar8 & 0xfffffffeU));
        puVar17 = DAT_000597ec;
        puVar19 = puVar18;
      } while (puVar18 != puVar11);
      *DAT_000597ec = 0x5800;
      if (uVar14 == 0) {
        *puVar10 = 0x4046;
        uVar9 = 0x1f81;
      }
      else {
        *puVar10 = 0x40c6;
        uVar9 = 0x1f83;
      }
      iVar20 = DAT_000597f4;
      puVar10 = DAT_000597f0;
      puVar17[1] = uVar9;
      do {
        puVar19 = puVar18 + 1;
        *puVar18 = *(undefined2 *)((int)auStack_48 + ((int)puVar18 + iVar20 & 0xfffffffeU));
        puVar17 = DAT_000597f8;
        puVar18 = puVar19;
      } while (puVar19 != puVar10);
      *DAT_000597f8 = 0x5800;
      if (uVar14 == 0) {
        *puVar11 = 0x6046;
        uVar9 = 0x1981;
      }
      else {
        *puVar11 = 0x60c6;
        uVar9 = 0x1983;
      }
      puVar17[1] = uVar9;
      iVar20 = DAT_00059800;
      puVar11 = DAT_000597fc;
      do {
        puVar15 = puVar19 + 1;
        *puVar19 = *(undefined2 *)((int)auStack_48 + ((int)puVar19 + iVar20 & 0xfffffffeU));
        puVar18 = DAT_00059808;
        puVar17 = DAT_00059804;
        puVar19 = puVar15;
      } while (puVar15 != puVar11);
      if (uVar14 == 0) {
        *puVar10 = 0x6046;
        *puVar17 = 0x5801;
        uVar9 = 0x201;
      }
      else {
        *puVar10 = 0x60c6;
        *puVar17 = 0x5801;
        uVar9 = 0x203;
      }
      *puVar18 = uVar9;
      *puVar11 = 0xc046;
      puVar10 = DAT_00059814;
      iVar20 = DAT_00059810;
      puVar11 = DAT_0005980c;
      *DAT_0005980c = 0x5802;
      puVar11[1] = 0x1201;
      puVar11 = DAT_00059818;
      *DAT_00059818 = 0;
      puVar11[1] = 0;
      puVar11[2] = 0;
      puVar11[3] = 0;
      puVar11[4] = 0;
      puVar11 = DAT_0005981c;
      puVar17 = DAT_0005981c;
      do {
        puVar15 = puVar17 + 1;
        *puVar17 = *(undefined2 *)((int)auStack_48 + ((int)puVar17 + iVar20 & 0xfffffffeU));
        puVar19 = DAT_00059824;
        puVar18 = DAT_00059820;
        puVar17 = puVar15;
      } while (puVar15 != puVar10);
      if (uVar14 == 0) {
        *puVar11 = 0xc006;
        *puVar18 = 0x5802;
        uVar9 = 0x1200;
      }
      else {
        *puVar11 = 0xc086;
        *puVar18 = 0x5802;
        uVar9 = 0x1202;
      }
      *puVar19 = uVar9;
      puVar11 = DAT_00059828;
      do {
        puVar10 = puVar15 + 1;
        *puVar15 = 0;
        puVar15 = puVar10;
      } while (puVar10 != puVar11);
    }
    puVar10 = DAT_00059830;
    puVar11 = DAT_0005982c;
    *DAT_0005982c = 0x5061;
    puVar11[1] = 0x7098;
    puVar11 = DAT_00059834;
    *DAT_00059834 = 0;
    puVar11[-3] = 0xbedc;
    puVar11[3] = 0xb0db;
    puVar11[4] = 0;
    puVar11[-0x2f8f7] = 0;
    puVar11 = DAT_00059838;
    *DAT_00059838 = 0x7ff;
    puVar11[1] = 0x668;
    puVar11[2] = 0x7910;
    puVar11[3] = 0x355e;
    puVar11[4] = 0xcbb5;
    puVar11 = DAT_00059840;
    if ((uVar13 & 4) == 0) {
      *DAT_0005983c = 0xffff;
      uVar9 = 0x710;
    }
    else {
      *DAT_0005983c = 0x710;
      uVar9 = 0xffff;
    }
    *puVar11 = uVar9;
    *DAT_00059844 = 0x7800;
    puVar11 = DAT_00059848;
    *DAT_00059848 = 0xffff;
    puVar11[2] = 0xff10;
    puVar11[-0x4fe] = 0x2ee8;
    puVar11[1] = 0xffff;
    puVar11 = DAT_00059850;
    *DAT_0005984c = 0xffdf;
    puVar17 = DAT_00059854;
    *DAT_00059854 = 0x6f10;
    *puVar11 = 0x6f10;
    puVar17[2] = 0x2868;
    puVar17[3] = 0x2868;
    *DAT_00059afc = 0xfeef;
    puVar17 = DAT_00059b00;
    *DAT_00059b00 = 0xe400;
    puVar17[0x82] = 0xe400;
    puVar17[0x1c] = 0;
    puVar17[0x1d] = 0;
    puVar17[0x1e] = 0;
    puVar17[0x1f] = 0;
    *puVar10 = 0xff00;
    puVar10[1] = 0xff00;
    puVar10[2] = 0xff00;
    puVar10[3] = 0xff00;
    puVar10[0xc] = 0x4000;
    puVar10[0xd] = 0x2000;
    puVar10[0xe] = 0xff00;
    puVar10[0xf] = 0xff00;
    puVar17 = DAT_00059b08;
    puVar10 = DAT_00059b04;
    *DAT_00059b04 = 0;
    puVar10[2] = 0;
    if ((uVar21 & 0x1000) == 0) {
      *DAT_00059b0c = 0;
    }
    else {
      *DAT_00059b0c = 1;
    }
    *puVar11 = 0xffff;
    *DAT_00059b10 = 0x27f7;
    puVar11 = DAT_00059b14;
    *DAT_00059b14 = 0x2108;
    puVar11[1] = 0x2108;
    puVar11[-0x10038] = 1;
    puVar11[-0x10040] = 0x180;
    puVar11[-0x10037] = 1;
    *puVar17 = 0;
    puVar17[0x13] = 1;
    puVar17[0x1017] = 1;
    puVar17[0x100f] = 0x180;
    puVar17[0x1018] = 1;
    puVar17[0x1000] = 0;
    puVar17[0x1013] = 1;
    puVar17[0x2017] = 1;
    puVar17[0x200f] = 0x180;
    puVar17[0x2018] = 1;
    puVar17[0x2000] = 0;
    puVar17[0x2013] = 1;
    puVar17[0x3017] = 1;
    puVar17[0x300f] = 0x180;
    puVar11 = DAT_00059b18;
    *DAT_00059b18 = 1;
    puVar11[-0x18] = 0;
    puVar10 = DAT_00059b1c;
    *DAT_00059b1c = 1;
    puVar10[0x5cf6f] = 0x5a3c;
    puVar10[0x5cf70] = 0x5a3c;
    puVar10[0x5cf71] = 0x5a3c;
    puVar10[0x5cf72] = 0x5a3c;
    puVar10[0x5cf73] = 0x5a3c;
    puVar10[0x5cf74] = 0x5a3c;
    puVar10[0x5cf75] = 0x5a3c;
    puVar10[0x5cf76] = 0x5a3c;
    puVar10[0x5d06f] = 0x5a3c;
    puVar10[0x5d070] = 0x5a3c;
    puVar10[0x5d071] = 0x5a3c;
    puVar10[0x5d072] = 0x5a3c;
    puVar10[0x5d073] = 0x5a3c;
    puVar10[0x5d074] = 0x5a3c;
    puVar10[0x5d075] = 0x5a3c;
    puVar10[0x5d076] = 0x5a3c;
    puVar10[0x5d16f] = 0x5a3c;
    puVar10[0x5d170] = 0x5a3c;
    puVar10[0x5d171] = 0x5a3c;
    puVar10[0x5d172] = 0x5a3c;
    puVar10[0x5d173] = 0x5a3c;
    puVar10[0x5d174] = 0x5a3c;
    puVar10[0x5d175] = 0x5a3c;
    puVar10[0x5d176] = 0x5a3c;
    puVar10[0x5d26f] = 0x5a3c;
    puVar10[0x5d270] = 0x5a3c;
    puVar10[0x5d271] = 0x5a3c;
    puVar10[0x5d272] = 0x5a3c;
    puVar10[0x5d273] = 0x5a3c;
    puVar10[0x5d274] = 0x5a3c;
    puVar10[0x5d275] = 0x5a3c;
    puVar10[0x5d276] = 0x5a3c;
    puVar10[0x5d36f] = 0x5a3c;
    puVar10[0x5d370] = 0x5a3c;
    puVar10[0x5d371] = 0x5a3c;
    puVar10[0x5d372] = 0x5a3c;
    puVar10[0x5d373] = 0x5a3c;
    puVar10[0x5d374] = 0x5a3c;
    puVar10[0x5d375] = 0x5a3c;
    puVar10[0x5d376] = 0x5a3c;
    puVar10[0x5d46f] = 0x5a3c;
    puVar10[0x5d470] = 0x5a3c;
    puVar10[0x5d471] = 0x5a3c;
    puVar10[0x5d472] = 0x5a3c;
    puVar10[0x5d473] = 0x5a3c;
    puVar10[0x5d474] = 0x5a3c;
    puVar10[0x5d475] = 0x5a3c;
    puVar10[0x5d476] = 0x5a3c;
    puVar10[0x5d56f] = 0x5a3c;
    puVar10[0x5d570] = 0x5a3c;
    puVar10[0x5d571] = 0x5a3c;
    puVar10[0x5d572] = 0x5a3c;
    puVar10[0x5d573] = 0x5a3c;
    puVar10[0x5d574] = 0x5a3c;
    puVar10[0x5d575] = 0x5a3c;
    puVar10[0x5d576] = 0x5a3c;
    puVar10[0x5d66f] = 0x5a3c;
    puVar10[0x5d670] = 0x5a3c;
    puVar10[0x5d671] = 0x5a3c;
    puVar10[0x5d672] = 0x5a3c;
    puVar10[0x5d673] = 0x5a3c;
    puVar10[0x5d674] = 0x5a3c;
    puVar10[0x5d675] = 0x5a3c;
    puVar10[0x5d676] = 0x5a3c;
    puVar10[0x5d76f] = 0x5a3c;
    puVar10[0x5d770] = 0x5a3c;
    puVar10[0x5d771] = 0x5a3c;
    puVar10[0x5d772] = 0x5a3c;
    puVar10[0x5d773] = 0x5a3c;
    puVar10[0x5d774] = 0x5a3c;
    puVar10[0x5d775] = 0x5a3c;
    puVar10[0x5d776] = 0x5a3c;
    puVar10 = DAT_00059b20;
    *DAT_00059b20 = 0x1ff;
    if ((uVar21 & 0x1000) == 0) {
      uVar9 = 0x44;
    }
    else {
      uVar9 = 0xcc;
    }
    puVar11[0xcfc0] = uVar9;
    puVar10[-0x4ffe7] = uVar9;
    puVar10 = DAT_00059b28;
    puVar11 = DAT_00059b24;
    *DAT_00059b24 = 2;
    puVar11[199] = 0xffff;
    puVar17 = DAT_00059b2c;
    puVar11[0x708e8] = 2;
    *puVar17 = 1;
    puVar17[1] = 1;
    puVar11 = DAT_00059b30;
    *DAT_00059b30 = 2;
    *puVar10 = 0;
    *puVar11 = 0;
    *DAT_00059b34 = 1;
    return;
  }
  thunk_FUN_00047c40(auStack_48,0,0x20);
  local_32 = 0x2b00;
  iVar16 = *(int *)(param_1 + 4);
  *DAT_0005a514 = 0;
  thunk_FUN_00048d80(1);
  iVar20 = DAT_0005a51c;
  puVar11 = DAT_0005a518;
  uVar21 = *(uint *)(param_1 + 0x1c);
  *DAT_0005a518 = 0;
  puVar11[1] = 0;
  puVar11[2] = 0;
  puVar11[3] = 0;
  puVar11[4] = 0;
  puVar11[5] = 0;
  puVar11[6] = 0;
  puVar11[7] = 0;
  puVar17 = DAT_0005af6c;
  iVar12 = DAT_0005af68;
  puVar10 = DAT_0005a524;
  iVar8 = DAT_0005a520;
  if ((uVar21 & 0x1000) == 0) {
    puVar11 = DAT_0005af64;
    do {
      puVar18 = puVar11 + 1;
      *puVar11 = *(undefined2 *)(((int)puVar11 + iVar20 & 0xfffffffeU) + iVar12 + 0xa14);
      puVar10 = DAT_0005af7c;
      iVar7 = DAT_0005af78;
      iVar8 = DAT_0005af74;
      puVar11 = puVar18;
    } while (puVar18 != puVar17);
    puVar11 = DAT_0005af70;
    do {
      puVar17 = puVar11 + 1;
      *puVar11 = *(undefined2 *)(((int)puVar11 + iVar7 & 0xfffffffeU) + iVar8 + 0x78c);
      puVar11 = puVar17;
    } while (puVar17 != puVar10);
  }
  else {
    puVar11 = puVar11 + 0x388;
    do {
      puVar18 = puVar11 + 1;
      *puVar11 = *(undefined2 *)(iVar8 + ((int)puVar11 + iVar20 >> 1) * 2);
      puVar17 = DAT_0005a534;
      iVar7 = DAT_0005a530;
      iVar12 = DAT_0005a52c;
      puVar11 = puVar18;
    } while (puVar18 != puVar10);
    puVar11 = DAT_0005a528;
    do {
      puVar10 = puVar11 + 1;
      *puVar11 = *(undefined2 *)(iVar12 + ((int)puVar11 + iVar7 >> 1) * 2);
      puVar11 = puVar10;
    } while (puVar10 != puVar17);
  }
  puVar17 = DAT_0005a540;
  puVar10 = DAT_0005a53c;
  puVar11 = DAT_0005a538;
  *DAT_0005a538 = 0x600;
  puVar11[-0x400cb] = 0;
  puVar11[-0x400c7] = 0x77;
  puVar11[-0x400c3] = 0x82;
  puVar19 = DAT_0005a54c;
  puVar18 = DAT_0005a548;
  puVar11 = DAT_0005a544;
  *DAT_0005a544 = 0x2b;
  puVar11[1] = 0x2b;
  puVar15 = DAT_0005a550;
  puVar11 = puVar11 + 0x6dd;
  if ((uVar21 & 0x1000) == 0) {
    *puVar10 = 0x106;
    *puVar17 = 0x11d;
    *puVar18 = 0x144;
    *puVar19 = 0x166;
    *puVar11 = 0x185;
    uVar9 = 0x123;
  }
  else {
    *puVar10 = 0x10e;
    *puVar17 = 0x125;
    *puVar18 = 0x14c;
    *puVar19 = 0x16e;
    *puVar11 = 0x18d;
    uVar9 = 299;
  }
  *puVar15 = uVar9;
  puVar10 = DAT_0005a558;
  puVar11 = DAT_0005a554;
  *DAT_0005a554 = 0;
  puVar11[1] = 0;
  puVar11[2] = 0;
  puVar11[3] = 0;
  puVar11[-0x7057a] = 0;
  puVar17 = DAT_0005a55c;
  *DAT_0005a55c = 1;
  puVar17[0x67] = 0x16;
  uVar13 = *(uint *)(param_1 + 0x78);
  uVar14 = uVar13 & 4;
  if (uVar14 == 0) {
    *puVar10 = 0x39;
    puVar11[-0x70578] = 0x4e;
  }
  else {
    *puVar10 = 1;
    puVar11[-0x70578] = 0x16;
  }
  puVar10 = DAT_0005a564;
  puVar11 = DAT_0005a560;
  *DAT_0005a560 = 1;
  puVar17 = puVar11 + 0x68;
  puVar11[0x67] = 0x16;
  if (uVar14 == 0) {
    *puVar10 = 0x39;
    *puVar17 = 0x4e;
  }
  else {
    *puVar10 = 1;
    *puVar17 = 0x16;
  }
  puVar10 = DAT_0005a56c;
  puVar11 = DAT_0005a568;
  *DAT_0005a568 = 0x17;
  puVar17 = puVar11 + 0x68;
  puVar11[0x67] = 0x27;
  if (uVar14 == 0) {
    *puVar10 = 0x4f;
    *puVar17 = 0x5f;
  }
  else {
    *puVar10 = 0x17;
    *puVar17 = 0x27;
  }
  puVar10 = DAT_0005a574;
  puVar11 = DAT_0005a570;
  *DAT_0005a570 = 0x17;
  puVar17 = puVar11 + 0x68;
  puVar11[0x67] = 0x27;
  if (uVar14 == 0) {
    *puVar10 = 0x4f;
    *puVar17 = 0x5f;
  }
  else {
    *puVar10 = 0x17;
    *puVar17 = 0x27;
  }
  puVar10 = DAT_0005a57c;
  puVar11 = DAT_0005a578;
  *DAT_0005a578 = 0x28;
  puVar17 = puVar11 + 0x68;
  puVar11[0x67] = 0x38;
  if (uVar14 == 0) {
    *puVar10 = 0x60;
    *puVar17 = 0x70;
  }
  else {
    *puVar10 = 0x28;
    *puVar17 = 0x38;
  }
  puVar10 = DAT_0005a584;
  puVar11 = DAT_0005a580;
  *DAT_0005a580 = 0x28;
  puVar17 = puVar11 + 0x68;
  puVar11[0x67] = 0x38;
  if (uVar14 == 0) {
    *puVar10 = 0x60;
    *puVar17 = 0x70;
  }
  else {
    *puVar10 = 0x28;
    *puVar17 = 0x38;
  }
  puVar10 = DAT_0005a58c;
  puVar11 = DAT_0005a588;
  *DAT_0005a588 = 0x80;
  puVar11[0x67] = 0x80;
  puVar11[1] = 0x80;
  puVar11[0x68] = 0x80;
  puVar11[2] = 0x80;
  puVar11[0x69] = 0x80;
  puVar11[3] = 0x80;
  puVar11[0x6a] = 0x80;
  puVar11[4] = 0x71;
  puVar11[0x6b] = 0x74;
  puVar11[5] = 0x77;
  *puVar10 = 0x7a;
  puVar10[-0x66] = 0x71;
  puVar2 = DAT_0005a5dc;
  puVar1 = DAT_0005a5d8;
  *DAT_0005a590 = 0x74;
  puVar3 = DAT_0005a5e0;
  puVar11 = DAT_0005a598;
  *DAT_0005a594 = 0x77;
  puVar17 = DAT_0005a5a0;
  *DAT_0005a59c = 0x7a;
  puVar18 = DAT_0005a5a4;
  *DAT_0005a5a4 = 0x75;
  puVar18[0x67] = 0x76;
  puVar18[1] = 0x7b;
  puVar10[4] = 0x7c;
  puVar10[-0x62] = 0x75;
  puVar18 = DAT_0005a5a8;
  *DAT_0005a5a8 = 0x76;
  puVar19 = DAT_0005a5ac;
  *DAT_0005a5ac = 0x7b;
  *DAT_0005a5b0 = 0x7c;
  *DAT_0005a5b4 = 0x7d;
  puVar19[0x68] = 0x7e;
  puVar19[2] = 0x7d;
  puVar19[0x69] = 0x7e;
  puVar19[3] = 0x7d;
  puVar19[0x6a] = 0x7e;
  puVar19[4] = 0x7d;
  puVar19 = DAT_0005a5b8;
  *DAT_0005a5b8 = 0x7e;
  puVar19[-0x66] = 0x7f;
  puVar19[1] = 0x7f;
  puVar19[-0x65] = 0x7f;
  puVar19[2] = 0x7f;
  puVar19[-100] = 0x7f;
  puVar19[3] = 0x7f;
  puVar19[-99] = 0x7f;
  puVar19[4] = 0x7f;
  puVar19[-0x62] = 0x80;
  puVar19[5] = 0x7f;
  puVar19[-0x61] = 0x80;
  puVar19[6] = 0x7f;
  puVar19[-0x60] = 0x80;
  puVar19[7] = 0x7f;
  puVar19[-0x5f] = 0x80;
  puVar19 = DAT_0005a5bc;
  *DAT_0005a5bc = 0x7f;
  puVar19[-0x66] = 0x81;
  puVar19[1] = 0x93;
  puVar19[-0x65] = 0x81;
  *DAT_0005a5c0 = 0x93;
  puVar4 = DAT_0005b24c;
  puVar15 = DAT_0005a5c4;
  if ((uVar21 & 0x1000) == 0) {
    puVar19[-100] = 0xef;
    *puVar1 = 0x100;
    *puVar4 = 0xef;
    *puVar2 = 0x100;
    *puVar3 = 0x94;
    puVar4[0x68] = 0x93;
    *puVar11 = 0x94;
    *puVar17 = 0x93;
    puVar10[-0x4e] = 0x101;
    puVar18[0x14] = 0x100;
    puVar4[4] = 0x101;
    puVar4[0x6b] = 0x100;
    puVar11 = DAT_0005b254;
    *DAT_0005b250 = 0x94;
    puVar4[0x6c] = 0x9e;
    puVar4[6] = 0x94;
    puVar4[0x6d] = 0x9e;
    *DAT_0005b258 = 0x101;
    puVar4[0x6e] = 0x109;
    puVar4[8] = 0x101;
    puVar10 = DAT_0005b25c;
    *DAT_0005b25c = 0x109;
    puVar10[-0x66] = 0x9f;
    puVar4[0x70] = 0xa5;
    puVar4[10] = 0x9f;
    *DAT_0005b260 = 0xa5;
    *DAT_0005b264 = 0x10a;
    puVar4[0x72] = 0x110;
    puVar4[0xc] = 0x10a;
    *DAT_0005b268 = 0x110;
    *DAT_0005b26c = 0xa6;
    puVar4[0x74] = 0xaf;
    puVar4[0xe] = 0xa6;
    *DAT_0005b270 = 0xaf;
    *DAT_0005b274 = 0x111;
    puVar4[0x76] = 0x11a;
    puVar4[0x10] = 0x111;
    *DAT_0005b278 = 0x11a;
    *DAT_0005b27c = 0xb0;
    puVar4[0x78] = 0xb9;
    puVar4[0x12] = 0xb0;
    *DAT_0005b280 = 0xb9;
    *DAT_0005b284 = 0x11b;
    puVar4[0x7a] = 0x124;
    puVar4[0x14] = 0x11b;
    *DAT_0005b288 = 0x124;
    *DAT_0005b28c = 0xba;
    puVar4[0x7c] = 0xc4;
    puVar4[0x16] = 0xba;
    *DAT_0005b290 = 0xc4;
    *DAT_0005b294 = 0x125;
    puVar4[0x7e] = 0x12e;
    puVar4[0x18] = 0x125;
    *DAT_0005b298 = 0x12e;
    *DAT_0005b29c = 0xc5;
    puVar4[0x80] = 0xd3;
    puVar4[0x1a] = 0xc5;
    *DAT_0005b2a0 = 0xd3;
    *DAT_0005b2a4 = 0x12f;
    puVar4[0x82] = 0x13d;
    puVar4[0x1c] = 0x12f;
    *DAT_0005b2a8 = 0x13d;
    *DAT_0005b2ac = 0xd4;
    puVar4[0x84] = 0xde;
    puVar4[0x1e] = 0xd4;
    *DAT_0005b2b0 = 0xde;
    *DAT_0005b2b4 = 0x13e;
    puVar4[0x86] = 0x147;
    puVar4[0x20] = 0x13e;
    *DAT_0005b2b8 = 0x147;
    *DAT_0005b2bc = 0xdf;
    puVar4[0x88] = 0xed;
    puVar4[0x22] = 0xdf;
    *DAT_0005b2c0 = 0xed;
    *DAT_0005b2c4 = 0x148;
    puVar4[0x8a] = 0x156;
    puVar4[0x24] = 0x148;
    *DAT_0005b2c8 = 0x156;
    puVar10 = DAT_0005b2cc;
    *DAT_0005b2cc = 0xee;
    puVar10[0x67] = 0xee;
    puVar10[1] = 0xee;
    puVar10[0x68] = 0xee;
    puVar10[2] = 0x157;
    puVar10[0x69] = 0x157;
    puVar10[3] = 0x157;
    puVar10[0x6a] = 0x157;
    puVar10[0x213cb] = 0xb00;
    puVar10[0x213cf] = 0;
    puVar10[0x213f3] = 0xb00;
    puVar10[0x213f7] = 0;
    puVar10[0x2141b] = 0xb00;
    puVar10[0x2141f] = 0;
    puVar10[0x21443] = 0xb00;
    puVar10[0x21447] = 0;
    puVar10[0x214db] = 0xb00;
    puVar10[0x214df] = 0;
    puVar10[0x21503] = 0xb00;
    puVar10[0x21507] = 0;
    puVar10[0x215ab] = 0xb00;
    puVar10[0x215af] = 0;
    puVar10[0x215d3] = 0xb00;
    puVar10 = DAT_0005b2d0;
    *DAT_0005b2d0 = 0;
    puVar10[0x14c] = 0x5b00;
    puVar10[0x150] = 0;
    puVar10[0x174] = 0x7b00;
    *puVar11 = 0x400;
    puVar11[0x24] = 0x5b00;
    puVar11[0x28] = 0;
    puVar11[0x4c] = 0x7b00;
    puVar11[0x50] = 0x400;
    puVar11[0xdc] = 0x5b00;
    puVar11[0xe0] = 0;
    puVar11[0x104] = 0x7b00;
    puVar11[0x108] = 0x400;
    puVar11[0x1a4] = 0x5b00;
    *DAT_0005b2d4 = 0;
    puVar11 = DAT_0005b2d8;
  }
  else {
    puVar19[-100] = 0x10a;
    *puVar1 = 0x11b;
    *puVar15 = 0x10a;
    *puVar2 = 0x11b;
    *puVar3 = 0x94;
    puVar15[0x68] = 0x9b;
    *puVar11 = 0x94;
    *puVar17 = 0x9b;
    puVar10[-0x4e] = 0x11c;
    puVar18[0x14] = 0x122;
    puVar15[4] = 0x11c;
    *DAT_0005a5c8 = 0x122;
    *DAT_0005a5cc = 0x9c;
    puVar15[0x6c] = 0xaf;
    puVar15[6] = 0x9c;
    *DAT_0005a5d0 = 0xaf;
    *DAT_0005a5d4 = 0x123;
    puVar15[0x6e] = 0x132;
    puVar15[8] = 0x123;
    *DAT_0005a8cc = 0x132;
    *DAT_0005a8d0 = 0xb0;
    puVar15[0x70] = 0xc0;
    puVar15[10] = 0xb0;
    *DAT_0005a8d4 = 0xc0;
    *DAT_0005a8d8 = 0x133;
    puVar15[0x72] = 0x143;
    puVar15[0xc] = 0x133;
    *DAT_0005a8dc = 0x143;
    *DAT_0005a8e0 = 0xc1;
    puVar15[0x74] = 0xca;
    puVar15[0xe] = 0xc1;
    *DAT_0005a8e4 = 0xca;
    *DAT_0005a8e8 = 0x144;
    puVar15[0x76] = 0x14d;
    puVar15[0x10] = 0x144;
    *DAT_0005a8ec = 0x14d;
    *DAT_0005a8f0 = 0xcb;
    puVar15[0x78] = 0xd4;
    puVar15[0x12] = 0xcb;
    *DAT_0005a8f4 = 0xd4;
    *DAT_0005a8f8 = 0x14e;
    puVar15[0x7a] = 0x157;
    puVar15[0x14] = 0x14e;
    *DAT_0005a8fc = 0x157;
    *DAT_0005a900 = 0xd5;
    puVar15[0x7c] = 0xdf;
    puVar15[0x16] = 0xd5;
    *DAT_0005a904 = 0xdf;
    *DAT_0005a908 = 0x158;
    puVar15[0x7e] = 0x161;
    puVar15[0x18] = 0x158;
    *DAT_0005a90c = 0x161;
    *DAT_0005a910 = 0xe0;
    puVar15[0x80] = 0xee;
    puVar15[0x1a] = 0xe0;
    *DAT_0005a914 = 0xee;
    *DAT_0005a918 = 0x162;
    puVar15[0x82] = 0x170;
    puVar15[0x1c] = 0x162;
    *DAT_0005a91c = 0x170;
    *DAT_0005a920 = 0xef;
    puVar15[0x84] = 0xf9;
    puVar15[0x1e] = 0xef;
    *DAT_0005a924 = 0xf9;
    *DAT_0005a928 = 0x171;
    puVar15[0x86] = 0x17a;
    puVar15[0x20] = 0x171;
    *DAT_0005a92c = 0x17a;
    *DAT_0005a930 = 0xfa;
    puVar15[0x88] = 0x108;
    puVar15[0x22] = 0xfa;
    *DAT_0005a934 = 0x108;
    *DAT_0005a938 = 0x17b;
    puVar15[0x8a] = 0x189;
    puVar15[0x24] = 0x17b;
    *DAT_0005a93c = 0x189;
    puVar11 = DAT_0005a940;
    *DAT_0005a940 = 0x109;
    puVar11[0x67] = 0x109;
    puVar11[1] = 0x109;
    puVar11[0x68] = 0x109;
    puVar11[2] = 0x18a;
    puVar11[0x69] = 0x18a;
    puVar11[3] = 0x18a;
    puVar11[0x6a] = 0x18a;
    *DAT_0005a944 = 0xb00;
    puVar15[0x214cc] = 0;
    puVar15[0x214f0] = 0xb00;
    puVar15[0x214f4] = 0;
    puVar15[0x21518] = 0xb00;
    puVar15[0x2151c] = 0;
    puVar15[0x21540] = 0xb00;
    puVar15[0x21544] = 0;
    puVar15[0x215d8] = 0xb00;
    puVar15[0x215dc] = 0;
    puVar15[0x21600] = 0xb00;
    puVar15[0x21604] = 0;
    puVar15[0x216a8] = 0xb00;
    puVar15[0x216ac] = 0;
    puVar15[0x216d0] = 0xb00;
    puVar11 = DAT_0005a948;
    *DAT_0005a948 = 0;
    puVar11[0x20c] = 0x5b00;
    puVar11[0x210] = 0;
    puVar11[0x234] = 0x7b00;
    puVar18[0x218b6] = 0x400;
    puVar18[0x218da] = 0x5b00;
    puVar18[0x218de] = 0;
    puVar18[0x21902] = 0x7b00;
    puVar18[0x21906] = 0x400;
    puVar18[0x21992] = 0x5b00;
    puVar18[0x21996] = 0;
    puVar18[0x219ba] = 0x7b00;
    puVar18[0x219be] = 0x400;
    puVar18[0x21a5a] = 0x5b00;
    *DAT_0005a94c = 0;
    puVar11 = DAT_0005a950;
  }
  *puVar11 = 0x7b00;
  puVar11[4] = 0x400;
  iVar20 = DAT_0005a95c;
  puVar10 = DAT_0005a958;
  puVar11 = DAT_0005a954;
  if (iVar16 != 9) goto LAB_0005ab48;
  puVar17 = DAT_0005a954;
  do {
    puVar19 = puVar17 + 1;
    *puVar17 = *(undefined2 *)((int)auStack_48 + ((int)puVar17 + iVar20 & 0xfffffffeU));
    puVar18 = DAT_0005a960;
    puVar17 = puVar19;
  } while (puVar19 != puVar10);
  uVar14 = uVar21 & 0x1000;
  if (uVar14 == 0) {
    *puVar11 = 0x49d8;
    uVar9 = 0x4808;
  }
  else {
    *puVar11 = 0xc9d8;
    uVar9 = 0xc808;
  }
  iVar20 = DAT_0005a968;
  puVar11 = DAT_0005a964;
  *puVar18 = uVar9;
  do {
    puVar18 = puVar19 + 1;
    *puVar19 = *(undefined2 *)((int)auStack_48 + ((int)puVar19 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_0005a96c;
    puVar19 = puVar18;
  } while (puVar18 != puVar11);
  if (uVar14 == 0) {
    *puVar10 = 0x4958;
    uVar9 = 0x4e08;
  }
  else {
    *puVar10 = 0xc958;
    uVar9 = 0xce08;
  }
  *puVar17 = uVar9;
  iVar20 = DAT_0005a978;
  puVar10 = DAT_0005a974;
  *DAT_0005a970 = 0x2b00;
  do {
    puVar19 = puVar18 + 1;
    *puVar18 = *(undefined2 *)((int)auStack_48 + ((int)puVar18 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_0005a97c;
    puVar18 = puVar19;
  } while (puVar19 != puVar10);
  if (uVar14 == 0) {
    *puVar11 = 0x40d8;
    uVar9 = 0x4048;
  }
  else {
    *puVar11 = 0xc0d8;
    uVar9 = 0xc048;
  }
  *puVar17 = uVar9;
  iVar20 = DAT_0005a988;
  puVar11 = DAT_0005a984;
  *DAT_0005a980 = 0x2b00;
  do {
    puVar18 = puVar19 + 1;
    *puVar19 = *(undefined2 *)((int)auStack_48 + ((int)puVar19 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_0005a98c;
    puVar19 = puVar18;
  } while (puVar18 != puVar11);
  if (uVar14 == 0) {
    *puVar10 = 0x4158;
    uVar9 = 0x4448;
  }
  else {
    *puVar10 = 0xc158;
    uVar9 = 0xc448;
  }
  *puVar17 = uVar9;
  iVar20 = DAT_0005a998;
  puVar10 = DAT_0005a994;
  *DAT_0005a990 = 0x2b00;
  do {
    puVar19 = puVar18 + 1;
    *puVar18 = *(undefined2 *)((int)auStack_48 + ((int)puVar18 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_0005ac74;
    puVar18 = puVar19;
  } while (puVar19 != puVar10);
  iVar20 = *DAT_0005a99c;
  if (uVar14 == 0) {
    *puVar11 = 0x41d8;
    *puVar17 = 0x4308;
    if (iVar20 != 0) {
      uVar9 = 0x4b08;
      goto LAB_0005a9ba;
    }
  }
  else {
    *puVar11 = 0xc1d8;
    *puVar17 = 0xc308;
    if (iVar20 != 0) {
      uVar9 = 0xcb08;
LAB_0005a9ba:
      *puVar17 = uVar9;
    }
  }
  iVar20 = DAT_0005ac80;
  puVar11 = DAT_0005ac7c;
  *DAT_0005ac78 = 0x2b00;
  do {
    puVar18 = puVar19 + 1;
    *puVar19 = *(undefined2 *)((int)auStack_48 + ((int)puVar19 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_0005ac84;
    puVar19 = puVar18;
  } while (puVar18 != puVar11);
  if (uVar14 == 0) {
    *puVar10 = 0x4558;
    uVar9 = 0x6a08;
  }
  else {
    *puVar10 = 0xc558;
    uVar9 = 0xea08;
  }
  *puVar17 = uVar9;
  iVar20 = DAT_0005ac8c;
  *DAT_0005ac88 = 0x2b00;
  puVar10 = DAT_0005ac90;
  do {
    puVar19 = puVar18 + 1;
    *puVar18 = *(undefined2 *)((int)auStack_48 + ((int)puVar18 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_0005ac94;
    puVar18 = puVar19;
  } while (puVar19 != puVar10);
  if (uVar14 == 0) {
    *puVar11 = 0x45d8;
    uVar9 = 0x4208;
  }
  else {
    *puVar11 = 0xc5d8;
    uVar9 = 0xc108;
  }
  *puVar17 = uVar9;
  puVar11 = DAT_0005ac9c;
  iVar8 = *(int *)(param_1 + 0x6c);
  *DAT_0005ac98 = 0x2b00;
  puVar17 = DAT_0005aca0;
  *puVar10 = 0x48d8;
  iVar20 = DAT_0005aca4;
  *puVar17 = 0;
  puVar17[1] = 0;
  puVar17[2] = 0;
  if (iVar8 < 0) {
    uVar9 = 0x4348;
  }
  else {
    uVar9 = 0x4308;
  }
  *DAT_0005aca8 = uVar9;
  puVar10 = DAT_0005acac;
  *DAT_0005acac = 0;
  puVar10[1] = 0;
  puVar10[2] = 0;
  puVar10 = DAT_0005acb0;
  puVar17 = DAT_0005acb0;
  do {
    puVar19 = puVar17 + 1;
    *puVar17 = *(undefined2 *)((int)auStack_48 + ((int)puVar17 + iVar20 & 0xfffffffeU));
    puVar18 = DAT_0005acb4;
    puVar17 = puVar19;
  } while (puVar19 != puVar11);
  if (uVar14 == 0) {
    *puVar10 = 0x8d8;
    if (iVar8 < 0) {
      uVar9 = 0x1748;
    }
    else {
      uVar9 = 0x1708;
    }
  }
  else {
    if (iVar8 < 0) {
      uVar9 = 0x9748;
    }
    else {
      uVar9 = 0x9708;
    }
    *puVar10 = 0x88d8;
  }
  *puVar18 = uVar9;
  iVar20 = DAT_0005acbc;
  *DAT_0005acb8 = 0x2b00;
  puVar10 = DAT_0005acc0;
  do {
    puVar18 = puVar19 + 1;
    *puVar19 = *(undefined2 *)((int)auStack_48 + ((int)puVar19 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_0005acc4;
    puVar19 = puVar18;
  } while (puVar18 != puVar10);
  if (uVar14 == 0) {
    *puVar11 = 0x4a58;
    uVar9 = 0x4108;
  }
  else {
    *puVar11 = 0xca58;
    uVar9 = 0xc108;
  }
  *puVar17 = uVar9;
  iVar20 = DAT_0005acd0;
  puVar11 = DAT_0005accc;
  *DAT_0005acc8 = 0x2b00;
  do {
    puVar19 = puVar18 + 1;
    *puVar18 = *(undefined2 *)((int)auStack_48 + ((int)puVar18 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_0005acd4;
    puVar18 = puVar19;
  } while (puVar19 != puVar11);
  if (uVar14 == 0) {
    *puVar10 = 0x4b58;
    uVar9 = 0x4008;
  }
  else {
    *puVar10 = 0xcb58;
    uVar9 = 0xc008;
  }
  *puVar17 = uVar9;
  iVar20 = DAT_0005acdc;
  *DAT_0005acd8 = 0x2b00;
  puVar10 = DAT_0005ace0;
  do {
    puVar18 = puVar19 + 1;
    *puVar19 = *(undefined2 *)((int)auStack_48 + ((int)puVar19 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_0005ace4;
    puVar19 = puVar18;
  } while (puVar18 != puVar10);
  if (uVar14 == 0) {
    *puVar11 = 0x54d8;
    uVar9 = 0x7008;
  }
  else {
    *puVar11 = 0xd4d8;
    uVar9 = 0xf008;
  }
  *puVar17 = uVar9;
LAB_0005ab48:
  puVar10 = DAT_0005acec;
  puVar11 = DAT_0005ace8;
  *DAT_0005ace8 = 0x5061;
  puVar11[1] = 0x7098;
  puVar11 = DAT_0005acf0;
  *DAT_0005acf0 = 0;
  puVar11[-3] = 0xbedc;
  puVar11[3] = 0xb0db;
  puVar11[4] = 0;
  puVar11[-0x2f8f7] = 0;
  puVar11 = DAT_0005acf4;
  *DAT_0005acf4 = 0x7ff;
  puVar11[1] = 0x668;
  puVar11[2] = 0x7910;
  puVar11[3] = 0x355e;
  puVar11[4] = 0xcbb5;
  puVar11 = DAT_0005acfc;
  if ((uVar13 & 4) == 0) {
    *DAT_0005acf8 = 0xffff;
    uVar9 = 0x710;
  }
  else {
    *DAT_0005acf8 = 0x710;
    uVar9 = 0xffff;
  }
  *puVar11 = uVar9;
  *DAT_0005ad00 = 0x7800;
  puVar11 = DAT_0005ad04;
  *DAT_0005ad04 = 0xffff;
  puVar11[2] = 0xff10;
  puVar11[-0x4fe] = 0x2ee8;
  puVar11[1] = 0xffff;
  puVar11 = DAT_0005ad0c;
  *DAT_0005ad08 = 0xffdf;
  puVar17 = DAT_0005ad10;
  *DAT_0005ad10 = 0x6f10;
  puVar17[1] = 0x6f10;
  puVar17[2] = 0x2868;
  puVar17[3] = 0x2868;
  *DAT_0005ad14 = 0xfeef;
  puVar17 = DAT_0005ad18;
  *DAT_0005ad18 = 0xe400;
  puVar17[0x82] = 0xe400;
  puVar17[0x1c] = 0;
  puVar17[0x1d] = 0;
  puVar17[0x1e] = 0;
  puVar17[0x1f] = 0;
  *puVar11 = 0xff00;
  puVar11[1] = 0xff00;
  puVar11[2] = 0xff00;
  puVar11[3] = 0xff00;
  puVar11[0xc] = 0x4000;
  puVar11[0xd] = 0x2000;
  puVar11[0xe] = 0xff00;
  puVar11[0xf] = 0xff00;
  puVar11 = DAT_0005ad1c;
  *DAT_0005ad1c = 0;
  puVar11[2] = 0;
  if ((uVar21 & 0x1000) == 0) {
    *DAT_0005ad20 = 0;
  }
  else {
    *DAT_0005ad20 = 1;
  }
  *DAT_0005ad24 = 0x27f7;
  puVar11 = DAT_0005ad28;
  *DAT_0005ad28 = 0x2108;
  puVar11[1] = 0x2108;
  puVar11[-0x10038] = 1;
  puVar11[-0x10040] = 0x180;
  puVar11[-0x10037] = 1;
  *puVar10 = 0;
  puVar10[0x13] = 1;
  puVar10[0x1017] = 1;
  puVar10[0x100f] = 0x180;
  puVar10[0x1018] = 1;
  puVar10[0x1000] = 0;
  puVar10[0x1013] = 1;
  puVar10[0x2017] = 1;
  puVar10[0x200f] = 0x180;
  puVar10[0x2018] = 1;
  puVar10[0x2000] = 0;
  puVar10[0x2013] = 1;
  puVar10[0x3017] = 1;
  puVar10[0x300f] = 0x180;
  puVar11 = DAT_0005af48;
  *DAT_0005af48 = 1;
  puVar11[-0x18] = 0;
  puVar11 = DAT_0005af4c;
  *DAT_0005af4c = 1;
  puVar11[0x5cf6f] = 0x5a3c;
  puVar11[0x5cf70] = 0x5a3c;
  puVar11[0x5cf71] = 0x5a3c;
  puVar11[0x5cf72] = 0x5a3c;
  puVar11[0x5cf73] = 0x5a3c;
  puVar11[0x5cf74] = 0x5a3c;
  puVar11[0x5cf75] = 0x5a3c;
  puVar11[0x5cf76] = 0x5a3c;
  puVar11[0x5d06f] = 0x5a3c;
  puVar11[0x5d070] = 0x5a3c;
  puVar11[0x5d071] = 0x5a3c;
  puVar11[0x5d072] = 0x5a3c;
  puVar11[0x5d073] = 0x5a3c;
  puVar11[0x5d074] = 0x5a3c;
  puVar11[0x5d075] = 0x5a3c;
  puVar11[0x5d076] = 0x5a3c;
  puVar11[0x5d16f] = 0x5a3c;
  puVar11[0x5d170] = 0x5a3c;
  puVar11[0x5d171] = 0x5a3c;
  puVar11[0x5d172] = 0x5a3c;
  puVar11[0x5d173] = 0x5a3c;
  puVar11[0x5d174] = 0x5a3c;
  puVar11[0x5d175] = 0x5a3c;
  puVar11[0x5d176] = 0x5a3c;
  puVar11[0x5d26f] = 0x5a3c;
  puVar11[0x5d270] = 0x5a3c;
  puVar11[0x5d271] = 0x5a3c;
  puVar11[0x5d272] = 0x5a3c;
  puVar11[0x5d273] = 0x5a3c;
  puVar11[0x5d274] = 0x5a3c;
  puVar11[0x5d275] = 0x5a3c;
  puVar11[0x5d276] = 0x5a3c;
  puVar11[0x5d36f] = 0x5a3c;
  puVar11[0x5d370] = 0x5a3c;
  puVar11[0x5d371] = 0x5a3c;
  puVar11[0x5d372] = 0x5a3c;
  puVar11[0x5d373] = 0x5a3c;
  puVar11[0x5d374] = 0x5a3c;
  puVar11[0x5d375] = 0x5a3c;
  puVar11[0x5d376] = 0x5a3c;
  puVar11[0x5d46f] = 0x5a3c;
  puVar11[0x5d470] = 0x5a3c;
  puVar11[0x5d471] = 0x5a3c;
  puVar11[0x5d472] = 0x5a3c;
  puVar11[0x5d473] = 0x5a3c;
  puVar11[0x5d474] = 0x5a3c;
  puVar11[0x5d475] = 0x5a3c;
  puVar11[0x5d476] = 0x5a3c;
  puVar11[0x5d56f] = 0x5a3c;
  puVar11[0x5d570] = 0x5a3c;
  puVar11[0x5d571] = 0x5a3c;
  puVar11[0x5d572] = 0x5a3c;
  puVar11[0x5d573] = 0x5a3c;
  puVar11[0x5d574] = 0x5a3c;
  puVar11[0x5d575] = 0x5a3c;
  puVar11[0x5d576] = 0x5a3c;
  puVar11[0x5d66f] = 0x5a3c;
  puVar11[0x5d670] = 0x5a3c;
  puVar11[0x5d671] = 0x5a3c;
  puVar11[0x5d672] = 0x5a3c;
  puVar11[0x5d673] = 0x5a3c;
  puVar11[0x5d674] = 0x5a3c;
  puVar11[0x5d675] = 0x5a3c;
  puVar11[0x5d676] = 0x5a3c;
  puVar11[0x5d76f] = 0x5a3c;
  puVar11[0x5d770] = 0x5a3c;
  puVar11[0x5d771] = 0x5a3c;
  puVar11[0x5d772] = 0x5a3c;
  puVar11[0x5d773] = 0x5a3c;
  puVar11[0x5d774] = 0x5a3c;
  puVar11[0x5d775] = 0x5a3c;
  puVar11[0x5d776] = 0x5a3c;
  puVar11 = DAT_0005af50;
  *DAT_0005af50 = 0x1ff;
  if ((uVar21 & 0x1000) == 0) {
    uVar9 = 0x11;
  }
  else {
    uVar9 = 0x33;
  }
  puVar11[-0x4ffe7] = uVar9;
  puVar10 = DAT_0005af58;
  puVar11 = DAT_0005af54;
  *DAT_0005af54 = 0xffff;
  puVar11[0x70821] = 2;
  *puVar10 = 1;
  puVar10[1] = 1;
  *DAT_0005af5c = 2;
  puVar11 = DAT_0005af60;
  *DAT_0005af60 = 0;
  puVar11[-3] = 1;
  return;
}

