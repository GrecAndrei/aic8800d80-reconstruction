// sub_115F4C @ 0x115f4c, size 18 bytes
uint32_t * sub_115F4C(int a1)
{
  uint32_t *result; // r0

  result = *(uint32_t **)(a1 + 72);
  if ( result )
  {
    result = (uint32_t *)sub_10FEC8(result);
    *(uint32_t *)(a1 + 72) = 0;
  }
  return result;
}

