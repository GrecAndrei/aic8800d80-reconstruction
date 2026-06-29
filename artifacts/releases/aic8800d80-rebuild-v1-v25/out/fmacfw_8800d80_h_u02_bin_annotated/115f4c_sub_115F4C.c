// fwstruct annotate: 115f4c_sub_115F4C.c
// sub_115F4C @ 0x115f4c, size 18 bytes
_DWORD *__fastcall sub_115F4C(int a1)
{
  _DWORD *result; // r0

  result = *(_DWORD **)(a1 + 72);
  if ( result )
  {
    result = (_DWORD *)sub_10FEC8(result);
    *(_DWORD *)(a1 + 72) = 0;
  }
  return result;
}

