// sub_128DDC @ 0x128ddc, size 50 bytes
int sub_128DDC()
{
  uint32_t *v0; // r4
  uint32_t *v1; // r3

  v0 = off_128E10;
  if ( !*(uint8_t *)off_128E10 && !sub_12A32C() )
    return 0;
  if ( v0[1] )
    return 0;
  v1 = *((uint32_t **)off_128E14 + 2);
  if ( v1 )
  {
    while ( !v1[1] )
    {
      v1 = (uint32_t *)*v1;
      if ( !v1 )
        return 1;
    }
    return 0;
  }
  return 1;
}

