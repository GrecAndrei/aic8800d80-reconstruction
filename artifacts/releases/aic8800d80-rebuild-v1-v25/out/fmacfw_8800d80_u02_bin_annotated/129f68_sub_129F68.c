// fwstruct annotate: 129f68_sub_129F68.c
// sub_129F68 @ 0x129f68, size 206 bytes
int __fastcall sub_129F68(int a1, int a2)
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

  v2 = (char *)off_12A038;
  if ( *((unsigned __int8 *)off_12A038 + 113) == 255 )
  {
    v5 = 0;
    v10 = 0;
    v11 = 48;
    v12 = (int *)off_12A038;
  }
  else
  {
    if ( *((unsigned __int8 *)off_12A038 + 253) != 255 )
      return 255;
    v5 = 1;
    v10 = 1;
    v11 = 188;
    v12 = (int *)((char *)off_12A038 + 140);
  }
  memset_thunk(v12, 0, 0x8Cu);
  v7 = &v2[140 * v10];
  v7[113] = a1;
  v7[112] = a2;
  if ( a2 == 1 )
  {
    v13 = dword_12A044;
    v14 = off_12A048;
    v7[66] = 1;
    v15 = v13 + 1320 * a1;
    LOBYTE(v13) = *v14;
    v16 = *(_DWORD *)(v15 + 4);
    v7[133] = 1;
    *((_DWORD *)v7 + 14) = &v2[v11];
    v17 = dword_12A03C;
    *(_DWORD *)(v15 + 4) = v16 | 0x20;
    v18 = off_12A040;
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
    v8 = dword_12A03C;
    v9 = off_12A040;
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

