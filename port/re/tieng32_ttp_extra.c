// ==== FUN_1c208a80 @ 1c208a80 size=522

undefined4 FUN_1c208a80(char *param_1,undefined4 param_2,char *param_3)

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
    pcVar8 = (&PTR_DAT_1c24cfc8)[iVar6];
  }
  else {
    uVar4 = 0xffffffff;
    pcVar8 = (&PTR_DAT_1c24d040)[iVar6 / 10];
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
    pcVar8 = (&PTR_DAT_1c24cfc8)[iVar6 % 10];
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
    pcVar8 = (&PTR_DAT_1c24cfc8)[iVar7];
  }
  else {
    uVar4 = 0xffffffff;
    pcVar8 = (&PTR_DAT_1c24d040)[iVar7 / 10];
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
    pcVar8 = (&PTR_DAT_1c24cfc8)[iVar7 % 10];
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
    pcVar8 = (&PTR_DAT_1c24cfc8)[iVar1];
  }
  else {
    uVar4 = 0xffffffff;
    pcVar8 = (&PTR_DAT_1c24d040)[iVar1 / 10];
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
    pcVar8 = (&PTR_DAT_1c24cfc8)[iVar1 % 10];
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


// ==== FUN_1c208c90 @ 1c208c90 size=642

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1c208c90(byte *param_1,undefined4 param_2,char *param_3)

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
  
  DAT_1c250130 = 0x23;
  pbVar5 = &DAT_1c24ed88;
  iVar9 = 0;
  DAT_1c250131 = 0x23;
  DAT_1c250132 = 0x23;
  _DAT_1c24ed88 = 0;
  bVar2 = *param_1;
  while (param_1 = param_1 + 1, bVar2 != 0x3a) {
    *pbVar5 = bVar2;
    pbVar5 = pbVar5 + 1;
    iVar9 = (char)bVar2 + -0x30 + iVar9 * 10;
    bVar2 = *param_1;
  }
  FUN_1c207890(&DAT_1c24ed88,(byte *)0x0,param_3);
  uVar6 = 0xffffffff;
  pcVar11 = (char *)0x1c24cc3c;
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
    pcVar11 = &DAT_1c24cc38;
  }
  else {
    pcVar11 = (char *)0x1c24cc34;
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
  pbVar5 = &DAT_1c24ed88;
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar10 = *pcVar11;
    pcVar11 = pcVar11 + 1;
    pcVar10 = pcVar10 + 1;
  }
  _DAT_1c24ed88 = 0;
  bVar2 = *param_1;
  while (pbVar4 = param_1 + 1, bVar2 != 0x3a) {
    *pbVar5 = bVar2;
    pbVar5 = pbVar5 + 1;
    iVar9 = (char)bVar2 + -0x30 + iVar9 * 10;
    param_1 = pbVar4;
    bVar2 = *pbVar4;
  }
  FUN_1c207890(&DAT_1c24ed88,(byte *)0x0,param_3);
  uVar6 = 0xffffffff;
  pcVar11 = (char *)0x1c24cc28;
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
    pcVar11 = &DAT_1c24cc38;
  }
  else {
    pcVar11 = (char *)0x1c24cc24;
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
  pbVar5 = &DAT_1c24ed88;
  for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar10 = *pcVar11;
    pcVar11 = pcVar11 + 1;
    pcVar10 = pcVar10 + 1;
  }
  _DAT_1c24ed88 = 0;
  bVar2 = *pbVar4;
  if (bVar2 != 0x30) {
    pbVar5 = (byte *)0x1c24ed89;
    _DAT_1c24ed88 = (uint)bVar2;
  }
  bVar3 = param_1[2];
  *pbVar5 = bVar3;
  pbVar5[1] = 0;
  FUN_1c207890(&DAT_1c24ed88,(byte *)0x0,param_3);
  uVar6 = 0xffffffff;
  pcVar11 = (char *)0x1c24cc18;
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
    pcVar11 = (char *)0x1c24cc34;
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
  pcVar11 = &DAT_1c24cc38;
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


// ==== FUN_1c208f20 @ 1c208f20 size=205

undefined4 FUN_1c208f20(int param_1,byte *param_2,char *param_3)

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
      pcVar6 = &DAT_1c24cc44;
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
      FUN_1c209290((char *)(param_1 + 1),param_2,param_3);
      uVar3 = 0xffffffff;
      pcVar6 = (char *)&DAT_1c24cbd4;
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


// ==== FUN_1c209120 @ 1c209120 size=206

undefined4 FUN_1c209120(char *param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  uVar2 = 0xffffffff;
  pcVar5 = *(char **)(&DAT_1c24cf08 + *param_1 * 4);
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
  pcVar5 = (char *)&DAT_1c24cbd4;
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
  FUN_1c209290(param_1 + 2,param_2,param_3);
  uVar2 = 0xffffffff;
  pcVar5 = (char *)&DAT_1c24cbd4;
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
  FUN_1c208ff0(param_1 + 6,param_2,param_3);
  return 1;
}


// ==== FUN_1c209380 @ 1c209380 size=497

undefined4 FUN_1c209380(byte *param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  
  if (*param_1 == 0x30) {
    FUN_1c209580(param_1,&param_2,param_3);
    return 1;
  }
  iVar2 = (char)*param_1 + -0x30;
  iVar7 = (char)param_1[1] + -0x30;
  iVar5 = (char)param_1[2] + -0x30;
  iVar6 = (char)param_1[3] + -0x30;
  if (iVar7 * 10 + iVar5 == 0) {
    uVar3 = 0xffffffff;
    pcVar10 = (&PTR_DAT_1c24cfc8)[iVar2];
    do {
      pcVar8 = pcVar10;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar8 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar8;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    iVar2 = -1;
    pcVar10 = param_3;
    do {
      pcVar9 = pcVar10;
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      pcVar9 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar9;
    } while (cVar1 != '\0');
    pcVar10 = pcVar8 + -uVar3;
    pcVar8 = pcVar9 + -1;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar8 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar8 = pcVar8 + 1;
    }
    uVar3 = 0xffffffff;
    pcVar10 = (char *)0x1c24cc68;
    do {
      pcVar8 = pcVar10;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar8 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar8;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    iVar2 = -1;
    pcVar10 = param_3;
    do {
      pcVar9 = pcVar10;
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      pcVar9 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar9;
    } while (cVar1 != '\0');
    pcVar10 = pcVar8 + -uVar3;
    pcVar8 = pcVar9 + -1;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar8 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar8 = pcVar8 + 1;
    }
    if (iVar6 == 0) {
      return 1;
    }
    pcVar10 = (&PTR_DAT_1c24cfc8)[iVar6];
    goto LAB_1c209537;
  }
  if (iVar2 == 1) {
    pcVar10 = (&PTR_DAT_1c24cfc8)[(char)param_1[1] + -0x26];
LAB_1c2094ac:
    uVar3 = 0xffffffff;
    do {
      pcVar8 = pcVar10;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar8 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar8;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    iVar2 = -1;
    pcVar10 = param_3;
    do {
      pcVar9 = pcVar10;
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      pcVar9 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar9;
    } while (cVar1 != '\0');
    pcVar10 = pcVar8 + -uVar3;
    pcVar8 = pcVar9 + -1;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar8 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar8 = pcVar8 + 1;
    }
  }
  else {
    uVar3 = 0xffffffff;
    pcVar10 = (&PTR_DAT_1c24d040)[iVar2];
    do {
      pcVar8 = pcVar10;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar8 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar8;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    iVar2 = -1;
    pcVar10 = param_3;
    do {
      pcVar9 = pcVar10;
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      pcVar9 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar9;
    } while (cVar1 != '\0');
    pcVar10 = pcVar8 + -uVar3;
    pcVar8 = pcVar9 + -1;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar8 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar8 = pcVar8 + 1;
    }
    if (iVar7 != 0) {
      pcVar10 = (&PTR_DAT_1c24cfc8)[iVar7];
      goto LAB_1c2094ac;
    }
  }
  iVar2 = iVar6 + iVar5 * 10;
  if (iVar2 == 0) {
    pcVar10 = &DAT_1c24cc58;
  }
  else if (iVar5 == 1) {
    pcVar10 = (&PTR_DAT_1c24cfc8)[iVar2];
  }
  else {
    uVar3 = 0xffffffff;
    pcVar10 = (&PTR_DAT_1c24d040)[iVar5];
    do {
      pcVar8 = pcVar10;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar8 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar8;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    iVar2 = -1;
    pcVar10 = param_3;
    do {
      pcVar9 = pcVar10;
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      pcVar9 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar9;
    } while (cVar1 != '\0');
    pcVar10 = pcVar8 + -uVar3;
    pcVar8 = pcVar9 + -1;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar8 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar8 = pcVar8 + 1;
    }
    if (iVar6 == 0) {
      return 1;
    }
    pcVar10 = (&PTR_DAT_1c24cfc8)[iVar6];
  }
LAB_1c209537:
  uVar3 = 0xffffffff;
  do {
    pcVar8 = pcVar10;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar8 = pcVar10 + 1;
    cVar1 = *pcVar10;
    pcVar10 = pcVar8;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  iVar2 = -1;
  do {
    pcVar10 = param_3;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar10 = param_3 + 1;
    cVar1 = *param_3;
    param_3 = pcVar10;
  } while (cVar1 != '\0');
  pcVar8 = pcVar8 + -uVar3;
  pcVar10 = pcVar10 + -1;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
    pcVar8 = pcVar8 + 4;
    pcVar10 = pcVar10 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar10 = *pcVar8;
    pcVar8 = pcVar8 + 1;
    pcVar10 = pcVar10 + 1;
  }
  return 1;
}


