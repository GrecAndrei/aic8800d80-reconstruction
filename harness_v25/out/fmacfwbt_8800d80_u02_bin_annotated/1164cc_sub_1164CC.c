// fwstruct annotate: 1164cc_sub_1164CC.c
// sub_1164CC @ 0x1164cc, size 18 bytes
_DWORD *__fastcall sub_1164CC(int a1)
{
  _DWORD *result; // r0

  result = *(_DWORD **)(a1 + 72);
  if ( result )
  {
    result = (_DWORD *)log_free_dispatch_2(result);
    *(_DWORD *)(a1 + 72) = 0;
  }
  return result;
}

