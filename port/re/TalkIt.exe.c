// ==== FUN_00401010 @ 00401010 size=10

void FUN_00401010(void)

{
  Ordinal_340();
  return;
}


// ==== FUN_00401020 @ 00401020 size=14

void FUN_00401020(void)

{
  _atexit((_func_4879 *)&LAB_00401030);
  return;
}


// ==== FUN_00401050 @ 00401050 size=10

void FUN_00401050(void)

{
  Ordinal_486();
  return;
}


// ==== FUN_00401060 @ 00401060 size=14

void FUN_00401060(void)

{
  _atexit(FUN_00401070);
  return;
}


// ==== FUN_00401070 @ 00401070 size=10

void FUN_00401070(void)

{
  Ordinal_706();
  return;
}


// ==== FUN_00401090 @ 00401090 size=10

void FUN_00401090(void)

{
  Ordinal_486();
  return;
}


// ==== FUN_004010a0 @ 004010a0 size=14

void FUN_004010a0(void)

{
  _atexit(FUN_004010b0);
  return;
}


// ==== FUN_004010b0 @ 004010b0 size=10

void FUN_004010b0(void)

{
  Ordinal_706();
  return;
}


// ==== FUN_004010d0 @ 004010d0 size=10

void FUN_004010d0(void)

{
  Ordinal_486();
  return;
}


// ==== FUN_004010e0 @ 004010e0 size=14

void FUN_004010e0(void)

{
  _atexit(FUN_004010f0);
  return;
}


// ==== FUN_004010f0 @ 004010f0 size=10

void FUN_004010f0(void)

{
  Ordinal_706();
  return;
}


// ==== FUN_00401260 @ 00401260 size=30

undefined4 * __thiscall FUN_00401260(void *this,byte param_1)

{
  FUN_00401280(this);
  if ((param_1 & 1) != 0) {
    Ordinal_731(this);
  }
  return this;
}


// ==== FUN_00401280 @ 00401280 size=61

void __fastcall FUN_00401280(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_004012bd;
  *param_1 = &PTR_LAB_004081d0;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  FUN_004012c7();
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_004012c7 @ 004012c7 size=8

void FUN_004012c7(void)

{
  Ordinal_600();
  return;
}


// ==== FUN_004016d0 @ 004016d0 size=55

void FUN_004016d0(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00401707;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  FUN_00401711();
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_00401711 @ 00401711 size=8

void FUN_00401711(void)

{
  Ordinal_570();
  return;
}


// ==== FUN_00401730 @ 00401730 size=68

void FUN_00401730(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 == 1) {
    _SVAbort_4(DAT_0040a7ec);
  }
  if ((param_1 == 2) || (param_1 == 0)) {
    FUN_004017b0();
  }
  Ordinal_4479(param_1,param_2,param_3);
  return;
}


// ==== FUN_004017b0 @ 004017b0 size=110

undefined4 FUN_004017b0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0x1e0;
  iVar1 = GetSystemMetrics(0);
  iVar2 = GetSystemMetrics(1);
  if (0x1e0 < iVar2) {
    iVar3 = GetSystemMetrics(0xf);
    iVar4 = GetSystemMetrics(4);
    iVar4 = iVar3 + 0x1ba + iVar4;
  }
  Ordinal_3786((iVar1 + -0x280) / 2,(iVar2 - iVar4) / 2,0x280,iVar4,1);
  return 0;
}


// ==== FUN_00401820 @ 00401820 size=113

void FUN_00401820(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  *(undefined4 *)(param_1 + 8) = 0x280;
  *(undefined4 *)(param_1 + 0xc) = 0x1e0;
  iVar1 = GetSystemMetrics(0);
  iVar2 = GetSystemMetrics(1);
  if (0x1e0 < iVar2) {
    iVar3 = GetSystemMetrics(0xf);
    iVar4 = GetSystemMetrics(4);
    *(int *)(param_1 + 0xc) = iVar3 + iVar4 + 0x1ba;
  }
  *(int *)(param_1 + 0x10) = (iVar1 - *(int *)(param_1 + 8)) / 2;
  *(int *)(param_1 + 0x14) = (iVar2 - *(int *)(param_1 + 0xc)) / 2;
  return;
}


// ==== FUN_00401a30 @ 00401a30 size=30

undefined4 * __thiscall FUN_00401a30(void *this,byte param_1)

{
  FUN_00401a50(this);
  if ((param_1 & 1) != 0) {
    Ordinal_731(this);
  }
  return this;
}


// ==== FUN_00401a50 @ 00401a50 size=61

void __fastcall FUN_00401a50(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00401a8d;
  *param_1 = &PTR_LAB_004082e8;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  FUN_00401a97();
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_00401a97 @ 00401a97 size=8

void FUN_00401a97(void)

{
  Ordinal_578();
  return;
}


// ==== FUN_00401b86 @ 00401b86 size=8

void FUN_00401b86(void)

{
  FUN_004016d0();
  return;
}


// ==== FUN_00401c44 @ 00401c44 size=8

void FUN_00401c44(void)

{
  FUN_00401ce0();
  return;
}


// ==== FUN_00401cd7 @ 00401cd7 size=8

void FUN_00401cd7(void)

{
  Ordinal_592();
  return;
}


// ==== FUN_00401ce0 @ 00401ce0 size=55

void FUN_00401ce0(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00401d17;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  FUN_00401d21();
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_00401d21 @ 00401d21 size=8

void FUN_00401d21(void)

{
  Ordinal_570();
  return;
}


// ==== FUN_00401d50 @ 00401d50 size=119

undefined4 * __fastcall FUN_00401d50(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00401de8;
  *unaff_FS_OFFSET = &local_10;
  Ordinal_509();
  param_1[0x10] = &PTR_LAB_004084c8;
  param_1[0x10] = &PTR_LAB_004084f8;
  param_1[0x10] = &PTR_LAB_004084e0;
  param_1[0x11] = 0;
  *param_1 = &PTR_LAB_00408408;
  DAT_0040a630 = 0;
  DAT_0040a628 = 0;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}


// ==== FUN_00401e00 @ 00401e00 size=30

undefined4 * __thiscall FUN_00401e00(void *this,byte param_1)

{
  FUN_00401e20(this);
  if ((param_1 & 1) != 0) {
    Ordinal_731(this);
  }
  return this;
}


// ==== FUN_00401e20 @ 00401e20 size=144

void __fastcall FUN_00401e20(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00401ebb;
  *param_1 = &PTR_LAB_00408408;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 1;
  if (DAT_0040a630 != 0) {
    free((void *)DAT_0040a630);
  }
  if (DAT_0040a628 != (int *)0x0) {
    Ordinal_2115(param_1);
    if (DAT_0040a628 != (int *)0x0) {
      (**(code **)(*DAT_0040a628 + 4))(1);
    }
  }
  DAT_0040a62c = 0;
  local_8 = local_8 & 0xffffff00;
  FUN_00401eb0();
  local_8 = 0xffffffff;
  FUN_00401ec5();
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_00401eb0 @ 00401eb0 size=11

void FUN_00401eb0(void)

{
  int unaff_EBP;
  
  FUN_004023c0((undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x40));
  return;
}


// ==== FUN_00401ec5 @ 00401ec5 size=8

void FUN_00401ec5(void)

{
  Ordinal_724();
  return;
}


// ==== FUN_00401ef0 @ 00401ef0 size=10

void __cdecl FUN_00401ef0(undefined4 param_1)

{
  DAT_0040a624 = param_1;
  return;
}


// ==== FUN_00401f00 @ 00401f00 size=159

void __cdecl FUN_00401f00(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00401f9f;
  *unaff_FS_OFFSET = &local_10;
  if ((DAT_0040a624 != 0) && (DAT_0040a62c == (int *)0x0)) {
    puVar1 = (undefined4 *)Ordinal_729(0x48);
    local_8 = 0;
    piVar2 = (int *)0x0;
    if (puVar1 != (undefined4 *)0x0) {
      piVar2 = FUN_00401d50(puVar1);
    }
    local_8 = 0xffffffff;
    DAT_0040a62c = piVar2;
    iVar3 = FUN_00402020(param_1);
    if (iVar3 == 0) {
      if (DAT_0040a62c != (int *)0x0) {
        (**(code **)(*DAT_0040a62c + 4))(1);
      }
    }
    else {
      UpdateWindow((HWND)DAT_0040a62c[8]);
    }
  }
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_00401fc0 @ 00401fc0 size=95

undefined4 __cdecl FUN_00401fc0(int param_1)

{
  int iVar1;
  
  if (DAT_0040a62c == (int *)0x0) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 4);
  if (((((iVar1 != 0x100) && (iVar1 != 0x104)) && (iVar1 != 0x201)) &&
      ((iVar1 != 0x204 && (iVar1 != 0x207)))) &&
     ((iVar1 != 0xa1 && ((iVar1 != 0xa4 && (iVar1 != 0xa7)))))) {
    return 0;
  }
  FUN_004020c0(DAT_0040a62c);
  return 1;
}


// ==== FUN_00402020 @ 00402020 size=160

undefined4 FUN_00402020(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  HCURSOR pHVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  LPCSTR pCVar12;
  undefined4 uVar13;
  
  pCVar12 = (LPCSTR)0x66;
  iVar1 = Ordinal_1035();
  DAT_0040a630 = FUN_00403740(*(HMODULE *)(iVar1 + 8),pCVar12);
  if (DAT_0040a630 == (int *)0x0) {
    DAT_0040a628 = (int *)0x0;
  }
  else {
    DAT_0040a628 = FUN_004037c0((int)DAT_0040a630);
  }
  if (DAT_0040a630 == (int *)0x0) {
    return 0;
  }
  Ordinal_1035();
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x20);
  }
  uVar13 = 0;
  uVar11 = 0;
  iVar1 = DAT_0040a630[2];
  iVar10 = DAT_0040a630[1];
  uVar9 = 0;
  uVar8 = 0;
  uVar7 = 0x90000000;
  uVar6 = 0;
  uVar5 = 0;
  uVar4 = 0;
  pHVar3 = LoadCursorA((HINSTANCE)0x0,&DAT_00007f00);
  uVar2 = Ordinal_1090(0,pHVar3,uVar4,uVar5,uVar6,uVar7,uVar8,uVar9,iVar10,iVar1,uVar2,uVar11,uVar13
                      );
  uVar2 = Ordinal_1869(0,uVar2);
  return uVar2;
}


// ==== FUN_004020c0 @ 004020c0 size=50

void __fastcall FUN_004020c0(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  (**(code **)(*param_1 + 0x5c))();
  iVar1 = Ordinal_1041();
  if (iVar1 != 0) {
    piVar2 = (int *)Ordinal_1041();
    iVar1 = (**(code **)(*piVar2 + 0x78))();
    UpdateWindow(*(HWND *)(iVar1 + 0x20));
    return;
  }
  UpdateWindow(pHRam00000020);
  return;
}


// ==== FUN_00402110 @ 00402110 size=56

undefined4 __fastcall FUN_00402110(int param_1)

{
  int iVar1;
  
  iVar1 = Ordinal_2081();
  if (iVar1 == -1) {
    return 0xffffffff;
  }
  Ordinal_1532(0);
  SetTimer(*(HWND *)(param_1 + 0x20),1,2000,(TIMERPROC)0x0);
  return 0;
}


// ==== FUN_00402260 @ 00402260 size=7

void __fastcall FUN_00402260(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_004084c8;
  return;
}


// ==== FUN_004022db @ 004022db size=8

void FUN_004022db(void)

{
  int unaff_EBP;
  
  FUN_00402260(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}


// ==== FUN_004022f0 @ 004022f0 size=73

void __fastcall FUN_004022f0(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00402339;
  *param_1 = &PTR_LAB_004084f8;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0;
  Ordinal_2115(param_1);
  local_8 = 0xffffffff;
  FUN_00402343();
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_00402343 @ 00402343 size=8

void FUN_00402343(void)

{
  int unaff_EBP;
  
  FUN_00402260(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}


// ==== FUN_004023af @ 004023af size=8

void FUN_004023af(void)

{
  int unaff_EBP;
  
  FUN_004022f0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}


// ==== FUN_004023c0 @ 004023c0 size=61

void __fastcall FUN_004023c0(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_004023fd;
  *param_1 = &PTR_LAB_004084e0;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  FUN_00402407();
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_00402407 @ 00402407 size=8

void FUN_00402407(void)

{
  int unaff_EBP;
  
  FUN_004022f0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}


// ==== FUN_00402550 @ 00402550 size=30

undefined4 * __thiscall FUN_00402550(void *this,byte param_1)

{
  FUN_004025c0(this);
  if ((param_1 & 1) != 0) {
    Ordinal_731(this);
  }
  return this;
}


// ==== FUN_00402570 @ 00402570 size=55

void FUN_00402570(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_004025a7;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  FUN_004025b1();
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_004025b1 @ 004025b1 size=8

void FUN_004025b1(void)

{
  Ordinal_690();
  return;
}


// ==== FUN_004025c0 @ 004025c0 size=61

void __fastcall FUN_004025c0(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_004025fd;
  *param_1 = &PTR_LAB_004085b0;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  FUN_00402607();
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_00402607 @ 00402607 size=8

void FUN_00402607(void)

{
  FUN_00402570();
  return;
}


// ==== FUN_00402660 @ 00402660 size=22

void FUN_00402660(void)

{
  Ordinal_2081(1);
  return;
}


// ==== FUN_004026b0 @ 004026b0 size=92

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004026b0(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  _DAT_0040a638 = &PTR_LAB_00408740;
  DAT_0040a63c = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_00402730 @ 00402730 size=14

void FUN_00402730(void)

{
  _atexit(FUN_00402740);
  return;
}


// ==== FUN_00402740 @ 00402740 size=60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00402740(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  _DAT_0040a638 = &PTR_LAB_00408740;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040277c;
  *unaff_FS_OFFSET = &local_10;
  FUN_00402786();
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_00402786 @ 00402786 size=10

void FUN_00402786(void)

{
  FUN_004022f0((undefined4 *)&DAT_0040a638);
  return;
}


// ==== FUN_004027a0 @ 004027a0 size=92

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004027a0(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  _DAT_0040a660 = &PTR_LAB_00408740;
  DAT_0040a664 = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_00402820 @ 00402820 size=14

void FUN_00402820(void)

{
  _atexit(FUN_00402830);
  return;
}


// ==== FUN_00402830 @ 00402830 size=60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00402830(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  _DAT_0040a660 = &PTR_LAB_00408740;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040286c;
  *unaff_FS_OFFSET = &local_10;
  FUN_00402876();
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_00402876 @ 00402876 size=10

void FUN_00402876(void)

{
  FUN_004022f0((undefined4 *)&DAT_0040a660);
  return;
}


// ==== FUN_00402890 @ 00402890 size=10

void FUN_00402890(void)

{
  Ordinal_486();
  return;
}


// ==== FUN_004028a0 @ 004028a0 size=14

void FUN_004028a0(void)

{
  _atexit(FUN_004028b0);
  return;
}


// ==== FUN_004028b0 @ 004028b0 size=10

void FUN_004028b0(void)

{
  Ordinal_706();
  return;
}


// ==== FUN_004028e0 @ 004028e0 size=77

undefined4 * __fastcall FUN_004028e0(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040292d;
  *unaff_FS_OFFSET = &local_10;
  Ordinal_504(0);
  *param_1 = &PTR_LAB_00408758;
  *unaff_FS_OFFSET = local_10;
  return param_1;
}


// ==== FUN_00402999 @ 00402999 size=8

void FUN_00402999(void)

{
  Ordinal_721();
  return;
}


// ==== FUN_004029c0 @ 004029c0 size=10

void FUN_004029c0(void)

{
  FUN_004028e0((undefined4 *)&DAT_0040a668);
  return;
}


// ==== FUN_004029d0 @ 004029d0 size=14

void FUN_004029d0(void)

{
  _atexit(FUN_004029e0);
  return;
}


// ==== FUN_004029e0 @ 004029e0 size=49

void FUN_004029e0(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00402a11;
  local_8 = 0xffffffff;
  *unaff_FS_OFFSET = &local_10;
  FUN_00402a1b();
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_00402a1b @ 00402a1b size=10

void FUN_00402a1b(void)

{
  Ordinal_721();
  return;
}


// ==== FUN_00403436 @ 00403436 size=8

void FUN_00403436(void)

{
  Ordinal_549();
  return;
}


// ==== FUN_004036b0 @ 004036b0 size=44

undefined4 FUN_004036b0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00401fc0(param_1);
  if (iVar1 != 0) {
    return 1;
  }
  uVar2 = Ordinal_4703(param_1);
  return uVar2;
}


// ==== FUN_004036e0 @ 004036e0 size=85

void __cdecl FUN_004036e0(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = param_1 * 8 + 0x1f;
  iVar1 = ((int)(iVar1 + (iVar1 >> 0x1f & 0x1fU)) >> 5) * param_2;
  puVar2 = calloc(1,iVar1 * 4 + 0x38);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = 0x28;
    *(undefined2 *)((int)puVar2 + 0xe) = 2;
    puVar2[2] = param_2;
    puVar2[1] = param_1;
    puVar2[5] = iVar1 * 4;
  }
  return;
}


// ==== FUN_00403740 @ 00403740 size=114

int * __cdecl FUN_00403740(HMODULE param_1,LPCSTR param_2)

{
  HRSRC hResInfo;
  HGLOBAL hResData;
  int *piVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  
  hResInfo = FindResourceA(param_1,param_2,(LPCSTR)0x2);
  if (hResInfo == (HRSRC)0x0) {
    return (int *)0x0;
  }
  hResData = LoadResource(param_1,hResInfo);
  if (hResData != (HGLOBAL)0x0) {
    piVar1 = LockResource(hResData);
    if (piVar1 != (int *)0x0) {
      uVar4 = piVar1[5] + 0x400 + *piVar1;
      piVar2 = malloc(uVar4);
      if (piVar2 != (int *)0x0) {
        piVar5 = piVar2;
        for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *piVar5 = *piVar1;
          piVar1 = piVar1 + 1;
          piVar5 = piVar5 + 1;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(char *)piVar5 = (char)*piVar1;
          piVar1 = (int *)((int)piVar1 + 1);
          piVar5 = (int *)((int)piVar5 + 1);
        }
        return piVar2;
      }
    }
    return (int *)0x0;
  }
  return (int *)0x0;
}


// ==== FUN_004037c0 @ 004037c0 size=242

int * __cdecl FUN_004037c0(int param_1)

{
  LOGPALETTE *pLVar1;
  int *piVar2;
  LOGPALETTE *pLVar3;
  int iVar4;
  BYTE *pBVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_004038c2;
  *unaff_FS_OFFSET = &local_10;
  if (param_1 != 0) {
    pLVar3 = (LOGPALETTE *)Ordinal_729(0x404);
    if (pLVar3 != (LOGPALETTE *)0x0) {
      iVar4 = 0x100;
      pBVar5 = (BYTE *)(param_1 + 0x2a);
      pLVar1 = pLVar3;
      do {
        iVar4 = iVar4 + -1;
        pLVar1->palPalEntry[0].peRed = *pBVar5;
        pLVar1->palPalEntry[0].peBlue = pBVar5[-2];
        pLVar1->palPalEntry[0].peGreen = pBVar5[-1];
        pLVar1->palPalEntry[0].peFlags = '\0';
        pBVar5 = pBVar5 + 4;
        pLVar1 = (LOGPALETTE *)pLVar1->palPalEntry;
      } while (iVar4 != 0);
      pLVar3->palVersion = 0x300;
      pLVar3->palNumEntries = 0x100;
      piVar2 = (int *)Ordinal_729(8);
      if (piVar2 == (int *)0x0) {
        piVar2 = (int *)0x0;
      }
      else {
        *piVar2 = (int)&PTR_LAB_004084c8;
        *piVar2 = (int)&PTR_LAB_004084f8;
        piVar2[1] = 0;
        *piVar2 = (int)&PTR_LAB_004087f8;
      }
      local_8 = 0xffffffff;
      iVar4 = FUN_00403950((int)piVar2,pLVar3);
      if (iVar4 == 0) {
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 4))(1);
        }
        piVar2 = (int *)0x0;
      }
      Ordinal_731(pLVar3);
      goto LAB_004037e7;
    }
  }
  piVar2 = (int *)0x0;
LAB_004037e7:
  *unaff_FS_OFFSET = local_10;
  return piVar2;
}


// ==== FUN_004038e0 @ 004038e0 size=93

void __cdecl FUN_004038e0(undefined4 param_1)

{
  undefined4 *unaff_FS_OFFSET;
  HDC local_20;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0040393d;
  *unaff_FS_OFFSET = &local_10;
  Ordinal_505(0);
  local_8 = 0;
  Ordinal_5127(param_1,1);
  RealizePalette(local_20);
  local_8 = 0xffffffff;
  FUN_00403947();
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_00403947 @ 00403947 size=8

void FUN_00403947(void)

{
  Ordinal_722();
  return;
}


// ==== FUN_00403950 @ 00403950 size=56

undefined4 __cdecl FUN_00403950(int param_1,LOGPALETTE *param_2)

{
  HPALETTE pHVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return 0;
  }
  pHVar1 = CreatePalette(param_2);
  iVar2 = Ordinal_1426(pHVar1);
  if (iVar2 == 0) {
    return 0;
  }
  FUN_004038e0(param_1);
  return 1;
}


// ==== FUN_00403b7f @ 00403b7f size=8

void FUN_00403b7f(void)

{
  int unaff_EBP;
  
  FUN_004022f0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}


// ==== FUN_00403b90 @ 00403b90 size=85

undefined4 * __thiscall FUN_00403b90(void *this,byte param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00403be5;
  *(undefined ***)this = &PTR_LAB_004087f8;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  FUN_00403bef();
  if ((param_1 & 1) != 0) {
    Ordinal_731(this);
  }
  *unaff_FS_OFFSET = local_10;
  return this;
}


// ==== FUN_00403bef @ 00403bef size=8

void FUN_00403bef(void)

{
  int unaff_EBP;
  
  FUN_004022f0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}


// ==== FUN_00403c10 @ 00403c10 size=92

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00403c10(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  _DAT_0040d308 = &PTR_LAB_00408740;
  _DAT_0040d30c = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_00403c90 @ 00403c90 size=14

void FUN_00403c90(void)

{
  _atexit(FUN_00403ca0);
  return;
}


// ==== FUN_00403ca0 @ 00403ca0 size=60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00403ca0(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  _DAT_0040d308 = &PTR_LAB_00408740;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00403cdc;
  *unaff_FS_OFFSET = &local_10;
  FUN_00403ce6();
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_00403ce6 @ 00403ce6 size=10

void FUN_00403ce6(void)

{
  FUN_004022f0((undefined4 *)&DAT_0040d308);
  return;
}


// ==== FUN_00403d00 @ 00403d00 size=92

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00403d00(void)

{
  undefined4 uVar1;
  undefined4 *unaff_FS_OFFSET;
  undefined1 local_10 [12];
  
  uVar1 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = local_10;
  _DAT_0040aaa0 = &PTR_LAB_00408a28;
  _DAT_0040aaa4 = 0;
  *unaff_FS_OFFSET = uVar1;
  return;
}


// ==== FUN_00403d80 @ 00403d80 size=14

void FUN_00403d80(void)

{
  _atexit(FUN_00403d90);
  return;
}


// ==== FUN_00403d90 @ 00403d90 size=60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00403d90(void)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  _DAT_0040aaa0 = &PTR_LAB_00408a28;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00403dcc;
  *unaff_FS_OFFSET = &local_10;
  FUN_00403dd6();
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_00403dd6 @ 00403dd6 size=10

void FUN_00403dd6(void)

{
  FUN_004022f0((undefined4 *)&DAT_0040aaa0);
  return;
}


// ==== FUN_00403fc0 @ 00403fc0 size=30

undefined4 * __thiscall FUN_00403fc0(void *this,byte param_1)

{
  FUN_00403fe0(this);
  if ((param_1 & 1) != 0) {
    Ordinal_731(this);
  }
  return this;
}


// ==== FUN_00403fe0 @ 00403fe0 size=105

void __fastcall FUN_00403fe0(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00404049;
  *param_1 = &PTR_LAB_00408a40;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0;
  if ((int *)param_1[0x20] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x20] + 4))(1);
  }
  if ((int *)param_1[0x21] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x21] + 4))(1);
  }
  local_8 = 0xffffffff;
  FUN_00404053();
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_00404053 @ 00404053 size=8

void FUN_00404053(void)

{
  FUN_00402570();
  return;
}


// ==== FUN_00404120 @ 00404120 size=546

void FUN_00404120(void)

{
  POINT pt;
  uint uVar1;
  BOOL BVar2;
  HWND pHVar3;
  uint uVar4;
  RECT *lprc;
  LONG unaff_ESI;
  int unaff_EDI;
  int iVar5;
  undefined1 local_4 [4];
  
  iVar5 = 0x3eb;
  uVar1 = Ordinal_2710(0x3eb,local_4,0);
  if (unaff_EDI == 0) {
    uVar4 = (uint)DAT_0040aa1c;
  }
  else {
    uVar4 = uVar1;
    if ((int)uVar1 < 0x29) {
      uVar4 = 0x28;
    }
    if (0x3e6 < (int)uVar4) {
      uVar4 = 999;
    }
  }
  if (uVar4 != uVar1) {
    Ordinal_5273(0x3eb,uVar4,0);
  }
  uVar1 = Ordinal_2710(0x3ea,&stack0xfffffff0,0);
  if (iVar5 == 0) {
    uVar4 = (uint)DAT_0040aa1e;
  }
  else {
    uVar4 = uVar1;
    if ((int)uVar1 < 0x29) {
      uVar4 = 0x28;
    }
    if (499 < (int)uVar4) {
      uVar4 = 500;
    }
  }
  if (uVar4 != uVar1) {
    Ordinal_5273(0x3ea,uVar4,0);
  }
  iVar5 = 0;
  lprc = (RECT *)&DAT_0040a488;
  do {
    pt.y = unaff_ESI;
    pt.x = unaff_EDI;
    BVar2 = PtInRect(lprc,pt);
    if (BVar2 != 0) break;
    lprc = lprc + 1;
    iVar5 = iVar5 + 1;
  } while (lprc < (RECT *)&DAT_0040a558);
  switch(iVar5) {
  case 0:
    if (DAT_0040a1b0 == 0) {
      FUN_00404c80(unaff_EDI,unaff_ESI);
    }
    break;
  case 1:
    if (DAT_0040a1b0 == 0) {
      FUN_00404ee0(unaff_EDI,unaff_ESI);
    }
    break;
  case 2:
    if (DAT_0040a1b0 == 0) {
      FUN_004050b0(unaff_EDI,unaff_ESI);
    }
    break;
  case 3:
    if (DAT_0040a1b0 == 0) {
      FUN_00405280(unaff_EDI,unaff_ESI);
    }
    break;
  case 4:
    if (DAT_0040a1b0 == 0) {
      FUN_00405700(unaff_EDI,unaff_ESI,0);
    }
    break;
  case 5:
    if (DAT_0040a1b0 != 0) {
      FUN_00405840(unaff_EDI,unaff_ESI,0);
    }
    break;
  case 6:
    FUN_00405980(unaff_EDI,unaff_ESI,0);
    break;
  case 7:
    if (DAT_0040a1b0 == 0) {
      FUN_004053c0(unaff_EDI,unaff_ESI,0);
    }
    break;
  case 8:
    if (DAT_0040a1b0 == 0) {
      FUN_00405560(unaff_EDI,unaff_ESI,0);
    }
  }
  pHVar3 = SetCapture(*(HWND *)(DAT_0040a1ac + 0x20));
  Ordinal_2515(pHVar3);
  return;
}


// ==== FUN_00404b60 @ 00404b60 size=54

void FUN_00404b60(void)

{
  Ordinal_4183();
  Ordinal_5429(1,1,1,Ordinal_5507_exref,Ordinal_5507_exref);
  return;
}


// ==== FUN_00404c80 @ 00404c80 size=608

void __cdecl FUN_00404c80(LONG param_1,LONG param_2)

{
  POINT pt;
  BOOL BVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  undefined4 uVar7;
  RECT local_10;
  
  iVar2 = 0;
  iVar4 = 0;
  piVar3 = &DAT_0040a248;
  do {
    local_10.left = *piVar3;
    local_10.top = piVar3[1];
    local_10.right = piVar3[2] + 1;
    local_10.bottom = piVar3[3] + 1;
    pt.y = param_2;
    pt.x = param_1;
    BVar1 = PtInRect(&local_10,pt);
    if ((BVar1 != 0) && (iVar4 != DAT_0040aad4)) {
      DAT_0040aad4 = iVar4;
      FUN_00405f70(DAT_0040a730,DAT_0040a72c,DAT_0040a7f8,DAT_0040a7fc,DAT_0040a800,DAT_0040a804);
      DAT_0040a7f8 = *piVar3;
      DAT_0040a7fc = piVar3[1];
      DAT_0040a800 = piVar3[2];
      DAT_0040a804 = piVar3[3];
      FUN_00405f70(DAT_0040a72c,DAT_0040a730,DAT_0040a7f8,DAT_0040a7fc,DAT_0040a800,DAT_0040a804);
      FUN_00405f70(*(int **)((int)&DAT_0040a758 + iVar2),DAT_0040a72c,DAT_0040a7f8,DAT_0040a7fc,
                   DAT_0040a800,DAT_0040a804);
      DAT_0040aab8 = *(undefined4 *)((int)&DAT_0040a1c0 + iVar2);
      uVar7 = 0x6a;
      _SVGetVoiceInfo_16();
      _SVSetPersonality_8();
      iVar6 = 0;
      puVar5 = &DAT_0040a488;
      InvalidateRect(DAT_0040a7f0,(RECT *)&DAT_0040a488,0);
      if (DAT_0040aa28 == 0) {
        uVar7 = 0x94;
      }
      else if (DAT_0040aa28 == 2) {
        uVar7 = 0xa5;
      }
      else if (DAT_0040aa28 == 4) {
        uVar7 = 0xb6;
      }
      FUN_00406710(&stack0xffffffb0,0x71,uVar7);
      FUN_00404ee0((int)puVar5,iVar6);
      if (DAT_0040aa24 == 0) {
        uVar7 = 0x94;
      }
      else if (DAT_0040aa24 == 1) {
        uVar7 = 0xa5;
      }
      else if (DAT_0040aa24 == 2) {
        uVar7 = 0xb6;
      }
      FUN_00406710(&stack0xffffffb0,0x1c5,uVar7);
      FUN_004050b0((int)puVar5,iVar6);
      Ordinal_5273(0x3eb);
      Ordinal_5273(0x3ea,DAT_0040aa1e,0);
    }
    iVar2 = iVar2 + 4;
    piVar3 = piVar3 + 4;
    iVar4 = iVar4 + 1;
  } while (piVar3 < &DAT_0040a388);
  return;
}


// ==== FUN_00404ee0 @ 00404ee0 size=423

void __cdecl FUN_00404ee0(int param_1,int param_2)

{
  HRGN pHVar1;
  BOOL BVar2;
  undefined2 extraout_var;
  RECT *lprect;
  undefined2 *puVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 *local_1c;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00405097;
  *unaff_FS_OFFSET = &local_10;
  iVar4 = 0;
  puVar3 = &DAT_0040a220;
  local_1c = &DAT_0040a7a8;
  lprect = (RECT *)&DAT_0040a388;
  local_8 = 2;
  do {
    pHVar1 = CreateEllipticRgnIndirect(lprect);
    Ordinal_1426(pHVar1);
    BVar2 = PtInRegion((HRGN)0x0,param_1,param_2);
    if ((BVar2 != 0) && (iVar4 != DAT_0040aa10)) {
      DAT_0040aa10 = iVar4;
      FUN_00405f70(DAT_0040a734,DAT_0040a72c,DAT_0040aad8,DAT_0040aadc,DAT_0040aae0,DAT_0040aae4);
      DAT_0040aad8 = lprect->left;
      DAT_0040aadc = lprect->top;
      DAT_0040aae0 = lprect->right;
      DAT_0040aae4 = lprect->bottom;
      FUN_00405f70(DAT_0040a72c,DAT_0040a734,DAT_0040aad8,DAT_0040aadc,DAT_0040aae0,DAT_0040aae4);
      FUN_00405f70((int *)*local_1c,DAT_0040a72c,DAT_0040aad8,DAT_0040aadc,DAT_0040aae0,DAT_0040aae4
                  );
      _SVSetF0Style_8(DAT_0040a7ec,CONCAT22(extraout_var,*puVar3));
      InvalidateRect(DAT_0040a7f0,(RECT *)&DAT_0040a498,0);
    }
    puVar3 = puVar3 + 1;
    lprect = lprect + 1;
    Ordinal_2115();
    local_1c = local_1c + 1;
    iVar4 = iVar4 + 1;
  } while (lprect < (RECT *)&DAT_0040a3b8);
  local_8 = 0xffffffff;
  FUN_004050a1();
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_004050a1 @ 004050a1 size=8

void FUN_004050a1(void)

{
  int unaff_EBP;
  
  FUN_00406810((undefined4 *)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_004050b0 @ 004050b0 size=423

void __cdecl FUN_004050b0(int param_1,int param_2)

{
  HRGN pHVar1;
  BOOL BVar2;
  undefined2 extraout_var;
  RECT *lprect;
  undefined2 *puVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 *local_1c;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00405267;
  *unaff_FS_OFFSET = &local_10;
  iVar4 = 0;
  puVar3 = &DAT_0040a228;
  local_1c = &DAT_0040a7b4;
  lprect = (RECT *)&DAT_0040a3b8;
  local_8 = 2;
  do {
    pHVar1 = CreateEllipticRgnIndirect(lprect);
    Ordinal_1426(pHVar1);
    BVar2 = PtInRegion((HRGN)0x0,param_1,param_2);
    if ((BVar2 != 0) && (DAT_0040aae8 != iVar4)) {
      DAT_0040aae8 = iVar4;
      FUN_00405f70(DAT_0040a738,DAT_0040a72c,DAT_0040aaa8,DAT_0040aaac,DAT_0040aab0,DAT_0040aab4);
      DAT_0040aaa8 = lprect->left;
      DAT_0040aaac = lprect->top;
      DAT_0040aab0 = lprect->right;
      DAT_0040aab4 = lprect->bottom;
      FUN_00405f70(DAT_0040a72c,DAT_0040a738,DAT_0040aaa8,DAT_0040aaac,DAT_0040aab0,DAT_0040aab4);
      FUN_00405f70((int *)*local_1c,DAT_0040a72c,DAT_0040aaa8,DAT_0040aaac,DAT_0040aab0,DAT_0040aab4
                  );
      _SVSetVoicingMode_8(DAT_0040a7ec,CONCAT22(extraout_var,*puVar3));
      InvalidateRect(DAT_0040a7f0,(RECT *)&DAT_0040a4a8,0);
    }
    puVar3 = puVar3 + 1;
    lprect = lprect + 1;
    Ordinal_2115();
    local_1c = local_1c + 1;
    iVar4 = iVar4 + 1;
  } while (lprect < (RECT *)&DAT_0040a3e8);
  local_8 = 0xffffffff;
  FUN_00405271();
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_00405271 @ 00405271 size=8

void FUN_00405271(void)

{
  int unaff_EBP;
  
  FUN_00406810((undefined4 *)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00405280 @ 00405280 size=311

void __cdecl FUN_00405280(LONG param_1,LONG param_2)

{
  POINT pt;
  BOOL BVar1;
  int iVar2;
  RECT *lprc;
  int iVar3;
  int iVar4;
  
  iVar4 = 3 - (uint)(DAT_0040a644 == 0);
  if (0 < iVar4) {
    iVar3 = 0;
    lprc = (RECT *)&DAT_0040a3e8;
    do {
      pt.y = param_2;
      pt.x = param_1;
      BVar1 = PtInRect(lprc,pt);
      if (BVar1 != 0) {
        iVar2 = _SVSetLanguage_8(DAT_0040a7ec,*(undefined4 *)((int)&DAT_0040a210 + iVar3));
        if (iVar2 == 0) {
          FUN_00405f70(DAT_0040a73c,DAT_0040a72c,DAT_0040aa88,DAT_0040aa8c,DAT_0040aa90,DAT_0040aa94
                      );
          DAT_0040aa88 = lprc->left;
          DAT_0040aa8c = lprc->top;
          DAT_0040aa90 = lprc->right;
          DAT_0040aa94 = lprc->bottom;
          FUN_00405f70(DAT_0040a72c,DAT_0040a73c,DAT_0040aa88,DAT_0040aa8c,DAT_0040aa90,DAT_0040aa94
                      );
          FUN_00405f70(*(int **)((int)&DAT_0040a7c0 + iVar3),DAT_0040a72c,DAT_0040aa88,DAT_0040aa8c,
                       DAT_0040aa90,DAT_0040aa94);
          InvalidateRect(DAT_0040a7f0,(RECT *)&DAT_0040a4b8,0);
        }
        else {
          Ordinal_1060(0xf014,0x30,0);
        }
      }
      iVar3 = iVar3 + 4;
      lprc = lprc + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}


// ==== FUN_004053c0 @ 004053c0 size=403

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004053c0(LONG param_1,LONG param_2,int param_3)

{
  POINT pt;
  BOOL BVar1;
  int iVar2;
  int iVar3;
  RECT *lprc;
  int iVar4;
  int *piVar5;
  int local_4;
  
  iVar3 = 0;
  iVar4 = 0;
  lprc = (RECT *)&DAT_0040a418;
  do {
    pt.y = param_2;
    pt.x = param_1;
    BVar1 = PtInRect(lprc,pt);
    if (BVar1 != 0) {
      piVar5 = DAT_0040a74c;
      if (param_3 == 0) {
        iVar2 = Ordinal_2710(0x3eb,&local_4,0);
        if (lprc == (RECT *)&DAT_0040a418) {
          iVar2 = iVar2 + 1;
          if (0x3e6 < iVar2) {
            iVar2 = 999;
          }
        }
        else {
          iVar2 = iVar2 + -1;
          if (iVar2 < 0x29) {
            iVar2 = 0x28;
          }
        }
        if (local_4 != 0) {
          Ordinal_5273(0x3eb,iVar2,0);
        }
        _DAT_0040a1a4 =
             SetTimer(*(HWND *)(DAT_0040a1ac + 0x20),*(UINT_PTR *)((int)&DAT_0040a230 + iVar4),100,
                      (TIMERPROC)0x0);
        DAT_0040aac4 = lprc->top;
        DAT_0040a1a8 = 0;
        _DAT_0040a1a0 = 1;
        _DAT_0040a1b8 = 10 - (uint)(iVar3 == 0);
        DAT_0040aac0 = lprc->left;
        DAT_0040aac8 = lprc->right;
        DAT_0040aacc = lprc->bottom;
        FUN_00405f70(DAT_0040a72c,DAT_0040a74c,DAT_0040aac0,DAT_0040aac4,DAT_0040aac8,DAT_0040aacc);
        piVar5 = *(int **)((int)&DAT_0040a7cc + iVar4);
      }
      FUN_00405f70(piVar5,DAT_0040a72c,DAT_0040aac0,DAT_0040aac4,DAT_0040aac8,DAT_0040aacc);
      InvalidateRect(DAT_0040a7f0,(RECT *)&DAT_0040a4f8,0);
    }
    iVar4 = iVar4 + 4;
    lprc = lprc + 1;
    iVar3 = iVar3 + 1;
  } while (lprc < (RECT *)&DAT_0040a438);
  return;
}


// ==== FUN_00405560 @ 00405560 size=403

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00405560(LONG param_1,LONG param_2,int param_3)

{
  POINT pt;
  BOOL BVar1;
  int iVar2;
  int iVar3;
  RECT *lprc;
  int iVar4;
  int *piVar5;
  int local_4;
  
  iVar3 = 0;
  iVar4 = 0;
  lprc = (RECT *)&DAT_0040a438;
  do {
    pt.y = param_2;
    pt.x = param_1;
    BVar1 = PtInRect(lprc,pt);
    if (BVar1 != 0) {
      piVar5 = DAT_0040a750;
      if (param_3 == 0) {
        iVar2 = Ordinal_2710(0x3ea,&local_4,0);
        if (lprc == (RECT *)&DAT_0040a438) {
          iVar2 = iVar2 + 1;
          if (499 < iVar2) {
            iVar2 = 500;
          }
        }
        else {
          iVar2 = iVar2 + -1;
          if (iVar2 < 0x29) {
            iVar2 = 0x28;
          }
        }
        if (local_4 != 0) {
          Ordinal_5273(0x3ea,iVar2,0);
        }
        _DAT_0040a1a4 =
             SetTimer(*(HWND *)(DAT_0040a1ac + 0x20),*(UINT_PTR *)((int)&DAT_0040a238 + iVar4),100,
                      (TIMERPROC)0x0);
        DAT_0040d2fc = lprc->top;
        DAT_0040a1a8 = 0;
        _DAT_0040a19c = 1;
        _DAT_0040a1b8 = 0xc - (uint)(iVar3 == 0);
        DAT_0040d2f8 = lprc->left;
        DAT_0040d300 = lprc->right;
        DAT_0040d304 = lprc->bottom;
        FUN_00405f70(DAT_0040a72c,DAT_0040a750,DAT_0040d2f8,DAT_0040d2fc,DAT_0040d300,DAT_0040d304);
        piVar5 = *(int **)((int)&DAT_0040a7d4 + iVar4);
      }
      FUN_00405f70(piVar5,DAT_0040a72c,DAT_0040d2f8,DAT_0040d2fc,DAT_0040d300,DAT_0040d304);
      InvalidateRect(DAT_0040a7f0,(RECT *)&DAT_0040a508,0);
    }
    iVar4 = iVar4 + 4;
    lprc = lprc + 1;
    iVar3 = iVar3 + 1;
  } while (lprc < (RECT *)&DAT_0040a458);
  return;
}


// ==== FUN_00405700 @ 00405700 size=281

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00405700(int param_1,int param_2,int param_3)

{
  HRGN pHVar1;
  BOOL BVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00405829;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 2;
  pHVar1 = CreateEllipticRgnIndirect((RECT *)&DAT_0040a458);
  Ordinal_1426(pHVar1);
  BVar2 = PtInRegion((HRGN)0x0,param_1,param_2);
  if (BVar2 != 0) {
    Ordinal_2707(1000);
    Ordinal_5296();
    if (param_3 == 0) {
      FUN_00405f70(DAT_0040a7dc,DAT_0040a72c,DAT_0040a458,DAT_0040a45c,DAT_0040a460,DAT_0040a464);
      _DAT_0040a1b8 = 4;
    }
    else {
      FUN_00405f70(DAT_0040a740,DAT_0040a72c,DAT_0040a458,DAT_0040a45c,DAT_0040a460,DAT_0040a464);
    }
    InvalidateRect(DAT_0040a7f0,(RECT *)&DAT_0040a458,0);
  }
  Ordinal_2115();
  local_8 = 0xffffffff;
  FUN_00405833();
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_00405833 @ 00405833 size=8

void FUN_00405833(void)

{
  int unaff_EBP;
  
  FUN_00406810((undefined4 *)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00405840 @ 00405840 size=281

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00405840(int param_1,int param_2,int param_3)

{
  HRGN pHVar1;
  BOOL BVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00405969;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 2;
  pHVar1 = CreateEllipticRgnIndirect((RECT *)&DAT_0040a468);
  Ordinal_1426(pHVar1);
  BVar2 = PtInRegion((HRGN)0x0,param_1,param_2);
  if (BVar2 != 0) {
    if (param_3 == 0) {
      FUN_00405f70(DAT_0040a7e0,DAT_0040a72c,DAT_0040a468,DAT_0040a46c,DAT_0040a470,DAT_0040a474);
      _SVPause_4(DAT_0040a7ec);
      _DAT_0040a1b4 = 1;
      _DAT_0040a1b8 = 5;
    }
    else {
      FUN_00405f70(DAT_0040a744,DAT_0040a72c,DAT_0040a468,DAT_0040a46c,DAT_0040a470,DAT_0040a474);
    }
    InvalidateRect(DAT_0040a7f0,(RECT *)&DAT_0040a468,0);
  }
  Ordinal_2115();
  local_8 = 0xffffffff;
  FUN_00405973();
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_00405973 @ 00405973 size=8

void FUN_00405973(void)

{
  int unaff_EBP;
  
  FUN_00406810((undefined4 *)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00405980 @ 00405980 size=258

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00405980(int param_1,int param_2,int param_3)

{
  HRGN pHVar1;
  BOOL BVar2;
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_00405a92;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 2;
  pHVar1 = CreateEllipticRgnIndirect((RECT *)&DAT_0040a478);
  Ordinal_1426(pHVar1);
  BVar2 = PtInRegion((HRGN)0x0,param_1,param_2);
  if (BVar2 != 0) {
    if (param_3 == 0) {
      FUN_00405f70(DAT_0040a7e4,DAT_0040a72c,DAT_0040a478,DAT_0040a47c,DAT_0040a480,DAT_0040a484);
      _DAT_0040a1b8 = 6;
    }
    else {
      FUN_00405f70(DAT_0040a748,DAT_0040a72c,DAT_0040a478,DAT_0040a47c,DAT_0040a480,DAT_0040a484);
    }
    InvalidateRect(DAT_0040a7f0,(RECT *)&DAT_0040a478,0);
  }
  Ordinal_2115();
  local_8 = 0xffffffff;
  FUN_00405a9c();
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_00405a9c @ 00405a9c size=8

void FUN_00405a9c(void)

{
  int unaff_EBP;
  
  FUN_00406810((undefined4 *)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00405ef9 @ 00405ef9 size=8

void FUN_00405ef9(void)

{
  int unaff_EBP;
  
  FUN_00406810((undefined4 *)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00405f70 @ 00405f70 size=253

void __cdecl FUN_00405f70(int *param_1,int *param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  int local_10;
  int local_8;
  
  iVar8 = (param_5 - param_3) + 1;
  iVar4 = (param_6 - param_4) + 1;
  if (param_1[2] == iVar4) {
    iVar5 = 0;
    local_10 = 0;
    local_8 = param_3;
    iVar7 = (param_2[2] - iVar4) - param_4;
  }
  else {
    iVar7 = 0;
    iVar5 = (param_1[2] - iVar4) - param_4;
    local_10 = param_3;
    local_8 = 0;
  }
  iVar2 = param_1[1] * 8 + 0x1f;
  iVar2 = ((int)(iVar2 + (iVar2 >> 0x1f & 0x1fU)) >> 5) * 4;
  puVar6 = (undefined1 *)
           ((int)param_1 +
           local_10 + iVar5 * iVar2 + (1 << (*(byte *)((int)param_1 + 0xe) & 0x1f)) * 4 + *param_1);
  iVar5 = param_2[1] * 8 + 0x1f;
  iVar5 = ((int)(iVar5 + (iVar5 >> 0x1f & 0x1fU)) >> 5) * 4;
  puVar3 = (undefined1 *)
           ((int)param_2 +
           local_8 + iVar7 * iVar5 + (1 << (*(byte *)((int)param_2 + 0xe) & 0x1f)) * 4 + *param_2);
  if (0 < iVar4) {
    do {
      iVar7 = iVar8;
      if (0 < iVar8) {
        do {
          uVar1 = *puVar6;
          puVar6 = puVar6 + 1;
          *puVar3 = uVar1;
          puVar3 = puVar3 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      puVar6 = puVar6 + (iVar2 - iVar8);
      puVar3 = puVar3 + (iVar5 - iVar8);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}


// ==== FUN_00406070 @ 00406070 size=177

undefined1 * FUN_00406070(void)

{
  int iVar1;
  int unaff_EBX;
  undefined1 *puVar2;
  int aiStack_8 [2];
  
  DAT_0040a808 = 0;
  DAT_0040aaf0 = 0;
  iVar1 = Ordinal_2707(1000);
  SendMessageA(*(HWND *)(iVar1 + 0x20),0xb0,(WPARAM)&stack0xfffffff4,(LPARAM)aiStack_8);
  if (aiStack_8[0] == unaff_EBX) {
    aiStack_8[0] = 0x200;
  }
  iVar1 = aiStack_8[0] + 1;
  if (0x200 < iVar1) {
    iVar1 = 0x201;
  }
  puVar2 = &DAT_0040a808;
  Ordinal_2707(1000,&DAT_0040a808,iVar1);
  Ordinal_3382();
  puVar2 = &DAT_0040a808 + (int)puVar2;
  _SVTextToPhon_24(DAT_0040a7ec,puVar2,&DAT_0040aaf0,0x2800,0x18,0);
  return puVar2;
}


// ==== FUN_004061f0 @ 004061f0 size=174

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004061f0(void)

{
  WPARAM wParam;
  LPARAM lParam;
  int iVar1;
  
  lParam = DAT_0040aa14;
  wParam = DAT_0040aa0c;
  iVar1 = Ordinal_2707(1000);
  SendMessageA(*(HWND *)(iVar1 + 0x20),0xb1,wParam,lParam);
  SendMessageA(*(HWND *)(iVar1 + 0x20),0xb7,0,0);
  FUN_00405700(0x143,0x16a,1);
  _DAT_0040a1b4 = 0;
  DAT_0040a1b0 = 0;
  Ordinal_2707(1000);
  Ordinal_5296();
  iVar1 = Ordinal_2707(1000);
  ShowCaret(*(HWND *)(iVar1 + 0x20));
  return;
}


// ==== FUN_004062a0 @ 004062a0 size=420

void FUN_004062a0(undefined4 param_1)

{
  POINT pt;
  POINT pt_00;
  POINT pt_01;
  POINT pt_02;
  BOOL BVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int local_4;
  
  DAT_0040a1a8 = DAT_0040a1a8 + 100;
  iVar3 = (-(uint)(DAT_0040a1a8 < 3000) & 0xfffffff7) + 10;
  switch(param_1) {
  case 1:
    pt.y = DAT_0040aa9c;
    pt.x = DAT_0040aa98;
    BVar1 = PtInRect((RECT *)&DAT_0040a428,pt);
    if (BVar1 == 0) goto switchD_004062cf_default;
    iVar2 = Ordinal_2710(0x3eb,&local_4,0);
    iVar2 = iVar2 - iVar3;
    if (iVar2 < 0x29) {
      iVar2 = 0x28;
    }
    if (local_4 == 0) goto switchD_004062cf_default;
    uVar4 = 0x3eb;
    break;
  case 2:
    pt_00.y = DAT_0040aa9c;
    pt_00.x = DAT_0040aa98;
    BVar1 = PtInRect((RECT *)&DAT_0040a418,pt_00);
    if (BVar1 == 0) goto switchD_004062cf_default;
    iVar2 = Ordinal_2710(0x3eb,&local_4,0);
    iVar2 = iVar2 + iVar3;
    if (0x3e6 < iVar2) {
      iVar2 = 999;
    }
    if (local_4 == 0) goto switchD_004062cf_default;
    uVar4 = 0x3eb;
    break;
  case 3:
    pt_01.y = DAT_0040aa9c;
    pt_01.x = DAT_0040aa98;
    BVar1 = PtInRect((RECT *)&DAT_0040a448,pt_01);
    if (BVar1 == 0) goto switchD_004062cf_default;
    iVar2 = Ordinal_2710(0x3ea,&local_4,0);
    iVar2 = iVar2 - iVar3;
    if (iVar2 < 0x29) {
      iVar2 = 0x28;
    }
    goto joined_r0x00406420;
  case 4:
    pt_02.y = DAT_0040aa9c;
    pt_02.x = DAT_0040aa98;
    BVar1 = PtInRect((RECT *)&DAT_0040a438,pt_02);
    if (BVar1 == 0) goto switchD_004062cf_default;
    iVar2 = Ordinal_2710(0x3ea,&local_4,0);
    iVar2 = iVar2 + iVar3;
    if (499 < iVar2) {
      iVar2 = 500;
    }
joined_r0x00406420:
    if (local_4 == 0) goto switchD_004062cf_default;
    uVar4 = 0x3ea;
    break;
  default:
    goto switchD_004062cf_default;
  }
  Ordinal_5273(uVar4,iVar2,0);
switchD_004062cf_default:
  Ordinal_2081();
  return;
}


// ==== FUN_004064a0 @ 004064a0 size=88

void FUN_004064a0(void)

{
  uint uVar1;
  int iVar2;
  undefined1 local_4 [4];
  
  iVar2 = 0x3eb;
  uVar1 = Ordinal_2710(0x3eb,local_4,0);
  if (iVar2 == 0) {
    uVar1 = (uint)DAT_0040aa1c;
  }
  else {
    if ((int)uVar1 < 0x29) {
      uVar1 = 0x28;
    }
    if (0x3e6 < (int)uVar1) {
      uVar1 = 999;
    }
  }
  Ordinal_5273(0x3eb,uVar1,0);
  return;
}


// ==== FUN_00406500 @ 00406500 size=88

void FUN_00406500(void)

{
  uint uVar1;
  int iVar2;
  undefined1 local_4 [4];
  
  iVar2 = 0x3ea;
  uVar1 = Ordinal_2710(0x3ea,local_4,0);
  if (iVar2 == 0) {
    uVar1 = (uint)DAT_0040aa1e;
  }
  else {
    if ((int)uVar1 < 0x29) {
      uVar1 = 0x28;
    }
    if (499 < (int)uVar1) {
      uVar1 = 500;
    }
  }
  Ordinal_5273(0x3ea,uVar1,0);
  return;
}


// ==== FUN_004065d0 @ 004065d0 size=168

void __thiscall FUN_004065d0(void *this,undefined4 *param_1)

{
  int iVar1;
  HANDLE pvVar2;
  uint uVar3;
  int iStack_8;
  int iStack_4;
  
  if (DAT_0040a1b0 != 0) {
    uVar3 = 0;
    goto LAB_00406669;
  }
  iVar1 = param_1[1];
  if (0xe121 < iVar1) {
    if (iVar1 < 0xe124) {
      iVar1 = Ordinal_2707(1000);
      SendMessageA(*(HWND *)(iVar1 + 0x20),0xb0,(WPARAM)&iStack_4,(LPARAM)&iStack_8);
      uVar3 = (uint)(iStack_8 != iStack_4);
      goto LAB_00406669;
    }
    if (iVar1 == 0xe125) {
      uVar3 = OpenClipboard(*(HWND *)((int)this + 0x20));
      if (uVar3 != 0) {
        pvVar2 = GetClipboardData(1);
        if (pvVar2 == (HANDLE)0x0) {
          uVar3 = 0;
        }
        CloseClipboard();
      }
      goto LAB_00406669;
    }
  }
  uVar3 = 1;
LAB_00406669:
  (**(code **)*param_1)(uVar3);
  return;
}


// ==== FUN_00406710 @ 00406710 size=18

undefined4 * __thiscall FUN_00406710(void *this,undefined4 param_1,undefined4 param_2)

{
  *(undefined4 *)this = param_1;
  *(undefined4 *)((int)this + 4) = param_2;
  return this;
}


// ==== FUN_0040678f @ 0040678f size=8

void FUN_0040678f(void)

{
  int unaff_EBP;
  
  FUN_004022f0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}


// ==== FUN_004067ff @ 004067ff size=8

void FUN_004067ff(void)

{
  int unaff_EBP;
  
  FUN_004022f0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}


// ==== FUN_00406810 @ 00406810 size=61

void __fastcall FUN_00406810(undefined4 *param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  puStack_c = &LAB_0040684d;
  *param_1 = &PTR_LAB_00408b50;
  *unaff_FS_OFFSET = &local_10;
  local_8 = 0xffffffff;
  FUN_00406857();
  *unaff_FS_OFFSET = local_10;
  return;
}


// ==== FUN_00406857 @ 00406857 size=8

void FUN_00406857(void)

{
  int unaff_EBP;
  
  FUN_004022f0(*(undefined4 **)(unaff_EBP + -0x10));
  return;
}


// ==== FUN_00406860 @ 00406860 size=86

undefined4 * __thiscall FUN_00406860(void *this,undefined4 param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_004068b6;
  *unaff_FS_OFFSET = &local_10;
  Ordinal_315(0xb3,param_1);
  *(undefined ***)this = &PTR_LAB_00408b88;
  *unaff_FS_OFFSET = local_10;
  return this;
}


// ==== FUN_00406929 @ 00406929 size=8

void FUN_00406929(void)

{
  Ordinal_570();
  return;
}


// ==== FUN_00406a39 @ 00406a39 size=8

void FUN_00406a39(void)

{
  Ordinal_570();
  return;
}


// ==== FUN_00406f24 @ 00406f24 size=8

void FUN_00406f24(void)

{
  Ordinal_706();
  return;
}


// ==== FUN_004070a9 @ 004070a9 size=8

void FUN_004070a9(void)

{
  Ordinal_570();
  return;
}


// ==== FUN_004070f0 @ 004070f0 size=86

undefined4 * __thiscall FUN_004070f0(void *this,undefined4 param_1)

{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = *unaff_FS_OFFSET;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00407146;
  *unaff_FS_OFFSET = &local_10;
  Ordinal_315(0xc5,param_1);
  *(undefined ***)this = &PTR_LAB_00408ee8;
  *unaff_FS_OFFSET = local_10;
  return this;
}


// ==== FUN_004071b9 @ 004071b9 size=8

void FUN_004071b9(void)

{
  Ordinal_570();
  return;
}


// ==== __onexit @ 00407770 size=156

/* Library Function - Single Match
    __onexit
   
   Library: Visual Studio 1998 Release */

void __cdecl __onexit(_onexit_t param_1)

{
  DWORD DVar1;
  
  if (DAT_0040a5d8 == 0) {
    DVar1 = GetVersion();
    if (((DVar1 & 0xff) == 3) && ((DVar1 & 0x80000000) != 0)) {
      DAT_0040a5d8 = DAT_0040a5d8 + 1;
    }
    else {
      DAT_0040a5d8 = DAT_0040a5d8 + -1;
    }
  }
  if (0 < DAT_0040a5d8) {
    while (0 < DAT_0040a5dc) {
      Sleep(0);
    }
    DAT_0040a5dc = DAT_0040a5dc + 1;
  }
  if (DAT_0040d32c == -1) {
    _onexit(param_1);
  }
  else {
    __dllonexit(param_1,&DAT_0040d32c,&DAT_0040d328);
  }
  if (0 < DAT_0040a5d8) {
    DAT_0040a5dc = DAT_0040a5dc + -1;
  }
  return;
}


// ==== _atexit @ 00407810 size=19

/* Library Function - Single Match
    _atexit
   
   Library: Visual Studio 1998 Release */

int __cdecl _atexit(_func_4879 *param_1)

{
  int iVar1;
  
  iVar1 = __onexit((_onexit_t)param_1);
  return -(uint)(iVar1 == 0);
}


// ==== entry @ 00407830 size=350

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  byte bVar1;
  undefined4 *puVar2;
  uint uVar3;
  HMODULE pHVar4;
  int _Code;
  byte *pbVar5;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar7;
  _STARTUPINFOA local_8c;
  int local_40;
  char **local_3c;
  char **local_38 [3];
  _startupinfo local_2c [4];
  undefined1 *local_1c;
  undefined4 uStack_14;
  undefined *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  byte *pbVar6;
  
  uStack_14 = *unaff_FS_OFFSET;
  puStack_c = &DAT_00408fc0;
  puStack_10 = &DAT_00407a22;
  *unaff_FS_OFFSET = &uStack_14;
  local_1c = &stack0xffffff68;
  local_8 = 0;
  __set_app_type(2);
  DAT_0040d328 = 0xffffffff;
  DAT_0040d32c = 0xffffffff;
  puVar2 = (undefined4 *)__p__fmode();
  *puVar2 = DAT_0040a5f0;
  puVar2 = (undefined4 *)__p__commode();
  *puVar2 = DAT_0040a5ec;
  _DAT_0040d324 = *(undefined4 *)_adjust_fdiv_exref;
  FUN_00407a20();
  if (DAT_0040a5e8 == 0) {
    __setusermatherr(&LAB_00407a10);
  }
  __setdefaultprecision();
  initterm(&DAT_0040a048,&DAT_0040a04c);
  local_2c[0].newmode = DAT_0040a5e4;
  __getmainargs(&local_40,&local_3c,local_38,DAT_0040a5e0,local_2c);
  initterm(&DAT_0040a000,&DAT_0040a044);
  puVar2 = (undefined4 *)__p__acmdln();
  pbVar5 = (byte *)*puVar2;
  bVar1 = *pbVar5;
  if (bVar1 == 0x22) {
    do {
      pbVar6 = pbVar5;
      pbVar5 = pbVar6 + 1;
      if (*pbVar5 == 0) break;
    } while (*pbVar5 != 0x22);
    if (*pbVar5 == 0x22) {
      pbVar5 = pbVar6 + 2;
    }
  }
  else {
    while (0x20 < bVar1) {
      pbVar5 = pbVar5 + 1;
      bVar1 = *pbVar5;
    }
  }
  bVar1 = *pbVar5;
  while ((bVar1 != 0 && (*pbVar5 < 0x21))) {
    pbVar5 = pbVar5 + 1;
    bVar1 = *pbVar5;
  }
  local_8c.dwFlags = 0;
  GetStartupInfoA(&local_8c);
  uVar3 = 10;
  if ((local_8c.dwFlags & 1) != 0) {
    uVar3 = local_8c._48_4_ & 0xffff;
  }
  uVar7 = 0;
  pHVar4 = GetModuleHandleA((LPCSTR)0x0);
  _Code = _WinMain_16(pHVar4,uVar7,pbVar5,uVar3);
                    /* WARNING: Subroutine does not return */
  exit(_Code);
}


// ==== __setdefaultprecision @ 004079f0 size=19

/* Library Function - Single Match
    __setdefaultprecision
   
   Library: Visual Studio 1998 Release */

void __setdefaultprecision(void)

{
  _controlfp(0x10000,0x30000);
  return;
}


// ==== FUN_00407a20 @ 00407a20 size=1

void FUN_00407a20(void)

{
  return;
}


// ==== _WinMain@16 @ 00407a2e size=25

/* Library Function - Single Match
    _WinMain@16
   
   Library: Visual Studio 1998 Release */

void _WinMain_16(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  Ordinal_1368(param_1,param_2,param_3,param_4);
  return;
}


// ==== FUN_00407a47 @ 00407a47 size=45

undefined4 FUN_00407a47(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = Ordinal_1035();
  *(char *)(iVar1 + 0x14) = (char)param_1;
  *(undefined4 *)(iVar1 + 0x1040) = param_2;
  if (param_1 == 0) {
    _setmbcp(-3);
  }
  return 1;
}


