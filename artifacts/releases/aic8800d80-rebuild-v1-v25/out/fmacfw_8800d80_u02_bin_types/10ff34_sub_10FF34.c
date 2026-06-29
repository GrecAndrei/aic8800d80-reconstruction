// sub_10FF34 @ 0x10ff34, size 46 bytes
BOOL  sub_10FF34(unsigned int a1)
{
  if ( *(uint32_t *)off_10FF64 <= a1 && a1 <= *(uint32_t *)off_10FF64 + *((uint32_t *)off_10FF64 + 1) )
    return 1;
  if ( a1 < *(uint32_t *)off_10FF68 )
    return 0;
  return a1 <= *(uint32_t *)off_10FF68 + *((uint32_t *)off_10FF68 + 1);
}

