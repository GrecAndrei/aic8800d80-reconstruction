// sub_12DDF8 @ 0x12ddf8, size 40 bytes
unsigned __int8 * sub_12DDF8(unsigned __int8 *a1, int a2, uint8_t *a3)
{
  unsigned __int8 *result; // r0
  unsigned __int16 v5; // [sp+6h] [bp-2h] BYREF

  result = sub_12D6EC(a1, a2, 36, &v5);
  if ( result )
  {
    if ( (unsigned int)v5 - 9 > 9 )
      return nullptr;
    else
      *a3 = v5 - 3;
  }
  return result;
}

