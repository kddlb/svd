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
