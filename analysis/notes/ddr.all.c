
//==== 0x90000  0x90000-0x90003 inclusive
void thunk_FUN_00090004(void)

{
  uint uVar1;
  
  FUN_00090038();
  FUN_00090488();
  coproc_moveto_Invalidate_Entire_Instruction(0);
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  uVar1 = coproc_movefrom_Control();
  coproc_moveto_Control(uVar1 & 0xffffefff);
  InstructionSynchronizationBarrier(0xf);
  return;
}

//==== 0x90004  0x90004-0x90037 inclusive
void FUN_00090004(void)

{
  uint uVar1;
  
  FUN_00090038();
  FUN_00090488();
  coproc_moveto_Invalidate_Entire_Instruction(0);
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  uVar1 = coproc_movefrom_Control();
  coproc_moveto_Control(uVar1 & 0xffffefff);
  InstructionSynchronizationBarrier(0xf);
  return;
}

//==== 0x90038  0x90038-0x90053 inclusive
void FUN_00090038(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = DAT_00090058/*=0xc94a4*/;
  puVar2 = DAT_00090054/*=0xc8bdc*/;
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  } while ((int)puVar2 < iVar1);
  return;
}

//==== 0x9005c  0x9005c-0x90091 inclusive
void FUN_0009005c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int local_18;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined4 local_c;
  
  piVar1 = DAT_0009009c/*=0xc8bdc*/;
  local_18 = param_1;
  local_14 = param_2;
  uStack_10 = param_3;
  local_c = param_4;
  iVar2 = FUN_000936d4(DAT_00090098/*"serial"*/,DAT_00090094/*"devnum"*/);
  *piVar1 = iVar2;
  if ((-1 < iVar2) && (local_18 = FUN_000936d4(DAT_00090098/*"serial"*/,DAT_000900a0/*"baudrate"*/), -1 < local_18)) {
    local_14 = 3;
    uStack_10 = 0;
    local_c = 0;
    FUN_00091088(*piVar1,&local_18);
  }
  return;
}

//==== 0x900c0  0x900c0-0x900e3 inclusive
int FUN_000900c0(undefined4 param_1,uint3 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_c = (uint)param_2;
  uStack_8 = param_3;
  iVar1 = FUN_00091120(*DAT_000900e4/*=0xc8bdc*/,(int)&uStack_c + 3,1,DAT_000900e4/*=0xc8bdc*/,param_1);
  if (iVar1 == 1) {
  }
  else {
    uStack_c._3_1_ = (char)iVar1;
  }
  return (int)uStack_c._3_1_;
}

//==== 0x900e8  0x900e8-0x9013d inclusive
int FUN_000900e8(int *param_1,uint param_2,int param_3)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  uVar1 = param_2 >> 4;
  iVar3 = 0;
  piVar2 = param_1;
  while (piVar2 + 4 != param_1 + uVar1 * 4 + 4) {
    iVar3 = iVar3 + *piVar2 + piVar2[1] + piVar2[2] + piVar2[3];
    piVar2 = piVar2 + 4;
  }
  param_1 = param_1 + uVar1 * 4;
  piVar2 = param_1 + uVar1 * -4 + (param_2 >> 2);
  for (; param_1 != piVar2; param_1 = param_1 + 1) {
    iVar3 = iVar3 + *param_1;
  }
  return (DAT_00090140/*=0x5f0a6c39*/ - param_3) + iVar3;
}

//==== 0x90164  0x90164-0x90183 inclusive
bool FUN_00090164(void)

{
  int iVar1;
  
  FUN_00090690(DAT_00090184/*"check_fel"*/);
  iVar1 = FUN_000900c0();
  if (iVar1 == 0x32) {
    FUN_00092a80(3,DAT_00090188/*"Detected user input 2\n"*/);
  }
  return iVar1 == 0x32;
}

//==== 0x9018c  0x9018c-0x9019f inclusive
void FUN_0009018c(void)

{
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 in_r3;
  
  FUN_00092a80(3,DAT_000901a0/*"Jump to FEL...\n"*/);
  FUN_00091ebc(0,extraout_r1,extraout_r2,in_r3);
  return;
}

//==== 0x901a4  0x901a4-0x9023f inclusive
undefined4 FUN_000901a4(uint *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  
  uVar4 = FUN_00093508(DAT_00090244/*"/dram_select"*/,DAT_00090240/*"pins"*/,6);
  uVar3 = DAT_00090254/*"cur pin val %d\n"*/;
  uVar2 = DAT_00090244/*"/dram_select"*/;
  uVar1 = DAT_00090240/*"pins"*/;
  if ((int)uVar4 < 1) {
    FUN_00092a80(3,DAT_00090248/*"No GPIO found in '%s'\n"*/,DAT_00090240/*"pins"*/);
  }
  else {
    if ((int)uVar4 < 5) {
      uVar7 = 0;
      uVar6 = 0;
      do {
        iVar5 = FUN_00093590(uVar2,uVar1,&local_38,uVar6);
        if (iVar5 < 0) {
          FUN_00092a80(3,DAT_00090250/*"Failed to get GPIO[%d]\n"*/,uVar6);
          return 0xfffffffb;
        }
        FUN_00090ad8(&local_38);
        FUN_00090ad0(local_38,uStack_34,&local_3c);
        FUN_00092a80(3,uVar3,local_3c);
        if (local_3c != 0) {
          uVar7 = uVar7 | 1 << (uVar6 & 0xff);
        }
        uVar6 = uVar6 + 1;
      } while (uVar4 != uVar6);
      *param_1 = uVar7;
      return 0;
    }
    FUN_00092a80(3,DAT_0009024c/*"GPIO count > max(%d), truncated in '%s'\n"*/,4,DAT_00090240/*"pins"*/);
  }
  return 0xffffffea;
}

//==== 0x90258  0x90258-0x90303 inclusive
int FUN_00090258(undefined4 param_1,uint *param_2)

{
  ushort uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  ushort *puVar6;
  uint uVar7;
  uint local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c [2];
  
  puVar2 = DAT_00090304/*=0xa6738*/;
  iVar3 = FUN_000934c0(*DAT_00090304/*=0xa6738*/,param_1,DAT_00090308/*"channel"*/,&local_28);
  if (iVar3 < 0) {
    uVar5 = DAT_00090308/*"channel"*/;
  }
  else {
    iVar3 = FUN_000934c0(*puVar2,param_1,DAT_00090310/*=0xa4cd1*/,&local_20);
    if (iVar3 < 0) {
      uVar5 = DAT_00090310/*=0xa4cd1*/;
    }
    else {
      iVar3 = FUN_0009347a(*puVar2,local_20);
      if (iVar3 < 0) {
        return iVar3;
      }
      iVar3 = FUN_000934c0(*puVar2,iVar3,DAT_00090314/*"devnum"*/,&local_24);
      if (-1 < iVar3) {
        iVar3 = FUN_000918e4(0,local_24);
        if (iVar3 != 0) {
          FUN_00092a80(3,DAT_00090318/*"GPADC init failed\n"*/);
          return -5;
        }
        FUN_00091900(0,local_24,local_28 & 0xf,local_1c);
        uVar7 = 0;
        puVar6 = DAT_0009031c/*=0xa439a*/;
        do {
          uVar1 = *puVar6;
          uVar4 = uVar7 & 0xff;
          puVar6 = puVar6 + 1;
          if (local_1c[0] < (uint)*puVar6 + (uint)uVar1 >> 1) goto LAB_00090300;
          uVar7 = uVar7 + 1;
        } while (uVar7 != 7);
        uVar4 = 7;
LAB_00090300:
        *param_2 = uVar4;
        return 0;
      }
      uVar5 = DAT_00090314/*"devnum"*/;
    }
  }
  FUN_00092a80(3,DAT_0009030c/*"Missing property '%s'\n"*/,uVar5);
  return -0x16;
}

//==== 0x90320  0x90320-0x90371 inclusive
int FUN_00090320(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_1c;
  int local_18;
  int iStack_14;
  
  puVar1 = DAT_000903c4/*=0xa6738*/;
  if (param_1 == (int *)0x0) {
    return -0x16;
  }
  *param_1 = 0;
  local_1c = param_2;
  local_18 = param_3;
  iStack_14 = param_4;
  iVar2 = FUN_00093460(*puVar1,DAT_000903c8/*"/dram_select"*/,param_3,0,param_1);
  if (iVar2 < 0) {
    FUN_00092a80(3,DAT_000903cc/*"Node '%s' not found\n"*/,DAT_000903c8/*"/dram_select"*/);
    return iVar2;
  }
  iVar3 = FUN_000934c0(*puVar1,iVar2,DAT_000903d0/*"select-mode"*/,&local_1c);
  if (iVar3 < 0) {
    uVar4 = DAT_000903d4/*"Missing property '%s'\n"*/;
    uVar5 = DAT_000903d0/*"select-mode"*/;
LAB_0009035c:
    FUN_00092a80(3,uVar4,uVar5);
    return -0x16;
  }
  switch(local_1c) {
  case 0:
    return 0;
  case 1:
    iVar2 = FUN_000901a4(param_1);
    break;
  case 2:
    iVar2 = FUN_00090258(iVar2,param_1);
    break;
  case 3:
    local_18 = 0;
    iStack_14 = 0;
    iVar3 = FUN_000901a4(&local_18);
    if ((iVar3 == 0) && (iVar3 = FUN_00090258(iVar2,&iStack_14), iVar3 == 0)) {
      *param_1 = iStack_14 + local_18 * 8;
      FUN_00092a80(3,DAT_000903d8/*"adc_idx %d gpio_idx %d\n"*/);
    }
    return iVar3;
  default:
    uVar4 = DAT_000903dc/*"Invalid DRAM select mode: %u\n"*/;
    uVar5 = local_1c;
    goto LAB_0009035c;
  }
  return iVar2;
}

//==== 0x903e0  0x903e0-0x903e3 inclusive
undefined4 FUN_000903e0(void)

{
  return DAT_000903e4/*=0xc8fe0*/;
}

//==== 0x903e8  0x903e8-0x9040b inclusive
void FUN_000903e8(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_00090410/*"bootpara"*/;
  iVar1 = DAT_0009040c/*=0xc8be0*/;
  *(uint *)(DAT_0009040c/*=0xc8be0*/ + 0x18) = *(uint *)(DAT_0009040c/*=0xc8be0*/ + 0x18) | 1;
  FUN_00092b08(iVar1,uVar2);
  uVar2 = FUN_000900e8(iVar1,0x800,*(undefined4 *)(iVar1 + 0xc));
  *(undefined4 *)(iVar1 + 0xc) = uVar2;
  return;
}

//==== 0x90424  0x90424-0x90469 inclusive
int FUN_00090424(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = DAT_00090470/*=0xc8be0*/;
  piVar1 = DAT_0009046c/*=0xc93e0*/;
  iVar4 = *DAT_0009046c/*=0xc93e0*/;
  if (iVar4 == 0) {
    iVar4 = FUN_00092b76(DAT_00090470/*=0xc8be0*/,DAT_00090474/*"bootpara"*/);
    uVar3 = DAT_0009047c/*"boot params magic check is failed\n"*/;
    if (iVar4 == 0) {
      uVar3 = *(undefined4 *)(iVar2 + 0xc);
      *piVar1 = 1;
      iVar4 = FUN_000900e8(iVar2,0x800,uVar3);
      if (iVar4 == *(int *)(iVar2 + 0xc)) {
        *piVar1 = 0;
        uVar3 = DAT_00090478/*"boot params spl addsum check is failed\n"*/;
      }
      else {
        *piVar1 = 0;
        uVar3 = DAT_00090480/*"boot params addsum check is failed\n"*/;
      }
    }
    else {
      *piVar1 = 0;
    }
    FUN_00092a80(3,uVar3);
    iVar4 = *piVar1;
  }
  return iVar4;
}

//==== 0x90484  0x90484-0x90485 inclusive
void FUN_00090484(void)

{
  return;
}

//==== 0x90488  0x90488-0x9053f inclusive
undefined4 FUN_00090488(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  *DAT_00090540/*=0xa6738*/ = DAT_00090544/*=0xc8040*/;
  iVar3 = FUN_00092574();
  if (iVar3 == 0) {
    FUN_00092a5c(DAT_00090548/*"......\n\n\n"*/);
    FUN_00092a80(3,DAT_00090554/*"SPL-2.0 - %s %s %s\n"*/,DAT_00090550/*"preboot"*/,DAT_00090558/*"2026-06-17 10:06:51 +0800"*/,DAT_0009054c/*"{853efe0f-dirty}"*/,param_2);
    iVar3 = thunk_FUN_00092044();
    if ((iVar3 == 0) && (iVar3 = FUN_00090164(), puVar1 = DAT_0009055c/*=0xc93e4*/, iVar3 == 0)) {
      FUN_00090484();
      iVar3 = FUN_00090750(puVar1);
      if (iVar3 == 0) {
        FUN_00092a80(3,DAT_00090560/*"DRAM size %d MB\n"*/,*puVar1);
        iVar3 = FUN_00090650();
        if (iVar3 != 0) {
          FUN_00090668();
          return *puVar1;
        }
        uVar4 = FUN_00091ebc(thunk_FUN_00090004);
        uVar2 = DAT_00090560/*"DRAM size %d MB\n"*/;
        *puVar1 = uVar4;
        FUN_00092a80(3,uVar2,uVar4);
        FUN_00092cf4(0x40800000,0x1000000);
        iVar3 = FUN_00091ed0(*puVar1);
        if (iVar3 == 0) {
          FUN_00090692();
          FUN_000905a4(DAT_00090564/*=0xc93e8*/);
          FUN_000925ec();
          FUN_00090694();
          FUN_00091f80();
          FUN_00092600();
          FUN_00092a80(3,DAT_00090568/*"ERROR! Should not get here\n"*/);
        }
      }
    }
  }
  FUN_00092a80(3,DAT_0009056c/*"ERROR! to run fel now...\n"*/);
  FUN_0009018c();
  return 0;
}

//==== 0x90570  0x90570-0x9059b inclusive
byte FUN_00090570(void)

{
  byte bVar1;
  
  bVar1 = *(byte *)(DAT_0009059c/*=0xa56e0*/ + 0x28) & 0xf;
  if (bVar1 != 2) {
    if (bVar1 == 5) {
      bVar1 = 8;
    }
    else if ((*(byte *)(DAT_0009059c/*=0xa56e0*/ + 0x28) & 0xf) == 0) {
      bVar1 = 1;
    }
    else {
      FUN_00092a80(3,DAT_000905a0/*"storage_type(%d) not support now"*/,bVar1);
    }
  }
  return bVar1;
}

//==== 0x905a4  0x90414-0x9041d inclusive
void FUN_000905a4(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_00090690(DAT_0009060c/*"jump_prepare"*/);
  if (param_1[3] != 0) {
    return;
  }
  iVar2 = *param_1;
  if (iVar2 == 0) {
    FUN_00092a80(3,DAT_00090610/*"uboot base or toc1 base is NULL\n"*/);
  }
  else {
    *(undefined4 *)(iVar2 + 0x4f4) = *(undefined4 *)(DAT_00090614/*=0x42e00000*/ + 0x24);
    *(undefined4 *)(iVar2 + 0x4f8) = *DAT_00090618/*=0xc93e4*/;
    if (param_1[1] != 0) {
      *(undefined1 *)(iVar2 + 0x4e9) = 1;
    }
    if (param_1[2] != 0) {
      *(undefined1 *)(iVar2 + 0x4e8) = 1;
    }
    uVar1 = FUN_00090570();
    *(undefined4 *)(iVar2 + 0xe4) = uVar1;
    *(undefined4 *)(iVar2 + 0xb8) = 0;
  }
  FUN_000903e8();
  FUN_00092c40(*param_1 + 0x1ff000,DAT_00090420/*=0xc8be0*/,0x800,param_4);
  return;
}

//==== 0x9061c  0x9061c-0x9062d inclusive
bool FUN_0009061c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_00092b76(DAT_00090634/*"preboot"*/,DAT_00090630/*=0xa45de*/,param_3,param_4,param_4);
  return iVar1 == 0;
}

//==== 0x90638  0x90638-0x90649 inclusive
bool FUN_00090638(void)

{
  int iVar1;
  
  iVar1 = FUN_00092b76(DAT_0009064c/*"preboot"*/);
  return iVar1 == 0;
}

//==== 0x90650  0x90650-0x90667 inclusive
undefined4 FUN_00090650(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0009061c();
  if (iVar1 == 0) {
    iVar1 = FUN_00090638();
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

//==== 0x90668  0x90668-0x90683 inclusive
void FUN_00090668(void)

{
  int iVar1;
  undefined4 in_r3;
  
  iVar1 = FUN_00092b76(DAT_00090688/*"preboot"*/,DAT_00090684/*=0xa45de*/);
  if (iVar1 == 0) {
    FUN_000903e8();
    FUN_00092c40(DAT_0009068c/*=0x40800080*/,DAT_00090420/*=0xc8be0*/,0x800,in_r3);
    return;
  }
  return;
}

//==== 0x90690  0x90690-0x90691 inclusive
void FUN_00090690(void)

{
  return;
}

//==== 0x90692  0x90692-0x90693 inclusive
void FUN_00090692(void)

{
  return;
}

//==== 0x90694  0x90694-0x90695 inclusive
void FUN_00090694(void)

{
  return;
}

//==== 0x90698  0x90698-0x90731 inclusive
int FUN_00090698(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  local_24 = param_2;
  uStack_20 = param_3;
  uStack_1c = param_4;
  iVar3 = FUN_00090424();
  puVar2 = DAT_0009074c/*=0xa6738*/;
  piVar1 = DAT_00090734/*=0xc9400*/;
  if (iVar3 == 0) {
    local_24 = iVar3;
    if (*DAT_00090734/*=0xc9400*/ == 0) {
      iVar3 = FUN_00093460(*DAT_0009074c/*=0xa6738*/,DAT_00090738/*"/dram"*/);
      if (iVar3 < 0) {
        FUN_00092a80(3,DAT_0009073c/*"Init dram failed while parsing '/dram'\n"*/);
      }
      else {
        iVar5 = FUN_00090320(&local_24);
        if (iVar5 != 0) {
          FUN_00092a80(3,DAT_00090740/*"Get dram select index err\n"*/);
          return iVar5;
        }
        FUN_000929d4(&uStack_20,DAT_00090744/*"para%d"*/,local_24);
        uVar6 = *puVar2;
        uVar4 = FUN_000903e0();
        iVar3 = FUN_000934c0(uVar6,iVar3,&uStack_20,uVar4);
        if (-1 < iVar3) {
          uVar4 = FUN_000903e0();
          *param_1 = uVar4;
          *piVar1 = 1;
          return 0;
        }
        FUN_00092a80(3,DAT_00090748/*"Init dram failed while parsing %s \n"*/,&uStack_20);
      }
    }
    else {
      uVar4 = FUN_000903e0();
      *param_1 = uVar4;
      iVar3 = 0;
    }
  }
  else {
    iVar3 = 0;
    uVar4 = FUN_000903e0();
    *param_1 = uVar4;
  }
  return iVar3;
}

//==== 0x90750  0x90750-0x9079d inclusive
int FUN_00090750(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_14;
  undefined4 uStack_10;
  
  local_14 = 0;
  uStack_10 = param_3;
  FUN_00090690(DAT_000907a0/*"dram_init"*/);
  iVar1 = FUN_00090698(&local_14);
  if (iVar1 == 0) {
    if (*(code **)(DAT_000907a4/*=0xc8008*/ + 4) != (code *)0x0) {
      iVar2 = (**(code **)(DAT_000907a4/*=0xc8008*/ + 4))(local_14);
      *param_1 = iVar2;
    }
    if (*param_1 == 0) {
      iVar1 = -1;
      FUN_00092a80(3,DAT_000907a8/*"Invalid dram_size = 0\n"*/);
    }
    else {
      iVar2 = FUN_00090650();
      if (iVar2 != 0) {
        *DAT_000907ac/*=0x40000010*/ = *param_1;
      }
    }
  }
  return iVar1;
}

//==== 0x907b0  0x907b0-0x907b7 inclusive
uint FUN_000907b0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar5;
  uint *puVar4;
  
  FUN_00092a38(DAT_000a02f4/*"DRAM BOOT DRIVE INFO: %s\n"*/,DAT_000a02f8/*"V0.6036"*/,param_3,param_4,0,param_1,param_3);
  puVar4 = DAT_000a02fc/*=0x3000160*/;
  *DAT_000a02fc/*=0x3000160*/ = *DAT_000a02fc/*=0x3000160*/ | 0x100;
  puVar4[2] = puVar4[2] & 0xffffff00;
  if (((param_1[1] == 8) && (-1 < (int)param_1[0x17])) && (-1 < (int)(param_1[0x1b] << 2))) {
    uVar3 = param_1[0x1a] & 0x7f;
    puVar4 = param_1 + 0x20;
    do {
      puVar5 = puVar4 + 1;
      *puVar4 = uVar3 << 0x10 | uVar3 << 8 | uVar3 | uVar3 << 0x18;
      puVar4 = puVar5;
    } while (puVar5 != param_1 + 0x32);
    uVar3 = (uint)*(byte *)(param_1 + 0x12);
    param_1[0x32] = uVar3 << 0x10 | uVar3 << 8 | uVar3 | uVar3 << 0x18;
  }
  iVar1 = FUN_00093890(param_1);
  if ((iVar1 != 0) &&
     (((int)(param_1[0x1e] << 0x1f) < 0 || (iVar1 = FUN_000a0148(param_1), iVar1 != 0)))) {
    FUN_00092a38(DAT_000a0300/*"DRAM CLK =%d MHZ\n"*/,*param_1);
    FUN_00092a38(DAT_000a0304/*"DRAM Type =%d (8:LPDDR4,9:LPDDR5)\n"*/,param_1[1]);
    iVar1 = FUN_0009fe7c(param_1);
    if (iVar1 == 0) {
      FUN_00092a38(DAT_000a0308/*"DRAM initial error : 1 !\n"*/);
    }
    else {
      if ((-1 < (int)param_1[0x17]) && ((int)(param_1[0x1b] << 2) < 0)) {
        FUN_0009f9e4(param_1);
        if (-1 < (int)(param_1[0x1b] << 1)) {
          param_1[0x1b] = param_1[0x1b] & 0xdfffffff;
        }
      }
      if ((int)param_1[7] < 0) {
        uVar3 = (param_1[7] & 0x7fffffff) >> 0x10;
      }
      else {
        uVar3 = FUN_000939c4(param_1);
        FUN_00092a38(DAT_000a0310/*"Actual DRAM SIZE =%d M\n"*/,uVar3);
        param_1[7] = (uint)*(ushort *)(param_1 + 7) | uVar3 << 0x10;
      }
      FUN_00092a38(DAT_000a030c/*"DRAM SIZE =%d MBytes, para1 = %x, para2 = %x, dram_tpr13 = %x\n"*/,uVar3,param_1[6],param_1[7],param_1[0x1e]);
      uVar2 = uVar3;
      if (0x1000 < uVar3) {
        uVar2 = 0x1000;
      }
      iVar1 = FUN_00093744(uVar2);
      if (iVar1 == 0) {
        return uVar3;
      }
    }
  }
  return 0;
}

//==== 0x907b8  0x907b8-0x907eb inclusive
undefined4 FUN_000907b8(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined8 uVar10;
  
  piVar4 = DAT_0009084c/*=0xc8010*/;
  do {
    if (piVar4 == DAT_00090850/*=0xc8020*/) {
LAB_000907d0:
      uVar1 = DAT_00090854/*"Unsupported GPIO hardware type: %u\n"*/;
LAB_000907d2:
      FUN_00092a80(3,uVar1);
      return 0xffffffea;
    }
    if (param_1[3] == *piVar4) {
      piVar4 = (int *)piVar4[1];
      if (piVar4 != (int *)0x0) {
        switch(param_1[4]) {
        case 0:
          iVar2 = piVar4[2];
          iVar6 = piVar4[3];
          iVar8 = piVar4[4];
          iVar7 = piVar4[1];
          break;
        case 1:
          iVar2 = piVar4[6];
          iVar6 = piVar4[7];
          iVar8 = piVar4[8];
          iVar7 = piVar4[5];
          break;
        case 2:
          iVar2 = piVar4[10];
          iVar6 = piVar4[0xb];
          iVar8 = piVar4[0xc];
          iVar7 = piVar4[9];
          break;
        case 3:
          iVar2 = piVar4[0xe];
          iVar6 = piVar4[0xf];
          iVar8 = piVar4[0x10];
          iVar7 = piVar4[0xd];
          break;
        default:
          uVar1 = DAT_00090858/*"Reg_type %u not exist\n"*/;
          goto LAB_000907d2;
        }
        uVar9 = param_1[5];
        iVar5 = piVar4[0x11];
        if (10 < uVar9) {
          uVar9 = uVar9 - 0xb;
        }
        iVar3 = iVar5 * uVar9 + *param_1 + *piVar4;
        param_1[8] = iVar3;
        param_1[9] = iVar8;
        uVar10 = FUN_000a39ac(param_1[6],iVar2,iVar3,iVar5,param_4);
        param_1[10] = iVar7 + (int)uVar10 * 4;
        param_1[0xb] = iVar6 * (int)((ulonglong)uVar10 >> 0x20);
        return 0;
      }
      goto LAB_000907d0;
    }
    piVar4 = piVar4 + 2;
  } while( true );
}

//==== 0x9085c  0x9085c-0x90899 inclusive
int FUN_0009085c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_000907b8();
  if (iVar1 == 0) {
    if (*(uint *)(param_1 + 0x24) < *(uint *)(param_1 + 0x1c)) {
      FUN_00092a80(3,DAT_0009089c/*"Invalid Data %u\n"*/);
      iVar1 = -0x16;
    }
    else {
      DataMemoryBarrier(0x1f);
      DataMemoryBarrier(0x1f);
      *(uint *)(*(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x28)) =
           *(uint *)(param_1 + 0x1c) << (*(uint *)(param_1 + 0x2c) & 0xff) |
           *(uint *)(*(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x28)) &
           ~(*(uint *)(param_1 + 0x24) << (*(uint *)(param_1 + 0x2c) & 0xff));
    }
  }
  return iVar1;
}

//==== 0x908a0  0x908a0-0x908d3 inclusive
int FUN_000908a0(int param_1,uint *param_2)

{
  int iVar1;
  
  if (param_2 == (uint *)0x0) {
    FUN_00092a80(3,DAT_000908d4/*"NULL pointer passed to gpio_get_cfg\n"*/);
    iVar1 = -0x16;
  }
  else {
    iVar1 = FUN_000907b8();
    if (iVar1 == 0) {
      DataMemoryBarrier(0x1f);
      *param_2 = *(uint *)(*(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x28)) >>
                 (*(uint *)(param_1 + 0x2c) & 0xff) & *(uint *)(param_1 + 0x24);
    }
  }
  return iVar1;
}

//==== 0x908d8  0x908d8-0x90937 inclusive
undefined4 FUN_000908d8(uint param_1,uint param_2,int param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  if (((*DAT_00090938/*=0xc9404*/ == 0) || (param_1 < (uint)DAT_00090938/*=0xc9404*/[1])) ||
     ((uint)DAT_00090938/*=0xc9404*/[2] < param_1)) {
    if (((DAT_00090938/*=0xc9404*/[4] == 0) || (param_1 < (uint)DAT_00090938/*=0xc9404*/[5])) ||
       ((uint)DAT_00090938/*=0xc9404*/[6] < param_1)) {
      uVar1 = DAT_0009093c/*"Invalid GPIO bank %u\n"*/;
      param_2 = param_1;
      goto LAB_00090908;
    }
    iVar3 = 1;
  }
  else {
    iVar3 = 0;
  }
  if (param_2 < 0x20) {
    piVar5 = DAT_00090938/*=0xc9404*/ + iVar3 * 4;
    iVar3 = *piVar5;
    iVar2 = piVar5[1];
    iVar4 = piVar5[2];
    iVar6 = piVar5[3];
    param_4[4] = param_3;
    param_4[5] = param_1;
    param_4[6] = param_2;
    *param_4 = iVar3;
    param_4[1] = iVar2;
    param_4[2] = iVar4;
    param_4[3] = iVar6;
    return 0;
  }
  uVar1 = DAT_00090940/*"Invalid GPIO pin %u\n"*/;
LAB_00090908:
  FUN_00092a80(3,uVar1,param_2,DAT_00090938/*=0xc9404*/,param_4);
  return 0xffffffea;
}

//==== 0x909a4  0x909a4-0x90a89 inclusive
undefined4 FUN_000909a4(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34 [4];
  
  uVar3 = DAT_00090ab4/*"base"*/;
  puVar2 = DAT_00090ab0/*=0xa6738*/;
  piVar1 = DAT_00090a90/*=0xc9404*/;
  iVar9 = 0;
  local_34[0] = *DAT_00090a8c/*=0xa4720*/;
  local_34[1] = DAT_00090a8c/*=0xa4720*/[1];
  local_34[2] = DAT_00090a8c/*=0xa4720*/[2];
  FUN_00092c30(DAT_00090a90/*=0xc9404*/,0,0x20);
  FUN_00092c30(&local_3c,0,8);
  do {
    iVar8 = local_34[iVar9];
    if ((iVar8 == 0) || (iVar9 == 2)) {
      if (*DAT_00090a90/*=0xc9404*/ == 0) {
        uVar3 = 0;
        if (DAT_00090a90/*=0xc9404*/[4] == 0) {
          FUN_00092a80(3,DAT_00090a94/*"No GPIO controllers were initialized\n"*/);
          uVar3 = 0xffffffed;
        }
      }
      else {
        uVar3 = 0;
      }
      return uVar3;
    }
    iVar4 = FUN_00093460(*puVar2,iVar8);
    if (iVar4 < 0) {
      FUN_00092a80(3,DAT_00090a98/*"Failed to find GPIO node '%s': %d\n"*/,iVar8,iVar4);
    }
    else {
      iVar5 = FUN_000934c0(*puVar2,iVar4,uVar3,&local_44);
      uVar7 = DAT_00090aa0/*"range"*/;
      if (iVar5 < 0) {
        uVar7 = DAT_00090a9c/*"%s: missing or invalid membase property\n"*/;
      }
      else {
        uVar6 = *puVar2;
        piVar1[iVar9 * 4] = local_44;
        iVar5 = FUN_000934c0(uVar6,iVar4,uVar7,&local_3c);
        uVar7 = DAT_00090aa8/*"type"*/;
        if (iVar5 < 0) {
          uVar7 = DAT_00090aa4/*"%s: no bank_range property\n"*/;
        }
        else {
          uVar6 = *puVar2;
          piVar1[iVar9 * 4 + 1] = local_3c;
          piVar1[iVar9 * 4 + 2] = local_38;
          iVar4 = FUN_000934c0(uVar6,iVar4,uVar7,&local_40);
          if (-1 < iVar4) {
            piVar1[iVar9 * 4 + 3] = local_40;
            goto LAB_00090a1c;
          }
          uVar7 = DAT_00090aac/*"%s: missing or invalid hardtype property\n"*/;
        }
      }
      FUN_00092a80(3,uVar7,iVar8);
    }
LAB_00090a1c:
    iVar9 = iVar9 + 1;
  } while( true );
}

//==== 0x90ab8  0x90944-0x90973 inclusive
void FUN_00090ab8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 auStack_48 [28];
  undefined4 local_2c;
  
  FUN_00092c30(auStack_48,0,0x30);
  iVar1 = FUN_000908d8(param_1,param_2,1,auStack_48);
  if (iVar1 == 0) {
    local_2c = param_3;
    FUN_0009085c(auStack_48);
  }
  return;
}

//==== 0x90abe  0x90abe-0x90ac3 inclusive
void FUN_00090abe(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 auStack_48 [28];
  undefined4 uStack_2c;
  
  FUN_00092c30(auStack_48,0,0x30);
  iVar1 = FUN_000908d8(param_1,param_2,0,auStack_48);
  if (iVar1 == 0) {
    uStack_2c = param_3;
    FUN_0009085c(auStack_48);
  }
  return;
}

//==== 0x90ac4  0x90ac4-0x90ac9 inclusive
void FUN_00090ac4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 auStack_48 [28];
  undefined4 uStack_2c;
  
  FUN_00092c30(auStack_48,0,0x30);
  iVar1 = FUN_000908d8(param_1,param_2,2,auStack_48);
  if (iVar1 == 0) {
    uStack_2c = param_3;
    FUN_0009085c(auStack_48);
  }
  return;
}

//==== 0x90aca  0x90aca-0x90acf inclusive
void FUN_00090aca(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 auStack_48 [28];
  undefined4 uStack_2c;
  
  FUN_00092c30(auStack_48,0,0x30);
  iVar1 = FUN_000908d8(param_1,param_2,3,auStack_48);
  if (iVar1 == 0) {
    uStack_2c = param_3;
    FUN_0009085c(auStack_48);
  }
  return;
}

//==== 0x90ad0  0x90974-0x909a3 inclusive
void FUN_00090ad0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined1 auStack_48 [52];
  
  FUN_00092c30(auStack_48,0,0x30);
  iVar1 = FUN_000908d8(param_1,param_2,1,auStack_48);
  if (iVar1 == 0) {
    FUN_000908a0(auStack_48,param_3);
  }
  return;
}

//==== 0x90ad8  0x90ad8-0x90b45 inclusive
int FUN_00090ad8(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    iVar2 = -0x16;
    FUN_00092a80(3,DAT_00090b48/*"NULL ptr in hal_gpio_set_state\n"*/);
  }
  else {
    iVar2 = FUN_00090abe(*param_1,param_1[1],param_1[2],param_4,param_4);
    if (iVar2 == 0) {
      iVar2 = FUN_00090ab8(*param_1,param_1[1],param_1[3]);
      if (iVar2 == 0) {
        iVar2 = FUN_00090aca(*param_1,param_1[1],param_1[5]);
        if (iVar2 == 0) {
          iVar2 = FUN_00090ac4(*param_1,param_1[1],param_1[4]);
          if (iVar2 == 0) {
            return 0;
          }
          uVar1 = DAT_00090b58/*"Failed to set GPIO dlevel: %d\n"*/;
        }
        else {
          uVar1 = DAT_00090b54/*"Failed to set GPIO pull: %d\n"*/;
        }
      }
      else {
        uVar1 = DAT_00090b50/*"Failed to set GPIO data: %d\n"*/;
      }
    }
    else {
      uVar1 = DAT_00090b4c/*"Failed to set GPIO mux: %d\n"*/;
    }
    FUN_00092a80(3,uVar1,iVar2);
  }
  return iVar2;
}

//==== 0x90b5c  0x90b5c-0x90b7d inclusive
int FUN_00090b5c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if (iVar2 == param_2) {
      return 0;
    }
    iVar1 = FUN_00090ad8(iVar2 * 0x18 + param_1);
    if (iVar1 != 0) break;
    iVar2 = iVar2 + 1;
  }
  return iVar1;
}

//==== 0x90b80  0x90b80-0x90b8d inclusive
undefined4 FUN_00090b80(void)

{
  undefined4 uVar1;
  
  if (*(code **)(DAT_00090b90/*=0xc8020*/ + 4) == (code *)0x0) {
    return 0xffffffc3;
  }
                    /* WARNING: Could not recover jumptable at 0x00090b86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(DAT_00090b90/*=0xc8020*/ + 4))();
  return uVar1;
}

//==== 0x90b94  0x90b94-0x90ba1 inclusive
undefined4 FUN_00090b94(void)

{
  undefined4 uVar1;
  
  if (*(code **)(DAT_00090ba4/*=0xc8020*/ + 0xc) == (code *)0x0) {
    return 0xffffffc3;
  }
                    /* WARNING: Could not recover jumptable at 0x00090b9a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(DAT_00090ba4/*=0xc8020*/ + 0xc))();
  return uVar1;
}

//==== 0x90be0  0x90be0-0x90c13 inclusive
undefined4 FUN_00090be0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  DataMemoryBarrier(0x1f);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  DataMemoryBarrier(0x1f);
  iVar1 = 0xff;
  iVar2 = 1;
  *(undefined4 *)(param_1 + 0x18) = 1;
  do {
    iVar1 = iVar1 + -1;
    if (iVar1 == 0) {
      FUN_00092a80(3,DAT_00090c14/*"wait srst timeout\n"*/,0,iVar2,param_4);
      return 0xffffffc2;
    }
    iVar2 = *(int *)(param_1 + 0x18);
    DataMemoryBarrier(0x1f);
  } while (iVar2 != 0);
  return 0;
}

//==== 0x90d78  0x90d78-0x90d9b inclusive
undefined4 FUN_00090d78(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = 0xff;
  do {
    iVar1 = iVar1 + -1;
    if (iVar1 == 0) {
      FUN_00092a80(3,DAT_00090d9c/*"wait irq timeout\n"*/,param_3,0,param_4);
      return 0xffffffc2;
    }
    DataMemoryBarrier(0x1f);
    param_3 = *(int *)(param_1 + 0xc) << 0x1c;
  } while (-1 < param_3);
  return 0;
}

//==== 0x90da0  0x90da0-0x90dc7 inclusive
undefined4 FUN_00090da0(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = 0xff;
  do {
    iVar1 = iVar1 + -1;
    if (iVar1 == 0) {
      FUN_00092a80(3,DAT_00090dc8/*"wait status: 0x%x timeout\n"*/);
      return 0xffffffc2;
    }
    DataMemoryBarrier(0x1f);
  } while (*(byte *)(param_1 + 0x10) != param_2);
  return 0;
}

//==== 0x90dcc  0x90dcc-0x90e27 inclusive
int FUN_00090dcc(int param_1,char param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  DataMemoryBarrier(0x1f);
  *(byte *)(param_1 + 8) = (byte)param_3 | param_2 << 1;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 8;
  iVar1 = FUN_00090d78();
  if (iVar1 == 0) {
    if (param_3 == 0) {
      uVar2 = 0x18;
    }
    else {
      uVar2 = 0x40;
    }
    iVar1 = FUN_00090da0(param_1,uVar2);
    if (iVar1 != 0) {
      if (param_3 == 0) {
        uVar2 = 0x18;
      }
      else {
        uVar2 = 0x40;
      }
      FUN_00092a80(3,DAT_00090e2c/*"Slave addr send timeout: 0x%x\n"*/,uVar2);
    }
  }
  else {
    FUN_00092a80(3,DAT_00090e28/*"Wait irq timeout(send slave addr)\n"*/);
  }
  return iVar1;
}

//==== 0x90e30  0x90e30-0x90e7f inclusive
int FUN_00090e30(int param_1,undefined1 *param_2,undefined4 param_3)

{
  int iVar1;
  
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 8;
  iVar1 = FUN_00090d78();
  if (iVar1 == 0) {
    iVar1 = FUN_00090da0(param_1,param_3);
    if (iVar1 == 0) {
      DataMemoryBarrier(0x1f);
      *param_2 = *(undefined1 *)(param_1 + 8);
    }
    else {
      FUN_00092a80(3,DAT_00090e84/*"wait status: 0x%x timeout when tx\n"*/,param_3);
    }
  }
  else {
    FUN_00092a80(3,DAT_00090e80/*"wait irq timeout when rx\n"*/);
  }
  return iVar1;
}

//==== 0x90e88  0x90e88-0x90edb inclusive
int FUN_00090e88(int param_1,undefined4 param_2)

{
  int iVar1;
  
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x20;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 8;
  iVar1 = FUN_00090d78();
  if (iVar1 == 0) {
    iVar1 = FUN_00090da0(param_1,param_2);
    if (iVar1 != 0) {
      FUN_00092a80(3,DAT_00090ee0/*"Wait timeout: 0x%x at start\n"*/,param_2);
    }
  }
  else {
    FUN_00092a80(3,DAT_00090edc/*"wait irq timeout when setting start\n"*/);
  }
  return iVar1;
}

//==== 0x91088  0x91088-0x910fd inclusive
int FUN_00091088(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined2 local_44;
  undefined1 auStack_40 [48];
  
  local_4c = 0;
  uStack_48 = 0;
  local_44 = 0;
  FUN_000929d4(&local_4c,DAT_00091100/*"/uart%d"*/,param_1);
  iVar1 = FUN_0009133c(&local_4c,0,3);
  if (-1 < iVar1) {
    FUN_00091a8c(10,0);
    iVar1 = FUN_000912c8(&local_4c,0,3);
    if (-1 < iVar1) {
      iVar1 = FUN_0009365c(&local_4c,DAT_00091104/*"pins"*/,auStack_40,2);
      if (iVar1 == 2) {
        iVar2 = FUN_00090b5c(auStack_40,2);
        iVar1 = 0;
        if (iVar2 != 0) {
          return -1;
        }
      }
      else if (iVar1 < 0) {
        return iVar1;
      }
      if (*(code **)(DAT_00091108/*=0xc8030*/ + 4) != (code *)0x0) {
        iVar1 = (**(code **)(DAT_00091108/*=0xc8030*/ + 4))(param_1,param_2);
      }
    }
  }
  return iVar1;
}

//==== 0x9110c  0x9110c-0x91119 inclusive
undefined4 FUN_0009110c(void)

{
  undefined4 uVar1;
  
  if (*(code **)(DAT_0009111c/*=0xc8030*/ + 8) == (code *)0x0) {
    return 0xffffffff;
  }
                    /* WARNING: Could not recover jumptable at 0x00091112. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(DAT_0009111c/*=0xc8030*/ + 8))();
  return uVar1;
}

//==== 0x91120  0x91120-0x9112d inclusive
undefined4 FUN_00091120(void)

{
  undefined4 uVar1;
  
  if (*(code **)(DAT_00091130/*=0xc8030*/ + 0xc) == (code *)0x0) {
    return 0xffffffff;
  }
                    /* WARNING: Could not recover jumptable at 0x00091126. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(DAT_00091130/*=0xc8030*/ + 0xc))();
  return uVar1;
}

//==== 0x91134  0x91134-0x91185 inclusive
undefined4 FUN_00091134(int param_1,int *param_2)

{
  uint uVar1;
  uint *puVar2;
  
  uVar1 = FUN_000a3750((*param_2 + 3000000U & 0x1fffffff) >> 1);
  puVar2 = (uint *)((param_1 + 0x2500) * 0x1000);
  puVar2[4] = 3;
  puVar2[3] = puVar2[3] | 0x80;
  puVar2[1] = uVar1 >> 8;
  *puVar2 = uVar1 & 0xff;
  puVar2[3] = puVar2[3] & 0xffffff7f;
  puVar2[3] = param_2[2] << 2 | param_2[3] << 3 | param_2[1];
  puVar2[2] = 7;
  return 0;
}

//==== 0x911da  0x911da-0x911dd inclusive
uint FUN_000911da(uint param_1)

{
  return param_1 << 0x18 | (param_1 >> 8 & 0xff) << 0x10 | (param_1 >> 0x10 & 0xff) << 8 |
         param_1 >> 0x18;
}

//==== 0x911e0  0x911e0-0x912a9 inclusive
int FUN_000911e0(undefined4 param_1,uint param_2,int *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int extraout_r2;
  int extraout_r3;
  int extraout_r3_00;
  int extraout_r3_01;
  int extraout_r3_02;
  uint local_1c;
  
  puVar1 = DAT_000912ac/*=0xa6738*/;
  local_1c = param_2;
  iVar2 = FUN_00093460(*DAT_000912ac/*=0xa6738*/,param_1,param_3,param_4,param_1);
  if (iVar2 < 0) {
    FUN_00092a80(3,DAT_000912b0/*"Node not found: %s\n"*/,param_1);
  }
  else {
    iVar2 = FUN_00093344(*puVar1,iVar2,DAT_000912b4/*=0xa4bec*/,&local_1c);
    uVar5 = param_2 * 0x14 + 0x14;
    if ((iVar2 == 0) || (local_1c < uVar5)) {
      FUN_00092a80(3,DAT_000912b8/*"Invalid ccu property\n"*/);
    }
    else {
      iVar6 = uVar5 + iVar2;
      uVar5 = FUN_000911da(*(undefined4 *)(iVar6 + -0x14),local_1c,iVar6,iVar2);
      if (uVar5 < 3) {
        iVar2 = *(int *)(DAT_000912c0/*=0xa4bcc*/ + uVar5 * 4);
        if (iVar2 != 0) {
          iVar6 = param_2 * 5 + 1;
          iVar3 = FUN_000911da(*(undefined4 *)(extraout_r3 + iVar6 * 4),DAT_000912c0/*=0xa4bcc*/,iVar6 * 4);
          iVar6 = extraout_r3_00 + extraout_r2;
          if (iVar3 == -1) {
            *param_3 = 0;
          }
          else {
            *param_3 = iVar3 + iVar2;
            if (iVar3 + iVar2 != 0) {
              iVar6 = FUN_000911da(*(undefined4 *)(iVar6 + 4));
              param_3[1] = iVar6;
              iVar6 = extraout_r3_02;
            }
          }
          iVar6 = FUN_000911da(*(undefined4 *)(iVar6 + 8));
          if (iVar6 == -2) {
            param_3[2] = 0;
            return 0;
          }
          param_3[2] = iVar2 + iVar6;
          if (iVar2 + iVar6 == 0) {
            return 0;
          }
          iVar2 = FUN_000911da(*(undefined4 *)(extraout_r3_01 + 0xc));
          param_3[3] = iVar2;
          return 0;
        }
        uVar4 = DAT_000912c4/*"ccu base %u is defined as 0\n"*/;
      }
      else {
        uVar4 = DAT_000912bc/*"ccu index %u out of range\n"*/;
      }
      FUN_00092a80(3,uVar4,uVar5);
    }
    iVar2 = -0x16;
  }
  return iVar2;
}

//==== 0x912c8  0x912c8-0x91335 inclusive
int FUN_000912c8(uint *param_1,uint param_2,uint *param_3,uint param_4)

{
  int iVar1;
  uint *local_20;
  uint local_1c;
  uint *local_18;
  uint local_14;
  
  local_20 = param_1;
  local_1c = param_2;
  local_18 = param_3;
  local_14 = param_4;
  if (param_1 == (uint *)0x0) {
    FUN_00092a80(3,DAT_00091338/*"Invalid node_path\n"*/);
    iVar1 = -0x16;
  }
  else {
    FUN_00092c30(&local_20,0,0x10);
    iVar1 = FUN_000911e0(param_1,param_2,&local_20);
    if (iVar1 == 0) {
      if (((int)param_3 << 0x1f < 0) && (local_20 != (uint *)0x0)) {
        DataMemoryBarrier(0x1f);
        DataMemoryBarrier(0x1f);
        *local_20 = 1 << (local_1c & 0xff) | *local_20;
      }
      if (((int)param_3 << 0x1e < 0) && (local_18 != (uint *)0x0)) {
        DataMemoryBarrier(0x1f);
        DataMemoryBarrier(0x1f);
        *local_18 = 1 << (local_14 & 0xff) | *local_18;
      }
    }
  }
  return iVar1;
}

//==== 0x9133c  0x9133c-0x913ad inclusive
int FUN_0009133c(uint *param_1,uint param_2,uint *param_3,uint param_4)

{
  int iVar1;
  uint *local_20;
  uint local_1c;
  uint *local_18;
  uint local_14;
  
  local_20 = param_1;
  local_1c = param_2;
  local_18 = param_3;
  local_14 = param_4;
  if (param_1 == (uint *)0x0) {
    FUN_00092a80(3,DAT_000913b0/*"Invalid node_path\n"*/);
    iVar1 = -0x16;
  }
  else {
    FUN_00092c30(&local_20,0,0x10);
    iVar1 = FUN_000911e0(param_1,param_2,&local_20);
    if (iVar1 == 0) {
      if (((int)param_3 << 0x1e < 0) && (local_18 != (uint *)0x0)) {
        DataMemoryBarrier(0x1f);
        DataMemoryBarrier(0x1f);
        *local_18 = *local_18 & ~(1 << (local_14 & 0xff));
      }
      if (((int)param_3 << 0x1f < 0) && (local_20 != (uint *)0x0)) {
        DataMemoryBarrier(0x1f);
        DataMemoryBarrier(0x1f);
        *local_20 = *local_20 & ~(1 << (local_1c & 0xff));
      }
    }
  }
  return iVar1;
}

//==== 0x913b4  0x913b4-0x913c3 inclusive
void FUN_000913b4(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_00090b80();
  if (iVar1 == 0) {
    *DAT_000913c4/*=0xa5800*/ = param_1;
  }
  return;
}

//==== 0x913c8  0x913c8-0x91413 inclusive
void FUN_000913c8(undefined2 param_1,undefined1 param_2,undefined4 param_3)

{
  undefined1 local_29;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  undefined1 *local_20;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 local_18;
  undefined4 local_14;
  
  local_29 = param_2;
  FUN_00092c30(&local_28,0,0x18);
  local_24 = 1;
  local_20 = &local_29;
  local_18 = 1;
  local_1a = 5;
  local_26 = 2;
  local_28 = param_1;
  local_1c = param_1;
  local_14 = param_3;
  FUN_00090b94(*DAT_00091414/*=0xa5800*/,&local_28);
  return;
}

//==== 0x91418  0x91418-0x91455 inclusive
void FUN_00091418(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_20;
  uint local_1c;
  undefined4 local_18;
  undefined4 *local_14;
  
  local_20 = param_1;
  local_1c = param_2;
  local_18 = param_3;
  local_14 = (undefined4 *)param_4;
  FUN_00092c30(&local_1c,0,0xc);
  local_18 = CONCAT22(local_18._2_2_,2);
  local_20._0_2_ = CONCAT11((char)param_3,(char)param_2);
  local_1c = param_1 & 0xffff;
  local_14 = &local_20;
  FUN_00090b94(*DAT_00091458/*=0xa5800*/,&local_1c,1);
  return;
}

//==== 0x9145c  0x9145c-0x91473 inclusive
int * FUN_0009145c(int param_1)

{
  int *piVar1;
  
  piVar1 = DAT_00091474/*=0xc7fe0*/;
  while( true ) {
    if (piVar1 == DAT_00091478/*=0xc8008*/) {
      return (int *)0x0;
    }
    if (*piVar1 == param_1) break;
    piVar1 = piVar1 + 10;
  }
  return piVar1;
}

//==== 0x9147c  0x9147c-0x914a1 inclusive
undefined4 FUN_0009147c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = FUN_0009145c(param_2);
  if ((iVar1 == 0) ||
     (UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x10), UNRECOVERED_JUMPTABLE == (code *)0x0)) {
    return 0xffffffff;
  }
  *DAT_000914a4/*=0xc9428*/ = *(undefined4 *)(iVar1 + 4);
                    /* WARNING: Could not recover jumptable at 0x0009149a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(param_3,1);
  return uVar2;
}

//==== 0x914a8  0x914a8-0x914d3 inclusive
undefined4 FUN_000914a8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = FUN_0009145c(param_2);
  if ((iVar1 == 0) ||
     (UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x14), UNRECOVERED_JUMPTABLE == (code *)0x0)) {
    return 0xffffffff;
  }
  *DAT_000914d4/*=0xc9428*/ = *(undefined4 *)(iVar1 + 4);
                    /* WARNING: Could not recover jumptable at 0x000914cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(param_3,param_4,1);
  return uVar2;
}

//==== 0x914d8  0x914d8-0x91629 inclusive
int FUN_000914d8(undefined4 param_1,uint param_2,int param_3,int param_4,int param_5)

{
  byte bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  byte bVar10;
  uint uVar11;
  byte local_29 [5];
  
  iVar9 = 0;
  while( true ) {
    if (param_5 <= iVar9) {
      return -1;
    }
    uVar3 = FUN_00092bc6(param_4);
    iVar4 = FUN_00092b8c(param_1,param_4,uVar3);
    puVar2 = DAT_0009162c/*=0xc9428*/;
    if (iVar4 == 0) break;
    iVar9 = iVar9 + 1;
    param_4 = param_4 + 0x6c;
  }
  if (param_4 == 0) {
    return -1;
  }
  if ((param_2 != 0) && (uVar8 = *(uint *)(param_4 + 0x10), uVar8 != 0)) {
    if (uVar8 <= param_2) {
      uVar8 = param_2;
      if (*(uint *)(param_4 + 0x14) <= param_2) {
        uVar8 = *(uint *)(param_4 + 0x14);
      }
    }
    iVar9 = FUN_000913c8(*DAT_0009162c/*=0xc9428*/,*(undefined1 *)(param_4 + 0x18),local_29);
    if (iVar9 != 0) {
      return -1;
    }
    bVar1 = *(byte *)(param_4 + 0x1c);
    bVar10 = local_29[0] & ~bVar1;
    uVar6 = 0;
    uVar7 = 0;
    local_29[0] = bVar10;
    while( true ) {
      uVar11 = uVar6 & 0xff;
      iVar9 = param_4 + uVar11 * 0x10;
      uVar5 = *(uint *)(iVar9 + 0x30);
      if (uVar5 == 0) break;
      iVar9 = *(int *)(iVar9 + 0x2c);
      if (uVar8 <= uVar5) {
        uVar5 = uVar8;
LAB_000915d6:
        iVar9 = FUN_000a3750(uVar5 - iVar9);
        local_29[0] = bVar10 | (byte)(uVar7 + iVar9 << (*(uint *)(param_4 + 0x28) & 0xff));
        if (*(int *)(param_4 + (uVar11 + 3) * 0x10 + 8) != 0) {
          local_29[0] = bVar1 ^ local_29[0];
        }
        break;
      }
      uVar6 = uVar6 + 1;
      if (uVar8 < *(uint *)(param_4 + uVar11 * 0x10 + 0x3c)) goto LAB_000915d6;
      iVar9 = FUN_000a3750((uVar5 + *(int *)(param_4 + (uVar11 + 3) * 0x10 + 4)) - iVar9);
      uVar7 = uVar7 + iVar9 & 0xff;
    }
    iVar9 = FUN_00091418(*puVar2,*(undefined1 *)(param_4 + 0x18),local_29[0]);
    if (iVar9 != 0) {
      return -1;
    }
  }
  puVar2 = DAT_0009162c/*=0xc9428*/;
  if (param_3 < 0) {
    return 0;
  }
  iVar9 = FUN_000913c8(*DAT_0009162c/*=0xc9428*/,*(undefined1 *)(param_4 + 0x20),local_29);
  if (iVar9 != 0) {
    return -1;
  }
  bVar1 = (byte)(1 << (*(uint *)(param_4 + 0x24) & 0xff));
  if (param_3 == 0) {
    local_29[0] = local_29[0] & ~bVar1;
  }
  else {
    local_29[0] = local_29[0] | bVar1;
  }
  iVar9 = FUN_00091418(*puVar2,*(undefined1 *)(param_4 + 0x20),local_29[0]);
  return -(uint)(iVar9 != 0);
}

//==== 0x91630  0x91630-0x916c5 inclusive
undefined4 FUN_00091630(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  
  puVar1 = DAT_000916c8/*=0xa6738*/;
  iVar3 = FUN_00093460(*DAT_000916c8/*=0xa6738*/,DAT_000916cc/*"/power_sply"*/,param_3,param_4,param_4);
  uVar2 = DAT_000916d0/*"SPL: enable %s %dmV\n"*/;
  if (-1 < iVar3) {
    for (iVar3 = FUN_0009323a(*puVar1); 0 < iVar3; iVar3 = FUN_00093252(*puVar1,iVar3)) {
      iVar4 = FUN_000932e0(*puVar1,iVar3,0);
      if (iVar4 != 0) {
        uVar6 = *(uint *)(iVar4 + 8);
        uVar5 = FUN_00093146(*puVar1,uVar6 >> 0x18 | uVar6 << 0x18 | ((uVar6 & 0xffff) >> 8) << 0x10
                                     | ((uVar6 & 0xffffff) >> 0x10) << 8);
        uVar6 = *(uint *)(iVar4 + 0xc);
        uVar6 = uVar6 >> 0x18 | uVar6 << 0x18 | ((uVar6 & 0xffff) >> 8) << 0x10 |
                ((uVar6 & 0xffffff) >> 0x10) << 8;
        if (uVar6 != 0) {
          FUN_00092a80(3,uVar2,uVar5,uVar6);
          FUN_000914a8(0,param_1,uVar5,uVar6);
        }
      }
    }
  }
  return 0;
}

//==== 0x916d4  0x916d4-0x9170b inclusive
int FUN_000916d4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0009145c(param_2);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 8) == 0)) {
    iVar1 = -1;
  }
  else {
    iVar2 = FUN_000913b4(param_1);
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar1 = (**(code **)(iVar1 + 8))(param_3);
  }
  FUN_00091630(param_2);
  return iVar1;
}

//==== 0x9170c  0x9170c-0x91745 inclusive
int FUN_0009170c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00091748/*=0xc7fe0*/;
  iVar1 = FUN_000914d8(DAT_0009174c/*"dcdc3"*/,param_1,1,*(undefined4 *)(DAT_00091748/*=0xc7fe0*/ + 0x20),
                       *(undefined4 *)(DAT_00091748/*=0xc7fe0*/ + 0x24),param_2,param_3);
  if (iVar1 == 0) {
    iVar2 = FUN_000914d8(DAT_00091750/*"dcdc4"*/,param_1,1,*(undefined4 *)(iVar2 + 0x20),
                         *(undefined4 *)(iVar2 + 0x24),param_2,param_3);
    iVar2 = -(uint)(iVar2 != 0);
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}

//==== 0x918c4  0x918c4-0x918d9 inclusive
undefined4 FUN_000918c4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = DAT_000918e0/*=0xc7fd0*/;
  }
  else {
    FUN_00092a80(3,DAT_000918dc/*"Unsupported ADC type: %u\n"*/,param_1,param_4,param_4);
    uVar1 = 0;
  }
  return uVar1;
}

//==== 0x918e4  0x918e4-0x918ff inclusive
undefined4 FUN_000918e4(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_000918c4();
  if ((iVar1 == 0) || (*(code **)(iVar1 + 4) == (code *)0x0)) {
    return 0xffffffff;
  }
                    /* WARNING: Could not recover jumptable at 0x000918f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(iVar1 + 4))(param_2);
  return uVar2;
}

//==== 0x91900  0x91900-0x91929 inclusive
undefined4 FUN_00091900(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_000918c4();
  if ((iVar1 == 0) || (*(code **)(iVar1 + 0xc) == (code *)0x0)) {
    return 0xffffffff;
  }
                    /* WARNING: Could not recover jumptable at 0x00091920. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(iVar1 + 0xc))(param_2,param_3,param_4);
  return uVar2;
}

//==== 0x91a00  0x91a00-0x91a49 inclusive
undefined4 FUN_00091a00(undefined4 param_1,uint param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 1 << (param_2 & 0xff);
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *DAT_00091a4c/*=0x2521008*/ = *DAT_00091a4c/*=0x2521008*/ | uVar2;
  FUN_00091a8c(10000,0);
  DataMemoryBarrier(0x1f);
  uVar2 = *DAT_00091a50/*=0x2521038*/ & uVar2;
  DataMemoryBarrier(0x1f);
  *DAT_00091a50/*=0x2521038*/ = uVar2;
  uVar1 = 0;
  if (uVar2 != 0) {
    uVar1 = *(undefined4 *)((DAT_00091a54/*=0x948420*/ + param_2) * 4);
    DataMemoryBarrier(0x1f);
  }
  *param_3 = uVar1;
  return 0;
}

//==== 0x91a7a  0x91a7a-0x91a8b inclusive
void FUN_00091a7a(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 in_r3;
  undefined4 in_cr14;
  
  uVar1 = coprocessor_movefromRt(0xf,0,in_cr14);
  uVar2 = coprocessor_movefromRt2(0xf,0,in_cr14);
  FUN_000a41b4(uVar1,uVar2,24000,0,in_r3);
  return;
}

//==== 0x91a8c  0x91a8c-0x91aaf inclusive
void FUN_00091a8c(int param_1)

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

//==== 0x91de0  0x91de0-0x91ebb inclusive
void FUN_00091de0(uint *param_1,uint param_2,uint param_3)

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
    if ((int)param_3 < 4) goto LAB_00091e84;
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
LAB_00091e84:
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

//==== 0x91ebc  0x91ebc-0x91ecd inclusive
void FUN_00091ebc(code *param_1,undefined4 param_2)

{
  undefined4 in_cr5;
  undefined4 in_cr7;
  
  coprocessor_moveto(0xf,0,6,0,in_cr7,in_cr5);
  (*param_1)(param_1,param_2,0);
  return;
}

//==== 0x91ed0  0x91ed0-0x91f7b inclusive
undefined4 FUN_00091ed0(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 in_cr0;
  undefined4 in_cr1;
  undefined4 in_cr2;
  undefined4 in_cr3;
  undefined4 in_cr5;
  undefined4 in_cr6;
  undefined4 in_cr7;
  undefined4 in_cr8;
  
  FUN_00090690(DAT_00091f7c/*"dcache_init"*/);
  if (0x7ff < param_1) {
    param_1 = 0x800;
  }
  iVar3 = (param_1 - 1) * 0x100000;
  puVar2 = (uint *)(iVar3 + 0x40000000);
  for (puVar1 = puVar2; puVar1 != (uint *)(iVar3 + 0x40004000); puVar1 = puVar1 + 1) {
    *puVar1 = (int)puVar1 * 0x40000 | 0xde2;
  }
  *puVar2 = 0xdea;
  puVar1 = (uint *)(iVar3 + 0x40001000);
  for (uVar4 = 0x400; uVar4 < param_1 + 0x400; uVar4 = uVar4 + 1) {
    *puVar1 = uVar4 << 0x14 | 0xdea;
    puVar1 = puVar1 + 1;
  }
  coprocessor_moveto(0xf,0,0,0,in_cr8,in_cr7);
  coprocessor_moveto(0xf,0,0,0,in_cr8,in_cr6);
  coprocessor_moveto(0xf,0,0,0,in_cr8,in_cr5);
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  coprocessor_moveto(0xf,0,0,(uint)puVar2 | 0x13,in_cr2,in_cr0);
  coprocessor_moveto(0xf,0,1,0,in_cr2,in_cr0);
  coprocessor_moveto(0xf,0,0,0x55555555,in_cr3,in_cr0);
  InstructionSynchronizationBarrier(0xf);
  uVar4 = coprocessor_movefromRt(0xf,0,0,in_cr1,in_cr0);
  FUN_00091a8c(100,0,(uint)puVar2 | 0x13,0x55555555);
  coprocessor_moveto(0xf,0,0,uVar4 & 0xfffffffb | 0x1001,in_cr1,in_cr0);
  InstructionSynchronizationBarrier(0xf);
  return 0;
}

//==== 0x91f80  0x91f80-0x91fb7 inclusive
void FUN_00091f80(void)

{
  uint uVar1;
  undefined4 in_cr0;
  undefined4 in_cr1;
  undefined4 in_cr5;
  undefined4 in_cr7;
  
  FUN_00090690(DAT_00091fb8/*"dcache_deinit"*/);
  uVar1 = coprocessor_movefromRt(0xf,0,0,in_cr1,in_cr0);
  FUN_00091a8c(100,0);
  coprocessor_moveto(0xf,0,0,uVar1 & 0xffffeffe,in_cr1,in_cr0);
  InstructionSynchronizationBarrier(0xf);
  coprocessor_moveto(0xf,0,0,0,in_cr7,in_cr5);
  coprocessor_moveto(0xf,0,6,0,in_cr7,in_cr5);
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return;
}

//==== 0x91fbc  0x91fbc-0x92005 inclusive
int FUN_00091fbc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_14;
  undefined4 uStack_10;
  
  puVar2 = DAT_0009200c/*=0xa6738*/;
  piVar1 = DAT_00092008/*=0xa6734*/;
  if ((*DAT_00092008/*=0xa6734*/ != -1) ||
     ((((local_14 = param_2, uStack_10 = param_3,
        iVar3 = FUN_00093460(*DAT_0009200c/*=0xa6738*/,DAT_00092010/*"/axp"*/,param_3,0,param_1), -1 < iVar3 &&
        (iVar3 = FUN_000934c0(*puVar2,iVar3,DAT_00092014/*"pmic_bus_device"*/,&local_14), -1 < iVar3)) &&
       (iVar3 = FUN_0009347a(*puVar2,local_14), -1 < iVar3)) &&
      (iVar3 = FUN_000934c0(*puVar2,iVar3,DAT_00092018/*"devnum"*/,piVar1), -1 < iVar3)))) {
    iVar3 = *piVar1;
  }
  return iVar3;
}

//==== 0x92044  0x9201c-0x9203d inclusive
int FUN_00092044(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = FUN_00091fbc();
  iVar4 = FUN_000916d4(uVar3,0xe,0);
  uVar2 = DAT_000920b0/*=0xa7070025*/;
  puVar1 = DAT_000920ac/*=0x8000144*/;
  if (iVar4 == 0) {
    DataMemoryBarrier(0x1f);
    *DAT_000920ac/*=0x8000144*/ = DAT_000920b0/*=0xa7070025*/;
    DataMemoryBarrier(0x1f);
    *puVar1 = uVar2;
    FUN_0009147c(uVar3,0xe,800);
    FUN_000914a8(uVar3,0xe,DAT_000920b4/*"dcdc7"*/,0x438);
    FUN_000914a8(uVar3,0xe,DAT_000920b8/*"eldo1"*/,0x438);
    FUN_000914a8(uVar3,0xe,DAT_000920bc/*"dcdc6"*/,0x230);
    iVar4 = FUN_00092230();
    if (iVar4 == 0) {
      DataMemoryBarrier(0x1f);
      DataMemoryBarrier(0x1f);
      *DAT_00092040/*=0x8000200*/ = *DAT_00092040/*=0x8000200*/ | 1;
      return 0;
    }
  }
  return iVar4;
}

//==== 0x920c0  0x920c0-0x920d7 inclusive
undefined4 FUN_000920c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00091fbc();
  FUN_000914a8(uVar1,0xe,param_1,param_2,param_4);
  return 0;
}

//==== 0x920d8  0x920d8-0x920d9 inclusive
void FUN_000920d8(void)

{
  return;
}

//==== 0x920da  0x920da-0x920dd inclusive
undefined4 FUN_000920da(void)

{
  return 0;
}

//==== 0x920e6  0x920e6-0x920f5 inclusive
void FUN_000920e6(uint *param_1,uint param_2)

{
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *param_1 = param_2 | *param_1;
  return;
}

//==== 0x920f8  0x920f8-0x9217b inclusive
void FUN_000920f8(uint *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint *puVar2;
  int *extraout_r2;
  int iVar3;
  
  uVar1 = FUN_000920e6(param_1,0x40000000,param_2);
  puVar2 = (uint *)FUN_000920e6(uVar1,0x8000000);
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *param_1 = extraout_r2[3] << 0x10 | extraout_r2[1] << 0x14 | extraout_r2[2] | *extraout_r2 << 8 |
             DAT_0009217c/*=0xffc000f0*/ & *puVar2;
  FUN_00091a8c(0x14,0);
  uVar1 = FUN_000920e6(param_1,0x80000000);
  uVar1 = FUN_000920e6(uVar1,0x20000000);
  FUN_000920e6(uVar1,0x4000000);
  do {
    DataMemoryBarrier(0x1f);
  } while ((int)(*param_1 << 5) < 0);
  iVar3 = 3;
  do {
    do {
      DataMemoryBarrier(0x1f);
    } while (-1 < (int)(*param_1 << 3));
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  FUN_00091a8c(0x14,0);
  return;
}

//==== 0x92180  0x92180-0x9222b inclusive
void FUN_00092180(uint *param_1,int *param_2)

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
             DAT_0009222c/*=0xffc000f0*/ & *param_1;
  FUN_00091a8c(0x14,0);
  uVar1 = FUN_000920e6(param_1,0x20000000);
  FUN_000920e6(uVar1,0x4000000);
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
  FUN_00091a8c(0x14,0);
  FUN_000920e6(param_1,0x8000000);
  FUN_00091a8c(0x14,0);
  return;
}

//==== 0x92230  0x92230-0x924fb inclusive
undefined4 FUN_00092230(void)

{
  uint *puVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  undefined4 local_38;
  uint local_34;
  uint local_30;
  uint uStack_2c;
  
  FUN_00092a80(3,DAT_000924fc/*"set pll start\n"*/);
  FUN_000920e6(DAT_00092500/*=0x2002020*/,0x1000000);
  FUN_000920e6(DAT_00092504/*=0x20020a0*/,0x1000000);
  FUN_000920e6(DAT_00092508/*=0x20020c0*/,0x1000000);
  FUN_000920e6(DAT_0009250c/*=0x20020e0*/,0x1000000);
  FUN_000920e6(DAT_00092510/*=0x2002120*/,0x1000000);
  FUN_000920e6(DAT_00092514/*=0x2002140*/,0x1000000);
  FUN_000920e6(DAT_00092518/*=0x2002160*/,0x1000000);
  FUN_000920e6(DAT_0009251c/*=0x2002220*/,0x1000000);
  FUN_000920e6(DAT_00092520/*=0x2002240*/,0x1000000);
  FUN_000920e6(DAT_00092524/*=0x2002260*/,0x1000000);
  FUN_000920e6(DAT_00092528/*=0x2002280*/,0x1000000);
  FUN_000920e6(DAT_0009252c/*=0x20022a0*/,0x1000000);
  FUN_000920e6(DAT_00092530/*=0x20022e0*/,0x1000000);
  puVar4 = DAT_00092570/*=0x887101c*/;
  puVar2 = DAT_00092540/*=0x887301c*/;
  puVar1 = DAT_0009253c/*=0x887201c*/;
  puVar7 = DAT_00092538/*=0x8871000*/;
  DataMemoryBarrier(0x1f);
  uVar9 = *DAT_00092534/*=0x7090160*/ & 0x4000;
  if (uVar9 == 0) {
    uVar6 = *DAT_00092534/*=0x7090160*/ & 0x8000;
    if (uVar6 == 0) {
      local_38 = 0x14;
      local_34 = uVar6;
      local_30 = uVar6;
      uStack_2c = uVar6;
      FUN_000920f8(DAT_00092538/*=0x8871000*/,&local_38);
      local_38 = 0x2a;
      local_34 = uVar6;
      local_30 = uVar6;
      uStack_2c = uVar6;
      FUN_00092180(puVar7,&local_38);
      puVar3 = DAT_00092544/*=0x8872000*/;
      DataMemoryBarrier(0x1f);
      FUN_00092a80(3,DAT_00092548/*"cpul clk 0x%x!\n"*/,*puVar7);
      local_38 = 0x14;
      local_34 = uVar6;
      local_30 = uVar6;
      uStack_2c = uVar6;
      FUN_000920f8(puVar3,&local_38);
      local_38 = 0x2a;
      local_34 = uVar6;
      local_30 = uVar6;
      uStack_2c = uVar6;
      FUN_00092180(puVar3,&local_38);
      DataMemoryBarrier(0x1f);
      puVar7 = puVar3 + 0x400;
      FUN_00092a80(3,DAT_0009254c/*"cpub clk 0x%x!\n"*/,*puVar3);
      local_38 = 0x14;
      local_34 = uVar6;
      local_30 = uVar6;
      uStack_2c = uVar6;
      FUN_000920f8(puVar7,&local_38);
      local_38 = 0x1f;
      local_34 = uVar6;
      local_30 = uVar6;
      uStack_2c = uVar6;
      FUN_00092180(puVar7,&local_38);
      uVar5 = *puVar7;
    }
    else {
      local_38 = 0x14;
      local_34 = uVar9;
      local_30 = uVar9;
      uStack_2c = uVar9;
      FUN_000920f8(DAT_00092538/*=0x8871000*/,&local_38);
      local_38 = 0x27;
      local_34 = uVar9;
      local_30 = uVar9;
      uStack_2c = uVar9;
      FUN_00092180(puVar7,&local_38);
      puVar3 = DAT_00092544/*=0x8872000*/;
      DataMemoryBarrier(0x1f);
      FUN_00092a80(3,DAT_00092548/*"cpul clk 0x%x!\n"*/,*puVar7);
      local_38 = 0x14;
      local_34 = uVar9;
      local_30 = uVar9;
      uStack_2c = uVar9;
      FUN_000920f8(puVar3,&local_38);
      local_38 = 0x27;
      local_34 = uVar9;
      local_30 = uVar9;
      uStack_2c = uVar9;
      FUN_00092180(puVar3,&local_38);
      DataMemoryBarrier(0x1f);
      puVar7 = puVar3 + 0x400;
      FUN_00092a80(3,DAT_0009254c/*"cpub clk 0x%x!\n"*/,*puVar3);
      local_38 = 0x14;
      local_34 = uVar9;
      local_30 = uVar9;
      uStack_2c = uVar9;
      FUN_000920f8(puVar7,&local_38);
      local_38 = 0x1e;
      local_34 = uVar9;
      local_30 = uVar9;
      uStack_2c = uVar9;
      FUN_00092180(puVar7,&local_38);
      uVar5 = *puVar7;
    }
    DataMemoryBarrier(0x1f);
    FUN_00092a80(3,DAT_00092550/*"dsu clk 0x%x!\n"*/,uVar5);
    uVar9 = DAT_00092554/*=0xf8fcffff*/;
    DataMemoryBarrier(0x1f);
    DataMemoryBarrier(0x1f);
    *puVar4 = *puVar4 & DAT_00092554/*=0xf8fcffff*/ | 0x3000000;
    FUN_00091a8c(0x14,0);
    DataMemoryBarrier(0x1f);
    DataMemoryBarrier(0x1f);
    *puVar1 = *puVar1 & uVar9 | 0x3000000;
    FUN_00091a8c(0x14,0);
    DataMemoryBarrier(0x1f);
    DataMemoryBarrier(0x1f);
    *puVar2 = *puVar2 & uVar9 | 0x3000000;
    FUN_00091a8c(0x14,0);
  }
  puVar1 = DAT_0009255c/*=0x2002580*/;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *DAT_00092558/*=0x2002518*/ = *DAT_00092558/*=0x2002518*/ & 0xfcffffe0;
  iVar8 = DAT_00092560/*=0x186a0*/;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *puVar1 = *puVar1 & 0x7fffffe0 | 0x8000000;
  do {
    uVar9 = *puVar1;
    DataMemoryBarrier(0x1f);
    FUN_00091a8c(1,0);
    if (-1 < (int)(uVar9 << 4)) goto LAB_00092428;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  FUN_00092a80(3,DAT_00092564/*"nsi clk gating update failed!\n"*/);
LAB_00092428:
  iVar8 = DAT_00092560/*=0x186a0*/;
  puVar2 = DAT_0009255c/*=0x2002580*/;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  *puVar1 = *puVar1 & 0xf8ffffff | 0x8b000000;
  do {
    uVar9 = *puVar2;
    DataMemoryBarrier(0x1f);
    FUN_00091a8c(1,0);
    if (-1 < (int)(uVar9 << 4)) goto LAB_0009245e;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  FUN_00092a80(3,DAT_00092568/*"nsi clk update failed!\n"*/);
LAB_0009245e:
  FUN_00092a80(3,DAT_0009256c/*"set pll end\n"*/);
  return 0;
}

//==== 0x92574  0x92574-0x925d3 inclusive
int FUN_00092574(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  FUN_00090690(DAT_000925d4/*"board_early_init"*/);
  uVar3 = DAT_000925e4/*=0x44080*/;
  uVar2 = DAT_000925dc/*=0x48100000*/;
  puVar1 = DAT_000925d8/*=0xc942c*/;
  *DAT_000925d8/*=0xc942c*/ = 0x40000;
  puVar1[1] = 0x30000;
  puVar1[2] = thunk_FUN_00090004;
  puVar1[3] = 0x40000;
  puVar1[4] = &DAT_000b0000/*=0x1c6cfbef*/;
  puVar1[5] = 0x40800000;
  puVar1[6] = 0x1000000;
  puVar1[7] = 0;
  puVar1[8] = uVar2;
  puVar1[9] = 0x800;
  uVar2 = DAT_000925e0/*=0x42e00000*/;
  puVar1[10] = uVar3;
  puVar1[0xb] = uVar2;
  iVar4 = FUN_000920da();
  if ((iVar4 == 0) && (iVar4 = FUN_000909a4(), iVar4 == 0)) {
    FUN_0009005c();
  }
  return iVar4;
}

//==== 0x925e8  0x925e8-0x925eb inclusive
int thunk_FUN_00092044(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = FUN_00091fbc();
  iVar4 = FUN_000916d4(uVar3,0xe,0);
  uVar2 = DAT_000920b0/*=0xa7070025*/;
  puVar1 = DAT_000920ac/*=0x8000144*/;
  if (iVar4 == 0) {
    DataMemoryBarrier(0x1f);
    *DAT_000920ac/*=0x8000144*/ = DAT_000920b0/*=0xa7070025*/;
    DataMemoryBarrier(0x1f);
    *puVar1 = uVar2;
    FUN_0009147c(uVar3,0xe,800);
    FUN_000914a8(uVar3,0xe,DAT_000920b4/*"dcdc7"*/,0x438);
    FUN_000914a8(uVar3,0xe,DAT_000920b8/*"eldo1"*/,0x438);
    FUN_000914a8(uVar3,0xe,DAT_000920bc/*"dcdc6"*/,0x230);
    iVar4 = FUN_00092230();
    if (iVar4 == 0) {
      DataMemoryBarrier(0x1f);
      DataMemoryBarrier(0x1f);
      *DAT_00092040/*=0x8000200*/ = *DAT_00092040/*=0x8000200*/ | 1;
      return 0;
    }
  }
  return iVar4;
}

//==== 0x925ec  0x920de-0x920e1 inclusive
undefined4 FUN_000925ec(void)

{
  FUN_00090690(DAT_000925fc/*"board_late_init"*/);
  return 0;
}

//==== 0x92600  0x920e2-0x920e5 inclusive
undefined4 FUN_00092600(void)

{
  FUN_00090690(DAT_00092610/*"board_final_init"*/);
  return 0;
}

//==== 0x92634  0x92634-0x92679 inclusive
void FUN_00092634(undefined4 *param_1,uint *param_2,uint param_3,uint param_4)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  bVar2 = 0;
  while( true ) {
    uVar4 = *param_2;
    uVar5 = param_2[1];
    bVar6 = param_4 <= uVar5;
    if (uVar5 == param_4) {
      bVar6 = param_3 <= uVar4;
    }
    if (!bVar6) break;
    *param_2 = uVar4 - param_3;
    param_2[1] = (uVar5 - param_4) - (uint)(uVar4 < param_3);
    bVar2 = bVar2 + 1;
  }
  if ((*(char *)(param_1 + 1) != '\0') || (bVar2 != 0)) {
    pcVar3 = (char *)*param_1;
    if (bVar2 < 10) {
      cVar1 = '0';
    }
    else {
      cVar1 = 'W';
    }
    *param_1 = pcVar3 + 1;
    *pcVar3 = bVar2 + cVar1;
    *(undefined1 *)(param_1 + 1) = 1;
  }
  return;
}

//==== 0x9267c  0x9267c-0x929c3 inclusive
char * FUN_0009267c(int *param_1,byte *param_2,int *param_3)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  char *pcVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  byte bVar11;
  int *piVar12;
  char *pcVar13;
  char *pcVar14;
  bool bVar15;
  bool bVar16;
  longlong lVar17;
  int local_58;
  int local_50;
  int local_4c;
  undefined4 *local_48;
  undefined4 uStack_44;
  char local_40;
  undefined1 auStack_3f [27];
  
  bVar11 = 1;
  pcVar14 = (char *)0x0;
  do {
    while( true ) {
      bVar1 = *param_2;
      if (bVar1 == 0) {
        return pcVar14;
      }
      if (bVar1 == 0x25) break;
      if (bVar1 == 10) {
        (*(code *)param_1[4])(param_1,0xd);
        pcVar14 = pcVar14 + 1;
      }
      param_2 = param_2 + 1;
      pcVar14 = pcVar14 + 1;
      (*(code *)param_1[4])(param_1,bVar1);
    }
    uVar3 = (uint)param_2[1];
    if (uVar3 == 0x2d) {
      uVar3 = (uint)param_2[2];
      param_2 = param_2 + 3;
    }
    else {
      param_2 = param_2 + 2;
    }
    bVar15 = uVar3 == 0x30;
    if (bVar15) {
      uVar3 = (uint)*param_2;
      param_2 = param_2 + 1;
    }
    local_58 = 0;
    if (uVar3 - 0x30 < 10) {
      while (uVar3 - 0x30 < 10) {
        local_58 = local_58 * 10 + uVar3 + -0x30;
        uVar3 = (uint)*param_2;
        param_2 = param_2 + 1;
      }
    }
    if (uVar3 == 0x6c) {
      uVar3 = (uint)*param_2;
      if (uVar3 != 0x6c) goto LAB_000926f2;
      uVar3 = (uint)param_2[1];
      iVar5 = 1;
      param_2 = param_2 + 2;
      bVar16 = false;
    }
    else if (uVar3 == 0x7a) {
      uVar3 = (uint)*param_2;
LAB_000926f2:
      param_2 = param_2 + 1;
      iVar5 = 0;
      bVar16 = true;
    }
    else {
      iVar5 = 0;
      bVar16 = false;
    }
    pcVar13 = &local_40;
    *param_1 = (int)pcVar13;
    *(undefined1 *)(param_1 + 1) = 0;
    if (uVar3 == 100) {
LAB_000927ae:
      if (iVar5 == 0) {
        bVar11 = bVar11 + 1;
        piVar12 = param_3 + 1;
        local_50 = *param_3;
        uVar10 = DAT_000929cc/*=0x3b9aca00*/;
        if (bVar16) {
          uVar9 = 0;
          local_4c = iVar5;
          if (uVar3 == 100) {
LAB_000929a8:
            if (-1 < local_50) goto LAB_00092812;
LAB_000929b2:
            local_50 = -local_50;
            puVar6 = (undefined1 *)*param_1;
            *param_1 = (int)(puVar6 + 1);
            *puVar6 = 0x2d;
            local_4c = local_50 >> 0x1f;
          }
        }
        else {
          uVar9 = 0;
          local_4c = 0;
          if (uVar3 == 100) {
LAB_00092812:
            if ((iVar5 == 0 && !bVar16) && (local_50 < 0)) goto LAB_000929b2;
          }
        }
      }
      else {
        if ((bool)(bVar11 & 1)) {
          param_3 = param_3 + 1;
        }
        local_50 = *param_3;
        local_4c = param_3[1];
        piVar12 = param_3 + 2;
        if (uVar3 == 100) {
          if (local_4c < 0) {
            bVar16 = local_50 != 0;
            local_50 = -local_50;
            local_4c = -local_4c - (uint)bVar16;
            *param_1 = (int)auStack_3f;
            local_40 = '-';
          }
          else if (bVar16) {
            bVar11 = 0;
            uVar10 = DAT_000929c4/*=0x89e80000*/;
            uVar9 = DAT_000929c8/*=0x8ac72304*/;
            goto LAB_000929a8;
          }
        }
        bVar11 = 0;
        uVar10 = DAT_000929c4/*=0x89e80000*/;
        uVar9 = DAT_000929c8/*=0x8ac72304*/;
      }
      lVar17 = CONCAT44(uVar9,uVar10);
      if (local_4c == 0 && local_50 == 0) {
        puVar6 = (undefined1 *)*param_1;
        *param_1 = (int)(puVar6 + 1);
        *puVar6 = 0x30;
LAB_00092800:
        *(undefined1 *)(param_1 + 1) = 1;
      }
      else {
        do {
          uVar10 = (undefined4)((ulonglong)lVar17 >> 0x20);
          FUN_00092634(param_1,&local_50,(int)lVar17,uVar10);
          lVar17 = FUN_000a41b4((int)lVar17,uVar10,10,0);
        } while (lVar17 != 0);
      }
    }
    else if (uVar3 < 0x65) {
      if (uVar3 == 0x25) {
        local_40 = '%';
        *param_1 = (int)auStack_3f;
      }
      else {
        if (uVar3 == 99) {
          iVar5 = *param_3;
          piVar12 = param_3 + 1;
          *param_1 = (int)auStack_3f;
          bVar11 = bVar11 + 1;
          local_40 = (char)iVar5;
          goto LAB_00092868;
        }
        if (uVar3 == 0) {
          return pcVar14;
        }
      }
LAB_00092766:
      piVar12 = param_3;
    }
    else if (uVar3 == 0x73) {
      piVar12 = param_3 + 1;
      bVar11 = bVar11 + 1;
      pcVar13 = (char *)*param_3;
      if ((char *)*param_3 == (char *)0x0) {
        pcVar13 = DAT_000929d0/*"(null)"*/;
      }
    }
    else {
      if (0x73 < uVar3) {
        if (uVar3 == 0x75) goto LAB_000927ae;
        if (uVar3 != 0x78) goto LAB_00092766;
        if (iVar5 == 0) {
          local_50 = *param_3;
          piVar12 = param_3 + 1;
          bVar11 = bVar11 + 1;
          uVar8 = 0x10000000;
          uVar3 = 0;
          local_4c = iVar5;
        }
        else {
          uVar3 = 0x10000000;
          if ((bool)(bVar11 & 1)) {
            param_3 = param_3 + 1;
          }
          bVar11 = 0;
          local_50 = *param_3;
          piVar12 = param_3 + 2;
          uVar8 = 0;
          local_4c = param_3[1];
        }
        if (local_4c != 0 || local_50 != 0) {
          do {
            FUN_00092634(param_1,&local_50,uVar8,uVar3);
            uVar4 = uVar3 >> 4;
            uVar8 = uVar8 >> 4 | uVar3 << 0x1c;
            uVar3 = uVar4;
          } while (uVar8 != 0 || uVar4 != 0);
          goto LAB_00092868;
        }
        *param_1 = (int)auStack_3f;
        local_40 = '0';
        goto LAB_00092800;
      }
      if (uVar3 != 0x70) goto LAB_00092766;
      piVar12 = param_3 + 1;
      local_48 = (undefined4 *)*param_3;
      uStack_44 = 0;
      if ((*param_2 == 0x61) && (param_2[1] == 0x70)) {
        local_48 = (undefined4 *)*local_48;
      }
      iVar5 = 8;
      uVar3 = 0x10000000;
      do {
        FUN_00092634(param_1,&local_48,uVar3,0);
        uVar3 = uVar3 >> 4;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      bVar11 = bVar11 + 1;
      pbVar2 = param_2;
      do {
        do {
          param_2 = pbVar2;
          pbVar2 = param_2 + 1;
        } while ((*param_2 & 0xffffffdf) - 0x41 < 0x1a);
      } while (*param_2 - 0x30 < 10);
      pcVar13 = &local_40;
    }
LAB_00092868:
    *(undefined1 *)*param_1 = 0;
    *param_1 = (int)pcVar13;
    while (pcVar7 = (char *)*param_1, *param_1 = (int)(pcVar7 + 1), *pcVar7 != '\0') {
      if (local_58 == 0) goto LAB_00092976;
      local_58 = local_58 + -1;
    }
    iVar5 = local_58;
    if (bVar15) {
      uVar10 = 0x30;
    }
    else {
      uVar10 = 0x20;
    }
    while (bVar15 = iVar5 != 0, iVar5 = iVar5 + -1, bVar15) {
      (*(code *)param_1[4])(param_1,uVar10);
    }
    pcVar14 = pcVar14 + local_58;
LAB_00092976:
    iVar5 = (int)pcVar14 - (int)pcVar13;
    while( true ) {
      pcVar14 = pcVar13 + iVar5;
      param_3 = piVar12;
      if (*pcVar13 == '\0') break;
      (*(code *)param_1[4])(param_1);
      pcVar13 = pcVar13 + 1;
    }
  } while( true );
}

//==== 0x929d4  0x929d4-0x929fb inclusive
void FUN_000929d4(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 *local_1c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_24 = param_2;
  uStack_20 = param_3;
  local_1c = param_1;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_0009267c(&uStack_24,param_2,&uStack_8,DAT_000929fc/*=0x92625*/,&uStack_8);
  *local_1c = 0;
  return;
}

//==== 0x92a00  0x92a00-0x92a31 inclusive
undefined4 FUN_00092a00(undefined1 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iStack_24;
  undefined4 uStack_20;
  undefined1 *local_1c;
  undefined4 uStack_4;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    iStack_24 = param_2;
    uStack_20 = param_3;
    local_1c = param_1;
    uStack_4 = param_4;
    uVar1 = FUN_0009267c(&iStack_24,param_3,&uStack_4,DAT_00092a34/*=0x92615*/,&uStack_4);
    *local_1c = 0;
  }
  return uVar1;
}

//==== 0x92a38  0x92a38-0x92a57 inclusive
void FUN_00092a38(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_2c = param_2;
  uStack_28 = param_3;
  uStack_24 = param_4;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_0009267c(&uStack_2c,param_1,&uStack_c,DAT_00092a58/*=0x9262f*/,&uStack_c);
  return;
}

//==== 0x92a5c  0x92a5c-0x92a7b inclusive
void FUN_00092a5c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_2c = param_2;
  uStack_28 = param_3;
  uStack_24 = param_4;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_0009267c(&uStack_2c,param_1,&uStack_c,DAT_00092a7c/*=0x9262f*/,&uStack_c);
  return;
}

//==== 0x92a80  0x92a80-0x92afd inclusive
undefined4 FUN_00092a80(int param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  undefined8 uVar4;
  undefined1 auStack_134 [8];
  undefined1 *local_12c;
  undefined1 *local_128;
  undefined4 local_124;
  undefined1 local_120 [255];
  undefined1 uStack_21;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  pcVar3 = param_2;
  while( true ) {
    if (*pcVar3 != '\n') break;
    pcVar3 = pcVar3 + 1;
  }
  uStack_8 = param_3;
  uStack_4 = param_4;
  for (iVar2 = 0; iVar2 != (int)pcVar3 - (int)param_2; iVar2 = iVar2 + 1) {
    local_120[iVar2] = 10;
  }
  uVar4 = FUN_00091a7a();
  FUN_00092a00(local_120 + iVar2,0x100 - iVar2,DAT_00092b00/*"[%llu] "*/);
  iVar2 = FUN_00092bc6(local_120);
  local_128 = &uStack_21;
  local_12c = local_120 + iVar2;
  local_124 = DAT_00092b04/*=0x92615*/;
  uVar1 = FUN_0009267c(auStack_134,pcVar3,&uStack_8,DAT_00092b04/*=0x92615*/,uVar4,&uStack_8);
  *local_12c = 0;
  if (param_1 << 0x1f < 0) {
    FUN_00092a5c(local_120);
  }
  return uVar1;
}

//==== 0x92b08  0x92b08-0x92b17 inclusive
void FUN_00092b08(int param_1,char *param_2)

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

//==== 0x92b18  0x92b18-0x92b2f inclusive
void FUN_00092b18(int param_1,char *param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar3 = (char *)(param_1 + -1);
  pcVar2 = param_2;
  do {
    if (pcVar2 == param_2 + param_3) {
      return;
    }
    cVar1 = *pcVar2;
    pcVar3 = pcVar3 + 1;
    *pcVar3 = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  return;
}

//==== 0x92b76  0x92b76-0x92b8b inclusive
void FUN_00092b76(int param_1,char *param_2)

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

//==== 0x92b8c  0x92b8c-0x92bad inclusive
int FUN_00092b8c(int param_1,char *param_2,int param_3)

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

//==== 0x92bc6  0x92bc6-0x92bd5 inclusive
int FUN_00092bc6(char *param_1)

{
  char *pcVar1;
  
  pcVar1 = param_1;
  while (*pcVar1 != '\0') {
    pcVar1 = pcVar1 + 1;
  }
  return (int)pcVar1 - (int)param_1;
}

//==== 0x92bd6  0x92bd6-0x92bf5 inclusive
char * FUN_00092bd6(char *param_1,char param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  
  iVar1 = FUN_00092bc6();
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

//==== 0x92c30  0x92c30-0x92c39 inclusive
void FUN_00092c30(void)

{
  (*DAT_00092c3c/*=0x91de0*/)();
  return;
}

//==== 0x92c40  0x92c40-0x92c49 inclusive
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00092c40(void)

{
  (*_DAT_00092c4c)();
  return;
}

//==== 0x92c50  0x92c50-0x92c6d inclusive
int FUN_00092c50(int param_1,int param_2,int param_3)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    if (param_3 == iVar4) {
      return 0;
    }
    pcVar1 = (char *)(param_1 + iVar4);
    pcVar2 = (char *)(param_2 + iVar4);
    iVar4 = iVar4 + 1;
    iVar3 = (int)(char)(*pcVar1 - *pcVar2);
  } while (iVar3 == 0);
  return iVar3;
}

//==== 0x92cd8  0x92cd8-0x92cf3 inclusive
char * FUN_00092cd8(char *param_1,char param_2,int param_3)

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

//==== 0x92cf4  0x92cf4-0x92d1b inclusive
void FUN_00092cf4(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  FUN_00090690(DAT_00092d1c/*"malloc_init"*/);
  puVar2 = DAT_00092d24/*=0xc946c*/;
  puVar1 = DAT_00092d20/*=0xc945c*/;
  DAT_00092d20/*=0xc945c*/[2] = param_1;
  *puVar2 = 0;
  puVar1[3] = puVar2;
  puVar2[2] = param_1 + param_2;
  puVar2[3] = 0;
  puVar2 = DAT_00092d28/*=0xc947c*/;
  *puVar1 = 0;
  *puVar2 = 1;
  return;
}

//==== 0x92e20  0x92e20-0x92e23 inclusive
uint FUN_00092e20(uint param_1)

{
  return param_1 << 0x18 | (param_1 >> 8 & 0xff) << 0x10 | (param_1 >> 0x10 & 0xff) << 8 |
         param_1 >> 0x18;
}

//==== 0x92e3e  0x92e24-0x92e4d inclusive
undefined4 FUN_00092e3e(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = FUN_00092e20(*(undefined4 *)(param_1 + 0x14));
  if (uVar2 < 2) {
    return 0x1c;
  }
  if (uVar2 == 2) {
    return 0x20;
  }
  if (uVar2 < 0x11) {
    uVar1 = 0x24;
  }
  else {
    uVar1 = 0x28;
  }
  return uVar1;
}

//==== 0x92e50  0x92e50-0x92f0b inclusive
undefined4
FUN_00092e50(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int extraout_r2;
  int extraout_r2_00;
  undefined4 extraout_r2_01;
  int extraout_r2_02;
  int extraout_r2_03;
  int extraout_r2_04;
  int extraout_r2_05;
  int extraout_r2_06;
  int extraout_r2_07;
  uint extraout_r3;
  uint extraout_r3_00;
  uint extraout_r3_01;
  uint extraout_r3_02;
  bool bVar6;
  undefined8 uVar7;
  
  if (((uint)param_1 & 7) != 0) {
    return 0xffffffed;
  }
  iVar1 = FUN_00092e20(*param_1,param_2,param_1,0,param_4);
  if (iVar1 != DAT_00092f0c/*=0xd00dfeed*/) {
    return 0xfffffff7;
  }
  uVar2 = FUN_00092e20(*(undefined4 *)(extraout_r2 + 0x14));
  if (((uVar2 < 2) || (uVar3 = FUN_00092e20(*(undefined4 *)(extraout_r2_00 + 0x18)), 0x11 < uVar3))
     || (uVar2 < uVar3)) {
    return 0xfffffff6;
  }
  uVar3 = FUN_00092e3e(extraout_r2_01);
  uVar4 = FUN_00092e20(*(undefined4 *)(extraout_r2_02 + 4));
  if (((uVar3 <= uVar4) && (-1 < (int)uVar4)) &&
     ((uVar4 = FUN_00092e20(*(undefined4 *)(extraout_r2_03 + 0x10)), uVar3 <= uVar4 &&
      (uVar4 <= extraout_r3)))) {
    uVar4 = FUN_00092e20(*(undefined4 *)(extraout_r2_04 + 8));
    if (uVar2 < 0x11) {
      if (uVar4 < uVar3) {
        return 0xfffffff8;
      }
      bVar6 = uVar4 <= extraout_r3_00;
      iVar1 = extraout_r2_05;
    }
    else {
      uVar7 = FUN_00092e20(*(undefined4 *)(extraout_r2_05 + 0x24),uVar4);
      uVar4 = (uint)((ulonglong)uVar7 >> 0x20);
      if (uVar4 < uVar3) {
        return 0xfffffff8;
      }
      if (extraout_r3_01 < uVar4) {
        return 0xfffffff8;
      }
      if (CARRY4((uint)uVar7,uVar4)) {
        return 0xfffffff8;
      }
      bVar6 = (uint)uVar7 + uVar4 <= extraout_r3_01;
      iVar1 = extraout_r2_06;
    }
    if (bVar6) {
      uVar5 = FUN_00092e20(*(undefined4 *)(iVar1 + 0xc),uVar4);
      uVar7 = FUN_00092e20(*(undefined4 *)(extraout_r2_07 + 0x20),uVar5);
      uVar2 = (uint)((ulonglong)uVar7 >> 0x20);
      if (((uVar3 <= uVar2) && (uVar2 <= extraout_r3_02)) && (!CARRY4(uVar2,(uint)uVar7))) {
        if (extraout_r3_02 < uVar2 + (uint)uVar7) {
          return 0xfffffff8;
        }
        return 0;
      }
    }
  }
  return 0xfffffff8;
}

//==== 0x92f10  0x92f10-0x92f57 inclusive
int FUN_00092f10(int param_1)

{
  uint uVar1;
  uint extraout_r2;
  uint extraout_r2_00;
  int extraout_r3;
  int extraout_r3_00;
  int extraout_r3_01;
  int iVar2;
  uint uVar3;
  longlong lVar4;
  undefined8 uVar5;
  
  lVar4 = FUN_00092e20(*(undefined4 *)(param_1 + 8));
  uVar1 = (uint)((ulonglong)lVar4 >> 0x20);
  uVar3 = (uint)lVar4 + uVar1;
  if ((lVar4 < 0) || (CARRY4((uint)lVar4,uVar1))) {
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    if ((!CARRY4(uVar3,extraout_r2)) &&
       (uVar1 = FUN_00092e20(*(undefined4 *)(param_1 + 4)), iVar2 = extraout_r3,
       uVar3 + extraout_r2 <= uVar1)) {
      uVar5 = FUN_00092e20(*(undefined4 *)(param_1 + 0x14));
      uVar1 = (uint)((ulonglong)uVar5 >> 0x20);
      if (((uint)uVar5 < 0x11) ||
         ((iVar2 = extraout_r3_00, !CARRY4(uVar1,extraout_r2_00) &&
          (uVar5 = FUN_00092e20(*(undefined4 *)(param_1 + 0x24),uVar1 + extraout_r2_00),
          iVar2 = extraout_r3_01, (uint)((ulonglong)uVar5 >> 0x20) <= (uint)uVar5)))) {
        iVar2 = param_1 + uVar3;
      }
    }
  }
  return iVar2;
}

//==== 0x92f58  0x92f58-0x92f91 inclusive
int FUN_00092f58(int param_1,int param_2,uint *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  uint extraout_r2;
  uint uVar5;
  uint extraout_r3;
  int iVar6;
  undefined8 uVar7;
  
  *param_3 = 0xfffffff8;
  puVar1 = (undefined4 *)FUN_00092f10(param_1,param_2,4,0xfffffff8,param_4);
  if (puVar1 != (undefined4 *)0x0) {
    iVar6 = param_2 + 4;
    iVar2 = FUN_00092e20(*puVar1);
    *param_3 = 0xfffffff5;
    uVar5 = iVar2 - 1;
    iVar4 = iVar6;
    switch(uVar5) {
    case 0:
      do {
        iVar6 = iVar4 + 1;
        pbVar3 = (byte *)FUN_00092f10(param_1,iVar4,1,uVar5,param_4);
        if (pbVar3 == (byte *)0x0) {
          return 9;
        }
        uVar5 = (uint)*pbVar3;
        iVar4 = iVar6;
      } while (uVar5 != 0);
      break;
    case 1:
    case 3:
    case 8:
      break;
    case 2:
      puVar1 = (undefined4 *)FUN_00092f10(param_1,iVar6,4,uVar5,param_4);
      if (puVar1 == (undefined4 *)0x0) {
        return 9;
      }
      uVar7 = FUN_00092e20(*puVar1);
      iVar6 = (int)uVar7 + param_2 + 0xc;
      uVar5 = FUN_00092e20(*(undefined4 *)(param_1 + 0x14),(int)((ulonglong)uVar7 >> 0x20),
                           (int)uVar7);
      if (((uVar5 < 0x10) && (7 < extraout_r2)) && ((extraout_r3 & 7) != 0)) {
        iVar6 = iVar6 + 4;
      }
      break;
    default:
      goto LAB_00092fea;
    }
    iVar4 = FUN_00092f10(param_1,param_2,iVar6 - param_2);
    if (iVar4 != 0) {
      *param_3 = iVar6 + 3U & 0xfffffffc;
      return iVar2;
    }
  }
LAB_00092fea:
  return 9;
}

//==== 0x93024  0x93024-0x93047 inclusive
uint FUN_00093024(undefined4 param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint local_c;
  undefined4 uStack_8;
  
  if ((-1 < (int)param_2) && ((param_2 & 3) == 0)) {
    local_c = param_2;
    uStack_8 = param_3;
    iVar1 = FUN_00092f58(param_1,param_2,&local_c,0,param_1);
    if (iVar1 == 1) goto LAB_00093030;
  }
  local_c = 0xfffffffc;
LAB_00093030:
  return local_c;
}

//==== 0x93048  0x93048-0x9306b inclusive
uint FUN_00093048(undefined4 param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint local_c;
  undefined4 uStack_8;
  
  if ((-1 < (int)param_2) && ((param_2 & 3) == 0)) {
    local_c = param_2;
    uStack_8 = param_3;
    iVar1 = FUN_00092f58(param_1,param_2,&local_c,0,param_1);
    if (iVar1 == 3) goto LAB_00093054;
  }
  local_c = 0xfffffffc;
LAB_00093054:
  return local_c;
}

//==== 0x9306c  0x9306c-0x930d9 inclusive
int FUN_0009306c(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int local_14;
  
  local_14 = 0;
  if ((param_2 < 0) || (local_14 = FUN_00093024(), -1 < local_14)) {
    do {
      while( true ) {
        iVar2 = local_14;
        iVar1 = FUN_00092f58(param_1,local_14,&local_14);
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

//==== 0x930da  0x930da-0x930dd inclusive
uint FUN_000930da(uint param_1)

{
  return param_1 << 0x18 | (param_1 >> 8 & 0xff) << 0x10 | (param_1 >> 0x10 & 0xff) << 8 |
         param_1 >> 0x18;
}

//==== 0x93110  0x93110-0x93145 inclusive
int FUN_00093110(int param_1,int param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = FUN_00093048();
  if (iVar1 < 0) {
    if (param_3 == (int *)0x0) {
      param_1 = 0;
    }
    else {
      param_1 = 0;
      *param_3 = iVar1;
    }
  }
  else {
    iVar1 = FUN_000930da(*(undefined4 *)(param_1 + 8));
    param_1 = param_1 + iVar1 + param_2;
    if (param_3 != (int *)0x0) {
      iVar1 = FUN_000930da(*(undefined4 *)(param_1 + 4));
      *param_3 = iVar1;
    }
  }
  return param_1;
}

//==== 0x93146  0x93146-0x93155 inclusive
int FUN_00093146(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int extraout_r3;
  undefined8 uVar1;
  
  uVar1 = FUN_000930da(*(undefined4 *)(param_1 + 0xc),param_2,param_3,param_1,param_4);
  return (int)uVar1 + (int)((ulonglong)uVar1 >> 0x20) + extraout_r3;
}

//==== 0x93156  0x93156-0x931b5 inclusive
int FUN_00093156(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  iVar1 = FUN_000930da(*(undefined4 *)(param_1 + 8));
  iVar2 = FUN_00092e50(param_1);
  if ((iVar2 == 0) && (iVar2 = FUN_00093024(param_1,param_2), -1 < iVar2)) {
    uVar3 = FUN_000930da(*(undefined4 *)(param_1 + 0x14));
    iVar1 = param_2 + iVar1 + param_1 + 4;
    if (uVar3 < 0x10) {
      iVar1 = FUN_00092bd6(iVar1,0x2f);
      if (iVar1 == 0) goto LAB_000931a6;
      iVar1 = iVar1 + 1;
    }
    if (param_3 != (undefined4 *)0x0) {
      uVar4 = FUN_00092bc6(iVar1);
      *param_3 = uVar4;
    }
  }
  else {
LAB_000931a6:
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

//==== 0x931b6  0x931b6-0x93239 inclusive
int FUN_000931b6(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int local_20;
  int local_1c;
  
  local_20 = param_1;
  local_1c = param_2;
  iVar1 = FUN_00092e50();
  if (iVar1 == 0) {
    local_20 = 0;
    for (; -1 < param_2; param_2 = FUN_0009306c(param_1,param_2,&local_20)) {
      if (local_20 < 0) {
        return -1;
      }
      if ((((local_20 == 1) && (iVar1 = FUN_00093156(param_1,param_2,&local_1c), iVar1 != 0)) &&
          (param_4 <= local_1c)) && (iVar2 = FUN_00092c50(iVar1,param_3,param_4), iVar2 == 0)) {
        if (*(char *)(iVar1 + param_4) == '\0') {
          return param_2;
        }
        iVar2 = FUN_00092cd8(param_3,0x40,param_4);
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

//==== 0x9323a  0x930de-0x9310f inclusive
int FUN_0009323a(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar4;
  int local_14 [3];
  
  local_14[0] = FUN_00093024();
  if (local_14[0] < 0) {
    return local_14[0];
  }
  uVar4 = param_1;
  uVar3 = extraout_r3_00;
  while( true ) {
    iVar1 = local_14[0];
    iVar2 = FUN_00092f58(param_1,local_14[0],local_14,uVar3,uVar4);
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

//==== 0x93252  0x93252-0x93269 inclusive
int FUN_00093252(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar4;
  int aiStack_14 [3];
  
  aiStack_14[0] = FUN_00093048();
  if (aiStack_14[0] < 0) {
    return aiStack_14[0];
  }
  uVar4 = param_1;
  uVar3 = extraout_r3_00;
  while( true ) {
    iVar1 = aiStack_14[0];
    iVar2 = FUN_00092f58(param_1,aiStack_14[0],aiStack_14,uVar3,uVar4);
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

//==== 0x9326a  0x9326a-0x932df inclusive
int FUN_0009326a(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int *param_5,
                int *param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = FUN_0009323a();
  do {
    if (iVar1 < 0) {
LAB_00093282:
      if (param_5 != (int *)0x0) {
        *param_5 = iVar1;
      }
      return 0;
    }
    iVar2 = FUN_00093110(param_1,iVar1,param_5);
    if (iVar2 == 0) {
      iVar1 = -0xd;
      goto LAB_00093282;
    }
    uVar3 = FUN_000930da(*(undefined4 *)(iVar2 + 8));
    uVar3 = FUN_00093146(param_1,uVar3);
    iVar4 = FUN_00092bc6();
    if ((iVar4 == param_4) && (iVar4 = FUN_00092c50(uVar3,param_3,param_4), iVar4 == 0)) {
      if (param_6 == (int *)0x0) {
        return iVar2;
      }
      *param_6 = iVar1;
      return iVar2;
    }
    iVar1 = FUN_00093252(param_1,iVar1);
  } while( true );
}

//==== 0x932e0  0x932e0-0x93303 inclusive
undefined4 FUN_000932e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *extraout_r2;
  undefined4 extraout_r3;
  
  uVar1 = FUN_000930da(*(undefined4 *)(param_1 + 0x14),param_2,param_3,param_1);
  if (0xf < uVar1) {
    uVar2 = FUN_00093110(extraout_r3);
    return uVar2;
  }
  if (extraout_r2 != (undefined4 *)0x0) {
    *extraout_r2 = 0xfffffff6;
  }
  return 0;
}

//==== 0x93304  0x93304-0x93343 inclusive
int FUN_00093304(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int extraout_r3;
  int extraout_r3_00;
  int local_14;
  
  iVar1 = FUN_0009326a();
  iVar3 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_000930da(*(undefined4 *)(param_1 + 0x14));
    iVar3 = extraout_r3;
    if (((uVar2 < 0x10) && ((local_14 + 0xcU & 7) != 0)) &&
       (uVar2 = FUN_000930da(*(undefined4 *)(extraout_r3 + 4)), iVar3 = extraout_r3_00, 7 < uVar2))
    {
      iVar3 = extraout_r3_00 + 0x10;
    }
    else {
      iVar3 = iVar3 + 0xc;
    }
  }
  return iVar3;
}

//==== 0x93344  0x93344-0x93365 inclusive
void FUN_00093344(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = param_2;
  uVar3 = param_3;
  uVar1 = FUN_00092bc6(param_3);
  FUN_00093304(param_1,param_2,param_3,uVar1,param_4,uVar2,uVar3);
  return;
}

//==== 0x93368  0x93368-0x933a3 inclusive
undefined4 FUN_00093368(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int local_14;
  undefined4 uStack_10;
  
  uVar2 = param_1;
  local_14 = param_2;
  uStack_10 = param_3;
  puVar1 = (undefined4 *)FUN_00093344(param_1,param_2,DAT_000933a4/*"phandle"*/,&local_14,param_1);
  if (((puVar1 == (undefined4 *)0x0) || (local_14 != 4)) &&
     ((puVar1 = (undefined4 *)FUN_00093344(param_1,param_2,DAT_000933a8/*"linux,phandle"*/,&local_14,uVar2),
      puVar1 == (undefined4 *)0x0 || (local_14 != 4)))) {
    return 0;
  }
  uVar2 = FUN_000930da(*puVar1);
  return uVar2;
}

//==== 0x933ac  0x933ac-0x933d1 inclusive
void FUN_000933ac(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_00093460(param_1,DAT_000933d4/*"/aliases"*/,param_3,param_4,param_1,param_2);
  if (-1 < iVar1) {
    FUN_00093304(param_1,iVar1,param_2,param_3,0);
  }
  return;
}

//==== 0x93460  0x933d8-0x93479 inclusive
int FUN_00093460(undefined4 param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  undefined4 unaff_r4;
  char *pcVar4;
  undefined4 unaff_r5;
  char *pcVar5;
  
  iVar3 = FUN_00092bc6(param_2);
  iVar1 = FUN_00092e50();
  if (iVar1 == 0) {
    pcVar5 = param_2 + iVar3;
    pcVar2 = param_2;
    if (*param_2 != '/') {
      pcVar2 = (char *)FUN_00092cd8(param_2,0x2f,iVar3,*param_2,unaff_r4,unaff_r5);
      if (pcVar2 == (char *)0x0) {
        pcVar2 = pcVar5;
      }
      else {
      }
      iVar1 = FUN_000933ac(param_1,param_2,(int)pcVar2 - (int)param_2);
      if (iVar1 == 0) {
        return -5;
      }
      iVar1 = FUN_00093460(param_1,iVar1);
    }
    while (pcVar2 < pcVar5) {
      pcVar4 = pcVar2;
      while( true ) {
        pcVar2 = pcVar4 + 1;
        if (*pcVar4 != '/') break;
        pcVar4 = pcVar2;
        if (pcVar5 == pcVar2) {
          return iVar1;
        }
      }
      pcVar2 = (char *)FUN_00092cd8(pcVar4,0x2f,(int)pcVar5 - (int)pcVar4,*pcVar4,unaff_r4,unaff_r5)
      ;
      if (pcVar2 == (char *)0x0) {
        pcVar2 = pcVar5;
      }
      else {
      }
      iVar1 = FUN_000931b6(param_1,iVar1,pcVar4,(int)pcVar2 - (int)pcVar4);
      if (iVar1 < 0) {
        return iVar1;
      }
    }
  }
  return iVar1;
}

//==== 0x9347a  0x9347a-0x934bb inclusive
int FUN_0009347a(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 - 1U < 0xfffffffd || param_2 == -2) {
    iVar1 = FUN_00092e50();
    if (iVar1 == 0) {
      iVar1 = -1;
      do {
        iVar1 = FUN_0009306c(param_1,iVar1,0);
        if (iVar1 < 0) break;
        iVar2 = FUN_00093368(param_1,iVar1);
      } while (iVar2 != param_2);
    }
  }
  else {
    iVar1 = -6;
  }
  return iVar1;
}

//==== 0x934bc  0x934bc-0x934bf inclusive
uint FUN_000934bc(uint param_1)

{
  return param_1 << 0x18 | (param_1 >> 8 & 0xff) << 0x10 | (param_1 >> 0x10 & 0xff) << 8 |
         param_1 >> 0x18;
}

//==== 0x934c0  0x934c0-0x93503 inclusive
int FUN_000934c0(undefined4 param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int extraout_r2;
  int iVar2;
  int iVar3;
  int extraout_r3;
  undefined8 uVar4;
  
  iVar1 = FUN_00093344();
  if (((iVar1 == 0) || (param_2 == 0)) || ((param_2 & 3) != 0)) {
    iVar3 = -0xd;
  }
  else {
    if ((int)param_2 < 0) {
      param_2 = param_2 + 3;
    }
    iVar3 = (int)param_2 >> 2;
    if (param_4 != 0) {
      iVar2 = 0;
      while (iVar2 < iVar3) {
        uVar4 = FUN_000934bc(*(undefined4 *)(iVar1 + iVar2 * 4));
        iVar1 = (int)((ulonglong)uVar4 >> 0x20);
        *(int *)(param_4 + extraout_r2 * 4) = (int)uVar4;
        iVar3 = extraout_r3;
        iVar2 = extraout_r2 + 1;
      }
    }
  }
  return iVar3;
}

//==== 0x93504  0x93504-0x93507 inclusive
uint FUN_00093504(uint param_1)

{
  return param_1 << 0x18 | (param_1 >> 8 & 0xff) << 0x10 | (param_1 >> 0x10 & 0xff) << 8 |
         param_1 >> 0x18;
}

//==== 0x93508  0x93508-0x93577 inclusive
undefined4 FUN_00093508(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined8 uVar3;
  
  puVar1 = DAT_0009357c/*=0xa6738*/;
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {
    FUN_00092a80(3,DAT_00093578/*"Invalid parameters\n"*/);
  }
  else {
    iVar2 = FUN_00093460(*DAT_0009357c/*=0xa6738*/,param_1,param_3,param_4,param_1,param_2,param_3);
    if (iVar2 < 0) {
      FUN_00092a80(3,DAT_00093580/*"fdt err returned %d\n"*/,iVar2);
    }
    else {
      iVar2 = FUN_000934c0(*puVar1,iVar2,param_2,0);
      if (iVar2 < 0) {
        FUN_00092a80(3,DAT_00093588/*"%s :%s|%s err returned %d\n"*/,DAT_00093584/*"fdt_get_property_count"*/,param_1,param_2,iVar2);
      }
      else {
        uVar3 = FUN_000a39ac(iVar2,param_3);
        if ((int)((ulonglong)uVar3 >> 0x20) == 0) {
          return (int)uVar3;
        }
        FUN_00092a80(3,DAT_0009358c/*"Bad property len %d(element size=%d)\n"*/,iVar2,param_3);
      }
    }
  }
  return 0xffffffff;
}

//==== 0x93590  0x93590-0x93645 inclusive
undefined4 FUN_00093590(undefined4 param_1,undefined4 param_2,undefined4 *param_3,uint param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int extraout_r2;
  int extraout_r3;
  int extraout_r3_00;
  int extraout_r3_01;
  int extraout_r3_02;
  int extraout_r3_03;
  undefined8 uVar5;
  uint local_1c;
  
  local_1c = param_4;
  uVar2 = FUN_00093508(param_1,param_2,6,param_4,param_1,param_2,param_3);
  puVar1 = DAT_00093658/*=0xa6738*/;
  if (((int)uVar2 < 0) || (uVar2 <= param_4)) {
    FUN_00092a80(3,DAT_00093648/*"Index %d out of range, total count is %d\n"*/,param_4);
  }
  else {
    iVar3 = FUN_00093460(*DAT_00093658/*=0xa6738*/,param_1);
    if (iVar3 < 0) {
      FUN_00092a80(3,DAT_0009364c/*"fdt err returned %d\n"*/,iVar3);
    }
    else {
      uVar5 = FUN_00093344(*puVar1,iVar3,param_2,&local_1c);
      iVar3 = (int)uVar5;
      if ((iVar3 != 0) && (-1 < (int)local_1c)) {
        uVar4 = FUN_00093504(*(undefined4 *)(iVar3 + param_4 * 0x18),(int)((ulonglong)uVar5 >> 0x20)
                             ,param_4 * 6,iVar3);
        *param_3 = uVar4;
        uVar5 = FUN_00093504(*(undefined4 *)(extraout_r3 + (extraout_r2 + 1) * 4),
                             (extraout_r2 + 1) * 4);
        param_3[1] = (int)uVar5;
        uVar4 = FUN_00093504(*(undefined4 *)(extraout_r3_00 + (int)((ulonglong)uVar5 >> 0x20) + 4));
        param_3[2] = uVar4;
        uVar4 = FUN_00093504(*(undefined4 *)(extraout_r3_01 + 8));
        param_3[3] = uVar4;
        uVar4 = FUN_00093504(*(undefined4 *)(extraout_r3_02 + 0xc));
        param_3[4] = uVar4;
        uVar4 = FUN_00093504(*(undefined4 *)(extraout_r3_03 + 0x10));
        param_3[5] = uVar4;
        return 0;
      }
      FUN_00092a80(3,DAT_00093654/*"%s :%s|%s err returned %d\n"*/,DAT_00093650/*"fdt_get_one_gpio_by_index"*/,param_1,param_2,local_1c);
    }
  }
  return 0xffffffff;
}

//==== 0x9365c  0x9365c-0x936c7 inclusive
uint FUN_0009365c(int param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  
  if ((((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) || (param_4 == 0)) {
    FUN_00092a80(3,DAT_000936c8/*"Invalid parameters\n"*/);
  }
  else {
    uVar1 = FUN_00093508(param_1,param_2,6);
    if ((int)param_4 <= (int)uVar1) {
      if (param_4 < uVar1) {
        FUN_00092a80(3,DAT_000936cc/*"DTS GPIO cfg count %d > max %d, truncating\n"*/,uVar1,param_4);
      }
      uVar1 = 0;
      while (iVar2 = FUN_00093590(param_1,param_2,uVar1 * 0x18 + param_3,uVar1), iVar2 == 0) {
        uVar1 = uVar1 + 1;
        if (param_4 == uVar1) {
          return param_4;
        }
      }
      FUN_00092a80(3,DAT_000936d0/*"Failed to get GPIO at index %d\n"*/,uVar1);
    }
  }
  return 0xffffffff;
}

//==== 0x936d4  0x936d4-0x93715 inclusive
int FUN_000936d4(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_1c;
  undefined4 uStack_18;
  
  puVar1 = DAT_00093718/*=0xa6738*/;
  uVar4 = *DAT_00093718/*=0xa6738*/;
  uVar5 = param_1;
  local_1c = param_2;
  uStack_18 = param_3;
  uVar2 = FUN_00092bc6();
  iVar3 = FUN_000933ac(uVar4,param_1,uVar2);
  if (iVar3 == 0) {
    iVar3 = -1;
  }
  else {
    iVar3 = FUN_00093460(*puVar1,iVar3);
    if ((-1 < iVar3) && (iVar3 = FUN_000934c0(*puVar1,iVar3,param_2,&local_1c,uVar5), -1 < iVar3)) {
      iVar3 = local_1c;
    }
  }
  return iVar3;
}

//==== 0x9371c  0x9371c-0x9371f inclusive
void thunk_FUN_00091a8c(int param_1)

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

//==== 0x93720  0x93720-0x9373f inclusive
uint FUN_00093720(int param_1,int param_2)

{
  uint uVar1;
  int extraout_r1;
  
  FUN_000a39ac(param_2 * param_1,1000);
  uVar1 = (uint)((ulonglong)(uint)(param_2 * param_1) * (ulonglong)DAT_00093740/*=0x10624dd3*/ >> 0x26);
  if (extraout_r1 != 0) {
    uVar1 = uVar1 + 1;
  }
  return uVar1;
}

//==== 0x93744  0x93744-0x937b7 inclusive
undefined4 FUN_00093744(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = DAT_000937bc/*=0xfedcba98*/;
  iVar4 = DAT_000937b8/*=0x1234567*/;
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
      FUN_00092a38(DAT_000937c0/*"DRAM simple test OK.\n"*/);
      return 0;
    }
    if (iVar4 + DAT_000937bc/*=0xfedcba98*/ != piVar2[param_1 * 0x40000]) break;
    if (iVar4 + DAT_000937b8/*=0x1234567*/ != *piVar2) {
      FUN_00092a38(DAT_000937c4/*"DRAM simple test FAIL-----%x != %x at address %x\n"*/);
      return 1;
    }
    iVar4 = iVar4 + 1;
    piVar2 = piVar2 + 1;
  }
  FUN_00092a38(DAT_000937c4/*"DRAM simple test FAIL-----%x != %x at address %x\n"*/,piVar2[param_1 * 0x40000],iVar4 + DAT_000937bc/*=0xfedcba98*/,
               piVar2 + param_1 * 0x40000,param_4);
  FUN_00092a38(DAT_000937c8/*"  read 10 times again\n"*/);
  return 1;
}

//==== 0x937cc  0x937cc-0x9380d inclusive
void FUN_000937cc(int param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  iVar1 = DAT_00093814/*=0xa110080*/;
  param_1 = param_1 * 0x400000;
  piVar4 = (int *)(DAT_00093810/*=0xa110090*/ + param_1);
  do {
  } while (*piVar4 << 0x1f < 0);
  *(undefined4 *)(param_1 + DAT_00093814/*=0xa110080*/) = 0x10;
  iVar2 = DAT_00093818/*=0xa110084*/;
  *(uint *)(param_1 + DAT_00093818/*=0xa110084*/) = param_3 | param_2 << 8;
  *(undefined4 *)(param_1 + iVar1) = DAT_0009381c/*=0x80000010*/;
  uVar3 = DAT_00093820/*=0x80000020*/;
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

//==== 0x93824  0x93824-0x93879 inclusive
uint FUN_00093824(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  
  iVar1 = DAT_00093880/*=0xa110080*/;
  iVar4 = param_2 * 0x400000;
  do {
  } while (*(int *)(DAT_0009387c/*=0xa110090*/ + iVar4) << 0x1f < 0);
  uVar2 = 1 << (param_3 + 4U & 0xff);
  *(uint *)(iVar4 + DAT_00093880/*=0xa110080*/) = uVar2 | 1;
  *(int *)(iVar4 + DAT_00093884/*=0xa110084*/) = param_4 << 8;
  *(uint *)(iVar4 + iVar1) = uVar2 | 0x80000001;
  do {
  } while (*(int *)(iVar4 + iVar1) < 0);
  if ((*(int *)(param_1 + 4) == 8) && (param_2 == 1)) {
    uVar2 = *DAT_00093888/*=0xa020040*/ & 0xff;
  }
  else {
    if (param_2 == 0) {
      puVar3 = DAT_0009388c/*=0xa02002c*/;
    }
    else {
      puVar3 = DAT_00093888/*=0xa020040*/;
    }
    uVar2 = (*puVar3 & 0xffff) >> 8;
  }
  return uVar2;
}

//==== 0x93890  0x93890-0x939a5 inclusive
int FUN_00093890(int param_1)

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
      iVar2 = FUN_000920c0(DAT_000939b4/*"dcdc7"*/,iVar4,1);
      goto LAB_00093906;
    }
    iVar2 = FUN_000920c0(DAT_000939a8/*"dcdc8"*/,iVar4,1);
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
        iVar2 = FUN_000920c0(DAT_000939b4/*"dcdc7"*/,iVar6,1);
      }
      else {
        iVar2 = FUN_000920c0(DAT_000939b4/*"dcdc7"*/,0x4b0,1);
        iVar6 = 0x4b0;
      }
      iVar6 = FUN_000920c0(DAT_000939ac/*"eldo1"*/,iVar6,1);
      iVar2 = iVar2 + iVar6;
LAB_00093906:
      uVar1 = DAT_000939b8/*"dcdc6"*/;
      goto LAB_000938de;
    }
    if (uVar3 == 0) {
      iVar2 = FUN_000920c0(DAT_000939a8/*"dcdc8"*/,iVar6,1);
    }
    else {
      iVar2 = FUN_000920c0(DAT_000939a8/*"dcdc8"*/,0x4b0,1);
      iVar6 = 0x4b0;
    }
    iVar6 = FUN_000920c0(DAT_000939bc/*"eldo2"*/,iVar6,1);
    iVar2 = iVar2 + iVar6;
  }
  uVar1 = DAT_000939ac/*"eldo1"*/;
LAB_000938de:
  iVar5 = FUN_000920c0(uVar1,iVar5,1);
  if (iVar5 + iVar2 == 0) {
    FUN_00092a38(DAT_000939c0/*"DRAM_VCC set to %d mv\n"*/,iVar4);
    return iVar4;
  }
  FUN_00092a38(DAT_000939b0/*"POWER SETTING ERROR!\n"*/);
  return 0;
}

//==== 0x939c4  0x939c4-0x93a17 inclusive
uint FUN_000939c4(int param_1)

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

//==== 0x93a18  0x93a18-0x93a5b inclusive
int FUN_00093a18(uint param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)((ulonglong)param_1 * (ulonglong)DAT_00093a5c/*=0xaaaaaaab*/ >> 0x24);
  *param_2 = DAT_00093a60/*=0xff8f00fd*/ & *param_2 | 0x1000000 | (uVar2 - 1) * 0x100;
  uVar1 = *param_2;
  *param_2 = uVar1 | 0xc0000000;
  *param_2 = uVar1 | 0xe0000000;
  FUN_00091a8c(0x14);
  do {
  } while (-1 < (int)(*param_2 << 3));
  *param_2 = uVar1 | 0xe8000000;
  return uVar2 * 0x18;
}

//==== 0x93a64  0x93a64-0x93bd7 inclusive
void FUN_00093a64(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  
  iVar3 = DAT_00093bd8/*=0xa110c80*/;
  uVar6 = param_2 + 1;
  uVar1 = 0;
  while (iVar5 = DAT_00093bdc/*=0xa110510*/, (uVar1 & 0xffff) < uVar6) {
    *(undefined4 *)(uVar1 * 0x400000 + iVar3) = 0;
    uVar1 = uVar1 + 1;
  }
  uVar2 = 0;
  while( true ) {
    iVar3 = DAT_00093bdc/*=0xa110510*/;
    if (uVar6 <= uVar2) break;
    iVar3 = (uint)uVar2 * 0x400000;
    *(uint *)(iVar3 + iVar5) = *(uint *)(iVar3 + iVar5) | 0x1001;
    uVar2 = uVar2 + 1;
  }
  uVar2 = 0;
  while( true ) {
    iVar5 = DAT_00093bd8/*=0xa110c80*/;
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
    } while (-1 < *(int *)(DAT_00093be0/*=0xa110c84*/ + (uint)uVar2 * 0x400000) << 0x1f);
  }
  for (uVar1 = 0; (uVar1 & 0xffff) < uVar6; uVar1 = uVar1 + 1) {
    do {
    } while (-1 < *(int *)(DAT_00093be4/*=0xa110514*/ + uVar1 * 0x400000) << 0x1f);
  }
  FUN_00091a8c(0x32);
  *DAT_00093be8/*=0x7010250*/ = *DAT_00093be8/*=0x7010250*/ | 1;
  FUN_00091a8c(2000);
  iVar3 = DAT_00093bd8/*=0xa110c80*/;
  uVar1 = 0;
  while (iVar5 = DAT_00093bdc/*=0xa110510*/, (uVar1 & 0xffff) < uVar6) {
    *(undefined4 *)(uVar1 * 0x400000 + iVar3) = 0;
    uVar1 = uVar1 + 1;
  }
  uVar2 = 0;
  while( true ) {
    iVar3 = DAT_00093bec/*=0xa110180*/;
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
    puVar4 = (uint *)(DAT_00093bf0/*=0xa110014*/ + uVar1 * 0x400000);
    do {
    } while ((*puVar4 & 0x30) != 0);
    do {
    } while ((*puVar4 & 3) != 1);
  }
  FUN_00091a8c(0x32);
  iVar3 = DAT_00093bdc/*=0xa110510*/;
  uVar2 = 0;
  while( true ) {
    iVar5 = DAT_00093bd8/*=0xa110c80*/;
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
    } while (-1 < *(int *)(DAT_00093be0/*=0xa110c84*/ + uVar1 * 0x400000) << 0x1f);
  }
  FUN_00091a8c(2,DAT_00093be0/*=0xa110c84*/,uVar1,param_4);
  return;
}

//==== 0x93bf4  0x93bf4-0x93db7 inclusive
void FUN_00093bf4(int param_1)

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
  FUN_00092c40(auStack_f8,DAT_00093db8/*=0xa4fa8*/,8);
  FUN_00092c40(auStack_f0,DAT_00093dbc/*=0xa4fb0*/);
  FUN_00092c40(auStack_e8,DAT_00093dc0/*=0xa4fb8*/,8);
  FUN_00092c40(auStack_e0,DAT_00093dc4/*=0xa4fc0*/,8);
  FUN_00092c40(auStack_d8,DAT_00093dc8/*=0xa4fc8*/,8);
  FUN_00092c40(auStack_d0,DAT_00093dcc/*=0xa4fd0*/,8);
  FUN_00092c40(auStack_c8,DAT_00093dd0/*=0xa4fd8*/,8);
  FUN_00092c40(auStack_c0,DAT_00093dd4/*=0xa4fe0*/,8);
  FUN_00092c40(auStack_b8,DAT_00093dd8/*=0xa4fe8*/,8);
  FUN_00092c40(auStack_b0,DAT_00093ddc/*=0xa4ff0*/,8);
  FUN_00092c40(auStack_a8,DAT_00093de0/*=0xa4ff8*/,8);
  FUN_00092c40(auStack_a0,DAT_00093de4/*=0xa5000*/,8);
  FUN_00092c40(auStack_98,DAT_00093de8/*=0xa5008*/,8);
  FUN_00092c40(auStack_90,DAT_00093dec/*=0xa5010*/,8);
  FUN_00092c40(auStack_88,DAT_00093df0/*=0xa5018*/,8);
  FUN_00092c40(auStack_80,DAT_00093df4/*=0xa5020*/,8);
  FUN_00092c40(local_78,DAT_00093df8/*=0xa5028*/,8);
  FUN_00092c40(local_70,DAT_00093dfc/*=0xa5030*/,8);
  FUN_00092c40(local_68,DAT_00093e00/*=0xa5038*/,8);
  FUN_00092c40(local_60,DAT_00093e04/*=0xa5040*/,8);
  FUN_00092c40(auStack_58,DAT_00093e08/*=0xa5048*/,8);
  FUN_00092c40(auStack_50,DAT_00093e0c/*=0xa5050*/,8);
  FUN_00092c40(auStack_48,DAT_00093e10/*=0xa5058*/,8);
  FUN_00092c40(auStack_40,DAT_00093e14/*=0xa5060*/,8);
  FUN_00092c40(auStack_38,DAT_00093e18/*=0xa5068*/,8);
  FUN_00092c40(auStack_30,DAT_00093e1c/*=0xa5070*/,8);
  FUN_00092c40(auStack_28,DAT_00093e20/*=0xa5078*/,8);
  FUN_00092c40(auStack_20,DAT_00093e24/*=0xa5080*/,8);
  puVar2 = DAT_00093e2c/*=0xa920110*/;
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
    goto LAB_00093d3e;
  }
  if ((*(ushort *)(param_1 + 0x66) & 0xf) != 0) {
    if (uVar9 == 1) {
      puVar10 = auStack_c0;
      puVar7 = auStack_c8;
      puVar5 = auStack_d0;
      puVar3 = auStack_d8;
      goto LAB_00093d3e;
    }
    if (uVar9 == 2) {
      puVar10 = auStack_a0;
      puVar7 = auStack_a8;
      puVar5 = auStack_b0;
      puVar3 = auStack_b8;
      goto LAB_00093d3e;
    }
    if (uVar9 == 3) {
      puVar10 = auStack_80;
      puVar7 = auStack_88;
      puVar5 = auStack_90;
      puVar3 = auStack_98;
      goto LAB_00093d3e;
    }
    if (uVar9 == 4) {
      puVar10 = local_60;
      puVar7 = local_68;
      puVar5 = local_70;
      puVar3 = local_78;
      goto LAB_00093d3e;
    }
  }
  puVar10 = auStack_e0;
  puVar7 = auStack_e8;
  puVar5 = auStack_f0;
LAB_00093d3e:
  pbVar4 = puVar3 + -1;
  pbVar6 = puVar5 + -1;
  pbVar8 = puVar7 + -1;
  pbVar11 = puVar10 + -1;
  puVar12 = DAT_00093e28/*=0xa920100*/;
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

//==== 0x93e30  0x93e30-0x93ef9 inclusive
void FUN_00093e30(int param_1)

{
  ushort *puVar1;
  ushort uVar2;
  undefined2 uVar3;
  byte *pbVar4;
  byte bStack_68;
  byte abStack_67 [95];
  
  pbVar4 = &bStack_68;
  FUN_00092c40(&bStack_68,DAT_00093efc/*=0xa5088*/,0xe);
  FUN_00092c40(abStack_67 + 0xf,DAT_00093f00/*=0xa5096*/,0xe);
  FUN_00092c40(abStack_67 + 0x1f,DAT_00093f04/*=0xa50a4*/,0xe);
  FUN_00092c40(abStack_67 + 0x2f,DAT_00093f08/*=0xa50b2*/,0xe);
  FUN_00092c40(abStack_67 + 0x3f,DAT_00093f0c/*=0xa50c0*/,0xe);
  FUN_00092c40(abStack_67 + 0x4f,DAT_00093f10/*=0xa50ce*/,0xe);
  if (*(int *)(param_1 + 4) != 8) {
    uVar3 = 3;
    pbVar4 = abStack_67 + 0x4f;
    goto LAB_00093e96;
  }
  uVar2 = *(ushort *)(param_1 + 0x66) & 0xf;
  if ((*(ushort *)(param_1 + 0x66) & 0xf) != 0) {
    if (uVar2 == 1) {
      uVar3 = 5;
      pbVar4 = abStack_67 + 0xf;
      goto LAB_00093e96;
    }
    if (uVar2 == 2) {
      uVar3 = 0;
      pbVar4 = abStack_67 + 0x1f;
      goto LAB_00093e96;
    }
    if (uVar2 == 3) {
      pbVar4 = abStack_67 + 0x2f;
      uVar3 = 3;
      goto LAB_00093e96;
    }
    if (uVar2 == 4) {
      uVar3 = 0;
      pbVar4 = abStack_67 + 0x3f;
      goto LAB_00093e96;
    }
  }
  uVar3 = 5;
LAB_00093e96:
  *DAT_00093f14/*=0xa960120*/ = uVar3;
  puVar1 = DAT_00093f18/*=0xa960122*/;
  *DAT_00093f18/*=0xa960122*/ = (ushort)pbVar4[1];
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
  *DAT_00093f1c/*=0xa96212c*/ = (ushort)pbVar4[0xd];
  return;
}

//==== 0x976e4  0x976e4-0x976f1 inclusive
void FUN_000976e4(int param_1)

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
    FUN_00092c30(auStack_48,0,0x20);
    local_32 = 0x1b00;
    iVar12 = *(int *)(param_1 + 4);
    *DAT_000a1874/*=0xaaa0000*/ = 0;
    thunk_FUN_00091a8c(1);
    iVar20 = DAT_000a187c/*=0xb31fc*/;
    puVar11 = DAT_000a1878/*=0xa982000*/;
    uVar21 = *(uint *)(param_1 + 0x1c);
    *DAT_000a1878/*=0xa982000*/ = 0;
    puVar11[1] = 0;
    puVar11[2] = 0;
    puVar11[3] = 0;
    puVar11[4] = 0;
    puVar11[5] = 0;
    puVar11[6] = 0;
    puVar11[7] = 0;
    puVar17 = DAT_000a1fac/*=0xa9826d0*/;
    puVar10 = DAT_000a1884/*=0xa982790*/;
    iVar8 = DAT_000a1880/*=0xf567dcf0*/;
    if ((uVar21 & 0x1000) == 0) {
      puVar11 = DAT_000a1fa8/*=0xa982310*/;
      do {
        puVar18 = puVar11 + 1;
        *puVar11 = *(undefined2 *)(((int)puVar11 + iVar8 & 0xfffffffeU) + iVar20 + 0xd1a);
        puVar10 = DAT_000a1fbc/*=0xaa208c6*/;
        iVar7 = DAT_000a1fb8/*=0xf55dffa4*/;
        iVar16 = DAT_000a1fb4/*=0xb42f4*/;
        puVar11 = puVar18;
      } while (puVar18 != puVar17);
      puVar11 = DAT_000a1fb0/*=0xaa2005c*/;
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
        puVar17 = DAT_000a1890/*=0xaa208f6*/;
        iVar16 = DAT_000a188c/*=0xf55dffa4*/;
        puVar11 = puVar18;
      } while (puVar18 != puVar10);
      puVar11 = DAT_000a1888/*=0xaa2005c*/;
      do {
        puVar10 = puVar11 + 1;
        *puVar11 = *(undefined2 *)(((int)puVar11 + iVar16 & 0xfffffffeU) + iVar20 + 0x480);
        puVar11 = puVar10;
      } while (puVar10 != puVar17);
    }
    puVar17 = DAT_000a189c/*=0xaa20e10*/;
    puVar10 = DAT_000a1898/*=0xaa20056*/;
    puVar11 = DAT_000a1894/*=0xaaa01ce*/;
    *DAT_000a1894/*=0xaaa01ce*/ = 0x600;
    puVar11[-0x400cb] = 0;
    puVar11[-0x400c7] = 0x58;
    puVar11[-0x400c3] = 99;
    puVar19 = DAT_000a18a8/*=0xaa20e02*/;
    puVar18 = DAT_000a18a4/*=0xaa20e00*/;
    puVar11 = DAT_000a18a0/*=0xaa2004a*/;
    *DAT_000a18a0/*=0xaa2004a*/ = 0x1e;
    puVar11[1] = 0x1e;
    puVar15 = DAT_000a18ac/*=0xaa20e06*/;
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
    puVar10 = DAT_000a18b4/*=0xa94024a*/;
    puVar11 = DAT_000a18b0/*=0xaa20e08*/;
    *DAT_000a18b0/*=0xaa20e08*/ = 0;
    puVar11[1] = 0;
    puVar11[2] = 0;
    puVar11[3] = 0;
    puVar11[-0x7057a] = 0;
    puVar17 = DAT_000a18b8/*=0xa940248*/;
    *DAT_000a18b8/*=0xa940248*/ = 1;
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
    puVar10 = DAT_000a18c0/*=0xa94024e*/;
    puVar11 = DAT_000a18bc/*=0xa94024c*/;
    *DAT_000a18bc/*=0xa94024c*/ = 1;
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
    puVar10 = DAT_000a18c8/*=0xa940252*/;
    puVar11 = DAT_000a18c4/*=0xa940250*/;
    *DAT_000a18c4/*=0xa940250*/ = 0xf;
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
    puVar10 = DAT_000a18d0/*=0xa940256*/;
    puVar11 = DAT_000a18cc/*=0xa940254*/;
    *DAT_000a18cc/*=0xa940254*/ = 0xf;
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
    puVar10 = DAT_000a18d8/*=0xa94025a*/;
    puVar11 = DAT_000a18d4/*=0xa940258*/;
    *DAT_000a18d4/*=0xa940258*/ = 0x14;
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
    puVar10 = DAT_000a18e0/*=0xa94025e*/;
    puVar11 = DAT_000a18dc/*=0xa94025c*/;
    *DAT_000a18dc/*=0xa94025c*/ = 0x14;
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
    puVar2 = DAT_000a1928/*=0xa94035e*/;
    puVar10 = DAT_000a18e8/*=0xa940330*/;
    puVar11 = DAT_000a18e4/*=0xa940260*/;
    *DAT_000a18e4/*=0xa940260*/ = 0x31;
    puVar11[0x67] = 0x30;
    puVar11[1] = 0x33;
    *puVar10 = 0x32;
    puVar10[-0x66] = 0x31;
    puVar10[1] = 0x30;
    puVar4 = DAT_000a1930/*=0xa940360*/;
    puVar3 = DAT_000a192c/*=0xa940292*/;
    puVar11 = DAT_000a18ec/*=0xa940266*/;
    *DAT_000a18ec/*=0xa940266*/ = 0x33;
    puVar11[0x67] = 0x32;
    puVar11[1] = 0x31;
    puVar11[0x68] = 0x31;
    puVar11[2] = 0x33;
    puVar11[0x69] = 0x33;
    puVar11[3] = 0x31;
    puVar11[0x6a] = 0x31;
    puVar6 = DAT_000a1938/*=0xa940362*/;
    puVar5 = DAT_000a1934/*=0xa940294*/;
    puVar17 = DAT_000a18f0/*=0xa94026e*/;
    *DAT_000a18f0/*=0xa94026e*/ = 0x33;
    puVar17[0x67] = 0x33;
    puVar15 = DAT_000a18fc/*=0xa940298*/;
    puVar19 = DAT_000a18f8/*=0xa940364*/;
    puVar18 = DAT_000a18f4/*=0xa940270*/;
    *DAT_000a18f4/*=0xa940270*/ = 0x32;
    puVar18[0x67] = 0x32;
    puVar17[2] = 0x34;
    puVar17[0x69] = 0x34;
    puVar17[3] = 0x32;
    puVar17[0x6a] = 0x32;
    puVar1 = DAT_000a1904/*=0xa940366*/;
    puVar18 = DAT_000a1900/*=0xa940276*/;
    *DAT_000a1900/*=0xa940276*/ = 0x34;
    puVar18[0x67] = 0x34;
    puVar18 = DAT_000a1908/*=0xa940278*/;
    *DAT_000a1908/*=0xa940278*/ = 0x35;
    puVar18[0x67] = 0x35;
    puVar18[1] = 0x35;
    puVar18[0x68] = 0x35;
    puVar18[2] = 0x35;
    puVar18[0x69] = 0x35;
    puVar18[3] = 0x35;
    puVar18[0x6a] = 0x35;
    puVar18 = DAT_000a190c/*=0xa940280*/;
    *DAT_000a190c/*=0xa940280*/ = 0x36;
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
    *DAT_000a1910/*=0xa940290*/ = 0x37;
    puVar18 = DAT_000a2134/*=0xa940296*/;
    puVar17 = DAT_000a1914/*=0xa940296*/;
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
      *DAT_000a2138/*=0xa9402a0*/ = 0x4b;
      puVar18[0x6c] = 0x51;
      puVar18[6] = 0x4b;
      puVar18[0x6d] = 0x51;
      puVar18[7] = 0x4b;
      puVar18[0x6e] = 0x51;
      puVar18[8] = 0x4b;
      *DAT_000a213c/*=0xa940374*/ = 0x51;
      *DAT_000a2140/*=0xa9402a8*/ = 0x52;
      puVar18[0x70] = 0x56;
      puVar18[10] = 0x52;
      puVar18[0x71] = 0x56;
      puVar18[0xb] = 0x52;
      puVar18[0x72] = 0x56;
      puVar18[0xc] = 0x52;
      *DAT_000a2144/*=0xa94037c*/ = 0x56;
      *DAT_000a2148/*=0xa9402b0*/ = 0x57;
      puVar18[0x74] = 0x5c;
      puVar18[0xe] = 0x57;
      puVar18[0x75] = 0x5c;
      puVar18[0xf] = 0x57;
      puVar18[0x76] = 0x5c;
      puVar18[0x10] = 0x57;
      *DAT_000a214c/*=0xa940384*/ = 0x5c;
      *DAT_000a2150/*=0xa9402b8*/ = 0x5d;
      puVar18[0x78] = 0x62;
      puVar18[0x12] = 0x5d;
      puVar18[0x79] = 0x62;
      puVar18[0x13] = 0x5d;
      puVar18[0x7a] = 0x62;
      puVar18[0x14] = 0x5d;
      *DAT_000a2154/*=0xa94038c*/ = 0x62;
      *DAT_000a2158/*=0xa9402c0*/ = 99;
      puVar18[0x7c] = 0x67;
      puVar18[0x16] = 99;
      puVar18[0x7d] = 0x67;
      puVar18[0x17] = 99;
      puVar18[0x7e] = 0x67;
      puVar18[0x18] = 99;
      *DAT_000a215c/*=0xa940394*/ = 0x67;
      puVar18[0x19] = 0x68;
      puVar18[0x80] = 0x67;
      puVar18[0x1a] = 0x68;
      puVar18[0x81] = 0x67;
      puVar18[0x1b] = 0x68;
      puVar18[0x82] = 0x67;
      puVar18[0x1c] = 0x68;
      puVar18[0x83] = 0x67;
      *DAT_000a2160/*=0xa9402d0*/ = 0x68;
      puVar18[0x84] = 0x6c;
      puVar18[0x1e] = 0x68;
      puVar18[0x85] = 0x6c;
      puVar18[0x1f] = 0x68;
      puVar18[0x86] = 0x6c;
      puVar18[0x20] = 0x68;
      puVar11 = DAT_000a2164/*=0xa9403a4*/;
      *DAT_000a2164/*=0xa9403a4*/ = 0x6c;
      puVar11[0x210f1] = 0x4b00;
      puVar11[0x210f5] = 0;
      puVar18[0x21190] = 0x7b00;
      puVar18[0x21194] = 0;
      puVar18[0x211a8] = 0x4b00;
      puVar11 = DAT_000a2168/*=0xa9825ee*/;
      *DAT_000a2168/*=0xa9825ee*/ = 0;
      puVar11[0x14] = 0x7b00;
      *DAT_000a216c/*=0xa98261e*/ = 0;
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
      *DAT_000a1918/*=0xa94036c*/ = 0x4f;
      *DAT_000a191c/*=0xa9402a0*/ = 0x50;
      puVar17[0x6c] = 0x59;
      puVar17[6] = 0x50;
      puVar17[0x6d] = 0x59;
      puVar17[7] = 0x50;
      puVar17[0x6e] = 0x59;
      puVar17[8] = 0x50;
      *DAT_000a1920/*=0xa940374*/ = 0x59;
      *DAT_000a1924/*=0xa9402a8*/ = 0x5a;
      puVar17[0x70] = 0x62;
      puVar17[10] = 0x5a;
      puVar17[0x71] = 0x62;
      puVar17[0xb] = 0x5a;
      puVar17[0x72] = 0x62;
      puVar17[0xc] = 0x5a;
      *DAT_000a1c14/*=0xa94037c*/ = 0x62;
      *DAT_000a1c18/*=0xa9402b0*/ = 99;
      puVar17[0x74] = 0x68;
      puVar17[0xe] = 99;
      puVar17[0x75] = 0x68;
      puVar17[0xf] = 99;
      puVar17[0x76] = 0x68;
      puVar17[0x10] = 99;
      *DAT_000a1c1c/*=0xa940384*/ = 0x68;
      *DAT_000a1c20/*=0xa9402b8*/ = 0x69;
      puVar17[0x78] = 0x6e;
      puVar17[0x12] = 0x69;
      puVar17[0x79] = 0x6e;
      puVar17[0x13] = 0x69;
      puVar17[0x7a] = 0x6e;
      puVar17[0x14] = 0x69;
      *DAT_000a1c24/*=0xa94038c*/ = 0x6e;
      *DAT_000a1c28/*=0xa9402c0*/ = 0x6f;
      puVar17[0x7c] = 0x73;
      puVar17[0x16] = 0x6f;
      puVar17[0x7d] = 0x73;
      puVar17[0x17] = 0x6f;
      puVar17[0x7e] = 0x73;
      puVar17[0x18] = 0x6f;
      *DAT_000a1c2c/*=0xa940394*/ = 0x73;
      puVar17[0x19] = 0x74;
      puVar17[0x80] = 0x73;
      puVar17[0x1a] = 0x74;
      puVar17[0x81] = 0x73;
      puVar17[0x1b] = 0x74;
      puVar17[0x82] = 0x73;
      puVar17[0x1c] = 0x74;
      puVar17[0x83] = 0x73;
      *DAT_000a1c30/*=0xa9402d0*/ = 0x74;
      puVar17[0x84] = 0x78;
      puVar17[0x1e] = 0x74;
      puVar17[0x85] = 0x78;
      puVar17[0x1f] = 0x74;
      puVar17[0x86] = 0x78;
      puVar17[0x20] = 0x74;
      puVar10 = DAT_000a1c34/*=0xa9403a4*/;
      *DAT_000a1c34/*=0xa9403a4*/ = 0x78;
      puVar17 = DAT_000a1c38/*=0xa98264e*/;
      puVar10[0x21151] = 0x4b00;
      *puVar17 = 0;
      puVar11[0x21208] = 0x7b00;
      puVar11[0x2120c] = 0;
      puVar11[0x21220] = 0x4b00;
      puVar11 = DAT_000a1c3c/*=0xa9826ae*/;
      *DAT_000a1c3c/*=0xa9826ae*/ = 0;
      puVar11[0x14] = 0x7b00;
      *DAT_000a1c40/*=0xa9826de*/ = 0;
    }
    iVar20 = DAT_000a1c4c/*=0xf567dff0*/;
    puVar10 = DAT_000a1c48/*=0xa982030*/;
    puVar11 = DAT_000a1c44/*=0xa982010*/;
    if (iVar12 == 8) {
      puVar17 = DAT_000a1c44/*=0xa982010*/;
      do {
        puVar19 = puVar17 + 1;
        *puVar17 = *(undefined2 *)((int)auStack_48 + ((int)puVar17 + iVar20 & 0xfffffffeU));
        iVar8 = DAT_000a1c54/*=0xf567dfd0*/;
        puVar18 = DAT_000a1c50/*=0xa982012*/;
        puVar17 = puVar19;
      } while (puVar19 != puVar10);
      *DAT_000a1c50/*=0xa982012*/ = 0xd800;
      uVar14 = uVar21 & 0x1000;
      if (uVar14 == 0) {
        *puVar11 = 0x2066;
        uVar9 = 0x1e01;
        puVar11 = DAT_000a1c58/*=0xa982050*/;
      }
      else {
        *puVar11 = 0x20e6;
        uVar9 = 0x1e03;
        puVar11 = DAT_000a1c58/*=0xa982050*/;
      }
      DAT_000a1c58/*=0xa982050*/ = puVar11;
      puVar18[1] = uVar9;
      do {
        puVar18 = puVar19 + 1;
        *puVar19 = *(undefined2 *)((int)auStack_48 + ((int)puVar19 + iVar8 & 0xfffffffeU));
        puVar17 = DAT_000a1c5c/*=0xa982032*/;
        puVar19 = puVar18;
      } while (puVar18 != puVar11);
      *DAT_000a1c5c/*=0xa982032*/ = 0x5800;
      if (uVar14 == 0) {
        *puVar10 = 0x4046;
        uVar9 = 0x1f81;
      }
      else {
        *puVar10 = 0x40c6;
        uVar9 = 0x1f83;
      }
      iVar20 = DAT_000a1c64/*=0xf567dfb0*/;
      puVar10 = DAT_000a1c60/*=0xa982070*/;
      puVar17[1] = uVar9;
      do {
        puVar19 = puVar18 + 1;
        *puVar18 = *(undefined2 *)((int)auStack_48 + ((int)puVar18 + iVar20 & 0xfffffffeU));
        puVar17 = DAT_000a1c68/*=0xa982052*/;
        puVar18 = puVar19;
      } while (puVar19 != puVar10);
      *DAT_000a1c68/*=0xa982052*/ = 0x5800;
      if (uVar14 == 0) {
        *puVar11 = 0x6046;
        uVar9 = 0x1981;
      }
      else {
        *puVar11 = 0x60c6;
        uVar9 = 0x1983;
      }
      puVar17[1] = uVar9;
      iVar20 = DAT_000a1c70/*=0xf567df90*/;
      puVar11 = DAT_000a1c6c/*=0xa982090*/;
      do {
        puVar15 = puVar19 + 1;
        *puVar19 = *(undefined2 *)((int)auStack_48 + ((int)puVar19 + iVar20 & 0xfffffffeU));
        puVar18 = DAT_000a1c78/*=0xa982074*/;
        puVar17 = DAT_000a1c74/*=0xa982072*/;
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
      puVar10 = DAT_000a1c84/*=0xa9820c0*/;
      iVar20 = DAT_000a1c80/*=0xf567df60*/;
      puVar11 = DAT_000a1c7c/*=0xa982092*/;
      *DAT_000a1c7c/*=0xa982092*/ = 0x5802;
      puVar11[1] = 0x1201;
      puVar11 = DAT_000a1c88/*=0xa982096*/;
      *DAT_000a1c88/*=0xa982096*/ = 0;
      puVar11[1] = 0;
      puVar11[2] = 0;
      puVar11[3] = 0;
      puVar11[4] = 0;
      puVar11 = DAT_000a1c8c/*=0xa9820a0*/;
      puVar17 = DAT_000a1c8c/*=0xa9820a0*/;
      do {
        puVar15 = puVar17 + 1;
        *puVar17 = *(undefined2 *)((int)auStack_48 + ((int)puVar17 + iVar20 & 0xfffffffeU));
        puVar19 = DAT_000a1c94/*=0xa9820a4*/;
        puVar18 = DAT_000a1c90/*=0xa9820a2*/;
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
      puVar11 = DAT_000a1c98/*=0xa9820f0*/;
      do {
        puVar10 = puVar15 + 1;
        *puVar15 = 0;
        puVar15 = puVar10;
      } while (puVar10 != puVar11);
    }
    puVar10 = DAT_000a1ca0/*=0xaa21248*/;
    puVar11 = DAT_000a1c9c/*=0xaa80002*/;
    *DAT_000a1c9c/*=0xaa80002*/ = 0x5061;
    puVar11[1] = 0x7098;
    puVar11 = DAT_000a1ca4/*=0xaa80006*/;
    *DAT_000a1ca4/*=0xaa80006*/ = 0;
    puVar11[-3] = 0xbedc;
    puVar11[3] = 0xb0db;
    puVar11[4] = 0;
    puVar11[-0x2f8f7] = 0;
    puVar11 = DAT_000a1ca8/*=0xaa20e1a*/;
    *DAT_000a1ca8/*=0xaa20e1a*/ = 0x7ff;
    puVar11[1] = 0x668;
    puVar11[2] = 0x7910;
    puVar11[3] = 0x355e;
    puVar11[4] = 0xcbb5;
    puVar11 = DAT_000a1cb0/*=0xaa20e28*/;
    if ((uVar13 & 4) == 0) {
      *DAT_000a1cac/*=0xaa20e26*/ = 0xffff;
      uVar9 = 0x710;
    }
    else {
      *DAT_000a1cac/*=0xaa20e26*/ = 0x710;
      uVar9 = 0xffff;
    }
    *puVar11 = uVar9;
    *DAT_000a1cb4/*=0xaa20e2a*/ = 0x7800;
    puVar11 = DAT_000a1cb8/*=0xaa21820*/;
    *DAT_000a1cb8/*=0xaa21820*/ = 0xffff;
    puVar11[2] = 0xff10;
    puVar11[-0x4fe] = 0x2ee8;
    puVar11[1] = 0xffff;
    puVar11 = DAT_000a1cc0/*=0xaa20e30*/;
    *DAT_000a1cbc/*=0xaa20e2c*/ = 0xffdf;
    puVar17 = DAT_000a1cc4/*=0xaa20e2e*/;
    *DAT_000a1cc4/*=0xaa20e2e*/ = 0x6f10;
    *puVar11 = 0x6f10;
    puVar17[2] = 0x2868;
    puVar17[3] = 0x2868;
    *DAT_000a1f6c/*=0xaa20e36*/ = 0xfeef;
    puVar17 = DAT_000a1f70/*=0xaa21208*/;
    *DAT_000a1f70/*=0xaa21208*/ = 0xe400;
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
    puVar17 = DAT_000a1f78/*=0xa920144*/;
    puVar10 = DAT_000a1f74/*=0xaa21214*/;
    *DAT_000a1f74/*=0xaa21214*/ = 0;
    puVar10[2] = 0;
    if ((uVar21 & 0x1000) == 0) {
      *DAT_000a1f7c/*=0xaa2121a*/ = 0;
    }
    else {
      *DAT_000a1f7c/*=0xaa2121a*/ = 1;
    }
    *puVar11 = 0xffff;
    *DAT_000a1f80/*=0xa9401e0*/ = 0x27f7;
    puVar11 = DAT_000a1f84/*=0xa9401e2*/;
    *DAT_000a1f84/*=0xa9401e2*/ = 0x2108;
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
    puVar11 = DAT_000a1f88/*=0xa926174*/;
    *DAT_000a1f88/*=0xa926174*/ = 1;
    puVar11[-0x18] = 0;
    puVar10 = DAT_000a1f8c/*=0xa92616a*/;
    *DAT_000a1f8c/*=0xa92616a*/ = 1;
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
    puVar10 = DAT_000a1f90/*=0xa9e00ca*/;
    *DAT_000a1f90/*=0xa9e00ca*/ = 0x1ff;
    if ((uVar21 & 0x1000) == 0) {
      uVar9 = 0x44;
    }
    else {
      uVar9 = 0xcc;
    }
    puVar11[0xcfc0] = uVar9;
    puVar10[-0x4ffe7] = uVar9;
    puVar10 = DAT_000a1f98/*=0xaaa0006*/;
    puVar11 = DAT_000a1f94/*=0xa940050*/;
    *DAT_000a1f94/*=0xa940050*/ = 2;
    puVar11[199] = 0xffff;
    puVar17 = DAT_000a1f9c/*=0xa940620*/;
    puVar11[0x708e8] = 2;
    *puVar17 = 1;
    puVar17[1] = 1;
    puVar11 = DAT_000a1fa0/*=0xaa80100*/;
    *DAT_000a1fa0/*=0xaa80100*/ = 2;
    *puVar10 = 0;
    *puVar11 = 0;
    *DAT_000a1fa4/*=0xaaa0000*/ = 1;
    return;
  }
  FUN_00092c30(auStack_48,0,0x20);
  local_32 = 0x2b00;
  iVar16 = *(int *)(param_1 + 4);
  *DAT_000a2984/*=0xaaa0000*/ = 0;
  thunk_FUN_00091a8c(1);
  iVar20 = DAT_000a298c/*=0xf567d8f0*/;
  puVar11 = DAT_000a2988/*=0xa982000*/;
  uVar21 = *(uint *)(param_1 + 0x1c);
  *DAT_000a2988/*=0xa982000*/ = 0;
  puVar11[1] = 0;
  puVar11[2] = 0;
  puVar11[3] = 0;
  puVar11[4] = 0;
  puVar11[5] = 0;
  puVar11[6] = 0;
  puVar11[7] = 0;
  puVar17 = DAT_000a33dc/*=0xa983580*/;
  iVar12 = DAT_000a33d8/*=0xc4b16*/;
  puVar10 = DAT_000a2994/*=0xa9838b0*/;
  iVar8 = DAT_000a2990/*=0xc6d7e*/;
  if ((uVar21 & 0x1000) == 0) {
    puVar11 = DAT_000a33d4/*=0xa982710*/;
    do {
      puVar18 = puVar11 + 1;
      *puVar11 = *(undefined2 *)(((int)puVar11 + iVar20 & 0xfffffffeU) + iVar12 + 0xa14);
      puVar10 = DAT_000a33ec/*=0xaa20a40*/;
      iVar7 = DAT_000a33e8/*=0xf55dffa4*/;
      iVar8 = DAT_000a33e4/*=0xc5c0e*/;
      puVar11 = puVar18;
    } while (puVar18 != puVar17);
    puVar11 = DAT_000a33e0/*=0xaa2005c*/;
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
      puVar17 = DAT_000a29a4/*=0xaa20a70*/;
      iVar7 = DAT_000a29a0/*=0xf55dffa4*/;
      iVar12 = DAT_000a299c/*=0xc4b16*/;
      puVar11 = puVar18;
    } while (puVar18 != puVar10);
    puVar11 = DAT_000a2998/*=0xaa2005c*/;
    do {
      puVar10 = puVar11 + 1;
      *puVar11 = *(undefined2 *)(iVar12 + ((int)puVar11 + iVar7 >> 1) * 2);
      puVar11 = puVar10;
    } while (puVar10 != puVar17);
  }
  puVar17 = DAT_000a29b0/*=0xaa20e10*/;
  puVar10 = DAT_000a29ac/*=0xaa20056*/;
  puVar11 = DAT_000a29a8/*=0xaaa01ce*/;
  *DAT_000a29a8/*=0xaaa01ce*/ = 0x600;
  puVar11[-0x400cb] = 0;
  puVar11[-0x400c7] = 0x77;
  puVar11[-0x400c3] = 0x82;
  puVar19 = DAT_000a29bc/*=0xaa20e02*/;
  puVar18 = DAT_000a29b8/*=0xaa20e00*/;
  puVar11 = DAT_000a29b4/*=0xaa2004a*/;
  *DAT_000a29b4/*=0xaa2004a*/ = 0x2b;
  puVar11[1] = 0x2b;
  puVar15 = DAT_000a29c0/*=0xaa20e06*/;
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
  puVar10 = DAT_000a29c8/*=0xa94024a*/;
  puVar11 = DAT_000a29c4/*=0xaa20e08*/;
  *DAT_000a29c4/*=0xaa20e08*/ = 0;
  puVar11[1] = 0;
  puVar11[2] = 0;
  puVar11[3] = 0;
  puVar11[-0x7057a] = 0;
  puVar17 = DAT_000a29cc/*=0xa940248*/;
  *DAT_000a29cc/*=0xa940248*/ = 1;
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
  puVar10 = DAT_000a29d4/*=0xa94024e*/;
  puVar11 = DAT_000a29d0/*=0xa94024c*/;
  *DAT_000a29d0/*=0xa94024c*/ = 1;
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
  puVar10 = DAT_000a29dc/*=0xa940252*/;
  puVar11 = DAT_000a29d8/*=0xa940250*/;
  *DAT_000a29d8/*=0xa940250*/ = 0x17;
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
  puVar10 = DAT_000a29e4/*=0xa940256*/;
  puVar11 = DAT_000a29e0/*=0xa940254*/;
  *DAT_000a29e0/*=0xa940254*/ = 0x17;
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
  puVar10 = DAT_000a29ec/*=0xa94025a*/;
  puVar11 = DAT_000a29e8/*=0xa940258*/;
  *DAT_000a29e8/*=0xa940258*/ = 0x28;
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
  puVar10 = DAT_000a29f4/*=0xa94025e*/;
  puVar11 = DAT_000a29f0/*=0xa94025c*/;
  *DAT_000a29f0/*=0xa94025c*/ = 0x28;
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
  puVar10 = DAT_000a29fc/*=0xa940338*/;
  puVar11 = DAT_000a29f8/*=0xa940260*/;
  *DAT_000a29f8/*=0xa940260*/ = 0x80;
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
  puVar2 = DAT_000a2a4c/*=0xa940364*/;
  puVar1 = DAT_000a2a48/*=0xa940362*/;
  *DAT_000a2a00/*=0xa94033a*/ = 0x74;
  puVar3 = DAT_000a2a50/*=0xa940298*/;
  puVar11 = DAT_000a2a08/*=0xa94029a*/;
  *DAT_000a2a04/*=0xa94026e*/ = 0x77;
  puVar17 = DAT_000a2a10/*=0xa940368*/;
  *DAT_000a2a0c/*=0xa94033c*/ = 0x7a;
  puVar18 = DAT_000a2a14/*=0xa940270*/;
  *DAT_000a2a14/*=0xa940270*/ = 0x75;
  puVar18[0x67] = 0x76;
  puVar18[1] = 0x7b;
  puVar10[4] = 0x7c;
  puVar10[-0x62] = 0x75;
  puVar18 = DAT_000a2a18/*=0xa940342*/;
  *DAT_000a2a18/*=0xa940342*/ = 0x76;
  puVar19 = DAT_000a2a1c/*=0xa940276*/;
  *DAT_000a2a1c/*=0xa940276*/ = 0x7b;
  *DAT_000a2a20/*=0xa940344*/ = 0x7c;
  *DAT_000a2a24/*=0xa940278*/ = 0x7d;
  puVar19[0x68] = 0x7e;
  puVar19[2] = 0x7d;
  puVar19[0x69] = 0x7e;
  puVar19[3] = 0x7d;
  puVar19[0x6a] = 0x7e;
  puVar19[4] = 0x7d;
  puVar19 = DAT_000a2a28/*=0xa94034c*/;
  *DAT_000a2a28/*=0xa94034c*/ = 0x7e;
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
  puVar19 = DAT_000a2a2c/*=0xa94035c*/;
  *DAT_000a2a2c/*=0xa94035c*/ = 0x7f;
  puVar19[-0x66] = 0x81;
  puVar19[1] = 0x93;
  puVar19[-0x65] = 0x81;
  *DAT_000a2a30/*=0xa940360*/ = 0x93;
  puVar4 = DAT_000a36bc/*=0xa940296*/;
  puVar15 = DAT_000a2a34/*=0xa940296*/;
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
    puVar11 = DAT_000a36c4/*=0xa98317e*/;
    *DAT_000a36c0/*=0xa9402a0*/ = 0x94;
    puVar4[0x6c] = 0x9e;
    puVar4[6] = 0x94;
    puVar4[0x6d] = 0x9e;
    *DAT_000a36c8/*=0xa9402a4*/ = 0x101;
    puVar4[0x6e] = 0x109;
    puVar4[8] = 0x101;
    puVar10 = DAT_000a36cc/*=0xa940374*/;
    *DAT_000a36cc/*=0xa940374*/ = 0x109;
    puVar10[-0x66] = 0x9f;
    puVar4[0x70] = 0xa5;
    puVar4[10] = 0x9f;
    *DAT_000a36d0/*=0xa940378*/ = 0xa5;
    *DAT_000a36d4/*=0xa9402ac*/ = 0x10a;
    puVar4[0x72] = 0x110;
    puVar4[0xc] = 0x10a;
    *DAT_000a36d8/*=0xa94037c*/ = 0x110;
    *DAT_000a36dc/*=0xa9402b0*/ = 0xa6;
    puVar4[0x74] = 0xaf;
    puVar4[0xe] = 0xa6;
    *DAT_000a36e0/*=0xa940380*/ = 0xaf;
    *DAT_000a36e4/*=0xa9402b4*/ = 0x111;
    puVar4[0x76] = 0x11a;
    puVar4[0x10] = 0x111;
    *DAT_000a36e8/*=0xa940384*/ = 0x11a;
    *DAT_000a36ec/*=0xa9402b8*/ = 0xb0;
    puVar4[0x78] = 0xb9;
    puVar4[0x12] = 0xb0;
    *DAT_000a36f0/*=0xa940388*/ = 0xb9;
    *DAT_000a36f4/*=0xa9402bc*/ = 0x11b;
    puVar4[0x7a] = 0x124;
    puVar4[0x14] = 0x11b;
    *DAT_000a36f8/*=0xa94038c*/ = 0x124;
    *DAT_000a36fc/*=0xa9402c0*/ = 0xba;
    puVar4[0x7c] = 0xc4;
    puVar4[0x16] = 0xba;
    *DAT_000a3700/*=0xa940390*/ = 0xc4;
    *DAT_000a3704/*=0xa9402c4*/ = 0x125;
    puVar4[0x7e] = 0x12e;
    puVar4[0x18] = 0x125;
    *DAT_000a3708/*=0xa940394*/ = 0x12e;
    *DAT_000a370c/*=0xa9402c8*/ = 0xc5;
    puVar4[0x80] = 0xd3;
    puVar4[0x1a] = 0xc5;
    *DAT_000a3710/*=0xa940398*/ = 0xd3;
    *DAT_000a3714/*=0xa9402cc*/ = 0x12f;
    puVar4[0x82] = 0x13d;
    puVar4[0x1c] = 0x12f;
    *DAT_000a3718/*=0xa94039c*/ = 0x13d;
    *DAT_000a371c/*=0xa9402d0*/ = 0xd4;
    puVar4[0x84] = 0xde;
    puVar4[0x1e] = 0xd4;
    *DAT_000a3720/*=0xa9403a0*/ = 0xde;
    *DAT_000a3724/*=0xa9402d4*/ = 0x13e;
    puVar4[0x86] = 0x147;
    puVar4[0x20] = 0x13e;
    *DAT_000a3728/*=0xa9403a4*/ = 0x147;
    *DAT_000a372c/*=0xa9402d8*/ = 0xdf;
    puVar4[0x88] = 0xed;
    puVar4[0x22] = 0xdf;
    *DAT_000a3730/*=0xa9403a8*/ = 0xed;
    *DAT_000a3734/*=0xa9402dc*/ = 0x148;
    puVar4[0x8a] = 0x156;
    puVar4[0x24] = 0x148;
    *DAT_000a3738/*=0xa9403ac*/ = 0x156;
    puVar10 = DAT_000a373c/*=0xa9402e0*/;
    *DAT_000a373c/*=0xa9402e0*/ = 0xee;
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
    puVar10 = DAT_000a3740/*=0xa982e8e*/;
    *DAT_000a3740/*=0xa982e8e*/ = 0;
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
    *DAT_000a3744/*=0xa9834ce*/ = 0;
    puVar11 = DAT_000a3748/*=0xa983516*/;
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
    *DAT_000a2a38/*=0xa94036c*/ = 0x122;
    *DAT_000a2a3c/*=0xa9402a0*/ = 0x9c;
    puVar15[0x6c] = 0xaf;
    puVar15[6] = 0x9c;
    *DAT_000a2a40/*=0xa940370*/ = 0xaf;
    *DAT_000a2a44/*=0xa9402a4*/ = 0x123;
    puVar15[0x6e] = 0x132;
    puVar15[8] = 0x123;
    *DAT_000a2d3c/*=0xa940374*/ = 0x132;
    *DAT_000a2d40/*=0xa9402a8*/ = 0xb0;
    puVar15[0x70] = 0xc0;
    puVar15[10] = 0xb0;
    *DAT_000a2d44/*=0xa940378*/ = 0xc0;
    *DAT_000a2d48/*=0xa9402ac*/ = 0x133;
    puVar15[0x72] = 0x143;
    puVar15[0xc] = 0x133;
    *DAT_000a2d4c/*=0xa94037c*/ = 0x143;
    *DAT_000a2d50/*=0xa9402b0*/ = 0xc1;
    puVar15[0x74] = 0xca;
    puVar15[0xe] = 0xc1;
    *DAT_000a2d54/*=0xa940380*/ = 0xca;
    *DAT_000a2d58/*=0xa9402b4*/ = 0x144;
    puVar15[0x76] = 0x14d;
    puVar15[0x10] = 0x144;
    *DAT_000a2d5c/*=0xa940384*/ = 0x14d;
    *DAT_000a2d60/*=0xa9402b8*/ = 0xcb;
    puVar15[0x78] = 0xd4;
    puVar15[0x12] = 0xcb;
    *DAT_000a2d64/*=0xa940388*/ = 0xd4;
    *DAT_000a2d68/*=0xa9402bc*/ = 0x14e;
    puVar15[0x7a] = 0x157;
    puVar15[0x14] = 0x14e;
    *DAT_000a2d6c/*=0xa94038c*/ = 0x157;
    *DAT_000a2d70/*=0xa9402c0*/ = 0xd5;
    puVar15[0x7c] = 0xdf;
    puVar15[0x16] = 0xd5;
    *DAT_000a2d74/*=0xa940390*/ = 0xdf;
    *DAT_000a2d78/*=0xa9402c4*/ = 0x158;
    puVar15[0x7e] = 0x161;
    puVar15[0x18] = 0x158;
    *DAT_000a2d7c/*=0xa940394*/ = 0x161;
    *DAT_000a2d80/*=0xa9402c8*/ = 0xe0;
    puVar15[0x80] = 0xee;
    puVar15[0x1a] = 0xe0;
    *DAT_000a2d84/*=0xa940398*/ = 0xee;
    *DAT_000a2d88/*=0xa9402cc*/ = 0x162;
    puVar15[0x82] = 0x170;
    puVar15[0x1c] = 0x162;
    *DAT_000a2d8c/*=0xa94039c*/ = 0x170;
    *DAT_000a2d90/*=0xa9402d0*/ = 0xef;
    puVar15[0x84] = 0xf9;
    puVar15[0x1e] = 0xef;
    *DAT_000a2d94/*=0xa9403a0*/ = 0xf9;
    *DAT_000a2d98/*=0xa9402d4*/ = 0x171;
    puVar15[0x86] = 0x17a;
    puVar15[0x20] = 0x171;
    *DAT_000a2d9c/*=0xa9403a4*/ = 0x17a;
    *DAT_000a2da0/*=0xa9402d8*/ = 0xfa;
    puVar15[0x88] = 0x108;
    puVar15[0x22] = 0xfa;
    *DAT_000a2da4/*=0xa9403a8*/ = 0x108;
    *DAT_000a2da8/*=0xa9402dc*/ = 0x17b;
    puVar15[0x8a] = 0x189;
    puVar15[0x24] = 0x17b;
    *DAT_000a2dac/*=0xa9403ac*/ = 0x189;
    puVar11 = DAT_000a2db0/*=0xa9402e0*/;
    *DAT_000a2db0/*=0xa9402e0*/ = 0x109;
    puVar11[0x67] = 0x109;
    puVar11[1] = 0x109;
    puVar11[0x68] = 0x109;
    puVar11[2] = 0x18a;
    puVar11[0x69] = 0x18a;
    puVar11[3] = 0x18a;
    puVar11[0x6a] = 0x18a;
    *DAT_000a2db4/*=0xa982c26*/ = 0xb00;
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
    puVar11 = DAT_000a2db8/*=0xa98303e*/;
    *DAT_000a2db8/*=0xa98303e*/ = 0;
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
    *DAT_000a2dbc/*=0xa9837fe*/ = 0;
    puVar11 = DAT_000a2dc0/*=0xa983846*/;
  }
  *puVar11 = 0x7b00;
  puVar11[4] = 0x400;
  iVar20 = DAT_000a2dcc/*=0xf567dff0*/;
  puVar10 = DAT_000a2dc8/*=0xa982030*/;
  puVar11 = DAT_000a2dc4/*=0xa982010*/;
  if (iVar16 != 9) goto LAB_000a2fb8;
  puVar17 = DAT_000a2dc4/*=0xa982010*/;
  do {
    puVar19 = puVar17 + 1;
    *puVar17 = *(undefined2 *)((int)auStack_48 + ((int)puVar17 + iVar20 & 0xfffffffeU));
    puVar18 = DAT_000a2dd0/*=0xa982018*/;
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
  iVar20 = DAT_000a2dd8/*=0xf567dfd0*/;
  puVar11 = DAT_000a2dd4/*=0xa982050*/;
  *puVar18 = uVar9;
  do {
    puVar18 = puVar19 + 1;
    *puVar19 = *(undefined2 *)((int)auStack_48 + ((int)puVar19 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_000a2ddc/*=0xa982038*/;
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
  iVar20 = DAT_000a2de8/*=0xf567dfb0*/;
  puVar10 = DAT_000a2de4/*=0xa982070*/;
  *DAT_000a2de0/*=0xa982046*/ = 0x2b00;
  do {
    puVar19 = puVar18 + 1;
    *puVar18 = *(undefined2 *)((int)auStack_48 + ((int)puVar18 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_000a2dec/*=0xa982058*/;
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
  iVar20 = DAT_000a2df8/*=0xf567df90*/;
  puVar11 = DAT_000a2df4/*=0xa982090*/;
  *DAT_000a2df0/*=0xa982066*/ = 0x2b00;
  do {
    puVar18 = puVar19 + 1;
    *puVar19 = *(undefined2 *)((int)auStack_48 + ((int)puVar19 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_000a2dfc/*=0xa982078*/;
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
  iVar20 = DAT_000a2e08/*=0xf567df70*/;
  puVar10 = DAT_000a2e04/*=0xa9820b0*/;
  *DAT_000a2e00/*=0xa982086*/ = 0x2b00;
  do {
    puVar19 = puVar18 + 1;
    *puVar18 = *(undefined2 *)((int)auStack_48 + ((int)puVar18 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_000a30e4/*=0xa982098*/;
    puVar18 = puVar19;
  } while (puVar19 != puVar10);
  iVar20 = *DAT_000a2e0c/*=0xc9484*/;
  if (uVar14 == 0) {
    *puVar11 = 0x41d8;
    *puVar17 = 0x4308;
    if (iVar20 != 0) {
      uVar9 = 0x4b08;
      goto LAB_000a2e2a;
    }
  }
  else {
    *puVar11 = 0xc1d8;
    *puVar17 = 0xc308;
    if (iVar20 != 0) {
      uVar9 = 0xcb08;
LAB_000a2e2a:
      *puVar17 = uVar9;
    }
  }
  iVar20 = DAT_000a30f0/*=0xf567df50*/;
  puVar11 = DAT_000a30ec/*=0xa9820d0*/;
  *DAT_000a30e8/*=0xa9820a6*/ = 0x2b00;
  do {
    puVar18 = puVar19 + 1;
    *puVar19 = *(undefined2 *)((int)auStack_48 + ((int)puVar19 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_000a30f4/*=0xa9820b8*/;
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
  iVar20 = DAT_000a30fc/*=0xf567df30*/;
  *DAT_000a30f8/*=0xa9820c6*/ = 0x2b00;
  puVar10 = DAT_000a3100/*=0xa9820f0*/;
  do {
    puVar19 = puVar18 + 1;
    *puVar18 = *(undefined2 *)((int)auStack_48 + ((int)puVar18 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_000a3104/*=0xa9820d8*/;
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
  puVar11 = DAT_000a310c/*=0xa982120*/;
  iVar8 = *(int *)(param_1 + 0x6c);
  *DAT_000a3108/*=0xa9820e6*/ = 0x2b00;
  puVar17 = DAT_000a3110/*=0xa9820f2*/;
  *puVar10 = 0x48d8;
  iVar20 = DAT_000a3114/*=0xf567df00*/;
  *puVar17 = 0;
  puVar17[1] = 0;
  puVar17[2] = 0;
  if (iVar8 < 0) {
    uVar9 = 0x4348;
  }
  else {
    uVar9 = 0x4308;
  }
  *DAT_000a3118/*=0xa9820f8*/ = uVar9;
  puVar10 = DAT_000a311c/*=0xa9820fa*/;
  *DAT_000a311c/*=0xa9820fa*/ = 0;
  puVar10[1] = 0;
  puVar10[2] = 0;
  puVar10 = DAT_000a3120/*=0xa982100*/;
  puVar17 = DAT_000a3120/*=0xa982100*/;
  do {
    puVar19 = puVar17 + 1;
    *puVar17 = *(undefined2 *)((int)auStack_48 + ((int)puVar17 + iVar20 & 0xfffffffeU));
    puVar18 = DAT_000a3124/*=0xa982108*/;
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
  iVar20 = DAT_000a312c/*=0xf567dee0*/;
  *DAT_000a3128/*=0xa982116*/ = 0x2b00;
  puVar10 = DAT_000a3130/*=0xa982140*/;
  do {
    puVar18 = puVar19 + 1;
    *puVar19 = *(undefined2 *)((int)auStack_48 + ((int)puVar19 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_000a3134/*=0xa982128*/;
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
  iVar20 = DAT_000a3140/*=0xf567dec0*/;
  puVar11 = DAT_000a313c/*=0xa982160*/;
  *DAT_000a3138/*=0xa982136*/ = 0x2b00;
  do {
    puVar19 = puVar18 + 1;
    *puVar18 = *(undefined2 *)((int)auStack_48 + ((int)puVar18 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_000a3144/*=0xa982148*/;
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
  iVar20 = DAT_000a314c/*=0xf567dea0*/;
  *DAT_000a3148/*=0xa982156*/ = 0x2b00;
  puVar10 = DAT_000a3150/*=0xa982170*/;
  do {
    puVar18 = puVar19 + 1;
    *puVar19 = *(undefined2 *)((int)auStack_48 + ((int)puVar19 + iVar20 & 0xfffffffeU));
    puVar17 = DAT_000a3154/*=0xa982168*/;
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
LAB_000a2fb8:
  puVar10 = DAT_000a315c/*=0xa920144*/;
  puVar11 = DAT_000a3158/*=0xaa80002*/;
  *DAT_000a3158/*=0xaa80002*/ = 0x5061;
  puVar11[1] = 0x7098;
  puVar11 = DAT_000a3160/*=0xaa80006*/;
  *DAT_000a3160/*=0xaa80006*/ = 0;
  puVar11[-3] = 0xbedc;
  puVar11[3] = 0xb0db;
  puVar11[4] = 0;
  puVar11[-0x2f8f7] = 0;
  puVar11 = DAT_000a3164/*=0xaa20e1a*/;
  *DAT_000a3164/*=0xaa20e1a*/ = 0x7ff;
  puVar11[1] = 0x668;
  puVar11[2] = 0x7910;
  puVar11[3] = 0x355e;
  puVar11[4] = 0xcbb5;
  puVar11 = DAT_000a316c/*=0xaa20e28*/;
  if ((uVar13 & 4) == 0) {
    *DAT_000a3168/*=0xaa20e26*/ = 0xffff;
    uVar9 = 0x710;
  }
  else {
    *DAT_000a3168/*=0xaa20e26*/ = 0x710;
    uVar9 = 0xffff;
  }
  *puVar11 = uVar9;
  *DAT_000a3170/*=0xaa20e2a*/ = 0x7800;
  puVar11 = DAT_000a3174/*=0xaa21820*/;
  *DAT_000a3174/*=0xaa21820*/ = 0xffff;
  puVar11[2] = 0xff10;
  puVar11[-0x4fe] = 0x2ee8;
  puVar11[1] = 0xffff;
  puVar11 = DAT_000a317c/*=0xaa21248*/;
  *DAT_000a3178/*=0xaa20e2c*/ = 0xffdf;
  puVar17 = DAT_000a3180/*=0xaa20e2e*/;
  *DAT_000a3180/*=0xaa20e2e*/ = 0x6f10;
  puVar17[1] = 0x6f10;
  puVar17[2] = 0x2868;
  puVar17[3] = 0x2868;
  *DAT_000a3184/*=0xaa20e36*/ = 0xfeef;
  puVar17 = DAT_000a3188/*=0xaa21208*/;
  *DAT_000a3188/*=0xaa21208*/ = 0xe400;
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
  puVar11 = DAT_000a318c/*=0xaa21214*/;
  *DAT_000a318c/*=0xaa21214*/ = 0;
  puVar11[2] = 0;
  if ((uVar21 & 0x1000) == 0) {
    *DAT_000a3190/*=0xaa2121a*/ = 0;
  }
  else {
    *DAT_000a3190/*=0xaa2121a*/ = 1;
  }
  *DAT_000a3194/*=0xa9401e0*/ = 0x27f7;
  puVar11 = DAT_000a3198/*=0xa9401e2*/;
  *DAT_000a3198/*=0xa9401e2*/ = 0x2108;
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
  puVar11 = DAT_000a33b8/*=0xa926174*/;
  *DAT_000a33b8/*=0xa926174*/ = 1;
  puVar11[-0x18] = 0;
  puVar11 = DAT_000a33bc/*=0xa92616a*/;
  *DAT_000a33bc/*=0xa92616a*/ = 1;
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
  puVar11 = DAT_000a33c0/*=0xa9e00ca*/;
  *DAT_000a33c0/*=0xa9e00ca*/ = 0x1ff;
  if ((uVar21 & 0x1000) == 0) {
    uVar9 = 0x11;
  }
  else {
    uVar9 = 0x33;
  }
  puVar11[-0x4ffe7] = uVar9;
  puVar10 = DAT_000a33c8/*=0xa940620*/;
  puVar11 = DAT_000a33c4/*=0xa9401de*/;
  *DAT_000a33c4/*=0xa9401de*/ = 0xffff;
  puVar11[0x70821] = 2;
  *puVar10 = 1;
  puVar10[1] = 1;
  *DAT_000a33cc/*=0xaa80100*/ = 2;
  puVar11 = DAT_000a33d0/*=0xaaa0006*/;
  *DAT_000a33d0/*=0xaaa0006*/ = 0;
  puVar11[-3] = 1;
  return;
}

//==== 0x976f4  0x976f4-0x97749 inclusive
undefined4 FUN_000976f4(void)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 *puVar4;
  ushort *puVar5;
  undefined2 *puVar6;
  ushort *puVar7;
  
  puVar5 = DAT_00097754/*=0xaaa0062*/;
  puVar4 = DAT_0009774c/*=0xaaa0132*/;
  *DAT_00097750/*=0xaaa0000*/ = 1;
  *puVar4 = 9;
  *puVar4 = 1;
  *puVar4 = 0;
  puVar6 = DAT_00097758/*=0xaaa0066*/;
  *puVar5 = 1;
  *puVar6 = 1;
  puVar7 = DAT_0009775c/*=0xaaa0008*/;
  do {
    uVar1 = *DAT_0009775c/*=0xaaa0008*/;
  } while ((uVar1 & 1) != 0);
  uVar2 = *DAT_00097760/*=0xaaa0064*/;
  uVar3 = DAT_00097760/*=0xaaa0064*/[2];
  FUN_00092a38(DAT_00097764/*"Training result is = %x\n"*/,CONCAT22(uVar3,uVar2));
  *puVar5 = uVar1 & 1;
  do {
  } while (*puVar7 == 0);
  *puVar5 = 1;
  *puVar4 = 1;
  return CONCAT22(uVar3,uVar2);
}

//==== 0x97768  0x97768-0x97775 inclusive
void FUN_00097768(uint param_1,uint *param_2)

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
      uVar16 = FUN_000a3750((*param_2 & 0x7fff) << 3,
                            (param_2[0x18] >> ((param_1 & 0x1f) << 3) & 0x1f) + 1);
      uVar32 = (uint)uVar16;
    }
    uVar22 = (undefined2)uVar32;
    if (uVar32 < 0x640) {
      uVar22 = 0x640;
    }
    *DAT_000a2270/*=0xaaa0000*/ = 0;
    thunk_FUN_00091a8c(1);
    puVar25 = DAT_000a2274/*=0xa9b0000*/;
    *DAT_000a2274/*=0xa9b0000*/ = 0;
    puVar25[1] = 0;
    uVar34 = param_2[0x1e];
    uVar32 = uVar34 & 4;
    if (uVar32 == 0) {
      uVar23 = 0x30;
LAB_000a21c6:
      *DAT_000a2278/*=0xa9b0004*/ = uVar23;
    }
    else {
      if (param_1 == 0) {
        uVar23 = 0xa0;
        goto LAB_000a21c6;
      }
      if (param_1 == 1) {
        uVar23 = 0x91;
        goto LAB_000a21c6;
      }
      if (param_1 == 2) {
        uVar23 = 0x82;
        goto LAB_000a21c6;
      }
      if (param_1 == 3) {
        uVar23 = 0x83;
        goto LAB_000a21c6;
      }
    }
    puVar25 = DAT_000a2280/*=0xa9b0008*/;
    *DAT_000a227c/*=0xa9b0006*/ = uVar22;
    *puVar25 = 4;
    puVar25[1] = 4;
    puVar25[2] = 0;
    puVar25[3] = 0;
    uVar19 = param_2[0x1b];
    uVar26 = uVar19 & 0x1fffffff;
    if (uVar26 >> 0x10 == 0) {
      *DAT_000a2284/*=0xa9b0010*/ = 799;
      param_2[0x1b] = uVar19 | 0x31f0000;
    }
    else {
      *DAT_000a2284/*=0xa9b0010*/ = (short)(uVar26 >> 0x10);
    }
    uVar26 = param_2[0x1b];
    *DAT_000a2288/*=0xa9b0012*/ = 0xff;
    puVar25 = DAT_000a228c/*=0xa9b0014*/;
    uVar22 = 0;
    *DAT_000a228c/*=0xa9b0014*/ = 0;
    puVar25[1] = 2;
    puVar25[2] = 0;
    puVar25[3] = 0;
    if ((int)uVar26 < 0) {
      uVar22 = 0xf;
    }
    puVar25[4] = uVar22;
    puVar25 = DAT_000a2290/*=0xa9b001e*/;
    *DAT_000a2290/*=0xa9b001e*/ = 0;
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
    *DAT_000a2294/*=0xa9b0024*/ = uVar22;
    puVar25 = DAT_000a2540/*=0xa9b003e*/;
    puVar20 = DAT_000a253c/*=0xa9b0026*/;
    do {
      puVar31 = puVar20 + 1;
      *puVar20 = 0;
      puVar24 = DAT_000a2544/*=0xa9b0040*/;
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
    puVar17 = DAT_000a254c/*=0xa9b005a*/;
    puVar21 = DAT_000a2548/*=0xa9b0042*/;
    do {
      puVar28 = puVar21 + 1;
      *puVar21 = 0;
      puVar21 = puVar28;
    } while (puVar28 != puVar17);
    uVar16 = (ushort)param_2[9] | (ushort)param_2[9] << 8;
    *puVar28 = uVar16;
    puVar17 = DAT_000a2550/*=0xa9b005c*/;
    *DAT_000a2550/*=0xa9b005c*/ = uVar16;
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
    puVar15 = DAT_000a263c/*=0xa9b007c*/;
    puVar28 = DAT_000a2638/*=0xa9b007a*/;
    puVar21 = DAT_000a2634/*=0xa9b0078*/;
    puVar17 = DAT_000a2554/*=0xa9b0076*/;
    uVar34 = uVar26 & 0x20000000;
    if ((int)param_2[0x17] < 0) {
      if ((uVar34 == 0) && ((uVar32 == 0 || (param_1 == 0)))) {
        uVar19 = param_2[0x32];
        uVar2 = (ushort)uVar19;
        *DAT_000a2640/*=0xa9b0076*/ = uVar2;
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
        *DAT_000a2640/*=0xa9b0076*/ = uVar16;
        *puVar21 = uVar16;
        *puVar28 = uVar16;
      }
      *puVar15 = uVar16;
    }
    else if (uVar34 != 0) {
      uVar16 = (ushort)param_2[0x12] | (ushort)param_2[0x12] << 8;
      *DAT_000a2554/*=0xa9b0076*/ = uVar16;
      puVar17[1] = uVar16;
      puVar17[2] = uVar16;
      puVar17[3] = uVar16;
    }
    puVar21 = DAT_000a255c/*=0xa9b0096*/;
    puVar17 = DAT_000a2558/*=0xa9b007e*/;
    uVar16 = (ushort)param_2[0x13] | (ushort)param_2[0x13] << 8;
    puVar28 = DAT_000a255c/*=0xa9b0096*/ + 0x1a;
    *DAT_000a2558/*=0xa9b007e*/ = uVar16;
    puVar17[1] = uVar16;
    puVar17 = DAT_000a2560/*=0xa9b0082*/;
    uVar16 = (ushort)param_2[0x14] | 0x2800 | (ushort)param_2[0x14] << 8;
    *DAT_000a2560/*=0xa9b0082*/ = uVar16;
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
    puVar25 = DAT_000a2564/*=0xa9b009a*/;
    *DAT_000a2564/*=0xa9b009a*/ = 0;
    puVar25[1] = 0;
    puVar25[2] = 0;
    puVar25[3] = 0;
    puVar25[4] = 0;
    puVar25[5] = 0;
    puVar25[6] = 0;
    puVar25[7] = 0;
    puVar21[10] = 0x404;
    puVar21[0xb] = 0x404;
    puVar17 = DAT_000a2568/*=0xa9b00ae*/;
    do {
      puVar21 = puVar17 + 1;
      *puVar17 = 0;
      puVar17 = puVar21;
    } while (puVar21 != puVar28);
    *puVar21 = 0x6060;
    *DAT_000a256c/*=0xa9b00cc*/ = 0x6060;
    if (uVar34 == 0) {
LAB_000a2536:
      *DAT_000a2570/*=0xa9b00ce*/ = 1;
    }
    else if (uVar32 == 0) {
      *DAT_000a2570/*=0xa9b00ce*/ = 0;
    }
    else {
      if (param_1 != 0) goto LAB_000a2536;
      *DAT_000a2570/*=0xa9b00ce*/ = 0;
    }
    puVar25 = DAT_000a2578/*=0xa9b00e8*/;
    puVar20 = DAT_000a2574/*=0xa9b00d0*/;
    do {
      puVar24 = puVar20 + 1;
      *puVar20 = 0;
      puVar20 = puVar24;
    } while (puVar24 != puVar25);
    *puVar24 = 0x2e;
    puVar25 = DAT_000a257c/*=0xa9b00ea*/;
    *DAT_000a257c/*=0xa9b00ea*/ = 0x50;
    puVar25[1] = 0;
    puVar25[2] = 0;
    puVar20 = DAT_000a2630/*=0xa9b00f0*/;
    if (uVar32 == 0) {
      *DAT_000a2630/*=0xa9b00f0*/ = 0;
      uVar22 = 0;
    }
    else {
      if (param_1 == 0) {
        puVar25[3] = 0x58;
        puVar25[4] = 0x287;
        goto LAB_000a2428;
      }
      if (param_1 == 1) {
        *DAT_000a2630/*=0xa9b00f0*/ = 0x458;
        uVar22 = 0x687;
      }
      else if (param_1 == 2) {
        *DAT_000a2630/*=0xa9b00f0*/ = 0x858;
        uVar22 = 0xa87;
      }
      else {
        if (param_1 != 3) goto LAB_000a2428;
        *DAT_000a2630/*=0xa9b00f0*/ = 0xc58;
        uVar22 = 0xe87;
      }
    }
    puVar20[1] = uVar22;
LAB_000a2428:
    psVar12 = DAT_000a2584/*=0xa9b0102*/;
    puVar25 = DAT_000a2580/*=0xa9b00f4*/;
    *DAT_000a2580/*=0xa9b00f4*/ = 0;
    puVar25[1] = 0;
    puVar25[2] = 0;
    puVar25[3] = 0;
    puVar25[4] = 0;
    puVar25[5] = 0;
    *DAT_000a2588/*=0xa9b0100*/ = 0xf01;
    bVar1 = *DAT_000a258c/*=0xc9488*/;
    *psVar12 = ((ushort)bVar1 * 4 + -1) * 0x100;
    psVar12 = DAT_000a2590/*=0xa9b0104*/;
    *DAT_000a2590/*=0xa9b0104*/ = (ushort)bVar1 * 4 + -5;
    psVar29 = DAT_000a2594/*=0xa9b0106*/;
    do {
      psVar30 = psVar29 + 1;
      *psVar29 = 0;
      psVar29 = psVar30;
    } while (psVar30 != psVar12 + 0x182);
    *psVar30 = 0x500;
    puVar25 = DAT_000a259c/*=0xa9b0424*/;
    puVar20 = DAT_000a2598/*=0xa9b040a*/;
    do {
      puVar24 = puVar20 + 1;
      *puVar20 = 0;
      puVar20 = puVar24;
    } while (puVar24 != puVar25);
    *puVar24 = 0x715d;
    puVar25 = DAT_000a25a0/*=0xa9b0426*/;
    *DAT_000a25a0/*=0xa9b0426*/ = 0xce;
    puVar20 = DAT_000a25a4/*=0xa9b043a*/;
    puVar25 = puVar25 + 1;
    do {
      puVar31 = puVar25 + 1;
      *puVar25 = 0;
      puVar24 = DAT_000a25a8/*=0xa9b045a*/;
      puVar25 = puVar31;
    } while (puVar31 != puVar20);
    *puVar31 = 4;
    puVar25 = DAT_000a25ac/*=0xa9b043c*/;
    do {
      puVar20 = puVar25 + 1;
      *puVar25 = 0;
      iVar13 = DAT_000a25b0/*=0xb4b40*/;
      puVar25 = puVar20;
    } while (puVar20 != puVar24);
    *puVar20 = 4;
    puVar20 = DAT_000a25bc/*=0xa9b09a0*/;
    iVar14 = DAT_000a25b8/*=0xf564fb96*/;
    puVar25 = DAT_000a25b4/*=0xa9b045c*/;
    *DAT_000a25b4/*=0xa9b045c*/ = 0;
    puVar25[1] = 0;
    puVar25[2] = 0;
    puVar25[3] = 0;
    puVar25[4] = 0;
    puVar25[5] = 0;
    puVar25[6] = 0;
    puVar25 = DAT_000a25c0/*=0xa9b046a*/;
    do {
      puVar31 = puVar25 + 1;
      *puVar25 = *(undefined2 *)(iVar13 + ((int)puVar25 + iVar14 >> 1) * 2);
      puVar24 = DAT_000a25c4/*=0xa9c0000*/;
      puVar25 = puVar31;
    } while (puVar31 != puVar20);
    do {
      puVar25 = puVar31 + 1;
      *puVar31 = 0;
      puVar31 = puVar25;
    } while (puVar25 != puVar24);
    *DAT_000a25c8/*=0xaaa0000*/ = 1;
    return;
  }
  uVar32 = (*param_2 & 0x7fff) << 1;
  if ((int)(param_2[0x1e] << 0x1d) < 0) {
    uVar16 = FUN_000a3750((*param_2 & 0x7fff) << 3,
                          (param_2[0x18] >> ((param_1 & 0x1f) << 3) & 0x1f) + 1);
    uVar32 = (uint)uVar16;
  }
  uVar22 = (undefined2)uVar32;
  if (uVar32 < 0x640) {
    uVar22 = 0x640;
  }
  *DAT_000a12ac/*=0xaaa0000*/ = 0;
  thunk_FUN_00091a8c(1);
  puVar25 = DAT_000a12b0/*=0xa9b0000*/;
  uVar32 = param_2[0x1e];
  *DAT_000a12b0/*=0xa9b0000*/ = 0;
  puVar25[1] = 0;
  if ((uVar32 & 4) == 0) {
    uVar23 = 0x30;
LAB_000a114c:
    *DAT_000a12ec/*=0xa9b0004*/ = uVar23;
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
        if (param_1 != 3) goto LAB_000a1076;
        uVar23 = 0x83;
      }
      goto LAB_000a114c;
    }
    puVar25[2] = 0xa0;
  }
LAB_000a1076:
  *DAT_000a12b4/*=0xa9b0006*/ = uVar22;
  if (*DAT_000a12b8/*=0xc9480*/ == '\0') {
    uVar22 = 4;
  }
  else {
    uVar22 = 2;
  }
  *DAT_000a12bc/*=0xa9b0008*/ = uVar22;
  puVar25 = DAT_000a12c4/*=0xa9b0010*/;
  *DAT_000a12c0/*=0xa9b000a*/ = 4;
  puVar20 = DAT_000a12c8/*=0xa9b000c*/;
  *DAT_000a12c8/*=0xa9b000c*/ = 0;
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
  *DAT_000a12cc/*=0xa9b0012*/ = 0xff;
  puVar25 = DAT_000a12d0/*=0xa9b0014*/;
  *DAT_000a12d0/*=0xa9b0014*/ = 0;
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
  *DAT_000a12d4/*=0xa9b0024*/ = uVar22;
  puVar17 = DAT_000a12dc/*=0xa9b0038*/;
  puVar25 = DAT_000a12d8/*=0xa9b0026*/;
  uVar18 = param_2[0x1b];
  *DAT_000a12d8/*=0xa9b0026*/ = 0;
  puVar25[1] = 0;
  uVar18 = uVar18 & 0x20000000;
  puVar25[2] = 0;
  puVar25[3] = 0;
  puVar25[4] = 0;
  puVar25[5] = 0;
  uVar26 = param_2[10];
  uVar19 = param_2[9];
  uVar3 = (ushort)uVar19 | (ushort)uVar26 << 8;
  *DAT_000a12e0/*=0xa9b0032*/ = uVar3;
  uVar7 = param_2[0xc];
  uVar8 = param_2[0xb];
  uVar4 = (ushort)uVar8 | (ushort)uVar7 << 8;
  *DAT_000a12e4/*=0xa9b0034*/ = uVar4;
  uVar9 = param_2[0x10];
  uVar10 = param_2[0xf];
  uVar16 = (ushort)param_2[0x11];
  uVar2 = (ushort)uVar10 | (ushort)uVar9 << 8;
  *DAT_000a12e8/*=0xa9b0036*/ = uVar2;
  puVar28 = DAT_000a1304/*=0xa9b003c*/;
  puVar21 = DAT_000a1300/*=0xa9b003a*/;
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
  *DAT_000a1308/*=0xa9b0040*/ = uVar4;
  puVar17 = DAT_000a130c/*=0xa9b0042*/;
  *DAT_000a130c/*=0xa9b0042*/ = uVar2;
  if (uVar18 == 0) {
    uVar2 = (ushort)param_2[0x32] & 0xff00;
  }
  else {
    uVar2 = (ushort)(param_2[0x12] << 8);
  }
  puVar17[1] = uVar2 | uVar16;
  puVar17 = DAT_000a12f0/*=0xa9b0046*/;
  *DAT_000a12f0/*=0xa9b0046*/ = uVar5;
  puVar25 = DAT_000a12f4/*=0xa9b004a*/;
  puVar17[1] = uVar6;
  *puVar25 = 0;
  puVar25[1] = 0;
  puVar25[2] = 0;
  puVar25[3] = 0;
  puVar25[4] = 0;
  puVar25[5] = 0;
  puVar20 = DAT_000a12f8/*=0xa9b0058*/;
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
  puVar21 = DAT_000a1314/*=0xa9b0068*/;
  puVar17 = DAT_000a1310/*=0xa9b0066*/;
  puVar25 = DAT_000a12fc/*=0xa9b005a*/;
  *DAT_000a12fc/*=0xa9b005a*/ = 0;
  puVar25[1] = 0;
  puVar25[2] = 0;
  puVar25[3] = 0;
  puVar25[4] = 0;
  puVar28 = DAT_000a1318/*=0xa9b006c*/;
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
  puVar17 = DAT_000a1530/*=0xa9b006e*/;
  uVar6 = (ushort)uVar11 | uVar6 << 8;
  *DAT_000a1530/*=0xa9b006e*/ = uVar6;
  puVar17[1] = uVar2;
  puVar17 = DAT_000a14d8/*=0xa9b0072*/;
  *DAT_000a14d8/*=0xa9b0072*/ = uVar3;
  puVar17[1] = uVar4;
  puVar17[2] = uVar16;
  puVar21 = DAT_000a14dc/*=0xa9b0092*/;
  if (uVar18 == 0) {
    uVar16 = (ushort)*(byte *)((int)param_2 + 0xcb);
  }
  else {
    uVar16 = (ushort)param_2[0x12];
  }
  puVar17[3] = uVar5 | uVar16;
  puVar17 = DAT_000a14e0/*=0xa9b007a*/;
  *DAT_000a14e0/*=0xa9b007a*/ = uVar6;
  puVar17 = puVar17 + 1;
  do {
    puVar28 = puVar17 + 1;
    *puVar17 = 0;
    puVar17 = puVar28;
  } while (puVar28 != puVar21);
  uVar32 = param_2[0x1e];
  if (uVar18 == 0) {
LAB_000a148a:
    *puVar28 = 0x100;
  }
  else if ((uVar32 & 4) == 0) {
    *puVar28 = 0;
  }
  else {
    if (param_1 != 0) goto LAB_000a148a;
    *puVar28 = 0;
  }
  bVar1 = *DAT_000a14e4/*=0xc9488*/;
  *DAT_000a14e8/*=0xa9b0094*/ = (bVar1 - 2) * 0x100;
  psVar12 = DAT_000a14ec/*=0xa9b0096*/;
  *DAT_000a14ec/*=0xa9b0096*/ = bVar1 - 2;
  psVar12[1] = 0;
  psVar12[2] = 0;
  psVar12[3] = 0x1e;
  psVar12[4] = 0x28;
  psVar12[5] = 0;
  psVar12[6] = 0;
  puVar25 = DAT_000a14f0/*=0xa9b00a4*/;
  if ((uVar32 & 4) == 0) {
    *DAT_000a14f0/*=0xa9b00a4*/ = 0;
    uVar22 = 0;
  }
  else if (param_1 == 0) {
    *DAT_000a14f0/*=0xa9b00a4*/ = 0x38;
    uVar22 = 0x24a;
  }
  else if (param_1 == 1) {
    *DAT_000a14f0/*=0xa9b00a4*/ = 0x438;
    uVar22 = 0x64a;
  }
  else if (param_1 == 2) {
    *DAT_000a14f0/*=0xa9b00a4*/ = 0x838;
    uVar22 = 0xa4a;
  }
  else {
    if (param_1 != 3) goto LAB_000a13c2;
    *DAT_000a14f0/*=0xa9b00a4*/ = 0xc38;
    uVar22 = 0xe4a;
  }
  puVar25[1] = uVar22;
LAB_000a13c2:
  puVar25 = DAT_000a14f4/*=0xa9b00a8*/;
  uVar22 = 0;
  *DAT_000a14f4/*=0xa9b00a8*/ = 0;
  puVar25[1] = 0;
  puVar25[2] = 0;
  puVar25[3] = 0;
  puVar25[4] = 0;
  puVar25[5] = 0;
  puVar25[6] = 1;
  puVar20 = DAT_000a14f8/*=0xa9b0408*/;
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
  *DAT_000a14fc/*=0xa9b00d6*/ = uVar22;
  *puVar20 = 0x200;
  puVar25 = DAT_000a1504/*=0xa9b0424*/;
  puVar20 = DAT_000a1500/*=0xa9b040a*/;
  do {
    puVar31 = puVar20 + 1;
    *puVar20 = 0;
    puVar24 = DAT_000a1508/*=0xa9b045a*/;
    puVar20 = puVar31;
  } while (puVar31 != puVar25);
  *puVar31 = 0x715d;
  *DAT_000a150c/*=0xa9b0426*/ = 0xce;
  puVar25 = DAT_000a1510/*=0xa9b0428*/;
  do {
    puVar20 = puVar25 + 1;
    *puVar25 = 0;
    iVar13 = DAT_000a1514/*=0xa6748*/;
    puVar25 = puVar20;
  } while (puVar20 != puVar24);
  *puVar20 = 4;
  iVar14 = DAT_000a151c/*=0xf564fb94*/;
  puVar25 = DAT_000a1518/*=0xa9b045c*/;
  *DAT_000a1518/*=0xa9b045c*/ = 0x400;
  puVar25[1] = 0;
  puVar20 = DAT_000a1520/*=0xa9b0548*/;
  puVar25[2] = 0;
  puVar25[3] = 0;
  puVar25[4] = 0;
  puVar25[5] = 0;
  puVar25[6] = 0;
  puVar25[7] = 0;
  puVar25 = DAT_000a1524/*=0xa9b046c*/;
  do {
    puVar31 = puVar25 + 1;
    *puVar25 = *(undefined2 *)(iVar13 + ((int)puVar25 + iVar14 >> 1) * 2);
    puVar24 = DAT_000a1528/*=0xa9c0000*/;
    puVar25 = puVar31;
  } while (puVar31 != puVar20);
  do {
    puVar25 = puVar31 + 1;
    *puVar31 = 0;
    puVar31 = puVar25;
  } while (puVar25 != puVar24);
  *DAT_000a152c/*=0xaaa0000*/ = 1;
  return;
}

//==== 0x97778  0x97778-0x977e1 inclusive
void FUN_00097778(uint param_1,int param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  bool bVar4;
  
  puVar1 = DAT_000977e8/*=0xa110510*/;
  puVar2 = DAT_000977e4/*=0xa110c80*/;
  *DAT_000977e4/*=0xa110c80*/ = 0;
  *puVar1 = *puVar1 & 0xffffe0ff | param_1 << 8;
  *puVar2 = 1;
  puVar2 = puVar2 + 0x100000;
  *puVar2 = 0;
  puVar1 = DAT_000977f0/*=0x2002c00*/;
  *DAT_000977ec/*=0xa510510*/ = param_1 << 8 | *DAT_000977ec/*=0xa510510*/ & 0xffffe0ff;
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
  FUN_00091a8c(1000);
  return;
}

//==== 0x977f4  0x977f4-0x97801 inclusive
void FUN_000977f4(int param_1)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  
  puVar4 = DAT_000a2678/*=0xa9afaa0*/;
  iVar3 = DAT_000a2674/*=0xb5076*/;
  puVar5 = DAT_000a1568/*=0xa9ac9d8*/;
  iVar1 = DAT_000a1564/*=0xa6824*/;
  if (*(int *)(param_1 + 4) == 8) {
    puVar4 = DAT_000a1560/*=0xa9a0000*/;
    do {
      puVar6 = puVar4 + 1;
      *puVar4 = *(undefined2 *)(iVar1 + ((uint)(puVar4 + -0x54d0000) & 0xfffffffe));
      puVar2 = DAT_000a156c/*=0xa9b0000*/;
      puVar4 = puVar6;
    } while (puVar6 != puVar5);
    do {
      puVar5 = puVar6 + 1;
      *puVar6 = 0;
      puVar6 = puVar5;
    } while (puVar5 != puVar2);
    return;
  }
  puVar5 = DAT_000a2670/*=0xa9a0000*/;
  do {
    puVar6 = puVar5 + 1;
    *puVar5 = *(undefined2 *)(iVar3 + ((uint)(puVar5 + -0x54d0000) & 0xfffffffe));
    puVar2 = DAT_000a267c/*=0xa9b0000*/;
    puVar5 = puVar6;
  } while (puVar6 != puVar4);
  do {
    puVar5 = puVar6 + 1;
    *puVar6 = 0;
    puVar6 = puVar5;
  } while (puVar5 != puVar2);
  return;
}
