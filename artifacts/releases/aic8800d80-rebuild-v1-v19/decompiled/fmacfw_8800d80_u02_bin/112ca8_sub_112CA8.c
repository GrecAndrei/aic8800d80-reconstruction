// sub_112CA8 @ 0x112ca8, size 48 bytes
_BYTE *__fastcall sub_112CA8(int a1, int a2, int a3)
{
  _BYTE *result; // r0
  _DWORD *v4; // r2

  if ( (*((_WORD *)off_112CD8 + 89) & 0x4000) != 0 )
    result = sub_10D7B4((_BYTE *)dword_112CE8);
  else
    result = (_BYTE *)sub_12EA88(dword_112CDC, a2, a3);
  v4 = off_112CE4;
  *(_BYTE *)off_112CE0 = 0;
  v4[896] &= ~1u;
  return result;
}

