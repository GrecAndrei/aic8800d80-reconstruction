// sub_112B24 @ 0x112b24, size 40 bytes
_BYTE *__fastcall sub_112B24(int a1, int a2, int a3)
{
  _BYTE *result; // r0

  if ( (*((_WORD *)off_112B4C + 89) & 0x4000) != 0 )
    result = sub_10D674((_BYTE *)dword_112B58);
  else
    result = (_BYTE *)sub_12E948(dword_112B50, a2, a3);
  *(_BYTE *)off_112B54 = 1;
  return result;
}

