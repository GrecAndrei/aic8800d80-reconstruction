// sub_124F7C @ 0x124f7c, size 30 bytes
int  sub_124F7C(uint32_t *a1)
{
  uint32_t *v1; // r3

  v1 = *(uint32_t **)off_124F9C;
  if ( !*(uint32_t *)off_124F9C )
    return (int)v1;
  if ( v1 != a1 )
  {
    while ( 1 )
    {
      v1 = (uint32_t *)*v1;
      if ( !v1 )
        break;
      if ( a1 == v1 )
        return 1;
    }
    return (int)v1;
  }
  return 1;
}

