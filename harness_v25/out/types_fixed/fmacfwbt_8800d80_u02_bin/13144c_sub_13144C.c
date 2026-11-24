// sub_13144C @ 0x13144c, size 40 bytes
unsigned __int8 *__fastcall sub_13144C(unsigned __int8 *a1, int a2, int a3)
{
  unsigned __int8 *result; // r0
  char v5; // [sp+7h] [bp-1h] BYREF

  result = sub_12E160(a1, a2, &v5);
  if ( result )
    *(_DWORD *)(a3 + 220) = *(_DWORD *)(result + 3);
  else
    *(_DWORD *)(a3 + 220) = 0x80000000;
  return result;
}

