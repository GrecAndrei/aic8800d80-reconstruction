// sub_12D658 @ 0x12d658, size 48 bytes
uint32_t * sub_12D658(uint32_t *result, uint32_t *a2)
{
  uint32_t *v3; // r1
  uint32_t *v4; // r2
  int v5; // r1

  v3 = (uint32_t *)*a2;
  if ( v3 )
  {
    v4 = result;
    if ( *result )
    {
      result = (uint32_t *)a2[1];
      *(uint32_t *)v4[1] = v3;
      v4[1] = result;
    }
    else
    {
      result = (uint32_t *)*a2;
      v5 = a2[1];
      *v4 = *a2;
      v4[1] = v5;
    }
    *a2 = 0;
  }
  return result;
}

