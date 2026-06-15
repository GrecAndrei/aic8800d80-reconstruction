// sub_13A490 @ 0x13a490, size 94 bytes
int __fastcall sub_13A490(int a1, int a2, __int16 a3)
{
  int v3; // r4
  char v5; // r5
  int *v7; // r0
  int *v8; // r6
  _DWORD *v9; // r3
  int v10; // r3
  int v11; // r2

  v3 = a1 + 4 * a2;
  if ( *(_DWORD *)(v3 + 408) )
    return 0;
  v5 = a2;
  v7 = sub_12D4F8(dword_13A4F0);
  v8 = v7;
  if ( !v7 )
    return 0;
  memset_thunk(v7, 0, 0x124u);
  v9 = off_13A4F4;
  *((_BYTE *)v8 + 10) = a3 & 0x3F;
  *((_BYTE *)v8 + 12) = v5;
  v10 = v9[4];
  v11 = dword_13A4F8;
  *((_WORD *)v8 + 4) = a3;
  v8[69] = v11;
  v8[70] = (int)v8;
  v8[1] = v10;
  *(_DWORD *)(v3 + 408) = v8;
  timestamp_update_4f60((int)(v8 + 68), v10 + 50000);
  return 1;
}

