// sub_10FDF4 @ 0x10fdf4, size 46 bytes
BOOL  sub_10FDF4(unsigned int a1)
{
  if ( *(uint32_t *)off_10FE24 <= a1 && a1 <= *(uint32_t *)off_10FE24 + *((uint32_t *)off_10FE24 + 1) )
    return 1;
  if ( a1 < *(uint32_t *)off_10FE28 )
    return 0;
  return a1 <= *(uint32_t *)off_10FE28 + *((uint32_t *)off_10FE28 + 1);
}

