// ==== FUN_1c4010d0 @ 1c4010d0 size=2001

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1c4010d0(int param_1)

{
  short sVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  short *psVar5;
  
  puVar2 = *(undefined4 **)(param_1 + 0x28);
  _DAT_1c416fa0 = *(short *)(puVar2 + -10);
  _DAT_1c416f58 = *(undefined4 *)(*(int *)(puVar2[-0xb] + 0x1c) + _DAT_1c416fa0 * 4);
  _DAT_1c416fb8 = *(undefined4 *)((int)puVar2 + -0x1e);
  _DAT_1c416f64 = *(undefined2 *)(puVar2 + -9);
  DAT_1c416f6c = *(short *)((int)puVar2 + -0xe);
  DAT_1c416f84 = *(uint *)(*(int *)(*(int *)((int)puVar2 + -0x12) + 0x1c) + DAT_1c416f6c * 4);
  _DAT_1c416f78 = puVar2[-1];
  DAT_1c416f94 = *(short *)((int)puVar2 + -10);
  DAT_1c416f80 = *(short *)(puVar2 + 3);
  DAT_1c416f98 = *(uint *)(*(int *)(puVar2[2] + 0x1c) + DAT_1c416f80 * 4);
  DAT_1c416f88 = *(uint *)((int)puVar2 + 0x16);
  DAT_1c416fa2 = *(short *)(puVar2 + 4);
  DAT_1c416f96 = *(short *)((int)puVar2 + 0x26);
  if (DAT_1c416f96 == 0xff) {
    DAT_1c416f96 = 0;
    DAT_1c416fb4 = 0x100000;
    DAT_1c416f82 = 0;
    _DAT_1c416f9c = 0x100000;
    DAT_1c416f54 = 0;
    _DAT_1c416fa8 = 0;
    _DAT_1c416fa4 = 0;
    _DAT_1c416f90 = 0;
  }
  else {
    DAT_1c416fb4 = *(uint *)(*(int *)(*(int *)((int)puVar2 + 0x22) + 0x1c) + DAT_1c416f96 * 4);
    _DAT_1c416fa4 = puVar2[0xc];
    DAT_1c416f54 = *(short *)((int)puVar2 + 0x2a);
    DAT_1c416f82 = *(short *)(puVar2 + 0x10);
    if (DAT_1c416f82 == 0xff) {
      _DAT_1c416f9c = 0x100000;
      DAT_1c416f82 = 0;
      _DAT_1c416f90 = 0;
      _DAT_1c416fa8 = 0;
    }
    else {
      _DAT_1c416f9c = *(undefined4 *)(*(int *)(puVar2[0xf] + 0x1c) + DAT_1c416f82 * 4);
      _DAT_1c416f90 = *(undefined4 *)((int)puVar2 + 0x4a);
      _DAT_1c416fa8 = *(undefined2 *)(puVar2 + 0x11);
    }
  }
  DAT_1c416fb0 = 0;
  DAT_1c416fac = 100;
  psVar5 = (short *)*puVar2;
  if (psVar5 != (short *)0x0) {
    sVar1 = *psVar5;
    while (sVar1 != 0x1e) {
      iVar3 = (int)*psVar5;
      if (iVar3 < 0x33) {
        if (iVar3 == 0x32) {
          *(int *)(param_1 + 0x56) =
               (int)*(short *)(*(int *)(puVar2[2] + 0x20) + 0x24 + psVar5[1] * 0x4a);
        }
        else if (iVar3 == 0x28) goto switchD_1c40129c_caseD_50;
      }
      else {
        switch(iVar3) {
        case 0x50:
switchD_1c40129c_caseD_50:
          sVar1 = psVar5[1];
          if (sVar1 < 0) {
            DAT_1c416fac = (sVar1 * DAT_1c416fac) / -100;
          }
          else {
            DAT_1c416fb0 = DAT_1c416fb0 + (int)sVar1;
          }
          break;
        case 0x5a:
          *(short *)(param_1 + 0xb2) = psVar5[1];
          break;
        case 100:
          *(short *)(param_1 + 0xb0) = psVar5[1];
          break;
        case 0x6e:
          *(short *)(param_1 + 0xb4) = psVar5[1];
          break;
        case 0x136:
          *(int *)(param_1 + 0x56) = (int)psVar5[1];
        }
      }
      psVar5 = psVar5 + 3;
      sVar1 = *psVar5;
    }
  }
  if ((DAT_1c416f98 & 0x100000) != 0) {
    return 0;
  }
  if (((DAT_1c416f98 & 0x2000000) != 0) && (DAT_1c416f80 != 0x1b)) {
    if (DAT_1c416f80 == 4) {
      DAT_1c416f68 = (uint)*(ushort *)(param_1 + 0xb0);
    }
    else if ((DAT_1c416f98 & 1) == 0) {
      DAT_1c416f68 = (uint)*(ushort *)(param_1 + 0xb2);
    }
    else {
      DAT_1c416f68 = (uint)*(ushort *)(param_1 + 0xb4);
    }
    goto LAB_1c40183c;
  }
  DAT_1c416f74 = 100;
  if ((DAT_1c416f88 & 4) != 0) {
    DAT_1c416f74 = 0x82;
  }
  if (((DAT_1c416f98 & 0x18000) != 0) && ((DAT_1c416f88 & 4) != 0)) {
    DAT_1c416f74 = (DAT_1c416f74 * 0x8c + 0x32) / 100;
  }
  if ((DAT_1c416f98 & 0x10000000) != 0) {
    switch(DAT_1c416fa2) {
    case 6:
      uVar4 = DAT_1c416f74 * 0x6e + 0x32;
      break;
    case 7:
      uVar4 = DAT_1c416f74 * 0x78 + 0x32;
      break;
    case 8:
      uVar4 = DAT_1c416f74 * 0x82 + 0x32;
      break;
    case 9:
      uVar4 = DAT_1c416f74 * 0x8c + 0x32;
      break;
    default:
      goto switchD_1c4013f2_default;
    }
    DAT_1c416f74 = uVar4 / 100;
switchD_1c4013f2_default:
    if (((DAT_1c416f88 & 0x40) != 0) &&
       (DAT_1c416f74 = (DAT_1c416f74 * 0x50 + 0x32) / 100, DAT_1c416fa2 == 0)) {
      DAT_1c416f74 = (DAT_1c416f74 * 0x50 + 0x32) / 100;
    }
    if (DAT_1c416f6c < 9) {
      DAT_1c416f74 = (DAT_1c416f74 * 0x78 + 0x32) / 100;
    }
    DAT_1c416f60 = 100;
    if (((DAT_1c416f88 & 8) != 0) && ((DAT_1c416fa2 != 0 || ((DAT_1c416f88 & 0x40) != 0)))) {
      DAT_1c416f60 = 0x78;
    }
    if ((DAT_1c416fb4 & 0x1000000) != 0) {
      DAT_1c416f60 = 0x55;
    }
    if (((DAT_1c416fb4 & 0x1000) != 0) && ((DAT_1c416fb4 & 0x8000000) != 0)) {
      DAT_1c416f60 = 0x82;
    }
    DAT_1c416f74 = (DAT_1c416f60 * DAT_1c416f74 + 0x32) / 100;
    if (((DAT_1c416fa2 != 0) && ((DAT_1c416fb4 & 2) != 0)) && ((_DAT_1c416fa4 & 0x80) == 0)) {
      DAT_1c416f74 = (DAT_1c416f74 * 0x46 + 0x32) / 100;
    }
    if (((DAT_1c416f96 == 0x1e) || (DAT_1c416f96 == 0x36)) || (DAT_1c416f96 == 0x6c)) {
      DAT_1c416f74 = (int)(DAT_1c416f74 * 0x4b + 0x32) / 100;
    }
    if (DAT_1c416fa2 == 0) {
      if ((DAT_1c416f54 == 0) || ((DAT_1c416fb4 & 0x10000000) == 0)) {
        if ((DAT_1c416f94 == 0) || ((DAT_1c416f84 & 0x10000000) == 0)) goto LAB_1c40160b;
        iVar3 = DAT_1c416f74 * 0x82;
      }
      else {
        iVar3 = DAT_1c416f74 * 0x96;
      }
      DAT_1c416f74 = (iVar3 + 0x32) / 100;
    }
  }
LAB_1c40160b:
  uVar4 = DAT_1c416f98 & 2;
  if (uVar4 != 0) {
    if ((DAT_1c416f98 & 0x400000) != 0) {
      DAT_1c416f74 = (int)(DAT_1c416f74 * 0x4b + 0x32) / 100;
    }
    if (DAT_1c416f6c < 9) {
      if ((DAT_1c416f98 & 0x30000) != 0) {
        if (DAT_1c416fa2 == 0) {
          iVar3 = DAT_1c416f74 * 0x8c;
        }
        else {
          iVar3 = DAT_1c416f74 * 200;
        }
        DAT_1c416f74 = (iVar3 + 0x32) / 100;
      }
    }
    else {
      DAT_1c416f74 = (int)(DAT_1c416f74 * 0x55 + 0x32) / 100;
    }
    if ((((DAT_1c416f84 & 0x10000000) == 0) || (uVar4 == 0)) || ((DAT_1c416fb4 & 2) == 0)) {
      if (((DAT_1c416f84 & 0x10000000) != 0) && (uVar4 != 0)) {
        iVar3 = DAT_1c416f74 * 0x82 + 0x32;
        goto LAB_1c401748;
      }
    }
    else {
      if (DAT_1c416f94 == 0) {
        iVar3 = DAT_1c416f74 * 0x82 + 0x32;
      }
      else if ((DAT_1c416fb4 & 0x8000000) == 0) {
        iVar3 = DAT_1c416f74 * 0xa0 + 0x32;
      }
      else {
        iVar3 = DAT_1c416f74 * 200 + 0x32;
      }
LAB_1c401748:
      DAT_1c416f74 = iVar3 / 100;
    }
    if ((((DAT_1c416f80 == 0x52) && (DAT_1c416f6c == 0x3d)) ||
        ((DAT_1c416f80 == 0x51 && (DAT_1c416f6c == 0x3c)))) ||
       ((DAT_1c416f80 == 0x54 && (DAT_1c416f6c == 0x3e)))) {
      DAT_1c416f74 = (int)(DAT_1c416f74 * 0x96 + 0x32) / 100;
    }
  }
  _DAT_1c416f5c = DAT_1c416f84;
  _DAT_1c416f8c = DAT_1c416fb4;
  _DAT_1c416f70 = (int)*(short *)(puVar2[1] + 0x14 + DAT_1c416f80 * 0x1a);
  DAT_1c416f7c = (int)*(short *)(puVar2[1] + 0x12 + DAT_1c416f80 * 0x1a);
  iVar3 = _DAT_1c416f70;
  if (DAT_1c416fa2 == 0) {
    iVar3 = DAT_1c416f7c;
  }
  uVar4 = DAT_1c416f74;
  if (299 < (int)DAT_1c416f74) {
    uVar4 = 300;
  }
  DAT_1c416f68 = (int)(uVar4 * iVar3) / 100;
  if ((DAT_1c416f98 & 0x10000000) != 0) {
    DAT_1c416f68 = (uint)(((longlong)*(int *)(param_1 + 0x56) * (longlong)(int)DAT_1c416f68 &
                          0xffffffffU) / 100);
  }
LAB_1c40183c:
  if (DAT_1c416fb0 != 0) {
    DAT_1c416f68 = DAT_1c416fb0;
  }
  DAT_1c416f68 = (((int)(DAT_1c416f68 * DAT_1c416fac) / 100) * 0xf) / 0xd;
  if (3999 < (int)DAT_1c416f68) {
    DAT_1c416f68 = 4000;
  }
  if ((int)DAT_1c416f68 < 0x1a) {
    DAT_1c416f68 = 0x19;
  }
  *(short *)((int)puVar2 + 0xe) = (short)DAT_1c416f68;
  return 0;
}


