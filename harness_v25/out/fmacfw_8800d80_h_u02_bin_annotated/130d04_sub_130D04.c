// fwstruct annotate: 130d04_sub_130D04.c
// sub_130D04 @ 0x130d04, size 18 bytes
_BYTE *__fastcall sub_130D04(_BYTE *a1, int a2, int a3)
{
  _BYTE *result; // r0

  result = sub_12DB20(a1, a2);
  if ( result )
    result = (_BYTE *)(unsigned __int8)result[2];
  *(_BYTE *)(a3 + 216) = (_BYTE)result;
  return result;
}

