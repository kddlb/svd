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
