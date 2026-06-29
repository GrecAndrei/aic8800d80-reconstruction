// fwstruct annotate: 139d90_sub_139D90.c
// sub_139D90 @ 0x139d90, size 118 bytes
int sub_139D90()
{
  _DWORD *v0; // r6
  int v1; // r4
  int v2; // r5
  _DWORD *v3; // r1
  int v4; // r3
  int result; // r0
  int v6; // r1

  v0 = (_DWORD *)(dword_139E08 + 16);
  sub_12D468((_DWORD *)dword_139E08);
  v1 = dword_139E0C;
  sub_12D468(v0);
  v2 = v1 + 4672;
  do
  {
    v3 = (_DWORD *)v1;
    v1 += 292;
    sub_12D470((int)v0, v3);
  }
  while ( v1 != v2 );
  sub_12D468((_DWORD *)dword_139E10);
  sub_12D468((_DWORD *)dword_139E14);
  sub_12D470(dword_139E10, (_DWORD *)dword_139E18);
  sub_12D470(dword_139E10, (_DWORD *)dword_139E1C);
  sub_12D470(dword_139E10, (_DWORD *)dword_139E20);
  v4 = dword_139E28;
  result = dword_139E2C;
  *((_WORD *)off_139E24 + 51) = -1;
  v6 = v4 + 15360;
  do
  {
    *(_BYTE *)(v4 - 52) = 0;
    *(_WORD *)(v4 + 8) = 0;
    *(_DWORD *)(v4 - 64) = result;
    *(_DWORD *)(v4 - 60) = v4;
    *(_DWORD *)(v4 - 48) = v4;
    v4 += 80;
  }
  while ( v6 != v4 );
  return result;
}

