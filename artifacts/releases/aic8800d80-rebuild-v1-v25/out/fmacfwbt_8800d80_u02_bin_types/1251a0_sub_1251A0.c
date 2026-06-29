// sub_1251A0 @ 0x1251a0, size 30 bytes
int  sub_1251A0(uint32_t *a1)
{
  uint32_t *v1; // r3

  v1 = *(uint32_t **)off_1251C0;
  if ( !*(uint32_t *)off_1251C0 )
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

