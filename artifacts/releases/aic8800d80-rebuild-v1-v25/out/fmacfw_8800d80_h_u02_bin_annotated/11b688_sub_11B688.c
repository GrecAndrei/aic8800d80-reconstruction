// fwstruct annotate: 11b688_sub_11B688.c
// sub_11B688 @ 0x11b688, size 100 bytes
_DWORD *__fastcall sub_11B688(_DWORD *result)
{
  _DWORD *v1; // r2
  int v2; // r5
  _DWORD *v3; // r4
  _DWORD *v4; // r2
  _DWORD *v5; // r3
  _DWORD *v6; // r6
  int v7; // r4
  int v8; // r1
  _DWORD *v9; // r5

  v1 = off_11B6F4;
  v2 = result[9];
  v3 = off_11B6F8;
  *(_DWORD *)off_11B6F0 = *(_DWORD *)off_11B6EC + 20000;
  *v1 = 64;
  v4 = off_11B6FC;
  v5 = off_11B700;
  v6 = off_11B704;
  *v3 |= 0x40u;
  v5[275] = *(_DWORD *)(v2 + 12);
  v7 = v4[52];
  v8 = result[15];
  v5[276] = *(_DWORD *)(v2 + 16);
  v4[52] = v7 | 1;
  v9 = off_11B708;
  result[9] = v5 + 272;
  result[15] = v8 & 0xFF00;
  result[1] = 0;
  *((_BYTE *)v4 + 200) = 0;
  *v6 = result;
  *v9 = 0x2000;
  return result;
}

