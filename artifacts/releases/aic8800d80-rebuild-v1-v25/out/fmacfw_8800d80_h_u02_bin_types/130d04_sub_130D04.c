// sub_130D04 @ 0x130d04, size 18 bytes
uint8_t * sub_130D04(uint8_t *a1, int a2, int a3)
{
  uint8_t *result; // r0

  result = sub_12DB20(a1, a2);
  if ( result )
    result = (uint8_t *)(unsigned __int8)result[2];
  *(uint8_t *)(a3 + 216) = (uint8_t)result;
  return result;
}

