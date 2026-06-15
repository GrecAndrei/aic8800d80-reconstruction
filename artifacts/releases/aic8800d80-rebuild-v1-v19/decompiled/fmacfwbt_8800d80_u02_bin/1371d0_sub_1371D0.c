// sub_1371D0 @ 0x1371d0, size 82 bytes
int __fastcall sub_1371D0(int a1, int a2, int a3, int a4)
{
  _WORD *v4; // r2
  __int64 v6; // r0
  _BYTE *v8; // r0
  int v9; // r0

  v4 = off_137224;
  *((_WORD *)off_137224 + 1924) = a4;
  v4[1925] = 0;
  v6 = *(_QWORD *)(a2 + 352);
  *(_DWORD *)v4 = a2;
  *((_DWORD *)v4 + 963) = v6;
  v4[1928] = WORD2(v6);
  if ( a4 == 11 || a4 == 6 )
  {
    sub_13876C(v6);
    return 1;
  }
  else
  {
    v8 = (_BYTE *)sub_12CB54(4105, a4, 4, 2u);
    v8[1] = 1;
    *v8 = *(_BYTE *)(a2 + 366);
    v9 = sub_12CBB4((int)v8);
    sub_13876C(v9);
    return 1;
  }
}

