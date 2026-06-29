// sub_12EC84 @ 0x12ec84, size 40 bytes
BOOL  sub_12EC84(unsigned int a1, unsigned int a2)
{
  BOOL result; // r0

  if ( a1 > 9 )
    return 0;
  result = (*(uint32_t *)off_12ECAC >> a1) & 1;
  if ( result )
    return *((uint32_t *)off_12ECAC + 1) >= a2;
  return result;
}

