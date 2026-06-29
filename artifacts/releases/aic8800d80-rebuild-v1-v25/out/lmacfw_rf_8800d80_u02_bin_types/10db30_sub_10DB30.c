// sub_10DB30 @ 0x10db30, size 20 bytes
BOOL  sub_10DB30(char a1)
{
  return ((1 << a1) & *(uint32_t *)off_10DB44) != 0;
}

