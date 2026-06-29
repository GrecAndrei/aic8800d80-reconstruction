// sub_12D4F8 @ 0x12d4f8, size 22 bytes
uint32_t * sub_12D4F8(int a1)
{
  uint32_t *v1; // r3
  uint32_t *v2; // r2

  v1 = *(uint32_t **)a1;
  if ( *(uint32_t *)a1 )
  {
    v2 = *(uint32_t **)(a1 + 4);
    *(uint32_t *)a1 = *v1;
    if ( v2 == v1 )
      *(uint32_t *)(a1 + 4) = 0;
  }
  return v1;
}

