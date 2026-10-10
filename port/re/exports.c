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


