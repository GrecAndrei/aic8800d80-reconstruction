// fwstruct annotate: 131230_sub_131230.c
// sub_131230 @ 0x131230, size 40 bytes
unsigned __int8 *__fastcall sub_131230(unsigned __int8 *a1, int a2, int a3)
{
  unsigned __int8 *result; // r0
  char v5; // [sp+7h] [bp-1h] BYREF

  result = sub_12DF38(a1, a2, &v5);
  if ( result )
    *(_DWORD *)(a3 + 220) = *(_DWORD *)(result + 3);
  else
    *(_DWORD *)(a3 + 220) = 0x80000000;
  return result;
}

