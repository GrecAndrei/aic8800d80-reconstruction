// fwstruct annotate: 10fe14_sub_10FE14.c
// sub_10FE14 @ 0x10fe14, size 62 bytes
_DWORD *__fastcall sub_10FE14(char a1)
{
  _DWORD *v2; // r4

  if ( **(_BYTE **)off_10FE54 == 1 )
    v2 = (_DWORD *)sub_1102D8();
  else
    v2 = sub_10F980(dword_10FE58, 0x7Cu);
  if ( !v2 )
    return v2;
  if ( sub_10FD8C((unsigned int)v2) )
  {
    *((_BYTE *)v2 - 1) = a1;
    return v2;
  }
  sub_10DA7C(dword_10FE5C, v2);
  return v2;
}

