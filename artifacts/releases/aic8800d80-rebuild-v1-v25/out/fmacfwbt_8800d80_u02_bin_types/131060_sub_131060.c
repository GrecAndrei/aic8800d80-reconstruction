// sub_131060 @ 0x131060, size 18 bytes
uint8_t * sub_131060(uint8_t *a1, int a2, int a3)
{
  uint8_t *result; // r0

  result = sub_12DE88(a1, a2);
  if ( result )
    result = (uint8_t *)(unsigned __int8)result[2];
  *(uint8_t *)(a3 + 216) = (uint8_t)result;
  return result;
}

