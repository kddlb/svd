// ==== FUN_1c201000 @ 1c201000 size=34

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1c201000(undefined4 param_1,int param_2)

{
  if (param_2 == 1) {
    DAT_1c25543c = &DAT_1c255370;
    _DAT_1c255438 = param_1;
  }
  return 1;
}


// ==== LoadLanguage @ 1c201030 size=149

undefined4 * LoadLanguage(void)

{
  int iVar1;
  int iVar2;
  
                    /* 0x1030  1  LoadLanguage */
  DAT_1c25543c[1] = FUN_1c2010d0;
  DAT_1c25543c[2] = FUN_1c204690;
  *DAT_1c25543c = FUN_1c206780;
  DAT_1c25543c[3] = FUN_1c2067c0;
  DAT_1c25543c[5] = &DAT_1c24d720;
  DAT_1c25543c[6] = &DAT_1c24e250;
  DAT_1c25543c[7] = &DAT_1c24b010;
  DAT_1c25543c[8] = &PTR_DAT_1c24b318;
  DAT_1c25543c[9] = &DAT_1c24bd28;
  DAT_1c25543c[4] = 1;
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 4;
    *(undefined4 *)((int)DAT_1c25543c + iVar1 + 0x28) = 0;
    iVar1 = iVar2;
  } while (iVar2 < 0xa0);
  return DAT_1c25543c;
}


// ==== FUN_1c2010d0 @ 1c2010d0 size=2429

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1c2010d0(int param_1)

{
  short sVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  short *psVar8;
  uint uVar9;
  
  puVar2 = *(undefined4 **)(param_1 + 0x28);
  DAT_1c255350 = *(short *)(puVar2 + -10);
  DAT_1c255308 = *(uint *)(*(int *)(puVar2[-0xb] + 0x1c) + DAT_1c255350 * 4);
  _DAT_1c255368 = *(undefined4 *)((int)puVar2 + -0x1e);
  _DAT_1c255314 = *(undefined2 *)(puVar2 + -9);
  DAT_1c25531c = *(short *)((int)puVar2 + -0xe);
  DAT_1c255334 = *(uint *)(*(int *)(*(int *)((int)puVar2 + -0x12) + 0x1c) + DAT_1c25531c * 4);
  _DAT_1c255328 = puVar2[-1];
  _DAT_1c255344 = *(undefined2 *)((int)puVar2 + -10);
  DAT_1c255330 = *(short *)(puVar2 + 3);
  DAT_1c255348 = *(uint *)(*(int *)(puVar2[2] + 0x1c) + DAT_1c255330 * 4);
  DAT_1c255338 = *(uint *)((int)puVar2 + 0x16);
  DAT_1c255352 = *(ushort *)(puVar2 + 4);
  DAT_1c255346 = *(short *)((int)puVar2 + 0x26);
  if (DAT_1c255346 == 0xff) {
    DAT_1c255346 = 0;
    DAT_1c255364 = 0x100000;
    DAT_1c255332 = 0;
    DAT_1c25534c = 0x100000;
    DAT_1c255304 = 0;
    _DAT_1c255358 = 0;
    _DAT_1c255354 = 0;
    _DAT_1c255340 = 0;
  }
  else {
    DAT_1c255364 = *(uint *)(*(int *)(*(int *)((int)puVar2 + 0x22) + 0x1c) + DAT_1c255346 * 4);
    _DAT_1c255354 = puVar2[0xc];
    DAT_1c255304 = *(short *)((int)puVar2 + 0x2a);
    DAT_1c255332 = *(short *)(puVar2 + 0x10);
    if (DAT_1c255332 == 0xff) {
      DAT_1c25534c = 0x100000;
      DAT_1c255332 = 0;
      _DAT_1c255340 = 0;
      _DAT_1c255358 = 0;
    }
    else {
      DAT_1c25534c = *(uint *)(*(int *)(puVar2[0xf] + 0x1c) + DAT_1c255332 * 4);
      _DAT_1c255340 = *(undefined4 *)((int)puVar2 + 0x4a);
      _DAT_1c255358 = *(undefined2 *)(puVar2 + 0x11);
    }
  }
  iVar6 = *(int *)(puVar2[2] + 0x1c);
  DAT_1c255360 = 0;
  DAT_1c25535c = 100;
  psVar8 = (short *)*puVar2;
  if (psVar8 != (short *)0x0) {
    sVar1 = *psVar8;
    while (sVar1 != 0x1e) {
      iVar7 = (int)*psVar8;
      if (iVar7 < 0x33) {
        if (iVar7 == 0x32) {
          *(int *)(param_1 + 0x56) =
               (int)*(short *)(*(int *)(puVar2[2] + 0x20) + 0x24 + psVar8[1] * 0x4a);
        }
        else if (iVar7 == 0x28) goto switchD_1c2012a5_caseD_50;
      }
      else {
        switch(iVar7) {
        case 0x50:
switchD_1c2012a5_caseD_50:
          sVar1 = psVar8[1];
          if (sVar1 < 0) {
            DAT_1c25535c = (sVar1 * DAT_1c25535c) / -100;
          }
          else {
            DAT_1c255360 = DAT_1c255360 + (int)sVar1;
          }
          break;
        case 0x5a:
          *(short *)(param_1 + 0xb2) = psVar8[1];
          break;
        case 100:
          *(short *)(param_1 + 0xb0) = psVar8[1];
          break;
        case 0x6e:
          *(short *)(param_1 + 0xb4) = psVar8[1];
          break;
        case 0x136:
          *(int *)(param_1 + 0x56) = (int)psVar8[1];
        }
      }
      psVar8 = psVar8 + 3;
      sVar1 = *psVar8;
    }
  }
  uVar4 = DAT_1c255364;
  uVar3 = DAT_1c255334;
  if ((DAT_1c255348 & 0x100000) != 0) {
    return 0;
  }
  if (((DAT_1c255348 & 0x2000000) != 0) && (DAT_1c255330 != 0x1b)) {
    if (DAT_1c255330 == 4) {
      DAT_1c255318 = (uint)*(ushort *)(param_1 + 0xb0);
    }
    else if ((DAT_1c255348 & 1) == 0) {
      DAT_1c255318 = (uint)*(ushort *)(param_1 + 0xb2);
    }
    else {
      DAT_1c255318 = (uint)*(ushort *)(param_1 + 0xb4);
    }
    goto LAB_1c2019f8;
  }
  DAT_1c255324 = 100;
  uVar9 = DAT_1c255338 & 4;
  if (uVar9 != 0) {
    DAT_1c255324 = 0x82;
  }
  if (((DAT_1c255348 & 0x18000) != 0) && (uVar9 != 0)) {
    DAT_1c255324 = (DAT_1c255324 * 0x8c + 0x32) / 100;
  }
  uVar5 = DAT_1c255348 & 0x10000000;
  if (uVar5 != 0) {
    if (uVar9 == 0) {
      DAT_1c255324 = (DAT_1c255324 * 0x3c + 0x32) / 100;
    }
    if ((DAT_1c255338 & 8) == 0) {
      DAT_1c255324 = (DAT_1c255324 * 0x55 + 0x32) / 100;
    }
    if ((DAT_1c255338 & 0x40) != 0) {
      DAT_1c255324 = (DAT_1c255324 * 0x50 + 0x32) / 100;
    }
    if (DAT_1c255352 < 3) {
      DAT_1c255324 = (DAT_1c255324 * 0x3c + 0x32) / 100;
    }
    switch(DAT_1c255352) {
    case 0:
      DAT_1c255310 = 100;
      break;
    case 1:
      DAT_1c255310 = 0x5a;
      break;
    case 2:
      DAT_1c255310 = 0x5d;
      break;
    case 3:
      DAT_1c255310 = 0x60;
      break;
    case 4:
    case 5:
      DAT_1c255310 = 100;
      break;
    case 6:
      DAT_1c255310 = 0x6e;
      break;
    case 7:
      DAT_1c255310 = 0x78;
      break;
    case 8:
      DAT_1c255310 = 0x82;
      break;
    case 9:
      DAT_1c255310 = 0x8c;
      break;
    default:
      DAT_1c255310 = 100;
    }
    DAT_1c255324 = (DAT_1c255310 * DAT_1c255324 + 0x32) / 100;
    if ((DAT_1c255330 == 0x29) && (DAT_1c25531c == 0x39)) {
      DAT_1c255324 = (DAT_1c255324 * 0x41 + 0x32) / 100;
    }
    DAT_1c255310 = 100;
    if (DAT_1c255352 != 0) {
      if (((DAT_1c255364 & 0x20000000) == 0) && (DAT_1c255346 != 0)) {
        if ((((DAT_1c255364 & 0x1000) == 0) || ((DAT_1c255364 & 0x4000) != 0)) ||
           ((DAT_1c255364 & 0x8000000) == 0)) {
          if ((DAT_1c255364 & 0x800000) == 0) {
            if (((DAT_1c255364 & 0x8000) == 0) || (DAT_1c255304 != 0)) {
              if (((DAT_1c255364 & 0x1000000) != 0) || (DAT_1c255346 == 0x3f)) {
                if ((DAT_1c255346 == 0x54) || (DAT_1c255346 == 0x55)) {
                  DAT_1c255310 = 0x37;
                }
                else {
                  DAT_1c255310 = 0x46;
                }
              }
            }
            else if ((*(byte *)(iVar6 + 3 + DAT_1c255332 * 4) & 1) == 0) {
              DAT_1c255310 = 0x55;
            }
            else {
              DAT_1c255310 = 0x3c;
            }
          }
          else {
            DAT_1c255310 = 0x78;
          }
        }
        else {
          DAT_1c255310 = 0x96;
        }
      }
      else {
        DAT_1c255310 = 0x82;
      }
    }
    if (uVar9 == 0) {
      DAT_1c255310 = (DAT_1c255310 * 0x1e + 0xfU) / 0x28 + 0x19;
    }
    DAT_1c255324 = (int)(DAT_1c255310 * DAT_1c255324 + 0x32) / 100;
  }
  if ((DAT_1c255348 & 2) != 0) {
    if (8 < DAT_1c25531c) {
      DAT_1c255324 = (int)(DAT_1c255324 * 0x55 + 0x32) / 100;
    }
    if (((DAT_1c255348 & 0x1800000) != 0) && (DAT_1c25531c == 0x41)) {
      DAT_1c255324 = (int)(DAT_1c255324 * 0x3c + 0x32) / 100;
    }
    if (((DAT_1c255350 == 0x41) && ((DAT_1c255334 & 0x1800000) != 0)) &&
       ((DAT_1c255348 & 0x30000) != 0)) {
      DAT_1c255324 = (int)((DAT_1c255324 * 5 + 5) * 10) / 100;
    }
    if ((DAT_1c25531c == 0x41) && ((DAT_1c255348 & 0x8000) != 0)) {
      DAT_1c255324 = (int)(DAT_1c255324 * 0x3c + 0x32) / 100;
    }
    if ((((DAT_1c255348 & 0x1000) != 0) && ((DAT_1c255348 & 0x8000000) == 0)) && (uVar9 != 0)) {
      DAT_1c255324 = (int)(DAT_1c255324 * 0x96 + 0x32) / 100;
    }
    if (DAT_1c255352 < 3) {
      if (((DAT_1c255348 & 0x30000) == 0) || ((DAT_1c255364 & 0x10000000) == 0)) {
        if (2 < DAT_1c255352) goto LAB_1c2017e6;
        iVar6 = DAT_1c255324 * 0x46;
      }
      else {
        iVar6 = DAT_1c255324 * 0x14;
      }
      DAT_1c255324 = (iVar6 + 0x32) / 100;
    }
LAB_1c2017e6:
    if ((DAT_1c255330 == 0x39) && (DAT_1c255346 == 0x29)) {
      DAT_1c255324 = (int)(DAT_1c255324 * 0x46 + 0x32) / 100;
    }
  }
  DAT_1c25530c = DAT_1c255334;
  DAT_1c25533c = DAT_1c255364;
  if (DAT_1c25531c == 0) {
    DAT_1c255334 = DAT_1c255308;
  }
  if (DAT_1c255346 == 0) {
    DAT_1c255364 = DAT_1c25534c;
  }
  if (uVar5 == 0) {
    if ((DAT_1c255348 & 2) != 0) {
      if (((DAT_1c255334 & 2) == 0) || ((DAT_1c255364 & 2) == 0)) {
        if (((DAT_1c255334 & 2) == 0) && ((DAT_1c255364 & 2) == 0)) goto LAB_1c20190a;
        iVar6 = DAT_1c255324 * 0x46 + 0x32;
      }
      else {
        iVar6 = (DAT_1c255324 * 5 + 5) * 10;
      }
LAB_1c201902:
      DAT_1c255324 = iVar6 / 100;
    }
  }
  else {
    if ((DAT_1c255364 & 0x10000000) != 0) {
      DAT_1c255324 = (int)(DAT_1c255324 * 0x78 + 0x32) / 100;
    }
    if ((DAT_1c255334 & 0x10000000) != 0) {
      iVar6 = DAT_1c255324 * 0x46 + 0x32;
      goto LAB_1c201902;
    }
  }
LAB_1c20190a:
  DAT_1c255320 = (int)*(short *)(puVar2[1] + 0x14 + DAT_1c255330 * 0x1a);
  DAT_1c25532c = (int)*(short *)(puVar2[1] + 0x12 + DAT_1c255330 * 0x1a);
  if (DAT_1c255352 == 0) {
    DAT_1c25532c = DAT_1c25532c + 1 >> 1;
  }
  if (0xa9 < (int)DAT_1c255324) {
    DAT_1c255324 = 0xaa;
  }
  DAT_1c255318 = DAT_1c25532c + (int)((DAT_1c255320 - DAT_1c25532c) * DAT_1c255324 + 0x32) / 100;
  if (((DAT_1c255352 != 0) && ((DAT_1c255348 & 4) != 0)) && ((uVar3 & 0x1000000) != 0)) {
    DAT_1c255318 = DAT_1c255318 + 0x19;
  }
  if (((uVar5 != 0) && (DAT_1c255330 != 0x17)) && (DAT_1c255330 != 0x18)) {
    DAT_1c255318 = (uint)(((longlong)*(int *)(param_1 + 0x56) * (longlong)(int)DAT_1c255318 &
                          0xffffffffU) / 100);
  }
LAB_1c2019f8:
  if (DAT_1c255360 != 0) {
    DAT_1c255318 = DAT_1c255360;
  }
  DAT_1c255318 = (int)(DAT_1c255318 * DAT_1c25535c) / 100;
  if (3999 < (int)DAT_1c255318) {
    DAT_1c255318 = 4000;
  }
  if ((int)DAT_1c255318 < 0x1a) {
    DAT_1c255318 = 0x19;
  }
  DAT_1c255334 = uVar3;
  DAT_1c255364 = uVar4;
  *(short *)((int)puVar2 + 0xe) = (short)DAT_1c255318;
  return 0;
}


// ==== FUN_1c201b80 @ 1c201b80 size=5031

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1c201b80(int param_1)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  FUN_1c202fe0(0x1c2506d0);
  FUN_1c202fe0(0x1c2505b0);
  FUN_1c202fe0(0x1c250750);
  FUN_1c202fe0(0x1c250600);
  FUN_1c202fe0(0x1c250790);
  FUN_1c202fe0(0x1c250640);
  bVar1 = DAT_1c2509b4;
  if ((DAT_1c250810 != 0x4b) && (DAT_1c250810 != 0x4c)) {
    bVar1 = DAT_1c250810;
  }
  iVar3 = (short)(ushort)bVar1 * 0x1a + *(int *)(param_1 + 4);
  DAT_1c2506e8 = (int)*(short *)(iVar3 + 6);
  DAT_1c2505c8 = (int)*(short *)(iVar3 + 0xc);
  DAT_1c250768 = (int)*(short *)(iVar3 + 8);
  DAT_1c250618 = (int)*(short *)(iVar3 + 0xe);
  DAT_1c2507a8 = (int)*(short *)(iVar3 + 10);
  DAT_1c250658 = (int)*(short *)(iVar3 + 0x10);
  DAT_1c2505cc = DAT_1c2505c8;
  DAT_1c25061c = DAT_1c250618;
  DAT_1c25065c = DAT_1c250658;
  DAT_1c2506ec = DAT_1c2506e8;
  DAT_1c25076c = DAT_1c250768;
  DAT_1c2507ac = DAT_1c2507a8;
  if ((DAT_1c2552fc & 0x10) != 0) {
    DAT_1c2506ec = (int)*(short *)(iVar3 + 0x20);
    DAT_1c2505cc = (int)*(short *)(iVar3 + 0x26);
    DAT_1c25076c = (int)*(short *)(iVar3 + 0x22);
    DAT_1c25061c = (int)*(short *)(iVar3 + 0x28);
    DAT_1c2507ac = (int)*(short *)(iVar3 + 0x24);
    DAT_1c25065c = (int)*(short *)(iVar3 + 0x2a);
  }
  if ((DAT_1c250810 == 0x4b) || (DAT_1c250810 == 0x4c)) {
    DAT_1c2505c8 = *(short *)(iVar3 + 0xc) + 200;
    DAT_1c250618 = *(short *)(iVar3 + 0xe) + 0x28;
    if (DAT_1c250618 < 0xc9) {
      DAT_1c250618 = 200;
    }
    DAT_1c250658 = *(short *)(iVar3 + 0x10) + 0x3c;
    if (DAT_1c250658 < 0x12d) {
      DAT_1c250658 = 300;
    }
    DAT_1c2505cc = DAT_1c2505c8;
    DAT_1c25061c = DAT_1c250618;
    DAT_1c25065c = DAT_1c250658;
    if ((DAT_1c250e70 & 0x20000000) == 0) {
      DAT_1c2506e8 = DAT_1c2506ec + DAT_1c2506dc >> 1;
      DAT_1c250768 = DAT_1c25075c + DAT_1c25076c >> 1;
      DAT_1c2507a8 = DAT_1c2507ac + DAT_1c25079c >> 1;
    }
  }
  if ((DAT_1c2552fc & 0x20000000) != 0) {
    DAT_1c2506e8 = DAT_1c2506dc;
    DAT_1c2505c8 = DAT_1c2505bc;
    DAT_1c250768 = DAT_1c25075c;
    DAT_1c250618 = DAT_1c25060c;
    DAT_1c2507a8 = DAT_1c25079c;
    DAT_1c250658 = DAT_1c25064c;
  }
  if ((DAT_1c250e70 & 0x20000000) != 0) {
    DAT_1c2506dc = DAT_1c2506e8;
    DAT_1c2505bc = DAT_1c2505cc;
    DAT_1c25075c = DAT_1c250768;
    DAT_1c25060c = DAT_1c25061c;
    DAT_1c25079c = DAT_1c2507a8;
    DAT_1c25064c = DAT_1c25065c;
  }
  if ((DAT_1c2552fc & 0x10000000) == 0) {
    if (((((DAT_1c2552fc & 0x40) != 0) && ((DAT_1c2552fc & 0x10000) != 0)) &&
        ((DAT_1c250e5c._3_1_ & 0x10) != 0)) && ((DAT_1c250e5c._2_1_ & 0x20) != 0)) {
      DAT_1c250768 = DAT_1c250768 + -0x32;
      DAT_1c2507a8 = DAT_1c2507a8 + -200;
      DAT_1c25076c = DAT_1c250768;
      DAT_1c2507ac = DAT_1c2507a8;
    }
  }
  else {
    if (((DAT_1c250810 == 0x1c) && ((DAT_1c250e64 & 0x800000) != 0)) &&
       ((DAT_1c250e64 & 0x8000) == 0)) {
      DAT_1c250768 = DAT_1c250768 + _DAT_1c250760 >> 1;
      DAT_1c25076c = DAT_1c250768;
    }
    if ((((DAT_1c2552fc & 0x80) != 0) && ((DAT_1c2552fc & 0x1000) != 0)) &&
       ((DAT_1c250e5c._3_1_ & 4) != 0)) {
      DAT_1c25076c = DAT_1c250768;
    }
    if (((DAT_1c2552fc & 0x40000080) != 0) && ((DAT_1c250e5c._1_1_ & 8) != 0)) {
      DAT_1c25076c = DAT_1c25076c + -300;
    }
    if (((DAT_1c2552fc & 0x40000000) != 0) && (((byte)DAT_1c250e5c & 2) != 0)) {
      DAT_1c25076c = DAT_1c25076c + -0x96;
    }
    if ((DAT_1c2552fc & 0x400000) != 0) {
      DAT_1c2507a8 = (*(short *)((uint)DAT_1c2509b4 * 0x1a + 10 + *(int *)(param_1 + 4)) +
                      DAT_1c2507a8 + DAT_1c250798) / 3;
      DAT_1c2507ac = DAT_1c2507a8;
    }
  }
  if (((DAT_1c2552fc & 2) != 0) && ((DAT_1c250e70 & 0x180000) != 0)) {
    DAT_1c25076c = 0x73a;
    DAT_1c250768 = 0x73a;
    DAT_1c2507ac = 0x898;
    DAT_1c2507a8 = 0x898;
  }
  if (((DAT_1c2552fc & 0x4000000) != 0) && ((DAT_1c250e70 & 0x180000) != 0)) {
    DAT_1c25076c = 0x6a4;
    DAT_1c250768 = 0x6a4;
    DAT_1c2507ac = 0x76c;
    DAT_1c2507a8 = 0x76c;
  }
  if (((DAT_1c2552fc & 0x4000000) != 0) && ((DAT_1c250e70 & 0x80000000) != 0)) {
    DAT_1c25076c = 900;
    DAT_1c250768 = 900;
    DAT_1c2507ac = 0x9c4;
    DAT_1c2507a8 = 0x9c4;
  }
  if (DAT_1c250810 == 0x37) {
    if (((DAT_1c250e5c._2_1_ & 0x80) != 0) && ((DAT_1c250e5c._1_1_ & 0x80) == 0)) {
      DAT_1c250768 = ((int)*(short *)((uint)DAT_1c2509b4 * 0x1a + 8 + *(int *)(param_1 + 4)) +
                     DAT_1c250768 * 9) / 10;
      DAT_1c25076c = DAT_1c250768;
    }
    if (((DAT_1c250e5c._2_1_ & 0x80) == 0) || ((DAT_1c250e5c._1_1_ & 0x80) != 0)) {
      DAT_1c250768 = (DAT_1c250768 * 9 + 0x91) / 10;
      DAT_1c25076c = DAT_1c250768;
    }
  }
  if (DAT_1c250810 == 0x36) {
    iVar3 = (uint)DAT_1c2509b4 * 0x1a;
    DAT_1c250768 = (((int)*(short *)(*(int *)(param_1 + 4) + 8 + iVar3) + DAT_1c250768 * 3) * 0x19)
                   / 100;
    DAT_1c25076c = ((int)*(short *)(*(int *)(param_1 + 4) + 8 + iVar3) + DAT_1c250768 * 2) / 3;
    DAT_1c2507a8 = DAT_1c250768 + 0xfa;
    DAT_1c2507ac = ((int)*(short *)(*(int *)(param_1 + 4) + 10 + iVar3) + DAT_1c2507a8 * 2) / 3;
  }
  if (((DAT_1c2552fc & 0x800) != 0) && (DAT_1c2509b4 == 0x29)) {
    DAT_1c2506ec = DAT_1c2506ec + -0x50;
  }
  if (DAT_1c250810 == 0x3f) {
    iVar3 = (uint)DAT_1c2509b4 * 0x1a;
    DAT_1c2506e8 = (int)*(short *)(*(int *)(param_1 + 4) + 6 + iVar3) + DAT_1c2506d8 * 2 +
                   DAT_1c2506e8 >> 2;
    DAT_1c250768 = (*(short *)(*(int *)(param_1 + 4) + 8 + iVar3) + DAT_1c250768 + DAT_1c250758) / 3
    ;
    DAT_1c2507a8 = (*(short *)(*(int *)(param_1 + 4) + 10 + iVar3) + DAT_1c2507a8 + DAT_1c250798) /
                   3;
    DAT_1c2506ec = DAT_1c2506e8;
    DAT_1c25076c = DAT_1c250768;
    DAT_1c2507ac = DAT_1c2507a8;
  }
  if (DAT_1c250810 == 0x40) {
    iVar3 = (uint)DAT_1c2509b4 * 0x1a;
    DAT_1c2506e8 = *(short *)(*(int *)(param_1 + 4) + 6 + iVar3) + DAT_1c2506dc >> 1;
    DAT_1c250768 = *(short *)(*(int *)(param_1 + 4) + 8 + iVar3) + DAT_1c25075c >> 1;
    DAT_1c2507a8 = *(short *)(*(int *)(param_1 + 4) + 10 + iVar3) + DAT_1c25079c >> 1;
    DAT_1c2506ec = DAT_1c2506e8;
    DAT_1c25076c = DAT_1c250768;
    DAT_1c2507ac = DAT_1c2507a8;
  }
  if ((DAT_1c250810 == 0x3e) && ((DAT_1c250e70 & 0x40000080) != 0)) {
    DAT_1c2506e8 = DAT_1c2506e8 + -100;
    DAT_1c250768 = DAT_1c250768 + 0x28a;
    DAT_1c2506ec = DAT_1c2506e8;
    DAT_1c25076c = DAT_1c250768;
    DAT_1c2507a8 = DAT_1c2507a8 + 0x2ee;
    DAT_1c2507ac = DAT_1c2507a8;
  }
  if (((DAT_1c250e70 & 8) != 0) && (DAT_1c250810 == 0x36)) {
    DAT_1c2506ec = DAT_1c2506e8;
    DAT_1c25076c = DAT_1c250768;
    DAT_1c2507ac = DAT_1c2507a8;
    iVar3 = *(int *)(param_1 + 4);
    DAT_1c2506e8 = (int)*(short *)(iVar3 + 0x276);
    DAT_1c250768 = (int)*(short *)(iVar3 + 0x278);
    DAT_1c2507a8 = (int)*(short *)(iVar3 + 0x27a);
    DAT_1c2505c8 = (int)*(short *)(iVar3 + 0x27c);
    DAT_1c250618 = (int)*(short *)(iVar3 + 0x27e);
    DAT_1c250658 = (int)*(short *)(iVar3 + 0x280);
  }
  if ((DAT_1c250810 == 0x29) && ((DAT_1c250e5c._1_1_ & 8) != 0)) {
    iVar3 = *(int *)(param_1 + 4);
    DAT_1c2506ec = *(short *)(iVar3 + 0x312) + DAT_1c2506ec >> 1;
    DAT_1c25076c = *(short *)(iVar3 + 0x314) + DAT_1c25076c >> 1;
    DAT_1c2507ac = *(short *)(iVar3 + 0x316) + DAT_1c2507ac >> 1;
    DAT_1c2505cc = *(short *)(iVar3 + 0x318) + DAT_1c2505cc >> 1;
    DAT_1c25061c = *(short *)(iVar3 + 0x31a) + DAT_1c25061c >> 1;
    DAT_1c25065c = *(short *)(iVar3 + 0x31c) + DAT_1c25065c >> 1;
  }
  if (DAT_1c2507a8 - DAT_1c250768 < 0xfa) {
    DAT_1c250768 = DAT_1c2507a8 + -0xfa;
  }
  if (DAT_1c2507ac - DAT_1c25076c < 0xfa) {
    DAT_1c25076c = DAT_1c2507ac + -0xfa;
  }
  if (DAT_1c250768 - DAT_1c2506e8 < 200) {
    DAT_1c2506e8 = DAT_1c250768 + -200;
  }
  if (DAT_1c25076c - DAT_1c2506ec < 200) {
    DAT_1c2506ec = DAT_1c25076c + -200;
  }
  FUN_1c203770();
  sVar2 = DAT_1c25055a;
  if ((DAT_1c2552fc & 0x10002000) != 0) {
    if ((DAT_1c250e5c._1_1_ & 0x80) != 0) {
      DAT_1c2505cc = DAT_1c2505cc + 100;
      DAT_1c25061c = DAT_1c25061c + 0x32;
      DAT_1c25065c = DAT_1c25065c + 0x32;
      DAT_1c2506ec = (DAT_1c2506ec * 2 + 500) / 3;
    }
    if ((DAT_1c250e70 & 0x8000) != 0) {
      DAT_1c2505c8 = DAT_1c2505c8 + 100;
      DAT_1c250618 = DAT_1c250618 + 0x32;
      DAT_1c250658 = DAT_1c250658 + 0x32;
      DAT_1c2506e8 = (DAT_1c2506e8 * 2 + 500) / 3;
    }
  }
  DAT_1c250562 = DAT_1c25055a;
  uVar5 = DAT_1c2552fc & 0x10000000;
  if (uVar5 == 0) {
    if ((DAT_1c2552fc & 0x1000000) == 0) {
      DAT_1c25055a = 2;
      if ((DAT_1c2552fc & 0x40) == 0) {
        DAT_1c25055a = 3;
      }
    }
    else {
      DAT_1c25055a = 1;
    }
  }
  else {
    DAT_1c25055a = 0;
  }
  DAT_1c2507b8 = (uint)(byte)(&DAT_1c24c3f0)[sVar2 * 4 + (int)DAT_1c25055a];
  if (DAT_1c250e7e == '7') {
    DAT_1c2507b8 = 0x14;
  }
  uVar7 = DAT_1c250e70 & 0x800000;
  if ((uVar7 == 0) || ((DAT_1c2552fc & 0x40) == 0)) {
    DAT_1c2506f8 = DAT_1c2507b8;
    if (((DAT_1c250e70 & 0x40) != 0) && ((DAT_1c2552fc & 0x800000) != 0)) {
      DAT_1c2506f8 = 10;
    }
  }
  else {
    DAT_1c2506f8 = 0x5a;
  }
  DAT_1c250668 = DAT_1c2507b8;
  if (((DAT_1c250e70 & 0x1000000) == 0) || ((DAT_1c2552fc & 0x800000) == 0)) {
    if ((uVar7 == 0) || ((DAT_1c2552fc & 0x1000000) == 0)) {
      DAT_1c2505d8 = DAT_1c2506f8;
      DAT_1c250628 = DAT_1c2507b8;
      if ((DAT_1c2552fc & 0x20000000) != 0) {
        DAT_1c2507b8 = 0;
        DAT_1c2506f8 = 0;
        DAT_1c2505d8 = 0x32;
        DAT_1c250668 = 0x32;
        DAT_1c250628 = DAT_1c2505d8;
      }
    }
    else {
      DAT_1c2506f8 = 0x3c;
      DAT_1c2505d8 = 0x1e;
      DAT_1c250628 = DAT_1c2505d8;
    }
  }
  else if ((DAT_1c250e70 & 0x4000000) == 0) {
    DAT_1c2506f8 = 0x28;
    DAT_1c2505d8 = 0x46;
    DAT_1c250628 = DAT_1c2505d8;
  }
  else {
    DAT_1c2506f8 = 0x14;
    DAT_1c2505d8 = 0x46;
    DAT_1c250628 = DAT_1c2505d8;
  }
  if ((DAT_1c250e70 & 0x20000000) != 0) {
    DAT_1c2507b8 = 100;
    DAT_1c2506f8 = 100;
  }
  uVar6 = DAT_1c250e70 & 0x10000000;
  if ((uVar6 == 0) || ((DAT_1c2552fc & 0x4000000) == 0)) {
    DAT_1c250778 = DAT_1c2507b8;
    if (((DAT_1c250e70 & 0x4000000) != 0) && (uVar5 != 0)) {
      DAT_1c250778 = 0x1e;
    }
  }
  else {
    DAT_1c250778 = 0x50;
  }
  if ((uVar7 != 0) && ((DAT_1c2552fc & 0x800) != 0)) {
    DAT_1c2505d8 = 0x5a;
    DAT_1c2506f8 = 0x5a;
    DAT_1c250628 = 0x5a;
    DAT_1c250778 = 0x5a;
    DAT_1c250668 = 0x5a;
    DAT_1c2507b8 = 0x5a;
  }
  if (((DAT_1c250e70 & 0x80000) == 0) || ((DAT_1c2552fc & 0x8000) == 0)) {
    if (((DAT_1c250e70 & 0x8000) != 0) && ((DAT_1c2552fc & 0x80000) != 0)) {
      DAT_1c250628 = 0x5a;
      DAT_1c250668 = DAT_1c250628;
      DAT_1c250778 = DAT_1c250628;
      DAT_1c2507b8 = DAT_1c250628;
    }
  }
  else {
    DAT_1c250628 = 10;
    DAT_1c250668 = DAT_1c250628;
    DAT_1c250778 = DAT_1c250628;
    DAT_1c2507b8 = DAT_1c250628;
  }
  if (((DAT_1c250e70 & 0xc0100000) != 0) && ((DAT_1c2552fc & 0x2000) != 0)) {
    DAT_1c2505d8 = 0x14;
    DAT_1c2506f8 = 0x14;
    DAT_1c250628 = 0x14;
    DAT_1c250778 = 0x14;
    DAT_1c250668 = 0x14;
    DAT_1c2507b8 = 0x14;
  }
  DAT_1c2506f4 = DAT_1c2506dc + (int)((DAT_1c2506e8 - DAT_1c2506dc) * DAT_1c2506f8) / 100;
  DAT_1c250774 = DAT_1c25075c + (int)((DAT_1c250768 - DAT_1c25075c) * DAT_1c250778) / 100;
  _DAT_1c2507b4 = DAT_1c25079c + (int)((DAT_1c2507a8 - DAT_1c25079c) * DAT_1c2507b8) / 100;
  _DAT_1c2505d4 = DAT_1c2505bc + (int)((DAT_1c2505c8 - DAT_1c2505bc) * DAT_1c2505d8) / 100;
  _DAT_1c250624 = DAT_1c25060c + (int)((DAT_1c250618 - DAT_1c25060c) * DAT_1c250628) / 100;
  _DAT_1c250664 = DAT_1c25064c + (int)((DAT_1c250658 - DAT_1c25064c) * DAT_1c250668) / 100;
  if ((((DAT_1c250e64 & 2) != 0) && (DAT_1c255303 != '?')) && (uVar7 != 0)) {
    _DAT_1c250770 = 0x640;
    _DAT_1c2507b0 = 0x8fc;
    if ((DAT_1c250e70 & 0x80000) == 0) {
      _DAT_1c2507b0 = 0xa28;
    }
  }
  if ((((DAT_1c250e70 & 2) != 0) && (DAT_1c250e7e != '?')) &&
     (((DAT_1c2552fc & 0x800000) != 0 && (_DAT_1c2507b4 = 0x8fc, (DAT_1c2552fc & 0x80000) == 0)))) {
    _DAT_1c2507b4 = 0xa3c;
  }
  if (((DAT_1c250e64 & 2) != 0) && (DAT_1c250e7e == ')')) {
    _DAT_1c250770 = _DAT_1c250770 + 300;
  }
  if (((DAT_1c250e70 & 0x10002000) != 0) && ((DAT_1c2552fc & 0x4000000) != 0)) {
    _DAT_1c2505d4 = _DAT_1c2505d4 + 100;
    DAT_1c250774 = (DAT_1c25079c + DAT_1c250768 + DAT_1c25075c) / 3 + -400;
  }
  if (((DAT_1c2552fc & 0x4000000) != 0) && ((DAT_1c250e70 & 0x40000080) != 0)) {
    DAT_1c250774 = DAT_1c250774 + 100;
  }
  uVar4 = DAT_1c250e70 & 0x4000000;
  if ((uVar4 != 0) && ((DAT_1c2552fc & 0x40000080) != 0)) {
    DAT_1c250774 = DAT_1c250774 + 100;
  }
  if (uVar4 != 0) {
    if ((DAT_1c2552fc & 0x400) == 0) {
      _DAT_1c2507b4 = DAT_1c250774 + 400;
    }
    else {
      _DAT_1c2507b4 = DAT_1c250774 + 800;
    }
  }
  if ((DAT_1c2552fc & 0x4000000) != 0) {
    if ((DAT_1c250e70 & 0x400) == 0) {
      _DAT_1c2507b4 = DAT_1c250774 + 600;
    }
    else {
      _DAT_1c2507b4 = DAT_1c250774 + 800;
    }
  }
  if (((DAT_1c250e70 & 0x800) == 0) || (uVar5 == 0)) {
    if ((uVar6 != 0) && ((DAT_1c250e64 & 0x800) != 0)) {
      DAT_1c2506f0 = DAT_1c2506f0 + 100;
      _DAT_1c250770 = _DAT_1c250770 + 100;
    }
  }
  else {
    DAT_1c2506f4 = DAT_1c2506f4 + -0x3c;
    DAT_1c250774 = DAT_1c250774 + -0x32;
  }
  if (((DAT_1c250e70 & 0x20000100) != 0) && (DAT_1c250e7e != '@')) {
    DAT_1c2506f0 = DAT_1c2506d8;
    _DAT_1c250770 = DAT_1c250758;
    _DAT_1c2507b0 = DAT_1c250798;
  }
  if ((uVar4 == 0) || ((DAT_1c2552fc & 0x10002000) == 0)) goto switchD_1c2029a9_caseD_a;
  switch(DAT_1c250810) {
  case 9:
    DAT_1c250774 = 0x8de;
    _DAT_1c2507b4 = 0xc1c;
    break;
  case 0xb:
    DAT_1c250774 = 0x866;
    _DAT_1c2507b4 = 0xb54;
    break;
  case 0xd:
    DAT_1c250774 = 0x834;
    _DAT_1c2507b4 = 0xa14;
    break;
  case 0xf:
    DAT_1c250774 = 0x898;
    _DAT_1c2507b4 = 0xa00;
    break;
  case 0x11:
    DAT_1c250774 = 2000;
    _DAT_1c2507b4 = 0x9c4;
    break;
  case 0x12:
    DAT_1c250774 = 2000;
    goto LAB_1c202bbd;
  case 0x13:
    DAT_1c250774 = 0x5dc;
    _DAT_1c2507b4 = 0x898;
    break;
  case 0x15:
    DAT_1c250774 = 0x5dc;
    _DAT_1c2507b4 = 2000;
    break;
  case 0x17:
    DAT_1c250774 = 2000;
    goto LAB_1c202bbd;
  case 0x18:
    DAT_1c250774 = 0x866;
    _DAT_1c2507b4 = 0xb54;
    break;
  case 0x19:
    DAT_1c250774 = 0x6a4;
    _DAT_1c2507b4 = 0x802;
    break;
  case 0x1f:
    DAT_1c250774 = 0x866;
    _DAT_1c2507b4 = 0xa41;
    break;
  case 0x21:
    DAT_1c250774 = 0x7e4;
    _DAT_1c2507b4 = 0x92e;
    break;
  case 0x23:
    DAT_1c250774 = 0x5dc;
    _DAT_1c2507b4 = 2000;
    break;
  case 0x25:
    DAT_1c250774 = 0x80c;
    _DAT_1c2507b4 = 0x8d4;
    break;
  case 0x27:
    DAT_1c250774 = 0x73a;
    _DAT_1c2507b4 = 0x834;
    break;
  case 0x29:
    DAT_1c250774 = 2000;
    _DAT_1c2507b4 = 0x8fc;
    break;
  case 0x2b:
    DAT_1c250774 = 0x898;
    _DAT_1c2507b4 = 0xaf0;
    break;
  case 0x2d:
    DAT_1c250774 = 0x7f8;
    _DAT_1c2507b4 = 0x9d8;
    break;
  case 0x31:
    DAT_1c250774 = 0x500;
    _DAT_1c2507b4 = 2000;
    break;
  case 0x33:
    DAT_1c250774 = 0x5dc;
    _DAT_1c2507b4 = 2000;
    break;
  case 0x36:
    DAT_1c250774 = 0x47e;
    _DAT_1c2507b4 = 0x776;
    break;
  case 0x37:
  case 0x56:
    DAT_1c250774 = 0x410;
LAB_1c202bbd:
    _DAT_1c2507b4 = 0x8ca;
  }
switchD_1c2029a9_caseD_a:
  _DAT_1c2505dc = 10;
  DAT_1c2506fc = 10;
  _DAT_1c25062c = 10;
  _DAT_1c25077c = 10;
  _DAT_1c25066c = 10;
  _DAT_1c2507bc = 10;
  _DAT_1c2505e0 = 10;
  DAT_1c250700 = 10;
  _DAT_1c250630 = 10;
  _DAT_1c250780 = 10;
  _DAT_1c250670 = 10;
  _DAT_1c2507c0 = 10;
  if ((uVar7 != 0) && ((DAT_1c2552fc & 0x1000000) != 0)) {
    _DAT_1c2505e0 = 7;
    DAT_1c250700 = 7;
    _DAT_1c250630 = 9;
    _DAT_1c250780 = 9;
    _DAT_1c250670 = 9;
    _DAT_1c2507c0 = 9;
  }
  if (DAT_1c250e7e == '9') {
    _DAT_1c250630 = (-(uint)((DAT_1c2552fc & 0x1000000) == 0) & 2) + 3;
    _DAT_1c250670 = _DAT_1c250630;
    _DAT_1c250780 = _DAT_1c250630;
    _DAT_1c2507c0 = _DAT_1c250630;
  }
  if (DAT_1c250e7e == '6') {
    _DAT_1c2505e0 = 6;
    DAT_1c250700 = 6;
    _DAT_1c2505dc = 6;
    DAT_1c2506fc = 6;
    _DAT_1c250630 = 6;
    _DAT_1c250780 = 6;
    _DAT_1c25062c = 6;
    _DAT_1c25077c = 6;
    _DAT_1c250670 = 6;
    _DAT_1c2507c0 = 6;
    _DAT_1c25066c = 6;
    _DAT_1c2507bc = 6;
  }
  if (((DAT_1c250e64 & 0x2000) == 0) || (DAT_1c255303 == '6')) {
LAB_1c202cfb:
    if ((((uVar6 != 0) && (DAT_1c250e74 != '\0')) && (DAT_1c250edc != '\0')) &&
       (((DAT_1c250e64 & 0x2000) != 0 && ((DAT_1c250eda & 4) != 0)))) {
      _DAT_1c2505dc = 5;
      DAT_1c2506fc = 5;
      _DAT_1c25062c = 5;
      _DAT_1c25077c = 5;
      _DAT_1c25066c = 5;
      _DAT_1c2507bc = 5;
    }
  }
  else if (uVar6 != 0) {
    _DAT_1c2505dc = 7;
    DAT_1c2506fc = 7;
    _DAT_1c25062c = 7;
    _DAT_1c25077c = 7;
    _DAT_1c25066c = 7;
    _DAT_1c2507bc = 7;
    goto LAB_1c202cfb;
  }
  if (((DAT_1c250e64 & 0x1000000) != 0) && (uVar7 != 0)) {
    _DAT_1c2505dc = 7;
    DAT_1c2506fc = 7;
  }
  if (DAT_1c2505f0 == 3) {
    if (uVar7 != 0) {
      _DAT_1c2505dc = 5;
      DAT_1c2506fc = 5;
      _DAT_1c25062c = 7;
      _DAT_1c25077c = 7;
      _DAT_1c25066c = 7;
      _DAT_1c2507bc = 7;
      goto LAB_1c202e27;
    }
  }
  else if ((uVar7 != 0) && (DAT_1c250e7c == 3)) {
    _DAT_1c2505e0 = 5;
    DAT_1c250700 = 5;
    _DAT_1c250630 = 7;
    _DAT_1c250780 = 7;
    _DAT_1c250670 = 7;
    _DAT_1c2507c0 = 7;
    goto LAB_1c202e27;
  }
  if (DAT_1c250564 == 3) {
    _DAT_1c250630 = 3;
    _DAT_1c2505e0 = 2;
    _DAT_1c2505dc = 2;
    DAT_1c250700 = 2;
    DAT_1c2506fc = 2;
    _DAT_1c25062c = 3;
    _DAT_1c250780 = 3;
    _DAT_1c25077c = 3;
    _DAT_1c250670 = 3;
    _DAT_1c25066c = 3;
    _DAT_1c2507c0 = 3;
    _DAT_1c2507bc = 3;
  }
LAB_1c202e27:
  if (DAT_1c250810 == 0x3f) {
    DAT_1c2506f8 = 0x4b;
    _DAT_1c2505e0 = 6;
    DAT_1c250700 = 6;
  }
  if (DAT_1c250e7e == '?') {
    DAT_1c2506f8 = 0x19;
    DAT_1c250700 = 1;
    DAT_1c2506fc = 1;
  }
  if (DAT_1c255303 == '?') {
    _DAT_1c2505dc = 4;
    DAT_1c2506fc = 4;
  }
  if (DAT_1c250810 == 0x1d) {
    _DAT_1c2505e0 = 0xe;
    DAT_1c250700 = 0xe;
    _DAT_1c250630 = 0xe;
    _DAT_1c250780 = 0xe;
    _DAT_1c250670 = 0xe;
    _DAT_1c2507c0 = 0xe;
  }
  if (DAT_1c250e7e == '7') {
    _DAT_1c2505e0 = 3;
    DAT_1c250700 = 3;
    _DAT_1c250630 = 3;
    _DAT_1c250780 = 3;
    _DAT_1c250670 = 3;
    _DAT_1c2507c0 = 3;
  }
  if ((DAT_1c250e70 & 0x10002000) != 0) {
    if ((DAT_1c250e64 & 0x1000040) != 0) {
      _DAT_1c25066c = 5;
      _DAT_1c25062c = 5;
      _DAT_1c2505dc = 5;
    }
    if ((DAT_1c2552fc & 0x1000040) != 0) {
      _DAT_1c250670 = 5;
      _DAT_1c250630 = 5;
      _DAT_1c2505e0 = 5;
    }
  }
  return;
}


// ==== FUN_1c202fe0 @ 1c202fe0 size=35

void __cdecl FUN_1c202fe0(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x24);
  return;
}


// ==== FUN_1c203010 @ 1c203010 size=155

char __cdecl FUN_1c203010(int param_1)

{
  uint uVar1;
  
  if (*(ushort *)(param_1 + 0xc) == 0xff) {
    return '\t';
  }
  uVar1 = *(uint *)((uint)*(ushort *)(param_1 + 0xc) * 0x1a + 2 + *(int *)(param_1 + 4));
  if ((uVar1 & 0x10000000) != 0) {
    return '\0';
  }
  if ((uVar1 & 0x2000) != 0) {
    return '\x01';
  }
  if ((uVar1 & 0x8000) != 0) {
    return '\x02';
  }
  if ((uVar1 & 0x40) != 0) {
    return (-((uVar1 & 0x8000000) == 0) & 2U) + 3;
  }
  if ((uVar1 & 0x40000) != 0) {
    return (-((uVar1 & 0x8000000) == 0) & 2U) + 4;
  }
  if ((uVar1 & 4) != 0) {
    return '\a';
  }
  if ((uVar1 & 0x20000000) != 0) {
    return '\t';
  }
  return ((uVar1 & 0x100) == 0) + '\b';
}


// ==== FUN_1c2030b0 @ 1c2030b0 size=1663

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1c2030b0(int param_1)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  uint uVar4;
  
  FUN_1c202fe0(0x1c2508b0);
  FUN_1c202fe0(0x1c2507d0);
  iVar1 = ((uint)DAT_1c250e7c + (uint)DAT_1c250564 * 10) * 10;
  DAT_1c2508d8 = (uint)(byte)(&DAT_1c24c460)[iVar1];
  iVar2 = ((uint)DAT_1c250564 + (uint)DAT_1c2505f0 * 10) * 10;
  _DAT_1c2508dc = (uint)(byte)(&DAT_1c24c463)[iVar2];
  _DAT_1c2508e0 = (uint)(byte)(&DAT_1c24c466)[iVar1];
  if (DAT_1c255303 == '?') {
    _DAT_1c2508dc = 1;
  }
  if (DAT_1c250e7e == '?') {
    _DAT_1c2508e0 = 1;
    _DAT_1c2508dc = 1;
  }
  if (DAT_1c250810 == 0x3f) {
    _DAT_1c2508e0 = 1;
  }
  _DAT_1c2508e8 = 0;
  _DAT_1c2508ec = 0x4b;
  DAT_1c2507f8 = (uint)(byte)(&DAT_1c24c461)[iVar1];
  _DAT_1c2507fc = (uint)(byte)(&DAT_1c24c464)[iVar2];
  _DAT_1c250800 = (uint)(byte)(&DAT_1c24c467)[iVar1];
  DAT_1c2508c8 = (uint)*(byte *)(*(int *)(*(int *)(param_1 + 0x2c) + 4) + 0x16 +
                                (uint)DAT_1c250810 * 0x1a);
  if (((DAT_1c250810 == 0x1c) || (DAT_1c250810 == 0x1b)) && ((DAT_1c250e70 & 0x8000000) == 0)) {
    DAT_1c2508c8 = 0;
  }
  uVar4 = DAT_1c250e70 & 0x10000000;
  if (((uVar4 != 0) && ((DAT_1c2552fc & 0x8000000) != 0)) &&
     (((DAT_1c2552fc & 0x40) != 0 && ((DAT_1c250e5c & 0x10000000) != 0)))) {
    DAT_1c2508c8 = DAT_1c2508c8 + 6;
  }
  DAT_1c2508cc = DAT_1c2508c8;
  if (((DAT_1c2552fc & 0x8000000) != 0) && ((DAT_1c250e5c & 0x8000000) == 0)) {
    DAT_1c2508cc = DAT_1c2508c8 - 3;
  }
  DAT_1c2507e8 = 0;
  DAT_1c2508c8 = (uint)(byte)(&DAT_1c2065be)[DAT_1c2508c8];
  DAT_1c2508cc = (uint)(byte)(&DAT_1c2065be)[DAT_1c2508cc];
  if ((DAT_1c2552fc & 0x44) != 0) {
    switch((uint)DAT_1c250810) {
    case 0x35:
      DAT_1c2507e8 = 0x2f;
      break;
    case 0x41:
      DAT_1c2507e8 = 0x21;
      break;
    case 0x42:
      DAT_1c2507e8 = 0x20;
      break;
    case 0x43:
      DAT_1c2507e8 = 0x24;
      break;
    case 0x44:
      DAT_1c2507e8 = 0x21;
      break;
    case 0x4b:
    case 0x4c:
      DAT_1c2507e8 = 0x2b;
    }
  }
  DAT_1c2507e8 = (uint)(byte)(&DAT_1c2065c8)[DAT_1c2507e8];
  if ((((DAT_1c250e64 & 0x8000000) == 0) && ((DAT_1c250e64 & 0x40040) != 0)) &&
     (((DAT_1c250e70 & 0x10002000) != 0 || (DAT_1c250e7e == '\x1c')))) {
    DAT_1c250e6e = 5;
    DAT_1c250e52 = 0x2e;
    if (DAT_1c250e68 == '\0') {
      DAT_1c250e6e = 2;
      DAT_1c250e52 = 0x28;
    }
    if (uVar4 == 0) {
      if (((DAT_1c250e70 & 0x800) == 0) && ((DAT_1c250e64 & 0x400) == 0)) {
        DAT_1c250e6e = 7;
      }
      else {
        DAT_1c250e6e = 6;
      }
    }
    if (((DAT_1c250edb & 8) != 0) && (DAT_1c250e74 == '\0')) {
      DAT_1c250e6e = DAT_1c250e6e - 1;
    }
    if ((DAT_1c250e64 & 1) != 0) {
      DAT_1c250e6e = DAT_1c250e6e - 3;
    }
    if ((DAT_1c250e7e == '\x1c') || (DAT_1c250e7e == '\x1b')) {
      DAT_1c250e6e = 8;
      DAT_1c250e52 = DAT_1c250e52 + -3;
    }
    if ((((DAT_1c250e64 & 0x40000) == 0) || (DAT_1c255301 != 'A')) || ((DAT_1c2552f0 & 0x80) != 0))
    {
      if ((DAT_1c250e64 & 0x40) != 0) {
        if (uVar4 == 0) {
          DAT_1c250e6e = DAT_1c250566 >> 1;
        }
        else {
          DAT_1c250e6e = 1;
        }
      }
    }
    else {
      DAT_1c250e6e = 0;
    }
    uVar3 = DAT_1c250566;
    if ((short)DAT_1c250e6e <= (short)DAT_1c250566) {
      uVar3 = DAT_1c250e6e;
    }
    if (((DAT_1c250e70 & 0x80000) != 0) && ((DAT_1c250e64 & 2) != 0)) {
      if (DAT_1c250e7e == '6') {
        DAT_1c250e52 = DAT_1c250e52 + 6;
      }
      else {
        DAT_1c250e52 = DAT_1c250e52 + 1;
      }
    }
    DAT_1c250e6e = uVar3;
    if ((((*(short *)(param_1 + 0x52) == 0) || (*(short *)(param_1 + 0x52) == 3)) &&
        (((DAT_1c250e64 & 0x400) == 0 && ((DAT_1c250e70 & 0x10002000) != 0)))) &&
       ((DAT_1c250e6e = uVar3 + 2, DAT_1c250e74 != '\0' || (((byte)DAT_1c250e78 & 4) != 0)))) {
      DAT_1c250e6e = uVar3 + 4;
    }
    if (*(short *)(param_1 + 0x4c) == 3) {
      DAT_1c250e6e = (short)DAT_1c250e6e >> 1;
    }
    if (0 < (short)DAT_1c250e6e) {
      _DAT_1c2507d8 = (uint)(byte)(&DAT_1c2065c8)[DAT_1c250e52];
      if ((DAT_1c250e64 & 0x40) != 0) {
        _DAT_1c2507d8 = DAT_1c2507e4;
      }
      _DAT_1c2507fc = 2;
      DAT_1c2507dc = 0;
      _DAT_1c250808 = 0;
      DAT_1c25080c = ((short)DAT_1c250e6e * 100 + 0x32U) / (uint)DAT_1c250566;
      if (99 < DAT_1c25080c) {
        DAT_1c25080c = 100;
      }
      _DAT_1c250608 = _DAT_1c250608 + 100;
      if ((DAT_1c250e64 & 0x40000) != 0) {
        if ((DAT_1c250e64 & 0x4000000) != 0) {
          _DAT_1c250660 = _DAT_1c250660 + 0x96;
        }
        _DAT_1c2507fc = 0;
        _DAT_1c2508b8 = 0;
        _DAT_1c25062c = 0;
        _DAT_1c2505dc = 0;
        _DAT_1c2508dc = 0;
        _DAT_1c2505e8 = DAT_1c25080c + (int)(-400 / (longlong)(int)(short)DAT_1c250566);
        _DAT_1c2505ec = DAT_1c25080c;
        _DAT_1c250638 = _DAT_1c2505e8;
        _DAT_1c25063c = DAT_1c25080c;
        _DAT_1c2508e8 = _DAT_1c2505e8;
        _DAT_1c2508ec = DAT_1c25080c;
        if (_DAT_1c2505e8 < 1) {
          _DAT_1c2505e8 = 0;
          _DAT_1c250638 = _DAT_1c2505e8;
          _DAT_1c2508e8 = _DAT_1c2505e8;
        }
      }
    }
  }
  DAT_1c2508d4 = DAT_1c2508bc + (int)((DAT_1c2508c8 - DAT_1c2508bc) * DAT_1c2508d8) / 100;
  _DAT_1c2507f4 = DAT_1c2507dc + (int)((DAT_1c2507e8 - DAT_1c2507dc) * DAT_1c2507f8) / 100;
  if (DAT_1c2508c8 == 0) {
    DAT_1c2508c8 = 0;
  }
  if (DAT_1c2508cc == 0) {
    DAT_1c2508cc = 0;
  }
  if (DAT_1c2508d4 < 1) {
    DAT_1c2508d4 = 0;
  }
  _DAT_1c2507ec = DAT_1c2507e8;
  FUN_1c202fe0(0x1c250870);
  FUN_1c202fe0(0x1c250a10);
  DAT_1c250a28 = 0xc;
  if ((DAT_1c2552fc & 0x8000000) == 0) {
    DAT_1c250a28 = 8;
  }
  if (DAT_1c255300 != '\0') {
    DAT_1c250a28 = DAT_1c250a28 + 2;
  }
  if (((DAT_1c250554 & 4) != 0) && (DAT_1c255300 == '\0')) {
    DAT_1c250a28 = DAT_1c250a28 + -2;
  }
  if ((DAT_1c2552fc & 0x1000000) != 0) {
    DAT_1c250a28 = DAT_1c250a28 + -5;
  }
  if (DAT_1c250810 == 1) {
    DAT_1c2505bc = DAT_1c2505bc + 0x32;
  }
  DAT_1c250a28 = DAT_1c250a28 * 0x100;
  _DAT_1c250a40 = 3;
  _DAT_1c250a3c = 3;
  _DAT_1c250a2c = DAT_1c250a28;
  _DAT_1c250894 = DAT_1c25087c + ((DAT_1c250888 - DAT_1c25087c) * DAT_1c250898) / 100;
  _DAT_1c250a38 = 0x32;
  _DAT_1c250a34 = DAT_1c250a1c + ((DAT_1c250a28 - DAT_1c250a1c) * 0x32) / 100;
  return;
}


// ==== FUN_1c203770 @ 1c203770 size=246

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1c203770(void)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  ushort uVar6;
  
  if ((DAT_1c250e70 & 0x10) != 0) {
    sVar3 = 0;
    do {
      if ((&DAT_1c24c420)[sVar3 * 3] == DAT_1c250e7e) break;
      sVar3 = sVar3 + 1;
    } while (sVar3 < 0x15);
    bVar1 = *(byte *)(sVar3 * 3 + 0x1c24c421);
    uVar4 = (ushort)bVar1;
    bVar2 = *(byte *)(sVar3 * 3 + 0x1c24c422);
    uVar6 = (ushort)bVar2;
    if (((DAT_1c250e70 & 0xc0000000) != 0) && ((DAT_1c2552fc._1_1_ & 0x20) != 0)) {
      uVar4 = bVar1 - 10;
      uVar6 = bVar2 - 0xf;
    }
    if (0x5e < (short)uVar4) {
      uVar4 = 0x5f;
    }
    if ((short)uVar4 < 1) {
      uVar4 = 0;
    }
    _DAT_1c250638 = (int)(short)uVar4;
    if (99 < (short)uVar6) {
      uVar6 = 100;
    }
    iVar5 = (int)(short)uVar6;
    if ((int)(short)uVar6 <= _DAT_1c250638 + 5) {
      iVar5 = _DAT_1c250638 + 5;
    }
    _DAT_1c25063c = (int)(short)iVar5;
    _DAT_1c2505e8 = _DAT_1c250638;
    _DAT_1c2505ec = _DAT_1c25063c;
    _DAT_1c250678 = _DAT_1c250638;
    _DAT_1c25067c = _DAT_1c25063c;
    DAT_1c250708 = _DAT_1c250638;
    DAT_1c25070c = _DAT_1c25063c;
    _DAT_1c250788 = _DAT_1c250638;
    _DAT_1c25078c = _DAT_1c25063c;
    _DAT_1c2507c8 = _DAT_1c250638;
    _DAT_1c2507cc = _DAT_1c25063c;
    if (DAT_1c250e7e == '#') {
      _DAT_1c2505e8 = 0x32;
      DAT_1c250708 = 0x32;
      _DAT_1c2505ec = 0x5f;
      DAT_1c25070c = 0x5f;
    }
  }
  return;
}


// ==== FUN_1c203870 @ 1c203870 size=440

void __cdecl FUN_1c203870(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  short *psVar6;
  uint uVar7;
  short *psVar8;
  int iVar9;
  int iVar10;
  undefined2 *puVar11;
  short *psVar12;
  
  uVar7 = (int)(*(int *)(param_1 + 0x38) * (uint)DAT_1c250566) / 100 + 1;
  iVar3 = (int)(*(int *)(param_1 + 0x3c) * (uint)DAT_1c250566 + 0x32) / 100 - uVar7;
  if (iVar3 < 2) {
    iVar3 = 1;
  }
  iVar3 = (int)(0x8000 / (longlong)iVar3);
  iVar9 = 0x8000 - iVar3;
  puVar4 = &DAT_1c250a50;
  if (0 < (int)uVar7) {
    puVar4 = &DAT_1c250a50;
    for (uVar5 = uVar7 >> 1; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar4 = 0x1000100;
      puVar4 = puVar4 + 1;
    }
    for (uVar5 = (uint)((uVar7 & 1) != 0); uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined2 *)puVar4 = 0x100;
      puVar4 = (undefined4 *)((int)puVar4 + 2);
    }
    puVar4 = (undefined4 *)((int)&DAT_1c250a50 + uVar7 * 2);
  }
  if ((int)uVar7 < (int)(uint)DAT_1c250566) {
    do {
      if (iVar9 < 0) {
        iVar9 = 0;
      }
      iVar1 = iVar9 >> 7;
      iVar9 = iVar9 - iVar3;
      *(short *)puVar4 = (short)iVar1;
      uVar7 = uVar7 + 1;
      puVar4 = (undefined4 *)((int)puVar4 + 2);
    } while ((int)uVar7 < (int)(uint)DAT_1c250566);
  }
  *(undefined2 *)(&DAT_1c250a4e + (uint)DAT_1c250566 * 2) = 0;
  iVar3 = *(int *)(param_1 + 0x34);
  if (7 < iVar3) {
    iVar3 = 8;
  }
  if (iVar3 < 1) {
    iVar3 = 0;
  }
  iVar9 = *(int *)(param_1 + 0x20);
  iVar1 = *(int *)(param_1 + 8);
  iVar10 = *(int *)(&DAT_1c24c1b0 + (*(int *)(param_1 + 0x2c) + iVar3 * 0x10) * 4);
  iVar2 = 0;
  psVar6 = (short *)&DAT_1c250a50;
  puVar11 = &DAT_1c250150;
  if (DAT_1c250566 != 0) {
    do {
      iVar2 = iVar2 + 1;
      iVar9 = iVar9 + ((iVar1 - iVar9) * iVar10 >> 8);
      *puVar11 = (short)((uint)(*psVar6 * iVar9) >> 8);
      psVar6 = psVar6 + 1;
      puVar11 = puVar11 + 1;
    } while (iVar2 < (int)(uint)DAT_1c250566);
  }
  iVar9 = (uint)DAT_1c250566 * 2;
  iVar1 = *(int *)(param_1 + 0xc);
  iVar10 = *(int *)(param_1 + 0x24);
  iVar3 = *(int *)(&DAT_1c24c1b0 + (*(int *)(param_1 + 0x30) + iVar3 * 0x10) * 4);
  iVar2 = 0;
  psVar6 = (short *)(*(int *)(param_1 + 4) + iVar9 + -2);
  psVar8 = (short *)(&DAT_1c250a4e + iVar9);
  psVar12 = (short *)(&DAT_1c25014e + (uint)DAT_1c250566 * 2);
  if (DAT_1c250566 != 0) {
    do {
      iVar2 = iVar2 + 1;
      *psVar6 = (short)((uint)((0x100 - *psVar8) * iVar10) >> 8) + *psVar12;
      iVar10 = iVar10 + ((iVar1 - iVar10) * iVar3 >> 8);
      psVar6 = psVar6 + -1;
      psVar8 = psVar8 + -1;
      psVar12 = psVar12 + -1;
    } while (iVar2 < (int)(uint)DAT_1c250566);
  }
  return;
}


// ==== FUN_1c203a30 @ 1c203a30 size=119

void FUN_1c203a30(void)

{
  short sVar1;
  short *psVar2;
  
  if ((0 < DAT_1c25058c) && (0 < DAT_1c25055c)) {
    sVar1 = 0;
    psVar2 = (short *)((uint)DAT_1c250566 * 2 + DAT_1c250714);
    if (0 < DAT_1c25058c) {
      do {
        psVar2 = psVar2 + -1;
        sVar1 = sVar1 + 1;
        *psVar2 = DAT_1c25055c;
      } while (sVar1 < DAT_1c25058c);
    }
    if (((byte)DAT_1c250e70 & 1) != 0) {
      *psVar2 = *psVar2 + -8;
      psVar2[1] = psVar2[1] + -4;
      psVar2 = (short *)(DAT_1c250714 + -2 + (uint)DAT_1c250566 * 2);
      *psVar2 = *psVar2 + -8;
      psVar2[-1] = psVar2[-1] + -4;
    }
  }
  return;
}


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


// ==== FUN_1c204030 @ 1c204030 size=418

void __cdecl FUN_1c204030(int param_1,int param_2,undefined4 *param_3)

{
  undefined2 uVar1;
  int iVar2;
  short sVar3;
  ushort uVar4;
  short *psVar5;
  
  psVar5 = (short *)*param_3;
  if (psVar5 != (short *)0x0) {
    sVar3 = *psVar5;
    while (sVar3 != 0x1e) {
      switch(*psVar5) {
      case 0x32:
        FUN_1c204680();
        break;
      case 0x8c:
        *(short *)(param_1 + 0xae) = psVar5[1];
        break;
      case 0xb4:
        sVar3 = psVar5[1];
        if (sVar3 < 1) {
          sVar3 = (*(short *)(param_1 + 0xac) * 0xc + *(short *)(param_1 + 0xae)) - sVar3;
          if (0x54 < sVar3) {
            sVar3 = sVar3 + ((ushort)(sVar3 - 0x49U) / 0xc) * -0xc;
          }
          if (sVar3 < 0) {
            sVar3 = sVar3 + ((ushort)(0xbU - sVar3) / 0xc) * 0xc;
          }
          sVar3 = *(short *)(&DAT_1c24c028 + sVar3 * 2);
        }
        else {
          if (1999 < sVar3) {
            sVar3 = 2000;
          }
          if (sVar3 < 0xb) {
            sVar3 = 10;
          }
        }
        uVar4 = psVar5[2];
        iVar2 = (short)uVar4 * 0x20 + param_2;
        if (uVar4 < DAT_1c250566) {
          do {
            *(short *)(iVar2 + 0x18) = sVar3;
            iVar2 = iVar2 + 0x20;
            uVar4 = uVar4 + 1;
          } while (uVar4 < DAT_1c250566);
        }
        break;
      case 0xf0:
        *(short *)(param_1 + 0x4c) = psVar5[1];
        break;
      case 0xfa:
        *(short *)(param_1 + 0x60) = psVar5[1];
      }
      psVar5 = psVar5 + 3;
      sVar3 = *psVar5;
    }
  }
  if ((((byte)DAT_1c250e78 & 0x80) != 0) || ((DAT_1c250e70._3_1_ & 0x20) != 0)) {
    uVar1 = DAT_1c250560;
    if (((DAT_1c250e70._3_1_ & 0x20) == 0) && (DAT_1c250e7e != 0x1c)) {
      uVar1 = (short)((int)((int)*(short *)(&DAT_1c24c1a0 +
                                           ((uint)DAT_1c250e7e + (uint)*(ushort *)(param_1 + 0x46) &
                                           7) * 2) * (uint)*(ushort *)(param_1 + 0x46)) / 0x6e);
    }
    *(undefined2 *)(param_2 + -8) = DAT_1c250560;
    *(undefined2 *)(param_2 + 0x18) = uVar1;
    DAT_1c250560 = uVar1;
  }
  return;
}


// ==== FUN_1c2042c0 @ 1c2042c0 size=346

void __cdecl FUN_1c2042c0(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  ushort uVar2;
  short *psVar3;
  short sVar4;
  
  sVar4 = DAT_1c250560;
  uVar2 = 0;
  iVar1 = param_2;
  if (DAT_1c250566 != 0) {
    do {
      *(short *)(iVar1 + 0x18) = sVar4;
      iVar1 = iVar1 + 0x20;
      uVar2 = uVar2 + 1;
    } while (uVar2 < DAT_1c250566);
  }
  psVar3 = (short *)*param_3;
  if (psVar3 != (short *)0x0) {
    sVar4 = *psVar3;
    while (sVar4 != 0x1e) {
      switch(*psVar3) {
      case 0x32:
        FUN_1c204680();
        break;
      case 0x8c:
        *(short *)(param_1 + 0xae) = psVar3[1];
        break;
      case 0xb4:
        DAT_1c250560 = psVar3[1];
        if (DAT_1c250560 < 1) {
          sVar4 = (*(short *)(param_1 + 0xac) * 0xc + *(short *)(param_1 + 0xae)) - DAT_1c250560;
          if (0x54 < sVar4) {
            sVar4 = sVar4 + ((ushort)(sVar4 - 0x49U) / 0xc) * -0xc;
          }
          if (sVar4 < 0) {
            sVar4 = sVar4 + ((ushort)(0xbU - sVar4) / 0xc) * 0xc;
          }
          DAT_1c250560 = *(short *)(&DAT_1c24c028 + sVar4 * 2);
        }
        else {
          if (1999 < DAT_1c250560) {
            DAT_1c250560 = 2000;
          }
          if (DAT_1c250560 < 0xb) {
            DAT_1c250560 = 10;
          }
        }
        uVar2 = psVar3[2];
        iVar1 = (short)uVar2 * 0x20 + param_2;
        if (uVar2 < DAT_1c250566) {
          do {
            *(short *)(iVar1 + 0x18) = DAT_1c250560;
            iVar1 = iVar1 + 0x20;
            uVar2 = uVar2 + 1;
          } while (uVar2 < DAT_1c250566);
        }
        break;
      case 0xf0:
        *(short *)(param_1 + 0x4c) = psVar3[1];
        break;
      case 0xfa:
        *(short *)(param_1 + 0x60) = psVar3[1];
      }
      psVar3 = psVar3 + 3;
      sVar4 = *psVar3;
    }
  }
  return;
}


// ==== FUN_1c204500 @ 1c204500 size=70

void __cdecl FUN_1c204500(int param_1,int param_2,int param_3)

{
  if (0x6e < param_3) {
    param_3 = (int)((uint)*(ushort *)(param_1 + 0x60) * (param_3 + -0x6e)) / 100 + 0x6e;
  }
  *(short *)(param_2 + 0x18) = (short)((int)((uint)*(ushort *)(param_1 + 0x46) * param_3) / 0x6e);
  return;
}


// ==== FUN_1c204550 @ 1c204550 size=86

void __cdecl FUN_1c204550(int param_1,int param_2,int param_3)

{
  if (0x6e < param_3) {
    param_3 = (int)((uint)*(ushort *)(param_1 + 0x60) * (param_3 + -0x6e)) / 100 + 0x6e;
  }
  *(short *)((DAT_1c250566 & 0xfffffffe) * 0x10 + 0x18 + param_2) =
       (short)((int)((uint)*(ushort *)(param_1 + 0x46) * param_3) / 0x6e);
  return;
}


// ==== FUN_1c2045b0 @ 1c2045b0 size=83

void __cdecl FUN_1c2045b0(int param_1,int param_2,int param_3)

{
  if (0x6e < param_3) {
    param_3 = (int)((uint)*(ushort *)(param_1 + 0x60) * (param_3 + -0x6e)) / 100 + 0x6e;
  }
  *(short *)((uint)DAT_1c250566 * 0x20 + -8 + param_2) =
       (short)((int)((uint)*(ushort *)(param_1 + 0x46) * param_3) / 0x6e);
  return;
}


// ==== FUN_1c204610 @ 1c204610 size=100

void __cdecl FUN_1c204610(int param_1,int param_2,int param_3)

{
  if (0x6e < param_3) {
    param_3 = (int)((uint)*(ushort *)(param_1 + 0x60) * (param_3 + -0x6e)) / 100 + 0x6e;
  }
  *(short *)((DAT_1c250e60 & 0xfffffffe) * 0x10 + (uint)DAT_1c250566 * 0x20 + 0x18 + param_2) =
       (short)((int)((uint)*(ushort *)(param_1 + 0x46) * param_3) / 0x6e);
  return;
}


// ==== FUN_1c204680 @ 1c204680 size=1

void FUN_1c204680(void)

{
  return;
}


// ==== FUN_1c204690 @ 1c204690 size=6441

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1c204690(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  char cVar3;
  char cVar4;
  ushort uVar5;
  short sVar6;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  short *psVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  byte bVar12;
  ushort uVar13;
  uint uVar14;
  short *psVar15;
  int iVar16;
  short *psVar17;
  ushort *puVar18;
  int iVar19;
  short *psVar20;
  int iVar21;
  ushort *puVar22;
  int iVar23;
  bool bVar24;
  undefined1 local_47;
  short local_46;
  short local_44;
  ushort local_42;
  short sStack_40;
  short sStack_3e;
  int local_3c;
  int local_34;
  int local_30;
  int local_28;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  cVar3 = '\0';
  if (*(short *)(*(int *)(param_1 + 0x28) + 0xc) == 0xff) {
    DAT_1c24c154 = 1;
    return 0;
  }
  DAT_1c250e58 = *(undefined1 **)(param_1 + 0xfa);
  if (DAT_1c24c154 != 0) {
    DAT_1c250e90 = &DAT_1c250690;
    DAT_1c250e94 = &DAT_1c2506d0;
    _DAT_1c250e98 = &DAT_1c250750;
    _DAT_1c250e9c = &DAT_1c250790;
    _DAT_1c250ea0 = &DAT_1c2505b0;
    _DAT_1c250ea4 = &DAT_1c250600;
    _DAT_1c250ea8 = &DAT_1c250640;
    _DAT_1c250eac = &DAT_1c2508b0;
    _DAT_1c250eb0 = &DAT_1c250710;
    _DAT_1c250eb4 = &DAT_1c2507d0;
    _DAT_1c250eb8 = &DAT_1c250820;
    _DAT_1c250ebc = &DAT_1c2508f0;
    _DAT_1c250ec0 = &DAT_1c250930;
    _DAT_1c250ec4 = &DAT_1c250a10;
    _DAT_1c250ec8 = &DAT_1c250870;
    _DAT_1c250ecc = &DAT_1c250970;
    _DAT_1c250ed0 = &DAT_1c2509c0;
    _DAT_1c250574 = &DAT_1c250ef0;
    DAT_1c250694 = &DAT_1c250ef0;
    DAT_1c25057c = &DAT_1c2512f0;
    DAT_1c2506d4 = &DAT_1c2512f0;
    DAT_1c250580 = (short *)&DAT_1c2516f0;
    DAT_1c250754 = (short *)&DAT_1c2516f0;
    DAT_1c250588 = (short *)&DAT_1c251af0;
    DAT_1c250794 = (short *)&DAT_1c251af0;
    DAT_1c250568 = &DAT_1c251ef0;
    DAT_1c2505b4 = &DAT_1c251ef0;
    DAT_1c25056c = &DAT_1c2522f0;
    DAT_1c250604 = &DAT_1c2522f0;
    DAT_1c250570 = (short *)&DAT_1c2526f0;
    DAT_1c250644 = (short *)&DAT_1c2526f0;
    DAT_1c250598 = &DAT_1c252af0;
    DAT_1c2508b4 = &DAT_1c252af0;
    DAT_1c250578 = &DAT_1c252ef0;
    DAT_1c250714 = &DAT_1c252ef0;
    DAT_1c250584 = &DAT_1c2532f0;
    DAT_1c2507d4 = &DAT_1c2532f0;
    DAT_1c250590 = &DAT_1c2536f0;
    DAT_1c250824 = &DAT_1c2536f0;
    DAT_1c25059c = &DAT_1c253af0;
    DAT_1c2508f4 = &DAT_1c253af0;
    DAT_1c2505a0 = &DAT_1c253ef0;
    DAT_1c250934 = &DAT_1c253ef0;
    DAT_1c250864 = &DAT_1c2542f0;
    DAT_1c250a14 = &DAT_1c2542f0;
    _DAT_1c250594 = &DAT_1c2546f0;
    DAT_1c250874 = &DAT_1c2546f0;
    _DAT_1c2505a4 = &DAT_1c254af0;
    DAT_1c250974 = &DAT_1c254af0;
    _DAT_1c250e50 = 0;
    DAT_1c250e6a = 0;
    _DAT_1c250680 = &DAT_1c254ef0;
    DAT_1c2509c4 = &DAT_1c254ef0;
    DAT_1c250148 = 0;
    DAT_1c2552f4 = 0;
    DAT_1c250e84 = 0x6e;
    DAT_1c250e80 = 0x6e;
    DAT_1c250a00 = 0x6e;
    _DAT_1c250ee0 = 0;
    DAT_1c250698 = 100;
    _DAT_1c250878 = 0;
    DAT_1c2506d8 = 400;
    _DAT_1c2505b8 = 100;
    _DAT_1c250a18 = 0xf;
    DAT_1c250758 = 0x578;
    _DAT_1c250608 = 100;
    _DAT_1c250938 = 400;
    _DAT_1c2508b8 = 0;
    _DAT_1c2507d8 = 0;
    _DAT_1c250718 = 0;
    _DAT_1c250828 = 0;
    _DAT_1c250978 = 0;
    _DAT_1c2509c8 = 0;
    DAT_1c250798 = 0x960;
    _DAT_1c250648 = 200;
    _DAT_1c2508f8 = 3000;
    local_1c = (int)*(short *)(param_1 + 0x98);
    local_18 = (int)*(short *)(param_1 + 0x9c);
    local_14 = (int)*(short *)(param_1 + 0x9a);
    local_10 = (int)*(short *)(param_1 + 0x9e);
    *(undefined2 *)(DAT_1c250e58 + 0x18) = *(undefined2 *)(param_1 + 0x46);
    DAT_1c250560 = *(undefined2 *)(DAT_1c250e58 + 0x18);
    *(undefined2 *)
     (DAT_1c250e58 + ((int)(*(ushort *)(*(int *)(param_1 + 0x28) + 0xe) + 4) >> 3) * 0x20 + 0x18) =
         DAT_1c250560;
    uVar14 = 0;
    do {
      uVar13 = (short)uVar14 + 1;
      puVar1 = (&DAT_1c250e90)[uVar14];
      uVar2 = puVar1[2];
      puVar1[5] = uVar2;
      puVar1[4] = uVar2;
      puVar1[3] = uVar2;
      uVar2 = puVar1[2];
      puVar1[9] = uVar2;
      puVar1[8] = uVar2;
      puVar1[7] = uVar2;
      puVar1[6] = uVar2;
      *puVar1 = (&PTR_DAT_1c24c158)[uVar14];
      uVar14 = (uint)uVar13;
    } while (uVar13 < 0x11);
    DAT_1c250e69 = '\x01';
    DAT_1c24c154 = 0;
  }
  iVar11 = *(int *)(param_1 + 0x20);
  DAT_1c255301 = *(undefined1 *)(iVar11 + 0xc);
  _DAT_1c250ed8 = *(undefined4 *)(iVar11 + 0x12);
  DAT_1c250edc = (byte)*(undefined4 *)(iVar11 + 0x16) & 0x10;
  DAT_1c250550 = *(undefined1 *)(iVar11 + 0x10);
  _DAT_1c2552f8 = *(undefined4 *)(iVar11 + 0x16);
  _DAT_1c2509b2 = (undefined2)((int)(*(ushort *)(iVar11 + 0xe) + 4) >> 3);
  cVar4 = FUN_1c203010(iVar11);
  _DAT_1c2509b0 = (undefined2)CONCAT31(extraout_var,cVar4);
  iVar11 = *(int *)(param_1 + 0x24);
  DAT_1c255303 = *(undefined1 *)(iVar11 + 0xc);
  DAT_1c250e64 = *(uint *)(iVar11 + 0x12);
  DAT_1c250e68 = (byte)*(undefined4 *)(iVar11 + 0x16) & 0x10;
  DAT_1c255302 = *(undefined1 *)(iVar11 + 0x10);
  _DAT_1c2552f0 = *(undefined4 *)(iVar11 + 0x16);
  _DAT_1c250558 = (undefined2)((int)(*(ushort *)(iVar11 + 0xe) + 4) >> 3);
  cVar4 = FUN_1c203010(iVar11);
  DAT_1c2505f0 = (undefined2)CONCAT31(extraout_var_00,cVar4);
  puVar1 = *(undefined4 **)(param_1 + 0x28);
  DAT_1c250e7e = *(byte *)(puVar1 + 3);
  DAT_1c250e70 = *(uint *)((int)puVar1 + 0x12);
  DAT_1c250e74 = (byte)*(undefined4 *)((int)puVar1 + 0x16) & 0x10;
  DAT_1c250ed4 = *(undefined1 *)(puVar1 + 4);
  DAT_1c250e78 = *(undefined4 *)((int)puVar1 + 0x16);
  DAT_1c250566 = (ushort)((int)(*(ushort *)((int)puVar1 + 0xe) + 4) >> 3);
  cVar4 = FUN_1c203010((int)puVar1);
  DAT_1c250564 = (undefined2)CONCAT31(extraout_var_01,cVar4);
  iVar11 = *(int *)(param_1 + 0x2c);
  DAT_1c250810 = *(char *)(iVar11 + 0xc);
  if (DAT_1c250810 == -1) {
    DAT_1c250810 = '\x1b';
  }
  DAT_1c2552fc = *(undefined4 *)(iVar11 + 0x12);
  DAT_1c255300 = (byte)*(undefined4 *)(iVar11 + 0x16) & 0x10;
  DAT_1c25055e = *(undefined1 *)(iVar11 + 0x10);
  _DAT_1c250554 = *(undefined4 *)(iVar11 + 0x16);
  DAT_1c250e60 = (undefined2)((int)(*(ushort *)(iVar11 + 0xe) + 4) >> 3);
  cVar4 = FUN_1c203010(iVar11);
  DAT_1c250e7c = (undefined2)CONCAT31(extraout_var_02,cVar4);
  iVar11 = *(int *)(param_1 + 0x30);
  DAT_1c2509b4 = *(char *)(iVar11 + 0xc);
  if (DAT_1c2509b4 == -1) {
    DAT_1c2509b4 = '\x1b';
  }
  DAT_1c250e5c = *(undefined4 *)(iVar11 + 0x12);
  DAT_1c250e62 = (byte)*(undefined4 *)(iVar11 + 0x16) & 0x10;
  DAT_1c250e6c = *(undefined1 *)(iVar11 + 0x10);
  _DAT_1c250e54 = *(undefined4 *)(iVar11 + 0x16);
  _DAT_1c250146 = (undefined2)((int)(*(ushort *)(iVar11 + 0xe) + 4) >> 3);
  cVar4 = FUN_1c203010(iVar11);
  _DAT_1c250860 = (undefined2)CONCAT31(extraout_var_03,cVar4);
  DAT_1c250e63 = DAT_1c250e69;
  uVar14 = 0;
  do {
    uVar13 = (short)uVar14 + 1;
    iVar23 = (int)(&DAT_1c250e90)[uVar14];
    *(undefined4 *)(iVar23 + 0x28) = 0x32;
    *(undefined4 *)(iVar23 + 0x38) = 0x19;
    *(undefined4 *)(iVar23 + 0x3c) = 0x4b;
    *(undefined4 *)(iVar23 + 0x2c) = 7;
    *(undefined4 *)(iVar23 + 0x30) = 7;
    *(undefined4 *)(iVar23 + 0x34) = 3;
    uVar14 = (uint)uVar13;
  } while (uVar13 < 0x11);
  _DAT_1c250e88 = DAT_1c25058c;
  FUN_1c201b80((int)puVar1);
  FUN_1c2030b0(param_1);
  FUN_1c249310((int)puVar1);
  _DAT_1c2505e4 = (int)(short)(*(short *)(param_1 + 0x5e) + 3);
  _DAT_1c2508e4 = *(short *)(param_1 + 0x7e) + 3;
  _DAT_1c250804 = *(short *)(param_1 + 0x80) + 3;
  _DAT_1c250744 = *(short *)(param_1 + 0x82) + 3;
  uVar14 = 0;
  _DAT_1c250634 = _DAT_1c2505e4;
  _DAT_1c250674 = _DAT_1c2505e4;
  DAT_1c250704 = _DAT_1c2505e4;
  _DAT_1c250784 = _DAT_1c2505e4;
  _DAT_1c2507c4 = _DAT_1c2505e4;
  _DAT_1c250854 = _DAT_1c250744;
  _DAT_1c250924 = _DAT_1c2505e4;
  _DAT_1c250964 = _DAT_1c2505e4;
  do {
    uVar13 = (short)uVar14 + 1;
    FUN_1c203870((int)(&DAT_1c250e90)[uVar14]);
    uVar14 = (uint)uVar13;
  } while (uVar13 < 0x11);
  uVar13 = 0;
  psVar7 = DAT_1c2507d4;
  puVar18 = DAT_1c250714;
  puVar22 = DAT_1c2508b4;
  if (DAT_1c250566 != 0) {
    do {
      uVar5 = *puVar22;
      if ((short)uVar5 < 1) {
        uVar5 = 0;
      }
      *puVar22 = (ushort)(byte)(&DAT_1c20660e)[(short)uVar5];
      sVar6 = *psVar7;
      if (sVar6 < 1) {
        sVar6 = 0;
      }
      *psVar7 = (byte)(&DAT_1c20660e)[sVar6] - 10;
      uVar5 = *puVar18;
      if ((short)uVar5 < 1) {
        uVar5 = 0;
      }
      uVar13 = uVar13 + 1;
      puVar22 = puVar22 + 1;
      psVar7 = psVar7 + 1;
      *puVar18 = (ushort)(byte)(&DAT_1c20660e)[(short)uVar5];
      puVar18 = puVar18 + 1;
    } while (uVar13 < DAT_1c250566);
  }
  FUN_1c203a30();
  if (((DAT_1c250e70 & 0x40000) != 0) && ((DAT_1c250e70 & 0x8000000) != 0)) {
    if (((DAT_1c250e64 & 0x8000000) == 0) ||
       (((DAT_1c250e64 & 0x800000) == 0 || (*(short *)(param_1 + 0x2f2) == 2)))) {
      local_3c = CONCAT22(local_3c._2_2_,0x3c);
    }
    else {
      local_3c = CONCAT22(local_3c._2_2_,5);
    }
    local_42 = 0;
    psVar7 = DAT_1c2506d4;
    psVar15 = DAT_1c2505b4;
    psVar17 = DAT_1c250604;
    puVar18 = DAT_1c2508b4;
    psVar20 = DAT_1c2507d4;
    if (DAT_1c250566 != 0) {
      do {
        *puVar18 = *puVar18 - (short)local_3c;
        *psVar20 = 0;
        if (*(short *)(param_1 + 0x52) == 1) {
          *psVar7 = 0xfa;
        }
        else {
          *psVar7 = 0x78;
        }
        *psVar15 = *psVar15 + 0x28;
        psVar7 = psVar7 + 1;
        *psVar17 = *psVar17 + 0xfa;
        psVar15 = psVar15 + 1;
        local_42 = local_42 + 1;
        psVar17 = psVar17 + 1;
        puVar18 = puVar18 + 1;
        psVar20 = psVar20 + 1;
      } while (local_42 < DAT_1c250566);
    }
  }
  bVar24 = (DAT_1c250e70 & 0x8000) == 0;
  if (bVar24) {
    bVar12 = 0;
  }
  else {
    bVar12 = 0x10;
  }
  _DAT_1c250574 = DAT_1c250694;
  DAT_1c25057c = DAT_1c2506d4;
  DAT_1c250580 = DAT_1c250754;
  DAT_1c250588 = DAT_1c250794;
  DAT_1c250568 = DAT_1c2505b4;
  DAT_1c25056c = DAT_1c250604;
  DAT_1c250570 = DAT_1c250644;
  DAT_1c25059c = DAT_1c2508f4;
  DAT_1c2505a0 = DAT_1c250934;
  DAT_1c250598 = DAT_1c2508b4;
  DAT_1c250584 = DAT_1c2507d4;
  DAT_1c250578 = DAT_1c250714;
  DAT_1c250590 = DAT_1c250824;
  _DAT_1c250594 = DAT_1c250874;
  DAT_1c250864 = DAT_1c250a14;
  _DAT_1c250680 = DAT_1c2509c4;
  _DAT_1c2505a4 = DAT_1c250974;
  local_42 = 0;
  iVar10 = local_3c;
  iVar23 = local_3c;
  if (DAT_1c250566 != 0) {
    do {
      psVar7 = (short *)*puVar1;
      if ((psVar7 != (short *)0x0) && (*psVar7 != 0x1e)) {
        do {
          if ((int)psVar7[2] == (uint)local_42) {
            sVar6 = *psVar7;
            if (sVar6 < 0xbf) {
              if (sVar6 == 0xbe) {
                *(short *)(param_1 + 0x44) = psVar7[1];
              }
              else if (sVar6 == 0x32) {
                iVar9 = psVar7[1] * 0x4a;
                if (*(short *)(param_1 + 0x4c) != 3) {
                  *(undefined2 *)(param_1 + 0x4c) = *(undefined2 *)(&DAT_1c24b32a + iVar9);
                  *(undefined2 *)(param_1 + 0x44) = *(undefined2 *)(&DAT_1c24b320 + iVar9);
                }
                *(undefined2 *)(param_1 + 0x52) = *(undefined2 *)(&DAT_1c24b322 + iVar9);
                *(undefined2 *)(param_1 + 0x2f2) = *(undefined2 *)(&DAT_1c24b326 + iVar9);
                *(undefined2 *)(param_1 + 0x46) = *(undefined2 *)(&DAT_1c24b31c + iVar9);
                *(undefined2 *)(param_1 + 0xac) = *(undefined2 *)(&DAT_1c24b31e + iVar9);
                *(undefined2 *)(param_1 + 0x60) = *(undefined2 *)(&DAT_1c24b32c + iVar9);
                *(undefined2 *)(param_1 + 0x62) = *(undefined2 *)(&DAT_1c24b32e + iVar9);
                *(undefined2 *)(param_1 + 100) = *(undefined2 *)(&DAT_1c24b332 + iVar9);
                *(undefined2 *)(param_1 + 0x66) = *(undefined2 *)(&DAT_1c24b334 + iVar9);
                *(undefined2 *)(param_1 + 0x8a) = *(undefined2 *)(&DAT_1c24b328 + iVar9);
                *(undefined2 *)(param_1 + 0x98) = *(undefined2 *)(&DAT_1c24b35a + iVar9);
                *(undefined2 *)(param_1 + 0x9a) = *(undefined2 *)(&DAT_1c24b35c + iVar9);
                *(undefined2 *)(param_1 + 0x9c) = *(undefined2 *)(&DAT_1c24b35e + iVar9);
                *(undefined2 *)(param_1 + 0x9e) = *(undefined2 *)(&DAT_1c24b360 + iVar9);
                *(undefined2 *)(param_1 + 0x92) = *(undefined2 *)(&DAT_1c24b34e + iVar9);
                *(undefined2 *)(param_1 + 0x94) = *(undefined2 *)(&DAT_1c24b350 + iVar9);
                *(undefined2 *)(param_1 + 0x96) = *(undefined2 *)(&DAT_1c24b352 + iVar9);
                *(undefined2 *)(param_1 + 0x8c) = *(undefined2 *)(&DAT_1c24b354 + iVar9);
                *(undefined2 *)(param_1 + 0x8e) = *(undefined2 *)(&DAT_1c24b356 + iVar9);
                *(undefined2 *)(param_1 + 0x90) = *(undefined2 *)(&DAT_1c24b358 + iVar9);
                *(undefined2 *)(param_1 + 0x84) = *(undefined2 *)(&DAT_1c24b348 + iVar9);
                *(undefined2 *)(param_1 + 0x86) = *(undefined2 *)(&DAT_1c24b34a + iVar9);
                *(undefined2 *)(param_1 + 0x88) = *(undefined2 *)(&DAT_1c24b34c + iVar9);
                *(undefined2 *)(param_1 + 0x7e) = *(undefined2 *)(&DAT_1c24b342 + iVar9);
                *(undefined2 *)(param_1 + 0x80) = *(undefined2 *)(&DAT_1c24b344 + iVar9);
                *(undefined2 *)(param_1 + 0x82) = *(undefined2 *)(&DAT_1c24b346 + iVar9);
                *(undefined2 *)(param_1 + 0x5c) = *(undefined2 *)(&DAT_1c24b33e + iVar9);
                *(undefined2 *)(param_1 + 0x5e) = *(undefined2 *)(&DAT_1c24b340 + iVar9);
              }
            }
            else if (sVar6 < 0xdd) {
              if (sVar6 == 0xdc) {
                *(short *)(param_1 + 0x2f2) = psVar7[1];
              }
              else if (sVar6 == 200) {
                *(short *)(param_1 + 0x52) = psVar7[1];
              }
            }
            else if (sVar6 < 0xf1) {
              if (sVar6 == 0xf0) {
                *(short *)(param_1 + 0x4c) = psVar7[1];
              }
              else if (sVar6 == 0xe6) {
                *(short *)(param_1 + 0x8a) = psVar7[1];
              }
            }
            else if (sVar6 < 0x14b) {
              if (sVar6 == 0x14a) {
                *(short *)(param_1 + 0x5e) = psVar7[1];
              }
              else if (sVar6 == 0x140) {
                *(short *)(param_1 + 0x5c) = psVar7[1];
              }
            }
            else if (sVar6 < 0x15f) {
              if (sVar6 == 0x15e) {
                *(short *)(param_1 + 0x80) = psVar7[1];
              }
              else if (sVar6 == 0x154) {
                *(short *)(param_1 + 0x7e) = psVar7[1];
              }
            }
            else if (sVar6 < 0x173) {
              if (sVar6 == 0x172) {
                *(short *)(param_1 + 0x84) = psVar7[1];
              }
              else if (sVar6 == 0x168) {
                *(short *)(param_1 + 0x82) = psVar7[1];
              }
            }
            else if (sVar6 < 0x187) {
              if (sVar6 == 0x186) {
                *(short *)(param_1 + 0x88) = psVar7[1];
              }
              else if (sVar6 == 0x17c) {
                *(short *)(param_1 + 0x86) = psVar7[1];
              }
            }
            else if (sVar6 < 0x1ff) {
              if (sVar6 == 0x1fe) {
                *(short *)(param_1 + 0x94) = psVar7[1];
              }
              else if (sVar6 == 500) {
                *(short *)(param_1 + 0x92) = psVar7[1];
              }
            }
            else if (sVar6 < 0x227) {
              if (sVar6 == 0x226) {
                *(short *)(param_1 + 0x8c) = psVar7[1];
              }
              else if (sVar6 == 0x208) {
                *(short *)(param_1 + 0x96) = psVar7[1];
              }
            }
            else if (sVar6 < 0x23b) {
              if (sVar6 == 0x23a) {
                *(short *)(param_1 + 0x90) = psVar7[1];
              }
              else if (sVar6 == 0x230) {
                *(short *)(param_1 + 0x8e) = psVar7[1];
              }
            }
            else if (sVar6 == 0x334) {
              local_46 = psVar7[1];
              bVar12 = bVar12 | 0x20;
            }
            else if (sVar6 == 0x352) {
              bVar12 = bVar12 | 8;
              local_47 = (undefined1)psVar7[1];
            }
          }
          psVar7 = psVar7 + 3;
        } while (*psVar7 != 0x1e);
      }
      local_44 = *DAT_1c250864 >> 8;
      if (bVar24) {
        sStack_40 = *DAT_1c25057c;
        sStack_3e = sStack_40 >> 0xf;
        local_3c = (int)*DAT_1c250580;
        iVar10 = (int)*DAT_1c250588;
        iVar23 = (int)*DAT_1c250568;
        local_30 = (int)*DAT_1c25056c;
        local_34 = (int)*DAT_1c250570;
      }
      else {
        switch(DAT_1c250e7e) {
        case 0x3c:
        case 0x57:
          local_3c = 0x4a1;
          iVar10 = 0x898;
          sStack_40 = 0x14a;
          sStack_3e = 0;
          local_34 = 0x3c;
          iVar23 = 500;
          break;
        case 0x3d:
        case 0x58:
          local_3c = 0x640;
          iVar10 = 0x8fc;
          sStack_40 = 0x109;
          sStack_3e = 0;
          local_34 = 0x3c;
          iVar23 = 500;
          break;
        case 0x3e:
          local_3c = 0x6d6;
          iVar10 = 0x8ca;
          sStack_40 = 0xfa;
          sStack_3e = 0;
          local_34 = 0x3c;
          iVar23 = 500;
        }
      }
      iVar9 = CONCAT22(sStack_3e,sStack_40);
      if (*(short *)(param_1 + 0x2f2) == 1) {
        if (*(short *)(param_1 + 0x52) == 0) {
          iVar23 = iVar23 + 0x3c;
        }
        iVar21 = (short)*DAT_1c250598 + -7;
        if ((short)*DAT_1c250598 + -7 <= (int)*DAT_1c250584) {
          iVar21 = (int)*DAT_1c250584;
        }
        *DAT_1c250584 = (short)iVar21;
        if (0x14 < (short)*DAT_1c250598) {
          *DAT_1c250598 = *DAT_1c250598 + 4;
        }
        local_44 = local_44 + -4;
      }
      else if (*(short *)(param_1 + 0x2f2) == 2) {
        iVar21 = (short)*DAT_1c250598 + -3;
        if ((short)*DAT_1c250598 + -3 <= (int)*DAT_1c250584) {
          iVar21 = (int)*DAT_1c250584;
        }
        iVar23 = 200;
        *DAT_1c250584 = (short)iVar21;
        *DAT_1c250598 = 0;
      }
      else if (bVar24) {
        iVar21 = (short)*DAT_1c250598 + -0x14;
        if ((short)*DAT_1c250598 + -0x14 <= (int)*DAT_1c250584) {
          iVar21 = (int)*DAT_1c250584;
        }
        *DAT_1c250584 = (short)iVar21;
      }
      else {
        *DAT_1c250584 = 0;
      }
      if ((DAT_1c250e70 & 0x8000) != 0) {
        *DAT_1c250584 = *DAT_1c250584 + -7;
      }
      sVar6 = *(short *)(param_1 + 0x52);
      iVar21 = *(short *)(param_1 + 0x5c) + 10;
      if (sVar6 == 1) {
        local_44 = local_44 + -5;
        *DAT_1c250598 = *DAT_1c250598 - 10;
        *DAT_1c250584 = *DAT_1c250584 + -0x14;
        *DAT_1c250578 = *DAT_1c250578 - 6;
        *DAT_1c25059c = *DAT_1c25059c + 0x96;
        iVar16 = local_3c;
        iVar19 = iVar10;
      }
      else if (sVar6 == 2) {
        local_44 = local_44 + -1;
        *DAT_1c250598 = *DAT_1c250598 - 0xd;
        iVar19 = iVar10 + 0x429;
        *DAT_1c250584 = *DAT_1c250584 + -0x16;
        *DAT_1c250578 = *DAT_1c250578 - 7;
        iVar9 = ((CONCAT22(sStack_3e,sStack_40) + -0x1c2) * iVar21 * 0x91) / 1000 + 0x2e4;
        iVar10 = ((local_3c + -0x5aa) * iVar21 * 0x91) / 1000;
        iVar16 = iVar10 + 0x834;
        if (iVar19 - iVar16 < 0x15e) {
          iVar19 = iVar10 + 0x992;
        }
        iVar23 = (iVar9 * iVar23) / CONCAT22(sStack_3e,sStack_40) + 0x96;
        local_30 = (iVar16 * local_30) / local_3c + 0x32;
        if (299 < iVar23) {
          iVar23 = 300;
        }
        if (iVar23 < 0x65) {
          iVar23 = 100;
        }
        *DAT_1c25059c = *DAT_1c25059c + 0xfa;
      }
      else {
        iVar9 = CONCAT22(sStack_3e,sStack_40) + -0x1c2;
        if (sVar6 == 3) {
          iVar9 = (iVar9 * iVar21 * 0x5c) / 1000 + 400;
          iVar8 = ((local_3c + -0x5aa) * iVar21 * 0x5c) / 1000;
          iVar16 = iVar8 + 0x564;
          iVar19 = ((iVar10 + -0x9a1) * iVar21 * 0x5c) / 1000 + 0x92e;
          if (iVar19 - iVar16 < 0xfa) {
            iVar19 = iVar8 + 0x65e;
          }
          *DAT_1c25059c = *DAT_1c25059c + -100;
        }
        else {
          iVar9 = (iVar9 * iVar21 * 100) / 1000 + 0x1c2;
          iVar16 = ((local_3c + -0x5aa) * iVar21 * 100) / 1000 + 0x5aa;
          iVar19 = ((iVar10 + -0x9a1) * iVar21 * 100) / 1000 + 0x9a1;
        }
        iVar23 = (iVar9 * iVar23) / CONCAT22(sStack_3e,sStack_40);
        local_30 = (iVar16 * local_30) / local_3c;
        local_34 = (iVar19 * local_34) / iVar10;
        if (299 < iVar23) {
          iVar23 = 300;
        }
        if (iVar23 < 0x29) {
          iVar23 = 0x28;
        }
        iVar10 = *(short *)(param_1 + 0x46) + -0x6e;
        if (iVar10 < 1) {
          iVar10 = 0;
        }
        iVar10 = iVar10 / 0xe;
        if (0x13 < iVar10) {
          iVar10 = 0x14;
        }
        *DAT_1c250598 = *DAT_1c250598 - (short)iVar10;
        *DAT_1c250584 = *DAT_1c250584 + -0xd;
        *DAT_1c250578 = *DAT_1c250578 - 2;
        iVar9 = (iVar9 * 0x22) / 0x21;
      }
      *DAT_1c250598 = *DAT_1c250598 + *(short *)(param_1 + 0x84);
      *DAT_1c250584 = *DAT_1c250584 + *(short *)(param_1 + 0x86);
      *DAT_1c250578 = *DAT_1c250578 + *(short *)(param_1 + 0x88);
      iVar9 = (*(short *)(param_1 + 0x92) * iVar9) / 100;
      local_3c = (*(short *)(param_1 + 0x94) * iVar16) / 100;
      iVar10 = (*(short *)(param_1 + 0x96) * iVar19) / 100;
      if (0xfef < iVar9) {
        iVar9 = 0xff0;
      }
      if (iVar9 < 0x65) {
        iVar9 = 100;
      }
      sStack_40 = (short)iVar9;
      sStack_3e = (short)((uint)iVar9 >> 0x10);
      if (0xfef < local_3c) {
        local_3c = 0xff0;
      }
      if (local_3c < 0x65) {
        local_3c = 100;
      }
      if (0xfef < iVar10) {
        iVar10 = 0xff0;
      }
      if (iVar10 < 0x65) {
        iVar10 = 100;
      }
      iVar23 = (*(short *)(param_1 + 0x8c) * iVar23) / 100;
      local_30 = (*(short *)(param_1 + 0x8e) * local_30) / 100;
      local_34 = (*(short *)(param_1 + 0x90) * local_34) / 100;
      if (499 < iVar23) {
        iVar23 = 500;
      }
      if (iVar23 < 0x29) {
        iVar23 = 0x28;
      }
      if (499 < local_30) {
        local_30 = 500;
      }
      if (local_30 < 0x29) {
        local_30 = 0x28;
      }
      if (499 < local_34) {
        local_34 = 500;
      }
      if (local_34 < 0x29) {
        local_34 = 0x28;
      }
      local_1c = local_1c + ((*(short *)(param_1 + 0x98) - local_1c) * 5000 >> 0x10);
      local_18 = local_18 + ((*(short *)(param_1 + 0x9c) - local_18) * 5000 >> 0x10);
      local_14 = local_14 + ((*(short *)(param_1 + 0x9a) - local_14) * 5000 >> 0x10);
      local_10 = local_10 + ((*(short *)(param_1 + 0x9e) - local_10) * 5000 >> 0x10);
      local_44 = local_44 + *(short *)(param_1 + 0x8a);
      if (0xe < local_44) {
        local_44 = 0xf;
      }
      if (local_44 < 1) {
        local_44 = 0;
      }
      local_20 = (int)*DAT_1c25059c;
      local_28 = (int)*DAT_1c2505a0;
      if (*(short *)(param_1 + 0x48) == 8000) {
        sStack_40 = (short)(iVar9 * 0xb >> 3);
        sStack_3e = (short)(iVar9 * 0xb >> 0x13);
        iVar23 = iVar23 * 0xb >> 3;
        local_3c = local_3c * 0xb >> 3;
        local_30 = local_30 * 0xb >> 3;
        iVar10 = iVar10 * 0xb >> 3;
        local_34 = local_34 * 0xb >> 3;
        local_1c = local_1c * 0xb >> 3;
        local_14 = local_14 * 0xb >> 3;
        local_18 = local_18 * 0xb >> 3;
        local_10 = local_10 * 0xb >> 3;
        local_20 = local_20 * 0xb >> 3;
        local_28 = local_28 * 0xb >> 3;
      }
      if (((DAT_1c250e70 & 0xc0100000) == 0) || (local_42 <= DAT_1c250566 >> 1)) {
        DAT_1c250e69 = *(char *)((uint)DAT_1c250e7e * 0x1a + 0x17 + *(int *)(iVar11 + 4));
      }
      else {
        DAT_1c250e69 = *(char *)((uint)DAT_1c250e7e * 0x1a + 0x31 + *(int *)(iVar11 + 4));
      }
      if (DAT_1c250e69 == '\0') {
        DAT_1c250e69 = DAT_1c250e63;
      }
      DAT_1c250e58[0x1a] = DAT_1c250e69;
      iVar9 = CONCAT22(sStack_3e,sStack_40) + 8;
      *DAT_1c250e58 = (&UNK_1c205ff4)[(int)(iVar9 + (iVar9 >> 0x1f & 0xfU)) >> 4 & 0xff];
      DAT_1c250e58[1] =
           (&UNK_1c205ff4)[(int)(local_3c + 8 + (local_3c + 8 >> 0x1f & 0xfU)) >> 4 & 0xff];
      DAT_1c250e58[2] = (&UNK_1c205ff4)[(int)(iVar10 + 8 + (iVar10 + 8 >> 0x1f & 0xfU)) >> 4 & 0xff]
      ;
      DAT_1c250e58[3] =
           "  !\"\"#$$%%&&\'\'(())**+++,,--...//000111223334445556667777888999::::;;;;<<<====>>>>????@@@@@AAAABBBBCCCCCDDDDDEEEEEFFFFFGGGGGHHHHHIIIIIIJJJJJJKKKKKLLLLLLMMMMMMMNNNNNNOOOOOOOPPPPPPQQQQQQQRRRRRRRRSSSSSSST"
           [((int)(local_1c + 0x10 + (local_1c + 0x10 >> 0x1f & 0x1fU)) >> 5 & 0xffU) + 200];
      DAT_1c250e58[4] =
           "  !\"\"#$$%%&&\'\'(())**+++,,--...//000111223334445556667777888999::::;;;;<<<====>>>>????@@@@@AAAABBBBCCCCCDDDDDEEEEEFFFFFGGGGGHHHHHIIIIIIJJJJJJKKKKKLLLLLLMMMMMMMNNNNNNOOOOOOOPPPPPPQQQQQQQRRRRRRRRSSSSSSST"
           [((int)(local_18 + 0x10 + (local_18 + 0x10 >> 0x1f & 0x1fU)) >> 5 & 0xffU) + 200];
      DAT_1c250e58[5] = 0;
      DAT_1c250e58[6] =
           "     !!!!!!\"\"\"\"\"######$$$$$$%%%%%%%&&&&&&&\'\'\'\'\'\'\'((((((())))))))********+++++++++,,,,,,,,,----------..........////////////////////////////////////////////"
           [((int)(iVar23 + 4 + (iVar23 + 4 >> 0x1f & 7U)) >> 3 & 0xffU) + 0x9a] * '\x10' +
           "     !!!!!!\"\"\"\"\"######$$$$$$%%%%%%%&&&&&&&\'\'\'\'\'\'\'((((((())))))))********+++++++++,,,,,,,,,----------..........////////////////////////////////////////////"
           [((int)(local_30 + 4 + (local_30 + 4 >> 0x1f & 7U)) >> 3 & 0xffU) + 0x9a];
      DAT_1c250e58[7] =
           "     !!!!!!\"\"\"\"\"######$$$$$$%%%%%%%&&&&&&&\'\'\'\'\'\'\'((((((())))))))********+++++++++,,,,,,,,,----------..........////////////////////////////////////////////"
           [((int)(local_34 + 4 + (local_34 + 4 >> 0x1f & 7U)) >> 3 & 0xffU) + 0x9a] * '\x10' +
           (char)local_44;
      DAT_1c250e58[8] =
           (&DAT_1c2062f4)[(int)(local_14 + 4 + (local_14 + 4 >> 0x1f & 7U)) >> 3 & 0xff] * '\x10' +
           (&DAT_1c2062f4)[(int)(local_10 + 4 + (local_10 + 4 >> 0x1f & 7U)) >> 3 & 0xff];
      DAT_1c250e58[9] =
           "  !\"\"#$$%%&&\'\'(())**+++,,--...//000111223334445556667777888999::::;;;;<<<====>>>>????@@@@@AAAABBBBCCCCCDDDDDEEEEEFFFFFGGGGGHHHHHIIIIIIJJJJJJKKKKKLLLLLLMMMMMMMNNNNNNOOOOOOOPPPPPPQQQQQQQRRRRRRRRSSSSSSST"
           [((int)(local_20 + 0x10 + (local_20 + 0x10 >> 0x1f & 0x1fU)) >> 5 & 0xffU) + 200];
      DAT_1c250e58[0xb] = DAT_1c250e7e;
      uVar13 = *(ushort *)(param_1 + 0x44) >> 1;
      if (uVar13 < 2) {
        uVar13 = 1;
      }
      DAT_1c250e58[10] = (char)uVar13;
      iVar9 = (short)*DAT_1c250598 * 2;
      if (0x7f < iVar9) {
        iVar9 = 0x80;
      }
      if (iVar9 < 1) {
        iVar9 = 0;
      }
      DAT_1c250e58[0x10] = (char)iVar9;
      iVar9 = *DAT_1c250584 * 2;
      if (0x7f < iVar9) {
        iVar9 = 0x80;
      }
      if (iVar9 < 1) {
        iVar9 = 0;
      }
      DAT_1c250e58[0x11] = (char)iVar9;
      iVar9 = (short)*DAT_1c250578 * 2;
      if (0x7f < iVar9) {
        iVar9 = 0x80;
      }
      if (iVar9 < 1) {
        iVar9 = 0;
      }
      DAT_1c250e58[0x12] = (char)iVar9;
      iVar9 = *DAT_1c250590 * 2 + 0x5c;
      if (iVar9 < 1) {
        iVar9 = 0;
      }
      DAT_1c250e58[0x13] = (char)iVar9;
      DAT_1c250e58[0x14] =
           (&DAT_1c2062f4)[(int)(local_28 + 4 + (local_28 + 4 >> 0x1f & 7U)) >> 3 & 0xff] << 4;
      DAT_1c250e58[0x1b] = local_47;
      *(short *)(DAT_1c250e58 + 0x1c) = local_46;
      DAT_1c250e58[0x17] = bVar12;
      DAT_1c250e58[0x1f] = cVar3;
      cVar3 = cVar3 + '\x01';
      if (*(short *)(param_1 + 0x4c) == 2) {
        *(undefined2 *)(DAT_1c250e58 + 0x18) = *(undefined2 *)(param_1 + 0x46);
      }
      else if (*(short *)(param_1 + 0x4c) != 4) {
        *(undefined2 *)(DAT_1c250e58 + 0x18) = 0;
      }
      DAT_1c250e58 = DAT_1c250e58 + 0x20;
      if ((bVar12 & 8) != 0) {
        bVar12 = bVar12 ^ 8;
      }
      if ((bVar12 & 0x20) != 0) {
        bVar12 = bVar12 ^ 0x20;
      }
      DAT_1c25057c = DAT_1c25057c + 1;
      DAT_1c250580 = DAT_1c250580 + 1;
      DAT_1c250588 = DAT_1c250588 + 1;
      DAT_1c250568 = DAT_1c250568 + 1;
      DAT_1c25056c = DAT_1c25056c + 1;
      DAT_1c250570 = DAT_1c250570 + 1;
      DAT_1c25059c = DAT_1c25059c + 1;
      DAT_1c2505a0 = DAT_1c2505a0 + 1;
      DAT_1c250864 = DAT_1c250864 + 1;
      _DAT_1c250594 = _DAT_1c250594 + 2;
      DAT_1c250598 = DAT_1c250598 + 1;
      local_42 = local_42 + 1;
      DAT_1c250584 = DAT_1c250584 + 1;
      DAT_1c250578 = DAT_1c250578 + 1;
      DAT_1c250590 = DAT_1c250590 + 1;
      _DAT_1c250574 = _DAT_1c250574 + 2;
    } while (local_42 < DAT_1c250566);
  }
  *(undefined2 *)(*(int *)(param_1 + 0xf6) + 0x18) = *(undefined2 *)(param_1 + 0x46);
  FUN_1c203ab0(param_1,(int)(DAT_1c250e58 + (uint)DAT_1c250566 * -0x20),puVar1);
  if (*(short *)(param_1 + 0x4c) == 3) {
    FUN_1c2042c0(param_1,(int)(DAT_1c250e58 + (uint)DAT_1c250566 * -0x20),puVar1);
  }
  else if (*(short *)(param_1 + 0x4c) == 4) {
    FUN_1c204030(param_1,(int)DAT_1c250e58,puVar1);
  }
  bVar12 = 1;
  if ((*(uint *)((int)puVar1 + 0x16) & 0x100) != 0) {
    bVar12 = 3;
  }
  if ((*(uint *)((int)puVar1 + 0x16) & 0x80) != 0) {
    bVar12 = bVar12 | 4;
  }
  DAT_1c250e58[(uint)DAT_1c250566 * -0x20 + 0x17] =
       DAT_1c250e58[(uint)DAT_1c250566 * -0x20 + 0x17] | bVar12;
  *(undefined1 **)(param_1 + 0xfa) = DAT_1c250e58;
  iVar11 = *(short *)(param_1 + 0x98) + 0x10;
  *(ushort *)(param_1 + 0xa0) =
       (ushort)(byte)"  !\"\"#$$%%&&\'\'(())**+++,,--...//000111223334445556667777888999::::;;;;<<<====>>>>????@@@@@AAAABBBBCCCCCDDDDDEEEEEFFFFFGGGGGHHHHHIIIIIIJJJJJJKKKKKLLLLLLMMMMMMMNNNNNNOOOOOOOPPPPPPQQQQQQQRRRRRRRRSSSSSSST"
                     [((int)(iVar11 + (iVar11 >> 0x1f & 0x1fU)) >> 5 & 0xffU) + 200];
  iVar11 = *(short *)(param_1 + 0x9c) + 0x10;
  *(ushort *)(param_1 + 0xa4) =
       (ushort)(byte)"  !\"\"#$$%%&&\'\'(())**+++,,--...//000111223334445556667777888999::::;;;;<<<====>>>>????@@@@@AAAABBBBCCCCCDDDDDEEEEEFFFFFGGGGGHHHHHIIIIIIJJJJJJKKKKKLLLLLLMMMMMMMNNNNNNOOOOOOOPPPPPPQQQQQQQRRRRRRRRSSSSSSST"
                     [((int)(iVar11 + (iVar11 >> 0x1f & 0x1fU)) >> 5 & 0xffU) + 200];
  iVar11 = *(short *)(param_1 + 0x9a) + 4;
  *(ushort *)(param_1 + 0xa2) =
       (ushort)(byte)(&DAT_1c2062f4)[(int)(iVar11 + (iVar11 >> 0x1f & 7U)) >> 3 & 0xff];
  iVar11 = *(short *)(param_1 + 0x9e) + 4;
  iVar11 = iVar11 + (iVar11 >> 0x1f & 7U);
  bVar12 = (&DAT_1c2062f4)[iVar11 >> 3 & 0xff];
  *(ushort *)(param_1 + 0xa6) = (ushort)bVar12;
  return CONCAT22((short)(iVar11 >> 0x13),(ushort)bVar12);
}


// ==== FUN_1c206780 @ 1c206780 size=54

undefined4 __cdecl FUN_1c206780(int param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(*(uint *)(param_1 + 0x102) & 0xffffffe0);
  *(void **)(param_1 + 0xf6) = pvVar1;
  if (pvVar1 == (void *)0x0) {
    return 0x1b5b;
  }
  *(void **)(param_1 + 0xfa) = pvVar1;
  return 0;
}


// ==== FUN_1c2067c0 @ 1c2067c0 size=151

void __cdecl FUN_1c2067c0(int param_1,int *param_2)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  
  uVar1 = param_2[6];
  if ((uVar1 & 4) == 0) {
    bVar2 = true;
    do {
      param_2[7] = param_2[7] & 0xfffffffb;
      iVar3 = FUN_1c2097a0(param_1,param_2);
      if (iVar3 != 0) {
        return;
      }
      iVar3 = FUN_1c207230(param_2);
      if (iVar3 != 0) {
        return;
      }
      iVar3 = FUN_1c208150(param_2);
      if (iVar3 != 0) {
        return;
      }
      if ((*(byte *)(param_2 + 7) & 4) == 0) {
        iVar3 = FUN_1c206860(param_2);
        if (iVar3 != 0) {
          return;
        }
        if ((param_2[7] & 4U) == 0) {
          if (((uVar1 & 2) != 0) || ((param_2[7] & 1U) != 0)) {
            FUN_1c2077b0((int)param_2);
          }
          bVar2 = false;
        }
      }
    } while (bVar2);
  }
  else {
    iVar3 = FUN_1c209a00(param_2);
    if (iVar3 == 0) {
      param_2[7] = param_2[7] & 0xfffffffb;
      return;
    }
  }
  return;
}


// ==== FUN_1c206860 @ 1c206860 size=1949

undefined4 __cdecl FUN_1c206860(int *param_1)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  char *_Dest;
  byte *pbVar4;
  bool bVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  uint uVar14;
  size_t _Count;
  int local_8;
  
  _Dest = (char *)param_1[1];
  bVar5 = false;
  uVar14 = param_1[7];
  bVar6 = *(byte *)param_1[2];
  pbVar4 = (byte *)param_1[2];
joined_r0x1c206888:
  if ((bVar6 != 0x20) && (bVar6 = *pbVar4, bVar6 != 0)) {
    if (((*(ushort *)(&DAT_1c209c20 + (uint)bVar6 * 2) & 2) == 0) && (!bVar5)) {
      if ((*(ushort *)(&DAT_1c209c20 + (uint)bVar6 * 2) & 0x80) == 0) {
LAB_1c206907:
        bVar5 = true;
        pbVar12 = PTR_DAT_1c24c8c4;
      }
      else {
        switch((uint)bVar6) {
        case 0xc4:
          pbVar12 = PTR_DAT_1c24c8b0;
          break;
        default:
          if (bVar6 < 0x7b) {
            pbVar12 = *(byte **)(&DAT_1c24c744 + (char)bVar6 * 4);
            break;
          }
          goto LAB_1c206907;
        case 0xd6:
          pbVar12 = PTR_DAT_1c24c8b4;
          break;
        case 0xdc:
          pbVar12 = PTR_DAT_1c24c8bc;
          break;
        case 0xdf:
          pbVar12 = PTR_DAT_1c24c8b8;
        }
      }
LAB_1c206915:
      do {
        bVar6 = *pbVar12;
        pbVar10 = pbVar12;
        while (bVar6 != 0x5b) {
          pbVar10 = pbVar10 + 1;
          bVar6 = *pbVar10;
        }
        pbVar11 = pbVar10 + 1;
        pbVar13 = pbVar4;
        do {
          if (*pbVar11 == 0x5d) {
            if (pbVar11[-1] == 0x5b) {
              pbVar13 = pbVar13 + 1;
            }
            iVar7 = -1;
            local_8 = 0;
            pbVar10 = pbVar10 + -1;
            pbVar12 = pbVar4 + -1;
            goto LAB_1c206978;
          }
          iVar7 = FUN_1c207180(*pbVar11);
          if (iVar7 == 0) {
            bVar6 = FUN_1c2070b0(*pbVar13);
          }
          else {
            bVar6 = *pbVar13;
          }
          pbVar13 = pbVar13 + 1;
          pbVar12 = pbVar11 + 1;
          bVar2 = *pbVar11;
          pbVar11 = pbVar12;
        } while (bVar2 == bVar6);
      } while( true );
    }
  }
  *_Dest = '\0';
  param_1[1] = (int)_Dest;
  param_1[7] = uVar14;
  *param_1 = (int)(pbVar4 + (*param_1 - param_1[2]));
  param_1[2] = (int)pbVar4;
  return 0;
LAB_1c206978:
  bVar6 = *pbVar10;
  while (((bVar6 != 0x5c && (bVar6 = *pbVar10, bVar6 != 0x60)) && (bVar6 != 0x3d))) {
    if (((&DAT_1c209c21)[(uint)bVar6 * 2] & 4) == 0) {
      iVar8 = FUN_1c207180(bVar6);
      bVar6 = *pbVar12;
      if (iVar8 == 0) {
        bVar6 = FUN_1c2070b0(bVar6);
      }
      if (*pbVar10 != bVar6) {
        pbVar12 = pbVar10 + 1;
        if (*pbVar12 == 0x5c) goto LAB_1c206915;
        goto LAB_1c206d09;
      }
      pbVar12 = pbVar12 + iVar7;
    }
    else {
      switch(bVar6) {
      case 0x20:
        if (((&DAT_1c209c20)[(uint)*pbVar12 * 2] & 0x80) != 0) {
          pbVar12 = pbVar10 + 1;
          if (*pbVar12 == 0x5c) goto LAB_1c206915;
          goto LAB_1c206d45;
        }
        do {
          pbVar12 = pbVar12 + iVar7;
          piVar9 = (int *)__p___mb_cur_max();
          if (*piVar9 < 2) {
            piVar9 = (int *)__p__pctype();
            uVar14 = *(ushort *)(*piVar9 + (uint)*pbVar12 * 2) & 8;
          }
          else {
            uVar14 = _isctype((uint)*pbVar12,8);
          }
        } while (uVar14 != 0);
        break;
      default:
        pbVar12 = pbVar10 + 1;
        if (*pbVar12 == 0x5c) goto LAB_1c206915;
        goto LAB_1c206d27;
      case 0x23:
        if (((&DAT_1c209c20)[(uint)*pbVar12 * 2] & 0x40) == 0) {
          pbVar12 = pbVar10 + 1;
          if (*pbVar12 == 0x5c) goto LAB_1c206915;
          goto LAB_1c206d63;
        }
        pbVar12 = pbVar12 + iVar7;
        break;
      case 0x25:
        pbVar1 = pbVar12 + 2;
        if (*pbVar12 == 0x45) {
          bVar6 = pbVar12[1];
          if (bVar6 == 0x52) {
            bVar6 = *pbVar1;
            iVar8 = 3;
            goto LAB_1c206ac2;
          }
          if ((bVar6 == 0x4c) && (*pbVar1 == 0x59)) {
            iVar8 = 3;
          }
          else if ((bVar6 == 0x53) || (bVar6 == 0x44)) {
            iVar8 = 2;
          }
          else {
            iVar8 = 1;
          }
        }
        else {
          if (((*pbVar12 != 0x49) || (pbVar12[1] != 0x4e)) || (*pbVar1 != 0x47)) {
            pbVar12 = pbVar10 + 1;
            if (*pbVar12 == 0x5c) goto LAB_1c206915;
            goto LAB_1c206d9f;
          }
          bVar6 = pbVar12[3];
          iVar8 = 4;
LAB_1c206ac2:
          iVar8 = iVar8 + -1 + (uint)(bVar6 == 0x53);
        }
        pbVar12 = pbVar12 + iVar8;
        if (((&DAT_1c209c20)[(uint)*pbVar12 * 2] & 0x80) != 0) {
          pbVar12 = pbVar10 + 1;
          if (*pbVar12 == 0x5c) goto LAB_1c206915;
          goto LAB_1c206d81;
        }
        break;
      case 0x26:
        if (*pbVar12 == 0x48) {
          if ((pbVar12[-1] != 0x43) && (pbVar12[-1] != 0x53)) {
            pbVar12 = pbVar10 + 1;
            if (*pbVar12 == 0x5c) goto LAB_1c206915;
            goto LAB_1c206dbd;
          }
          pbVar12 = pbVar12 + iVar7 * 2;
        }
        else {
          if (((&DAT_1c209c20)[(uint)*pbVar12 * 2] & 0x10) == 0) {
            pbVar12 = pbVar10 + 1;
            if (*pbVar12 == 0x5c) goto LAB_1c206915;
            goto LAB_1c206ddb;
          }
          pbVar12 = pbVar12 + iVar7;
        }
        break;
      case 0x2b:
        if (((&DAT_1c209c21)[(uint)*pbVar12 * 2] & 1) == 0) {
          pbVar12 = pbVar10 + 1;
          if (*pbVar12 == 0x5c) goto LAB_1c206915;
          goto LAB_1c206df9;
        }
        pbVar12 = pbVar12 + iVar7;
        break;
      case 0x2e:
        if (((byte)*(undefined2 *)(&DAT_1c209c20 + (uint)*pbVar12 * 2) & 0x28) != 0x28) {
          pbVar12 = pbVar10 + 1;
          if (*pbVar12 == 0x5c) goto LAB_1c206915;
          goto LAB_1c206e17;
        }
        pbVar12 = pbVar12 + iVar7;
        break;
      case 0x3a:
        if (((&DAT_1c209c20)[(uint)*pbVar12 * 2] & 0x20) != 0) {
          do {
            pbVar12 = pbVar12 + iVar7;
          } while ((*(ushort *)(&DAT_1c209c20 + (uint)*pbVar12 * 2) & 0x20) != 0);
        }
        break;
      case 0x3c:
        piVar9 = (int *)__p___mb_cur_max();
        if (*piVar9 < 2) {
          piVar9 = (int *)__p__pctype();
          uVar14 = *(ushort *)(*piVar9 + (uint)*pbVar12 * 2) & 8;
        }
        else {
          uVar14 = _isctype((uint)*pbVar12,8);
        }
        if ((uVar14 != 0) || (((&DAT_1c209c20)[(uint)*pbVar12 * 2] & 3) == 0)) {
          pbVar12 = pbVar10 + 1;
          if (*pbVar12 == 0x5c) goto LAB_1c206915;
          goto LAB_1c206e35;
        }
        pbVar12 = pbVar12 + iVar7;
        break;
      case 0x3e:
        if (((&DAT_1c209c20)[(uint)*pbVar12 * 2] & 1) != 0) {
          pbVar12 = pbVar10 + 1;
          if (*pbVar12 == 0x5c) goto LAB_1c206915;
          goto LAB_1c206e53;
        }
        pbVar12 = pbVar12 + iVar7;
        break;
      case 0x3f:
        if (((&DAT_1c209c20)[(uint)*pbVar12 * 2] & 2) == 0) {
          pbVar12 = pbVar10 + 1;
          if (*pbVar12 == 0x5c) goto LAB_1c206915;
          goto LAB_1c206e71;
        }
        pbVar12 = pbVar12 + iVar7;
        break;
      case 0x40:
        if (*pbVar12 == 0x48) {
          bVar6 = pbVar12[-1];
          if (((bVar6 != 0x54) && (bVar6 != 0x43)) && (bVar6 != 0x53)) {
            pbVar12 = pbVar10 + 1;
            if (*pbVar12 == 0x5c) goto LAB_1c206915;
            goto LAB_1c206e8f;
          }
          pbVar12 = pbVar12 + iVar7 * 2;
        }
        else {
          if (((&DAT_1c209c20)[(uint)*pbVar12 * 2] & 4) == 0) {
            pbVar12 = pbVar10 + 1;
            if (*pbVar12 == 0x5c) goto LAB_1c206915;
            goto LAB_1c206ead;
          }
          pbVar12 = pbVar12 + iVar7;
        }
        break;
      case 0x5e:
        if (((&DAT_1c209c20)[(uint)*pbVar12 * 2] & 0x20) == 0) {
          pbVar12 = pbVar10 + 1;
          if (*pbVar12 == 0x5c) goto LAB_1c206915;
          goto LAB_1c206ecb;
        }
        pbVar12 = pbVar12 + iVar7;
        break;
      case 0x62:
        piVar9 = (int *)__p___mb_cur_max();
        if (*piVar9 < 2) {
          piVar9 = (int *)__p__pctype();
          uVar14 = *(ushort *)(*piVar9 + (uint)*pbVar12 * 2) & 8;
        }
        else {
          uVar14 = _isctype((uint)*pbVar12,8);
        }
        if (uVar14 == 0) {
          pbVar12 = pbVar10 + 1;
          if (*pbVar12 == 0x5c) goto LAB_1c206915;
          goto LAB_1c206ee9;
        }
        do {
          pbVar12 = pbVar12 + iVar7;
          piVar9 = (int *)__p___mb_cur_max();
          if (*piVar9 < 2) {
            piVar9 = (int *)__p__pctype();
            uVar14 = *(ushort *)(*piVar9 + (uint)*pbVar12 * 2) & 8;
          }
          else {
            uVar14 = _isctype((uint)*pbVar12,8);
          }
        } while (uVar14 != 0);
      }
    }
    pbVar10 = pbVar10 + iVar7;
    bVar6 = *pbVar10;
  }
  local_8 = local_8 + 1;
  if (1 < local_8) {
    bVar6 = pbVar10[1];
    pbVar12 = pbVar10 + 1;
    iVar7 = 0;
    uVar14 = 4;
    pbVar10 = pbVar10 + 2;
    goto joined_r0x1c206f0d;
  }
  iVar7 = 1;
  pbVar10 = pbVar11 + 1;
  pbVar12 = pbVar13;
  goto LAB_1c206978;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c206d09:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c206915;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c206ee9:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c206915;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c206ecb:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c206915;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c206ead:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c206915;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c206e8f:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c206915;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c206e71:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c206915;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c206e53:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c206915;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c206e35:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c206915;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c206e17:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c206915;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c206df9:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c206915;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c206ddb:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c206915;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c206dbd:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c206915;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c206d9f:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c206915;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c206d81:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c206915;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c206d63:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c206915;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c206d27:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c206915;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c206d45:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c206915;
joined_r0x1c206f0d:
  if (bVar6 == 0x5c) goto LAB_1c206f2f;
  if (bVar6 == 0x60) {
    uVar14 = uVar14 | 2;
    goto LAB_1c206f32;
  }
  iVar7 = iVar7 + 1;
  if ((bVar6 == 0x2e) || (bVar6 == 0x3f)) {
    uVar14 = uVar14 | 8;
  }
  bVar6 = *pbVar10;
  pbVar10 = pbVar10 + 1;
  goto joined_r0x1c206f0d;
LAB_1c206f2f:
  uVar14 = uVar14 | 1;
LAB_1c206f32:
  if (param_1[5] < iVar7) {
    param_1[7] = 0;
    return 1;
  }
  if ((((*(byte *)(param_1 + 6) & 0x40) == 0) && (*pbVar4 == 0x3f)) && (iVar7 == 1)) {
    _Count = 1;
    pbVar12 = &DAT_1c24c8c8;
  }
  else {
    _Count = (size_t)(short)iVar7;
  }
  strncat(_Dest,(char *)pbVar12,_Count);
  param_1[5] = param_1[5] - iVar7;
  cVar3 = *_Dest;
  while (cVar3 != '\0') {
    _Dest = _Dest + 1;
    cVar3 = *_Dest;
  }
  param_1[1] = (int)_Dest;
  param_1[7] = uVar14;
  *param_1 = (int)(pbVar4 + (*param_1 - param_1[2]));
  param_1[2] = (int)pbVar4;
  bVar6 = *pbVar13;
  pbVar4 = pbVar13;
  goto joined_r0x1c206888;
}


// ==== FUN_1c2070b0 @ 1c2070b0 size=87

byte __cdecl FUN_1c2070b0(byte param_1)

{
  if (((&DAT_1c209c20)[(uint)param_1 * 2] & 0x40) != 0) {
    switch((uint)param_1) {
    case 0xc1:
      return 0x41;
    case 0xc9:
      return 0x45;
    case 0xcd:
      return 0x49;
    case 0xd1:
      return 0x4e;
    case 0xd3:
      return 0x4f;
    case 0xda:
      return 0x55;
    case 0xe1:
      return 0x41;
    case 0xe9:
      return 0x45;
    case 0xed:
      return 0x49;
    case 0xf1:
      return 0x4e;
    case 0xf3:
      return 0x4f;
    case 0xfa:
      return 0x55;
    case 0xfc:
      param_1 = 0x55;
    }
  }
  return param_1;
}


// ==== FUN_1c207180 @ 1c207180 size=47

undefined4 __cdecl FUN_1c207180(byte param_1)

{
  switch(param_1) {
  case 0xc1:
  case 0xc9:
  case 0xcd:
  case 0xd1:
  case 0xd3:
  case 0xda:
  case 0xe1:
  case 0xe9:
  case 0xed:
  case 0xf1:
  case 0xf3:
  case 0xfa:
  case 0xfc:
    return 1;
  default:
    return 0;
  }
}


// ==== FUN_1c207230 @ 1c207230 size=1286

undefined4 __cdecl FUN_1c207230(int *param_1)

{
  byte *pbVar1;
  byte bVar2;
  bool bVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  char *local_10;
  int local_8;
  
  local_10 = (char *)param_1[1];
  bVar3 = false;
  pbVar7 = (byte *)param_1[2];
LAB_1c20724d:
  bVar4 = *pbVar7;
  if ((*(ushort *)(&DAT_1c209c20 + (uint)bVar4 * 2) & 0x80) == 0) {
    pbVar11 = PTR_DAT_1c24c938;
    if ((*(ushort *)(&DAT_1c209c20 + (uint)bVar4 * 2) & 2) == 0) goto LAB_1c207281;
  }
  else {
    if (bVar4 < 0x7b) {
      pbVar11 = *(byte **)(&DAT_1c24c7cc + (char)bVar4 * 4);
      goto LAB_1c20728f;
    }
LAB_1c207281:
    pbVar11 = PTR_DAT_1c24c93c;
  }
  bVar3 = true;
LAB_1c20728f:
  do {
    bVar4 = *pbVar11;
    pbVar9 = pbVar11;
    while (bVar4 != 0x5b) {
      pbVar9 = pbVar9 + 1;
      bVar4 = *pbVar9;
    }
    pbVar10 = pbVar9 + 1;
    pbVar8 = pbVar7;
    if (bVar3) {
      if (*pbVar10 == 0x2a) {
        *local_10 = '\0';
        param_1[1] = (int)local_10;
        *param_1 = (int)(pbVar7 + (*param_1 - param_1[2]));
        param_1[2] = (int)pbVar7;
        return 0;
      }
    }
    else if (((char)pbVar7[1] < (char)pbVar9[2]) || (*pbVar10 == 0x2a)) {
      *local_10 = '\0';
      param_1[1] = (int)local_10;
      *param_1 = (int)(pbVar7 + (*param_1 - param_1[2]));
      param_1[2] = (int)pbVar7;
      return 0;
    }
    do {
      if (*pbVar10 == 0x5d) {
        iVar5 = -1;
        local_8 = 0;
        pbVar9 = pbVar9 + -1;
        pbVar11 = pbVar7 + -1;
        goto LAB_1c20733b;
      }
      iVar5 = FUN_1c207180(*pbVar10);
      if (iVar5 == 0) {
        bVar4 = FUN_1c2070b0(*pbVar8);
      }
      else {
        bVar4 = *pbVar8;
      }
      pbVar11 = pbVar10 + 1;
      bVar2 = *pbVar10;
      pbVar8 = pbVar8 + 1;
      pbVar10 = pbVar11;
    } while (bVar2 == bVar4);
  } while( true );
LAB_1c20733b:
  bVar4 = *pbVar9;
joined_r0x1c20733e:
  if ((bVar4 == 0x5c) || (bVar4 = *pbVar9, bVar4 == 0x3d)) goto LAB_1c207570;
  if (((&DAT_1c209c21)[(uint)bVar4 * 2] & 4) != 0) {
    switch(bVar4) {
    case 0x20:
      if (((&DAT_1c209c20)[(uint)*pbVar11 * 2] & 0x80) != 0) {
        pbVar11 = pbVar9 + 1;
        bVar4 = *pbVar11;
        while (bVar4 != 0x5c) {
          pbVar11 = pbVar11 + 1;
          bVar4 = *pbVar11;
        }
        goto LAB_1c20728f;
      }
      pbVar9 = pbVar9 + iVar5;
      pbVar11 = pbVar11 + iVar5;
      break;
    case 0x23:
    case 0x2b:
      if (((&DAT_1c209c20)[(uint)*pbVar11 * 2] & 0x40) == 0) {
        pbVar11 = pbVar9 + 1;
        bVar4 = *pbVar11;
        while (bVar4 != 0x5c) {
          pbVar11 = pbVar11 + 1;
          bVar4 = *pbVar11;
        }
        goto LAB_1c20728f;
      }
      pbVar9 = pbVar9 + iVar5;
      pbVar11 = pbVar11 + iVar5;
      break;
    case 0x25:
      pbVar1 = pbVar11 + 2;
      if (*pbVar11 == 0x45) {
        bVar4 = pbVar11[1];
        if (bVar4 == 0x52) {
          bVar4 = *pbVar1;
          iVar6 = 3;
          goto LAB_1c207446;
        }
        if ((bVar4 == 0x4c) && (*pbVar1 == 0x59)) {
          iVar6 = 3;
        }
        else if ((bVar4 == 0x53) || (bVar4 == 0x44)) {
          iVar6 = 2;
        }
        else {
          iVar6 = 1;
        }
      }
      else {
        if (((*pbVar11 != 0x49) || (pbVar11[1] != 0x4e)) || (*pbVar1 != 0x47)) {
          pbVar11 = pbVar9 + 1;
          bVar4 = *pbVar11;
          while (bVar4 != 0x5c) {
            pbVar11 = pbVar11 + 1;
            bVar4 = *pbVar11;
          }
          goto LAB_1c20728f;
        }
        bVar4 = pbVar11[3];
        iVar6 = 4;
LAB_1c207446:
        iVar6 = iVar6 + -1 + (uint)(bVar4 == 0x53);
      }
      pbVar11 = pbVar11 + iVar6;
      if (((&DAT_1c209c20)[(uint)*pbVar11 * 2] & 0x80) == 0) goto LAB_1c207565;
      pbVar11 = pbVar9 + 1;
      bVar4 = *pbVar11;
      while (bVar4 != 0x5c) {
        pbVar11 = pbVar11 + 1;
        bVar4 = *pbVar11;
      }
      goto LAB_1c20728f;
    case 0x26:
      if (*pbVar11 == 0x48) {
        if ((pbVar11[-1] != 0x43) && (pbVar11[-1] != 0x53)) {
          pbVar11 = pbVar9 + 1;
          bVar4 = *pbVar11;
          while (bVar4 != 0x5c) {
            pbVar11 = pbVar11 + 1;
            bVar4 = *pbVar11;
          }
          goto LAB_1c20728f;
        }
        pbVar9 = pbVar9 + iVar5;
        pbVar11 = pbVar11 + iVar5 * 2;
      }
      else {
        if (((&DAT_1c209c20)[(uint)*pbVar11 * 2] & 0x10) == 0) {
          pbVar11 = pbVar9 + 1;
          bVar4 = *pbVar11;
          while (bVar4 != 0x5c) {
            pbVar11 = pbVar11 + 1;
            bVar4 = *pbVar11;
          }
          goto LAB_1c20728f;
        }
        pbVar9 = pbVar9 + iVar5;
        pbVar11 = pbVar11 + iVar5;
      }
      break;
    case 0x2e:
      if (((byte)*(undefined2 *)(&DAT_1c209c20 + (uint)*pbVar11 * 2) & 0x28) != 0x28) {
        pbVar11 = pbVar9 + 1;
        bVar4 = *pbVar11;
        while (bVar4 != 0x5c) {
          pbVar11 = pbVar11 + 1;
          bVar4 = *pbVar11;
        }
        goto LAB_1c20728f;
      }
      pbVar9 = pbVar9 + iVar5;
      pbVar11 = pbVar11 + iVar5;
      break;
    case 0x3a:
      if (((&DAT_1c209c20)[(uint)*pbVar11 * 2] & 0x20) != 0) {
        do {
          pbVar11 = pbVar11 + iVar5;
        } while ((*(ushort *)(&DAT_1c209c20 + (uint)*pbVar11 * 2) & 0x20) != 0);
      }
LAB_1c207565:
      pbVar9 = pbVar9 + iVar5;
      break;
    case 0x3e:
      if (((&DAT_1c209c20)[(uint)*pbVar11 * 2] & 1) != 0) {
        pbVar11 = pbVar9 + 1;
        bVar4 = *pbVar11;
        while (bVar4 != 0x5c) {
          pbVar11 = pbVar11 + 1;
          bVar4 = *pbVar11;
        }
        goto LAB_1c20728f;
      }
      pbVar9 = pbVar9 + iVar5;
      pbVar11 = pbVar11 + iVar5;
      break;
    case 0x3f:
      if (((&DAT_1c209c20)[(uint)*pbVar11 * 2] & 2) == 0) {
        pbVar11 = pbVar9 + 1;
        bVar4 = *pbVar11;
        while (bVar4 != 0x5c) {
          pbVar11 = pbVar11 + 1;
          bVar4 = *pbVar11;
        }
        goto LAB_1c20728f;
      }
      pbVar9 = pbVar9 + iVar5;
      pbVar11 = pbVar11 + iVar5;
      break;
    case 0x40:
      if (*pbVar11 == 0x48) {
        bVar4 = pbVar11[-1];
        if (((bVar4 != 0x54) && (bVar4 != 0x43)) && (bVar4 != 0x53)) {
          pbVar11 = pbVar9 + 1;
          bVar4 = *pbVar11;
          while (bVar4 != 0x5c) {
            pbVar11 = pbVar11 + 1;
            bVar4 = *pbVar11;
          }
          goto LAB_1c20728f;
        }
        pbVar9 = pbVar9 + iVar5;
        pbVar11 = pbVar11 + iVar5 * 2;
      }
      else {
        if (((&DAT_1c209c20)[(uint)*pbVar11 * 2] & 4) == 0) {
          pbVar11 = pbVar9 + 1;
          bVar4 = *pbVar11;
          while (bVar4 != 0x5c) {
            pbVar11 = pbVar11 + 1;
            bVar4 = *pbVar11;
          }
          goto LAB_1c20728f;
        }
        pbVar9 = pbVar9 + iVar5;
        pbVar11 = pbVar11 + iVar5;
      }
      break;
    case 0x5e:
      if (((&DAT_1c209c20)[(uint)*pbVar11 * 2] & 0x20) == 0) {
        pbVar11 = pbVar9 + 1;
        bVar4 = *pbVar11;
        while (bVar4 != 0x5c) {
          pbVar11 = pbVar11 + 1;
          bVar4 = *pbVar11;
        }
        goto LAB_1c20728f;
      }
      pbVar9 = pbVar9 + iVar5;
      pbVar11 = pbVar11 + iVar5;
    }
switchD_1c20739c_caseD_21:
    bVar4 = *pbVar9;
    goto joined_r0x1c20733e;
  }
  iVar6 = FUN_1c207180(bVar4);
  bVar4 = *pbVar11;
  if (iVar6 == 0) {
    bVar4 = FUN_1c2070b0(bVar4);
  }
  if (*pbVar9 == bVar4) {
    pbVar9 = pbVar9 + iVar5;
    pbVar11 = pbVar11 + iVar5;
    goto switchD_1c20739c_caseD_21;
  }
  pbVar11 = pbVar9 + 1;
  bVar4 = *pbVar11;
  while (bVar4 != 0x5c) {
    pbVar11 = pbVar11 + 1;
    bVar4 = *pbVar11;
  }
  goto LAB_1c20728f;
LAB_1c207570:
  local_8 = local_8 + 1;
  if (local_8 < 2) {
    iVar5 = 1;
    pbVar9 = pbVar10 + 1;
    pbVar11 = pbVar8;
    goto LAB_1c20733b;
  }
  iVar5 = 0;
  pbVar9 = pbVar9 + 1;
  param_1[7] = 2;
  bVar4 = *pbVar9;
  pbVar11 = pbVar9;
  while (bVar4 != 0x5c) {
    iVar5 = iVar5 + 1;
    pbVar11 = pbVar11 + 1;
    bVar4 = *pbVar11;
  }
  if (param_1[5] < iVar5) {
    return 1;
  }
  strncat(local_10,(char *)pbVar9,(int)(short)iVar5);
  local_10 = local_10 + iVar5;
  param_1[5] = param_1[5] - iVar5;
  *param_1 = (int)(pbVar7 + (*param_1 - param_1[2]));
  param_1[1] = (int)local_10;
  param_1[2] = (int)pbVar7;
  pbVar7 = pbVar8;
  goto LAB_1c20724d;
}


// ==== FUN_1c2077b0 @ 1c2077b0 size=209

undefined4 __cdecl FUN_1c2077b0(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  
  pbVar4 = *(byte **)(param_1 + 4);
  bVar1 = *pbVar4;
  while (bVar1 != 0x20) {
    bVar1 = *pbVar4;
    if ((((*(ushort *)(&DAT_1c209c20 + (uint)bVar1 * 2) & 2) != 0) && (bVar1 != 0x31)) &&
       (bVar1 != 0x32)) {
      return 0;
    }
    pbVar4 = pbVar4 + -1;
    bVar1 = *pbVar4;
  }
  pbVar4 = pbVar4 + 1;
  iVar5 = (-(uint)((*(uint *)(param_1 + 0x18) & 2) == 0) & 0xfffffffe) + 0x12;
  bVar1 = *pbVar4;
  do {
    if (bVar1 == 0) {
      return 0;
    }
    iVar7 = 0;
    if (0 < iVar5) {
      pcVar6 = s_IYIHEHAEAAAOUHAHEREYAYOYAWOWUWOH_1c24c940;
      do {
        if ((*pcVar6 == *pbVar4) && (pbVar4[1] == pcVar6[1])) {
          pbVar4 = pbVar4 + 2;
          if (((&DAT_1c209c20)[(uint)*pbVar4 * 2] & 2) != 0) {
            return 0;
          }
          if (0 < *(int *)(param_1 + 0x14)) {
            *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
            bVar1 = *pbVar4;
            bVar3 = 0x35;
            while (bVar1 != 0) {
              bVar2 = *pbVar4;
              *pbVar4 = bVar3;
              pbVar4 = pbVar4 + 1;
              bVar3 = bVar2;
              bVar1 = *pbVar4;
            }
            *pbVar4 = bVar3;
            pbVar4[1] = 0;
            *(byte **)(param_1 + 4) = pbVar4 + 1;
            return 0;
          }
          return 1;
        }
        pcVar6 = pcVar6 + 2;
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar5);
    }
    pbVar4 = pbVar4 + 1;
    bVar1 = *pbVar4;
  } while( true );
}


// ==== FUN_1c207890 @ 1c207890 size=2067

undefined4 __cdecl FUN_1c207890(char *param_1,byte *param_2,char *param_3)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  size_t sVar5;
  undefined3 extraout_var;
  uint uVar6;
  char *pcVar7;
  size_t sVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  size_t sVar12;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  char *pcVar17;
  char *pcVar18;
  size_t sVar19;
  char *pcVar20;
  bool bVar21;
  bool bVar22;
  uint local_34;
  uint local_2c;
  int local_28;
  int local_20;
  int local_1c;
  int local_18;
  
  uVar6 = 0xffffffff;
  pcVar18 = param_1;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar18;
    pcVar18 = pcVar18 + 1;
  } while (cVar1 != '\0');
  iVar16 = ~uVar6 - 1;
  bVar21 = *param_1 == '$';
  if (bVar21) {
    param_1 = param_1 + 1;
    iVar16 = ~uVar6 - 2;
  }
  pcVar18 = param_1 + iVar16 + -1;
  bVar22 = *pcVar18 == '%';
  if (bVar22) {
    iVar16 = iVar16 + -1;
    *pcVar18 = '\0';
  }
  sVar5 = strcspn(param_1,(char *)&DAT_1c24ca00);
  if (0x52 < (int)sVar5) {
    if (bVar22) {
      *pcVar18 = '%';
    }
    return 0;
  }
  local_28 = (iVar16 - sVar5) + -1;
  if (local_28 < 1) {
    local_28 = 0;
  }
  bVar4 = FUN_1c2080d0((char *)param_2);
  iVar16 = CONCAT31(extraout_var,bVar4);
  if (((bVar21) && (sVar5 == 1)) && (*param_1 == '1')) {
    bVar4 = true;
  }
  else {
    bVar4 = false;
  }
  if (((bVar21) && ((local_28 == 2 || (local_28 == 0)))) && (iVar16 == 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  bVar3 = true;
  iVar11 = 0;
  pcVar7 = &DAT_1c250130 + (sVar5 - !bVar21);
  sVar19 = sVar5;
  while (sVar19 != 0) {
    sVar19 = sVar19 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + -1;
    if (cVar1 == '#') {
      iVar11 = iVar11 + 1;
    }
    else if ((cVar1 == ',') && (iVar11 == 3)) {
      iVar11 = 0;
    }
    else {
      bVar3 = false;
    }
  }
  if (3 < iVar11) {
    bVar3 = false;
  }
  if ((local_28 != 0) && (pcVar7 = strchr(param_1 + sVar5 + 1,0x2e), pcVar7 != (char *)0x0)) {
    bVar3 = false;
  }
  if (!bVar3) {
    if (bVar22) {
      *pcVar18 = '%';
    }
    return 0;
  }
  local_18 = 0;
  pcVar7 = param_1;
  sVar8 = sVar5;
  sVar19 = sVar5;
  if (0 < (int)sVar5) {
    do {
      local_18 = local_18 + (uint)(*pcVar7 == ',');
      sVar8 = sVar8 - 1;
      pcVar7 = pcVar7 + 1;
    } while (sVar8 != 0);
  }
  for (; 0 < (int)sVar19; sVar19 = sVar19 - (sVar12 + 1)) {
    sVar8 = strcspn(param_1,&DAT_1c24c9fc);
    sVar12 = 3;
    if (sVar8 < 3) {
      sVar12 = strcspn(param_1,&DAT_1c24c9fc);
    }
    local_1c = 0;
    local_20 = 0;
    local_2c = 0;
    if (sVar12 == 1) {
LAB_1c207a98:
      local_1c = *param_1 + -0x30;
      param_1 = param_1 + 1;
    }
    else {
      if (sVar12 == 2) {
LAB_1c207a8d:
        local_20 = *param_1 + -0x30;
        param_1 = param_1 + 1;
        goto LAB_1c207a98;
      }
      if (sVar12 == 3) {
        local_2c = *param_1 + -0x30;
        param_1 = param_1 + 1;
        goto LAB_1c207a8d;
      }
    }
    if (local_2c != 0) {
      uVar6 = 0xffffffff;
      pcVar7 = (&PTR_DAT_1c24cfc8)[local_2c];
      do {
        pcVar17 = pcVar7;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar17 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar17;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar11 = -1;
      pcVar7 = param_3;
      do {
        pcVar20 = pcVar7;
        if (iVar11 == 0) break;
        iVar11 = iVar11 + -1;
        pcVar20 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar20;
      } while (cVar1 != '\0');
      pcVar7 = pcVar17 + -uVar6;
      pcVar17 = pcVar20 + -1;
      for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar17 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar17 = pcVar17 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar17 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar17 = pcVar17 + 1;
      }
      uVar6 = 0xffffffff;
      pcVar7 = &DAT_1c24c9f0;
      do {
        pcVar17 = pcVar7;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar17 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar17;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar11 = -1;
      pcVar7 = param_3;
      do {
        pcVar20 = pcVar7;
        if (iVar11 == 0) break;
        iVar11 = iVar11 + -1;
        pcVar20 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar20;
      } while (cVar1 != '\0');
      pcVar7 = pcVar17 + -uVar6;
      pcVar17 = pcVar20 + -1;
      for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar17 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar17 = pcVar17 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar17 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar17 = pcVar17 + 1;
      }
    }
    if (local_20 < 2) {
      iVar11 = local_1c + local_20 * 10;
      if (iVar11 != 0) {
        local_34 = 0xffffffff;
        pcVar7 = (&PTR_DAT_1c24cfc8)[iVar11];
        do {
          pcVar17 = pcVar7;
          if (local_34 == 0) break;
          local_34 = local_34 - 1;
          pcVar17 = pcVar7 + 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar17;
        } while (cVar1 != '\0');
        local_34 = ~local_34;
        iVar11 = -1;
        pcVar7 = param_3;
        do {
          pcVar20 = pcVar7;
          if (iVar11 == 0) break;
          iVar11 = iVar11 + -1;
          pcVar20 = pcVar7 + 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar20;
        } while (cVar1 != '\0');
        pcVar7 = pcVar17 + -local_34;
        pcVar17 = pcVar20 + -1;
        for (uVar6 = local_34 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar17 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pcVar17 = pcVar17 + 4;
        }
        goto LAB_1c207bf2;
      }
    }
    else {
      uVar6 = 0xffffffff;
      pcVar7 = (&PTR_DAT_1c24d018)[local_20];
      do {
        pcVar17 = pcVar7;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar17 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar17;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar11 = -1;
      pcVar7 = param_3;
      do {
        pcVar20 = pcVar7;
        if (iVar11 == 0) break;
        iVar11 = iVar11 + -1;
        pcVar20 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar20;
      } while (cVar1 != '\0');
      pcVar7 = pcVar17 + -uVar6;
      pcVar17 = pcVar20 + -1;
      for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar17 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar17 = pcVar17 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar17 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar17 = pcVar17 + 1;
      }
      if (local_1c != 0) {
        local_34 = 0xffffffff;
        pcVar7 = (&PTR_DAT_1c24cfc8)[local_1c];
        do {
          pcVar17 = pcVar7;
          if (local_34 == 0) break;
          local_34 = local_34 - 1;
          pcVar17 = pcVar7 + 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar17;
        } while (cVar1 != '\0');
        local_34 = ~local_34;
        iVar11 = -1;
        pcVar7 = param_3;
        do {
          pcVar20 = pcVar7;
          if (iVar11 == 0) break;
          iVar11 = iVar11 + -1;
          pcVar20 = pcVar7 + 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar20;
        } while (cVar1 != '\0');
        pcVar7 = pcVar17 + -local_34;
        pcVar17 = pcVar20 + -1;
        for (uVar6 = local_34 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar17 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pcVar17 = pcVar17 + 4;
        }
LAB_1c207bf2:
        for (local_34 = local_34 & 3; local_34 != 0; local_34 = local_34 - 1) {
          *pcVar17 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          pcVar17 = pcVar17 + 1;
        }
      }
    }
    local_2c = (uint)(local_2c + local_20 + local_1c == 0);
    if (local_2c == 0) {
      if (local_18 != 0) {
        uVar6 = 0xffffffff;
        pcVar7 = (&PTR_DAT_1c24cf68)[local_18];
        do {
          pcVar17 = pcVar7;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar17 = pcVar7 + 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar17;
        } while (cVar1 != '\0');
        uVar6 = ~uVar6;
        iVar11 = -1;
        pcVar7 = param_3;
        do {
          pcVar20 = pcVar7;
          if (iVar11 == 0) break;
          iVar11 = iVar11 + -1;
          pcVar20 = pcVar7 + 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar20;
        } while (cVar1 != '\0');
        pcVar7 = pcVar17 + -uVar6;
        pcVar17 = pcVar20 + -1;
        for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
          *(undefined4 *)pcVar17 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pcVar17 = pcVar17 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar17 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          pcVar17 = pcVar17 + 1;
        }
        uVar6 = 0xffffffff;
        local_18 = local_18 + -1;
        pcVar7 = (char *)&DAT_1c24c9e0;
        do {
          pcVar17 = pcVar7;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar17 = pcVar7 + 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar17;
        } while (cVar1 != '\0');
        uVar6 = ~uVar6;
        iVar11 = -1;
        pcVar7 = param_3;
        do {
          pcVar20 = pcVar7;
          if (iVar11 == 0) break;
          iVar11 = iVar11 + -1;
          pcVar20 = pcVar7 + 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar20;
        } while (cVar1 != '\0');
        pcVar7 = pcVar17 + -uVar6;
        pcVar17 = pcVar20 + -1;
        for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
          *(undefined4 *)pcVar17 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pcVar17 = pcVar17 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar17 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          pcVar17 = pcVar17 + 1;
        }
      }
    }
    else {
      if ((int)sVar19 < 4) {
        while (bVar3 = sVar19 != 0, sVar19 = sVar19 - 1, bVar3) {
          uVar6 = 0xffffffff;
          pcVar7 = &DAT_1c24c9e4;
          do {
            pcVar17 = pcVar7;
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            pcVar17 = pcVar7 + 1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar17;
          } while (cVar1 != '\0');
          uVar6 = ~uVar6;
          iVar11 = -1;
          pcVar7 = param_3;
          do {
            pcVar20 = pcVar7;
            if (iVar11 == 0) break;
            iVar11 = iVar11 + -1;
            pcVar20 = pcVar7 + 1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar20;
          } while (cVar1 != '\0');
          pcVar7 = pcVar17 + -uVar6;
          pcVar17 = pcVar20 + -1;
          for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
            *(undefined4 *)pcVar17 = *(undefined4 *)pcVar7;
            pcVar7 = pcVar7 + 4;
            pcVar17 = pcVar17 + 4;
          }
          for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
            *pcVar17 = *pcVar7;
            pcVar7 = pcVar7 + 1;
            pcVar17 = pcVar17 + 1;
          }
        }
      }
      local_18 = local_18 + -1;
    }
    param_1 = param_1 + 1;
  }
  if ((local_2c != 0) && (pcVar7 = strrchr(param_3,0x2c), pcVar7 != (char *)0x0)) {
    *pcVar7 = '\0';
  }
  if (sVar5 == 0) {
    param_1 = param_1 + 1;
  }
  if (bVar21) {
    if (bVar2) {
      if (bVar4) {
        pcVar7 = &DAT_1c24c9d4;
LAB_1c207d4b:
        uVar6 = 0xffffffff;
        do {
          pcVar17 = pcVar7;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar17 = pcVar7 + 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar17;
        } while (cVar1 != '\0');
        uVar6 = ~uVar6;
        iVar11 = -1;
        pcVar7 = param_3;
        do {
          pcVar20 = pcVar7;
          if (iVar11 == 0) break;
          iVar11 = iVar11 + -1;
          pcVar20 = pcVar7 + 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar20;
        } while (cVar1 != '\0');
        pcVar7 = pcVar17 + -uVar6;
        pcVar17 = pcVar20 + -1;
        for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
          *(undefined4 *)pcVar17 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pcVar17 = pcVar17 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar17 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          pcVar17 = pcVar17 + 1;
        }
      }
      else if (sVar5 != 0) {
        pcVar7 = &DAT_1c24c9c8;
        goto LAB_1c207d4b;
      }
      if (local_28 == 2) {
        cVar1 = *param_1;
        iVar15 = cVar1 + -0x30;
        iVar13 = param_1[1] + -0x30;
        param_1 = param_1 + 2;
        iVar11 = iVar13 + (cVar1 * 5 + -0xf0) * 2;
        if (iVar11 != 0) {
          if (sVar5 != 0) {
            uVar6 = 0xffffffff;
            pcVar7 = (char *)&DAT_1c24c9c0;
            do {
              pcVar17 = pcVar7;
              if (uVar6 == 0) break;
              uVar6 = uVar6 - 1;
              pcVar17 = pcVar7 + 1;
              cVar1 = *pcVar7;
              pcVar7 = pcVar17;
            } while (cVar1 != '\0');
            uVar6 = ~uVar6;
            iVar10 = -1;
            pcVar7 = param_3;
            do {
              pcVar20 = pcVar7;
              if (iVar10 == 0) break;
              iVar10 = iVar10 + -1;
              pcVar20 = pcVar7 + 1;
              cVar1 = *pcVar7;
              pcVar7 = pcVar20;
            } while (cVar1 != '\0');
            pcVar7 = pcVar17 + -uVar6;
            pcVar17 = pcVar20 + -1;
            for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
              *(undefined4 *)pcVar17 = *(undefined4 *)pcVar7;
              pcVar7 = pcVar7 + 4;
              pcVar17 = pcVar17 + 4;
            }
            for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
              *pcVar17 = *pcVar7;
              pcVar7 = pcVar7 + 1;
              pcVar17 = pcVar17 + 1;
            }
          }
          if (iVar15 < 2) {
            pcVar7 = (&PTR_DAT_1c24cfc8)[iVar11];
LAB_1c207e38:
            uVar6 = 0xffffffff;
            do {
              pcVar17 = pcVar7;
              if (uVar6 == 0) break;
              uVar6 = uVar6 - 1;
              pcVar17 = pcVar7 + 1;
              cVar1 = *pcVar7;
              pcVar7 = pcVar17;
            } while (cVar1 != '\0');
            uVar6 = ~uVar6;
            iVar13 = -1;
            pcVar7 = param_3;
            do {
              pcVar20 = pcVar7;
              if (iVar13 == 0) break;
              iVar13 = iVar13 + -1;
              pcVar20 = pcVar7 + 1;
              cVar1 = *pcVar7;
              pcVar7 = pcVar20;
            } while (cVar1 != '\0');
            pcVar7 = pcVar17 + -uVar6;
            pcVar17 = pcVar20 + -1;
            for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
              *(undefined4 *)pcVar17 = *(undefined4 *)pcVar7;
              pcVar7 = pcVar7 + 4;
              pcVar17 = pcVar17 + 4;
            }
            for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
              *pcVar17 = *pcVar7;
              pcVar7 = pcVar7 + 1;
              pcVar17 = pcVar17 + 1;
            }
          }
          else {
            uVar6 = 0xffffffff;
            pcVar7 = (&PTR_DAT_1c24d018)[iVar15];
            do {
              pcVar17 = pcVar7;
              if (uVar6 == 0) break;
              uVar6 = uVar6 - 1;
              pcVar17 = pcVar7 + 1;
              cVar1 = *pcVar7;
              pcVar7 = pcVar17;
            } while (cVar1 != '\0');
            uVar6 = ~uVar6;
            iVar15 = -1;
            pcVar7 = param_3;
            do {
              pcVar20 = pcVar7;
              if (iVar15 == 0) break;
              iVar15 = iVar15 + -1;
              pcVar20 = pcVar7 + 1;
              cVar1 = *pcVar7;
              pcVar7 = pcVar20;
            } while (cVar1 != '\0');
            pcVar7 = pcVar17 + -uVar6;
            pcVar17 = pcVar20 + -1;
            for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
              *(undefined4 *)pcVar17 = *(undefined4 *)pcVar7;
              pcVar7 = pcVar7 + 4;
              pcVar17 = pcVar17 + 4;
            }
            for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
              *pcVar17 = *pcVar7;
              pcVar7 = pcVar7 + 1;
              pcVar17 = pcVar17 + 1;
            }
            if (iVar13 != 0) {
              pcVar7 = (&PTR_DAT_1c24cfc8)[iVar13];
              goto LAB_1c207e38;
            }
          }
          if (iVar11 == 1) {
            pcVar7 = &DAT_1c24c9b8;
          }
          else {
            pcVar7 = s_SEH5NTS_1c24c9ac;
          }
          uVar6 = 0xffffffff;
          do {
            pcVar17 = pcVar7;
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            pcVar17 = pcVar7 + 1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar17;
          } while (cVar1 != '\0');
          uVar6 = ~uVar6;
          iVar11 = -1;
          pcVar7 = param_3;
          do {
            pcVar20 = pcVar7;
            if (iVar11 == 0) break;
            iVar11 = iVar11 + -1;
            pcVar20 = pcVar7 + 1;
            cVar1 = *pcVar7;
            pcVar7 = pcVar20;
          } while (cVar1 != '\0');
          pcVar7 = pcVar17 + -uVar6;
          pcVar17 = pcVar20 + -1;
          for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
            *(undefined4 *)pcVar17 = *(undefined4 *)pcVar7;
            pcVar7 = pcVar7 + 4;
            pcVar17 = pcVar17 + 4;
          }
          for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
            *pcVar17 = *pcVar7;
            pcVar7 = pcVar7 + 1;
            pcVar17 = pcVar17 + 1;
          }
        }
      }
    }
    if ((!bVar21) || (!bVar2)) goto LAB_1c207eb7;
  }
  else {
LAB_1c207eb7:
    if (local_28 != 0) {
      uVar6 = 0xffffffff;
      pcVar7 = &DAT_1c24c9a4;
      do {
        pcVar17 = pcVar7;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar17 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar17;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar11 = -1;
      pcVar7 = param_3;
      do {
        pcVar20 = pcVar7;
        if (iVar11 == 0) break;
        iVar11 = iVar11 + -1;
        pcVar20 = pcVar7 + 1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar20;
      } while (cVar1 != '\0');
      pcVar7 = pcVar17 + -uVar6;
      pcVar17 = pcVar20 + -1;
      for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined4 *)pcVar17 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar17 = pcVar17 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar17 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar17 = pcVar17 + 1;
      }
      while (local_28 != 0) {
        local_28 = local_28 + -1;
        uVar6 = 0xffffffff;
        pcVar7 = *(char **)(&DAT_1c24cf08 + *param_1 * 4);
        do {
          pcVar17 = pcVar7;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar17 = pcVar7 + 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar17;
        } while (cVar1 != '\0');
        uVar6 = ~uVar6;
        iVar11 = -1;
        pcVar7 = param_3;
        do {
          pcVar20 = pcVar7;
          if (iVar11 == 0) break;
          iVar11 = iVar11 + -1;
          pcVar20 = pcVar7 + 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar20;
        } while (cVar1 != '\0');
        param_1 = param_1 + 1;
        pcVar7 = pcVar17 + -uVar6;
        pcVar17 = pcVar20 + -1;
        for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
          *(undefined4 *)pcVar17 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pcVar17 = pcVar17 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar17 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          pcVar17 = pcVar17 + 1;
        }
      }
    }
  }
  uVar14 = 1;
  if (iVar16 == 0) goto LAB_1c207fc5;
  iVar11 = toupper((uint)*param_2);
  switch(iVar11) {
  case 0x42:
    pcVar7 = s_BIH5LYIN_1c24c98c;
    break;
  default:
    goto switchD_1c207f72_caseD_43;
  case 0x4d:
    pcVar7 = s_MIH5LYIN_1c24c998;
    break;
  case 0x51:
    pcVar7 = s_KWAADRIH5LYIN_1c24c970;
    break;
  case 0x54:
    pcVar7 = &DAT_1c24c980;
  }
  uVar6 = 0xffffffff;
  do {
    pcVar17 = pcVar7;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar17 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar17;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  iVar11 = -1;
  pcVar7 = param_3;
  do {
    pcVar20 = pcVar7;
    if (iVar11 == 0) break;
    iVar11 = iVar11 + -1;
    pcVar20 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar20;
  } while (cVar1 != '\0');
  pcVar7 = pcVar17 + -uVar6;
  pcVar17 = pcVar20 + -1;
  for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
    *(undefined4 *)pcVar17 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar17 = pcVar17 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar17 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar17 = pcVar17 + 1;
  }
switchD_1c207f72_caseD_43:
  uVar14 = 2;
LAB_1c207fc5:
  if ((bVar21) && ((iVar16 != 0 || (!bVar2)))) {
    uVar6 = 0xffffffff;
    pcVar7 = &DAT_1c24c9c8;
    do {
      pcVar17 = pcVar7;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar17 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar17;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar11 = -1;
    pcVar7 = param_3;
    do {
      pcVar20 = pcVar7;
      if (iVar11 == 0) break;
      iVar11 = iVar11 + -1;
      pcVar20 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar20;
    } while (cVar1 != '\0');
    pcVar7 = pcVar17 + -uVar6;
    pcVar17 = pcVar20 + -1;
    for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if ((iVar16 != 0) && (pcVar7 = strchr((char *)param_2,0x29), pcVar7 != (char *)0x0)) {
    uVar6 = 0xffffffff;
    pcVar7 = (char *)&DAT_1c24c9e0;
    do {
      pcVar17 = pcVar7;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar17 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar17;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar16 = -1;
    pcVar7 = param_3;
    do {
      pcVar20 = pcVar7;
      if (iVar16 == 0) break;
      iVar16 = iVar16 + -1;
      pcVar20 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar20;
    } while (cVar1 != '\0');
    pcVar7 = pcVar17 + -uVar6;
    pcVar17 = pcVar20 + -1;
    for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar17 = pcVar17 + 1;
    }
  }
  if (bVar22) {
    uVar6 = 0xffffffff;
    pcVar7 = s_IYIHEHAEAAAOUHAHEREYAYOYAWOWUWOH_1c24c940 + 0x24;
    do {
      pcVar17 = pcVar7;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar17 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar17;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar16 = -1;
    do {
      pcVar7 = param_3;
      if (iVar16 == 0) break;
      iVar16 = iVar16 + -1;
      pcVar7 = param_3 + 1;
      cVar1 = *param_3;
      param_3 = pcVar7;
    } while (cVar1 != '\0');
    pcVar17 = pcVar17 + -uVar6;
    pcVar7 = pcVar7 + -1;
    for (uVar9 = uVar6 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar17;
      pcVar17 = pcVar17 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar7 = *pcVar17;
      pcVar17 = pcVar17 + 1;
      pcVar7 = pcVar7 + 1;
    }
    *pcVar18 = '%';
  }
  return uVar14;
}


// ==== FUN_1c2080d0 @ 1c2080d0 size=119

bool __cdecl FUN_1c2080d0(char *param_1)

{
  int iVar1;
  
  if (param_1 == (char *)0x0) {
    return false;
  }
  iVar1 = strncmp(param_1,s_MILLION_1c24ca24,7);
  if (iVar1 == 0) {
    return true;
  }
  iVar1 = strncmp(param_1,s_BILLION_1c24ca1c,7);
  if (iVar1 == 0) {
    return true;
  }
  iVar1 = strncmp(param_1,s_TRILLION_1c24ca10,8);
  if (iVar1 == 0) {
    return true;
  }
  iVar1 = strncmp(param_1,s_QUADRILLION_1c24ca04,0xb);
  return iVar1 == 0;
}


// ==== FUN_1c208150 @ 1c208150 size=1703

undefined4 __cdecl FUN_1c208150(int *param_1)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  undefined *puVar5;
  int iVar6;
  bool bVar7;
  undefined **ppuVar8;
  int *piVar9;
  uint uVar10;
  size_t sVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  byte *pbVar17;
  char *pcVar18;
  byte *pbVar19;
  char *pcVar20;
  char *pcVar21;
  bool bVar22;
  int iStack_4;
  
  DAT_1c250128 = (byte *)param_1[2];
  if (*DAT_1c250128 == 0) {
    return 0;
  }
  piVar9 = (int *)__p___mb_cur_max();
  if (*piVar9 < 2) {
    uVar12 = (uint)*DAT_1c250128;
    piVar9 = (int *)__p__pctype();
    uVar10 = *(ushort *)(*piVar9 + uVar12 * 2) & 4;
  }
  else {
    uVar12 = (uint)*DAT_1c250128;
    uVar10 = _isctype(uVar12,4);
  }
  if (uVar10 == 0) {
    uVar10 = (uint)DAT_1c250128[1];
    if (uVar12 == 0x24) {
      piVar9 = (int *)__p___mb_cur_max();
      if (*piVar9 < 2) {
        piVar9 = (int *)__p__pctype();
        uVar12 = *(ushort *)(*piVar9 + uVar10 * 2) & 4;
      }
      else {
        uVar12 = _isctype(uVar10,4);
      }
      if ((uVar12 == 0) && (uVar10 != 0x2e)) {
        return 0;
      }
    }
    else if (uVar12 == 0x28) {
      piVar9 = (int *)__p___mb_cur_max();
      if (*piVar9 < 2) {
        piVar9 = (int *)__p__pctype();
        uVar10 = *(ushort *)(*piVar9 + uVar10 * 2) & 4;
      }
      else {
        uVar10 = _isctype(uVar10,4);
      }
      if (uVar10 == 0) {
        return 0;
      }
    }
    else {
      if (uVar12 != 0x2e) {
        return 0;
      }
      piVar9 = (int *)__p___mb_cur_max();
      if (*piVar9 < 2) {
        piVar9 = (int *)__p__pctype();
        uVar10 = *(ushort *)(*piVar9 + uVar10 * 2) & 4;
      }
      else {
        uVar10 = _isctype(uVar10,4);
      }
      if (uVar10 == 0) {
        return 0;
      }
    }
  }
  DAT_1c250130 = 0;
  sVar11 = strspn((char *)DAT_1c250128,s_0123456789___________1c24cbec);
  DAT_1c25011c = DAT_1c250128 + sVar11;
  bVar3 = DAT_1c25011c[-1];
  if ((bVar3 == 0x2c) || (bVar3 == 0x2e)) {
    DAT_1c25011c = DAT_1c25011c + -1;
  }
  bVar3 = *DAT_1c25011c;
  DAT_1c250124 = DAT_1c25011c;
  if (bVar3 != 0) {
    *DAT_1c25011c = 0;
    DAT_1c25011c = DAT_1c25011c + 1;
    bVar4 = *DAT_1c25011c;
    while (bVar4 == 0x20) {
      DAT_1c25011c = DAT_1c25011c + 1;
      bVar4 = *DAT_1c25011c;
    }
  }
  DAT_1c250120 = (byte *)strchr((char *)DAT_1c25011c,0x20);
  if (DAT_1c250120 == (byte *)0x0) {
    uVar10 = 0xffffffff;
    pbVar17 = DAT_1c25011c;
    do {
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
      bVar4 = *pbVar17;
      pbVar17 = pbVar17 + 1;
    } while (bVar4 != 0);
    DAT_1c250120 = DAT_1c25011c + (~uVar10 - 1);
  }
  if ((DAT_1c250120[-1] == 0x2c) || (DAT_1c250120[-1] == 0x2e)) {
    DAT_1c250120 = DAT_1c250120 + -1;
  }
  bVar4 = *DAT_1c250120;
  *DAT_1c250120 = 0;
  uVar10 = 0xffffffff;
  pbVar17 = DAT_1c250128;
  do {
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    bVar1 = *pbVar17;
    pbVar17 = pbVar17 + 1;
  } while (bVar1 != 0);
  iStack_4 = ~uVar10 - 1;
  bVar7 = true;
  pbVar17 = DAT_1c250128;
  if (0x13 < iStack_4) {
    iStack_4 = 0x14;
  }
joined_r0x1c2083be:
  if (iStack_4 != 0) {
    iStack_4 = iStack_4 + -1;
    pbVar19 = pbVar17 + 1;
    uVar10 = (uint)*pbVar17;
    piVar9 = (int *)__p___mb_cur_max();
    if (*piVar9 < 2) {
      piVar9 = (int *)__p__pctype();
      uVar12 = *(ushort *)(*piVar9 + uVar10 * 2) & 0x103;
    }
    else {
      uVar12 = _isctype(uVar10,0x103);
    }
    pbVar17 = pbVar19;
    if (uVar12 != 0) {
      pcVar18 = &DAT_1c24cbe8;
      goto LAB_1c208592;
    }
    piVar9 = (int *)__p___mb_cur_max();
    if (*piVar9 < 2) {
      piVar9 = (int *)__p__pctype();
      uVar12 = *(ushort *)(*piVar9 + uVar10 * 2) & 4;
    }
    else {
      uVar12 = _isctype(uVar10,4);
    }
    if (uVar12 != 0) {
      uVar10 = 0xffffffff;
      pcVar18 = &DAT_1c24cbe4;
      do {
        pcVar21 = pcVar18;
        if (uVar10 == 0) break;
        uVar10 = uVar10 - 1;
        pcVar21 = pcVar18 + 1;
        cVar2 = *pcVar18;
        pcVar18 = pcVar21;
      } while (cVar2 != '\0');
      uVar10 = ~uVar10;
      iVar14 = -1;
      pcVar18 = &DAT_1c250130;
      do {
        pcVar20 = pcVar18;
        if (iVar14 == 0) break;
        iVar14 = iVar14 + -1;
        pcVar20 = pcVar18 + 1;
        cVar2 = *pcVar18;
        pcVar18 = pcVar20;
      } while (cVar2 != '\0');
      pcVar18 = pcVar21 + -uVar10;
      pcVar21 = pcVar20 + -1;
      for (uVar12 = uVar10 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
        *(undefined4 *)pcVar21 = *(undefined4 *)pcVar18;
        pcVar18 = pcVar18 + 4;
        pcVar21 = pcVar21 + 4;
      }
      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *pcVar21 = *pcVar18;
        pcVar18 = pcVar18 + 1;
        pcVar21 = pcVar21 + 1;
      }
      goto joined_r0x1c2083be;
    }
    switch(uVar10) {
    case 0x24:
      uVar10 = 0xffffffff;
      pcVar18 = (char *)&DAT_1c24cbd0;
      do {
        pcVar21 = pcVar18;
        if (uVar10 == 0) break;
        uVar10 = uVar10 - 1;
        pcVar21 = pcVar18 + 1;
        cVar2 = *pcVar18;
        pcVar18 = pcVar21;
      } while (cVar2 != '\0');
      uVar10 = ~uVar10;
      iVar14 = -1;
      pcVar18 = &DAT_1c250130;
      do {
        pcVar20 = pcVar18;
        if (iVar14 == 0) break;
        iVar14 = iVar14 + -1;
        pcVar20 = pcVar18 + 1;
        cVar2 = *pcVar18;
        pcVar18 = pcVar20;
      } while (cVar2 != '\0');
      pcVar18 = pcVar21 + -uVar10;
      pcVar21 = pcVar20 + -1;
      for (uVar12 = uVar10 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
        *(undefined4 *)pcVar21 = *(undefined4 *)pcVar18;
        pcVar18 = pcVar18 + 4;
        pcVar21 = pcVar21 + 4;
      }
      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *pcVar21 = *pcVar18;
        pcVar18 = pcVar18 + 1;
        pcVar21 = pcVar21 + 1;
      }
      goto joined_r0x1c2083be;
    case 0x25:
      uVar10 = 0xffffffff;
      pcVar18 = (char *)&DAT_1c24cbcc;
      do {
        pcVar21 = pcVar18;
        if (uVar10 == 0) break;
        uVar10 = uVar10 - 1;
        pcVar21 = pcVar18 + 1;
        cVar2 = *pcVar18;
        pcVar18 = pcVar21;
      } while (cVar2 != '\0');
      uVar10 = ~uVar10;
      iVar14 = -1;
      pcVar18 = &DAT_1c250130;
      do {
        pcVar20 = pcVar18;
        if (iVar14 == 0) break;
        iVar14 = iVar14 + -1;
        pcVar20 = pcVar18 + 1;
        cVar2 = *pcVar18;
        pcVar18 = pcVar20;
      } while (cVar2 != '\0');
      pcVar18 = pcVar21 + -uVar10;
      pcVar21 = pcVar20 + -1;
      for (uVar12 = uVar10 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
        *(undefined4 *)pcVar21 = *(undefined4 *)pcVar18;
        pcVar18 = pcVar18 + 4;
        pcVar21 = pcVar21 + 4;
      }
      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *pcVar21 = *pcVar18;
        pcVar18 = pcVar18 + 1;
        pcVar21 = pcVar21 + 1;
      }
      goto joined_r0x1c2083be;
    default:
      pcVar18 = &DAT_1c24cbe8;
      break;
    case 0x28:
      pcVar18 = &DAT_1c24cbe0;
      break;
    case 0x29:
      pcVar18 = &DAT_1c24cbdc;
      break;
    case 0x2c:
      uVar10 = 0xffffffff;
      pcVar18 = (char *)&DAT_1c24cbd4;
      do {
        pcVar21 = pcVar18;
        if (uVar10 == 0) break;
        uVar10 = uVar10 - 1;
        pcVar21 = pcVar18 + 1;
        cVar2 = *pcVar18;
        pcVar18 = pcVar21;
      } while (cVar2 != '\0');
      uVar10 = ~uVar10;
      iVar14 = -1;
      pcVar18 = &DAT_1c250130;
      do {
        pcVar20 = pcVar18;
        if (iVar14 == 0) break;
        iVar14 = iVar14 + -1;
        pcVar20 = pcVar18 + 1;
        cVar2 = *pcVar18;
        pcVar18 = pcVar20;
      } while (cVar2 != '\0');
      pcVar18 = pcVar21 + -uVar10;
      pcVar21 = pcVar20 + -1;
      for (uVar12 = uVar10 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
        *(undefined4 *)pcVar21 = *(undefined4 *)pcVar18;
        pcVar18 = pcVar18 + 4;
        pcVar21 = pcVar21 + 4;
      }
      for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
        *pcVar21 = *pcVar18;
        pcVar18 = pcVar18 + 1;
        pcVar21 = pcVar21 + 1;
      }
      goto joined_r0x1c2083be;
    case 0x2d:
      pcVar18 = &DAT_1c24cbd8;
      break;
    case 0x2e:
      goto switchD_1c208483_caseD_2e;
    case 0x2f:
      pcVar18 = &DAT_1c24cbc8;
      break;
    case 0x3a:
      pcVar18 = &DAT_1c24cbc4;
    }
LAB_1c208592:
    uVar10 = 0xffffffff;
    do {
      pcVar21 = pcVar18;
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
      pcVar21 = pcVar18 + 1;
      cVar2 = *pcVar18;
      pcVar18 = pcVar21;
    } while (cVar2 != '\0');
    uVar10 = ~uVar10;
    iVar14 = -1;
    pcVar18 = &DAT_1c250130;
    do {
      pcVar20 = pcVar18;
      if (iVar14 == 0) break;
      iVar14 = iVar14 + -1;
      pcVar20 = pcVar18 + 1;
      cVar2 = *pcVar18;
      pcVar18 = pcVar20;
    } while (cVar2 != '\0');
    pcVar18 = pcVar21 + -uVar10;
    pcVar21 = pcVar20 + -1;
    for (uVar12 = uVar10 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
      *(undefined4 *)pcVar21 = *(undefined4 *)pcVar18;
      pcVar18 = pcVar18 + 4;
      pcVar21 = pcVar21 + 4;
    }
    for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
      *pcVar21 = *pcVar18;
      pcVar18 = pcVar18 + 1;
      pcVar21 = pcVar21 + 1;
    }
    bVar7 = false;
    goto joined_r0x1c2083be;
  }
  iVar14 = 0;
  uVar10 = 0xffffffff;
  DAT_1c24ed90 = 0;
  pcVar18 = &DAT_1c24cbc0;
  do {
    pcVar21 = pcVar18;
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    pcVar21 = pcVar18 + 1;
    cVar2 = *pcVar18;
    pcVar18 = pcVar21;
  } while (cVar2 != '\0');
  uVar10 = ~uVar10;
  iVar15 = -1;
  pcVar18 = &DAT_1c24ed90;
  do {
    pcVar20 = pcVar18;
    if (iVar15 == 0) break;
    iVar15 = iVar15 + -1;
    pcVar20 = pcVar18 + 1;
    cVar2 = *pcVar18;
    pcVar18 = pcVar20;
  } while (cVar2 != '\0');
  pcVar18 = pcVar21 + -uVar10;
  pcVar21 = pcVar20 + -1;
  for (uVar12 = uVar10 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(undefined4 *)pcVar21 = *(undefined4 *)pcVar18;
    pcVar18 = pcVar18 + 4;
    pcVar21 = pcVar21 + 4;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar21 = *pcVar18;
    pcVar18 = pcVar18 + 1;
    pcVar21 = pcVar21 + 1;
  }
  ppuVar8 = &PTR_s________________1c24cae8;
  puVar5 = PTR_LAB_1c24caf0;
  while (puVar5 != (undefined *)0x0) {
    pbVar17 = *ppuVar8;
    pbVar19 = &DAT_1c250130;
    do {
      bVar1 = *pbVar17;
      bVar22 = bVar1 < *pbVar19;
      if (bVar1 != *pbVar19) {
LAB_1c208647:
        iVar15 = (1 - (uint)bVar22) - (uint)(bVar22 != 0);
        goto LAB_1c20864c;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar17[1];
      bVar22 = bVar1 < pbVar19[1];
      if (bVar1 != pbVar19[1]) goto LAB_1c208647;
      pbVar17 = pbVar17 + 2;
      pbVar19 = pbVar19 + 2;
    } while (bVar1 != 0);
    iVar15 = 0;
LAB_1c20864c:
    if (iVar15 == 0) {
      iVar14 = (*(code *)ppuVar8[2])(DAT_1c250128,DAT_1c25011c,&DAT_1c24ed90);
      break;
    }
    puVar5 = ppuVar8[5];
    ppuVar8 = ppuVar8 + 3;
  }
  if ((iVar14 != 0) ||
     (((bVar7 && (iVar14 = FUN_1c207890((char *)DAT_1c250128,DAT_1c25011c,&DAT_1c24ed90),
                 iVar14 != 0)) ||
      (iVar14 = FUN_1c209580(DAT_1c250128,&DAT_1c25011c,&DAT_1c24ed90), iVar14 != 0)))) {
    uVar10 = 0xffffffff;
    pcVar18 = &DAT_1c24ed90;
    do {
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
      cVar2 = *pcVar18;
      pcVar18 = pcVar18 + 1;
    } while (cVar2 != '\0');
    iVar15 = ~uVar10 - 1;
    iVar13 = param_1[5] - iVar15;
    param_1[5] = iVar13;
    if (iVar13 < 1) {
      iVar14 = -1;
    }
    else {
      uVar12 = 0xffffffff;
      pcVar18 = &DAT_1c24ed90;
      do {
        pcVar21 = pcVar18;
        if (uVar12 == 0) break;
        uVar12 = uVar12 - 1;
        pcVar21 = pcVar18 + 1;
        cVar2 = *pcVar18;
        pcVar18 = pcVar21;
      } while (cVar2 != '\0');
      uVar12 = ~uVar12;
      iVar13 = -1;
      pcVar18 = (char *)param_1[1];
      do {
        pcVar20 = pcVar18;
        if (iVar13 == 0) break;
        iVar13 = iVar13 + -1;
        pcVar20 = pcVar18 + 1;
        cVar2 = *pcVar18;
        pcVar18 = pcVar20;
      } while (cVar2 != '\0');
      pcVar18 = pcVar21 + -uVar12;
      pcVar21 = pcVar20 + -1;
      for (uVar16 = uVar12 >> 2; uVar16 != 0; uVar16 = uVar16 - 1) {
        *(undefined4 *)pcVar21 = *(undefined4 *)pcVar18;
        pcVar18 = pcVar18 + 4;
        pcVar21 = pcVar21 + 4;
      }
      for (uVar12 = uVar12 & 3; uVar12 != 0; uVar12 = uVar12 - 1) {
        *pcVar21 = *pcVar18;
        pcVar18 = pcVar18 + 1;
        pcVar21 = pcVar21 + 1;
      }
      iVar13 = ~uVar10 - 2;
      while (iVar6 = iVar13, iVar15 != 0) {
        param_1[1] = param_1[1] + 1;
        iVar13 = iVar6 + -1;
        iVar15 = iVar6;
      }
    }
  }
  *DAT_1c250124 = bVar3;
  *DAT_1c250120 = bVar4;
  switch(iVar14) {
  case 0:
    return 0;
  case 1:
    *param_1 = (int)(DAT_1c250124 + (*param_1 - param_1[2]));
    pbVar17 = DAT_1c250124;
    param_1[7] = 4;
    param_1[2] = (int)pbVar17;
    return 0;
  case 2:
    *param_1 = (int)(DAT_1c250120 + (*param_1 - param_1[2]));
    pbVar17 = DAT_1c250120;
    param_1[7] = 4;
    param_1[2] = (int)pbVar17;
    return 0;
  case 3:
    *param_1 = (int)(DAT_1c25011c + (*param_1 - param_1[2]));
    pbVar17 = DAT_1c25011c;
    param_1[7] = 4;
    param_1[2] = (int)pbVar17;
    return 0;
  case -1:
    return 1;
  default:
    *param_1 = (int)(DAT_1c250124 + (*param_1 - param_1[2]));
    param_1[2] = (int)DAT_1c250124;
    return 0;
  }
switchD_1c208483_caseD_2e:
  uVar10 = 0xffffffff;
  pcVar18 = (char *)&DAT_1c24ca00;
  do {
    pcVar21 = pcVar18;
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    pcVar21 = pcVar18 + 1;
    cVar2 = *pcVar18;
    pcVar18 = pcVar21;
  } while (cVar2 != '\0');
  uVar10 = ~uVar10;
  iVar14 = -1;
  pcVar18 = &DAT_1c250130;
  do {
    pcVar20 = pcVar18;
    if (iVar14 == 0) break;
    iVar14 = iVar14 + -1;
    pcVar20 = pcVar18 + 1;
    cVar2 = *pcVar18;
    pcVar18 = pcVar20;
  } while (cVar2 != '\0');
  pcVar18 = pcVar21 + -uVar10;
  pcVar21 = pcVar20 + -1;
  for (uVar12 = uVar10 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {
    *(undefined4 *)pcVar21 = *(undefined4 *)pcVar18;
    pcVar18 = pcVar18 + 4;
    pcVar21 = pcVar21 + 4;
  }
  for (uVar10 = uVar10 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar21 = *pcVar18;
    pcVar18 = pcVar18 + 1;
    pcVar21 = pcVar21 + 1;
  }
  goto joined_r0x1c2083be;
}


// ==== FUN_1c208850 @ 1c208850 size=553

undefined4 __cdecl FUN_1c208850(char *param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  
  pcVar8 = param_1 + 1;
  if (*pcVar8 == ':') {
    iVar2 = 0;
    iVar4 = *param_1 + -0x30;
  }
  else {
    iVar4 = *pcVar8 + -0x30;
    pcVar8 = param_1 + 2;
    iVar2 = *param_1 + -0x30;
  }
  iVar4 = iVar4 + iVar2 * 10;
  iVar6 = pcVar8[1] + -0x30;
  iVar7 = pcVar8[2] + -0x30;
  iVar2 = iVar7 + iVar6 * 10;
  if (((iVar4 < 1) || (0xc < iVar4)) || (0x3b < iVar2)) {
    return 0;
  }
  uVar3 = 0xffffffff;
  pcVar8 = (&PTR_DAT_1c24cfc8)[iVar4];
  do {
    pcVar9 = pcVar8;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar9 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar9;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  iVar4 = -1;
  pcVar8 = param_3;
  do {
    pcVar10 = pcVar8;
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    pcVar10 = pcVar8 + 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar10;
  } while (cVar1 != '\0');
  pcVar8 = pcVar9 + -uVar3;
  pcVar9 = pcVar10 + -1;
  for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar9 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar9 = pcVar9 + 1;
  }
  if (iVar2 == 0) {
    uVar3 = 0xffffffff;
    pcVar8 = &DAT_1c24cc04;
    do {
      pcVar9 = pcVar8;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar9 = pcVar8 + 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar9;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    iVar4 = -1;
    do {
      pcVar8 = param_3;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar8 = param_3 + 1;
      cVar1 = *param_3;
      param_3 = pcVar8;
    } while (cVar1 != '\0');
    pcVar9 = pcVar9 + -uVar3;
    pcVar8 = pcVar8 + -1;
    for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar8 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar8 = pcVar8 + 1;
    }
  }
  else {
    if (iVar6 == 0) {
      uVar3 = 0xffffffff;
      pcVar8 = (char *)&DAT_1c24cc10;
      do {
        pcVar9 = pcVar8;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar9 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar9;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      iVar4 = -1;
      pcVar8 = param_3;
      do {
        pcVar10 = pcVar8;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar10 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar10;
      } while (cVar1 != '\0');
      pcVar8 = pcVar9 + -uVar3;
      pcVar9 = pcVar10 + -1;
      for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar9 = pcVar9 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar9 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar9 = pcVar9 + 1;
      }
      uVar3 = 0xffffffff;
      pcVar8 = (&PTR_DAT_1c24cfc8)[iVar7];
      do {
        pcVar9 = pcVar8;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar9 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar9;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      iVar4 = -1;
      do {
        pcVar8 = param_3;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar8 = param_3 + 1;
        cVar1 = *param_3;
        param_3 = pcVar8;
      } while (cVar1 != '\0');
      pcVar9 = pcVar9 + -uVar3;
      pcVar8 = pcVar8 + -1;
      for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar8 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        pcVar8 = pcVar8 + 1;
      }
      return 1;
    }
    if (iVar6 == 1) {
      uVar3 = 0xffffffff;
      pcVar8 = (&PTR_DAT_1c24cfc8)[iVar2];
      do {
        pcVar9 = pcVar8;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar9 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar9;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      iVar4 = -1;
      do {
        pcVar8 = param_3;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar8 = param_3 + 1;
        cVar1 = *param_3;
        param_3 = pcVar8;
      } while (cVar1 != '\0');
      pcVar9 = pcVar9 + -uVar3;
      pcVar8 = pcVar8 + -1;
      for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar8 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        pcVar8 = pcVar8 + 1;
      }
      return 1;
    }
    uVar3 = 0xffffffff;
    pcVar8 = (&PTR_DAT_1c24d040)[iVar6];
    do {
      pcVar9 = pcVar8;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar9 = pcVar8 + 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar9;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    iVar4 = -1;
    pcVar8 = param_3;
    do {
      pcVar10 = pcVar8;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar10 = pcVar8 + 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar10;
    } while (cVar1 != '\0');
    pcVar8 = pcVar9 + -uVar3;
    pcVar9 = pcVar10 + -1;
    for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar9 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar9 = pcVar9 + 1;
    }
    if (iVar7 != 0) {
      uVar3 = 0xffffffff;
      pcVar8 = (&PTR_DAT_1c24cfc8)[iVar7];
      do {
        pcVar9 = pcVar8;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar9 = pcVar8 + 1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar9;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      iVar4 = -1;
      do {
        pcVar8 = param_3;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar8 = param_3 + 1;
        cVar1 = *param_3;
        param_3 = pcVar8;
      } while (cVar1 != '\0');
      pcVar9 = pcVar9 + -uVar3;
      pcVar8 = pcVar8 + -1;
      for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar8 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar8 = pcVar8 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar8 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        pcVar8 = pcVar8 + 1;
      }
      return 1;
    }
  }
  return 1;
}


// ==== FUN_1c208ff0 @ 1c208ff0 size=302

undefined4 __cdecl FUN_1c208ff0(char *param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  uVar2 = 0xffffffff;
  pcVar5 = *(char **)(&DAT_1c24cf08 + *param_1 * 4);
  do {
    pcVar7 = pcVar5;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  iVar3 = -1;
  pcVar5 = param_3;
  do {
    pcVar6 = pcVar5;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  pcVar5 = pcVar7 + -uVar2;
  pcVar7 = pcVar6 + -1;
  for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar7 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar2 = 0xffffffff;
  pcVar5 = *(char **)(&DAT_1c24cf08 + param_1[1] * 4);
  do {
    pcVar7 = pcVar5;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  iVar3 = -1;
  pcVar5 = param_3;
  do {
    pcVar6 = pcVar5;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  pcVar5 = pcVar7 + -uVar2;
  pcVar7 = pcVar6 + -1;
  for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar7 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar2 = 0xffffffff;
  pcVar5 = *(char **)(&DAT_1c24cf08 + param_1[2] * 4);
  do {
    pcVar7 = pcVar5;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  iVar3 = -1;
  pcVar5 = param_3;
  do {
    pcVar6 = pcVar5;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  pcVar5 = pcVar7 + -uVar2;
  pcVar7 = pcVar6 + -1;
  for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar7 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar2 = 0xffffffff;
  pcVar5 = (char *)&DAT_1c24c9e0;
  do {
    pcVar7 = pcVar5;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  iVar3 = -1;
  pcVar5 = param_3;
  do {
    pcVar6 = pcVar5;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  pcVar5 = pcVar7 + -uVar2;
  pcVar7 = pcVar6 + -1;
  for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar7 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar2 = 0xffffffff;
  pcVar5 = *(char **)(&DAT_1c24cf08 + param_1[4] * 4);
  do {
    pcVar7 = pcVar5;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  iVar3 = -1;
  pcVar5 = param_3;
  do {
    pcVar6 = pcVar5;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  pcVar5 = pcVar7 + -uVar2;
  pcVar7 = pcVar6 + -1;
  for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar7 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar7 = pcVar7 + 1;
  }
  FUN_1c209290(param_1 + 5,param_2,param_3);
  return 1;
}


// ==== FUN_1c2091f0 @ 1c2091f0 size=151

undefined4 __cdecl FUN_1c2091f0(char *param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  uVar2 = 0xffffffff;
  pcVar5 = &DAT_1c24cc44;
  do {
    pcVar7 = pcVar5;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  iVar3 = -1;
  pcVar5 = param_3;
  do {
    pcVar6 = pcVar5;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  pcVar5 = pcVar7 + -uVar2;
  pcVar7 = pcVar6 + -1;
  for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar7 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar7 = pcVar7 + 1;
  }
  FUN_1c209290(param_1,param_2,param_3);
  uVar2 = 0xffffffff;
  pcVar5 = (char *)&DAT_1c24cbd4;
  do {
    pcVar7 = pcVar5;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar7 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar7;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  iVar3 = -1;
  pcVar5 = param_3;
  do {
    pcVar6 = pcVar5;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  pcVar5 = pcVar7 + -uVar2;
  pcVar7 = pcVar6 + -1;
  for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar7 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar7 = pcVar7 + 1;
  }
  FUN_1c208ff0(param_1 + 4,param_2,param_3);
  return 1;
}


// ==== FUN_1c209290 @ 1c209290 size=225

undefined4 __cdecl FUN_1c209290(char *param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  
  cVar2 = *param_1;
  cVar3 = param_1[1];
  cVar4 = param_1[2];
  uVar5 = 0xffffffff;
  pcVar9 = (&PTR_DAT_1c24cfc8)[cVar2 + -0x30];
  do {
    pcVar8 = pcVar9;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar9 + 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar8;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  iVar6 = -1;
  pcVar9 = param_3;
  do {
    pcVar10 = pcVar9;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar10 = pcVar9 + 1;
    cVar1 = *pcVar9;
    pcVar9 = pcVar10;
  } while (cVar1 != '\0');
  pcVar9 = pcVar8 + -uVar5;
  pcVar8 = pcVar10 + -1;
  for (uVar7 = uVar5 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar9;
    pcVar9 = pcVar9 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar8 = *pcVar9;
    pcVar9 = pcVar9 + 1;
    pcVar8 = pcVar8 + 1;
  }
  if (((cVar2 + -0x30 == 0) || (cVar3 + -0x30 != 0)) || (cVar4 + -0x30 != 0)) {
    uVar5 = 0xffffffff;
    pcVar9 = (&PTR_DAT_1c24cfc8)[cVar3 + -0x30];
    do {
      pcVar8 = pcVar9;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar8 = pcVar9 + 1;
      cVar2 = *pcVar9;
      pcVar9 = pcVar8;
    } while (cVar2 != '\0');
    uVar5 = ~uVar5;
    iVar6 = -1;
    pcVar9 = param_3;
    do {
      pcVar10 = pcVar9;
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      pcVar10 = pcVar9 + 1;
      cVar2 = *pcVar9;
      pcVar9 = pcVar10;
    } while (cVar2 != '\0');
    pcVar9 = pcVar8 + -uVar5;
    pcVar8 = pcVar10 + -1;
    for (uVar7 = uVar5 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar9;
      pcVar9 = pcVar9 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar8 = *pcVar9;
      pcVar9 = pcVar9 + 1;
      pcVar8 = pcVar8 + 1;
    }
    pcVar9 = (&PTR_DAT_1c24cfc8)[cVar4 + -0x30];
  }
  else {
    pcVar9 = &DAT_1c24cc58;
  }
  uVar5 = 0xffffffff;
  do {
    pcVar8 = pcVar9;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar9 + 1;
    cVar2 = *pcVar9;
    pcVar9 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  iVar6 = -1;
  do {
    pcVar9 = param_3;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar9 = param_3 + 1;
    cVar2 = *param_3;
    param_3 = pcVar9;
  } while (cVar2 != '\0');
  pcVar8 = pcVar8 + -uVar5;
  pcVar9 = pcVar9 + -1;
  for (uVar7 = uVar5 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar9 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar9 = pcVar9 + 1;
  }
  return 1;
}


// ==== FUN_1c209580 @ 1c209580 size=479

int __cdecl FUN_1c209580(byte *param_1,undefined4 *param_2,char *param_3)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  char *pcVar10;
  byte *pbVar11;
  char *pcVar12;
  char *pcVar13;
  
  uVar5 = 0xffffffff;
  pbVar11 = param_1;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    bVar1 = *pbVar11;
    pbVar11 = pbVar11 + 1;
  } while (bVar1 != 0);
  uVar5 = ~uVar5;
  iVar6 = uVar5 - 1;
  pbVar11 = param_1 + (uVar5 - 2);
  bVar1 = *pbVar11;
  if (bVar1 == 0x29) {
    *pbVar11 = 0;
    *(undefined1 *)(uVar5 + 0x1c25012e) = 0;
  }
  if (*param_1 == 0x28) {
    param_1 = param_1 + 1;
    iVar8 = 0;
    if (0 < iVar6) {
      do {
        iVar3 = iVar8 + 1;
        (&DAT_1c250130)[iVar8] = (&DAT_1c250131)[iVar8];
        iVar8 = iVar3;
      } while (iVar3 < iVar6);
    }
    uVar7 = 0xffffffff;
    pcVar12 = (char *)&DAT_1c24c9e0;
    do {
      pcVar10 = pcVar12;
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      pcVar10 = pcVar12 + 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar10;
    } while (cVar2 != '\0');
    uVar7 = ~uVar7;
    iVar8 = -1;
    pcVar12 = param_3;
    do {
      pcVar13 = pcVar12;
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      pcVar13 = pcVar12 + 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar13;
    } while (cVar2 != '\0');
    pcVar12 = pcVar10 + -uVar7;
    pcVar10 = pcVar13 + -1;
    for (uVar9 = uVar7 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(undefined4 *)pcVar10 = *(undefined4 *)pcVar12;
      pcVar12 = pcVar12 + 4;
      pcVar10 = pcVar10 + 4;
    }
    for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
      *pcVar10 = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar10 = pcVar10 + 1;
    }
  }
  iVar8 = FUN_1c207890((char *)param_1,(byte *)0x0,param_3);
  *pbVar11 = bVar1;
  if (iVar8 == 0) {
    iVar8 = uVar5 - 2;
    do {
      iVar3 = iVar8;
      if (iVar6 == 0) {
        return 1;
      }
      uVar5 = (uint)*param_1;
      piVar4 = (int *)__p___mb_cur_max();
      if (*piVar4 < 2) {
        piVar4 = (int *)__p__pctype();
        uVar7 = *(ushort *)(*piVar4 + uVar5 * 2) & 4;
      }
      else {
        uVar7 = _isctype(uVar5,4);
      }
      if (uVar7 == 0) {
        switch(uVar5) {
        case 0x24:
          pcVar12 = &DAT_1c24c9d4;
          break;
        default:
          *param_2 = param_1;
          return 3;
        case 0x2b:
          pcVar12 = s_PLAH5S_1c24cc80;
          break;
        case 0x2c:
          pcVar12 = &DAT_1c24cc38;
          break;
        case 0x2d:
          pcVar12 = s_DAE5SH_1c24cc88;
          break;
        case 0x2e:
          pcVar12 = &DAT_1c24c9a4;
          break;
        case 0x2f:
          pcVar12 = s_SLAE5SH_1c24cc90;
          break;
        case 0x3a:
          pcVar12 = s_KOW5LUN_1c24cc74;
        }
      }
      else {
        pcVar12 = *(char **)(&DAT_1c24cf08 + uVar5 * 4);
      }
      uVar5 = 0xffffffff;
      do {
        pcVar10 = pcVar12;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar10 = pcVar12 + 1;
        cVar2 = *pcVar12;
        pcVar12 = pcVar10;
      } while (cVar2 != '\0');
      uVar5 = ~uVar5;
      iVar6 = -1;
      pcVar12 = param_3;
      do {
        pcVar13 = pcVar12;
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        pcVar13 = pcVar12 + 1;
        cVar2 = *pcVar12;
        pcVar12 = pcVar13;
      } while (cVar2 != '\0');
      pcVar12 = pcVar10 + -uVar5;
      pcVar10 = pcVar13 + -1;
      for (uVar7 = uVar5 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar10 = *pcVar12;
        pcVar12 = pcVar12 + 1;
        pcVar10 = pcVar10 + 1;
      }
      iVar8 = iVar3 + -1;
      param_1 = param_1 + 1;
      iVar6 = iVar3;
    } while( true );
  }
  if (bVar1 == 0x29) {
    uVar5 = 0xffffffff;
    pcVar12 = (char *)&DAT_1c24c9e0;
    do {
      pcVar10 = pcVar12;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar10 = pcVar12 + 1;
      cVar2 = *pcVar12;
      pcVar12 = pcVar10;
    } while (cVar2 != '\0');
    uVar5 = ~uVar5;
    iVar6 = -1;
    do {
      pcVar12 = param_3;
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      pcVar12 = param_3 + 1;
      cVar2 = *param_3;
      param_3 = pcVar12;
    } while (cVar2 != '\0');
    pcVar10 = pcVar10 + -uVar5;
    pcVar12 = pcVar12 + -1;
    for (uVar7 = uVar5 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar12 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar12 = pcVar12 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar12 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar12 = pcVar12 + 1;
    }
  }
  return iVar8;
}


// ==== FUN_1c2097a0 @ 1c2097a0 size=412

undefined4 __cdecl FUN_1c2097a0(int param_1,int *param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  int iVar8;
  char *local_c;
  
  if (param_1 == 0) {
    return 0;
  }
  local_c = (char *)param_2[2];
  if (*(int *)(param_1 + 0x28) != 0) {
    while( true ) {
      cVar2 = local_c[-1];
      if ((*(ushort *)(&DAT_1c209c20 + *local_c * 2) & 0x83) == 2) {
        iVar8 = 1;
        pbVar7 = (byte *)(*(int *)(param_1 + 0x98) + *(int *)(param_1 + 0xa0));
      }
      else if ((*(ushort *)(&DAT_1c209c20 + *local_c * 2) & 0x83) == 0x80) {
        iVar8 = 0;
        pbVar7 = (byte *)(*(int *)(param_1 + -0xd4 + *local_c * 4) + *(int *)(param_1 + 0xa0));
      }
      else {
        iVar8 = 1;
        pbVar7 = (byte *)(*(int *)(param_1 + 0x9c) + *(int *)(param_1 + 0xa0));
      }
      uVar5 = 0;
      do {
        pbVar6 = pbVar7 + uVar5;
        uVar5 = (uint)*pbVar6;
        uVar4 = (uint)pbVar6[1];
        pbVar7 = pbVar6 + 3;
        bVar1 = pbVar6[2];
        if ((bVar1 & 2) == 0) {
          iVar3 = FUN_1c2099f0(param_2,(char *)pbVar7);
        }
        else if (((&DAT_1c209c20)[cVar2 * 2] & 0x80) == 0) {
          iVar3 = FUN_1c209940(param_2,pbVar7,iVar8);
        }
        else {
          iVar3 = 1;
        }
      } while (iVar3 == 3);
      if (iVar3 == 1) break;
      iVar8 = uVar5 - uVar4;
      if (param_2[5] < iVar8) {
        return 1;
      }
      param_2[7] = 2;
      strncat((char *)param_2[1],(char *)(pbVar7 + uVar4),(int)(short)iVar8);
      if ((bVar1 & 2) == 0) {
        do {
          pbVar6 = pbVar7;
          pbVar7 = pbVar6 + 1;
        } while (*pbVar6 != 0x5b);
        uVar4 = 0;
        bVar1 = pbVar6[1];
        pbVar7 = pbVar6 + 2;
        while (bVar1 != 0x5d) {
          uVar4 = uVar4 + 1;
          bVar1 = *pbVar7;
          pbVar7 = pbVar7 + 1;
        }
      }
      local_c = local_c + uVar4;
      param_2[1] = param_2[1] + iVar8;
      param_2[5] = param_2[5] - iVar8;
      *param_2 = (int)(local_c + (*param_2 - param_2[2]));
      param_2[2] = (int)local_c;
    }
    *(undefined1 *)param_2[1] = 0;
    *param_2 = (int)(local_c + (*param_2 - param_2[2]));
    param_2[2] = (int)local_c;
    return 0;
  }
  return 0;
}


// ==== FUN_1c209940 @ 1c209940 size=172

int __cdecl FUN_1c209940(undefined4 *param_1,byte *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  byte *pbVar5;
  byte local_1;
  
  uVar3 = (uint)param_2[-2];
  if ((param_2[-1] & 1) == 0) {
    pbVar5 = (byte *)param_1[2];
  }
  else {
    pbVar5 = (byte *)*param_1;
  }
  bVar4 = local_1;
  if (uVar3 == 0) {
    return 1;
  }
  do {
    if (uVar3 == 0) break;
    local_1 = *param_2;
    bVar4 = *pbVar5;
    param_2 = param_2 + 1;
    pbVar5 = pbVar5 + 1;
    uVar3 = uVar3 - 1;
  } while (bVar4 == local_1);
  if (bVar4 == local_1) {
    return 3 - (uint)((*(ushort *)(&DAT_1c209c20 + (uint)*pbVar5 * 2) & 0x80) == 0);
  }
  if (param_3 == 0) {
    iVar1 = toupper((uint)local_1);
    iVar2 = toupper((uint)bVar4);
    if (iVar2 < iVar1) {
      return 1;
    }
  }
  return 3;
}


// ==== FUN_1c2099f0 @ 1c2099f0 size=16

int __cdecl FUN_1c2099f0(undefined4 param_1,char *param_2)

{
  return (-(uint)(*param_2 == '\0') & 0xfffffffe) + 3;
}


// ==== FUN_1c209a00 @ 1c209a00 size=542

undefined4 __cdecl FUN_1c209a00(int *param_1)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  byte *local_8;
  
  uVar4 = param_1[7];
  pcVar11 = (char *)param_1[1];
  local_8 = (byte *)param_1[2];
  do {
    bVar2 = *local_8;
    if ((bVar2 == 0) || (0x7f < bVar2)) break;
    iVar7 = (int)(char)bVar2;
    pcVar10 = (&PTR_DAT_1c24d318)[iVar7 * 2];
    bVar3 = local_8[1];
    if (iVar7 == 0x2e) {
      piVar8 = (int *)__p___mb_cur_max();
      if (*piVar8 < 2) {
        piVar8 = (int *)__p__pctype();
        uVar9 = *(ushort *)(*piVar8 + (uint)bVar3 * 2) & 4;
      }
      else {
        uVar9 = _isctype((uint)bVar3,4);
      }
      if (uVar9 == 0) {
        piVar8 = (int *)__p___mb_cur_max();
        if (*piVar8 < 2) {
          piVar8 = (int *)__p__pctype();
          uVar9 = *(ushort *)(*piVar8 + (uint)bVar3 * 2) & 8;
        }
        else {
          uVar9 = _isctype((uint)bVar3,8);
        }
        if ((uVar9 == 0) && (bVar3 != 0)) {
          pcVar10 = s_DAA5T_1c24d718;
        }
      }
      else {
        pcVar10 = &DAT_1c24c9a4;
      }
    }
    else if (iVar7 == 0x3f) {
      piVar8 = (int *)__p___mb_cur_max();
      if (*piVar8 < 2) {
        piVar8 = (int *)__p__pctype();
        uVar9 = *(ushort *)(*piVar8 + (uint)bVar3 * 2) & 8;
      }
      else {
        uVar9 = _isctype((uint)bVar3,8);
      }
      if ((uVar9 != 0) || (bVar3 == 0)) {
        pcVar10 = &DAT_1c24d260;
      }
    }
    uVar9 = 0xffffffff;
    pcVar12 = pcVar10;
    do {
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      cVar1 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar1 != '\0');
    iVar7 = ~uVar9 - 1;
    if (param_1[5] < iVar7) {
      param_1[7] = 0;
      return 1;
    }
    param_1[5] = param_1[5] - iVar7;
    iVar6 = ~uVar9 - 2;
    while (iVar5 = iVar6, iVar7 != 0) {
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      *pcVar11 = cVar1;
      pcVar11 = pcVar11 + 1;
      iVar6 = iVar5 + -1;
      iVar7 = iVar5;
    }
    *pcVar11 = '\0';
    *param_1 = *param_1 + 1;
    param_1[2] = param_1[2] + 1;
    param_1[1] = (int)pcVar11;
    param_1[7] = uVar4 | 6;
    piVar8 = (int *)__p___mb_cur_max();
    if (*piVar8 < 2) {
      piVar8 = (int *)__p__pctype();
      uVar9 = *(ushort *)(*piVar8 + (uint)bVar2 * 2) & 8;
    }
    else {
      uVar9 = _isctype((uint)bVar2,8);
    }
    local_8 = local_8 + 1;
  } while (uVar9 == 0);
  if (bVar2 != 0) {
    if (param_1[5] == 0) {
      param_1[7] = 0;
      return 1;
    }
    param_1[5] = param_1[5] + -1;
    pcVar11[-1] = ',';
    *pcVar11 = ' ';
    pcVar11[1] = '\0';
    param_1[1] = (int)(pcVar11 + 1);
    param_1[7] = uVar4 | 6;
  }
  return 0;
}


// ==== FUN_1c249310 @ 1c249310 size=2444

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1c249310(int param_1)

{
  byte *pbVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  short sVar6;
  uint uVar7;
  short sVar8;
  uint local_4;
  
  FUN_1c202fe0(0x1c2508f0);
  FUN_1c202fe0(0x1c250930);
  FUN_1c202fe0(0x1c250710);
  FUN_1c202fe0(0x1c250820);
  DAT_1c25072c = 0;
  uVar3 = DAT_1c2552fc & 0x40;
  if (uVar3 != 0) {
    switch(DAT_1c250810) {
    case 'A':
      DAT_1c250728 = 0x30;
      break;
    case 'B':
      DAT_1c250728 = 0x3d;
      break;
    case 'C':
      DAT_1c250728 = 0x37;
      break;
    case 'D':
      DAT_1c250728 = 0x31;
      break;
    case 'E':
      DAT_1c250728 = 0x2e;
      break;
    case 'F':
      DAT_1c250728 = 0x3c;
      break;
    case 'G':
      DAT_1c250728 = 0x38;
      break;
    case 'H':
      DAT_1c250728 = 0x35;
      break;
    default:
      DAT_1c250728 = 0;
    }
    if (((DAT_1c250e70 & 0x10000) != 0) && ((DAT_1c2552fc & 0x80) == 0)) {
      DAT_1c250728 = DAT_1c250728 + 3;
    }
    iVar4 = DAT_1c250728;
    if ((DAT_1c255300 == '\0') && (DAT_1c250728 = DAT_1c250728 + -2, (DAT_1c250554 & 4) != 0)) {
      DAT_1c250728 = iVar4 + -4;
    }
    DAT_1c25072c = DAT_1c250728;
  }
  _DAT_1c250748 = 0;
  _DAT_1c25074c = 0x4b;
  DAT_1c250838 = -10;
  DAT_1c250908 = 3000;
  DAT_1c250948 = 400;
  pbVar1 = &DAT_1c2065be + DAT_1c25072c;
  DAT_1c250728 = (uint)*pbVar1;
  DAT_1c25072c = (uint)(byte)(&DAT_1c2065be)[DAT_1c25072c];
  if (((DAT_1c2552fc & 0x40040) != 0) || (DAT_1c250810 == '?')) {
    if ((DAT_1c2509b4 == 0x29) || ((DAT_1c2509b4 == 0x38 || (bVar2 = false, DAT_1c2509b4 == 0x15))))
    {
      bVar2 = true;
    }
    if ((DAT_1c2552fc & 2) == 0) {
      if ((DAT_1c2552fc & 0x10000) == 0) {
        if ((DAT_1c2552fc & 0x4000000) == 0) {
          if ((DAT_1c2552fc & 8) == 0) {
            sVar8 = (short)local_4;
            sVar6 = (short)local_4;
            if ((DAT_1c2552fc & 0x400) != 0) {
              local_4._0_2_ = 1000;
              sVar8 = -3;
              sVar6 = 0xe10;
            }
          }
          else {
            local_4._0_2_ = 1000;
            sVar8 = -6;
            sVar6 = 0xe10;
          }
        }
        else if ((DAT_1c250e5c & 0x800000) == 0) {
          local_4._0_2_ = 0xdc;
          sVar8 = -0x12;
          sVar6 = 0x834;
        }
        else {
          iVar4 = (uint)DAT_1c2509b4 * 0x1a + *(int *)(param_1 + 4);
          local_4._0_2_ = 0xfa;
          sVar8 = -0x12;
          sVar6 = (short)((int)*(short *)(iVar4 + 8) + (int)*(short *)(iVar4 + 10) >> 1);
        }
      }
      else if (bVar2) {
        local_4._0_2_ = 300;
        sVar8 = -0x12;
        sVar6 = 0x8fc;
      }
      else {
        local_4._0_2_ = 300;
        sVar8 = -0x12;
        sVar6 = 0x9c4;
      }
    }
    else if (((DAT_1c2552fc & 0x40000) == 0) || (DAT_1c2509b4 != 0x36)) {
      local_4._0_2_ = 500;
      sVar8 = -0x12;
      sVar6 = 0x1194;
    }
    else {
      local_4._0_2_ = 400;
      sVar8 = -0x12;
      sVar6 = 0xa28;
    }
    DAT_1c250908 = (int)sVar6;
    _DAT_1c25094c = (int)(short)local_4;
    DAT_1c250838 = (int)sVar8;
    _DAT_1c25090c = DAT_1c250908;
    if ((DAT_1c2552fc & 2) != 0) {
      if (bVar2) {
        _DAT_1c25090c = DAT_1c250908 + -300;
      }
      if ((DAT_1c250e70 & 0x200000) != 0) {
        DAT_1c250908 = DAT_1c250908 + -0x96;
      }
    }
    _DAT_1c25083c = DAT_1c250838;
    DAT_1c250948 = _DAT_1c25094c;
    if ((DAT_1c2552fc & 0x10000) != 0) {
      if ((DAT_1c250e70 & 0x10002000) != 0) {
        DAT_1c250908 = (DAT_1c25079c + DAT_1c25075c >> 1) + 100;
        DAT_1c250948 = DAT_1c250908 / 6;
      }
      if ((DAT_1c250e5c & 0x10002000) != 0) {
        iVar4 = (uint)DAT_1c2509b4 * 0x1a + *(int *)(param_1 + 4);
        _DAT_1c25090c = ((int)*(short *)(iVar4 + 8) + (int)*(short *)(iVar4 + 10) >> 1) + 100;
        _DAT_1c25094c = _DAT_1c25090c / 6;
      }
    }
  }
  if ((uVar3 == 0) && ((DAT_1c250e70 & 0x40) != 0)) {
    DAT_1c250908 = DAT_1c2508fc;
    DAT_1c250948 = DAT_1c25093c;
    DAT_1c250838 = DAT_1c25082c;
  }
  if (((DAT_1c250e70 & 0x40) == 0) && ((DAT_1c250e70 & 0x40000) == 0)) {
    if ((DAT_1c250e64 & 0x40) != 0) {
      _DAT_1c2508f8 = DAT_1c250904;
      _DAT_1c250938 = DAT_1c250944;
      _DAT_1c250828 = DAT_1c250834;
    }
    if (uVar3 != 0) {
      DAT_1c2508fc = DAT_1c250908;
      DAT_1c25093c = DAT_1c250948;
      DAT_1c25082c = DAT_1c250838;
    }
  }
  uVar7 = DAT_1c250e70 & 0x4000000;
  if ((uVar7 != 0) && ((DAT_1c2552fc & 0x10002000) != 0)) {
    DAT_1c2508fc = DAT_1c250774 + 0x82;
  }
  iVar4 = ((uint)DAT_1c250e7c + (uint)DAT_1c250564 * 10) * 10;
  DAT_1c250738 = (uint)(byte)(&DAT_1c24c462)[iVar4];
  DAT_1c250918 = 0x32;
  DAT_1c250958 = 0x32;
  DAT_1c250848 = 0x32;
  local_4 = (uint)(byte)(&DAT_1c24c465)[((uint)DAT_1c250564 + (uint)DAT_1c2505f0 * 10) * 10];
  _DAT_1c25073c = local_4;
  _DAT_1c250740 = (uint)(byte)(&DAT_1c24c468)[iVar4];
  if ((DAT_1c250e64 & 0x40) == 0) {
    _DAT_1c25095c = 5;
  }
  else {
    _DAT_1c25095c = 2;
  }
  if (uVar3 == 0) {
    _DAT_1c250960 = 5;
  }
  else {
    _DAT_1c250960 = 2;
  }
  uVar3 = DAT_1c250e70 & 0x40000;
  if (uVar3 != 0) {
    DAT_1c250848 = 0;
    DAT_1c250958 = 0;
    DAT_1c250918 = 0;
    _DAT_1c250960 = 0;
  }
  if (((DAT_1c250e70 & 0x40) != 0) && ((DAT_1c250e64 & 0x40000) != 0)) {
    _DAT_1c25095c = 0;
  }
  _DAT_1c250734 =
       DAT_1c25071c +
       (int)(((uint)*pbVar1 - DAT_1c25071c) * (uint)(byte)(&DAT_1c24c462)[iVar4]) / 100;
  _DAT_1c250914 = DAT_1c2508fc + ((DAT_1c250908 - DAT_1c2508fc) * DAT_1c250918) / 100;
  _DAT_1c250954 = DAT_1c25093c + ((DAT_1c250948 - DAT_1c25093c) * DAT_1c250958) / 100;
  DAT_1c25058c = 0;
  _DAT_1c250844 = DAT_1c25082c + ((DAT_1c250838 - DAT_1c25082c) * DAT_1c250848) / 100;
  DAT_1c25055c = 0;
  uVar5 = DAT_1c250e70 & 1;
  if (((uVar5 != 0) || (DAT_1c250e7e == '?')) ||
     ((uVar3 != 0 && (((DAT_1c2552fc & 0x20000000) == 0 || ((DAT_1c2552fc & 0x8000) != 0)))))) {
    sVar8 = 0;
    do {
      if ((&DAT_1c24c400)[sVar8 * 2] == DAT_1c250e7e) break;
      sVar8 = sVar8 + 1;
    } while (sVar8 < 0xf);
    DAT_1c25058c = (ushort)*(byte *)(sVar8 * 2 + 0x1c24c401);
    if (((DAT_1c255303 != 'A') && (DAT_1c250e7e == 'R')) && (DAT_1c250810 == '6')) {
      DAT_1c25058c = DAT_1c25058c + 3;
    }
    if (((uVar5 != 0) && (DAT_1c250e74 != '\0')) && (DAT_1c250810 != '6')) {
      DAT_1c25058c = DAT_1c25058c + 2;
    }
    if ((DAT_1c255303 == 'A') && ((DAT_1c2552f0 & 0x80) != 0)) {
      DAT_1c25058c = 2;
    }
    if ((short)DAT_1c250566 <= (short)DAT_1c25058c) {
      DAT_1c25058c = DAT_1c250566;
    }
    if ((uVar3 != 0) || (DAT_1c250e7e == '?')) {
      switch(DAT_1c250e7e) {
      case '?':
        DAT_1c25055c = 0x2a;
        break;
      default:
        DAT_1c25055c = 0;
        break;
      case 'I':
        DAT_1c25055c = 0x3c;
        break;
      case 'J':
        DAT_1c25055c = 0x3e;
        break;
      case 'M':
        DAT_1c25055c = 0x32;
        break;
      case 'N':
        DAT_1c25055c = 0x2c;
        break;
      case 'O':
        DAT_1c25055c = 0x3a;
        break;
      case 'P':
        DAT_1c25055c = 0x38;
        break;
      case 'Q':
        DAT_1c25055c = 0x38;
        break;
      case 'R':
        DAT_1c25055c = 0x2e;
        if ((DAT_1c255303 != 'A') && (DAT_1c250810 == '6')) {
          DAT_1c25055c = 0x34;
        }
        break;
      case 'T':
      case 'U':
        DAT_1c25055c = 0x3b;
      }
    }
    uVar3 = DAT_1c250e70 & 0x10000;
    if ((uVar3 != 0) && ((DAT_1c2552fc & 0x80) == 0)) {
      DAT_1c25055c = DAT_1c25055c + 4;
    }
    if (((DAT_1c250e64 & 0x8000) == 0) || (DAT_1c250e74 != '\0')) {
      if (((DAT_1c250e64 & 0x8000) == 0) && (DAT_1c250e74 == '\0')) {
        DAT_1c25055c = DAT_1c25055c + -3;
      }
    }
    else {
      DAT_1c25055c = DAT_1c25055c + -6;
    }
    if ((DAT_1c2552fc & 0x40040) == 0) {
      if (DAT_1c250810 == '\x1c') {
        DAT_1c25055c = DAT_1c25055c + -5;
      }
    }
    else {
      DAT_1c25055c = DAT_1c25055c + -3;
    }
    if ((DAT_1c255303 == 'A') && ((DAT_1c2552f0 & 0x80) != 0)) {
      DAT_1c25055c = DAT_1c25055c + -3;
    }
    if ((uVar7 != 0) && (DAT_1c250810 == '6')) {
      DAT_1c25055c = DAT_1c25055c + 6;
    }
    if (uVar5 == 0) {
      if (DAT_1c250810 == '@') {
        DAT_1c25055c = 0;
      }
      if ((DAT_1c2552fc & 1) == 0) {
        if ((DAT_1c2552fc & 0x40000) == 0) {
          if ((DAT_1c250810 == '@') && ((DAT_1c250e5c & 0x40000) != 0)) {
            if (((DAT_1c250e70 & 0x400) != 0) && ((DAT_1c250e5c & 0x400) != 0)) {
              DAT_1c25055c = 0;
              _DAT_1c25084c = _DAT_1c25095c;
              _DAT_1c250850 = _DAT_1c250960;
              _DAT_1c25091c = _DAT_1c25095c;
              _DAT_1c250920 = _DAT_1c250960;
              return;
            }
            if (((DAT_1c250e70 & 2) != 0) && ((DAT_1c250e5c & 2) != 0)) {
              DAT_1c25055c = 0;
              _DAT_1c25084c = _DAT_1c25095c;
              _DAT_1c250850 = _DAT_1c250960;
              _DAT_1c25091c = _DAT_1c25095c;
              _DAT_1c250920 = _DAT_1c250960;
              return;
            }
            if ((uVar7 != 0) && ((DAT_1c250e5c & 0x4000000) != 0)) {
              DAT_1c25055c = 0;
              _DAT_1c25084c = _DAT_1c25095c;
              _DAT_1c250850 = _DAT_1c250960;
              _DAT_1c25091c = _DAT_1c25095c;
              _DAT_1c250920 = _DAT_1c250960;
              return;
            }
            if ((uVar3 != 0) && ((DAT_1c250e5c & 0x10000) != 0)) {
              DAT_1c25055c = 0;
            }
          }
        }
        else {
          if (((DAT_1c250e70 & 0x400) != 0) && ((DAT_1c2552fc & 0x400) != 0)) {
            DAT_1c25055c = 0;
            _DAT_1c25084c = _DAT_1c25095c;
            _DAT_1c250850 = _DAT_1c250960;
            _DAT_1c25091c = _DAT_1c25095c;
            _DAT_1c250920 = _DAT_1c250960;
            return;
          }
          if (((DAT_1c250e70 & 2) != 0) && ((DAT_1c2552fc & 2) != 0)) {
            DAT_1c25055c = 0;
            _DAT_1c25084c = _DAT_1c25095c;
            _DAT_1c250850 = _DAT_1c250960;
            _DAT_1c25091c = _DAT_1c25095c;
            _DAT_1c250920 = _DAT_1c250960;
            return;
          }
          if ((uVar7 != 0) && ((DAT_1c2552fc & 0x4000000) != 0)) {
            DAT_1c25055c = 0;
            _DAT_1c25084c = _DAT_1c25095c;
            _DAT_1c250850 = _DAT_1c250960;
            _DAT_1c25091c = _DAT_1c25095c;
            _DAT_1c250920 = _DAT_1c250960;
            return;
          }
          if ((uVar3 != 0) && ((DAT_1c2552fc & 0x10000) != 0)) {
            DAT_1c25055c = 0;
            _DAT_1c25084c = _DAT_1c25095c;
            _DAT_1c250850 = _DAT_1c250960;
            _DAT_1c25091c = _DAT_1c25095c;
            _DAT_1c250920 = _DAT_1c250960;
            return;
          }
        }
      }
    }
  }
  _DAT_1c25084c = _DAT_1c25095c;
  _DAT_1c250850 = _DAT_1c250960;
  _DAT_1c25091c = _DAT_1c25095c;
  _DAT_1c250920 = _DAT_1c250960;
  return;
}


// ==== FUN_1c249d10 @ 1c249d10 size=371

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1c249d10(undefined4 param_1,int param_2)

{
  DWORD DVar1;
  undefined4 *puVar2;
  
  if (param_2 == 1) {
    DAT_1c24ed7c = DAT_1c24ed7c + 1;
  }
  else if (param_2 == 0) {
    if (DAT_1c24ed7c < 1) {
      return 0;
    }
    DAT_1c24ed7c = DAT_1c24ed7c + -1;
  }
  if (DAT_1c24ed80 == 0) {
    DVar1 = GetVersion();
    if (((char)DVar1 == '\x03') && ((DVar1 & 0x80000000) != 0)) {
      DAT_1c24ed80 = DAT_1c24ed80 + 1;
    }
    else {
      DAT_1c24ed80 = DAT_1c24ed80 + -1;
    }
  }
  _DAT_1c255440 = *(undefined4 *)_adjust_fdiv_exref;
  if (param_2 != 1) {
    if ((param_2 == 0) &&
       (((DAT_1c24ed80 < 0 || (DAT_1c24ed7c == 0)) && (DAT_1c255448 != (undefined4 *)0x0)))) {
      puVar2 = DAT_1c255444 + -1;
      if (DAT_1c255448 <= puVar2) {
        do {
          if ((code *)*puVar2 != (code *)0x0) {
            (*(code *)*puVar2)();
          }
          puVar2 = puVar2 + -1;
        } while (DAT_1c255448 <= puVar2);
      }
      if (DAT_1c24ed80 < 0) {
        free(DAT_1c255448);
      }
      else {
        GlobalFree(DAT_1c255448);
      }
      DAT_1c255448 = (undefined4 *)0x0;
    }
    return 1;
  }
  if (-1 < DAT_1c24ed80) {
    if (DAT_1c24ed7c != 1) {
      return 1;
    }
    if (-1 < DAT_1c24ed80) {
      DAT_1c255448 = GlobalAlloc(0x2000,0x80);
      if (DAT_1c255448 == (undefined4 *)0x0) {
        return 0;
      }
      goto LAB_1c249ddd;
    }
  }
  DAT_1c255448 = malloc(0x80);
  if (DAT_1c255448 == (undefined4 *)0x0) {
    return 0;
  }
LAB_1c249ddd:
  *DAT_1c255448 = 0;
  DAT_1c255444 = DAT_1c255448;
  initterm(&DAT_1c24b000,&DAT_1c24b004);
  return 1;
}


// ==== entry @ 1c249e90 size=169

int entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if ((param_2 == 0) && (DAT_1c24ed7c == 0)) {
    return 0;
  }
  if ((param_2 == 1) || (param_2 == 2)) {
    if (DAT_1c25544c != (code *)0x0) {
      iVar2 = (*DAT_1c25544c)(param_1,param_2,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_1c249f05;
    iVar2 = FUN_1c249d10(param_1,param_2);
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_1c201000(param_1,param_2);
  }
LAB_1c249f05:
  if ((param_2 == 0) || (param_2 == 3)) {
    iVar2 = FUN_1c249d10(param_1,param_2);
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    if ((iVar1 != 0) && (DAT_1c25544c != (code *)0x0)) {
      iVar1 = (*DAT_1c25544c)(param_1,param_2,param_3);
    }
  }
  return iVar1;
}


