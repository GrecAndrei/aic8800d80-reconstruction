// sub_10FD8C @ 0x10fd8c, size 46 bytes
BOOL  sub_10FD8C(unsigned int a1)
{
  if ( *(uint32_t *)off_10FDBC <= a1 && a1 <= *(uint32_t *)off_10FDBC + *((uint32_t *)off_10FDBC + 1) )
    return 1;
  if ( a1 < *(uint32_t *)off_10FDC0 )
    return 0;
  return a1 <= *(uint32_t *)off_10FDC0 + *((uint32_t *)off_10FDC0 + 1);
}

