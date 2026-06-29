// fwstruct annotate: 1374c8_sub_1374C8.c
// sub_1374C8 @ 0x1374c8, size 212 bytes
_DWORD *__fastcall sub_1374C8(int a1)
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

  if ( *(_BYTE *)off_13759C )
    sub_102B80(*((_BYTE *)off_1375CC + 9));
  v2 = off_1375A0;
  v3 = (_BYTE **)off_1375A4;
  if ( *((_BYTE *)off_1375A0 + 3850) == 1 )
    v4 = 4099;
  else
    v4 = 4097;
  v5 = (_BYTE *)sub_12C92C(v4, *((_WORD *)off_1375A0 + 1924), 4, 3u);
  feature_guard_check(
    8,
    dword_1375AC,
    dword_1375A8,
    *(unsigned __int8 *)(*(_DWORD *)v2 + 366),
    *((unsigned __int8 *)v2 + 3850),
    a1);
  v6 = (int *)off_1375B4;
  v7 = (unsigned __int16 *)off_1375B8;
  *(_DWORD *)off_1375B0 &= ~4u;
  v8 = *v7;
  v9 = *(_DWORD *)v2;
  *v6 = (HIWORD(*v6) << 16) | v8;
  *v5 = *(_BYTE *)(v9 + 366);
  v5[1] = a1;
  v5[2] = v2[2];
  if ( **v3 == 1 && *((_BYTE *)off_1375C0 + 189) )
  {
    v11 = off_1375C8;
    *(_DWORD *)off_1375C4 &= 0xFC0FFFFF;
    *v11 |= 0x400000u;
    *v11 |= 0x200000u;
  }
  sub_12CA38(v9 - 12);
  *(_DWORD *)v2 = 0;
  sdio_buffer_prepare_n_4e8((int)v5);
  *((_DWORD *)off_1375BC + 1) &= ~0x20u;
  return sub_12CD34(4u, 0);
}

