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
