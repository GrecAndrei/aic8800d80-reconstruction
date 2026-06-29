// fwstruct annotate: 1375cc_sub_1375CC.c
// sub_1375CC @ 0x1375cc, size 212 bytes
_DWORD *__fastcall sub_1375CC(int a1)
{
  _WORD *v2; // r4
  _BYTE **v3; // r7
  __int16 v4; // r0
  _BYTE *v5; // r5
  int *v6; // r2
  unsigned __int16 *v7; // r0
  int v8; // r1
  int v9; // r0
  _DWORD *v11; // r3

  if ( *(_BYTE *)off_1376A0 )
    sub_1029F8(*((_BYTE *)off_1376D0 + 9));
  v2 = off_1376A4;
  v3 = (_BYTE **)off_1376A8;
  if ( *((_BYTE *)off_1376A4 + 3850) == 1 )
    v4 = 4099;
  else
    v4 = 4097;
  v5 = (_BYTE *)sub_12CB54(v4, *((_WORD *)off_1376A4 + 1924), 4, 3u);
  sub_12EEF8(
    8,
    dword_1376B0,
    dword_1376AC,
    *(unsigned __int8 *)(*(_DWORD *)v2 + 366),
    *((unsigned __int8 *)v2 + 3850),
    a1);
  v6 = (int *)off_1376B8;
  v7 = (unsigned __int16 *)off_1376BC;
  *(_DWORD *)off_1376B4 &= ~4u;
  v8 = *v7;
  v9 = *(_DWORD *)v2;
  *v6 = (HIWORD(*v6) << 16) | v8;
  *v5 = *(_BYTE *)(v9 + 366);
  v5[1] = a1;
  v5[2] = v2[2];
  if ( **v3 == 1 && *((_BYTE *)off_1376C4 + 189) )
  {
    v11 = off_1376CC;
    *(_DWORD *)off_1376C8 &= 0xFC0FFFFF;
    *v11 |= 0x400000u;
    *v11 |= 0x200000u;
  }
  sub_12CC60(v9 - 12);
  *(_DWORD *)v2 = 0;
  sub_12CBB4((int)v5);
  *((_DWORD *)off_1376C0 + 1) &= ~0x20u;
  return sub_12CF5C(4u, 0);
}

