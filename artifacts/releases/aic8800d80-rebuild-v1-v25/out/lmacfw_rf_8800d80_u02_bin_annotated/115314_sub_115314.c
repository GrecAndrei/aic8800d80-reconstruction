// fwstruct annotate: 115314_sub_115314.c
// sub_115314 @ 0x115314, size 18 bytes
_DWORD *__fastcall sub_115314(int a1)
{
  _DWORD *result; // r0

  result = *(_DWORD **)(a1 + 28);
  if ( result )
  {
    result = (_DWORD *)sub_10FEF8(result);
    *(_DWORD *)(a1 + 28) = 0;
  }
  return result;
}

