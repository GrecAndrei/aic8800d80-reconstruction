// sub_1202F8 @ 0x1202f8, size 80 bytes
int  sub_1202F8(uint8_t *a1)
{
  uint32_t *v1; // r3
  int *v2; // r3
  int result; // r0

  v1 = off_120348;
  *a1 = 0;
  v2 = (int *)v1[2];
  if ( v2 )
  {
    result = 0;
    while ( 1 )
    {
      if ( *((uint8_t *)v2 + 106) )
      {
        if ( *((uint8_t *)v2 + 108) && *((uint8_t *)v2 + 1224) )
          goto LABEL_10;
LABEL_6:
        v2 = (int *)*v2;
        if ( !v2 )
          return result;
      }
      else
      {
        if ( !*((uint8_t *)v2 + 108) )
          goto LABEL_6;
        if ( !*((uint8_t *)v2 + 1224) )
        {
          ++result;
          goto LABEL_6;
        }
LABEL_10:
        *a1 = 1;
        v2 = (int *)*v2;
        if ( !v2 )
          return result;
      }
    }
  }
  return 0;
}

