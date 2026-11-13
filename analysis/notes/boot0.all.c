
//==== 0x47000  0x47000-0x47003 inclusive
/* WARNING: This function may have set the stack pointer */

void thunk_FUN_00047b04(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  uVar2 = coproc_movefrom_Control();
  uVar2 = uVar2 & 0xffffcff8 | 0x800;
  coproc_moveto_Control(uVar2);
  FUN_00047b40(uVar2);
  FUN_0005e158();
  iVar1 = DAT_00047b60/*=0x83c28*/;
  puVar3 = DAT_00047b5c/*=0x82dd0*/;
  do {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  } while ((int)puVar3 < iVar1);
  return;
}

//==== 0x47b00  0x47b00-0x47b03 inclusive
/* WARNING: This function may have set the stack pointer */

void thunk_FUN_00047b04(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  uVar2 = coproc_movefrom_Control();
  uVar2 = uVar2 & 0xffffcff8 | 0x800;
  coproc_moveto_Control(uVar2);
  FUN_00047b40(uVar2);
  FUN_0005e158();
  iVar1 = DAT_00047b60/*=0x83c28*/;
  puVar3 = DAT_00047b5c/*=0x82dd0*/;
  do {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  } while ((int)puVar3 < iVar1);
  return;
}

//==== 0x47b04  0x47b04-0x47b3f inclusive
/* WARNING: This function may have set the stack pointer */

void FUN_00047b04(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  uVar2 = coproc_movefrom_Control();
  uVar2 = uVar2 & 0xffffcff8 | 0x800;
  coproc_moveto_Control(uVar2);
  FUN_00047b40(uVar2);
  FUN_0005e158();
  iVar1 = DAT_00047b60/*=0x83c28*/;
  puVar3 = DAT_00047b5c/*=0x82dd0*/;
  do {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  } while ((int)puVar3 < iVar1);
  return;
}

//==== 0x47b40  0x47b40-0x47b5b inclusive
void FUN_00047b40(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = DAT_00047b60/*=0x83c28*/;
  puVar2 = DAT_00047b5c/*=0x82dd0*/;
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  } while ((int)puVar2 < iVar1);
  return;
}

//==== 0x47b80  0x47b80-0x47c1b inclusive
void FUN_00047b80(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 in_cr0;
  undefined4 in_cr7;
  undefined4 in_cr14;
  
  DataMemoryBarrier(0xf);
  uVar2 = coprocessor_movefromRt(0xf,1,1,in_cr0,in_cr0);
  uVar4 = uVar2 >> 0x17 & 0xe;
  if (uVar4 != 0) {
    uVar8 = 0;
    do {
      if (1 < (uVar2 >> (uVar8 + (uVar8 >> 1) & 0xff) & 7)) {
        coprocessor_moveto(0xf,2,0,uVar8,in_cr0,in_cr0);
        InstructionSynchronizationBarrier(0xf);
        uVar3 = coprocessor_movefromRt(0xf,1,0,in_cr0,in_cr0);
        uVar5 = uVar3 >> 3 & 0x3ff;
        uVar6 = uVar5;
        do {
          uVar7 = uVar3 >> 0xd & 0x7fff;
          do {
            coprocessor_moveto(0xf,0,2,uVar8 | uVar6 << LZCOUNT(uVar5) | uVar7 << (uVar3 & 7) + 4,
                               in_cr7,in_cr14);
            bVar1 = 0 < (int)uVar7;
            uVar7 = uVar7 - 1;
          } while (bVar1);
          bVar1 = 0 < (int)uVar6;
          uVar6 = uVar6 - 1;
        } while (bVar1);
      }
      uVar8 = uVar8 + 2;
    } while ((int)uVar8 < (int)uVar4);
  }
  coprocessor_moveto(0xf,2,0,0,in_cr0,in_cr0);
  DataSynchronizationBarrier(0xe);
  InstructionSynchronizationBarrier(0xf);
  return;
}

//==== 0x47c1c  0x47c1c-0x47c2b inclusive
void FUN_00047c1c(void)

{
  FUN_00047b80();
  return;
}

//==== 0x47c40  0x47c40-0x47d1b inclusive
void FUN_00047c40(uint *param_1,uint param_2,uint param_3)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  uint *puVar6;
  uint *puVar7;
  bool bVar8;
  
  uVar3 = (uint)param_1 & 3;
  if (uVar3 != 0) {
    uVar2 = param_3 - 4;
    if ((int)param_3 < 4) goto LAB_00047ce4;
    uVar1 = (undefined1)param_2;
    puVar6 = param_1;
    if (uVar3 < 2) {
      puVar6 = (uint *)((int)param_1 + 1);
      *(undefined1 *)param_1 = uVar1;
    }
    puVar7 = puVar6;
    if (uVar3 < 3) {
      puVar7 = (uint *)((int)puVar6 + 1);
      *(undefined1 *)puVar6 = uVar1;
    }
    param_1 = (uint *)((int)puVar7 + 1);
    *(undefined1 *)puVar7 = uVar1;
    param_3 = uVar2 + uVar3;
  }
  param_2 = param_2 | param_2 << 8;
  param_2 = param_2 | param_2 << 0x10;
  if (0xf < (int)param_3) {
    bVar8 = param_3 == 0x60;
    if ((int)param_3 >= 0x61) {
      bVar8 = ((uint)param_1 & 0x1f) == 0;
    }
    uVar3 = param_3;
    if (!bVar8 && ((int)param_3 < 0x61 && (int)(param_3 - 0x60) < 0) == SBORROW4(param_3,0x60)) {
      uVar4 = 0x20 - ((uint)param_1 & 0x1f);
      uVar3 = param_3 - uVar4;
      uVar2 = ((uint)param_1 & 0x1f) * -0x10000000;
      puVar6 = param_1;
      if ((bool)((byte)(uVar4 >> 4) & 1)) {
        *param_1 = param_2;
        param_1[1] = param_2;
        param_1[2] = param_2;
        param_1[3] = param_2;
        puVar6 = param_1 + 4;
      }
      if ((int)uVar2 < 0) {
        *puVar6 = param_2;
        puVar6[1] = param_2;
        puVar6 = puVar6 + 2;
      }
      param_1 = puVar6;
      if ((uVar2 & 0x40000000) != 0) {
        param_1 = puVar6 + 1;
        *puVar6 = param_2;
      }
    }
    do {
      param_3 = uVar3 - 0x40;
      if (0x3f < (int)uVar3) {
        *param_1 = param_2;
        param_1[1] = param_2;
        param_1[2] = param_2;
        param_1[3] = param_2;
        param_1[4] = param_2;
        param_1[5] = param_2;
        param_1[6] = param_2;
        param_1[7] = param_2;
        param_1[8] = param_2;
        param_1[9] = param_2;
        param_1[10] = param_2;
        param_1[0xb] = param_2;
        param_1[0xc] = param_2;
        param_1[0xd] = param_2;
        param_1[0xe] = param_2;
        param_1[0xf] = param_2;
        param_1 = param_1 + 0x10;
      }
      bVar8 = 0x3f < (int)uVar3;
      uVar3 = param_3;
    } while (param_3 != 0 && bVar8);
    if (param_3 == 0) {
      return;
    }
    if ((param_3 & 0x20) != 0) {
      *param_1 = param_2;
      param_1[1] = param_2;
      param_1[2] = param_2;
      param_1[3] = param_2;
      param_1[4] = param_2;
      param_1[5] = param_2;
      param_1[6] = param_2;
      param_1[7] = param_2;
      param_1 = param_1 + 8;
    }
    if ((param_3 & 0x10) != 0) {
      *param_1 = param_2;
      param_1[1] = param_2;
      param_1[2] = param_2;
      param_1[3] = param_2;
      param_1 = param_1 + 4;
    }
  }
  puVar6 = param_1;
  if ((param_3 & 8) != 0) {
    *param_1 = param_2;
    param_1[1] = param_2;
    puVar6 = param_1 + 2;
  }
  uVar2 = param_3;
  param_1 = puVar6;
  if ((param_3 & 4) != 0) {
    param_1 = puVar6 + 1;
    *puVar6 = param_2;
  }
LAB_00047ce4:
  uVar1 = (undefined1)param_2;
  if ((uVar2 & 2) != 0) {
    puVar5 = (undefined1 *)((int)param_1 + 1);
    *(undefined1 *)param_1 = uVar1;
    param_1 = (uint *)((int)param_1 + 2);
    *puVar5 = uVar1;
  }
  if ((uVar2 & 1) != 0) {
    *(undefined1 *)param_1 = uVar1;
  }
  return;
}

//==== 0x48038  0x48038-0x48069 inclusive
ulonglong FUN_00048038(uint param_1,uint param_2)

{
  uint uVar1;
  ulonglong uVar2;
  
  if (param_2 - 1 == 0) {
    return CONCAT44(param_2,param_1);
  }
  if (param_2 == 0) {
    uVar1 = FUN_00049d10(8);
    return (ulonglong)uVar1;
  }
  if (param_1 <= param_2) {
    return CONCAT44(param_2,(uint)(param_1 == param_2));
  }
  if ((param_2 & param_2 - 1) == 0) {
    return CONCAT44(param_2,param_1 >> (0x1fU - LZCOUNT(param_2) & 0xff));
  }
                    /* WARNING: Could not recover jumptable at 0x00048068. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*(code *)((0x1f - (LZCOUNT(param_2) - LZCOUNT(param_1))) * 0x10 + 0x48070))
                    (param_1,param_2,0);
  return uVar2;
}

//==== 0x48294  0x48294-0x482ad inclusive
void FUN_00048294(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    FUN_00049d10(8);
    return;
  }
  FUN_00048038();
  return;
}

//==== 0x482b0  0x482b0-0x482f1 inclusive
ulonglong FUN_000482b0(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  ulonglong uVar4;
  
  if (param_2 == 0) {
    uVar2 = FUN_00049d10(8);
    return (ulonglong)uVar2;
  }
  uVar3 = param_1 ^ param_2;
  uVar2 = param_2;
  if ((int)param_2 < 0) {
    uVar2 = -param_2;
  }
  if (uVar2 - 1 == 0) {
    if ((int)param_2 < 0) {
      param_1 = -param_1;
    }
    return CONCAT44(uVar2,param_1);
  }
  uVar1 = param_1;
  if ((int)param_1 < 0) {
    uVar1 = -param_1;
  }
  if (uVar2 < uVar1) {
    if ((uVar2 & uVar2 - 1) != 0) {
                    /* WARNING: Could not recover jumptable at 0x000482f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar4 = (*(code *)((0x1f - (LZCOUNT(uVar2) - LZCOUNT(uVar1))) * 0x10 + 0x482f8))(0);
      return uVar4;
    }
    uVar1 = uVar1 >> (0x1fU - LZCOUNT(uVar2) & 0xff);
    if ((int)uVar3 < 0) {
      uVar1 = -uVar1;
    }
    return CONCAT44(uVar2,uVar1);
  }
  if (uVar1 < uVar2) {
    param_1 = 0;
  }
  if (uVar1 == uVar2) {
    param_1 = (int)uVar3 >> 0x1f | 1;
  }
  return CONCAT44(uVar2,param_1);
}

//==== 0x487e4  0x486a4-0x48745 inclusive
ulonglong FUN_000487e4(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint in_r12;
  bool bVar6;
  bool bVar7;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar1 = 0;
  iVar4 = LZCOUNT(param_1);
  uVar5 = iVar4 + 0x15;
  bVar7 = SBORROW4(uVar5,0x20);
  uVar2 = iVar4 - 0xb;
  bVar6 = uVar2 == 0;
  uVar3 = uVar2;
  if (uVar5 < 0x20) {
    bVar7 = SCARRY4(uVar2,0xc);
    uVar3 = iVar4 + 1;
    bVar6 = uVar3 == 0;
    if (!bVar6 && -0xd < (int)uVar2) {
      uVar1 = param_1 << uVar5;
      param_1 = param_1 >> (0xc - uVar3 & 0xff);
      goto LAB_000486f0;
    }
    uVar2 = uVar5;
  }
  if (bVar6 || (int)uVar3 < 0 != bVar7) {
    in_r12 = 0x20 - uVar2;
  }
  param_1 = param_1 << (uVar2 & 0xff);
  if (bVar6 || (int)uVar3 < 0 != bVar7) {
    param_1 = param_1 | 0U >> (in_r12 & 0xff);
    uVar1 = 0 << (uVar2 & 0xff);
  }
LAB_000486f0:
  if (uVar5 < 0x433) {
    return CONCAT44(param_1 + (0x432 - uVar5) * 0x100000,uVar1);
  }
  uVar2 = ~(0x432 - uVar5);
  if (0x1e < (int)uVar2) {
    return (ulonglong)(param_1 >> (uVar2 - 0x1f & 0xff));
  }
  if (uVar2 - 0x13 == 0 || (int)(uVar2 - 0x1f) < -0xc) {
    uVar2 = uVar2 + 1;
    return CONCAT44(param_1 >> (uVar2 & 0xff),
                    uVar1 >> (uVar2 & 0xff) | param_1 << (0x20 - uVar2 & 0xff));
  }
  uVar2 = 0xc - (uVar2 - 0x13);
  return (ulonglong)(uVar1 >> (0x20 - uVar2 & 0xff) | param_1 << (uVar2 & 0xff));
}

//==== 0x488d8  0x488d8-0x48a73 inclusive
ulonglong FUN_000488d8(undefined4 param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  uint extraout_r2;
  uint extraout_r3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint unaff_r5;
  uint uVar7;
  uint uVar8;
  uint extraout_r12;
  uint uVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  ulonglong uVar13;
  
  uVar13 = CONCAT44(param_2,param_1);
  uVar8 = 0x7ff;
  uVar4 = param_2 >> 0x14 & 0x7ff;
  bVar10 = uVar4 == 0;
  if (!bVar10) {
    unaff_r5 = param_4 >> 0x14 & 0x7ff;
    bVar10 = unaff_r5 == 0;
  }
  if (!bVar10) {
    bVar10 = uVar4 == 0x7ff;
  }
  if (!bVar10) {
    bVar10 = unaff_r5 == 0x7ff;
  }
  if (bVar10) {
    uVar13 = FUN_00048ab4();
    param_3 = extraout_r2;
    param_4 = extraout_r3;
    uVar8 = extraout_r12;
  }
  uVar3 = (uint)(uVar13 >> 0x20);
  uVar7 = (uint)uVar13;
  iVar5 = uVar4 + unaff_r5;
  uVar4 = uVar3 ^ param_4;
  uVar3 = uVar3 & ~(uVar8 << 0x15);
  param_4 = param_4 & ~(uVar8 << 0x15);
  bVar10 = (uVar3 & 0xfffff) == 0;
  bVar11 = uVar7 == 0 && bVar10;
  if (uVar7 != 0 || !bVar10) {
    bVar11 = param_3 == 0 && (param_4 & 0xfffff) == 0;
  }
  uVar3 = uVar3 | 0x100000;
  param_4 = param_4 | 0x100000;
  if (bVar11) {
    uVar7 = uVar7 | param_3;
    param_4 = (uVar4 & 0x80000000 | uVar3) ^ param_4;
    uVar4 = uVar8 >> 1;
    bVar11 = SBORROW4(iVar5,uVar4);
    uVar6 = iVar5 - uVar4;
    bVar10 = uVar6 == 0;
    uVar3 = uVar6;
    if (!bVar10 && (int)uVar4 <= iVar5) {
      bVar11 = SBORROW4(uVar8,uVar6);
      uVar3 = uVar8 - uVar6;
      bVar10 = uVar8 == uVar6;
    }
    if (!bVar10 && (int)uVar3 < 0 == bVar11) {
      return CONCAT44(param_4 | uVar6 * 0x100000,uVar7);
    }
    param_4 = param_4 | 0x100000;
    uVar4 = 0;
    bVar11 = SBORROW4(uVar6,1);
    uVar6 = uVar6 - 1;
    bVar10 = uVar6 == 0;
    uVar8 = uVar6;
  }
  else {
    uVar1 = (uVar13 & 0xffffffff) * (ulonglong)param_3;
    uVar13 = (uVar13 & 0xffffffff) * (ulonglong)param_4 +
             (ulonglong)uVar3 * (ulonglong)param_3 + (uVar1 >> 0x20);
    uVar9 = (uint)uVar13;
    lVar2 = (ulonglong)uVar3 * (ulonglong)param_4 + (uVar13 >> 0x20);
    uVar8 = (uint)lVar2;
    uVar7 = (uint)((ulonglong)lVar2 >> 0x20);
    if ((int)uVar1 != 0) {
      uVar9 = uVar9 | 1;
    }
    uVar6 = (iVar5 + -0x3ff) - (uint)(uVar7 < 0x200);
    if (uVar7 < 0x200) {
      bVar10 = (uVar9 & 0x80000000) != 0;
      uVar9 = uVar9 << 1;
      lVar2 = CONCAT44(uVar7 * 2 + (uint)(CARRY4(uVar8,uVar8) || CARRY4(uVar8 * 2,(uint)bVar10)),
                       uVar8 * 2 + (uint)bVar10);
    }
    param_4 = uVar4 & 0x80000000 | (int)((ulonglong)lVar2 >> 0x20) << 0xb | (uint)lVar2 >> 0x15;
    uVar7 = (uint)lVar2 << 0xb | uVar9 >> 0x15;
    uVar4 = uVar9 * 0x800;
    bVar12 = 0xfc < uVar6;
    bVar11 = SBORROW4(uVar6,0xfd);
    uVar3 = uVar6 - 0xfd;
    bVar10 = uVar3 == 0;
    uVar8 = uVar3;
    if (bVar12 && !bVar10) {
      bVar12 = 0x6ff < uVar3;
      bVar11 = SBORROW4(uVar3,0x700);
      uVar8 = uVar6 - 0x7fd;
      bVar10 = uVar3 == 0x700;
    }
    if (!bVar12 || bVar10) {
      bVar10 = 0x7fffffff < uVar4;
      if (uVar4 == 0x80000000) {
        bVar10 = (uVar9 >> 0x15 & 1) != 0;
      }
      return CONCAT44(param_4 + uVar6 * 0x100000 + (uint)CARRY4(uVar7,(uint)bVar10),uVar7 + bVar10);
    }
  }
  if (!bVar10 && (int)uVar8 < 0 == bVar11) {
    return (ulonglong)(param_4 & 0x80000000 | 0x7ff00000) << 0x20;
  }
  if ((int)uVar6 < -0x35) {
    return (ulonglong)(param_4 & 0x80000000) << 0x20;
  }
  uVar8 = -uVar6;
  uVar3 = uVar8 - 0x20;
  if (0x1f < (int)uVar8) {
    uVar6 = uVar7 >> (uVar3 & 0xff) | param_4 << (0x20 - uVar3 & 0xff);
    uVar8 = (param_4 >> (uVar3 & 0xff) & ~((param_4 & 0x80000000) >> (uVar3 & 0xff))) -
            ((int)uVar6 >> 0x1f);
    if ((uVar4 == 0 && uVar7 << (0x20 - uVar3 & 0xff) == 0) && (uVar6 & 0x7fffffff) == 0) {
      uVar8 = uVar8 & ~(uVar6 >> 0x1f);
    }
    return CONCAT44(param_4,uVar8) & 0x80000000ffffffff;
  }
  if (uVar8 - 0x14 == 0 || (int)uVar3 < -0xc) {
    uVar9 = uVar7 << (uVar6 + 0x20 & 0xff);
    uVar7 = uVar7 >> (uVar8 & 0xff) | param_4 << (uVar6 + 0x20 & 0xff);
    uVar3 = uVar7 + -((int)uVar9 >> 0x1f);
    if (uVar4 == 0 && (uVar9 & 0x7fffffff) == 0) {
      uVar3 = uVar3 & ~(uVar9 >> 0x1f);
    }
    return CONCAT44((param_4 & 0x80000000) +
                    ((param_4 & 0x7fffffff) >> (uVar8 & 0xff)) +
                    (uint)CARRY4(uVar7,-((int)uVar9 >> 0x1f)),uVar3);
  }
  uVar8 = 0xc - (uVar8 - 0x14);
  uVar3 = uVar7 << (uVar8 & 0xff);
  uVar8 = uVar7 >> (0x20 - uVar8 & 0xff) | param_4 << (uVar8 & 0xff);
  uVar7 = uVar8 + -((int)uVar3 >> 0x1f);
  if (uVar4 == 0 && (uVar3 & 0x7fffffff) == 0) {
    uVar7 = uVar7 & ~(uVar3 >> 0x1f);
  }
  return CONCAT44((param_4 & 0x80000000) + (uint)CARRY4(uVar8,-((int)uVar3 >> 0x1f)),uVar7);
}

//==== 0x48ab4  0x48a74-0x48b2b inclusive
ulonglong FUN_00048ab4(uint param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint unaff_r4;
  uint uVar4;
  uint uVar5;
  uint in_r12;
  bool bVar6;
  
  uVar4 = in_r12 & param_4 >> 0x14;
  if (unaff_r4 == in_r12 || uVar4 == in_r12) {
    bVar1 = (param_2 & 0x7fffffff) == 0;
    bVar6 = param_1 == 0 && bVar1;
    uVar5 = param_4;
    uVar2 = param_3;
    if (param_1 != 0 || !bVar1) {
      bVar6 = param_3 == 0 && (param_4 & 0x7fffffff) == 0;
      uVar5 = param_2;
      uVar2 = param_1;
    }
    uVar3 = uVar5;
    if (((bVar6) || ((unaff_r4 == in_r12 && (uVar2 != 0 || (uVar5 & 0xfffff) != 0)))) ||
       ((uVar4 == in_r12 &&
        (uVar2 = param_3, uVar3 = param_4, param_3 != 0 || (param_4 & 0xfffff) != 0)))) {
      return CONCAT44(uVar3,uVar2) | 0x7ff8000000000000;
    }
    return (ulonglong)((uVar5 ^ param_4) & 0x80000000 | 0x7ff00000) << 0x20;
  }
  bVar1 = (param_2 & 0x7fffffff) == 0;
  bVar6 = param_1 == 0 && bVar1;
  if (param_1 != 0 || !bVar1) {
    bVar6 = param_3 == 0 && (param_4 & 0x7fffffff) == 0;
  }
  if (bVar6) {
    return (ulonglong)((param_2 ^ param_4) & 0x80000000) << 0x20;
  }
  if (unaff_r4 == 0) {
    uVar5 = param_2 & 0x80000000;
    do {
      uVar2 = param_1 & 0x80000000;
      param_1 = param_1 << 1;
      param_2 = param_2 * 2 + (uint)(uVar2 != 0);
    } while ((param_2 & 0x100000) == 0);
    param_2 = param_2 | uVar5;
    if (uVar4 != 0) {
      return CONCAT44(param_2,param_1);
    }
  }
  do {
    uVar4 = param_3 & 0x80000000;
    param_3 = param_3 << 1;
    param_4 = param_4 * 2 + (uint)(uVar4 != 0);
  } while ((param_4 & 0x100000) == 0);
  return CONCAT44(param_2,param_1);
}

//==== 0x48b2c  0x48b2c-0x48c93 inclusive
ulonglong FUN_00048b2c(undefined4 param_1,uint param_2,uint param_3,uint param_4)

{
  uint extraout_r2;
  uint uVar1;
  uint extraout_r3;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint unaff_r5;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint extraout_r12;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  undefined8 uVar15;
  
  uVar15 = CONCAT44(param_2,param_1);
  uVar11 = 0x7ff;
  uVar5 = param_2 >> 0x14 & 0x7ff;
  bVar12 = uVar5 == 0;
  if (!bVar12) {
    unaff_r5 = param_4 >> 0x14 & 0x7ff;
    bVar12 = unaff_r5 == 0;
  }
  if (!bVar12) {
    bVar12 = uVar5 == 0x7ff;
  }
  if (!bVar12) {
    bVar12 = unaff_r5 == 0x7ff;
  }
  if (bVar12) {
    uVar15 = FUN_00048c9a();
    param_3 = extraout_r2;
    param_4 = extraout_r3;
    uVar11 = extraout_r12;
  }
  uVar7 = (uint)((ulonglong)uVar15 >> 0x20);
  uVar9 = (uint)uVar15;
  iVar6 = uVar5 - unaff_r5;
  if (param_3 == 0 && (param_4 & 0xfffff) == 0) {
    uVar5 = (uVar7 ^ param_4) & 0x80000000 | uVar7 & 0xfffff;
    bVar13 = SCARRY4(iVar6,uVar11 >> 1);
    uVar7 = iVar6 + (uVar11 >> 1);
    bVar12 = (int)uVar7 < 0;
    bVar14 = uVar7 == 0;
    if (!bVar14 && bVar12 == bVar13) {
      bVar13 = SBORROW4(uVar11,uVar7);
      bVar12 = (int)(uVar11 - uVar7) < 0;
      bVar14 = uVar11 == uVar7;
    }
    if (!bVar14 && bVar12 == bVar13) {
      return CONCAT44(uVar5 | uVar7 * 0x100000,uVar9);
    }
    uVar5 = uVar5 | 0x100000;
    uVar2 = 0;
    bVar14 = SBORROW4(uVar7,1);
    uVar7 = uVar7 - 1;
    bVar12 = uVar7 == 0;
    uVar11 = uVar7;
  }
  else {
    uVar2 = (param_4 & 0xfffff) << 8 | 0x10000000 | param_3 >> 0x18;
    uVar11 = param_3 << 8;
    uVar8 = (uVar7 & 0xfffff) << 8 | 0x10000000 | uVar9 >> 0x18;
    uVar9 = uVar9 * 0x100;
    uVar5 = (uVar7 ^ param_4) & 0x80000000;
    bVar12 = uVar2 <= uVar8;
    if (uVar8 == uVar2) {
      bVar12 = uVar11 <= uVar9;
    }
    iVar6 = iVar6 + (uint)bVar12;
    uVar7 = iVar6 + 0x3fd;
    if (bVar12 == false) {
      uVar2 = uVar2 >> 1;
      uVar11 = (uint)((param_3 >> 0x18 & 1) != 0) << 0x1f | (param_3 & 0xffffff) << 7;
    }
    uVar10 = uVar9 - uVar11;
    uVar8 = (uVar8 - uVar2) - (uint)(uVar9 < uVar11);
    uVar3 = uVar2 >> 1;
    uVar1 = (uint)((uVar2 & 1) != 0) << 0x1f | uVar11 >> 1;
    uVar9 = 0x100000;
    uVar11 = 0x80000;
    while( true ) {
      bVar12 = uVar1 <= uVar10;
      if (uVar3 < uVar8 || uVar8 - uVar3 < (uint)bVar12) {
        uVar10 = uVar10 - uVar1;
        uVar9 = uVar9 | uVar11;
        uVar8 = (uVar8 - uVar3) - (uint)!bVar12;
      }
      uVar4 = uVar3 >> 1;
      uVar2 = (uint)((uVar3 & 1) != 0) << 0x1f | uVar1 >> 1;
      bVar12 = uVar2 <= uVar10;
      if (uVar4 < uVar8 || uVar8 - uVar4 < (uint)bVar12) {
        uVar10 = uVar10 - uVar2;
        uVar9 = uVar9 | uVar11 >> 1;
        uVar8 = (uVar8 - uVar4) - (uint)!bVar12;
      }
      uVar1 = uVar3 >> 2;
      uVar4 = (uint)((uVar4 & 1) != 0) << 0x1f | uVar2 >> 1;
      bVar12 = uVar4 <= uVar10;
      if (uVar1 < uVar8 || uVar8 - uVar1 < (uint)bVar12) {
        uVar10 = uVar10 - uVar4;
        uVar9 = uVar9 | uVar11 >> 2;
        uVar8 = (uVar8 - uVar1) - (uint)!bVar12;
      }
      uVar3 = uVar3 >> 3;
      uVar1 = (uint)((uVar1 & 1) != 0) << 0x1f | uVar4 >> 1;
      bVar12 = uVar1 <= uVar10;
      if (uVar3 < uVar8 || uVar8 - uVar3 < (uint)bVar12) {
        uVar10 = uVar10 - uVar1;
        uVar9 = uVar9 | uVar11 >> 3;
        uVar8 = (uVar8 - uVar3) - (uint)!bVar12;
      }
      uVar2 = uVar8 | uVar10;
      if (uVar2 == 0) break;
      uVar8 = uVar8 << 4 | uVar10 >> 0x1c;
      uVar10 = uVar10 << 4;
      uVar3 = uVar3 << 3 | uVar1 >> 0x1d;
      uVar1 = (uVar4 >> 1) << 3;
      uVar11 = uVar11 >> 4;
      if (uVar11 == 0) {
        if ((uVar5 & 0x100000) != 0) goto LAB_00048c4a;
        uVar5 = uVar5 | uVar9;
        uVar9 = 0;
        uVar11 = 0x80000000;
      }
    }
    if ((uVar5 & 0x100000) == 0) {
      uVar5 = uVar5 | uVar9;
      uVar9 = 0;
    }
LAB_00048c4a:
    bVar13 = 0xfc < uVar7;
    bVar14 = SBORROW4(uVar7,0xfd);
    uVar4 = iVar6 + 0x300;
    bVar12 = uVar4 == 0;
    uVar11 = uVar4;
    if (bVar13 && !bVar12) {
      bVar13 = 0x6ff < uVar4;
      bVar14 = SBORROW4(uVar4,0x700);
      uVar11 = iVar6 - 0x400;
      bVar12 = uVar4 == 0x700;
    }
    if (!bVar13 || bVar12) {
      bVar12 = uVar3 <= uVar8;
      if (uVar8 == uVar3) {
        bVar12 = uVar1 <= uVar10;
      }
      if (uVar8 == uVar3 && uVar10 == uVar1) {
        bVar12 = (uVar9 & 1) != 0;
      }
      return CONCAT44(uVar5 + uVar7 * 0x100000 + (uint)CARRY4(uVar9,(uint)bVar12),uVar9 + bVar12);
    }
  }
  if (!bVar12 && (int)uVar11 < 0 == bVar14) {
    return (ulonglong)(uVar5 & 0x80000000 | 0x7ff00000) << 0x20;
  }
  if ((int)uVar7 < -0x35) {
    return (ulonglong)(uVar5 & 0x80000000) << 0x20;
  }
  uVar11 = -uVar7;
  uVar8 = uVar11 - 0x20;
  if (0x1f < (int)uVar11) {
    uVar7 = uVar9 >> (uVar8 & 0xff) | uVar5 << (0x20 - uVar8 & 0xff);
    uVar11 = (uVar5 >> (uVar8 & 0xff) & ~((uVar5 & 0x80000000) >> (uVar8 & 0xff))) -
             ((int)uVar7 >> 0x1f);
    if ((uVar2 == 0 && uVar9 << (0x20 - uVar8 & 0xff) == 0) && (uVar7 & 0x7fffffff) == 0) {
      uVar11 = uVar11 & ~(uVar7 >> 0x1f);
    }
    return CONCAT44(uVar5,uVar11) & 0x80000000ffffffff;
  }
  if (uVar11 - 0x14 == 0 || (int)uVar8 < -0xc) {
    uVar8 = uVar9 << (uVar7 + 0x20 & 0xff);
    uVar9 = uVar9 >> (uVar11 & 0xff) | uVar5 << (uVar7 + 0x20 & 0xff);
    uVar7 = uVar9 + -((int)uVar8 >> 0x1f);
    if (uVar2 == 0 && (uVar8 & 0x7fffffff) == 0) {
      uVar7 = uVar7 & ~(uVar8 >> 0x1f);
    }
    return CONCAT44((uVar5 & 0x80000000) +
                    ((uVar5 & 0x7fffffff) >> (uVar11 & 0xff)) +
                    (uint)CARRY4(uVar9,-((int)uVar8 >> 0x1f)),uVar7);
  }
  uVar11 = 0xc - (uVar11 - 0x14);
  uVar7 = uVar9 << (uVar11 & 0xff);
  uVar11 = uVar9 >> (0x20 - uVar11 & 0xff) | uVar5 << (uVar11 & 0xff);
  uVar9 = uVar11 + -((int)uVar7 >> 0x1f);
  if (uVar2 == 0 && (uVar7 & 0x7fffffff) == 0) {
    uVar9 = uVar9 & ~(uVar7 >> 0x1f);
  }
  return CONCAT44((uVar5 & 0x80000000) + (uint)CARRY4(uVar11,-((int)uVar7 >> 0x1f)),uVar9);
}

//==== 0x48c9a  0x48c9a-0x48cfb inclusive
ulonglong FUN_00048c9a(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  bool bVar2;
  uint unaff_r4;
  uint uVar3;
  uint uVar4;
  uint in_r12;
  bool bVar5;
  
  uVar3 = in_r12 & param_4 >> 0x14;
  if (unaff_r4 != in_r12 || uVar3 != in_r12) {
    if (unaff_r4 == in_r12) {
      if (param_1 == 0 && (param_2 & 0xfffff) == 0) {
        if (uVar3 != in_r12) {
LAB_00048b0c:
          return (ulonglong)((param_2 ^ param_4) & 0x80000000 | 0x7ff00000) << 0x20;
        }
        param_1 = param_3;
        param_2 = param_4;
      }
    }
    else if (uVar3 == in_r12) {
      if (param_3 == 0 && (param_4 & 0xfffff) == 0) {
LAB_00048ad0:
        return (ulonglong)((param_2 ^ param_4) & 0x80000000) << 0x20;
      }
      param_1 = param_3;
      param_2 = param_4;
    }
    else {
      bVar2 = (param_2 & 0x7fffffff) == 0;
      bVar5 = param_1 == 0 && bVar2;
      if (param_1 != 0 || !bVar2) {
        bVar5 = param_3 == 0 && (param_4 & 0x7fffffff) == 0;
      }
      if (!bVar5) {
        if (unaff_r4 == 0) {
          uVar4 = param_2 & 0x80000000;
          do {
            uVar1 = param_1 & 0x80000000;
            param_1 = param_1 << 1;
            param_2 = param_2 * 2 + (uint)(uVar1 != 0);
          } while ((param_2 & 0x100000) == 0);
          param_2 = param_2 | uVar4;
          if (uVar3 != 0) {
            return CONCAT44(param_2,param_1);
          }
        }
        do {
          uVar3 = param_3 & 0x80000000;
          param_3 = param_3 << 1;
          param_4 = param_4 * 2 + (uint)(uVar3 != 0);
        } while ((param_4 & 0x100000) == 0);
        return CONCAT44(param_2,param_1);
      }
      if (param_1 != 0 || (param_2 & 0x7fffffff) != 0) goto LAB_00048b0c;
      if (param_3 != 0 || (param_4 & 0x7fffffff) != 0) goto LAB_00048ad0;
    }
  }
  return CONCAT44(param_2,param_1) | 0x7ff8000000000000;
}

//==== 0x48cfc  0x48cfc-0x48d49 inclusive
uint FUN_00048cfc(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = param_2 * 2 + 0x200000;
  if (param_2 * 2 < 0xffe00000) {
    if (-1 < iVar2) {
      return 0;
    }
    uVar1 = iVar2 >> 0x15;
    uVar3 = -uVar1 - 0x3e1;
    if (uVar1 < 0xfffffc20 && uVar3 != 0) {
      uVar1 = (param_2 << 0xb | 0x80000000 | param_1 >> 0x15) >> (uVar3 & 0xff);
      if ((param_2 & 0x80000000) != 0) {
        uVar1 = -uVar1;
      }
      return uVar1;
    }
  }
  else if (param_1 != 0 || (param_2 & 0xfffff) != 0) {
    return 0;
  }
  param_2 = param_2 & 0x80000000;
  if (param_2 == 0) {
    param_2 = 0x7fffffff;
  }
  return param_2;
}

//==== 0x48d58  0x48d58-0x48d65 inclusive
uint FUN_00048d58(void)

{
  uint uVar1;
  undefined4 in_cr14;
  
  uVar1 = coprocessor_movefromRt(0xf,0,in_cr14);
  coprocessor_movefromRt2(0xf,0,in_cr14);
  return (uint)((ulonglong)uVar1 * (ulonglong)DAT_00048d68/*=0x57619f1*/ >> 0x29);
}

//==== 0x48d6c  0x48d6c-0x48d79 inclusive
uint FUN_00048d6c(void)

{
  uint uVar1;
  undefined4 in_cr14;
  
  uVar1 = coprocessor_movefromRt(0xf,0,in_cr14);
  coprocessor_movefromRt2(0xf,0,in_cr14);
  return (uint)((ulonglong)uVar1 * (ulonglong)DAT_00048d7c/*=0xaaaaaaab*/ >> 0x24);
}

//==== 0x48d80  0x48d80-0x48da3 inclusive
void FUN_00048d80(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  undefined4 in_cr14;
  
  uVar5 = coprocessor_movefromRt(0xf,0,in_cr14);
  iVar2 = coprocessor_movefromRt2(0xf,0,in_cr14);
  uVar4 = iVar2 + (uint)CARRY4(uVar5,param_1 * 0x18);
  do {
    uVar1 = coprocessor_movefromRt(0xf,0,in_cr14);
    uVar3 = coprocessor_movefromRt2(0xf,0,in_cr14);
    bVar6 = uVar3 <= uVar4;
    if (uVar4 == uVar3) {
      bVar6 = uVar1 <= uVar5 + param_1 * 0x18;
    }
  } while (bVar6);
  return;
}

//==== 0x48da4  0x48da4-0x48dad inclusive
void FUN_00048da4(int param_1)

{
  FUN_00048d80(param_1 * 1000);
  return;
}

//==== 0x48dae  0x48dae-0x48dbb inclusive
uint FUN_00048dae(void)

{
  uint uVar1;
  undefined4 in_cr0;
  undefined4 in_cr1;
  
  uVar1 = coprocessor_movefromRt(0xf,0,1,in_cr1,in_cr0);
  coprocessor_moveto(0xf,0,1,uVar1 | 0x40,in_cr1,in_cr0);
  return uVar1 | 0x40;
}

//==== 0x48dbc  0x48dbc-0x48dd5 inclusive
void FUN_00048dbc(void)

{
  uint uVar1;
  undefined4 in_cr0;
  undefined4 in_cr1;
  
  uVar1 = coprocessor_movefromRt(0xf,0,0,in_cr1,in_cr0);
  FUN_00048d80(100);
  coprocessor_moveto(0xf,0,0,uVar1 | 4,in_cr1,in_cr0);
  InstructionSynchronizationBarrier(0xf);
  return;
}

//==== 0x48dd8  0x48dd8-0x48df5 inclusive
void FUN_00048dd8(void)

{
  uint uVar1;
  undefined4 in_cr0;
  undefined4 in_cr1;
  
  (*DAT_00048df8/*=0x47b80*/)();
  uVar1 = coprocessor_movefromRt(0xf,0,0,in_cr1,in_cr0);
  coprocessor_moveto(0xf,0,0,uVar1 & 0xfffffffb,in_cr1,in_cr0);
  InstructionSynchronizationBarrier(0xf);
  return;
}

//==== 0x48dfc  0x48dfc-0x48e8b inclusive
void FUN_00048dfc(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 in_cr0;
  undefined4 in_cr1;
  undefined4 in_cr2;
  undefined4 in_cr3;
  undefined4 in_cr7;
  undefined4 in_cr8;
  
  if (0x7ff < param_1) {
    param_1 = 0x800;
  }
  iVar1 = param_1 * 0x100000;
  *(undefined4 *)(iVar1 + 0x3ff00000) = 0xdee;
  uVar5 = 0x100000;
  puVar3 = (uint *)(iVar1 + 0x3ff00004);
  do {
    uVar2 = uVar5 | 0xde2;
    uVar5 = uVar5 + 0x100000;
    *puVar3 = uVar2;
    puVar3 = puVar3 + 1;
  } while (uVar5 != 0x40000000);
  uVar5 = 0x40000000;
  puVar3 = (uint *)(iVar1 + 0x3ff01000);
  do {
    uVar2 = uVar5 | 0xdee;
    uVar5 = uVar5 + 0x100000;
    puVar4 = puVar3 + 1;
    *puVar3 = uVar2;
    puVar3 = puVar4;
  } while (uVar5 != 0);
  coprocessor_moveto(0xf,0,0,0,in_cr8,in_cr7);
  uVar5 = (uint)(iVar1 + 0x3ff00000) | 0x13;
  coprocessor_moveto(0xf,0,0,uVar5,in_cr2,in_cr0);
  coprocessor_moveto(0xf,0,1,uVar5,in_cr2,in_cr0);
  coprocessor_moveto(0xf,0,0,0x55555555,in_cr3,in_cr0);
  InstructionSynchronizationBarrier(0xf);
  FUN_00048dae(uVar5,uVar2,puVar4,0x55555555);
  uVar5 = coprocessor_movefromRt(0xf,0,0,in_cr1,in_cr0);
  FUN_00048d80(100);
  coprocessor_moveto(0xf,0,0,uVar5 & 0xfffffffb | 0x1001,in_cr1,in_cr0);
  InstructionSynchronizationBarrier(0xf);
  return;
}

//==== 0x48e8c  0x48e8c-0x48ebb inclusive
void FUN_00048e8c(void)

{
  uint uVar1;
  undefined4 in_cr0;
  undefined4 in_cr1;
  undefined4 in_cr5;
  undefined4 in_cr7;
  
  uVar1 = coprocessor_movefromRt(0xf,0,0,in_cr1,in_cr0);
  FUN_00048d80(100);
  coprocessor_moveto(0xf,0,0,uVar1 & 0xffffeff8,in_cr1,in_cr0);
  InstructionSynchronizationBarrier(0xf);
  coprocessor_moveto(0xf,0,0,0,in_cr7,in_cr5);
  coprocessor_moveto(0xf,0,6,0,in_cr7,in_cr5);
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return;
}

//==== 0x48ebc  0x48ebc-0x48ec5 inclusive
void FUN_00048ebc(void)

{
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return;
}

//==== 0x48ec6  0x48ec6-0x48ecf inclusive
void FUN_00048ec6(code *UNRECOVERED_JUMPTABLE,undefined4 param_2)

{
  undefined4 in_cr5;
  undefined4 in_cr7;
  
  coprocessor_moveto(0xf,0,6,0,in_cr7,in_cr5);
                    /* WARNING: Could not recover jumptable at 0x00048ece. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(UNRECOVERED_JUMPTABLE,param_2,0);
  return;
}

//==== 0x48ed2  0x48ed2-0x48edb inclusive
void FUN_00048ed2(code *UNRECOVERED_JUMPTABLE,int param_2)

{
                    /* WARNING: Could not recover jumptable at 0x00048eda. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(UNRECOVERED_JUMPTABLE,param_2,param_2 + 0x200000);
  return;
}

//==== 0x48ee0  0x48ee0-0x48f09 inclusive
void FUN_00048ee0(undefined4 param_1)

{
  uint uVar1;
  undefined4 in_cr0;
  undefined4 in_cr12;
  
  DataMemoryBarrier(0x1f);
  *DAT_00048f0c/*=0x8001004*/ = param_1;
  DataMemoryBarrier(0x1f);
  DAT_00048f0c/*=0x8001004*/[1] = 0;
  uVar1 = coprocessor_movefromRt(0xf,0,2,in_cr12,in_cr0);
  DataSynchronizationBarrier(0xf);
  coprocessor_moveto(0xf,0,2,uVar1 | 3,in_cr12,in_cr0);
  InstructionSynchronizationBarrier(0xf);
  do {
    WaitForInterrupt();
  } while( true );
}

//==== 0x48f10  0x48f10-0x48f31 inclusive
undefined4 FUN_00048f10(void)

{
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *DAT_00048f34/*=0x8000200*/ = *DAT_00048f34/*=0x8000200*/ | 1;
  return 0;
}

//==== 0x48f38  0x48f38-0x48f97 inclusive
undefined4 FUN_00048f38(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_00048f9c/*=0x202446c*/;
  uVar1 = DAT_00048f98/*=0x40a05*/;
  DataMemoryBarrier(0x1f);
  *DAT_00048f9c/*=0x202446c*/ = DAT_00048f98/*=0x40a05*/;
  DataMemoryBarrier(0x1f);
  puVar2[0x80] = uVar1;
  puVar2 = DAT_00048fa0/*=0x2023a14*/;
  DataMemoryBarrier(0x1f);
  *DAT_00048fa0/*=0x2023a14*/ = 0x3f;
  DataMemoryBarrier(0x1f);
  puVar2[0x80] = 0x7f;
  DataMemoryBarrier(0x1f);
  puVar2[0x100] = 0xf;
  puVar2 = DAT_00048fa4/*=0x2024014*/;
  DataMemoryBarrier(0x1f);
  *DAT_00048fa4/*=0x2024014*/ = 0xf1;
  DataMemoryBarrier(0x1f);
  puVar2[0x80] = 0xf1;
  DataMemoryBarrier(0x1f);
  puVar2[-0x802] = 1;
  DataMemoryBarrier(0x1f);
  puVar2[-0x782] = 1;
  return 0;
}

//==== 0x48fa8  0x48fa8-0x48fa9 inclusive
void FUN_00048fa8(void)

{
  return;
}

//==== 0x48fac  0x48fac-0x4902b inclusive
undefined4 FUN_00048fac(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_0005d9f0();
  uVar3 = DAT_00049034/*"board gpio withstand voltage auto mode\n"*/;
  if (iVar2 == 1) {
    DataMemoryBarrier(0x1f);
    *DAT_0004902c/*=0x2000040*/ = DAT_00049030/*=0x1155550*/;
    FUN_0004993c(uVar3);
  }
  FUN_0005d744(0);
  iVar2 = FUN_0005d9f0();
  if (iVar2 == 0) {
    DataMemoryBarrier(0x1f);
    uVar3 = DAT_0004903c/*=0xa7070025*/;
  }
  else {
    iVar2 = FUN_0005d9f0();
    if (iVar2 != 1) goto LAB_00048fe2;
    DataMemoryBarrier(0x1f);
    uVar3 = DAT_00049048/*=0xa7060025*/;
  }
  puVar1 = DAT_00049038/*=0x8000144*/;
  *DAT_00049038/*=0x8000144*/ = uVar3;
  DataMemoryBarrier(0x1f);
  *puVar1 = uVar3;
LAB_00048fe2:
  if ((*(byte *)(DAT_00049040/*=0x47000*/ + 0x28) & 0xf) == 2) {
    FUN_0004993c(DAT_00049044/*"EMMC 0x%x\n"*/);
    uVar3 = 0x348;
  }
  else {
    uVar3 = 800;
  }
  FUN_0005d714(uVar3);
  FUN_000491b8();
  FUN_0005d744(0);
  FUN_0004b2e8();
  FUN_00048f10();
  return 0;
}

//==== 0x49050  0x49050-0x4905d inclusive
undefined4 FUN_00049050(void)

{
  FUN_00048f38();
  FUN_0005d9ee();
  return 0;
}

//==== 0x49062  0x49062-0x49065 inclusive
undefined4 FUN_00049062(void)

{
  return 0;
}

//==== 0x49066  0x49066-0x4906f inclusive
undefined4 FUN_00049066(void)

{
  FUN_00048dbc();
  return 0;
}

//==== 0x49074  0x49074-0x4907d inclusive
undefined4 FUN_00049074(void)

{
  FUN_00048dd8();
  return 0;
}

//==== 0x49082  0x49082-0x49097 inclusive
void FUN_00049082(uint *param_1,uint param_2)

{
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *param_1 = 1 << (param_2 & 0xff) | *param_1;
  return;
}

//==== 0x49098  0x49098-0x4910d inclusive
void FUN_00049098(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint *puVar2;
  int iVar3;
  
  uVar1 = FUN_00049082(param_1,0x1e);
  puVar2 = (uint *)FUN_00049082(uVar1,0x1b);
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *puVar2 = param_2[3] << 0x10 | param_2[1] << 0x14 | param_2[2] | *param_2 << 8 |
            DAT_00049110/*=0xffc000f0*/ & *puVar2;
  FUN_00048d80(0x14);
  uVar1 = FUN_00049082(param_1,0x1f);
  uVar1 = FUN_00049082(uVar1,0x1d);
  FUN_00049082(uVar1,0x1a);
  do {
    DataMemoryBarrier(0x1f);
  } while (*param_1 << 5 < 0);
  iVar3 = 3;
  do {
    do {
      DataMemoryBarrier(0x1f);
    } while (-1 < *param_1 << 3);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  FUN_00048d80(0x14,*param_1 << 5,*param_1 << 3,param_4);
  return;
}

//==== 0x49114  0x49114-0x491b3 inclusive
void FUN_00049114(uint *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  param_1[7] = param_1[7] & 0xfcffffff;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *param_1 = *param_1 & 0xf7ffffff;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *param_1 = *param_1 & 0xdfffffff;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *param_1 = param_2[3] << 0x10 | param_2[1] << 0x14 | param_2[2] | *param_2 << 8 |
             DAT_000491b4/*=0xffc000f0*/ & *param_1;
  FUN_00048d80(0x14);
  uVar1 = FUN_00049082(param_1,0x1d);
  FUN_00049082(uVar1,0x1a);
  do {
    DataMemoryBarrier(0x1f);
  } while ((int)(*param_1 << 5) < 0);
  iVar2 = 3;
  do {
    do {
      DataMemoryBarrier(0x1f);
    } while (-1 < (int)(*param_1 << 3));
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_00048d80(0x14);
  FUN_00049082(param_1,0x1b);
  FUN_00048d80(0x14);
  return;
}

//==== 0x491b8  0x491b8-0x49483 inclusive
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
  FUN_00049082(DAT_00049484/*=0x2002020*/,0x18);
  FUN_00049082(DAT_00049488/*=0x20020a0*/,0x18);
  FUN_00049082(DAT_0004948c/*=0x20020c0*/,0x18);
  FUN_00049082(DAT_00049490/*=0x20020e0*/,0x18);
  FUN_00049082(DAT_00049494/*=0x2002120*/,0x18);
  FUN_00049082(DAT_00049498/*=0x2002140*/,0x18);
  FUN_00049082(DAT_0004949c/*=0x2002160*/,0x18);
  FUN_00049082(DAT_000494a0/*=0x2002220*/,0x18);
  FUN_00049082(DAT_000494a4/*=0x2002240*/,0x18);
  FUN_00049082(DAT_000494a8/*=0x2002260*/,0x18);
  FUN_00049082(DAT_000494ac/*=0x2002280*/,0x18);
  FUN_00049082(DAT_000494b0/*=0x20022a0*/,0x18);
  FUN_00049082(DAT_000494b4/*=0x20022e0*/,0x18);
  puVar3 = DAT_00049500/*=0x887201c*/;
  puVar2 = DAT_000494fc/*=0x887101c*/;
  puVar8 = DAT_000494c0/*=0x8871000*/;
  puVar1 = DAT_000494bc/*=0x887301c*/;
  DataMemoryBarrier(0x1f);
  uVar5 = *DAT_000494b8/*=0x7090160*/ & 0x4000;
  if (uVar5 == 0) {
    uVar4 = *DAT_000494b8/*=0x7090160*/ & 0x8000;
    if (uVar4 == 0) {
      local_30 = 0x14;
      local_2c = uVar4;
      local_28 = uVar4;
      uStack_24 = uVar4;
      FUN_00049098(DAT_000494c0/*=0x8871000*/,&local_30);
      local_30 = 0x2a;
      local_2c = uVar4;
      local_28 = uVar4;
      uStack_24 = uVar4;
      FUN_00049114(puVar8,&local_30);
      DataMemoryBarrier(0x1f);
      puVar7 = puVar8 + 0x400;
      FUN_0004993c(DAT_000494f0/*"cpul clk 0x%x!\n"*/,*puVar8);
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
      FUN_0004993c(DAT_000494f4/*"cpub clk 0x%x!\n"*/,*puVar7);
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
      FUN_0004993c(DAT_000494f8/*"dsu clk 0x%x!\n"*/,*puVar8);
    }
    else {
      local_30 = 0x14;
      local_2c = uVar5;
      local_28 = uVar5;
      uStack_24 = uVar5;
      FUN_00049098(DAT_000494c0/*=0x8871000*/,&local_30);
      local_30 = 0x27;
      local_2c = uVar5;
      local_28 = uVar5;
      uStack_24 = uVar5;
      FUN_00049114(DAT_000494c0/*=0x8871000*/,&local_30);
      local_30 = 0x14;
      local_2c = uVar5;
      local_28 = uVar5;
      uStack_24 = uVar5;
      FUN_00049098(DAT_000494c4/*=0x8872000*/,&local_30);
      local_30 = 0x27;
      local_2c = uVar5;
      local_28 = uVar5;
      uStack_24 = uVar5;
      FUN_00049114(DAT_000494c4/*=0x8872000*/,&local_30);
      local_30 = 0x14;
      local_2c = uVar5;
      local_28 = uVar5;
      uStack_24 = uVar5;
      FUN_00049098(DAT_000494c8/*=0x8873000*/,&local_30);
      local_30 = 0x1e;
      local_2c = uVar5;
      local_28 = uVar5;
      uStack_24 = uVar5;
      FUN_00049114(DAT_000494c8/*=0x8873000*/,&local_30);
    }
    uVar5 = DAT_000494cc/*=0xf8fcffff*/;
    DataMemoryBarrier(0x1f);
    DataMemoryBarrier(0x1f);
    *puVar2 = *puVar2 & DAT_000494cc/*=0xf8fcffff*/ | 0x3000000;
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
  *DAT_000494d0/*=0x2002518*/ = *DAT_000494d0/*=0x2002518*/ & 0xfcffffe0;
  puVar1 = DAT_000494d8/*=0x2002580*/;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *DAT_000494d4/*=0x7010010*/ = *DAT_000494d4/*=0x7010010*/ & 0xf8ffffff | 0x4000000;
  iVar6 = DAT_000494dc/*=0x186a0*/;
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
  FUN_0004993c(DAT_000494e0/*"nsi clk gating update failed!\n"*/);
LAB_00049362:
  iVar6 = DAT_000494dc/*=0x186a0*/;
  puVar2 = DAT_000494d8/*=0x2002580*/;
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
  FUN_0004993c(DAT_000494e4/*"nsi clk update failed!\n"*/);
LAB_00049394:
  puVar1 = DAT_000494e8/*=0x7090000*/;
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
    uVar5 = DAT_000494ec/*=0x16aa4001*/ | *puVar1;
  }
  else {
    uVar5 = uVar5 | 0xc;
  }
  DataMemoryBarrier(0x1f);
  *puVar1 = uVar5;
  return;
}

//==== 0x49504  0x49504-0x49505 inclusive
void FUN_00049504(void)

{
  return;
}

//==== 0x49508  0x49508-0x49555 inclusive
undefined4 FUN_00049508(void)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_0004955c/*=0x2002fc4*/;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *DAT_00049558/*=0x2002fc0*/ = *DAT_00049558/*=0x2002fc0*/ & 0xffffffe0 | 0x80000000;
  uVar2 = *puVar1;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *puVar1 = uVar2 & 0xfffeffff;
  FUN_00048d80(2);
  DataMemoryBarrier(0x1f);
  *puVar1 = uVar2 & 0xfffeffff | 0x10000;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *puVar1 = *puVar1 | 1;
  return 0;
}

//==== 0x49560  0x49560-0x495a3 inclusive
void FUN_00049560(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  puVar1 = DAT_000495a4/*=0x2002e00*/;
  DataMemoryBarrier(0x1f);
  uVar2 = 1 << (param_1 + 0x10 & 0xff);
  uVar3 = *DAT_000495a4/*=0x2002e00*/ & ~uVar2;
  DataMemoryBarrier(0x1f);
  *DAT_000495a4/*=0x2002e00*/ = uVar3;
  DataMemoryBarrier(0x1f);
  *puVar1 = uVar2 | uVar3;
  DataMemoryBarrier(0x1f);
  uVar2 = 1 << (param_1 & 0xff);
  uVar3 = *puVar1 & ~uVar2;
  DataMemoryBarrier(0x1f);
  *puVar1 = uVar3;
  DataMemoryBarrier(0x1f);
  *puVar1 = uVar2 | uVar3;
  return;
}

//==== 0x495a8  0x495a8-0x495b7 inclusive
void FUN_000495a8(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = (char *)(param_1 + -1);
  do {
    cVar1 = *param_2;
    pcVar2 = pcVar2 + 1;
    *pcVar2 = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  return;
}

//==== 0x495b8  0x495b8-0x495cd inclusive
void FUN_000495b8(int param_1,char *param_2)

{
  char *pcVar1;
  
  pcVar1 = (char *)(param_1 + -1);
  do {
    pcVar1 = pcVar1 + 1;
    if (*pcVar1 != *param_2) {
      return;
    }
    param_2 = param_2 + 1;
  } while (*pcVar1 != '\0');
  return;
}

//==== 0x495ce  0x495ce-0x495ef inclusive
int FUN_000495ce(int param_1,char *param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar3 = (char *)(param_1 + -1);
  pcVar2 = param_2;
  while( true ) {
    if (pcVar2 == param_2 + param_3) {
      return 0;
    }
    pcVar3 = pcVar3 + 1;
    iVar1 = (int)(char)(*pcVar3 - *pcVar2);
    if (iVar1 != 0) break;
    pcVar2 = pcVar2 + 1;
    if (*pcVar3 == '\0') {
      return 0;
    }
  }
  return iVar1;
}

//==== 0x495f0  0x495f0-0x495ff inclusive
int FUN_000495f0(char *param_1)

{
  char *pcVar1;
  
  pcVar1 = param_1;
  while (*pcVar1 != '\0') {
    pcVar1 = pcVar1 + 1;
  }
  return (int)pcVar1 - (int)param_1;
}

//==== 0x49600  0x49600-0x4961f inclusive
char * FUN_00049600(char *param_1,char param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  
  iVar1 = FUN_000495f0();
  pcVar2 = param_1 + iVar1;
  do {
    pcVar3 = pcVar2 + -1;
    if (*pcVar2 == param_2) {
      return pcVar2;
    }
    pcVar2 = pcVar3;
  } while (param_1 <= pcVar3);
  return (char *)0x0;
}

//==== 0x49620  0x49620-0x49623 inclusive
void thunk_FUN_00047c40(void)

{
  (*DAT_00049628/*=0x47c40*/)();
  return;
}

//==== 0x4962c  0x4962c-0x4962f inclusive
void thunk_FUN_00047d1c(void)

{
  (*DAT_00049634/*=0x47d1c*/)();
  return;
}

//==== 0x49638  0x49638-0x49655 inclusive
int FUN_00049638(int param_1,int param_2,int param_3)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    if (iVar4 == param_3) {
      return 0;
    }
    pcVar1 = (char *)(param_1 + iVar4);
    pcVar2 = (char *)(param_2 + iVar4);
    iVar4 = iVar4 + 1;
    iVar3 = (int)(char)(*pcVar1 - *pcVar2);
  } while (iVar3 == 0);
  return iVar3;
}

//==== 0x49656  0x49656-0x49671 inclusive
char * FUN_00049656(char *param_1,char param_2,int param_3)

{
  char *pcVar1;
  
  pcVar1 = param_1;
  while( true ) {
    if (pcVar1 == param_1 + param_3) {
      return (char *)0x0;
    }
    if (*pcVar1 == param_2) break;
    pcVar1 = pcVar1 + 1;
  }
  return pcVar1;
}

//==== 0x49682  0x49682-0x496b3 inclusive
void FUN_00049682(undefined4 *param_1,uint *param_2,uint param_3)

{
  char cVar1;
  char *pcVar2;
  byte bVar3;
  
  bVar3 = 0;
  while( true ) {
    if (*param_2 < param_3) break;
    *param_2 = *param_2 - param_3;
    bVar3 = bVar3 + 1;
  }
  if ((*(char *)(param_1 + 1) != '\0') || (bVar3 != 0)) {
    pcVar2 = (char *)*param_1;
    if (bVar3 < 10) {
      cVar1 = '0';
    }
    else {
      cVar1 = 'W';
    }
    *param_1 = pcVar2 + 1;
    *pcVar2 = bVar3 + cVar1;
    *(undefined1 *)(param_1 + 1) = 1;
  }
  return;
}

//==== 0x496b4  0x496b4-0x4988b inclusive
undefined4 FUN_000496b4(int *param_1,byte *param_2,int *param_3)

{
  byte bVar1;
  uint uVar2;
  undefined1 *puVar3;
  char *pcVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  char *pcVar8;
  undefined4 uVar9;
  bool bVar10;
  int local_38;
  char local_34;
  undefined1 local_33 [15];
  
  do {
    bVar1 = *param_2;
    if (bVar1 == 0) {
      return 0;
    }
    piVar6 = param_3;
    if (bVar1 == 0x25) {
      uVar2 = (uint)param_2[1];
      iVar5 = 0;
      if (uVar2 == 0x2d) {
        uVar2 = (uint)param_2[2];
        param_2 = param_2 + 3;
      }
      else {
        param_2 = param_2 + 2;
      }
      bVar10 = uVar2 == 0x30;
      if (bVar10) {
        uVar2 = (uint)*param_2;
        param_2 = param_2 + 1;
      }
      if (uVar2 - 0x30 < 10) {
        while (uVar2 - 0x30 < 10) {
          iVar5 = iVar5 * 10 + uVar2 + -0x30;
          uVar2 = (uint)*param_2;
          param_2 = param_2 + 1;
        }
      }
      if (uVar2 == 0x6c) {
        uVar2 = (uint)*param_2;
        param_2 = param_2 + 1;
      }
      *param_1 = (int)&local_34;
      *(undefined1 *)(param_1 + 1) = 0;
      if (uVar2 == 100) {
LAB_00049782:
        local_38 = *param_3;
        piVar6 = param_3 + 1;
        if ((uVar2 == 100) && (local_38 < 0)) {
          local_38 = -local_38;
          *param_1 = (int)local_33;
          local_34 = '-';
        }
        if (local_38 == 0) {
          puVar3 = (undefined1 *)*param_1;
          *param_1 = (int)(puVar3 + 1);
          *puVar3 = 0x30;
LAB_000497b2:
          piVar6 = param_3 + 1;
          *(undefined1 *)(param_1 + 1) = 1;
        }
        else {
          iVar7 = 10;
          uVar2 = DAT_00049894/*=0x3b9aca00*/;
          do {
            FUN_00049682(param_1,&local_38,uVar2);
            iVar7 = iVar7 + -1;
            uVar2 = (uint)((ulonglong)uVar2 * (ulonglong)DAT_0004988c/*=0xcccccccd*/ >> 0x23);
          } while (iVar7 != 0);
        }
LAB_000497da:
        pcVar8 = &local_34;
      }
      else {
        if (uVar2 < 0x65) {
          if (uVar2 == 0x25) {
            local_34 = '%';
            *param_1 = (int)local_33;
          }
          else if (uVar2 == 99) {
            iVar7 = *param_3;
            piVar6 = param_3 + 1;
            *param_1 = (int)local_33;
            local_34 = (char)iVar7;
          }
          else if (uVar2 == 0) {
            return 0;
          }
          goto LAB_000497da;
        }
        if (uVar2 != 0x73) {
          if (uVar2 < 0x74) {
            if (uVar2 == 0x70) {
              piVar6 = param_3 + 1;
              while ((*(byte *)(DAT_00049890/*=0x5e430*/ + (uint)*param_2) & 7) != 0) {
                param_2 = param_2 + 1;
              }
            }
          }
          else {
            if (uVar2 == 0x75) goto LAB_00049782;
            if (uVar2 == 0x78) {
              local_38 = *param_3;
              piVar6 = param_3 + 1;
              if (local_38 == 0) {
                *param_1 = (int)local_33;
                local_34 = '0';
                goto LAB_000497b2;
              }
              iVar7 = 8;
              uVar2 = 0x10000000;
              do {
                FUN_00049682(param_1,&local_38,uVar2);
                iVar7 = iVar7 + -1;
                uVar2 = uVar2 >> 4;
              } while (iVar7 != 0);
            }
          }
          goto LAB_000497da;
        }
        piVar6 = param_3 + 1;
        pcVar8 = (char *)*param_3;
      }
      *(undefined1 *)*param_1 = 0;
      *param_1 = (int)pcVar8;
      while (pcVar4 = (char *)*param_1, *param_1 = (int)(pcVar4 + 1), *pcVar4 != '\0') {
        if (iVar5 == 0) goto LAB_00049872;
        iVar5 = iVar5 + -1;
      }
      if (bVar10) {
        uVar9 = 0x30;
      }
      else {
        uVar9 = 0x20;
      }
      while (bVar10 = iVar5 != 0, iVar5 = iVar5 + -1, bVar10) {
        (*(code *)param_1[3])(param_1,uVar9);
      }
LAB_00049872:
      if (pcVar8 != (char *)0x0) {
        for (; *pcVar8 != '\0'; pcVar8 = pcVar8 + 1) {
          (*(code *)param_1[3])(param_1);
        }
      }
    }
    else {
      if (bVar1 == 10) {
        (*(code *)param_1[3])(param_1,0xd);
      }
      param_2 = param_2 + 1;
      (*(code *)param_1[3])(param_1,bVar1);
    }
    param_3 = piVar6;
  } while( true );
}

//==== 0x49898  0x49898-0x498b5 inclusive
undefined4 FUN_00049898(uint param_1,int param_2)

{
  if (8 < param_1) {
    return 0xffffffff;
  }
  *DAT_000498b8/*=0x60670*/ = (char)param_1;
  if (param_2 == 0) {
    *DAT_000498bc/*=0x82dd4*/ = 0;
  }
  else {
    *DAT_000498bc/*=0x82dd4*/ = 1;
  }
  return 0;
}

//==== 0x498c0  0x498c0-0x498c5 inclusive
undefined1 FUN_000498c0(void)

{
  return *DAT_000498c8/*=0x60670*/;
}

//==== 0x498cc  0x498cc-0x498db inclusive
byte FUN_000498cc(void)

{
  byte bVar1;
  
  bVar1 = *DAT_000498dc/*=0x60670*/;
  if (*DAT_000498e0/*=0x82dd4*/ != '\0') {
    bVar1 = bVar1 | 0x80;
  }
  return bVar1;
}

//==== 0x498e4  0x498e4-0x49907 inclusive
void FUN_000498e4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*DAT_00049908/*=0x60670*/ != '\0') {
    uStack_28 = param_3;
    uStack_24 = param_4;
    uStack_c = param_2;
    uStack_8 = param_3;
    uStack_4 = param_4;
    FUN_000496b4(&uStack_28,param_1,&uStack_c,DAT_0004990c/*=0x4967d*/,param_1,&uStack_c);
  }
  return;
}

//==== 0x49910  0x49910-0x49937 inclusive
void FUN_00049910(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_20 = param_3;
  uStack_1c = param_4;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_000496b4(&uStack_20,param_2,&uStack_8,DAT_00049938/*=0x49673*/,param_1,&uStack_8);
  *param_1 = 0;
  return;
}

//==== 0x4993c  0x4993c-0x49981 inclusive
void FUN_0004993c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  char local_3c [12];
  undefined1 auStack_30 [12];
  undefined4 local_24;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*DAT_00049984/*=0x60670*/ != '\0') {
    iVar2 = 0;
    uStack_c = param_2;
    uStack_8 = param_3;
    uStack_4 = param_4;
    uVar1 = FUN_00048d58();
    FUN_00049910(local_3c,DAT_00049988/*"[%d]"*/,uVar1);
    do {
      if (local_3c[iVar2] == '\0') break;
      iVar2 = iVar2 + 1;
      FUN_0004a540();
    } while (iVar2 != 0xc);
    local_24 = DAT_0004998c/*=0x4967d*/;
    FUN_000496b4(auStack_30,param_1,&uStack_c,DAT_0004998c/*=0x4967d*/,&uStack_c);
  }
  return;
}

//==== 0x49990  0x49990-0x499f5 inclusive
undefined4 FUN_00049990(int *param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  FUN_00048dbc();
  param_2 = param_2 >> 2;
  iVar6 = param_1[5];
  iVar5 = 0;
  param_1[5] = DAT_000499f8/*=0x5f0a6c39*/;
  uVar1 = param_2;
  piVar3 = param_1;
  do {
    uVar1 = uVar1 - 4;
    iVar5 = iVar5 + *piVar3 + piVar3[1] + piVar3[2] + piVar3[3];
    piVar3 = piVar3 + 4;
  } while (3 < uVar1);
  piVar4 = param_1 + ((param_2 - 4 >> 2) + 1) * 4;
  piVar3 = piVar4 + (param_2 & 3);
  for (; piVar4 != piVar3; piVar4 = piVar4 + 1) {
    iVar5 = iVar5 + *piVar4;
  }
  param_1[5] = iVar6;
  FUN_00048dd8();
  uVar2 = 0;
  if (iVar5 != iVar6) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

//==== 0x499fc  0x499fc-0x49a3d inclusive
int FUN_000499fc(int *param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  
  param_2 = param_2 >> 2;
  iVar1 = 0;
  do {
    param_2 = param_2 + param_3 * -4;
    iVar1 = iVar1 + *param_1 + param_1[1] + param_1[2] + param_1[3];
    piVar2 = param_1 + 4;
    param_1 = param_1 + 4;
  } while (3 < (int)param_2);
  for (; 0 < (int)param_2; param_2 = param_2 - 1) {
    iVar1 = iVar1 + *piVar2;
    piVar2 = piVar2 + 1;
  }
  return (DAT_00049a40/*=0x5f0a6c39*/ - param_4) + iVar1;
}

//==== 0x49a44  0x49a44-0x49a59 inclusive
undefined4 FUN_00049a44(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_000499fc(param_1,param_2,1,param_3);
  uVar2 = 0;
  if (param_3 != iVar1) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

//==== 0x49a5c  0x49a5c-0x49a79 inclusive
undefined4 FUN_00049a5c(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0004a568();
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0004a554();
    FUN_0004993c(DAT_00049a7c/*"key press : %c\n"*/,uVar2);
  }
  return uVar2;
}

//==== 0x49a80  0x49a80-0x49a89 inclusive
void FUN_00049a80(byte param_1)

{
  *DAT_00049a8c/*=0x82dd5*/ = param_1 | *DAT_00049a8c/*=0x82dd5*/;
  return;
}

//==== 0x49a90  0x49a90-0x49a97 inclusive
byte FUN_00049a90(byte param_1)

{
  return param_1 & *DAT_00049a98/*=0x82dd5*/;
}

//==== 0x49a9c  0x49a9c-0x49a9f inclusive
undefined4 FUN_00049a9c(void)

{
  return 0;
}

//==== 0x49aa8  0x49aa8-0x49aab inclusive
undefined4 FUN_00049aa8(void)

{
  return DAT_00049aac/*=0x831f8*/;
}

//==== 0x49ab4  0x49ab4-0x49b8f inclusive
void FUN_00049ab4(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = DAT_00049b90/*=0x82df8*/;
  *(undefined1 *)(DAT_00049b90/*=0x82df8*/ + 0x800) = 1;
  FUN_0005dab0();
  iVar5 = 0;
  iVar2 = FUN_0005da04(1);
  do {
    iVar6 = iVar5 * 0x200;
    iVar3 = iVar2 + -8 + iVar5;
    iVar5 = iVar5 + 1;
    FUN_0005db08(iVar3,1,iVar1 + iVar6);
  } while (iVar5 != 4);
  uVar4 = FUN_000495f0(DAT_00049b94/*"bootpara"*/);
  iVar2 = FUN_000495ce(DAT_00049b90/*=0x82df8*/,DAT_00049b94/*"bootpara"*/,uVar4);
  iVar5 = *(int *)(DAT_00049b98/*=0x47000*/ + 0xc);
  if (iVar2 == 0) {
    if (*(int *)(iVar1 + 0x14) == iVar5) {
      iVar6 = FUN_00049a44(DAT_00049b90/*=0x82df8*/,0x800,*(undefined4 *)(iVar1 + 0xc));
      iVar2 = 0;
      if (-1 < iVar6) {
        do {
          iVar6 = FUN_0005d9d8(iVar2);
          iVar3 = *(int *)(iVar1 + iVar2 + 0x600);
          if (iVar6 != iVar3) {
            FUN_0004993c(DAT_00049ba8/*"boot param - chipid not match, bootparam:%d, efuse:%d\n"*/,iVar3,iVar6);
            uVar4 = DAT_00049bac/*"boot param - chipid error\n"*/;
            goto LAB_00049b78;
          }
          iVar2 = iVar2 + 4;
        } while (iVar2 != 0x10);
        goto LAB_00049b88;
      }
      uVar4 = DAT_00049bb8/*"boot param - bootparam checksum not match\n"*/;
    }
    else {
      FUN_0004993c(DAT_00049bb0/*"boot param - boot0 checksum not match\n"*/);
      uVar4 = DAT_00049bb4/*"boot param - version error\n"*/;
    }
LAB_00049b78:
    FUN_0004993c(uVar4);
  }
  else {
    FUN_0004993c(DAT_00049b9c/*"boot param - magic error %s\n"*/,DAT_00049b90/*=0x82df8*/);
  }
  iVar6 = 0;
  thunk_FUN_00047c40(DAT_00049b90/*=0x82df8*/,0,0x800);
  thunk_FUN_00047d1c(DAT_00049ba4/*=0x831f8*/,DAT_00049ba0/*=0x47038*/,0x80);
  uVar4 = DAT_00049b94/*"bootpara"*/;
  iVar2 = DAT_00049b90/*=0x82df8*/;
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) | 1;
  FUN_000495a8(iVar2,uVar4);
  *(int *)(iVar1 + 0x14) = iVar5;
  do {
    uVar4 = FUN_0005d9d8(iVar6);
    iVar2 = iVar1 + iVar6;
    iVar6 = iVar6 + 4;
    *(undefined4 *)(iVar2 + 0x600) = uVar4;
  } while (iVar6 != 0x10);
LAB_00049b88:
  *(undefined1 *)(iVar1 + 0x800) = 0;
  return;
}

//==== 0x49bbc  0x49bbc-0x49bbf inclusive
undefined4 FUN_00049bbc(void)

{
  return 0;
}

//==== 0x49bc0  0x49bc0-0x49bd1 inclusive
undefined4 FUN_00049bc0(void)

{
  undefined4 in_r3;
  
  FUN_0004993c(DAT_00049bd8/*"__weak %s...%d\n"*/,DAT_00049bd4/*"init_DRAM"*/,0x11e,in_r3,in_r3);
  return 0;
}

//==== 0x49bdc  0x49bdc-0x49ced inclusive
uint FUN_00049bdc(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar5;
  uint *puVar4;
  
  FUN_0004993c(DAT_00049cf0/*"DRAM BOOT DRIVE INFO: %s\n"*/,DAT_00049cf4/*"V0.6034"*/,param_3,param_4,param_1,param_2,param_3);
  puVar4 = DAT_00049cf8/*=0x3000160*/;
  *DAT_00049cf8/*=0x3000160*/ = *DAT_00049cf8/*=0x3000160*/ | 0x100;
  puVar4[2] = puVar4[2] & 0xffffff00;
  if (((param_2[1] == 8) && (-1 < (int)param_2[0x17])) && (-1 < (int)(param_2[0x1b] << 2))) {
    uVar3 = param_2[0x1a] & 0x7f;
    puVar4 = param_2 + 0x20;
    do {
      puVar5 = puVar4 + 1;
      *puVar4 = uVar3 << 0x10 | uVar3 << 8 | uVar3 | uVar3 << 0x18;
      puVar4 = puVar5;
    } while (puVar5 != param_2 + 0x32);
    uVar3 = (uint)*(byte *)(param_2 + 0x12);
    param_2[0x32] = uVar3 << 0x10 | uVar3 << 8 | uVar3 | uVar3 << 0x18;
  }
  iVar1 = FUN_0004b618(param_2);
  if ((iVar1 != 0) &&
     (((int)(param_2[0x1e] << 0x1f) < 0 || (iVar1 = FUN_00057e44(param_2), iVar1 != 0)))) {
    FUN_0004993c(DAT_00049cfc/*"DRAM CLK =%d MHZ\n"*/,*param_2);
    FUN_0004993c(DAT_00049d00/*"DRAM Type =%d (8:LPDDR4,9:LPDDR5)\n"*/,param_2[1]);
    iVar1 = FUN_00057b7c(param_2);
    if (iVar1 == 0) {
      FUN_0004993c(DAT_00049d04/*"DRAM initial error : 1 !\n"*/);
    }
    else {
      if ((-1 < (int)param_2[0x17]) && ((int)(param_2[0x1b] << 2) < 0)) {
        FUN_000576e4(param_2);
        if (-1 < (int)(param_2[0x1b] << 1)) {
          param_2[0x1b] = param_2[0x1b] & 0xdfffffff;
        }
      }
      if ((int)param_2[7] < 0) {
        uVar3 = (param_2[7] & 0x7fffffff) >> 0x10;
      }
      else {
        uVar3 = FUN_0004b74c(param_2);
        FUN_0004993c(DAT_00049d0c/*"Actual DRAM SIZE =%d M\n"*/,uVar3);
        param_2[7] = (uint)*(ushort *)(param_2 + 7) | uVar3 << 0x10;
      }
      FUN_0004993c(DAT_00049d08/*"DRAM SIZE =%d MBytes, para1 = %x, para2 = %x, dram_tpr13 = %x\n"*/,uVar3,param_2[6],param_2[7],param_2[0x1e]);
      uVar2 = uVar3;
      if (0x1000 < uVar3) {
        uVar2 = 0x1000;
      }
      iVar1 = FUN_0004b4cc(uVar2);
      if (iVar1 == 0) {
        return uVar3;
      }
    }
  }
  return 0;
}

//==== 0x49d10  0x49d10-0x49d13 inclusive
undefined4 FUN_00049d10(void)

{
  return 0;
}

//==== 0x49d14  0x49d14-0x49d29 inclusive
undefined4 FUN_00049d14(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = DAT_00049d2c/*=0x82dd8*/;
  DAT_00049d2c/*=0x82dd8*/[4] = param_1;
  piVar1[5] = 0;
  piVar1[1] = 0;
  *piVar1 = param_2 + param_1;
  piVar1[7] = (int)piVar1;
  piVar1[3] = 0;
  return 0;
}

//==== 0x49d30  0x49d30-0x49d31 inclusive
void FUN_00049d30(void)

{
  return;
}

//==== 0x49d32  0x49d32-0x49d9d inclusive
undefined4 FUN_00049d32(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = 0;
  iVar3 = *(int *)(param_1 + 0x20) + param_1;
  while( true ) {
    iVar1 = iVar2 * 0x38 + iVar3;
    if ((int)(uint)*(ushort *)(param_1 + 0x38) <= iVar2) break;
    if (((*(int *)(iVar2 * 0x38 + iVar3) == 1) &&
        (*(int *)(iVar1 + 0x2c) != 0 || *(int *)(iVar1 + 0x28) != 0)) &&
       (*(int *)(iVar1 + 0x20) != 0 || *(int *)(iVar1 + 0x24) != 0)) {
      iVar4 = *(int *)(iVar1 + 0x18);
      thunk_FUN_00047d1c(iVar4,*(int *)(iVar1 + 8) + param_1);
      iVar5 = *(int *)(iVar1 + 0x20);
      if (*(int *)(iVar1 + 0x24) != *(int *)(iVar1 + 0x2c) || iVar5 != *(int *)(iVar1 + 0x28)) {
        thunk_FUN_00047c40(iVar5 + iVar4,0,*(int *)(iVar1 + 0x28) - iVar5);
      }
    }
    iVar2 = iVar2 + 1;
  }
  return 0;
}

//==== 0x49da0  0x49da0-0x49dc5 inclusive
undefined4 FUN_00049da0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_00049dc8/*=0x82df8*/;
  uVar2 = FUN_000499fc(DAT_00049dc8/*=0x82df8*/,0x800,1,*(undefined4 *)(DAT_00049dc8/*=0x82df8*/ + 0xc),param_4);
  *(undefined4 *)(iVar1 + 0xc) = uVar2;
  thunk_FUN_00047d1c(param_1,iVar1,0x800);
  return 0;
}

//==== 0x49dcc  0x49dcc-0x49e5d inclusive
uint * FUN_00049dcc(uint *param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint *puVar5;
  uint uVar6;
  
  uVar6 = *param_1;
  uVar6 = uVar6 >> 0x18 | uVar6 << 0x18 | ((uVar6 & 0xffff) >> 8) << 0x10 |
          ((uVar6 & 0xffffff) >> 0x10) << 8;
  if (uVar6 != DAT_00049e60/*=0xd00dfeed*/) {
    if (uVar6 != DAT_00049e64/*=0x2ff20112*/) {
      return (uint *)0xfffffff7;
    }
    uVar6 = param_1[9];
    bVar3 = uVar6 >> 0x18 == 0;
    bVar4 = (uVar6 & 0xff) == 0;
    bVar2 = (uVar6 & 0xffff) >> 8 == 0;
    bVar1 = (uVar6 & 0xffffff) >> 0x10 != 0;
    if (((!bVar3 || !bVar4) || !bVar2) || bVar1) {
      param_1 = (uint *)0x0;
    }
    if (((bVar3 && bVar4) && bVar2) && !bVar1) {
      param_1 = (uint *)0xfffffff9;
    }
    return param_1;
  }
  uVar6 = param_1[5];
  if ((uVar6 >> 0x18 | uVar6 << 0x18 | ((uVar6 & 0xffff) >> 8) << 0x10 |
      ((uVar6 & 0xffffff) >> 0x10) << 8) < 2) {
    return (uint *)0xfffffff6;
  }
  uVar6 = param_1[6];
  if ((uVar6 >> 0x18 | uVar6 << 0x18 | ((uVar6 & 0xffff) >> 8) << 0x10 |
      ((uVar6 & 0xffffff) >> 0x10) << 8) < 0x12) {
    puVar5 = (uint *)0x0;
  }
  else {
    puVar5 = (uint *)0xfffffff6;
  }
  return puVar5;
}

//==== 0x49e68  0x49e68-0x49ee9 inclusive
int FUN_00049e68(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 8);
  uVar2 = uVar1 >> 0x18 | uVar1 << 0x18 | ((uVar1 & 0xffff) >> 8) << 0x10 |
          ((uVar1 & 0xffffff) >> 0x10) << 8;
  uVar1 = param_2 + uVar2;
  if ((((CARRY4(param_2,uVar2)) || (CARRY4(uVar1,param_3))) ||
      (uVar2 = *(uint *)(param_1 + 4),
      (uVar2 >> 0x18 | uVar2 << 0x18 | ((uVar2 & 0xffff) >> 8) << 0x10 |
      ((uVar2 & 0xffffff) >> 0x10) << 8) < uVar1 + param_3)) ||
     ((uVar2 = *(uint *)(param_1 + 0x14),
      0x10 < (uVar2 >> 0x18 | uVar2 << 0x18 | ((uVar2 & 0xffff) >> 8) << 0x10 |
             ((uVar2 & 0xffffff) >> 0x10) << 8) &&
      ((CARRY4(param_2,param_3) ||
       (uVar2 = *(uint *)(param_1 + 0x24),
       (uVar2 >> 0x18 | uVar2 << 0x18 | ((uVar2 & 0xffff) >> 8) << 0x10 |
       ((uVar2 & 0xffffff) >> 0x10) << 8) < param_2 + param_3)))))) {
    param_1 = 0;
  }
  else {
    param_1 = param_1 + uVar1;
  }
  return param_1;
}

//==== 0x49eec  0x49eec-0x49f33 inclusive
uint FUN_00049eec(int param_1,int param_2,uint *param_3,undefined4 param_4)

{
  uint *puVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  *param_3 = 0xfffffff8;
  puVar1 = (uint *)FUN_00049e68(param_1,param_2,4,0xfffffff8,param_4);
  if (puVar1 != (uint *)0x0) {
    uVar5 = *puVar1;
    iVar6 = param_2 + 4;
    uVar7 = uVar5 >> 0x18 | uVar5 << 0x18 | ((uVar5 & 0xffff) >> 8) << 0x10 |
            ((uVar5 & 0xffffff) >> 0x10) << 8;
    *param_3 = 0xfffffff5;
    uVar5 = uVar7 - 1;
    uVar4 = uVar5;
    iVar3 = iVar6;
    switch(uVar5) {
    case 0:
      do {
        iVar6 = iVar3 + 1;
        pbVar2 = (byte *)FUN_00049e68(param_1,iVar3,1,uVar4,param_4);
        if (pbVar2 == (byte *)0x0) {
          return 9;
        }
        uVar4 = (uint)*pbVar2;
        uVar5 = 0;
        iVar3 = iVar6;
      } while (uVar4 != 0);
      break;
    case 1:
    case 3:
    case 8:
      break;
    case 2:
      puVar1 = (uint *)FUN_00049e68(param_1,iVar6,4,uVar5,param_4);
      if (puVar1 == (uint *)0x0) {
        return 9;
      }
      uVar5 = *puVar1;
      uVar4 = *(uint *)(param_1 + 0x14);
      uVar5 = uVar5 >> 0x18 | uVar5 << 0x18 | ((uVar5 & 0xffff) >> 8) << 0x10 |
              ((uVar5 & 0xffffff) >> 0x10) << 8;
      iVar6 = uVar5 + param_2 + 0xc;
      if ((((uVar4 >> 0x18 | uVar4 << 0x18 | ((uVar4 & 0xffff) >> 8) << 0x10 |
            ((uVar4 & 0xffffff) >> 0x10) << 8) < 0x10) && (7 < uVar5)) &&
         (uVar5 = (param_2 + 0xc) * 0x20000000, uVar5 != 0)) {
        iVar6 = iVar6 + 4;
      }
      break;
    default:
      goto LAB_00049f88;
    }
    iVar3 = FUN_00049e68(param_1,param_2,iVar6 - param_2,uVar5,param_4);
    if (iVar3 != 0) {
      *param_3 = iVar6 + 3U & 0xfffffffc;
      return uVar7;
    }
  }
LAB_00049f88:
  return 9;
}

//==== 0x49fe4  0x49fe4-0x4a007 inclusive
uint FUN_00049fe4(undefined4 param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint local_c;
  undefined4 uStack_8;
  
  if ((-1 < (int)param_2) && ((param_2 & 3) == 0)) {
    local_c = param_2;
    uStack_8 = param_3;
    iVar1 = FUN_00049eec(param_1,param_2,&local_c,0,param_1);
    if (iVar1 == 1) goto LAB_00049ff0;
  }
  local_c = 0xfffffffc;
LAB_00049ff0:
  return local_c;
}

//==== 0x4a008  0x4a008-0x4a02b inclusive
uint FUN_0004a008(undefined4 param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint local_c;
  undefined4 uStack_8;
  
  if ((-1 < (int)param_2) && ((param_2 & 3) == 0)) {
    local_c = param_2;
    uStack_8 = param_3;
    iVar1 = FUN_00049eec(param_1,param_2,&local_c,0,param_1);
    if (iVar1 == 3) goto LAB_0004a014;
  }
  local_c = 0xfffffffc;
LAB_0004a014:
  return local_c;
}

//==== 0x4a02c  0x4a02c-0x4a099 inclusive
int FUN_0004a02c(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int local_14;
  
  local_14 = 0;
  if ((param_2 < 0) || (local_14 = FUN_00049fe4(), -1 < local_14)) {
    do {
      while( true ) {
        iVar2 = local_14;
        iVar1 = FUN_00049eec(param_1,local_14,&local_14);
        if (iVar1 == 2) break;
        if (iVar1 == 9) {
          if (-1 < local_14) {
            return -1;
          }
          if (local_14 != -8) {
            return local_14;
          }
          if (param_3 == (int *)0x0) {
            return -1;
          }
          return -8;
        }
        if (iVar1 == 1) {
          if (param_3 == (int *)0x0) {
            return iVar2;
          }
          *param_3 = *param_3 + 1;
          return iVar2;
        }
      }
    } while ((param_3 == (int *)0x0) || (iVar2 = *param_3, *param_3 = iVar2 + -1, -1 < iVar2 + -1));
  }
  return local_14;
}

//==== 0x4a0cc  0x4a0cc-0x4a123 inclusive
int FUN_0004a0cc(int param_1,int param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = FUN_0004a008();
  if ((int)uVar1 < 0) {
    if (param_3 == (uint *)0x0) {
      param_1 = 0;
    }
    else {
      *param_3 = uVar1;
      param_1 = 0;
    }
  }
  else {
    uVar1 = *(uint *)(param_1 + 8);
    param_1 = (uVar1 >> 0x18 | uVar1 << 0x18 | ((uVar1 & 0xffff) >> 8) << 0x10 |
              ((uVar1 & 0xffffff) >> 0x10) << 8) + param_2 + param_1;
    if (param_3 != (uint *)0x0) {
      uVar1 = *(uint *)(param_1 + 4);
      *param_3 = uVar1 >> 0x18 | uVar1 << 0x18 | ((uVar1 & 0xffff) >> 8) << 0x10 |
                 ((uVar1 & 0xffffff) >> 0x10) << 8;
    }
  }
  return param_1;
}

//==== 0x4a124  0x4a124-0x4a143 inclusive
int FUN_0004a124(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0xc);
  return param_1 + param_2 + (uVar1 >> 0x18 | uVar1 << 0x18 | ((uVar1 & 0xffff) >> 8) << 0x10 |
                             ((uVar1 & 0xffffff) >> 0x10) << 8);
}

//==== 0x4a144  0x4a144-0x4a1c5 inclusive
int FUN_0004a144(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 + 8);
  iVar1 = FUN_00049dcc();
  if ((iVar1 == 0) && (iVar1 = FUN_00049fe4(param_1,param_2), -1 < iVar1)) {
    uVar3 = *(uint *)(param_1 + 0x14);
    iVar1 = (uVar4 >> 0x18 | uVar4 << 0x18 | ((uVar4 & 0xffff) >> 8) << 0x10 |
            ((uVar4 & 0xffffff) >> 0x10) << 8) + param_2 + param_1 + 4;
    if ((uVar3 >> 0x18 | uVar3 << 0x18 | ((uVar3 & 0xffff) >> 8) << 0x10 |
        ((uVar3 & 0xffffff) >> 0x10) << 8) < 0x10) {
      iVar1 = FUN_00049600(iVar1,0x2f);
      if (iVar1 == 0) goto LAB_0004a1b6;
      iVar1 = iVar1 + 1;
    }
    if (param_3 != (undefined4 *)0x0) {
      uVar2 = FUN_000495f0(iVar1);
      *param_3 = uVar2;
    }
  }
  else {
LAB_0004a1b6:
    if (param_3 == (undefined4 *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = 0;
      *param_3 = 0xfffffff5;
    }
  }
  return iVar1;
}

//==== 0x4a1c6  0x4a1c6-0x4a249 inclusive
int FUN_0004a1c6(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int local_20;
  int local_1c;
  
  local_20 = param_1;
  local_1c = param_2;
  iVar1 = FUN_00049dcc();
  if (iVar1 == 0) {
    local_20 = 0;
    for (; -1 < param_2; param_2 = FUN_0004a02c(param_1,param_2,&local_20)) {
      if (local_20 < 0) {
        return -1;
      }
      if ((((local_20 == 1) && (iVar1 = FUN_0004a144(param_1,param_2,&local_1c), iVar1 != 0)) &&
          (param_4 <= local_1c)) && (iVar2 = FUN_00049638(iVar1,param_3,param_4), iVar2 == 0)) {
        if (*(char *)(iVar1 + param_4) == '\0') {
          return param_2;
        }
        iVar2 = FUN_00049656(param_3,0x40,param_4);
        if ((iVar2 == 0) && (*(char *)(iVar1 + param_4) == '@')) {
          return param_2;
        }
      }
    }
    iVar1 = param_2;
    if (local_20 < 0) {
      iVar1 = -1;
    }
  }
  return iVar1;
}

//==== 0x4a24a  0x4a24a-0x4a267 inclusive
void FUN_0004a24a(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_000495f0(param_3);
  FUN_0004a1c6(param_1,param_2,param_3,uVar1);
  return;
}

//==== 0x4a268  0x4a09a-0x4a0cb inclusive
int FUN_0004a268(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar4;
  int local_14 [3];
  
  local_14[0] = FUN_00049fe4();
  if (local_14[0] < 0) {
    return local_14[0];
  }
  uVar4 = param_1;
  uVar3 = extraout_r3_00;
  while( true ) {
    iVar1 = local_14[0];
    iVar2 = FUN_00049eec(param_1,local_14[0],local_14,uVar3,uVar4);
    if (iVar2 == 3) {
      return iVar1;
    }
    if (iVar2 == 9) break;
    uVar3 = extraout_r3;
    if (iVar2 != 4) {
      return -1;
    }
  }
  if (local_14[0] < 0) {
    return local_14[0];
  }
  return -0xb;
}

//==== 0x4a280  0x4a280-0x4a297 inclusive
int FUN_0004a280(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar4;
  int aiStack_14 [3];
  
  aiStack_14[0] = FUN_0004a008();
  if (aiStack_14[0] < 0) {
    return aiStack_14[0];
  }
  uVar4 = param_1;
  uVar3 = extraout_r3_00;
  while( true ) {
    iVar1 = aiStack_14[0];
    iVar2 = FUN_00049eec(param_1,aiStack_14[0],aiStack_14,uVar3,uVar4);
    if (iVar2 == 3) {
      return iVar1;
    }
    if (iVar2 == 9) break;
    uVar3 = extraout_r3;
    if (iVar2 != 4) {
      return -1;
    }
  }
  if (aiStack_14[0] < 0) {
    return aiStack_14[0];
  }
  return -0xb;
}

//==== 0x4a298  0x4a298-0x4a31f inclusive
int FUN_0004a298(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int *param_5,
                int *param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  iVar8 = param_4;
  iVar1 = FUN_0004a268();
  do {
    if (iVar1 < 0) {
LAB_0004a2b0:
      if (param_5 != (int *)0x0) {
        *param_5 = iVar1;
      }
      return 0;
    }
    iVar2 = FUN_0004a0cc(param_1,iVar1,param_5);
    if (iVar2 == 0) {
      iVar1 = -0xd;
      goto LAB_0004a2b0;
    }
    uVar6 = *(uint *)(iVar2 + 8);
    uVar5 = (uVar6 & 0xffff) >> 8;
    uVar7 = (uVar6 & 0xffffff) >> 0x10;
    uVar3 = FUN_0004a124(param_1,uVar6 >> 0x18 | uVar6 << 0x18 | uVar5 << 0x10 | uVar7 << 8,uVar5,
                         uVar7,iVar8);
    iVar4 = FUN_000495f0();
    if ((iVar4 == param_4) && (iVar4 = FUN_00049638(uVar3,param_3,param_4), iVar4 == 0)) {
      if (param_6 == (int *)0x0) {
        return iVar2;
      }
      *param_6 = iVar1;
      return iVar2;
    }
    iVar1 = FUN_0004a280(param_1,iVar1);
  } while( true );
}

//==== 0x4a320  0x4a320-0x4a37d inclusive
int FUN_0004a320(int param_1)

{
  int iVar1;
  uint uVar2;
  int local_14;
  
  iVar1 = FUN_0004a298();
  if (iVar1 != 0) {
    uVar2 = *(uint *)(param_1 + 0x14);
    if ((((uVar2 >> 0x18 | uVar2 << 0x18 | ((uVar2 & 0xffff) >> 8) << 0x10 |
          ((uVar2 & 0xffffff) >> 0x10) << 8) < 0x10) && ((local_14 + 0xcU & 7) != 0)) &&
       (uVar2 = *(uint *)(iVar1 + 4),
       7 < (uVar2 >> 0x18 | uVar2 << 0x18 | ((uVar2 & 0xffff) >> 8) << 0x10 |
           ((uVar2 & 0xffffff) >> 0x10) << 8))) {
      iVar1 = iVar1 + 0x10;
    }
    else {
      iVar1 = iVar1 + 0xc;
    }
  }
  return iVar1;
}

//==== 0x4a37e  0x4a37e-0x4a39f inclusive
void FUN_0004a37e(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = param_2;
  uVar3 = param_3;
  uVar1 = FUN_000495f0(param_3);
  FUN_0004a320(param_1,param_2,param_3,uVar1,param_4,uVar2,uVar3);
  return;
}

//==== 0x4a3a0  0x4a3a0-0x4a3c5 inclusive
void FUN_0004a3a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_0004a454(param_1,DAT_0004a3c8/*"/aliases"*/,param_3,param_4,param_1,param_2);
  if (-1 < iVar1) {
    FUN_0004a320(param_1,iVar1,param_2,param_3,0);
  }
  return;
}

//==== 0x4a454  0x4a3cc-0x4a46d inclusive
int FUN_0004a454(undefined4 param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined4 unaff_r4;
  char *pcVar4;
  undefined4 unaff_r5;
  char *pcVar5;
  
  iVar3 = FUN_000495f0(param_2);
  iVar1 = FUN_00049dcc();
  if (iVar1 == 0) {
    pcVar5 = param_2 + iVar3;
    pcVar2 = param_2;
    if (*param_2 != '/') {
      pcVar2 = (char *)FUN_00049656(param_2,0x2f,iVar3,*param_2,unaff_r4,unaff_r5);
      if (pcVar2 == (char *)0x0) {
        pcVar2 = pcVar5;
      }
      else {
      }
      iVar1 = FUN_0004a3a0(param_1,param_2,(int)pcVar2 - (int)param_2);
      if (iVar1 == 0) {
        return -5;
      }
      iVar1 = FUN_0004a454(param_1,iVar1);
    }
    while (pcVar2 < pcVar5) {
      pcVar4 = pcVar2;
      while( true ) {
        pcVar2 = pcVar4 + 1;
        if (*pcVar4 != '/') break;
        pcVar4 = pcVar2;
        if (pcVar2 == pcVar5) {
          return iVar1;
        }
      }
      pcVar2 = (char *)FUN_00049656(pcVar4,0x2f,(int)pcVar5 - (int)pcVar4,*pcVar4,unaff_r4,unaff_r5)
      ;
      if (pcVar2 == (char *)0x0) {
        pcVar2 = pcVar5;
      }
      else {
      }
      iVar1 = FUN_0004a1c6(param_1,iVar1,pcVar4,(int)pcVar2 - (int)pcVar4);
      if (iVar1 < 0) {
        return iVar1;
      }
    }
  }
  return iVar1;
}

//==== 0x4a470  0x4a470-0x4a48d inclusive
bool FUN_0004a470(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_0004a37e(param_1,param_2,DAT_0004a490/*"status"*/,0,param_4);
  if (iVar2 == 0) {
    bVar1 = true;
  }
  else {
    iVar2 = FUN_000495b8(iVar2,DAT_0004a494/*"okay"*/);
    bVar1 = iVar2 == 0;
  }
  return bVar1;
}

//==== 0x4a498  0x4a498-0x4a4eb inclusive
int FUN_0004a498(undefined4 param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = FUN_0004a37e();
  if (((iVar1 == 0) || (param_2 == 0)) || ((param_2 & 3) != 0)) {
    iVar3 = -0xd;
  }
  else {
    if ((int)param_2 < 0) {
      param_2 = param_2 + 3;
    }
    iVar3 = (int)param_2 >> 2;
    if (param_4 != 0) {
      for (iVar4 = 0; iVar4 < iVar3; iVar4 = iVar4 + 1) {
        uVar2 = *(uint *)(iVar1 + iVar4 * 4);
        *(uint *)(param_4 + iVar4 * 4) =
             uVar2 >> 0x18 | uVar2 << 0x18 | ((uVar2 & 0xffff) >> 8) << 0x10 |
             ((uVar2 & 0xffffff) >> 0x10) << 8;
      }
    }
  }
  return iVar3;
}

//==== 0x4a4ec  0x4a4ec-0x4a539 inclusive
void FUN_0004a4ec(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_00049d30(0x2500000);
  FUN_00049560(param_1);
  FUN_0004a5cc(param_2,param_3,1);
  piVar1 = DAT_0004a53c/*=0x83600*/;
  iVar3 = iVar2 + param_1 * 0x1000;
  *(undefined4 *)(iVar3 + 0x10) = 3;
  *piVar1 = iVar3;
  *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) | 0x80;
  *(undefined4 *)(iVar3 + 4) = 0;
  *(undefined4 *)(iVar2 + param_1 * 0x1000) = 0xd;
  *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) & 0xffffff7f;
  *(undefined4 *)(iVar3 + 0xc) = 3;
  *(undefined4 *)(iVar3 + 8) = 7;
  return;
}

//==== 0x4a540  0x4a540-0x4a54d inclusive
void FUN_0004a540(undefined4 param_1)

{
  do {
  } while (-1 < (int)(((undefined4 *)*DAT_0004a550/*=0x83600*/)[5] << 0x19));
  *(undefined4 *)*DAT_0004a550/*=0x83600*/ = param_1;
  return;
}

//==== 0x4a554  0x4a554-0x4a563 inclusive
uint FUN_0004a554(void)

{
  do {
  } while (-1 < (int)(((uint *)*DAT_0004a564/*=0x83600*/)[5] << 0x1f));
  return *(uint *)*DAT_0004a564/*=0x83600*/ & 0xff;
}

//==== 0x4a568  0x4a568-0x4a573 inclusive
uint FUN_0004a568(void)

{
  return *(uint *)(*DAT_0004a574/*=0x83600*/ + 0x14) & 1;
}

//==== 0x4a578  0x4a578-0x4a591 inclusive
uint FUN_0004a578(int param_1,uint param_2)

{
  DataMemoryBarrier(0x1f);
  return *(uint *)((param_1 + 0x3ffff) * 0x80 + 0x90) >> (param_2 & 0xff) & 1;
}

//==== 0x4a5ac  0x4a592-0x4a5c5 inclusive
uint FUN_0004a5ac(uint param_1)

{
  int iVar1;
  
  iVar1 = (param_1 >> 5) * 0x80;
  if (param_1 >> 5 < 0xb) {
    iVar1 = iVar1 + 0x2000080;
  }
  else {
    iVar1 = DAT_0004a5c8/*=0x7024b00*/ + iVar1;
  }
  DataMemoryBarrier(0x1f);
  return *(uint *)(iVar1 + ((param_1 & 0x1f) >> 3) * 4) >> ((param_1 & 7) << 2) & 0xf;
}

//==== 0x4a5cc  0x4a5cc-0x4a92d inclusive
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
    puVar4 = (uint *)(DAT_0004a930/*=0x7024dc0*/ + iVar5);
    iVar7 = DAT_0004a934/*=0x7024de4*/ + iVar9;
    puVar6 = (uint *)(DAT_0004a938/*=0x7024dd4*/ + iVar5);
    local_44 = (uint *)(DAT_0004a93c/*=0x7024e50*/ + iVar9);
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
          local_38 = DAT_0004a930/*=0x7024dc0*/;
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
        puVar4 = (uint *)(iVar15 + DAT_0004a930/*=0x7024dc0*/);
        local_48 = (uint *)(iVar5 + DAT_0004a934/*=0x7024de4*/ + uVar8 * 4);
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

//==== 0x4a940  0x4a940-0x4a955 inclusive
void FUN_0004a940(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_00049d30(DAT_0004a958/*=0x7090100*/);
  DataMemoryBarrier(0x1f);
  *(undefined4 *)(iVar1 + param_1 * 4) = param_2;
  return;
}

//==== 0x4a95c  0x4a95c-0x4a96f inclusive
undefined4 FUN_0004a95c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00049d30(DAT_0004a970/*=0x7090100*/);
  DataMemoryBarrier(0x1f);
  return *(undefined4 *)(iVar1 + param_1 * 4);
}

//==== 0x4a990  0x4a990-0x4a9eb inclusive
undefined4 FUN_0004a990(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = DAT_0004a9ec/*"rtc[%d] value = 0x%x\n"*/;
  iVar3 = 0;
  do {
    iVar1 = FUN_0004a95c(iVar3);
    if (iVar1 != 0) {
      FUN_0004993c(uVar2,iVar3,iVar1);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 8);
  iVar1 = FUN_0004a95c(2);
  iVar3 = DAT_0004a9fc/*=0x5aa55aa7*/;
  if (iVar1 == DAT_0004a9f0/*=0x5aa5a55a*/) {
    uVar2 = DAT_0004a9f4/*"eraly jump fel\n"*/;
  }
  else {
    if (iVar1 != DAT_0004a9f8/*=0x5aa55aa5*/) {
      return 0;
    }
    FUN_0004a940(2,DAT_0004aa00/*=0x5aa55aa6*/);
    do {
      FUN_00048da4(0x96);
      iVar1 = FUN_0004a95c(2);
    } while (iVar1 != iVar3);
    uVar2 = DAT_0004aa04/*"carshdump mode , jump fel\n"*/;
  }
  FUN_0004993c(uVar2);
  return 1;
}

//==== 0x4aa08  0x4a974-0x4a98f inclusive
void FUN_0004aa08(void)

{
  int iVar1;
  
  do {
    FUN_0004a940(2,0);
    FUN_00048ebc();
    iVar1 = FUN_0004a95c(2);
  } while (iVar1 != 0);
  return;
}

//==== 0x4aa10  0x4aa10-0x4aa43 inclusive
undefined4 FUN_0004aa10(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  iVar3 = *DAT_0004aa44/*=0x83604*/;
  *(undefined4 *)(iVar3 + 8) = param_1;
  *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) | 8;
  iVar2 = 0xffff;
  do {
    bVar4 = iVar2 == 0;
    iVar2 = iVar2 + -1;
    if (bVar4) {
      return 0xfffffffc;
    }
  } while (-1 < *(int *)(iVar3 + 0xc) << 0x1c);
  if (iVar2 == 0) {
    return 0xfffffffc;
  }
  if (*(int *)(iVar3 + 0x10) == 0x28) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffd8;
  }
  return uVar1;
}

//==== 0x4aa48  0x4aa48-0x4aa81 inclusive
undefined4 FUN_0004aa48(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  iVar3 = *DAT_0004aa84/*=0x83604*/;
  *(undefined4 *)(iVar3 + 0x1c) = 0;
  *(undefined4 *)(iVar3 + 0x18) = 1;
  *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) | 0x20;
  iVar2 = 0xffff;
  do {
    bVar4 = iVar2 == 0;
    iVar2 = iVar2 + -1;
    if (bVar4) {
      return 0xfffffffc;
    }
  } while (-1 < *(int *)(iVar3 + 0xc) << 0x1c);
  if (iVar2 == 0) {
    return 0xfffffffc;
  }
  if (*(int *)(iVar3 + 0x10) == 8) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffff8;
  }
  return uVar1;
}

//==== 0x4aa88  0x4aa88-0x4aacf inclusive
undefined4 FUN_0004aa88(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  iVar3 = *DAT_0004aad0/*=0x83604*/;
  *(uint *)(iVar3 + 8) = param_2 | param_1 << 1;
  *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) | 8;
  iVar2 = 0xffff;
  do {
    bVar4 = iVar2 == 0;
    iVar2 = iVar2 + -1;
    if (bVar4) {
      return 0xfffffffc;
    }
  } while ((*(uint *)(iVar3 + 0xc) & 8) == 0);
  if (iVar2 == 0) {
    return 0xfffffffc;
  }
  if (param_2 == 0) {
    if (*(int *)(iVar3 + 0x10) == 0x18) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffe8;
    }
    return uVar1;
  }
  if (*(int *)(iVar3 + 0x10) == 0x40) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffc0;
  }
  return uVar1;
}

//==== 0x4aad4  0x4aad4-0x4ab1b inclusive
undefined4 FUN_0004aad4(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
  iVar3 = *DAT_0004ab1c/*=0x83604*/;
  *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) | 0x10;
  *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) | 8;
  iVar2 = 0xffff;
  do {
    bVar4 = iVar2 == 0;
    iVar2 = iVar2 + -1;
    if (bVar4) {
      return 0xfffffffc;
    }
  } while (*(int *)(iVar3 + 0xc) << 0x1b < 0);
  if (iVar2 == 0) {
    return 0xfffffffc;
  }
  iVar2 = 0x10000;
  do {
    iVar2 = iVar2 + -1;
    if (iVar2 == 0) break;
  } while (*(int *)(iVar3 + 0x10) != 0xf8);
  if (*(int *)(iVar3 + 0x10) == 0xf8) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffffc;
  }
  return uVar1;
}

//==== 0x4ab20  0x4ab20-0x4ac75 inclusive
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
  
  piVar1 = DAT_0004ac78/*=0x83604*/;
  if (DAT_0004ac78/*=0x83604*/[1] == 0) {
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

//==== 0x4ac7c  0x4ac7c-0x4ad25 inclusive
undefined4 FUN_0004ac7c(undefined4 param_1,undefined4 param_2,int param_3,byte *param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  undefined1 *puVar6;
  undefined1 *puVar5;
  undefined4 uVar7;
  bool bVar8;
  undefined4 local_1c;
  
  piVar1 = DAT_0004ad28/*=0x83604*/;
  if (DAT_0004ad28/*=0x83604*/[1] == 0) {
    uVar7 = 0xfffffffc;
  }
  else {
    local_1c = param_2;
    iVar2 = FUN_0004aa48();
    if ((iVar2 == 0) && (iVar2 = FUN_0004aa88(param_1,0), iVar2 == 0)) {
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
      puVar6 = (undefined1 *)(iVar2 + (int)&local_1c);
      do {
        puVar5 = puVar6 + -1;
        iVar2 = FUN_0004aa10(*puVar6);
        if (iVar2 != 0) goto LAB_0004ac9a;
        puVar6 = puVar5;
      } while ((int)puVar5 - (int)&local_1c != -1);
      iVar2 = *piVar1;
      pbVar4 = param_4;
      while( true ) {
        uVar7 = 0;
        if (param_4 + param_5 == pbVar4) goto LAB_0004ac9e;
        *(uint *)(iVar2 + 8) = (uint)*pbVar4;
        *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | 8;
        iVar3 = 0xffff;
        do {
          bVar8 = iVar3 == 0;
          iVar3 = iVar3 + -1;
          if (bVar8) goto LAB_0004ac9a;
        } while (-1 < *(int *)(iVar2 + 0xc) << 0x1c);
        if (iVar3 == 0) break;
        iVar3 = 0xffff;
        do {
          bVar8 = iVar3 == 0;
          iVar3 = iVar3 + -1;
          if (bVar8) goto LAB_0004ac9a;
        } while (*(int *)(iVar2 + 0x10) != 0x28);
        pbVar4 = pbVar4 + 1;
        if (iVar3 == 0) break;
      }
    }
LAB_0004ac9a:
    uVar7 = 0xffffffff;
LAB_0004ac9e:
    FUN_0004aad4();
  }
  return uVar7;
}

//==== 0x4ae08  0x4ae08-0x4ae1d inclusive
int FUN_0004ae08(void)

{
  int iVar1;
  
  iVar1 = DAT_0004ae20/*=0x47000*/ + 0x308;
  if (*(char *)(DAT_0004ae20/*=0x47000*/ + 0x308) == '\0') {
    iVar1 = DAT_0004ae24/*=0x60674*/;
  }
  return iVar1;
}

//==== 0x4ae28  0x4ad2c-0x4adfd inclusive
void FUN_0004ae28(int param_1,int param_2)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  uint *puVar7;
  uint uVar8;
  undefined4 unaff_lr;
  
  piVar1 = DAT_0004aedc/*=0x83604*/;
  *DAT_0004aedc/*=0x83604*/ = param_1;
  FUN_0004a5cc(piVar1[2],2,1);
  puVar7 = DAT_0004aee4/*=0x701019c*/;
  puVar2 = DAT_0004aee0/*=0x2002e80*/;
  uVar5 = param_1 + 0xfdaf0000U >> 10;
  if (uVar5 < 6) {
    DataMemoryBarrier(0x1f);
    DataMemoryBarrier(0x1f);
    *DAT_0004aee0/*=0x2002e80*/ = 1 << (uVar5 + 0x10 & 0xff) | *DAT_0004aee0/*=0x2002e80*/;
    uVar8 = *puVar2;
    DataMemoryBarrier(0x1f);
    puVar7 = puVar2;
  }
  else {
    uVar5 = param_1 + 0xf8f7d000U >> 10;
    DataMemoryBarrier(0x1f);
    uVar8 = 1 << (uVar5 + 0x10 & 0xff);
    DataMemoryBarrier(0x1f);
    *DAT_0004aee4/*=0x701019c*/ = *DAT_0004aee4/*=0x701019c*/ & ~uVar8;
    DataMemoryBarrier(0x1f);
    DataMemoryBarrier(0x1f);
    *puVar7 = uVar8 | *puVar7;
    uVar8 = *puVar7;
    DataMemoryBarrier(0x1f);
  }
  uVar5 = 1 << (uVar5 & 0xff);
  DataMemoryBarrier(0x1f);
  *puVar7 = uVar8 & ~uVar5;
  FUN_00048da4();
  DataMemoryBarrier(0x1f);
  *puVar7 = uVar8 | uVar5;
  piVar1 = DAT_0004ae00/*=0x83604*/;
  iVar4 = *DAT_0004ae00/*=0x83604*/;
  *(undefined4 *)(iVar4 + 0x18) = 1;
  iVar3 = 0x10000;
  do {
    if (*(int *)(iVar4 + 0x18) == 0) break;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if ((*(uint *)(iVar4 + 0x20) & 0x30) != 0x30) {
    iVar3 = 10;
    *(undefined4 *)(iVar4 + 0x20) = 5;
    FUN_00048d80(500);
    do {
      iVar4 = *piVar1;
      if (*(int *)(iVar4 + 0x20) << 0x1e < 0) break;
      *(uint *)(iVar4 + 0x20) = *(uint *)(iVar4 + 0x20) | 8;
      *(uint *)(iVar4 + 0x20) = *(uint *)(iVar4 + 0x20) | 2;
      FUN_00048d80(1000);
      iVar4 = *piVar1;
      *(uint *)(iVar4 + 0x20) = *(uint *)(iVar4 + 0x20) & 0xfffffff7;
      *(uint *)(iVar4 + 0x20) = *(uint *)(iVar4 + 0x20) & 0xfffffffd;
      FUN_00048d80(1000);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *(undefined4 *)(*piVar1 + 0x20) = 0;
    FUN_00048d80(500);
  }
  uVar5 = 0;
  iVar6 = (int)((longlong)param_2 * (longlong)DAT_0004ae04/*=0x10624dd3*/ >> 0x26) - (param_2 >> 0x1f);
  iVar4 = 1;
  iVar3 = iVar6;
  if (399 < iVar6) {
    iVar3 = 400;
  }
  if (iVar3 < 100) {
    iVar3 = 100;
  }
  if (iVar6 < 0x65) {
    uVar8 = 1;
  }
  else {
    uVar8 = 0;
  }
  while (uVar5 < uVar8) {
    iVar4 = iVar4 << 1;
    uVar5 = 1;
  }
  iVar6 = *piVar1;
  iVar3 = FUN_000482b0(0x960,iVar4 * iVar3,uVar5,iVar4,unaff_r4,unaff_r5,unaff_r6,unaff_lr);
  *(uint *)(iVar6 + 0x14) = uVar8 | (iVar3 + -1) * 8;
  *(uint *)(iVar6 + 0xc) = *(uint *)(iVar6 + 0xc) | 0x40;
  *(undefined4 *)(iVar6 + 0x1c) = 0;
  return;
}

//==== 0x4aee8  0x4aee8-0x4af17 inclusive
void FUN_0004aee8(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar1 = DAT_0004af18/*=0x83604*/;
  if (*(int *)(DAT_0004af18/*=0x83604*/ + 4) == 0) {
    uVar3 = FUN_0004ae08();
    iVar2 = (int)uVar3;
    *(int *)(iVar1 + 8) = iVar2;
    if (iVar2 != 0) {
      if (*(byte *)(iVar2 + 6) == 6) {
        iVar2 = DAT_0004af1c/*=0x7083000*/;
      }
      else {
        iVar2 = (*(byte *)(iVar2 + 6) + 0x9440) * 0x400;
      }
      FUN_0004ae28(iVar2,param_1,(int)((ulonglong)uVar3 >> 0x20));
      *(undefined4 *)(iVar1 + 4) = 1;
    }
  }
  return;
}

//==== 0x4af20  0x4af20-0x4af29 inclusive
undefined4 FUN_0004af20(void)

{
  FUN_0004aee8();
  return 0;
}

//==== 0x4af2a  0x4af2a-0x4af3d inclusive
void FUN_0004af2a(undefined1 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0004ab20(param_1,param_2,1,param_3,1,param_2);
  return;
}

//==== 0x4af3e  0x4af3e-0x4af55 inclusive
void FUN_0004af3e(undefined1 param_1,undefined4 param_2,undefined4 param_3,undefined3 param_4)

{
  undefined1 auStackY_98 [128];
  
  FUN_0004ac7c(param_1,param_2,1,auStackY_98 + 0x8f,1,param_2,param_3,
               CONCAT13((char)param_3,param_4));
  return;
}

//==== 0x4af58  0x4af58-0x4af5b inclusive
undefined4 FUN_0004af58(void)

{
  return DAT_0004af5c/*=0x83610*/;
}

//==== 0x4af60  0x4af60-0x4b0bd inclusive
int FUN_0004af60(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  uint uVar11;
  int local_58;
  int local_54;
  uint local_50;
  int local_4c;
  undefined1 auStack_48 [36];
  
  local_54 = 1;
  uVar10 = *DAT_0004b0c0/*=0x82dc8*/;
  iVar3 = FUN_0004a454(uVar10,DAT_0004b0c4/*"/sunxi-amp"*/);
  if (iVar3 < 0) {
    FUN_0004993c(DAT_0004b0cc/*"%s cant't find node "%s" \n"*/,DAT_0004b0c8/*"sunxi_amp_boot_args_set"*/,DAT_0004b0c4/*"/sunxi-amp"*/);
    iVar4 = iVar3;
  }
  else {
    iVar4 = FUN_0004a470(uVar10,iVar3);
    if (iVar4 == 0) {
      iVar4 = -1;
      FUN_0004993c(DAT_0004b0d0/*"%s %s node status is not okay \n"*/,DAT_0004b0c8/*"sunxi_amp_boot_args_set"*/,DAT_0004b0c4/*"/sunxi-amp"*/);
    }
    else {
      iVar4 = FUN_0004a498(uVar10,iVar3,DAT_0004b0d4/*"amp-count"*/,&local_50);
      piVar1 = DAT_0004b10c/*=0x83610*/;
      if (iVar4 < 0) {
        uVar10 = DAT_0004b0d8/*"%s cant't get amp-count node "%s" \n"*/;
        puVar9 = DAT_0004b0c4/*"/sunxi-amp"*/;
LAB_0004afc2:
        FUN_0004993c(uVar10,DAT_0004b0c8/*"sunxi_amp_boot_args_set"*/,puVar9);
      }
      else {
        for (uVar11 = 0; piVar2 = DAT_0004b10c/*=0x83610*/, uVar11 < local_50; uVar11 = uVar11 + 1) {
          FUN_00049910(auStack_48,DAT_0004b0dc/*"amp%d"*/,uVar11);
          iVar5 = FUN_0004a24a(uVar10,iVar3,auStack_48);
          if (iVar5 < 0) {
            FUN_0004993c(DAT_0004b0e0/*"%s cant't find node %s \n"*/,DAT_0004b0c8/*"sunxi_amp_boot_args_set"*/,auStack_48);
            return iVar5;
          }
          uVar6 = FUN_0004a37e(uVar10,iVar5,DAT_0004b0e4/*"boot-stage"*/,&local_58);
          if (local_58 < 0) {
            puVar9 = auStack_48;
            uVar10 = DAT_0004b0e8/*"%s cant't get boot-stage node "%s" \n"*/;
            goto LAB_0004afc2;
          }
          uVar7 = FUN_000495f0(DAT_0004b0ec/*"boot0"*/);
          iVar8 = FUN_000495ce(uVar6,DAT_0004b0ec/*"boot0"*/,uVar7);
          if (iVar8 == 0) {
            uVar6 = FUN_0004a37e(uVar10,iVar5,DAT_0004b0f0/*"image"*/,&local_58);
            if (local_58 < 0) {
              puVar9 = auStack_48;
              uVar10 = DAT_0004b0f4/*"%s cant't get image node "%s" \n"*/;
              goto LAB_0004afc2;
            }
            uVar7 = FUN_000495f0(param_1);
            iVar8 = FUN_000495ce(uVar6,param_1,uVar7);
            if (iVar8 == 0) {
              iVar4 = FUN_0004a498(uVar10,iVar5,DAT_0004b0fc/*"cpu-id"*/,DAT_0004b0f8/*=0x83618*/);
              if ((iVar4 < 0) ||
                 (iVar4 = FUN_0004a498(uVar10,iVar5,DAT_0004b104/*"entry-addr"*/,&local_4c), uVar6 = DAT_0004b108/*"arch"*/,
                 iVar4 < 0)) {
                puVar9 = auStack_48;
                uVar10 = DAT_0004b100/*"%s cant't get cpu-id node "%s" \n"*/;
                goto LAB_0004afc2;
              }
              *piVar1 = local_4c;
              piVar1[1] = 0;
              iVar4 = FUN_0004a498(uVar10,iVar5,uVar6,&local_54);
            }
          }
        }
        iVar4 = 0;
        if (*DAT_0004b10c/*=0x83610*/ == 0 && DAT_0004b10c/*=0x83610*/[1] == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = DAT_0004b110/*=0x616d70*/;
        }
        DAT_0004b10c/*=0x83610*/[3] = iVar3;
        if (local_54 == 1) {
          piVar2[3] = piVar2[3] | 0x80000000;
        }
      }
    }
  }
  return iVar4;
}

//==== 0x4b114  0x4b114-0x4b16b inclusive
void FUN_0004b114(void)

{
  undefined4 *puVar1;
  uint *puVar2;
  
  FUN_00049508();
  puVar2 = DAT_0004b16c/*=0x2521000*/;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *DAT_0004b16c/*=0x2521000*/ = *DAT_0004b16c/*=0x2521000*/ & 0xffff | 0x5dbf0000;
  puVar2 = puVar2 + 1;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *puVar2 = *puVar2 & 0xfffbffff | 0x80000;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *puVar2 = *puVar2 | 0x10000;
  puVar1 = DAT_0004b170/*=0x2521028*/;
  DataMemoryBarrier(0x1f);
  *DAT_0004b170/*=0x2521028*/ = 0;
  DataMemoryBarrier(0x1f);
  puVar1[4] = 1;
  return;
}

//==== 0x4b174  0x4b174-0x4b1ad inclusive
undefined4 FUN_0004b174(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 1 << (param_1 & 0xff);
  *DAT_0004b1b0/*=0x2521008*/ = *DAT_0004b1b0/*=0x2521008*/ | uVar2;
  FUN_00048d80(0x5dc);
  DataMemoryBarrier(0x1f);
  uVar2 = *DAT_0004b1b4/*=0x2521038*/ & uVar2;
  DataMemoryBarrier(0x1f);
  *DAT_0004b1b4/*=0x2521038*/ = uVar2;
  uVar1 = 0;
  if (uVar2 != 0) {
    uVar1 = *(undefined4 *)((DAT_0004b1b8/*=0x948420*/ + param_1) * 4);
    DataMemoryBarrier(0x1f);
  }
  return uVar1;
}

//==== 0x4b1bc  0x4b1bc-0x4b227 inclusive
int FUN_0004b1bc(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  int local_2c [3];
  
  iVar1 = DAT_0004b22c/*=0x55555556*/;
  local_2c[0] = param_2;
  local_2c[1] = param_3;
  local_2c[2] = param_4;
  iVar2 = FUN_00048d58();
  while( true ) {
    iVar4 = 0;
    iVar6 = 0;
    do {
      iVar3 = FUN_0004b174(param_1);
      uVar7 = FUN_000482b0(iVar3 * 0x708,0xfff);
      iVar3 = (int)uVar7;
      local_2c[iVar6] = iVar3;
      iVar6 = iVar6 + 1;
      iVar4 = iVar4 + iVar3;
    } while (iVar6 != 3);
    iVar5 = (int)((ulonglong)((longlong)iVar4 * (longlong)iVar1) >> 0x20) - (iVar4 >> 0x1f);
    iVar6 = iVar5 - local_2c[0];
    if (iVar6 < 0) {
      iVar6 = -iVar6;
    }
    if (iVar6 < 5) break;
    iVar4 = FUN_00048d58(iVar3,(int)((ulonglong)uVar7 >> 0x20),
                         (int)((longlong)iVar4 * (longlong)iVar1));
    if (1999 < (uint)(iVar4 - iVar2)) {
      FUN_0004993c(DAT_0004b228/*"get adc time out!!!\n"*/);
      return iVar5;
    }
  }
  return iVar5;
}

//==== 0x4b230  0x4b230-0x4b259 inclusive
undefined4 FUN_0004b230(void)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  
  pbVar1 = DAT_0004b25c/*=0x60694*/;
  iVar2 = FUN_0004a5ac((uint)DAT_0004b25c/*=0x60694*/[1] + (*DAT_0004b25c/*=0x60694*/ - 1) * 0x20);
  if (iVar2 == 3) {
    uVar3 = 0xffffffff;
  }
  else {
    FUN_0004a5cc(pbVar1,2,1);
    uVar3 = 0;
  }
  return uVar3;
}

//==== 0x4b260  0x4b260-0x4b287 inclusive
undefined4 FUN_0004b260(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  puVar1 = DAT_0004b288/*=0x60694*/;
  iVar2 = FUN_0004a578(*DAT_0004b288/*=0x60694*/,DAT_0004b288/*=0x60694*/[1],param_3,param_4,param_4);
  iVar3 = FUN_0004a578(puVar1[8],puVar1[9]);
  if ((iVar2 == 0) || (iVar3 == 0)) {
    FUN_0004993c(DAT_0004b28c/*"volume key pressed!\n"*/);
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

//==== 0x4b290  0x4b290-0x4b2e7 inclusive
undefined4 FUN_0004b290(undefined2 *param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = FUN_0004b230();
  if (iVar2 == 0) {
    iVar3 = FUN_00048d58();
    uVar1 = FUN_0004b260();
    *param_1 = uVar1;
    iVar2 = 0;
    do {
      iVar4 = FUN_0004b260();
      if (iVar4 < 1) break;
      iVar4 = FUN_0005d6fc();
      if (0 < iVar4) {
        iVar2 = iVar2 + 1;
      }
      if (2 < iVar2) {
        return 0xffffffff;
      }
      iVar4 = FUN_00048d58();
    } while ((uint)(iVar4 - iVar3) < 0xbb9);
    if ((iVar2 == 0) && (iVar2 = FUN_0005d6e4(), iVar2 != 0)) {
      *param_1 = 0;
      return 0;
    }
  }
  return 0;
}

//==== 0x4b2e8  0x4b2e8-0x4b47b inclusive
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
  
  iVar11 = DAT_0004b480/*=0x47000*/;
  local_38[0] = *DAT_0004b47c/*=0x5e5c0*/;
  local_38[1] = DAT_0004b47c/*=0x5e5c0*/[1];
  local_38[2] = DAT_0004b47c/*=0x5e5c0*/[2];
  local_38[3] = DAT_0004b47c/*=0x5e5c0*/[3];
  local_38[4] = DAT_0004b47c/*=0x5e5c0*/[4];
  iStack_24 = DAT_0004b47c/*=0x5e5c0*/[5];
  iStack_20 = DAT_0004b47c/*=0x5e5c0*/[6];
  iStack_1c = DAT_0004b47c/*=0x5e5c0*/[7];
  if (*(int *)(DAT_0004b480/*=0x47000*/ + 0x94) < 0) goto LAB_0004b3a6;
  uVar4 = FUN_000495f0(DAT_0004b484/*"DRAM.ext"*/);
  iVar5 = FUN_000495ce(iVar11 + 0x348,DAT_0004b484/*"DRAM.ext"*/,uVar4);
  if (iVar5 != 0) {
    FUN_0004993c(DAT_0004b4a0/*"extd_head bad magic\n"*/);
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
      FUN_0004993c(DAT_0004b498/*"dram_para_total:0x%x\n"*/,0xf);
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
      FUN_0004993c(DAT_0004b488/*"dram para%d invalid use default para\n"*/,iVar10);
      iVar10 = 0;
    }
    else {
      thunk_FUN_00047d1c(DAT_0004b49c/*=0x47038*/,iVar6 + 0x374 + iVar11,0x80);
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
  FUN_0004993c(DAT_0004b48c/*"vaild para:%d  select dram para%d\n"*/,iVar7,iVar10);
LAB_0004b3a6:
  uVar13 = FUN_000498c0();
  uVar4 = DAT_0004b494/*"dram_para[%d]:0x%x\n"*/;
  if (3 < uVar13) {
    iVar11 = 0;
    puVar12 = DAT_0004b490/*=0x47034*/;
    do {
      puVar12 = puVar12 + 1;
      iVar5 = iVar11 + 1;
      FUN_0004993c(uVar4,iVar11,*puVar12);
      iVar11 = iVar5;
    } while (iVar5 != 0x20);
  }
  return 0;
}

//==== 0x4b4a4  0x4b4a4-0x4b4a7 inclusive
void thunk_FUN_00048d80(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  undefined4 in_cr14;
  
  uVar5 = coprocessor_movefromRt(0xf,0,in_cr14);
  iVar2 = coprocessor_movefromRt2(0xf,0,in_cr14);
  uVar4 = iVar2 + (uint)CARRY4(uVar5,param_1 * 0x18);
  do {
    uVar1 = coprocessor_movefromRt(0xf,0,in_cr14);
    uVar3 = coprocessor_movefromRt2(0xf,0,in_cr14);
    bVar6 = uVar3 <= uVar4;
    if (uVar4 == uVar3) {
      bVar6 = uVar1 <= uVar5 + param_1 * 0x18;
    }
  } while (bVar6);
  return;
}

//==== 0x4b4a8  0x4b4a8-0x4b4c7 inclusive
uint FUN_0004b4a8(int param_1,int param_2)

{
  uint uVar1;
  int extraout_r1;
  
  FUN_00048294(param_2 * param_1,1000);
  uVar1 = (uint)((ulonglong)(uint)(param_2 * param_1) * (ulonglong)DAT_0004b4c8/*=0x10624dd3*/ >> 0x26);
  if (extraout_r1 != 0) {
    uVar1 = uVar1 + 1;
  }
  return uVar1;
}

//==== 0x4b4cc  0x4b4cc-0x4b53f inclusive
undefined4 FUN_0004b4cc(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = DAT_0004b544/*=0xfedcba98*/;
  iVar4 = DAT_0004b540/*=0x1234567*/;
  param_1 = param_1 >> 1;
  piVar2 = (int *)&DAT_40000000;
  for (iVar3 = 0; iVar3 != param_2; iVar3 = iVar3 + 1) {
    *piVar2 = iVar3 + iVar4;
    piVar2[param_1 * 0x40000] = iVar3 + iVar1;
    piVar2 = piVar2 + 1;
  }
  iVar4 = 0;
  piVar2 = (int *)&DAT_40000000;
  while( true ) {
    if (iVar3 == iVar4) {
      FUN_0004993c(DAT_0004b548/*"DRAM simple test OK.\n"*/);
      return 0;
    }
    if (iVar4 + DAT_0004b544/*=0xfedcba98*/ != piVar2[param_1 * 0x40000]) break;
    if (iVar4 + DAT_0004b540/*=0x1234567*/ != *piVar2) {
      FUN_0004993c(DAT_0004b54c/*"DRAM simple test FAIL-----%x != %x at address %x\n"*/);
      return 1;
    }
    iVar4 = iVar4 + 1;
    piVar2 = piVar2 + 1;
  }
  FUN_0004993c(DAT_0004b54c/*"DRAM simple test FAIL-----%x != %x at address %x\n"*/,piVar2[param_1 * 0x40000],iVar4 + DAT_0004b544/*=0xfedcba98*/,
               piVar2 + param_1 * 0x40000,param_4);
  FUN_0004993c(DAT_0004b550/*"  read 10 times again\n"*/);
  return 1;
}

//==== 0x4b554  0x4b554-0x4b595 inclusive
void FUN_0004b554(int param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  iVar1 = DAT_0004b59c/*=0xa110080*/;
  param_1 = param_1 * 0x400000;
  piVar4 = (int *)(DAT_0004b598/*=0xa110090*/ + param_1);
  do {
  } while (*piVar4 << 0x1f < 0);
  *(undefined4 *)(param_1 + DAT_0004b59c/*=0xa110080*/) = 0x10;
  iVar2 = DAT_0004b5a0/*=0xa110084*/;
  *(uint *)(param_1 + DAT_0004b5a0/*=0xa110084*/) = param_3 | param_2 << 8;
  *(undefined4 *)(param_1 + iVar1) = DAT_0004b5a4/*=0x80000010*/;
  uVar3 = DAT_0004b5a8/*=0x80000020*/;
  do {
  } while (*(int *)(param_1 + iVar1) < 0);
  do {
  } while (*piVar4 << 0x1f < 0);
  *(undefined4 *)(param_1 + iVar1) = 0x20;
  *(uint *)(param_1 + iVar2) = param_2 << 8 | param_4;
  *(undefined4 *)(param_1 + iVar1) = uVar3;
  do {
  } while (*(int *)(param_1 + iVar1) < 0);
  return;
}

//==== 0x4b5ac  0x4b5ac-0x4b601 inclusive
uint FUN_0004b5ac(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  
  iVar1 = DAT_0004b608/*=0xa110080*/;
  iVar4 = param_2 * 0x400000;
  do {
  } while (*(int *)(DAT_0004b604/*=0xa110090*/ + iVar4) << 0x1f < 0);
  uVar2 = 1 << (param_3 + 4U & 0xff);
  *(uint *)(iVar4 + DAT_0004b608/*=0xa110080*/) = uVar2 | 1;
  *(int *)(iVar4 + DAT_0004b60c/*=0xa110084*/) = param_4 << 8;
  *(uint *)(iVar4 + iVar1) = uVar2 | 0x80000001;
  do {
  } while (*(int *)(iVar4 + iVar1) < 0);
  if ((*(int *)(param_1 + 4) == 8) && (param_2 == 1)) {
    uVar2 = *DAT_0004b610/*=0xa020040*/ & 0xff;
  }
  else {
    if (param_2 == 0) {
      puVar3 = DAT_0004b614/*=0xa02002c*/;
    }
    else {
      puVar3 = DAT_0004b610/*=0xa020040*/;
    }
    uVar2 = (*puVar3 & 0xffff) >> 8;
  }
  return uVar2;
}

//==== 0x4b618  0x4b618-0x4b72d inclusive
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
      iVar2 = FUN_0005d72c(DAT_0004b73c/*"dcdc7"*/,iVar4,1);
      goto LAB_0004b68e;
    }
    iVar2 = FUN_0005d72c(DAT_0004b730/*"dcdc8"*/,iVar4,1);
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
        iVar2 = FUN_0005d72c(DAT_0004b73c/*"dcdc7"*/,iVar6,1);
      }
      else {
        iVar2 = FUN_0005d72c(DAT_0004b73c/*"dcdc7"*/,0x4b0,1);
        iVar6 = 0x4b0;
      }
      iVar6 = FUN_0005d72c(DAT_0004b734/*"eldo1"*/,iVar6,1);
      iVar2 = iVar2 + iVar6;
LAB_0004b68e:
      uVar1 = DAT_0004b740/*"dcdc6"*/;
      goto LAB_0004b666;
    }
    if (uVar3 == 0) {
      iVar2 = FUN_0005d72c(DAT_0004b730/*"dcdc8"*/,iVar6,1);
    }
    else {
      iVar2 = FUN_0005d72c(DAT_0004b730/*"dcdc8"*/,0x4b0,1);
      iVar6 = 0x4b0;
    }
    iVar6 = FUN_0005d72c(DAT_0004b744/*"eldo2"*/,iVar6,1);
    iVar2 = iVar2 + iVar6;
  }
  uVar1 = DAT_0004b734/*"eldo1"*/;
LAB_0004b666:
  iVar5 = FUN_0005d72c(uVar1,iVar5,1);
  if (iVar5 + iVar2 == 0) {
    FUN_0004993c(DAT_0004b748/*"DRAM_VCC set to %d mv\n"*/,iVar4);
    return iVar4;
  }
  FUN_0004993c(DAT_0004b738/*"POWER SETTING ERROR!\n"*/);
  return 0;
}

//==== 0x4b74c  0x4b74c-0x4b79f inclusive
uint FUN_0004b74c(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(param_1 + 0x18);
  uVar1 = *(uint *)(param_1 + 0x1c);
  iVar3 = ((uVar1 & 0xffff) >> 0xc) +
          ((uVar2 & 0xffff) >> 0xe) +
          ((uVar2 & 0xfff) >> 4) + ((uVar2 & 0x3fff) >> 0xc) + (uVar2 & 0xf);
  if ((uVar1 & 0xf) == 0) {
    uVar2 = iVar3 - 0x12;
  }
  else if ((*(uint *)(param_1 + 0x78) & 0x40) == 0) {
    uVar2 = iVar3 - 0x13;
  }
  else {
    uVar2 = iVar3 - 0x12;
  }
  uVar2 = 1 << (uVar2 & 0xff);
  if (((*(uint *)(param_1 + 0x78) & 0x70000) != 0) && (uVar1 >> 0x1e != 2)) {
    uVar2 = uVar2 * 3 >> 2;
  }
  return uVar2;
}

//==== 0x4b7a0  0x4b7a0-0x4b7e3 inclusive
int FUN_0004b7a0(uint param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)((ulonglong)param_1 * (ulonglong)DAT_0004b7e4/*=0xaaaaaaab*/ >> 0x24);
  *param_2 = DAT_0004b7e8/*=0xff8f00fd*/ & *param_2 | 0x1000000 | (uVar2 - 1) * 0x100;
  uVar1 = *param_2;
  *param_2 = uVar1 | 0xc0000000;
  *param_2 = uVar1 | 0xe0000000;
  FUN_00048d80(0x14);
  do {
  } while (-1 < (int)(*param_2 << 3));
  *param_2 = uVar1 | 0xe8000000;
  return uVar2 * 0x18;
}

//==== 0x4b7ec  0x4b7ec-0x4b95f inclusive
void FUN_0004b7ec(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  
  iVar3 = DAT_0004b960/*=0xa110c80*/;
  uVar6 = param_2 + 1;
  uVar1 = 0;
  while (iVar5 = DAT_0004b964/*=0xa110510*/, (uVar1 & 0xffff) < uVar6) {
    *(undefined4 *)(uVar1 * 0x400000 + iVar3) = 0;
    uVar1 = uVar1 + 1;
  }
  uVar2 = 0;
  while( true ) {
    iVar3 = DAT_0004b964/*=0xa110510*/;
    if (uVar6 <= uVar2) break;
    iVar3 = (uint)uVar2 * 0x400000;
    *(uint *)(iVar3 + iVar5) = *(uint *)(iVar3 + iVar5) | 0x1001;
    uVar2 = uVar2 + 1;
  }
  uVar2 = 0;
  while( true ) {
    iVar5 = DAT_0004b960/*=0xa110c80*/;
    if (uVar6 <= uVar2) break;
    iVar5 = (uint)uVar2 * 0x400000;
    *(uint *)(iVar5 + iVar3) = *(uint *)(iVar5 + iVar3) | 0x20;
    uVar2 = uVar2 + 1;
  }
  uVar2 = 0;
  while( true ) {
    if (uVar6 <= uVar2) break;
    *(undefined4 *)((uint)uVar2 * 0x400000 + iVar5) = 1;
    uVar2 = uVar2 + 1;
  }
  for (uVar2 = 0; uVar2 < uVar6; uVar2 = uVar2 + 1) {
    do {
    } while (-1 < *(int *)(DAT_0004b968/*=0xa110c84*/ + (uint)uVar2 * 0x400000) << 0x1f);
  }
  for (uVar1 = 0; (uVar1 & 0xffff) < uVar6; uVar1 = uVar1 + 1) {
    do {
    } while (-1 < *(int *)(DAT_0004b96c/*=0xa110514*/ + uVar1 * 0x400000) << 0x1f);
  }
  FUN_00048d80(0x32);
  *DAT_0004b970/*=0x7010250*/ = *DAT_0004b970/*=0x7010250*/ | 1;
  FUN_00048d80(2000);
  iVar3 = DAT_0004b960/*=0xa110c80*/;
  uVar1 = 0;
  while (iVar5 = DAT_0004b964/*=0xa110510*/, (uVar1 & 0xffff) < uVar6) {
    *(undefined4 *)(uVar1 * 0x400000 + iVar3) = 0;
    uVar1 = uVar1 + 1;
  }
  uVar2 = 0;
  while( true ) {
    iVar3 = DAT_0004b974/*=0xa110180*/;
    if (uVar6 <= uVar2) break;
    iVar3 = (uint)uVar2 * 0x400000;
    *(uint *)(iVar3 + iVar5) = *(uint *)(iVar3 + iVar5) & 0xffffffdf;
    uVar2 = uVar2 + 1;
  }
  uVar2 = 0;
  while( true ) {
    if (uVar6 <= uVar2) break;
    iVar5 = (uint)uVar2 * 0x400000;
    *(uint *)(iVar5 + iVar3) = *(uint *)(iVar5 + iVar3) & 0xfffff7ff;
    uVar2 = uVar2 + 1;
  }
  for (uVar1 = 0; (uVar1 & 0xffff) < uVar6; uVar1 = uVar1 + 1) {
    puVar4 = (uint *)(DAT_0004b978/*=0xa110014*/ + uVar1 * 0x400000);
    do {
    } while ((*puVar4 & 0x30) != 0);
    do {
    } while ((*puVar4 & 3) != 1);
  }
  FUN_00048d80(0x32);
  iVar3 = DAT_0004b964/*=0xa110510*/;
  uVar2 = 0;
  while( true ) {
    iVar5 = DAT_0004b960/*=0xa110c80*/;
    if (uVar6 <= uVar2) break;
    iVar5 = (uint)uVar2 * 0x400000;
    *(uint *)(iVar5 + iVar3) = *(uint *)(iVar5 + iVar3) & 0xfffffffe;
    uVar2 = uVar2 + 1;
  }
  uVar2 = 0;
  while( true ) {
    if (uVar6 <= uVar2) break;
    *(undefined4 *)((uint)uVar2 * 0x400000 + iVar5) = 1;
    uVar2 = uVar2 + 1;
  }
  for (uVar1 = 0; (uVar1 & 0xffff) < uVar6; uVar1 = uVar1 + 1) {
    do {
    } while (-1 < *(int *)(DAT_0004b968/*=0xa110c84*/ + uVar1 * 0x400000) << 0x1f);
  }
  FUN_00048d80(2,DAT_0004b968/*=0xa110c84*/,uVar1,param_4);
  return;
}

//==== 0x4b97c  0x4b97c-0x4bb3f inclusive
void FUN_0004b97c(int param_1)

{
  byte bVar1;
  ushort *puVar2;
  undefined1 *puVar3;
  byte *pbVar4;
  undefined1 *puVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  byte *pbVar8;
  ushort uVar9;
  undefined1 *puVar10;
  byte *pbVar11;
  ushort *puVar12;
  ushort *puVar13;
  undefined1 auStack_f8 [8];
  undefined1 auStack_f0 [8];
  undefined1 auStack_e8 [8];
  undefined1 auStack_e0 [8];
  undefined1 auStack_d8 [8];
  undefined1 auStack_d0 [8];
  undefined1 auStack_c8 [8];
  undefined1 auStack_c0 [8];
  undefined1 auStack_b8 [8];
  undefined1 auStack_b0 [8];
  undefined1 auStack_a8 [8];
  undefined1 auStack_a0 [8];
  undefined1 auStack_98 [8];
  undefined1 auStack_90 [8];
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [8];
  undefined1 local_78 [8];
  undefined1 local_70 [8];
  undefined1 local_68 [8];
  undefined1 local_60 [8];
  undefined1 auStack_58 [8];
  undefined1 auStack_50 [8];
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [8];
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [8];
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [12];
  
  puVar3 = auStack_f8;
  thunk_FUN_00047d1c(auStack_f8,DAT_0004bb40/*=0x5e5e0*/,8);
  thunk_FUN_00047d1c(auStack_f0,DAT_0004bb44/*=0x5e5e8*/);
  thunk_FUN_00047d1c(auStack_e8,DAT_0004bb48/*=0x5e5f0*/,8);
  thunk_FUN_00047d1c(auStack_e0,DAT_0004bb4c/*=0x5e5f8*/,8);
  thunk_FUN_00047d1c(auStack_d8,DAT_0004bb50/*=0x5e600*/,8);
  thunk_FUN_00047d1c(auStack_d0,DAT_0004bb54/*=0x5e608*/,8);
  thunk_FUN_00047d1c(auStack_c8,DAT_0004bb58/*=0x5e610*/,8);
  thunk_FUN_00047d1c(auStack_c0,DAT_0004bb5c/*=0x5e618*/,8);
  thunk_FUN_00047d1c(auStack_b8,DAT_0004bb60/*=0x5e620*/,8);
  thunk_FUN_00047d1c(auStack_b0,DAT_0004bb64/*=0x5e628*/,8);
  thunk_FUN_00047d1c(auStack_a8,DAT_0004bb68/*=0x5e630*/,8);
  thunk_FUN_00047d1c(auStack_a0,DAT_0004bb6c/*=0x5e638*/,8);
  thunk_FUN_00047d1c(auStack_98,DAT_0004bb70/*=0x5e640*/,8);
  thunk_FUN_00047d1c(auStack_90,DAT_0004bb74/*=0x5e648*/,8);
  thunk_FUN_00047d1c(auStack_88,DAT_0004bb78/*=0x5e650*/,8);
  thunk_FUN_00047d1c(auStack_80,DAT_0004bb7c/*=0x5e658*/,8);
  thunk_FUN_00047d1c(local_78,DAT_0004bb80/*=0x5e660*/,8);
  thunk_FUN_00047d1c(local_70,DAT_0004bb84/*=0x5e668*/,8);
  thunk_FUN_00047d1c(local_68,DAT_0004bb88/*=0x5e670*/,8);
  thunk_FUN_00047d1c(local_60,DAT_0004bb8c/*=0x5e678*/,8);
  thunk_FUN_00047d1c(auStack_58,DAT_0004bb90/*=0x5e680*/,8);
  thunk_FUN_00047d1c(auStack_50,DAT_0004bb94/*=0x5e688*/,8);
  thunk_FUN_00047d1c(auStack_48,DAT_0004bb98/*=0x5e690*/,8);
  thunk_FUN_00047d1c(auStack_40,DAT_0004bb9c/*=0x5e698*/,8);
  thunk_FUN_00047d1c(auStack_38,DAT_0004bba0/*=0x5e6a0*/,8);
  thunk_FUN_00047d1c(auStack_30,DAT_0004bba4/*=0x5e6a8*/,8);
  thunk_FUN_00047d1c(auStack_28,DAT_0004bba8/*=0x5e6b0*/,8);
  thunk_FUN_00047d1c(auStack_20,DAT_0004bbac/*=0x5e6b8*/,8);
  puVar2 = DAT_0004bbb4/*=0xa920110*/;
  uVar9 = *(ushort *)(param_1 + 0x66) & 0xf;
  if (*(int *)(param_1 + 4) != 8) {
    if (uVar9 == 1) {
      puVar10 = auStack_20;
      puVar7 = auStack_28;
      puVar5 = auStack_30;
      puVar3 = auStack_38;
    }
    else {
      puVar10 = auStack_40;
      puVar7 = auStack_48;
      puVar5 = auStack_50;
      puVar3 = auStack_58;
    }
    goto LAB_0004bac6;
  }
  if ((*(ushort *)(param_1 + 0x66) & 0xf) != 0) {
    if (uVar9 == 1) {
      puVar10 = auStack_c0;
      puVar7 = auStack_c8;
      puVar5 = auStack_d0;
      puVar3 = auStack_d8;
      goto LAB_0004bac6;
    }
    if (uVar9 == 2) {
      puVar10 = auStack_a0;
      puVar7 = auStack_a8;
      puVar5 = auStack_b0;
      puVar3 = auStack_b8;
      goto LAB_0004bac6;
    }
    if (uVar9 == 3) {
      puVar10 = auStack_80;
      puVar7 = auStack_88;
      puVar5 = auStack_90;
      puVar3 = auStack_98;
      goto LAB_0004bac6;
    }
    if (uVar9 == 4) {
      puVar10 = local_60;
      puVar7 = local_68;
      puVar5 = local_70;
      puVar3 = local_78;
      goto LAB_0004bac6;
    }
  }
  puVar10 = auStack_e0;
  puVar7 = auStack_e8;
  puVar5 = auStack_f0;
LAB_0004bac6:
  pbVar4 = puVar3 + -1;
  pbVar6 = puVar5 + -1;
  pbVar8 = puVar7 + -1;
  pbVar11 = puVar10 + -1;
  puVar12 = DAT_0004bbb0/*=0xa920100*/;
  do {
    pbVar4 = pbVar4 + 1;
    pbVar6 = pbVar6 + 1;
    bVar1 = *pbVar6;
    *puVar12 = (ushort)*pbVar4;
    puVar12[0x1000] = (ushort)bVar1;
    pbVar8 = pbVar8 + 1;
    puVar12[0x2000] = (ushort)*pbVar8;
    puVar13 = puVar12 + 0x3000;
    pbVar11 = pbVar11 + 1;
    puVar12 = puVar12 + 1;
    *puVar13 = (ushort)*pbVar11;
  } while (puVar12 != puVar2);
  return;
}

//==== 0x4bbb8  0x4bbb8-0x4bc81 inclusive
void FUN_0004bbb8(int param_1)

{
  ushort *puVar1;
  ushort uVar2;
  undefined2 uVar3;
  byte *pbVar4;
  byte bStack_68;
  byte abStack_67 [95];
  
  pbVar4 = &bStack_68;
  thunk_FUN_00047d1c(&bStack_68,DAT_0004bc84/*=0x5e6c0*/,0xe);
  thunk_FUN_00047d1c(abStack_67 + 0xf,DAT_0004bc88/*=0x5e6ce*/,0xe);
  thunk_FUN_00047d1c(abStack_67 + 0x1f,DAT_0004bc8c/*=0x5e6dc*/,0xe);
  thunk_FUN_00047d1c(abStack_67 + 0x2f,DAT_0004bc90/*=0x5e6ea*/,0xe);
  thunk_FUN_00047d1c(abStack_67 + 0x3f,DAT_0004bc94/*=0x5e6f8*/,0xe);
  thunk_FUN_00047d1c(abStack_67 + 0x4f,DAT_0004bc98/*=0x5e706*/,0xe);
  if (*(int *)(param_1 + 4) != 8) {
    uVar3 = 3;
    pbVar4 = abStack_67 + 0x4f;
    goto LAB_0004bc1e;
  }
  uVar2 = *(ushort *)(param_1 + 0x66) & 0xf;
  if ((*(ushort *)(param_1 + 0x66) & 0xf) != 0) {
    if (uVar2 == 1) {
      uVar3 = 5;
      pbVar4 = abStack_67 + 0xf;
      goto LAB_0004bc1e;
    }
    if (uVar2 == 2) {
      uVar3 = 0;
      pbVar4 = abStack_67 + 0x1f;
      goto LAB_0004bc1e;
    }
    if (uVar2 == 3) {
      pbVar4 = abStack_67 + 0x2f;
      uVar3 = 3;
      goto LAB_0004bc1e;
    }
    if (uVar2 == 4) {
      uVar3 = 0;
      pbVar4 = abStack_67 + 0x3f;
      goto LAB_0004bc1e;
    }
  }
  uVar3 = 5;
LAB_0004bc1e:
  *DAT_0004bc9c/*=0xa960120*/ = uVar3;
  puVar1 = DAT_0004bca0/*=0xa960122*/;
  *DAT_0004bca0/*=0xa960122*/ = (ushort)pbVar4[1];
  puVar1[1] = (ushort)pbVar4[2];
  puVar1[2] = (ushort)pbVar4[3];
  puVar1[3] = (ushort)pbVar4[4];
  puVar1[4] = (ushort)pbVar4[5];
  puVar1[5] = (ushort)pbVar4[6];
  puVar1[0xfff] = (ushort)pbVar4[7];
  puVar1[0x1000] = (ushort)pbVar4[8];
  puVar1[0x1001] = (ushort)pbVar4[9];
  puVar1[0x1002] = (ushort)pbVar4[10];
  puVar1[0x1003] = (ushort)pbVar4[0xb];
  puVar1[0x1004] = (ushort)pbVar4[0xc];
  *DAT_0004bca4/*=0xa96212c*/ = (ushort)pbVar4[0xd];
  return;
}

//==== 0x4f46c  0x4f46c-0x4f479 inclusive
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
    *DAT_00059404/*=0xaaa0000*/ = 0;
    thunk_FUN_00048d80(1);
    iVar20 = DAT_0005940c/*=0x6d174*/;
    puVar11 = DAT_00059408/*=0xa982000*/;
    uVar21 = *(uint *)(param_1 + 0x1c);
    *DAT_00059408/*=0xa982000*/ = 0;
    puVar11[1] = 0;
    puVar11[2] = 0;
    puVar11[3] = 0;
    puVar11[4] = 0;
    puVar11[5] = 0;
    puVar11[6] = 0;
    puVar11[7] = 0;
    puVar17 = DAT_00059b3c/*=0xa9826d0*/;
    puVar10 = DAT_00059414/*=0xa982790*/;
    iVar8 = DAT_00059410/*=0xf567dcf0*/;
    if ((uVar21 & 0x1000) == 0) {
      puVar11 = DAT_00059b38/*=0xa982310*/;
      do {
        puVar18 = puVar11 + 1;
        *puVar11 = *(undefined2 *)(((int)puVar11 + iVar8 & 0xfffffffeU) + iVar20 + 0xd1a);
        puVar10 = DAT_00059b4c/*=0xaa208c6*/;
        iVar7 = DAT_00059b48/*=0xf55dffa4*/;
        iVar16 = DAT_00059b44/*=0x6e26c*/;
        puVar11 = puVar18;
      } while (puVar18 != puVar17);
      puVar11 = DAT_00059b40/*=0xaa2005c*/;
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
        puVar17 = DAT_00059420/*=0xaa208f6*/;
        iVar16 = DAT_0005941c/*=0xf55dffa4*/;
        puVar11 = puVar18;
      } while (puVar18 != puVar10);
      puVar11 = DAT_00059418/*=0xaa2005c*/;
      do {
        puVar10 = puVar11 + 1;
        *puVar11 = *(undefined2 *)(((int)puVar11 + iVar16 & 0xfffffffeU) + iVar20 + 0x480);
        puVar11 = puVar10;
      } while (puVar10 != puVar17);
    }
    puVar17 = DAT_0005942c/*=0xaa20e10*/;
    puVar10 = DAT_00059428/*=0xaa20056*/;
    puVar11 = DAT_00059424/*=0xaaa01ce*/;
    *DAT_00059424/*=0xaaa01ce*/ = 0x600;
    puVar11[-0x400cb] = 0;
    puVar11[-0x400c7] = 0x58;
    puVar11[-0x400c3] = 99;
    puVar19 = DAT_00059438/*=0xaa20e02*/;
    puVar18 = DAT_00059434/*=0xaa20e00*/;
    puVar11 = DAT_00059430/*=0xaa2004a*/;
    *DAT_00059430/*=0xaa2004a*/ = 0x1e;
    puVar11[1] = 0x1e;
    puVar15 = DAT_0005943c/*=0xaa20e06*/;
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
    puVar10 = DAT_00059444/*=0xa94024a*/;
    puVar11 = DAT_00059440/*=0xaa20e08*/;
    *DAT_00059440/*=0xaa20e08*/ = 0;
    puVar11[1] = 0;
    puVar11[2] = 0;
    puVar11[3] = 0;
    puVar11[-0x7057a] = 0;
    puVar17 = DAT_00059448/*=0xa940248*/;
    *DAT_00059448/*=0xa940248*/ = 1;
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
    puVar10 = DAT_00059450/*=0xa94024e*/;
    puVar11 = DAT_0005944c/*=0xa94024c*/;
    *DAT_0005944c/*=0xa94024c*/ = 1;
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
    puVar10 = DAT_00059458/*=0xa940252*/;
    puVar11 = DAT_00059454/*=0xa940250*/;
    *DAT_00059454/*=0xa940250*/ = 0xf;
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
    puVar10 = DAT_00059460/*=0xa940256*/;
    puVar11 = DAT_0005945c/*=0xa940254*/;
    *DAT_0005945c/*=0xa940254*/ = 0xf;
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
    puVar10 = DAT_00059468/*=0xa94025a*/;
    puVar11 = DAT_00059464/*=0xa940258*/;
    *DAT_00059464/*=0xa940258*/ = 0x14;
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
    puVar10 = DAT_00059470/*=0xa94025e*/;
    puVar11 = DAT_0005946c/*=0xa94025c*/;
    *DAT_0005946c/*=0xa94025c*/ = 0x14;
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
    puVar2 = DAT_000594b8/*=0xa94035e*/;
    puVar10 = DAT_00059478/*=0xa940330*/;
    puVar11 = DAT_00059474/*=0xa940260*/;
    *DAT_00059474/*=0xa940260*/ = 0x31;
    puVar11[0x67] = 0x30;
    puVar11[1] = 0x33;
    *puVar10 = 0x32;
    puVar10[-0x66] = 0x31;
    puVar10[1] = 0x30;
    puVar4 = DAT_000594c0/*=0xa940360*/;
    puVar3 = DAT_000594bc/*=0xa940292*/;
    puVar11 = DAT_0005947c/*=0xa940266*/;
    *DAT_0005947c/*=0xa940266*/ = 0x33;
    puVar11[0x67] = 0x32;
    puVar11[1] = 0x31;
    puVar11[0x68] = 0x31;
    puVar11[2] = 0x33;
    puVar11[0x69] = 0x33;
    puVar11[3] = 0x31;
    puVar11[0x6a] = 0x31;
    puVar6 = DAT_000594c8/*=0xa940362*/;
    puVar5 = DAT_000594c4/*=0xa940294*/;
    puVar17 = DAT_00059480/*=0xa94026e*/;
    *DAT_00059480/*=0xa94026e*/ = 0x33;
    puVar17[0x67] = 0x33;
    puVar15 = DAT_0005948c/*=0xa940298*/;
    puVar19 = DAT_00059488/*=0xa940364*/;
    puVar18 = DAT_00059484/*=0xa940270*/;
    *DAT_00059484/*=0xa940270*/ = 0x32;
    puVar18[0x67] = 0x32;
    puVar17[2] = 0x34;
    puVar17[0x69] = 0x34;
    puVar17[3] = 0x32;
    puVar17[0x6a] = 0x32;
    puVar1 = DAT_00059494/*=0xa940366*/;
    puVar18 = DAT_00059490/*=0xa940276*/;
    *DAT_00059490/*=0xa940276*/ = 0x34;
    puVar18[0x67] = 0x34;
    puVar18 = DAT_00059498/*=0xa940278*/;
    *DAT_00059498/*=0xa940278*/ = 0x35;
    puVar18[0x67] = 0x35;
    puVar18[1] = 0x35;
    puVar18[0x68] = 0x35;
    puVar18[2] = 0x35;
    puVar18[0x69] = 0x35;
    puVar18[3] = 0x35;
    puVar18[0x6a] = 0x35;
    puVar18 = DAT_0005949c/*=0xa940280*/;
    *DAT_0005949c/*=0xa940280*/ = 0x36;
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
    *DAT_000594a0/*=0xa940290*/ = 0x37;
    puVar18 = DAT_00059cc4/*=0xa940296*/;
    puVar17 = DAT_000594a4/*=0xa940296*/;
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
      *DAT_00059cc8/*=0xa9402a0*/ = 0x4b;
      puVar18[0x6c] = 0x51;
      puVar18[6] = 0x4b;
      puVar18[0x6d] = 0x51;
      puVar18[7] = 0x4b;
      puVar18[0x6e] = 0x51;
      puVar18[8] = 0x4b;
      *DAT_00059ccc/*=0xa940374*/ = 0x51;
      *DAT_00059cd0/*=0xa9402a8*/ = 0x52;
      puVar18[0x70] = 0x56;
      puVar18[10] = 0x52;
      puVar18[0x71] = 0x56;
      puVar18[0xb] = 0x52;
      puVar18[0x72] = 0x56;
      puVar18[0xc] = 0x52;
      *DAT_00059cd4/*=0xa94037c*/ = 0x56;
      *DAT_00059cd8/*=0xa9402b0*/ = 0x57;
      puVar18[0x74] = 0x5c;
      puVar18[0xe] = 0x57;
      puVar18[0x75] = 0x5c;
      puVar18[0xf] = 0x57;
      puVar18[0x76] = 0x5c;
      puVar18[0x10] = 0x57;
      *DAT_00059cdc/*=0xa940384*/ = 0x5c;
      *DAT_00059ce0/*=0xa9402b8*/ = 0x5d;
      puVar18[0x78] = 0x62;
      puVar18[0x12] = 0x5d;
      puVar18[0x79] = 0x62;
      puVar18[0x13] = 0x5d;
      puVar18[0x7a] = 0x62;
      puVar18[0x14] = 0x5d;
      *DAT_00059ce4/*=0xa94038c*/ = 0x62;
      *DAT_00059ce8/*=0xa9402c0*/ = 99;
      puVar18[0x7c] = 0x67;
      puVar18[0x16] = 99;
      puVar18[0x7d] = 0x67;
      puVar18[0x17] = 99;
      puVar18[0x7e] = 0x67;
      puVar18[0x18] = 99;
      *DAT_00059cec/*=0xa940394*/ = 0x67;
      puVar18[0x19] = 0x68;
      puVar18[0x80] = 0x67;
      puVar18[0x1a] = 0x68;
      puVar18[0x81] = 0x67;
      puVar18[0x1b] = 0x68;
      puVar18[0x82] = 0x67;
      puVar18[0x1c] = 0x68;
      puVar18[0x83] = 0x67;
      *DAT_00059cf0/*=0xa9402d0*/ = 0x68;
      puVar18[0x84] = 0x6c;
      puVar18[0x1e] = 0x68;
      puVar18[0x85] = 0x6c;
      puVar18[0x1f] = 0x68;
      puVar18[0x86] = 0x6c;
      puVar18[0x20] = 0x68;
      puVar11 = DAT_00059cf4/*=0xa9403a4*/;
      *DAT_00059cf4/*=0xa9403a4*/ = 0x6c;
      puVar11[0x210f1] = 0x4b00;
      puVar11[0x210f5] = 0;
      puVar18[0x21190] = 0x7b00;
      puVar18[0x21194] = 0;
      puVar18[0x211a8] = 0x4b00;
      puVar11 = DAT_00059cf8/*=0xa9825ee*/;
      *DAT_00059cf8/*=0xa9825ee*/ = 0;
      puVar11[0x14] = 0x7b00;
      *DAT_00059cfc/*=0xa98261e*/ = 0;
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
      *DAT_000594a8/*=0xa94036c*/ = 0x4f;
      *DAT_000594ac/*=0xa9402a0*/ = 0x50;
      puVar17[0x6c] = 0x59;
      puVar17[6] = 0x50;
      puVar17[0x6d] = 0x59;
      puVar17[7] = 0x50;
      puVar17[0x6e] = 0x59;
      puVar17[8] = 0x50;
      *DAT_000594b0/*=0xa940374*/ = 0x59;
      *DAT_000594b4/*=0xa9402a8*/ = 0x5a;
      puVar17[0x70] = 0x62;
      puVar17[10] = 0x5a;
      puVar17[0x71] = 0x62;
      puVar17[0xb] = 0x5a;
      puVar17[0x72] = 0x62;
      puVar17[0xc] = 0x5a;
      *DAT_000597a4/*=0xa94037c*/ = 0x62;
      *DAT_000597a8/*=0xa9402b0*/ = 99;
      puVar17[0x74] = 0x68;
      puVar17[0xe] = 99;
      puVar17[0x75] = 0x68;
      puVar17[0xf] = 99;
      puVar17[0x76] = 0x68;
      puVar17[0x10] = 99;
      *DAT_000597ac/*=0xa940384*/ = 0x68;
      *DAT_000597b0/*=0xa9402b8*/ = 0x69;
      puVar17[0x78] = 0x6e;
      puVar17[0x12] = 0x69;
      puVar17[0x79] = 0x6e;
      puVar17[0x13] = 0x69;
      puVar17[0x7a] = 0x6e;
      puVar17[0x14] = 0x69;
      *DAT_000597b4/*=0xa94038c*/ = 0x6e;
      *DAT_000597b8/*=0xa9402c0*/ = 0x6f;
      puVar17[0x7c] = 0x73;
      puVar17[0x16] = 0x6f;
      puVar17[0x7d] = 0x73;
      puVar17[0x17] = 0x6f;
      puVar17[0x7e] = 0x73;
      puVar17[0x18] = 0x6f;
      *DAT_000597bc/*=0xa940394*/ = 0x73;
      puVar17[0x19] = 0x74;
      puVar17[0x80] = 0x73;
      puVar17[0x1a] = 0x74;
      puVar17[0x81] = 0x73;
      puVar17[0x1b] = 0x74;
      puVar17[0x82] = 0x73;
      puVar17[0x1c] = 0x74;
      puVar17[0x83] = 0x73;
      *DAT_000597c0/*=0xa9402d0*/ = 0x74;
      puVar17[0x84] = 0x78;
      puVar17[0x1e] = 0x74;
      puVar17[0x85] = 0x78;
      puVar17[0x1f] = 0x74;
      puVar17[0x86] = 0x78;
      puVar17[0x20] = 0x74;
      puVar10 = DAT_000597c4/*=0xa9403a4*/;
      *DAT_000597c4/*=0xa9403a4*/ = 0x78;
      puVar17 = DAT_000597c8/*=0xa98264e*/;
      puVar10[0x21151] = 0x4b00;
      *puVar17 = 0;
      puVar11[0x21208] = 0x7b00;
      puVar11[0x2120c] = 0;
      puVar11[0x21220] = 0x4b00;
      puVar11 = DAT_000597cc/*=0xa9826ae*/;
      *DAT_000597cc/*=0xa9826ae*/ = 0;
      puVar11[0x14] = 0x7b00;
      *DAT_000597d0/*=0xa9826de*/ = 0;
    }
    iVar20 = DAT_000597dc/*=0xf567dff0*/;
    puVar10 = DAT_000597d8/*=0xa982030*/;
    puVar11 = DAT_000597d4/*=0xa982010*/;
    if (iVar12 == 8) {
      puVar17 = DAT_000597d4/*=0xa982010*/;
      do {
        puVar19 = puVar17 + 1;
        *puVar17 = *(undefined2 *)((int)auStack_48 + ((int)puVar17 + iVar20 & 0xfffffffeU));
        iVar8 = DAT_000597e4/*=0xf567dfd0*/;
        puVar18 = DAT_000597e0/*=0xa982012*/;
        puVar17 = puVar19;
      } while (puVar19 != puVar10);
      *DAT_000597e0/*=0xa982012*/ = 0xd800;
      uVar14 = uVar21 & 0x1000;
      if (uVar14 == 0) {
        *puVar11 = 0x2066;
        uVar9 = 0x1e01;
        puVar11 = DAT_000597e8/*=0xa982050*/;
      }
      else {
        *puVar11 = 0x20e6;
        uVar9 = 0x1e03;
        puVar11 = DAT_000597e8/*=0xa982050*/;
      }
      DAT_000597e8/*=0xa982050*/ = puVar11;
      puVar18[1] = uVar9;
      do {
        puVar18 = puVar19 + 1;
        *puVar19 = *(undefined2 *)((int)auStack_48 + ((int)puVar19 + iVar8 & 0xfffffffeU));
        puVar17 = DAT_000597ec/*=0xa982032*/;
        puVar19 = puVar18;
      } while (puVar18 != puVar11);
      *DAT_000597ec/*=0xa982032*/ = 0x5800;
      if (uVar14 == 0) {
        *puVar10 = 0x4046;
        uVar9 = 0x1f81;
      }
      else {
        *puVar10 = 0x40c6;
        uVar9 = 0x1f83;
      }
      iVar20 = DAT_000597f4/*=0xf567dfb0*/;
      puVar10 = DAT_000597f0/*=0xa982070*/;
      puVar17[1] = uVar9;
      do {
        puVar19 = puVar18 + 1;
        *puVar18 = *(undefined2 *)((int)auStack_48 + ((int)puVar18 + iVar20 & 0xfffffffeU));
        puVar17 = DAT_000597f8/*=0xa982052*/;
        puVar18 = puVar19;
      } while (puVar19 != puVar10);
      *DAT_000597f8/*=0xa982052*/ = 0x5800;
      if (uVar14 == 0) {
        *puVar11 = 0x6046;
        uVar9 = 0x1981;
      }
      else {
        *puVar11 = 0x60c6;
        uVar9 = 0x1983;
      }
      puVar17[1] = uVar9;
      iVar20 = DAT_00059800/*=0xf567df90*/;
      puVar11 = DAT_000597fc/*=0xa982090*/;
      do {
        puVar15 = puVar19 + 1;
        *puVar19 = *(undefined2 *)((int)auStack_48 + ((int)puVar19 + iVar20 & 0xfffffffeU));
        puVar18 = DAT_00059808/*=0xa982074*/;
        puVar17 = DAT_00059804/*=0xa982072*/;
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
      puVar10 = DAT_00059814/*=0xa9820c0*/;
      iVar20 = DAT_00059810/*=0xf567df60*/;
      puVar11 = DAT_0005980c/*=0xa982092*/;
      *DAT_0005980c/*=0xa982092*/ = 0x5802;
      puVar11[1] = 0x1201;
      puVar11 = DAT_00059818/*=0xa982096*/;
      *DAT_00059818/*=0xa982096*/ = 0;
      puVar11[1] = 0;
      puVar11[2] = 0;
      puVar11[3] = 0;
      puVar11[4] = 0;
      puVar11 = DAT_0005981c/*=0xa9820a0*/;
      puVar17 = DAT_0005981c/*=0xa9820a0*/;
      do {
        puVar15 = puVar17 + 1;
        *puVar17 = *(undefined2 *)((int)auStack_48 + ((int)puVar17 + iVar20 & 0xfffffffeU));
        puVar19 = DAT_00059824/*=0xa9820a4*/;
        puVar18 = DAT_00059820/*=0xa9820a2*/;
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
      puVar11 = DAT_00059828/*=0xa9820f0*/;
      do {
        puVar10 = puVar15 + 1;
        *puVar15 = 0;
        puVar15 = puVar10;
      } while (puVar10 != puVar11);
    }
    puVar10 = DAT_00059830/*=0xaa21248*/;
    puVar11 = DAT_0005982c/*=0xaa80002*/;
    *DAT_0005982c/*=0xaa80002*/ = 0x5061;
    puVar11[1] = 0x7098;
    puVar11 = DAT_00059834/*=0xaa80006*/;
    *DAT_00059834/*=0xaa80006*/ = 0;
    puVar11[-3] = 0xbedc;
    puVar11[3] = 0xb0db;
    puVar11[4] = 0;
    puVar11[-0x2f8f7] = 0;
    puVar11 = DAT_00059838/*=0xaa20e1a*/;
    *DAT_00059838/*=0xaa20e1a*/ = 0x7ff;
    puVar11[1] = 0x668;
    puVar11[2] = 0x7910;
    puVar11[3] = 0x355e;
    puVar11[4] = 0xcbb5;
    puVar11 = DAT_00059840/*=0xaa20e28*/;
    if ((uVar13 & 4) == 0) {
      *DAT_0005983c/*=0xaa20e26*/ = 0xffff;
      uVar9 = 0x710;
    }
    else {
      *DAT_0005983c/*=0xaa20e26*/ = 0x710;
      uVar9 = 0xffff;
    }
    *puVar11 = uVar9;
    *DAT_00059844/*=0xaa20e2a*/ = 0x7800;
    puVar11 = DAT_00059848/*=0xaa21820*/;
    *DAT_00059848/*=0xaa21820*/ = 0xffff;
    puVar11[2] = 0xff10;
    puVar11[-0x4fe] = 0x2ee8;
    puVar11[1] = 0xffff;
    puVar11 = DAT_00059850/*=0xaa20e30*/;
    *DAT_0005984c/*=0xaa20e2c*/ = 0xffdf;
    puVar17 = DAT_00059854/*=0xaa20e2e*/;
    *DAT_00059854/*=0xaa20e2e*/ = 0x6f10;
    *puVar11 = 0x6f10;
    puVar17[2] = 0x2868;
    puVar17[3] = 0x2868;
    *DAT_00059afc/*=0xaa20e36*/ = 0xfeef;
    puVar17 = DAT_00059b00/*=0xaa21208*/;
    *DAT_00059b00/*=0xaa21208*/ = 0xe400;
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
    puVar17 = DAT_00059b08/*=0xa920144*/;
    puVar10 = DAT_00059b04/*=0xaa21214*/;
    *DAT_00059b04/*=0xaa21214*/ = 0;
    puVar10[2] = 0;
    if ((uVar21 & 0x1000) == 0) {
      *DAT_00059b0c/*=0xaa2121a*/ = 0;
    }
    else {
      *DAT_00059b0c/*=0xaa2121a*/ = 1;
    }
    *puVar11 = 0xffff;
    *DAT_00059b10/*=0xa9401e0*/ = 0x27f7;
    puVar11 = DAT_00059b14/*=0xa9401e2*/;
    *DAT_00059b14/*=0xa9401e2*/ = 0x2108;
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
    puVar11 = DAT_00059b18/*=0xa926174*/;
    *DAT_00059b18/*=0xa926174*/ = 1;
    puVar11[-0x18] = 0;
    puVar10 = DAT_00059b1c/*=0xa92616a*/;
    *DAT_00059b1c/*=0xa92616a*/ = 1;
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
    puVar10 = DAT_00059b20/*=0xa9e00ca*/;
    *DAT_00059b20/*=0xa9e00ca*/ = 0x1ff;
    if ((uVar21 & 0x1000) == 0) {
      uVar9 = 0x44;
    }
    else {
      uVar9 = 0xcc;
    }
    puVar11[0xcfc0] = uVar9;
    puVar10[-0x4ffe7] = uVar9;
    puVar10 = DAT_00059b28/*=0xaaa0006*/;
    puVar11 = DAT_00059b24/*=0xa940050*/;
    *DAT_00059b24/*=0xa940050*/ = 2;
    puVar11[199] = 0xffff;
    puVar17 = DAT_00059b2c/*=0xa940620*/;
    puVar11[0x708e8] = 2;
    *puVar17 = 1;
    puVar17[1] = 1;
    puVar11 = DAT_00059b30/*=0xaa80100*/;
    *DAT_00059b30/*=0xaa80100*/ = 2;
    *puVar10 = 0;
    *puVar11 = 0;
    *DAT_00059b34/*=0xaaa0000*/ = 1;
    return;
  }
  thunk_FUN_00047c40(auStack_48,0,0x20);
  local_32 = 0x2b00;
  iVar16 = *(int *)(param_1 + 4);
  *DAT_0005a514/*=0xaaa0000*/ = 0;
  thunk_FUN_00048d80(1);
  iVar20 = DAT_0005a51c/*=0xf567d8f0*/;
  puVar11 = DAT_0005a518/*=0xa982000*/;
  uVar21 = *(uint *)(param_1 + 0x1c);
  *DAT_0005a518/*=0xa982000*/ = 0;
  puVar11[1] = 0;
  puVar11[2] = 0;
  puVar11[3] = 0;
  puVar11[4] = 0;
  puVar11[5] = 0;
  puVar11[6] = 0;
  puVar11[7] = 0;
  puVar17 = DAT_0005af6c/*=0xa983580*/;
  iVar12 = DAT_0005af68/*=0x7ea8e*/;
  puVar10 = DAT_0005a524/*=0xa9838b0*/;
  iVar8 = DAT_0005a520/*=0x80cf6*/;
  if ((uVar21 & 0x1000) == 0) {
    puVar11 = DAT_0005af64/*=0xa982710*/;
    do {
      puVar18 = puVar11 + 1;
      *puVar11 = *(undefined2 *)(((int)puVar11 + iVar20 & 0xfffffffeU) + iVar12 + 0xa14);
      puVar10 = DAT_0005af7c/*=0xaa20a40*/;
      iVar7 = DAT_0005af78/*=0xf55dffa4*/;
      iVar8 = DAT_0005af74/*=0x7fb86*/;
      puVar11 = puVar18;
    } while (puVar18 != puVar17);
    puVar11 = DAT_0005af70/*=0xaa2005c*/;
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
      puVar17 = DAT_0005a534/*=0xaa20a70*/;
      iVar7 = DAT_0005a530/*=0xf55dffa4*/;
      iVar12 = DAT_0005a52c/*=0x7ea8e*/;
      puVar11 = puVar18;
    } while (puVar18 != puVar10);
    puVar11 = DAT_0005a528/*=0xaa2005c*/;
    do {
      puVar10 = puVar11 + 1;
      *puVar11 = *(undefined2 *)(iVar12 + ((int)puVar11 + iVar7 >> 1) * 2);
      puVar11 = puVar10;
    } while (puVar10 != puVar17);
  }
  puVar17 = DAT_0005a540/*=0xaa20e10*/;
  puVar10 = DAT_0005a53c/*=0xaa20056*/;
  puVar11 = DAT_0005a538/*=0xaaa01ce*/;
  *DAT_0005a538/*=0xaaa01ce*/ = 0x600;
  puVar11[-0x400cb] = 0;
  puVar11[-0x400c7] = 0x77;
  puVar11[-0x400c3] = 0x82;
  puVar19 = DAT_0005a54c/*=0xaa20e02*/;
  puVar18 = DAT_0005a548/*=0xaa20e00*/;
  puVar11 = DAT_0005a544/*=0xaa2004a*/;
  *DAT_0005a544/*=0xaa2004a*/ = 0x2b;
  puVar11[1] = 0x2b;
  puVar15 = DAT_0005a550/*=0xaa20e06*/;
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
  puVar10 = DAT_0005a558/*=0xa94024a*/;
  puVar11 = DAT_0005a554/*=0xaa20e08*/;
  *DAT_0005a554/*=0xaa20e08*/ = 0;
  puVar11[1] = 0;
  puVar11[2] = 0;
  puVar11[3] = 0;
  puVar11[-0x7057a] = 0;
  puVar17 = DAT_0005a55c/*=0xa940248*/;
  *DAT_0005a55c/*=0xa940248*/ = 1;
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
  puVar10 = DAT_0005a564/*=0xa94024e*/;
  puVar11 = DAT_0005a560/*=0xa94024c*/;
  *DAT_0005a560/*=0xa94024c*/ = 1;
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
  puVar10 = DAT_0005a56c/*=0xa940252*/;
  puVar11 = DAT_0005a568/*=0xa940250*/;
  *DAT_0005a568/*=0xa940250*/ = 0x17;
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
  puVar10 = DAT_0005a574/*=0xa940256*/;
  puVar11 = DAT_0005a570/*=0xa940254*/;
  *DAT_0005a570/*=0xa940254*/ = 0x17;
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
  puVar10 = DAT_0005a57c/*=0xa94025a*/;
  puVar11 = DAT_0005a578/*=0xa940258*/;
  *DAT_0005a578/*=0xa940258*/ = 0x28;
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
  puVar10 = DAT_0005a584/*=0xa94025e*/;
  puVar11 = DAT_0005a580/*=0xa94025c*/;
  *DAT_0005a580/*=0xa94025c*/ = 0x28;
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
  puVar10 = DAT_0005a58c/*=0xa940338*/;
  puVar11 = DAT_0005a588/*=0xa940260*/;
  *DAT_0005a588/*=0xa940260*/ = 0x80;
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
  puVar2 = DAT_0005a5dc/*=0xa940364*/;
  puVar1 = DAT_0005a5d8/*=0xa940362*/;
  *DAT_0005a590/*=0xa94033a*/ = 0x74;
  puVar3 = DAT_0005a5e0/*=0xa940298*/;
  puVar11 = DAT_0005a598/*=0xa94029a*/;
  *DAT_0005a594/*=0xa94026e*/ = 0x77;
  puVar17 = DAT_0005a5a0/*=0xa940368*/;
  *DAT_0005a59c/*=0xa94033c*/ = 0x7a;
  puVar18 = DAT_0005a5a4/*=0xa940270*/;
  *DAT_0005a5a4/*=0xa940270*/ = 0x75;
  puVar18[0x67] = 0x76;
  puVar18[1] = 0x7b;
  puVar10[4] = 0x7c;
  puVar10[-0x62] = 0x75;
  puVar18 = DAT_0005a5a8/*=0xa940342*/;
  *DAT_0005a5a8/*=0xa940342*/ = 0x76;
  puVar19 = DAT_0005a5ac/*=0xa940276*/;
  *DAT_0005a5ac/*=0xa940276*/ = 0x7b;
  *DAT_0005a5b0/*=0xa940344*/ = 0x7c;
  *DAT_0005a5b4/*=0xa940278*/ = 0x7d;
  puVar19[0x68] = 0x7e;
  puVar19[2] = 0x7d;
  puVar19[0x69] = 0x7e;
  puVar19[3] = 0x7d;
  puVar19[0x6a] = 0x7e;
  puVar19[4] = 0x7d;
  puVar19 = DAT_0005a5b8/*=0xa94034c*/;
  *DAT_0005a5b8/*=0xa94034c*/ = 0x7e;
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
  puVar19 = DAT_0005a5bc/*=0xa94035c*/;
  *DAT_0005a5bc/*=0xa94035c*/ = 0x7f;
  puVar19[-0x66] = 0x81;
  puVar19[1] = 0x93;
  puVar19[-0x65] = 0x81;
  *DAT_0005a5c0/*=0xa940360*/ = 0x93;
  puVar4 = DAT_0005b24c/*=0xa940296*/;
  puVar15 = DAT_0005a5c4/*=0xa940296*/;
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
    puVar11 = DAT_0005b254/*=0xa98317e*/;
    *DAT_0005b250/*=0xa9402a0*/ = 0x94;
    puVar4[0x6c] = 0x9e;
    puVar4[6] = 0x94;
    puVar4[0x6d] = 0x9e;
    *DAT_0005b258/*=0xa9402a4*/ = 0x101;
    puVar4[0x6e] = 0x109;
    puVar4[8] = 0x101;
    puVar10 = DAT_0005b25c/*=0xa940374*/;
    *DAT_0005b25c/*=0xa940374*/ = 0x109;
    puVar10[-0x66] = 0x9f;
    puVar4[0x70] = 0xa5;
    puVar4[10] = 0x9f;
    *DAT_0005b260/*=0xa940378*/ = 0xa5;
    *DAT_0005b264/*=0xa9402ac*/ = 0x10a;
    puVar4[0x72] = 0x110;
    puVar4[0xc] = 0x10a;
    *DAT_0005b268/*=0xa94037c*/ = 0x110;
    *DAT_0005b26c/*=0xa9402b0*/ = 0xa6;
    puVar4[0x74] = 0xaf;
    puVar4[0xe] = 0xa6;
    *DAT_0005b270/*=0xa940380*/ = 0xaf;
    *DAT_0005b274/*=0xa9402b4*/ = 0x111;
    puVar4[0x76] = 0x11a;
    puVar4[0x10] = 0x111;
    *DAT_0005b278/*=0xa940384*/ = 0x11a;
    *DAT_0005b27c/*=0xa9402b8*/ = 0xb0;
    puVar4[0x78] = 0xb9;
    puVar4[0x12] = 0xb0;
    *DAT_0005b280/*=0xa940388*/ = 0xb9;
    *DAT_0005b284/*=0xa9402bc*/ = 0x11b;
    puVar4[0x7a] = 0x124;
    puVar4[0x14] = 0x11b;
    *DAT_0005b288/*=0xa94038c*/ = 0x124;
    *DAT_0005b28c/*=0xa9402c0*/ = 0xba;
    puVar4[0x7c] = 0xc4;
    puVar4[0x16] = 0xba;
    *DAT_0005b290/*=0xa940390*/ = 0xc4;
    *DAT_0005b294/*=0xa9402c4*/ = 0x125;
    puVar4[0x7e] = 0x12e;
    puVar4[0x18] = 0x125;
    *DAT_0005b298/*=0xa940394*/ = 0x12e;
    *DAT_0005b29c/*=0xa9402c8*/ = 0xc5;
    puVar4[0x80] = 0xd3;
    puVar4[0x1a] = 0xc5;
    *DAT_0005b2a0/*=0xa940398*/ = 0xd3;
    *DAT_0005b2a4/*=0xa9402cc*/ = 0x12f;
    puVar4[0x82] = 0x13d;
    puVar4[0x1c] = 0x12f;
    *DAT_0005b2a8/*=0xa94039c*/ = 0x13d;
    *DAT_0005b2ac/*=0xa9402d0*/ = 0xd4;
    puVar4[0x84] = 0xde;
    puVar4[0x1e] = 0xd4;
    *DAT_0005b2b0/*=0xa9403a0*/ = 0xde;
    *DAT_0005b2b4/*=0xa9402d4*/ = 0x13e;
    puVar4[0x86] = 0x147;
    puVar4[0x20] = 0x13e;
    *DAT_0005b2b8/*=0xa9403a4*/ = 0x147;
    *DAT_0005b2bc/*=0xa9402d8*/ = 0xdf;
    puVar4[0x88] = 0xed;
    puVar4[0x22] = 0xdf;
    *DAT_0005b2c0/*=0xa9403a8*/ = 0xed;
    *DAT_0005b2c4/*=0xa9402dc*/ = 0x148;
    puVar4[0x8a] = 0x156;
    puVar4[0x24] = 0x148;
    *DAT_0005b2c8/*=0xa9403ac*/ = 0x156;
    puVar10 = DAT_0005b2cc/*=0xa9402e0*/;
    *DAT_0005b2cc/*=0xa9402e0*/ = 0xee;
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
    puVar10 = DAT_0005b2d0/*=0xa982e8e*/;
    *DAT_0005b2d0/*=0xa982e8e*/ = 0;
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
    *DAT_0005b2d4/*=0xa9834ce*/ = 0;
    puVar11 = DAT_0005b2d8/*=0xa983516*/;
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
    *DAT_0005a5c8/*=0xa94036c*/ = 0x122;
    *DAT_0005a5cc/*=0xa9402a0*/ = 0x9c;
    puVar15[0x6c] = 0xaf;
    puVar15[6] = 0x9c;
    *DAT_0005a5d0/*=0xa940370*/ = 0xaf;
    *DAT_0005a5d4/*=0xa9402a4*/ = 0x123;
    puVar15[0x6e] = 0x132;
    puVar15[8] = 0x123;
    *DAT_0005a8cc/*=0xa940374*/ = 0x132;
    *DAT_0005a8d0/*=0xa9402a8*/ = 0xb0;
    puVar15[0x70] = 0xc0;
    puVar15[10] = 0xb0;
    *DAT_0005a8d4/*=0xa940378*/ = 0xc0;
    *DAT_0005a8d8/*=0xa9402ac*/ = 0x133;
    puVar15[0x72] = 0x143;
    puVar15[0xc] = 0x133;
    *DAT_0005a8dc/*=0xa94037c*/ = 0x143;
    *DAT_0005a8e0/*=0xa9402b0*/ = 0xc1;
    puVar15[0x74] = 0xca;
    puVar15[0xe] = 0xc1;
    *DAT_0005a8e4/*=0xa940380*/ = 0xca;
    *DAT_0005a8e8/*=0xa9402b4*/ = 0x144;
    puVar15[0x76] = 0x14d;
    puVar15[0x10] = 0x144;
    *DAT_0005a8ec/*=0xa940384*/ = 0x14d;
    *DAT_0005a8f0/*=0xa9402b8*/ = 0xcb;
    puVar15[0x78] = 0xd4;
    puVar15[0x12] = 0xcb;
    *DAT_0005a8f4/*=0xa940388*/ = 0xd4;
    *DAT_0005a8f8/*=0xa9402bc*/ = 0x14e;
    puVar15[0x7a] = 0x157;
    puVar15[0x14] = 0x14e;
    *DAT_0005a8fc/*=0xa94038c*/ = 0x157;
    *DAT_0005a900/*=0xa9402c0*/ = 0xd5;
    puVar15[0x7c] = 0xdf;
    puVar15[0x16] = 0xd5;
    *DAT_0005a904/*=0xa940390*/ = 0xdf;
    *DAT_0005a908/*=0xa9402c4*/ = 0x158;
    puVar15[0x7e] = 0x161;
    puVar15[0x18] = 0x158;
    *DAT_0005a90c/*=0xa940394*/ = 0x161;
    *DAT_0005a910/*=0xa9402c8*/ = 0xe0;
    puVar15[0x80] = 0xee;
    puVar15[0x1a] = 0xe0;
    *DAT_0005a914/*=0xa940398*/ = 0xee;
    *DAT_0005a918/*=0xa9402cc*/ = 0x162;
    puVar15[0x82] = 0x170;
    puVar15[0x1c] = 0x162;
    *DAT_0005a91c/*=0xa94039c*/ = 0x170;
    *DAT_0005a920/*=0xa9402d0*/ = 0xef;
    puVar15[0x84] = 0xf9;
    puVar15[0x1e] = 0xef;
    *DAT_0005a924/*=0xa9403a0*/ = 0xf9;
    *DAT_0005a928/*=0xa9402d4*/ = 0x171;
    puVar15[0x86] = 0x17a;
    puVar15[0x20] = 0x171;
    *DAT_0005a92c/*=0xa9403a4*/ = 0x17a;
    *DAT_0005a930/*=0xa9402d8*/ = 0xfa;
    puVar15[0x88] = 0x108;
    puVar15[0x22] = 0xfa;
    *DAT_0005a934/*=0xa9403a8*/ = 0x108;
    *DAT_0005a938/*=0xa9402dc*/ = 0x17b;
    puVar15[0x8a] = 0x189;
    puVar15[0x24] = 0x17b;
    *DAT_0005a93c/*=0xa9403ac*/ = 0x189;
    puVar11 = DAT_0005a940/*=0xa9402e0*/;
    *DAT_0005a940/*=0xa9402e0*/ = 0x109;
    puVar11[0x67] = 0x109;
    puVar11[1] = 0x109;
    puVar11[0x68] = 0x109;
    puVar11[2] = 0x18a;
    puVar11[0x69] = 0x18a;
    puVar11[3] = 0x18a;
    puVar11[0x6a] = 0x18a;
    *DAT_0005a944/*=0xa982c26*/ = 0xb00;
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
    puVar11 = DAT_0005a948/*=0xa98303e*/;
    *DAT_0005a948/*=0xa98303e*/ = 0;
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
    *DAT_0005a94c/*=0xa9837fe*/ = 0;
    puVar11 = DAT_0005a950/*=0xa983846*/;
  }
  *puVar11 = 0x7b00;
  puVar11[4] = 0x400;
  iVar20 = DAT_0005a95c/*=0xf567dff0*/;
  puVar10 = DAT_0005a958/*=0xa982030*/;
  puVar11 = DAT_0005a954/*=0xa982010*/;
  if (iVar16 != 9) goto LAB_0005ab48;
  puVar17 = DAT_0005a954/*=0xa982010*/;
  do {
    puVar19 = puVar17 + 1;
    *puVar17 = *(undefined2 *)((int)auStack_48 + ((int)puVar17 + iVar20 & 0xfffffffeU));
    puVar18 = DAT_0005a960/*=0xa982018*/;
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
  iVar20 = DAT_0005a968/*=0xf567dfd0*/;
  puVar11 = DAT_0005a964/*=0xa982050*/;
  *puVar18 = uVar9;
  do {
    puVar18 = puVar19 + 1;
    *puVar19 = *(undefined2 *)((int)auStack_48 + ((int)puVar19 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_0005a96c/*=0xa982038*/;
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
  iVar20 = DAT_0005a978/*=0xf567dfb0*/;
  puVar10 = DAT_0005a974/*=0xa982070*/;
  *DAT_0005a970/*=0xa982046*/ = 0x2b00;
  do {
    puVar19 = puVar18 + 1;
    *puVar18 = *(undefined2 *)((int)auStack_48 + ((int)puVar18 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_0005a97c/*=0xa982058*/;
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
  iVar20 = DAT_0005a988/*=0xf567df90*/;
  puVar11 = DAT_0005a984/*=0xa982090*/;
  *DAT_0005a980/*=0xa982066*/ = 0x2b00;
  do {
    puVar18 = puVar19 + 1;
    *puVar19 = *(undefined2 *)((int)auStack_48 + ((int)puVar19 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_0005a98c/*=0xa982078*/;
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
  iVar20 = DAT_0005a998/*=0xf567df70*/;
  puVar10 = DAT_0005a994/*=0xa9820b0*/;
  *DAT_0005a990/*=0xa982086*/ = 0x2b00;
  do {
    puVar19 = puVar18 + 1;
    *puVar18 = *(undefined2 *)((int)auStack_48 + ((int)puVar18 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_0005ac74/*=0xa982098*/;
    puVar18 = puVar19;
  } while (puVar19 != puVar10);
  iVar20 = *DAT_0005a99c/*=0x83624*/;
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
  iVar20 = DAT_0005ac80/*=0xf567df50*/;
  puVar11 = DAT_0005ac7c/*=0xa9820d0*/;
  *DAT_0005ac78/*=0xa9820a6*/ = 0x2b00;
  do {
    puVar18 = puVar19 + 1;
    *puVar19 = *(undefined2 *)((int)auStack_48 + ((int)puVar19 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_0005ac84/*=0xa9820b8*/;
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
  iVar20 = DAT_0005ac8c/*=0xf567df30*/;
  *DAT_0005ac88/*=0xa9820c6*/ = 0x2b00;
  puVar10 = DAT_0005ac90/*=0xa9820f0*/;
  do {
    puVar19 = puVar18 + 1;
    *puVar18 = *(undefined2 *)((int)auStack_48 + ((int)puVar18 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_0005ac94/*=0xa9820d8*/;
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
  puVar11 = DAT_0005ac9c/*=0xa982120*/;
  iVar8 = *(int *)(param_1 + 0x6c);
  *DAT_0005ac98/*=0xa9820e6*/ = 0x2b00;
  puVar17 = DAT_0005aca0/*=0xa9820f2*/;
  *puVar10 = 0x48d8;
  iVar20 = DAT_0005aca4/*=0xf567df00*/;
  *puVar17 = 0;
  puVar17[1] = 0;
  puVar17[2] = 0;
  if (iVar8 < 0) {
    uVar9 = 0x4348;
  }
  else {
    uVar9 = 0x4308;
  }
  *DAT_0005aca8/*=0xa9820f8*/ = uVar9;
  puVar10 = DAT_0005acac/*=0xa9820fa*/;
  *DAT_0005acac/*=0xa9820fa*/ = 0;
  puVar10[1] = 0;
  puVar10[2] = 0;
  puVar10 = DAT_0005acb0/*=0xa982100*/;
  puVar17 = DAT_0005acb0/*=0xa982100*/;
  do {
    puVar19 = puVar17 + 1;
    *puVar17 = *(undefined2 *)((int)auStack_48 + ((int)puVar17 + iVar20 & 0xfffffffeU));
    puVar18 = DAT_0005acb4/*=0xa982108*/;
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
  iVar20 = DAT_0005acbc/*=0xf567dee0*/;
  *DAT_0005acb8/*=0xa982116*/ = 0x2b00;
  puVar10 = DAT_0005acc0/*=0xa982140*/;
  do {
    puVar18 = puVar19 + 1;
    *puVar19 = *(undefined2 *)((int)auStack_48 + ((int)puVar19 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_0005acc4/*=0xa982128*/;
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
  iVar20 = DAT_0005acd0/*=0xf567dec0*/;
  puVar11 = DAT_0005accc/*=0xa982160*/;
  *DAT_0005acc8/*=0xa982136*/ = 0x2b00;
  do {
    puVar19 = puVar18 + 1;
    *puVar18 = *(undefined2 *)((int)auStack_48 + ((int)puVar18 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_0005acd4/*=0xa982148*/;
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
  iVar20 = DAT_0005acdc/*=0xf567dea0*/;
  *DAT_0005acd8/*=0xa982156*/ = 0x2b00;
  puVar10 = DAT_0005ace0/*=0xa982170*/;
  do {
    puVar18 = puVar19 + 1;
    *puVar19 = *(undefined2 *)((int)auStack_48 + ((int)puVar19 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_0005ace4/*=0xa982168*/;
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
  puVar10 = DAT_0005acec/*=0xa920144*/;
  puVar11 = DAT_0005ace8/*=0xaa80002*/;
  *DAT_0005ace8/*=0xaa80002*/ = 0x5061;
  puVar11[1] = 0x7098;
  puVar11 = DAT_0005acf0/*=0xaa80006*/;
  *DAT_0005acf0/*=0xaa80006*/ = 0;
  puVar11[-3] = 0xbedc;
  puVar11[3] = 0xb0db;
  puVar11[4] = 0;
  puVar11[-0x2f8f7] = 0;
  puVar11 = DAT_0005acf4/*=0xaa20e1a*/;
  *DAT_0005acf4/*=0xaa20e1a*/ = 0x7ff;
  puVar11[1] = 0x668;
  puVar11[2] = 0x7910;
  puVar11[3] = 0x355e;
  puVar11[4] = 0xcbb5;
  puVar11 = DAT_0005acfc/*=0xaa20e28*/;
  if ((uVar13 & 4) == 0) {
    *DAT_0005acf8/*=0xaa20e26*/ = 0xffff;
    uVar9 = 0x710;
  }
  else {
    *DAT_0005acf8/*=0xaa20e26*/ = 0x710;
    uVar9 = 0xffff;
  }
  *puVar11 = uVar9;
  *DAT_0005ad00/*=0xaa20e2a*/ = 0x7800;
  puVar11 = DAT_0005ad04/*=0xaa21820*/;
  *DAT_0005ad04/*=0xaa21820*/ = 0xffff;
  puVar11[2] = 0xff10;
  puVar11[-0x4fe] = 0x2ee8;
  puVar11[1] = 0xffff;
  puVar11 = DAT_0005ad0c/*=0xaa21248*/;
  *DAT_0005ad08/*=0xaa20e2c*/ = 0xffdf;
  puVar17 = DAT_0005ad10/*=0xaa20e2e*/;
  *DAT_0005ad10/*=0xaa20e2e*/ = 0x6f10;
  puVar17[1] = 0x6f10;
  puVar17[2] = 0x2868;
  puVar17[3] = 0x2868;
  *DAT_0005ad14/*=0xaa20e36*/ = 0xfeef;
  puVar17 = DAT_0005ad18/*=0xaa21208*/;
  *DAT_0005ad18/*=0xaa21208*/ = 0xe400;
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
  puVar11 = DAT_0005ad1c/*=0xaa21214*/;
  *DAT_0005ad1c/*=0xaa21214*/ = 0;
  puVar11[2] = 0;
  if ((uVar21 & 0x1000) == 0) {
    *DAT_0005ad20/*=0xaa2121a*/ = 0;
  }
  else {
    *DAT_0005ad20/*=0xaa2121a*/ = 1;
  }
  *DAT_0005ad24/*=0xa9401e0*/ = 0x27f7;
  puVar11 = DAT_0005ad28/*=0xa9401e2*/;
  *DAT_0005ad28/*=0xa9401e2*/ = 0x2108;
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
  puVar11 = DAT_0005af48/*=0xa926174*/;
  *DAT_0005af48/*=0xa926174*/ = 1;
  puVar11[-0x18] = 0;
  puVar11 = DAT_0005af4c/*=0xa92616a*/;
  *DAT_0005af4c/*=0xa92616a*/ = 1;
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
  puVar11 = DAT_0005af50/*=0xa9e00ca*/;
  *DAT_0005af50/*=0xa9e00ca*/ = 0x1ff;
  if ((uVar21 & 0x1000) == 0) {
    uVar9 = 0x11;
  }
  else {
    uVar9 = 0x33;
  }
  puVar11[-0x4ffe7] = uVar9;
  puVar10 = DAT_0005af58/*=0xa940620*/;
  puVar11 = DAT_0005af54/*=0xa9401de*/;
  *DAT_0005af54/*=0xa9401de*/ = 0xffff;
  puVar11[0x70821] = 2;
  *puVar10 = 1;
  puVar10[1] = 1;
  *DAT_0005af5c/*=0xaa80100*/ = 2;
  puVar11 = DAT_0005af60/*=0xaaa0006*/;
  *DAT_0005af60/*=0xaaa0006*/ = 0;
  puVar11[-3] = 1;
  return;
}

//==== 0x4f47c  0x4f47c-0x4f4d1 inclusive
undefined4 FUN_0004f47c(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  ushort *puVar5;
  undefined2 *puVar6;
  ushort *puVar7;
  
  puVar5 = DAT_0004f4dc/*=0xaaa0062*/;
  puVar4 = DAT_0004f4d4/*=0xaaa0132*/;
  *DAT_0004f4d8/*=0xaaa0000*/ = 1;
  *puVar4 = 9;
  *puVar4 = 1;
  *puVar4 = 0;
  puVar6 = DAT_0004f4e0/*=0xaaa0066*/;
  *puVar5 = 1;
  *puVar6 = 1;
  puVar7 = DAT_0004f4e4/*=0xaaa0008*/;
  do {
    uVar1 = *DAT_0004f4e4/*=0xaaa0008*/;
  } while ((uVar1 & 1) != 0);
  uVar2 = *DAT_0004f4e8/*=0xaaa0064*/;
  uVar3 = DAT_0004f4e8/*=0xaaa0064*/[2];
  FUN_0004993c(DAT_0004f4ec/*"Training result is = %x\n"*/,CONCAT22(uVar3,uVar2));
  *puVar5 = uVar1 & 1;
  do {
  } while (*puVar7 == 0);
  *puVar5 = 1;
  *puVar4 = 1;
  return CONCAT22(uVar3,uVar2);
}

//==== 0x4f4f0  0x4f4f0-0x4f4fd inclusive
void FUN_0004f4f0(uint param_1,uint *param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  short *psVar12;
  int iVar13;
  int iVar14;
  ushort *puVar15;
  ushort uVar16;
  ushort *puVar17;
  uint uVar18;
  uint uVar19;
  undefined2 *puVar20;
  ushort *puVar21;
  undefined2 uVar22;
  undefined2 uVar23;
  undefined2 *puVar24;
  undefined2 *puVar25;
  uint uVar26;
  uint uVar27;
  ushort *puVar28;
  short *psVar30;
  short *psVar29;
  undefined2 *puVar31;
  uint uVar32;
  ushort uVar33;
  uint uVar34;
  
  if (param_2[1] != 8) {
    uVar32 = (*param_2 & 0x7fff) << 1;
    if ((int)(param_2[0x1e] << 0x1d) < 0) {
      uVar16 = FUN_00048038((*param_2 & 0x7fff) << 3,
                            (param_2[0x18] >> ((param_1 & 0x1f) << 3) & 0x1f) + 1);
      uVar32 = (uint)uVar16;
    }
    uVar22 = (undefined2)uVar32;
    if (uVar32 < 0x640) {
      uVar22 = 0x640;
    }
    *DAT_00059e00/*=0xaaa0000*/ = 0;
    thunk_FUN_00048d80(1);
    puVar25 = DAT_00059e04/*=0xa9b0000*/;
    *DAT_00059e04/*=0xa9b0000*/ = 0;
    puVar25[1] = 0;
    uVar34 = param_2[0x1e];
    uVar32 = uVar34 & 4;
    if (uVar32 == 0) {
      uVar23 = 0x30;
LAB_00059d56:
      *DAT_00059e08/*=0xa9b0004*/ = uVar23;
    }
    else {
      if (param_1 == 0) {
        uVar23 = 0xa0;
        goto LAB_00059d56;
      }
      if (param_1 == 1) {
        uVar23 = 0x91;
        goto LAB_00059d56;
      }
      if (param_1 == 2) {
        uVar23 = 0x82;
        goto LAB_00059d56;
      }
      if (param_1 == 3) {
        uVar23 = 0x83;
        goto LAB_00059d56;
      }
    }
    puVar25 = DAT_00059e10/*=0xa9b0008*/;
    *DAT_00059e0c/*=0xa9b0006*/ = uVar22;
    *puVar25 = 4;
    puVar25[1] = 4;
    puVar25[2] = 0;
    puVar25[3] = 0;
    uVar19 = param_2[0x1b];
    uVar26 = uVar19 & 0x1fffffff;
    if (uVar26 >> 0x10 == 0) {
      *DAT_00059e14/*=0xa9b0010*/ = 799;
      param_2[0x1b] = uVar19 | 0x31f0000;
    }
    else {
      *DAT_00059e14/*=0xa9b0010*/ = (short)(uVar26 >> 0x10);
    }
    uVar26 = param_2[0x1b];
    *DAT_00059e18/*=0xa9b0012*/ = 0xff;
    puVar25 = DAT_00059e1c/*=0xa9b0014*/;
    uVar22 = 0;
    *DAT_00059e1c/*=0xa9b0014*/ = 0;
    puVar25[1] = 2;
    puVar25[2] = 0;
    puVar25[3] = 0;
    if ((int)uVar26 < 0) {
      uVar22 = 0xf;
    }
    puVar25[4] = uVar22;
    puVar25 = DAT_00059e20/*=0xa9b001e*/;
    *DAT_00059e20/*=0xa9b001e*/ = 0;
    puVar25[1] = 0;
    puVar25[2] = 0;
    uVar19 = param_2[7] & 0x1000;
    if ((param_2[7] & 1) == 0) {
      if (uVar19 == 0) {
        uVar22 = 0x120;
      }
      else {
        uVar22 = 800;
      }
    }
    else if (uVar19 == 0) {
      uVar22 = 0x110;
    }
    else {
      uVar22 = 0x310;
    }
    *DAT_00059e24/*=0xa9b0024*/ = uVar22;
    puVar25 = DAT_0005a0d0/*=0xa9b003e*/;
    puVar20 = DAT_0005a0cc/*=0xa9b0026*/;
    do {
      puVar31 = puVar20 + 1;
      *puVar20 = 0;
      puVar24 = DAT_0005a0d4/*=0xa9b0040*/;
      puVar20 = puVar31;
    } while (puVar31 != puVar25);
    if ((uVar34 & 0x40) == 0) {
      *puVar31 = 0;
      uVar22 = 0;
    }
    else {
      *puVar31 = 0x1000;
      if (uVar19 == 0) {
        uVar22 = 1;
      }
      else {
        uVar22 = 3;
      }
    }
    *puVar24 = uVar22;
    puVar17 = DAT_0005a0dc/*=0xa9b005a*/;
    puVar21 = DAT_0005a0d8/*=0xa9b0042*/;
    do {
      puVar28 = puVar21 + 1;
      *puVar21 = 0;
      puVar21 = puVar28;
    } while (puVar28 != puVar17);
    uVar16 = (ushort)param_2[9] | (ushort)param_2[9] << 8;
    *puVar28 = uVar16;
    puVar17 = DAT_0005a0e0/*=0xa9b005c*/;
    *DAT_0005a0e0/*=0xa9b005c*/ = uVar16;
    uVar16 = (ushort)param_2[10] | (ushort)param_2[10] << 8;
    puVar17[1] = uVar16;
    puVar17[2] = uVar16;
    uVar16 = (ushort)param_2[0xb] | (ushort)param_2[0xb] << 8;
    puVar17[3] = uVar16;
    puVar17[4] = uVar16;
    puVar17[5] = 0x5454;
    puVar17[6] = 0x5454;
    uVar16 = (ushort)param_2[0xf] | (ushort)param_2[0xf] << 8;
    puVar17[7] = uVar16;
    puVar17[8] = uVar16;
    uVar16 = (ushort)param_2[0x10] | (ushort)param_2[0x10] << 8;
    puVar17[9] = uVar16;
    puVar17[10] = uVar16;
    uVar16 = (ushort)param_2[0x11] | (ushort)param_2[0x11] << 8;
    puVar17[0xb] = uVar16;
    puVar17[0xc] = uVar16;
    puVar15 = DAT_0005a1cc/*=0xa9b007c*/;
    puVar28 = DAT_0005a1c8/*=0xa9b007a*/;
    puVar21 = DAT_0005a1c4/*=0xa9b0078*/;
    puVar17 = DAT_0005a0e4/*=0xa9b0076*/;
    uVar34 = uVar26 & 0x20000000;
    if ((int)param_2[0x17] < 0) {
      if ((uVar34 == 0) && ((uVar32 == 0 || (param_1 == 0)))) {
        uVar19 = param_2[0x32];
        uVar2 = (ushort)uVar19;
        *DAT_0005a1d0/*=0xa9b0076*/ = uVar2;
        uVar16 = (ushort)(uVar19 >> 0x10);
        *puVar21 = uVar16;
        if ((int)uVar26 < 0) {
          *puVar28 = uVar2;
        }
        else {
          uVar16 = (ushort)(param_2[0x33] >> 0x10);
          *puVar28 = (ushort)param_2[0x33];
        }
      }
      else {
        uVar16 = (ushort)param_2[0x12] | (ushort)param_2[0x12] << 8;
        *DAT_0005a1d0/*=0xa9b0076*/ = uVar16;
        *puVar21 = uVar16;
        *puVar28 = uVar16;
      }
      *puVar15 = uVar16;
    }
    else if (uVar34 != 0) {
      uVar16 = (ushort)param_2[0x12] | (ushort)param_2[0x12] << 8;
      *DAT_0005a0e4/*=0xa9b0076*/ = uVar16;
      puVar17[1] = uVar16;
      puVar17[2] = uVar16;
      puVar17[3] = uVar16;
    }
    puVar21 = DAT_0005a0ec/*=0xa9b0096*/;
    puVar17 = DAT_0005a0e8/*=0xa9b007e*/;
    uVar16 = (ushort)param_2[0x13] | (ushort)param_2[0x13] << 8;
    puVar28 = DAT_0005a0ec/*=0xa9b0096*/ + 0x1a;
    *DAT_0005a0e8/*=0xa9b007e*/ = uVar16;
    puVar17[1] = uVar16;
    puVar17 = DAT_0005a0f0/*=0xa9b0082*/;
    uVar16 = (ushort)param_2[0x14] | 0x2800 | (ushort)param_2[0x14] << 8;
    *DAT_0005a0f0/*=0xa9b0082*/ = uVar16;
    puVar17[1] = uVar16;
    puVar17[2] = 0x1c1c;
    puVar17[3] = 0x1c1c;
    puVar17[4] = 0x1010;
    puVar17[5] = 0x1010;
    puVar17[6] = 0x202;
    puVar17[7] = 0x202;
    puVar17[8] = 0;
    puVar17[9] = 0;
    uVar16 = (ushort)param_2[0x15] | (ushort)param_2[0x15] << 8;
    *puVar21 = uVar16;
    puVar21[1] = uVar16;
    puVar25 = DAT_0005a0f4/*=0xa9b009a*/;
    *DAT_0005a0f4/*=0xa9b009a*/ = 0;
    puVar25[1] = 0;
    puVar25[2] = 0;
    puVar25[3] = 0;
    puVar25[4] = 0;
    puVar25[5] = 0;
    puVar25[6] = 0;
    puVar25[7] = 0;
    puVar21[10] = 0x404;
    puVar21[0xb] = 0x404;
    puVar17 = DAT_0005a0f8/*=0xa9b00ae*/;
    do {
      puVar21 = puVar17 + 1;
      *puVar17 = 0;
      puVar17 = puVar21;
    } while (puVar21 != puVar28);
    *puVar21 = 0x6060;
    *DAT_0005a0fc/*=0xa9b00cc*/ = 0x6060;
    if (uVar34 == 0) {
LAB_0005a0c6:
      *DAT_0005a100/*=0xa9b00ce*/ = 1;
    }
    else if (uVar32 == 0) {
      *DAT_0005a100/*=0xa9b00ce*/ = 0;
    }
    else {
      if (param_1 != 0) goto LAB_0005a0c6;
      *DAT_0005a100/*=0xa9b00ce*/ = 0;
    }
    puVar25 = DAT_0005a108/*=0xa9b00e8*/;
    puVar20 = DAT_0005a104/*=0xa9b00d0*/;
    do {
      puVar24 = puVar20 + 1;
      *puVar20 = 0;
      puVar20 = puVar24;
    } while (puVar24 != puVar25);
    *puVar24 = 0x2e;
    puVar25 = DAT_0005a10c/*=0xa9b00ea*/;
    *DAT_0005a10c/*=0xa9b00ea*/ = 0x50;
    puVar25[1] = 0;
    puVar25[2] = 0;
    puVar20 = DAT_0005a1c0/*=0xa9b00f0*/;
    if (uVar32 == 0) {
      *DAT_0005a1c0/*=0xa9b00f0*/ = 0;
      uVar22 = 0;
    }
    else {
      if (param_1 == 0) {
        puVar25[3] = 0x58;
        puVar25[4] = 0x287;
        goto LAB_00059fb8;
      }
      if (param_1 == 1) {
        *DAT_0005a1c0/*=0xa9b00f0*/ = 0x458;
        uVar22 = 0x687;
      }
      else if (param_1 == 2) {
        *DAT_0005a1c0/*=0xa9b00f0*/ = 0x858;
        uVar22 = 0xa87;
      }
      else {
        if (param_1 != 3) goto LAB_00059fb8;
        *DAT_0005a1c0/*=0xa9b00f0*/ = 0xc58;
        uVar22 = 0xe87;
      }
    }
    puVar20[1] = uVar22;
LAB_00059fb8:
    psVar12 = DAT_0005a114/*=0xa9b0102*/;
    puVar25 = DAT_0005a110/*=0xa9b00f4*/;
    *DAT_0005a110/*=0xa9b00f4*/ = 0;
    puVar25[1] = 0;
    puVar25[2] = 0;
    puVar25[3] = 0;
    puVar25[4] = 0;
    puVar25[5] = 0;
    *DAT_0005a118/*=0xa9b0100*/ = 0xf01;
    bVar1 = *DAT_0005a11c/*=0x83628*/;
    *psVar12 = ((ushort)bVar1 * 4 + -1) * 0x100;
    psVar12 = DAT_0005a120/*=0xa9b0104*/;
    *DAT_0005a120/*=0xa9b0104*/ = (ushort)bVar1 * 4 + -5;
    psVar29 = DAT_0005a124/*=0xa9b0106*/;
    do {
      psVar30 = psVar29 + 1;
      *psVar29 = 0;
      psVar29 = psVar30;
    } while (psVar30 != psVar12 + 0x182);
    *psVar30 = 0x500;
    puVar25 = DAT_0005a12c/*=0xa9b0424*/;
    puVar20 = DAT_0005a128/*=0xa9b040a*/;
    do {
      puVar24 = puVar20 + 1;
      *puVar20 = 0;
      puVar20 = puVar24;
    } while (puVar24 != puVar25);
    *puVar24 = 0x715d;
    puVar25 = DAT_0005a130/*=0xa9b0426*/;
    *DAT_0005a130/*=0xa9b0426*/ = 0xce;
    puVar20 = DAT_0005a134/*=0xa9b043a*/;
    puVar25 = puVar25 + 1;
    do {
      puVar31 = puVar25 + 1;
      *puVar25 = 0;
      puVar24 = DAT_0005a138/*=0xa9b045a*/;
      puVar25 = puVar31;
    } while (puVar31 != puVar20);
    *puVar31 = 4;
    puVar25 = DAT_0005a13c/*=0xa9b043c*/;
    do {
      puVar20 = puVar25 + 1;
      *puVar25 = 0;
      iVar13 = DAT_0005a140/*=0x6eab8*/;
      puVar25 = puVar20;
    } while (puVar20 != puVar24);
    *puVar20 = 4;
    puVar20 = DAT_0005a14c/*=0xa9b09a0*/;
    iVar14 = DAT_0005a148/*=0xf564fb96*/;
    puVar25 = DAT_0005a144/*=0xa9b045c*/;
    *DAT_0005a144/*=0xa9b045c*/ = 0;
    puVar25[1] = 0;
    puVar25[2] = 0;
    puVar25[3] = 0;
    puVar25[4] = 0;
    puVar25[5] = 0;
    puVar25[6] = 0;
    puVar25 = DAT_0005a150/*=0xa9b046a*/;
    do {
      puVar31 = puVar25 + 1;
      *puVar25 = *(undefined2 *)(iVar13 + ((int)puVar25 + iVar14 >> 1) * 2);
      puVar24 = DAT_0005a154/*=0xa9c0000*/;
      puVar25 = puVar31;
    } while (puVar31 != puVar20);
    do {
      puVar25 = puVar31 + 1;
      *puVar31 = 0;
      puVar31 = puVar25;
    } while (puVar25 != puVar24);
    *DAT_0005a158/*=0xaaa0000*/ = 1;
    return;
  }
  uVar32 = (*param_2 & 0x7fff) << 1;
  if ((int)(param_2[0x1e] << 0x1d) < 0) {
    uVar16 = FUN_00048038((*param_2 & 0x7fff) << 3,
                          (param_2[0x18] >> ((param_1 & 0x1f) << 3) & 0x1f) + 1);
    uVar32 = (uint)uVar16;
  }
  uVar22 = (undefined2)uVar32;
  if (uVar32 < 0x640) {
    uVar22 = 0x640;
  }
  *DAT_00058e3c/*=0xaaa0000*/ = 0;
  thunk_FUN_00048d80(1);
  puVar25 = DAT_00058e40/*=0xa9b0000*/;
  uVar32 = param_2[0x1e];
  *DAT_00058e40/*=0xa9b0000*/ = 0;
  puVar25[1] = 0;
  if ((uVar32 & 4) == 0) {
    uVar23 = 0x30;
LAB_00058cdc:
    *DAT_00058e7c/*=0xa9b0004*/ = uVar23;
  }
  else {
    if (param_1 != 0) {
      if (param_1 == 1) {
        uVar23 = 0x91;
      }
      else if (param_1 == 2) {
        uVar23 = 0x82;
      }
      else {
        if (param_1 != 3) goto LAB_00058c06;
        uVar23 = 0x83;
      }
      goto LAB_00058cdc;
    }
    puVar25[2] = 0xa0;
  }
LAB_00058c06:
  *DAT_00058e44/*=0xa9b0006*/ = uVar22;
  if (*DAT_00058e48/*=0x83620*/ == '\0') {
    uVar22 = 4;
  }
  else {
    uVar22 = 2;
  }
  *DAT_00058e4c/*=0xa9b0008*/ = uVar22;
  puVar25 = DAT_00058e54/*=0xa9b0010*/;
  *DAT_00058e50/*=0xa9b000a*/ = 4;
  puVar20 = DAT_00058e58/*=0xa9b000c*/;
  *DAT_00058e58/*=0xa9b000c*/ = 0;
  puVar20[1] = 0;
  uVar26 = param_2[0x1b];
  uVar34 = uVar26 & 0x1fffffff;
  if (uVar34 >> 0x10 == 0) {
    *puVar25 = 799;
    param_2[0x1b] = uVar26 | 0x21f0000;
  }
  else {
    *puVar25 = (short)(uVar34 >> 0x10);
  }
  *DAT_00058e5c/*=0xa9b0012*/ = 0xff;
  puVar25 = DAT_00058e60/*=0xa9b0014*/;
  *DAT_00058e60/*=0xa9b0014*/ = 0;
  puVar25[1] = 2;
  puVar25[2] = 0;
  puVar25[3] = 0;
  puVar25[4] = 0;
  puVar25[5] = 0;
  puVar25[6] = 0;
  puVar25[7] = 0;
  uVar34 = param_2[7] & 0x1000;
  if ((param_2[7] & 1) == 0) {
    if (uVar34 == 0) {
      uVar22 = 0x120;
    }
    else {
      uVar22 = 800;
    }
  }
  else if (uVar34 == 0) {
    uVar22 = 0x110;
  }
  else {
    uVar22 = 0x310;
  }
  *DAT_00058e64/*=0xa9b0024*/ = uVar22;
  puVar17 = DAT_00058e6c/*=0xa9b0038*/;
  puVar25 = DAT_00058e68/*=0xa9b0026*/;
  uVar18 = param_2[0x1b];
  *DAT_00058e68/*=0xa9b0026*/ = 0;
  puVar25[1] = 0;
  uVar18 = uVar18 & 0x20000000;
  puVar25[2] = 0;
  puVar25[3] = 0;
  puVar25[4] = 0;
  puVar25[5] = 0;
  uVar26 = param_2[10];
  uVar19 = param_2[9];
  uVar3 = (ushort)uVar19 | (ushort)uVar26 << 8;
  *DAT_00058e70/*=0xa9b0032*/ = uVar3;
  uVar7 = param_2[0xc];
  uVar8 = param_2[0xb];
  uVar4 = (ushort)uVar8 | (ushort)uVar7 << 8;
  *DAT_00058e74/*=0xa9b0034*/ = uVar4;
  uVar9 = param_2[0x10];
  uVar10 = param_2[0xf];
  uVar16 = (ushort)param_2[0x11];
  uVar2 = (ushort)uVar10 | (ushort)uVar9 << 8;
  *DAT_00058e78/*=0xa9b0036*/ = uVar2;
  puVar28 = DAT_00058e94/*=0xa9b003c*/;
  puVar21 = DAT_00058e90/*=0xa9b003a*/;
  if (uVar18 == 0) {
    uVar27 = param_2[0x32];
  }
  else {
    uVar27 = param_2[0x12];
  }
  *puVar17 = uVar16 | (ushort)(uVar27 << 8);
  uVar27 = param_2[0x13];
  uVar11 = param_2[0x14];
  uVar5 = (ushort)uVar27 | (ushort)uVar11 << 8;
  *puVar21 = uVar5;
  uVar6 = (ushort)param_2[0x15];
  *puVar28 = uVar6;
  puVar28[1] = uVar3;
  *DAT_00058e98/*=0xa9b0040*/ = uVar4;
  puVar17 = DAT_00058e9c/*=0xa9b0042*/;
  *DAT_00058e9c/*=0xa9b0042*/ = uVar2;
  if (uVar18 == 0) {
    uVar2 = (ushort)param_2[0x32] & 0xff00;
  }
  else {
    uVar2 = (ushort)(param_2[0x12] << 8);
  }
  puVar17[1] = uVar2 | uVar16;
  puVar17 = DAT_00058e80/*=0xa9b0046*/;
  *DAT_00058e80/*=0xa9b0046*/ = uVar5;
  puVar25 = DAT_00058e84/*=0xa9b004a*/;
  puVar17[1] = uVar6;
  *puVar25 = 0;
  puVar25[1] = 0;
  puVar25[2] = 0;
  puVar25[3] = 0;
  puVar25[4] = 0;
  puVar25[5] = 0;
  puVar20 = DAT_00058e88/*=0xa9b0058*/;
  if ((uVar32 & 0x40) == 0) {
    puVar25[6] = 0;
    *puVar20 = 0;
  }
  else {
    puVar25[6] = 0x1000;
    if (uVar34 == 0) {
      uVar22 = 1;
    }
    else {
      uVar22 = 3;
    }
    *puVar20 = uVar22;
  }
  puVar21 = DAT_00058ea4/*=0xa9b0068*/;
  puVar17 = DAT_00058ea0/*=0xa9b0066*/;
  puVar25 = DAT_00058e8c/*=0xa9b005a*/;
  *DAT_00058e8c/*=0xa9b005a*/ = 0;
  puVar25[1] = 0;
  puVar25[2] = 0;
  puVar25[3] = 0;
  puVar25[4] = 0;
  puVar28 = DAT_00058ea8/*=0xa9b006c*/;
  uVar2 = (ushort)uVar19 << 8;
  puVar25[5] = uVar2;
  uVar3 = (ushort)uVar26 | (ushort)uVar8 << 8;
  *puVar17 = uVar3;
  uVar4 = (ushort)uVar7 | (ushort)uVar10 << 8;
  uVar16 = (ushort)uVar9 | uVar16 << 8;
  *puVar21 = uVar4;
  uVar5 = (ushort)uVar27 << 8;
  puVar21[1] = uVar16;
  if (uVar18 == 0) {
    uVar33 = (ushort)*(byte *)((int)param_2 + 0xca);
  }
  else {
    uVar33 = (ushort)param_2[0x12];
  }
  *puVar28 = uVar5 | uVar33;
  puVar17 = DAT_000590c0/*=0xa9b006e*/;
  uVar6 = (ushort)uVar11 | uVar6 << 8;
  *DAT_000590c0/*=0xa9b006e*/ = uVar6;
  puVar17[1] = uVar2;
  puVar17 = DAT_00059068/*=0xa9b0072*/;
  *DAT_00059068/*=0xa9b0072*/ = uVar3;
  puVar17[1] = uVar4;
  puVar17[2] = uVar16;
  puVar21 = DAT_0005906c/*=0xa9b0092*/;
  if (uVar18 == 0) {
    uVar16 = (ushort)*(byte *)((int)param_2 + 0xcb);
  }
  else {
    uVar16 = (ushort)param_2[0x12];
  }
  puVar17[3] = uVar5 | uVar16;
  puVar17 = DAT_00059070/*=0xa9b007a*/;
  *DAT_00059070/*=0xa9b007a*/ = uVar6;
  puVar17 = puVar17 + 1;
  do {
    puVar28 = puVar17 + 1;
    *puVar17 = 0;
    puVar17 = puVar28;
  } while (puVar28 != puVar21);
  uVar32 = param_2[0x1e];
  if (uVar18 == 0) {
LAB_0005901a:
    *puVar28 = 0x100;
  }
  else if ((uVar32 & 4) == 0) {
    *puVar28 = 0;
  }
  else {
    if (param_1 != 0) goto LAB_0005901a;
    *puVar28 = 0;
  }
  bVar1 = *DAT_00059074/*=0x83628*/;
  *DAT_00059078/*=0xa9b0094*/ = (bVar1 - 2) * 0x100;
  psVar12 = DAT_0005907c/*=0xa9b0096*/;
  *DAT_0005907c/*=0xa9b0096*/ = bVar1 - 2;
  psVar12[1] = 0;
  psVar12[2] = 0;
  psVar12[3] = 0x1e;
  psVar12[4] = 0x28;
  psVar12[5] = 0;
  psVar12[6] = 0;
  puVar25 = DAT_00059080/*=0xa9b00a4*/;
  if ((uVar32 & 4) == 0) {
    *DAT_00059080/*=0xa9b00a4*/ = 0;
    uVar22 = 0;
  }
  else if (param_1 == 0) {
    *DAT_00059080/*=0xa9b00a4*/ = 0x38;
    uVar22 = 0x24a;
  }
  else if (param_1 == 1) {
    *DAT_00059080/*=0xa9b00a4*/ = 0x438;
    uVar22 = 0x64a;
  }
  else if (param_1 == 2) {
    *DAT_00059080/*=0xa9b00a4*/ = 0x838;
    uVar22 = 0xa4a;
  }
  else {
    if (param_1 != 3) goto LAB_00058f52;
    *DAT_00059080/*=0xa9b00a4*/ = 0xc38;
    uVar22 = 0xe4a;
  }
  puVar25[1] = uVar22;
LAB_00058f52:
  puVar25 = DAT_00059084/*=0xa9b00a8*/;
  uVar22 = 0;
  *DAT_00059084/*=0xa9b00a8*/ = 0;
  puVar25[1] = 0;
  puVar25[2] = 0;
  puVar25[3] = 0;
  puVar25[4] = 0;
  puVar25[5] = 0;
  puVar25[6] = 1;
  puVar20 = DAT_00059088/*=0xa9b0408*/;
  puVar25 = puVar25 + 7;
  do {
    puVar24 = puVar25 + 1;
    *puVar25 = 0;
    puVar25 = puVar24;
  } while (puVar24 != puVar20);
  uVar16 = *(ushort *)((int)param_2 + 0x66) & 0xf;
  if (((*(ushort *)((int)param_2 + 0x66) & 0xf) < 2) || (uVar16 == 4)) {
    uVar22 = 0x300;
  }
  else if (uVar16 == 3) {
    uVar22 = 0xc00;
  }
  *DAT_0005908c/*=0xa9b00d6*/ = uVar22;
  *puVar20 = 0x200;
  puVar25 = DAT_00059094/*=0xa9b0424*/;
  puVar20 = DAT_00059090/*=0xa9b040a*/;
  do {
    puVar31 = puVar20 + 1;
    *puVar20 = 0;
    puVar24 = DAT_00059098/*=0xa9b045a*/;
    puVar20 = puVar31;
  } while (puVar31 != puVar25);
  *puVar31 = 0x715d;
  *DAT_0005909c/*=0xa9b0426*/ = 0xce;
  puVar25 = DAT_000590a0/*=0xa9b0428*/;
  do {
    puVar20 = puVar25 + 1;
    *puVar25 = 0;
    iVar13 = DAT_000590a4/*=0x606c0*/;
    puVar25 = puVar20;
  } while (puVar20 != puVar24);
  *puVar20 = 4;
  iVar14 = DAT_000590ac/*=0xf564fb94*/;
  puVar25 = DAT_000590a8/*=0xa9b045c*/;
  *DAT_000590a8/*=0xa9b045c*/ = 0x400;
  puVar25[1] = 0;
  puVar20 = DAT_000590b0/*=0xa9b0548*/;
  puVar25[2] = 0;
  puVar25[3] = 0;
  puVar25[4] = 0;
  puVar25[5] = 0;
  puVar25[6] = 0;
  puVar25[7] = 0;
  puVar25 = DAT_000590b4/*=0xa9b046c*/;
  do {
    puVar31 = puVar25 + 1;
    *puVar25 = *(undefined2 *)(iVar13 + ((int)puVar25 + iVar14 >> 1) * 2);
    puVar24 = DAT_000590b8/*=0xa9c0000*/;
    puVar25 = puVar31;
  } while (puVar31 != puVar20);
  do {
    puVar25 = puVar31 + 1;
    *puVar31 = 0;
    puVar31 = puVar25;
  } while (puVar25 != puVar24);
  *DAT_000590bc/*=0xaaa0000*/ = 1;
  return;
}

//==== 0x4f500  0x4f500-0x4f569 inclusive
void FUN_0004f500(uint param_1,int param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  bool bVar4;
  
  puVar1 = DAT_0004f570/*=0xa110510*/;
  puVar2 = DAT_0004f56c/*=0xa110c80*/;
  *DAT_0004f56c/*=0xa110c80*/ = 0;
  *puVar1 = *puVar1 & 0xffffe0ff | param_1 << 8;
  *puVar2 = 1;
  puVar2 = puVar2 + 0x100000;
  *puVar2 = 0;
  puVar1 = DAT_0004f578/*=0x2002c00*/;
  *DAT_0004f574/*=0xa510510*/ = param_1 << 8 | *DAT_0004f574/*=0xa510510*/ & 0xffffe0ff;
  *puVar2 = 1;
  *puVar1 = *puVar1 & 0xf8ffffff;
  uVar3 = *(int *)(param_2 + 0x78) << 0x1d;
  bVar4 = (int)uVar3 < 0;
  if (bVar4) {
    uVar3 = param_1 << 3;
    param_1 = *(uint *)(param_2 + 0x60);
  }
  if (bVar4) {
    uVar3 = *puVar1 & 0xffffffe0 | param_1 >> (uVar3 & 0xff) & 0x1f;
  }
  else {
    uVar3 = *puVar1 & 0xffffffe0 | 3;
  }
  *puVar1 = uVar3;
  *puVar1 = uVar3 | 0x8000000;
  FUN_00048d80(1000);
  return;
}

//==== 0x4f57c  0x4f57c-0x4f589 inclusive
void FUN_0004f57c(int param_1)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  
  puVar4 = DAT_0005a208/*=0xa9afaa0*/;
  iVar3 = DAT_0005a204/*=0x6efee*/;
  puVar5 = DAT_000590f8/*=0xa9ac9d8*/;
  iVar1 = DAT_000590f4/*=0x6079c*/;
  if (*(int *)(param_1 + 4) == 8) {
    puVar4 = DAT_000590f0/*=0xa9a0000*/;
    do {
      puVar6 = puVar4 + 1;
      *puVar4 = *(undefined2 *)(iVar1 + ((uint)(puVar4 + -0x54d0000) & 0xfffffffe));
      puVar2 = DAT_000590fc/*=0xa9b0000*/;
      puVar4 = puVar6;
    } while (puVar6 != puVar5);
    do {
      puVar5 = puVar6 + 1;
      *puVar6 = 0;
      puVar6 = puVar5;
    } while (puVar5 != puVar2);
    return;
  }
  puVar5 = DAT_0005a200/*=0xa9a0000*/;
  do {
    puVar6 = puVar5 + 1;
    *puVar5 = *(undefined2 *)(iVar3 + ((uint)(puVar5 + -0x54d0000) & 0xfffffffe));
    puVar2 = DAT_0005a20c/*=0xa9b0000*/;
    puVar5 = puVar6;
  } while (puVar6 != puVar4);
  do {
    puVar5 = puVar6 + 1;
    *puVar6 = 0;
    puVar6 = puVar5;
  } while (puVar5 != puVar2);
  return;
}

//==== 0x55654  0x55654-0x55921 inclusive
void FUN_00055654(uint *param_1)

{
  byte bVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  uint uVar8;
  undefined2 uVar9;
  undefined2 uVar10;
  ushort uVar11;
  ushort uVar12;
  uint uVar13;
  uint uVar14;
  
  uVar8 = *param_1;
  uVar13 = param_1[1];
  if (uVar8 < 0x1a9) {
LAB_000557aa:
    uVar9 = 0x123e;
    uVar10 = 0x502;
  }
  else if (uVar8 < 0x20a) {
LAB_000557b4:
    uVar9 = 0x123e;
    uVar10 = 0x402;
  }
  else if (uVar8 < 0x272) {
LAB_000557be:
    uVar9 = 0x123e;
    uVar10 = 0x302;
  }
  else {
    if (uVar8 < 0x351) goto LAB_000557aa;
    if (uVar8 < 0x413) goto LAB_000557b4;
    if (uVar8 < 0x4e3) goto LAB_000557be;
    if (uVar8 < 0x6a1) goto LAB_000557aa;
    if (uVar8 < 0x825) goto LAB_000557b4;
    if (uVar8 < 0x9c5) goto LAB_000557be;
    uVar10 = 0x601;
    uVar9 = 0x1c3e;
    if (uVar8 < 0xa8d) {
      uVar10 = 0x701;
    }
  }
  uVar14 = param_1[0x1e];
  uVar8 = param_1[7];
  *DAT_00055924/*=0xa940094*/ = uVar10;
  puVar6 = DAT_00055988/*=0xa96015a*/;
  puVar5 = DAT_00055984/*=0xa96015c*/;
  puVar2 = DAT_00055928/*=0xa940096*/;
  uVar8 = uVar8 & 0x1000;
  *DAT_00055928/*=0xa940096*/ = uVar9;
  puVar2[0x3d] = 0x101;
  puVar2[0x15] = 2;
  if (uVar13 == 9) {
    puVar2[0x5a] = 1;
  }
  puVar7 = DAT_0005598c/*=0xa960158*/;
  *DAT_0005592c/*=0xaaa006c*/ = 0;
  puVar2 = DAT_00055930/*=0xa94017a*/;
  *DAT_00055930/*=0xa94017a*/ = 0xff;
  puVar2[0x243] = 0x808;
  puVar2[0x246] = 9;
  if (uVar13 == 9) {
    *DAT_00055934/*=0xa940604*/ = 0x26;
    puVar2[0x26b] = 0;
  }
  else {
    *DAT_00055934/*=0xa940604*/ = 0x129;
    puVar2[0x26b] = 1;
  }
  puVar4 = DAT_00055940/*=0xa96215a*/;
  puVar3 = DAT_0005593c/*=0xa96215c*/;
  puVar2 = DAT_00055938/*=0xa940602*/;
  *DAT_00055938/*=0xa940602*/ = 3;
  puVar2[10] = 0;
  puVar2 = DAT_00055944/*=0xa962158*/;
  if ((uVar14 & 0x40) == 0) {
    if (uVar8 == 0) {
      uVar9 = 0x280;
    }
    else if (uVar13 == 9) {
      uVar9 = 0x80;
    }
    else {
      uVar9 = 0;
    }
    *puVar5 = uVar9;
    *puVar6 = uVar9;
    *puVar7 = uVar9;
    uVar9 = 0x7ff;
  }
  else {
    if (uVar8 == 0) {
      uVar9 = 0x280;
    }
    else if (uVar13 == 9) {
      uVar9 = 0x80;
    }
    else {
      uVar9 = 0;
    }
    *puVar5 = uVar9;
    *puVar6 = uVar9;
    *puVar7 = uVar9;
  }
  *puVar3 = uVar9;
  *puVar4 = uVar9;
  uVar11 = *(ushort *)((int)param_1 + 0x66);
  *puVar2 = uVar9;
  puVar5 = DAT_00055950/*=0xa922146*/;
  puVar2 = DAT_0005594c/*=0xa920146*/;
  uVar12 = uVar11 & 0xf;
  *DAT_00055948/*=0xaa8010c*/ = 0;
  puVar7 = DAT_00055958/*=0xa926146*/;
  puVar6 = DAT_00055954/*=0xa924146*/;
  if (uVar8 == 0) {
    if (uVar13 == 9) {
      uVar10 = 0x91d;
      *puVar2 = 0x91d;
      uVar9 = 0x911;
      goto LAB_000557a2;
    }
    if (((uVar11 & 0xf) < 2) || (uVar12 == 4)) {
      uVar10 = 0x50d;
      *puVar2 = 0x50d;
      uVar9 = 0x501;
      goto LAB_00055802;
    }
    uVar10 = 0x501;
    *puVar2 = 0x501;
    uVar9 = 0x50d;
LAB_000558cc:
    *puVar5 = uVar9;
    if (uVar12 == 3) goto LAB_00055804;
  }
  else {
    if (uVar13 != 9) {
      if ((1 < (uVar11 & 0xf)) && (uVar12 != 4)) {
        uVar10 = 0x703;
        *puVar2 = 0x703;
        uVar9 = 0x70f;
        goto LAB_000558cc;
      }
      uVar10 = 0x70f;
      *puVar2 = 0x70f;
      uVar9 = 0x703;
LAB_00055802:
      *puVar5 = uVar9;
LAB_00055804:
      *puVar6 = uVar9;
      *puVar7 = uVar10;
      goto LAB_00055808;
    }
    uVar10 = 0xb3f;
    *puVar2 = 0xb3f;
    uVar9 = 0xb33;
LAB_000557a2:
    *puVar5 = uVar9;
  }
  *puVar6 = uVar10;
  *puVar7 = uVar9;
LAB_00055808:
  uVar8 = uVar14 & 4;
  if (uVar8 != 0) {
    *DAT_0005595c/*=0xaa80242*/ = 2;
  }
  puVar2 = DAT_00055960/*=0xaa801e2*/;
  *DAT_00055960/*=0xaa801e2*/ = 0x6000;
  puVar2[1] = 0xa9;
  puVar2[2] = 0x8000;
  bVar1 = *DAT_00055964/*=0x83620*/;
  uVar11 = (ushort)bVar1;
  if (bVar1 == 0) {
    if (uVar8 == 0) {
      uVar9 = 5;
    }
    else {
      uVar9 = 0x5555;
    }
  }
  else {
    uVar9 = 0;
  }
  *DAT_00055968/*=0xaa801e8*/ = uVar9;
  puVar2 = DAT_0005596c/*=0xaa801ea*/;
  *DAT_0005596c/*=0xaa801ea*/ = 0x4000;
  if (bVar1 == 0) {
    if (uVar8 == 0) {
      uVar9 = 2;
    }
    else {
      uVar9 = 0x2222;
    }
  }
  else {
    uVar9 = 0;
  }
  puVar2[1] = uVar9;
  puVar2 = DAT_00055970/*=0xaa801ee*/;
  *DAT_00055970/*=0xaa801ee*/ = 0xf000;
  puVar2[2] = 0x6000;
  puVar2[3] = 0xa9;
  puVar2[4] = 0x8000;
  if (bVar1 == 0) {
    puVar2[5] = 0;
  }
  else {
    puVar2[5] = 5;
  }
  puVar2 = DAT_00055974/*=0xaa801fa*/;
  *DAT_00055974/*=0xaa801fa*/ = 0x4000;
  if (bVar1 != 0) {
    uVar11 = 2;
  }
  puVar2[1] = uVar11;
  puVar2 = DAT_00055978/*=0xaa801fe*/;
  *DAT_00055978/*=0xaa801fe*/ = 0xf000;
  puVar2[-0x2f800] = 0xf;
  puVar2 = DAT_0005597c/*=0xa920126*/;
  if (uVar13 == 9) {
    uVar9 = 0;
  }
  else {
    uVar9 = 0x400;
  }
  *DAT_0005597c/*=0xa920126*/ = uVar9;
  puVar2[0x1000] = uVar9;
  puVar2[0x2000] = uVar9;
  puVar2[0x3000] = uVar9;
  if ((uVar14 & 0x40) == 0) {
    uVar9 = 1;
  }
  else {
    uVar9 = 3;
  }
  *DAT_00055980/*=0xa9400a2*/ = uVar9;
  return;
}

//==== 0x55990  0x55990-0x55a83 inclusive
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
  puVar3 = DAT_0005615c/*=0xaaa0000*/;
  puVar1 = DAT_00055a84/*=0xaaa0000*/;
  if ((param_1[0x1e] & 4U) == 0) {
    FUN_0004f58c(0,param_1);
    FUN_0004f500(0,param_1);
    FUN_0004f4f0(0,param_1);
    *puVar3 = 0;
    FUN_0004bbb8(param_1);
    FUN_0004b97c(param_1);
    *puVar3 = 1;
    iVar4 = FUN_0004f47c(0);
    FUN_0004993c(DAT_00056160/*"DRAM Pstate %d training, frequency is %d Mhz\n"*/,0,*param_1);
    if (iVar4 != 7) {
      FUN_0004993c(DAT_00056164/*"DRAM Pstate %d training fail, fail result is 0x%x!\n"*/,0,iVar4);
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
      FUN_0004993c(DAT_00055a88/*"DRAM Pstate %d training, frequency is %d Mhz\n"*/,uVar15,uVar5);
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
    FUN_0004993c(DAT_00055a88/*"DRAM Pstate %d training, frequency is %d Mhz\n"*/,0,uVar5);
    if (iVar4 != 7) {
      uVar15 = 0;
LAB_00055a0e:
      FUN_0004993c(DAT_00055a8c/*"DRAM Pstate %d training fail, fail result is 0x%x!\n"*/,uVar15,iVar4);
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
      *DAT_00055e28/*=0xaaa0000*/ = 0;
      iVar2 = DAT_00055e2c/*=0xaa41ad0*/;
      iVar25 = param_1[0x21];
      iVar24 = param_1[0x2a];
      *(ushort *)(iVar4 + DAT_00055e2c/*=0xaa41ad0*/) = (ushort)iVar23 & 0xff;
      *(ushort *)(iVar4 + iVar2 + 2) = (ushort)iVar22 & 0xff;
      *(undefined2 *)(iVar4 + iVar2 + 4) = 0x8027;
      iVar2 = DAT_00055e30/*=0xaa41ad6*/;
      *(undefined2 *)(iVar4 + DAT_00055e30/*=0xaa41ad6*/) = 0x18;
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
      *(ushort *)(iVar4 + DAT_00055e34/*=0xaa41b10*/) = (ushort)local_2c;
      iVar2 = DAT_00055e38/*=0xaa41b12*/;
      iVar17 = param_1[0x31];
      *(ushort *)(iVar4 + DAT_00055e38/*=0xaa41b12*/) = (ushort)iVar17 & 0xff;
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
      *(ushort *)(iVar4 + DAT_00056168/*=0xaa41baa*/) = (ushort)(byte)((uint)iVar22 >> 0x18);
      iVar22 = DAT_0005616c/*=0xaa41bac*/;
      *(undefined2 *)(iVar4 + DAT_0005616c/*=0xaa41bac*/) = 0x9827;
      *(undefined2 *)(iVar4 + iVar22 + 2) = 0x18;
      *(ushort *)(iVar4 + iVar22 + 4) = (ushort)(byte)((uint)iVar25 >> 0x18);
      *(ushort *)(iVar4 + DAT_00056170/*=0xaa41bb2*/) = (ushort)(byte)((uint)iVar24 >> 0x18);
      iVar22 = DAT_00056174/*=0xaa41bb4*/;
      *(undefined2 *)(iVar4 + DAT_00056174/*=0xaa41bb4*/) = 0x98a7;
      *(undefined2 *)(iVar4 + iVar22 + 2) = 0x18;
      iVar22 = DAT_00056178/*=0xaa41bb8*/;
      *(ushort *)(iVar4 + DAT_00056178/*=0xaa41bb8*/) = (ushort)(byte)((uint)iVar6 >> 0x18);
      *(ushort *)(iVar4 + iVar22 + 2) = (ushort)(byte)((uint)iVar7 >> 0x18);
      iVar22 = DAT_0005617c/*=0xaa41bbc*/;
      *(undefined2 *)(iVar4 + DAT_0005617c/*=0xaa41bbc*/) = 0x9927;
      *(undefined2 *)(iVar4 + iVar22 + 2) = 0x18;
      iVar22 = DAT_00056180/*=0xaa41bc0*/;
      *(ushort *)(iVar4 + DAT_00056180/*=0xaa41bc0*/) = (ushort)(byte)((uint)iVar8 >> 0x18);
      *(ushort *)(iVar4 + iVar22 + 2) = (ushort)(byte)((uint)iVar9 >> 0x18);
      iVar22 = DAT_00056184/*=0xaa41bc4*/;
      *(undefined2 *)(iVar4 + DAT_00056184/*=0xaa41bc4*/) = 0x99a7;
      *(undefined2 *)(iVar4 + iVar22 + 2) = 0x18;
      iVar22 = DAT_00056188/*=0xaa41bc8*/;
      *(ushort *)(iVar4 + DAT_00056188/*=0xaa41bc8*/) = (ushort)(byte)((uint)iVar10 >> 0x18);
      *(ushort *)(iVar4 + iVar22 + 2) = (ushort)(byte)((uint)iVar11 >> 0x18);
      iVar22 = DAT_0005618c/*=0xaa41bcc*/;
      *(undefined2 *)(iVar4 + DAT_0005618c/*=0xaa41bcc*/) = 0x9a27;
      iVar23 = DAT_00056190/*=0xaa41bd0*/;
      *(undefined2 *)(iVar4 + iVar22 + 2) = 0x18;
      *(ushort *)(iVar4 + iVar23) = (ushort)(byte)((uint)iVar12 >> 0x18);
      *(ushort *)(iVar4 + iVar23 + 2) = (ushort)(byte)((uint)iVar13 >> 0x18);
      iVar22 = DAT_00056194/*=0xaa41bd4*/;
      *(undefined2 *)(iVar4 + DAT_00056194/*=0xaa41bd4*/) = 0x9aa7;
      iVar23 = DAT_00056198/*=0xaa41bd8*/;
      *(undefined2 *)(iVar4 + iVar22 + 2) = 0x18;
      *(ushort *)(iVar4 + iVar23) = (ushort)(byte)((uint)iVar14 >> 0x18);
      *(ushort *)(iVar4 + DAT_0005619c/*=0xaa41bda*/) = (ushort)(byte)((uint)iVar21 >> 0x18);
      iVar22 = DAT_00056148/*=0xaa41bdc*/;
      *(undefined2 *)(iVar4 + DAT_00056148/*=0xaa41bdc*/) = 0x9b27;
      *(undefined2 *)(iVar4 + iVar22 + 2) = 0x18;
      *(ushort *)(iVar4 + iVar22 + 4) = (ushort)(byte)((uint)iVar20 >> 0x18);
      *(ushort *)(iVar4 + DAT_0005614c/*=0xaa41be2*/) = (ushort)(byte)((uint)iVar19 >> 0x18);
      iVar22 = DAT_00056150/*=0xaa41be4*/;
      *(undefined2 *)(iVar4 + DAT_00056150/*=0xaa41be4*/) = 0x9ba7;
      *(undefined2 *)(iVar4 + iVar22 + 2) = 0x18;
      *(ushort *)(iVar4 + iVar22 + 4) = (ushort)(byte)((uint)iVar16 >> 0x18);
      *(ushort *)(iVar4 + DAT_00056154/*=0xaa41bea*/) = (ushort)(byte)((uint)iVar17 >> 0x18);
      iVar22 = DAT_00056158/*=0xaa41bec*/;
      *(undefined2 *)(iVar4 + DAT_00056158/*=0xaa41bec*/) = 0x9c27;
      *(undefined2 *)(iVar4 + iVar22 + 2) = 0x18;
      *DAT_0005615c/*=0xaaa0000*/ = 1;
    }
  }
  FUN_0004f46c(param_1);
  return 1;
}

//==== 0x561a0  0x561a0-0x562a1 inclusive
void FUN_000561a0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  ushort uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  
  iVar1 = DAT_000562a4/*=0xa110c80*/;
  uVar5 = 0;
  if ((*(uint *)(param_1 + 0x78) & 0x40) == 0) {
    uVar8 = 1;
  }
  else {
    uVar8 = 2;
  }
  while (iVar7 = DAT_000562a8/*=0xa110208*/, (uVar5 & 0xffff) < uVar8) {
    *(undefined4 *)(uVar5 * 0x400000 + iVar1) = 0;
    uVar5 = uVar5 + 1;
  }
  uVar5 = 0;
  while (iVar1 = DAT_000562ac/*=0xa110510*/, (uVar5 & 0xffff) < uVar8) {
    *(undefined4 *)(uVar5 * 0x400000 + iVar7) = 0;
    uVar5 = uVar5 + 1;
  }
  uVar4 = 0;
  while( true ) {
    iVar7 = DAT_000562a4/*=0xa110c80*/;
    if (uVar8 <= uVar4) break;
    iVar7 = (uint)uVar4 * 0x400000;
    *(uint *)(iVar7 + iVar1) = *(uint *)(iVar7 + iVar1) & 0xffff3fff | 0x4000;
    uVar4 = uVar4 + 1;
  }
  uVar4 = 0;
  while( true ) {
    puVar3 = DAT_000562d4/*=0x20244a8*/;
    puVar6 = DAT_000562b8/*=0x202481c*/;
    if (uVar8 <= uVar4) break;
    *(undefined4 *)((uint)uVar4 * 0x400000 + iVar7) = 1;
    uVar4 = uVar4 + 1;
  }
  for (uVar4 = 0; uVar4 < uVar8; uVar4 = uVar4 + 1) {
    do {
    } while (-1 < *(int *)(DAT_000562b0/*=0xa110c84*/ + (uint)uVar4 * 0x400000) << 0x1f);
  }
  if (uVar8 == 2) {
    *DAT_000562b4/*=0x2024818*/ = 0x8002;
    *puVar6 = 0xffffffff;
    puVar6 = DAT_000562bc/*=0xa030018*/;
    *DAT_000562bc/*=0xa030018*/ = 0x8002;
    puVar6[0x4000] = 0x8002;
    puVar6 = DAT_000562c0/*=0xa030068*/;
    *DAT_000562c0/*=0xa030068*/ = 0xffffffff;
    puVar6[0x4000] = 0xffffffff;
    puVar6 = DAT_000562c4/*=0x2024838*/;
    *DAT_000562c4/*=0x2024838*/ = 2;
    puVar6[-0xeb] = 2;
    puVar6[-0x6b] = 2;
    uVar9 = DAT_000562cc/*=0x8081008*/;
    uVar2 = DAT_000562c8/*=0x10102010*/;
    uRam02023a04 = 0xffffffff;
    uRam02023c04 = 0xffffffff;
    uRam02023e04 = 0xffffffff;
    uRam02024004 = 0xffffffff;
    uRam02024204 = 0xffffffff;
    uRam02024490 = DAT_000562c8/*=0x10102010*/;
    puVar6[-0xe9] = DAT_000562cc/*=0x8081008*/;
    puVar6[-0x6a] = uVar2;
    puVar6 = DAT_000562d0/*=0x2024694*/;
  }
  else {
    *DAT_000562d4/*=0x20244a8*/ = 1;
    puVar3[0x80] = 1;
    puVar6 = DAT_000562d8/*=0xa030008*/;
    uVar9 = 3;
    *DAT_000562d8/*=0xa030008*/ = 3;
    puVar6 = puVar6 + 0x4000;
  }
  *puVar6 = uVar9;
  return;
}

//==== 0x562dc  0x562dc-0x563bf inclusive
void FUN_000562dc(uint *param_1,int param_2)

{
  char cVar1;
  short sVar2;
  char *pcVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint *puVar13;
  uint *puVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  uint local_11c;
  uint local_118;
  uint local_114;
  uint local_110;
  int local_10c;
  uint local_108;
  uint local_104;
  uint local_100;
  uint local_fc;
  uint local_f8;
  uint local_f4;
  uint local_f0;
  uint local_ec;
  uint local_e8;
  uint local_e4;
  uint local_e0;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  uint local_cc;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  uint local_bc;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  int local_a4;
  int local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  int local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  int local_60;
  int local_5c;
  int local_58;
  uint local_50;
  int local_4c;
  uint local_48;
  uint local_44;
  int local_40;
  uint local_3c;
  int local_38;
  uint local_34;
  
  param_2 = param_2 * 0x400000;
  iVar17 = 3;
  puVar13 = (uint *)(param_2 + DAT_000563c0/*=0xa110d00*/);
  iVar18 = 3;
  uVar20 = param_1[1];
  local_70 = 3;
  local_6c = 3;
  puVar14 = (uint *)(param_2 + DAT_000563c0/*=0xa110d00*/ + -0x7f0);
  local_e4 = 3;
  local_108 = 8;
  local_e0 = 100;
  local_11c = 0;
  local_74 = 0;
  local_ac = 0;
  local_78 = 0;
  local_b0 = 0xf;
  local_7c = 0xf;
  local_10c = 0x1c;
  local_118 = 2;
  local_34 = 2;
  local_80 = 2;
  local_110 = 4;
  local_b4 = 4;
  local_38 = 0x20;
  local_40 = 8;
  local_3c = 8;
  local_44 = 8;
  local_48 = 2;
  local_84 = 4;
  local_b8 = 4;
  local_e8 = 4;
  local_88 = 3;
  local_bc = 8;
  local_8c = 0x1b;
  local_ec = 0xc;
  uVar5 = 0x3c;
  local_114 = 10;
  local_50 = 100;
  local_4c = 100;
  local_94 = 0x8c;
  local_f0 = 0x80;
  local_c4 = 10;
  local_c0 = 0x62;
  local_104 = 6;
  local_f8 = 0xe;
  local_c8 = 0x10;
  local_9c = 6;
  local_98 = 0x14;
  local_d0 = 2;
  uVar19 = 1;
  local_a0 = 2;
  local_d4 = 0;
  local_fc = 0;
  uVar4 = 10;
  uVar16 = 0;
  local_100 = 3;
  local_f4 = 3;
  local_cc = 3;
  local_a4 = 3;
  local_d8 = 1;
  local_58 = 1;
  local_60 = 0;
  local_5c = 0;
  do {
    if (iVar17 == -1) {
      return;
    }
    if ((param_1[0x1e] & 5) != 5) {
      iVar17 = 0;
    }
    if ((int)(param_1[0x1e] << 0x1d) < 0) {
      if (uVar20 == 8) {
        uVar10 = param_1[0x18];
        uVar16 = *param_1 << 2;
      }
      else {
        if (uVar20 != 9) goto LAB_000563f6;
        uVar10 = param_1[0x18];
        uVar16 = *param_1;
      }
      if (iVar17 == 0) {
        uVar10 = uVar10 & 0x1f;
      }
      else if (iVar17 == 1) {
        uVar10 = (uVar10 & 0x1fff) >> 8;
      }
      else if (iVar17 == 2) {
        uVar10 = (uVar10 & 0x1fffff) >> 0x10;
      }
      else {
        uVar10 = (uVar10 & 0x1fffffff) >> 0x18;
      }
      uVar16 = FUN_00048038(uVar16,uVar10 + 1);
    }
    else if (uVar20 == 8) {
      uVar16 = *param_1;
    }
    else if (uVar20 == 9) {
      uVar16 = *param_1 >> 2;
    }
LAB_000563f6:
    if (uVar20 == 8) {
      uVar4 = FUN_0004b4a8(0x28,uVar16);
      local_c8 = (uint)uVar4;
      uVar4 = FUN_0004b4a8(10,uVar16);
      local_f4 = (uint)uVar4;
      local_cc = local_f4;
      if (local_f4 < 4) {
        local_cc = 4;
      }
      uVar4 = FUN_0004b4a8(0x12,uVar16);
      local_9c = (uint)uVar4;
      if (local_9c < 4) {
        local_9c = 4;
      }
      uVar4 = FUN_0004b4a8(8,uVar16);
      local_c4 = (uint)uVar4;
      if (local_c4 < 5) {
        local_c4 = 5;
      }
      if (local_f4 < 8) {
        local_f4 = 8;
      }
      uVar4 = FUN_0004b4a8(0x15,uVar16);
      local_104 = (uint)uVar4;
      if (local_104 < 4) {
        local_104 = 4;
      }
      uVar4 = FUN_0004b4a8(0x2a,uVar16);
      local_f8 = (uint)uVar4;
      if (local_f8 < 3) {
        local_f8 = 3;
      }
      local_98 = local_f8 + local_104 & 0xffff;
      uVar19 = FUN_0004b4a8(0xf40,uVar16);
      local_c0 = (uVar19 & 0x1fffff) >> 5;
      uVar4 = FUN_0004b4a8(0x17c,uVar16);
      local_f0 = (uint)uVar4;
      uVar4 = FUN_0004b4a8(0x184,uVar16);
      local_110 = (uint)uVar4;
      if (local_110 < 2) {
        local_110 = 2;
      }
      uVar4 = FUN_0004b4a8(0x5a,uVar16);
      local_94 = (uint)uVar4;
      local_a0 = 8;
LAB_000564be:
      uVar4 = FUN_0004b4a8(0xe,uVar16);
      if (uVar4 < 10) {
        uVar4 = 10;
      }
      uVar5 = FUN_0004b4a8(8,uVar16);
      uVar19 = (uint)uVar5;
      local_d0 = uVar19;
      if (uVar19 < 4) {
        local_d0 = 4;
      }
      uVar5 = FUN_0004b4a8(2,uVar16);
      uVar10 = (uint)uVar5;
      local_e4 = uVar10;
      if (uVar10 < 3) {
        local_e4 = 3;
      }
      local_84 = uVar19;
      if (uVar19 < 5) {
        local_84 = 5;
      }
      uVar5 = FUN_0004b4a8(0xf,uVar16);
      local_88 = (uint)uVar5;
      if (local_88 < 4) {
        local_88 = 4;
      }
      local_8c = local_c0 * 0x4800 >> 0x10;
      uVar6 = FUN_0004b4a8(3,uVar16);
      if (uVar16 < 0x42b) {
        local_10c = 0x14;
LAB_00056d4a:
        iVar18 = 4;
      }
      else {
        if (uVar16 < 0x536) {
          local_10c = 0x16;
          goto LAB_00056d4a;
        }
        if (uVar16 < 0x641) {
          iVar18 = 6;
          local_10c = 0x18;
        }
        else if (uVar16 < 0x74b) {
          iVar18 = 6;
          local_10c = 0x1a;
        }
        else {
          iVar18 = 8;
          local_10c = 0x1c;
        }
      }
      uVar5 = FUN_0004b4a8(0x28,uVar16);
      if (uVar5 < 8) {
        uVar5 = 8;
      }
      uVar7 = FUN_0004b4a8(1000,uVar16);
      local_e0 = (uint)uVar7;
      uVar7 = FUN_0004b4a8(0x1e,uVar16);
      local_108 = (uint)uVar7;
      if (local_108 < 8) {
        local_108 = 8;
      }
      uVar7 = FUN_0004b4a8(0x32,uVar16);
      local_70 = (uint)uVar7;
      *(undefined1 *)(DAT_00056680/*=0x83620*/ + 8) = 0x24;
      if (local_70 < 3) {
        local_70 = 3;
      }
      if (uVar19 < 8) {
        uVar19 = 8;
      }
      param_1[9] = param_1[9] | 0x74;
      param_1[10] = param_1[10] & 0xffffff80 | 0x3f;
      local_e8 = ((uVar6 + 0x34) - uVar10) - iVar18 & 0xffff;
      local_bc = local_f4 + 0x1b & 0xffff;
      local_fc = uVar6 + 0x36 + uVar19 & 0xffff;
      local_d4 = uVar19 + 0x43 & 0xffff;
      local_78 = (iVar18 + local_10c) - 7U & 0xffff;
      uVar19 = 0xe;
      local_ac = uVar10 + 7 & 0xffff;
      iVar18 = FUN_0004b4a8(1,uVar16);
      local_11c = 9U - iVar18 & 0xffff;
      iVar18 = 0x24;
      if (local_11c < 4) {
        local_11c = 4;
      }
      local_b4 = 4;
      local_ec = 0x43;
      local_100 = 0x10;
      local_a4 = 0x12;
      local_d8 = 0x1f;
      local_b8 = local_e4;
      local_74 = local_fc;
    }
    else if (uVar20 == 9) {
      iVar15 = *(int *)(DAT_00056944/*=0x83620*/ + 4);
      if (iVar15 == 0) {
        local_a0 = 4;
      }
      else {
        local_a0 = 2;
      }
      uVar5 = FUN_0004b4a8(0x14,uVar16);
      local_c8 = (uint)uVar5;
      uVar5 = FUN_0004b4a8(5,uVar16);
      local_84 = (uint)uVar5;
      local_cc = local_84;
      if (local_84 < 2) {
        local_cc = 2;
      }
      uVar5 = FUN_0004b4a8(0x12,uVar16);
      local_9c = (uint)uVar5;
      if (local_9c < 2) {
        local_9c = 2;
      }
      uVar19 = FUN_0004b4a8(7,uVar16);
      uVar10 = param_1[0x1b];
      uVar19 = uVar19 & 0xffff;
      local_c4 = uVar19;
      if (uVar19 < 3) {
        local_c4 = 3;
      }
      if ((int)uVar10 < 0) {
        uVar8 = 0xe;
      }
      else {
        uVar8 = 0xc;
      }
      uVar5 = FUN_0004b4a8(uVar8,uVar16);
      if (iVar15 != 0) {
        uVar5 = FUN_0004b4a8(0xe,uVar16);
      }
      local_f4 = (uint)uVar5;
      if (local_f4 < 4) {
        local_f4 = 4;
      }
      uVar6 = FUN_0004b4a8(8,uVar16);
      local_114 = (uint)uVar6;
      local_118 = local_114;
      if (local_114 < 2) {
        local_118 = 2;
      }
      if (iVar15 == 0) {
        local_100 = local_118;
      }
      else {
        local_100 = local_118 + 2 & 0xffff;
      }
      uVar5 = FUN_0004b4a8(0x15,uVar16);
      local_104 = (uint)uVar5;
      if (local_104 < 2) {
        local_104 = 2;
      }
      uVar5 = FUN_0004b4a8(0x2a,uVar16);
      local_f8 = (uint)uVar5;
      if (local_f8 < 3) {
        local_f8 = 3;
      }
      local_98 = local_f8 + local_104 & 0xffff;
      uVar12 = FUN_0004b4a8(0xf42,uVar16);
      local_c0 = uVar12 >> 5 & 0xffff;
      uVar5 = FUN_0004b4a8(0x17c,uVar16);
      local_f0 = (uint)uVar5;
      local_110 = local_f0 + local_118 & 0xffff;
      uVar5 = FUN_0004b4a8(DAT_00056948/*=0x30d40*/,uVar16);
      uVar9 = uVar5 & 0x3ff;
      if ((uVar5 & 0x3ff) != 0) {
        uVar9 = 1;
      }
      local_4c = uVar9 + (uVar5 >> 10);
      uVar5 = FUN_0004b4a8(0x104,uVar16);
      local_50 = (uint)uVar5;
      uVar5 = FUN_0004b4a8(0x5a,uVar16);
      local_94 = (uint)uVar5;
      uVar5 = FUN_0004b4a8(3,uVar16);
      local_80 = (uint)uVar5;
      local_48 = local_cc + 1 & 0xffff;
      uVar19 = uVar19 & ~((int)uVar10 >> 0x20);
      if ((int)uVar10 < 0) {
        uVar19 = local_114;
      }
      if (uVar19 < 4) {
        uVar19 = 4;
      }
      iVar18 = FUN_0004b4a8(10,uVar16);
      local_d0 = iVar18 + 1U & 0xffff;
      if (iVar15 == 0) {
        local_38 = 0x10;
      }
      else {
        local_38 = 8;
      }
      if (local_84 < 3) {
        local_84 = 3;
      }
      uVar5 = FUN_0004b4a8(0xf,uVar16);
      local_88 = (uint)uVar5;
      if (local_88 < 2) {
        local_88 = 2;
      }
      local_8c = (uVar12 >> 5 & 0xffff) * 9 >> 5;
      uVar12 = FUN_0004b4a8(1,uVar16);
      uVar5 = FUN_0004b4a8(0x28,uVar16);
      if (uVar5 < 8) {
        uVar5 = 8;
      }
      iVar18 = FUN_0004b4a8(6000,uVar16);
      local_e0 = iVar18 + 10U & 0xffff;
      uVar7 = FUN_0004b4a8(0x1e,uVar16);
      local_6c = (uint)uVar7;
      local_108 = local_6c;
      if (local_6c < 4) {
        local_108 = 4;
      }
      uVar7 = FUN_0004b4a8(0x32,uVar16);
      local_70 = (uint)uVar7;
      if (local_70 < 3) {
        local_70 = 3;
      }
      if (-1 < (int)uVar10) {
        iVar18 = 0xd;
      }
      else {
        iVar18 = 0xe;
      }
      *(char *)(DAT_00056944/*=0x83620*/ + 8) = (char)iVar18;
      if (-1 < (int)uVar10) {
        iVar11 = 0x15;
      }
      else {
        iVar11 = 0x16;
      }
      local_d8 = iVar18 * 4 - 5U & 0xffff;
      param_1[9] = param_1[9] | 0x80;
      param_1[10] = param_1[10] | 0x88;
      if (iVar15 == 0) {
        local_bc = local_f4 + 0xb;
        local_e8 = iVar18 + 3;
      }
      else {
        param_1[0xb] = param_1[0xb] & 0xffffffe7 | 0x10;
        local_e8 = iVar18 - 3U & 0xffff;
        local_bc = local_f4 + 9;
      }
      local_ec = iVar11 + 10;
      local_7c = iVar18 + 3;
      local_bc = local_bc & 0xffff;
      local_44 = uVar19 + 9 & 0xffff;
      local_11c = local_c8 + 0xb + iVar18 & 0xffff;
      if (iVar15 == 0) {
        local_7c = iVar18 + 5;
        local_b0 = 0xc;
      }
      else {
        local_b0 = 10;
      }
      local_40 = iVar18 + 1;
      if (local_114 < 4) {
        uVar6 = 4;
      }
      sVar2 = (short)local_100 + uVar6 + (short)iVar18;
      if (iVar15 == 0) {
        uVar7 = sVar2 + 6;
      }
      else {
        uVar7 = sVar2 + 4;
      }
      local_fc = (uint)uVar7;
      sVar2 = uVar6 + 7 + (short)iVar11;
      if (iVar15 == 0) {
        uVar6 = sVar2 + 4;
      }
      else {
        uVar6 = sVar2 + 2;
      }
      local_d4 = (uint)uVar6;
      uVar10 = (uVar12 & 0xffff) >> 2;
      local_78 = local_80 + 7 & 0xffff;
      uVar19 = 0x17;
      local_ac = uVar10 + 0xb;
      local_74 = uVar10 + 2 + local_e8 & 0xffff;
      local_10c = 10;
      local_b4 = 2;
      local_e4 = 3;
      local_b8 = 2;
      local_a4 = 7;
      local_5c = 3;
      local_58 = 3;
      local_60 = 5;
      local_3c = local_ec;
      local_34 = local_d0;
    }
    else if (uVar20 == 8) goto LAB_000564be;
    iVar15 = iVar17 * 0x100000 + param_2;
    *(uint *)(iVar15 + 0xa100000) = local_f8 | local_c8 << 0x10 | local_ec << 0x18 | local_8c << 8;
    *(uint *)(iVar15 + 0xa100004) = local_98 | local_c4 << 0x10 | local_100 << 8;
    *(uint *)(iVar15 + 0xa100008) = iVar18 << 0x10 | local_a4 << 0x18 | local_bc | local_e8 << 8;
    *(uint *)(iVar15 + 0xa10000c) = local_fc << 8 | (uint)uVar4 << 0x10 | local_d4;
    *(uint *)(iVar15 + 0xa100010) = local_a0 << 0x10 | local_9c << 0x18 | local_104 | local_cc << 8;
    *(uint *)(iVar15 + 0xa100014) = local_84 << 0x10 | local_b8 << 0x18 | local_d0 | local_88 << 8;
    *(uint *)(iVar15 + 0xa100018) = local_c4 + 2;
    *(uint *)(iVar15 + 0xa10001c) = local_80;
    *(uint *)(iVar15 + 0xa100024) = local_44 | 0x20000 | local_48 << 8;
    *(uint *)(iVar15 + 0xa100030) = local_e4 << 0x10;
    *(uint *)(iVar15 + 0xa100034) = local_b4 | local_38 << 0x10 | local_10c << 0x18;
    *(uint *)(iVar15 + 0xa100038) = local_110 | (uint)uVar5 << 0x10;
    *(uint *)(iVar15 + 0xa10005c) = local_34 | local_4c << 0x10;
    uVar10 = local_b0;
    if (uVar20 == 9) {
      uVar10 = local_3c;
    }
    *(uint *)(iVar15 + 0xa100060) = local_7c << 8 | local_40 << 0x10 | local_b0;
    pcVar3 = DAT_00056d9c/*=0x83620*/;
    if (uVar20 == 9) {
      uVar12 = local_118;
    }
    else {
      uVar12 = local_100 | 0x20000;
      uVar10 = local_ec;
    }
    *(uint *)(iVar15 + 0xa100064) = uVar12 | uVar10 << 8;
    *(undefined4 *)(iVar15 + 0xa100078) = DAT_00056da0/*=0x556262*/;
    *(undefined4 *)(iVar15 + 0xa100080) = 0;
    cVar1 = *pcVar3;
    if (cVar1 == '\0') {
      uVar10 = *(uint *)(iVar15 + 0xa100d00) | 1;
    }
    else {
      uVar10 = *(uint *)(iVar15 + 0xa100d00) & 0xfffffffe;
    }
    *(uint *)(iVar15 + 0xa100d00) = uVar10;
    if (iVar17 == 0) {
      uVar10 = *puVar13;
      if (uVar20 == 9) {
        uVar10 = uVar10 & 0x3fffffff;
      }
      if (uVar20 == 9) {
        uVar10 = uVar10 | 0x40000000;
      }
      if (*DAT_00056da4/*=0x606b4*/ != 0) {
        uVar10 = uVar10 | 0xc0000000;
      }
      uVar12 = FUN_0004b4a8(2000,uVar16 >> 2);
      uVar9 = FUN_0004b4a8(DAT_00056da8/*=0x1e8480*/,uVar16 >> 2);
      *puVar13 = (uVar9 >> 10) + 1 & 0xffff | uVar10 & 0xfc00e000 | ((uVar12 >> 10) + 1) * 0x10000;
      *puVar14 = *puVar14 & 0xfffffffe;
    }
    if (uVar20 == 8) {
      *(uint *)(iVar15 + 0xa100500) = param_1[10] | param_1[9] << 0x10;
      *(uint *)(iVar15 + 0xa100504) = param_1[0x11] | param_1[0xb] << 0x10;
      *(uint *)(iVar15 + 0xa100508) = param_1[0x10] | param_1[0xf] << 0x10;
      if ((param_1[0x1b] & 0x20000000) == 0) {
        uVar10 = (uint)(byte)param_1[0x32];
      }
      else {
        uVar10 = param_1[0x12];
      }
      *(uint *)(iVar15 + 0xa10050c) = uVar10 | param_1[0x15] << 0x10;
    }
    uVar10 = *(uint *)(iVar15 + 0xa100d04) & 0xffff0000;
    if (uVar20 == 9) {
      uVar10 = local_ac | uVar10 | local_78 << 8;
    }
    else {
      uVar10 = local_ac + 0x10 | local_78 << 8 | uVar10;
    }
    *(uint *)(iVar15 + 0xa100d04) = uVar10;
    *(uint *)(iVar15 + 0xa100d08) =
         *(uint *)(iVar15 + 0xa100d08) & 0xffff0000 | local_11c | local_74 << 8;
    *(undefined4 *)(iVar15 + 0xa100d0c) = DAT_00056dac/*=0x400005*/;
    if (uVar20 == 9) {
      *(undefined4 *)(iVar15 + 0xa1005a0) = DAT_00056db0/*=0x20202*/;
      *(undefined4 *)(iVar15 + 0xa1005a4) = 0x201;
      *(undefined4 *)(iVar15 + 0xa1005a8) = DAT_00056db4/*=0x1c0003*/;
      *(undefined4 *)(iVar15 + 0xa1005ac) = DAT_00056db8/*=0x5800a0*/;
      *(undefined4 *)(iVar15 + 0xa1005b0) = 0x97;
      *(undefined4 *)(iVar15 + 0xa1005b8) = 0x147;
      uVar10 = uVar19 | 0x3000000;
LAB_00056c10:
      uVar10 = uVar10 | 0x200;
    }
    else {
      if (cVar1 != '\0') {
        uVar10 = uVar19 | 0x4000000;
        goto LAB_00056c10;
      }
      uVar10 = uVar19 | 0x2000200;
    }
    *(uint *)(iVar15 + 0xa100580) = uVar10 | local_d8 << 0x10;
    if (uVar20 == 9) {
      uVar8 = DAT_00056dd4/*=0x70303*/;
    }
    else {
      uVar8 = DAT_00056dbc/*=0x60202*/;
      if (cVar1 != '\0') {
        uVar8 = DAT_00056dc0/*=0xc0404*/;
      }
    }
    *(undefined4 *)(iVar15 + 0xa100584) = uVar8;
    if (uVar20 == 9) {
      uVar10 = uVar19 | 0x180000;
    }
    else if (cVar1 == '\0') {
      uVar10 = uVar19 | 0x1f0000;
    }
    else {
      uVar10 = uVar19 | 0x3e0000;
    }
    *(uint *)(iVar15 + 0xa100588) = local_d8 << 8 | uVar10;
    *(uint *)(iVar15 + 0xa100590) = (local_5c + -1) * 0x40000 | (local_60 + -1) * 0x4000000 | 0x411;
    *(uint *)(iVar15 + 0xa100594) = DAT_00056dc4/*=0x400000f*/ | local_58 << 0x12;
    *(uint *)(iVar15 + 0xa100600) = DAT_00056dc8/*=0x7fff0000*/ & *(uint *)(iVar15 + 0xa100600) | local_c0;
    *(uint *)(iVar15 + 0xa100604) =
         *(uint *)(iVar15 + 0xa100604) & 0xf000f000 | local_f0 | local_f0 << 0x10;
    *(uint *)(iVar15 + 0xa100608) =
         local_94 << 0x10 | local_114 << 0x18 | *(uint *)(iVar15 + 0xa100608) & 0xffff;
    *(uint *)(iVar15 + 0xa100650) = *(uint *)(iVar15 + 0xa100650) & 0xfffff000 | local_50;
    *(uint *)(iVar15 + 0xa100800) = local_e0 | local_108 << 0x10;
    *(uint *)(iVar15 + 0xa100804) = local_70 << 0x14 | 0x100;
    if (uVar20 == 9) {
      *(uint *)(iVar15 + 0xa100808) = local_6c;
      *(undefined4 *)(iVar15 + 0xa100a80) = 0x1f74;
      *(undefined4 *)(iVar15 + 0xa100b00) = DAT_00056dcc/*=0x7c0c3e2*/;
      *(undefined4 *)(iVar15 + 0xa100b04) = DAT_00056dd0/*=0x1024100a*/;
      *(undefined4 *)(iVar15 + 0xa100b08) = 0x33;
      *(undefined4 *)(iVar15 + 0xa100b80) = 0x170000;
    }
    iVar17 = iVar17 + -1;
    FUN_00048d80(0x14);
  } while( true );
}

//==== 0x56dd8  0x56dd8-0x56e41 inclusive
void FUN_00056dd8(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  iVar8 = DAT_0005705c/*=0xa130018*/;
  uVar1 = *(uint *)(param_1 + 0x18);
  uVar3 = (uVar1 & 0x3fff) >> 0xc;
  uVar11 = uVar1 & 0xf;
  uVar7 = (uVar1 & 0xfff) >> 4;
  uVar1 = (uVar1 & 0xffff) >> 0xe;
  uVar4 = (*(uint *)(param_1 + 0x1c) & 0x7fff) >> 0xc;
  if (uVar4 == 7) {
    uVar4 = 2;
  }
  else {
    uVar4 = (uint)(uVar4 == 1);
  }
  uVar9 = uVar1 << 8;
  uVar10 = uVar9 | uVar1 << 0x10;
  param_2 = param_2 * 0x400000;
  *(uint *)(param_2 + DAT_0005705c/*=0xa130018*/) = uVar10 | uVar1 << 0x18;
  iVar6 = DAT_00057038/*=0x83620*/;
  if (*(int *)(DAT_00057038/*=0x83620*/ + 4) != 0) {
    *(undefined4 *)(param_2 + iVar8) = 0;
  }
  iVar8 = DAT_00057060/*=0xa130014*/;
  switch(uVar11) {
  case 8:
    uVar10 = uVar1 | 0x1f1f1f00;
    break;
  case 9:
    uVar10 = uVar1 | 0x1f1f0000 | uVar9;
    break;
  case 10:
    *(uint *)(param_2 + DAT_00057060/*=0xa130014*/) = uVar1 | 0x1f000000 | uVar9 | uVar1 << 0x10;
    if (*(int *)(iVar6 + 4) != 0) {
      uVar10 = 0x1f000000;
      break;
    }
    goto LAB_00056e56;
  default:
    uVar10 = uVar1 << 0x18 | uVar1 | uVar10;
  }
  *(uint *)(param_2 + iVar8) = uVar10;
LAB_00056e56:
  iVar8 = DAT_00057064/*=0xa130010*/;
  if (uVar1 == 2) {
    uVar5 = 0x101;
  }
  else {
    uVar5 = 0x3f3f;
    if (uVar1 == 1) {
      uVar5 = 0x3f01;
    }
  }
  *(undefined4 *)(param_2 + DAT_00057064/*=0xa130010*/) = uVar5;
  if (*(int *)(iVar6 + 4) != 0) {
    if (uVar1 == 2) {
      uVar5 = 0x909;
    }
    else {
      uVar5 = 0x3f3f;
      if (uVar1 == 1) {
        uVar5 = 0x3f09;
      }
    }
    *(undefined4 *)(param_2 + iVar8) = uVar5;
  }
  iVar8 = DAT_00057068/*=0xa13000c*/;
  uVar9 = uVar11 - 3;
  uVar10 = uVar9 + uVar1;
  if (uVar3 == 3) {
    uVar10 = uVar10 * 0x100 | uVar10 * 0x10000 | uVar10;
LAB_00056ea8:
    *(uint *)(param_2 + iVar8) = uVar10;
  }
  else {
    *(uint *)(param_2 + DAT_00057068/*=0xa13000c*/) = uVar10 | 0x3f0000 | uVar10 * 0x100;
    if (*(int *)(iVar6 + 4) != 0) {
      uVar10 = uVar9 | 0x3f0000 | uVar9 * 0x100;
      goto LAB_00056ea8;
    }
  }
  iVar6 = DAT_0005706c/*=0xa130020*/;
  iVar8 = DAT_00057040/*=0xa130028*/;
  iVar2 = uVar1 + uVar3 + uVar11;
  uVar1 = iVar2 - 6;
  uVar10 = uVar1 | uVar1 * 0x100;
  uVar3 = uVar10 | uVar1 * 0x10000;
  *(uint *)(param_2 + DAT_0005703c/*=0xa13002c*/) = uVar10;
  uVar11 = uVar3 | uVar1 * 0x1000000;
  *(uint *)(param_2 + iVar8) = uVar11;
  *(uint *)(param_2 + iVar8 + -4) = uVar11;
  iVar8 = iVar8 + -0xc;
  *(uint *)(param_2 + iVar6) = uVar11;
  switch(uVar7) {
  case 0xe:
    uVar3 = 0x1f1f1f1f;
    break;
  case 0xf:
    if ((*(ushort *)(param_1 + 0x7a) & 7) - 1 < 2) {
      uVar11 = uVar1 + uVar4 | DAT_00057044/*=0x1f1f1f00*/;
      *(uint *)(param_2 + iVar6) = uVar3 | (uVar1 + uVar4) * 0x1000000;
      *(uint *)(param_2 + iVar8) = uVar11;
      uVar3 = iVar2 + 7;
      goto LAB_00056f6e;
    }
    uVar3 = uVar1 | DAT_00057044/*=0x1f1f1f00*/;
    break;
  case 0x10:
    if ((*(ushort *)(param_1 + 0x7a) & 7) == 1) {
      *(uint *)(param_2 + iVar8) = DAT_00057054/*=0x1f1f0000*/ | uVar1 + uVar4 | (uVar1 + uVar4) * 0x100;
      iVar6 = *(int *)(param_1 + 4);
      iVar8 = iVar6;
      if (iVar6 == 9) {
        uVar4 = 3;
        iVar8 = DAT_00057058/*=0xa130030*/;
      }
      if (iVar6 == 9) {
        *(uint *)(param_2 + iVar8) = uVar4;
      }
      uVar3 = iVar2 + 8;
      goto LAB_00056f6e;
    }
    uVar11 = uVar10 | DAT_00057054/*=0x1f1f0000*/;
LAB_00056fe0:
    *(uint *)(param_2 + iVar8) = uVar11;
    goto LAB_00056f76;
  case 0x11:
    if ((*(ushort *)(param_1 + 0x7a) & 7) == 1) {
      uVar3 = iVar2 + 9;
      *(uint *)(param_2 + iVar8) =
           uVar1 | 0x1f000000 | (uVar4 + uVar1) * 0x100 | (uVar4 + uVar1) * 0x10000;
      goto LAB_00056f6e;
    }
    uVar3 = uVar3 | 0x1f000000;
    break;
  default:
    if ((*(ushort *)(param_1 + 0x7a) & 7) != 1) goto LAB_00056fe0;
    *(uint *)(param_2 + iVar8) = (uVar1 + uVar4) * 0x1000000 | (uVar1 + uVar4) * 0x10000 | uVar10;
    uVar3 = (uVar7 - 8) + iVar2;
LAB_00056f6e:
    *(uint *)(param_2 + DAT_00057048/*=0xa130004*/) = uVar3 | 0x3f00;
    goto LAB_00056f76;
  }
  *(uint *)(param_2 + iVar8) = uVar3;
LAB_00056f76:
  if (*(int *)(param_1 + 0x1c) << 0x13 < 0) {
    if ((*(ushort *)(param_1 + 0x7a) & 7) - 1 < 2) goto LAB_00056f96;
    uVar1 = iVar2 + (uVar7 - 6) | 0x3f00;
  }
  else {
    uVar1 = 0x3f3f;
  }
  *(uint *)(param_2 + DAT_00057048/*=0xa130004*/) = uVar1;
LAB_00056f96:
  iVar8 = DAT_0005704c/*=0xa110220*/;
  if (*(int *)(param_1 + 4) == 9) {
    *(undefined4 *)(param_2 + DAT_0005704c/*=0xa110220*/) = DAT_00057050/*=0xa090e01*/;
    *(undefined4 *)(param_2 + iVar8 + 4) = 0;
  }
  return;
}

//==== 0x57070  0x57070-0x57085 inclusive
void FUN_00057070(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0x303;
  if ((*(uint *)(param_1 + 0x1c) & 0x1000) == 0) {
    uVar1 = 1;
  }
  *(undefined4 *)(param_2 * 0x400000 + DAT_00057088/*=0xa110c9c*/) = uVar1;
  return;
}

//==== 0x5708c  0x5708c-0x570c9 inclusive
void FUN_0005708c(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = (*(uint *)(param_1 + 4) & 0xf) - 4;
  if (uVar1 < 6) {
    uVar1 = *(uint *)(DAT_000570cc/*=0x5e5e0*/ + uVar1 * 4 + 0x134);
  }
  else {
    uVar1 = DAT_000570d0/*=0x40001*/;
  }
  *(uint *)(param_2 * 0x400000 + 0xa110000) =
       (*(uint *)(param_1 + 0x1c) & 1) << 0xc |
       ((*(uint *)(param_1 + 0x1c) >> 0xb & 6) + 1) * 0x1000000 | uVar1;
  return;
}

//==== 0x570d4  0x570d4-0x57213 inclusive
void FUN_000570d4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = param_2 * 0x400000;
  uVar3 = FUN_0005708c();
  iVar1 = DAT_00057214/*=0xa110510*/;
  iVar4 = FUN_00057070(uVar3,param_2);
  if (*(int *)(iVar4 + 4) == 9) {
    uVar6 = *(uint *)(iVar7 + DAT_00057218/*=0xa110010*/) & 0xfffffeff | 1;
  }
  else {
    uVar6 = 0;
  }
  *(uint *)(iVar7 + DAT_00057218/*=0xa110010*/) = uVar6;
  iVar2 = DAT_0005721c/*=0xa11018c*/;
  *(uint *)(iVar7 + DAT_0005721c/*=0xa11018c*/) = *(uint *)(iVar7 + DAT_0005721c/*=0xa11018c*/) & 0xffffffc0;
  *(uint *)(iVar7 + iVar2 + -0xc) = *(uint *)(iVar7 + iVar2 + -0xc) & 0xffffff00 | 0x800;
  *(uint *)(iVar7 + iVar2 + 0x37c) = *(uint *)(iVar7 + iVar2 + 0x37c) & 0xffff7fff | 0xc0000000;
  uVar6 = *(uint *)(iVar7 + iVar2 + 0xf4);
  if (*(int *)(iVar4 + 4) == 9) {
    uVar6 = uVar6 & 0xdfffffff;
  }
  else {
    uVar6 = uVar6 | 0x20000000;
  }
  *(uint *)(iVar7 + iVar2 + 0xf4) = uVar6 | 0x80000000;
  iVar2 = DAT_00057220/*=0xa110288*/;
  *(uint *)(iVar7 + DAT_00057220/*=0xa110288*/) = *(uint *)(iVar7 + DAT_00057220/*=0xa110288*/) | 1;
  uVar6 = *(uint *)(iVar7 + iVar2 + 0x78) & 0xff00ff00;
  if (*(int *)(iVar4 + 4) == 9) {
    uVar6 = uVar6 | 0xc000c0;
  }
  else {
    uVar6 = uVar6 | 0xc0;
  }
  *(uint *)(iVar7 + iVar2 + 0x78) = uVar6;
  *(uint *)(iVar7 + DAT_00057224/*=0xa110308*/) = *(uint *)(iVar7 + DAT_00057224/*=0xa110308*/) | 1;
  iVar2 = DAT_0005722c/*=0xa110518*/;
  *(undefined4 *)(iVar7 + DAT_00057228/*=0xa110500*/) = 0;
  *(uint *)(iVar7 + iVar2) = *(uint *)(iVar7 + iVar2) & 0xfffffe | 0x25000000;
  *(uint *)(iVar7 + iVar2 + -0x310) = *(uint *)(iVar7 + iVar2 + -0x310) | 1;
  *(uint *)(iVar7 + iVar1) = *(uint *)(iVar7 + iVar1) & 0xfffcffff | 0x10015;
  uVar3 = FUN_00056dd8(iVar4,param_2);
  FUN_000562dc(uVar3,param_2);
  iVar2 = DAT_00057234/*=0xa110c80*/;
  iVar4 = DAT_00057230/*=0xa110b84*/;
  if (*(int *)(param_1 + 4) == 9) {
    *(uint *)(iVar7 + DAT_00057230/*=0xa110b84*/) = *(uint *)(iVar7 + DAT_00057230/*=0xa110b84*/) & 0xfffffffe;
    *(undefined4 *)(iVar7 + iVar2) = 0;
    piVar5 = (int *)(iVar4 + 0x100 + iVar7);
    *(uint *)(iVar7 + iVar1) = *(uint *)(iVar7 + iVar1) & 0xfffcffee | 0x10004;
    *(undefined4 *)(iVar7 + iVar2) = 1;
    do {
    } while (-1 < *piVar5 << 0x1f);
    *(undefined4 *)(iVar7 + iVar2) = 0;
    *(uint *)(iVar7 + iVar1) = *(uint *)(iVar7 + iVar1) & 0xfffcfffe | 0x10014;
    *(undefined4 *)(iVar7 + iVar2) = 1;
    do {
    } while (-1 < *piVar5 << 0x1f);
  }
  return;
}

//==== 0x57238  0x57238-0x572ef inclusive
void FUN_00057238(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = DAT_000572fc/*=0xa110384*/;
  if (*(int *)(param_1 + 4) == 8) {
    iVar1 = param_2 * 0x400000;
    *(uint *)(iVar1 + DAT_000572f0/*=0xa110380*/) = DAT_000572f8/*=0xa001381c*/ | DAT_000572f4/*=0xb7ff001c*/ & *(uint *)(iVar1 + DAT_000572f0/*=0xa110380*/);
    *(uint *)(iVar1 + iVar2) = DAT_00057300/*=0x8880fff*/ & *(uint *)(iVar1 + iVar2) | 0x2000;
    *(uint *)(iVar1 + iVar2 + 8) = *(uint *)(iVar1 + iVar2 + 8) & 0xc0c0c0c0 | 0x4040c3e;
    *(undefined4 *)(iVar1 + DAT_00057304/*=0xa110390*/) = DAT_00057308/*=0x8300810*/;
    uVar3 = *(uint *)(iVar1 + 0xa100c88) & 0xff0000 | 0x1e000046;
    *(uint *)(iVar1 + 0xa100c88) = uVar3;
    *(uint *)(iVar1 + 0xa200c88) = uVar3;
    *(uint *)(iVar1 + 0xa300c88) = uVar3;
    *(uint *)(iVar1 + 0xa400c88) = uVar3;
    *(undefined4 *)(iVar1 + 0xa100c00) = 0xff;
    *(undefined4 *)(iVar1 + 0xa200c00) = 0xff;
    *(undefined4 *)(iVar1 + 0xa300c00) = 0xff;
  }
  else {
    if (*(int *)(param_1 + 4) != 9) {
      return;
    }
    iVar2 = param_2 * 0x400000;
    *(undefined4 *)(iVar2 + DAT_000572f0/*=0xa110380*/) = DAT_0005730c/*=0x80013414*/;
    *(undefined4 *)(iVar2 + 0xa100c00) = 0xff;
    *(undefined4 *)(iVar2 + 0xa200c00) = 0xff;
    *(undefined4 *)(iVar2 + 0xa300c00) = 0xff;
  }
  *(undefined4 *)(param_2 * 0x400000 + 0xa400c00) = 0xff;
  return;
}

//==== 0x57310  0x57310-0x57601 inclusive
void FUN_00057310(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 *puVar3;
  uint *puVar4;
  int iVar5;
  ushort *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int *piVar18;
  uint uVar19;
  bool bVar20;
  
  puVar3 = DAT_00057608/*=0xaa80100*/;
  param_2 = param_2 * 0x400000;
  iVar9 = *(int *)(param_1 + 4);
  *DAT_00057604/*=0xaaa0000*/ = 0;
  *puVar3 = 3;
  if (*DAT_0005760c/*=0xa9b0030*/ >> 8 < (*DAT_0005760c/*=0xa9b0030*/ & 0xff)) {
    uVar10 = (uint)(byte)*DAT_0005760c/*=0xa9b0030*/;
  }
  else {
    uVar10 = (uint)(*DAT_0005760c/*=0xa9b0030*/ >> 8);
  }
  if ((*DAT_00057614/*=0xa9b004c*/ & 0xff) < *DAT_00057610/*=0xa9b004a*/ >> 8) {
    uVar8 = (uint)(*DAT_00057610/*=0xa9b004a*/ >> 8);
  }
  else {
    uVar8 = *DAT_00057614/*=0xa9b004c*/ & 0xff;
  }
  if (uVar10 < uVar8) {
    uVar10 = uVar8;
  }
  if (*DAT_0005761c/*=0xa9b0026*/ >> 8 < (*DAT_0005761c/*=0xa9b0026*/ & 0xff)) {
    uVar8 = (uint)(byte)*DAT_0005761c/*=0xa9b0026*/;
  }
  else {
    uVar8 = (uint)(*DAT_0005761c/*=0xa9b0026*/ >> 8);
  }
  bVar20 = (*DAT_00057618/*=0xa9b0042*/ & 0xff) < *DAT_00057620/*=0xa9b0040*/ >> 8;
  if (bVar20) {
    uVar1 = *DAT_00057620/*=0xa9b0040*/;
  }
  else {
    uVar1 = *DAT_00057618/*=0xa9b0042*/;
  }
  if (bVar20) {
    uVar11 = (uint)(uVar1 >> 8);
  }
  else {
    uVar11 = uVar1 & 0xff;
  }
  bVar20 = *DAT_00057628/*=0xa9b0028*/ >> 8 <= (*DAT_00057624/*=0xa9b002a*/ & 0xff);
  if (bVar20) {
    uVar1 = *DAT_00057624/*=0xa9b002a*/;
  }
  else {
    uVar1 = *DAT_00057628/*=0xa9b0028*/;
  }
  if (bVar20) {
    uVar14 = uVar1 & 0xff;
  }
  else {
    uVar14 = (uint)(uVar1 >> 8);
  }
  if (*DAT_0005762c/*=0xa9b0044*/ >> 8 < (*DAT_0005762c/*=0xa9b0044*/ & 0xff)) {
    uVar12 = (uint)(byte)*DAT_0005762c/*=0xa9b0044*/;
  }
  else {
    uVar12 = (uint)(*DAT_0005762c/*=0xa9b0044*/ >> 8);
  }
  if (uVar14 < uVar12) {
    uVar14 = uVar12;
  }
  bVar20 = *DAT_00057634/*=0xa9b002c*/ >> 8 <= (*DAT_00057630/*=0xa9b002e*/ & 0xff);
  if (bVar20) {
    uVar1 = *DAT_00057630/*=0xa9b002e*/;
  }
  else {
    uVar1 = *DAT_00057634/*=0xa9b002c*/;
  }
  if (bVar20) {
    uVar12 = uVar1 & 0xff;
  }
  else {
    uVar12 = (uint)(uVar1 >> 8);
  }
  if (*DAT_00057640/*=0xa9b0048*/ >> 8 < (*DAT_00057640/*=0xa9b0048*/ & 0xff)) {
    uVar19 = (uint)(byte)*DAT_00057640/*=0xa9b0048*/;
  }
  else {
    uVar19 = (uint)(*DAT_00057640/*=0xa9b0048*/ >> 8);
  }
  if (uVar12 < uVar19) {
    uVar12 = uVar19;
  }
  if (*DAT_00057624/*=0xa9b002a*/ >> 8 < (*DAT_00057628/*=0xa9b0028*/ & 0xff)) {
    uVar1 = *DAT_00057628/*=0xa9b0028*/;
  }
  else {
    uVar1 = *DAT_00057624/*=0xa9b002a*/;
  }
  if (*DAT_00057624/*=0xa9b002a*/ >> 8 < (*DAT_00057628/*=0xa9b0028*/ & 0xff)) {
    uVar19 = (uint)(byte)uVar1;
  }
  else {
    uVar19 = (uint)(uVar1 >> 8);
  }
  bVar20 = *DAT_00057618/*=0xa9b0042*/ >> 8 <= (*DAT_00057644/*=0xa9b0046*/ & 0xff);
  if (bVar20) {
    uVar1 = *DAT_00057644/*=0xa9b0046*/;
  }
  else {
    uVar1 = *DAT_00057618/*=0xa9b0042*/;
  }
  if (bVar20) {
    uVar17 = uVar1 & 0xff;
  }
  else {
    uVar17 = (uint)(uVar1 >> 8);
  }
  if (*DAT_00057630/*=0xa9b002e*/ >> 8 < (*DAT_00057634/*=0xa9b002c*/ & 0xff)) {
    uVar1 = *DAT_00057634/*=0xa9b002c*/;
  }
  else {
    uVar1 = *DAT_00057630/*=0xa9b002e*/;
  }
  if (*DAT_00057630/*=0xa9b002e*/ >> 8 < (*DAT_00057634/*=0xa9b002c*/ & 0xff)) {
    uVar13 = uVar1 & 0xff;
  }
  else {
    uVar13 = (uint)(uVar1 >> 8);
  }
  bVar20 = (*DAT_00057610/*=0xa9b004a*/ & 0xff) < *DAT_00057644/*=0xa9b0046*/ >> 8;
  if (bVar20) {
    uVar1 = *DAT_00057644/*=0xa9b0046*/;
  }
  else {
    uVar1 = *DAT_00057610/*=0xa9b004a*/;
  }
  *puVar3 = 0;
  iVar5 = DAT_00057648/*=0xa110b84*/;
  if (bVar20) {
    uVar1 = uVar1 >> 8;
  }
  uVar16 = (uint)uVar1;
  if (!bVar20) {
    uVar16 = uVar16 & 0xff;
  }
  *DAT_00057604/*=0xaaa0000*/ = 1;
  puVar4 = DAT_00057638/*=0xa110b88*/;
  if (iVar9 == 9) {
    *(uint *)(param_2 + iVar5) = *(uint *)(param_2 + iVar5) | 1;
  }
  do {
  } while ((*puVar4 & 0x7ffffff) >> 0x19 != 3);
  do {
  } while ((*puVar4 & 0x3fffffff) >> 0x1c != 3);
  piVar18 = (int *)(DAT_0005764c/*=0xa110c84*/ + param_2);
  *(undefined4 *)(param_2 + DAT_0005763c/*=0xa110c80*/) = 0;
  do {
  } while (*piVar18 << 0x1f < 0);
  uVar15 = *(uint *)(param_2 + 0xa100d04) & 0xffff0000;
  if (iVar9 == 9) {
    uVar7 = ((*(uint *)(param_2 + 0xa100d04) & 0xffff) >> 8) + uVar10;
    if (0xfe < uVar7) {
      uVar7 = 0xff;
    }
    uVar15 = uVar15 | uVar7 << 8;
    if (uVar8 < uVar11) {
      uVar8 = uVar11;
    }
    uVar8 = uVar8 + (*(uint *)(param_2 + 0xa100d04) & 0xff);
    if (uVar8 < 0x100) {
      uVar15 = uVar15 | uVar8;
    }
    else {
      uVar15 = uVar15 | 0xff;
    }
  }
  *(uint *)(param_2 + 0xa100d04) = uVar15;
  uVar8 = *(uint *)(param_2 + 0xa100d08) & 0xffff0000;
  if (iVar9 == 9) {
    uVar15 = uVar12 + (*(uint *)(param_2 + 0xa100d08) & 0xff);
    uVar11 = ((*(uint *)(param_2 + 0xa100d08) & 0xffff) >> 8) + uVar14;
    if (0xfe < uVar11) {
      uVar11 = 0xff;
    }
    uVar8 = uVar8 | uVar11 << 8;
    if (uVar15 < 0x100) {
      uVar8 = uVar8 | uVar15;
    }
    else {
      uVar8 = uVar8 | 0xff;
    }
  }
  *(uint *)(param_2 + 0xa100d08) = uVar8;
  uVar8 = *(uint *)(param_2 + 0xa100008) & 0xffff0000;
  if (iVar9 == 9) {
    if (uVar19 < uVar17) {
      uVar19 = uVar17;
    }
    uVar19 = ((*(uint *)(param_2 + 0xa100008) & 0xffff) >> 8) + uVar19;
    if (0xfe < uVar19) {
      uVar19 = 0xff;
    }
    uVar8 = uVar8 | uVar19 << 8;
    if (uVar13 < uVar16) {
      uVar13 = uVar16;
    }
    uVar13 = uVar13 + (*(uint *)(param_2 + 0xa100008) & 0xff);
    if (uVar13 < 0x100) {
      uVar8 = uVar8 | uVar13;
    }
    else {
      uVar8 = uVar8 | 0xff;
    }
  }
  *(uint *)(param_2 + 0xa100008) = uVar8;
  uVar8 = *(uint *)(param_2 + 0xa100060) & 0xff00ffff;
  if (iVar9 == 9) {
    uVar14 = ((*(uint *)(param_2 + 0xa100060) & 0xffffff) >> 0x10) + uVar14;
    if (0xfe < uVar14) {
      uVar14 = 0xff;
    }
    uVar8 = uVar8 | uVar14 << 0x10;
  }
  *(uint *)(param_2 + 0xa100060) = uVar8;
  uVar8 = *(uint *)(param_2 + 0xa100024) & 0xffffff00;
  if (iVar9 == 9) {
    uVar12 = uVar12 + (*(uint *)(param_2 + 0xa100024) & 0xff);
    if (uVar12 < 0x100) {
      uVar8 = uVar8 | uVar12;
    }
    else {
      uVar8 = uVar8 | 0xff;
    }
  }
  *(uint *)(param_2 + 0xa100024) = uVar8;
  uVar8 = *(uint *)(param_2 + 0xa100584) & 0xffe0ffff;
  if (iVar9 == 9) {
    uVar10 = ((*(uint *)(param_2 + 0xa100584) & 0xffffff) >> 0x10) + uVar10;
    if (0x1e < uVar10) {
      uVar10 = 0x1f;
    }
    uVar8 = uVar8 | uVar10 << 0x10;
  }
  *(uint *)(param_2 + 0xa100584) = uVar8;
  puVar6 = DAT_000576d8/*=0xa920054*/;
  puVar3 = DAT_000576d4/*=0xaaa0000*/;
  *DAT_000576d4/*=0xaaa0000*/ = 0;
  uVar1 = *DAT_000576dc/*=0xa940004*/;
  uVar2 = *puVar6;
  *puVar3 = 1;
  uVar10 = *(uint *)(param_2 + 0xa100588) & 0xffc0ffff;
  if (iVar9 == 9) {
    uVar10 = uVar10 | (((uVar2 & 0x1f) >> 1) + ((uVar1 & 0xf) + 1 >> 3) * 4 + 0x15) * 0x10000;
  }
  *(uint *)(param_2 + 0xa100588) = uVar10;
  *(undefined4 *)(param_2 + DAT_000576e0/*=0xa110c80*/) = 1;
  do {
  } while (-1 < *piVar18 << 0x1f);
  *(uint *)(param_2 + iVar5) = *(uint *)(param_2 + iVar5) & 0xfffffffe;
  return;
}

//==== 0x576e4  0x576e4-0x57897 inclusive
void FUN_000576e4(int param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort uVar4;
  ushort *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  ushort *puVar11;
  
  puVar5 = DAT_0005789c/*=0xa92129c*/;
  *DAT_00057898/*=0xaaa0000*/ = 0;
  puVar10 = (uint *)(param_1 + 0x80);
  puVar11 = DAT_000578a0/*=0xa92009c*/;
  do {
    uVar4 = puVar11[1];
    *puVar10 = (puVar11[0x1000] & 0x7f) << 8 | (puVar11[0x2000] & 0x7f) << 0x10 | *puVar11 & 0x7f |
               (puVar11[0x3000] & 0x7f) << 0x18;
    puVar3 = puVar11 + 0x1001;
    puVar1 = puVar11 + 0x2001;
    puVar2 = puVar11 + 0x3001;
    puVar11 = puVar11 + 0x100;
    puVar10[9] = (*puVar3 & 0x7f) << 8 | (*puVar1 & 0x7f) << 0x10 | uVar4 & 0x7f |
                 (*puVar2 & 0x7f) << 0x18;
    puVar10 = puVar10 + 1;
  } while (puVar11 != puVar5);
  if (*(int *)(param_1 + 4) == 9) {
    FUN_0004b554(0,0x10,5);
    FUN_0004b554(1,0x10,5);
  }
  if (*(int *)(param_1 + 4) == 8) {
    FUN_0004b554(0,0xd,200);
    FUN_0004b554(1,0xd,200);
  }
  uVar6 = FUN_0004b5ac(param_1,0,0,0xe);
  iVar7 = FUN_0004b5ac(param_1,0,1,0xe);
  iVar8 = FUN_0004b5ac(param_1,1,0,0xe);
  iVar9 = FUN_0004b5ac(param_1,1,1,0xe);
  *(uint *)(param_1 + 200) = uVar6 | iVar8 << 0x10 | iVar7 << 8 | iVar9 << 0x18;
  if (*(int *)(param_1 + 4) == 9) {
    uVar6 = FUN_0004b5ac(param_1,0,0,0xf);
    iVar7 = FUN_0004b5ac(param_1,0,1,0xf);
    iVar8 = FUN_0004b5ac(param_1,1,0,0xf);
    iVar9 = FUN_0004b5ac(param_1,1,1,0xf);
    *(uint *)(param_1 + 0xcc) = uVar6 | iVar8 << 0x10 | iVar7 << 8 | iVar9 << 0x18;
  }
  if (*(int *)(param_1 + 4) == 9) {
    FUN_0004b554(0,0x10,4);
    FUN_0004b554(1,0x10,4);
  }
  if (*(int *)(param_1 + 4) == 8) {
    FUN_0004b554(0,0xd,0x80);
    FUN_0004b554(1,0xd,0x80);
  }
  *DAT_00057898/*=0xaaa0000*/ = 1;
  return;
}

//==== 0x57a4c  0x57a4c-0x57b5b inclusive
void FUN_00057a4c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  
  puVar5 = DAT_00057b78/*=0x2002020*/;
  puVar4 = DAT_00057b68/*=0xa020010*/;
  puVar3 = DAT_00057b64/*=0x2002c0c*/;
  puVar2 = DAT_00057b60/*=0x2002584*/;
  puVar1 = DAT_00057b5c/*=0x2002588*/;
  *DAT_00057b5c/*=0x2002588*/ = *DAT_00057b5c/*=0x2002588*/ & 0x7fffffff | 0x8000000;
  *puVar2 = *puVar2 & 0xfffffffe;
  *puVar2 = *puVar2 & 0xfffeffff;
  *puVar3 = *puVar3 & 0xfffeffff;
  *puVar3 = *puVar3 & 0xfffffffe;
  *puVar3 = *puVar3 | 0x10000;
  *puVar3 = *puVar3 | 1;
  *puVar4 = *puVar4 & 0xffffd9ff | 0x100;
  FUN_00048fa8();
  *puVar4 = *puVar4 & 0xfffffeff | 0x2600;
  puVar4 = DAT_00057b6c/*=0x2002c00*/;
  DataMemoryBarrier(0x1f);
  *puVar5 = *puVar5 & 0x7fffffff;
  *puVar4 = *puVar4 & 0x7fffffff | 0x8000000;
  FUN_00048d80(5);
  FUN_0004b7a0(*param_1,puVar5);
  puVar5 = DAT_00057b74/*=0x2002580*/;
  if (*DAT_00057b70/*=0x83620*/ == '\0') {
    uVar6 = *puVar4 & 0xffffffe0 | 3;
  }
  else {
    uVar6 = *puVar4 & 0xffffffe0 | 1;
  }
  *puVar4 = uVar6 | 0x8000000;
  *puVar4 = *puVar4 & 0xf8ffffff | 0x8000000;
  *puVar3 = *puVar3 | 0x10000;
  *puVar3 = *puVar3 | 1;
  *puVar1 = *puVar1 & 0xf8ffffff | 0x89000000;
  *puVar2 = *puVar2 | 0x10000;
  *puVar2 = *puVar2 | 1;
  *puVar5 = *puVar5 & 0xf8ffffff | 0xcb000000;
  *puVar4 = *puVar4 | 0x88000000;
  FUN_00048d80(5,puVar5,puVar4,param_4);
  return;
}

//==== 0x57b7c  0x578a4-0x57a1d inclusive
undefined4 FUN_00057b7c(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 unaff_r4;
  int iVar8;
  
  FUN_00057a4c();
  puVar2 = DAT_00057a24/*=0xa020014*/;
  puVar1 = DAT_00057a20/*=0xa020010*/;
  if ((*(uint *)(param_1 + 0x78) & 0x40) == 0) {
    iVar8 = 1;
  }
  else {
    iVar8 = 2;
  }
  *DAT_00057a20/*=0xa020010*/ = *DAT_00057a20/*=0xa020010*/ & 0xffffffeb;
  *puVar1 = *puVar1 & 0xffffffd7;
  if (iVar8 == 2) {
    uVar7 = *puVar1 & 0xffffc0c0 | 0x2728;
  }
  else {
    uVar7 = *puVar1 & 0xffffc0c0 | 0x2208;
  }
  *puVar1 = uVar7;
  puVar3 = DAT_00057a28/*=0xa02021c*/;
  uVar7 = *puVar2 & 0xfffffffc;
  if (iVar8 == 2) {
    uVar7 = uVar7 | 2;
  }
  if (*(int *)(param_1 + 4) == 9) {
    uVar7 = uVar7 | 1;
  }
  *puVar2 = uVar7;
  puVar4 = DAT_00057a2c/*=0xa020220*/;
  *puVar3 = 0x103;
  *puVar4 = 0x13ff;
  puVar4[1] = 0x103;
  *DAT_00057a30/*=0xa020228*/ = 0x13ff;
  *puVar3 = 0x107;
  puVar4[1] = 0x107;
  *DAT_00057a34/*=0x7010250*/ = *DAT_00057a34/*=0x7010250*/ | 1;
  FUN_00048d80(10000);
  FUN_00057238(param_1,0);
  if (*(int *)(param_1 + 4) == 9) {
    *DAT_00057a38/*=0xa110b84*/ = *DAT_00057a38/*=0xa110b84*/ | 1;
  }
  puVar3 = DAT_00057a3c/*=0xa110184*/;
  *DAT_00057a3c/*=0xa110184*/ = 2;
  FUN_000570d4(param_1,0,2,puVar3,unaff_r4);
  if (iVar8 == 2) {
    FUN_00057238(param_1,1);
    if (*(int *)(param_1 + 4) == 9) {
      *DAT_00057a40/*=0xa510b84*/ = *DAT_00057a40/*=0xa510b84*/ | 1;
    }
    puVar3 = DAT_00057a44/*=0xa510184*/;
    *DAT_00057a44/*=0xa510184*/ = 2;
    FUN_000570d4(param_1,1,2,puVar3,unaff_r4);
  }
  if (iVar8 == 2) {
    uVar7 = *puVar1 & 0xffffffef | 0x14;
  }
  else {
    uVar7 = *puVar1 & 0xffffffef | 4;
  }
  *puVar1 = uVar7;
  *puVar1 = *puVar1 & 0xfffffffe | 2;
  FUN_00048d80(1);
  *puVar1 = *puVar1 | 3;
  FUN_00048d80(1);
  iVar5 = FUN_00055990(param_1);
  uVar6 = 0;
  if (iVar5 != 0) {
    if ((*(int *)(param_1 + 4) == 9) && (FUN_00057310(param_1,0), iVar8 == 2)) {
      FUN_00057310(param_1,1);
    }
    FUN_0004b7ec(param_1,iVar8 + -1);
    FUN_000561a0(param_1);
    puVar1 = DAT_00057a48/*=0xa110180*/;
    if ((*(int *)(param_1 + 0x78) << 7 < 0) && (*DAT_00057a48/*=0xa110180*/ = *DAT_00057a48/*=0xa110180*/ | 0x11, iVar8 == 2)) {
      puVar1[0x100000] = puVar1[0x100000] | 0x11;
    }
    if (*(int *)(param_1 + 0x78) << 0x1d < 0) {
      FUN_000581b4(param_1,1,0);
    }
    uVar6 = 1;
  }
  return uVar6;
}

//==== 0x57b8e  0x57b8e-0x57dc7 inclusive
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00057b8e(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  if ((*(int *)(param_1 + 4) == 4) || (*(int *)(param_1 + 4) == 9)) {
    uVar6 = 0xb0eb;
  }
  else {
    uVar6 = 0x30eb;
  }
  *(undefined4 *)(param_1 + 0x18) = uVar6;
  uVar8 = *(uint *)(param_1 + 0x18);
  iVar10 = *(int *)(param_1 + 0x78);
  if ((*(uint *)(param_1 + 0x1c) & 0xf) == 0) {
    iVar9 = 2;
  }
  else {
    iVar9 = 1;
  }
  iVar1 = FUN_00057b7c(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = 0;
  puVar5 = (undefined4 *)&DAT_40000000;
  do {
    if (iVar1 << 0x1f < 0) {
      puVar3 = puVar5;
    }
    else {
      puVar3 = (undefined4 *)~(uint)puVar5;
    }
    *puVar5 = puVar3;
    DataSynchronizationBarrier(0xf);
    iVar1 = iVar1 + 1;
    puVar5 = puVar5 + 1;
  } while (iVar1 != 0x10);
  uVar4 = 0x40000000;
  iVar1 = 0;
  do {
    if (iVar1 << 0x1f < 0) {
      uVar7 = uVar4;
    }
    else {
      uVar7 = ~uVar4;
    }
    if (uVar7 != *(uint *)(uVar4 + 0x80)) {
      uVar4 = 0x40000000;
      iVar1 = 0;
      goto LAB_00057d0a;
    }
    iVar1 = iVar1 + 1;
    uVar4 = uVar4 + 4;
  } while (iVar1 != 0x10);
  iVar1 = 1;
  goto LAB_00057c08;
  while( true ) {
    iVar1 = iVar1 + 1;
    uVar4 = uVar4 + 4;
    if (iVar1 == 0x10) break;
LAB_00057d0a:
    if (iVar1 << 0x1f < 0) {
      uVar7 = uVar4;
    }
    else {
      uVar7 = ~uVar4;
    }
    if (uVar7 != *(uint *)(uVar4 + 0x100)) break;
  }
  if (*(int *)(param_1 + 4) == 4) {
    iVar1 = 2;
  }
  else if (*(int *)(param_1 + 4) == 9) {
    iVar1 = 2;
  }
  else {
    iVar1 = 0;
  }
LAB_00057c08:
  uVar4 = 7;
  iVar9 = (((uVar8 & 0xffff) >> 0xe) - ((iVar10 << 0x19) >> 0x1f)) + iVar9;
  do {
    uVar8 = 0x40000000;
    iVar10 = 0;
    while( true ) {
      if (iVar10 << 0x1f < 0) {
        uVar7 = uVar8;
      }
      else {
        uVar7 = ~uVar8;
      }
      if (*(uint *)(uVar8 + (1 << (iVar9 + uVar4 & 0xff))) != uVar7) break;
      iVar10 = iVar10 + 1;
      uVar8 = uVar8 + 4;
      if (iVar10 == 0x10) goto LAB_00057c42;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 != 0xb);
LAB_00057c42:
  iVar10 = 0;
  uVar8 = 0x40000000;
  do {
    if (iVar10 << 0x1f < 0) {
      uVar7 = uVar8;
    }
    else {
      uVar7 = ~uVar8;
    }
    if (*(uint *)((1 << (iVar9 + 0xdU & 0xff)) + uVar8) != uVar7) {
      iVar10 = 3;
      goto LAB_00057c6a;
    }
    iVar10 = iVar10 + 1;
    uVar8 = uVar8 + 4;
  } while (iVar10 != 0x10);
  iVar10 = 2;
LAB_00057c6a:
  if ((*(int *)(param_1 + 4) == 4) || (*(int *)(param_1 + 4) == 9)) {
    uVar6 = 0x6118;
  }
  else {
    uVar6 = 0x2118;
  }
  *(undefined4 *)(param_1 + 0x18) = uVar6;
  uVar8 = *(uint *)(param_1 + 0x18);
  iVar9 = *(int *)(param_1 + 0x78);
  if ((*(uint *)(param_1 + 0x1c) & 0xf) == 0) {
    iVar11 = 2;
  }
  else {
    iVar11 = 1;
  }
  iVar2 = FUN_00057b7c(param_1);
  if (iVar2 != 0) {
    iVar2 = 0;
    puVar5 = (undefined4 *)&DAT_40000000;
    do {
      if (iVar2 << 0x1f < 0) {
        puVar3 = puVar5;
      }
      else {
        puVar3 = (undefined4 *)~(uint)puVar5;
      }
      *puVar5 = puVar3;
      DataSynchronizationBarrier(0xf);
      iVar2 = iVar2 + 1;
      puVar5 = puVar5 + 1;
    } while (iVar2 != 0x10);
    iVar2 = 0xc;
    iVar11 = ((((uVar8 & 0xffff) >> 0xe) + 10) - ((iVar9 << 0x19) >> 0x1f)) + iVar11;
    do {
      uVar8 = 0x40000000;
      iVar9 = 0;
      while( true ) {
        if (iVar9 << 0x1f < 0) {
          uVar7 = uVar8;
        }
        else {
          uVar7 = ~uVar8;
        }
        if (*(uint *)((1 << (iVar11 + iVar2 & 0xffU)) + uVar8) != uVar7) break;
        iVar9 = iVar9 + 1;
        uVar8 = uVar8 + 4;
        if (iVar9 == 0x10) goto LAB_00057cee;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 0x11);
    if ((*(int *)(param_1 + 4) == 4) || (*(int *)(param_1 + 4) == 9)) {
      uVar6 = 0x6128;
    }
    else {
      uVar6 = 0x2128;
    }
    *(undefined4 *)(param_1 + 0x18) = uVar6;
    iVar9 = FUN_00057b7c(param_1);
    if (iVar9 != 0) {
      iVar9 = 0;
      puVar5 = (undefined4 *)&DAT_40000000;
      do {
        if (iVar9 << 0x1f < 0) {
          puVar3 = puVar5;
        }
        else {
          puVar3 = (undefined4 *)~(uint)puVar5;
        }
        *puVar5 = puVar3;
        DataSynchronizationBarrier(0xf);
        iVar9 = iVar9 + 1;
        puVar5 = puVar5 + 1;
      } while (iVar9 != 0x10);
      uVar8 = 0x40000000;
      if (_DAT_40000000 == -0x40000001) {
        iVar9 = 0;
        do {
          if (iVar9 << 0x1f < 0) {
            uVar7 = uVar8;
          }
          else {
            uVar7 = ~uVar8;
          }
          if (*(uint *)((1 << (iVar11 + 0x11U & 0xff)) + uVar8) != uVar7) goto LAB_00057cee;
          iVar9 = iVar9 + 1;
          uVar8 = uVar8 + 4;
        } while (iVar9 != 0x10);
        iVar2 = 0x12;
      }
LAB_00057cee:
      *(uint *)(param_1 + 0x18) = uVar4 | iVar1 << 0xe | iVar10 << 0xc | iVar2 << 4;
      return 1;
    }
  }
  return 0;
}

//==== 0x57dc8  0x57dc8-0x57e3b inclusive
undefined4 FUN_00057dc8(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  
  uVar4 = *(uint *)(param_1 + 0x6c);
  uVar5 = *(uint *)(param_1 + 0x78);
  if (*(int *)(param_1 + 4) - 7U < 2) {
    uVar2 = uVar4 | 0x21f0000;
  }
  else {
    uVar2 = uVar4 | 0x150000;
  }
  *(uint *)(param_1 + 0x6c) = uVar2;
  *(uint *)(param_1 + 0x78) = uVar5 | 1;
  if (*(int *)(param_1 + 4) == 4) {
    uVar3 = 0x60b7;
  }
  else {
    uVar3 = 0x20b7;
  }
  uVar6 = *(undefined4 *)(param_1 + 0x18);
  uVar2 = *(uint *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x18) = uVar3;
  *(undefined4 *)(param_1 + 0x1c) = 0x1001;
  iVar1 = FUN_00057b7c();
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x1c) = 1;
    iVar1 = FUN_00057b7c(param_1);
    if (iVar1 == 0) {
      return 0;
    }
    uVar3 = DAT_00057e40/*"[AUTO DEBUG]16 bit,1 ranks training success!\n"*/;
  }
  else {
    uVar3 = DAT_00057e3c/*"[AUTO DEBUG]16 bit,2 ranks training success!\n"*/;
  }
  FUN_0004993c(uVar3);
  *(uint *)(param_1 + 0x78) = uVar5;
  *(undefined4 *)(param_1 + 0x18) = uVar6;
  *(uint *)(param_1 + 0x6c) = uVar4;
  *(uint *)(param_1 + 0x1c) = uVar2 & 0xffff0000 | *(uint *)(param_1 + 0x1c);
  return 1;
}

//==== 0x57e44  0x57e44-0x57e99 inclusive
undefined4 FUN_00057e44(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0x78) & 4;
  if (uVar3 != 0) {
    *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) & 0xfffffffb;
  }
  if ((*(int *)(param_1 + 0x78) << 0x11 < 0) || (iVar1 = FUN_00057dc8(), iVar1 != 0)) {
    iVar1 = FUN_00057b8e(param_1);
    if (iVar1 != 0) {
      if (-1 < (int)(*(uint *)(param_1 + 0x78) << 0x10)) {
        *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) | 0x6003;
      }
      if (uVar3 != 0) {
        *(uint *)(param_1 + 0x78) = *(uint *)(param_1 + 0x78) | 4;
      }
      return 1;
    }
    uVar2 = DAT_00057ea0/*"scan dram size fail !\n"*/;
  }
  else {
    uVar2 = DAT_00057e9c/*"scan dram rank&width fail !\n"*/;
  }
  FUN_0004993c(uVar2);
  return 0;
}

//==== 0x57ea4  0x57ea4-0x57eaf inclusive
void FUN_00057ea4(undefined4 param_1)

{
  *(undefined4 *)(*DAT_00057eb0/*=0x8362c*/ * 0x10 + DAT_00057eb4/*=0xa021d0c*/) = param_1;
  return;
}

//==== 0x57eb8  0x57eb8-0x57f37 inclusive
void FUN_00057eb8(uint param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5,
                 uint param_6,undefined4 param_7,int param_8,uint param_9,uint param_10)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_00057f38/*=0x8362c*/;
  *(uint *)((*(int *)(DAT_00057f38/*=0x8362c*/ + 4) + 0xa02180) * 0x10) =
       (param_1 & 3) << 0x11 | param_3 >> 1 & 0x8000 | (param_2 & 1) << 0x10 | param_3 & 0x7fff |
       (param_10 & 1) << 0x19 | (param_6 & 1) << 0x1a | (param_10 & 2) << 0x17 | param_8 << 0x1f |
       (param_9 & 1) << 0x1c;
  *(undefined4 *)(*(int *)(iVar1 + 4) * 0x10 + DAT_00057f3c/*=0xa021804*/) = param_4;
  iVar2 = DAT_00057f40/*=0xa021808*/;
  *(undefined4 *)(*(int *)(iVar1 + 4) * 0x10 + DAT_00057f40/*=0xa021808*/) = param_5;
  if (param_6 != 0) {
    *(undefined4 *)(*(int *)(iVar1 + 4) * 0x10 + iVar2 + 4) = param_7;
  }
  *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
  return;
}

//==== 0x57f44  0x57f44-0x57fb9 inclusive
void FUN_00057f44(uint param_1,uint param_2,uint param_3,uint param_4,undefined4 param_5,int param_6
                 )

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = DAT_00057fbc/*=0x8362c*/;
  if (param_3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (*DAT_00057fbc/*=0x8362c*/ & 0xf) << 0x14;
  }
  *(uint *)((DAT_00057fbc/*=0x8362c*/[1] + 0xa02180) * 0x10) =
       (param_3 & 1) << 0x1b | (param_4 & 1) << 0x1a | 0x80000 | param_6 << 0x1f | uVar2;
  *(undefined4 *)(puVar1[1] * 0x10 + DAT_00057fc0/*=0xa021808*/) = 0;
  if (param_4 != 0) {
    *(undefined4 *)(puVar1[1] * 0x10 + DAT_00057fc4/*=0xa02180c*/) = param_5;
  }
  if (param_3 == 0) {
    *(uint *)(puVar1[1] * 0x10 + DAT_00057fc8/*=0xa021804*/) = (param_1 & 1) << 0x18 | param_2 & 0xffffff;
  }
  else {
    *puVar1 = *puVar1 + 1;
  }
  puVar1[1] = puVar1[1] + 1;
  return;
}

//==== 0x57fcc  0x57fcc-0x58039 inclusive
void FUN_00057fcc(uint param_1,uint param_2,uint param_3,undefined4 param_4,uint param_5,
                 undefined4 param_6,int param_7)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = DAT_00058040/*=0xa021808*/;
  puVar1 = DAT_0005803c/*=0x8362c*/;
  *(uint *)((DAT_0005803c/*=0x8362c*/[1] + 0xa02180) * 0x10) =
       (*DAT_0005803c/*=0x8362c*/ & 0xf) << 0x14 | 0x8000000 | param_3 & 0x7fff | (param_2 & 1) << 0x10 |
       param_3 >> 1 & 0x8000 | (param_1 & 3) << 0x11 | param_7 << 0x1f | (param_5 & 1) << 0x1a;
  *(undefined4 *)(puVar1[1] * 0x10 + iVar2) = param_4;
  if (param_5 != 0) {
    *(undefined4 *)(puVar1[1] * 0x10 + DAT_00058044/*=0xa02180c*/) = param_6;
  }
  puVar1[1] = puVar1[1] + 1;
  *puVar1 = *puVar1 + 1;
  return;
}

//==== 0x58048  0x58048-0x58081 inclusive
void FUN_00058048(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0) {
    *(undefined4 *)((DAT_00058088/*=0xa021d0*/ + *DAT_00058084/*=0x8362c*/) * 0x10) = param_1;
    return;
  }
  if (param_2 == 1) {
    iVar2 = *DAT_00058084/*=0x8362c*/;
    iVar1 = DAT_0005808c/*=0xa021d04*/;
  }
  else {
    if (param_2 != 2) {
      if (param_2 == 3) {
        FUN_00057ea4();
        return;
      }
      return;
    }
    iVar2 = *DAT_00058084/*=0x8362c*/;
    iVar1 = DAT_00058090/*=0xa021d08*/;
  }
  *(undefined4 *)(iVar2 * 0x10 + iVar1) = param_1;
  return;
}

//==== 0x58094  0x58094-0x58199 inclusive
void FUN_00058094(uint param_1,undefined4 param_2,undefined4 param_3,uint param_4,byte param_5,
                 uint param_6,uint param_7)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = DAT_0005819c/*=0x8362c*/;
  iVar4 = 0;
  do {
    iVar3 = iVar4;
    if (param_1 == 0xd) {
      puVar1[2] = *puVar1;
      if (iVar4 == 2) {
        uVar2 = param_5 | 0xd00;
      }
      else {
        uVar2 = param_4;
        if (iVar4 != 3) {
          if (iVar4 == 1) {
            uVar2 = param_6;
          }
          else {
            iVar3 = 0;
            uVar2 = param_7;
          }
        }
        uVar2 = uVar2 & 0xff | 0xd00;
      }
LAB_000580cc:
      FUN_00058048(uVar2,iVar3);
    }
    else if (param_1 == 0x10) {
      puVar1[2] = *puVar1;
      if (iVar4 == 2) {
        uVar2 = param_5 | 0x1000;
      }
      else {
        uVar2 = param_4;
        if (iVar4 != 3) {
          if (iVar4 == 1) {
            uVar2 = param_6;
          }
          else {
            iVar3 = 0;
            uVar2 = param_7;
          }
        }
        uVar2 = uVar2 & 0xff | 0x1000;
      }
      goto LAB_000580cc;
    }
    iVar4 = iVar4 + 1;
    if (iVar4 == 4) {
      DAT_0005819c/*=0x8362c*/[3] = DAT_0005819c/*=0x8362c*/[1];
      FUN_00057fcc(1,1,DAT_000581a4/*=0x10084*/,DAT_000581a0/*=0xfff80000*/,param_2,param_3,0);
      FUN_00057eb8(1,1,DAT_000581ac/*=0x10080*/,(param_1 & 0xf) << 0xc | 0xf0,DAT_000581a8/*=0xffff000c*/,param_2,param_3,0,0,0
                  );
      FUN_00057eb8(1,1,DAT_000581ac/*=0x10080*/,0x80000000,0x7fffffff,param_2,param_3,0,0,0);
      FUN_00057eb8(1,0,DAT_000581b0/*=0x10090*/,0,0xfffffffe,param_2,param_3,0,0,0);
      return;
    }
  } while( true );
}

//==== 0x581b4  0x581b4-0x58557 inclusive
void FUN_000581b4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  puVar2 = DAT_00058598/*=0x8362c*/;
  iVar4 = *(int *)(param_1 + 4);
  *DAT_00058598/*=0x8362c*/ = 0;
  puVar2[1] = 0;
  FUN_00057eb8(1,1,DAT_00058558/*=0x10180*/,0,0xffffff00,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_0005855c/*=0x10184*/,0,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_00058560/*=0x10014*/,1,0xfffffff8,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_00058560/*=0x10014*/,1,0xfffffff8,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_00058560/*=0x10014*/,1,0xfffffff8,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058564/*=0x10b84*/,2,0xfffffffd,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_00058568/*=0x10b88*/,0x36000000,0xc9ffffff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_0005856c/*=0x10100*/,4,0xfffffffb,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058570/*=0x10b8c*/,0x20000,0xfffdffff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_00058574/*=0x10b90*/,0,0xfffdffff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058578/*=0x10518*/,0,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_0005857c/*=0x10280*/,0x80000000,0x7fffffff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058580/*=0x10500*/,0,0xffffffef,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_00058584/*=0x10514*/,0,0xfffffffd,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058580/*=0x10500*/,0,0xffefffff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_00058584/*=0x10514*/,0,0xfffffffb,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058558/*=0x10180*/,0,0xfffffdff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058558/*=0x10180*/,0x8800,0xffff77ff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_00058560/*=0x10014*/,0x1000,0xffff8fff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058564/*=0x10b84*/,1,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_00058568/*=0x10b88*/,0x30000000,0xcfffffff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058588/*=0x10c80*/,0,0xfffffffe,param_3,param_4,0,0,0);
  uVar5 = DAT_0005858c/*=0x10510*/;
  puVar2[4] = puVar2[1];
  FUN_00057eb8(1,1,uVar5,0,0xffffe0ff,param_3,param_4,0,1,0);
  FUN_00057eb8(1,1,DAT_00058588/*=0x10c80*/,1,0xfffffffe,param_3,param_4,0,0,0);
  if (iVar4 == 8) {
    FUN_00058094(0xd,param_3,param_4,200,200,200,200);
    FUN_00057eb8(1,1,DAT_00058558/*=0x10180*/,0,0xffff7fff,param_3,param_4,0,0,0);
    FUN_00057eb8(1,0,DAT_00058560/*=0x10014*/,0x2000,0xffff8fff,param_3,param_4,0,0,0);
  }
  else if (iVar4 == 9) {
    uVar5 = *DAT_00058ba4/*=0x606bc*/;
    FUN_00058094(0x10,param_3,param_4,uVar5,uVar5,uVar5,uVar5);
  }
  FUN_00057eb8(1,1,DAT_00058588/*=0x10c80*/,0,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_0005858c/*=0x10510*/,0,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058588/*=0x10c80*/,1,0xfffffffe,param_3,param_4,0,0,0);
  piVar1 = DAT_00058590/*=0x606bc*/;
  FUN_00057eb8(1,1,DAT_00058594/*=0x10508*/,0,0xffff7fff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058588/*=0x10c80*/,0,0xfffffffe,param_3,param_4,0,0,0);
  iVar3 = *piVar1;
  puVar2[5] = *puVar2;
  FUN_00058048(iVar3 << 0xe,0);
  FUN_00058048(*piVar1 << 0xe,1);
  FUN_00058048(*piVar1 << 0xe,2);
  FUN_00057ea4(*piVar1 << 0xe);
  FUN_00057fcc(1,1,DAT_00058960/*=0x10510*/,0xffff3fff,param_3,param_4,0);
  FUN_00058048(0,0);
  FUN_00058048(1);
  FUN_00058048(2);
  FUN_00057ea4(3);
  FUN_00057fcc(1,1,DAT_00058964/*=0x10008*/,0xffffffe0,param_3,param_4,0);
  FUN_00057eb8(1,1,DAT_00058960/*=0x10510*/,0x20,0xffffffdf,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058968/*=0x10c80*/,1,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_0005896c/*=0x10514*/,0,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00058048((*(uint *)(param_1 + 0x60) & 0x1f) << 0x13 | 0x501,0);
  FUN_00058048((*(uint *)(param_1 + 0x60) & 0x1f00) << 0xb | 0xd09,1);
  FUN_00058048((*(ushort *)(param_1 + 0x62) & 0x1f) << 0x13 | 0x1511,2);
  FUN_00057ea4((*(byte *)(param_1 + 99) & 0x1f) << 0x13 | 0x1d19);
  FUN_00057f44(0,0,1,1,200,0);
  FUN_00057eb8(1,1,DAT_00058970/*=0x10208*/,0x10,0xffffffef,1,200,0,0,0);
  FUN_00057eb8(1,1,DAT_00058968/*=0x10c80*/,0,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058960/*=0x10510*/,0,0xffffffdf,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058968/*=0x10c80*/,1,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058974/*=0x10508*/,0,0xffff7fff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_0005896c/*=0x10514*/,1,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058968/*=0x10c80*/,0,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058960/*=0x10510*/,1,0xfffffffe,1,200,0,0,0);
  FUN_00057eb8(1,1,DAT_00058978/*=0x10288*/,1,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058968/*=0x10c80*/,1,0xfffffffe,param_3,param_4,0,0,0);
  if (iVar4 == 8) {
    FUN_00057eb8(1,1,DAT_0005897c/*=0x10180*/,0x8000,0xffff77ff,param_3,param_4,0,0,0);
    FUN_00057eb8(1,0,DAT_00058980/*=0x10014*/,0x3000,0xffff8fff,param_3,param_4,0,0,0);
  }
  FUN_00057eb8(1,1,DAT_00058984/*=0x10b8c*/,0x10000,0xfffeffff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_00058988/*=0x10b90*/,0,0xfffeffff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058968/*=0x10c80*/,0,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058978/*=0x10288*/,0,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058968/*=0x10c80*/,1,0xfffffffe,param_3,param_4,0,0,0);
  if (iVar4 == 9) {
    FUN_00057eb8(1,0,DAT_0005898c/*=0x10090*/,0,0xfffffffe,param_3,param_4,0,0,0);
    uVar5 = DAT_00058998/*=0xfff80000*/;
    FUN_00057eb8(1,1,DAT_00058990/*=0x10080*/,0x30,0,param_3,param_4,0,0,0);
    FUN_00057eb8(1,1,DAT_00058994/*=0x10084*/,0,uVar5,param_3,param_4,0,0,0);
    FUN_00057eb8(1,1,DAT_00058990/*=0x10080*/,0x80000000,0x7fffffff,param_3,param_4,0,0,0);
    FUN_00057eb8(1,0,DAT_00058990/*=0x10080*/,0,0x7fffffff,param_3,param_4,0,0,0);
    FUN_00057eb8(1,0,DAT_0005898c/*=0x10090*/,0,0xfffffffe,param_3,param_4,0,0,0);
    FUN_00057eb8(1,1,DAT_00058990/*=0x10080*/,0x30,0,param_3,param_4,0,0,0);
    FUN_00057eb8(1,1,DAT_00058994/*=0x10084*/,0xb12,uVar5,param_3,param_4,0,0,0);
    FUN_00057eb8(1,1,DAT_00058b7c/*=0x10080*/,0x80000000,0x7fffffff,param_3,param_4,0,0,0);
    FUN_00057eb8(1,0,DAT_00058b7c/*=0x10080*/,0,0x7fffffff,param_3,param_4,0,0,0);
    FUN_00057eb8(1,0,DAT_00058b80/*=0x10090*/,0,0xfffffffe,param_3,param_4,0,0,0);
    FUN_00057eb8(1,1,DAT_00058b7c/*=0x10080*/,0x30,0,param_3,param_4,0,0,0);
    FUN_00057eb8(1,1,DAT_00058b84/*=0x10084*/,0,uVar5,param_3,param_4,0,0,0);
    FUN_00057eb8(1,1,DAT_00058b7c/*=0x10080*/,0x80000000,0x7fffffff,param_3,param_4,0,0,0);
    FUN_00057eb8(1,0,DAT_00058b7c/*=0x10080*/,0,0x7fffffff,param_3,param_4,0,0,0);
    FUN_00057eb8(1,1,DAT_00058b88/*=0x10180*/,0,0xfffff7ff,param_3,param_4,0,0,0);
  }
  FUN_00057eb8(1,1,DAT_00058b88/*=0x10180*/,0,0xffff7fff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,0,DAT_00058b8c/*=0x10014*/,0,0xffff8fff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058b90/*=0x10500*/,0,0xffefffef,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058b94/*=0x10b84*/,0,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058b94/*=0x10b84*/,0,0xfffffffd,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058b98/*=0x10100*/,0,0xfffffffb,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058b9c/*=0x10518*/,0,0xfffffffe,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058ba0/*=0x10280*/,0x80000000,0x7fffffff,param_3,param_4,0,0,0);
  FUN_00057eb8(1,1,DAT_00058b88/*=0x10180*/,0,0xfffffdff,param_3,param_4,1,0,0);
  return;
}

//==== 0x5b2dc  0x5b2dc-0x5b30f inclusive
void FUN_0005b2dc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  int iVar4;
  
  uVar3 = DAT_0005b314/*=0x5f21c*/;
  uVar2 = DAT_0005b310/*"\n0x%x : "*/;
  iVar4 = 0;
  FUN_0004993c(DAT_0005b31c/*"dump %s registers:"*/,DAT_0005b318/*"info"*/);
  do {
    if (iVar4 == 0) {
      FUN_0004993c(uVar2,param_1);
    }
    puVar1 = (undefined4 *)(param_1 + iVar4);
    iVar4 = iVar4 + 4;
    FUN_0004993c(uVar3,*puVar1);
  } while (iVar4 != 0x10);
  FUN_0004993c(DAT_0005b320/*=0x604ba*/,extraout_r1,extraout_r2,param_4);
  return;
}

//==== 0x5b324  0x5b324-0x5b329 inclusive
void FUN_0005b324(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0005b328. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1 + 0xa8))();
  return;
}

//==== 0x5b948  0x5b948-0x5b9bb inclusive
int FUN_0005b948(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  undefined4 local_38;
  undefined4 uStack_34;
  int local_30;
  uint local_2c;
  undefined4 local_1c;
  
  uVar1 = DAT_0005b9bc/*=0xfdf94080*/;
  local_38 = 0xd;
  uStack_34 = 0x15;
  local_30 = *(int *)(param_1 + 0x80) << 0x10;
  local_1c = 0;
  do {
    iVar2 = FUN_0005b324(param_1,&local_38,0);
    if (iVar2 != 0) {
      FUN_000498e4(DAT_0005b9c0/*"[mmc]: mmc %u Send status failed\n"*/,*(undefined4 *)(param_1 + 0x30));
      return iVar2;
    }
    if ((int)(local_2c << 0x17) < 0) {
      if (param_2 == 0) {
        FUN_000498e4(DAT_0005b9c8/*"[mmc]: mmc %u Timeout waiting card ready\n"*/,*(undefined4 *)(param_1 + 0x30));
        return -0x13;
      }
      return 0;
    }
    FUN_00048da4(1);
    if ((local_2c & uVar1) != 0) {
      FUN_000498e4(DAT_0005b9c4/*"[mmc]: mmc %u Status Error: 0x%08X\n"*/,*(undefined4 *)(param_1 + 0x30));
      return -0x12;
    }
    bVar3 = param_2 != 0;
    param_2 = param_2 + -1;
  } while (bVar3);
  return 0;
}

//==== 0x5b9cc  0x5b9cc-0x5b9f9 inclusive
undefined4 FUN_0005b9cc(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 local_c;
  
  if ((*(int *)(param_1 + 0x104) == 2) || (*(int *)(param_1 + 0x104) == 4)) {
    uVar1 = 0;
  }
  else {
    local_28 = 0x10;
    uStack_24 = 0x15;
    local_c = 0;
    local_20 = param_2;
    uVar1 = FUN_0005b324(param_1,&local_28);
  }
  return uVar1;
}

//==== 0x5b9fc  0x5b9fc-0x5ba11 inclusive
int FUN_0005b9fc(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_0005ba14/*=0x83648*/ + param_1 * 4);
  if (iVar1 == 0) {
    FUN_000498e4(DAT_0005ba18/*"[mmc]: MMC Device %d not found\n"*/,param_1);
  }
  return iVar1;
}

//==== 0x5ba1c  0x5ba1c-0x5ba9f inclusive
uint FUN_0005ba1c(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  int iStack_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  int local_1c;
  
  if (param_4 < 2) {
    local_38 = 0x11;
  }
  else {
    local_38 = 0x12;
  }
  iStack_3c = *(int *)(param_1 + 0x90);
  if (*(int *)(param_1 + 0x40) == 0) {
    param_3 = iStack_3c * param_3;
  }
  local_34 = 0x15;
  local_1c = 0;
  local_44 = 1;
  local_48 = param_2;
  local_40 = param_4;
  local_30 = param_3;
  iVar1 = FUN_0005b324(param_1,&local_38,&local_48);
  if (iVar1 == 0) {
    if (1 < param_4) {
      local_38 = 0xc;
      local_34 = 0x1d;
      local_30 = iVar1;
      local_1c = iVar1;
      iVar1 = FUN_0005b324(param_1,&local_38,0);
      if (iVar1 != 0) {
        FUN_000498e4(DAT_0005baa4/*"[mmc]: mmc %u fail to send stop cmd\n"*/,*(undefined4 *)(param_1 + 0x30));
        return 0;
      }
      FUN_0005b948(param_1,1000);
    }
  }
  else {
    param_4 = 0;
    FUN_000498e4(DAT_0005baa0/*"[mmc]: mmc %u  read blcok failed\n"*/,*(undefined4 *)(param_1 + 0x30));
  }
  return param_4;
}

//==== 0x5baa8  0x5baa8-0x5bb2d inclusive
uint FUN_0005baa8(undefined4 param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar3 = param_4;
  iVar1 = FUN_0005b9fc();
  if (param_3 == 0) {
    FUN_000498e4(DAT_0005bb30/*"[mmc]: mmc %u blkcnt should not be 0\n"*/,*(undefined4 *)(iVar1 + 0x30));
    return 0;
  }
  if (iVar1 == 0) {
    uVar2 = DAT_0005bb34/*"[mmc]: Can not find mmc dev %d\n"*/;
  }
  else {
    if (*(uint *)(iVar1 + 0xec) < param_3 + param_2) {
      FUN_000498e4(DAT_0005bb38/*"[mmc]: mmc %u: block number 0x%x exceeds max(0x%x)\n"*/,*(undefined4 *)(iVar1 + 0x30));
      return 0;
    }
    iVar3 = FUN_0005b9cc(iVar1,*(undefined4 *)(iVar1 + 0x90),param_3 + param_2,
                         *(uint *)(iVar1 + 0xec),iVar3);
    if (iVar3 == 0) {
      uVar6 = param_3;
      while( true ) {
        uVar5 = *(uint *)(iVar1 + 0xe8);
        if (uVar6 <= *(uint *)(iVar1 + 0xe8)) {
          uVar5 = uVar6;
        }
        uVar4 = FUN_0005ba1c(iVar1,param_4,param_2);
        if (uVar4 != uVar5) break;
        uVar6 = uVar6 - uVar4;
        param_2 = param_2 + uVar4;
        param_4 = *(int *)(iVar1 + 0x90) * uVar4 + param_4;
        if (uVar6 == 0) {
          return param_3;
        }
      }
      param_1 = *(undefined4 *)(iVar1 + 0x30);
      uVar2 = DAT_0005bb40/*"[mmc]: mmc %u block read failed\n"*/;
    }
    else {
      param_1 = *(undefined4 *)(iVar1 + 0x30);
      uVar2 = DAT_0005bb3c/*"[mmc]: mmc %u Set block len failed\n"*/;
    }
  }
  FUN_000498e4(uVar2,param_1);
  return 0;
}

//==== 0x5bb44  0x5bb44-0x5bb7b inclusive
int FUN_0005bb44(int param_1)

{
  int iVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 local_14;
  
  FUN_00048da4(1);
  local_30 = 0;
  local_2c = 0;
  uStack_28 = 0;
  local_14 = 0;
  iVar1 = FUN_0005b324(param_1,&local_30);
  if (iVar1 == 0) {
    FUN_00048da4(2);
  }
  else {
    FUN_000498e4(DAT_0005bb7c/*"[mmc]: mmc %u go idle failed\n"*/,*(undefined4 *)(param_1 + 0x30));
  }
  return iVar1;
}

//==== 0x5bb80  0x5bb80-0x5bc61 inclusive
int FUN_0005bb80(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  bool bVar7;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  uint local_34;
  undefined4 local_24;
  
  uVar1 = DAT_0005bc78/*=0xff8000*/;
  iVar4 = DAT_0005bc70/*=0x20020*/;
  iVar6 = 1000;
  do {
    local_40 = 0x37;
    local_3c = 0x15;
    local_38 = 0;
    local_24 = 0;
    iVar2 = FUN_0005b324(param_1,&local_40);
    if (iVar2 != 0) {
      uVar5 = *(undefined4 *)(param_1 + 0x30);
      uVar3 = DAT_0005bc64/*"[mmc]: mmc %u send app cmd failed\n"*/;
LAB_0005bbb2:
      FUN_000498e4(uVar3,uVar5);
      return iVar2;
    }
    local_40 = 0x29;
    local_3c = 1;
    local_38 = 0;
    if (-1 < *(int *)(param_1 + 0x50) << 0x1b) {
      local_38 = uVar1 & *(uint *)(param_1 + 0x24);
    }
    if (*(int *)(param_1 + 0x28) == iVar4) {
      local_38 = local_38 | 0x40000000;
    }
    iVar2 = FUN_0005b324(param_1,&local_40,0);
    if (iVar2 != 0) {
      uVar5 = *(undefined4 *)(param_1 + 0x30);
      uVar3 = DAT_0005bc68/*"[mmc]: mmc %u send cmd41 failed\n"*/;
      goto LAB_0005bbb2;
    }
    FUN_00048da4(1);
    if ((int)local_34 < 0) {
      if (iVar6 != 0) {
        if (*(int *)(param_1 + 0x28) != DAT_0005bc70/*=0x20020*/) {
          *(int *)(param_1 + 0x28) = DAT_0005bc70/*=0x20020*/ + -0x10;
        }
        if (*(int *)(param_1 + 0x50) << 0x1b < 0) {
          local_40 = 0x3a;
          local_3c = 1;
          local_38 = 0;
          local_24 = 0;
          iVar4 = FUN_0005b324(param_1,&local_40);
          if (iVar4 != 0) {
            FUN_000498e4(DAT_0005bc74/*"[mmc]: mmc %u spi read ocr failed\n"*/,*(undefined4 *)(param_1 + 0x30));
            return iVar4;
          }
        }
        *(uint *)(param_1 + 0x54) = local_34;
        *(uint *)(param_1 + 0x40) = (local_34 & 0x7fffffff) >> 0x1e;
        *(undefined4 *)(param_1 + 0x80) = 0;
        return 0;
      }
      goto LAB_0005bc06;
    }
    bVar7 = iVar6 == 0;
    iVar6 = iVar6 + -1;
    if (bVar7) {
LAB_0005bc06:
      FUN_000498e4(DAT_0005bc6c/*"[mmc]: mmc %u wait card init failed\n"*/,*(undefined4 *)(param_1 + 0x30));
      return -0x11;
    }
  } while( true );
}

//==== 0x5bc7c  0x5bc7c-0x5bd5d inclusive
int FUN_0005bc7c(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  undefined4 local_40;
  undefined4 uStack_3c;
  uint local_38;
  uint local_34;
  int local_24;
  
  FUN_0005bb44();
  local_40 = 1;
  uStack_3c = 1;
  local_38 = 0;
  local_24 = 0;
  iVar2 = FUN_0005b324(param_1,&local_40);
  uVar1 = DAT_0005bd68/*=0x7fff80*/;
  iVar3 = iVar2;
  if (iVar2 == 0) {
    iVar4 = 10000;
    FUN_00048da4(1);
    do {
      local_40 = 1;
      uStack_3c = 1;
      if (*(int *)(param_1 + 0x50) << 0x1b < 0) {
        local_38 = 0;
      }
      else {
        local_38 = local_34 & uVar1 & *(uint *)(param_1 + 0x24) | local_34 & 0x60000000;
      }
      if (*(int *)(param_1 + 0x50) << 0x1a < 0) {
        local_38 = local_38 | 0x40000000;
      }
      local_24 = iVar2;
      iVar3 = FUN_0005b324(param_1,&local_40,0);
      if (iVar3 != 0) goto LAB_0005bca0;
      FUN_00048da4(1);
      if ((int)local_34 < 0) {
        if (iVar4 != 0) {
          if (*(int *)(param_1 + 0x50) << 0x1b < 0) {
            local_40 = 0x3a;
            uStack_3c = 1;
            local_38 = iVar3;
            local_24 = iVar3;
            iVar3 = FUN_0005b324(param_1,&local_40,0);
            if (iVar3 != 0) {
              return iVar3;
            }
          }
          *(undefined4 *)(param_1 + 0x28) = 0x10000;
          *(uint *)(param_1 + 0x54) = local_34;
          *(uint *)(param_1 + 0x40) = (local_34 & 0x7fffffff) >> 0x1e;
          *(undefined4 *)(param_1 + 0x80) = 1;
          return 0;
        }
        break;
      }
      bVar5 = iVar4 != 0;
      iVar4 = iVar4 + -1;
    } while (bVar5);
    iVar3 = -0x11;
    FUN_000498e4(DAT_0005bd64/*"[mmc]: mmc %u wait for mmc init failed\n"*/,*(undefined4 *)(param_1 + 0x30));
  }
  else {
LAB_0005bca0:
    FUN_000498e4(DAT_0005bd60/*"[mmc]: mmc %u send op cond failed\n"*/,*(undefined4 *)(param_1 + 0x30));
  }
  return iVar3;
}

//==== 0x5bd6c  0x5bd6c-0x5bda7 inclusive
int FUN_0005bd6c(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 local_14;
  
  local_30 = 8;
  uStack_2c = 0x15;
  local_28 = 0;
  local_14 = 0;
  local_38 = 1;
  uStack_34 = 0x200;
  local_3c = 1;
  local_40 = param_2;
  iVar1 = FUN_0005b324(param_1,&local_30,&local_40);
  if (iVar1 != 0) {
    FUN_000498e4(DAT_0005bda8/*"[mmc]: mmc %u send ext csd failed\n"*/,*(undefined4 *)(param_1 + 0x30));
  }
  return iVar1;
}

//==== 0x5bdac  0x5bdac-0x5bdb7 inclusive
undefined4 FUN_0005bdac(int param_1)

{
  undefined4 uVar1;
  
  if (*(code **)(param_1 + 0xb4) == (code *)0x0) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0005bdb2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(param_1 + 0xb4))();
  return uVar1;
}

//==== 0x5bdc8  0x5bdc8-0x5be17 inclusive
int FUN_0005bdc8(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 local_30;
  undefined4 uStack_2c;
  uint local_28;
  undefined4 local_14;
  
  local_28 = param_4 << 8 | 0x3000000U | param_3 << 0x10;
  local_30 = 6;
  uStack_2c = 0x1d;
  local_14 = 0;
  iVar1 = FUN_0005b324(param_1,&local_30);
  if (iVar1 != 0) {
    FUN_000498e4(DAT_0005be18/*"[mmc]: mmc %u switch failed\n"*/,*(undefined4 *)(param_1 + 0x30));
  }
  iVar1 = FUN_0005bdac(param_1);
  if (iVar1 == 0) {
    FUN_0005b948(param_1,1000);
  }
  else {
    FUN_000498e4(DAT_0005be1c/*"[mmc]: mmc_switch: update clock failed after send cmd6\n"*/);
  }
  return iVar1;
}

//==== 0x5bed0  0x5be20-0x5bebf inclusive
int FUN_0005bed0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_218 [185];
  char local_15f;
  byte local_154;
  
  *(undefined4 *)(param_1 + 0x4c) = 0;
  if ((*(int *)(param_1 + 0x50) << 0x1b < 0) || (*(uint *)(param_1 + 0x28) <= DAT_0005beec/*=0x1003f*/)) {
    return 0;
  }
  *(undefined4 *)(param_1 + 0x4c) = 0xc;
  iVar1 = FUN_0005bd6c(param_1,auStack_218);
  uVar3 = DAT_0005becc/*"[mmc]: retry mmc switch(cmd6)\n"*/;
  if (iVar1 == 0) {
    iVar4 = 6;
    do {
      iVar1 = FUN_0005bdc8(param_1,1,0xb9);
      if (iVar1 == 0) {
        iVar1 = FUN_0005bd6c(param_1,auStack_218);
        if (iVar1 == 0) {
          if (local_15f == '\0') {
            return 0;
          }
          if ((local_154 & 3) == 0) {
            *(undefined4 *)(param_1 + 0x104) = 0;
            *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 1;
            return 0;
          }
          if ((local_154 & 0xc) == 0) {
            uVar3 = 1;
          }
          else {
            *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x40;
            uVar3 = 2;
          }
          *(undefined4 *)(param_1 + 0x104) = uVar3;
          *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 3;
          return 0;
        }
        uVar2 = *(undefined4 *)(param_1 + 0x30);
        uVar3 = DAT_0005bec8/*"[mmc]: mmc %u send ext csd faild\n"*/;
        goto LAB_0005be3c;
      }
      FUN_000498e4(uVar3);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    uVar2 = *(undefined4 *)(param_1 + 0x30);
    uVar3 = DAT_0005bec4/*"[mmc]: mmc %u change to hs failed\n"*/;
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x30);
    uVar3 = DAT_0005bec0/*"[mmc]: mmc %u get ext csd failed\n"*/;
  }
LAB_0005be3c:
  FUN_000498e4(uVar3,uVar2);
  return iVar1;
}

//==== 0x5bef0  0x5bef0-0x5bf33 inclusive
void FUN_0005bef0(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  uint local_20;
  undefined4 local_c;
  
  local_28 = 6;
  uStack_24 = 0x15;
  local_20 = (param_2 << 0x1f | 0xffffffU) & ~(0xf << (param_3 << 2 & 0xffU)) |
             param_4 << (param_3 << 2 & 0xffU);
  local_c = 0;
  local_38 = param_5;
  local_30 = 1;
  uStack_2c = 0x40;
  local_34 = 1;
  FUN_0005b324(param_1,&local_28,&local_38);
  return;
}

//==== 0x5bf34  0x5bf34-0x5c05f inclusive
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
        iVar1 = DAT_0005c068/*=0x20010*/;
        if (uVar4 == 1) {
          uVar2 = DAT_0005c06c/*=0x2001a*/;
LAB_0005bfe0:
          *(undefined4 *)(param_1 + 0x28) = uVar2;
        }
        else {
          if (uVar4 == 2) {
            uVar2 = DAT_0005c070/*=0x20020*/;
            goto LAB_0005bfe0;
          }
          *(int *)(param_1 + 0x28) = DAT_0005c068/*=0x20010*/;
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
    uVar2 = DAT_0005c064/*"[mmc]: mmc %u Send scr failed\n"*/;
  }
  else {
    uVar3 = *(undefined4 *)(param_1 + 0x30);
    uVar2 = DAT_0005c060/*"[mmc]: mmc %u Send app cmd failed\n"*/;
  }
LAB_0005bf68:
  FUN_000498e4(uVar2,uVar3);
  return iVar1;
  while( true ) {
    iVar1 = FUN_0005bef0(param_1,0,0,1,auStack_60);
    if (iVar1 != 0) {
      uVar3 = *(undefined4 *)(param_1 + 0x30);
      uVar2 = DAT_0005c078/*"[mmc]: mmc %u Check high speed status faild\n"*/;
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
      uVar2 = DAT_0005c074/*"[mmc]: mmc %u switch to high speed failed\n"*/;
      goto LAB_0005bf68;
    }
    iVar1 = FUN_0005bdac(param_1);
    if (iVar1 != 0) {
      FUN_000498e4(DAT_0005c07c/*"[mmc]: update clock failed after send cmd6 to switch to sd high speed "*/);
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

//==== 0x5c080  0x5c080-0x5c085 inclusive
void FUN_0005c080(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0005c084. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1 + 0xac))();
  return;
}

//==== 0x5c5b8  0x5c5b8-0x5c5cd inclusive
void FUN_0005c5b8(int param_1,uint param_2)

{
  if (*(uint *)(param_1 + 0x38) <= param_2) {
    param_2 = *(uint *)(param_1 + 0x38);
  }
  if (*(uint *)(param_1 + 0x34) < param_2) {
    *(uint *)(param_1 + 0x48) = param_2;
  }
  else {
    *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x34);
  }
  FUN_0005c080();
  return;
}

//==== 0x5c5d0  0x5c5d0-0x5c68f inclusive
undefined4 FUN_0005c5d0(int param_1,byte *param_2,undefined4 param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  
  iVar3 = DAT_0005c6b0/*=0x6d6d6361*/;
  pbVar2 = DAT_0005c694/*"go err"*/;
  pbVar1 = DAT_0005c690/*"retry more time"*/;
  iVar8 = 0;
  iVar6 = param_1;
  pbVar5 = param_2;
  do {
    iVar4 = FUN_0005ba1c(param_1,param_2,0x5fb8,param_3,iVar6,pbVar5);
    if (iVar4 < 0) {
      if (iVar8 == 3) {
        pbVar7 = pbVar2;
      }
      else {
        pbVar7 = pbVar1;
      }
      FUN_0004993c(DAT_0005c69c/*"%s %d:read region parameter fail, %s \n"*/,DAT_0005c698/*"mmc_read_info"*/,0x32f,pbVar7);
      FUN_0005b2dc(param_2);
LAB_0005c610:
      if (iVar8 == 3) goto LAB_0005c614;
    }
    else {
      iVar6 = *(int *)(param_2 + 0x14);
      if (iVar6 == iVar3) {
        iVar4 = 0;
        iVar6 = *(int *)(param_2 + 0x18);
        param_2[0x18] = 0;
        param_2[0x19] = 0;
        param_2[0x1a] = 0;
        param_2[0x1b] = 0;
        for (pbVar5 = param_2; param_2 + *(int *)(param_2 + 0x1c) != pbVar5; pbVar5 = pbVar5 + 1) {
          iVar4 = iVar4 + (uint)*pbVar5;
        }
        if (iVar4 == iVar6) {
          FUN_000498e4(DAT_0005c6ac/*"[mmc]: RMCA OK!\n"*/);
          return 0;
        }
        if (iVar8 == 3) {
          pbVar5 = pbVar2;
        }
        else {
          pbVar5 = pbVar1;
        }
        FUN_0004993c(DAT_0005c6a4/*"%s %d:region add sum(%x) is not right(%x), %s \n"*/,DAT_0005c698/*"mmc_read_info"*/,0x345);
        goto LAB_0005c610;
      }
      if (iVar8 == 3) {
        pbVar7 = pbVar2;
      }
      else {
        pbVar7 = pbVar1;
      }
      FUN_0004993c(DAT_0005c6a8/*"%s %d:region magic is not right, %s %x\n"*/,DAT_0005c698/*"mmc_read_info"*/,0x34e,pbVar7);
      if (iVar8 == 3) {
        FUN_0005b2dc(param_2);
LAB_0005c614:
        FUN_000498e4(DAT_0005c6a0/*"[mmc]: RMCA FAIL!\n"*/);
        return 0xffffffff;
      }
    }
    iVar8 = iVar8 + 1;
  } while( true );
}

//==== 0x5c6b4  0x5c6b4-0x5c797 inclusive
uint FUN_0005c6b4(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  bool bVar9;
  undefined4 local_24c [4];
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_234;
  int local_230;
  uint local_22c;
  uint local_228;
  uint local_224;
  uint local_220;
  uint local_21c;
  undefined1 auStack_218 [160];
  byte local_178;
  char local_169;
  byte local_165;
  byte local_158;
  uint local_144;
  byte local_138;
  
  local_24c[0] = *DAT_0005c978/*=0x5e73c*/;
  local_24c[1] = DAT_0005c978/*=0x5e73c*/[1];
  local_24c[2] = DAT_0005c978/*=0x5e73c*/[2];
  local_24c[3] = DAT_0005c978/*=0x5e73c*/[3];
  local_23c = DAT_0005c978/*=0x5e73c*/[4];
  local_21c = 0;
  if ((*(uint *)(param_1 + 0x50) & 0x10) == 0) {
    local_238 = 2;
  }
  else {
    local_238 = 10;
  }
  local_234 = 7;
  local_230 = 0;
  uVar2 = FUN_0005b324(param_1,&local_238);
  if (uVar2 != 0) {
    uVar3 = *(uint *)(param_1 + 0x30);
    uVar7 = DAT_0005c97c/*"[mmc]: mmc %u Put the Card in Identify Mode failed\n"*/;
    goto LAB_0005c6f4;
  }
  thunk_FUN_00047d1c(param_1 + 0x70,&local_22c,0x10);
  if (-1 < *(int *)(param_1 + 0x50) << 0x1b) {
    local_238 = 3;
    local_230 = *(int *)(param_1 + 0x80) << 0x10;
    local_234 = 0x15;
    local_21c = uVar2;
    uVar2 = FUN_0005b324(param_1,&local_238,0);
    if (uVar2 != 0) {
      uVar3 = *(uint *)(param_1 + 0x30);
      uVar7 = DAT_0005c980/*"[mmc]: mmc %u send rca failed\n"*/;
      goto LAB_0005c6f4;
    }
    if (*(int *)(param_1 + 0x28) << 0xe < 0) {
      *(uint *)(param_1 + 0x80) = local_22c >> 0x10;
    }
  }
  local_238 = 9;
  local_234 = 7;
  local_21c = 0;
  local_230 = *(int *)(param_1 + 0x80) << 0x10;
  uVar2 = FUN_0005b324(param_1,&local_238);
  FUN_0005b948(param_1,1000);
  if (uVar2 != 0) {
    uVar3 = *(uint *)(param_1 + 0x30);
    uVar7 = DAT_0005c984/*"[mmc]: mmc %u get csd failed\n"*/;
    goto LAB_0005c6f4;
  }
  *(uint *)(param_1 + 0x60) = local_22c;
  *(uint *)(param_1 + 100) = local_228;
  *(uint *)(param_1 + 0x68) = local_224;
  *(uint *)(param_1 + 0x6c) = local_220;
  if (*(int *)(param_1 + 0x28) == 0x10000) {
    switch((local_22c & 0x3fffffff) >> 0x1a) {
    case 1:
      uVar2 = DAT_0005c994/*=0x10014*/;
      break;
    case 2:
      uVar2 = DAT_0005c998/*=0x10022*/;
      break;
    case 3:
      uVar2 = DAT_0005c99c/*=0x10030*/;
      break;
    case 4:
      uVar2 = DAT_0005c9a0/*=0x10040*/;
      break;
    default:
      uVar2 = DAT_0005c988/*=0x10012*/;
    }
    *(uint *)(param_1 + 0x28) = uVar2;
  }
  bVar9 = -1 < *(int *)(param_1 + 0x28) << 0xe;
  if (bVar9) {
    local_220 = (local_220 & 0x3ffffff) >> 0x16;
  }
  *(int *)(param_1 + 0x8c) =
       *(int *)(DAT_0005c98c/*"mmc_read_info"*/ + ((local_22c & 0x7f) >> 3) * 4 + 0x24) *
       *(int *)(DAT_0005c98c/*"mmc_read_info"*/ + (local_22c & 7) * 4 + 100);
  uVar2 = 1 << ((local_228 & 0xfffff) >> 0x10);
  if (bVar9) {
    *(int *)(param_1 + 0x94) = 1 << (local_220 & 0xff);
  }
  *(uint *)(param_1 + 0x90) = uVar2;
  if (!bVar9) {
    *(uint *)(param_1 + 0x94) = uVar2;
  }
  if (*(int *)(param_1 + 0x40) == 0) {
    uVar5 = (local_228 & 0x3ff) << 2 | local_224 >> 0x1e;
    uVar3 = (local_224 & 0x3ffff) >> 0xf;
  }
  else {
    uVar5 = (local_228 & 0x3f) << 0x10 | local_224 >> 0x10;
    uVar3 = 8;
  }
  uVar6 = uVar5 + 1;
  iVar8 = uVar3 + 2;
  lVar1 = (ulonglong)(uVar6 << iVar8) * (ulonglong)uVar2;
  *(int *)(param_1 + 0xa0) = (int)lVar1;
  *(uint *)(param_1 + 0xa4) =
       (int)((ulonglong)lVar1 >> 0x20) +
       uVar2 * ((uint)(0xfffffffe < uVar5) << iVar8 | uVar6 << (uVar3 - 0x1e & 0xff) |
               uVar6 >> (0x20U - iVar8 & 0xff)) + (uVar6 << iVar8) * ((int)uVar2 >> 0x1f);
  if (0x200 < (int)uVar2) {
    *(undefined4 *)(param_1 + 0x90) = 0x200;
  }
  if (0x200 < *(uint *)(param_1 + 0x94)) {
    *(undefined4 *)(param_1 + 0x94) = 0x200;
  }
  uVar2 = *(uint *)(param_1 + 0x50) & 0x10;
  if (uVar2 == 0) {
    local_238 = 7;
    local_234 = 0x1d;
    local_230 = *(int *)(param_1 + 0x80) << 0x10;
    local_21c = uVar2;
    uVar2 = FUN_0005b324(param_1,&local_238);
    if (uVar2 != 0) {
      uVar7 = DAT_0005c990/*"[mmc]: Select the card failed\n"*/;
      goto LAB_0005c878;
    }
  }
  if (-1 < *(int *)(param_1 + 0x28) << 0xe) {
    iVar8 = FUN_0005c5d0(param_1,DAT_0005c9a4/*=0x83654*/,1);
    if (iVar8 < 0) {
      FUN_000498e4(DAT_0005c9a8/*"[mmc]: mmc read timing info fail\n"*/);
    }
    FUN_0005d404(*(undefined4 *)(param_1 + 0x30));
  }
  FUN_0005c5b8(param_1,DAT_0005c9ac/*=0x17d7840*/);
  *(undefined4 *)(param_1 + 0x98) = 1;
  *(undefined4 *)(param_1 + 0x84) = 0xff;
  if ((int)(*(uint *)(param_1 + 0x28) << 0xe) < 0) {
LAB_0005c966:
    uVar2 = FUN_0005bf34(param_1);
  }
  else {
    if (DAT_0005c9b0/*=0x1003f*/ < *(uint *)(param_1 + 0x28)) {
      iVar8 = FUN_0005bd6c(param_1,auStack_218);
      if (iVar8 == 0) {
        switch(local_158) {
        case 0:
          uVar2 = DAT_0005c9a0/*=0x10040*/;
          break;
        case 1:
          uVar2 = DAT_0005cbdc/*=0x10041*/;
          break;
        case 2:
          uVar2 = DAT_0005cbe0/*=0x10042*/;
          break;
        case 3:
          uVar2 = DAT_0005cbe4/*=0x10043*/;
          break;
        default:
          goto switchD_0005c8fc_caseD_4;
        case 5:
          uVar2 = DAT_0005cbe8/*=0x10044*/;
          break;
        case 6:
          uVar2 = DAT_0005cbec/*=0x10045*/;
          break;
        case 7:
          uVar2 = DAT_0005cbf0/*=0x10050*/;
          break;
        case 8:
          uVar2 = DAT_0005cbf4/*=0x10051*/;
        }
        *(uint *)(param_1 + 0x28) = uVar2;
      }
switchD_0005c8fc_caseD_4:
      if ((1 < local_158) && (iVar8 == 0)) {
        uVar3 = ((int)local_144 >> 0x1f) << 9 | local_144 >> 0x17;
        uVar2 = ((int)local_144 >> 0x1f & 0x7fffffU) >> 0xb;
        bVar9 = uVar2 == 0;
        if (uVar2 == 0) {
          bVar9 = ((local_144 & 0x7fffff) >> 0xb | uVar3 << 0xc) < 0x801;
        }
        if (!bVar9) {
          *(uint *)(param_1 + 0xa0) = local_144 << 9;
          *(uint *)(param_1 + 0xa4) = uVar3;
        }
      }
      if (local_169 == '\0') {
        iVar8 = ((*(uint *)(param_1 + 0x68) & 0x3ff) >> 5) + 1;
        iVar8 = ((*(uint *)(param_1 + 0x68) & 0x7fff) >> 10) * iVar8 + iVar8;
      }
      else {
        iVar8 = (uint)local_138 << 0x13;
      }
      *(int *)(param_1 + 0x98) = iVar8;
      if ((int)((uint)local_178 << 0x1f) < 0) {
        *(uint *)(param_1 + 0x84) = (uint)local_165;
      }
      if (*(int *)(param_1 + 0x28) << 0xe < 0) goto LAB_0005c966;
    }
    uVar2 = FUN_0005bed0(param_1);
  }
  if (uVar2 != 0) {
    uVar3 = *(uint *)(param_1 + 0x30);
    uVar7 = DAT_0005c9b4/*"[mmc]: mmc %u Change speed mode failed\n"*/;
    goto LAB_0005c6f4;
  }
  uVar2 = FUN_0005bdac(param_1);
  if (uVar2 != 0) {
    uVar7 = DAT_0005cbf8/*"[mmc]: update clock failed\n"*/;
LAB_0005c878:
    FUN_000498e4(uVar7);
    return uVar2;
  }
  uVar5 = *(uint *)(param_1 + 0x4c) & *(uint *)(param_1 + 0x50);
  uVar2 = uVar5 & 0x40;
  *(uint *)(param_1 + 0x4c) = uVar5;
  uVar3 = *(uint *)(param_1 + 0x28) & 0x20000;
  if (uVar2 == 0) {
    if (uVar3 == 0) {
      if (*(int *)(param_1 + 0x104) == 2) {
        *(undefined4 *)(param_1 + 0x104) = 1;
      }
      else {
        *(undefined4 *)(param_1 + 0x104) = 0;
      }
      goto LAB_0005ca24;
    }
LAB_0005ca48:
    if ((int)(uVar5 << 0x1d) < 0) {
      local_238 = 0x37;
      local_234 = 0x15;
      local_21c = 0;
      local_230 = *(int *)(param_1 + 0x80) << 0x10;
      uVar2 = FUN_0005b324(param_1,&local_238);
      if (uVar2 != 0) {
        uVar4 = *(undefined4 *)(param_1 + 0x30);
        uVar7 = DAT_0005cc00/*"[mmc]: mmc %u send app cmd failed\n"*/;
        goto LAB_0005ca72;
      }
      local_238 = 6;
      local_234 = 0x15;
      local_230 = 2;
      local_21c = uVar2;
      uVar2 = FUN_0005b324(param_1,&local_238,0);
      if (uVar2 != 0) {
        uVar4 = *(undefined4 *)(param_1 + 0x30);
        uVar7 = DAT_0005cc04/*"[mmc]: mmc %u sd set bus width failed\n"*/;
        goto LAB_0005ca72;
      }
      *(undefined4 *)(param_1 + 0x44) = 4;
      FUN_0005c080(param_1);
    }
    if (*(int *)(param_1 + 0x4c) << 0x1f < 0) {
      uVar7 = DAT_0005cc08/*=0x2faf080*/;
    }
    else {
      uVar7 = DAT_0005cc0c/*=0x17d7840*/;
    }
  }
  else {
    if (uVar3 != 0) goto LAB_0005ca48;
LAB_0005ca24:
    if ((int)(uVar5 << 0x1c) < 0) {
      if (uVar2 == 0) {
        uVar2 = FUN_0005bdc8(param_1,1,0xb7,2);
        if (uVar2 != 0) {
          uVar4 = *(undefined4 *)(param_1 + 0x30);
          uVar7 = DAT_0005cc18/*"[mmc]: mmc %u switch bus width8 failed\n"*/;
          goto LAB_0005ca72;
        }
      }
      else {
        uVar2 = FUN_0005bdc8(param_1,1,0xb7,6);
        if (uVar2 != 0) {
LAB_0005ca3e:
          uVar4 = *(undefined4 *)(param_1 + 0x30);
          uVar7 = DAT_0005cbfc/*"[mmc]: mmc %u switch bus width failed\n"*/;
LAB_0005ca72:
          FUN_000498e4(uVar7,uVar4);
          return uVar2;
        }
      }
      uVar7 = 8;
LAB_0005cafa:
      *(undefined4 *)(param_1 + 0x44) = uVar7;
      FUN_0005c080(param_1);
    }
    else if ((int)(uVar5 << 0x1d) < 0) {
      if (uVar2 == 0) {
        uVar7 = 1;
      }
      else {
        uVar7 = 5;
      }
      uVar2 = FUN_0005bdc8(param_1,1,0xb7,uVar7);
      if (uVar2 != 0) goto LAB_0005ca3e;
      uVar7 = 4;
      goto LAB_0005cafa;
    }
    iVar8 = *(int *)(param_1 + 0x4c);
    if ((iVar8 << 0x19 < 0) || ((iVar8 << 0x1f < 0 && (iVar8 << 0x1e < 0)))) {
      uVar7 = DAT_0005cc14/*=0x3197500*/;
    }
    else {
      uVar7 = DAT_0005cc1c/*=0x18cba80*/;
    }
  }
  *(undefined4 *)(param_1 + 0x8c) = uVar7;
  FUN_0005c5b8(param_1,*(undefined4 *)(param_1 + 0x8c));
  *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(param_1 + 0x90);
  *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xa0) >> 9 | *(int *)(param_1 + 0xa4) << 0x17;
  uVar2 = *(uint *)(param_1 + 0x28);
  if (-1 < (int)(uVar2 << 0xe)) {
    if (uVar2 == DAT_0005cbdc/*=0x10041*/) {
      uVar7 = DAT_0005cc4c/*"[mmc]: MMC 4.1\n"*/;
    }
    else if (uVar2 < DAT_0005cbdc/*=0x10041*/) {
      if (uVar2 == DAT_0005cbdc/*=0x10041*/ - 0x1f) {
        uVar7 = DAT_0005cc44/*"[mmc]: MMC 2.2\n"*/;
      }
      else if (uVar2 < DAT_0005cbdc/*=0x10041*/ - 0x1f) {
        if (uVar2 == DAT_0005cbdc/*=0x10041*/ - 0x2f) {
          uVar7 = DAT_0005cc30/*"[mmc]: MMC 1.2\n"*/;
        }
        else if (uVar2 == DAT_0005cbdc/*=0x10041*/ - 0x2d) {
          uVar7 = DAT_0005cc40/*"[mmc]: MMC 1.4\n"*/;
        }
        else {
LAB_0005caf4:
          uVar7 = DAT_0005cc10/*"[mmc]: Unknow MMC ver\n"*/;
        }
      }
      else if (uVar2 == DAT_0005cc20/*=0x10030*/) {
        uVar7 = DAT_0005cc48/*"[mmc]: MMC 3.0\n"*/;
      }
      else {
        if (uVar2 != DAT_0005cc20/*=0x10030*/ + 0x10) goto LAB_0005caf4;
        uVar7 = DAT_0005cc24/*"[mmc]: MMC 4.0\n"*/;
      }
    }
    else if (uVar2 == DAT_0005cbe8/*=0x10044*/) {
      uVar7 = DAT_0005cc54/*"[mmc]: MMC 4.41\n"*/;
    }
    else if (uVar2 < DAT_0005cbe8/*=0x10044*/) {
      if (uVar2 == DAT_0005cbe8/*=0x10044*/ - 2) {
        uVar7 = DAT_0005cc50/*"[mmc]: MMC 4.2\n"*/;
      }
      else {
        if (uVar2 != DAT_0005cbe8/*=0x10044*/ - 1) goto LAB_0005caf4;
        uVar7 = DAT_0005cc28/*"[mmc]: MMC 4.3\n"*/;
      }
    }
    else if (uVar2 == DAT_0005cbf0/*=0x10050*/) {
      uVar7 = DAT_0005cc58/*"[mmc]: MMC 5.0\n"*/;
    }
    else if (uVar2 == DAT_0005cbf0/*=0x10050*/ + 1) {
      uVar7 = DAT_0005cc5c/*"[mmc]: MMC 5.1\n"*/;
    }
    else {
      if (uVar2 != DAT_0005cbf0/*=0x10050*/ - 0xb) goto LAB_0005caf4;
      uVar7 = DAT_0005cc2c/*"[mmc]: MMC 4.5\n"*/;
    }
    FUN_000498e4(uVar7);
  }
  FUN_000498e4(DAT_0005cc34/*"[mmc]: %s %u bit\n"*/,local_24c[*(int *)(param_1 + 0x104)],*(undefined4 *)(param_1 + 0x44));
  FUN_000498e4(DAT_0005cc38/*"[mmc]: %u Hz\n"*/,*(undefined4 *)(param_1 + 0x48));
  uVar3 = *(uint *)(param_1 + 0xec) >> 0xb;
  uVar2 = 0;
  uVar7 = DAT_0005cc3c/*"[mmc]: %u MB\n"*/;
LAB_0005c6f4:
  FUN_000498e4(uVar7,uVar3);
  return uVar2;
}

//==== 0x5cc60  0x5cc60-0x5ccad inclusive
int FUN_0005cc60(int param_1)

{
  int iVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  char local_24;
  undefined4 local_14;
  
  local_30 = 8;
  local_14 = 0;
  if ((DAT_0005ccb0/*=0xff8000*/ & *(uint *)(param_1 + 0x24)) == 0) {
    local_28 = 0xaa;
  }
  else {
    local_28 = 0x1aa;
  }
  local_2c = 0x15;
  iVar1 = FUN_0005b324(param_1,&local_30);
  if (iVar1 == 0) {
    if (local_24 == -0x56) {
      *(undefined4 *)(param_1 + 0x28) = DAT_0005ccb8/*=0x20020*/;
    }
    else {
      iVar1 = -0x11;
    }
  }
  else {
    FUN_000498e4(DAT_0005ccb4/*"[mmc]: mmc %u send if cond failed\n"*/,*(undefined4 *)(param_1 + 0x30));
  }
  return iVar1;
}

//==== 0x5ce50  0x5ccbc-0x5ce17 inclusive
int FUN_0005ce50(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  *(int *)(DAT_0005ce6c/*=0x83648*/ + param_1 * 4) = param_2;
  if (*(int *)(param_2 + 0xe8) == 0) {
    *(undefined4 *)(param_2 + 0xe8) = 0xffff;
  }
  if (*(int *)(param_2 + 0x2c) == 0) {
    iVar5 = (**(code **)(param_2 + 0xb0))();
    iVar2 = DAT_0005ce4c/*=0x83648*/;
    uVar3 = DAT_0005ce24/*"[mmc]: Wrong media type 0x%x, but host sdc2, try mmc first\n"*/;
    iVar1 = DAT_0005ce20/*=0x8000001*/;
    if (iVar5 == 0) {
      *(undefined4 *)(param_2 + 0x44) = 1;
      FUN_0005c080(param_2);
      FUN_0005c5b8(param_2,1);
      while (iVar5 = FUN_0005bb44(param_2), iVar5 == 0) {
        *(undefined4 *)(param_2 + 0x88) = 0;
        iVar5 = *(int *)(iVar2 + 0x74);
        if (iVar5 == iVar1) {
          FUN_000498e4(DAT_0005ce2c/*"[mmc]: ***Try SD card %u***\n"*/);
          FUN_0005cc60(param_2);
          iVar5 = FUN_0005bb80(param_2);
          if (iVar5 != 0) {
            uVar4 = *(undefined4 *)(param_2 + 0x30);
            uVar3 = DAT_0005ce30/*"[mmc]: SD card %u Card did not respond to voltage select!\n"*/;
LAB_0005cd54:
            FUN_000498e4(uVar3,uVar4);
            FUN_000498e4(DAT_0005ce34/*"[mmc]: ***SD/MMC %u init error!!!***\n"*/,*(undefined4 *)(param_2 + 0x30));
            return -0x11;
          }
LAB_0005cdf6:
          iVar5 = FUN_0005c6b4(param_2);
          if (iVar5 != 0) {
            FUN_000498e4(DAT_0005ce34/*"[mmc]: ***SD/MMC %u init error!!!***\n"*/,*(undefined4 *)(param_2 + 0x30));
            *(undefined4 *)(param_2 + 0x2c) = 0;
            return iVar5;
          }
          uVar4 = *(undefined4 *)(param_2 + 0x30);
          *(undefined4 *)(param_2 + 0x2c) = 1;
          iVar5 = 0;
          uVar3 = DAT_0005ce48/*"[mmc]: ***SD/MMC %u init OK!!!***\n"*/;
          goto LAB_0005cce4;
        }
        if (iVar5 == 0x8000000) {
          FUN_000498e4(DAT_0005ce38/*"[mmc]: ***Try MMC card %u***\n"*/);
          iVar5 = FUN_0005bc7c(param_2);
          if (iVar5 != 0) {
            uVar4 = *(undefined4 *)(param_2 + 0x30);
            uVar3 = DAT_0005ce3c/*"[mmc]: MMC card %u Card did not respond to voltage select!\n"*/;
            goto LAB_0005cd54;
          }
          goto LAB_0005cdf6;
        }
        if (*(int *)(param_2 + 0x30) != 2) {
          FUN_000498e4(DAT_0005ce40/*"[mmc]: Wrong media type 0x%x\n"*/,iVar5);
          FUN_000498e4(DAT_0005ce2c/*"[mmc]: ***Try SD card %u***\n"*/,*(undefined4 *)(param_2 + 0x30));
          FUN_0005cc60(param_2);
          iVar5 = FUN_0005bb80(param_2);
          if (iVar5 != 0) {
            FUN_000498e4(DAT_0005ce38/*"[mmc]: ***Try MMC card %u***\n"*/,*(undefined4 *)(param_2 + 0x30));
            iVar5 = FUN_0005bc7c(param_2);
            if (iVar5 != 0) {
              uVar4 = *(undefined4 *)(param_2 + 0x30);
              uVar3 = DAT_0005ce44/*"[mmc]: mmc %u Card did not respond to voltage select!\n"*/;
              goto LAB_0005cd54;
            }
          }
          goto LAB_0005cdf6;
        }
        FUN_000498e4(uVar3,iVar5);
        FUN_000498e4(DAT_0005ce38/*"[mmc]: ***Try MMC card %u***\n"*/,*(undefined4 *)(param_2 + 0x30));
        iVar5 = FUN_0005bc7c(param_2);
        if (iVar5 == 0) goto LAB_0005cdf6;
        FUN_000498e4(DAT_0005ce3c/*"[mmc]: MMC card %u Card did not respond to voltage select!\n"*/,*(undefined4 *)(param_2 + 0x30));
        FUN_000498e4(DAT_0005ce34/*"[mmc]: ***SD/MMC %u init error!!!***\n"*/,*(undefined4 *)(param_2 + 0x30));
        *(undefined1 *)(iVar2 + 0x75) = 0;
        *(undefined1 *)(iVar2 + 0x74) = 1;
        *(undefined1 *)(iVar2 + 0x76) = 0;
        *(undefined1 *)(iVar2 + 0x77) = 8;
      }
      uVar4 = *(undefined4 *)(param_2 + 0x30);
      uVar3 = DAT_0005ce28/*"[mmc]: mmc %u reset card failed\n"*/;
    }
    else {
      uVar4 = *(undefined4 *)(param_2 + 0x30);
      uVar3 = DAT_0005ce1c/*"[mmc]: mmc %u host init failed\n"*/;
    }
LAB_0005cce4:
    FUN_000498e4(uVar3,uVar4);
  }
  else {
    iVar5 = 0;
    FUN_000498e4(DAT_0005ce18/*"[mmc]: mmc %u Has init\n"*/,*(undefined4 *)(param_2 + 0x30));
  }
  return iVar5;
}

//==== 0x5ce70  0x5ce70-0x5ce7b inclusive
undefined4 FUN_0005ce70(int param_1)

{
  *(undefined4 *)(DAT_0005ce7c/*=0x83648*/ + param_1 * 4) = 0;
  return 0;
}

//==== 0x5ce80  0x5ce80-0x5ced5 inclusive
void FUN_0005ce80(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = **(uint **)(param_1 + 0x10);
  DataMemoryBarrier(0x1f);
  uVar4 = (uVar3 & 0x3ffffff) >> 0x18;
  if (uVar4 == 0) {
    uVar1 = DAT_0005cee8/*=0x16e3600*/;
  }
  else if (uVar4 == 1) {
    if (*(int *)(param_1 + 4) == 0) {
      uVar1 = DAT_0005ceec/*=0x17d78400*/;
    }
    else {
      uVar1 = DAT_0005ced8/*=0x2faf0800*/;
      if (*(int *)(param_1 + 4) != 2) {
        uVar1 = 0;
      }
    }
  }
  else {
    if (uVar4 == 2) {
      uVar1 = 2;
      uVar2 = DAT_0005cee0/*"[mmc]: %s: clock source need todo %u\n"*/;
    }
    else {
      uVar1 = 3;
      uVar2 = DAT_0005cee4/*"[mmc]: %s: wrong clock source %u\n"*/;
    }
    FUN_000498e4(uVar2,DAT_0005cedc/*"mmc_get_mclk"*/,uVar1,*(uint **)(param_1 + 0x10),param_4);
    uVar1 = 0;
  }
  uVar1 = FUN_00048038(uVar1,((uVar3 & 0x3ff) >> 8) + 1);
  FUN_00048038(uVar1,(uVar3 & 0xf) + 1);
  return;
}

//==== 0x5d03c  0x5d03c-0x5d081 inclusive
void FUN_0005d03c(undefined4 *param_1,int param_2)

{
  uint uVar1;
  
  DataMemoryBarrier(0x1f);
  uVar1 = *(uint *)*param_1 & 0xfffffbff;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *(uint *)param_1[4] = *(uint *)param_1[4] & 0x7fffffff;
  if (param_2 != 0) {
    uVar1 = uVar1 | 0x400;
  }
  DataMemoryBarrier(0x1f);
  *(uint *)*param_1 = uVar1;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *(uint *)param_1[4] = *(uint *)param_1[4] | 0x80000000;
  return;
}

//==== 0x5d082  0x5d082-0x5d0d7 inclusive
void FUN_0005d082(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_1[1] == 2) {
    DataMemoryBarrier(0x1f);
    uVar2 = *(uint *)(*param_1 + 0x10c) & 0x7fffffff;
    if (param_2 == 0) {
      DataMemoryBarrier(0x1f);
      iVar1 = *param_1;
      *(uint *)(iVar1 + 0x10c) = uVar2;
      DataMemoryBarrier(0x1f);
      uVar2 = *(uint *)(iVar1 + 0x54) & 0xfffffff0 | 3;
    }
    else {
      DataMemoryBarrier(0x1f);
      iVar1 = *param_1;
      *(uint *)(iVar1 + 0x10c) = uVar2 | 0x80000000;
      DataMemoryBarrier(0x1f);
      uVar2 = *(uint *)(iVar1 + 0x54) & 0xfffffff0 | 6;
    }
    DataMemoryBarrier(0x1f);
    *(uint *)(*param_1 + 0x54) = uVar2;
  }
  return;
}

//==== 0x5d0d8  0x5d0d8-0x5d175 inclusive
undefined4 FUN_0005d0d8(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  iVar2 = FUN_00048d6c();
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *(uint *)(*param_1 + 4) = *(uint *)(*param_1 + 4) | 0x80000000;
  DataMemoryBarrier(0x1f);
  *(undefined4 *)(*param_1 + 0x18) = DAT_0005d178/*=0x80202000*/;
  do {
    DataMemoryBarrier(0x1f);
    if (-1 < *(int *)(*param_1 + 0x18)) break;
    uVar3 = FUN_00048d6c();
  } while (uVar3 < iVar2 + 0xfffffU);
  DataMemoryBarrier(0x1f);
  if (*(int *)(*param_1 + 0x18) < 0) {
    FUN_000498e4(DAT_0005d17c/*"[mmc]: mmc %d update clk failed\n"*/,param_1[1]);
    puVar1 = DAT_0005d180/*=0x1c2084c*/;
    DataMemoryBarrier(0x1f);
    *DAT_0005d180/*=0x1c2084c*/ = 0;
    DataMemoryBarrier(0x1f);
    DataMemoryBarrier(0x1f);
    FUN_000498e4(DAT_0005d184/*"[mmc]: 0x%x 0x%x\n"*/,*puVar1,puVar1[3],puVar1,param_4);
    uVar4 = 0xffffffff;
  }
  else {
    DataMemoryBarrier(0x1f);
    DataMemoryBarrier(0x1f);
    iVar2 = *param_1;
    *(uint *)(iVar2 + 4) = *(uint *)(*param_1 + 4) & 0x7fffffff;
    DataMemoryBarrier(0x1f);
    DataMemoryBarrier(0x1f);
    uVar4 = 0;
    *(undefined4 *)(*param_1 + 0x38) = *(undefined4 *)(iVar2 + 0x38);
  }
  return uVar4;
}

//==== 0x5d188  0x5d188-0x5d1e7 inclusive
undefined4 FUN_0005d188(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 8;
    iVar1 = param_2;
  }
  else {
    uVar2 = 0xc;
    iVar1 = param_2 + param_3 * 8;
  }
  FUN_0004a5cc(iVar1,uVar2,1,param_2,param_4);
  iVar1 = param_1 * 0x34 + DAT_0005d1e8/*=0x83858*/;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  **(uint **)(iVar1 + 0xc) = **(uint **)(iVar1 + 0xc) | 1;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  **(uint **)(iVar1 + 8) = **(uint **)(iVar1 + 8) | 0x10000;
  DataMemoryBarrier(0x1f);
  **(undefined4 **)(iVar1 + 0x10) = 0x80000000;
  *(undefined4 *)(iVar1 + 0x2c) = DAT_0005d1ec/*=0x16e3600*/;
  return 0;
}

//==== 0x5d1f0  0x5d1f0-0x5d38f inclusive
uint FUN_0005d1f0(int param_1,uint param_2,uint param_3,undefined1 *param_4,undefined1 *param_5)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar6 = DAT_0005d394/*=0x83654*/;
  iVar5 = *(int *)(param_1 * 0x34 + DAT_0005d390/*=0x83858*/ + 0x24);
  if (param_1 != 2) {
    if ((param_1 != 0) || (iVar5 != 1)) goto LAB_0005d37e;
    if ((param_2 < 2) && (param_3 < 3)) {
      *param_4 = 0;
      *param_5 = 0;
      return 0;
    }
    iVar6 = 1;
    uVar2 = DAT_0005d3a8/*"[mmc]: sdc0 spd mode error, %d\n"*/;
    uVar1 = DAT_0005d390/*=0x83858*/;
    goto LAB_0005d27a;
  }
  if (iVar5 != 4) {
LAB_0005d37e:
    FUN_000498e4(DAT_0005d3ac/*"[mmc]: mmc_get_timing_cfg: input para error!\n"*/);
    return 0xffffffff;
  }
  if (*(int *)(DAT_0005d394/*=0x83654*/ + 0x14) == DAT_0005d398/*=0x6d6d6361*/) {
    uVar1 = (uint)*(byte *)(DAT_0005d394/*=0x83654*/ + 0x60);
  }
  else {
    uVar1 = 0;
  }
  if ((uVar1 & 1) == 0) {
    if ((uVar1 & 2) == 0) {
      if (4 < param_2) {
        FUN_000498e4(DAT_0005d3a4/*"[mmc]: wrong input para: mmc %d/2, mode %d/[0,4], freq %d/[0,5]\n"*/,2,param_2,param_3,param_4);
        return 0xffffffff;
      }
      iVar6 = DAT_0005d394/*=0x83654*/ + (param_2 * 2 + (param_3 >> 2)) * 4;
      iVar5 = (param_3 & 3) << 3;
      uVar7 = *(uint *)(iVar6 + 0x30) >> iVar5;
      uVar1 = uVar7 & 0xff;
      uVar3 = (undefined1)uVar7;
      if ((uVar1 == 0xff) || (uVar1 == 0)) {
        if (param_2 == 0) {
          if (param_3 < 2) {
LAB_0005d360:
            uVar7 = 0;
            uVar1 = uVar7;
            goto LAB_0005d31c;
          }
LAB_0005d310:
          FUN_000498e4(DAT_0005d39c/*"[mmc]: wrong freq %d at spd md %d\n"*/,param_3,param_2,iVar5,param_4);
        }
        else {
          if (param_2 == 1) {
            if (param_3 < 2) goto LAB_0005d360;
            if (param_3 == 2) {
              uVar1 = 0xf;
              uVar7 = 0;
              goto LAB_0005d31c;
            }
            goto LAB_0005d310;
          }
          if (param_2 == 2) {
            if (param_3 < 2) {
              uVar3 = 0;
              uVar7 = 0;
            }
            else {
              FUN_000498e4(DAT_0005d39c/*"[mmc]: wrong freq %d at spd md %d\n"*/,param_3,2,iVar5,param_4);
              uVar7 = 0xffffffff;
            }
            goto LAB_0005d346;
          }
          FUN_000498e4(DAT_0005d3a0/*"[mmc]: wrong speed mode %d\n"*/,param_2,*(undefined1 *)(iVar6 + 0x32),iVar5,param_4);
        }
        uVar7 = 0xffffffff;
      }
      else {
        uVar7 = 0;
        if (param_2 == 2) {
LAB_0005d346:
          uVar4 = 1;
          goto LAB_0005d348;
        }
        uVar7 = 0;
      }
LAB_0005d31c:
      uVar3 = (undefined1)uVar1;
      uVar4 = 0;
LAB_0005d348:
      *param_4 = uVar4;
      *param_5 = uVar3;
      return uVar7;
    }
    if (param_2 == 0) goto LAB_0005d23a;
    if (param_2 == 1) {
      if (param_3 < 2) goto LAB_0005d25e;
      if (param_3 == 2) {
        *param_4 = *(undefined1 *)(DAT_0005d394/*=0x83654*/ + 0x61);
        uVar3 = *(undefined1 *)(iVar6 + 0x62);
LAB_0005d2a0:
        *param_5 = uVar3;
        return 0;
      }
      goto LAB_0005d272;
    }
    if (param_2 != 2) goto LAB_0005d276;
    if (1 < param_3) {
      if (param_3 == 2) {
        *param_4 = *(undefined1 *)(DAT_0005d394/*=0x83654*/ + 99);
        uVar3 = *(undefined1 *)(iVar6 + 100);
        goto LAB_0005d2a0;
      }
      uVar2 = 2;
      goto LAB_0005d24a;
    }
  }
  else {
    if (param_2 != 0) {
      if (param_2 != 1) {
LAB_0005d276:
        uVar2 = DAT_0005d3a0/*"[mmc]: wrong speed mode %d\n"*/;
LAB_0005d27a:
        FUN_000498e4(uVar2,param_2,uVar1,iVar6,param_4);
        return 0xffffffff;
      }
      if (param_3 < 2) {
LAB_0005d25e:
        uVar3 = 3;
        *param_4 = 0;
        goto LAB_0005d244;
      }
      if (param_3 == 2) {
        uVar3 = 4;
        *param_4 = 0;
        goto LAB_0005d244;
      }
LAB_0005d272:
      uVar2 = 1;
      goto LAB_0005d24a;
    }
LAB_0005d23a:
    if (1 < param_3) {
      uVar2 = 0;
LAB_0005d24a:
      FUN_000498e4(DAT_0005d39c/*"[mmc]: wrong freq %d at spd md %d\n"*/,param_3,uVar2,DAT_0005d394/*=0x83654*/,param_4);
      return 0xffffffff;
    }
  }
  uVar3 = 2;
  *param_4 = 0;
LAB_0005d244:
  *param_5 = uVar3;
  return 0;
}

//==== 0x5d3b0  0x5d3b0-0x5d3f1 inclusive
void FUN_0005d3b0(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (*(int *)(DAT_0005d3f4/*=0x83654*/ + 0x14) == DAT_0005d3f8/*=0x6d6d6361*/) {
    thunk_FUN_00047d1c(param_3 + 1000,DAT_0005d3f4/*=0x83654*/ + 0x30,0x4c);
    FUN_0004993c(DAT_0005d400/*"tunning data addr:0x%x\n"*/,param_3 + 1000);
    return;
  }
  FUN_0004993c(DAT_0005d3fc/*"mmc not para\n"*/);
  return;
}

//==== 0x5d404  0x5d404-0x5d505 inclusive
/* WARNING: Removing unreachable block (ram,0x0005d438) */
/* WARNING: Removing unreachable block (ram,0x0005d468) */

undefined4 FUN_0005d404(int param_1,undefined4 param_2,undefined4 param_3)

{
  ulonglong uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined1 local_1a;
  undefined1 local_19;
  
  iVar6 = DAT_0005d508/*=0x83654*/;
  uVar7 = (uint)*(byte *)(DAT_0005d508/*=0x83654*/ + 0x65);
  FUN_0005d1f0(param_1,1,2,&local_19,&local_1a,param_2,param_3);
  *(undefined4 *)(param_1 * 0x108 + DAT_0005d50c/*=0x83858*/ + 0xd8) = DAT_0005d510/*=0x17d7840*/;
  uVar3 = FUN_0005d1f0(param_1,2,2,&local_19,&local_1a,param_2,param_3);
  uVar1 = (ulonglong)uVar3;
  *(undefined4 *)(param_1 * 0x108 + DAT_0005d50c/*=0x83858*/ + 0xdc) = DAT_0005d510/*=0x17d7840*/;
  uVar3 = DAT_0005d514/*=0x431bde83*/;
  iVar5 = DAT_0005d50c/*=0x83858*/;
  if (uVar7 != 0) {
    iVar8 = param_1 * 0x108 + DAT_0005d50c/*=0x83858*/;
    if (uVar7 < (uint)((ulonglong)*(uint *)(iVar8 + 0xdc) * (ulonglong)DAT_0005d514/*=0x431bde83*/ >> 0x32)) {
      *(uint *)(iVar8 + 0xdc) = uVar7 * DAT_0005d518/*=0xf4240*/;
    }
    iVar5 = param_1 * 0x108 + iVar5;
    uVar1 = (ulonglong)*(uint *)(iVar5 + 0xd8) * (ulonglong)uVar3;
    if (uVar7 < (uint)(uVar1 >> 0x32)) {
      *(uint *)(iVar5 + 0xd8) = DAT_0005d518/*=0xf4240*/ * uVar7;
    }
  }
  uVar4 = (undefined4)uVar1;
  if ((DAT_0005d51c/*=0xff000001*/ & *(uint *)(iVar6 + 0x6c)) != DAT_0005d520/*=0x55000001*/) {
    uVar4 = FUN_000498e4(DAT_0005d524/*"[mmc]: force 25m\n"*/);
    uVar2 = DAT_0005d510/*=0x17d7840*/;
    iVar6 = param_1 * 0x108 + DAT_0005d50c/*=0x83858*/;
    *(undefined4 *)(iVar6 + 0xd8) = DAT_0005d510/*=0x17d7840*/;
    *(undefined4 *)(iVar6 + 0xdc) = uVar2;
  }
  return uVar4;
}

//==== 0x5d528  0x5d528-0x5d66f inclusive
undefined4 FUN_0005d528(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = DAT_0005d670/*=0x83858*/;
  iVar4 = DAT_0005d670/*=0x83858*/ + 0xa0;
  FUN_000498e4(DAT_0005d678/*"[mmc]: mmc driver ver %s\n"*/,DAT_0005d674/*"2025-10-16 17:10"*/);
  iVar4 = param_1 * 0x108 + iVar4;
  thunk_FUN_00047c40(iVar4,0);
  iVar5 = param_1 * 0x34 + iVar1;
  thunk_FUN_00047c40(iVar5,0);
  *(int *)(iVar5 + 0x28) = iVar4;
  if (param_1 < 2) {
    *(undefined4 *)(iVar5 + 0x24) = 1;
  }
  else if (param_1 == 2) {
    *(undefined4 *)(iVar1 + 0x8c) = 4;
  }
  FUN_000495a8(iVar4,DAT_0005d67c/*"SUNXI SD/MMC"*/);
  iVar3 = param_1 * 0x108 + iVar1;
  *(undefined4 *)(iVar3 + 0x148) = DAT_0005d680/*=0x5b32d*/;
  uVar2 = DAT_0005d684/*=0x5c089*/;
  *(int *)(iVar3 + 0xc0) = iVar5;
  *(undefined4 *)(iVar3 + 0x14c) = uVar2;
  *(undefined4 *)(iVar3 + 0x150) = DAT_0005d688/*=0x5cef1*/;
  *(undefined4 *)(iVar3 + 0x154) = DAT_0005d68c/*=0x5bdb9*/;
  *(undefined4 *)(iVar3 + 0xc4) = 0xfe0000;
  if (param_2 < 4) {
    uVar2 = 0x23;
  }
  else {
    uVar2 = 0x27;
  }
  *(undefined4 *)(iVar3 + 0xf0) = uVar2;
  if ((param_1 == 2) && (param_2 == 8)) {
    *(uint *)(iVar1 + 0x300) = *(uint *)(iVar1 + 0x300) | 0xc;
  }
  iVar5 = DAT_0005d690/*=0x61a80*/;
  iVar3 = param_1 * 0x108 + iVar1;
  *(int *)(iVar3 + 0xd4) = DAT_0005d690/*=0x61a80*/;
  *(uint *)(iVar3 + 0xd0) = param_1;
  *(int *)(iVar3 + 0xd8) = iVar5 + 49600000;
  *(int *)(iVar3 + 0xdc) = iVar5 + 49600000;
  iVar5 = iVar1 + param_1 * 0x34;
  *(undefined4 *)(iVar5 + 0x20) = 0x42000000;
  iVar3 = (param_1 + 0x4020) * 0x1000;
  *(int *)(iVar1 + param_1 * 0x34) = iVar3;
  *(int *)(iVar5 + 0x14) = iVar3 + 0x200;
  iVar3 = DAT_0005d694/*=0x2002d0c*/ + param_1 * 0x10;
  *(int *)(iVar5 + 8) = iVar3;
  *(int *)(iVar5 + 0xc) = iVar3;
  if (param_1 == 0) {
    *(undefined4 *)(iVar1 + 0x10) = DAT_0005d698/*=0x2002d00*/;
  }
  else {
    if (param_1 != 2) {
      FUN_000498e4(DAT_0005d6a4/*"[mmc]: Wrong mmc NO.: %d\n"*/,param_1);
      uVar2 = DAT_0005d6a8/*"[mmc]: mmc %d resource init failed\n"*/;
      goto LAB_0005d656;
    }
    *(undefined4 *)(iVar1 + 0x78) = DAT_0005d6a0/*=0x2002d20*/;
  }
  *(uint *)(param_1 * 0x34 + iVar1 + 4) = param_1;
  FUN_0005d188(param_1,param_3,param_4);
  iVar4 = FUN_0005ce50(param_1,iVar4);
  if (-1 < iVar4) {
    return *(undefined4 *)(param_1 * 0x108 + iVar1 + 0x18c);
  }
  uVar2 = DAT_0005d69c/*"[mmc]: mmc %d register failed\n"*/;
LAB_0005d656:
  FUN_000498e4(uVar2,param_1);
  return 0xffffffff;
}

//==== 0x5d6ac  0x5d6ac-0x5d6dd inclusive
undefined4 FUN_0005d6ac(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_0005d6e0/*=0x83858*/;
  FUN_0005d188();
  FUN_0005ce70(param_1);
  thunk_FUN_00047c40(param_1 * 0x108 + iVar1 + 0xa0,0);
  thunk_FUN_00047c40(param_1 * 0x34 + iVar1,0);
  return 0;
}

//==== 0x5d6e4  0x5d6e4-0x5d6f5 inclusive
undefined4 FUN_0005d6e4(undefined4 param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  if (*DAT_0005d6f8/*=0x83c10*/ != 0xe) {
    return 0xffffffff;
  }
  uStack_c = param_2;
  uStack_8 = param_3;
  iVar1 = FUN_0004af2a(0x36,0x50,(int)&uStack_c + 3,0xe,param_1);
  if (iVar1 == 0) {
    if ((int)((uStack_c >> 0x18) << 0x1f) < 0) {
      uVar2 = 2;
    }
    else {
      uVar2 = 0;
      if (-1 < (int)((uStack_c >> 0x18) << 0x1e)) {
        if ((uStack_c & 0x4000000) == 0) {
          uVar2 = 0xffffffff;
        }
        else {
          uVar2 = 1;
        }
      }
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

//==== 0x5d6fc  0x5d6fc-0x5d70d inclusive
uint FUN_0005d6fc(undefined4 param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  if (*DAT_0005d710/*=0x83c10*/ != 0xe) {
    return 0xffffffff;
  }
  uStack_c = param_2;
  uStack_8 = param_3;
  iVar1 = FUN_0004af2a(0x36,0x49,(int)&uStack_c + 3,0xe,param_1);
  if ((iVar1 == 0) &&
     ((uVar2 = uStack_c & 0x18000000, uStack_c = uStack_c & 0x18ffffff, uVar2 == 0 ||
      (iVar1 = FUN_0004af3e(0x36,0x49), iVar1 == 0)))) {
    uVar2 = (uStack_c >> 0x18 & 0x1f) >> 3;
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

//==== 0x5d714  0x5d714-0x5d727 inclusive
/* WARNING: Removing unreachable block (ram,0x0005d88e) */

int FUN_0005d714(uint param_1)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  byte bVar12;
  byte abStack_29 [5];
  
  uVar2 = DAT_0005d938/*"dcdc2"*/;
  iVar5 = DAT_0005d8b0/*"dcdc1"*/;
  if (*DAT_0005d728/*=0x83c10*/ != 0xe) {
    return -1;
  }
  iVar9 = 0;
  while( true ) {
    iVar8 = iVar9 * 0x6c + iVar5;
    uVar3 = FUN_000495f0(iVar8);
    iVar4 = FUN_000495ce(uVar2,iVar8,uVar3);
    if (iVar4 == 0) break;
    iVar9 = iVar9 + 1;
    if (iVar9 == 0x24) {
      return -1;
    }
  }
  if (iVar8 == 0) {
    return -1;
  }
  if ((0 < (int)param_1) && (uVar6 = *(uint *)(iVar8 + 0x10), uVar6 != 0)) {
    if (param_1 < uVar6) {
      param_1 = uVar6;
    }
    else if (*(uint *)(iVar8 + 0x14) <= param_1) {
      param_1 = *(uint *)(iVar8 + 0x14);
    }
    iVar5 = FUN_0004af2a(0x36,*(undefined1 *)(iVar8 + 0x18),abStack_29);
    if (iVar5 != 0) {
      return -1;
    }
    bVar1 = *(byte *)(iVar8 + 0x1c);
    bVar12 = abStack_29[0] & ~bVar1;
    uVar6 = 0;
    uVar10 = 0;
    abStack_29[0] = bVar12;
    while( true ) {
      uVar11 = uVar6 & 0xff;
      uVar7 = *(uint *)(iVar8 + uVar11 * 0x10 + 0x30);
      if (uVar7 == 0) break;
      if ((uVar7 < param_1) && (param_1 < *(uint *)(iVar8 + uVar11 * 0x10 + 0x3c))) {
        param_1 = uVar7;
      }
      iVar9 = iVar8 + (uVar11 + 3) * 0x10;
      iVar5 = *(int *)(uVar11 * 0x10 + iVar8 + 0x2c);
      uVar6 = uVar6 + 1;
      if (param_1 <= uVar7) {
        iVar5 = FUN_00048038(param_1 - iVar5);
        abStack_29[0] = bVar12 | (byte)(uVar10 + iVar5 << (*(uint *)(iVar8 + 0x28) & 0xff));
        if (*(int *)(iVar9 + 8) != 0) {
          abStack_29[0] = bVar1 ^ abStack_29[0];
        }
        break;
      }
      iVar5 = FUN_00048038((uVar7 + *(int *)(iVar9 + 4)) - iVar5);
      uVar10 = uVar10 + iVar5 & 0xff;
    }
    iVar5 = FUN_0004af3e(0x36,*(undefined1 *)(iVar8 + 0x18),abStack_29[0]);
    if (iVar5 != 0) {
      return -1;
    }
  }
  iVar5 = FUN_0004af2a(0x36,*(undefined1 *)(iVar8 + 0x20),abStack_29);
  if (iVar5 == 0) {
    abStack_29[0] = (byte)(1 << (*(uint *)(iVar8 + 0x24) & 0xff)) | abStack_29[0];
    iVar5 = FUN_0004af3e(0x36,*(undefined1 *)(iVar8 + 0x20),abStack_29[0]);
    return -(uint)(iVar5 != 0);
  }
  return -1;
}

//==== 0x5d72c  0x5d72c-0x5d73d inclusive
int FUN_0005d72c(undefined4 param_1,uint param_2,int param_3)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  byte bVar11;
  byte local_29 [5];
  
  iVar4 = DAT_0005d8b0/*"dcdc1"*/;
  if (*DAT_0005d740/*=0x83c10*/ != 0xe) {
    return -1;
  }
  iVar8 = 0;
  while( true ) {
    iVar7 = iVar8 * 0x6c + iVar4;
    uVar2 = FUN_000495f0(iVar7);
    iVar3 = FUN_000495ce(param_1,iVar7,uVar2);
    if (iVar3 == 0) break;
    iVar8 = iVar8 + 1;
    if (iVar8 == 0x24) {
      return -1;
    }
  }
  if (iVar7 == 0) {
    return -1;
  }
  if ((0 < (int)param_2) && (uVar5 = *(uint *)(iVar7 + 0x10), uVar5 != 0)) {
    if (param_2 < uVar5) {
      param_2 = uVar5;
    }
    else if (*(uint *)(iVar7 + 0x14) <= param_2) {
      param_2 = *(uint *)(iVar7 + 0x14);
    }
    iVar4 = FUN_0004af2a(0x36,*(undefined1 *)(iVar7 + 0x18),local_29);
    if (iVar4 != 0) {
      return -1;
    }
    bVar1 = *(byte *)(iVar7 + 0x1c);
    bVar11 = local_29[0] & ~bVar1;
    uVar5 = 0;
    uVar9 = 0;
    local_29[0] = bVar11;
    while( true ) {
      uVar10 = uVar5 & 0xff;
      uVar6 = *(uint *)(iVar7 + uVar10 * 0x10 + 0x30);
      if (uVar6 == 0) break;
      if ((uVar6 < param_2) && (param_2 < *(uint *)(iVar7 + uVar10 * 0x10 + 0x3c))) {
        param_2 = uVar6;
      }
      iVar8 = iVar7 + (uVar10 + 3) * 0x10;
      iVar4 = *(int *)(uVar10 * 0x10 + iVar7 + 0x2c);
      uVar5 = uVar5 + 1;
      if (param_2 <= uVar6) {
        iVar4 = FUN_00048038(param_2 - iVar4);
        local_29[0] = bVar11 | (byte)(uVar9 + iVar4 << (*(uint *)(iVar7 + 0x28) & 0xff));
        if (*(int *)(iVar8 + 8) != 0) {
          local_29[0] = bVar1 ^ local_29[0];
        }
        break;
      }
      iVar4 = FUN_00048038((uVar6 + *(int *)(iVar8 + 4)) - iVar4);
      uVar9 = uVar9 + iVar4 & 0xff;
    }
    iVar4 = FUN_0004af3e(0x36,*(undefined1 *)(iVar7 + 0x18),local_29[0]);
    if (iVar4 != 0) {
      return -1;
    }
  }
  if (param_3 < 0) {
    return 0;
  }
  iVar4 = FUN_0004af2a(0x36,*(undefined1 *)(iVar7 + 0x20),local_29);
  if (iVar4 != 0) {
    return -1;
  }
  bVar1 = (byte)(1 << (*(uint *)(iVar7 + 0x24) & 0xff));
  if (param_3 == 0) {
    local_29[0] = local_29[0] & ~bVar1;
  }
  else {
    local_29[0] = bVar1 | local_29[0];
  }
  iVar4 = FUN_0004af3e(0x36,*(undefined1 *)(iVar7 + 0x20),local_29[0]);
  return -(uint)(iVar4 != 0);
}

//==== 0x5d744  0x5d744-0x5d75b inclusive
undefined4 FUN_0005d744(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_0005d75c/*=0x83c10*/;
  *DAT_0005d75c/*=0x83c10*/ = 0xffffffff;
  iVar2 = FUN_0005d940();
  if (iVar2 == 0xe) {
    *puVar1 = 0xe;
    uVar3 = 0xe;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

//==== 0x5d940  0x5d940-0x5d9c5 inclusive
undefined4 FUN_0005d940(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  char cVar4;
  undefined4 uStack_c;
  
  uStack_c = param_2;
  iVar1 = FUN_0004af20(DAT_0005d9c8/*=0x61a80*/,0x36,param_3,param_4,param_1);
  if (iVar1 == 0) {
    iVar1 = FUN_0004af2a(0x36,0xe,(int)&uStack_c + 2);
    if (iVar1 == 0) {
      if (uStack_c._2_1_ == '\x03') {
        FUN_0004af2a(0x36,0x10,(int)&uStack_c + 3);
        uStack_c = uStack_c | 0x8000000;
        FUN_0004af3e(0x36,0x10);
        cVar3 = '\x13';
        do {
          FUN_0004af2a(0x36,cVar3,(int)&uStack_c + 3);
          cVar4 = cVar3 + '\x01';
          uStack_c = uStack_c | 0x80000000;
          FUN_0004af3e(0x36,cVar3);
          cVar3 = cVar4;
        } while (cVar4 != '\x1b');
        return 0xe;
      }
      uVar2 = DAT_0005d9d4/*"unknow PMU\n"*/;
    }
    else {
      uVar2 = DAT_0005d9d0/*"[pmu]: bus read error\n"*/;
    }
  }
  else {
    uVar2 = DAT_0005d9cc/*"[pmu]: bus init error\n"*/;
  }
  FUN_0004993c(uVar2);
  return 0xffffffff;
}

//==== 0x5d9d8  0x5d9d8-0x5d9ed inclusive
undefined4 FUN_0005d9d8(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00049d30(param_1 + 0x3006200);
  DataMemoryBarrier(0x1f);
  return *puVar1;
}

//==== 0x5d9ee  0x5d9ee-0x5d9ef inclusive
void FUN_0005d9ee(void)

{
  return;
}

//==== 0x5d9f0  0x5d9f0-0x5d9fd inclusive
uint FUN_0005d9f0(void)

{
  DataMemoryBarrier(0x1f);
  return *DAT_0005da00/*=0x3000024*/ & 7;
}

//==== 0x5da04  0x5da04-0x5da19 inclusive
int FUN_0005da04(uint param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_0005da1c/*=0x47000*/ + 0x31c);
  if ((iVar1 == 0) && (param_1 < 3)) {
    iVar1 = (int)*(short *)(DAT_0005da20/*=0x5e7cc*/ + param_1 * 2);
  }
  return iVar1;
}

//==== 0x5da24  0x5da24-0x5da3b inclusive
uint FUN_0005da24(uint param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(DAT_0005da3c/*=0x47000*/ + 800);
  if ((uVar1 == 0) && (param_1 < 3)) {
    uVar1 = (uint)*(ushort *)(DAT_0005da40/*=0x5e7cc*/ + param_1 * 2 + 6);
  }
  return uVar1;
}

//==== 0x5da44  0x5da44-0x5da5f inclusive
undefined4 FUN_0005da44(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(DAT_0005da60/*=0x47000*/ + 800) != 0) {
    return *(undefined4 *)(DAT_0005da60/*=0x47000*/ + 0x324);
  }
  if (param_1 - 1U < 2) {
    uVar1 = 0x6000;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

//==== 0x5da64  0x5da64-0x5da75 inclusive
byte FUN_0005da64(void)

{
  byte bVar1;
  
  bVar1 = *(byte *)(DAT_0005da78/*=0x47000*/ + 0x28) & 0xf;
  if (bVar1 == 1) {
    bVar1 = 3;
  }
  return bVar1;
}

//==== 0x5da7c  0x5da7c-0x5daa9 inclusive
void FUN_0005da7c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0005da64();
  FUN_0005d3b0(iVar1,DAT_0005daac/*=0x471f8*/,param_1);
  if (iVar1 == 0) {
    uVar2 = 1;
  }
  else {
    if (iVar1 == 2) {
      *(undefined4 *)(param_1 + 0xe4) = 2;
      return;
    }
    if (iVar1 != 3) {
      return;
    }
    uVar2 = 4;
  }
  *(undefined4 *)(param_1 + 0xe4) = uVar2;
  return;
}

//==== 0x5dab0  0x5dab0-0x5dafb inclusive
undefined4 FUN_0005dab0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 in_r3;
  
  piVar1 = DAT_0005dafc/*=0x83c14*/;
  if (*DAT_0005dafc/*=0x83c14*/ != 1) {
    iVar2 = FUN_0005da64();
    iVar3 = DAT_0005db00/*=0x47000*/;
    if (iVar2 < 0) {
      return 1;
    }
    iVar4 = DAT_0005db00/*=0x47000*/ + (iVar2 + 10) * 4;
    if (*(int *)(iVar4 + 0x1f8) == 0) {
      *(undefined4 *)(iVar4 + 0x1f8) = 4;
    }
    iVar3 = FUN_0005d528(iVar2,*(undefined4 *)(iVar3 + (iVar2 + 10) * 4 + 0x1f8),DAT_0005db04/*=0x470f8*/,0x10,
                         in_r3);
    if (iVar3 == -1) {
      return 2;
    }
    *piVar1 = 1;
  }
  return 0;
}

//==== 0x5db08  0x5db08-0x5db31 inclusive
uint FUN_0005db08(undefined4 param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_r2;
  undefined8 uVar3;
  
  if (param_2 == 1) {
    uVar3 = FUN_0005da64();
    iVar2 = FUN_0005baa8((int)uVar3,param_1,(int)((ulonglong)uVar3 >> 0x20),extraout_r2);
    uVar1 = (uint)(iVar2 == 0);
  }
  else {
    FUN_0004993c(DAT_0005db34/*"only read one sector\n"*/);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

//==== 0x5dc30  0x5db38-0x5dc09 inclusive
undefined4 FUN_0005dc30(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  int local_38 [5];
  
  thunk_FUN_00047c40(local_38,0,0x10);
  *(undefined4 *)(DAT_0005dc0c/*=0x83c14*/ + 4) = DAT_0005dc10/*=0x471f8*/;
  uVar3 = FUN_0005da64();
  iVar4 = FUN_0005dab0();
  uVar6 = DAT_0005dc2c/*=0x42e08000*/;
  iVar2 = DAT_0005dc28/*=0x89119800*/;
  iVar1 = DAT_0005dc14/*=0x42e00000*/;
  if (iVar4 == 0) {
    local_38[0] = FUN_0005da24(1);
    local_38[1] = FUN_0005da44(1);
    iVar4 = 0;
    do {
      iVar8 = local_38[iVar4];
      if (iVar8 == 0) {
        uVar6 = 4;
        goto LAB_0005db94;
      }
      iVar5 = FUN_0005baa8(uVar3,iVar8,0x40,DAT_0005dc14/*=0x42e00000*/);
      if (iVar5 == 0) {
LAB_0005db92:
        uVar6 = 3;
        goto LAB_0005db94;
      }
      if (*(int *)(iVar1 + 0x10) == iVar2) {
        uVar9 = *(uint *)(iVar1 + 0x24);
        if ((0x8000 < uVar9) &&
           (iVar8 = FUN_0005baa8(uVar3,iVar8 + 0x40,uVar9 - 0x7e01 >> 9,uVar6), iVar8 == 0))
        goto LAB_0005db92;
        iVar8 = FUN_00049990(iVar1,uVar9);
        if (iVar8 == 0) break;
        uVar7 = DAT_0005dc24/*"error:bad checksum.\n"*/;
      }
      else {
        uVar7 = DAT_0005dc20/*"error:bad magic.\n"*/;
      }
      iVar4 = iVar4 + 1;
      FUN_0004993c(uVar7);
    } while (iVar4 != 4);
    FUN_0005d6ac(uVar3,DAT_0005dc1c/*=0x470f8*/,0x10);
    uVar7 = 0;
  }
  else {
    uVar6 = 2;
LAB_0005db94:
    uVar7 = 0xffffffff;
    FUN_0004993c(DAT_0005dc18/*"Loading boot-pkg fail(error=%d)\n"*/,uVar6);
    FUN_0005d6ac(uVar3,DAT_0005dc1c/*=0x470f8*/,0x10);
  }
  return uVar7;
}

//==== 0x5dc3c  0x5dc3c-0x5dc5d inclusive
int FUN_0005dc3c(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00049d30((param_1 + 0x217000) * 0x200);
  thunk_FUN_00047d1c(param_3,uVar1,param_2 << 9);
  return param_2;
}

//==== 0x5dc5e  0x5dc5e-0x5dc71 inclusive
undefined4 FUN_0005dc5e(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00049d30((param_1 + 0x217000) * 0x200);
  return *(undefined4 *)(iVar1 + 0x2c);
}

//==== 0x5dc74  0x5dc74-0x5dc79 inclusive
undefined4 FUN_0005dc74(void)

{
  return *DAT_0005dc7c/*=0x83c1c*/;
}

//==== 0x5dc80  0x5dc80-0x5df69 inclusive
undefined4
FUN_0005dc80(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,undefined4 param_6,
            int *param_7)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint local_34;
  uint local_30;
  
  puVar1 = DAT_0005df6c/*=0x83c1c*/;
  FUN_00049aa8();
  iVar2 = FUN_00049d30(DAT_0005df70/*=0x42e00000*/);
  FUN_00049066();
  uVar3 = DAT_0005df74/*"sunxi-secure"*/;
  *puVar1 = 0xffffffff;
  uVar3 = FUN_000495f0(uVar3);
  iVar4 = FUN_000495ce(iVar2,DAT_0005df74/*"sunxi-secure"*/,uVar3);
  if (iVar4 == 0) {
    *puVar1 = 0x11;
  }
  iVar9 = 0;
  local_30 = 0;
  iVar4 = iVar2 + 0x40;
  do {
    if (*(uint *)(iVar2 + 0x20) <= local_30) {
      FUN_00049074();
      return 0;
    }
    if (*(int *)(iVar4 + 0x4c) == 3) {
      iVar5 = FUN_0005dc5e(*(uint *)(iVar4 + 0x40) >> 9);
      uVar3 = FUN_000495f0(iVar4);
      iVar6 = FUN_000495ce(iVar4,DAT_0005df78/*"u-boot"*/,uVar3);
      if (iVar6 == 0) {
        *param_1 = iVar5;
LAB_0005dd06:
        uVar7 = *(uint *)(iVar4 + 0x40);
        uVar8 = *(int *)(iVar4 + 0x44) + 0x1ff;
        goto LAB_0005dd10;
      }
      uVar3 = FUN_000495f0(iVar4);
      iVar6 = FUN_000495ce(iVar4,DAT_0005df7c/*"u-boot-gz"*/,uVar3);
      if (iVar6 == 0) {
LAB_0005dd26:
        iVar9 = FUN_0005e13c(param_1,param_2,param_3,param_4,param_5,param_6,param_7,iVar4,iVar2);
      }
      else {
        uVar3 = FUN_000495f0(iVar4);
        iVar6 = FUN_000495ce(iVar4,DAT_0005df80/*"u-boot-lz4"*/,uVar3);
        if (iVar6 == 0) goto LAB_0005dd26;
        uVar3 = FUN_000495f0(iVar4);
        iVar6 = FUN_000495ce(iVar4,DAT_0005df84/*"u-boot-lzma"*/,uVar3);
        if (iVar6 == 0) goto LAB_0005dd26;
        iVar6 = FUN_000495ce(iVar4,DAT_0005df88/*"optee"*/,6);
        if (iVar6 == 0) {
          iVar6 = *(int *)(iVar4 + 0x44);
          uVar7 = *(uint *)(iVar4 + 0x40);
          *param_2 = iVar5;
          FUN_0005dc3c(uVar7 >> 9,iVar6 + 0x1ffU >> 9,iVar5);
          uVar3 = FUN_00049aa8();
          thunk_FUN_00047d1c(iVar5 + 0x2c,uVar3,0x80);
          iVar5 = iVar5 + 0xec;
LAB_0005dda8:
          thunk_FUN_00047d1c(iVar5,DAT_0005df8c/*=0x470f0*/,8);
        }
        else {
          iVar6 = FUN_000495ce(iVar4,DAT_0005df90/*"monitor"*/,8);
          if (iVar6 == 0) {
            iVar6 = *(int *)(iVar4 + 0x44);
            uVar7 = *(uint *)(iVar4 + 0x40);
            *param_3 = iVar5;
            FUN_0005dc3c(uVar7 >> 9,iVar6 + 0x1ffU >> 9,iVar5);
            uVar3 = FUN_00049aa8();
            thunk_FUN_00047d1c(iVar5 + 0x30,uVar3,0x80);
            *(undefined4 *)(iVar5 + 0x2c) = *DAT_0005df94/*=0x83c20*/;
LAB_0005dde6:
            iVar5 = iVar5 + 0x24;
            goto LAB_0005dda8;
          }
          iVar6 = FUN_000495ce(iVar4,DAT_0005df98/*=0x6035d*/,4);
          if (iVar6 == 0) {
            iVar5 = iVar2 + 0x40;
            for (local_34 = 0; local_34 < *(uint *)(iVar2 + 0x20); local_34 = local_34 + 1) {
              iVar6 = FUN_000495ce(iVar5,DAT_0005df9c/*=0x60361*/,4);
              if (iVar6 == 0) {
                if (*(uint *)(iVar5 + 0x44) < 0x40001) {
                  FUN_0005dc3c(*(uint *)(iVar5 + 0x40) >> 9,*(uint *)(iVar5 + 0x44) + 0x1ff >> 9,
                               DAT_0005dfa4/*=0x48100000*/);
                }
                else {
                  FUN_0004993c(DAT_0005dfa8/*"error: dtb size larger than scp dts size\n"*/);
                }
                break;
              }
              iVar5 = iVar5 + 0x170;
            }
            if (local_34 == *(uint *)(iVar2 + 0x20)) {
              FUN_0004993c(DAT_0005dfac/*"error: dtb not found for scp\n"*/);
            }
            uVar7 = *(uint *)(iVar4 + 0x40);
            uVar8 = 0x268;
            iVar5 = DAT_0005dfa4/*=0x48100000*/;
LAB_0005de82:
            FUN_0005dc3c(uVar7 >> 9,uVar8,iVar5);
            goto LAB_0005de88;
          }
          iVar6 = FUN_000495ce(iVar4,DAT_0005df9c/*=0x60361*/,0x40);
          if (iVar6 == 0) {
            iVar6 = *param_3;
            iVar5 = *param_1 + 0x200000;
            *DAT_0005dfa0/*=0x82dc8*/ = iVar5;
            iVar6 = FUN_00049d30(iVar6);
            *(int *)(iVar6 + 0xb0) = iVar5;
            *param_7 = iVar5;
            goto LAB_0005dd06;
          }
          uVar3 = FUN_000495f0(DAT_0005dfb4/*"dtb-lzma"*/);
          iVar6 = FUN_000495ce(iVar4,DAT_0005dfb4/*"dtb-lzma"*/,uVar3);
          if (iVar6 == 0) goto LAB_0005dd26;
          uVar3 = FUN_000495f0(DAT_0005dfb8/*"dtb-lz4"*/);
          iVar6 = FUN_000495ce(iVar4,DAT_0005dfb8/*"dtb-lz4"*/,uVar3);
          if (iVar6 == 0) goto LAB_0005dd26;
          uVar3 = FUN_000495f0(DAT_0005dfbc/*"dtb-gz"*/);
          iVar6 = FUN_000495ce(iVar4,DAT_0005dfbc/*"dtb-gz"*/,uVar3);
          if (iVar6 == 0) goto LAB_0005dd26;
          iVar6 = FUN_000495ce(iVar4,DAT_0005dfc0/*"dtbo"*/,5);
          if (iVar6 == 0) {
            uVar7 = *(uint *)(iVar4 + 0x40);
            uVar8 = *(int *)(iVar4 + 0x44) + 0x1ff;
            iVar5 = *param_1 + 0x100000;
LAB_0005dd10:
            uVar8 = uVar8 >> 9;
            goto LAB_0005de82;
          }
          iVar6 = FUN_000495ce(iVar4,DAT_0005dfc4/*"logo"*/,5);
          if (iVar6 == 0) {
            iVar5 = *param_1;
            *(undefined4 *)(iVar5 + 0x300000) = *(undefined4 *)(iVar4 + 0x44);
            FUN_0005dc3c(*(uint *)(iVar4 + 0x40) >> 9,*(int *)(iVar4 + 0x44) + 0x1ffU >> 9,
                         iVar5 + 0x300010);
            FUN_00049a80(1);
          }
          else {
            iVar6 = FUN_000495ce(iVar4,DAT_0005dfc8/*"opensbi"*/,0x40);
            if (iVar6 == 0) {
              iVar6 = *(int *)(iVar4 + 0x44);
              uVar7 = *(uint *)(iVar4 + 0x40);
              *param_5 = iVar5;
              FUN_0005dc3c(uVar7 >> 9,iVar6 + 0x1ffU >> 9,iVar5);
              iVar6 = FUN_000495ce(iVar5 + 4,DAT_0005dfc8/*"opensbi"*/,7);
              if (iVar6 == 0) goto LAB_0005dde6;
            }
            else {
              iVar6 = FUN_000495ce(iVar4,DAT_0005e100/*"opensbi-gz"*/,0x40);
              if (((iVar6 == 0) || (iVar6 = FUN_000495ce(iVar4,DAT_0005e104/*"opensbi-lz4"*/,0x40), iVar6 == 0)) ||
                 (iVar6 = FUN_000495ce(iVar4,DAT_0005e108/*"opensbi-lzma"*/,0x40), iVar6 == 0)) goto LAB_0005dd26;
              iVar6 = FUN_000495ce(iVar4,DAT_0005e10c/*"rtos"*/,5);
              if ((iVar6 == 0) || (iVar6 = FUN_000495ce(iVar4,DAT_0005e110/*"melis"*/,6), iVar6 == 0)) {
                *param_4 = iVar5;
                goto LAB_0005dd06;
              }
              iVar6 = FUN_000495ce(iVar4,DAT_0005e114/*"melis-config"*/,0xd);
              if (iVar6 == 0) {
                FUN_0004993c(DAT_0005e118/*"image_base:%x\n"*/,0x43000000);
                thunk_FUN_00047d1c(0x43000000,local_30 * 0x170 + iVar2 + 0x84,4);
                uVar7 = *(uint *)(iVar4 + 0x40);
                uVar8 = *(int *)(iVar4 + 0x44) + 0x1ff;
                iVar5 = DAT_0005e11c/*=0x43000200*/;
                goto LAB_0005dd10;
              }
              iVar6 = FUN_000495ce(iVar4,DAT_0005e120/*"amp-arm"*/,8);
              if (iVar6 == 0) {
                thunk_FUN_00047d1c(iVar5,local_30 * 0x170 + iVar2 + 0x84,4);
                FUN_0005dc3c(*(uint *)(iVar4 + 0x40) >> 9,*(int *)(iVar4 + 0x44) + 0x1ffU >> 9,
                             0x50000000);
                FUN_00049d32(0x50000000);
                FUN_0004af60(DAT_0005e120/*"amp-arm"*/);
              }
              else {
                iVar5 = FUN_000495ce(iVar4,DAT_0005e124/*"melis-gz"*/,9);
                if (((iVar5 == 0) || (iVar5 = FUN_000495ce(iVar4,DAT_0005e128/*"rtos-gz"*/,8), iVar5 == 0)) ||
                   ((iVar5 = FUN_000495ce(iVar4,DAT_0005e12c/*"melis-lz4"*/,10), iVar5 == 0 ||
                    (((iVar5 = FUN_000495ce(iVar4,DAT_0005e130/*"rtos-lz4"*/,9), iVar5 == 0 ||
                      (iVar5 = FUN_000495ce(iVar4,DAT_0005e134/*"melis-lzma"*/,0xb), iVar5 == 0)) ||
                     (iVar5 = FUN_000495ce(iVar4,DAT_0005e138/*"rtos-lzma"*/,10), iVar5 == 0))))))
                goto LAB_0005dd26;
              }
            }
          }
        }
      }
LAB_0005de88:
      if (iVar9 != 0) {
        FUN_0004993c(DAT_0005dfb0/*"%s img load_comp_image fail \n"*/,iVar4);
      }
    }
    iVar4 = iVar4 + 0x170;
    local_30 = local_30 + 1;
  } while( true );
}

//==== 0x5e13c  0x5e13c-0x5e151 inclusive
undefined4 FUN_0005e13c(void)

{
  int in_stack_0000000c;
  int in_stack_00000010;
  
  if ((in_stack_0000000c == 0) || (in_stack_00000010 == 0)) {
    FUN_0004993c(DAT_0005e154/*"[erro] input toc1_item or bootpkg_base is null \n"*/);
  }
  return 0xffffffff;
}

//==== 0x5e158  0x5e158-0x5e3e7 inclusive
void FUN_0005e158(void)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  undefined1 uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  undefined2 local_46;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c [2];
  
  iVar11 = DAT_0005e3e8/*=0x47000*/;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c[0] = 0;
  local_46 = 0;
  FUN_00049a9c();
  uVar12 = *(undefined4 *)(iVar11 + 0xb8);
  FUN_0004a4ec(uVar12,iVar11 + 0xbc,6);
  FUN_000498e4(DAT_0005e3ec/*"......\n\n\n"*/);
  FUN_0004993c(DAT_0005e3f0/*"HELLO! BOOT0 is starting!\n"*/);
  FUN_0004993c(DAT_0005e3f4/*"BOOT0 commit : %s\n"*/,iVar11 + 0x2f8);
  FUN_00049898(*(undefined1 *)(iVar11 + 0x34),0);
  iVar7 = FUN_00048fac();
  if (iVar7 == 0) {
    iVar7 = FUN_0004a990();
    if (iVar7 == 0) {
      iVar7 = FUN_0004b290(&local_46);
      if (iVar7 == 0) {
        if (*(int *)(iVar11 + 0xcc) != 0) {
          FUN_0004a5cc(iVar11 + 0xd0,5,1);
        }
        iVar7 = FUN_00049a5c();
        if (iVar7 == 0x32) {
          uVar12 = DAT_0005e3fc/*"detected_f user input 2\n"*/;
        }
        else {
          FUN_00049ab4();
          uVar8 = FUN_00049aa8();
          iVar7 = FUN_00049bdc(0,uVar8);
          piVar1 = DAT_0005e404/*=0x83c20*/;
          if (iVar7 == 0) {
            uVar12 = DAT_0005e400/*"init dram fail\n"*/;
          }
          else {
            if (*(int *)(iVar11 + 0x318) != 0) {
              iVar7 = *(int *)(iVar11 + 0x318);
            }
            *DAT_0005e404/*=0x83c20*/ = iVar7;
            iVar9 = FUN_00049a5c();
            if (iVar9 != 0x32) {
              if (iVar9 == 100) {
                FUN_00049898(8,1);
                FUN_0004993c(DAT_0005e40c/*"detected user input d\n"*/);
              }
              else if (iVar9 == 0x71) {
                FUN_0004993c(DAT_0005e420/*"detected user input q\n"*/);
                FUN_00049898(0,1);
              }
              FUN_00048dfc(iVar7);
              FUN_00049d14(0x40800000,0x1000000);
              iVar10 = FUN_00049050();
              if ((iVar10 == 0) && (iVar10 = FUN_0005dc30(&local_44), iVar10 == 0)) {
                FUN_0005dc80(&local_44,&local_40,&local_3c,&local_38,&local_34,&local_30,local_2c);
                iVar4 = local_3c;
                iVar3 = local_40;
                iVar10 = local_44;
                uVar2 = local_46;
                if ((local_38 == 0) && (local_44 != 0)) {
                  FUN_00049da0(local_44 + 0x1ff000);
                  uVar8 = *(undefined4 *)(DAT_0005e410/*=0x42e00000*/ + 0x24);
                  *(int *)(iVar10 + 0x4f8) = iVar7;
                  *(undefined4 *)(iVar10 + 0x4f4) = uVar8;
                  uVar8 = FUN_00049aa8();
                  thunk_FUN_00047d1c(iVar10 + 0x30,uVar8,0x80);
                  if (iVar4 != 0) {
                    *(undefined1 *)(iVar10 + 0x4e9) = 1;
                  }
                  if (iVar3 != 0) {
                    *(undefined1 *)(iVar10 + 0x4e8) = 1;
                    uVar8 = *(undefined4 *)(iVar11 + 0x32c);
                    *(int *)(iVar3 + 0xc) = iVar7;
                    *(char *)(iVar3 + 0x10c) = (char)uVar12;
                    *(undefined4 *)(iVar3 + 0x10) = uVar8;
                  }
                  bVar5 = FUN_00049a90(0xff);
                  *(byte *)(iVar10 + 0x4ea) = bVar5 | *(byte *)(iVar10 + 0x4ea);
                  FUN_0005da7c(iVar10);
                  uVar8 = DAT_0005e414/*=0x470bc*/;
                  *(undefined4 *)(iVar10 + 0xb8) = uVar12;
                  thunk_FUN_00047d1c(iVar10 + 0xbc,uVar8,0x10);
                  *(short *)(iVar10 + 0x502) = (short)iVar9;
                  *(undefined2 *)(iVar10 + 0x500) = 0;
                  *(undefined2 *)(iVar10 + 0x504) = uVar2;
                  uVar6 = FUN_000498cc();
                  *(undefined1 *)(iVar10 + 0x507) = uVar6;
                  iVar11 = FUN_0005dc74();
                  if (iVar11 != -1) {
                    uVar12 = FUN_0005dc74();
                    *(undefined4 *)(iVar10 + 0xe0) = uVar12;
                  }
                  *(char *)(iVar10 + 0x4eb) = (char)piVar1[1];
                }
                iVar11 = FUN_00049bbc(local_44,local_40,local_3c,local_38,local_34,local_30);
                if (iVar11 == 0) {
                  FUN_00048e8c();
                  iVar11 = local_3c;
                  if (local_3c == 0) {
                    if (local_40 == 0) {
                      if (local_38 == 0) {
                        FUN_0004993c(DAT_0005e42c/*"Jump to U-Boot: uboot_base = 0x%x\n"*/,local_44);
                        iVar11 = local_44;
                      }
                      else {
                        FUN_0004993c(DAT_0005e428/*"Jump to RTOS: rtos_base = 0x%x\n"*/);
                        iVar11 = local_38;
                      }
                      FUN_00048ec6(iVar11);
                    }
                    else {
                      FUN_0004993c(DAT_0005e424/*"Jump to OPTEE: optee_base = 0x%x, uboot_base = 0x%x\n"*/,local_40,local_44);
                      FUN_00048ed2(local_40,local_44);
                    }
                  }
                  else {
                    *(int *)(local_3c + 0x18) = local_40;
                    *(int *)(local_3c + 0x10) = local_44;
                    uVar12 = FUN_0004af58();
                    thunk_FUN_00047d1c(iVar11 + 0xb8,uVar12,0x10);
                    FUN_0004993c(DAT_0005e418/*"Jump to ATF: monitor_base = 0x%x, uboot_base = 0x%x, optee_base = 0x%x"*/,local_3c,local_44,local_40);
                    FUN_00048ee0(local_3c);
                  }
                  FUN_0004993c(DAT_0005e41c/*"Jump to second boot failed! Stay in the loop...\n"*/);
                  do {
                    /* WARNING: Do nothing block with infinite loop */
                  } while( true );
                }
              }
              goto LAB_0005e1b8;
            }
            FUN_00049898(3,0);
            uVar12 = DAT_0005e408/*"detected_r user input 2\n"*/;
          }
        }
        FUN_0004993c(uVar12);
      }
    }
    else {
      FUN_0004aa08();
    }
  }
LAB_0005e1b8:
  FUN_0004993c(DAT_0005e3f8/*"Failed preparing the second boot\n"*/);
  FUN_00049062();
  FUN_00049504();
  FUN_00048e8c();
  FUN_00048da4(10);
  FUN_00048ec6(0x20);
  return;
}
