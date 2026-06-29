// sub_12EA5C @ 0x12ea5c, size 40 bytes
BOOL  sub_12EA5C(unsigned int a1, unsigned int a2)
{
  BOOL result; // r0

  if ( a1 > 9 )
    return 0;
  result = (*(uint32_t *)off_12EA84 >> a1) & 1;
  if ( result )
    return *((uint32_t *)off_12EA84 + 1) >= a2;
  return result;
}

