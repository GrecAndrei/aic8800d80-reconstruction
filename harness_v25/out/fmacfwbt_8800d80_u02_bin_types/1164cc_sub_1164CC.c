// sub_1164CC @ 0x1164cc, size 18 bytes
uint32_t * sub_1164CC(int a1)
{
  uint32_t *result; // r0

  result = *(uint32_t **)(a1 + 72);
  if ( result )
  {
    result = (uint32_t *)log_free_dispatch_2(result);
    *(uint32_t *)(a1 + 72) = 0;
  }
  return result;
}

