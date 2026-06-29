// fwstruct annotate: 11256c_sub_11256C.c
// sub_11256C @ 0x11256c, size 40 bytes
_BYTE *__fastcall sub_11256C(int a1, int a2)
{
  _BYTE *result; // r0

  if ( (*((_WORD *)off_112594 + 89) & 0x4000) != 0 )
    result = sub_10D654((_BYTE *)dword_1125A0);
  else
    result = (_BYTE *)sub_11F504(dword_112598, a2);
  *(_BYTE *)off_11259C = 1;
  return result;
}

