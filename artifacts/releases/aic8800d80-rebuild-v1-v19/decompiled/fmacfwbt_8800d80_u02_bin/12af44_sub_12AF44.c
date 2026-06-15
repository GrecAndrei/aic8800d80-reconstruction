// sub_12AF44 @ 0x12af44, size 212 bytes
int __fastcall sub_12AF44(int a1)
{
  int v1; // r7
  int v3; // r5
  int v4; // r4
  int v5; // r9
  int v6; // r8
  int **v7; // r0
  int v8; // r12
  int v9; // r1
  int v10; // r4
  unsigned int v11; // r2
  unsigned int v12; // r4
  bool v13; // cc
  int v14; // r3
  int v15; // r1

  v1 = dword_12B018;
  v3 = *((_DWORD *)off_12B01C + 4);
  sub_11C040((unsigned __int8 *)(dword_12B018 + 1320 * *(unsigned __int8 *)(a1 + 28)));
  if ( *(_BYTE *)(a1 + 31) )
  {
    v4 = *(_DWORD *)(a1 + 16) > 2u;
    v5 = *(unsigned __int8 *)(a1 + 28);
    if ( *(_DWORD *)(a1 + 20) > 2u )
      v4 |= 2u;
    if ( (*(unsigned __int8 *)(a1 + 29) ^ v4) << 30 )
      sub_12A6E8(*(unsigned __int8 *)(a1 + 28), v4);
    v6 = *(unsigned __int8 *)(a1 + 28);
    *(_BYTE *)(a1 + 29) = v4;
    v7 = *(int ***)(v1 + 1320 * v5 + 240);
    if ( v7 )
    {
      v8 = dword_12B024;
      do
      {
        v9 = *((unsigned __int8 *)v7 + 35);
        v7 = (int **)*v7;
        v10 = 3 * v9 + v8;
        v11 = *(unsigned __int8 *)(v10 + 1);
        v12 = *(unsigned __int8 *)(v10 + 2);
        v13 = v11 > 2;
        v14 = 3 * v9;
        if ( v11 > 2 )
          LOBYTE(v11) = 1;
        v15 = v8 + v14;
        if ( !v13 )
          LOBYTE(v11) = 0;
        if ( v12 > 2 )
          LOBYTE(v11) = v11 | 2;
        *(_BYTE *)(v8 + v14) = v11;
        *(_BYTE *)(v15 + 1) = 0;
        *(_BYTE *)(v15 + 2) = 0;
      }
      while ( v7 );
    }
  }
  else
  {
    v6 = *(unsigned __int8 *)(a1 + 28);
  }
  *(_BYTE *)(a1 + 31) = *((_DWORD *)off_12B020 + 10) == *(_DWORD *)(v1 + 1320 * v6 + 72);
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 20) = 0;
  return sub_124F60(a1, v3 + 102400);
}

