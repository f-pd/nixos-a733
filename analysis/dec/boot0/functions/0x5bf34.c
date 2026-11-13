// rea decompile_all
// name: FUN_0005bf34
// address: 0x5bf34
// body: available
// range: 0x5bf34-0x5c05f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: 840b41569fe64355049a7b5ebf73933b40a3394e9d351121f6df7f10d37dc1f1
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; Headerless raw-binary analysis uses the caller-supplied architecture and entry address; file offset 0 is mapped at that address. Headers are not discovered from file bytes.; Little-endian generic Ghidra languages are used for x86, x86_64, arm, arm64, and NMOS 6502; m68k uses the big-endian 68000 default language, which decodes the 68040 superset. Big-endian ARM, Thumb-only, Cortex-M, 65C02, 65816, separate 68020/68030/CPU32/ColdFire variants, and other processor variants are unsupported in this increment.; Static analysis does not emulate reset vectors, memory-mapped I/O, or firmware boot sequences.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int FUN_0005bf34(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint local_98;
  uint local_94;
  uint *local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined4 local_80;
  undefined4 uStack_7c;
  int local_78;
  uint local_64;
  undefined1 auStack_60 [12];
  uint local_54;
  uint local_50;
  uint local_44;
  
  local_64 = *(uint *)(param_1 + 0x50) & 0x10;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  if (local_64 != 0) {
    return 0;
  }
  local_80 = 0x37;
  uStack_7c = 0x15;
  local_78 = *(int *)(param_1 + 0x80) << 0x10;
  iVar1 = FUN_0005b324(param_1,&local_80);
  if (iVar1 == 0) {
    local_80 = 0x33;
    uStack_7c = 0x15;
    iVar6 = 4;
    local_78 = 0;
    local_64 = 0;
    do {
      local_88 = 1;
      uStack_84 = 8;
      local_8c = 1;
      local_90 = &local_98;
      iVar1 = FUN_0005b324(param_1,&local_80,&local_90);
      if (iVar1 == 0) {
        uVar5 = local_98 << 0x18 | (local_98 >> 8 & 0xff) << 0x10 | (local_98 >> 0x10 & 0xff) << 8 |
                local_98 >> 0x18;
        uVar4 = (local_98 << 0x18 & 0xfffffff) >> 0x18;
        *(uint *)(param_1 + 0x5c) =
             local_94 << 0x18 | (local_94 >> 8 & 0xff) << 0x10 | (local_94 >> 0x10 & 0xff) << 8 |
             local_94 >> 0x18;
        *(uint *)(param_1 + 0x58) = uVar5;
        iVar1 = DAT_0005c068;
        if (uVar4 == 1) {
          uVar2 = DAT_0005c06c;
LAB_0005bfe0:
          *(undefined4 *)(param_1 + 0x28) = uVar2;
        }
        else {
          if (uVar4 == 2) {
            uVar2 = DAT_0005c070;
            goto LAB_0005bfe0;
          }
          *(int *)(param_1 + 0x28) = DAT_0005c068;
        }
        if ((int)(uVar5 << 0xd) < 0) {
          *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 4;
        }
        if (*(int *)(param_1 + 0x28) == iVar1) {
          return 0;
        }
        iVar6 = 5;
        goto LAB_0005c016;
      }
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    uVar3 = *(undefined4 *)(param_1 + 0x30);
    uVar2 = DAT_0005c064;
  }
  else {
    uVar3 = *(undefined4 *)(param_1 + 0x30);
    uVar2 = DAT_0005c060;
  }
LAB_0005bf68:
  FUN_000498e4(uVar2,uVar3);
  return iVar1;
  while( true ) {
    iVar1 = FUN_0005bef0(param_1,0,0,1,auStack_60);
    if (iVar1 != 0) {
      uVar3 = *(undefined4 *)(param_1 + 0x30);
      uVar2 = DAT_0005c078;
      goto LAB_0005bf68;
    }
    if (-1 < (int)(((local_44 >> 8 & 0xff) << 0x10 | (local_44 >> 0x10 & 0xff) << 8 |
                   local_44 >> 0x18) << 0xe)) break;
LAB_0005c016:
    iVar6 = iVar6 + -1;
    if (iVar6 == 0) break;
  }
  if ((int)(((local_54 >> 8 & 0xff) << 0x10 | (local_54 >> 0x10 & 0xff) << 8 | local_54 >> 0x18) <<
           0xe) < 0) {
    iVar1 = FUN_0005bef0(param_1,1,0,1,auStack_60);
    if (iVar1 != 0) {
      uVar3 = *(undefined4 *)(param_1 + 0x30);
      uVar2 = DAT_0005c074;
      goto LAB_0005bf68;
    }
    iVar1 = FUN_0005bdac(param_1);
    if (iVar1 != 0) {
      FUN_000498e4(DAT_0005c07c);
      return iVar1;
    }
    if ((local_50 & 0xf) == 1) {
      *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 1;
      *(undefined4 *)(param_1 + 0x104) = 1;
      return 0;
    }
  }
  return 0;
}

