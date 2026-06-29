// fwstruct annotate: 10e1e8_sub_10E1E8.c
// sub_10E1E8 @ 0x10e1e8, size 130 bytes
int sub_10E1E8()
{
  _DWORD *v0; // r2
  __int64 v1; // r0
  __int64 v2; // r0
  __int64 v3; // r0
  int v4; // r0
  float v5; // r0
  __int64 v6; // r0
  __int64 v7; // r0
  __int64 v8; // r0
  __int64 v9; // r0
  __int64 v10; // r0
  int v11; // r0

  v0 = off_10E290;
  *((_DWORD *)off_10E290 + 1) = 1;
  while ( v0[7] != 1 )
    ;
  v0[7] = 1;
  v1 = sub_1429B4(v0[4]);
  v2 = sub_142AA8(v1, HIDWORD(v1), dword_10E270, dword_10E274);
  v3 = sub_142CFC(v2, HIDWORD(v2), dword_10E278, dword_10E27C);
  v4 = sub_142738(v3, HIDWORD(v3), dword_10E270, dword_10E274);
  v5 = sub_14306C(v4);
  v6 = sub_1429F8(LODWORD(v5));
  v7 = sub_142CFC(v6, HIDWORD(v6), dword_10E280, dword_10E284);
  v8 = sub_142AA8(v7, HIDWORD(v7), 0, dword_10E294);
  v9 = sub_142AA8(v8, HIDWORD(v8), 0, dword_10E298);
  v10 = sub_142AA8(v9, HIDWORD(v9), dword_10E288, dword_10E28C);
  v11 = sub_142CFC(v10, HIDWORD(v10), 0, dword_10E29C);
  return (int)sub_14306C(v11);
}

