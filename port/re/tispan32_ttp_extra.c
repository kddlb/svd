// ==== FUN_1c408750 @ 1c408750 size=522

undefined4 FUN_1c408750(char *param_1,undefined4 param_2,char *param_3)

{
  int iVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  
  iVar6 = 0;
  cVar2 = *param_1;
  while (cVar2 != '/') {
    iVar6 = *param_1 + -0x30 + iVar6 * 10;
    cVar2 = param_1[1];
    param_1 = param_1 + 1;
  }
  iVar7 = 0;
  cVar2 = param_1[1];
  pcVar8 = param_1 + 1;
  while (cVar2 != '/') {
    iVar7 = *pcVar8 + -0x30 + iVar7 * 10;
    cVar2 = pcVar8[1];
    pcVar8 = pcVar8 + 1;
  }
  iVar1 = pcVar8[2] + -0x30 + (pcVar8[1] * 5 + -0xf0) * 2;
  if (iVar6 < 0x14) {
    pcVar8 = (&PTR_DAT_1c40eb98)[iVar6];
  }
  else {
    uVar4 = 0xffffffff;
    pcVar8 = (&PTR_DAT_1c40ec10)[iVar6 / 10];
    do {
      pcVar9 = pcVar8;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar9 = pcVar8 + 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar9;
    } while (cVar2 != '\0');
    uVar4 = ~uVar4;
    iVar3 = -1;
    pcVar8 = param_3;
    do {
      pcVar10 = pcVar8;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar10 = pcVar8 + 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar10;
    } while (cVar2 != '\0');
    pcVar8 = pcVar9 + -uVar4;
    pcVar9 = pcVar10 + -1;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar9 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar9 = pcVar9 + 1;
    }
    pcVar8 = (&PTR_DAT_1c40eb98)[iVar6 % 10];
  }
  uVar4 = 0xffffffff;
  do {
    pcVar9 = pcVar8;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar8 + 1;
    cVar2 = *pcVar8;
    pcVar8 = pcVar9;
  } while (cVar2 != '\0');
  uVar4 = ~uVar4;
  iVar6 = -1;
  pcVar8 = param_3;
  do {
    pcVar10 = pcVar8;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar10 = pcVar8 + 1;
    cVar2 = *pcVar8;
    pcVar8 = pcVar10;
  } while (cVar2 != '\0');
  pcVar8 = pcVar9 + -uVar4;
  pcVar9 = pcVar10 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar9 = pcVar9 + 1;
  }
  if (iVar7 < 0x14) {
    pcVar8 = (&PTR_DAT_1c40eb98)[iVar7];
  }
  else {
    uVar4 = 0xffffffff;
    pcVar8 = (&PTR_DAT_1c40ec10)[iVar7 / 10];
    do {
      pcVar9 = pcVar8;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar9 = pcVar8 + 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar9;
    } while (cVar2 != '\0');
    uVar4 = ~uVar4;
    iVar6 = -1;
    pcVar8 = param_3;
    do {
      pcVar10 = pcVar8;
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      pcVar10 = pcVar8 + 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar10;
    } while (cVar2 != '\0');
    pcVar8 = pcVar9 + -uVar4;
    pcVar9 = pcVar10 + -1;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar9 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar9 = pcVar9 + 1;
    }
    pcVar8 = (&PTR_DAT_1c40eb98)[iVar7 % 10];
  }
  uVar4 = 0xffffffff;
  do {
    pcVar9 = pcVar8;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar8 + 1;
    cVar2 = *pcVar8;
    pcVar8 = pcVar9;
  } while (cVar2 != '\0');
  uVar4 = ~uVar4;
  iVar6 = -1;
  pcVar8 = param_3;
  do {
    pcVar10 = pcVar8;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar10 = pcVar8 + 1;
    cVar2 = *pcVar8;
    pcVar8 = pcVar10;
  } while (cVar2 != '\0');
  pcVar8 = pcVar9 + -uVar4;
  pcVar9 = pcVar10 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar9 = pcVar9 + 1;
  }
  if (iVar1 < 0x14) {
    pcVar8 = (&PTR_DAT_1c40eb98)[iVar1];
  }
  else {
    uVar4 = 0xffffffff;
    pcVar8 = (&PTR_DAT_1c40ec10)[iVar1 / 10];
    do {
      pcVar9 = pcVar8;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar9 = pcVar8 + 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar9;
    } while (cVar2 != '\0');
    uVar4 = ~uVar4;
    iVar6 = -1;
    pcVar8 = param_3;
    do {
      pcVar10 = pcVar8;
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      pcVar10 = pcVar8 + 1;
      cVar2 = *pcVar8;
      pcVar8 = pcVar10;
    } while (cVar2 != '\0');
    pcVar8 = pcVar9 + -uVar4;
    pcVar9 = pcVar10 + -1;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar8;
      pcVar8 = pcVar8 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar9 = *pcVar8;
      pcVar8 = pcVar8 + 1;
      pcVar9 = pcVar9 + 1;
    }
    pcVar8 = (&PTR_DAT_1c40eb98)[iVar1 % 10];
  }
  uVar4 = 0xffffffff;
  do {
    pcVar9 = pcVar8;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar8 + 1;
    cVar2 = *pcVar8;
    pcVar8 = pcVar9;
  } while (cVar2 != '\0');
  uVar4 = ~uVar4;
  iVar6 = -1;
  do {
    pcVar8 = param_3;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar8 = param_3 + 1;
    cVar2 = *param_3;
    param_3 = pcVar8;
  } while (cVar2 != '\0');
  pcVar9 = pcVar9 + -uVar4;
  pcVar8 = pcVar8 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar8 = *(undefined4 *)pcVar9;
    pcVar9 = pcVar9 + 4;
    pcVar8 = pcVar8 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar8 = *pcVar9;
    pcVar9 = pcVar9 + 1;
    pcVar8 = pcVar8 + 1;
  }
  return 1;
}


// ==== FUN_1c408960 @ 1c408960 size=642

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1c408960(byte *param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  
  DAT_1c411d80 = 0x23;
  pbVar5 = &DAT_1c4109d0;
  iVar9 = 0;
  DAT_1c411d81 = 0x23;
  DAT_1c411d82 = 0x23;
  _DAT_1c4109d0 = 0;
  bVar2 = *param_1;
  while (param_1 = param_1 + 1, bVar2 != 0x3a) {
    *pbVar5 = bVar2;
    pbVar5 = pbVar5 + 1;
    iVar9 = (char)bVar2 + -0x30 + iVar9 * 10;
    bVar2 = *param_1;
  }
  FUN_1c4073d0(&DAT_1c4109d0,(byte *)0x0,param_3);
  uVar6 = 0xffffffff;
  pcVar11 = &DAT_1c40e76c;
  do {
    pcVar10 = pcVar11;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar10 = pcVar11 + 1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar10;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  iVar7 = -1;
  pcVar11 = param_3;
  do {
    pcVar12 = pcVar11;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    pcVar12 = pcVar11 + 1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar12;
  } while (cVar1 != '\0');
  pcVar11 = pcVar10 + -uVar6;
  pcVar10 = pcVar12 + -1;
  for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar11;
    pcVar11 = pcVar11 + 4;
    pcVar10 = pcVar10 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar10 = *pcVar11;
    pcVar11 = pcVar11 + 1;
    pcVar10 = pcVar10 + 1;
  }
  if (iVar9 == 1) {
    pcVar11 = (char *)&DAT_1c40e768;
  }
  else {
    pcVar11 = &DAT_1c40e764;
  }
  uVar6 = 0xffffffff;
  do {
    pcVar10 = pcVar11;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar10 = pcVar11 + 1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar10;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  iVar9 = -1;
  pcVar11 = param_3;
  do {
    pcVar12 = pcVar11;
    if (iVar9 == 0) break;
    iVar9 = iVar9 + -1;
    pcVar12 = pcVar11 + 1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar12;
  } while (cVar1 != '\0');
  pcVar11 = pcVar10 + -uVar6;
  pcVar10 = pcVar12 + -1;
  for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar11;
    pcVar11 = pcVar11 + 4;
    pcVar10 = pcVar10 + 4;
  }
  iVar9 = 0;
  pbVar5 = &DAT_1c4109d0;
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar10 = *pcVar11;
    pcVar11 = pcVar11 + 1;
    pcVar10 = pcVar10 + 1;
  }
  _DAT_1c4109d0 = 0;
  bVar2 = *param_1;
  while (pbVar4 = param_1 + 1, bVar2 != 0x3a) {
    *pbVar5 = bVar2;
    pbVar5 = pbVar5 + 1;
    iVar9 = (char)bVar2 + -0x30 + iVar9 * 10;
    param_1 = pbVar4;
    bVar2 = *pbVar4;
  }
  FUN_1c4073d0(&DAT_1c4109d0,(byte *)0x0,param_3);
  uVar6 = 0xffffffff;
  pcVar11 = &DAT_1c40e758;
  do {
    pcVar10 = pcVar11;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar10 = pcVar11 + 1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar10;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  iVar7 = -1;
  pcVar11 = param_3;
  do {
    pcVar12 = pcVar11;
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    pcVar12 = pcVar11 + 1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar12;
  } while (cVar1 != '\0');
  pcVar11 = pcVar10 + -uVar6;
  pcVar10 = pcVar12 + -1;
  for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar11;
    pcVar11 = pcVar11 + 4;
    pcVar10 = pcVar10 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar10 = *pcVar11;
    pcVar11 = pcVar11 + 1;
    pcVar10 = pcVar10 + 1;
  }
  if (iVar9 == 1) {
    pcVar11 = (char *)&DAT_1c40e768;
  }
  else {
    pcVar11 = &DAT_1c40e754;
  }
  uVar6 = 0xffffffff;
  do {
    pcVar10 = pcVar11;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar10 = pcVar11 + 1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar10;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  iVar9 = -1;
  pcVar11 = param_3;
  do {
    pcVar12 = pcVar11;
    if (iVar9 == 0) break;
    iVar9 = iVar9 + -1;
    pcVar12 = pcVar11 + 1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar12;
  } while (cVar1 != '\0');
  pcVar11 = pcVar10 + -uVar6;
  pcVar10 = pcVar12 + -1;
  for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar11;
    pcVar11 = pcVar11 + 4;
    pcVar10 = pcVar10 + 4;
  }
  pbVar5 = &DAT_1c4109d0;
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar10 = *pcVar11;
    pcVar11 = pcVar11 + 1;
    pcVar10 = pcVar10 + 1;
  }
  _DAT_1c4109d0 = 0;
  bVar2 = *pbVar4;
  if (bVar2 != 0x30) {
    pbVar5 = &DAT_1c4109d1;
    _DAT_1c4109d0 = (uint)bVar2;
  }
  bVar3 = param_1[2];
  *pbVar5 = bVar3;
  pbVar5[1] = 0;
  FUN_1c4073d0(&DAT_1c4109d0,(byte *)0x0,param_3);
  uVar6 = 0xffffffff;
  pcVar11 = &DAT_1c40e748;
  do {
    pcVar10 = pcVar11;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar10 = pcVar11 + 1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar10;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  iVar9 = -1;
  pcVar11 = param_3;
  do {
    pcVar12 = pcVar11;
    if (iVar9 == 0) break;
    iVar9 = iVar9 + -1;
    pcVar12 = pcVar11 + 1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar12;
  } while (cVar1 != '\0');
  pcVar11 = pcVar10 + -uVar6;
  pcVar10 = pcVar12 + -1;
  for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar11;
    pcVar11 = pcVar11 + 4;
    pcVar10 = pcVar10 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar10 = *pcVar11;
    pcVar11 = pcVar11 + 1;
    pcVar10 = pcVar10 + 1;
  }
  if (((char)bVar2 * 5 + -0xf0) * 2 + -0x30 + (int)(char)bVar3 != 1) {
    uVar6 = 0xffffffff;
    pcVar11 = &DAT_1c40e764;
    do {
      pcVar10 = pcVar11;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar10 = pcVar11 + 1;
      cVar1 = *pcVar11;
      pcVar11 = pcVar10;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    iVar9 = -1;
    do {
      pcVar11 = param_3;
      if (iVar9 == 0) break;
      iVar9 = iVar9 + -1;
      pcVar11 = param_3 + 1;
      cVar1 = *param_3;
      param_3 = pcVar11;
    } while (cVar1 != '\0');
    pcVar10 = pcVar10 + -uVar6;
    pcVar11 = pcVar11 + -1;
    for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
      *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar11 = pcVar11 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar11 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar11 = pcVar11 + 1;
    }
    return 1;
  }
  uVar6 = 0xffffffff;
  pcVar11 = (char *)&DAT_1c40e768;
  do {
    pcVar10 = pcVar11;
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    pcVar10 = pcVar11 + 1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar10;
  } while (cVar1 != '\0');
  uVar6 = ~uVar6;
  iVar9 = -1;
  do {
    pcVar11 = param_3;
    if (iVar9 == 0) break;
    iVar9 = iVar9 + -1;
    pcVar11 = param_3 + 1;
    cVar1 = *param_3;
    param_3 = pcVar11;
  } while (cVar1 != '\0');
  pcVar10 = pcVar10 + -uVar6;
  pcVar11 = pcVar11 + -1;
  for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
    pcVar10 = pcVar10 + 4;
    pcVar11 = pcVar11 + 4;
  }
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar11 = *pcVar10;
    pcVar10 = pcVar10 + 1;
    pcVar11 = pcVar11 + 1;
  }
  return 1;
}


// ==== FUN_1c408bf0 @ 1c408bf0 size=205

undefined4 FUN_1c408bf0(int param_1,byte *param_2,char *param_3)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  
  if (param_2 != (byte *)0x0) {
    piVar2 = (int *)__p___mb_cur_max();
    if (*piVar2 < 2) {
      piVar2 = (int *)__p__pctype();
      uVar3 = *(ushort *)(*piVar2 + (uint)*param_2 * 2) & 4;
    }
    else {
      uVar3 = _isctype((uint)*param_2,4);
    }
    if (uVar3 != 0) {
      uVar3 = 0xffffffff;
      pcVar6 = &DAT_1c40e4f4;
      do {
        pcVar7 = pcVar6;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar7 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar7;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      iVar4 = -1;
      pcVar6 = param_3;
      do {
        pcVar8 = pcVar6;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar8 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar8;
      } while (cVar1 != '\0');
      pcVar6 = pcVar7 + -uVar3;
      pcVar7 = pcVar8 + -1;
      for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar7 = *pcVar6;
        pcVar6 = pcVar6 + 1;
        pcVar7 = pcVar7 + 1;
      }
      FUN_1c408f60((char *)(param_1 + 1),param_2,param_3);
      uVar3 = 0xffffffff;
      pcVar6 = (char *)&DAT_1c40e710;
      do {
        pcVar7 = pcVar6;
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        pcVar7 = pcVar6 + 1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar7;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      iVar4 = -1;
      do {
        pcVar6 = param_3;
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        pcVar6 = param_3 + 1;
        cVar1 = *param_3;
        param_3 = pcVar6;
      } while (cVar1 != '\0');
      pcVar7 = pcVar7 + -uVar3;
      pcVar6 = pcVar6 + -1;
      for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        *(undefined4 *)pcVar6 = *(undefined4 *)pcVar7;
        pcVar7 = pcVar7 + 4;
        pcVar6 = pcVar6 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *pcVar6 = *pcVar7;
        pcVar7 = pcVar7 + 1;
        pcVar6 = pcVar6 + 1;
      }
      return 1;
    }
  }
  return 0;
}


// ==== FUN_1c408df0 @ 1c408df0 size=206

undefined4 FUN_1c408df0(char *param_1,undefined4 param_2,char *param_3)

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
  FUN_1c408f60(param_1 + 2,param_2,param_3);
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
  FUN_1c408cc0(param_1 + 6,param_2,param_3);
  return 1;
}


// ==== FUN_1c4090f0 @ 1c4090f0 size=740

undefined4 FUN_1c4090f0(byte *param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  
  if (*param_1 == 0x30) {
    FUN_1c409400(param_1,&param_2,param_3);
    return 1;
  }
  bVar2 = param_1[1];
  iVar3 = (char)*param_1 + -0x30;
  iVar8 = (char)bVar2 + -0x30;
  iVar7 = (char)param_1[2] + -0x30;
  iVar6 = (char)param_1[3] + -0x30;
  if (1 < iVar3) {
    uVar4 = 0xffffffff;
    pcVar10 = (&PTR_DAT_1c40eb98)[iVar3];
    do {
      pcVar9 = pcVar10;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar9 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar9;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar3 = -1;
    pcVar10 = param_3;
    do {
      pcVar11 = pcVar10;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar11 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar11;
    } while (cVar1 != '\0');
    pcVar10 = pcVar9 + -uVar4;
    pcVar9 = pcVar11 + -1;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar9 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar9 = pcVar9 + 1;
    }
  }
  uVar4 = 0xffffffff;
  pcVar10 = s_MIY5L_1c40e7b0;
  do {
    pcVar9 = pcVar10;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar10 + 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar3 = -1;
  pcVar10 = param_3;
  do {
    pcVar11 = pcVar10;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar11 = pcVar10 + 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar11;
  } while (cVar1 != '\0');
  pcVar10 = pcVar9 + -uVar4;
  pcVar9 = pcVar11 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar10;
    pcVar10 = pcVar10 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar10;
    pcVar10 = pcVar10 + 1;
    pcVar9 = pcVar9 + 1;
  }
  if (iVar8 == 0) goto LAB_1c409336;
  switch((int)(char)bVar2) {
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x36:
  case 0x38:
    uVar4 = 0xffffffff;
    pcVar10 = (&PTR_DAT_1c40eb98)[iVar8];
    do {
      pcVar9 = pcVar10;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar9 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar9;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar3 = -1;
    pcVar10 = param_3;
    do {
      pcVar11 = pcVar10;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar11 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar11;
    } while (cVar1 != '\0');
    pcVar10 = pcVar9 + -uVar4;
    pcVar9 = pcVar11 + -1;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar9 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar9 = pcVar9 + 1;
    }
  case 0x31:
    uVar4 = 0xffffffff;
    pcVar10 = &DAT_1c40e534;
    do {
      pcVar9 = pcVar10;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar9 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar9;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar3 = -1;
    pcVar10 = param_3;
    do {
      pcVar11 = pcVar10;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar11 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar11;
    } while (cVar1 != '\0');
    pcVar10 = pcVar9 + -uVar4;
    pcVar9 = pcVar11 + -1;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar9 = pcVar9 + 4;
    }
    break;
  case 0x35:
    uVar4 = 0xffffffff;
    pcVar10 = &DAT_1c40e528;
    do {
      pcVar9 = pcVar10;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar9 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar9;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar3 = -1;
    pcVar10 = param_3;
    do {
      pcVar11 = pcVar10;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar11 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar11;
    } while (cVar1 != '\0');
    pcVar10 = pcVar9 + -uVar4;
    pcVar9 = pcVar11 + -1;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar9 = pcVar9 + 4;
    }
    break;
  case 0x37:
    uVar4 = 0xffffffff;
    pcVar10 = &DAT_1c40e7a0;
    do {
      pcVar9 = pcVar10;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar9 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar9;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar3 = -1;
    pcVar10 = param_3;
    do {
      pcVar11 = pcVar10;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar11 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar11;
    } while (cVar1 != '\0');
    pcVar10 = pcVar9 + -uVar4;
    pcVar9 = pcVar11 + -1;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar9 = pcVar9 + 4;
    }
    break;
  case 0x39:
    uVar4 = 0xffffffff;
    pcVar10 = &DAT_1c40e790;
    do {
      pcVar9 = pcVar10;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar9 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar9;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar3 = -1;
    pcVar10 = param_3;
    do {
      pcVar11 = pcVar10;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar11 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar11;
    } while (cVar1 != '\0');
    pcVar10 = pcVar9 + -uVar4;
    pcVar9 = pcVar11 + -1;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar9 = pcVar9 + 4;
    }
    break;
  default:
    goto switchD_1c4091c5_default;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar10;
    pcVar10 = pcVar10 + 1;
    pcVar9 = pcVar9 + 1;
  }
switchD_1c4091c5_default:
  if (iVar8 < 2) {
    if (iVar7 + iVar6 == 0) {
      pcVar10 = &DAT_1c40e4f4;
    }
    else {
      pcVar10 = &DAT_1c40e4f8;
    }
  }
  else {
    pcVar10 = (char *)&DAT_1c40e500;
  }
  uVar4 = 0xffffffff;
  do {
    pcVar9 = pcVar10;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar10 + 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar3 = -1;
  pcVar10 = param_3;
  do {
    pcVar11 = pcVar10;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar11 = pcVar10 + 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar11;
  } while (cVar1 != '\0');
  pcVar10 = pcVar9 + -uVar4;
  pcVar9 = pcVar11 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar10;
    pcVar10 = pcVar10 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar9 = *pcVar10;
    pcVar10 = pcVar10 + 1;
    pcVar9 = pcVar9 + 1;
  }
LAB_1c409336:
  if (iVar7 < 2) {
    iVar6 = iVar6 + iVar7 * 10;
    if (iVar6 == 0) {
      return 1;
    }
    pcVar10 = (&PTR_DAT_1c40eb98)[iVar6];
  }
  else {
    if (iVar6 == 0) {
      pcVar10 = (&PTR_DAT_1c40ebe8)[iVar7];
    }
    else {
      pcVar10 = (&PTR_DAT_1c40ec10)[iVar7];
    }
    uVar4 = 0xffffffff;
    do {
      pcVar9 = pcVar10;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar9 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar9;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar3 = -1;
    pcVar10 = param_3;
    do {
      pcVar11 = pcVar10;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar11 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar11;
    } while (cVar1 != '\0');
    pcVar10 = pcVar9 + -uVar4;
    pcVar9 = pcVar11 + -1;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar9 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar9 = pcVar9 + 1;
    }
    if (iVar6 == 0) {
      return 1;
    }
    pcVar10 = (&PTR_DAT_1c40eb98)[iVar6];
  }
  uVar4 = 0xffffffff;
  do {
    pcVar9 = pcVar10;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar9 = pcVar10 + 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar9;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar6 = -1;
  do {
    pcVar10 = param_3;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar10 = param_3 + 1;
    cVar1 = *param_3;
    param_3 = pcVar10;
  } while (cVar1 != '\0');
  pcVar9 = pcVar9 + -uVar4;
  pcVar10 = pcVar10 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
    pcVar9 = pcVar9 + 4;
    pcVar10 = pcVar10 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar10 = *pcVar9;
    pcVar9 = pcVar9 + 1;
    pcVar10 = pcVar10 + 1;
  }
  return 1;
}


