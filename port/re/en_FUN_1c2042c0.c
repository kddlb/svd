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
