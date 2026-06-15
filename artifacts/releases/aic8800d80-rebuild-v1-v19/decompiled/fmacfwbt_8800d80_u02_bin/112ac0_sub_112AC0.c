// sub_112AC0 @ 0x112ac0, size 40 bytes
_BYTE *__fastcall sub_112AC0(int a1, int a2, int a3)
{
  _BYTE *result; // r0

  if ( (*((_WORD *)off_112AE8 + 89) & 0x4000) != 0 )
    result = sub_10D60C((_BYTE *)dword_112AF4);
  else
    result = (_BYTE *)sub_12ECB0(dword_112AEC, a2, a3);
  *(_BYTE *)off_112AF0 = 1;
  return result;
}

