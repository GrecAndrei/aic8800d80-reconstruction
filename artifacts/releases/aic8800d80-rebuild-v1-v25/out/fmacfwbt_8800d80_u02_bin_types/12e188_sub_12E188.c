// sub_12E188 @ 0x12e188, size 32 bytes
unsigned __int8 * sub_12E188(unsigned __int8 *a1, int a2)
{
  unsigned __int8 *result; // r0
  uint16_t v3[3]; // [sp+6h] [bp-6h] BYREF

  result = sub_12DA54(a1, a2, 38, v3);
  if ( result )
  {
    if ( v3[0] != 16 )
      return nullptr;
  }
  return result;
}

