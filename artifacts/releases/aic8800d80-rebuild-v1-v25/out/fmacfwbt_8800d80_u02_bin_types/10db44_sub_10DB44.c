// sub_10DB44 @ 0x10db44, size 16 bytes
int  sub_10DB44(char a1)
{
  int result; // r0

  result = (1 << a1) | *((uint32_t *)off_10DB54 + 2);
  *((uint32_t *)off_10DB54 + 2) = result;
  return result;
}

