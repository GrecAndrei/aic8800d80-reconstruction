// sub_12F414 @ 0x12f414, size 48 bytes
uint32_t ** sub_12F414(uint32_t **result)
{
  uint32_t *v1; // r4
  int v2; // r6
  uint32_t *v3; // r5
  int v4; // r2

  v1 = *result;
  if ( *result )
  {
    v2 = dword_12F444;
    v3 = result;
    do
    {
      while ( 1 )
      {
        sub_12D190((int)v3);
        result = (uint32_t **)v2;
        if ( !v1[3] )
          break;
        result = (uint32_t **)sub_12D108(v2, v1);
        v1 = (uint32_t *)*v3;
        if ( !*v3 )
          return result;
      }
      v4 = v1[2];
      v1 = (uint32_t *)*v3;
      *(uint16_t *)(v4 + 8) = 0;
    }
    while ( v1 );
  }
  return result;
}

