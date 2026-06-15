// v23 annotated: sub_114C98 @ 0x114c98
// Original: 114c98_sub_114C98.c
// Primary struct: <unclustered>
//
// sub_114C98 @ 0x114c98, size 218 bytes
// Doc: sub_1214C98 [util]: stack-saving helper with argument byte fetch and null check
// sub_1214C98 [util]: stack-saving helper with argument byte fetch and null check
int __fastcall sub_114C98(int a1, int a2, int a3, int a4, char a5)
{
  _BYTE *v5; // r8
  _DWORD *v8; // r7
  int v9; // r0
  _DWORD *v10; // r2
  _BYTE *v11; // r3
  unsigned int *v12; // r2
  _DWORD *v13; // r6
  _DWORD *v14; // r5
  _DWORD *v15; // r4
  unsigned int v17; // r3
  unsigned int v18; // r1
  unsigned int v19; // r1
  _BYTE *v20; // r3
  _DWORD *v21; // r4
  _DWORD *v22; // r3
  _BYTE *v23; // r2

  if ( a1 )
    return 1;
  if ( a2 )
    return 2;
  v5 = off_114DB8;
  if ( *(_BYTE *)off_114DB8 )
  {
    v8 = off_114D74;
  }
  else
  {
    v22 = off_114D98;
    v8 = off_114D74;
    *(_DWORD *)off_114DA8 = off_114D74;
    *v22 = 196608;
    sub_12ECB0(dword_114DAC, 38, 196608);
    v23 = off_114DA4;
    *(_DWORD *)(*((_DWORD *)off_114DB0 + 2) + 216) = dword_114DB4;
    v23[806] = -4;
    *v5 = 1;
  }
  v9 = dword_114D7C;
  *(_DWORD *)off_114D78 = 196608;
  sub_12ECB0(v9, 38, 196608);
  v10 = off_114D84;
  *(_DWORD *)off_114D80 = a3;
  v11 = off_114D88;
  *v10 = a4;
  v12 = (unsigned int *)off_114D8C;
  *v11 = a5;
  v13 = off_114D94;
  v14 = off_114D98;
  v15 = off_114D9C;
  v17 = *v12 & 0xFFFFFFFC;
  *(_DWORD *)off_114D90 = 0;
  *v8 = 0;
  *v12 = v17;
  v18 = *v12;
  v13[3] = 0;
  *v12 = v18 & 0xFFFFFFF3;
  *v14 = 4980736;
  *v15 = 0x10000;
  *v14 = 0x4000000;
  *v15 = 0x4000000;
  v19 = *v12;
  v20 = off_114DA0;
  v21 = off_114DA4;
  *((_BYTE *)off_114DA0 + 16) = 0;
  *v12 = v19 & 0xFFCFFFFF;
  v20[36] = 0;
  v20[56] = 0;
  v20[76] = 0;
  v20[96] = 0;
  v20[116] = 0;
  v21[1] = 64;
  return 0;
}

