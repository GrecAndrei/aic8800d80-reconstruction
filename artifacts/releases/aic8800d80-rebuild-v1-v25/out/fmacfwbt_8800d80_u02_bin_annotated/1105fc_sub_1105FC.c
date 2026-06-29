// fwstruct annotate: 1105fc_sub_1105FC.c
// sub_1105FC @ 0x1105fc, size 52 bytes
int __fastcall sub_1105FC(int a1)
{
  _DWORD *v1; // r2
  _DWORD *v2; // r1

  v1 = off_110630;
  v2 = off_110634;
  *(_DWORD *)off_110630 = 0;
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
  sub_110494((int)v1, (int)v2);
  return 1;
}

