// sub_12D210 @ 0x12d210, size 26 bytes
BOOL  sub_12D210(uint32_t **a1, uint32_t *a2)
{
  uint32_t *v2; // r3

  v2 = *a1;
  if ( *a1 == a2 )
    return 1;
  while ( v2 )
  {
    v2 = (uint32_t *)*v2;
    if ( a2 == v2 )
      return 1;
  }
  return a2 == nullptr;
}

