// ==== FUN_1c001000 @ 1c001000 size=162

undefined4 FUN_1c001000(HINSTANCE param_1,int param_2)

{
  ATOM AVar1;
  WNDCLASSA local_28;
  
  if (param_2 == 1) {
    DAT_1c0145b8 = param_1;
    if (DAT_1c012010 == 0) {
      local_28.cbClsExtra = 0;
      local_28.cbWndExtra = 0;
      local_28.hInstance = param_1;
      local_28.hIcon = (HICON)0x0;
      local_28.hCursor = (HCURSOR)0x0;
      local_28.lpszMenuName = (LPCSTR)0x0;
      local_28.lpfnWndProc = (WNDPROC)&LAB_1c00f4e0;
      local_28.hbrBackground = (HBRUSH)0x2;
      local_28.lpszClassName = s_NarratorClass_1c012024;
      local_28.style = 0x4000;
      AVar1 = RegisterClassA(&local_28);
      DAT_1c012010 = (uint)AVar1;
      if (AVar1 == 0) {
        return 0;
      }
    }
    DAT_1c014570 = 0;
    DAT_1c014544 = 0;
    DAT_1c0145b0 = RegisterWindowMessageA(s_SVSyncMessages_1c012014);
  }
  return 1;
}


// ==== _SVNarrate@20 @ 1c0036f0 size=379

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _SVNarrate_20(undefined4 *param_1,char *param_2,HWND param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  
                    /* 0x36f0  8  _SVNarrate@20 */
  iVar1 = FUN_1c00e0f0((int)param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  if (DAT_1c01208c != 0) {
    if ((param_4 & 0x20) == 0) {
      return 0x1b66;
    }
    _SVAbort_4((int)param_1);
  }
  if (param_2 == (char *)0x0) {
    return 0x1b70;
  }
  if (*param_2 == '\0') {
    _DAT_1c012048 = param_1;
    _DAT_1c01204c = 0;
    _DAT_1c012058 = 0;
    PostMessageA(param_3,DAT_1c0145b0,1000,0x1c012048);
    _DAT_1c012072 = 0;
    _DAT_1c012068 = param_1;
    _DAT_1c01206c = 0;
    _DAT_1c012078 = 0;
    _DAT_1c012084 = 0;
    PostMessageA(param_3,DAT_1c0145b0,0x3e9,0x1c012068);
    return 0;
  }
  *param_1 = param_3;
  uVar2 = FUN_1c00c620((int)param_1);
  if (uVar2 == 0) {
    DAT_1c01208c = 1;
    param_1[7] = 2;
    *(undefined2 *)param_1[0x29] = 0;
    *(undefined2 *)(param_1[0x29] + 2) = 0;
    param_1[0x32] = param_2;
    param_1[8] = DAT_1c0145b0;
    FUN_1c00df20((int)param_1);
    *(undefined4 *)((int)param_1 + 0x176) = param_1[0x13e];
    *(undefined4 *)((int)param_1 + 0x172) = param_1[0x13f];
    *(undefined4 *)((int)param_1 + 0x17a) = param_1[0x140];
    *(HWND *)((int)param_1 + 0x13e) = param_3;
    uVar2 = param_1[0x62] | param_4;
    param_1[0x62] = uVar2;
    param_1[0x62] = uVar2 | 0x80000000;
    if ((uVar2 & 0x40000000) == 0) {
      param_1[0x62] = uVar2 | 0xa0000000;
    }
    *(undefined4 *)((int)param_1 + 0x156) = 0;
    uVar2 = FUN_1c003870((DWORD_PTR)param_1);
  }
  return uVar2;
}


// ==== FUN_1c003870 @ 1c003870 size=1322

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __cdecl FUN_1c003870(DWORD_PTR param_1)

{
  uint uVar1;
  LPWAVEHDR pwVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  MMRESULT MVar6;
  int iVar7;
  DWORD DVar8;
  undefined4 extraout_EDX;
  undefined4 *puVar9;
  int *piVar10;
  code *pcVar11;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  undefined4 *local_4;
  
  _DAT_1c0145ac = 0;
  _DAT_1c0145a8 = 0;
  _DAT_1c0145a4 = 0;
  local_18 = 0;
  iVar7 = param_1 + 0x13a;
  *(undefined4 *)(param_1 + 0x230) = 0;
  *(undefined4 *)(param_1 + 0x1fa) = 0;
  *(undefined1 *)(param_1 + 0x457) = 0;
  DAT_1c0145b4 = 0;
  DAT_1c0145a0 = 0;
  iVar3 = FUN_1c00c500(iVar7);
  if (iVar3 == 0) {
    *(undefined1 *)(param_1 + 0x457) = 0;
  }
  else {
    *(undefined1 *)(param_1 + 0x457) = 1;
    *(undefined1 *)(param_1 + 0x456) = 2;
    if (*(void **)(param_1 + 0x156) != (void *)0x0) {
      free(*(void **)(param_1 + 0x156));
    }
    uVar1 = *(int *)(param_1 + 0x152) * 2 + 10;
    *(short *)(param_1 + 0x146) = (short)uVar1;
    pvVar4 = calloc(uVar1 & 0xffff,0x1a);
    *(void **)(param_1 + 0x156) = pvVar4;
    if (pvVar4 == (void *)0x0) {
      FUN_1c003f50(param_1,1);
      return 0x1b5a;
    }
    iVar3 = FUN_1c004a10(iVar7);
    if (iVar3 == 0) {
      FUN_1c003e40(iVar7);
      FUN_1c00c550(iVar7);
      FUN_1c005910(iVar7);
      FUN_1c00c6d0(iVar7);
      FUN_1c003de0(iVar7);
      iVar5 = FUN_1c00cc10(iVar7);
      if (iVar5 != 0) {
        FUN_1c003f50(param_1,1);
        return 0x1b5a;
      }
      FUN_1c00c8c0(iVar7);
      FUN_1c00cdc0(iVar7);
      FUN_1c00c3e0(iVar7);
      FUN_1c00f7c0(iVar7);
      local_18 = FUN_1c00c420(iVar7);
      if (local_18 == 0) {
        FUN_1c005840(iVar7);
        FUN_1c00cd40(iVar7);
        FUN_1c00de60(iVar7);
        FUN_1c00de60(iVar7);
        FUN_1c00be40(iVar7);
        FUN_1c00df10();
        *(undefined2 *)(param_1 + 0x448) = 0xff;
        *(ushort *)(param_1 + 0x44e) = (ushort)(*(short *)(param_1 + 0x44a) != 0x65);
        iVar5 = FUN_1c00f300(param_1);
        if (iVar5 != 0) {
          FUN_1c00f3d0(param_1);
          FUN_1c003f50(param_1,1);
          return iVar5;
        }
        *(undefined4 *)(param_1 + 0x298) = *(undefined4 *)(param_1 + 0xbc);
        *(undefined4 *)(param_1 + 0x2c0) = *(undefined4 *)(param_1 + 0xc4);
        FUN_1c00402c(*(undefined4 *)(param_1 + 0xc4),extraout_EDX,iVar7,0x2000);
        puVar9 = (undefined4 *)(param_1 + 0xac);
        local_c = 0;
        local_8 = 0;
        local_10 = 0;
        piVar10 = (int *)(param_1 + 0x29c);
        local_4 = puVar9;
        do {
          MVar6 = waveOutPrepareHeader(*(HWAVEOUT *)(param_1 + 8),(LPWAVEHDR)*local_4,0x20);
          if (MVar6 != 0) {
            FUN_1c00f3d0(param_1);
            if (0 < local_c) {
              do {
                pwVar2 = (LPWAVEHDR)*puVar9;
                puVar9 = puVar9 + 2;
                waveOutUnprepareHeader(*(HWAVEOUT *)(param_1 + 8),pwVar2,0x20);
                local_c = local_c + -1;
              } while (local_c != 0);
            }
            FUN_1c003f50(param_1,1);
            return 0x1b5f;
          }
          iVar7 = *(int *)(param_1 + 0x298) + local_10;
          local_c = local_c + 1;
          local_10 = local_10 + 0x1000;
          local_4 = local_4 + 2;
          *piVar10 = iVar7;
          piVar10[10] = *(int *)(param_1 + 0x2c0) + local_8;
          local_8 = local_8 + 0x2000;
          piVar10 = piVar10 + 1;
        } while (local_10 < 0x2000);
        if ((*(byte *)(param_1 + 0x188) & 0x40) == 0) {
          MVar6 = timeBeginPeriod(10);
          if (MVar6 != 0) {
            FUN_1c00f3d0(param_1);
            FUN_1c003f50(param_1,1);
            return 0x1d50;
          }
          DAT_1c0145a0 = 1;
          DAT_1c0145b4 = timeSetEvent(0x32,10,FUN_1c00f700,param_1,1);
          if (DAT_1c0145b4 == 0) {
            FUN_1c00f3d0(param_1);
            FUN_1c003f50(param_1,1);
            return 0x1b6f;
          }
        }
        iVar7 = 0;
        DVar8 = timeGetTime();
        *(DWORD *)(param_1 + 0x24) = DVar8;
        do {
          MVar6 = waveOutWrite(*(HWAVEOUT *)(param_1 + 8),(LPWAVEHDR)*puVar9,0x20);
          if (MVar6 != 0) {
            if (iVar7 < 2) {
              puVar9 = (undefined4 *)(param_1 + 0xac + iVar7 * 8);
              iVar7 = 2 - iVar7;
              do {
                pwVar2 = (LPWAVEHDR)*puVar9;
                puVar9 = puVar9 + 2;
                waveOutUnprepareHeader(*(HWAVEOUT *)(param_1 + 8),pwVar2,0x20);
                iVar7 = iVar7 + -1;
              } while (iVar7 != 0);
            }
            FUN_1c00f3d0(param_1);
            FUN_1c003f50(param_1,1);
            return 0x1b60;
          }
          puVar9 = puVar9 + 2;
          iVar7 = iVar7 + 1;
        } while (iVar7 < 2);
        pcVar11 = PostMessageA_exref;
        if ((*(byte *)(param_1 + 0x18b) & 0x80) != 0) {
          _DAT_1c012048 = param_1;
          _DAT_1c01204c = timeGetTime();
          pcVar11 = PostMessageA_exref;
          _DAT_1c012058 = *(undefined4 *)(param_1 + 200);
          PostMessageA(*(HWND *)(param_1 + 0x13e),DAT_1c0145b0,1000,0x1c012048);
          *(uint *)(param_1 + 0x188) = *(uint *)(param_1 + 0x188) ^ 0x80000000;
        }
        _DAT_1c012048 = param_1;
        _DAT_1c01204c = timeGetTime();
        _DAT_1c012058 = *(undefined4 *)(param_1 + 200);
        (*pcVar11)(*(undefined4 *)(param_1 + 0x13e),DAT_1c0145b0,0x3ea,&DAT_1c012048);
        local_18 = 0;
      }
    }
    else {
      local_18 = iVar3;
      if (iVar3 == 1000) {
        local_18 = 0;
      }
      _DAT_1c012068 = param_1;
      _DAT_1c012072 = (undefined2)local_18;
      _DAT_1c01206c = 0;
      _DAT_1c012078 = *(undefined4 *)(param_1 + 200);
      _DAT_1c012084 = *(undefined4 *)(param_1 + 0x14a);
      PostMessageA(*(HWND *)(param_1 + 0x13e),DAT_1c0145b0,0x3e9,0x1c012068);
    }
    if (((local_18 == 0) && (iVar3 != 1000)) && (iVar3 != 0x1b6d)) {
      FUN_1c003f50(param_1,0);
    }
    else {
      FUN_1c003f50(param_1,1);
    }
  }
  return local_18;
}


// ==== FUN_1c003da0 @ 1c003da0 size=50

void __cdecl FUN_1c003da0(int param_1)

{
  free(*(void **)(param_1 + 0x230));
  *(undefined4 *)(param_1 + 0x230) = 0;
  FUN_1c00f3d0(param_1);
  return;
}


// ==== FUN_1c003de0 @ 1c003de0 size=85

void __cdecl FUN_1c003de0(int param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = *(int *)(param_1 + 0x1c);
  uVar3 = *(uint *)(*(int *)(*(int *)(iVar2 + 0x70) + 0x1c) + *(short *)(iVar2 + 0x74) * 4);
  sVar1 = *(short *)(iVar2 + 0x8e);
  iVar2 = iVar2 + 0x82;
  while( true ) {
    if (sVar1 == 0xff) {
      return;
    }
    uVar4 = uVar3 & 0x4000000;
    uVar3 = *(uint *)(*(int *)(*(int *)(iVar2 + 8) + 0x1c) + *(short *)(iVar2 + 0xc) * 4);
    if (uVar4 != 0) {
      *(uint *)(iVar2 + 0x16) = *(uint *)(iVar2 + 0x16) | 0x100;
    }
    if ((uVar3 & 1) != 0) break;
    sVar1 = *(short *)(iVar2 + 0x26);
    iVar2 = iVar2 + 0x1a;
  }
  return;
}


// ==== FUN_1c003e40 @ 1c003e40 size=221

void __cdecl FUN_1c003e40(int param_1)

{
  short sVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  short *psVar6;
  int iVar7;
  int iVar8;
  
  uVar5 = *(undefined4 *)(param_1 + 0x40);
  iVar7 = *(int *)(param_1 + 0x38);
  sVar1 = *(short *)(*(undefined4 **)(param_1 + 0x1c) + 3);
  puVar2 = *(undefined4 **)(param_1 + 0x1c);
  do {
    if (sVar1 == 0xff) {
      puVar2[2] = iVar7;
      puVar2[1] = uVar5;
      return;
    }
    psVar6 = (short *)*puVar2;
    if (psVar6 != (short *)0x0) {
      sVar1 = *psVar6;
      iVar8 = DAT_1c012038;
      iVar3 = DAT_1c01203c;
      iVar4 = DAT_1c012040;
      while (DAT_1c012038 = iVar8, DAT_1c01203c = iVar3, DAT_1c012040 = iVar4, sVar1 != 0x1e) {
        if (*psVar6 == 0x41) {
          sVar1 = psVar6[1];
          if (sVar1 == 0) {
            *(int *)(param_1 + 0x3c) = iVar8;
            iVar7 = DAT_1c012038;
          }
          else if (sVar1 == 1) {
            *(int *)(param_1 + 0x3c) = iVar3;
            iVar7 = DAT_1c01203c;
            iVar8 = iVar3;
          }
          else {
            if (sVar1 != 2) goto LAB_1c003ec8;
            *(int *)(param_1 + 0x3c) = iVar4;
            iVar7 = DAT_1c012040;
            iVar8 = iVar4;
          }
          *(int *)(param_1 + 0x38) = iVar7;
          iVar7 = iVar8;
        }
LAB_1c003ec8:
        if (*psVar6 == 0x32) {
          switch(psVar6[1]) {
          case 1:
          case 3:
          case 5:
          case 0xd:
          case 0xf:
            uVar5 = *(undefined4 *)(iVar7 + 0x18);
            break;
          default:
            uVar5 = *(undefined4 *)(iVar7 + 0x14);
          }
          *(undefined4 *)(param_1 + 0x40) = uVar5;
        }
        psVar6 = psVar6 + 3;
        iVar8 = DAT_1c012038;
        iVar3 = DAT_1c01203c;
        iVar4 = DAT_1c012040;
        sVar1 = *psVar6;
      }
    }
    puVar2[2] = iVar7;
    puVar2[1] = uVar5;
    sVar1 = *(short *)((int)puVar2 + 0x26);
    puVar2 = (undefined4 *)((int)puVar2 + 0x1a);
  } while( true );
}


// ==== FUN_1c003f50 @ 1c003f50 size=219

void __cdecl FUN_1c003f50(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 == 0) {
    if (*(void **)(param_1 + 0x156) != (void *)0x0) {
      free(*(void **)(param_1 + 0x156));
    }
    if (*(HLOCAL *)(param_1 + 0x16e) != (HLOCAL)0x0) {
      LocalFree(*(HLOCAL *)(param_1 + 0x16e));
    }
    if (*(void **)(param_1 + 0x1fa) != (void *)0x0) {
      free(*(void **)(param_1 + 0x1fa));
    }
    *(undefined4 *)(param_1 + 0x16e) = 0;
    *(undefined4 *)(param_1 + 0x156) = 0;
    *(undefined4 *)(param_1 + 0x1fa) = 0;
    if (param_2 != 0) {
      if (DAT_1c0145b4 != 0) {
        timeKillEvent(DAT_1c0145b4);
        DAT_1c0145b4 = 0;
      }
      if (DAT_1c0145a0 != 0) {
        timeEndPeriod(10);
        DAT_1c0145a0 = 0;
      }
      *(undefined4 *)(param_1 + 0x1c) = 1;
      DAT_1c01208c = 0;
      FUN_1c003da0(param_1);
      waveOutClose(*(HWAVEOUT *)(param_1 + 8));
    }
  }
  return;
}


// ==== FUN_1c00402c @ 1c00402c size=2386

undefined8 __fastcall
FUN_1c00402c(undefined4 param_1,undefined4 param_2,int param_3,undefined2 param_4)

{
  byte bVar1;
  short *psVar2;
  int iVar3;
  undefined2 uVar4;
  short sVar5;
  short sVar6;
  undefined4 in_EAX;
  undefined2 uVar7;
  short sVar8;
  short sVar9;
  uint uVar10;
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint extraout_ECX_01;
  uint extraout_ECX_02;
  undefined2 extraout_var;
  ushort uVar11;
  byte *pbVar12;
  char *pcVar13;
  int iVar14;
  int iVar15;
  undefined2 uStack_26;
  
  *(undefined2 *)(param_3 + 0x2f4) = param_4;
  pcVar13 = *(char **)(param_3 + 0x15e);
  if (*(short *)(param_3 + 0x30e) == 0) goto LAB_1c0044a0;
  *(undefined2 *)(param_3 + 0x30e) = 0;
  *(undefined4 *)(param_3 + 0x1b2) = 0;
  *(undefined4 *)(param_3 + 0x1c6) = 0;
  *(undefined4 *)(param_3 + 0x1da) = 0;
  *(undefined4 *)(param_3 + 0x1ee) = 0;
  *(undefined4 *)(param_3 + 0x202) = 0;
  *(undefined4 *)(param_3 + 0x216) = 0;
  *(undefined4 *)(param_3 + 0x22a) = 0;
  *(undefined4 *)(param_3 + 0x23e) = 0;
  *(undefined4 *)(param_3 + 0x252) = 0;
  *(undefined4 *)(param_3 + 0x28a) = 0;
  *(undefined4 *)(param_3 + 0x282) = 0;
  *(undefined4 *)(param_3 + 0x292) = 0;
  *(undefined4 *)(param_3 + 0x2aa) = 0;
  *(undefined4 *)(param_3 + 0x2fc) = 0;
  *(undefined2 *)(param_3 + 0x2ee) = 0x3ff;
  *(undefined4 *)(param_3 + 0x300) = 0x20000;
  *(int *)(param_3 + 0xfa) = *(int *)(param_3 + 0xf6) + 0x80;
  *(undefined4 *)(param_3 + 0xfe) = 0x40;
  *(undefined2 **)(param_3 + 0x2e4) = &DAT_1c001570;
  *(undefined4 *)(param_3 + 0x2e8) = *(undefined4 *)(param_3 + 0x2c0);
  while( true ) {
    uVar4 = SUB42(pcVar13,0);
    uStack_26 = (undefined2)((uint)pcVar13 >> 0x10);
    iVar3 = *(int *)(param_3 + 0xfa);
    pbVar12 = (byte *)(iVar3 + 0x20);
    if (((*pbVar12 == 0xff) || (*(char *)(iVar3 + -0x15) == '\x01')) ||
       (*(char *)(iVar3 + -0x15) == '\x02')) break;
    *(byte **)(param_3 + 0xfa) = pbVar12;
    *(ushort *)(param_3 + 700) =
         (ushort)((((*(uint *)(param_3 + 0x48) & 0xffff) * (uint)DAT_1c0120e8) / (uint)DAT_1c0120ea
                  & 0xffff) / ((uint)*(byte *)(iVar3 + 0x2a) << 1)) >> 1;
    *(short *)(param_3 + 0x2fa) = (short)(0x10000 / (int)*(short *)(param_3 + 700));
    if ((*(uint *)(param_3 + 0x4e) & 0x40) == 0) {
      uVar10 = 0;
      if ((*(uint *)(param_3 + 0x4e) & 8) != 0) {
        bVar1 = *(byte *)(iVar3 + 0x3a);
        uVar10 = (uint)(ushort)bVar1;
        if (bVar1 != *(byte *)(param_3 + 0x312)) {
          *(byte *)(param_3 + 0x312) = bVar1;
          FUN_1c00498f(0x3f0,CONCAT26(uVar4,(uint6)CONCAT12(bVar1,(ushort)bVar1)));
          uVar10 = extraout_ECX;
        }
      }
      if (((*(uint *)(param_3 + 0x4e) & 4) != 0) && ((*(byte *)(iVar3 + 0x37) & 1) != 0)) {
        FUN_1c00498f(0x3ee,CONCAT26(uVar4,CONCAT42(CONCAT22((short)(uVar10 >> 0x10),
                                                            (ushort)*(byte *)(iVar3 + 0x2b)),
                                                   (ushort)*(byte *)(iVar3 + 0x2b))));
        uVar10 = extraout_ECX_00;
      }
      if (((*(uint *)(param_3 + 0x4e) & 2) != 0) && ((*(byte *)(iVar3 + 0x37) & 4) != 0)) {
        FUN_1c00498f(0x3ed,CONCAT26(uVar4,CONCAT42(uVar10,(short)uVar10)));
        uVar10 = extraout_ECX_01;
      }
      if (((*(uint *)(param_3 + 0x4e) & 1) != 0) && ((*(byte *)(iVar3 + 0x37) & 2) != 0)) {
        FUN_1c00498f(0x3ec,CONCAT26(uVar4,CONCAT42(uVar10,(short)uVar10)));
        uVar10 = extraout_ECX_02;
      }
      uVar7 = (undefined2)(uVar10 >> 0x10);
      if ((*(byte *)(iVar3 + 0x37) & 8) != 0) {
        FUN_1c00498f(0x3ef,CONCAT26(uVar4,CONCAT42(CONCAT22(uVar7,(ushort)*(byte *)(iVar3 + 0x3b)),
                                                   (ushort)*(byte *)(iVar3 + 0x3b))));
        uVar7 = extraout_var;
      }
      if ((*(byte *)(iVar3 + 0x37) & 0x20) != 0) {
        FUN_1c00498f(0x3eb,CONCAT26(uVar4,CONCAT42(CONCAT22(uVar7,*(undefined2 *)(iVar3 + 0x3c)),
                                                   *(undefined2 *)(iVar3 + 0x3c))));
      }
    }
    *(int *)(param_3 + 0xfe) =
         *(int *)(param_3 + 0xfe) +
         (int)(short)(((uint)*(ushort *)(param_3 + 700) * 64000) / (uint)*(ushort *)(param_3 + 0x48)
                     );
    iVar14 = (*(byte *)(iVar3 + 0x27) & 0xf) * 2;
    iVar15 = (int)(short)(*(short *)(&DAT_1c0036b0 + iVar14) - *(short *)(param_3 + 0x244)) *
             (int)*(short *)(param_3 + 0x2fa);
    *(short *)(param_3 + 0x246) = (short)iVar15;
    *(short *)(param_3 + 0x248) = (short)((uint)iVar15 >> 0x10);
    iVar15 = (int)(short)(*(short *)(&DAT_1c0036d0 + iVar14) - *(short *)(param_3 + 0x24c)) *
             (int)*(short *)(param_3 + 0x2fa);
    *(short *)(param_3 + 0x24e) = (short)iVar15;
    *(short *)(param_3 + 0x250) = (short)((uint)iVar15 >> 0x10);
    *(uint *)(param_3 + 0x300) = (uint)*(ushort *)(iVar3 + 0x38) << 9;
    bVar1 = *(byte *)(iVar3 + 0x26);
    iVar14 = (uint)(bVar1 >> 4) * 2;
    iVar15 = (int)(short)(*(short *)(&DAT_1c003070 + iVar14) - *(short *)(param_3 + 0x1c0)) *
             (int)*(short *)(param_3 + 0x2fa);
    *(short *)(param_3 + 0x1c2) = (short)iVar15;
    *(short *)(param_3 + 0x1c4) = (short)((uint)iVar15 >> 0x10);
    iVar15 = (int)(short)(*(short *)(&DAT_1c002570 +
                                    (ushort)((ushort)iVar14 | (ushort)*pbVar12 << 5)) -
                         *(short *)(param_3 + 0x1b8)) * (int)*(short *)(param_3 + 0x2fa);
    *(short *)(param_3 + 0x1ba) = (short)iVar15;
    *(short *)(param_3 + 0x1bc) = (short)((uint)iVar15 >> 0x10);
    iVar14 = (bVar1 & 0xf) * 2;
    iVar15 = (int)(short)(*(short *)(&DAT_1c003070 + iVar14) - *(short *)(param_3 + 0x1d4)) *
             (int)*(short *)(param_3 + 0x2fa);
    *(short *)(param_3 + 0x1d6) = (short)iVar15;
    *(short *)(param_3 + 0x1d8) = (short)((uint)iVar15 >> 0x10);
    iVar15 = (int)(short)(*(short *)(&DAT_1c002570 +
                                    (ushort)((ushort)iVar14 | (ushort)*(byte *)(iVar3 + 0x21) << 5))
                         - *(short *)(param_3 + 0x1cc)) * (int)*(short *)(param_3 + 0x2fa);
    *(short *)(param_3 + 0x1ce) = (short)iVar15;
    *(short *)(param_3 + 0x1d0) = (short)((uint)iVar15 >> 0x10);
    iVar14 = (uint)(*(byte *)(iVar3 + 0x27) >> 4) * 2;
    iVar15 = (int)(short)(*(short *)(&DAT_1c003070 + iVar14) - *(short *)(param_3 + 0x1e8)) *
             (int)*(short *)(param_3 + 0x2fa);
    *(short *)(param_3 + 0x1ea) = (short)iVar15;
    *(short *)(param_3 + 0x1ec) = (short)((uint)iVar15 >> 0x10);
    iVar15 = (int)(short)(*(short *)(&DAT_1c002570 +
                                    (ushort)((ushort)iVar14 | (ushort)*(byte *)(iVar3 + 0x22) << 5))
                         - *(short *)(param_3 + 0x1e0)) * (int)*(short *)(param_3 + 0x2fa);
    *(short *)(param_3 + 0x1e2) = (short)iVar15;
    *(short *)(param_3 + 0x1e4) = (short)((uint)iVar15 >> 0x10);
    bVar1 = *(byte *)(iVar3 + 0x28);
    iVar15 = (uint)(bVar1 >> 4) * 2;
    *(uint *)(param_3 + 0x1fa) = (uint)*(ushort *)(&DAT_1c003690 + iVar15) << 0x10;
    *(uint *)(param_3 + 0x1f2) =
         (uint)*(ushort *)
                (&DAT_1c003090 + (ushort)((ushort)iVar15 | (ushort)*(byte *)(iVar3 + 0x23) << 5)) <<
         0x10;
    iVar15 = (bVar1 & 0xf) * 2;
    *(uint *)(param_3 + 0x20e) = (uint)*(ushort *)(&DAT_1c003690 + iVar15) << 0x10;
    *(uint *)(param_3 + 0x206) =
         (uint)*(ushort *)
                (&DAT_1c003090 + (ushort)((ushort)iVar15 | (ushort)*(byte *)(iVar3 + 0x24) << 5)) <<
         0x10;
    iVar15 = (uint)(*(byte *)(iVar3 + 0x34) >> 4) * 2;
    *(uint *)(param_3 + 0x222) = (uint)*(ushort *)(&DAT_1c003690 + iVar15) << 0x10;
    *(uint *)(param_3 + 0x21a) =
         (uint)*(ushort *)
                (&DAT_1c003090 + (ushort)((ushort)iVar15 | (ushort)*(byte *)(iVar3 + 0x29) << 5)) <<
         0x10;
    bVar1 = *(byte *)(iVar3 + 0x2f);
    *(ushort *)(param_3 + 0x268) = (ushort)bVar1 * 0x80;
    *(ushort *)(param_3 + 0x270) = (ushort)bVar1 * -0x80 + 0x7f80;
    iVar15 = (int)(short)(*(short *)(&DAT_1c001308 + *(byte *)(iVar3 + 0x30)) -
                         *(short *)(param_3 + 0x278)) * (int)*(short *)(param_3 + 0x2fa);
    *(short *)(param_3 + 0x27a) = (short)iVar15;
    *(short *)(param_3 + 0x27c) = (short)((uint)iVar15 >> 0x10);
    iVar15 = (uint)*(ushort *)(&DAT_1c001308 + *(byte *)(iVar3 + 0x31)) << 0x10;
    *(int *)(param_3 + 0x27e) = iVar15;
    *(int *)(param_3 + 0x296) = iVar15;
    *(int *)(param_3 + 0x29a) = iVar15;
    iVar15 = (uint)*(ushort *)(&DAT_1c001308 + *(byte *)(iVar3 + 0x32)) << 0x10;
    *(int *)(param_3 + 0x286) = iVar15;
    *(int *)(param_3 + 0x29e) = iVar15;
    *(int *)(param_3 + 0x2a2) = iVar15;
    *(uint *)(param_3 + 0x28e) =
         (uint)(ushort)(0x101d - *(short *)(&DAT_1c001308 + *(byte *)(iVar3 + 0x33))) << 0x10;
    if (0x3b < *(byte *)(iVar3 + 0x30)) {
      *(uint *)(param_3 + 0x29a) = *(uint *)(param_3 + 0x296) >> 3;
      *(uint *)(param_3 + 0x2a2) = *(uint *)(param_3 + 0x29e) >> 4;
    }
    if ((((*(byte *)(iVar3 + 0x30) < 0xf) && (*(byte *)(iVar3 + 0x31) < 0xf)) &&
        (*(byte *)(iVar3 + 0x10) < 0xf)) && (*(byte *)(iVar3 + 0x11) < 0xf)) {
      *(undefined4 *)(param_3 + 0x1b2) = 0;
      *(undefined4 *)(param_3 + 0x1c6) = 0;
      *(undefined4 *)(param_3 + 0x1da) = 0;
      *(undefined4 *)(param_3 + 0x1ee) = 0;
      *(undefined4 *)(param_3 + 0x23e) = 0;
    }
    *(undefined **)(param_3 + 0x2d8) = (&PTR_DAT_1c013bd0)[*(byte *)(iVar3 + 0x2d)];
    *(undefined **)(param_3 + 0x2dc) = (&PTR_DAT_1c013bd0)[*(byte *)(iVar3 + 0x2e)];
    pcVar13 = (char *)CONCAT22(uStack_26,uVar4);
    *(undefined2 *)(param_3 + 0x30c) = *(undefined2 *)(param_3 + 700);
    do {
      uVar10 = *(int *)(param_3 + 0x2fc) + *(int *)(param_3 + 0x300) & 0x3ffffff;
      *(uint *)(param_3 + 0x2fc) = uVar10;
      iVar3 = (int)*(short *)(*(int *)(param_3 + 0x2d8) + (uVar10 >> 0x10) * 2) *
              (int)*(short *)(param_3 + 0x268);
      iVar15 = (int)*(short *)(*(int *)(param_3 + 0x2dc) + (*(uint *)(param_3 + 0x2fc) >> 0x10) * 2)
               * (int)*(short *)(param_3 + 0x270);
      iVar3 = (int)(short)(((short)((uint)iVar3 >> 0x10) << 1 | (ushort)iVar3 >> 0xf) +
                          ((short)((uint)iVar15 >> 0x10) << 1 | (ushort)iVar15 >> 0xf)) *
              (int)*(short *)(param_3 + 0x278);
      uVar11 = (short)((uint)iVar3 >> 0x10) << 1 | (ushort)iVar3 >> 0xf;
      *(int *)(param_3 + 0x276) = *(int *)(param_3 + 0x276) + *(int *)(param_3 + 0x27a);
      if ((short)uVar11 < 0) {
        uVar4 = *(undefined2 *)(param_3 + 0x298);
        uVar7 = *(undefined2 *)(param_3 + 0x2a0);
      }
      else {
        uVar4 = *(undefined2 *)(param_3 + 0x29c);
        uVar7 = *(undefined2 *)(param_3 + 0x2a4);
      }
      *(undefined2 *)(param_3 + 0x280) = uVar4;
      *(undefined2 *)(param_3 + 0x288) = uVar7;
      iVar15 = (uint)uVar11 * 0x10000;
      LOCK();
      iVar3 = *(int *)(param_3 + 0x2aa);
      *(int *)(param_3 + 0x2aa) = iVar15;
      UNLOCK();
      sVar6 = (short)((iVar15 - iVar3 & 0x7fffffffU) >> 0xf);
      sVar8 = (short)*(undefined4 *)(param_3 + 0x23e);
      *(short *)(param_3 + 0x240) = sVar8;
      iVar3 = (int)(short)(sVar8 - sVar6) * (int)*(short *)(param_3 + 0x244);
      iVar15 = (int)(short)((short)((uint)*(undefined4 *)(param_3 + 0x23e) >> 0x10) - sVar6) *
               (int)*(short *)(param_3 + 0x24c);
      sVar8 = (sVar6 - ((short)((uint)iVar15 >> 0x10) << 1 | (ushort)iVar15 >> 0xf)) +
              ((short)((uint)iVar3 >> 0x10) << 2 | (ushort)iVar3 >> 0xe);
      *(short *)(param_3 + 0x23e) = sVar8;
      *(int *)(param_3 + 0x242) = *(int *)(param_3 + 0x242) + *(int *)(param_3 + 0x246);
      *(int *)(param_3 + 0x24a) = *(int *)(param_3 + 0x24a) + *(int *)(param_3 + 0x24e);
      psVar2 = *(short **)(param_3 + 0x2e4);
      iVar3 = (int)*psVar2 * (int)*(short *)(param_3 + 0x280);
      sVar8 = sVar8 + ((short)((uint)iVar3 >> 0x10) << 1 | (ushort)iVar3 >> 0xf);
      sVar6 = (short)*(undefined4 *)(param_3 + 0x202);
      *(short *)(param_3 + 0x204) = sVar6;
      iVar3 = (int)(short)(sVar6 - sVar8) * (int)*(short *)(param_3 + 0x208);
      iVar15 = (int)(short)((short)((uint)*(undefined4 *)(param_3 + 0x202) >> 0x10) - sVar8) *
               (int)*(short *)(param_3 + 0x210);
      sVar8 = (sVar8 - ((short)((uint)iVar15 >> 0x10) << 1 | (ushort)iVar15 >> 0xf)) +
              ((short)((uint)iVar3 >> 0x10) << 2 | (ushort)iVar3 >> 0xe);
      *(short *)(param_3 + 0x202) = sVar8;
      sVar6 = (short)*(undefined4 *)(param_3 + 0x1b2);
      *(short *)(param_3 + 0x1b4) = sVar6;
      iVar3 = (int)(short)(sVar6 - sVar8) * (int)*(short *)(param_3 + 0x1b8);
      iVar15 = (int)(short)((short)((uint)*(undefined4 *)(param_3 + 0x1b2) >> 0x10) - sVar8) *
               (int)*(short *)(param_3 + 0x1c0);
      sVar8 = (sVar8 - ((short)((uint)iVar15 >> 0x10) << 1 | (ushort)iVar15 >> 0xf)) +
              ((short)((uint)iVar3 >> 0x10) << 2 | (ushort)iVar3 >> 0xe);
      *(short *)(param_3 + 0x1b2) = sVar8;
      *(int *)(param_3 + 0x1b6) = *(int *)(param_3 + 0x1b6) + *(int *)(param_3 + 0x1ba);
      *(int *)(param_3 + 0x1be) = *(int *)(param_3 + 0x1be) + *(int *)(param_3 + 0x1c2);
      sVar6 = (short)*(undefined4 *)(param_3 + 0x1da);
      *(short *)(param_3 + 0x1dc) = sVar6;
      iVar3 = (int)(short)(sVar6 - sVar8) * (int)*(short *)(param_3 + 0x1e0);
      iVar15 = (int)(short)((short)((uint)*(undefined4 *)(param_3 + 0x1da) >> 0x10) - sVar8) *
               (int)*(short *)(param_3 + 0x1e8);
      sVar8 = (sVar8 - ((short)((uint)iVar15 >> 0x10) << 1 | (ushort)iVar15 >> 0xf)) +
              ((short)((uint)iVar3 >> 0x10) << 2 | (ushort)iVar3 >> 0xe);
      *(short *)(param_3 + 0x1da) = sVar8;
      *(int *)(param_3 + 0x1de) = *(int *)(param_3 + 0x1de) + *(int *)(param_3 + 0x1e2);
      *(int *)(param_3 + 0x1e6) = *(int *)(param_3 + 0x1e6) + *(int *)(param_3 + 0x1ea);
      sVar6 = (short)*(undefined4 *)(param_3 + 0x1ee);
      *(short *)(param_3 + 0x1f0) = sVar6;
      iVar3 = (int)(short)(sVar6 - sVar8) * (int)*(short *)(param_3 + 500);
      iVar15 = (int)(short)((short)((uint)*(undefined4 *)(param_3 + 0x1ee) >> 0x10) - sVar8) *
               (int)*(short *)(param_3 + 0x1fc);
      sVar8 = (sVar8 - ((short)((uint)iVar15 >> 0x10) << 1 | (ushort)iVar15 >> 0xf)) +
              ((short)((uint)iVar3 >> 0x10) << 2 | (ushort)iVar3 >> 0xe);
      *(short *)(param_3 + 0x1ee) = sVar8;
      sVar6 = (short)*(undefined4 *)(param_3 + 0x1c6);
      *(short *)(param_3 + 0x1c8) = sVar6;
      iVar3 = (int)(short)(sVar6 - sVar8) * (int)*(short *)(param_3 + 0x1cc);
      iVar15 = (int)(short)((short)((uint)*(undefined4 *)(param_3 + 0x1c6) >> 0x10) - sVar8) *
               (int)*(short *)(param_3 + 0x1d4);
      sVar9 = (sVar8 - ((short)((uint)iVar15 >> 0x10) << 1 | (ushort)iVar15 >> 0xf)) +
              ((short)((uint)iVar3 >> 0x10) << 2 | (ushort)iVar3 >> 0xe);
      *(short *)(param_3 + 0x1c6) = sVar9;
      *(int *)(param_3 + 0x1ca) = *(int *)(param_3 + 0x1ca) + *(int *)(param_3 + 0x1ce);
      *(int *)(param_3 + 0x1d2) = *(int *)(param_3 + 0x1d2) + *(int *)(param_3 + 0x1d6);
      sVar6 = psVar2[1];
      *(short **)(param_3 + 0x2e4) = psVar2 + 2;
      sVar8 = sVar6 >> 2;
      sVar5 = (short)*(undefined4 *)(param_3 + 0x216);
      *(short *)(param_3 + 0x218) = sVar5;
      iVar3 = (int)(short)(sVar5 - sVar8) * (int)*(short *)(param_3 + 0x21c);
      iVar15 = (int)(short)((short)((uint)*(undefined4 *)(param_3 + 0x216) >> 0x10) - sVar8) *
               (int)*(short *)(param_3 + 0x224);
      sVar8 = (sVar8 - ((short)((uint)iVar15 >> 0x10) << 1 | (ushort)iVar15 >> 0xf)) +
              ((short)((uint)iVar3 >> 0x10) << 2 | (ushort)iVar3 >> 0xe);
      *(short *)(param_3 + 0x216) = sVar8;
      iVar3 = (int)sVar8 * (int)*(short *)(param_3 + 0x290);
      iVar3 = (int)(short)(((short)((uint)iVar3 >> 0x10) << 1 | (ushort)iVar3 >> 0xf) - (sVar6 >> 7)
                          ) * (int)*(short *)(param_3 + 0x288);
      uVar11 = (ushort)iVar3;
      sVar6 = (short)(sVar9 + (((short)((uint)iVar3 >> 0x10) << 1 | uVar11 >> 0xf) << 3 |
                              uVar11 >> 0xd)) >> 5;
      if (sVar6 < -199) {
        sVar6 = -200;
      }
      else if (199 < sVar6) {
        sVar6 = 200;
      }
      *pcVar13 = (char)*(undefined2 *)(&DAT_1c0011c6 + sVar6) + -0x80;
      psVar2 = (short *)(param_3 + 0x2f4);
      *psVar2 = *psVar2 + -1;
      pcVar13 = pcVar13 + 1;
      if (*psVar2 == 0) goto LAB_1c004985;
LAB_1c0044a0:
      psVar2 = (short *)(param_3 + 0x2ee);
      *psVar2 = *psVar2 + -1;
      if (*psVar2 == 0) {
        *(undefined2 *)(param_3 + 0x2ee) = 0x3ff;
        *(undefined2 **)(param_3 + 0x2e4) = &DAT_1c001570;
      }
      psVar2 = (short *)(param_3 + 0x30c);
      *psVar2 = *psVar2 + -1;
    } while (*psVar2 != 0);
  }
  for (uVar10 = (uint)*(ushort *)(param_3 + 0x2f4); uVar10 != 0; uVar10 = uVar10 - 1) {
    *pcVar13 = -0x80;
    pcVar13 = pcVar13 + 1;
  }
  *(undefined2 *)(param_3 + 0x314) = 0;
LAB_1c004985:
  return CONCAT44(param_2,in_EAX);
}


// ==== FUN_1c00498f @ 1c00498f size=120

void __cdecl FUN_1c00498f(undefined2 param_1,undefined8 param_2)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  uint uVar4;
  int *unaff_EBX;
  undefined1 *puVar5;
  int *piVar6;
  
  iVar2 = *unaff_EBX;
  puVar3 = *(ushort **)(iVar2 + 0xa4);
  uVar1 = *puVar3;
  uVar4 = (uint)uVar1;
  *puVar3 = *puVar3 + 1;
  if (0x62 < uVar4) {
    *puVar3 = 0;
  }
  puVar5 = (undefined1 *)((int)puVar3 + uVar4 + 0xc84);
  *puVar5 = 1;
  piVar6 = (int *)(puVar5 + (uint)(ushort)(uVar1 * 0x20) + (-0xc80 - uVar4));
  *piVar6 = iVar2;
  *(undefined2 *)(piVar6 + 2) = param_1;
  piVar6[1] = *(uint *)((int)unaff_EBX + 0xfe) >> 6;
  *(undefined2 *)((int)piVar6 + 10) = (undefined2)param_2;
  piVar6[3] = param_2._2_4_;
  piVar6[5] = unaff_EBX[2];
  piVar6[4] = *(int *)(iVar2 + 200);
  return;
}


// ==== FUN_1c004a10 @ 1c004a10 size=1836

int __cdecl FUN_1c004a10(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  bool bVar5;
  ushort uVar6;
  short *psVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  byte *pbVar12;
  byte *pbVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  short *psVar16;
  short *psVar17;
  bool bVar18;
  byte local_21;
  undefined4 local_20;
  byte *local_1c;
  short *local_18;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  uint local_4;
  
  iVar11 = 10;
  pbVar12 = *(byte **)(param_1 + 8);
  iVar4 = *(int *)(param_1 + 0x1c);
  DAT_1c014598 = *(int *)(param_1 + 0x38);
  local_21 = *pbVar12;
  local_1c = pbVar12;
  while (local_21 != 0) {
    local_1c = local_1c + 1;
    if (local_21 == 0x3b) {
      iVar11 = iVar11 + 1;
    }
    if (local_21 == 0x7d) {
      iVar11 = iVar11 + 2;
    }
    if (local_21 == 0x2a) {
      iVar11 = iVar11 + 2;
      pbVar13 = local_1c;
      do {
        local_1c = pbVar13;
        local_21 = *local_1c;
        pbVar13 = local_1c + 1;
      } while (local_21 == 0x2a);
    }
    if (local_21 == 0x40) {
      iVar11 = iVar11 + 2;
    }
    local_21 = *local_1c;
  }
  local_1c = pbVar12;
  psVar7 = LocalAlloc(0x40,iVar11 * 6);
  *(short **)(param_1 + 0x34) = psVar7;
  if (psVar7 == (short *)0x0) {
    return 0x1b5a;
  }
  *(undefined2 *)(iVar4 + 0xc) = 0;
  *(undefined4 *)(iVar4 + 0x12) = *(undefined4 *)(*(int *)(param_1 + 0x40) + 2);
  *(int *)(iVar4 + 8) = DAT_1c014598;
  *(undefined4 *)(iVar4 + 4) = *(undefined4 *)(param_1 + 0x40);
  *(undefined2 *)(iVar4 + 0x26) = 0;
  *(undefined4 *)(iVar4 + 0x2c) = *(undefined4 *)(*(int *)(param_1 + 0x40) + 2);
  *(int *)(iVar4 + 0x22) = DAT_1c014598;
  *(undefined4 *)(iVar4 + 0x1e) = *(undefined4 *)(param_1 + 0x40);
  *(undefined2 *)(iVar4 + 0x40) = 0x1b;
  *(undefined4 *)(iVar4 + 0x46) = *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x2c0);
  *(undefined2 *)(iVar4 + 0x42) = 0x50;
  *(int *)(iVar4 + 0x3c) = DAT_1c014598;
  *(undefined4 *)(iVar4 + 0x38) = *(undefined4 *)(param_1 + 0x40);
  *(undefined2 *)(iVar4 + 0x5a) = 0x1b;
  *(undefined4 *)(iVar4 + 0x60) = *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x2c0);
  *(undefined2 *)(iVar4 + 0x5c) = 0x50;
  *(int *)(iVar4 + 0x56) = DAT_1c014598;
  *(undefined4 *)(iVar4 + 0x52) = *(undefined4 *)(param_1 + 0x40);
  *(undefined2 *)(iVar4 + 0x74) = 0;
  puVar14 = (undefined4 *)(iVar4 + 0x82);
  local_10 = 0;
  *(undefined4 *)(iVar4 + 0x7a) = *(undefined4 *)(*(int *)(param_1 + 0x40) + 2);
  *(int *)(iVar4 + 0x70) = DAT_1c014598;
  *(undefined4 *)(iVar4 + 0x6c) = *(undefined4 *)(param_1 + 0x40);
  *(undefined2 *)(param_1 + 0xe) = 5;
  time((time_t *)&DAT_1c014594);
  DAT_1c01459c = (int)localtime((time_t *)&DAT_1c014594);
  local_21 = *local_1c;
  local_20 = (uint)(ushort)local_20;
  local_1c = local_1c + 1;
  local_18 = (short *)0x0;
  local_8 = 0;
  local_4 = (uint)(0x270f000c <
                  (uint)(((tm *)DAT_1c01459c)->tm_year << 0x10 | ((tm *)DAT_1c01459c)->tm_mon));
  local_14 = *(int *)(param_1 + 0x14);
  uVar8 = local_c;
joined_r0x1c004bea:
  if (0 < local_14) {
    if (local_21 == 0x7b) {
      if ((*(byte *)(param_1 + 0x4e) & 0x80) != 0) {
        local_14 = local_14 + -1;
        local_21 = 0x7b;
        do {
          if (local_21 == 0x7d) break;
          local_21 = *local_1c;
          local_1c = local_1c + 1;
          local_14 = local_14 + -1;
        } while (local_21 != 0);
        if (local_14 < 1) goto LAB_1c00504a;
        local_21 = *local_1c;
        local_1c = local_1c + 1;
        goto joined_r0x1c004bea;
      }
      if (local_18 == (short *)0x0) {
        local_18 = psVar7;
      }
      psVar7 = FUN_1c005180((int *)&local_1c,psVar7,&local_21,&local_14);
      if (psVar7 == (short *)0x0) {
        local_10 = 0x1b67;
        goto LAB_1c00504a;
      }
      if (local_14 == 0) goto LAB_1c00504a;
    }
    uVar8 = (int)(char)local_21 - 0x20;
    if (((int)uVar8 < 0) || (0x3b < uVar8)) {
      uVar8 = 1;
    }
    pbVar12 = (&PTR_DAT_1c012a68)[uVar8];
    bVar1 = *local_1c;
    local_c = CONCAT31(local_c._1_3_,bVar1);
    if (bVar1 == 0x48) {
      bVar5 = false;
      bVar18 = true;
      pbVar13 = local_1c;
      while (bVar18) {
        pbVar13 = pbVar13 + 1;
        bVar5 = !bVar5;
        bVar18 = *pbVar13 == 0x48;
      }
    }
    else {
      bVar5 = true;
    }
    bVar2 = *pbVar12;
    bVar3 = bVar2;
    while (((!bVar5 - 1U & bVar1) != bVar3 && (*pbVar12 != 0))) {
      pbVar12 = pbVar12 + 2;
      bVar3 = *pbVar12;
    }
    uVar8 = (uint)pbVar12[1];
    if (uVar8 == 0xff) {
      if (bVar2 != 0) {
        local_1c = local_1c + 1;
      }
      local_10 = 0x1b59;
      local_14 = 0;
      uVar8 = 8;
    }
    else {
      if (*pbVar12 != 0) {
        local_1c = local_1c + 1;
        local_14 = local_14 + -1;
      }
      local_21 = *local_1c;
      local_1c = local_1c + 1;
      local_14 = local_14 + -1;
    }
    bVar5 = true;
    if ((*(uint *)(*(int *)(DAT_1c014598 + 0x1c) + uVar8 * 4) & 0x40000200) != 0) {
      if ((*(byte *)(*(int *)(*(int *)((int)puVar14 + -0x12) + 0x1c) + 3 +
                    *(short *)((int)puVar14 + -0xe) * 4) & 0x10) == 0) {
        bVar5 = false;
        local_1c = local_1c + -1;
        local_10 = 0x1b59;
        local_21 = 0;
      }
      else {
        if (uVar8 == 0x68) {
          *(undefined2 *)((int)puVar14 + -10) = 5;
        }
        else if (uVar8 == 0x69) {
          *(ushort *)((int)puVar14 + -10) = 2;
        }
        else {
          *(ushort *)((int)puVar14 + -10) = (short)uVar8 - 0x5eU & 0xff;
        }
        if (*(short *)((int)puVar14 + -10) != 0) {
          puVar14[-1] = puVar14[-1] | 0x30;
        }
        bVar5 = false;
      }
    }
    if (uVar8 == 0x6a) {
      if ((*(byte *)(param_1 + 0x4e) & 0x80) == 0) {
        local_20 = CONCAT22(local_20._2_2_ + 1,(ushort)local_20);
      }
      bVar5 = false;
    }
    if (uVar8 == 0x6b) {
      uVar6 = FUN_1c0056e0(local_1c + -1);
      local_20 = CONCAT22(local_20._2_2_,uVar6);
      if (uVar6 == 0xffff8000) {
        local_10 = 0x1b67;
        goto LAB_1c00504a;
      }
      do {
        local_21 = *local_1c;
        local_1c = local_1c + 1;
        if (local_21 == 0) break;
        local_14 = local_14 + -1;
        piVar9 = (int *)__p___mb_cur_max();
        if (*piVar9 < 2) {
          piVar9 = (int *)__p__pctype();
          uVar10 = *(ushort *)(*piVar9 + (uint)local_21 * 2) & 4;
        }
        else {
          uVar10 = _isctype((uint)local_21,4);
        }
      } while (uVar10 != 0);
      local_8 = 1;
      bVar5 = false;
    }
    if ((*(byte *)(*(int *)(DAT_1c014598 + 0x1c) + 3 + uVar8 * 4) & 4) != 0) {
      if (*(short *)(param_1 + 0xe) == 4) {
LAB_1c004e80:
        bVar5 = false;
      }
      else if ((*(byte *)(*(int *)(*(int *)((int)puVar14 + -0x12) + 0x1c) + 3 +
                         *(short *)((int)puVar14 + -0xe) * 4) & 4) != 0) {
        if (uVar8 == 0) goto LAB_1c004e80;
        *(short *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + -1;
        puVar14 = (undefined4 *)((int)puVar14 + -0x1a);
        bVar5 = true;
      }
    }
    if (uVar8 == 5) {
      *(uint *)((int)puVar14 + 0x16) = *(uint *)((int)puVar14 + 0x16) | 0x800;
LAB_1c004ec0:
      bVar5 = false;
    }
    else if (uVar8 == 6) {
      if ((*(byte *)(*(int *)(*(int *)((int)puVar14 + -0x12) + 0x1c) + 3 +
                    *(short *)((int)puVar14 + -0xe) * 4) & 4) == 0) {
        puVar14[-1] = puVar14[-1] | 0x1000;
      }
      else if (*(short *)((int)puVar14 + -0xe) == 0) {
        *(uint *)((int)puVar14 + -0x1e) = *(uint *)((int)puVar14 + -0x1e) | 0x1000;
      }
      goto LAB_1c004ec0;
    }
    if ((((*(int *)(DAT_1c014598 + 0x10) == 1) && (uVar8 == 0x36)) && (local_18 == (short *)0x0)) &&
       (local_20._2_2_ == 0)) {
      switch(*(undefined2 *)((int)puVar14 + -0xe)) {
      case 9:
        uVar8 = 0x2b;
        break;
      case 0xd:
        uVar8 = 0x2d;
        break;
      case 0x11:
        uVar8 = 0x2f;
        break;
      case 0x27:
        uVar8 = 0x31;
        break;
      case 0x29:
        uVar8 = 0x33;
      }
      local_c = 0x36;
      if (uVar8 != 0x36) {
        *(short *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + -1;
        puVar15 = (undefined4 *)((int)puVar14 + -0x1a);
        puVar14 = (undefined4 *)((int)puVar14 + -0x1a);
        if ((short *)*puVar15 != (short *)0x0) {
          psVar7 = psVar7 + -3;
          local_18 = (short *)*puVar15;
        }
      }
    }
    else if (uVar8 == 0x5c) {
      uVar8 = 0x27;
    }
    if (local_4 != 0) {
      bVar5 = false;
    }
    if (bVar5) {
      *(short *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + 1;
      *(short *)(puVar14 + 3) = (short)uVar8;
      *(undefined4 *)((int)puVar14 + 0x12) =
           *(undefined4 *)(uVar8 * 0x1a + 2 + *(int *)(param_1 + 0x40));
      puVar14[2] = DAT_1c014598;
      puVar14[1] = *(undefined4 *)(param_1 + 0x40);
      if (uVar8 != 0) {
        psVar16 = psVar7;
        if (local_20._2_2_ != 0) {
          if (local_18 == (short *)0x0) {
            local_18 = psVar7;
          }
          if (psVar7 != (short *)0x0) {
            *psVar7 = 700;
            psVar16 = psVar7 + 3;
            psVar7[1] = local_20._2_2_;
            psVar7[2] = 0;
          }
          *(uint *)((int)puVar14 + 0x16) = *(uint *)((int)puVar14 + 0x16) | 0x400;
          local_20 = local_20 & 0xffff;
        }
        psVar17 = psVar16;
        if (local_8 != 0) {
          if (local_18 == (short *)0x0) {
            local_18 = psVar16;
          }
          if (psVar16 != (short *)0x0) {
            *psVar16 = 0x334;
            psVar17 = psVar16 + 3;
            psVar16[1] = (ushort)local_20;
            psVar16[2] = 0;
          }
          local_8 = 0;
        }
        psVar16 = local_18;
        psVar7 = psVar17;
        if ((local_18 != (short *)0x0) && (psVar17 != (short *)0x0)) {
          *psVar17 = 0x1e;
          psVar7 = psVar17 + 3;
          psVar17[1] = 0;
          psVar17[2] = 0;
        }
        local_18 = (short *)0x0;
        *puVar14 = psVar16;
      }
      puVar14 = (undefined4 *)((int)puVar14 + 0x1a);
    }
    goto joined_r0x1c004bea;
  }
LAB_1c00504a:
  *(byte **)(param_1 + 0x10) = local_1c + -1;
  if (local_10 == 0) {
    uVar6 = *(ushort *)(param_1 + 0xe);
    if (uVar6 < 5) goto LAB_1c005111;
    puVar15 = puVar14;
    if (*(short *)((int)puVar14 + -0xe) == 0) {
      *(undefined2 *)((int)puVar14 + -0xe) = 4;
    }
    else if (((*(byte *)(*(int *)(*(int *)((int)puVar14 + -0x12) + 0x1c) + 3 +
                        *(short *)((int)puVar14 + -0xe) * 4) & 2) == 0) || (uVar8 == 0x1b)) {
      *(undefined2 *)(puVar14 + 3) = 4;
      puVar15 = (undefined4 *)((int)puVar14 + 0x1a);
      *(undefined4 *)((int)puVar14 + 0x12) = *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x6a);
      *(short *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + 1;
    }
    if (local_18 != (short *)0x0) {
      if (psVar7 != (short *)0x0) {
        *psVar7 = 0x1e;
        psVar7[1] = 0;
        psVar7[2] = 0;
      }
      *(short **)((int)puVar15 + -0x1a) = local_18;
    }
    *(undefined2 *)(puVar15 + 3) = 0x1b;
    *(undefined4 *)((int)puVar15 + 0x12) = *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x2c0);
    *(undefined2 *)((int)puVar15 + 0x26) = 0x1b;
    puVar15[0xb] = *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x2c0);
    *(undefined2 *)(puVar15 + 0x10) = 0xff;
    *(undefined2 *)(puVar15 + 0x11) = 0xff;
    *(undefined2 *)((int)puVar15 + 0x42) = 0xff;
    *(undefined4 *)((int)puVar15 + 0x46) = 0;
    *(short *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + 3;
  }
  uVar6 = *(ushort *)(param_1 + 0xe);
LAB_1c005111:
  if (uVar6 == 4) {
    local_10 = 1000;
    *(undefined2 *)(param_1 + 0xe) = 0;
  }
  if (local_4 != 0) {
    local_10 = 0x1b6d;
  }
  return local_10;
}


// ==== FUN_1c005180 @ 1c005180 size=166

short * __cdecl FUN_1c005180(int *param_1,short *param_2,undefined1 *param_3,int *param_4)

{
  char *pcVar1;
  char *pcVar2;
  ushort uVar3;
  char *pcVar4;
  int iVar5;
  char *local_10 [4];
  
  pcVar1 = (char *)*param_1;
  pcVar4 = pcVar1;
  if (pcVar1 == (char *)0x0) {
    return (short *)0x0;
  }
  while (pcVar2 = pcVar4, pcVar2 != (char *)0x0) {
    local_10[0] = pcVar2;
    FUN_1c005230(local_10);
    uVar3 = FUN_1c005310((int)local_10,param_2);
    if (uVar3 == 0x8000) {
      *param_2 = 0x46;
      *param_1 = (int)pcVar2;
      return (short *)0x0;
    }
    param_2 = param_2 + 3;
    pcVar4 = FUN_1c0052d0(pcVar2);
    pcVar1 = pcVar2;
  }
  iVar5 = (int)pcVar1 - *param_1;
  *param_1 = (int)pcVar1;
  do {
    pcVar1 = (char *)*param_1;
    if (*pcVar1 == '\0') break;
    iVar5 = iVar5 + 1;
    *param_1 = (int)(pcVar1 + 1);
  } while (*pcVar1 != '}');
  *param_3 = *(undefined1 *)*param_1;
  *param_1 = *param_1 + 1;
  *param_4 = *param_4 - (iVar5 + 1);
  return param_2;
}


// ==== FUN_1c005230 @ 1c005230 size=147

void __cdecl FUN_1c005230(undefined4 *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  pcVar3 = (char *)*param_1;
  if ((char *)*param_1 != (char *)0x0) {
    do {
      pcVar2 = pcVar3;
      cVar1 = *pcVar2;
      pcVar3 = pcVar2 + 1;
    } while (cVar1 == ' ');
    if (((cVar1 != ';') && (cVar1 != '}')) && (cVar1 != '\0')) {
      param_1[1] = pcVar2;
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
        if (cVar1 == '\0') {
          return;
        }
        if (cVar1 == ';') {
          return;
        }
        if (cVar1 == '}') {
          return;
        }
      } while (cVar1 != ' ');
      do {
        pcVar3 = pcVar2;
        cVar1 = *pcVar3;
        pcVar2 = pcVar3 + 1;
      } while (cVar1 == ' ');
      if (((cVar1 != ';') && (cVar1 != '}')) && (cVar1 != '\0')) {
        param_1[2] = pcVar3;
        do {
          cVar1 = *pcVar3;
          pcVar3 = pcVar3 + 1;
          if (cVar1 == '\0') {
            return;
          }
          if (cVar1 == ';') {
            return;
          }
          if (cVar1 == '}') {
            return;
          }
        } while (cVar1 != ' ');
        do {
          pcVar2 = pcVar3;
          cVar1 = *pcVar2;
          pcVar3 = pcVar2 + 1;
        } while (cVar1 == ' ');
        if (((cVar1 != ';') && (cVar1 != '}')) && (cVar1 != '\0')) {
          param_1[3] = pcVar2;
        }
      }
    }
  }
  return;
}


// ==== FUN_1c0052d0 @ 1c0052d0 size=60

char * __cdecl FUN_1c0052d0(char *param_1)

{
  char cVar1;
  
  if (param_1 == (char *)0x0) {
    return (char *)0x0;
  }
  do {
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    if (cVar1 == '\0') {
      return (char *)0x0;
    }
    if (cVar1 == ';') {
      return param_1;
    }
  } while (cVar1 != '}');
  do {
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    if (cVar1 == '\0') break;
  } while (cVar1 == ' ');
  return (char *)(-(uint)(cVar1 == '{') & (uint)param_1);
}


// ==== FUN_1c005310 @ 1c005310 size=891

ushort __cdecl FUN_1c005310(int param_1,short *param_2)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  ushort uVar6;
  short sVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  undefined **ppuVar11;
  int iVar12;
  char *pcVar13;
  
  pbVar5 = *(byte **)(param_1 + 4);
  if (pbVar5 == (byte *)0x0) {
    return 0x8000;
  }
  piVar8 = (int *)__p___mb_cur_max();
  if (*piVar8 < 2) {
    piVar8 = (int *)__p__pctype();
    uVar9 = *(ushort *)(*piVar8 + (uint)*pbVar5 * 2) & 4;
  }
  else {
    uVar9 = _isctype((uint)*pbVar5,4);
  }
  if (uVar9 != 0) {
    param_2[2] = 0;
    *param_2 = 0x28;
    uVar6 = FUN_1c0056e0(pbVar5);
    param_2[1] = uVar6;
    return uVar6;
  }
  bVar3 = *pbVar5;
  if (('`' < (char)bVar3) && ((char)bVar3 < 'h')) {
    bVar4 = pbVar5[1];
    sVar7 = FUN_1c0056e0(pbVar5 + (short)(ushort)(bVar4 == 0x23) + 1);
    if ((-1 < sVar7) && (sVar7 < 9)) {
      *param_2 = 0xb4;
      param_2[1] = -(*(short *)(&DAT_1c012b58 + (short)((char)bVar3 + -0x61) * 2) + sVar7 * 0xc +
                    (ushort)(bVar4 == 0x23));
      sVar7 = FUN_1c005700(*(byte **)(param_1 + 8));
      param_2[2] = sVar7;
      return -(ushort)(sVar7 == -0x8000) & 0x8000;
    }
  }
  if (*pbVar5 == 0x70) {
    piVar8 = (int *)__p___mb_cur_max();
    pbVar1 = pbVar5 + 1;
    if (*piVar8 < 2) {
      piVar8 = (int *)__p__pctype();
      uVar9 = *(ushort *)(*piVar8 + (uint)*pbVar1 * 2) & 4;
    }
    else {
      uVar9 = _isctype((uint)*pbVar1,4);
    }
    if (uVar9 != 0) {
      *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 8);
      *(byte **)(param_1 + 8) = pbVar1;
    }
  }
  iVar12 = 0;
  ppuVar11 = &PTR_s_voice_1c0126b0;
  do {
    uVar9 = 0xffffffff;
    pcVar13 = *ppuVar11;
    do {
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      cVar2 = *pcVar13;
      pcVar13 = pcVar13 + 1;
    } while (cVar2 != '\0');
    iVar10 = strncmp((char *)pbVar5,*ppuVar11,~uVar9 - 1);
    if (iVar10 == 0) break;
    ppuVar11 = (undefined **)((int)ppuVar11 + 6);
    iVar12 = iVar12 + 1;
  } while (ppuVar11 < &DAT_1c012812);
  if (iVar12 == 0x3b) {
    return 0x8000;
  }
  sVar7 = *(short *)(iVar12 * 6 + 0x1c0126b4);
  *param_2 = sVar7;
  pbVar5 = *(byte **)(param_1 + 8);
  pbVar1 = *(byte **)(param_1 + 0xc);
  iVar12 = (int)sVar7;
  if (iVar12 < 0x42) {
    if (iVar12 == 0x41) {
      sVar7 = FUN_1c0057e0((char *)pbVar5,&PTR_s_english_1c012918);
      param_2[1] = sVar7;
      sVar7 = FUN_1c005700(pbVar1);
      param_2[2] = sVar7;
      sVar7 = param_2[1];
      if (sVar7 == 0) {
        DAT_1c014598 = DAT_1c012038;
      }
      else if (sVar7 == 1) {
        DAT_1c014598 = DAT_1c01203c;
      }
      else if (sVar7 == 2) {
        DAT_1c014598 = DAT_1c012040;
      }
      goto LAB_1c00566c;
    }
    if (iVar12 == 0x32) {
      sVar7 = FUN_1c0057e0((char *)pbVar5,&PTR_DAT_1c012830);
      goto LAB_1c00565a;
    }
switchD_1c005559_caseD_32b:
    sVar7 = FUN_1c0056e0(pbVar5);
  }
  else {
    if ((iVar12 < 0x5b) || (iVar12 < 0x6f)) goto switchD_1c005559_caseD_32b;
    if (iVar12 < 0xd3) {
      if (iVar12 == 0xd2) {
        sVar7 = FUN_1c0057e0((char *)pbVar5,&PTR_s_default_1c0128a0);
      }
      else {
        if (iVar12 != 200) goto switchD_1c005559_caseD_32b;
        sVar7 = FUN_1c0057e0((char *)pbVar5,&PTR_DAT_1c012888);
      }
    }
    else {
      if (0xf0 < iVar12) {
        if (iVar12 < 0x321) {
          if (iVar12 == 800) {
switchD_1c005559_caseD_32a:
            sVar7 = FUN_1c0057e0((char *)pbVar5,&PTR_DAT_1c012908);
            goto LAB_1c00565a;
          }
          if (iVar12 == 0x212) {
            sVar7 = FUN_1c0057e0((char *)pbVar5,&PTR_s_natural_1c0128f0);
            goto LAB_1c00565a;
          }
        }
        else {
          switch(iVar12) {
          case 0x32a:
          case 0x33e:
          case 0x348:
          case 0x35c:
            goto switchD_1c005559_caseD_32a;
          }
        }
        goto switchD_1c005559_caseD_32b;
      }
      if (iVar12 == 0xf0) {
        sVar7 = FUN_1c0057e0((char *)pbVar5,&PTR_s_natural_1c0128d8);
      }
      else {
        if (iVar12 != 0xdc) goto switchD_1c005559_caseD_32b;
        sVar7 = FUN_1c0057e0((char *)pbVar5,&PTR_s_normal_1c0128c8);
      }
    }
  }
LAB_1c00565a:
  param_2[1] = sVar7;
  sVar7 = FUN_1c005700(pbVar1);
  param_2[2] = sVar7;
LAB_1c00566c:
  if ((param_2[1] != -0x8000) && (param_2[2] != -0x8000)) {
    return 0;
  }
  return 0x8000;
}


// ==== FUN_1c0056e0 @ 1c0056e0 size=23

short __cdecl FUN_1c0056e0(byte *param_1)

{
  short sVar1;
  
  if (param_1 == (byte *)0x0) {
    return -0x8000;
  }
  sVar1 = FUN_1c005720(param_1);
  return sVar1;
}


// ==== FUN_1c005700 @ 1c005700 size=22

short __cdecl FUN_1c005700(byte *param_1)

{
  short sVar1;
  
  if (param_1 == (byte *)0x0) {
    return 0;
  }
  sVar1 = FUN_1c005720(param_1);
  return sVar1;
}


// ==== FUN_1c005720 @ 1c005720 size=180

short __cdecl FUN_1c005720(byte *param_1)

{
  byte bVar1;
  bool bVar2;
  int *piVar3;
  uint uVar4;
  short sVar5;
  
  bVar1 = *param_1;
  if (bVar1 == 0) {
    return -0x8000;
  }
  if (bVar1 == 0x2d) {
    bVar2 = true;
    param_1 = param_1 + 1;
  }
  else {
    bVar2 = false;
    if (bVar1 == 0x2b) {
      param_1 = param_1 + 1;
    }
  }
  sVar5 = 0;
  while( true ) {
    piVar3 = (int *)__p___mb_cur_max();
    bVar1 = *param_1;
    if (*piVar3 < 2) {
      piVar3 = (int *)__p__pctype();
      uVar4 = *(ushort *)(*piVar3 + (uint)bVar1 * 2) & 4;
    }
    else {
      uVar4 = _isctype((uint)bVar1,4);
    }
    param_1 = param_1 + 1;
    if (uVar4 == 0) break;
    sVar5 = sVar5 * 10 + (short)(char)bVar1 + -0x30;
  }
  if (bVar2) {
    sVar5 = -sVar5;
  }
  if (((bVar1 != 0x3b) && (bVar1 != 0x7d)) && (bVar1 != 0x20)) {
    if ((bVar1 == 0x25) && (!bVar2)) {
      return -sVar5;
    }
    return -0x8000;
  }
  return sVar5;
}


// ==== FUN_1c0057e0 @ 1c0057e0 size=92

short __cdecl FUN_1c0057e0(char *param_1,undefined4 *param_2)

{
  size_t _MaxCount;
  char cVar1;
  int iVar2;
  uint uVar3;
  short sVar4;
  char *pcVar5;
  
  if (param_1 == (char *)0x0) {
    return -0x8000;
  }
  sVar4 = 0;
  do {
    uVar3 = 0xffffffff;
    pcVar5 = (char *)*param_2;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    _MaxCount = ~uVar3 - 1;
    if (_MaxCount == 0) {
      return -0x8000;
    }
    iVar2 = strncmp(param_1,(char *)*param_2,_MaxCount);
    if (iVar2 == 0) {
      if (_MaxCount == 0) {
        return -0x8000;
      }
      return sVar4;
    }
    param_2 = param_2 + 1;
    sVar4 = sVar4 + 1;
  } while( true );
}


// ==== FUN_1c005840 @ 1c005840 size=203

void __cdecl FUN_1c005840(int param_1)

{
  short sVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  
  *(undefined4 *)(param_1 + 0xfa) = *(undefined4 *)(param_1 + 0xf6);
  iVar4 = *(int *)(param_1 + 0x1c);
  *(int *)(param_1 + 0x20) = iVar4;
  *(int *)(param_1 + 0x24) = iVar4;
  *(int *)(param_1 + 0x28) = iVar4 + 0x1a;
  *(int *)(param_1 + 0x2c) = iVar4 + 0x34;
  *(int *)(param_1 + 0x30) = iVar4 + 0x4e;
  sVar1 = *(short *)(iVar4 + 0x26);
  while (sVar1 != 0xff) {
    (**(code **)(*(int *)(iVar4 + 0x22) + 8))(param_1);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x28);
    iVar2 = *(int *)(param_1 + 0x30);
    *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(param_1 + 0x2c);
    *(int *)(param_1 + 0x2c) = iVar2;
    if (*(short *)(iVar2 + 0xc) != 0xff) {
      *(int *)(param_1 + 0x30) = iVar2 + 0x1a;
    }
    sVar1 = *(short *)(iVar4 + 0x40);
    iVar4 = iVar4 + 0x1a;
  }
  (**(code **)(*(int *)(iVar4 + 0x22) + 8))(param_1);
  puVar3 = *(undefined1 **)(param_1 + 0xfa);
  *puVar3 = 0xff;
  puVar3[1] = 0xff;
  puVar3[2] = 0xff;
  puVar3[0x10] = 0xff;
  *(undefined2 *)(puVar3 + 0x18) = 0xffff;
  if (*(short *)(param_1 + 0x4c) == 3) {
    iVar4 = -4 - (uint)*(ushort *)(*(int *)(param_1 + 0x24) + 0xe);
    *(undefined2 *)(puVar3 + -8) =
         *(undefined2 *)(puVar3 + ((int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3) * 0x20 + -8);
  }
  return;
}


// ==== FUN_1c005910 @ 1c005910 size=239

undefined4 __cdecl FUN_1c005910(int param_1)

{
  short sVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  
  uVar2 = *(uint *)(param_1 + 0x4e);
  iVar5 = *(ushort *)(param_1 + 0xe) - 5;
  sVar1 = *(short *)(*(int *)(param_1 + 0x1c) + 0x8e);
  puVar6 = (undefined4 *)(*(int *)(param_1 + 0x1c) + 0x82);
  while (sVar1 != 0xff) {
    pbVar7 = *(byte **)(puVar6[2] + 0x24);
    do {
      bVar3 = pbVar7[0xb] & 0x20;
      iVar4 = FUN_1c005a00((int)pbVar7,(int)puVar6);
      if (((iVar4 != 0) && ((pbVar7[0xb] & 0x12) == 0)) &&
         (iVar4 = FUN_1c005a60((int)pbVar7,(int)puVar6,uVar2 & 0x10), iVar4 != 0)) {
        iVar4 = FUN_1c005c00(pbVar7,puVar6,iVar5);
        if (iVar4 != 0) {
          iVar5 = iVar5 + 1;
          *(short *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + 1;
        }
        FUN_1c005cb0((int)pbVar7,(int)puVar6);
        iVar4 = FUN_1c005d40((int)pbVar7,(int)puVar6,iVar5);
        if (iVar4 != 0) {
          puVar6 = (undefined4 *)((int)puVar6 + 0x1a);
          *(short *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + 1;
        }
        iVar4 = FUN_1c005cf0((char *)pbVar7,puVar6,iVar5);
        if (iVar4 != 0) {
          puVar6 = (undefined4 *)((int)puVar6 + -0x1a);
          *(short *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + -1;
        }
        if ((pbVar7[0xb] & 0x40) == 0) {
          bVar3 = 1;
        }
      }
      pbVar7 = pbVar7 + 0x10;
    } while (bVar3 == 0);
    iVar5 = iVar5 + -1;
    sVar1 = *(short *)((int)puVar6 + 0x26);
    puVar6 = (undefined4 *)((int)puVar6 + 0x1a);
  }
  return 0;
}


// ==== FUN_1c005a00 @ 1c005a00 size=94

undefined4 __cdecl FUN_1c005a00(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(byte *)(param_1 + 4) != 0xff) &&
     (*(ushort *)(param_2 + 0xc) != (ushort)*(byte *)(param_1 + 4))) {
    return 0;
  }
  if (((*(byte *)(param_1 + 3) == 0xff) ||
      (*(ushort *)(param_2 + -0xe) == (ushort)*(byte *)(param_1 + 3))) &&
     ((*(byte *)(param_1 + 5) == 0xff ||
      (*(ushort *)(param_2 + 0x26) == (ushort)*(byte *)(param_1 + 5))))) {
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_1c005a60 @ 1c005a60 size=290

int __cdecl FUN_1c005a60(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  short *psVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  iVar5 = 1;
  iVar1 = param_2 + 0x1a;
  uVar7 = *(uint *)(param_2 + -4);
  uVar8 = 0;
  uVar9 = *(uint *)(*(int *)(*(int *)(param_2 + -0x12) + 0x1c) + *(short *)(param_2 + -0xe) * 4);
  do {
    if (iVar5 == 0) break;
    bVar4 = *(byte *)(param_1 + 6 + uVar8);
    uVar6 = (uint)bVar4;
    if (uVar6 == 0xff) goto switchD_1c005ac6_default;
    switch(uVar6 & 0x60) {
    case 0:
      uVar6 = uVar7 & 0x10;
      break;
    case 0x20:
      uVar6 = uVar7 & 0x10;
      goto joined_r0x1c005afd;
    case 0x40:
      uVar6 = *(uint *)(&DAT_1c0122a8 + (uVar6 & 0x1f) * 4) & uVar9;
      break;
    case 0x60:
      uVar6 = *(uint *)(&DAT_1c0122a8 + (uVar6 & 0x1f) * 4) & uVar9;
joined_r0x1c005afd:
      if (uVar6 == 0) goto LAB_1c005aff;
    default:
      goto switchD_1c005ac6_default;
    }
    if (uVar6 != 0) {
LAB_1c005aff:
      iVar5 = 0;
    }
switchD_1c005ac6_default:
    if ((bVar4 & 0x80) != 0) {
      uVar9 = *(uint *)(*(int *)(*(int *)(param_2 + 8) + 0x1c) + *(short *)(param_2 + 0xc) * 4);
      uVar7 = *(uint *)(param_2 + 0x16);
      if (((iVar1 == param_2) && ((*(byte *)(param_1 + 0xb) & 0x80) != 0)) &&
         (*(short *)(param_2 + 0xc) == 0)) {
        piVar2 = (int *)(param_2 + 0x22);
        uVar7 = *(uint *)(param_2 + 0x30);
        psVar3 = (short *)(param_2 + 0x26);
        param_2 = param_2 + 0x1a;
        uVar9 = *(uint *)(*(int *)(*piVar2 + 0x1c) + *psVar3 * 4);
      }
      param_2 = param_2 + 0x1a;
    }
    uVar8 = uVar8 + 1;
  } while (uVar8 < 5);
  if ((*(byte *)(param_1 + 0xb) & 0x10) != 0) {
    if ((*(byte *)(param_1 + 0xb) & 0x1f) != 0x11) {
      return 0;
    }
    if (param_3 == 0) {
      iVar5 = 0;
    }
  }
  return iVar5;
}


// ==== FUN_1c005c00 @ 1c005c00 size=168

undefined4 __cdecl FUN_1c005c00(byte *param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  ushort uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  uVar2 = (ushort)*param_1;
  if (uVar2 != 0xff) {
    puVar3 = (undefined4 *)(param_3 * 0x1a + -0x1a + (int)param_2);
    puVar1 = (undefined4 *)(param_3 * 0x1a + (int)param_2);
    while (param_3 != 0) {
      param_3 = param_3 + -1;
      puVar5 = puVar3;
      puVar6 = puVar1;
      for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      *(undefined2 *)puVar6 = *(undefined2 *)puVar5;
      puVar3 = (undefined4 *)((int)puVar3 + -0x1a);
      puVar1 = (undefined4 *)((int)puVar1 + -0x1a);
    }
    *(undefined4 *)((int)param_2 + 0x16) = 0;
    *(undefined2 *)(param_2 + 4) = 0;
    *(ushort *)(param_2 + 3) = uVar2;
    param_2[2] = puVar1[2];
    iVar4 = puVar1[1];
    param_2[1] = iVar4;
    *(undefined4 *)((int)param_2 + 0x12) = *(undefined4 *)((short)uVar2 * 0x1a + 2 + iVar4);
    *param_2 = 0;
    return 1;
  }
  return 0;
}


// ==== FUN_1c005cb0 @ 1c005cb0 size=55

undefined4 __cdecl FUN_1c005cb0(int param_1,int param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)*(byte *)(param_1 + 1);
  if (uVar1 == 0xff) {
    return 0;
  }
  *(ushort *)(param_2 + 0xc) = uVar1;
  *(undefined4 *)(param_2 + 0x12) = *(undefined4 *)((short)uVar1 * 0x1a + 2 + *(int *)(param_2 + 4))
  ;
  return 1;
}


// ==== FUN_1c005cf0 @ 1c005cf0 size=77

undefined4 __cdecl FUN_1c005cf0(char *param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (((*param_1 == -1) && (param_1[1] == -1)) && (puVar1 = param_2, param_1[2] == -1)) {
    while (param_3 = param_3 + -1, param_3 != 0) {
      puVar3 = (undefined4 *)((int)puVar1 + 0x1a);
      puVar4 = param_2;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      *(undefined2 *)puVar4 = *(undefined2 *)puVar3;
      param_2 = (undefined4 *)((int)param_2 + 0x1a);
      puVar1 = (undefined4 *)((int)puVar1 + 0x1a);
    }
    return 1;
  }
  return 0;
}


// ==== FUN_1c005d40 @ 1c005d40 size=164

undefined4 __cdecl FUN_1c005d40(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  ushort uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  uVar2 = (ushort)*(byte *)(param_1 + 2);
  if (uVar2 != 0xff) {
    puVar3 = (undefined4 *)(param_3 * 0x1a + -0x1a + param_2);
    puVar1 = (undefined4 *)(param_3 * 0x1a + param_2);
    while (param_3 = param_3 + -1, param_3 != 0) {
      puVar5 = puVar3;
      puVar6 = puVar1;
      for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      *(undefined2 *)puVar6 = *(undefined2 *)puVar5;
      puVar3 = (undefined4 *)((int)puVar3 + -0x1a);
      puVar1 = (undefined4 *)((int)puVar1 + -0x1a);
    }
    *(ushort *)(param_2 + 0x26) = uVar2;
    *(undefined2 *)(param_2 + 0x2a) = 0;
    *(undefined4 *)(param_2 + 0x30) = 0;
    *(undefined4 *)(param_2 + 0x22) = puVar1[2];
    iVar4 = puVar1[1];
    *(int *)(param_2 + 0x1e) = iVar4;
    *(undefined4 *)(param_2 + 0x2c) = *(undefined4 *)((short)uVar2 * 0x1a + 2 + iVar4);
    *(undefined4 *)(param_2 + 0x1a) = 0;
    return 1;
  }
  return 0;
}


// ==== FUN_1c00be40 @ 1c00be40 size=1142

void __cdecl FUN_1c00be40(int param_1)

{
  char cVar1;
  bool bVar2;
  undefined4 *puVar3;
  short sVar4;
  short sVar5;
  ushort uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  short *psVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  short local_22;
  ushort local_20;
  ushort local_1e;
  int local_1c;
  undefined4 *local_18;
  char *local_c;
  int local_8;
  
  local_c = &DAT_1c001470;
  local_1e = 0;
  local_20 = 0;
  iVar14 = *(int *)(param_1 + 0xf6);
  local_22 = (short)((ulonglong)(uint)(*(short *)(param_1 + 0x68) * 0x340) / 0x7f);
  local_1c = (int)*(short *)(param_1 + 0x6a) << 8;
  local_8 = (int)(0x10000 / (longlong)(int)*(short *)(param_1 + 0x6c));
  sVar5 = *(short *)((int)*(undefined4 **)(param_1 + 0x1c) + 0x26);
  puVar3 = *(undefined4 **)(param_1 + 0x1c);
  do {
    if (sVar5 == 0xff) {
      return;
    }
    local_18 = (undefined4 *)((int)puVar3 + 0x1a);
    psVar10 = (short *)*local_18;
    if (psVar10 != (short *)0x0) {
      sVar5 = *psVar10;
      while (sVar5 != 0x1e) {
        switch(*psVar10) {
        case 0x32:
          *(undefined2 *)(param_1 + 0x62) = *(undefined2 *)(&DAT_1c013616 + psVar10[1] * 0x4a);
          *(undefined2 *)(param_1 + 0x5a) = *(undefined2 *)(&DAT_1c01360c + psVar10[1] * 0x4a);
          break;
        case 0xa0:
          *(short *)(param_1 + 0x78) = psVar10[1];
          break;
        case 0xa2:
          *(short *)(param_1 + 0x7a) = psVar10[1];
          break;
        case 0xa4:
          *(short *)(param_1 + 0x7c) = psVar10[1];
          break;
        case 0xaa:
          sVar5 = psVar10[1];
          *(short *)(param_1 + 0x68) = sVar5;
          local_22 = (short)((ulonglong)(uint)(sVar5 * 0x340) / 0x7f);
          break;
        case 0xac:
          sVar4 = (short)(((int)psVar10[1] << 8) / 100);
          *(short *)(param_1 + 0x6a) = sVar4;
          local_1c = (int)sVar4 << 8;
          sVar5 = *(short *)(param_1 + 0x72);
          *(short *)(param_1 + 0x72) = sVar4;
          *(uint *)(param_1 + 0x6e) = (uint)(sVar5 < sVar4);
          break;
        case 0xae:
          sVar5 = psVar10[1];
          *(short *)(param_1 + 0x6c) = sVar5;
          local_8 = (int)(0x10000 / (longlong)(int)sVar5);
          break;
        case 0xd2:
          *(short *)(param_1 + 0x5a) = psVar10[1];
          break;
        case 0x104:
          *(short *)(param_1 + 0x62) = psVar10[1];
        }
        psVar10 = psVar10 + 3;
        sVar5 = *psVar10;
      }
    }
    for (sVar5 = (short)((int)(*(ushort *)(puVar3 + 10) + 4) >> 3); sVar5 != 0; sVar5 = sVar5 + -1)
    {
      uVar6 = *(ushort *)(iVar14 + 0x18);
      uVar11 = (uint)uVar6;
      *(short *)(iVar14 + 0x18) = (short)((uVar11 << 0x11) / (uint)*(ushort *)(param_1 + 0x48));
      local_1e = local_22 + local_1e & 0x1fff;
      bVar2 = false;
      iVar12 = (int)*(short *)(&DAT_1c013430 + (local_1e >> 5 & 0xfffffffe));
      if (*(int *)(param_1 + 0x6e) == 1) {
        iVar7 = local_8 + *(int *)(param_1 + 0x74);
        *(int *)(param_1 + 0x74) = iVar7;
        if (local_1c < iVar7) {
LAB_1c00c06d:
          *(int *)(param_1 + 0x74) = local_1c;
        }
      }
      else {
        iVar7 = *(int *)(param_1 + 0x74) + -0x1999;
        *(int *)(param_1 + 0x74) = iVar7;
        if (iVar7 < local_1c) goto LAB_1c00c06d;
      }
      iVar7 = *(int *)(param_1 + 0x74) >> 8;
      if ((*(short *)(param_1 + 0x78) != 0) && (iVar7 != 0)) {
        bVar2 = true;
        *(ushort *)(iVar14 + 0x18) =
             (short)((int)*(short *)(param_1 + 0x78) *
                     (((int)((uint)*(ushort *)(iVar14 + 0x18) * iVar12) >> 0xf) * iVar7 >> 8) >> 10)
             + *(ushort *)(iVar14 + 0x18);
      }
      if ((*(short *)(param_1 + 0x7a) != 0) && (iVar7 != 0)) {
        bVar2 = true;
        iVar13 = (((iVar12 + -0x7ff8) * (int)*(short *)(param_1 + 0x7a) >> 0x10) * iVar7 >> 8) * 2;
        iVar8 = (uint)*(byte *)(iVar14 + 0x11) + iVar13;
        iVar13 = (uint)*(byte *)(iVar14 + 0x10) + iVar13;
        if (0x7f < iVar13) {
          iVar13 = 0x80;
        }
        if (iVar13 < 1) {
          iVar13 = 0;
        }
        *(char *)(iVar14 + 0x10) = (char)iVar13;
        if (0x7f < iVar8) {
          iVar8 = 0x80;
        }
        if (iVar8 < 1) {
          iVar8 = 0;
        }
        *(char *)(iVar14 + 0x11) = (char)iVar8;
      }
      if ((*(short *)(param_1 + 0x7c) != 0) && (iVar7 != 0)) {
        bVar2 = true;
        iVar12 = ((*(short *)(param_1 + 0x7c) * iVar12 >> 0xf) * iVar7 >> 8) +
                 (uint)(*(byte *)(iVar14 + 7) & 0xf);
        if (0xe < iVar12) {
          iVar12 = 0xf;
        }
        if (iVar12 < 1) {
          iVar12 = 0;
        }
        *(byte *)(iVar14 + 7) = (char)iVar12 + (*(byte *)(iVar14 + 7) & 0xf0);
      }
      if (!bVar2) {
        local_1e = 0;
      }
      if (*(ushort *)(param_1 + 0x62) != 0) {
        *(short *)(iVar14 + 0x18) =
             *(short *)(iVar14 + 0x18) +
             (short)((int)((int)*local_c * (uint)*(ushort *)(param_1 + 0x62) * uVar11) >> 0xd);
      }
      local_20 = local_20 + 1;
      if (0xff < local_20) {
        local_c = &DAT_1c001470;
        local_20 = 0;
      }
      *(undefined1 *)(iVar14 + 0xf) = 0xff;
      switch(*(undefined2 *)(param_1 + 0x5a)) {
      case 0:
        if (*(short *)(param_1 + 0x52) == 0) goto switchD_1c00c1cf_caseD_1;
        break;
      case 1:
switchD_1c00c1cf_caseD_1:
        if (uVar6 < 0x10e) {
          uVar9 = 0;
          do {
            cVar1 = (&DAT_1c012ee8)[uVar11 * 5 + uVar9];
            if (cVar1 != '\0') break;
            uVar6 = (short)uVar9 + 1;
            uVar9 = (uint)uVar6;
          } while (uVar6 < 5);
          *(char *)(iVar14 + 0xd) = (char)uVar9;
          if ((short)uVar9 != 4) {
            uVar9 = (uint)(byte)((char)uVar9 + 1);
          }
          *(char *)(iVar14 + 0xe) = (char)uVar9;
          *(char *)(iVar14 + 0xf) = cVar1;
        }
        else {
          *(undefined1 *)(iVar14 + 0xe) = 4;
          *(undefined1 *)(iVar14 + 0xd) = 4;
        }
        break;
      case 2:
        *(undefined1 *)(iVar14 + 0xe) = 5;
        *(undefined1 *)(iVar14 + 0xd) = 5;
        break;
      case 3:
        *(undefined1 *)(iVar14 + 0xe) = 6;
        *(undefined1 *)(iVar14 + 0xd) = 6;
        break;
      case 4:
        *(undefined1 *)(iVar14 + 0xe) = 7;
        *(undefined1 *)(iVar14 + 0xd) = 7;
        break;
      case 5:
        *(undefined1 *)(iVar14 + 0xe) = 10;
        *(undefined1 *)(iVar14 + 0xd) = 10;
        break;
      case 6:
        *(undefined1 *)(iVar14 + 0xe) = 8;
        *(undefined1 *)(iVar14 + 0xd) = 8;
        break;
      case 7:
        *(undefined1 *)(iVar14 + 0xe) = 9;
        *(undefined1 *)(iVar14 + 0xd) = 9;
        break;
      case 8:
        *(undefined1 *)(iVar14 + 0xe) = 0xb;
        *(undefined1 *)(iVar14 + 0xd) = 0xb;
        break;
      default:
        *(undefined1 *)(iVar14 + 0xe) = 0;
        *(undefined1 *)(iVar14 + 0xd) = 0;
      }
      iVar14 = iVar14 + 0x20;
      local_c = local_c + 1;
    }
    sVar5 = *(short *)(puVar3 + 0x10);
    puVar3 = local_18;
  } while( true );
}


// ==== FUN_1c00c3e0 @ 1c00c3e0 size=50

void __cdecl FUN_1c00c3e0(int param_1)

{
  short sVar1;
  int iVar2;
  
  sVar1 = *(short *)(*(int *)(param_1 + 0x1c) + 0x40);
  iVar2 = *(int *)(param_1 + 0x1c) + 0x34;
  while (sVar1 != 0xff) {
    *(int *)(param_1 + 0x28) = iVar2;
    (**(code **)(*(int *)(iVar2 + 8) + 4))(param_1);
    sVar1 = *(short *)(iVar2 + 0x26);
    iVar2 = iVar2 + 0x1a;
  }
  return;
}


// ==== FUN_1c00c420 @ 1c00c420 size=210

undefined4 __cdecl FUN_1c00c420(int param_1)

{
  short sVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *local_8;
  size_t local_4;
  
  local_4 = 4;
  local_8 = *(undefined4 **)(param_1 + 0x1c);
  sVar1 = *(short *)(local_8 + 3);
  puVar2 = local_8;
  while (sVar1 != 0xff) {
    if ((*(byte *)(*(int *)(puVar2[2] + 0x1c) + 2 + *(short *)(puVar2 + 3) * 4) & 0x10) == 0) {
      puVar5 = puVar2;
      puVar6 = local_8;
      for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      *(undefined2 *)puVar6 = *(undefined2 *)puVar5;
      local_8 = (undefined4 *)((int)local_8 + 0x1a);
      local_4 = local_4 + ((int)(*(ushort *)((int)puVar2 + 0xe) + 4) >> 3);
    }
    sVar1 = *(short *)((int)puVar2 + 0x26);
    puVar2 = (undefined4 *)((int)puVar2 + 0x1a);
  }
  *(undefined2 *)(local_8 + 3) = 0xff;
  *(size_t *)(param_1 + 0x102) = local_4 << 5;
  pvVar3 = calloc(local_4,0x20);
  *(void **)(param_1 + 0xf6) = pvVar3;
  if (pvVar3 != (void *)0x0) {
    *(void **)(param_1 + 0xfa) = pvVar3;
    *(void **)(param_1 + 0x31e) = pvVar3;
    *(void **)(param_1 + 0x322) = pvVar3;
    *(void **)(param_1 + 0x326) = pvVar3;
    *(void **)(param_1 + 0x32a) = pvVar3;
    *(int *)(param_1 + 0x32e) = param_1;
    return 0;
  }
  return 0x1b5b;
}


// ==== FUN_1c00c500 @ 1c00c500 size=75

void __cdecl FUN_1c00c500(int param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  
  iVar3 = 0;
  pcVar4 = (char *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 8));
  iVar5 = 0;
  bVar2 = true;
  *(char **)(param_1 + 8) = pcVar4;
  while( true ) {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    if (cVar1 == '\0') break;
    iVar3 = iVar3 + 1;
    if (cVar1 == '@') {
      bVar2 = false;
    }
    if (cVar1 == ' ') {
      bVar2 = true;
    }
    if (bVar2) {
      iVar5 = iVar5 + 1;
    }
    if ((cVar1 == '.') || (cVar1 == '?')) break;
  }
  *(int *)(param_1 + 0x14) = iVar3;
  *(int *)(param_1 + 0x18) = iVar5;
  return;
}


// ==== FUN_1c00c550 @ 1c00c550 size=186

undefined4 __cdecl FUN_1c00c550(int param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = *(int *)(param_1 + 0x1c);
  iVar5 = iVar2 + 0x68;
  sVar1 = *(short *)(iVar2 + 0x8e);
  iVar2 = iVar2 + 0x82;
  while (sVar1 != 0xff) {
    if ((*(short *)(iVar2 + 0x10) != 0) &&
       ((*(byte *)(*(int *)(*(int *)(iVar5 + 8) + 0x1c) + *(short *)(iVar5 + 0xc) * 4) & 2) != 0)) {
      *(uint *)(iVar5 + 0x16) = *(uint *)(iVar5 + 0x16) | 0x10;
      uVar3 = *(uint *)(*(int *)(*(int *)(iVar5 + 8) + 0x1c) + *(short *)(iVar5 + 0xc) * 4);
      if ((uVar3 & 0x8000) == 0) {
        iVar4 = iVar5;
        if ((uVar3 & 0x30000) != 0) {
          iVar4 = iVar5 + -0x1a;
        }
        if ((*(uint *)(*(int *)(*(int *)(iVar4 + 8) + 0x1c) + *(short *)(iVar4 + 0xc) * 4) &
            0x1800000) != 0) {
          *(uint *)(iVar4 + 0x16) = *(uint *)(iVar4 + 0x16) | 0x10;
          iVar4 = iVar4 + -0x1a;
        }
      }
      else {
        iVar4 = iVar5 + -0x1a;
      }
      uVar3 = *(uint *)(*(int *)(*(int *)(iVar4 + 8) + 0x1c) + *(short *)(iVar4 + 0xc) * 4);
      if (((uVar3 & 0x4000) != 0) || (((uVar3 & 0x1000) != 0 && ((uVar3 & 0x8000000) == 0)))) {
        *(uint *)(iVar4 + 0x16) = *(uint *)(iVar4 + 0x16) | 0x10;
      }
      FUN_1c00c610();
    }
    iVar5 = iVar5 + 0x1a;
    sVar1 = *(short *)(iVar2 + 0x26);
    iVar2 = iVar2 + 0x1a;
  }
  return 0;
}


// ==== FUN_1c00c610 @ 1c00c610 size=3

undefined4 FUN_1c00c610(void)

{
  return 0;
}


// ==== FUN_1c00c620 @ 1c00c620 size=164

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __cdecl FUN_1c00c620(int param_1)

{
  UINT UVar1;
  MMRESULT MVar2;
  
  *(LPHWAVEOUT)(param_1 + 8) = (HWAVEOUT)0x0;
  UVar1 = waveOutGetNumDevs();
  if (UVar1 == 0) {
    return 0x1b63;
  }
  _DAT_1c014580 = 1;
  _DAT_1c014584 = 0x2b11;
  _DAT_1c014582 = 1;
  _DAT_1c01458c = 1;
  _DAT_1c014588 = 0x2b11;
  _DAT_1c01458e = 8;
  MVar2 = waveOutOpen((LPHWAVEOUT)0x0,*(UINT *)(param_1 + 0xc),(LPCWAVEFORMATEX)&DAT_1c014580,0,0,1)
  ;
  if (MVar2 != 0) {
    return 0x1b64;
  }
  MVar2 = waveOutOpen((LPHWAVEOUT)(param_1 + 8),*(UINT *)(param_1 + 0xc),
                      (LPCWAVEFORMATEX)&DAT_1c014580,*(DWORD_PTR *)(param_1 + 4),0,0x10000);
  return (MVar2 == 0) - 1 & 0x1b65;
}


// ==== FUN_1c00c6d0 @ 1c00c6d0 size=481

void __cdecl FUN_1c00c6d0(int param_1)

{
  int iVar1;
  short *psVar2;
  short sVar3;
  short sVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  
  iVar13 = *(int *)(param_1 + 0x1c);
  iVar12 = iVar13 + 0x82;
  uVar8 = 0;
  iVar10 = -1;
  iVar1 = iVar13 + 0x9c;
  bVar5 = false;
  sVar3 = *(short *)(iVar13 + 0x8e);
  iVar13 = iVar12;
  iVar11 = 0;
  while (sVar3 != 0xff) {
    iVar9 = iVar11 + 1;
    uVar6 = *(uint *)(*(int *)(*(int *)(iVar1 + -0x12) + 0x1c) + *(short *)(iVar1 + -0xe) * 4) &
            0x14000000;
    if (uVar6 == 0x4000000) {
      sVar4 = *(short *)(iVar9 * -0x1a + 0xc + iVar1);
      if ((sVar4 == 0x1e) || (sVar4 == 0x1d)) {
        iVar10 = iVar10 + -1;
        iVar13 = iVar13 + 0x1a;
        *(uint *)(iVar12 + 0x16) = *(uint *)(iVar12 + 0x16) | *(uint *)(iVar12 + -4) & 0x60;
        iVar12 = iVar12 + 0x1a;
        iVar9 = iVar11;
      }
      if (0 < iVar10) {
        iVar13 = iVar13 + iVar10 * 0x1a;
      }
      iVar11 = (iVar9 + -1) - iVar10;
      *(uint *)(iVar13 + 0x16) = *(uint *)(iVar13 + 0x16) | 8;
      if ((sVar3 != 0) || (iVar7 = iVar11 * 0x1a + iVar13, (*(byte *)(iVar7 + -3) & 0x10) != 0)) {
        for (; iVar7 = iVar13, 0 < iVar11; iVar11 = iVar11 + -1) {
          *(uint *)(iVar7 + 0x16) = *(uint *)(iVar7 + 0x16) | 4;
          iVar13 = iVar7 + 0x1a;
        }
      }
      *(uint *)(iVar12 + 0x16) = *(uint *)(iVar12 + 0x16) | 0x80;
      iVar13 = iVar9 + -2;
      iVar11 = iVar9 + -1;
      while (iVar9 = iVar13, iVar11 != 0) {
        *(uint *)(iVar12 + 0x16) = *(uint *)(iVar12 + 0x16) | uVar8;
        iVar12 = iVar12 + 0x1a;
        iVar13 = iVar9 + -1;
        iVar11 = iVar9;
      }
      uVar8 = 0;
      iVar9 = 0;
      iVar12 = iVar12 + 0x1a;
      iVar13 = iVar7 + 0x1a;
      bVar5 = false;
    }
    else if (((uVar6 == 0x10000000) && (sVar3 != 0x1e)) && (sVar3 != 0x1d)) {
      if (bVar5) {
        sVar3 = *(short *)(iVar9 * -0x1a + 0xc + iVar1);
        if ((sVar3 == 0x1e) || (sVar3 == 0x1d)) {
          iVar10 = iVar10 + -1;
          iVar13 = iVar13 + 0x1a;
          *(uint *)(iVar12 + 0x16) = *(uint *)(iVar12 + 0x16) | *(uint *)(iVar12 + -4) & 0x60;
          iVar12 = iVar12 + 0x1a;
          iVar9 = iVar11;
        }
        *(uint *)(iVar12 + 0x16) = *(uint *)(iVar12 + 0x16) | 0x80;
        iVar10 = iVar10 + iVar9 >> 1;
        iVar9 = iVar9 - iVar10;
        iVar13 = iVar13 + iVar10 * 0x1a;
        for (; iVar10 != 0; iVar10 = iVar10 + -1) {
          *(uint *)(iVar12 + 0x16) = *(uint *)(iVar12 + 0x16) | uVar8 | 0x40;
          iVar12 = iVar12 + 0x1a;
        }
        uVar8 = 0x40;
      }
      else {
        bVar5 = true;
      }
      iVar10 = iVar9 + -1;
      uVar8 = uVar8 | *(uint *)(iVar10 * 0x1a + 0x16 + iVar12) & 0x20;
    }
    psVar2 = (short *)(iVar1 + 0xc);
    iVar1 = iVar1 + 0x1a;
    iVar11 = iVar9;
    sVar3 = *psVar2;
  }
  return;
}


// ==== FUN_1c00c8c0 @ 1c00c8c0 size=54

undefined4 __cdecl FUN_1c00c8c0(int param_1)

{
  FUN_1c00c900(param_1);
  FUN_1c00c9b0(param_1);
  FUN_1c00cac0(param_1);
  FUN_1c00caf0(param_1);
  FUN_1c00cb60(param_1);
  return 0;
}


// ==== FUN_1c00c900 @ 1c00c900 size=169

void __cdecl FUN_1c00c900(int param_1)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  byte *pbVar7;
  
  pbVar7 = *(byte **)(param_1 + 0xdc);
  sVar1 = *(short *)(*(int *)(param_1 + 0x1c) + 0xc);
  iVar4 = *(int *)(param_1 + 0x1c);
  while (sVar1 != 0xff) {
    uVar2 = *(ushort *)(iVar4 + 0x10);
    uVar3 = *(uint *)(iVar4 + 0x16);
    iVar6 = iVar4 + 0x1a;
    if ((*(byte *)(*(int *)(*(int *)(iVar4 + 8) + 0x1c) + 3 + *(short *)(iVar4 + 0xc) * 4) & 4) == 0
       ) {
      if ((uVar3 & 0x80) != 0) {
        if ((uVar3 & 0x20) != 0) {
          bVar5 = (byte)uVar2;
          while ((uVar2 & 0xf) == 0) {
            uVar2 = *(ushort *)(iVar6 + 0x10);
            uVar3 = *(uint *)(iVar6 + 0x16);
            iVar6 = iVar6 + 0x1a;
            bVar5 = (byte)uVar2;
          }
          bVar5 = (byte)(((uint)(bVar5 & 0xf) * 0xd) / 9);
          if ((uVar3 & 0x40) != 0) {
            bVar5 = bVar5 + 2;
          }
          if (4 < bVar5) {
            *pbVar7 = *pbVar7 | 0x20;
          }
          *pbVar7 = *pbVar7 | bVar5;
        }
        pbVar7 = pbVar7 + 1;
      }
    }
    else {
      bVar5 = pbVar7[-1];
      pbVar7[-1] = bVar5 | 0x80;
      if ((*(byte *)(*(int *)(*(int *)(iVar4 + 8) + 0x1c) + 2 + *(short *)(iVar4 + 0xc) * 4) & 8) !=
          0) {
        pbVar7[-1] = bVar5 | 0xc0;
      }
    }
    iVar4 = iVar6;
    sVar1 = *(short *)(iVar6 + 0xc);
  }
  return;
}


// ==== FUN_1c00c9b0 @ 1c00c9b0 size=268

void __cdecl FUN_1c00c9b0(int param_1)

{
  short *psVar1;
  byte bVar2;
  byte bVar3;
  short sVar4;
  uint uVar5;
  bool bVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte bVar9;
  byte *pbVar10;
  int iVar11;
  byte *pbVar12;
  uint local_8;
  
  pbVar10 = (byte *)(*(int *)(param_1 + 0xd8) + -1);
  bVar6 = false;
  pbVar12 = (byte *)(*(int *)(param_1 + 0xdc) + -1);
  iVar11 = *(int *)(param_1 + 0x1c);
  sVar4 = *(short *)(iVar11 + 0xc);
  while (sVar4 != 0xff) {
    uVar5 = *(uint *)(iVar11 + 0x16);
    *pbVar12 = *pbVar12 | !bVar6 - 1U & 0x10;
    if ((uVar5 & 0x80) != 0) {
      pbVar10 = pbVar10 + 1;
      pbVar12 = pbVar12 + 1;
    }
    if (sVar4 == 4) {
      *pbVar10 = *pbVar10 | 0x90;
    }
    if ((uVar5 & 0x800) == 0) {
      if ((uVar5 & 0x1000) != 0) {
        bVar6 = false;
        *pbVar10 = *pbVar10 | 0xe;
      }
    }
    else {
      bVar6 = true;
      *pbVar10 = *pbVar10 | 2;
    }
    psVar1 = (short *)(iVar11 + 0x26);
    iVar11 = iVar11 + 0x1a;
    sVar4 = *psVar1;
  }
  bVar9 = 0;
  pbVar12 = (byte *)0x0;
  local_8 = (uint)*(ushort *)(param_1 + 0xbe);
  pbVar10 = *(byte **)(param_1 + 0xdc);
  bVar6 = false;
  pbVar8 = *(byte **)(param_1 + 0xd8);
  while (pbVar7 = pbVar8, local_8 != 0) {
    local_8 = local_8 - 1;
    bVar2 = *pbVar7;
    bVar3 = *pbVar10;
    pbVar10 = pbVar10 + 1;
    if ((bVar2 & 0xf) == 2) {
      *pbVar7 = *pbVar7 & 0xf0;
      bVar6 = true;
      bVar9 = 2;
    }
    if (((bVar3 & 0x20) != 0) && (pbVar12 = pbVar7, bVar6)) {
      *pbVar7 = *pbVar7 | bVar9;
      bVar9 = 0;
    }
    pbVar8 = pbVar7 + 1;
    if ((bVar2 & 0xf) == 0xe) {
      *pbVar7 = *pbVar7 & 0xf0;
      bVar9 = 0;
      bVar6 = false;
      if (pbVar12 != (byte *)0x0) {
        *pbVar12 = *pbVar12 | 0xe;
      }
      pbVar12 = (byte *)0x0;
    }
  }
  return;
}


// ==== FUN_1c00cac0 @ 1c00cac0 size=38

void __cdecl FUN_1c00cac0(int param_1)

{
  byte *pbVar1;
  uint uVar2;
  
  pbVar1 = *(byte **)(param_1 + 0xe0);
  for (uVar2 = (uint)*(ushort *)(param_1 + 0xbe); uVar2 != 0; uVar2 = uVar2 - 1) {
    *pbVar1 = *pbVar1 | 1;
    pbVar1 = pbVar1 + 1;
  }
  return;
}


// ==== FUN_1c00caf0 @ 1c00caf0 size=99

void __cdecl FUN_1c00caf0(int param_1)

{
  short sVar1;
  byte *pbVar2;
  byte bVar3;
  byte *pbVar4;
  uint uVar5;
  
  sVar1 = *(short *)((uint)*(ushort *)(param_1 + 0xe) * 0x1a + -0x5c + *(int *)(param_1 + 0x1c));
  bVar3 = 0;
  if (sVar1 == 1) {
    bVar3 = 4;
  }
  else if (sVar1 == 2) {
    bVar3 = 8;
  }
  uVar5 = (uint)*(ushort *)(param_1 + 0xbe);
  pbVar2 = (byte *)(*(int *)(param_1 + 0xe0) + -1 + uVar5);
  pbVar4 = (byte *)(*(int *)(param_1 + 0xdc) + uVar5 + -1);
  *pbVar2 = *pbVar2 | bVar3;
  while ((uVar5 = uVar5 - 1, uVar5 != 0 && (pbVar4 = pbVar4 + -1, (*pbVar4 & 0x80) == 0))) {
    pbVar2[-1] = pbVar2[-1] | bVar3;
    pbVar2 = pbVar2 + -1;
  }
  return;
}


// ==== FUN_1c00cb60 @ 1c00cb60 size=170

void __cdecl FUN_1c00cb60(int param_1)

{
  short sVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  uint uVar5;
  byte *pbVar6;
  
  uVar5 = (uint)*(ushort *)(param_1 + 0xbe);
  pbVar6 = (byte *)0x0;
  pbVar2 = *(byte **)(param_1 + 0xdc);
  pbVar3 = *(byte **)(param_1 + 0xd8);
  bVar4 = *(byte *)(*(int *)(param_1 + 0xe0) + -1 + uVar5) & 0xc;
  sVar1 = *(short *)((uint)*(ushort *)(param_1 + 0xe) * 0x1a + -0x5c + *(int *)(param_1 + 0x1c));
  if (sVar1 == 4) {
    pbVar2[uVar5 - 1] = pbVar2[uVar5 - 1] | 0x40;
  }
  while (uVar5 != 0) {
    uVar5 = uVar5 - 1;
    if ((*pbVar2 & 0x20) != 0) {
      pbVar6 = pbVar3;
    }
    if (((*pbVar2 & 0x40) != 0) && (*pbVar3 = *pbVar3 | 0xb0, pbVar6 != (byte *)0x0)) {
      *pbVar6 = *pbVar6 & 0xf4 | 4;
      pbVar6 = (byte *)0x0;
    }
    pbVar2 = pbVar2 + 1;
    pbVar3 = pbVar3 + 1;
  }
  if (bVar4 != 0) {
    pbVar3[-1] = pbVar3[-1] & 0xf;
  }
  if (bVar4 == 4) {
    pbVar3[-1] = pbVar3[-1] | 0x80;
  }
  if (sVar1 == 1) {
    pbVar3[-1] = 0;
  }
  return;
}


// ==== FUN_1c00cc10 @ 1c00cc10 size=293

undefined4 __cdecl FUN_1c00cc10(int param_1)

{
  int iVar1;
  short sVar2;
  void *pvVar3;
  int iVar4;
  short sVar5;
  uint uVar6;
  
  sVar5 = 0;
  sVar2 = *(short *)(*(int *)(param_1 + 0x1c) + 0x8e);
  iVar1 = *(int *)(param_1 + 0x1c) + 0x82;
  while (sVar2 != 0xff) {
    if ((*(uint *)(iVar1 + 0x16) & 0x80) != 0) {
      sVar5 = sVar5 + 1;
    }
    sVar2 = *(short *)(iVar1 + 0x26);
    iVar1 = iVar1 + 0x1a;
  }
  uVar6 = (uint)(ushort)(sVar5 + 3);
  pvVar3 = calloc(1,uVar6 * 8);
  *(void **)(param_1 + 0xc0) = pvVar3;
  if (pvVar3 == (void *)0x0) {
    return 0xfffffffe;
  }
  iVar1 = uVar6 + 2 + (int)pvVar3;
  *(short *)(param_1 + 0xbe) = sVar5;
  *(int *)(param_1 + 0xc4) = (int)pvVar3 + 2;
  *(int *)(param_1 + 200) = iVar1;
  *(uint *)(param_1 + 0xcc) = uVar6 + iVar1;
  iVar4 = uVar6 + iVar1 + uVar6;
  *(int *)(param_1 + 0xd0) = iVar4;
  iVar4 = iVar4 + uVar6;
  *(int *)(param_1 + 0xd4) = iVar4;
  iVar4 = iVar4 + uVar6;
  *(int *)(param_1 + 0xd8) = iVar4;
  iVar4 = iVar4 + uVar6;
  *(int *)(param_1 + 0xe0) = iVar4;
  *(uint *)(param_1 + 0xdc) = iVar4 + uVar6;
  *(undefined1 *)(iVar1 + -3) = 0xff;
  *(undefined1 *)(*(int *)(param_1 + 200) + -3 + uVar6) = 0xff;
  *(undefined1 *)(*(int *)(param_1 + 0xcc) + -3 + uVar6) = 0xff;
  *(undefined1 *)(*(int *)(param_1 + 0xd0) + -3 + uVar6) = 0xff;
  *(undefined1 *)(*(int *)(param_1 + 0xd4) + -3 + uVar6) = 0xff;
  *(undefined1 *)(*(int *)(param_1 + 0xd8) + -3 + uVar6) = 0xff;
  *(undefined1 *)(*(int *)(param_1 + 0xe0) + -3 + uVar6) = 0xff;
  *(undefined1 *)(*(int *)(param_1 + 0xdc) + -3 + uVar6) = 0xff;
  *(undefined2 *)(param_1 + 0xe8) = 0;
  *(undefined2 *)(param_1 + 0xe4) = 0;
  *(undefined2 *)(param_1 + 0xf0) = 0;
  *(int *)(param_1 + 0xf2) = *(int *)(param_1 + 0x1c) + 0x68;
  return 0;
}


// ==== FUN_1c00cd40 @ 1c00cd40 size=116

void __cdecl FUN_1c00cd40(int param_1)

{
  int iVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  
  pcVar5 = *(char **)(param_1 + 0xf6);
  while( true ) {
    pcVar6 = pcVar5;
    iVar7 = 0;
    uVar2 = *(ushort *)(pcVar6 + 0x18);
    iVar9 = (uint)uVar2 * 0x100;
    sVar3 = *(short *)(pcVar6 + 0x38);
    pcVar8 = pcVar6;
    while (pcVar5 = pcVar8 + 0x20, sVar3 == 0) {
      iVar7 = iVar7 + 1;
      sVar3 = *(short *)(pcVar8 + 0x58);
      pcVar8 = pcVar5;
    }
    if (*pcVar5 == -1) break;
    if ((0 < iVar7) && (iVar1 = iVar7 + 1, uVar4 = *(ushort *)(pcVar8 + 0x38), 0 < iVar7)) {
      do {
        iVar9 = iVar9 + (int)((uint)uVar4 * 0x100 + (uint)uVar2 * -0x100) / iVar1;
        iVar7 = iVar7 + -1;
        *(short *)(pcVar6 + 0x38) = (short)((uint)iVar9 >> 8);
        pcVar6 = pcVar6 + 0x20;
      } while (iVar7 != 0);
    }
  }
  return;
}


// ==== FUN_1c00cdc0 @ 1c00cdc0 size=227

undefined4 __cdecl FUN_1c00cdc0(int param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_1c00ceb0(param_1);
  while (iVar2 != 0) {
    if (*(short *)(param_1 + 0xe6) != 0) {
      FUN_1c00cfb0(param_1);
      FUN_1c00d010(param_1);
      FUN_1c00d200(param_1);
      FUN_1c00d370(param_1);
    }
    FUN_1c00d6e0(param_1);
    FUN_1c00d780(param_1);
    FUN_1c00dc80(param_1);
    sVar1 = *(short *)(*(int *)(param_1 + 0xf2) + 0xc);
    iVar2 = *(int *)(param_1 + 0xf2);
    while ((sVar1 != 0xff &&
           ((*(byte *)(*(int *)(*(int *)(iVar2 + 8) + 0x1c) + 2 + *(short *)(iVar2 + 0xc) * 4) & 8)
            == 0))) {
      sVar1 = *(short *)(iVar2 + 0x26);
      iVar2 = iVar2 + 0x1a;
    }
    *(int *)(param_1 + 0xf2) = iVar2 + 0x1a;
    iVar2 = FUN_1c00ceb0(param_1);
  }
  uVar3 = (uint)*(ushort *)(param_1 + 0xbe);
  *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) - uVar3;
  *(int *)(param_1 + 200) = *(int *)(param_1 + 200) - uVar3;
  *(int *)(param_1 + 0xcc) = *(int *)(param_1 + 0xcc) - uVar3;
  *(int *)(param_1 + 0xd0) = *(int *)(param_1 + 0xd0) - uVar3;
  *(int *)(param_1 + 0xd4) = *(int *)(param_1 + 0xd4) - uVar3;
  *(int *)(param_1 + 0xdc) = *(int *)(param_1 + 0xdc) - uVar3;
  *(int *)(param_1 + 0xd8) = *(int *)(param_1 + 0xd8) - uVar3;
  *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) - uVar3;
  return 0;
}


// ==== FUN_1c00ceb0 @ 1c00ceb0 size=246

undefined4 __cdecl FUN_1c00ceb0(int param_1)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  byte *pbVar4;
  
  uVar3 = (uint)*(ushort *)(param_1 + 0xe8);
  *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + uVar3;
  *(int *)(param_1 + 200) = *(int *)(param_1 + 200) + uVar3;
  pbVar4 = (byte *)(*(int *)(param_1 + 0xdc) + uVar3);
  *(int *)(param_1 + 0xcc) = *(int *)(param_1 + 0xcc) + uVar3;
  *(undefined2 *)(param_1 + 0xe8) = 0;
  *(undefined2 *)(param_1 + 0xe6) = 0;
  *(byte **)(param_1 + 0xdc) = pbVar4;
  *(int *)(param_1 + 0xd8) = *(int *)(param_1 + 0xd8) + uVar3;
  *(undefined2 *)(param_1 + 0xec) = 0;
  *(short *)(param_1 + 0xe4) = *(short *)(param_1 + 0xe4) + 1;
  *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) + uVar3;
  *(undefined2 *)(param_1 + 0xee) = 0;
  *(int *)(param_1 + 0xd0) = *(int *)(param_1 + 0xd0) + uVar3;
  *(int *)(param_1 + 0xd4) = *(int *)(param_1 + 0xd4) + uVar3;
  *(undefined2 *)(param_1 + 0xf0) = 0;
  if (*pbVar4 == 0xff) {
    return 0;
  }
  bVar2 = true;
  do {
    bVar1 = *pbVar4;
    pbVar4 = pbVar4 + 1;
    if ((bVar1 & 0x80) != 0) {
      *(short *)(param_1 + 0xf0) = *(short *)(param_1 + 0xf0) + 1;
    }
    if ((bVar1 & 0x20) != 0) {
      *(short *)(param_1 + 0xe6) = *(short *)(param_1 + 0xe6) + 1;
      if (bVar2) {
        bVar2 = false;
        *(undefined2 *)(param_1 + 0xec) = *(undefined2 *)(param_1 + 0xe8);
      }
      *(undefined2 *)(param_1 + 0xee) = *(undefined2 *)(param_1 + 0xe8);
    }
    *(short *)(param_1 + 0xe8) = *(short *)(param_1 + 0xe8) + 1;
  } while ((bVar1 & 0x40) == 0);
  *(short *)(param_1 + 0xf0) = (short)((*(ushort *)(param_1 + 0xf0) + 4) / 3);
  return 1;
}


// ==== FUN_1c00cfb0 @ 1c00cfb0 size=81

void __cdecl FUN_1c00cfb0(int param_1)

{
  int iVar1;
  
  iVar1 = (uint)*(ushort *)(param_1 + 0xf0) * (6 - (uint)*(ushort *)(param_1 + 0xe4)) +
          (uint)*(ushort *)(param_1 + 0xe4) * -4 + 0x3d;
  if (iVar1 < 0x3f) {
    iVar1 = 0x3e;
  }
  if (0x47 < iVar1) {
    iVar1 = 0x48;
  }
  *(char *)((uint)*(ushort *)(param_1 + 0xec) + *(int *)(param_1 + 200)) = (char)iVar1;
  return;
}


// ==== FUN_1c00d010 @ 1c00d010 size=482

void __cdecl FUN_1c00d010(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  
  uVar11 = (uint)*(ushort *)(param_1 + 0xe6);
  iVar2 = (-(uint)((*(byte *)((*(ushort *)(param_1 + 0xe8) - 1) + *(int *)(param_1 + 0xe0)) & 0xc)
                  == 8) & 8) + 0x37;
  if (1 < *(ushort *)(param_1 + 0xe6)) {
    pbVar8 = (byte *)(*(int *)(param_1 + 200) + (uint)*(ushort *)(param_1 + 0xec));
    uVar6 = (uint)*pbVar8;
    iVar7 = uVar6 * 4;
    pbVar8 = pbVar8 + 1;
    iVar3 = (int)((uVar6 - iVar2) * 4) / (int)uVar11;
    iVar9 = uVar11 - 1;
    pbVar5 = (byte *)(*(int *)(param_1 + 0xdc) + 1 + (uint)*(ushort *)(param_1 + 0xec));
    if ((iVar9 < 1) || (2 < iVar9)) {
      iVar9 = (iVar3 * 0x73 + 0x32) / 100;
      iVar3 = iVar3 + ((iVar3 * -0x1e + -0x32) / 100) / (int)(uVar11 - 3);
      bVar1 = *pbVar5;
      while (pbVar5 = pbVar5 + 1, (bVar1 & 0x20) == 0) {
        pbVar8 = pbVar8 + 1;
        bVar1 = *pbVar5;
      }
      iVar7 = iVar7 - iVar9;
      iVar10 = uVar11 - 4;
      *pbVar8 = (byte)(iVar7 >> 2);
      while (pbVar8 = pbVar8 + 1, iVar10 != 0) {
        pbVar4 = pbVar5 + 1;
        bVar1 = *pbVar5;
        pbVar5 = pbVar4;
        if ((bVar1 & 0x20) != 0) {
          iVar7 = iVar7 - iVar3;
          iVar10 = iVar10 + -1;
          *pbVar8 = (byte)(iVar7 >> 2);
        }
      }
      bVar1 = *pbVar5;
      while ((bVar1 & 0x20) == 0) {
        pbVar5 = pbVar5 + 1;
        pbVar8 = pbVar8 + 1;
        bVar1 = *pbVar5;
      }
      iVar7 = iVar7 - iVar9;
      *pbVar8 = (byte)(iVar7 >> 2);
      *(char *)((uint)*(ushort *)(param_1 + 0xee) + *(int *)(param_1 + 200)) =
           (char)(iVar7 - iVar3 >> 2);
    }
    else {
      while (iVar9 != 0) {
        if ((*pbVar5 & 0x20) != 0) {
          iVar7 = iVar7 - iVar3;
          iVar9 = iVar9 + -1;
          *pbVar8 = (byte)(iVar7 >> 2);
        }
        pbVar8 = pbVar8 + 1;
        pbVar5 = pbVar5 + 1;
      }
    }
  }
  uVar11 = (uint)*(ushort *)(param_1 + 0xe6);
  pbVar5 = (byte *)(*(int *)(param_1 + 200) + (uint)*(ushort *)(param_1 + 0xec));
  pbVar8 = (byte *)(*(int *)(param_1 + 0xdc) + (uint)*(ushort *)(param_1 + 0xec));
  while (uVar11 != 0) {
    if ((*pbVar8 & 0x20) != 0) {
      iVar7 = ((int)((((uint)*pbVar5 - iVar2) * 5 + 0x19) * 2) / 100) * ((*pbVar8 & 0xf) - 8) +
              (uint)*pbVar5;
      if (iVar7 < 0x1a) {
        iVar7 = 0x19;
      }
      if (199 < iVar7) {
        iVar7 = 200;
      }
      uVar11 = uVar11 - 1;
      *pbVar5 = (byte)iVar7;
    }
    pbVar5 = pbVar5 + 1;
    pbVar8 = pbVar8 + 1;
  }
  return;
}


// ==== FUN_1c00d200 @ 1c00d200 size=363

void __cdecl FUN_1c00d200(int param_1)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  
  uVar2 = (uint)*(ushort *)(param_1 + 0xec);
  uVar8 = (uint)*(ushort *)(param_1 + 0xe6);
  pbVar6 = (byte *)(uVar2 + *(int *)(param_1 + 200));
  pbVar5 = (byte *)(*(int *)(param_1 + 0xd0) + uVar2);
  pbVar9 = (byte *)(*(int *)(param_1 + 0xd4) + uVar2);
  pbVar10 = (byte *)(*(int *)(param_1 + 0xdc) + uVar2);
  pbVar3 = (byte *)(*(int *)(param_1 + 0xd8) + uVar2);
  while (uVar8 != 0) {
    if ((*pbVar10 & 0x20) != 0) {
      bVar1 = *pbVar6;
      uVar7 = (uint)(*pbVar3 & 0xf);
      if (6 < (*pbVar3 & 0xf)) {
        uVar7 = uVar7 - 0x10;
      }
      *pbVar5 = (byte)((int)(((int)(uVar7 * 0x14 + 0x32) / 100 + 1) * (bVar1 - 0x37) * 0x28 + 0x32)
                      / 100);
      iVar4 = (int)((1 - uVar7) * (bVar1 - 0x37) * 0x14 + -0x32) / 100;
      if (iVar4 < 1) {
        iVar4 = 0;
      }
      *pbVar9 = (byte)iVar4;
      if (((*pbVar10 & 0x10) != 0) && (uVar7 == 0)) {
        *pbVar5 = *pbVar5 + (char)((int)((uint)*pbVar5 * -0x1e + -0x32) / 100);
        *pbVar9 = *pbVar9 + (char)((int)((uint)*pbVar9 * -0x1e + -0x32) / 100);
      }
      uVar8 = uVar8 - 1;
    }
    pbVar10 = pbVar10 + 1;
    pbVar5 = pbVar5 + 1;
    pbVar9 = pbVar9 + 1;
    pbVar6 = pbVar6 + 1;
    pbVar3 = pbVar3 + 1;
  }
  *(char *)(*(int *)(param_1 + 0xd0) + uVar2) = *(char *)(*(int *)(param_1 + 200) + uVar2) + -0x37;
  return;
}


// ==== FUN_1c00d370 @ 1c00d370 size=860

void __cdecl FUN_1c00d370(int param_1)

{
  int iVar1;
  ushort uVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte bVar6;
  char cVar7;
  byte *pbVar8;
  byte *pbVar9;
  int iVar10;
  byte *pbVar11;
  uint uVar12;
  char *pcVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  char *pcVar18;
  byte *local_20;
  int local_10;
  
  if (0x270f000c < (*(int *)(DAT_1c01459c + 0x14) << 0x10 | *(uint *)(DAT_1c01459c + 0x10))) {
    *(undefined2 *)(param_1 + 0x310) = 0x65;
  }
  if (*(ushort *)(param_1 + 0xe6) < 2) {
LAB_1c00d594:
    uVar2 = *(ushort *)(param_1 + 0xe6);
    if (uVar2 != 0) {
      uVar12 = (uint)uVar2;
      pbVar8 = (byte *)(*(int *)(param_1 + 200) + (uint)*(ushort *)(param_1 + 0xec));
      uVar15 = 0;
      uVar16 = uVar15;
      pbVar11 = (byte *)(*(int *)(param_1 + 0xdc) + (uint)*(ushort *)(param_1 + 0xec));
      if (uVar2 != 0) {
        do {
          uVar15 = uVar16;
          if ((*pbVar11 & 0x20) != 0) {
            uVar15 = (uint)*pbVar8;
            if (*pbVar8 <= uVar16) {
              uVar15 = uVar16;
            }
            uVar12 = uVar12 - 1;
          }
          pbVar8 = pbVar8 + 1;
          uVar16 = uVar15;
          pbVar11 = pbVar11 + 1;
        } while (uVar12 != 0);
      }
      uVar12 = (uint)*(ushort *)(param_1 + 0xee);
      pbVar8 = (byte *)(*(int *)(param_1 + 0xe0) + uVar12);
      pbVar11 = (byte *)(*(int *)(param_1 + 0xdc) + uVar12);
      pcVar18 = (char *)(*(int *)(param_1 + 200) + uVar12);
      pcVar13 = (char *)(*(int *)(param_1 + 0xd0) + uVar12);
      pbVar9 = (byte *)(*(int *)(param_1 + 0xd4) + uVar12);
      bVar6 = *pbVar8;
      while (bVar6 = bVar6 & 0xc, bVar6 != 0) {
        if ((*pbVar11 & 0x20) != 0) {
          if (bVar6 == 8) {
            cVar7 = (char)(((uint)*pbVar9 * 0x50 + 0x32) / 100);
            *pcVar13 = *pcVar13 + cVar7;
            *pbVar9 = *pbVar9 - cVar7;
          }
          if ((*pbVar11 & 0x80) != 0) {
            if ((*(short *)(param_1 + 0x52) == 1) || (cVar7 = '%', *(short *)(param_1 + 0x52) == 2))
            {
              cVar7 = '*';
            }
            if (bVar6 == 4) {
              *pbVar9 = *pcVar18 - cVar7;
            }
            else {
              *pbVar9 = *pcVar18 + (char)((int)(uVar15 * -0x78 + -0x32) / 100);
            }
          }
        }
        pbVar9 = pbVar9 + -1;
        pbVar8 = pbVar8 + -1;
        pcVar13 = pcVar13 + -1;
        pbVar11 = pbVar11 + -1;
        pcVar18 = pcVar18 + -1;
        bVar6 = *pbVar8;
      }
    }
    return;
  }
  uVar12 = (uint)*(ushort *)(param_1 + 0xec);
  pbVar8 = (byte *)(*(int *)(param_1 + 200) + uVar12);
  pbVar9 = (byte *)(*(int *)(param_1 + 0xd0) + uVar12);
  local_20 = (byte *)(*(int *)(param_1 + 0xd4) + uVar12);
  iVar17 = 0;
  iVar1 = *(ushort *)(param_1 + 0xe6) - 1;
  pbVar11 = pbVar8;
  pbVar3 = pbVar9;
  pbVar4 = local_20;
  pbVar5 = (byte *)(*(int *)(param_1 + 0xdc) + 1 + uVar12);
joined_r0x1c00d40e:
  for (; iVar1 != 0; iVar1 = iVar1 + -1) {
    local_20 = local_20 + 1;
    pbVar8 = pbVar8 + 1;
    pbVar9 = pbVar9 + 1;
    if ((*pbVar5 & 0x20) == 0) goto LAB_1c00d582;
    switch(iVar17) {
    case 0:
      iVar10 = -0x28;
      iVar14 = -0x14;
      local_10 = 0x14;
      break;
    case 1:
      iVar10 = 0;
      iVar14 = 0;
      local_10 = 0;
      break;
    case 2:
      iVar10 = 0xf;
      iVar14 = 10;
      local_10 = -0xf;
      break;
    case 3:
      iVar10 = 0x19;
      goto LAB_1c00d46f;
    default:
      iVar10 = 0x1e;
LAB_1c00d46f:
      local_10 = -0x19;
      iVar14 = 0xf;
    }
    *pbVar3 = (char)((int)((uint)*pbVar3 * iVar10 + 0x32) / 100) + *pbVar3;
    *pbVar9 = *pbVar9 + (char)((int)((uint)*pbVar9 * iVar10 + 0x32) / 100);
    *pbVar11 = (char)((int)((*pbVar11 - 0x37) * iVar14 + 0x32) / 100) + *pbVar11;
    bVar6 = (char)((int)((*pbVar8 - 0x37) * local_10 + 0x32) / 100) + *pbVar8;
    *pbVar8 = bVar6;
    if ((2 < iVar17) && ((*pbVar5 & 0x10) == 0)) {
      *pbVar9 = bVar6 - 0x34;
    }
    if (iVar17 == 0) {
      iVar17 = (uint)*pbVar9 + (((uint)*pbVar11 - (uint)*pbVar8) - (uint)*pbVar4);
      cVar7 = (char)iVar17;
      if (iVar17 < 1) {
        *pbVar9 = *pbVar9 - cVar7;
      }
      else {
        *pbVar4 = cVar7 + *pbVar4;
      }
      if ((pbVar5[-2] & 0x20) != 0) {
        bVar6 = *pbVar3;
        *pbVar3 = *pbVar4;
        *pbVar4 = bVar6;
      }
    }
    iVar17 = 0;
    pbVar11 = pbVar8;
    pbVar3 = pbVar9;
    pbVar4 = local_20;
    pbVar5 = pbVar5 + 1;
  }
  goto LAB_1c00d594;
LAB_1c00d582:
  iVar17 = iVar17 + 1;
  pbVar5 = pbVar5 + 1;
  goto joined_r0x1c00d40e;
}


// ==== FUN_1c00d6e0 @ 1c00d6e0 size=155

void __cdecl FUN_1c00d6e0(int param_1)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *local_4;
  
  pbVar2 = *(byte **)(param_1 + 0xd8);
  uVar3 = (uint)*(ushort *)(param_1 + 0xe8);
  pbVar5 = *(byte **)(param_1 + 0xdc);
  local_4 = (byte *)0x0;
  pbVar4 = *(byte **)(param_1 + 0xd4);
  while (uVar3 != 0) {
    uVar3 = uVar3 - 1;
    if ((*pbVar5 & 0x20) != 0) {
      local_4 = pbVar4;
    }
    if (((*pbVar2 & 0xf0) != 0) && (local_4 != (byte *)0x0)) {
      if ((*pbVar2 & 0x80) == 0) {
        iVar1 = (uint)*pbVar4 * -0x50 + -0x32;
      }
      else {
        iVar1 = (uint)*pbVar4 * 0x1e + 0x32;
      }
      *pbVar4 = *pbVar4 + (char)(iVar1 / 100);
    }
    if ((*pbVar5 & 0x80) != 0) {
      local_4 = (byte *)0x0;
    }
    pbVar5 = pbVar5 + 1;
    pbVar4 = pbVar4 + 1;
    pbVar2 = pbVar2 + 1;
  }
  return;
}


// ==== FUN_1c00d780 @ 1c00d780 size=1279

void __cdecl FUN_1c00d780(int param_1)

{
  byte *pbVar1;
  ushort uVar2;
  undefined1 *puVar3;
  char cVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  char *pcVar9;
  byte bVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  undefined1 *puVar15;
  byte *pbVar16;
  byte *pbVar17;
  bool bVar18;
  uint local_28;
  int local_24;
  uint local_20;
  char *local_1c;
  byte *local_18;
  byte *local_14;
  char *local_10;
  byte *local_c;
  char *local_4;
  
  pbVar8 = *(byte **)(param_1 + 0xdc);
  puVar15 = *(undefined1 **)(param_1 + 0xc4);
  if (*(short *)(param_1 + 0xe6) == 0) {
    uVar2 = *(ushort *)(param_1 + 0xe8);
  }
  else {
    uVar2 = *(ushort *)(param_1 + 0xec);
  }
  puVar3 = *(undefined1 **)(param_1 + 0xcc);
  pcVar9 = *(char **)(param_1 + 200);
  for (uVar6 = (uint)uVar2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar15 = 0x37;
    puVar15 = puVar15 + 1;
    bVar5 = *pbVar8;
    pbVar8 = pbVar8 + 1;
    *pcVar9 = (bVar5 & 0xf) * '\x02' + '7';
    *puVar3 = 0x37;
    puVar3 = puVar3 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar6 = (uint)*(ushort *)(param_1 + 0xec);
  local_14 = (byte *)(*(int *)(param_1 + 0xdc) + uVar6);
  local_18 = (byte *)(*(int *)(param_1 + 0xc4) + uVar6);
  local_10 = (char *)(*(int *)(param_1 + 200) + uVar6);
  local_c = (byte *)(*(int *)(param_1 + 0xcc) + uVar6);
  local_4 = (char *)(*(int *)(param_1 + 0xd0) + uVar6);
  local_1c = (char *)(*(int *)(param_1 + 0xd4) + uVar6);
  iVar12 = *(ushort *)(param_1 + 0xe6) - 1;
  *local_18 = *local_10 - *local_4;
  *local_c = *local_10 - *local_1c;
  if (iVar12 < 1) {
    iVar12 = 0;
  }
  iVar13 = 0;
  pbVar8 = local_14;
  pbVar17 = local_18;
  pcVar9 = local_10;
  pbVar16 = local_c;
  while (iVar12 != 0) {
    local_4 = local_4 + 1;
    local_c = local_c + 1;
    local_10 = local_10 + 1;
    local_14 = local_14 + 1;
    local_18 = local_18 + 1;
    local_1c = local_1c + 1;
    if ((*local_14 & 0x20) == 0) {
      iVar13 = iVar13 + 1;
    }
    else {
      *local_18 = *local_10 - *local_4;
      *local_c = *local_10 - *local_1c;
      if (iVar13 != 0) {
        local_20 = (uint)*pbVar16;
        local_28 = (uint)*local_18;
        iVar7 = local_20 - local_28;
        local_24 = iVar7;
        if (iVar7 < 0) {
          local_24 = 0;
          cVar4 = (char)(iVar7 / 2);
          *pbVar16 = *pbVar16 - cVar4;
          *local_18 = *local_18 + cVar4;
        }
        if ((*local_14 & 0x10) == 0) {
          if (iVar13 == 1) {
            bVar5 = *pbVar16;
            pbVar17[1] = bVar5;
            pcVar9[1] = bVar5 - (char)(local_24 / 2);
            pbVar16[1] = pbVar17[1] - (char)local_24;
          }
          else if (iVar13 == 2) {
            bVar5 = *pbVar16;
            pbVar17[1] = bVar5;
            pcVar9[1] = bVar5 + (char)((local_24 * -0x1e + -0x32) / 100);
            bVar5 = (char)((local_24 * -0x3c + -0x32) / 100) + pbVar17[1];
            pbVar16[1] = bVar5;
            pbVar17[2] = bVar5;
            pcVar9[2] = bVar5 + (char)((local_24 * -0x14 + -0x32) / 100);
            pbVar16[2] = pbVar17[2] + (char)((local_24 * -0x28 + -0x32) / 100);
          }
          else {
            bVar5 = *pbVar16;
            iVar7 = bVar5 - 0x34;
            pbVar17[1] = bVar5;
            pcVar9[1] = bVar5 + (char)((iVar7 * -0x16 + -0x32) / 100);
            bVar5 = (char)((iVar7 * -0x2d + -0x32) / 100) + pbVar17[1];
            pbVar16[1] = bVar5;
            pbVar17[2] = bVar5;
            pcVar9[2] = bVar5 + (char)((iVar7 * -0x12 + -0x32) / 100);
            bVar5 = (char)((iVar7 * -0x23 + -0x32) / 100) + pbVar17[2];
            pbVar16[2] = bVar5;
            pbVar17[3] = bVar5;
            pbVar17 = pbVar17 + 3;
            pcVar9 = pcVar9 + 3;
            pbVar16 = pbVar16 + 3;
            *pcVar9 = bVar5 + (char)(((-5 - iVar7) * 10) / 100);
            pbVar8 = pbVar8 + 3;
            *pbVar16 = *pbVar17 + (char)((iVar7 * -0x14 + -0x32) / 100);
            iVar7 = iVar13 + -4;
            if (iVar13 != 3) {
              do {
                bVar5 = *pbVar16;
                pbVar17 = pbVar17 + 1;
                pcVar9 = pcVar9 + 1;
                *pbVar17 = bVar5;
                pbVar16[1] = bVar5;
                pbVar1 = pbVar8 + 1;
                pbVar16 = pbVar16 + 1;
                pbVar8 = pbVar8 + 1;
                *pcVar9 = bVar5 + (*pbVar1 & 0xf) * '\x02';
                bVar18 = iVar7 != 0;
                iVar7 = iVar7 + -1;
              } while (bVar18);
            }
          }
        }
        else {
          local_24 = local_24 / iVar13;
          if (iVar13 != 0) {
            do {
              iVar13 = iVar13 + -1;
              bVar5 = *pbVar16;
              pbVar17 = pbVar17 + 1;
              pcVar9 = pcVar9 + 1;
              pbVar16 = pbVar16 + 1;
              *pbVar17 = bVar5;
              *pcVar9 = bVar5 - (char)(local_24 / 2);
              *pbVar16 = *pbVar17 - (char)local_24;
            } while (iVar13 != 0);
          }
        }
      }
      iVar13 = 0;
      iVar12 = iVar12 + -1;
      pbVar8 = local_14;
      pbVar17 = local_18;
      pcVar9 = local_10;
      pbVar16 = local_c;
    }
  }
  uVar6 = (uint)*(ushort *)(param_1 + 0xe8);
  if ((*(byte *)(*(int *)(param_1 + 0xdc) + -1 + uVar6) & 0x20) == 0) {
    uVar11 = (uint)*(ushort *)(param_1 + 0xee);
    uVar14 = uVar6;
    if (*(short *)(param_1 + 0xe6) != 0) {
      uVar14 = (uVar6 - uVar11) - 1;
    }
    pbVar8 = (byte *)(*(int *)(param_1 + 0xc4) + uVar11);
    pcVar9 = (char *)(*(int *)(param_1 + 200) + uVar11);
    pbVar17 = (byte *)(uVar11 + *(int *)(param_1 + 0xcc));
    bVar5 = *(byte *)(*(int *)(param_1 + 0xe0) + -1 + uVar6) & 0xc;
    if (bVar5 == 4) {
      iVar12 = *pbVar17 - 0x25;
    }
    else {
      iVar12 = *pbVar17 - 0x37;
    }
    iVar12 = iVar12 / (int)uVar14;
    for (; uVar14 != 0; uVar14 = uVar14 - 1) {
      bVar10 = *pbVar17;
      pbVar8 = pbVar8 + 1;
      pbVar17 = pbVar17 + 1;
      pcVar9 = pcVar9 + 1;
      *pbVar8 = bVar10;
      bVar10 = bVar10 - (char)iVar12;
      *pbVar17 = bVar10;
      *pcVar9 = bVar10 + 2;
    }
    if (bVar5 == 8) {
      pbVar8 = *(byte **)(param_1 + 200);
      uVar14 = 0;
      for (; uVar6 != 0; uVar6 = uVar6 - 1) {
        bVar5 = *pbVar8;
        pbVar8 = pbVar8 + 1;
        uVar11 = (uint)bVar5;
        if (bVar5 <= uVar14) {
          uVar11 = uVar14;
        }
        uVar14 = uVar11;
      }
      *(char *)((*(ushort *)(param_1 + 0xe8) - 1) + *(int *)(param_1 + 0xcc)) =
           (char)((uVar14 * 0x78 + 0x32) / 100);
    }
  }
  return;
}


// ==== FUN_1c00dc80 @ 1c00dc80 size=475

void __cdecl FUN_1c00dc80(int param_1)

{
  uint *puVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  bool bVar5;
  byte *pbVar6;
  int iVar7;
  byte bVar8;
  byte *pbVar9;
  uint uVar10;
  int iVar11;
  uint local_c;
  
  iVar7 = *(int *)(param_1 + 0xf2);
  pbVar2 = *(byte **)(param_1 + 0xdc);
  pbVar3 = *(byte **)(param_1 + 0xc4);
  pbVar9 = *(byte **)(param_1 + 200);
  local_c = (uint)*(ushort *)(param_1 + 0xe8);
  pbVar6 = *(byte **)(param_1 + 0xcc);
  while (local_c != 0) {
    local_c = local_c - 1;
    iVar11 = iVar7;
    if ((*(byte *)(iVar7 + 0x16) & 0x80) == 0) {
      do {
        iVar7 = iVar11 + 0x1a;
        puVar1 = (uint *)(iVar11 + 0x30);
        iVar11 = iVar7;
      } while ((*puVar1 & 0x80) == 0);
    }
    uVar10 = *(uint *)(*(int *)(*(int *)(iVar7 + 8) + 0x1c) + *(short *)(iVar7 + 0xc) * 4);
    if (((uVar10 & 2) == 0) || (bVar4 = true, (uVar10 & 0x8000000) == 0)) {
      bVar4 = false;
    }
    if (((uVar10 & 2) == 0) || (bVar5 = true, (uVar10 & 0x8000000) != 0)) {
      bVar5 = false;
    }
    if ((*pbVar2 & 0x20) == 0) {
      bVar8 = *pbVar6;
      iVar11 = (((uint)*pbVar9 - (uint)bVar8) * 5 + 5) * 10;
    }
    else {
      if (bVar5) {
        *pbVar9 = *pbVar9 + (char)((int)((uint)*pbVar9 * 0x14 + -0x41a) / 100);
      }
      uVar10 = !bVar4 - 1 & 0x14;
      if (bVar5) {
        uVar10 = 0x50;
      }
      bVar5 = false;
      *pbVar3 = *pbVar3 + (char)((int)(((uint)*pbVar9 - (uint)*pbVar3) * uVar10 + 0x32) / 100);
      bVar4 = true;
      bVar8 = pbVar2[1] & 0x20;
      iVar11 = iVar7;
      while (bVar8 == 0) {
        uVar10 = *(uint *)(*(int *)(*(int *)(iVar11 + 0x22) + 0x1c) + *(short *)(iVar11 + 0x26) * 4)
        ;
        if ((bVar5) || (((uVar10 & 2) != 0 && ((uVar10 & 0x8000000) == 0)))) {
          bVar5 = true;
        }
        else {
          bVar5 = false;
        }
        if (((!bVar4) || ((uVar10 & 2) == 0)) || (bVar4 = true, (uVar10 & 0x8000000) == 0)) {
          bVar4 = false;
        }
        bVar8 = *(byte *)(iVar11 + 0x30) & 0x88;
        iVar11 = iVar11 + 0x1a;
      }
      iVar11 = 0x32;
      if (bVar5) {
        iVar11 = 0x42;
      }
      else if (bVar4) {
        iVar11 = 0x14;
      }
      bVar8 = *pbVar6;
      iVar11 = ((uint)*pbVar9 - (uint)bVar8) * iVar11 + 0x32;
    }
    pbVar2 = pbVar2 + 1;
    pbVar3 = pbVar3 + 1;
    pbVar9 = pbVar9 + 1;
    *pbVar6 = bVar8 + (char)(iVar11 / 100);
    pbVar6 = pbVar6 + 1;
  }
  return;
}


// ==== FUN_1c00de60 @ 1c00de60 size=161

void __cdecl FUN_1c00de60(int param_1)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  
  pcVar6 = *(char **)(param_1 + 0xf6);
  uVar2 = *(ushort *)(param_1 + 0x66);
  uVar3 = *(ushort *)(param_1 + 100);
  iVar7 = 0;
  iVar5 = (uint)*(ushort *)(pcVar6 + 0x18) << 8;
  cVar1 = *pcVar6;
  while (cVar1 != -1) {
    uVar4 = (uint)uVar3;
    if ((int)((uint)*(ushort *)(pcVar6 + 0x18) * 0x100) <= iVar5) {
      uVar4 = (uint)uVar2;
    }
    iVar7 = iVar7 + 1;
    iVar5 = iVar5 + ((uint)*(ushort *)(pcVar6 + 0x18) - (iVar5 >> 8)) * uVar4;
    *(short *)(pcVar6 + 0x18) = (short)((uint)iVar5 >> 8);
    cVar1 = pcVar6[0x20];
    pcVar6 = pcVar6 + 0x20;
  }
  iVar7 = iVar7 + -1;
  if (0 < iVar7) {
    do {
      uVar4 = (uint)uVar2;
      if ((int)((uint)*(ushort *)(pcVar6 + -8) * 0x100) < iVar5) {
        uVar4 = (uint)uVar3;
      }
      iVar5 = iVar5 + ((uint)*(ushort *)(pcVar6 + -8) - (iVar5 >> 8)) * uVar4;
      iVar7 = iVar7 + -1;
      *(short *)(pcVar6 + -8) = (short)((uint)iVar5 >> 8);
      pcVar6 = pcVar6 + -0x20;
    } while (iVar7 != 0);
  }
  return;
}


// ==== FUN_1c00df10 @ 1c00df10 size=1

void FUN_1c00df10(void)

{
  return;
}


// ==== FUN_1c00df20 @ 1c00df20 size=449

void __cdecl FUN_1c00df20(int param_1)

{
  *(int *)(param_1 + 0x13a) = param_1;
  *(undefined4 *)(param_1 + 0x188) = *(undefined4 *)(param_1 + 0xcc);
  *(undefined4 *)(param_1 + 0x142) = *(undefined4 *)(param_1 + 200);
  *(undefined2 *)(param_1 + 0x17e) = *(undefined2 *)(param_1 + 0xd6);
  *(undefined2 *)(param_1 + 0x180) = *(undefined2 *)(param_1 + 0xd4);
  *(undefined2 *)(param_1 + 0x3f2) = *(undefined2 *)(param_1 + 0xd4);
  *(undefined2 *)(param_1 + 0x182) = 0x2b11;
  *(undefined2 *)(param_1 + 0x186) = *(undefined2 *)(param_1 + 0xe0);
  *(undefined2 *)(param_1 + 0x19a) = *(undefined2 *)(param_1 + 0xe2);
  *(undefined2 *)(param_1 + 0x19c) = *(undefined2 *)(param_1 + 0xe4);
  *(undefined2 *)(param_1 + 0x19e) = *(undefined2 *)(param_1 + 0xe8);
  *(undefined2 *)(param_1 + 0x1a0) = *(undefined2 *)(param_1 + 0xea);
  *(undefined2 *)(param_1 + 0x18c) = *(undefined2 *)(param_1 + 0xd8);
  *(undefined2 *)(param_1 + 0x42c) = *(undefined2 *)(param_1 + 0xdc);
  *(undefined2 *)(param_1 + 0x1c4) = *(undefined2 *)(param_1 + 0xde);
  *(undefined2 *)(param_1 + 0x196) = *(undefined2 *)(param_1 + 0xf4);
  *(undefined2 *)(param_1 + 0x198) = *(undefined2 *)(param_1 + 0xf6);
  *(uint *)(param_1 + 400) = (uint)*(ushort *)(param_1 + 0xf2);
  *(undefined2 *)(param_1 + 0x194) = *(undefined2 *)(param_1 + 0xda);
  *(undefined4 *)(param_1 + 0x14e) = 0;
  *(undefined2 *)(param_1 + 0x1be) = *(undefined2 *)(param_1 + 0xf8);
  *(undefined2 *)(param_1 + 0x1c0) = *(undefined2 *)(param_1 + 0xfa);
  *(undefined2 *)(param_1 + 0x1c2) = *(undefined2 *)(param_1 + 0xfc);
  *(undefined2 *)(param_1 + 0x1b8) = *(undefined2 *)(param_1 + 0xfe);
  *(undefined2 *)(param_1 + 0x1ba) = *(undefined2 *)(param_1 + 0x100);
  *(undefined2 *)(param_1 + 0x1bc) = *(undefined2 *)(param_1 + 0x102);
  *(undefined2 *)(param_1 + 0x1c6) = *(undefined2 *)(param_1 + 0x10a);
  *(undefined2 *)(param_1 + 0x1c8) = *(undefined2 *)(param_1 + 0x10c);
  *(undefined2 *)(param_1 + 0x1ca) = *(undefined2 *)(param_1 + 0x10e);
  *(undefined2 *)(param_1 + 0x1cc) = *(undefined2 *)(param_1 + 0x104);
  *(undefined2 *)(param_1 + 0x1ce) = *(undefined2 *)(param_1 + 0x106);
  *(undefined2 *)(param_1 + 0x1d0) = *(undefined2 *)(param_1 + 0x108);
  *(undefined2 *)(param_1 + 0x1d2) = *(undefined2 *)(param_1 + 0x110);
  *(undefined2 *)(param_1 + 0x1d6) = *(undefined2 *)(param_1 + 0x114);
  *(undefined2 *)(param_1 + 0x1d4) = *(undefined2 *)(param_1 + 0x112);
  *(undefined2 *)(param_1 + 0x1d8) = *(undefined2 *)(param_1 + 0x116);
  *(undefined2 *)(param_1 + 0x1e6) = *(undefined2 *)(param_1 + 0x118);
  *(undefined2 *)(param_1 + 0x1e8) = 0;
  *(undefined2 *)(param_1 + 0x1e2) = 0x50;
  *(undefined2 *)(param_1 + 0x1e4) = 0x2ee;
  *(undefined4 *)(param_1 + 0x1a8) = 0;
  *(undefined2 *)(param_1 + 0x1ac) = 0;
  *(undefined4 *)(param_1 + 0x1ae) = 0;
  *(undefined2 *)(param_1 + 0x1a2) = 0x41;
  *(undefined2 *)(param_1 + 0x1a6) = 10;
  *(undefined2 *)(param_1 + 0x1ea) = 0x60;
  *(undefined2 *)(param_1 + 0x1ee) = 0x8c;
  *(undefined2 *)(param_1 + 0x1ec) = 200;
  *(undefined4 *)(param_1 + 0x452) = 0;
  *(undefined2 *)(param_1 + 0x44c) = 0xff;
  return;
}


// ==== FUN_1c00e0f0 @ 1c00e0f0 size=47

undefined4 __cdecl FUN_1c00e0f0(int param_1)

{
  int iVar1;
  
  iVar1 = DAT_1c014544;
  if (param_1 == 0) {
    return 1;
  }
  while( true ) {
    if (iVar1 == 0) {
      return 1;
    }
    if (iVar1 == param_1) break;
    iVar1 = *(int *)(iVar1 + 0x5a4);
  }
  return 0;
}


// ==== FUN_1c00e120 @ 1c00e120 size=466

void __cdecl FUN_1c00e120(undefined4 *param_1,uint param_2,short param_3)

{
  int iVar1;
  
  if (param_3 == 0x6a) {
    strncpy((char *)((int)param_1 + 0x4a),
            *(char **)((int)&PTR_DAT_1c013600 + (param_2 & 0xffff) * 0x4a),0x20);
    *param_1 = (char *)((int)param_1 + 0x4a);
    *(undefined1 *)((int)param_1 + 0x69) = 0;
  }
  iVar1 = (param_2 & 0xffff) * 0x4a;
  *(undefined2 *)(param_1 + 1) = *(undefined2 *)(&DAT_1c013604 + iVar1);
  *(undefined2 *)((int)param_1 + 6) = *(undefined2 *)(&DAT_1c013608 + iVar1);
  *(undefined2 *)(param_1 + 2) = *(undefined2 *)(&DAT_1c01360a + iVar1);
  *(undefined2 *)((int)param_1 + 10) = *(undefined2 *)(&DAT_1c01360c + iVar1);
  *(undefined2 *)(param_1 + 3) = *(undefined2 *)(&DAT_1c01360e + iVar1);
  *(undefined2 *)((int)param_1 + 0xe) = *(undefined2 *)(&DAT_1c013610 + iVar1);
  *(undefined2 *)(param_1 + 4) = *(undefined2 *)(&DAT_1c013612 + iVar1);
  *(undefined2 *)((int)param_1 + 0x12) = *(undefined2 *)(&DAT_1c013614 + iVar1);
  *(undefined2 *)(param_1 + 5) = *(undefined2 *)(&DAT_1c013616 + iVar1);
  *(undefined2 *)((int)param_1 + 0x16) = *(undefined2 *)(&DAT_1c013618 + iVar1);
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)(&DAT_1c01361a + iVar1);
  *(undefined2 *)((int)param_1 + 0x1a) = *(undefined2 *)(&DAT_1c01361c + iVar1);
  *(undefined2 *)(param_1 + 7) = *(undefined2 *)(&DAT_1c01361e + iVar1);
  *(undefined2 *)((int)param_1 + 0x1e) = *(undefined2 *)(&DAT_1c013620 + iVar1);
  *(undefined2 *)(param_1 + 8) = *(undefined2 *)(&DAT_1c013622 + iVar1);
  *(undefined2 *)((int)param_1 + 0x22) = *(undefined2 *)(&DAT_1c013624 + iVar1);
  *(undefined2 *)(param_1 + 9) = *(undefined2 *)(&DAT_1c013626 + iVar1);
  *(undefined2 *)((int)param_1 + 0x26) = *(undefined2 *)(&DAT_1c013628 + iVar1);
  *(undefined2 *)((int)param_1 + 0x2e) = *(undefined2 *)(&DAT_1c01362a + iVar1);
  *(undefined2 *)(param_1 + 0xc) = *(undefined2 *)(&DAT_1c01362c + iVar1);
  *(undefined2 *)((int)param_1 + 0x32) = *(undefined2 *)(&DAT_1c01362e + iVar1);
  *(undefined2 *)(param_1 + 10) = *(undefined2 *)(&DAT_1c013630 + iVar1);
  *(undefined2 *)((int)param_1 + 0x2a) = *(undefined2 *)(&DAT_1c013632 + iVar1);
  *(undefined2 *)(param_1 + 0xb) = *(undefined2 *)(&DAT_1c013634 + iVar1);
  *(undefined2 *)(param_1 + 0xd) = *(undefined2 *)(&DAT_1c013636 + iVar1);
  *(undefined2 *)((int)param_1 + 0x36) = *(undefined2 *)(&DAT_1c013638 + iVar1);
  *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(&DAT_1c01363a + iVar1);
  *(undefined2 *)((int)param_1 + 0x3a) = *(undefined2 *)(&DAT_1c01363c + iVar1);
  *(undefined2 *)(param_1 + 0xf) = *(undefined2 *)(&DAT_1c01363e + iVar1);
  *(undefined2 *)((int)param_1 + 0x3e) = *(undefined2 *)(&DAT_1c013640 + iVar1);
  *(undefined2 *)(param_1 + 0x10) = *(undefined2 *)(&DAT_1c013642 + iVar1);
  *(undefined2 *)((int)param_1 + 0x42) = *(undefined2 *)(&DAT_1c013644 + iVar1);
  *(undefined2 *)(param_1 + 0x11) = *(undefined2 *)(&DAT_1c013646 + iVar1);
  *(undefined2 *)((int)param_1 + 0x46) = *(undefined2 *)(&DAT_1c013648 + iVar1);
  *(undefined2 *)(param_1 + 0x12) = *(undefined2 *)(&DAT_1c013606 + iVar1);
  return;
}


// ==== FUN_1c00e300 @ 1c00e300 size=321

void __cdecl FUN_1c00e300(undefined4 *param_1,undefined4 *param_2,short param_3)

{
  int iVar1;
  
  if (param_3 == 0x6a) {
    for (iVar1 = 0x1a; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    }
    *(undefined2 *)param_1 = *(undefined2 *)param_2;
    return;
  }
  *(undefined2 *)(param_1 + 1) = *(undefined2 *)(param_2 + 1);
  *(undefined2 *)((int)param_1 + 6) = *(undefined2 *)((int)param_2 + 6);
  *(undefined2 *)(param_1 + 2) = *(undefined2 *)(param_2 + 2);
  *(undefined2 *)((int)param_1 + 10) = *(undefined2 *)((int)param_2 + 10);
  *(undefined2 *)(param_1 + 3) = *(undefined2 *)(param_2 + 3);
  *(undefined2 *)((int)param_1 + 0xe) = *(undefined2 *)((int)param_2 + 0xe);
  *(undefined2 *)(param_1 + 4) = *(undefined2 *)(param_2 + 4);
  *(undefined2 *)((int)param_1 + 0x12) = *(undefined2 *)((int)param_2 + 0x12);
  *(undefined2 *)(param_1 + 5) = *(undefined2 *)(param_2 + 5);
  *(undefined2 *)((int)param_1 + 0x16) = *(undefined2 *)((int)param_2 + 0x16);
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)(param_2 + 6);
  *(undefined2 *)((int)param_1 + 0x1a) = *(undefined2 *)((int)param_2 + 0x1a);
  *(undefined2 *)(param_1 + 7) = *(undefined2 *)(param_2 + 7);
  *(undefined2 *)((int)param_1 + 0x1e) = *(undefined2 *)((int)param_2 + 0x1e);
  *(undefined2 *)(param_1 + 8) = *(undefined2 *)(param_2 + 8);
  *(undefined2 *)((int)param_1 + 0x22) = *(undefined2 *)((int)param_2 + 0x22);
  *(undefined2 *)(param_1 + 9) = *(undefined2 *)(param_2 + 9);
  *(undefined2 *)((int)param_1 + 0x26) = *(undefined2 *)((int)param_2 + 0x26);
  *(undefined2 *)((int)param_1 + 0x2e) = *(undefined2 *)((int)param_2 + 0x2e);
  *(undefined2 *)(param_1 + 0xc) = *(undefined2 *)(param_2 + 0xc);
  *(undefined2 *)((int)param_1 + 0x32) = *(undefined2 *)((int)param_2 + 0x32);
  *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_2 + 10);
  *(undefined2 *)((int)param_1 + 0x2a) = *(undefined2 *)((int)param_2 + 0x2a);
  *(undefined2 *)(param_1 + 0xb) = *(undefined2 *)(param_2 + 0xb);
  *(undefined2 *)(param_1 + 0xd) = *(undefined2 *)(param_2 + 0xd);
  *(undefined2 *)((int)param_1 + 0x36) = *(undefined2 *)((int)param_2 + 0x36);
  *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)(param_2 + 0xe);
  *(undefined2 *)((int)param_1 + 0x3a) = *(undefined2 *)((int)param_2 + 0x3a);
  *(undefined2 *)(param_1 + 0xf) = *(undefined2 *)(param_2 + 0xf);
  *(undefined2 *)((int)param_1 + 0x3e) = *(undefined2 *)((int)param_2 + 0x3e);
  *(undefined2 *)(param_1 + 0x10) = *(undefined2 *)(param_2 + 0x10);
  *(undefined2 *)((int)param_1 + 0x42) = *(undefined2 *)((int)param_2 + 0x42);
  *(undefined2 *)(param_1 + 0x11) = *(undefined2 *)(param_2 + 0x11);
  *(undefined2 *)((int)param_1 + 0x46) = *(undefined2 *)((int)param_2 + 0x46);
  *(undefined2 *)(param_1 + 0x12) = *(undefined2 *)(param_2 + 0x12);
  return;
}


// ==== _SVOpenSpeech@20 @ 1c00e450 size=862

uint _SVOpenSpeech_20(undefined4 *param_1,undefined4 param_2,UINT param_3,uint param_4)

{
  undefined4 *puVar1;
  UINT UVar2;
  MMRESULT MVar3;
  undefined4 *_Memory;
  int iVar4;
  HWND pHVar5;
  uint uVar6;
  uint uVar7;
  WAVEFORMATEX local_14;
  
                    /* 0xe450  9  _SVOpenSpeech@20 */
  UVar2 = waveOutGetNumDevs();
  if (UVar2 == 0) {
    *param_1 = 0;
    return 0x1b63;
  }
  local_14.wFormatTag = 1;
  local_14.nSamplesPerSec = 0x2b11;
  local_14.nChannels = 1;
  local_14.nBlockAlign = 1;
  local_14.nAvgBytesPerSec = 0x2b11;
  local_14.wBitsPerSample = 8;
  MVar3 = waveOutOpen((LPHWAVEOUT)0x0,param_3,&local_14,0,0,1);
  if (MVar3 != 0) {
    *param_1 = 0;
    return 0x1b64;
  }
  _Memory = calloc(1,0x5a8);
  *param_1 = _Memory;
  if (_Memory == (undefined4 *)0x0) {
    return 0x1b5a;
  }
  uVar7 = 0;
  DAT_1c01456c = (HMODULE)0x0;
  DAT_1c014578 = (HMODULE)0x0;
  DAT_1c014574 = (HMODULE)0x0;
  if ((param_4 == 0) || ((param_4 & 1) != 0)) {
    DAT_1c01456c = FUN_1c00e7b0(s_TIENG32_DLL_1c014044,&DAT_1c012038);
    if (DAT_1c01456c == (HMODULE)0x0) {
      uVar7 = 0x1b6e;
    }
    else {
      _Memory[0x141] = _Memory[0x141] | 1;
    }
  }
  if ((param_4 & 2) != 0) {
    DAT_1c014578 = FUN_1c00e7b0(s_TISPAN32_DLL_1c014034,&DAT_1c01203c);
    if (DAT_1c014578 == (HMODULE)0x0) {
      uVar7 = 0x1b6e;
    }
    else {
      _Memory[0x141] = _Memory[0x141] | 2;
    }
  }
  if ((param_4 & 4) != 0) {
    DAT_1c014574 = FUN_1c00e7b0(s_TIGERM32_DLL_1c014024,&DAT_1c012040);
    if (DAT_1c014574 == (HMODULE)0x0) {
      uVar7 = 0x1b6e;
    }
    else {
      _Memory[0x141] = _Memory[0x141] | 4;
    }
  }
  if (_Memory[0x141] != 0) {
    *_Memory = param_2;
    _Memory[3] = param_3;
    _Memory[5] = 0x20001;
    _Memory[6] = 0x6a;
    if (DAT_1c01456c == (HMODULE)0x0) {
      if (DAT_1c014578 == (HMODULE)0x0) {
        _Memory[0x13e] = DAT_1c012040;
        iVar4 = DAT_1c012040;
      }
      else {
        _Memory[0x13e] = DAT_1c01203c;
        iVar4 = DAT_1c01203c;
      }
    }
    else {
      _Memory[0x13e] = DAT_1c012038;
      iVar4 = DAT_1c012038;
    }
    _Memory[0x13f] = iVar4;
    FUN_1c00e120(_Memory + 0x34,0,(short)_Memory[6]);
    _Memory[0x140] = *(undefined4 *)(_Memory[0x13f] + 0x14);
    pHVar5 = CreateWindowExA(0,s_NarratorClass_1c012024,s_SVperapp_1c014018,0x100000,0x23,0x23,0xfa,
                             0x6e,(HWND)0x0,(HMENU)0x0,DAT_1c0145b8,(LPVOID)0x0);
    _Memory[1] = pHVar5;
    if (pHVar5 != (HWND)0x0) {
      puVar1 = _Memory;
      if (DAT_1c014544 != (undefined4 *)0x0) {
        DAT_1c014570[0x169] = _Memory;
        puVar1 = DAT_1c014544;
      }
      DAT_1c014544 = puVar1;
      DAT_1c014570 = _Memory;
      uVar6 = FUN_1c00f460((int)_Memory);
      if (uVar6 == 0) {
        return uVar7;
      }
      DestroyWindow((HWND)_Memory[1]);
      free(_Memory);
      *param_1 = 0;
      if (DAT_1c01456c != (HMODULE)0x0) {
        FreeLibrary(DAT_1c01456c);
      }
      if (DAT_1c014578 != (HMODULE)0x0) {
        FreeLibrary(DAT_1c014578);
      }
      if (DAT_1c014574 != (HMODULE)0x0) {
        FreeLibrary(DAT_1c014574);
      }
      return uVar6;
    }
    free(_Memory);
    *param_1 = 0;
    if (DAT_1c01456c != (HMODULE)0x0) {
      FreeLibrary(DAT_1c01456c);
    }
    if (DAT_1c014578 != (HMODULE)0x0) {
      FreeLibrary(DAT_1c014578);
    }
    if (DAT_1c014574 != (HMODULE)0x0) {
      FreeLibrary(DAT_1c014574);
    }
    return 0x1b69;
  }
  free(_Memory);
  *param_1 = 0;
  return 0x1b6e;
}


// ==== FUN_1c00e7b0 @ 1c00e7b0 size=76

HMODULE __cdecl FUN_1c00e7b0(LPCSTR param_1,int *param_2)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  
  hModule = LoadLibraryA(param_1);
  if (hModule == (HMODULE)0x0) {
    return (HMODULE)0x0;
  }
  pFVar1 = GetProcAddress(hModule,s_LoadLanguage_1c014050);
  if (pFVar1 == (FARPROC)0x0) {
    FreeLibrary(hModule);
    return (HMODULE)0x0;
  }
  iVar2 = (*pFVar1)();
  *param_2 = iVar2;
  if (iVar2 == 0) {
    FreeLibrary(hModule);
    return (HMODULE)0x0;
  }
  return hModule;
}


// ==== _SVCloseSpeech@4 @ 1c00e800 size=324

undefined4 _SVCloseSpeech_4(void *param_1)

{
  void *pvVar1;
  int iVar2;
  
                    /* 0xe800  2  _SVCloseSpeech@4 */
  iVar2 = FUN_1c00e0f0((int)param_1);
  if (iVar2 != 0) {
    return 0x1b61;
  }
  if (DAT_1c01456c != (HMODULE)0x0) {
    FreeLibrary(DAT_1c01456c);
  }
  if (DAT_1c014578 != (HMODULE)0x0) {
    FreeLibrary(DAT_1c014578);
  }
  if (DAT_1c014574 != (HMODULE)0x0) {
    FreeLibrary(DAT_1c014574);
  }
  DAT_1c01456c = (HMODULE)0x0;
  DAT_1c014578 = (HMODULE)0x0;
  DAT_1c014574 = (HMODULE)0x0;
  FUN_1c00f4a0((int)param_1);
  pvVar1 = DAT_1c014544;
  DAT_1c014548 = DAT_1c014544;
  while ((DAT_1c014540 = pvVar1, DAT_1c014540 != (void *)0x0 && (param_1 != DAT_1c014540))) {
    DAT_1c014548 = DAT_1c014540;
    pvVar1 = *(void **)((int)DAT_1c014540 + 0x5a4);
  }
  if (DAT_1c014540 == (void *)0x0) {
    return 0x1b61;
  }
  if (*(int *)((int)param_1 + 0x2c) != 0) {
    _SVUnloadUserDictionary_8((int)param_1);
  }
  if (DAT_1c014544 == DAT_1c014540) {
    DAT_1c014544 = *(void **)((int)DAT_1c014540 + 0x5a4);
  }
  else if (DAT_1c014570 == DAT_1c014540) {
    DAT_1c014570 = DAT_1c014548;
  }
  else {
    *(undefined4 *)((int)DAT_1c014548 + 0x5a4) = *(undefined4 *)((int)DAT_1c014540 + 0x5a4);
  }
  *(undefined4 *)((int)param_1 + 0x5a4) = 0;
  DestroyWindow(*(HWND *)((int)param_1 + 4));
  free(param_1);
  return 0;
}


// ==== _SVSetRate@8 @ 1c00e950 size=66

undefined4 _SVSetRate_8(int param_1,ushort param_2)

{
  int iVar1;
  
                    /* 0xe950  23  _SVSetRate@8 */
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  if ((0x13 < param_2) && (param_2 < 0x1f5)) {
    *(ushort *)(param_1 + 0xd6) = param_2;
    return 0;
  }
  return 0x1b62;
}


// ==== _SVSetPitch@8 @ 1c00e9a0 size=66

undefined4 _SVSetPitch_8(int param_1,ushort param_2)

{
  int iVar1;
  
                    /* 0xe9a0  22  _SVSetPitch@8 */
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  if ((9 < param_2) && (param_2 < 0x7d1)) {
    *(ushort *)(param_1 + 0xd4) = param_2;
    return 0;
  }
  return 0x1b62;
}


// ==== _SVSetGender@8 @ 1c00e9f0 size=60

undefined4 _SVSetGender_8(int param_1,ushort param_2)

{
  int iVar1;
  
                    /* 0xe9f0  18  _SVSetGender@8 */
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  if (param_2 < 4) {
    *(ushort *)(param_1 + 0xd8) = param_2;
    return 0;
  }
  return 0x1b62;
}


// ==== _SVSetGlottalSource@8 @ 1c00ea30 size=60

undefined4 _SVSetGlottalSource_8(int param_1,ushort param_2)

{
  int iVar1;
  
                    /* 0xea30  19  _SVSetGlottalSource@8 */
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  if (param_2 < 9) {
    *(ushort *)(param_1 + 0xda) = param_2;
    return 0;
  }
  return 0x1b62;
}


// ==== _SVSetF0Style@8 @ 1c00ea70 size=60

undefined4 _SVSetF0Style_8(int param_1,ushort param_2)

{
  int iVar1;
  
                    /* 0xea70  17  _SVSetF0Style@8 */
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  if (param_2 < 5) {
    *(ushort *)(param_1 + 0xe0) = param_2;
    return 0;
  }
  return 0x1b62;
}


// ==== _SVSetF0Perturb@8 @ 1c00eab0 size=60

undefined4 _SVSetF0Perturb_8(int param_1,ushort param_2)

{
  int iVar1;
  
                    /* 0xeab0  15  _SVSetF0Perturb@8 */
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  if (param_2 < 0x1f5) {
    *(ushort *)(param_1 + 0xe4) = param_2;
    return 0;
  }
  return 0x1b62;
}


// ==== _SVSetF0Range@8 @ 1c00eaf0 size=60

undefined4 _SVSetF0Range_8(int param_1,ushort param_2)

{
  int iVar1;
  
                    /* 0xeaf0  16  _SVSetF0Range@8 */
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  if (param_2 < 0x1f5) {
    *(ushort *)(param_1 + 0xe2) = param_2;
    return 0;
  }
  return 0x1b62;
}


// ==== _SVSetAVBias@8 @ 1c00eb30 size=45

undefined4 _SVSetAVBias_8(int param_1,undefined2 param_2)

{
  int iVar1;
  
                    /* 0xeb30  14  _SVSetAVBias@8 */
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  *(undefined2 *)(param_1 + 0xf8) = param_2;
  return 0;
}


// ==== _SVSetAHBias@8 @ 1c00eb60 size=45

undefined4 _SVSetAHBias_8(int param_1,undefined2 param_2)

{
  int iVar1;
  
                    /* 0xeb60  13  _SVSetAHBias@8 */
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  *(undefined2 *)(param_1 + 0xfa) = param_2;
  return 0;
}


// ==== _SVSetAFBias@8 @ 1c00eb90 size=45

undefined4 _SVSetAFBias_8(int param_1,undefined2 param_2)

{
  int iVar1;
  
                    /* 0xeb90  12  _SVSetAFBias@8 */
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  *(undefined2 *)(param_1 + 0xfc) = param_2;
  return 0;
}


// ==== _SVSetVowelFactor@8 @ 1c00ebc0 size=45

undefined4 _SVSetVowelFactor_8(int param_1,undefined2 param_2)

{
  int iVar1;
  
                    /* 0xebc0  27  _SVSetVowelFactor@8 */
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  *(undefined2 *)(param_1 + 0xf2) = param_2;
  return 0;
}


// ==== _SVSetVoicingMode@8 @ 1c00ebf0 size=60

undefined4 _SVSetVoicingMode_8(int param_1,ushort param_2)

{
  int iVar1;
  
                    /* 0xebf0  26  _SVSetVoicingMode@8 */
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  if (param_2 < 3) {
    *(ushort *)(param_1 + 0xdc) = param_2;
    return 0;
  }
  return 0x1b62;
}


// ==== _SVSetPersonality@8 @ 1c00ec30 size=121

undefined4 _SVSetPersonality_8(int param_1,ushort param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_EDI;
  
                    /* 0xec30  21  _SVSetPersonality@8 */
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  if (param_2 < 0x14) {
    FUN_1c00e120((undefined4 *)(param_1 + 0xd0),CONCAT22((short)((uint)unaff_EDI >> 0x10),param_2),
                 0x6a);
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x4fc) + 0x14);
    switch(param_2) {
    case 1:
    case 5:
    case 0xd:
    case 0xf:
      uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x4fc) + 0x18);
    }
    *(undefined4 *)(param_1 + 0x500) = uVar2;
    return 0;
  }
  return 0x1b62;
}


// ==== _SVSetSpeakingMode@8 @ 1c00ecd0 size=75

undefined4 _SVSetSpeakingMode_8(int param_1,ushort param_2)

{
  int iVar1;
  
                    /* 0xecd0  24  _SVSetSpeakingMode@8 */
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  if ((param_2 & 7) == 0) {
    return 0x1b62;
  }
  if ((param_2 & 2) != 0) {
    *(uint *)(param_1 + 0xcc) = *(uint *)(param_1 + 0xcc) | 0x10;
    return 0;
  }
  *(uint *)(param_1 + 0xcc) = *(uint *)(param_1 + 0xcc) & 0xffffffef;
  return 0;
}


// ==== _SVGetErrorText@12 @ 1c00ed20 size=147

uint _SVGetErrorText_12(int param_1,char *param_2,ushort param_3)

{
  char cVar1;
  char *_Source;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  
                    /* 0xed20  4  _SVGetErrorText@12 */
  if (param_2 == (char *)0x0) {
    return 0x1b70;
  }
  if (param_3 == 0) {
    return 0;
  }
  if (param_1 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = param_1 + -7000;
  }
  if ((iVar4 < 0) || (0x18 < iVar4)) {
    iVar4 = 0x19;
  }
  _Source = (&PTR_s_No_error_1c013fb0)[iVar4];
  uVar3 = 0xffffffff;
  pcVar5 = _Source;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar2 = ~uVar3 - 1 & 0xffff;
  uVar3 = param_3 - 1;
  if ((int)uVar2 <= (int)(param_3 - 1)) {
    uVar3 = uVar2;
  }
  *param_2 = '\0';
  strncat(param_2,_Source,uVar3 & 0xffff);
  return -(uint)(iVar4 == 0x19) & 0x1b62;
}


// ==== _SVPause@4 @ 1c00edc0 size=150

int _SVPause_4(int param_1)

{
  int iVar1;
  MMRESULT MVar2;
  DWORD DVar3;
  
                    /* 0xedc0  10  _SVPause@4 */
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  if (*(int *)(param_1 + 0x1c) == 2) {
    MVar2 = waveOutPause(*(HWAVEOUT *)(param_1 + 8));
    if (MVar2 != 0) {
      return MVar2 + 0x1db0;
    }
    *(undefined4 *)(param_1 + 0x1c) = 4;
    DVar3 = timeGetTime();
    *(DWORD *)(param_1 + 0x24) = DVar3 - *(int *)(param_1 + 0x24);
    if (DAT_1c0145b4 != 0) {
      timeKillEvent(DAT_1c0145b4);
      DAT_1c0145b4 = 0;
    }
    if (DAT_1c0145a0 != 0) {
      timeEndPeriod(10);
      DAT_1c0145a0 = 0;
    }
  }
  return 0;
}


// ==== _SVResume@4 @ 1c00ee60 size=227

int _SVResume_4(DWORD_PTR param_1)

{
  int iVar1;
  MMRESULT MVar2;
  DWORD DVar3;
  int iVar4;
  
                    /* 0xee60  11  _SVResume@4 */
  iVar4 = 0;
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  if (*(int *)(param_1 + 0x1c) == 4) {
    if ((*(byte *)(param_1 + 0x188) & 0x40) == 0) {
      MVar2 = timeBeginPeriod(10);
      if (MVar2 != 0) {
        DAT_1c0145a0 = 0;
        return 0x1d50;
      }
      DAT_1c0145a0 = 1;
      DAT_1c0145b4 = timeSetEvent(0x32,10,FUN_1c00f700,param_1,1);
      if (DAT_1c0145b4 == 0) {
        timeEndPeriod(10);
        DAT_1c0145a0 = 0;
        return 0x1d51;
      }
    }
    MVar2 = waveOutRestart(*(HWAVEOUT *)(param_1 + 8));
    if (MVar2 == 0) {
      *(undefined4 *)(param_1 + 0x1c) = 2;
      iVar4 = 0;
    }
    else {
      iVar4 = MVar2 + 0x1db0;
      timeEndPeriod(10);
      DAT_1c0145a0 = 0;
      timeKillEvent(DAT_1c0145b4);
    }
    DVar3 = timeGetTime();
    *(DWORD *)(param_1 + 0x24) = DVar3 - *(int *)(param_1 + 0x24);
  }
  return iVar4;
}


// ==== _SVGetVersionInfo@4 @ 1c00ef50 size=47

undefined4 _SVGetVersionInfo_4(undefined4 *param_1)

{
                    /* 0xef50  5  _SVGetVersionInfo@4 */
  if (param_1 == (undefined4 *)0x0) {
    return 0x1b70;
  }
  param_1[1] = s_Microsoft_Corporation___TalkIt_1c014070;
  param_1[2] = s_August_30__1996_1c014060;
  *(undefined2 *)(param_1 + 3) = 0x6a;
  *param_1 = 0x20001;
  return 0;
}


// ==== _SVSetVoiceInfo@12 @ 1c00ef80 size=329

undefined4 _SVSetVoiceInfo_12(int param_1,undefined4 *param_2,short param_3)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  
                    /* 0xef80  25  _SVSetVoiceInfo@12 */
  iVar2 = FUN_1c00e0f0(param_1);
  if (iVar2 != 0) {
    return 0x1b61;
  }
  if (param_2 == (undefined4 *)0x0) {
    return 0x1b70;
  }
  uVar1 = *(ushort *)(param_2 + 1);
  if ((uVar1 < 10) || (2000 < uVar1)) {
    return 0x1b62;
  }
  if ((*(ushort *)((int)param_2 + 6) < 0x14) || (500 < *(ushort *)((int)param_2 + 6))) {
    return 0x1b62;
  }
  if (8 < *(ushort *)((int)param_2 + 10)) {
    return 0x1b62;
  }
  if (4 < *(ushort *)(param_2 + 4)) {
    return 0x1b62;
  }
  if (500 < *(ushort *)((int)param_2 + 0x12)) {
    return 0x1b62;
  }
  if (*(ushort *)(param_2 + 5) < 0x1f5) {
    _SVSetPitch_8(param_1,uVar1);
    _SVSetRate_8(param_1,*(ushort *)((int)param_2 + 6));
    _SVSetGlottalSource_8(param_1,*(ushort *)((int)param_2 + 10));
    _SVSetF0Perturb_8(param_1,*(ushort *)(param_2 + 5));
    _SVSetF0Range_8(param_1,*(ushort *)((int)param_2 + 0x12));
    _SVSetF0Style_8(param_1,*(ushort *)(param_2 + 4));
    if (*(short *)(param_2 + 2) == 1) {
      uVar3 = *(undefined4 *)(*(int *)(param_1 + 0x4fc) + 0x18);
    }
    else {
      uVar3 = *(undefined4 *)(*(int *)(param_1 + 0x4fc) + 0x14);
    }
    *(undefined4 *)(param_1 + 0x500) = uVar3;
    FUN_1c00e300((undefined4 *)(param_1 + 0xd0),param_2,param_3);
    return 0;
  }
  return 0x1b62;
}


// ==== _SVGetVoiceInfo@16 @ 1c00f0d0 size=124

undefined4 _SVGetVoiceInfo_16(int param_1,ushort param_2,undefined4 *param_3,short param_4)

{
  int iVar1;
  
                    /* 0xf0d0  6  _SVGetVoiceInfo@16 */
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  if (param_3 == (undefined4 *)0x0) {
    return 0x1b70;
  }
  if (param_2 < 0x14) {
    if (param_2 != 0xff) {
      FUN_1c00e120(param_3,(uint)param_2,param_4);
      return 0;
    }
  }
  else if (param_2 != 0xff) {
    return 0x1b62;
  }
  FUN_1c00e300(param_3,(undefined4 *)(param_1 + 0xd0),param_4);
  return 0;
}


// ==== FUN_1c00f150 @ 1c00f150 size=54

void __cdecl FUN_1c00f150(int param_1,int param_2)

{
  *(int *)(param_1 + 0x4f8) = param_2;
  *(int *)(param_1 + 0x4fc) = param_2;
  if (*(short *)(param_1 + 0xd8) != 1) {
    *(undefined4 *)(param_1 + 0x500) = *(undefined4 *)(param_2 + 0x14);
    return;
  }
  *(undefined4 *)(param_1 + 0x500) = *(undefined4 *)(param_2 + 0x18);
  return;
}


// ==== _SVSetLanguage@8 @ 1c00f190 size=157

undefined4 _SVSetLanguage_8(int param_1,int param_2)

{
  int iVar1;
  
                    /* 0xf190  20  _SVSetLanguage@8 */
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  if (param_2 == 1) {
    if (DAT_1c012038 == 0) {
      return 0x1b6e;
    }
    FUN_1c00f150(param_1,DAT_1c012038);
    return 0;
  }
  if (param_2 == 2) {
    if (DAT_1c01203c == 0) {
      return 0x1b6e;
    }
    FUN_1c00f150(param_1,DAT_1c01203c);
    return 0;
  }
  if (param_2 != 4) {
    return 0x1b6e;
  }
  if (DAT_1c012040 == 0) {
    return 0x1b6e;
  }
  FUN_1c00f150(param_1,DAT_1c012040);
  return 0;
}


// ==== _SVAbort@4 @ 1c00f230 size=148

undefined4 _SVAbort_4(int param_1)

{
  int iVar1;
  
                    /* 0xf230  1  _SVAbort@4 */
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 == 0) {
    if ((*(byte *)(param_1 + 0x1c) & 6) != 0) {
      *(undefined4 *)(param_1 + 0x452) = 1;
      waveOutReset(*(HWAVEOUT *)(param_1 + 8));
      *(undefined4 *)(param_1 + 0x1c) = 1;
    }
    while (DAT_1c01208c != 0) {
      PeekMessageA((LPMSG)&DAT_1c014550,*(HWND *)(param_1 + 4),0x3bd,0x3bd,1);
      TranslateMessage((MSG *)&DAT_1c014550);
      DispatchMessageA((MSG *)&DAT_1c014550);
    }
    return 0;
  }
  return 0x1b61;
}


// ==== _SVGetAvailableLanguages@8 @ 1c00f2d0 size=45

undefined4 _SVGetAvailableLanguages_8(int param_1,undefined4 *param_2)

{
  int iVar1;
  
                    /* 0xf2d0  3  _SVGetAvailableLanguages@8 */
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x504);
  return 0;
}


// ==== FUN_1c00f300 @ 1c00f300 size=206

undefined4 __cdecl FUN_1c00f300(int param_1)

{
  int iVar1;
  HGLOBAL pvVar2;
  LPVOID pvVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  pvVar2 = GlobalAlloc(0x2002,0x2000);
  if (pvVar2 != (HGLOBAL)0x0) {
    *(HGLOBAL *)(param_1 + 0xb8) = pvVar2;
    pvVar3 = GlobalLock(pvVar2);
    if (pvVar3 == (LPVOID)0x0) {
      return 0x1b5e;
    }
    *(LPVOID *)(param_1 + 0xbc) = pvVar3;
    iVar1 = 0;
    puVar5 = (undefined4 *)(param_1 + 0xa8);
    while( true ) {
      pvVar2 = GlobalAlloc(0x2002,0x20);
      if (pvVar2 == (HGLOBAL)0x0) {
        return 0x1b5c;
      }
      *puVar5 = pvVar2;
      puVar4 = GlobalLock(pvVar2);
      if (puVar4 == (undefined4 *)0x0) break;
      puVar5[1] = puVar4;
      puVar5 = puVar5 + 2;
      iVar1 = iVar1 + 1;
      *puVar4 = pvVar3;
      puVar4[1] = 0x1000;
      puVar4[4] = 0;
      puVar4[5] = 0;
      pvVar3 = (LPVOID)((int)pvVar3 + 0x1000);
      puVar4[3] = param_1;
      if (1 < iVar1) {
        return 0;
      }
    }
    return 0x1b5e;
  }
  return 0x1b5d;
}


// ==== FUN_1c00f3d0 @ 1c00f3d0 size=129

void __cdecl FUN_1c00f3d0(int param_1)

{
  HGLOBAL pvVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = FUN_1c00e0f0(param_1);
  if (iVar2 == 0) {
    puVar3 = (undefined4 *)(param_1 + 0xa8);
    iVar2 = 2;
    do {
      pvVar1 = (HGLOBAL)*puVar3;
      if (pvVar1 != (HGLOBAL)0x0) {
        if (puVar3[1] != 0) {
          GlobalUnlock(pvVar1);
        }
        GlobalFree(pvVar1);
        *puVar3 = 0;
        puVar3[1] = 0;
      }
      puVar3 = puVar3 + 2;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    pvVar1 = *(HGLOBAL *)(param_1 + 0xb8);
    if (pvVar1 != (HGLOBAL)0x0) {
      if (*(int *)(param_1 + 0xbc) != 0) {
        GlobalUnlock(pvVar1);
      }
      GlobalFree(pvVar1);
      *(undefined4 *)(param_1 + 0xb8) = 0;
      *(undefined4 *)(param_1 + 0xbc) = 0;
    }
  }
  return;
}


// ==== FUN_1c00f460 @ 1c00f460 size=56

uint __cdecl FUN_1c00f460(int param_1)

{
  int iVar1;
  HLOCAL pvVar2;
  
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  pvVar2 = LocalAlloc(0x40,0xce8);
  *(HLOCAL *)(param_1 + 0xa4) = pvVar2;
  return -(uint)(pvVar2 == (HLOCAL)0x0) & 0x1b5a;
}


// ==== FUN_1c00f4a0 @ 1c00f4a0 size=56

undefined4 __cdecl FUN_1c00f4a0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  if (*(HLOCAL *)(param_1 + 0xa4) != (HLOCAL)0x0) {
    LocalFree(*(HLOCAL *)(param_1 + 0xa4));
  }
  *(undefined4 *)(param_1 + 0xa4) = 0;
  return 0;
}


// ==== FUN_1c00f700 @ 1c00f700 size=182

void FUN_1c00f700(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  DWORD DVar6;
  uint uVar7;
  
  if ((*(byte *)(param_3 + 7) & 5) == 0) {
    iVar2 = param_3[9];
    iVar3 = param_3[0x29];
    uVar7 = (uint)*(ushort *)(iVar3 + 2);
    cVar1 = *(char *)(iVar3 + 0xc84 + uVar7);
    iVar4 = *(int *)(uVar7 * 0x20 + 8 + iVar3);
    while ((cVar1 != '\0' && (DVar6 = timeGetTime(), (uint)(iVar2 + iVar4) < DVar6))) {
      *(int *)(uVar7 * 0x20 + 8 + iVar3) = iVar2 + iVar4;
      iVar4 = uVar7 * 0x20 + iVar3;
      PostMessageA((HWND)*param_3,param_3[8],(uint)*(ushort *)(iVar4 + 0xc),iVar4 + 4);
      *(undefined1 *)(iVar3 + 0xc84 + uVar7) = 0;
      uVar5 = *(short *)(iVar3 + 2) + 1;
      *(ushort *)(iVar3 + 2) = uVar5;
      if (99 < uVar5) {
        *(undefined2 *)(iVar3 + 2) = 0;
      }
      uVar7 = (uint)*(ushort *)(iVar3 + 2);
      cVar1 = *(char *)(iVar3 + 0xc84 + uVar7);
      iVar4 = *(int *)(uVar7 * 0x20 + 8 + iVar3);
    }
  }
  return;
}


// ==== FUN_1c00f7c0 @ 1c00f7c0 size=429

void __cdecl FUN_1c00f7c0(int param_1)

{
  short sVar1;
  undefined4 *puVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  short *psVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  int local_8;
  int local_4;
  
  uVar9 = 0;
  puVar8 = *(undefined4 **)(param_1 + 0x1c);
  local_8 = 0;
  local_4 = 0;
  sVar1 = *(short *)(puVar8 + 3);
  puVar2 = puVar8;
  do {
    if (sVar1 == 0xff) {
      return;
    }
    psVar6 = (short *)*puVar2;
    if (psVar6 != (short *)0x0) {
      sVar1 = *psVar6;
      while (sVar1 != 0x1e) {
        if (*psVar6 == 0x2c6) {
          uVar3 = psVar6[1];
          if ((short)uVar3 < 0x15) {
            uVar3 = 0x14;
          }
          *(ushort *)(param_1 + 0xa8) = uVar3;
          *(short *)(param_1 + 0xaa) = (short)(60000 / (ulonglong)uVar3);
          break;
        }
        sVar1 = psVar6[2];
        if (sVar1 != 0) {
          if (sVar1 < 0) {
            psVar6[2] = (short)((int)((8 - (uint)*(ushort *)((int)puVar2 + 0xe)) * (int)sVar1) / 100
                               >> 3);
          }
          else {
            iVar7 = *(short *)((int)puVar2 + 0xe) + -8;
            if (sVar1 <= iVar7) {
              iVar7 = (int)sVar1;
            }
            psVar6[2] = (short)(iVar7 >> 3);
          }
        }
        psVar6 = psVar6 + 3;
        sVar1 = *psVar6;
      }
    }
    if ((*(byte *)((int)puVar2 + 0x17) & 4) != 0) {
      local_8 = (uint)*(ushort *)(param_1 + 0xaa) * local_8;
      if (local_8 != 0) {
        for (; local_4 != 0; local_4 = local_4 + -1) {
          uVar4 = ((uint)*(ushort *)((int)puVar8 + 0xe) * local_8) / uVar9;
          if (3999 < uVar4) {
            uVar4 = 4000;
          }
          if (uVar4 < 0x1a) {
            uVar4 = 0x19;
          }
          *(short *)((int)puVar8 + 0xe) = (short)uVar4;
          psVar6 = (short *)*puVar8;
          if (psVar6 != (short *)0x0) {
            sVar1 = *psVar6;
            while (sVar1 != 0x1e) {
              if (psVar6[2] != 0) {
                uVar4 = (uint)(psVar6[2] * local_8) / uVar9;
                uVar5 = *(ushort *)((int)puVar2 + 0xe) - 1;
                if (uVar5 <= uVar4) {
                  uVar4 = uVar5;
                }
                psVar6[2] = (short)uVar4;
              }
              psVar6 = psVar6 + 3;
              sVar1 = *psVar6;
            }
          }
          puVar8 = (undefined4 *)((int)puVar8 + 0x1a);
        }
      }
      uVar9 = 0;
      psVar6 = (short *)*puVar2;
      local_4 = 0;
      sVar1 = *psVar6;
      local_8 = 0;
      while (puVar8 = puVar2, sVar1 != 0x1e) {
        if (*psVar6 == 700) {
          local_8 = (int)psVar6[1];
          break;
        }
        psVar6 = psVar6 + 3;
        sVar1 = *psVar6;
      }
    }
    local_4 = local_4 + 1;
    uVar9 = uVar9 + *(ushort *)((int)puVar2 + 0xe);
    sVar1 = *(short *)((int)puVar2 + 0x26);
    puVar2 = (undefined4 *)((int)puVar2 + 0x1a);
  } while( true );
}


// ==== _SVTTS@32 @ 1c00f970 size=722

uint _SVTTS_32(undefined4 *param_1,byte *param_2,int *param_3,int *param_4,HWND param_5,uint param_6
              ,uint param_7)

{
  byte bVar1;
  char cVar2;
  void *_Memory;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  char *pcVar8;
  int iVar9;
  undefined4 *puVar10;
  char *pcVar11;
  int iVar12;
  int iVar13;
  byte *pbVar14;
  size_t _Count;
  char **ppcVar15;
  int local_c;
  
                    /* 0xf970  28  _SVTTS@32 */
  iVar4 = FUN_1c00e0f0((int)param_1);
  if (iVar4 != 0) {
    return 0x1b61;
  }
  if (param_2 == (byte *)0x0) {
    return 0x1b70;
  }
  uVar5 = param_6 & 0x80;
  if (uVar5 != 0) {
    if (param_3 == (int *)0x0) {
      return 0x1b70;
    }
    if (*param_3 == 0) {
      return 0x1b70;
    }
    if (param_4 == (int *)0x0) {
      return 0x1b70;
    }
  }
  iVar12 = 0;
  local_c = (-(uint)((param_6 & 4) == 0) & 0xfffffffd) + 6;
  iVar4 = 0;
  do {
    if (iVar12 == -1) {
      local_c = local_c + 2;
    }
    uVar7 = 0xffffffff;
    pbVar14 = param_2;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      bVar1 = *pbVar14;
      pbVar14 = pbVar14 + 1;
    } while (bVar1 != 0);
    _Count = (~uVar7 + 9) * local_c;
    pcVar6 = calloc(_Count,1);
    if (pcVar6 == (char *)0x0) {
      uVar7 = 0x1b5a;
      iVar13 = iVar4;
    }
    else {
      (&DAT_1c014220)[iVar4 * 2] = pcVar6;
      iVar13 = iVar4 + 1;
      (&DAT_1c014224)[iVar4 * 2] = _Count;
      iVar12 = _SVTextToPhon_24((int)param_1,param_2,pcVar6,_Count,param_6);
      if (iVar12 == 0) {
        uVar7 = 0;
      }
      else if (iVar12 == 0x1b5a) {
        uVar7 = 0x1b5a;
      }
      else {
        if (iVar12 == -1) {
          free(*(void **)(iVar13 * 8 + 0x1c014218));
        }
        else {
          param_2 = param_2 + -(iVar12 + 1);
          iVar4 = iVar13;
        }
        uVar7 = 0x1d4c;
        iVar13 = iVar4;
      }
    }
    iVar4 = iVar13;
  } while (uVar7 == 0x1d4c);
  if (uVar7 != 0) {
    if (uVar7 != 0x1b5a) {
      return uVar7;
    }
    if (0 < iVar13) {
      ppcVar15 = &DAT_1c014220;
      do {
        pcVar6 = *ppcVar15;
        ppcVar15 = ppcVar15 + 2;
        free(pcVar6);
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
    }
    return 0x1b5a;
  }
  uVar7 = 0xffffffff;
  pcVar6 = DAT_1c014220;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar2 != '\0');
  iVar12 = ~uVar7 - 1;
  iVar4 = iVar12;
  if (1 < iVar13) {
    puVar10 = &DAT_1c014228;
    iVar9 = iVar13 + -1;
    do {
      uVar7 = 0xffffffff;
      pcVar6 = (char *)*puVar10;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        cVar2 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar2 != '\0');
      puVar10 = puVar10 + 2;
      iVar4 = (~uVar7 - 1) + iVar4;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  pcVar6 = realloc(DAT_1c014220,iVar4 + 1);
  if (pcVar6 == (char *)0x0) {
    if (0 < iVar13) {
      ppcVar15 = &DAT_1c014220;
      do {
        pcVar6 = *ppcVar15;
        ppcVar15 = ppcVar15 + 2;
        free(pcVar6);
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
    }
    return 0x1b5a;
  }
  pcVar11 = pcVar6 + iVar12;
  if (1 < iVar13) {
    puVar10 = &DAT_1c014228;
    iVar13 = iVar13 + -1;
    do {
      pcVar8 = (char *)*puVar10;
      pcVar3 = pcVar11;
      do {
        pcVar11 = pcVar3;
        cVar2 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        *pcVar11 = cVar2;
        pcVar3 = pcVar11 + 1;
      } while (cVar2 != '\0');
      _Memory = (void *)*puVar10;
      puVar10 = puVar10 + 2;
      free(_Memory);
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
  }
  if (uVar5 == 0) {
    uVar7 = param_7 & 0xdfffffff | 0x40000000;
  }
  else {
    uVar7 = param_7 | 0x60000000;
  }
  uVar7 = _SVNarrate_20(param_1,pcVar6,param_5,uVar7);
  if (uVar7 != 0) {
    free(pcVar6);
    pcVar6 = (char *)0x0;
  }
  if (uVar5 != 0) {
    *param_3 = (int)pcVar6;
    if (pcVar6 == (char *)0x0) {
      *param_4 = 0;
      return uVar7;
    }
    uVar5 = 0xffffffff;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar2 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar2 != '\0');
    *param_4 = ~uVar5 - 1;
  }
  return uVar7;
}


// ==== _SVTextToPhon@24 @ 1c00fc50 size=952

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _SVTextToPhon_24(int param_1,byte *param_2,char *param_3,int param_4,uint param_5)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  uint uVar6;
  short sVar7;
  uint _C;
  char *pcVar8;
  byte *pbVar9;
  byte *pbVar10;
  char *pcVar11;
  int iVar12;
  char *local_4;
  
                    /* 0xfc50  29  _SVTextToPhon@24 */
  iVar3 = FUN_1c00e0f0(param_1);
  if (iVar3 != 0) {
    return 0x1b61;
  }
  if ((param_2 == (byte *)0x0) || (param_3 == (char *)0x0)) {
    return 0x1b70;
  }
  iVar3 = -1;
  DAT_1c014210 = 0x40;
  DAT_1c014211 = 0x77;
  DAT_1c014212 = 0;
  pbVar10 = param_2;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar1 = *pbVar10;
    pbVar10 = pbVar10 + 1;
  } while (bVar1 != 0);
  pcVar4 = calloc((int)(short)(~(ushort)iVar3 + 2),1);
  if (pcVar4 == (char *)0x0) {
    return 0x1b5a;
  }
  DAT_1c0141e0 = param_2;
  DAT_1c0141e4 = param_3;
  pbVar10 = (byte *)(pcVar4 + 1);
  DAT_1c0141f4 = param_4;
  iVar3 = 0;
  _DAT_1c0141f8 = param_5;
  _DAT_1c0141fc = 0;
  DAT_1c0141e8 = pcVar4;
  DAT_1c0141ec = pcVar4;
  *pcVar4 = ' ';
  bVar1 = *param_2;
  while (bVar1 != 0) {
    param_2 = param_2 + 1;
    iVar3 = iVar3 + 1;
    bVar1 = *param_2;
  }
  if (0x202 < iVar3) {
    *pbVar10 = 0;
    pbVar10 = (byte *)(pcVar4 + 2);
  }
  bVar1 = *DAT_1c0141e0;
  pbVar9 = DAT_1c0141e0;
  while (bVar1 != 0) {
    bVar1 = *pbVar9;
    pbVar9 = pbVar9 + 1;
    uVar6 = (uint)local_4 >> 8;
    local_4 = (char *)CONCAT31((int3)uVar6,bVar1);
    piVar5 = (int *)__p___mb_cur_max();
    if (*piVar5 < 2) {
      piVar5 = (int *)__p__pctype();
      uVar6 = *(ushort *)(*piVar5 + (uint)bVar1 * 2) & 2;
    }
    else {
      uVar6 = _isctype((uint)bVar1,2);
    }
    _C = (uint)bVar1;
    if (uVar6 == 0) {
      switch(_C) {
      case 0xa2:
      case 0xa3:
      case 0xa5:
      case 0xa9:
      case 0xae:
      case 0xb0:
      case 0xb1:
      case 0xbc:
      case 0xbd:
      case 0xbe:
      case 0xc1:
      case 0xc4:
      case 0xc9:
      case 0xcd:
      case 0xd1:
      case 0xd3:
      case 0xd6:
      case 0xd7:
      case 0xda:
      case 0xdc:
      case 0xdf:
      case 0xe1:
      case 0xe9:
      case 0xed:
      case 0xf1:
      case 0xf3:
      case 0xf7:
      case 0xfa:
        *pbVar10 = bVar1;
        break;
      default:
        if ((bVar1 == 0x5d) && ((param_5 & 4) == 0)) {
          *pbVar10 = 0x20;
        }
        else {
          piVar5 = (int *)__p___mb_cur_max();
          if (*piVar5 < 2) {
            piVar5 = (int *)__p__pctype();
            uVar6 = *(ushort *)(*piVar5 + _C * 2) & 0x157;
          }
          else {
            uVar6 = _isctype(_C,0x157);
          }
          if (uVar6 == 0) {
            *pbVar10 = 0x20;
          }
          else {
            *pbVar10 = bVar1;
          }
        }
        break;
      case 0xe4:
        *pbVar10 = 0xc4;
        break;
      case 0xf6:
        *pbVar10 = 0xd6;
        break;
      case 0xfc:
        *pbVar10 = 0xdc;
      }
    }
    else {
      iVar3 = toupper(_C);
      *pbVar10 = (byte)iVar3;
    }
    pbVar10 = pbVar10 + 1;
    bVar1 = *pbVar9;
  }
  *pbVar10 = 0;
  DAT_1c0141e8 = DAT_1c0141e8 + 1;
  pcVar4 = DAT_1c0141e8;
  *DAT_1c0141e4 = '\0';
  DAT_1c0141f4 = DAT_1c0141f4 + -1;
  do {
    pcVar8 = pcVar4;
    pcVar4 = pcVar8 + 1;
  } while (*pcVar8 == ' ');
  iVar3 = 0;
  DAT_1c014598 = *(int *)(param_1 + 0x4f8);
  cVar2 = *pcVar8;
  pcVar4 = local_4;
  do {
    if (cVar2 == '\0') {
LAB_1c00ffcc:
      iVar12 = 0;
      if (iVar3 == 1) {
        *pcVar4 = '\0';
        iVar12 = -1 - (int)local_4;
      }
      free(DAT_1c0141ec);
      return iVar12;
    }
    local_4 = pcVar8 + (-1 - (int)DAT_1c0141ec);
    if (((_DAT_1c0141f8 & 8) != 0) &&
       (((*pcVar8 != '{' && (pcVar8[1] != '{')) || ((_DAT_1c0141f8 & 0x10) != 0)))) {
      _ltoa((long)local_4,&DAT_1c014212,10);
      iVar3 = -1;
      DAT_1c014200 = &DAT_1c014210;
      pcVar11 = &DAT_1c014210;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        cVar2 = *pcVar11;
        pcVar11 = pcVar11 + 1;
      } while (cVar2 != '\0');
      sVar7 = ~(ushort)iVar3 - 1;
      if (DAT_1c0141f4 <= sVar7 + 2) {
        iVar3 = 1;
        goto LAB_1c00ffcc;
      }
      DAT_1c0141f4 = DAT_1c0141f4 - (sVar7 + 2);
      *DAT_1c0141e4 = ' ';
      pcVar4 = DAT_1c0141e4;
      for (; DAT_1c0141e4 = pcVar4 + 1, sVar7 != 0; sVar7 = sVar7 + -1) {
        *DAT_1c0141e4 = *DAT_1c014200;
        DAT_1c014200 = DAT_1c014200 + 1;
        pcVar4 = DAT_1c0141e4;
      }
      *DAT_1c0141e4 = ' ';
      DAT_1c0141e4 = DAT_1c0141e4 + 1;
      *DAT_1c0141e4 = '\0';
    }
    pcVar11 = DAT_1c0141e4;
    DAT_1c0141e0 = DAT_1c0141e0 + ((int)pcVar8 - (int)DAT_1c0141e8);
    DAT_1c0141e8 = pcVar8;
    _DAT_1c0141f0 = pcVar8;
    if (DAT_1c0141f4 < 2) {
      iVar3 = 1;
      goto LAB_1c00ffcc;
    }
    *DAT_1c0141e4 = ' ';
    DAT_1c0141e4 = DAT_1c0141e4 + 1;
    *DAT_1c0141e4 = '\0';
    DAT_1c0141f4 = DAT_1c0141f4 + -1;
    iVar3 = FUN_1c0100d0(0x1c0141e0);
    pcVar4 = pcVar11;
    if ((iVar3 != 0) ||
       (iVar3 = (**(code **)(DAT_1c014598 + 0xc))(param_1,PTR_DAT_1c014090), pcVar11 = DAT_1c0141e8,
       iVar3 != 0)) goto LAB_1c00ffcc;
    do {
      pcVar8 = pcVar11;
      pcVar11 = pcVar8 + 1;
    } while (*pcVar8 == ' ');
    cVar2 = *pcVar8;
  } while( true );
}


// ==== FUN_1c0100d0 @ 1c0100d0 size=196

undefined4 __cdecl FUN_1c0100d0(int param_1)

{
  char cVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  size_t _Count;
  byte *_Dest;
  char *pcVar6;
  
  _Dest = *(byte **)(param_1 + 4);
  pcVar2 = *(char **)(param_1 + 8);
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) & 0xfffffffb;
  if ((*(byte *)(param_1 + 0x18) & 0x10) != 0) {
    return 0;
  }
  if (*pcVar2 != '{') {
    return 0;
  }
  if (pcVar2[1] != '{') {
    return 0;
  }
  cVar1 = pcVar2[2];
  iVar5 = 0;
  for (pcVar6 = pcVar2 + 3;
      (cVar3 = '\0', cVar1 != '\0' && ((cVar1 != '}' || (cVar3 = '}', *pcVar6 != '}'))));
      pcVar6 = pcVar6 + 1) {
    cVar1 = *pcVar6;
    iVar5 = iVar5 + 1;
  }
  if (cVar3 == '}') {
    _Count = iVar5 + 2;
    if ((int)_Count <= *(int *)(param_1 + 0x14)) {
      strncat((char *)_Dest,pcVar2 + 1,_Count);
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - _Count;
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + _Count;
      *(char **)(param_1 + 8) = pcVar6 + 1;
      for (; iVar5 != 0; iVar5 = iVar5 + -1) {
        _Dest = _Dest + 1;
        iVar4 = tolower((uint)*_Dest);
        *_Dest = (byte)iVar4;
      }
      **(undefined1 **)(param_1 + 4) = 0;
      *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 4;
      return 0;
    }
    return 1;
  }
  return 0;
}


// ==== _SVLoadUserDictionary@8 @ 1c0101a0 size=678

undefined4 _SVLoadUserDictionary_8(int param_1,char *param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  size_t sVar4;
  void *_DstBuf;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  undefined4 *puVar11;
  
                    /* 0x101a0  7  _SVLoadUserDictionary@8 */
  iVar3 = FUN_1c00e0f0(param_1);
  if (iVar3 != 0) {
    return 0x1b61;
  }
  if (*(int *)(param_1 + 0x2c) != 0) {
    _SVUnloadUserDictionary_8(param_1);
  }
  uVar5 = 0xffffffff;
  DAT_1c0140e8 = &DAT_1c0140f0;
  DAT_1c0140f0 = 0;
  do {
    pcVar8 = param_2;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar8;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  iVar3 = -1;
  pcVar10 = &DAT_1c0140f0;
  do {
    pcVar9 = pcVar10;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar9 = pcVar10 + 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar9;
  } while (cVar1 != '\0');
  pcVar8 = pcVar8 + -uVar5;
  pcVar10 = pcVar9 + -1;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar10 = pcVar10 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar10 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar10 = pcVar10 + 1;
  }
  DAT_1c0140dc = (int)fopen(DAT_1c0140e8,&DAT_1c01409c);
  if ((FILE *)DAT_1c0140dc == (FILE *)0x0) {
    return 0x1b6a;
  }
  sVar4 = fread(&DAT_1c0140b0,1,4,(FILE *)DAT_1c0140dc);
  if (sVar4 != 4) {
    return 0x1b6b;
  }
  iVar3 = strncmp(&DAT_1c0140b0,&DAT_1c014094,4);
  if (iVar3 != 0) {
    return 0x1b6c;
  }
  sVar4 = fread(&DAT_1c0140b0,1,4,(FILE *)DAT_1c0140dc);
  if (sVar4 != 4) {
    return 0x1b6b;
  }
  sVar4 = fread(&DAT_1c0140b0,1,4,(FILE *)DAT_1c0140dc);
  if (sVar4 != 4) {
    return 0x1b6b;
  }
  sVar4 = fread(&DAT_1c0140b0,1,4,(FILE *)DAT_1c0140dc);
  if (sVar4 != 4) {
    return 0x1b6b;
  }
  sVar4 = fread(&DAT_1c0140b0,1,4,(FILE *)DAT_1c0140dc);
  if (sVar4 != 4) {
    return 0x1b6b;
  }
  sVar4 = fread(&DAT_1c0140b0,1,4,(FILE *)DAT_1c0140dc);
  if (sVar4 != 4) {
    return 0x1b6b;
  }
  sVar4 = fread(&DAT_1c0140e4,1,4,(FILE *)DAT_1c0140dc);
  if (sVar4 != 4) {
    return 0x1b6b;
  }
  *(undefined4 *)(param_1 + 0x28) = DAT_1c0140e4;
  sVar4 = fread(&DAT_1c0140e0,1,4,(FILE *)DAT_1c0140dc);
  if (sVar4 != 4) {
    return 0x1b6b;
  }
  puVar11 = &DAT_1c014170;
  *(int *)(param_1 + 0x2c) = DAT_1c0140e0;
  do {
    sVar4 = fread(puVar11,1,4,(FILE *)DAT_1c0140dc);
    if (sVar4 != 4) {
      return 0x1b6b;
    }
    puVar11 = puVar11 + 1;
  } while (puVar11 < &DAT_1c0141e0);
  _DstBuf = calloc(DAT_1c0140e0 + 1,1);
  if (_DstBuf == (void *)0x0) {
    return 0x1b5a;
  }
  *(void **)(param_1 + 0xa0) = _DstBuf;
  sVar4 = fread(_DstBuf,1,DAT_1c0140e0,(FILE *)DAT_1c0140dc);
  if (sVar4 != DAT_1c0140e0) {
    return 0x1b6b;
  }
  puVar11 = &DAT_1c014170;
  puVar7 = (undefined4 *)(param_1 + 0x30);
  do {
    uVar2 = *puVar11;
    puVar11 = puVar11 + 1;
    *puVar7 = uVar2;
    puVar7 = puVar7 + 1;
  } while (puVar11 < &DAT_1c0141e0);
  fclose((FILE *)DAT_1c0140dc);
  return 0;
}


// ==== _SVUnloadUserDictionary@8 @ 1c010450 size=65

undefined4 _SVUnloadUserDictionary_8(int param_1)

{
  int iVar1;
  
                    /* 0x10450  30  _SVUnloadUserDictionary@8 */
  iVar1 = FUN_1c00e0f0(param_1);
  if (iVar1 != 0) {
    return 0x1b61;
  }
  if (*(void **)(param_1 + 0xa0) != (void *)0x0) {
    free(*(void **)(param_1 + 0xa0));
  }
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  return 0;
}


// ==== FUN_1c0104a0 @ 1c0104a0 size=371

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1c0104a0(undefined4 param_1,int param_2)

{
  DWORD DVar1;
  undefined4 *puVar2;
  
  if (param_2 == 1) {
    DAT_1c0140a0 = DAT_1c0140a0 + 1;
  }
  else if (param_2 == 0) {
    if (DAT_1c0140a0 < 1) {
      return 0;
    }
    DAT_1c0140a0 = DAT_1c0140a0 + -1;
  }
  if (DAT_1c0140a4 == 0) {
    DVar1 = GetVersion();
    if (((char)DVar1 == '\x03') && ((DVar1 & 0x80000000) != 0)) {
      DAT_1c0140a4 = DAT_1c0140a4 + 1;
    }
    else {
      DAT_1c0140a4 = DAT_1c0140a4 + -1;
    }
  }
  _DAT_1c0145bc = *(undefined4 *)_adjust_fdiv_exref;
  if (param_2 != 1) {
    if ((param_2 == 0) &&
       (((DAT_1c0140a4 < 0 || (DAT_1c0140a0 == 0)) && (DAT_1c0145c4 != (undefined4 *)0x0)))) {
      puVar2 = DAT_1c0145c0 + -1;
      if (DAT_1c0145c4 <= puVar2) {
        do {
          if ((code *)*puVar2 != (code *)0x0) {
            (*(code *)*puVar2)();
          }
          puVar2 = puVar2 + -1;
        } while (DAT_1c0145c4 <= puVar2);
      }
      if (DAT_1c0140a4 < 0) {
        free(DAT_1c0145c4);
      }
      else {
        GlobalFree(DAT_1c0145c4);
      }
      DAT_1c0145c4 = (undefined4 *)0x0;
    }
    return 1;
  }
  if (-1 < DAT_1c0140a4) {
    if (DAT_1c0140a0 != 1) {
      return 1;
    }
    if (-1 < DAT_1c0140a4) {
      DAT_1c0145c4 = GlobalAlloc(0x2000,0x80);
      if (DAT_1c0145c4 == (undefined4 *)0x0) {
        return 0;
      }
      goto LAB_1c01056d;
    }
  }
  DAT_1c0145c4 = malloc(0x80);
  if (DAT_1c0145c4 == (undefined4 *)0x0) {
    return 0;
  }
LAB_1c01056d:
  *DAT_1c0145c4 = 0;
  DAT_1c0145c0 = DAT_1c0145c4;
  initterm(&DAT_1c012000,&DAT_1c012004);
  return 1;
}


// ==== entry @ 1c010620 size=169

int entry(HINSTANCE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if ((param_2 == 0) && (DAT_1c0140a0 == 0)) {
    return 0;
  }
  if ((param_2 == 1) || (param_2 == 2)) {
    if (DAT_1c0145c8 != (code *)0x0) {
      iVar2 = (*DAT_1c0145c8)(param_1,param_2,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_1c010695;
    iVar2 = FUN_1c0104a0(param_1,param_2);
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_1c001000(param_1,param_2);
  }
LAB_1c010695:
  if ((param_2 == 0) || (param_2 == 3)) {
    iVar2 = FUN_1c0104a0(param_1,param_2);
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    if ((iVar1 != 0) && (DAT_1c0145c8 != (code *)0x0)) {
      iVar1 = (*DAT_1c0145c8)(param_1,param_2,param_3);
    }
  }
  return iVar1;
}


