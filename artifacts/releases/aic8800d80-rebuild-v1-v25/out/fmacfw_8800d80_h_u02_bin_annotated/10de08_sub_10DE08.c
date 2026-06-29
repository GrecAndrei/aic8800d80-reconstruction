// fwstruct annotate: 10de08_sub_10DE08.c
// sub_10DE08 @ 0x10de08, size 128 bytes
int sub_10DE08()
{
  _DWORD *v0; // r0
  _DWORD *v1; // r3
  int v2; // r1
  int v3; // r2
  __int64 v4; // r0
  __int64 v5; // r0
  __int64 v6; // r0
  int v7; // r0

  v0 = off_10DEA0;
  v1 = off_10DEA4;
  v2 = dword_10DEA8;
  v3 = dword_10DEAC;
  *(_DWORD *)off_10DEA4 = 0;
  v0[14] = 296;
  v1[2] = v1[2] & 0xF000FFFF | 0x2000000;
  v1[3] = v2 & v1[3] | 0xA06A000;
  v1[3] = v3 & v1[3] | 0x100230;
  v1[1] = 1;
  while ( v1[7] != 1 )
    ;
  v1[7] = 1;
  v4 = sub_142874(v1[4]);
  v5 = sub_142968(v4, HIDWORD(v4), dword_10DE88, dword_10DE8C);
  v6 = sub_142BBC(v5, HIDWORD(v5), dword_10DE90, dword_10DE94);
  v7 = sub_1425F8(v6, HIDWORD(v6), dword_10DE98, dword_10DE9C);
  return sub_142F2C(v7);
}

