// v23 annotated: sub_1235D0 @ 0x1235d0
// Original: 1235d0_sub_1235D0.c
// Primary struct: <unclustered>
//
// sub_1235D0 @ 0x1235d0, size 140 bytes
int __fastcall sub_1235D0(int a1, unsigned __int8 *a2)
{
  _BYTE *v3; // r0
  _BYTE *v4; // r4
  unsigned int v5; // r0
  int v6; // r0

  v3 = (_BYTE *)sub_12C92C(83, 13, 0, 1);
  *v3 = 1;
  v4 = v3;
  v5 = *a2;
  if ( v5 > 4 )
    goto LABEL_6;
  v6 = dword_12365C + 1320 * v5;
  if ( !*(_BYTE *)(v6 + 1224) )
    goto LABEL_6;
  if ( a2[2] )
  {
    if ( sub_12A5F4(
           v6,
           0,
           a2[3],
           a2[2],
           *((_DWORD *)a2 + 2),
           *((_DWORD *)a2 + 1),
           (*(unsigned __int16 *)(v6 + 222) << 10)
         + *(_DWORD *)off_123660 / (*(unsigned __int16 *)(v6 + 222) << 10) * (*(unsigned __int16 *)(v6 + 222) << 10)
         + *((_DWORD *)off_123664 + 4)
         - *(_DWORD *)off_123660
         + *((_DWORD *)a2 + 3)) != 255 )
      *v4 = 0;
LABEL_6:
    sub_12C98C(v4);
    return 0;
  }
  *v4 = sub_12A700();
  sub_12C98C(v4);
  return 0;
}

