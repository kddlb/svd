// ==== FUN_1c203ab0 @ 1c203ab0 size=1171
void __cdecl FUN_1c203ab0(int param_1,int param_2,undefined4 *param_3)
{
  bool bVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  short *psVar5;
  
  psVar5 = (short *)*param_3;
  if (psVar5 != (short *)0x0) {
    sVar2 = *psVar5;
    while (sVar2 != 0x1e) {
      switch(*psVar5) {
      case 0x32:
        FUN_1c204680();
        break;
      case 0x8c:
        *(short *)(param_1 + 0xae) = psVar5[1];
        break;
      case 0xb4:
        sVar2 = psVar5[1];
        if (0 < sVar2) {
          if (1999 < sVar2) {
            sVar2 = 2000;
          }
          if (sVar2 < 0xb) {
            sVar2 = 10;
          }
          *(short *)(param_1 + 0x46) = sVar2;
        }
        break;
      case 0xf0:
        *(short *)(param_1 + 0x4c) = psVar5[1];
        break;
      case 0xfa:
        *(short *)(param_1 + 0x60) = psVar5[1];
      }
      psVar5 = psVar5 + 3;
      sVar2 = *psVar5;
    }
  }
  uVar4 = (DAT_1c250e78 & 4) >> 2;
  if ((((DAT_1c2552fc & 0x20000000) == 0) && ((DAT_1c2552fc & 0x8000000) != 0)) &&
     (((DAT_1c2552fc & 0x1000000) == 0 || ((DAT_1c2552fc & 0x8000) != 0)))) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((DAT_1c250e78 & 0x80) != 0) {
    if (((DAT_1c250e64._1_1_ & 1) == 0) || ((DAT_1c250e70 & 0x8000000) == 0)) {
      DAT_1c250a00 = (uint)**(byte **)(param_1 + 0xc4) * 2;
    }
    else {
      DAT_1c250a00 = 100;
    }
    *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + 1;
    DAT_1c250e80 = (uint)**(byte **)(param_1 + 200) * 2;
    *(int *)(param_1 + 200) = *(int *)(param_1 + 200) + 1;
    DAT_1c250e84 = (uint)**(byte **)(param_1 + 0xcc) * 2;
    *(int *)(param_1 + 0xcc) = *(int *)(param_1 + 0xcc) + 1;
    DAT_1c250e6a = (ushort)((**(byte **)(param_1 + 0xd8) & 0x70) >> 1);
    *(int *)(param_1 + 0xd8) = *(int *)(param_1 + 0xd8) + 1;
    DAT_1c250148 = 1;
    DAT_1c2552f4 = 0;
    uVar3 = DAT_1c250e70;
    if ((((DAT_1c250e70 & 0x2000000) == 0) &&
        (uVar3 = DAT_1c2552fc, (DAT_1c2552fc & 0x2000000) == 0)) &&
       (uVar3 = 0, (DAT_1c250e5c & 0x2000000) != 0)) {
      uVar3 = DAT_1c250e5c;
    }
    if ((uVar3 & 0x400000) == 0) {
      if ((uVar3 & 0x200) == 0) {
        if ((uVar3 & 0x4000) != 0) {
          DAT_1c250a00 = DAT_1c250a00 + -4;
          DAT_1c250e80 = DAT_1c250e80 + -7;
          DAT_1c250e84 = DAT_1c250e84 + -4;
        }
      }
      else {
        DAT_1c250a00 = DAT_1c250a00 + 4;
        DAT_1c250e80 = DAT_1c250e80 + 7;
        DAT_1c250e84 = DAT_1c250e84 + 4;
      }
    }
  }
  if (*(short *)(param_1 + 0x4c) != 0) {
    return;
  }
  if ((((DAT_1c250e70 & 0x2000) != 0) && ((DAT_1c250e64._2_1_ & 0x80) != 0)) &&
     (((DAT_1c2552fc & 0x10000000) != 0 && (DAT_1c255300 != '\0')))) {
    FUN_1c204550(param_1,param_2,DAT_1c250a00 + -10);
  }
  if (DAT_1c2552f4 != 0) {
    if (DAT_1c250e6a != 0) {
      FUN_1c2045b0(param_1,param_2,(short)DAT_1c250e6a + DAT_1c250e84);
      return;
    }
    FUN_1c2045b0(param_1,param_2,DAT_1c250e84);
    return;
  }
  if ((DAT_1c250148 != 0) && (DAT_1c2552f4 = 0, (DAT_1c250e70 & 0x8000000) != 0)) {
    DAT_1c250148 = 0;
    if ((DAT_1c250e70 & 0x2000000) == 0) {
      if ((DAT_1c250e64._1_1_ & 1) == 0) {
        if ((uVar4 == 0) || ((DAT_1c2552fc & 0x2000000) == 0)) {
          FUN_1c2045b0(param_1,param_2,DAT_1c250a00);
        }
        else {
          FUN_1c204550(param_1,param_2,DAT_1c250a00);
        }
      }
      else {
        FUN_1c204500(param_1,param_2,DAT_1c250a00);
        FUN_1c204550(param_1,param_2,DAT_1c250e80 + DAT_1c250a00 >> 1);
      }
    }
    else {
      FUN_1c204500(param_1,param_2,DAT_1c250a00);
    }
  }
  if ((DAT_1c250e70 & 0x2000000) != 0) {
    if (((DAT_1c250e64._2_1_ & 4) == 0) || ((DAT_1c250e64._3_1_ & 8) != 0)) {
      if (DAT_1c250e74 == '\0') {
        if (uVar4 == 0) {
LAB_1c203e82:
          FUN_1c204550(param_1,param_2,DAT_1c250e80);
        }
        else {
          FUN_1c204500(param_1,param_2,DAT_1c250e80);
        }
      }
      else if (uVar4 == 0) {
        if ((DAT_1c250554 & 0x80) != 0) goto LAB_1c203e82;
        if ((DAT_1c2552fc & 0x10002000) == 0) {
          FUN_1c2045b0(param_1,param_2,DAT_1c250e80);
        }
        else {
          FUN_1c204610(param_1,param_2,DAT_1c250e80);
        }
      }
      else {
        FUN_1c204500(param_1,param_2,DAT_1c250e80);
      }
    }
    else {
      FUN_1c204500(param_1,param_2,DAT_1c250e80 + 8);
    }
    if (uVar4 != 0) goto LAB_1c203ec4;
    if (DAT_1c250e6a == 0) {
      if ((DAT_1c250554 & 0x80) == 0) {
        FUN_1c204610(param_1,param_2,DAT_1c250e84);
      }
      else {
        FUN_1c2045b0(param_1,param_2,DAT_1c250e84);
      }
    }
  }
  if (uVar4 == 0) {
    return;
  }
LAB_1c203ec4:
  if ((bVar1) && (DAT_1c250e6a == 0)) {
    FUN_1c2045b0(param_1,param_2,DAT_1c250e84);
    DAT_1c2552f4 = 1;
    return;
  }
  if ((uVar4 != 0) && (DAT_1c250e6a != 0)) {
    if ((DAT_1c250e70 & 0x2000000) != 0) {
      FUN_1c204550(param_1,param_2,DAT_1c250e84);
    }
    if (bVar1) {
      FUN_1c2045b0(param_1,param_2,(short)DAT_1c250e6a + DAT_1c250e84);
      DAT_1c2552f4 = 1;
    }
  }
  return;
}
