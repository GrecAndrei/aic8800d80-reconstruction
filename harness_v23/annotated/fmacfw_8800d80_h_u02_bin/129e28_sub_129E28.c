// v23 annotated: sub_129E28 @ 0x129e28
// Original: 129e28_sub_129E28.c
// Primary struct: <unclustered>
//
// sub_129E28 @ 0x129e28, size 206 bytes
int __fastcall sub_129E28(int a1, int a2)
{
  char *v2; // r4
  int v5; // r5
  char *v7; // r3
  int v8; // r1
  void *v9; // r0
  int v10; // r8
  int v11; // r10
  int *v12; // r9
  int v13; // r2
  _BYTE *v14; // r12
  int v15; // r0
  int v16; // r1
  int v17; // r4
  void *v18; // r1

  v2 = (char *)off_129EF8;
  if ( *((unsigned __int8 *)off_129EF8 + 113) == 255 )
  {
    v5 = 0;
    v10 = 0;
    v11 = 48;
    v12 = (int *)off_129EF8;
  }
  else
  {
    if ( *((unsigned __int8 *)off_129EF8 + 253) != 255 )
      return 255;
    v5 = 1;
    v10 = 1;
    v11 = 188;
    v12 = (int *)((char *)off_129EF8 + 140);
  }
  sub_100200(v12, 0, 0x8Cu);
  v7 = &v2[140 * v10];
  v7[113] = a1;
  v7[112] = a2;
  if ( a2 == 1 )
  {
    v13 = dword_129F04;
    v14 = off_129F08;
    v7[66] = 1;
    v15 = v13 + 1320 * a1;
    LOBYTE(v13) = *v14;
    v16 = *(_DWORD *)(v15 + 4);
    v7[133] = 1;
    *((_DWORD *)v7 + 14) = &v2[v11];
    v17 = dword_129EFC;
    *(_DWORD *)(v15 + 4) = v16 | 0x20;
    v18 = off_129F00;
    *((_DWORD *)v7 + 2) = v12;
    v7[17] = v5;
    v7[65] = v5;
    *((_DWORD *)v7 + 26) = v12;
    *v14 = v13 + 1;
    *((_DWORD *)v7 + 1) = v17;
    *((_DWORD *)v7 + 13) = v17;
    v7[18] = 0;
    *((_DWORD *)v7 + 25) = v18;
  }
  else
  {
    v8 = dword_129EFC;
    v9 = off_129F00;
    *((_DWORD *)v7 + 14) = &v2[v11];
    *((_DWORD *)v7 + 2) = v12;
    v7[17] = v5;
    v7[65] = v5;
    *((_DWORD *)v7 + 26) = v12;
    *((_DWORD *)v7 + 1) = v8;
    *((_DWORD *)v7 + 13) = v8;
    v7[18] = 0;
    v7[66] = 1;
    v7[133] = 1;
    *((_DWORD *)v7 + 25) = v9;
  }
  return v5;
}

