// sub_11F4D8 @ 0x11f4d8, size 40 bytes
BOOL  sub_11F4D8(unsigned int a1, unsigned int a2)
{
  BOOL result; // r0

  if ( a1 > 9 )
    return 0;
  result = (*(uint32_t *)off_11F500 >> a1) & 1;
  if ( result )
    return *((uint32_t *)off_11F500 + 1) >= a2;
  return result;
}

