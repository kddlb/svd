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
