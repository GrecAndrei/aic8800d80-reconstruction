// v23 annotated: sub_10DF48 @ 0x10df48
// Original: 10df48_sub_10DF48.c
// Primary struct: <unclustered>
//
// sub_10DF48 @ 0x10df48, size 128 bytes
int sub_10DF48()
{
  _DWORD *v0; // r0
  _DWORD *v1; // r3
  int v2; // r1
  int v3; // r2
  __int64 v4; // r0
  __int64 v5; // r0
  __int64 v6; // r0
  int v7; // r0

  v0 = off_10DFE0;
  v1 = off_10DFE4;
  v2 = dword_10DFE8;
  v3 = dword_10DFEC;
  *(_DWORD *)off_10DFE4 = 0;
  v0[14] = 296;
  v1[2] = v1[2] & 0xF000FFFF | 0x2000000;
  v1[3] = v2 & v1[3] | 0xA06A000;
  v1[3] = v3 & v1[3] | 0x100230;
  v1[1] = 1;
  while ( v1[7] != 1 )
    ;
  v1[7] = 1;
  v4 = sub_1429B4(v1[4]);
  v5 = sub_142AA8(v4, HIDWORD(v4), dword_10DFC8, dword_10DFCC);
  v6 = sub_142CFC(v5, HIDWORD(v5), dword_10DFD0, dword_10DFD4);
  v7 = sub_142738(v6, HIDWORD(v6), dword_10DFD8, dword_10DFDC);
  return sub_14306C(v7);
}

