// sub_115314 @ 0x115314, size 18 bytes
uint32_t * sub_115314(int a1)
{
  uint32_t *result; // r0

  result = *(uint32_t **)(a1 + 28);
  if ( result )
  {
    result = (uint32_t *)sub_10FEF8(result);
    *(uint32_t *)(a1 + 28) = 0;
  }
  return result;
}

