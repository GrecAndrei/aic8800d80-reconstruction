// sub_112B04 @ 0x112b04, size 48 bytes
_BYTE *__fastcall sub_112B04(int a1, int a2, int a3)
{
  _BYTE *result; // r0
  _DWORD *v4; // r2

  if ( (*((_WORD *)off_112B34 + 89) & 0x4000) != 0 )
    result = sub_10D60C((_BYTE *)dword_112B44);
  else
    result = (_BYTE *)sub_12ECB0(dword_112B38, a2, a3);
  v4 = off_112B40;
  *(_BYTE *)off_112B3C = 0;
  v4[896] &= ~1u;
  return result;
}

