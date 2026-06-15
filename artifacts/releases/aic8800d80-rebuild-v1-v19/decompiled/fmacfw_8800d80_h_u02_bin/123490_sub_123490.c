// sub_123490 @ 0x123490, size 140 bytes
int __fastcall sub_123490(int a1, unsigned __int8 *a2)
{
  _BYTE *v3; // r0
  _BYTE *v4; // r4
  unsigned int v5; // r0
  int v6; // r0

  v3 = (_BYTE *)sub_12C7EC(83, 13, 0, 1);
  *v3 = 1;
  v4 = v3;
  v5 = *a2;
  if ( v5 > 4 )
    goto LABEL_6;
  v6 = dword_12351C + 1320 * v5;
  if ( !*(_BYTE *)(v6 + 1224) )
    goto LABEL_6;
  if ( a2[2] )
  {
    if ( sub_12A4B4(
           v6,
           0,
           a2[3],
           a2[2],
           *((_DWORD *)a2 + 2),
           *((_DWORD *)a2 + 1),
           (*(unsigned __int16 *)(v6 + 222) << 10)
         + *(_DWORD *)off_123520 / (*(unsigned __int16 *)(v6 + 222) << 10) * (*(unsigned __int16 *)(v6 + 222) << 10)
         + *((_DWORD *)off_123524 + 4)
         - *(_DWORD *)off_123520
         + *((_DWORD *)a2 + 3)) != 255 )
      *v4 = 0;
LABEL_6:
    sub_12C84C(v4);
    return 0;
  }
  *v4 = sub_12A5C0();
  sub_12C84C(v4);
  return 0;
}

