// ==== FUN_1c401000 @ 1c401000 size=34

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1c401000(undefined4 param_1,int param_2)

{
  if (param_2 == 1) {
    DAT_1c417088 = &DAT_1c416fc0;
    _DAT_1c41708c = param_1;
  }
  return 1;
}


// ==== LoadLanguage @ 1c401030 size=149

undefined4 * LoadLanguage(void)

{
  int iVar1;
  int iVar2;
  
                    /* 0x1030  1  LoadLanguage */
  DAT_1c417088[1] = &LAB_1c4010d0;
  DAT_1c417088[2] = FUN_1c404020;
  *DAT_1c417088 = FUN_1c406210;
  DAT_1c417088[3] = FUN_1c406250;
  DAT_1c417088[5] = &DAT_1c40f368;
  DAT_1c417088[6] = &DAT_1c40fe98;
  DAT_1c417088[7] = &DAT_1c40d010;
  DAT_1c417088[8] = &PTR_DAT_1c40d318;
  DAT_1c417088[9] = &DAT_1c40da50;
  DAT_1c417088[4] = 2;
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 4;
    *(undefined4 *)((int)DAT_1c417088 + iVar1 + 0x28) = 0;
    iVar1 = iVar2;
  } while (iVar2 < 0xa0);
  return DAT_1c417088;
}


// ==== FUN_1c4019c0 @ 1c4019c0 size=4551

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1c4019c0(int param_1)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  if (((DAT_1c412ac0 & 0x10002000) != 0) && ((DAT_1c412ac0 & 0x10) == 0)) {
    _DAT_1c412238 = 0;
    DAT_1c412358 = 0;
    _DAT_1c412288 = 0;
    _DAT_1c4123d8 = 0;
    _DAT_1c4122c8 = 0;
    _DAT_1c412418 = 0;
    _DAT_1c41223c = 100;
    DAT_1c41235c = 100;
    _DAT_1c41228c = 100;
    _DAT_1c4123dc = 100;
    _DAT_1c4122cc = 100;
    _DAT_1c41241c = 100;
  }
  FUN_1c402c30(0x1c412320);
  FUN_1c402c30(0x1c412200);
  FUN_1c402c30(0x1c4123a0);
  FUN_1c402c30(0x1c412250);
  FUN_1c402c30(0x1c4123e0);
  FUN_1c402c30(0x1c412290);
  bVar1 = DAT_1c412604;
  if ((DAT_1c412460 != 0x4b) && (DAT_1c412460 != 0x4c)) {
    bVar1 = DAT_1c412460;
  }
  iVar4 = (short)(ushort)bVar1 * 0x1a + *(int *)(param_1 + 4);
  DAT_1c412338 = (int)*(short *)(iVar4 + 6);
  DAT_1c412218 = (int)*(short *)(iVar4 + 0xc);
  DAT_1c4123b8 = (int)*(short *)(iVar4 + 8);
  DAT_1c412268 = (int)*(short *)(iVar4 + 0xe);
  DAT_1c4123f8 = (int)*(short *)(iVar4 + 10);
  DAT_1c4122a8 = (int)*(short *)(iVar4 + 0x10);
  DAT_1c41221c = DAT_1c412218;
  DAT_1c41226c = DAT_1c412268;
  DAT_1c4122ac = DAT_1c4122a8;
  DAT_1c41233c = DAT_1c412338;
  DAT_1c4123bc = DAT_1c4123b8;
  DAT_1c4123fc = DAT_1c4123f8;
  if ((DAT_1c416f4c & 0x10) != 0) {
    DAT_1c41233c = (int)*(short *)(iVar4 + 0x20);
    DAT_1c41221c = (int)*(short *)(iVar4 + 0x26);
    DAT_1c4123bc = (int)*(short *)(iVar4 + 0x22);
    DAT_1c41226c = (int)*(short *)(iVar4 + 0x28);
    DAT_1c4123fc = (int)*(short *)(iVar4 + 0x24);
    DAT_1c4122ac = (int)*(short *)(iVar4 + 0x2a);
  }
  if ((DAT_1c412460 == 0x4b) || (DAT_1c412460 == 0x4c)) {
    DAT_1c412218 = *(short *)(iVar4 + 0xc) + 200;
    DAT_1c412268 = *(short *)(iVar4 + 0xe) + 0x28;
    if (DAT_1c412268 < 0xc9) {
      DAT_1c412268 = 200;
    }
    DAT_1c4122a8 = *(short *)(iVar4 + 0x10) + 0x3c;
    if (DAT_1c4122a8 < 0x12d) {
      DAT_1c4122a8 = 300;
    }
    DAT_1c41221c = DAT_1c412218;
    DAT_1c41226c = DAT_1c412268;
    DAT_1c4122ac = DAT_1c4122a8;
    if ((DAT_1c412ac0 & 0x20000000) == 0) {
      DAT_1c412338 = DAT_1c41233c + DAT_1c41232c >> 1;
      DAT_1c4123b8 = DAT_1c4123ac + DAT_1c4123bc >> 1;
      DAT_1c4123f8 = DAT_1c4123fc + DAT_1c4123ec >> 1;
    }
  }
  if ((DAT_1c416f4c & 0x20000000) != 0) {
    DAT_1c412338 = DAT_1c41232c;
    DAT_1c412218 = DAT_1c41220c;
    DAT_1c4123b8 = DAT_1c4123ac;
    DAT_1c412268 = DAT_1c41225c;
    DAT_1c4123f8 = DAT_1c4123ec;
    DAT_1c4122a8 = DAT_1c41229c;
  }
  if ((DAT_1c412ac0 & 0x20000000) != 0) {
    DAT_1c41232c = DAT_1c412338;
    DAT_1c41220c = DAT_1c41221c;
    DAT_1c4123ac = DAT_1c4123b8;
    DAT_1c41225c = DAT_1c41226c;
    DAT_1c4123ec = DAT_1c4123f8;
    DAT_1c41229c = DAT_1c4122ac;
  }
  if ((DAT_1c416f4c & 0x10000000) == 0) {
    if (((((DAT_1c416f4c & 0x40) != 0) && ((DAT_1c416f4c & 0x10000) != 0)) &&
        ((DAT_1c412aac._3_1_ & 0x10) != 0)) && ((DAT_1c412aac._2_1_ & 0x20) != 0)) {
      DAT_1c4123b8 = DAT_1c4123b8 + -0x32;
      DAT_1c4123f8 = DAT_1c4123f8 + -200;
      DAT_1c4123bc = DAT_1c4123b8;
      DAT_1c4123fc = DAT_1c4123f8;
    }
  }
  else {
    if ((((DAT_1c416f4c & 0x80) != 0) && ((DAT_1c416f4c & 0x1000) != 0)) &&
       ((DAT_1c412aac._3_1_ & 4) != 0)) {
      DAT_1c4123bc = DAT_1c4123b8;
    }
    if (((DAT_1c416f4c & 0x40000080) != 0) && ((DAT_1c412aac._1_1_ & 8) != 0)) {
      DAT_1c4123bc = DAT_1c4123bc + -300;
    }
    if (((DAT_1c416f4c & 0x40000000) != 0) && (((byte)DAT_1c412aac & 2) != 0)) {
      DAT_1c4123bc = DAT_1c4123bc + -0x96;
    }
    if ((DAT_1c412ace == '6') || (DAT_1c412ace == 'l')) {
      if ((DAT_1c412ac0 & 0x200000) == 0) {
        DAT_1c4123f8 = *(short *)(*(int *)(param_1 + 4) + 0x586) + DAT_1c4123f8 >> 1;
      }
      else {
        DAT_1c4123f8 = (int)*(short *)(*(int *)(param_1 + 4) + 0x586);
      }
    }
    if ((DAT_1c412460 == 0x11) && (DAT_1c416f50 == '\0')) {
      DAT_1c412338 = 0x294;
      DAT_1c41233c = 0x294;
      DAT_1c4123b8 = 0x514;
      DAT_1c4123bc = 0x514;
      DAT_1c4123f8 = 0x960;
      DAT_1c4123fc = 0x960;
    }
  }
  if (((DAT_1c416f4c & 2) != 0) && ((DAT_1c412ac0 & 0x180000) != 0)) {
    DAT_1c4123bc = 0x73a;
    DAT_1c4123b8 = 0x73a;
    DAT_1c4123fc = 0x898;
    DAT_1c4123f8 = 0x898;
  }
  if (((DAT_1c416f4c & 0x4000000) != 0) && ((DAT_1c412ac0 & 0x180000) != 0)) {
    DAT_1c4123bc = 0x6a4;
    DAT_1c4123b8 = 0x6a4;
    DAT_1c4123fc = 0x76c;
    DAT_1c4123f8 = 0x76c;
  }
  if (((DAT_1c416f4c & 0x4000000) != 0) && ((DAT_1c412ac0 & 0x80000000) != 0)) {
    DAT_1c4123bc = 900;
    DAT_1c4123b8 = 900;
    DAT_1c4123fc = 0x9c4;
    DAT_1c4123f8 = 0x9c4;
  }
  if (DAT_1c412460 == 0x37) {
    if (((DAT_1c412aac._2_1_ & 0x80) != 0) && ((DAT_1c412aac._1_1_ & 0x80) == 0)) {
      DAT_1c4123b8 = ((int)*(short *)((uint)DAT_1c412604 * 0x1a + 8 + *(int *)(param_1 + 4)) +
                     DAT_1c4123b8 * 9) / 10;
      DAT_1c4123bc = DAT_1c4123b8;
    }
    if (((DAT_1c412aac._2_1_ & 0x80) == 0) || ((DAT_1c412aac._1_1_ & 0x80) != 0)) {
      DAT_1c4123b8 = (DAT_1c4123b8 * 9 + 0x91) / 10;
      DAT_1c4123bc = DAT_1c4123b8;
    }
  }
  if ((DAT_1c412460 == 0x37) && ((DAT_1c412aac._2_1_ & 0x20) != 0)) {
    DAT_1c41233c = DAT_1c41233c + -100;
    DAT_1c4123bc = DAT_1c4123bc + -100;
  }
  if ((DAT_1c412460 == 0x36) || (DAT_1c412460 == 0x6c)) {
    if ((DAT_1c412ac0 & 0x200000) == 0) {
      DAT_1c4123f8 = DAT_1c4123e8;
    }
    if ((DAT_1c412aac._2_1_ & 0x20) == 0) {
      DAT_1c4123fc = (int)*(short *)((uint)DAT_1c412604 * 0x1a + 10 + *(int *)(param_1 + 4));
    }
  }
  if (DAT_1c412460 == 0x40) {
    iVar4 = (uint)DAT_1c412604 * 0x1a;
    DAT_1c412338 = *(short *)(*(int *)(param_1 + 4) + 6 + iVar4) + DAT_1c41232c >> 1;
    DAT_1c4123b8 = *(short *)(*(int *)(param_1 + 4) + 8 + iVar4) + DAT_1c4123ac >> 1;
    DAT_1c4123f8 = *(short *)(*(int *)(param_1 + 4) + 10 + iVar4) + DAT_1c4123ec >> 1;
    DAT_1c41233c = DAT_1c412338;
    DAT_1c4123bc = DAT_1c4123b8;
    DAT_1c4123fc = DAT_1c4123f8;
  }
  if ((DAT_1c412460 == 0x3e) && ((DAT_1c412ac0 & 0x40000080) != 0)) {
    DAT_1c4123bc = DAT_1c4123b8;
    DAT_1c4123fc = DAT_1c4123f8;
    DAT_1c412338 = DAT_1c412338 + -100;
    DAT_1c41233c = DAT_1c412338;
  }
  if (DAT_1c4123f8 - DAT_1c4123b8 < 0xfa) {
    DAT_1c4123b8 = DAT_1c4123f8 + -0xfa;
  }
  if (DAT_1c4123fc - DAT_1c4123bc < 0xfa) {
    DAT_1c4123bc = DAT_1c4123fc + -0xfa;
  }
  if (DAT_1c4123b8 - DAT_1c412338 < 200) {
    DAT_1c412338 = DAT_1c4123b8 + -200;
  }
  if (DAT_1c4123bc - DAT_1c41233c < 200) {
    DAT_1c41233c = DAT_1c4123bc + -200;
  }
  FUN_1c403100();
  sVar2 = DAT_1c4121aa;
  if ((DAT_1c416f4c & 0x10002000) != 0) {
    if ((DAT_1c412aac._1_1_ & 0x80) != 0) {
      DAT_1c41221c = DAT_1c41221c + 100;
      DAT_1c41226c = DAT_1c41226c + 0x32;
      DAT_1c4122ac = DAT_1c4122ac + 0x32;
      DAT_1c41233c = DAT_1c41233c + 500 >> 1;
    }
    if ((DAT_1c412ac0 & 0x8000) != 0) {
      DAT_1c412218 = DAT_1c412218 + 100;
      DAT_1c412268 = DAT_1c412268 + 0x32;
      DAT_1c4122a8 = DAT_1c4122a8 + 0x32;
      DAT_1c412338 = DAT_1c412338 + 500 >> 1;
    }
  }
  DAT_1c4121b2 = DAT_1c4121aa;
  uVar6 = DAT_1c416f4c & 0x10000000;
  if (uVar6 == 0) {
    if ((DAT_1c416f4c & 0x1000000) == 0) {
      DAT_1c4121aa = 2;
      if ((DAT_1c416f4c & 0x40) == 0) {
        DAT_1c4121aa = 3;
      }
    }
    else {
      DAT_1c4121aa = 1;
    }
  }
  else {
    DAT_1c4121aa = 0;
  }
  DAT_1c412408 = (uint)(byte)(&DAT_1c40dee8)[sVar2 * 4 + (int)DAT_1c4121aa];
  if (DAT_1c412ace == '7') {
    DAT_1c412408 = 0x14;
  }
  uVar7 = DAT_1c412ac0 & 0x10000000;
  if ((uVar7 != 0) && ((DAT_1c416f4c & 0x800) != 0)) {
    DAT_1c412408 = 0x14;
  }
  DAT_1c412228 = DAT_1c412408;
  DAT_1c4122b8 = DAT_1c412408;
  DAT_1c412348 = DAT_1c412408;
  DAT_1c4123c8 = DAT_1c412408;
  if (uVar7 != 0) {
    if ((DAT_1c416f4c & 0x1000000) != 0) {
      DAT_1c412348 = 0x41;
      DAT_1c412408 = 0x32;
    }
    DAT_1c412228 = DAT_1c412348;
    DAT_1c4122b8 = DAT_1c412408;
    DAT_1c4123c8 = DAT_1c412408;
    if ((uVar7 != 0) && ((DAT_1c412460 == 0x36 || (DAT_1c412460 == 0x6c)))) {
      DAT_1c412348 = 100;
      if ((DAT_1c412ac0 & 0x80) == 0) {
        DAT_1c412348 = 0x1e;
      }
      DAT_1c4123c8 = 0x50;
      DAT_1c412408 = 0x32;
      DAT_1c4122b8 = 0x14;
      DAT_1c412228 = 0x14;
    }
  }
  if ((DAT_1c412ace == '6') || (DAT_1c412ace == 'l')) {
    DAT_1c412348 = 0;
    if ((DAT_1c412ab4 & 0x80) == 0) {
      DAT_1c412348 = 0x46;
    }
    DAT_1c412408 = 0x32;
    DAT_1c4123c8 = 0x14;
    DAT_1c4122b8 = 0x14;
    DAT_1c412228 = 0x14;
  }
  uVar3 = DAT_1c412ac0 & 0x800000;
  if ((uVar3 == 0) || ((DAT_1c416f4c & 0x40) == 0)) {
    if (((DAT_1c412ac0 & 0x40) != 0) && ((DAT_1c416f4c & 0x800000) != 0)) {
      DAT_1c412228 = 10;
      DAT_1c412348 = DAT_1c412228;
    }
  }
  else {
    DAT_1c412228 = 0x5a;
    DAT_1c412348 = DAT_1c412228;
  }
  if ((DAT_1c416f4c & 0x20000000) != 0) {
    DAT_1c412408 = 0;
    DAT_1c4123c8 = 0;
    DAT_1c412348 = 0;
    DAT_1c4122b8 = 0x32;
    DAT_1c412228 = 0x32;
  }
  if ((DAT_1c412ac0 & 0x20000000) != 0) {
    DAT_1c412408 = 100;
    DAT_1c4123c8 = 100;
    DAT_1c412348 = 100;
  }
  if ((uVar7 == 0) || ((DAT_1c416f4c & 0x4000000) == 0)) {
    if (((DAT_1c412ac0 & 0x4000000) != 0) && (uVar6 != 0)) {
      DAT_1c4123c8 = 0x1e;
    }
  }
  else {
    DAT_1c4123c8 = 0x50;
  }
  if ((uVar3 != 0) && (DAT_1c412460 == 0x1e)) {
    DAT_1c412228 = 0x5a;
    DAT_1c412348 = 0x5a;
    DAT_1c4123c8 = 0x5a;
    DAT_1c4122b8 = 0x5a;
    DAT_1c412408 = 0x5a;
  }
  if (((DAT_1c412ac0 & 0x80000) == 0) || ((DAT_1c416f4c & 0x8000) == 0)) {
    if (((DAT_1c412ac0 & 0x8000) != 0) && ((DAT_1c416f4c & 0x80000) != 0)) {
      DAT_1c4122b8 = 0x5a;
      DAT_1c4123c8 = DAT_1c4122b8;
      DAT_1c412408 = DAT_1c4122b8;
    }
  }
  else {
    DAT_1c4122b8 = 10;
    DAT_1c4123c8 = DAT_1c4122b8;
    DAT_1c412408 = DAT_1c4122b8;
  }
  if (((DAT_1c412ac0 & 0xc0100000) != 0) && ((DAT_1c416f4c & 0x2000) != 0)) {
    DAT_1c412228 = 0x14;
    DAT_1c412348 = 0x14;
    DAT_1c4123c8 = 0x14;
    DAT_1c4122b8 = 0x14;
    DAT_1c412408 = 0x14;
  }
  DAT_1c412344 = DAT_1c41232c + (int)((DAT_1c412338 - DAT_1c41232c) * DAT_1c412348) / 100;
  DAT_1c4123c4 = DAT_1c4123ac + (int)((DAT_1c4123b8 - DAT_1c4123ac) * DAT_1c4123c8) / 100;
  _DAT_1c412404 = DAT_1c4123ec + (int)((DAT_1c4123f8 - DAT_1c4123ec) * DAT_1c412408) / 100;
  _DAT_1c412224 = DAT_1c41220c + (int)((DAT_1c412218 - DAT_1c41220c) * DAT_1c412228) / 100;
  _DAT_1c412274 = DAT_1c41225c + (int)((DAT_1c412268 - DAT_1c41225c) * DAT_1c4122b8) / 100;
  _DAT_1c4122b4 = DAT_1c41229c + (int)((DAT_1c4122a8 - DAT_1c41229c) * DAT_1c4122b8) / 100;
  if (((DAT_1c412ab4 & 2) != 0) && (uVar3 != 0)) {
    _DAT_1c4123c0 = 0x640;
    _DAT_1c412400 = 0x8fc;
    if ((DAT_1c412ac0 & 0x80000) == 0) {
      _DAT_1c412400 = 0xa28;
    }
  }
  if ((((DAT_1c412ac0 & 2) != 0) && ((DAT_1c416f4c & 0x800000) != 0)) &&
     (_DAT_1c412404 = 0x8fc, (DAT_1c416f4c & 0x80000) == 0)) {
    _DAT_1c412404 = 0xa3c;
  }
  if (((DAT_1c412ac0 & 0x10002000) != 0) && ((DAT_1c416f4c & 0x4000000) != 0)) {
    _DAT_1c412224 = _DAT_1c412224 + 100;
    DAT_1c4123c4 = (DAT_1c4123ec + DAT_1c4123b8 + DAT_1c4123ac) / 3 + -400;
  }
  if (((DAT_1c416f4c & 0x4000000) != 0) && ((DAT_1c412ac0 & 0x40000080) != 0)) {
    DAT_1c4123c4 = DAT_1c4123c4 + 100;
  }
  uVar5 = DAT_1c412ac0 & 0x4000000;
  if ((uVar5 != 0) && ((DAT_1c416f4c & 0x40000080) != 0)) {
    DAT_1c4123c4 = DAT_1c4123c4 + 100;
  }
  if (uVar5 != 0) {
    if ((DAT_1c416f4c & 0x400) == 0) {
      _DAT_1c412404 = DAT_1c4123c4 + 400;
    }
    else {
      _DAT_1c412404 = DAT_1c4123c4 + 800;
    }
  }
  if ((DAT_1c416f4c & 0x4000000) != 0) {
    if ((DAT_1c412ac0 & 0x400) == 0) {
      _DAT_1c412404 = DAT_1c4123c4 + 600;
    }
    else {
      _DAT_1c412404 = DAT_1c4123c4 + 800;
    }
  }
  if (((DAT_1c412ac0 & 0x800) == 0) || (uVar6 == 0)) {
    if ((uVar7 != 0) && ((DAT_1c412ab4 & 0x800) != 0)) {
      DAT_1c412340 = DAT_1c412340 + 100;
      _DAT_1c4123c0 = _DAT_1c4123c0 + 100;
    }
  }
  else {
    DAT_1c412344 = DAT_1c412344 + -0x3c;
    DAT_1c4123c4 = DAT_1c4123c4 + -0x32;
  }
  if (((DAT_1c412ac0 & 0x20000100) != 0) && (DAT_1c412ace != '@')) {
    DAT_1c412340 = DAT_1c412328;
    _DAT_1c4123c0 = DAT_1c4123a8;
    _DAT_1c412400 = DAT_1c4123e8;
  }
  if ((uVar5 != 0) && ((DAT_1c416f4c & 0x10002000) != 0)) {
    switch(DAT_1c412460) {
    case 9:
      DAT_1c4123c4 = 0x8de;
      _DAT_1c412404 = 0xc1c;
      break;
    case 0xd:
      DAT_1c4123c4 = 0x834;
      _DAT_1c412404 = 0xa14;
      break;
    case 0x11:
      DAT_1c4123c4 = 0x76c;
      _DAT_1c412404 = 0x97e;
      break;
    case 0x1f:
      DAT_1c4123c4 = 0x866;
      _DAT_1c412404 = 0xa41;
      break;
    case 0x21:
      DAT_1c4123c4 = 0x7e4;
      _DAT_1c412404 = 0x92e;
      break;
    case 0x23:
      DAT_1c4123c4 = 0x4b0;
      _DAT_1c412404 = 0x960;
      break;
    case 0x27:
    case 0x5c:
      DAT_1c4123c4 = 1000;
      _DAT_1c412404 = 0x9f6;
      break;
    case 0x29:
    case 0x38:
      DAT_1c4123c4 = 0x5dc;
      _DAT_1c412404 = 0x76c;
      break;
    case 0x36:
    case 0x6c:
      DAT_1c4123c4 = 0x78a;
      _DAT_1c412404 = 0x9a6;
      break;
    case 0x37:
      DAT_1c4123c4 = 0x410;
      _DAT_1c412404 = 0x8ca;
    }
  }
  _DAT_1c41222c = 10;
  DAT_1c41234c = 10;
  _DAT_1c41227c = 10;
  _DAT_1c4123cc = 10;
  _DAT_1c4122bc = 10;
  _DAT_1c41240c = 10;
  _DAT_1c412230 = 0xc;
  DAT_1c412350 = 0xc;
  _DAT_1c412280 = 0xc;
  _DAT_1c4123d0 = 0xc;
  _DAT_1c4122c0 = 0xc;
  _DAT_1c412410 = 0xc;
  if ((DAT_1c412ac0 & 0x1000000) != 0) {
    _DAT_1c412230 = 5;
    DAT_1c412350 = 5;
    _DAT_1c412280 = 5;
    _DAT_1c4123d0 = 5;
    _DAT_1c4122c0 = 5;
    _DAT_1c412410 = 5;
  }
  if ((uVar3 != 0) && ((DAT_1c416f4c & 0x1000000) != 0)) {
    _DAT_1c412230 = 6;
    DAT_1c412350 = 6;
    _DAT_1c412280 = 8;
    _DAT_1c4123d0 = 8;
    _DAT_1c4122c0 = 8;
    _DAT_1c412410 = 8;
  }
  if (DAT_1c412ace == '9') {
    _DAT_1c412280 = (-(uint)((DAT_1c416f4c & 0x1000000) == 0) & 2) + 3;
    _DAT_1c4122c0 = _DAT_1c412280;
    _DAT_1c4123d0 = _DAT_1c412280;
    _DAT_1c412410 = _DAT_1c412280;
  }
  if ((DAT_1c412ace == '6') || (DAT_1c412ace == 'l')) {
    DAT_1c412350 = 4;
    DAT_1c41234c = 4;
    _DAT_1c4123d0 = 4;
    _DAT_1c4123cc = 4;
    _DAT_1c412410 = 5;
    _DAT_1c41240c = 5;
    _DAT_1c412230 = 2;
    _DAT_1c41222c = 2;
    _DAT_1c412280 = 2;
    _DAT_1c41227c = 2;
    _DAT_1c4122c0 = 2;
    _DAT_1c4122bc = 2;
  }
  if (((DAT_1c412ab4 & 0x2000) == 0) || (DAT_1c416f53 == '6')) {
LAB_1c402964:
    if ((((uVar7 != 0) && (DAT_1c412ac4 != '\0')) && (DAT_1c412b30 != '\0')) &&
       (((DAT_1c412ab4 & 0x2000) != 0 && ((DAT_1c412b2e & 4) != 0)))) {
      _DAT_1c41222c = 5;
      DAT_1c41234c = 5;
      _DAT_1c41227c = 5;
      _DAT_1c4123cc = 5;
      _DAT_1c4122bc = 5;
      _DAT_1c41240c = 5;
    }
  }
  else if (uVar7 != 0) {
    _DAT_1c41222c = 7;
    DAT_1c41234c = 7;
    _DAT_1c41227c = 7;
    _DAT_1c4123cc = 7;
    _DAT_1c4122bc = 7;
    _DAT_1c41240c = 7;
    goto LAB_1c402964;
  }
  if (DAT_1c412240 == 3) {
    if (uVar3 != 0) {
      _DAT_1c41222c = 5;
      DAT_1c41234c = 5;
      _DAT_1c41227c = 7;
      _DAT_1c4123cc = 7;
      _DAT_1c4122bc = 7;
      _DAT_1c41240c = 7;
      goto LAB_1c402a6b;
    }
  }
  else if ((uVar3 != 0) && (DAT_1c412acc == 3)) {
    _DAT_1c412230 = 5;
    DAT_1c412350 = 5;
    _DAT_1c412280 = 7;
    _DAT_1c4123d0 = 7;
    _DAT_1c4122c0 = 7;
    _DAT_1c412410 = 7;
    goto LAB_1c402a6b;
  }
  if (DAT_1c4121b4 == 3) {
    _DAT_1c412280 = 3;
    _DAT_1c412230 = 2;
    _DAT_1c41222c = 2;
    DAT_1c412350 = 2;
    DAT_1c41234c = 2;
    _DAT_1c41227c = 3;
    _DAT_1c4123d0 = 3;
    _DAT_1c4123cc = 3;
    _DAT_1c4122c0 = 3;
    _DAT_1c4122bc = 3;
    _DAT_1c412410 = 3;
    _DAT_1c41240c = 3;
  }
LAB_1c402a6b:
  if (DAT_1c412ace == '7') {
    _DAT_1c412230 = 3;
    DAT_1c412350 = 3;
    _DAT_1c412280 = 3;
    _DAT_1c4123d0 = 3;
    _DAT_1c4122c0 = 3;
    _DAT_1c412410 = 3;
  }
  if ((uVar7 != 0) && ((DAT_1c416f4c & 0x800) != 0)) {
    _DAT_1c412230 = 5;
    DAT_1c412350 = 5;
    _DAT_1c412280 = 5;
    _DAT_1c4123d0 = 5;
    _DAT_1c4122c0 = 5;
    _DAT_1c412410 = 5;
  }
  if ((DAT_1c412ac0 & 0x10002000) != 0) {
    if ((DAT_1c412ab4 & 0x1000040) != 0) {
      _DAT_1c4122bc = 5;
      _DAT_1c41227c = 5;
      _DAT_1c41222c = 5;
    }
    if ((DAT_1c416f4c & 0x1000040) != 0) {
      _DAT_1c4122c0 = 5;
      _DAT_1c412280 = 5;
      _DAT_1c412230 = 5;
    }
  }
  if ((DAT_1c412ace == '6') || (DAT_1c412ace == 'l')) {
    DAT_1c412b28 = 1;
  }
  else {
    DAT_1c412b28 = 0;
  }
  if ((DAT_1c412460 == 0x36) || (DAT_1c412460 == 0x6c)) {
    _DAT_1c412274 = 0xfa;
    _DAT_1c412280 = 2;
  }
  if ((DAT_1c416f53 == '6') || (DAT_1c416f53 == 'l')) {
    _DAT_1c412270 = 0xfa;
    _DAT_1c41227c = 2;
  }
  DAT_1c412278 = DAT_1c4122b8;
  return;
}


// ==== FUN_1c402c30 @ 1c402c30 size=35

void __cdecl FUN_1c402c30(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x24);
  return;
}


// ==== FUN_1c402c60 @ 1c402c60 size=155

char __cdecl FUN_1c402c60(int param_1)

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


// ==== FUN_1c402d00 @ 1c402d00 size=985

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1c402d00(int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_1c402c30(0x1c412500);
  FUN_1c402c30(0x1c412420);
  iVar1 = ((uint)DAT_1c412acc + (uint)DAT_1c4121b4 * 10) * 10;
  DAT_1c412528 = (uint)(byte)(&DAT_1c40df58)[iVar1];
  _DAT_1c412538 = 0;
  iVar2 = ((uint)DAT_1c4121b4 + (uint)DAT_1c412240 * 10) * 10;
  _DAT_1c41253c = 0x4b;
  _DAT_1c41252c = (uint)(byte)(&DAT_1c40df5b)[iVar2];
  _DAT_1c412530 = (uint)(byte)(&DAT_1c40df5e)[iVar1];
  DAT_1c412448 = (uint)(byte)(&DAT_1c40df59)[iVar1];
  _DAT_1c41244c = (uint)(byte)(&DAT_1c40df5c)[iVar2];
  _DAT_1c412450 = (uint)(byte)(&DAT_1c40df5f)[iVar1];
  if ((DAT_1c412ace == '6') || (DAT_1c412ace == 'l')) {
    _DAT_1c412530 = 1;
    _DAT_1c41252c = 1;
  }
  if ((DAT_1c412ac0 & 0x800000) != 0) {
    if ((DAT_1c412460 == 0x36) || (DAT_1c412460 == 0x6c)) {
      DAT_1c412528 = 0;
    }
    if ((DAT_1c416f53 == '6') || (DAT_1c416f53 == 'l')) {
      _DAT_1c412520 = DAT_1c412508;
    }
  }
  DAT_1c412518 = (uint)*(byte *)(*(int *)(*(int *)(param_1 + 0x2c) + 4) + 0x16 +
                                (uint)DAT_1c412460 * 0x1a);
  if (((DAT_1c416f4c & 0x20000000) != 0) && ((DAT_1c412ac0 & 0x8000000) == 0)) {
    DAT_1c412518 = 0;
  }
  if (((((DAT_1c412ac0 & 0x10000000) != 0) && ((DAT_1c416f4c & 0x8000000) != 0)) &&
      ((DAT_1c416f4c & 0x40) != 0)) && ((DAT_1c412aac & 0x10000000) != 0)) {
    DAT_1c412518 = DAT_1c412518 + 6;
  }
  DAT_1c41251c = DAT_1c412518;
  if (((DAT_1c416f4c & 0x8000000) != 0) && ((DAT_1c412aac & 0x8000000) == 0)) {
    DAT_1c41251c = DAT_1c412518 - 3;
  }
  DAT_1c412438 = 0;
  DAT_1c412518 = (uint)(byte)(&DAT_1c40604e)[DAT_1c412518];
  DAT_1c41251c = (uint)(byte)(&DAT_1c40604e)[DAT_1c41251c];
  if ((DAT_1c416f4c & 0x44) != 0) {
    switch((uint)DAT_1c412460) {
    case 0x41:
      DAT_1c412438 = 0x20;
      break;
    case 0x42:
      DAT_1c412438 = 0x20;
      break;
    case 0x43:
      DAT_1c412438 = 0x24;
      break;
    case 0x44:
      DAT_1c412438 = 0x21;
      break;
    case 0x4b:
      DAT_1c412438 = 0x28;
    }
  }
  DAT_1c412438 = (uint)(byte)(&DAT_1c406058)[DAT_1c412438];
  DAT_1c412524 = DAT_1c41250c + (int)((DAT_1c412518 - DAT_1c41250c) * DAT_1c412528) / 100;
  _DAT_1c412444 = DAT_1c41242c + (int)((DAT_1c412438 - DAT_1c41242c) * DAT_1c412448) / 100;
  if (DAT_1c412518 == 0) {
    DAT_1c412518 = 0;
  }
  if (DAT_1c41251c == 0) {
    DAT_1c41251c = 0;
  }
  if (DAT_1c412524 < 1) {
    DAT_1c412524 = 0;
  }
  _DAT_1c41243c = DAT_1c412438;
  FUN_1c402c30(0x1c4124c0);
  FUN_1c402c30(0x1c412660);
  DAT_1c412678 = 0xc;
  if ((DAT_1c416f4c & 0x8000000) == 0) {
    DAT_1c412678 = 8;
  }
  if (DAT_1c416f50 != '\0') {
    DAT_1c412678 = DAT_1c412678 + 2;
  }
  if (((DAT_1c4121a4 & 4) != 0) && (DAT_1c416f50 == '\0')) {
    DAT_1c412678 = DAT_1c412678 + -2;
  }
  if ((DAT_1c416f4c & 0x1000000) != 0) {
    DAT_1c412678 = DAT_1c412678 + -5;
  }
  if (DAT_1c412460 == 1) {
    DAT_1c41220c = DAT_1c41220c + 0x32;
  }
  DAT_1c412678 = DAT_1c412678 * 0x100;
  _DAT_1c412690 = 3;
  _DAT_1c41268c = 3;
  _DAT_1c41267c = DAT_1c412678;
  _DAT_1c4124e4 = DAT_1c4124cc + ((DAT_1c4124d8 - DAT_1c4124cc) * DAT_1c4124e8) / 100;
  _DAT_1c412688 = 0x32;
  _DAT_1c412684 = DAT_1c41266c + ((DAT_1c412678 - DAT_1c41266c) * 0x32) / 100;
  return;
}


// ==== FUN_1c403100 @ 1c403100 size=246

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1c403100(void)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  ushort uVar6;
  
  if ((DAT_1c412ac0 & 0x10) != 0) {
    sVar3 = 0;
    do {
      if ((&DAT_1c40df18)[sVar3 * 3] == DAT_1c412ace) break;
      sVar3 = sVar3 + 1;
    } while (sVar3 < 0x15);
    bVar1 = *(byte *)(sVar3 * 3 + 0x1c40df19);
    uVar4 = (ushort)bVar1;
    bVar2 = *(byte *)(sVar3 * 3 + 0x1c40df1a);
    uVar6 = (ushort)bVar2;
    if (((DAT_1c412ac0 & 0xc0000000) != 0) && ((DAT_1c416f4c._1_1_ & 0x20) != 0)) {
      uVar4 = bVar1 - 10;
      uVar6 = bVar2 - 0xf;
    }
    if (0x5e < (short)uVar4) {
      uVar4 = 0x5f;
    }
    if ((short)uVar4 < 1) {
      uVar4 = 0;
    }
    _DAT_1c412288 = (int)(short)uVar4;
    if (99 < (short)uVar6) {
      uVar6 = 100;
    }
    iVar5 = (int)(short)uVar6;
    if ((int)(short)uVar6 <= _DAT_1c412288 + 5) {
      iVar5 = _DAT_1c412288 + 5;
    }
    _DAT_1c41228c = (int)(short)iVar5;
    _DAT_1c412238 = _DAT_1c412288;
    _DAT_1c41223c = _DAT_1c41228c;
    _DAT_1c4122c8 = _DAT_1c412288;
    _DAT_1c4122cc = _DAT_1c41228c;
    DAT_1c412358 = _DAT_1c412288;
    DAT_1c41235c = _DAT_1c41228c;
    _DAT_1c4123d8 = _DAT_1c412288;
    _DAT_1c4123dc = _DAT_1c41228c;
    _DAT_1c412418 = _DAT_1c412288;
    _DAT_1c41241c = _DAT_1c41228c;
    if (DAT_1c412ace == '#') {
      _DAT_1c412238 = 0x32;
      DAT_1c412358 = 0x32;
      _DAT_1c41223c = 0x5f;
      DAT_1c41235c = 0x5f;
    }
  }
  return;
}


// ==== FUN_1c403200 @ 1c403200 size=440

void __cdecl FUN_1c403200(int param_1)

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
  
  uVar7 = (int)(*(int *)(param_1 + 0x38) * (uint)DAT_1c4121b6) / 100 + 1;
  iVar3 = (int)(*(int *)(param_1 + 0x3c) * (uint)DAT_1c4121b6 + 0x32) / 100 - uVar7;
  if (iVar3 < 2) {
    iVar3 = 1;
  }
  iVar3 = (int)(0x8000 / (longlong)iVar3);
  iVar9 = 0x8000 - iVar3;
  puVar4 = &DAT_1c4126a0;
  if (0 < (int)uVar7) {
    puVar4 = &DAT_1c4126a0;
    for (uVar5 = uVar7 >> 1; uVar5 != 0; uVar5 = uVar5 - 1) {
      *puVar4 = 0x1000100;
      puVar4 = puVar4 + 1;
    }
    for (uVar5 = (uint)((uVar7 & 1) != 0); uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined2 *)puVar4 = 0x100;
      puVar4 = (undefined4 *)((int)puVar4 + 2);
    }
    puVar4 = (undefined4 *)((int)&DAT_1c4126a0 + uVar7 * 2);
  }
  if ((int)uVar7 < (int)(uint)DAT_1c4121b6) {
    do {
      if (iVar9 < 0) {
        iVar9 = 0;
      }
      iVar1 = iVar9 >> 7;
      iVar9 = iVar9 - iVar3;
      *(short *)puVar4 = (short)iVar1;
      uVar7 = uVar7 + 1;
      puVar4 = (undefined4 *)((int)puVar4 + 2);
    } while ((int)uVar7 < (int)(uint)DAT_1c4121b6);
  }
  *(undefined2 *)(&DAT_1c41269e + (uint)DAT_1c4121b6 * 2) = 0;
  iVar3 = *(int *)(param_1 + 0x34);
  if (7 < iVar3) {
    iVar3 = 8;
  }
  if (iVar3 < 1) {
    iVar3 = 0;
  }
  iVar9 = *(int *)(param_1 + 0x20);
  iVar1 = *(int *)(param_1 + 8);
  iVar10 = *(int *)(&DAT_1c40dca8 + (*(int *)(param_1 + 0x2c) + iVar3 * 0x10) * 4);
  iVar2 = 0;
  psVar6 = (short *)&DAT_1c4126a0;
  puVar11 = &DAT_1c411da0;
  if (DAT_1c4121b6 != 0) {
    do {
      iVar2 = iVar2 + 1;
      iVar9 = iVar9 + ((iVar1 - iVar9) * iVar10 >> 8);
      *puVar11 = (short)((uint)(*psVar6 * iVar9) >> 8);
      psVar6 = psVar6 + 1;
      puVar11 = puVar11 + 1;
    } while (iVar2 < (int)(uint)DAT_1c4121b6);
  }
  iVar9 = (uint)DAT_1c4121b6 * 2;
  iVar1 = *(int *)(param_1 + 0xc);
  iVar10 = *(int *)(param_1 + 0x24);
  iVar3 = *(int *)(&DAT_1c40dca8 + (*(int *)(param_1 + 0x30) + iVar3 * 0x10) * 4);
  iVar2 = 0;
  psVar6 = (short *)(*(int *)(param_1 + 4) + iVar9 + -2);
  psVar8 = (short *)(&DAT_1c41269e + iVar9);
  psVar12 = (short *)(&DAT_1c411d9e + (uint)DAT_1c4121b6 * 2);
  if (DAT_1c4121b6 != 0) {
    do {
      iVar2 = iVar2 + 1;
      *psVar6 = (short)((uint)((0x100 - *psVar8) * iVar10) >> 8) + *psVar12;
      iVar10 = iVar10 + ((iVar1 - iVar10) * iVar3 >> 8);
      psVar6 = psVar6 + -1;
      psVar8 = psVar8 + -1;
      psVar12 = psVar12 + -1;
    } while (iVar2 < (int)(uint)DAT_1c4121b6);
  }
  return;
}


// ==== FUN_1c4033c0 @ 1c4033c0 size=119

void FUN_1c4033c0(void)

{
  short sVar1;
  short *psVar2;
  
  if ((0 < DAT_1c4121dc) && (0 < DAT_1c4121ac)) {
    sVar1 = 0;
    psVar2 = (short *)((uint)DAT_1c4121b6 * 2 + DAT_1c412364);
    if (0 < DAT_1c4121dc) {
      do {
        psVar2 = psVar2 + -1;
        sVar1 = sVar1 + 1;
        *psVar2 = DAT_1c4121ac;
      } while (sVar1 < DAT_1c4121dc);
    }
    if (((byte)DAT_1c412ac0 & 1) != 0) {
      *psVar2 = *psVar2 + -8;
      psVar2[1] = psVar2[1] + -4;
      psVar2 = (short *)(DAT_1c412364 + -2 + (uint)DAT_1c4121b6 * 2);
      *psVar2 = *psVar2 + -8;
      psVar2[-1] = psVar2[-1] + -4;
    }
  }
  return;
}


// ==== FUN_1c403440 @ 1c403440 size=1171

void __cdecl FUN_1c403440(int param_1,int param_2,undefined4 *param_3)

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
        FUN_1c404010();
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
  uVar4 = (DAT_1c412ac8 & 4) >> 2;
  if ((((DAT_1c416f4c & 0x20000000) == 0) && ((DAT_1c416f4c & 0x8000000) != 0)) &&
     (((DAT_1c416f4c & 0x1000000) == 0 || ((DAT_1c416f4c & 0x8000) != 0)))) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((DAT_1c412ac8 & 0x80) != 0) {
    if (((DAT_1c412ab4._1_1_ & 1) == 0) || ((DAT_1c412ac0 & 0x8000000) == 0)) {
      DAT_1c412650 = (uint)**(byte **)(param_1 + 0xc4) * 2;
    }
    else {
      DAT_1c412650 = 100;
    }
    *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + 1;
    DAT_1c412ad0 = (uint)**(byte **)(param_1 + 200) * 2;
    *(int *)(param_1 + 200) = *(int *)(param_1 + 200) + 1;
    DAT_1c412ad4 = (uint)**(byte **)(param_1 + 0xcc) * 2;
    *(int *)(param_1 + 0xcc) = *(int *)(param_1 + 0xcc) + 1;
    DAT_1c412aba = (ushort)((**(byte **)(param_1 + 0xd8) & 0x70) >> 1);
    *(int *)(param_1 + 0xd8) = *(int *)(param_1 + 0xd8) + 1;
    DAT_1c411d98 = 1;
    DAT_1c416f44 = 0;
    uVar3 = DAT_1c412ac0;
    if ((((DAT_1c412ac0 & 0x2000000) == 0) &&
        (uVar3 = DAT_1c416f4c, (DAT_1c416f4c & 0x2000000) == 0)) &&
       (uVar3 = 0, (DAT_1c412aac & 0x2000000) != 0)) {
      uVar3 = DAT_1c412aac;
    }
    if ((uVar3 & 0x400000) == 0) {
      if ((uVar3 & 0x200) == 0) {
        if ((uVar3 & 0x4000) != 0) {
          DAT_1c412650 = DAT_1c412650 + -4;
          DAT_1c412ad0 = DAT_1c412ad0 + -7;
          DAT_1c412ad4 = DAT_1c412ad4 + -4;
        }
      }
      else {
        DAT_1c412650 = DAT_1c412650 + 4;
        DAT_1c412ad0 = DAT_1c412ad0 + 7;
        DAT_1c412ad4 = DAT_1c412ad4 + 4;
      }
    }
  }
  if (*(short *)(param_1 + 0x4c) != 0) {
    return;
  }
  if ((((DAT_1c412ac0 & 0x2000) != 0) && ((DAT_1c412ab4._2_1_ & 0x80) != 0)) &&
     (((DAT_1c416f4c & 0x10000000) != 0 && (DAT_1c416f50 != '\0')))) {
    FUN_1c403ee0(param_1,param_2,DAT_1c412650 + -10);
  }
  if (DAT_1c416f44 != 0) {
    if (DAT_1c412aba != 0) {
      FUN_1c403f40(param_1,param_2,(short)DAT_1c412aba + DAT_1c412ad4);
      return;
    }
    FUN_1c403f40(param_1,param_2,DAT_1c412ad4);
    return;
  }
  if ((DAT_1c411d98 != 0) && (DAT_1c416f44 = 0, (DAT_1c412ac0 & 0x8000000) != 0)) {
    DAT_1c411d98 = 0;
    if ((DAT_1c412ac0 & 0x2000000) == 0) {
      if ((DAT_1c412ab4._1_1_ & 1) == 0) {
        if ((uVar4 == 0) || ((DAT_1c416f4c & 0x2000000) == 0)) {
          FUN_1c403f40(param_1,param_2,DAT_1c412650);
        }
        else {
          FUN_1c403ee0(param_1,param_2,DAT_1c412650);
        }
      }
      else {
        FUN_1c403e90(param_1,param_2,DAT_1c412650);
        FUN_1c403ee0(param_1,param_2,DAT_1c412ad0 + DAT_1c412650 >> 1);
      }
    }
    else {
      FUN_1c403e90(param_1,param_2,DAT_1c412650);
    }
  }
  if ((DAT_1c412ac0 & 0x2000000) != 0) {
    if (((DAT_1c412ab4._2_1_ & 4) == 0) || ((DAT_1c412ab4._3_1_ & 8) != 0)) {
      if (DAT_1c412ac4 == '\0') {
        if (uVar4 == 0) {
LAB_1c403812:
          FUN_1c403ee0(param_1,param_2,DAT_1c412ad0);
        }
        else {
          FUN_1c403e90(param_1,param_2,DAT_1c412ad0);
        }
      }
      else if (uVar4 == 0) {
        if ((DAT_1c4121a4 & 0x80) != 0) goto LAB_1c403812;
        if ((DAT_1c416f4c & 0x10002000) == 0) {
          FUN_1c403f40(param_1,param_2,DAT_1c412ad0);
        }
        else {
          FUN_1c403fa0(param_1,param_2,DAT_1c412ad0);
        }
      }
      else {
        FUN_1c403e90(param_1,param_2,DAT_1c412ad0);
      }
    }
    else {
      FUN_1c403e90(param_1,param_2,DAT_1c412ad0 + 8);
    }
    if (uVar4 != 0) goto LAB_1c403854;
    if (DAT_1c412aba == 0) {
      if ((DAT_1c4121a4 & 0x80) == 0) {
        FUN_1c403fa0(param_1,param_2,DAT_1c412ad4);
      }
      else {
        FUN_1c403f40(param_1,param_2,DAT_1c412ad4);
      }
    }
  }
  if (uVar4 == 0) {
    return;
  }
LAB_1c403854:
  if ((bVar1) && (DAT_1c412aba == 0)) {
    FUN_1c403f40(param_1,param_2,DAT_1c412ad4);
    DAT_1c416f44 = 1;
    return;
  }
  if ((uVar4 != 0) && (DAT_1c412aba != 0)) {
    if ((DAT_1c412ac0 & 0x2000000) != 0) {
      FUN_1c403ee0(param_1,param_2,DAT_1c412ad4);
    }
    if (bVar1) {
      FUN_1c403f40(param_1,param_2,(short)DAT_1c412aba + DAT_1c412ad4);
      DAT_1c416f44 = 1;
    }
  }
  return;
}


// ==== FUN_1c4039c0 @ 1c4039c0 size=418

void __cdecl FUN_1c4039c0(int param_1,int param_2,undefined4 *param_3)

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
        FUN_1c404010();
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
          sVar3 = *(short *)(&DAT_1c40db20 + sVar3 * 2);
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
        if (uVar4 < DAT_1c4121b6) {
          do {
            *(short *)(iVar2 + 0x18) = sVar3;
            iVar2 = iVar2 + 0x20;
            uVar4 = uVar4 + 1;
          } while (uVar4 < DAT_1c4121b6);
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
  if ((((byte)DAT_1c412ac8 & 0x80) != 0) || ((DAT_1c412ac0._3_1_ & 0x20) != 0)) {
    uVar1 = DAT_1c4121b0;
    if (((DAT_1c412ac0._3_1_ & 0x20) == 0) && (DAT_1c412ace != 0x1c)) {
      uVar1 = (short)((int)((int)*(short *)(&DAT_1c40dc98 +
                                           ((uint)DAT_1c412ace + (uint)*(ushort *)(param_1 + 0x46) &
                                           7) * 2) * (uint)*(ushort *)(param_1 + 0x46)) / 0x6e);
    }
    *(undefined2 *)(param_2 + 0x18) = uVar1;
    *(undefined2 *)(param_2 + -8) = DAT_1c4121b0;
    DAT_1c4121b0 = uVar1;
  }
  return;
}


// ==== FUN_1c403c50 @ 1c403c50 size=346

void __cdecl FUN_1c403c50(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  ushort uVar2;
  short *psVar3;
  short sVar4;
  
  sVar4 = DAT_1c4121b0;
  uVar2 = 0;
  iVar1 = param_2;
  if (DAT_1c4121b6 != 0) {
    do {
      *(short *)(iVar1 + 0x18) = sVar4;
      iVar1 = iVar1 + 0x20;
      uVar2 = uVar2 + 1;
    } while (uVar2 < DAT_1c4121b6);
  }
  psVar3 = (short *)*param_3;
  if (psVar3 != (short *)0x0) {
    sVar4 = *psVar3;
    while (sVar4 != 0x1e) {
      switch(*psVar3) {
      case 0x32:
        FUN_1c404010();
        break;
      case 0x8c:
        *(short *)(param_1 + 0xae) = psVar3[1];
        break;
      case 0xb4:
        DAT_1c4121b0 = psVar3[1];
        if (DAT_1c4121b0 < 1) {
          sVar4 = (*(short *)(param_1 + 0xac) * 0xc + *(short *)(param_1 + 0xae)) - DAT_1c4121b0;
          if (0x54 < sVar4) {
            sVar4 = sVar4 + ((ushort)(sVar4 - 0x49U) / 0xc) * -0xc;
          }
          if (sVar4 < 0) {
            sVar4 = sVar4 + ((ushort)(0xbU - sVar4) / 0xc) * 0xc;
          }
          DAT_1c4121b0 = *(short *)(&DAT_1c40db20 + sVar4 * 2);
        }
        else {
          if (1999 < DAT_1c4121b0) {
            DAT_1c4121b0 = 2000;
          }
          if (DAT_1c4121b0 < 0xb) {
            DAT_1c4121b0 = 10;
          }
        }
        uVar2 = psVar3[2];
        iVar1 = (short)uVar2 * 0x20 + param_2;
        if (uVar2 < DAT_1c4121b6) {
          do {
            *(short *)(iVar1 + 0x18) = DAT_1c4121b0;
            iVar1 = iVar1 + 0x20;
            uVar2 = uVar2 + 1;
          } while (uVar2 < DAT_1c4121b6);
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


// ==== FUN_1c403e90 @ 1c403e90 size=70

void __cdecl FUN_1c403e90(int param_1,int param_2,int param_3)

{
  if (0x6e < param_3) {
    param_3 = (int)((uint)*(ushort *)(param_1 + 0x60) * (param_3 + -0x6e)) / 100 + 0x6e;
  }
  *(short *)(param_2 + 0x18) = (short)((int)((uint)*(ushort *)(param_1 + 0x46) * param_3) / 0x6e);
  return;
}


// ==== FUN_1c403ee0 @ 1c403ee0 size=86

void __cdecl FUN_1c403ee0(int param_1,int param_2,int param_3)

{
  if (0x6e < param_3) {
    param_3 = (int)((uint)*(ushort *)(param_1 + 0x60) * (param_3 + -0x6e)) / 100 + 0x6e;
  }
  *(short *)((DAT_1c4121b6 & 0xfffffffe) * 0x10 + 0x18 + param_2) =
       (short)((int)((uint)*(ushort *)(param_1 + 0x46) * param_3) / 0x6e);
  return;
}


// ==== FUN_1c403f40 @ 1c403f40 size=83

void __cdecl FUN_1c403f40(int param_1,int param_2,int param_3)

{
  if (0x6e < param_3) {
    param_3 = (int)((uint)*(ushort *)(param_1 + 0x60) * (param_3 + -0x6e)) / 100 + 0x6e;
  }
  *(short *)((uint)DAT_1c4121b6 * 0x20 + -8 + param_2) =
       (short)((int)((uint)*(ushort *)(param_1 + 0x46) * param_3) / 0x6e);
  return;
}


// ==== FUN_1c403fa0 @ 1c403fa0 size=100

void __cdecl FUN_1c403fa0(int param_1,int param_2,int param_3)

{
  if (0x6e < param_3) {
    param_3 = (int)((uint)*(ushort *)(param_1 + 0x60) * (param_3 + -0x6e)) / 100 + 0x6e;
  }
  *(short *)((DAT_1c412ab0 & 0xfffffffe) * 0x10 + (uint)DAT_1c4121b6 * 0x20 + 0x18 + param_2) =
       (short)((int)((uint)*(ushort *)(param_1 + 0x46) * param_3) / 0x6e);
  return;
}


// ==== FUN_1c404010 @ 1c404010 size=1

void FUN_1c404010(void)

{
  return;
}


// ==== FUN_1c404020 @ 1c404020 size=6697

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_1c404020(int param_1)

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
  int iVar12;
  byte bVar13;
  ushort uVar14;
  uint uVar15;
  short *psVar16;
  short *psVar17;
  ushort *puVar18;
  int iVar19;
  ushort *puVar20;
  short *psVar21;
  int iVar22;
  bool bVar23;
  undefined1 local_47;
  short local_46;
  short local_44;
  ushort local_42;
  short sStack_40;
  short sStack_3e;
  int local_3c;
  int local_38;
  int local_34;
  int local_2c;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  cVar3 = '\0';
  if (*(short *)(*(int *)(param_1 + 0x28) + 0xc) == 0xff) {
    DAT_1c40dc4c = 1;
    return 0;
  }
  DAT_1c412aa8 = *(undefined1 **)(param_1 + 0xfa);
  if (DAT_1c40dc4c != 0) {
    DAT_1c412ae0 = &DAT_1c4122e0;
    DAT_1c412ae4 = &DAT_1c412320;
    _DAT_1c412ae8 = &DAT_1c4123a0;
    _DAT_1c412aec = &DAT_1c4123e0;
    _DAT_1c412af0 = &DAT_1c412200;
    _DAT_1c412af4 = &DAT_1c412250;
    _DAT_1c412af8 = &DAT_1c412290;
    _DAT_1c412afc = &DAT_1c412500;
    _DAT_1c412b00 = &DAT_1c412360;
    _DAT_1c412b04 = &DAT_1c412420;
    _DAT_1c412b08 = &DAT_1c412470;
    _DAT_1c412b0c = &DAT_1c412540;
    _DAT_1c412b10 = &DAT_1c412580;
    _DAT_1c412b14 = &DAT_1c412660;
    _DAT_1c412b18 = &DAT_1c4124c0;
    _DAT_1c412b1c = &DAT_1c4125c0;
    _DAT_1c412b20 = &DAT_1c412610;
    _DAT_1c4121c4 = &DAT_1c412b40;
    DAT_1c4122e4 = &DAT_1c412b40;
    DAT_1c4121cc = &DAT_1c412f40;
    DAT_1c412324 = &DAT_1c412f40;
    DAT_1c4121d0 = (short *)&DAT_1c413340;
    DAT_1c4123a4 = (short *)&DAT_1c413340;
    DAT_1c4121d8 = (short *)&DAT_1c413740;
    DAT_1c4123e4 = (short *)&DAT_1c413740;
    DAT_1c4121b8 = &DAT_1c413b40;
    DAT_1c412204 = &DAT_1c413b40;
    DAT_1c4121bc = &DAT_1c413f40;
    DAT_1c412254 = &DAT_1c413f40;
    DAT_1c4121c0 = (short *)&DAT_1c414340;
    DAT_1c412294 = (short *)&DAT_1c414340;
    DAT_1c4121e8 = &DAT_1c414740;
    DAT_1c412504 = &DAT_1c414740;
    DAT_1c4121c8 = &DAT_1c414b40;
    DAT_1c412364 = &DAT_1c414b40;
    DAT_1c4121d4 = &DAT_1c414f40;
    DAT_1c412424 = &DAT_1c414f40;
    DAT_1c4121e0 = &DAT_1c415340;
    DAT_1c412474 = &DAT_1c415340;
    DAT_1c4121ec = &DAT_1c415740;
    DAT_1c412544 = &DAT_1c415740;
    DAT_1c4121f0 = &DAT_1c415b40;
    DAT_1c412584 = &DAT_1c415b40;
    DAT_1c4124b4 = &DAT_1c415f40;
    DAT_1c412664 = &DAT_1c415f40;
    _DAT_1c4121e4 = &DAT_1c416340;
    DAT_1c4124c4 = &DAT_1c416340;
    _DAT_1c4121f4 = &DAT_1c416740;
    DAT_1c4125c4 = &DAT_1c416740;
    _DAT_1c412aa0 = 0;
    DAT_1c412aba = 0;
    _DAT_1c4122d0 = &DAT_1c416b40;
    DAT_1c412614 = &DAT_1c416b40;
    DAT_1c411d98 = 0;
    DAT_1c416f44 = 0;
    DAT_1c412ad4 = 0x6e;
    DAT_1c412ad0 = 0x6e;
    DAT_1c412650 = 0x6e;
    _DAT_1c412b34 = 0;
    DAT_1c4122e8 = 100;
    _DAT_1c4124c8 = 0;
    DAT_1c412328 = 400;
    _DAT_1c412208 = 100;
    _DAT_1c412668 = 0xf;
    DAT_1c4123a8 = 0x578;
    _DAT_1c412258 = 100;
    _DAT_1c412588 = 400;
    DAT_1c412508 = 0;
    _DAT_1c412428 = 0;
    _DAT_1c412368 = 0;
    _DAT_1c412478 = 0;
    _DAT_1c4125c8 = 0;
    _DAT_1c412618 = 0;
    DAT_1c4123e8 = 0x960;
    _DAT_1c412298 = 200;
    _DAT_1c412548 = 3000;
    local_20 = (int)*(short *)(param_1 + 0x98);
    local_1c = (int)*(short *)(param_1 + 0x9c);
    local_18 = (int)*(short *)(param_1 + 0x9a);
    local_14 = (int)*(short *)(param_1 + 0x9e);
    *(undefined2 *)(DAT_1c412aa8 + 0x18) = *(undefined2 *)(param_1 + 0x46);
    DAT_1c4121b0 = *(undefined2 *)(DAT_1c412aa8 + 0x18);
    *(undefined2 *)
     (DAT_1c412aa8 + ((int)(*(ushort *)(*(int *)(param_1 + 0x28) + 0xe) + 4) >> 3) * 0x20 + 0x18) =
         DAT_1c4121b0;
    uVar15 = 0;
    do {
      uVar14 = (short)uVar15 + 1;
      puVar1 = (&DAT_1c412ae0)[uVar15];
      uVar2 = puVar1[2];
      puVar1[5] = uVar2;
      puVar1[4] = uVar2;
      puVar1[3] = uVar2;
      uVar2 = puVar1[2];
      puVar1[9] = uVar2;
      puVar1[8] = uVar2;
      puVar1[7] = uVar2;
      puVar1[6] = uVar2;
      *puVar1 = (&PTR_DAT_1c40dc50)[uVar15];
      uVar15 = (uint)uVar14;
    } while (uVar14 < 0x11);
    DAT_1c412ab9 = '\x01';
    DAT_1c40dc4c = 0;
  }
  iVar12 = *(int *)(param_1 + 0x20);
  DAT_1c416f51 = *(undefined1 *)(iVar12 + 0xc);
  _DAT_1c412b2c = *(undefined4 *)(iVar12 + 0x12);
  DAT_1c412b30 = (byte)*(undefined4 *)(iVar12 + 0x16) & 0x10;
  DAT_1c4121a0 = *(undefined1 *)(iVar12 + 0x10);
  _DAT_1c416f48 = *(undefined4 *)(iVar12 + 0x16);
  _DAT_1c412602 = (undefined2)((int)(*(ushort *)(iVar12 + 0xe) + 4) >> 3);
  cVar4 = FUN_1c402c60(iVar12);
  _DAT_1c412600 = (undefined2)CONCAT31(extraout_var,cVar4);
  iVar12 = *(int *)(param_1 + 0x24);
  DAT_1c416f53 = *(undefined1 *)(iVar12 + 0xc);
  DAT_1c412ab4 = *(uint *)(iVar12 + 0x12);
  DAT_1c412ab8 = (byte)*(undefined4 *)(iVar12 + 0x16) & 0x10;
  DAT_1c416f52 = *(undefined1 *)(iVar12 + 0x10);
  _DAT_1c416f40 = *(uint *)(iVar12 + 0x16);
  _DAT_1c4121a8 = (undefined2)((int)(*(ushort *)(iVar12 + 0xe) + 4) >> 3);
  cVar4 = FUN_1c402c60(iVar12);
  DAT_1c412240 = (undefined2)CONCAT31(extraout_var_00,cVar4);
  puVar1 = *(undefined4 **)(param_1 + 0x28);
  DAT_1c412ace = *(byte *)(puVar1 + 3);
  DAT_1c412ac0 = *(uint *)((int)puVar1 + 0x12);
  DAT_1c412ac4 = (byte)*(undefined4 *)((int)puVar1 + 0x16) & 0x10;
  DAT_1c412b24 = *(undefined1 *)(puVar1 + 4);
  DAT_1c412ac8 = *(undefined4 *)((int)puVar1 + 0x16);
  DAT_1c4121b6 = (ushort)((int)(*(ushort *)((int)puVar1 + 0xe) + 4) >> 3);
  cVar4 = FUN_1c402c60((int)puVar1);
  DAT_1c4121b4 = (undefined2)CONCAT31(extraout_var_01,cVar4);
  iVar12 = *(int *)(param_1 + 0x2c);
  DAT_1c412460 = *(char *)(iVar12 + 0xc);
  if (DAT_1c412460 == -1) {
    DAT_1c412460 = '\x1b';
  }
  DAT_1c416f4c = *(undefined4 *)(iVar12 + 0x12);
  DAT_1c416f50 = (byte)*(undefined4 *)(iVar12 + 0x16) & 0x10;
  DAT_1c4121ae = *(undefined1 *)(iVar12 + 0x10);
  _DAT_1c4121a4 = *(undefined4 *)(iVar12 + 0x16);
  DAT_1c412ab0 = (undefined2)((int)(*(ushort *)(iVar12 + 0xe) + 4) >> 3);
  cVar4 = FUN_1c402c60(iVar12);
  DAT_1c412acc = (undefined2)CONCAT31(extraout_var_02,cVar4);
  iVar12 = *(int *)(param_1 + 0x30);
  DAT_1c412604 = *(char *)(iVar12 + 0xc);
  if (DAT_1c412604 == -1) {
    DAT_1c412604 = '\x1b';
  }
  DAT_1c412aac = *(undefined4 *)(iVar12 + 0x12);
  DAT_1c412ab2 = (byte)*(undefined4 *)(iVar12 + 0x16) & 0x10;
  DAT_1c412abc = *(undefined1 *)(iVar12 + 0x10);
  _DAT_1c412aa4 = *(undefined4 *)(iVar12 + 0x16);
  _DAT_1c411d96 = (undefined2)((int)(*(ushort *)(iVar12 + 0xe) + 4) >> 3);
  cVar4 = FUN_1c402c60(iVar12);
  _DAT_1c4124b0 = (undefined2)CONCAT31(extraout_var_03,cVar4);
  DAT_1c412ab3 = DAT_1c412ab9;
  uVar15 = 0;
  do {
    uVar14 = (short)uVar15 + 1;
    iVar22 = (int)(&DAT_1c412ae0)[uVar15];
    *(undefined4 *)(iVar22 + 0x28) = 0x32;
    *(undefined4 *)(iVar22 + 0x38) = 0x19;
    *(undefined4 *)(iVar22 + 0x3c) = 0x4b;
    *(undefined4 *)(iVar22 + 0x2c) = 7;
    *(undefined4 *)(iVar22 + 0x30) = 7;
    *(undefined4 *)(iVar22 + 0x34) = 3;
    uVar15 = (uint)uVar14;
  } while (uVar14 < 0x11);
  _DAT_1c412ad8 = DAT_1c4121dc;
  FUN_1c4019c0((int)puVar1);
  FUN_1c402d00(param_1);
  FUN_1c40a9e0((int)puVar1);
  _DAT_1c412414 = 5;
  _DAT_1c4123d4 = 5;
  DAT_1c412354 = 5;
  _DAT_1c4122c4 = 5;
  _DAT_1c412284 = 5;
  _DAT_1c412234 = 5;
  _DAT_1c412574 = (int)(short)(*(short *)(param_1 + 0x5e) + 3);
  _DAT_1c412534 = *(short *)(param_1 + 0x7e) + 3;
  _DAT_1c412454 = *(short *)(param_1 + 0x80) + 3;
  _DAT_1c412394 = *(short *)(param_1 + 0x82) + 3;
  uVar15 = 0;
  _DAT_1c4124a4 = _DAT_1c412394;
  _DAT_1c4125b4 = _DAT_1c412574;
  do {
    uVar14 = (short)uVar15 + 1;
    FUN_1c403200((int)(&DAT_1c412ae0)[uVar15]);
    uVar15 = (uint)uVar14;
  } while (uVar14 < 0x11);
  uVar14 = 0;
  psVar7 = DAT_1c412424;
  puVar18 = DAT_1c412364;
  puVar20 = DAT_1c412504;
  if (DAT_1c4121b6 != 0) {
    do {
      uVar5 = *puVar20;
      if ((short)uVar5 < 1) {
        uVar5 = 0;
      }
      *puVar20 = (ushort)(byte)(&DAT_1c40609e)[(short)uVar5];
      sVar6 = *psVar7;
      if (sVar6 < 1) {
        sVar6 = 0;
      }
      *psVar7 = (byte)(&DAT_1c40609e)[sVar6] - 10;
      uVar5 = *puVar18;
      if ((short)uVar5 < 1) {
        uVar5 = 0;
      }
      uVar14 = uVar14 + 1;
      puVar20 = puVar20 + 1;
      psVar7 = psVar7 + 1;
      *puVar18 = (ushort)(byte)(&DAT_1c40609e)[(short)uVar5];
      puVar18 = puVar18 + 1;
    } while (uVar14 < DAT_1c4121b6);
  }
  FUN_1c4033c0();
  if (((((DAT_1c412ac0 & 0x40000) != 0) && ((DAT_1c412ac0 & 0x8000000) != 0)) && (DAT_1c412ac4 != 0)
      ) && ((((DAT_1c412ab4 & 0x20000000) != 0 || ((_DAT_1c416f40 & 8) != 0)) ||
            (DAT_1c412ace == 0x4f)))) {
    if ((((DAT_1c412ab4 & 0x8000000) == 0) || ((DAT_1c412ab4 & 0x800000) == 0)) ||
       (*(short *)(param_1 + 0x2f2) == 2)) {
      local_3c = CONCAT22(local_3c._2_2_,0x3c);
    }
    else {
      local_3c = CONCAT22(local_3c._2_2_,5);
    }
    local_42 = 0;
    psVar7 = DAT_1c412424;
    psVar16 = DAT_1c412324;
    psVar17 = DAT_1c412204;
    puVar18 = DAT_1c412504;
    psVar21 = DAT_1c412254;
    if (DAT_1c4121b6 != 0) {
      do {
        *puVar18 = *puVar18 - (short)local_3c;
        *psVar7 = 0;
        if (*(short *)(param_1 + 0x52) == 1) {
          *psVar16 = 0xfa;
        }
        else {
          *psVar16 = 0x78;
        }
        *psVar17 = *psVar17 + 0x28;
        psVar16 = psVar16 + 1;
        *psVar21 = *psVar21 + 0xfa;
        psVar17 = psVar17 + 1;
        local_42 = local_42 + 1;
        psVar21 = psVar21 + 1;
        psVar7 = psVar7 + 1;
        puVar18 = puVar18 + 1;
      } while (local_42 < DAT_1c4121b6);
    }
  }
  bVar23 = (DAT_1c412ac0 & 0x8000) == 0;
  if (bVar23) {
    bVar13 = 0;
  }
  else {
    bVar13 = 0x10;
  }
  _DAT_1c4121c4 = DAT_1c4122e4;
  DAT_1c4121cc = DAT_1c412324;
  DAT_1c4121d0 = DAT_1c4123a4;
  DAT_1c4121d8 = DAT_1c4123e4;
  DAT_1c4121b8 = DAT_1c412204;
  DAT_1c4121bc = DAT_1c412254;
  DAT_1c4121c0 = DAT_1c412294;
  DAT_1c4121ec = DAT_1c412544;
  DAT_1c4121f0 = DAT_1c412584;
  DAT_1c4121e8 = DAT_1c412504;
  DAT_1c4121d4 = DAT_1c412424;
  DAT_1c4121c8 = DAT_1c412364;
  DAT_1c4121e0 = DAT_1c412474;
  _DAT_1c4121e4 = DAT_1c4124c4;
  DAT_1c4124b4 = DAT_1c412664;
  _DAT_1c4122d0 = DAT_1c412614;
  _DAT_1c4121f4 = DAT_1c4125c4;
  local_42 = 0;
  iVar22 = local_3c;
  if (DAT_1c4121b6 != 0) {
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
                iVar8 = psVar7[1] * 0x4a;
                if (*(short *)(param_1 + 0x4c) != 3) {
                  *(undefined2 *)(param_1 + 0x4c) = *(undefined2 *)(&DAT_1c40d32a + iVar8);
                  *(undefined2 *)(param_1 + 0x44) = *(undefined2 *)(&DAT_1c40d320 + iVar8);
                }
                *(undefined2 *)(param_1 + 0x52) = *(undefined2 *)(&DAT_1c40d322 + iVar8);
                *(undefined2 *)(param_1 + 0x2f2) = *(undefined2 *)(&DAT_1c40d326 + iVar8);
                *(undefined2 *)(param_1 + 0x46) = *(undefined2 *)(&DAT_1c40d31c + iVar8);
                *(undefined2 *)(param_1 + 0xac) = *(undefined2 *)(&DAT_1c40d31e + iVar8);
                *(undefined2 *)(param_1 + 0x60) = *(undefined2 *)(&DAT_1c40d32c + iVar8);
                *(undefined2 *)(param_1 + 0x62) = *(undefined2 *)(&DAT_1c40d32e + iVar8);
                *(undefined2 *)(param_1 + 100) = *(undefined2 *)(&DAT_1c40d332 + iVar8);
                *(undefined2 *)(param_1 + 0x66) = *(undefined2 *)(&DAT_1c40d334 + iVar8);
                *(undefined2 *)(param_1 + 0x8a) = *(undefined2 *)(&DAT_1c40d328 + iVar8);
                *(undefined2 *)(param_1 + 0x98) = *(undefined2 *)(&DAT_1c40d35a + iVar8);
                *(undefined2 *)(param_1 + 0x9a) = *(undefined2 *)(&DAT_1c40d35c + iVar8);
                *(undefined2 *)(param_1 + 0x9c) = *(undefined2 *)(&DAT_1c40d35e + iVar8);
                *(undefined2 *)(param_1 + 0x9e) = *(undefined2 *)(&DAT_1c40d360 + iVar8);
                *(undefined2 *)(param_1 + 0x92) = *(undefined2 *)(&DAT_1c40d34e + iVar8);
                *(undefined2 *)(param_1 + 0x94) = *(undefined2 *)(&DAT_1c40d350 + iVar8);
                *(undefined2 *)(param_1 + 0x96) = *(undefined2 *)(&DAT_1c40d352 + iVar8);
                *(undefined2 *)(param_1 + 0x8c) = *(undefined2 *)(&DAT_1c40d354 + iVar8);
                *(undefined2 *)(param_1 + 0x8e) = *(undefined2 *)(&DAT_1c40d356 + iVar8);
                *(undefined2 *)(param_1 + 0x90) = *(undefined2 *)(&DAT_1c40d358 + iVar8);
                *(undefined2 *)(param_1 + 0x84) = *(undefined2 *)(&DAT_1c40d348 + iVar8);
                *(undefined2 *)(param_1 + 0x86) = *(undefined2 *)(&DAT_1c40d34a + iVar8);
                *(undefined2 *)(param_1 + 0x88) = *(undefined2 *)(&DAT_1c40d34c + iVar8);
                *(undefined2 *)(param_1 + 0x7e) = *(undefined2 *)(&DAT_1c40d342 + iVar8);
                *(undefined2 *)(param_1 + 0x80) = *(undefined2 *)(&DAT_1c40d344 + iVar8);
                *(undefined2 *)(param_1 + 0x82) = *(undefined2 *)(&DAT_1c40d346 + iVar8);
                *(undefined2 *)(param_1 + 0x5c) = *(undefined2 *)(&DAT_1c40d33e + iVar8);
                *(undefined2 *)(param_1 + 0x5e) = *(undefined2 *)(&DAT_1c40d340 + iVar8);
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
              bVar13 = bVar13 | 0x20;
            }
            else if (sVar6 == 0x352) {
              bVar13 = bVar13 | 8;
              local_47 = (undefined1)psVar7[1];
            }
          }
          psVar7 = psVar7 + 3;
        } while (*psVar7 != 0x1e);
      }
      local_44 = *DAT_1c4124b4 >> 8;
      if (bVar23) {
        local_3c = (int)*DAT_1c4121cc;
        iVar22 = (int)*DAT_1c4121d0;
        sStack_40 = *DAT_1c4121d8;
        local_38 = (int)*DAT_1c4121b8;
        sStack_3e = sStack_40 >> 0xf;
        local_34 = (int)*DAT_1c4121bc;
        local_2c = (int)*DAT_1c4121c0;
      }
      else {
        switch(DAT_1c412ace) {
        case 0x3c:
        case 0x57:
          local_3c = 0x14a;
          iVar22 = 0x4a1;
          sStack_40 = 0x898;
          sStack_3e = 0;
          local_38 = 500;
          local_2c = 0x3c;
          break;
        case 0x3d:
        case 0x58:
          local_3c = 0x109;
          iVar22 = 0x640;
          sStack_40 = 0x8fc;
          sStack_3e = 0;
          local_38 = 500;
          local_2c = 0x3c;
          break;
        case 0x3e:
          local_3c = 0xfa;
          iVar22 = 0x6d6;
          sStack_40 = 0x8ca;
          sStack_3e = 0;
          local_38 = 500;
          local_2c = 0x3c;
        }
      }
      if (*(short *)(param_1 + 0x2f2) == 1) {
        if (*(short *)(param_1 + 0x52) == 0) {
          local_38 = local_38 + 0x3c;
        }
        iVar8 = (short)*DAT_1c4121e8 + -7;
        if ((short)*DAT_1c4121e8 + -7 <= (int)*DAT_1c4121d4) {
          iVar8 = (int)*DAT_1c4121d4;
        }
        *DAT_1c4121d4 = (short)iVar8;
        if (0x14 < (short)*DAT_1c4121e8) {
          *DAT_1c4121e8 = *DAT_1c4121e8 + 4;
        }
        local_44 = local_44 + -4;
      }
      else if (*(short *)(param_1 + 0x2f2) == 2) {
        iVar8 = (short)*DAT_1c4121e8 + -3;
        if ((short)*DAT_1c4121e8 + -3 <= (int)*DAT_1c4121d4) {
          iVar8 = (int)*DAT_1c4121d4;
        }
        local_38 = 200;
        *DAT_1c4121d4 = (short)iVar8;
        *DAT_1c4121e8 = 0;
      }
      else if (bVar23) {
        iVar8 = (short)*DAT_1c4121e8 + -0x14;
        if ((short)*DAT_1c4121e8 + -0x14 <= (int)*DAT_1c4121d4) {
          iVar8 = (int)*DAT_1c4121d4;
        }
        *DAT_1c4121d4 = (short)iVar8;
      }
      else {
        *DAT_1c4121d4 = 0;
      }
      if ((DAT_1c412ac0 & 0x8000) != 0) {
        *DAT_1c4121d4 = *DAT_1c4121d4 + -7;
      }
      if (DAT_1c412b28 != 0) {
        if ((local_42 & 3) == 0) {
LAB_1c404e93:
          local_3c = local_3c + -0x32;
          iVar22 = iVar22 * 3 + 0x4b0 >> 2;
          local_34 = local_34 + 200 >> 1;
          local_38 = local_38 + 0x28;
          *DAT_1c4121e8 = *DAT_1c4121e8 - 3;
          iVar8 = CONCAT22(sStack_3e,sStack_40) + 2000;
          sStack_40 = (short)(iVar8 >> 1);
          sStack_3e = (short)(iVar8 >> 0x11);
        }
        else if ((local_42 & 3) == 1) {
          local_3c = local_3c + -100;
          iVar22 = iVar22 + 0x4b0 >> 1;
          local_38 = local_38 + 0x50;
          *DAT_1c4121e8 = *DAT_1c4121e8 - 6;
          local_34 = 200;
          sStack_40 = 2000;
          sStack_3e = 0;
        }
        else if ((local_42 & 3) == 2) goto LAB_1c404e93;
      }
      sVar6 = *(short *)(param_1 + 0x52);
      iVar8 = *(short *)(param_1 + 0x5c) + 10;
      if (sVar6 == 1) {
        iVar11 = CONCAT22(sStack_3e,sStack_40) + 0x1d1;
        *DAT_1c4121e8 = *DAT_1c4121e8 - 10;
        local_44 = local_44 + -5;
        *DAT_1c4121d4 = *DAT_1c4121d4 + -0x14;
        *DAT_1c4121c8 = *DAT_1c4121c8 - 6;
        iVar9 = ((local_3c + -0x1c2) * iVar8 * 0x73) / 1000 + 0x24a;
        iVar8 = ((iVar22 + -0x5aa) * iVar8 * 0x87) / 1000;
        iVar19 = iVar8 + 0x6de;
        if (iVar11 - iVar19 < 300) {
          iVar11 = iVar8 + 0x80a;
        }
        iVar8 = (iVar9 * local_38) / local_3c + 0x32;
        local_34 = (iVar19 * local_34) / iVar22;
        if (0x15d < iVar8) {
          iVar8 = 0x15e;
        }
        if (iVar8 < 0x47) {
          iVar8 = 0x46;
        }
        *DAT_1c4121ec = *DAT_1c4121ec + 0x96;
        local_3c = iVar9;
      }
      else if (sVar6 == 2) {
        local_44 = local_44 + -1;
        *DAT_1c4121e8 = *DAT_1c4121e8 - 0xd;
        *DAT_1c4121d4 = *DAT_1c4121d4 + -0x16;
        iVar11 = CONCAT22(sStack_3e,sStack_40) + 0x429;
        *DAT_1c4121c8 = *DAT_1c4121c8 - 7;
        iVar9 = ((local_3c + -0x1c2) * iVar8 * 0x91) / 1000 + 0x2e4;
        iVar8 = ((iVar22 + -0x5aa) * iVar8 * 0x91) / 1000;
        iVar19 = iVar8 + 0x834;
        if (iVar11 - iVar19 < 0x15e) {
          iVar11 = iVar8 + 0x992;
        }
        iVar8 = (iVar9 * local_38) / local_3c + 0x96;
        local_34 = (iVar19 * local_34) / iVar22 + 0x32;
        if (299 < iVar8) {
          iVar8 = 300;
        }
        if (iVar8 < 0x65) {
          iVar8 = 100;
        }
        *DAT_1c4121ec = *DAT_1c4121ec + 0xfa;
        local_3c = iVar9;
      }
      else {
        iVar11 = CONCAT22(sStack_3e,sStack_40) + -0x9a1;
        if (sVar6 == 3) {
          iVar9 = ((local_3c + -0x1c2) * iVar8 * 0x5c) / 1000 + 400;
          iVar10 = ((iVar22 + -0x5aa) * iVar8 * 0x5c) / 1000;
          iVar19 = iVar10 + 0x564;
          iVar11 = (iVar8 * iVar11 * 0x5c) / 1000 + 0x92e;
          if (iVar11 - iVar19 < 0xfa) {
            iVar11 = iVar10 + 0x65e;
          }
          *DAT_1c4121ec = *DAT_1c4121ec + -100;
        }
        else {
          iVar9 = ((local_3c + -0x1c2) * iVar8 * 100) / 1000 + 0x1c2;
          iVar19 = ((iVar22 + -0x5aa) * iVar8 * 100) / 1000 + 0x5aa;
          iVar11 = (iVar8 * iVar11 * 100) / 1000 + 0x9a1;
        }
        iVar8 = (iVar9 * local_38) / local_3c;
        local_34 = (iVar19 * local_34) / iVar22;
        local_2c = (local_2c * iVar11) / CONCAT22(sStack_3e,sStack_40);
        if (299 < iVar8) {
          iVar8 = 300;
        }
        if (iVar8 < 0x29) {
          iVar8 = 0x28;
        }
        iVar22 = *(short *)(param_1 + 0x46) + -0x6e;
        if (iVar22 < 1) {
          iVar22 = 0;
        }
        iVar22 = iVar22 / 0xe;
        if (0x13 < iVar22) {
          iVar22 = 0x14;
        }
        *DAT_1c4121e8 = *DAT_1c4121e8 - (short)iVar22;
        *DAT_1c4121d4 = *DAT_1c4121d4 + -0xd;
        *DAT_1c4121c8 = *DAT_1c4121c8 - 2;
        local_3c = (iVar9 * 0x22) / 0x21;
      }
      *DAT_1c4121e8 = *DAT_1c4121e8 + *(short *)(param_1 + 0x84);
      *DAT_1c4121d4 = *DAT_1c4121d4 + *(short *)(param_1 + 0x86);
      *DAT_1c4121c8 = *DAT_1c4121c8 + *(short *)(param_1 + 0x88);
      iVar9 = (*(short *)(param_1 + 0x92) * local_3c) / 100;
      iVar22 = (*(short *)(param_1 + 0x94) * iVar19) / 100;
      iVar11 = (*(short *)(param_1 + 0x96) * iVar11) / 100;
      if (0xfef < iVar9) {
        iVar9 = 0xff0;
      }
      if (iVar9 < 0x65) {
        iVar9 = 100;
      }
      if (0xfef < iVar22) {
        iVar22 = 0xff0;
      }
      if (iVar22 < 0x65) {
        iVar22 = 100;
      }
      if (0xfef < iVar11) {
        iVar11 = 0xff0;
      }
      if (iVar11 < 0x65) {
        iVar11 = 100;
      }
      sStack_40 = (short)iVar11;
      sStack_3e = (short)((uint)iVar11 >> 0x10);
      local_38 = (*(short *)(param_1 + 0x8c) * iVar8) / 100;
      local_34 = (*(short *)(param_1 + 0x8e) * local_34) / 100;
      local_2c = (*(short *)(param_1 + 0x90) * local_2c) / 100;
      if (499 < local_38) {
        local_38 = 500;
      }
      if (local_38 < 0x29) {
        local_38 = 0x28;
      }
      if (499 < local_34) {
        local_34 = 500;
      }
      if (local_34 < 0x29) {
        local_34 = 0x28;
      }
      if (499 < local_2c) {
        local_2c = 500;
      }
      if (local_2c < 0x29) {
        local_2c = 0x28;
      }
      local_20 = local_20 + ((*(short *)(param_1 + 0x98) - local_20) * 5000 >> 0x10);
      local_1c = local_1c + ((*(short *)(param_1 + 0x9c) - local_1c) * 5000 >> 0x10);
      local_18 = local_18 + ((*(short *)(param_1 + 0x9a) - local_18) * 5000 >> 0x10);
      local_14 = local_14 + ((*(short *)(param_1 + 0x9e) - local_14) * 5000 >> 0x10);
      local_44 = local_44 + *(short *)(param_1 + 0x8a);
      if (0xe < local_44) {
        local_44 = 0xf;
      }
      if (local_44 < 1) {
        local_44 = 0;
      }
      iVar8 = (int)*DAT_1c4121ec;
      local_3c = (int)*DAT_1c4121f0;
      if (*(short *)(param_1 + 0x48) == 8000) {
        iVar9 = iVar9 * 0xb >> 3;
        local_38 = local_38 * 0xb >> 3;
        iVar22 = iVar22 * 0xb >> 3;
        local_34 = local_34 * 0xb >> 3;
        sStack_40 = (short)(iVar11 * 0xb >> 3);
        sStack_3e = (short)(iVar11 * 0xb >> 0x13);
        local_2c = local_2c * 0xb >> 3;
        local_20 = local_20 * 0xb >> 3;
        local_18 = local_18 * 0xb >> 3;
        local_1c = local_1c * 0xb >> 3;
        local_14 = local_14 * 0xb >> 3;
        iVar8 = iVar8 * 0xb >> 3;
        local_3c = local_3c * 0xb >> 3;
      }
      if (((DAT_1c412ac0 & 0xc0100000) == 0) || (local_42 <= DAT_1c4121b6 >> 1)) {
        DAT_1c412ab9 = *(char *)((uint)DAT_1c412ace * 0x1a + 0x17 + *(int *)(iVar12 + 4));
      }
      else {
        DAT_1c412ab9 = *(char *)((uint)DAT_1c412ace * 0x1a + 0x31 + *(int *)(iVar12 + 4));
      }
      if (DAT_1c412ab9 == '\0') {
        DAT_1c412ab9 = DAT_1c412ab3;
      }
      DAT_1c412aa8[0x1a] = DAT_1c412ab9;
      *DAT_1c412aa8 = (&UNK_1c405a84)[(int)(iVar9 + 8 + (iVar9 + 8 >> 0x1f & 0xfU)) >> 4 & 0xff];
      DAT_1c412aa8[1] = (&UNK_1c405a84)[(int)(iVar22 + 8 + (iVar22 + 8 >> 0x1f & 0xfU)) >> 4 & 0xff]
      ;
      iVar11 = CONCAT22(sStack_3e,sStack_40) + 8;
      DAT_1c412aa8[2] = (&UNK_1c405a84)[(int)(iVar11 + (iVar11 >> 0x1f & 0xfU)) >> 4 & 0xff];
      DAT_1c412aa8[3] =
           "  !\"\"#$$%%&&\'\'(())**+++,,--...//000111223334445556667777888999::::;;;;<<<====>>>>????@@@@@AAAABBBBCCCCCDDDDDEEEEEFFFFFGGGGGHHHHHIIIIIIJJJJJJKKKKKLLLLLLMMMMMMMNNNNNNOOOOOOOPPPPPPQQQQQQQRRRRRRRRSSSSSSST"
           [((int)(local_20 + 0x10 + (local_20 + 0x10 >> 0x1f & 0x1fU)) >> 5 & 0xffU) + 200];
      DAT_1c412aa8[4] =
           "  !\"\"#$$%%&&\'\'(())**+++,,--...//000111223334445556667777888999::::;;;;<<<====>>>>????@@@@@AAAABBBBCCCCCDDDDDEEEEEFFFFFGGGGGHHHHHIIIIIIJJJJJJKKKKKLLLLLLMMMMMMMNNNNNNOOOOOOOPPPPPPQQQQQQQRRRRRRRRSSSSSSST"
           [((int)(local_1c + 0x10 + (local_1c + 0x10 >> 0x1f & 0x1fU)) >> 5 & 0xffU) + 200];
      DAT_1c412aa8[5] = 0;
      DAT_1c412aa8[6] =
           "     !!!!!!\"\"\"\"\"######$$$$$$%%%%%%%&&&&&&&\'\'\'\'\'\'\'((((((())))))))********+++++++++,,,,,,,,,----------..........////////////////////////////////////////////"
           [((int)(local_38 + 4 + (local_38 + 4 >> 0x1f & 7U)) >> 3 & 0xffU) + 0x9a] * '\x10' +
           "     !!!!!!\"\"\"\"\"######$$$$$$%%%%%%%&&&&&&&\'\'\'\'\'\'\'((((((())))))))********+++++++++,,,,,,,,,----------..........////////////////////////////////////////////"
           [((int)(local_34 + 4 + (local_34 + 4 >> 0x1f & 7U)) >> 3 & 0xffU) + 0x9a];
      DAT_1c412aa8[7] =
           "     !!!!!!\"\"\"\"\"######$$$$$$%%%%%%%&&&&&&&\'\'\'\'\'\'\'((((((())))))))********+++++++++,,,,,,,,,----------..........////////////////////////////////////////////"
           [((int)(local_2c + 4 + (local_2c + 4 >> 0x1f & 7U)) >> 3 & 0xffU) + 0x9a] * '\x10' +
           (char)local_44;
      DAT_1c412aa8[8] =
           (&DAT_1c405d84)[(int)(local_18 + 4 + (local_18 + 4 >> 0x1f & 7U)) >> 3 & 0xff] * '\x10' +
           (&DAT_1c405d84)[(int)(local_14 + 4 + (local_14 + 4 >> 0x1f & 7U)) >> 3 & 0xff];
      DAT_1c412aa8[9] =
           "  !\"\"#$$%%&&\'\'(())**+++,,--...//000111223334445556667777888999::::;;;;<<<====>>>>????@@@@@AAAABBBBCCCCCDDDDDEEEEEFFFFFGGGGGHHHHHIIIIIIJJJJJJKKKKKLLLLLLMMMMMMMNNNNNNOOOOOOOPPPPPPQQQQQQQRRRRRRRRSSSSSSST"
           [((int)(iVar8 + 0x10 + (iVar8 + 0x10 >> 0x1f & 0x1fU)) >> 5 & 0xffU) + 200];
      DAT_1c412aa8[0xb] = DAT_1c412ace;
      uVar14 = *(ushort *)(param_1 + 0x44) >> 1;
      if (uVar14 < 2) {
        uVar14 = 1;
      }
      DAT_1c412aa8[10] = (char)uVar14;
      iVar8 = (short)*DAT_1c4121e8 * 2;
      if (0x7f < iVar8) {
        iVar8 = 0x80;
      }
      if (iVar8 < 1) {
        iVar8 = 0;
      }
      DAT_1c412aa8[0x10] = (char)iVar8;
      iVar8 = *DAT_1c4121d4 * 2;
      if (0x7f < iVar8) {
        iVar8 = 0x80;
      }
      if (iVar8 < 1) {
        iVar8 = 0;
      }
      DAT_1c412aa8[0x11] = (char)iVar8;
      iVar8 = (short)*DAT_1c4121c8 * 2;
      if (0x7f < iVar8) {
        iVar8 = 0x80;
      }
      if (iVar8 < 1) {
        iVar8 = 0;
      }
      DAT_1c412aa8[0x12] = (char)iVar8;
      iVar8 = *DAT_1c4121e0 * 2 + 0x5c;
      if (iVar8 < 1) {
        iVar8 = 0;
      }
      DAT_1c412aa8[0x13] = (char)iVar8;
      DAT_1c412aa8[0x14] =
           (&DAT_1c405d84)[(int)(local_3c + 4 + (local_3c + 4 >> 0x1f & 7U)) >> 3 & 0xff] << 4;
      DAT_1c412aa8[0x1b] = local_47;
      *(short *)(DAT_1c412aa8 + 0x1c) = local_46;
      DAT_1c412aa8[0x17] = bVar13;
      DAT_1c412aa8[0x1f] = cVar3;
      if (*(short *)(param_1 + 0x4c) == 2) {
        *(undefined2 *)(DAT_1c412aa8 + 0x18) = *(undefined2 *)(param_1 + 0x46);
      }
      else if (*(short *)(param_1 + 0x4c) != 4) {
        *(undefined2 *)(DAT_1c412aa8 + 0x18) = 0;
      }
      DAT_1c412aa8 = DAT_1c412aa8 + 0x20;
      if ((bVar13 & 8) != 0) {
        bVar13 = bVar13 ^ 8;
      }
      if ((bVar13 & 0x20) != 0) {
        bVar13 = bVar13 ^ 0x20;
      }
      DAT_1c4121cc = DAT_1c4121cc + 1;
      DAT_1c4121d0 = DAT_1c4121d0 + 1;
      DAT_1c4121d8 = DAT_1c4121d8 + 1;
      DAT_1c4121b8 = DAT_1c4121b8 + 1;
      DAT_1c4121bc = DAT_1c4121bc + 1;
      DAT_1c4121c0 = DAT_1c4121c0 + 1;
      DAT_1c4121ec = DAT_1c4121ec + 1;
      DAT_1c4121f0 = DAT_1c4121f0 + 1;
      DAT_1c4124b4 = DAT_1c4124b4 + 1;
      _DAT_1c4121e4 = _DAT_1c4121e4 + 2;
      DAT_1c4121e8 = DAT_1c4121e8 + 1;
      local_42 = local_42 + 1;
      DAT_1c4121d4 = DAT_1c4121d4 + 1;
      DAT_1c4121c8 = DAT_1c4121c8 + 1;
      DAT_1c4121e0 = DAT_1c4121e0 + 1;
      _DAT_1c4121c4 = _DAT_1c4121c4 + 2;
      local_3c = iVar9;
      cVar3 = cVar3 + '\x01';
    } while (local_42 < DAT_1c4121b6);
  }
  *(undefined2 *)(*(int *)(param_1 + 0xf6) + 0x18) = *(undefined2 *)(param_1 + 0x46);
  FUN_1c403440(param_1,(int)(DAT_1c412aa8 + (uint)DAT_1c4121b6 * -0x20),puVar1);
  if (*(short *)(param_1 + 0x4c) == 3) {
    FUN_1c403c50(param_1,(int)(DAT_1c412aa8 + (uint)DAT_1c4121b6 * -0x20),puVar1);
  }
  else if (*(short *)(param_1 + 0x4c) == 4) {
    FUN_1c4039c0(param_1,(int)DAT_1c412aa8,puVar1);
  }
  bVar13 = 1;
  if ((*(uint *)((int)puVar1 + 0x16) & 0x100) != 0) {
    bVar13 = 3;
  }
  if ((*(uint *)((int)puVar1 + 0x16) & 0x80) != 0) {
    bVar13 = bVar13 | 4;
  }
  DAT_1c412aa8[(uint)DAT_1c4121b6 * -0x20 + 0x17] =
       DAT_1c412aa8[(uint)DAT_1c4121b6 * -0x20 + 0x17] | bVar13;
  *(undefined1 **)(param_1 + 0xfa) = DAT_1c412aa8;
  iVar12 = *(short *)(param_1 + 0x98) + 0x10;
  *(ushort *)(param_1 + 0xa0) =
       (ushort)(byte)"  !\"\"#$$%%&&\'\'(())**+++,,--...//000111223334445556667777888999::::;;;;<<<====>>>>????@@@@@AAAABBBBCCCCCDDDDDEEEEEFFFFFGGGGGHHHHHIIIIIIJJJJJJKKKKKLLLLLLMMMMMMMNNNNNNOOOOOOOPPPPPPQQQQQQQRRRRRRRRSSSSSSST"
                     [((int)(iVar12 + (iVar12 >> 0x1f & 0x1fU)) >> 5 & 0xffU) + 200];
  iVar12 = *(short *)(param_1 + 0x9c) + 0x10;
  *(ushort *)(param_1 + 0xa4) =
       (ushort)(byte)"  !\"\"#$$%%&&\'\'(())**+++,,--...//000111223334445556667777888999::::;;;;<<<====>>>>????@@@@@AAAABBBBCCCCCDDDDDEEEEEFFFFFGGGGGHHHHHIIIIIIJJJJJJKKKKKLLLLLLMMMMMMMNNNNNNOOOOOOOPPPPPPQQQQQQQRRRRRRRRSSSSSSST"
                     [((int)(iVar12 + (iVar12 >> 0x1f & 0x1fU)) >> 5 & 0xffU) + 200];
  iVar12 = *(short *)(param_1 + 0x9a) + 4;
  *(ushort *)(param_1 + 0xa2) =
       (ushort)(byte)(&DAT_1c405d84)[(int)(iVar12 + (iVar12 >> 0x1f & 7U)) >> 3 & 0xff];
  iVar12 = *(short *)(param_1 + 0x9e) + 4;
  iVar12 = iVar12 + (iVar12 >> 0x1f & 7U);
  bVar13 = (&DAT_1c405d84)[iVar12 >> 3 & 0xff];
  *(ushort *)(param_1 + 0xa6) = (ushort)bVar13;
  return CONCAT22((short)(iVar12 >> 0x13),(ushort)bVar13);
}


// ==== FUN_1c406210 @ 1c406210 size=54

undefined4 __cdecl FUN_1c406210(int param_1)

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


// ==== FUN_1c406250 @ 1c406250 size=151

void __cdecl FUN_1c406250(int param_1,int *param_2)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  
  uVar1 = param_2[6];
  if ((uVar1 & 4) == 0) {
    bVar2 = true;
    do {
      param_2[7] = param_2[7] & 0xfffffffb;
      iVar3 = FUN_1c409620(param_1,param_2);
      if (iVar3 != 0) {
        return;
      }
      iVar3 = FUN_1c406cc0(param_2);
      if (iVar3 != 0) {
        return;
      }
      iVar3 = FUN_1c407e20(param_2);
      if (iVar3 != 0) {
        return;
      }
      if ((*(byte *)(param_2 + 7) & 4) == 0) {
        iVar3 = FUN_1c4062f0(param_2);
        if (iVar3 != 0) {
          return;
        }
        if ((param_2[7] & 4U) == 0) {
          if (((uVar1 & 2) != 0) || ((param_2[7] & 1U) != 0)) {
            FUN_1c407240((int)param_2);
          }
          bVar2 = false;
        }
      }
    } while (bVar2);
  }
  else {
    iVar3 = FUN_1c409880(param_2);
    if (iVar3 == 0) {
      param_2[7] = param_2[7] & 0xfffffffb;
      return;
    }
  }
  return;
}


// ==== FUN_1c4062f0 @ 1c4062f0 size=1949

undefined4 __cdecl FUN_1c4062f0(int *param_1)

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
joined_r0x1c406318:
  if ((bVar6 != 0x20) && (bVar6 = *pbVar4, bVar6 != 0)) {
    if (((*(ushort *)(&DAT_1c409aa0 + (uint)bVar6 * 2) & 2) == 0) && (!bVar5)) {
      if ((*(ushort *)(&DAT_1c409aa0 + (uint)bVar6 * 2) & 0x80) == 0) {
LAB_1c406397:
        bVar5 = true;
        pbVar12 = PTR_DAT_1c40e3bc;
      }
      else {
        switch((uint)bVar6) {
        case 0xc4:
          pbVar12 = PTR_DAT_1c40e3a8;
          break;
        default:
          if (bVar6 < 0x7b) {
            pbVar12 = *(byte **)(&DAT_1c40e23c + (char)bVar6 * 4);
            break;
          }
          goto LAB_1c406397;
        case 0xd6:
          pbVar12 = PTR_DAT_1c40e3ac;
          break;
        case 0xdc:
          pbVar12 = PTR_DAT_1c40e3b4;
          break;
        case 0xdf:
          pbVar12 = PTR_DAT_1c40e3b0;
        }
      }
LAB_1c4063a5:
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
            goto LAB_1c406408;
          }
          iVar7 = FUN_1c406c10(*pbVar11);
          if (iVar7 == 0) {
            bVar6 = FUN_1c406b40(*pbVar13);
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
LAB_1c406408:
  bVar6 = *pbVar10;
  while (((bVar6 != 0x5c && (bVar6 = *pbVar10, bVar6 != 0x60)) && (bVar6 != 0x3d))) {
    if (((&DAT_1c409aa1)[(uint)bVar6 * 2] & 4) == 0) {
      iVar8 = FUN_1c406c10(bVar6);
      bVar6 = *pbVar12;
      if (iVar8 == 0) {
        bVar6 = FUN_1c406b40(bVar6);
      }
      if (*pbVar10 != bVar6) {
        pbVar12 = pbVar10 + 1;
        if (*pbVar12 == 0x5c) goto LAB_1c4063a5;
        goto LAB_1c406799;
      }
      pbVar12 = pbVar12 + iVar7;
    }
    else {
      switch(bVar6) {
      case 0x20:
        if (((&DAT_1c409aa0)[(uint)*pbVar12 * 2] & 0x80) != 0) {
          pbVar12 = pbVar10 + 1;
          if (*pbVar12 == 0x5c) goto LAB_1c4063a5;
          goto LAB_1c4067d5;
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
        if (*pbVar12 == 0x5c) goto LAB_1c4063a5;
        goto LAB_1c4067b7;
      case 0x23:
        if (((&DAT_1c409aa0)[(uint)*pbVar12 * 2] & 0x40) == 0) {
          pbVar12 = pbVar10 + 1;
          if (*pbVar12 == 0x5c) goto LAB_1c4063a5;
          goto LAB_1c4067f3;
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
            goto LAB_1c406552;
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
            if (*pbVar12 == 0x5c) goto LAB_1c4063a5;
            goto LAB_1c40682f;
          }
          bVar6 = pbVar12[3];
          iVar8 = 4;
LAB_1c406552:
          iVar8 = iVar8 + -1 + (uint)(bVar6 == 0x53);
        }
        pbVar12 = pbVar12 + iVar8;
        if (((&DAT_1c409aa0)[(uint)*pbVar12 * 2] & 0x80) != 0) {
          pbVar12 = pbVar10 + 1;
          if (*pbVar12 == 0x5c) goto LAB_1c4063a5;
          goto LAB_1c406811;
        }
        break;
      case 0x26:
        if (*pbVar12 == 0x48) {
          if ((pbVar12[-1] != 0x43) && (pbVar12[-1] != 0x53)) {
            pbVar12 = pbVar10 + 1;
            if (*pbVar12 == 0x5c) goto LAB_1c4063a5;
            goto LAB_1c40684d;
          }
          pbVar12 = pbVar12 + iVar7 * 2;
        }
        else {
          if (((&DAT_1c409aa0)[(uint)*pbVar12 * 2] & 0x10) == 0) {
            pbVar12 = pbVar10 + 1;
            if (*pbVar12 == 0x5c) goto LAB_1c4063a5;
            goto LAB_1c40686b;
          }
          pbVar12 = pbVar12 + iVar7;
        }
        break;
      case 0x2b:
        if (((&DAT_1c409aa1)[(uint)*pbVar12 * 2] & 1) == 0) {
          pbVar12 = pbVar10 + 1;
          if (*pbVar12 == 0x5c) goto LAB_1c4063a5;
          goto LAB_1c406889;
        }
        pbVar12 = pbVar12 + iVar7;
        break;
      case 0x2e:
        if (((byte)*(undefined2 *)(&DAT_1c409aa0 + (uint)*pbVar12 * 2) & 0x28) != 0x28) {
          pbVar12 = pbVar10 + 1;
          if (*pbVar12 == 0x5c) goto LAB_1c4063a5;
          goto LAB_1c4068a7;
        }
        pbVar12 = pbVar12 + iVar7;
        break;
      case 0x3a:
        if (((&DAT_1c409aa0)[(uint)*pbVar12 * 2] & 0x20) != 0) {
          do {
            pbVar12 = pbVar12 + iVar7;
          } while ((*(ushort *)(&DAT_1c409aa0 + (uint)*pbVar12 * 2) & 0x20) != 0);
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
        if ((uVar14 != 0) || (((&DAT_1c409aa0)[(uint)*pbVar12 * 2] & 3) == 0)) {
          pbVar12 = pbVar10 + 1;
          if (*pbVar12 == 0x5c) goto LAB_1c4063a5;
          goto LAB_1c4068c5;
        }
        pbVar12 = pbVar12 + iVar7;
        break;
      case 0x3e:
        if (((&DAT_1c409aa0)[(uint)*pbVar12 * 2] & 1) != 0) {
          pbVar12 = pbVar10 + 1;
          if (*pbVar12 == 0x5c) goto LAB_1c4063a5;
          goto LAB_1c4068e3;
        }
        pbVar12 = pbVar12 + iVar7;
        break;
      case 0x3f:
        if (((&DAT_1c409aa0)[(uint)*pbVar12 * 2] & 2) == 0) {
          pbVar12 = pbVar10 + 1;
          if (*pbVar12 == 0x5c) goto LAB_1c4063a5;
          goto LAB_1c406901;
        }
        pbVar12 = pbVar12 + iVar7;
        break;
      case 0x40:
        if (*pbVar12 == 0x48) {
          bVar6 = pbVar12[-1];
          if (((bVar6 != 0x54) && (bVar6 != 0x43)) && (bVar6 != 0x53)) {
            pbVar12 = pbVar10 + 1;
            if (*pbVar12 == 0x5c) goto LAB_1c4063a5;
            goto LAB_1c40691f;
          }
          pbVar12 = pbVar12 + iVar7 * 2;
        }
        else {
          if (((&DAT_1c409aa0)[(uint)*pbVar12 * 2] & 4) == 0) {
            pbVar12 = pbVar10 + 1;
            if (*pbVar12 == 0x5c) goto LAB_1c4063a5;
            goto LAB_1c40693d;
          }
          pbVar12 = pbVar12 + iVar7;
        }
        break;
      case 0x5e:
        if (((&DAT_1c409aa0)[(uint)*pbVar12 * 2] & 0x20) == 0) {
          pbVar12 = pbVar10 + 1;
          if (*pbVar12 == 0x5c) goto LAB_1c4063a5;
          goto LAB_1c40695b;
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
          if (*pbVar12 == 0x5c) goto LAB_1c4063a5;
          goto LAB_1c406979;
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
    goto joined_r0x1c40699d;
  }
  iVar7 = 1;
  pbVar10 = pbVar11 + 1;
  pbVar12 = pbVar13;
  goto LAB_1c406408;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c406799:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c4063a5;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c406979:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c4063a5;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c40695b:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c4063a5;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c40693d:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c4063a5;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c40691f:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c4063a5;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c406901:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c4063a5;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c4068e3:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c4063a5;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c4068c5:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c4063a5;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c4068a7:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c4063a5;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c406889:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c4063a5;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c40686b:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c4063a5;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c40684d:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c4063a5;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c40682f:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c4063a5;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c406811:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c4063a5;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c4067f3:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c4063a5;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c4067b7:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c4063a5;
  while (pbVar12 = pbVar12 + 1, *pbVar12 != 0x5c) {
LAB_1c4067d5:
    if (*pbVar12 == 0x60) break;
  }
  goto LAB_1c4063a5;
joined_r0x1c40699d:
  if (bVar6 == 0x5c) goto LAB_1c4069bf;
  if (bVar6 == 0x60) {
    uVar14 = uVar14 | 2;
    goto LAB_1c4069c2;
  }
  iVar7 = iVar7 + 1;
  if ((bVar6 == 0x2e) || (bVar6 == 0x3f)) {
    uVar14 = uVar14 | 8;
  }
  bVar6 = *pbVar10;
  pbVar10 = pbVar10 + 1;
  goto joined_r0x1c40699d;
LAB_1c4069bf:
  uVar14 = uVar14 | 1;
LAB_1c4069c2:
  if (param_1[5] < iVar7) {
    param_1[7] = 0;
    return 1;
  }
  if ((((*(byte *)(param_1 + 6) & 0x40) == 0) && (*pbVar4 == 0x3f)) && (iVar7 == 1)) {
    _Count = 1;
    pbVar12 = &DAT_1c40e3c0;
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
  goto joined_r0x1c406318;
}


// ==== FUN_1c406b40 @ 1c406b40 size=87

byte __cdecl FUN_1c406b40(byte param_1)

{
  if (((&DAT_1c409aa0)[(uint)param_1 * 2] & 0x40) != 0) {
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


// ==== FUN_1c406c10 @ 1c406c10 size=47

undefined4 __cdecl FUN_1c406c10(byte param_1)

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


// ==== FUN_1c406cc0 @ 1c406cc0 size=1286

undefined4 __cdecl FUN_1c406cc0(int *param_1)

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
LAB_1c406cdd:
  bVar4 = *pbVar7;
  if ((*(ushort *)(&DAT_1c409aa0 + (uint)bVar4 * 2) & 0x80) == 0) {
    pbVar11 = PTR_DAT_1c40e430;
    if ((*(ushort *)(&DAT_1c409aa0 + (uint)bVar4 * 2) & 2) == 0) goto LAB_1c406d11;
  }
  else {
    if (bVar4 < 0x7b) {
      pbVar11 = *(byte **)(&DAT_1c40e2c4 + (char)bVar4 * 4);
      goto LAB_1c406d1f;
    }
LAB_1c406d11:
    pbVar11 = PTR_DAT_1c40e434;
  }
  bVar3 = true;
LAB_1c406d1f:
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
        goto LAB_1c406dcb;
      }
      iVar5 = FUN_1c406c10(*pbVar10);
      if (iVar5 == 0) {
        bVar4 = FUN_1c406b40(*pbVar8);
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
LAB_1c406dcb:
  bVar4 = *pbVar9;
joined_r0x1c406dce:
  if ((bVar4 == 0x5c) || (bVar4 = *pbVar9, bVar4 == 0x3d)) goto LAB_1c407000;
  if (((&DAT_1c409aa1)[(uint)bVar4 * 2] & 4) != 0) {
    switch(bVar4) {
    case 0x20:
      if (((&DAT_1c409aa0)[(uint)*pbVar11 * 2] & 0x80) != 0) {
        pbVar11 = pbVar9 + 1;
        bVar4 = *pbVar11;
        while (bVar4 != 0x5c) {
          pbVar11 = pbVar11 + 1;
          bVar4 = *pbVar11;
        }
        goto LAB_1c406d1f;
      }
      pbVar9 = pbVar9 + iVar5;
      pbVar11 = pbVar11 + iVar5;
      break;
    case 0x23:
    case 0x2b:
      if (((&DAT_1c409aa0)[(uint)*pbVar11 * 2] & 0x40) == 0) {
        pbVar11 = pbVar9 + 1;
        bVar4 = *pbVar11;
        while (bVar4 != 0x5c) {
          pbVar11 = pbVar11 + 1;
          bVar4 = *pbVar11;
        }
        goto LAB_1c406d1f;
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
          goto LAB_1c406ed6;
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
          goto LAB_1c406d1f;
        }
        bVar4 = pbVar11[3];
        iVar6 = 4;
LAB_1c406ed6:
        iVar6 = iVar6 + -1 + (uint)(bVar4 == 0x53);
      }
      pbVar11 = pbVar11 + iVar6;
      if (((&DAT_1c409aa0)[(uint)*pbVar11 * 2] & 0x80) == 0) goto LAB_1c406ff5;
      pbVar11 = pbVar9 + 1;
      bVar4 = *pbVar11;
      while (bVar4 != 0x5c) {
        pbVar11 = pbVar11 + 1;
        bVar4 = *pbVar11;
      }
      goto LAB_1c406d1f;
    case 0x26:
      if (*pbVar11 == 0x48) {
        if ((pbVar11[-1] != 0x43) && (pbVar11[-1] != 0x53)) {
          pbVar11 = pbVar9 + 1;
          bVar4 = *pbVar11;
          while (bVar4 != 0x5c) {
            pbVar11 = pbVar11 + 1;
            bVar4 = *pbVar11;
          }
          goto LAB_1c406d1f;
        }
        pbVar9 = pbVar9 + iVar5;
        pbVar11 = pbVar11 + iVar5 * 2;
      }
      else {
        if (((&DAT_1c409aa0)[(uint)*pbVar11 * 2] & 0x10) == 0) {
          pbVar11 = pbVar9 + 1;
          bVar4 = *pbVar11;
          while (bVar4 != 0x5c) {
            pbVar11 = pbVar11 + 1;
            bVar4 = *pbVar11;
          }
          goto LAB_1c406d1f;
        }
        pbVar9 = pbVar9 + iVar5;
        pbVar11 = pbVar11 + iVar5;
      }
      break;
    case 0x2e:
      if (((byte)*(undefined2 *)(&DAT_1c409aa0 + (uint)*pbVar11 * 2) & 0x28) != 0x28) {
        pbVar11 = pbVar9 + 1;
        bVar4 = *pbVar11;
        while (bVar4 != 0x5c) {
          pbVar11 = pbVar11 + 1;
          bVar4 = *pbVar11;
        }
        goto LAB_1c406d1f;
      }
      pbVar9 = pbVar9 + iVar5;
      pbVar11 = pbVar11 + iVar5;
      break;
    case 0x3a:
      if (((&DAT_1c409aa0)[(uint)*pbVar11 * 2] & 0x20) != 0) {
        do {
          pbVar11 = pbVar11 + iVar5;
        } while ((*(ushort *)(&DAT_1c409aa0 + (uint)*pbVar11 * 2) & 0x20) != 0);
      }
LAB_1c406ff5:
      pbVar9 = pbVar9 + iVar5;
      break;
    case 0x3e:
      if (((&DAT_1c409aa0)[(uint)*pbVar11 * 2] & 1) != 0) {
        pbVar11 = pbVar9 + 1;
        bVar4 = *pbVar11;
        while (bVar4 != 0x5c) {
          pbVar11 = pbVar11 + 1;
          bVar4 = *pbVar11;
        }
        goto LAB_1c406d1f;
      }
      pbVar9 = pbVar9 + iVar5;
      pbVar11 = pbVar11 + iVar5;
      break;
    case 0x3f:
      if (((&DAT_1c409aa0)[(uint)*pbVar11 * 2] & 2) == 0) {
        pbVar11 = pbVar9 + 1;
        bVar4 = *pbVar11;
        while (bVar4 != 0x5c) {
          pbVar11 = pbVar11 + 1;
          bVar4 = *pbVar11;
        }
        goto LAB_1c406d1f;
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
          goto LAB_1c406d1f;
        }
        pbVar9 = pbVar9 + iVar5;
        pbVar11 = pbVar11 + iVar5 * 2;
      }
      else {
        if (((&DAT_1c409aa0)[(uint)*pbVar11 * 2] & 4) == 0) {
          pbVar11 = pbVar9 + 1;
          bVar4 = *pbVar11;
          while (bVar4 != 0x5c) {
            pbVar11 = pbVar11 + 1;
            bVar4 = *pbVar11;
          }
          goto LAB_1c406d1f;
        }
        pbVar9 = pbVar9 + iVar5;
        pbVar11 = pbVar11 + iVar5;
      }
      break;
    case 0x5e:
      if (((&DAT_1c409aa0)[(uint)*pbVar11 * 2] & 0x20) == 0) {
        pbVar11 = pbVar9 + 1;
        bVar4 = *pbVar11;
        while (bVar4 != 0x5c) {
          pbVar11 = pbVar11 + 1;
          bVar4 = *pbVar11;
        }
        goto LAB_1c406d1f;
      }
      pbVar9 = pbVar9 + iVar5;
      pbVar11 = pbVar11 + iVar5;
    }
switchD_1c406e2c_caseD_21:
    bVar4 = *pbVar9;
    goto joined_r0x1c406dce;
  }
  iVar6 = FUN_1c406c10(bVar4);
  bVar4 = *pbVar11;
  if (iVar6 == 0) {
    bVar4 = FUN_1c406b40(bVar4);
  }
  if (*pbVar9 == bVar4) {
    pbVar9 = pbVar9 + iVar5;
    pbVar11 = pbVar11 + iVar5;
    goto switchD_1c406e2c_caseD_21;
  }
  pbVar11 = pbVar9 + 1;
  bVar4 = *pbVar11;
  while (bVar4 != 0x5c) {
    pbVar11 = pbVar11 + 1;
    bVar4 = *pbVar11;
  }
  goto LAB_1c406d1f;
LAB_1c407000:
  local_8 = local_8 + 1;
  if (local_8 < 2) {
    iVar5 = 1;
    pbVar9 = pbVar10 + 1;
    pbVar11 = pbVar8;
    goto LAB_1c406dcb;
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
  goto LAB_1c406cdd;
}


// ==== FUN_1c407240 @ 1c407240 size=395

undefined4 __cdecl FUN_1c407240(int param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  byte bVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *local_4;
  
  iVar5 = 0;
  pbVar6 = *(byte **)(param_1 + 4);
  pbVar7 = pbVar6;
  bVar1 = *pbVar6;
  while (bVar1 != 0x20) {
    bVar1 = *pbVar7;
    if (((((&DAT_1c409aa0)[(uint)bVar1 * 2] & 2) != 0) && (bVar1 != 0x31)) && (bVar1 != 0x32)) {
      return 0;
    }
    pbVar7 = pbVar7 + -1;
    bVar1 = *pbVar7;
  }
  uVar3 = *(ushort *)(&DAT_1c409aa0 + (uint)*pbVar6 * 2);
  while ((uVar3 & 0x80) == 0) {
    pbVar6 = pbVar6 + -1;
    uVar3 = *(ushort *)(&DAT_1c409aa0 + (uint)*pbVar6 * 2);
  }
  bVar1 = *pbVar6;
  pbVar9 = local_4;
  pbVar7 = pbVar6;
  if ((bVar1 != 0x4e) && (bVar1 != 0x53)) {
    pbVar8 = (byte *)(s_IYEHAAEYAYOYOHUWPOHR_SIYEH5NTOH_1c40e438 + 1);
    while (((*pbVar8 != bVar1 || (pbVar6[-1] != pbVar8[-1])) ||
           ((pbVar8 == (byte *)(s_IYEHAAEYAYOYOHUWPOHR_SIYEH5NTOH_1c40e438 + 0xb) ||
            (pbVar8 == (byte *)(s_IYEHAAEYAYOYOHUWPOHR_SIYEH5NTOH_1c40e438 + 9)))))) {
      pbVar8 = pbVar8 + 2;
      if (s_IYEHAAEYAYOYOHUWPOHR_SIYEH5NTOH_1c40e438 + 0x10 < pbVar8) {
        do {
          if (bVar1 == 0x20) {
            return 0;
          }
          pbVar7 = (byte *)(s_IYEHAAEYAYOYOHUWPOHR_SIYEH5NTOH_1c40e438 + 1);
          do {
            if ((*pbVar7 == *pbVar6) && (pbVar6[-1] == pbVar7[-1])) {
              iVar5 = 1;
              goto LAB_1c407365;
            }
            pbVar7 = pbVar7 + 2;
          } while (pbVar7 < s_IYEHAAEYAYOYOHUWPOHR_SIYEH5NTOH_1c40e438 + 0x11);
          pbVar6 = pbVar6 + -1;
          bVar1 = *pbVar6;
        } while( true );
      }
    }
  }
  while (pbVar6 = pbVar9, bVar1 != 0x20) {
    pbVar8 = (byte *)(s_IYEHAAEYAYOYOHUWPOHR_SIYEH5NTOH_1c40e438 + 1);
    pbVar9 = pbVar6;
    do {
      pbVar6 = pbVar7;
      pbVar7 = pbVar6;
      if ((*pbVar6 == *pbVar8) && (pbVar8[-1] == pbVar6[-1])) {
        iVar5 = iVar5 + 1;
        if ((1 < iVar5) &&
           (((pbVar8 != (byte *)(s_IYEHAAEYAYOYOHUWPOHR_SIYEH5NTOH_1c40e438 + 1) || (iVar5 != 2)) ||
            ((int)local_4 - (int)pbVar6 != 2)))) goto LAB_1c407365;
        pbVar7 = pbVar6 + -1;
        local_4 = pbVar6;
        pbVar9 = pbVar6;
      }
      pbVar8 = pbVar8 + 2;
    } while (pbVar8 < s_IYEHAAEYAYOYOHUWPOHR_SIYEH5NTOH_1c40e438 + 0x11);
    bVar1 = pbVar7[-1];
    pbVar7 = pbVar7 + -1;
  }
LAB_1c407365:
  if (iVar5 == 0) {
    return 0;
  }
  pbVar6 = pbVar6 + 1;
  if (((&DAT_1c409aa0)[(uint)*pbVar6 * 2] & 2) != 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x14) < 1) {
    return 1;
  }
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
  bVar1 = *pbVar6;
  bVar4 = 0x35;
  while (bVar1 != 0) {
    bVar2 = *pbVar6;
    *pbVar6 = bVar4;
    pbVar6 = pbVar6 + 1;
    bVar4 = bVar2;
    bVar1 = *pbVar6;
  }
  *pbVar6 = bVar4;
  pbVar6[1] = 0;
  *(byte **)(param_1 + 4) = pbVar6 + 1;
  return 0;
}


// ==== FUN_1c4073d0 @ 1c4073d0 size=2423

undefined4 __cdecl FUN_1c4073d0(char *param_1,byte *param_2,char *param_3)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  size_t sVar5;
  undefined3 extraout_var;
  uint uVar6;
  size_t sVar7;
  size_t sVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  char *pcVar15;
  char *pcVar16;
  char *pcVar17;
  char *pcVar18;
  bool bVar19;
  bool bVar20;
  uint local_34;
  int local_2c;
  int local_24;
  int local_20;
  size_t local_c;
  
  uVar6 = 0xffffffff;
  pcVar16 = param_1;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar16;
    pcVar16 = pcVar16 + 1;
  } while (cVar1 != '\0');
  iVar14 = ~uVar6 - 1;
  bVar19 = *param_1 == '$';
  if (bVar19) {
    iVar14 = ~uVar6 - 2;
    param_1 = param_1 + 1;
  }
  pcVar16 = param_1 + iVar14 + -1;
  bVar20 = *pcVar16 == '%';
  if (bVar20) {
    iVar14 = iVar14 + -1;
    *pcVar16 = '\0';
  }
  sVar5 = strcspn(param_1,(char *)&DAT_1c40e548);
  if (0x52 < (int)sVar5) {
    if (bVar20) {
      *pcVar16 = '%';
    }
    return 0;
  }
  local_2c = (iVar14 - sVar5) + -1;
  if (local_2c < 1) {
    local_2c = 0;
  }
  bVar4 = FUN_1c407da0((char *)param_2);
  iVar14 = CONCAT31(extraout_var,bVar4);
  if (((bVar19) && (sVar5 == 1)) && (*param_1 == '1')) {
    bVar4 = true;
  }
  else {
    bVar4 = false;
  }
  if (((bVar19) && ((local_2c == 2 || (local_2c == 0)))) && (iVar14 == 0)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  bVar3 = true;
  iVar11 = 0;
  pcVar17 = &DAT_1c411d80 + (sVar5 - !bVar19);
  sVar7 = sVar5;
  while (sVar7 != 0) {
    sVar7 = sVar7 - 1;
    cVar1 = *pcVar17;
    pcVar17 = pcVar17 + -1;
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
  if ((local_2c != 0) && (pcVar17 = strchr(param_1 + sVar5 + 1,0x2e), pcVar17 != (char *)0x0)) {
    bVar3 = false;
  }
  if (!bVar3) {
    if (bVar20) {
      *pcVar16 = '%';
    }
    return 0;
  }
  local_20 = 0;
  pcVar17 = param_1;
  sVar8 = sVar5;
  sVar7 = sVar5;
  if (0 < (int)sVar5) {
    do {
      local_20 = local_20 + (uint)(*pcVar17 == ',');
      sVar8 = sVar8 - 1;
      pcVar17 = pcVar17 + 1;
    } while (sVar8 != 0);
  }
  for (; 0 < (int)sVar7; sVar7 = sVar7 - (local_c + 1)) {
    sVar8 = strcspn(param_1,&DAT_1c40e544);
    if (sVar8 < 3) {
      local_c = strcspn(param_1,&DAT_1c40e544);
    }
    else {
      local_c = 3;
    }
    iVar11 = 0;
    iVar13 = 0;
    local_24 = 0;
    if (local_c == 1) {
LAB_1c407604:
      iVar11 = *param_1 + -0x30;
      param_1 = param_1 + 1;
    }
    else {
      if (local_c == 2) {
LAB_1c4075f6:
        iVar13 = *param_1 + -0x30;
        param_1 = param_1 + 1;
        goto LAB_1c407604;
      }
      if (local_c == 3) {
        local_24 = *param_1 + -0x30;
        param_1 = param_1 + 1;
        goto LAB_1c4075f6;
      }
    }
    if ((local_24 + iVar13 == 0) && (iVar11 == 1)) {
      if (local_20 == 0) {
        pcVar17 = &DAT_1c40e53c;
        goto LAB_1c40788b;
      }
    }
    else {
      if (local_24 != 0) {
        switch(local_24) {
        case 2:
        case 3:
        case 4:
        case 6:
        case 8:
          uVar6 = 0xffffffff;
          pcVar17 = (&PTR_DAT_1c40eb98)[local_24];
          do {
            pcVar15 = pcVar17;
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            pcVar15 = pcVar17 + 1;
            cVar1 = *pcVar17;
            pcVar17 = pcVar15;
          } while (cVar1 != '\0');
          uVar6 = ~uVar6;
          iVar9 = -1;
          pcVar17 = param_3;
          do {
            pcVar18 = pcVar17;
            if (iVar9 == 0) break;
            iVar9 = iVar9 + -1;
            pcVar18 = pcVar17 + 1;
            cVar1 = *pcVar17;
            pcVar17 = pcVar18;
          } while (cVar1 != '\0');
          pcVar17 = pcVar15 + -uVar6;
          pcVar15 = pcVar18 + -1;
          for (uVar10 = uVar6 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined4 *)pcVar15 = *(undefined4 *)pcVar17;
            pcVar17 = pcVar17 + 4;
            pcVar15 = pcVar15 + 4;
          }
          for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
            *pcVar15 = *pcVar17;
            pcVar17 = pcVar17 + 1;
            pcVar15 = pcVar15 + 1;
          }
        case 1:
          uVar6 = 0xffffffff;
          pcVar17 = &DAT_1c40e534;
          do {
            pcVar15 = pcVar17;
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            pcVar15 = pcVar17 + 1;
            cVar1 = *pcVar17;
            pcVar17 = pcVar15;
          } while (cVar1 != '\0');
          uVar6 = ~uVar6;
          iVar9 = -1;
          pcVar17 = param_3;
          do {
            pcVar18 = pcVar17;
            if (iVar9 == 0) break;
            iVar9 = iVar9 + -1;
            pcVar18 = pcVar17 + 1;
            cVar1 = *pcVar17;
            pcVar17 = pcVar18;
          } while (cVar1 != '\0');
          pcVar17 = pcVar15 + -uVar6;
          pcVar15 = pcVar18 + -1;
          for (uVar10 = uVar6 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined4 *)pcVar15 = *(undefined4 *)pcVar17;
            pcVar17 = pcVar17 + 4;
            pcVar15 = pcVar15 + 4;
          }
          break;
        case 5:
          uVar6 = 0xffffffff;
          pcVar17 = &DAT_1c40e528;
          do {
            pcVar15 = pcVar17;
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            pcVar15 = pcVar17 + 1;
            cVar1 = *pcVar17;
            pcVar17 = pcVar15;
          } while (cVar1 != '\0');
          uVar6 = ~uVar6;
          iVar9 = -1;
          pcVar17 = param_3;
          do {
            pcVar18 = pcVar17;
            if (iVar9 == 0) break;
            iVar9 = iVar9 + -1;
            pcVar18 = pcVar17 + 1;
            cVar1 = *pcVar17;
            pcVar17 = pcVar18;
          } while (cVar1 != '\0');
          pcVar17 = pcVar15 + -uVar6;
          pcVar15 = pcVar18 + -1;
          for (uVar10 = uVar6 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined4 *)pcVar15 = *(undefined4 *)pcVar17;
            pcVar17 = pcVar17 + 4;
            pcVar15 = pcVar15 + 4;
          }
          break;
        case 7:
          uVar6 = 0xffffffff;
          pcVar17 = &DAT_1c40e518;
          do {
            pcVar15 = pcVar17;
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            pcVar15 = pcVar17 + 1;
            cVar1 = *pcVar17;
            pcVar17 = pcVar15;
          } while (cVar1 != '\0');
          uVar6 = ~uVar6;
          iVar9 = -1;
          pcVar17 = param_3;
          do {
            pcVar18 = pcVar17;
            if (iVar9 == 0) break;
            iVar9 = iVar9 + -1;
            pcVar18 = pcVar17 + 1;
            cVar1 = *pcVar17;
            pcVar17 = pcVar18;
          } while (cVar1 != '\0');
          pcVar17 = pcVar15 + -uVar6;
          pcVar15 = pcVar18 + -1;
          for (uVar10 = uVar6 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined4 *)pcVar15 = *(undefined4 *)pcVar17;
            pcVar17 = pcVar17 + 4;
            pcVar15 = pcVar15 + 4;
          }
          break;
        case 9:
          uVar6 = 0xffffffff;
          pcVar17 = &DAT_1c40e508;
          do {
            pcVar15 = pcVar17;
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            pcVar15 = pcVar17 + 1;
            cVar1 = *pcVar17;
            pcVar17 = pcVar15;
          } while (cVar1 != '\0');
          uVar6 = ~uVar6;
          iVar9 = -1;
          pcVar17 = param_3;
          do {
            pcVar18 = pcVar17;
            if (iVar9 == 0) break;
            iVar9 = iVar9 + -1;
            pcVar18 = pcVar17 + 1;
            cVar1 = *pcVar17;
            pcVar17 = pcVar18;
          } while (cVar1 != '\0');
          pcVar17 = pcVar15 + -uVar6;
          pcVar15 = pcVar18 + -1;
          for (uVar10 = uVar6 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined4 *)pcVar15 = *(undefined4 *)pcVar17;
            pcVar17 = pcVar17 + 4;
            pcVar15 = pcVar15 + 4;
          }
          break;
        default:
          goto switchD_1c40764d_default;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar15 = *pcVar17;
          pcVar17 = pcVar17 + 1;
          pcVar15 = pcVar15 + 1;
        }
switchD_1c40764d_default:
        if (local_24 < 2) {
          if (iVar11 + iVar13 == 0) {
            uVar6 = 0xffffffff;
            pcVar17 = &DAT_1c40e4f4;
            do {
              pcVar15 = pcVar17;
              if (uVar6 == 0) break;
              uVar6 = uVar6 - 1;
              pcVar15 = pcVar17 + 1;
              cVar1 = *pcVar17;
              pcVar17 = pcVar15;
            } while (cVar1 != '\0');
            local_34 = ~uVar6;
            iVar9 = -1;
            pcVar17 = param_3;
            do {
              pcVar18 = pcVar17;
              if (iVar9 == 0) break;
              iVar9 = iVar9 + -1;
              pcVar18 = pcVar17 + 1;
              cVar1 = *pcVar17;
              pcVar17 = pcVar18;
            } while (cVar1 != '\0');
            pcVar17 = pcVar15 + -local_34;
            pcVar15 = pcVar18 + -1;
            for (uVar6 = local_34 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
              *(undefined4 *)pcVar15 = *(undefined4 *)pcVar17;
              pcVar17 = pcVar17 + 4;
              pcVar15 = pcVar15 + 4;
            }
          }
          else {
            uVar6 = 0xffffffff;
            pcVar17 = &DAT_1c40e4f8;
            do {
              pcVar15 = pcVar17;
              if (uVar6 == 0) break;
              uVar6 = uVar6 - 1;
              pcVar15 = pcVar17 + 1;
              cVar1 = *pcVar17;
              pcVar17 = pcVar15;
            } while (cVar1 != '\0');
            local_34 = ~uVar6;
            iVar9 = -1;
            pcVar17 = param_3;
            do {
              pcVar18 = pcVar17;
              if (iVar9 == 0) break;
              iVar9 = iVar9 + -1;
              pcVar18 = pcVar17 + 1;
              cVar1 = *pcVar17;
              pcVar17 = pcVar18;
            } while (cVar1 != '\0');
            pcVar17 = pcVar15 + -local_34;
            pcVar15 = pcVar18 + -1;
            for (uVar6 = local_34 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
              *(undefined4 *)pcVar15 = *(undefined4 *)pcVar17;
              pcVar17 = pcVar17 + 4;
              pcVar15 = pcVar15 + 4;
            }
          }
        }
        else {
          uVar6 = 0xffffffff;
          pcVar17 = (char *)&DAT_1c40e500;
          do {
            pcVar15 = pcVar17;
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            pcVar15 = pcVar17 + 1;
            cVar1 = *pcVar17;
            pcVar17 = pcVar15;
          } while (cVar1 != '\0');
          local_34 = ~uVar6;
          iVar9 = -1;
          pcVar17 = param_3;
          do {
            pcVar18 = pcVar17;
            if (iVar9 == 0) break;
            iVar9 = iVar9 + -1;
            pcVar18 = pcVar17 + 1;
            cVar1 = *pcVar17;
            pcVar17 = pcVar18;
          } while (cVar1 != '\0');
          pcVar17 = pcVar15 + -local_34;
          pcVar15 = pcVar18 + -1;
          for (uVar6 = local_34 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
            *(undefined4 *)pcVar15 = *(undefined4 *)pcVar17;
            pcVar17 = pcVar17 + 4;
            pcVar15 = pcVar15 + 4;
          }
        }
        for (uVar6 = local_34 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar15 = *pcVar17;
          pcVar17 = pcVar17 + 1;
          pcVar15 = pcVar15 + 1;
        }
      }
      if (iVar13 < 2) {
        iVar9 = iVar11 + iVar13 * 10;
        if (iVar9 != 0) {
          pcVar17 = (&PTR_DAT_1c40eb98)[iVar9];
          goto LAB_1c40788b;
        }
      }
      else {
        if (iVar11 == 0) {
          pcVar17 = (&PTR_DAT_1c40ebe8)[iVar13];
        }
        else {
          pcVar17 = (&PTR_DAT_1c40ec10)[iVar13];
        }
        uVar6 = 0xffffffff;
        do {
          pcVar15 = pcVar17;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar15 = pcVar17 + 1;
          cVar1 = *pcVar17;
          pcVar17 = pcVar15;
        } while (cVar1 != '\0');
        uVar6 = ~uVar6;
        iVar9 = -1;
        pcVar17 = param_3;
        do {
          pcVar18 = pcVar17;
          if (iVar9 == 0) break;
          iVar9 = iVar9 + -1;
          pcVar18 = pcVar17 + 1;
          cVar1 = *pcVar17;
          pcVar17 = pcVar18;
        } while (cVar1 != '\0');
        pcVar17 = pcVar15 + -uVar6;
        pcVar15 = pcVar18 + -1;
        for (uVar10 = uVar6 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *(undefined4 *)pcVar15 = *(undefined4 *)pcVar17;
          pcVar17 = pcVar17 + 4;
          pcVar15 = pcVar15 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar15 = *pcVar17;
          pcVar17 = pcVar17 + 1;
          pcVar15 = pcVar15 + 1;
        }
        if (iVar11 != 0) {
          pcVar17 = (&PTR_DAT_1c40eb98)[iVar11];
LAB_1c40788b:
          uVar6 = 0xffffffff;
          do {
            pcVar15 = pcVar17;
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            pcVar15 = pcVar17 + 1;
            cVar1 = *pcVar17;
            pcVar17 = pcVar15;
          } while (cVar1 != '\0');
          uVar6 = ~uVar6;
          iVar9 = -1;
          pcVar17 = param_3;
          do {
            pcVar18 = pcVar17;
            if (iVar9 == 0) break;
            iVar9 = iVar9 + -1;
            pcVar18 = pcVar17 + 1;
            cVar1 = *pcVar17;
            pcVar17 = pcVar18;
          } while (cVar1 != '\0');
          pcVar17 = pcVar15 + -uVar6;
          pcVar15 = pcVar18 + -1;
          for (uVar10 = uVar6 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined4 *)pcVar15 = *(undefined4 *)pcVar17;
            pcVar17 = pcVar17 + 4;
            pcVar15 = pcVar15 + 4;
          }
          for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
            *pcVar15 = *pcVar17;
            pcVar17 = pcVar17 + 1;
            pcVar15 = pcVar15 + 1;
          }
        }
      }
    }
    local_34 = (uint)(iVar11 + local_24 + iVar13 == 0);
    if (local_34 == 0) {
      if (local_20 != 0) {
        uVar6 = 0xffffffff;
        pcVar17 = (&PTR_s_SIYEH5NTOH_1c40eb38)[local_20];
        do {
          pcVar15 = pcVar17;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar15 = pcVar17 + 1;
          cVar1 = *pcVar17;
          pcVar17 = pcVar15;
        } while (cVar1 != '\0');
        uVar6 = ~uVar6;
        iVar11 = -1;
        pcVar17 = param_3;
        do {
          pcVar18 = pcVar17;
          if (iVar11 == 0) break;
          iVar11 = iVar11 + -1;
          pcVar18 = pcVar17 + 1;
          cVar1 = *pcVar17;
          pcVar17 = pcVar18;
        } while (cVar1 != '\0');
        pcVar17 = pcVar15 + -uVar6;
        pcVar15 = pcVar18 + -1;
        for (uVar10 = uVar6 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *(undefined4 *)pcVar15 = *(undefined4 *)pcVar17;
          pcVar17 = pcVar17 + 4;
          pcVar15 = pcVar15 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar15 = *pcVar17;
          pcVar17 = pcVar17 + 1;
          pcVar15 = pcVar15 + 1;
        }
        uVar6 = 0xffffffff;
        local_20 = local_20 + -1;
        pcVar17 = (char *)&DAT_1c40e4e4;
        do {
          pcVar15 = pcVar17;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar15 = pcVar17 + 1;
          cVar1 = *pcVar17;
          pcVar17 = pcVar15;
        } while (cVar1 != '\0');
        uVar6 = ~uVar6;
        iVar11 = -1;
        pcVar17 = param_3;
        do {
          pcVar18 = pcVar17;
          if (iVar11 == 0) break;
          iVar11 = iVar11 + -1;
          pcVar18 = pcVar17 + 1;
          cVar1 = *pcVar17;
          pcVar17 = pcVar18;
        } while (cVar1 != '\0');
        pcVar17 = pcVar15 + -uVar6;
        pcVar15 = pcVar18 + -1;
        for (uVar10 = uVar6 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *(undefined4 *)pcVar15 = *(undefined4 *)pcVar17;
          pcVar17 = pcVar17 + 4;
          pcVar15 = pcVar15 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar15 = *pcVar17;
          pcVar17 = pcVar17 + 1;
          pcVar15 = pcVar15 + 1;
        }
      }
    }
    else {
      if ((int)sVar7 < 4) {
        while (bVar3 = sVar7 != 0, sVar7 = sVar7 - 1, bVar3) {
          uVar6 = 0xffffffff;
          pcVar17 = &DAT_1c40e4e8;
          do {
            pcVar15 = pcVar17;
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            pcVar15 = pcVar17 + 1;
            cVar1 = *pcVar17;
            pcVar17 = pcVar15;
          } while (cVar1 != '\0');
          uVar6 = ~uVar6;
          iVar11 = -1;
          pcVar17 = param_3;
          do {
            pcVar18 = pcVar17;
            if (iVar11 == 0) break;
            iVar11 = iVar11 + -1;
            pcVar18 = pcVar17 + 1;
            cVar1 = *pcVar17;
            pcVar17 = pcVar18;
          } while (cVar1 != '\0');
          pcVar17 = pcVar15 + -uVar6;
          pcVar15 = pcVar18 + -1;
          for (uVar10 = uVar6 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined4 *)pcVar15 = *(undefined4 *)pcVar17;
            pcVar17 = pcVar17 + 4;
            pcVar15 = pcVar15 + 4;
          }
          for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
            *pcVar15 = *pcVar17;
            pcVar17 = pcVar17 + 1;
            pcVar15 = pcVar15 + 1;
          }
        }
      }
      local_20 = local_20 + -1;
    }
    param_1 = param_1 + 1;
  }
  if ((local_34 != 0) && (pcVar17 = strrchr(param_3,0x2c), pcVar17 != (char *)0x0)) {
    *pcVar17 = '\0';
  }
  if (sVar5 == 0) {
    param_1 = param_1 + 1;
  }
  if (bVar19) {
    if (bVar2) {
      if (bVar4) {
        pcVar17 = &DAT_1c40e4d8;
LAB_1c4079f6:
        uVar6 = 0xffffffff;
        do {
          pcVar15 = pcVar17;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar15 = pcVar17 + 1;
          cVar1 = *pcVar17;
          pcVar17 = pcVar15;
        } while (cVar1 != '\0');
        uVar6 = ~uVar6;
        iVar11 = -1;
        pcVar17 = param_3;
        do {
          pcVar18 = pcVar17;
          if (iVar11 == 0) break;
          iVar11 = iVar11 + -1;
          pcVar18 = pcVar17 + 1;
          cVar1 = *pcVar17;
          pcVar17 = pcVar18;
        } while (cVar1 != '\0');
        pcVar17 = pcVar15 + -uVar6;
        pcVar15 = pcVar18 + -1;
        for (uVar10 = uVar6 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *(undefined4 *)pcVar15 = *(undefined4 *)pcVar17;
          pcVar17 = pcVar17 + 4;
          pcVar15 = pcVar15 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar15 = *pcVar17;
          pcVar17 = pcVar17 + 1;
          pcVar15 = pcVar15 + 1;
        }
      }
      else if (sVar5 != 0) {
        pcVar17 = &DAT_1c40e4c8;
        goto LAB_1c4079f6;
      }
      if (local_2c == 2) {
        iVar13 = *param_1 + -0x30;
        iVar9 = param_1[1] + -0x30;
        param_1 = param_1 + 2;
        iVar11 = iVar9 + iVar13 * 10;
        if (iVar11 != 0) {
          if (iVar13 < 2) {
            pcVar17 = (&PTR_DAT_1c40eb98)[iVar11];
LAB_1c407aa5:
            uVar6 = 0xffffffff;
            do {
              pcVar15 = pcVar17;
              if (uVar6 == 0) break;
              uVar6 = uVar6 - 1;
              pcVar15 = pcVar17 + 1;
              cVar1 = *pcVar17;
              pcVar17 = pcVar15;
            } while (cVar1 != '\0');
            uVar6 = ~uVar6;
            iVar13 = -1;
            pcVar17 = param_3;
            do {
              pcVar18 = pcVar17;
              if (iVar13 == 0) break;
              iVar13 = iVar13 + -1;
              pcVar18 = pcVar17 + 1;
              cVar1 = *pcVar17;
              pcVar17 = pcVar18;
            } while (cVar1 != '\0');
            pcVar17 = pcVar15 + -uVar6;
            pcVar15 = pcVar18 + -1;
            for (uVar10 = uVar6 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
              *(undefined4 *)pcVar15 = *(undefined4 *)pcVar17;
              pcVar17 = pcVar17 + 4;
              pcVar15 = pcVar15 + 4;
            }
            for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
              *pcVar15 = *pcVar17;
              pcVar17 = pcVar17 + 1;
              pcVar15 = pcVar15 + 1;
            }
          }
          else {
            uVar6 = 0xffffffff;
            pcVar17 = (&PTR_DAT_1c40ebe8)[iVar13];
            do {
              pcVar15 = pcVar17;
              if (uVar6 == 0) break;
              uVar6 = uVar6 - 1;
              pcVar15 = pcVar17 + 1;
              cVar1 = *pcVar17;
              pcVar17 = pcVar15;
            } while (cVar1 != '\0');
            uVar6 = ~uVar6;
            iVar13 = -1;
            pcVar17 = param_3;
            do {
              pcVar18 = pcVar17;
              if (iVar13 == 0) break;
              iVar13 = iVar13 + -1;
              pcVar18 = pcVar17 + 1;
              cVar1 = *pcVar17;
              pcVar17 = pcVar18;
            } while (cVar1 != '\0');
            pcVar17 = pcVar15 + -uVar6;
            pcVar15 = pcVar18 + -1;
            for (uVar10 = uVar6 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
              *(undefined4 *)pcVar15 = *(undefined4 *)pcVar17;
              pcVar17 = pcVar17 + 4;
              pcVar15 = pcVar15 + 4;
            }
            for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
              *pcVar15 = *pcVar17;
              pcVar17 = pcVar17 + 1;
              pcVar15 = pcVar15 + 1;
            }
            if (iVar9 != 0) {
              pcVar17 = (&PTR_DAT_1c40eb98)[iVar9];
              goto LAB_1c407aa5;
            }
          }
          if (iVar11 == 1) {
            pcVar17 = &DAT_1c40e4b8;
          }
          else {
            pcVar17 = s_SEHNTAA5VOHS_1c40e4a8;
          }
          uVar6 = 0xffffffff;
          do {
            pcVar15 = pcVar17;
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            pcVar15 = pcVar17 + 1;
            cVar1 = *pcVar17;
            pcVar17 = pcVar15;
          } while (cVar1 != '\0');
          uVar6 = ~uVar6;
          iVar11 = -1;
          pcVar17 = param_3;
          do {
            pcVar18 = pcVar17;
            if (iVar11 == 0) break;
            iVar11 = iVar11 + -1;
            pcVar18 = pcVar17 + 1;
            cVar1 = *pcVar17;
            pcVar17 = pcVar18;
          } while (cVar1 != '\0');
          pcVar17 = pcVar15 + -uVar6;
          pcVar15 = pcVar18 + -1;
          for (uVar10 = uVar6 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined4 *)pcVar15 = *(undefined4 *)pcVar17;
            pcVar17 = pcVar17 + 4;
            pcVar15 = pcVar15 + 4;
          }
          for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
            *pcVar15 = *pcVar17;
            pcVar17 = pcVar17 + 1;
            pcVar15 = pcVar15 + 1;
          }
        }
      }
    }
    if ((!bVar19) || (!bVar2)) goto LAB_1c407b22;
  }
  else {
LAB_1c407b22:
    if (local_2c != 0) {
      uVar6 = 0xffffffff;
      pcVar17 = &DAT_1c40e4a4;
      do {
        pcVar15 = pcVar17;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar15 = pcVar17 + 1;
        cVar1 = *pcVar17;
        pcVar17 = pcVar15;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar11 = -1;
      pcVar17 = param_3;
      do {
        pcVar18 = pcVar17;
        if (iVar11 == 0) break;
        iVar11 = iVar11 + -1;
        pcVar18 = pcVar17 + 1;
        cVar1 = *pcVar17;
        pcVar17 = pcVar18;
      } while (cVar1 != '\0');
      pcVar17 = pcVar15 + -uVar6;
      pcVar15 = pcVar18 + -1;
      for (uVar10 = uVar6 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
        *(undefined4 *)pcVar15 = *(undefined4 *)pcVar17;
        pcVar17 = pcVar17 + 4;
        pcVar15 = pcVar15 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar15 = *pcVar17;
        pcVar17 = pcVar17 + 1;
        pcVar15 = pcVar15 + 1;
      }
      while (local_2c != 0) {
        local_2c = local_2c + -1;
        uVar6 = 0xffffffff;
        pcVar17 = *(char **)(&DAT_1c40ead8 + *param_1 * 4);
        do {
          pcVar15 = pcVar17;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar15 = pcVar17 + 1;
          cVar1 = *pcVar17;
          pcVar17 = pcVar15;
        } while (cVar1 != '\0');
        uVar6 = ~uVar6;
        iVar11 = -1;
        pcVar17 = param_3;
        do {
          pcVar18 = pcVar17;
          if (iVar11 == 0) break;
          iVar11 = iVar11 + -1;
          pcVar18 = pcVar17 + 1;
          cVar1 = *pcVar17;
          pcVar17 = pcVar18;
        } while (cVar1 != '\0');
        pcVar17 = pcVar15 + -uVar6;
        pcVar15 = pcVar18 + -1;
        for (uVar10 = uVar6 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
          *(undefined4 *)pcVar15 = *(undefined4 *)pcVar17;
          pcVar17 = pcVar17 + 4;
          pcVar15 = pcVar15 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar15 = *pcVar17;
          pcVar17 = pcVar17 + 1;
          pcVar15 = pcVar15 + 1;
        }
        param_1 = param_1 + 1;
      }
      uVar6 = 0xffffffff;
      pcVar17 = &DAT_1c40e494;
      do {
        pcVar15 = pcVar17;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar15 = pcVar17 + 1;
        cVar1 = *pcVar17;
        pcVar17 = pcVar15;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar11 = -1;
      pcVar17 = param_3;
      do {
        pcVar18 = pcVar17;
        if (iVar11 == 0) break;
        iVar11 = iVar11 + -1;
        pcVar18 = pcVar17 + 1;
        cVar1 = *pcVar17;
        pcVar17 = pcVar18;
      } while (cVar1 != '\0');
      pcVar17 = pcVar15 + -uVar6;
      pcVar15 = pcVar18 + -1;
      for (uVar10 = uVar6 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
        *(undefined4 *)pcVar15 = *(undefined4 *)pcVar17;
        pcVar17 = pcVar17 + 4;
        pcVar15 = pcVar15 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar15 = *pcVar17;
        pcVar17 = pcVar17 + 1;
        pcVar15 = pcVar15 + 1;
      }
    }
  }
  uVar12 = 1;
  if (iVar14 == 0) goto LAB_1c407c69;
  iVar11 = toupper((uint)*param_2);
  switch(iVar11) {
  case 0x42:
    pcVar17 = s_MIY3L_MIYYOH5N_1c40e478;
    break;
  default:
    goto switchD_1c407c16_caseD_43;
  case 0x4d:
    pcVar17 = s_MIYYOH5N_1c40e488;
    break;
  case 0x51:
    pcVar17 = s_KWAADRIYYOH5N_1c40e45c;
    break;
  case 0x54:
    pcVar17 = &DAT_1c40e46c;
  }
  uVar6 = 0xffffffff;
  do {
    pcVar15 = pcVar17;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar15 = pcVar17 + 1;
    cVar1 = *pcVar17;
    pcVar17 = pcVar15;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  iVar11 = -1;
  pcVar17 = param_3;
  do {
    pcVar18 = pcVar17;
    if (iVar11 == 0) break;
    iVar11 = iVar11 + -1;
    pcVar18 = pcVar17 + 1;
    cVar1 = *pcVar17;
    pcVar17 = pcVar18;
  } while (cVar1 != '\0');
  pcVar17 = pcVar15 + -uVar6;
  pcVar15 = pcVar18 + -1;
  for (uVar10 = uVar6 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
    *(undefined4 *)pcVar15 = *(undefined4 *)pcVar17;
    pcVar17 = pcVar17 + 4;
    pcVar15 = pcVar15 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar15 = *pcVar17;
    pcVar17 = pcVar17 + 1;
    pcVar15 = pcVar15 + 1;
  }
switchD_1c407c16_caseD_43:
  uVar12 = 2;
LAB_1c407c69:
  if ((bVar19) && ((iVar14 != 0 || (!bVar2)))) {
    uVar6 = 0xffffffff;
    pcVar17 = &DAT_1c40e4c8;
    do {
      pcVar15 = pcVar17;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar15 = pcVar17 + 1;
      cVar1 = *pcVar17;
      pcVar17 = pcVar15;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar11 = -1;
    pcVar17 = param_3;
    do {
      pcVar18 = pcVar17;
      if (iVar11 == 0) break;
      iVar11 = iVar11 + -1;
      pcVar18 = pcVar17 + 1;
      cVar1 = *pcVar17;
      pcVar17 = pcVar18;
    } while (cVar1 != '\0');
    pcVar17 = pcVar15 + -uVar6;
    pcVar15 = pcVar18 + -1;
    for (uVar10 = uVar6 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined4 *)pcVar15 = *(undefined4 *)pcVar17;
      pcVar17 = pcVar17 + 4;
      pcVar15 = pcVar15 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar15 = *pcVar17;
      pcVar17 = pcVar17 + 1;
      pcVar15 = pcVar15 + 1;
    }
  }
  if ((iVar14 != 0) && (pcVar17 = strchr((char *)param_2,0x29), pcVar17 != (char *)0x0)) {
    uVar6 = 0xffffffff;
    pcVar17 = (char *)&DAT_1c40e4e4;
    do {
      pcVar15 = pcVar17;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar15 = pcVar17 + 1;
      cVar1 = *pcVar17;
      pcVar17 = pcVar15;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar14 = -1;
    pcVar17 = param_3;
    do {
      pcVar18 = pcVar17;
      if (iVar14 == 0) break;
      iVar14 = iVar14 + -1;
      pcVar18 = pcVar17 + 1;
      cVar1 = *pcVar17;
      pcVar17 = pcVar18;
    } while (cVar1 != '\0');
    pcVar17 = pcVar15 + -uVar6;
    pcVar15 = pcVar18 + -1;
    for (uVar10 = uVar6 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined4 *)pcVar15 = *(undefined4 *)pcVar17;
      pcVar17 = pcVar17 + 4;
      pcVar15 = pcVar15 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar15 = *pcVar17;
      pcVar17 = pcVar17 + 1;
      pcVar15 = pcVar15 + 1;
    }
  }
  if (bVar20) {
    uVar6 = 0xffffffff;
    pcVar17 = s_IYEHAAEYAYOYOHUWPOHR_SIYEH5NTOH_1c40e438 + 0x10;
    do {
      pcVar15 = pcVar17;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar15 = pcVar17 + 1;
      cVar1 = *pcVar17;
      pcVar17 = pcVar15;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar14 = -1;
    do {
      pcVar17 = param_3;
      if (iVar14 == 0) break;
      iVar14 = iVar14 + -1;
      pcVar17 = param_3 + 1;
      cVar1 = *param_3;
      param_3 = pcVar17;
    } while (cVar1 != '\0');
    pcVar15 = pcVar15 + -uVar6;
    pcVar17 = pcVar17 + -1;
    for (uVar10 = uVar6 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined4 *)pcVar17 = *(undefined4 *)pcVar15;
      pcVar15 = pcVar15 + 4;
      pcVar17 = pcVar17 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar17 = *pcVar15;
      pcVar15 = pcVar15 + 1;
      pcVar17 = pcVar17 + 1;
    }
    *pcVar16 = '%';
  }
  return uVar12;
}


// ==== FUN_1c407da0 @ 1c407da0 size=119

bool __cdecl FUN_1c407da0(char *param_1)

{
  int iVar1;
  
  if (param_1 == (char *)0x0) {
    return false;
  }
  iVar1 = strncmp(param_1,s_MILLON_1c40e568,6);
  if (iVar1 == 0) {
    return true;
  }
  iVar1 = strncmp(param_1,s_BILLON_1c40e560,6);
  if (iVar1 == 0) {
    return true;
  }
  iVar1 = strncmp(param_1,s_TRILLON_1c40e558,7);
  if (iVar1 == 0) {
    return true;
  }
  iVar1 = strncmp(param_1,s_QUADRILLON_1c40e54c,10);
  return iVar1 == 0;
}


// ==== FUN_1c407e20 @ 1c407e20 size=1703

undefined4 __cdecl FUN_1c407e20(int *param_1)

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
  
  DAT_1c411d78 = (byte *)param_1[2];
  if (*DAT_1c411d78 == 0) {
    return 0;
  }
  piVar9 = (int *)__p___mb_cur_max();
  if (*piVar9 < 2) {
    uVar12 = (uint)*DAT_1c411d78;
    piVar9 = (int *)__p__pctype();
    uVar10 = *(ushort *)(*piVar9 + uVar12 * 2) & 4;
  }
  else {
    uVar12 = (uint)*DAT_1c411d78;
    uVar10 = _isctype(uVar12,4);
  }
  if (uVar10 == 0) {
    uVar10 = (uint)DAT_1c411d78[1];
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
  DAT_1c411d80 = 0;
  sVar11 = strspn((char *)DAT_1c411d78,s_0123456789___________1c40e728);
  DAT_1c411d6c = DAT_1c411d78 + sVar11;
  bVar3 = DAT_1c411d6c[-1];
  if ((bVar3 == 0x2c) || (bVar3 == 0x2e)) {
    DAT_1c411d6c = DAT_1c411d6c + -1;
  }
  bVar3 = *DAT_1c411d6c;
  DAT_1c411d74 = DAT_1c411d6c;
  if (bVar3 != 0) {
    *DAT_1c411d6c = 0;
    DAT_1c411d6c = DAT_1c411d6c + 1;
    bVar4 = *DAT_1c411d6c;
    while (bVar4 == 0x20) {
      DAT_1c411d6c = DAT_1c411d6c + 1;
      bVar4 = *DAT_1c411d6c;
    }
  }
  DAT_1c411d70 = (byte *)strchr((char *)DAT_1c411d6c,0x20);
  if (DAT_1c411d70 == (byte *)0x0) {
    uVar10 = 0xffffffff;
    pbVar17 = DAT_1c411d6c;
    do {
      if (uVar10 == 0) break;
      uVar10 = uVar10 - 1;
      bVar4 = *pbVar17;
      pbVar17 = pbVar17 + 1;
    } while (bVar4 != 0);
    DAT_1c411d70 = DAT_1c411d6c + (~uVar10 - 1);
  }
  if ((DAT_1c411d70[-1] == 0x2c) || (DAT_1c411d70[-1] == 0x2e)) {
    DAT_1c411d70 = DAT_1c411d70 + -1;
  }
  bVar4 = *DAT_1c411d70;
  *DAT_1c411d70 = 0;
  uVar10 = 0xffffffff;
  pbVar17 = DAT_1c411d78;
  do {
    if (uVar10 == 0) break;
    uVar10 = uVar10 - 1;
    bVar1 = *pbVar17;
    pbVar17 = pbVar17 + 1;
  } while (bVar1 != 0);
  iStack_4 = ~uVar10 - 1;
  bVar7 = true;
  pbVar17 = DAT_1c411d78;
  if (0x13 < iStack_4) {
    iStack_4 = 0x14;
  }
joined_r0x1c40808e:
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
      pcVar18 = &DAT_1c40e724;
      goto LAB_1c408262;
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
      pcVar18 = &DAT_1c40e720;
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
      pcVar18 = &DAT_1c411d80;
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
      goto joined_r0x1c40808e;
    }
    switch(uVar10) {
    case 0x24:
      uVar10 = 0xffffffff;
      pcVar18 = (char *)&DAT_1c40e70c;
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
      pcVar18 = &DAT_1c411d80;
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
      goto joined_r0x1c40808e;
    case 0x25:
      uVar10 = 0xffffffff;
      pcVar18 = (char *)&DAT_1c40e708;
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
      pcVar18 = &DAT_1c411d80;
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
      goto joined_r0x1c40808e;
    default:
      pcVar18 = &DAT_1c40e724;
      break;
    case 0x28:
      pcVar18 = &DAT_1c40e71c;
      break;
    case 0x29:
      pcVar18 = &DAT_1c40e718;
      break;
    case 0x2c:
      uVar10 = 0xffffffff;
      pcVar18 = (char *)&DAT_1c40e710;
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
      pcVar18 = &DAT_1c411d80;
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
      goto joined_r0x1c40808e;
    case 0x2d:
      pcVar18 = &DAT_1c40e714;
      break;
    case 0x2e:
      goto switchD_1c408153_caseD_2e;
    case 0x2f:
      pcVar18 = &DAT_1c40e704;
      break;
    case 0x3a:
      pcVar18 = &DAT_1c40e700;
    }
LAB_1c408262:
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
    pcVar18 = &DAT_1c411d80;
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
    goto joined_r0x1c40808e;
  }
  iVar14 = 0;
  uVar10 = 0xffffffff;
  DAT_1c4109e0 = 0;
  pcVar18 = &DAT_1c40e4f4;
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
  pcVar18 = &DAT_1c4109e0;
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
  ppuVar8 = &PTR_s________________1c40e628;
  puVar5 = PTR_LAB_1c40e630;
  while (puVar5 != (undefined *)0x0) {
    pbVar17 = *ppuVar8;
    pbVar19 = &DAT_1c411d80;
    do {
      bVar1 = *pbVar17;
      bVar22 = bVar1 < *pbVar19;
      if (bVar1 != *pbVar19) {
LAB_1c408317:
        iVar15 = (1 - (uint)bVar22) - (uint)(bVar22 != 0);
        goto LAB_1c40831c;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar17[1];
      bVar22 = bVar1 < pbVar19[1];
      if (bVar1 != pbVar19[1]) goto LAB_1c408317;
      pbVar17 = pbVar17 + 2;
      pbVar19 = pbVar19 + 2;
    } while (bVar1 != 0);
    iVar15 = 0;
LAB_1c40831c:
    if (iVar15 == 0) {
      iVar14 = (*(code *)ppuVar8[2])(DAT_1c411d78,DAT_1c411d6c,&DAT_1c4109e0);
      break;
    }
    puVar5 = ppuVar8[5];
    ppuVar8 = ppuVar8 + 3;
  }
  if ((iVar14 != 0) ||
     (((bVar7 && (iVar14 = FUN_1c4073d0((char *)DAT_1c411d78,DAT_1c411d6c,&DAT_1c4109e0),
                 iVar14 != 0)) ||
      (iVar14 = FUN_1c409400(DAT_1c411d78,&DAT_1c411d6c,&DAT_1c4109e0), iVar14 != 0)))) {
    uVar10 = 0xffffffff;
    pcVar18 = &DAT_1c4109e0;
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
      pcVar18 = &DAT_1c4109e0;
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
  *DAT_1c411d74 = bVar3;
  *DAT_1c411d70 = bVar4;
  switch(iVar14) {
  case 0:
    return 0;
  case 1:
    *param_1 = (int)(DAT_1c411d74 + (*param_1 - param_1[2]));
    pbVar17 = DAT_1c411d74;
    param_1[7] = 4;
    param_1[2] = (int)pbVar17;
    return 0;
  case 2:
    *param_1 = (int)(DAT_1c411d70 + (*param_1 - param_1[2]));
    pbVar17 = DAT_1c411d70;
    param_1[7] = 4;
    param_1[2] = (int)pbVar17;
    return 0;
  case 3:
    *param_1 = (int)(DAT_1c411d6c + (*param_1 - param_1[2]));
    pbVar17 = DAT_1c411d6c;
    param_1[7] = 4;
    param_1[2] = (int)pbVar17;
    return 0;
  case -1:
    return 1;
  default:
    *param_1 = (int)(DAT_1c411d74 + (*param_1 - param_1[2]));
    param_1[2] = (int)DAT_1c411d74;
    return 0;
  }
switchD_1c408153_caseD_2e:
  uVar10 = 0xffffffff;
  pcVar18 = (char *)&DAT_1c40e548;
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
  pcVar18 = &DAT_1c411d80;
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
  goto joined_r0x1c40808e;
}


// ==== FUN_1c408520 @ 1c408520 size=553

undefined4 __cdecl FUN_1c408520(char *param_1,undefined4 param_2,char *param_3)

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
  pcVar8 = (&PTR_DAT_1c40eb98)[iVar4];
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
    pcVar8 = &DAT_1c40e4f4;
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
      pcVar8 = (char *)&DAT_1c40e740;
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
      pcVar8 = (&PTR_DAT_1c40eb98)[iVar7];
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
      pcVar8 = (&PTR_DAT_1c40eb98)[iVar2];
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
    pcVar8 = (&PTR_DAT_1c40ec10)[iVar6];
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
      pcVar8 = (&PTR_DAT_1c40eb98)[iVar7];
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


// ==== FUN_1c408cc0 @ 1c408cc0 size=302

undefined4 __cdecl FUN_1c408cc0(char *param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  uVar2 = 0xffffffff;
  pcVar5 = *(char **)(&DAT_1c40ead8 + *param_1 * 4);
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
  pcVar5 = *(char **)(&DAT_1c40ead8 + param_1[1] * 4);
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
  pcVar5 = *(char **)(&DAT_1c40ead8 + param_1[2] * 4);
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
  pcVar5 = (char *)&DAT_1c40e4e4;
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
  pcVar5 = *(char **)(&DAT_1c40ead8 + param_1[4] * 4);
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
  FUN_1c408f60(param_1 + 5,param_2,param_3);
  return 1;
}


// ==== FUN_1c408ec0 @ 1c408ec0 size=151

undefined4 __cdecl FUN_1c408ec0(char *param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  uVar2 = 0xffffffff;
  pcVar5 = &DAT_1c40e4f4;
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
  FUN_1c408f60(param_1,param_2,param_3);
  uVar2 = 0xffffffff;
  pcVar5 = (char *)&DAT_1c40e710;
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
  FUN_1c408cc0(param_1 + 4,param_2,param_3);
  return 1;
}


// ==== FUN_1c408f60 @ 1c408f60 size=396

undefined4 __cdecl FUN_1c408f60(char *param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  
  cVar2 = param_1[1];
  cVar3 = param_1[2];
  iVar4 = *param_1 + -0x30;
  if (((iVar4 == 0) || (cVar2 + -0x30 != 0)) || (cVar3 + -0x30 != 0)) {
    uVar5 = 0xffffffff;
    pcVar7 = (&PTR_DAT_1c40eb98)[iVar4];
    do {
      pcVar8 = pcVar7;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar8 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    iVar4 = -1;
    pcVar7 = param_3;
    do {
      pcVar9 = pcVar7;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar9 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar9;
    } while (cVar1 != '\0');
    pcVar7 = pcVar8 + -uVar5;
    pcVar8 = pcVar9 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar8 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
    }
    uVar5 = 0xffffffff;
    pcVar7 = (&PTR_DAT_1c40eb98)[cVar2 + -0x30];
    do {
      pcVar8 = pcVar7;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar8 = pcVar7 + 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar2 != '\0');
    uVar5 = ~uVar5;
    iVar4 = -1;
    pcVar7 = param_3;
    do {
      pcVar9 = pcVar7;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar9 = pcVar7 + 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar9;
    } while (cVar2 != '\0');
    pcVar7 = pcVar8 + -uVar5;
    pcVar8 = pcVar9 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar8 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
    }
    uVar5 = 0xffffffff;
    pcVar7 = (&PTR_DAT_1c40eb98)[cVar3 + -0x30];
    do {
      pcVar8 = pcVar7;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar8 = pcVar7 + 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar2 != '\0');
    uVar5 = ~uVar5;
    iVar4 = -1;
    do {
      pcVar7 = param_3;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar7 = param_3 + 1;
      cVar2 = *param_3;
      param_3 = pcVar7;
    } while (cVar2 != '\0');
    pcVar8 = pcVar8 + -uVar5;
    pcVar7 = pcVar7 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar7 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar7 = pcVar7 + 1;
    }
    return 1;
  }
  if (iVar4 != 1) {
    uVar5 = 0xffffffff;
    pcVar7 = (&PTR_DAT_1c40eb98)[iVar4];
    do {
      pcVar8 = pcVar7;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar8 = pcVar7 + 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar2 != '\0');
    uVar5 = ~uVar5;
    iVar4 = -1;
    pcVar7 = param_3;
    do {
      pcVar9 = pcVar7;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar9 = pcVar7 + 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar9;
    } while (cVar2 != '\0');
    pcVar7 = pcVar8 + -uVar5;
    pcVar8 = pcVar9 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar8 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
    }
    uVar5 = 0xffffffff;
    pcVar7 = &DAT_1c40e774;
    do {
      pcVar8 = pcVar7;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar8 = pcVar7 + 1;
      cVar2 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar2 != '\0');
    uVar5 = ~uVar5;
    iVar4 = -1;
    do {
      pcVar7 = param_3;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar7 = param_3 + 1;
      cVar2 = *param_3;
      param_3 = pcVar7;
    } while (cVar2 != '\0');
    pcVar8 = pcVar8 + -uVar5;
    pcVar7 = pcVar7 + -1;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar7 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar7 = pcVar7 + 1;
    }
    return 1;
  }
  uVar5 = 0xffffffff;
  pcVar7 = &DAT_1c40e784;
  do {
    pcVar8 = pcVar7;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = pcVar7 + 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar2 != '\0');
  uVar5 = ~uVar5;
  iVar4 = -1;
  do {
    pcVar7 = param_3;
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    pcVar7 = param_3 + 1;
    cVar2 = *param_3;
    param_3 = pcVar7;
  } while (cVar2 != '\0');
  pcVar8 = pcVar8 + -uVar5;
  pcVar7 = pcVar7 + -1;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar7 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar7 = pcVar7 + 1;
  }
  return 1;
}


// ==== FUN_1c409400 @ 1c409400 size=479

int __cdecl FUN_1c409400(byte *param_1,undefined4 *param_2,char *param_3)

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
    *(undefined1 *)(uVar5 + 0x1c411d7e) = 0;
  }
  if (*param_1 == 0x28) {
    param_1 = param_1 + 1;
    iVar8 = 0;
    if (0 < iVar6) {
      do {
        iVar3 = iVar8 + 1;
        (&DAT_1c411d80)[iVar8] = (&DAT_1c411d81)[iVar8];
        iVar8 = iVar3;
      } while (iVar3 < iVar6);
    }
    uVar7 = 0xffffffff;
    pcVar12 = (char *)&DAT_1c40e4e4;
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
  iVar8 = FUN_1c4073d0((char *)param_1,(byte *)0x0,param_3);
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
          pcVar12 = &DAT_1c40e4d8;
          break;
        default:
          *param_2 = param_1;
          return 3;
        case 0x2b:
          pcVar12 = s_MAA5S_1c40e7cc;
          break;
        case 0x2c:
          pcVar12 = (char *)&DAT_1c40e768;
          break;
        case 0x2d:
          pcVar12 = s_MEH5NOHS_1c40e7d4;
          break;
        case 0x2e:
          pcVar12 = s_PUW5NTOH_1c40e7ec;
          break;
        case 0x2f:
          pcVar12 = s_KOHRTAA5R_1c40e7e0;
          break;
        case 0x3a:
          pcVar12 = s_DOH3S_PUW5NTOHS_1c40e7b8;
        }
      }
      else {
        pcVar12 = *(char **)(&DAT_1c40ead8 + uVar5 * 4);
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
    pcVar12 = (char *)&DAT_1c40e4e4;
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


// ==== FUN_1c409620 @ 1c409620 size=412

undefined4 __cdecl FUN_1c409620(int param_1,int *param_2)

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
      if ((*(ushort *)(&DAT_1c409aa0 + *local_c * 2) & 0x83) == 2) {
        iVar8 = 1;
        pbVar7 = (byte *)(*(int *)(param_1 + 0x98) + *(int *)(param_1 + 0xa0));
      }
      else if ((*(ushort *)(&DAT_1c409aa0 + *local_c * 2) & 0x83) == 0x80) {
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
          iVar3 = FUN_1c409870(param_2,(char *)pbVar7);
        }
        else if (((&DAT_1c409aa0)[cVar2 * 2] & 0x80) == 0) {
          iVar3 = FUN_1c4097c0(param_2,pbVar7,iVar8);
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


// ==== FUN_1c4097c0 @ 1c4097c0 size=171

int __cdecl FUN_1c4097c0(undefined4 *param_1,byte *param_2,int param_3)

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
    return 3 - (uint)((*(ushort *)(&DAT_1c409aa0 + (uint)*pbVar5 * 2) & 0x80) == 0);
  }
  if (param_3 == 0) {
    iVar1 = toupper((uint)local_1);
    iVar2 = toupper((int)(char)bVar4);
    if (iVar2 < iVar1) {
      return 1;
    }
  }
  return 3;
}


// ==== FUN_1c409870 @ 1c409870 size=16

int __cdecl FUN_1c409870(undefined4 param_1,char *param_2)

{
  return (-(uint)(*param_2 == '\0') & 0xfffffffe) + 3;
}


// ==== FUN_1c409880 @ 1c409880 size=542

undefined4 __cdecl FUN_1c409880(int *param_1)

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
    pcVar10 = (&PTR_DAT_1c40ef58)[iVar7 * 2];
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
          pcVar10 = s_DAA5T_1c40f358;
        }
      }
      else {
        pcVar10 = s_POY5NT_1c40f360;
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
        pcVar10 = &DAT_1c40ee84;
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


// ==== FUN_1c40a9e0 @ 1c40a9e0 size=2346

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_1c40a9e0(int param_1)

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
  
  FUN_1c402c30(0x1c412540);
  FUN_1c402c30(0x1c412580);
  FUN_1c402c30(0x1c412360);
  FUN_1c402c30(0x1c412470);
  DAT_1c41237c = 0;
  uVar3 = DAT_1c416f4c & 0x40;
  if (uVar3 != 0) {
    switch(DAT_1c412460) {
    case 'A':
      DAT_1c412378 = 0x2f;
      break;
    case 'B':
      DAT_1c412378 = 0x3d;
      break;
    case 'C':
      DAT_1c412378 = 0x37;
      break;
    case 'D':
      DAT_1c412378 = 0x31;
      break;
    case 'E':
      DAT_1c412378 = 0x2e;
      break;
    case 'F':
      DAT_1c412378 = 0x3c;
      break;
    case 'G':
      DAT_1c412378 = 0x38;
      break;
    case 'H':
      DAT_1c412378 = 0x35;
      break;
    default:
      DAT_1c412378 = 0;
    }
    if (((DAT_1c412ac0 & 0x10000) != 0) && ((DAT_1c416f4c & 0x80) == 0)) {
      DAT_1c412378 = DAT_1c412378 + 3;
    }
    iVar4 = DAT_1c412378;
    if ((DAT_1c416f50 == '\0') && (DAT_1c412378 = DAT_1c412378 + -2, (DAT_1c416f4c & 2) != 0)) {
      DAT_1c412378 = iVar4 + -4;
    }
    DAT_1c41237c = DAT_1c412378;
  }
  bVar2 = false;
  _DAT_1c412398 = 0;
  _DAT_1c41239c = 0x4b;
  DAT_1c412488 = -10;
  DAT_1c412558 = 3000;
  DAT_1c412598 = 400;
  pbVar1 = &DAT_1c40604e + DAT_1c41237c;
  DAT_1c412378 = (uint)*pbVar1;
  DAT_1c41237c = (uint)(byte)(&DAT_1c40604e)[DAT_1c41237c];
  if ((DAT_1c416f4c & 0x40040) != 0) {
    if ((DAT_1c412604 == 0x29) || (DAT_1c412604 == 0x38)) {
      bVar2 = true;
    }
    if ((DAT_1c416f4c & 2) == 0) {
      if ((DAT_1c416f4c & 0x10000) == 0) {
        if ((DAT_1c416f4c & 0x4000000) == 0) {
          if ((DAT_1c416f4c & 8) == 0) {
            sVar8 = (short)local_4;
            sVar6 = (short)local_4;
            if ((DAT_1c416f4c & 0x400) != 0) {
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
        else if ((DAT_1c412aac & 0x800000) == 0) {
          local_4._0_2_ = 0xdc;
          sVar8 = -0x12;
          sVar6 = 0x834;
        }
        else {
          iVar4 = (uint)DAT_1c412604 * 0x1a + *(int *)(param_1 + 4);
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
    else if (((DAT_1c416f4c & 0x40000) == 0) || ((DAT_1c412604 != 0x36 && (DAT_1c412604 != 0x6c))))
    {
      local_4._0_2_ = 500;
      sVar8 = -0x12;
      sVar6 = 4000;
    }
    else {
      local_4._0_2_ = 0x1c2;
      sVar8 = -0x12;
      sVar6 = 0xdac;
    }
    DAT_1c412558 = (int)sVar6;
    _DAT_1c41259c = (int)(short)local_4;
    DAT_1c412488 = (int)sVar8;
    _DAT_1c41255c = DAT_1c412558;
    if ((DAT_1c416f4c & 2) != 0) {
      if (bVar2) {
        _DAT_1c41255c = DAT_1c412558 + -300;
      }
      if ((DAT_1c412ac0 & 0x200000) != 0) {
        DAT_1c412558 = DAT_1c412558 + -300;
      }
    }
    _DAT_1c41248c = DAT_1c412488;
    DAT_1c412598 = _DAT_1c41259c;
    if ((DAT_1c416f4c & 0x10000) != 0) {
      if ((DAT_1c412ac0 & 0x10002000) != 0) {
        DAT_1c412558 = (DAT_1c4123ec + DAT_1c4123ac >> 1) + 100;
        DAT_1c412598 = DAT_1c412558 / 6;
      }
      if ((DAT_1c412aac & 0x10002000) != 0) {
        iVar4 = (uint)DAT_1c412604 * 0x1a + *(int *)(param_1 + 4);
        _DAT_1c41255c = ((int)*(short *)(iVar4 + 8) + (int)*(short *)(iVar4 + 10) >> 1) + 100;
        _DAT_1c41259c = _DAT_1c41255c / 6;
      }
    }
  }
  if ((uVar3 == 0) && ((DAT_1c412ac0 & 0x40) != 0)) {
    DAT_1c412558 = DAT_1c41254c;
    DAT_1c412598 = DAT_1c41258c;
    DAT_1c412488 = DAT_1c41247c;
  }
  if (((DAT_1c412ac0 & 0x40) == 0) && ((DAT_1c412ac0 & 0x40000) == 0)) {
    if ((DAT_1c412ab4 & 0x40) != 0) {
      _DAT_1c412548 = DAT_1c412554;
      _DAT_1c412588 = DAT_1c412594;
      _DAT_1c412478 = DAT_1c412484;
    }
    if (uVar3 != 0) {
      DAT_1c41254c = DAT_1c412558;
      DAT_1c41258c = DAT_1c412598;
      DAT_1c41247c = DAT_1c412488;
    }
  }
  uVar7 = DAT_1c412ac0 & 0x4000000;
  if ((uVar7 != 0) && ((DAT_1c416f4c & 0x10002000) != 0)) {
    DAT_1c41254c = DAT_1c4123c4 + 0x82;
  }
  iVar4 = ((uint)DAT_1c412acc + (uint)DAT_1c4121b4 * 10) * 10;
  DAT_1c412388 = (uint)(byte)(&DAT_1c40df5a)[iVar4];
  DAT_1c412568 = 0x32;
  DAT_1c4125a8 = 0x32;
  DAT_1c412498 = 0x32;
  local_4 = (uint)(byte)(&DAT_1c40df5d)[((uint)DAT_1c4121b4 + (uint)DAT_1c412240 * 10) * 10];
  _DAT_1c41238c = local_4;
  _DAT_1c412390 = (uint)(byte)(&DAT_1c40df60)[iVar4];
  if ((DAT_1c412ab4 & 0x40) == 0) {
    _DAT_1c4125ac = 5;
  }
  else {
    _DAT_1c4125ac = 2;
  }
  if (uVar3 == 0) {
    _DAT_1c4125b0 = 5;
  }
  else {
    _DAT_1c4125b0 = 2;
  }
  uVar3 = DAT_1c412ac0 & 0x40000;
  if (uVar3 != 0) {
    DAT_1c412498 = 0;
    DAT_1c4125a8 = 0;
    DAT_1c412568 = 0;
    _DAT_1c4125b0 = 0;
  }
  if (((DAT_1c412ac0 & 0x40) != 0) && ((DAT_1c412ab4 & 0x40000) != 0)) {
    _DAT_1c4125ac = 0;
  }
  _DAT_1c412384 =
       DAT_1c41236c +
       (int)(((uint)*pbVar1 - DAT_1c41236c) * (uint)(byte)(&DAT_1c40df5a)[iVar4]) / 100;
  _DAT_1c412564 = DAT_1c41254c + ((DAT_1c412558 - DAT_1c41254c) * DAT_1c412568) / 100;
  _DAT_1c4125a4 = DAT_1c41258c + ((DAT_1c412598 - DAT_1c41258c) * DAT_1c4125a8) / 100;
  DAT_1c4121dc = 0;
  _DAT_1c412494 = DAT_1c41247c + ((DAT_1c412488 - DAT_1c41247c) * DAT_1c412498) / 100;
  DAT_1c4121ac = 0;
  uVar5 = DAT_1c412ac0 & 1;
  if ((uVar5 != 0) ||
     ((uVar3 != 0 && (((DAT_1c416f4c & 0x20000000) == 0 || ((DAT_1c416f4c & 0x8000) != 0)))))) {
    sVar8 = 0;
    do {
      if ((&DAT_1c40def8)[sVar8 * 2] == DAT_1c412ace) break;
      sVar8 = sVar8 + 1;
    } while (sVar8 < 0xf);
    DAT_1c4121dc = (ushort)*(byte *)(sVar8 * 2 + 0x1c40def9);
    if (((DAT_1c416f53 != 'A') && (DAT_1c412ace == 'R')) &&
       ((DAT_1c412460 == 'l' || (DAT_1c412460 == '6')))) {
      DAT_1c4121dc = DAT_1c4121dc + 3;
    }
    if (((uVar5 != 0) && (DAT_1c412ac4 != '\0')) && (DAT_1c412460 != 'l')) {
      DAT_1c4121dc = DAT_1c4121dc + 2;
    }
    if ((DAT_1c416f53 == 'A') && ((DAT_1c416f40 & 0x80) != 0)) {
      DAT_1c4121dc = 2;
    }
    if ((short)DAT_1c4121b6 <= (short)DAT_1c4121dc) {
      DAT_1c4121dc = DAT_1c4121b6;
    }
    if (uVar3 != 0) {
      switch(DAT_1c412ace) {
      case 'I':
        DAT_1c4121ac = 0x3b;
        break;
      case 'J':
        DAT_1c4121ac = 0x3e;
        break;
      default:
        DAT_1c4121ac = 0;
        break;
      case 'M':
        DAT_1c4121ac = 0;
        break;
      case 'N':
        DAT_1c4121ac = 0;
        break;
      case 'O':
        DAT_1c4121ac = 0;
        break;
      case 'Q':
        DAT_1c4121ac = 0x32;
        break;
      case 'R':
        DAT_1c4121ac = 0x25;
        if ((DAT_1c416f53 != 'A') && (DAT_1c412460 == 'l')) {
          DAT_1c4121ac = 0x2b;
        }
        break;
      case 'T':
        DAT_1c4121ac = 0x3a;
      }
    }
    uVar3 = DAT_1c412ac0 & 0x10000;
    if ((uVar3 != 0) && ((DAT_1c416f4c & 0x80) == 0)) {
      DAT_1c4121ac = DAT_1c4121ac + 4;
    }
    if (((DAT_1c412ab4 & 0x8000) == 0) || (DAT_1c412ac4 != '\0')) {
      if (((DAT_1c412ab4 & 0x8000) == 0) && (DAT_1c412ac4 == '\0')) {
        DAT_1c4121ac = DAT_1c4121ac + -3;
      }
    }
    else {
      DAT_1c4121ac = DAT_1c4121ac + -6;
    }
    if ((DAT_1c416f4c & 0x40040) != 0) {
      DAT_1c4121ac = DAT_1c4121ac + -3;
    }
    if ((DAT_1c416f53 == 'A') && ((DAT_1c416f40 & 0x80) != 0)) {
      DAT_1c4121ac = DAT_1c4121ac + -3;
    }
    if (uVar5 == 0) {
      if (DAT_1c412460 == '@') {
        DAT_1c4121ac = 0;
      }
      if ((DAT_1c416f4c & 1) == 0) {
        if ((DAT_1c416f4c & 0x40000) == 0) {
          if ((DAT_1c412460 == '@') && ((DAT_1c412aac & 0x40000) != 0)) {
            if (((DAT_1c412ac0 & 0x400) != 0) && ((DAT_1c412aac & 0x400) != 0)) {
              DAT_1c4121ac = 0;
              _DAT_1c41249c = _DAT_1c4125ac;
              _DAT_1c4124a0 = _DAT_1c4125b0;
              _DAT_1c41256c = _DAT_1c4125ac;
              _DAT_1c412570 = _DAT_1c4125b0;
              return;
            }
            if (((DAT_1c412ac0 & 2) != 0) && ((DAT_1c412aac & 2) != 0)) {
              DAT_1c4121ac = 0;
              _DAT_1c41249c = _DAT_1c4125ac;
              _DAT_1c4124a0 = _DAT_1c4125b0;
              _DAT_1c41256c = _DAT_1c4125ac;
              _DAT_1c412570 = _DAT_1c4125b0;
              return;
            }
            if ((uVar7 != 0) && ((DAT_1c412aac & 0x4000000) != 0)) {
              DAT_1c4121ac = 0;
              _DAT_1c41249c = _DAT_1c4125ac;
              _DAT_1c4124a0 = _DAT_1c4125b0;
              _DAT_1c41256c = _DAT_1c4125ac;
              _DAT_1c412570 = _DAT_1c4125b0;
              return;
            }
            if ((uVar3 != 0) && ((DAT_1c412aac & 0x10000) != 0)) {
              DAT_1c4121ac = 0;
            }
          }
        }
        else {
          if (((DAT_1c412ac0 & 0x400) != 0) && ((DAT_1c416f4c & 0x400) != 0)) {
            DAT_1c4121ac = 0;
            _DAT_1c41249c = _DAT_1c4125ac;
            _DAT_1c4124a0 = _DAT_1c4125b0;
            _DAT_1c41256c = _DAT_1c4125ac;
            _DAT_1c412570 = _DAT_1c4125b0;
            return;
          }
          if (((DAT_1c412ac0 & 2) != 0) && ((DAT_1c416f4c & 2) != 0)) {
            DAT_1c4121ac = 0;
            _DAT_1c41249c = _DAT_1c4125ac;
            _DAT_1c4124a0 = _DAT_1c4125b0;
            _DAT_1c41256c = _DAT_1c4125ac;
            _DAT_1c412570 = _DAT_1c4125b0;
            return;
          }
          if ((uVar7 != 0) && ((DAT_1c416f4c & 0x4000000) != 0)) {
            DAT_1c4121ac = 0;
            _DAT_1c41249c = _DAT_1c4125ac;
            _DAT_1c4124a0 = _DAT_1c4125b0;
            _DAT_1c41256c = _DAT_1c4125ac;
            _DAT_1c412570 = _DAT_1c4125b0;
            return;
          }
          if ((uVar3 != 0) && ((DAT_1c416f4c & 0x10000) != 0)) {
            DAT_1c4121ac = 0;
            _DAT_1c41249c = _DAT_1c4125ac;
            _DAT_1c4124a0 = _DAT_1c4125b0;
            _DAT_1c41256c = _DAT_1c4125ac;
            _DAT_1c412570 = _DAT_1c4125b0;
            return;
          }
        }
      }
    }
  }
  _DAT_1c41249c = _DAT_1c4125ac;
  _DAT_1c4124a0 = _DAT_1c4125b0;
  _DAT_1c41256c = _DAT_1c4125ac;
  _DAT_1c412570 = _DAT_1c4125b0;
  return;
}


// ==== FUN_1c40b360 @ 1c40b360 size=371

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1c40b360(undefined4 param_1,int param_2)

{
  DWORD DVar1;
  undefined4 *puVar2;
  
  if (param_2 == 1) {
    DAT_1c4109c4 = DAT_1c4109c4 + 1;
  }
  else if (param_2 == 0) {
    if (DAT_1c4109c4 < 1) {
      return 0;
    }
    DAT_1c4109c4 = DAT_1c4109c4 + -1;
  }
  if (DAT_1c4109c8 == 0) {
    DVar1 = GetVersion();
    if (((char)DVar1 == '\x03') && ((DVar1 & 0x80000000) != 0)) {
      DAT_1c4109c8 = DAT_1c4109c8 + 1;
    }
    else {
      DAT_1c4109c8 = DAT_1c4109c8 + -1;
    }
  }
  _DAT_1c417090 = *(undefined4 *)_adjust_fdiv_exref;
  if (param_2 != 1) {
    if ((param_2 == 0) &&
       (((DAT_1c4109c8 < 0 || (DAT_1c4109c4 == 0)) && (DAT_1c417098 != (undefined4 *)0x0)))) {
      puVar2 = DAT_1c417094 + -1;
      if (DAT_1c417098 <= puVar2) {
        do {
          if ((code *)*puVar2 != (code *)0x0) {
            (*(code *)*puVar2)();
          }
          puVar2 = puVar2 + -1;
        } while (DAT_1c417098 <= puVar2);
      }
      if (DAT_1c4109c8 < 0) {
        free(DAT_1c417098);
      }
      else {
        GlobalFree(DAT_1c417098);
      }
      DAT_1c417098 = (undefined4 *)0x0;
    }
    return 1;
  }
  if (-1 < DAT_1c4109c8) {
    if (DAT_1c4109c4 != 1) {
      return 1;
    }
    if (-1 < DAT_1c4109c8) {
      DAT_1c417098 = GlobalAlloc(0x2000,0x80);
      if (DAT_1c417098 == (undefined4 *)0x0) {
        return 0;
      }
      goto LAB_1c40b42d;
    }
  }
  DAT_1c417098 = malloc(0x80);
  if (DAT_1c417098 == (undefined4 *)0x0) {
    return 0;
  }
LAB_1c40b42d:
  *DAT_1c417098 = 0;
  DAT_1c417094 = DAT_1c417098;
  initterm(&DAT_1c40d000,&DAT_1c40d004);
  return 1;
}


// ==== entry @ 1c40b4e0 size=169

int entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if ((param_2 == 0) && (DAT_1c4109c4 == 0)) {
    return 0;
  }
  if ((param_2 == 1) || (param_2 == 2)) {
    if (DAT_1c41709c != (code *)0x0) {
      iVar2 = (*DAT_1c41709c)(param_1,param_2,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_1c40b555;
    iVar2 = FUN_1c40b360(param_1,param_2);
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_1c401000(param_1,param_2);
  }
LAB_1c40b555:
  if ((param_2 == 0) || (param_2 == 3)) {
    iVar2 = FUN_1c40b360(param_1,param_2);
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    if ((iVar1 != 0) && (DAT_1c41709c != (code *)0x0)) {
      iVar1 = (*DAT_1c41709c)(param_1,param_2,param_3);
    }
  }
  return iVar1;
}


