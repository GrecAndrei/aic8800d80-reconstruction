// v23 annotated: sub_1107A0 @ 0x1107a0
// Original: 1107a0_sub_1107A0.c
// Primary struct: <unclustered>
//
// sub_1107A0 @ 0x1107a0, size 52 bytes
int __fastcall sub_1107A0(int a1)
{
  _DWORD *v1; // r2
  _DWORD *v2; // r1

  v1 = off_1107D4;
  v2 = off_1107D8;
  *(_DWORD *)off_1107D4 = 0;
  v1[1] = 0;
  v1[2] = a1;
  v1[3] = 0;
  v1[4] = 0;
  v1[5] = 0;
  *v2 = 0;
  v2[1] = 0;
  v2[4] = 0;
  v2[5] = 0;
  *((_WORD *)v2 + 6) = 0;
  v2[2] = 0;
  *((_BYTE *)v2 + 14) = 0;
  *((_WORD *)v2 + 14) = 0;
  v2[6] = 0;
  *((_BYTE *)v2 + 30) = 0;
  sub_11063C((int)v1, (int)v2);
  return 1;
}

