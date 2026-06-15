// sub_112B68 @ 0x112b68, size 48 bytes
_BYTE *__fastcall sub_112B68(int a1, int a2, int a3)
{
  _BYTE *result; // r0
  _DWORD *v4; // r2

  if ( (*((_WORD *)off_112B98 + 89) & 0x4000) != 0 )
    result = sub_10D674((_BYTE *)dword_112BA8);
  else
    result = (_BYTE *)sub_12E948(dword_112B9C, a2, a3);
  v4 = off_112BA4;
  *(_BYTE *)off_112BA0 = 0;
  v4[896] &= ~1u;
  return result;
}

