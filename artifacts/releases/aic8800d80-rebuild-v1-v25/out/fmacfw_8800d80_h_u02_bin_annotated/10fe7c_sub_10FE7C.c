// fwstruct annotate: 10fe7c_sub_10FE7C.c
// sub_10FE7C @ 0x10fe7c, size 62 bytes
_DWORD *__fastcall sub_10FE7C(char a1)
{
  _DWORD *v2; // r4

  if ( **(_BYTE **)off_10FEBC == 1 )
    v2 = (_DWORD *)sub_110340();
  else
    v2 = sub_10F9E8(dword_10FEC0, 0x7Cu);
  if ( !v2 )
    return v2;
  if ( sub_10FDF4((unsigned int)v2) )
  {
    *((_BYTE *)v2 - 1) = a1;
    return v2;
  }
  sub_10DAE4(dword_10FEC4, v2);
  return v2;
}

