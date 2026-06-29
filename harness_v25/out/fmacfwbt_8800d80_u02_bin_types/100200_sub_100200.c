// sub_100200 @ 0x100200, size 160 bytes
int * sub_100200(int *result, unsigned __int8 a2, unsigned int a3)
{
  unsigned int v3; // r4
  int *v4; // r3
  int v6; // r5
  uint8_t *v7; // r2
  int *v8; // r2
  int v9; // r6
  int *v10; // r4

  if ( (uint32_t)result << 30 )
  {
    v3 = a3 - 1;
    if ( !a3 )
      return result;
    v4 = result;
    while ( 1 )
    {
      *(uint8_t *)v4 = a2;
      v4 = (int *)((char *)v4 + 1);
      if ( !((uint32_t)v4 << 30) )
        break;
      if ( v3-- == 0 )
        return result;
    }
  }
  else
  {
    v3 = a3;
    v4 = result;
  }
  if ( v3 > 3 )
  {
    v6 = a2 | (a2 << 8) | ((a2 | (a2 << 8)) << 16);
    if ( v3 <= 0xF )
    {
      v8 = v4;
      v9 = v3;
    }
    else
    {
      v7 = v4 + 4;
      do
      {
        *((uint32_t *)v7 - 4) = v6;
        *((uint32_t *)v7 - 3) = v6;
        *((uint32_t *)v7 - 2) = v6;
        *((uint32_t *)v7 - 1) = v6;
        v7 += 16;
      }
      while ( v7 != (char *)v4 + ((v3 - 16) & 0xFFFFFFF0) + 32 );
      v8 = &v4[4 * ((v3 - 16) >> 4) + 4];
      v9 = v3 & 0xF;
      if ( (v3 & 0xC) == 0 )
      {
        v3 &= 0xFu;
        v4 = v8;
        if ( !v9 )
          return result;
        goto LABEL_16;
      }
    }
    v4 = (int *)((char *)v8 + ((v9 - 4) & 0xFFFFFFFC) + 4);
    do
      *v8++ = v6;
    while ( v4 != v8 );
    v3 = v9 & 3;
  }
  if ( !v3 )
    return result;
LABEL_16:
  v10 = (int *)((char *)v4 + v3);
  do
  {
    *(uint8_t *)v4 = a2;
    v4 = (int *)((char *)v4 + 1);
  }
  while ( v10 != v4 );
  return result;
}

