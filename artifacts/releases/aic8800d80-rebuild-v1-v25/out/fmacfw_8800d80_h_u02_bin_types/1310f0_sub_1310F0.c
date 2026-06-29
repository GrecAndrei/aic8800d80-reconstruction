// sub_1310F0 @ 0x1310f0, size 40 bytes
unsigned __int8 * sub_1310F0(unsigned __int8 *a1, int a2, int a3)
{
  unsigned __int8 *result; // r0
  char v5; // [sp+7h] [bp-1h] BYREF

  result = sub_12DDF8(a1, a2, &v5);
  if ( result )
    *(uint32_t *)(a3 + 220) = *(uint32_t *)(result + 3);
  else
    *(uint32_t *)(a3 + 220) = 0x80000000;
  return result;
}

