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
