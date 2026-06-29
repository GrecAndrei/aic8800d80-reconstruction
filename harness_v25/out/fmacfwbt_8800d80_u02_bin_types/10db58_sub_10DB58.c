// sub_10DB58 @ 0x10db58, size 16 bytes
int  sub_10DB58(char a1)
{
  int result; // r0

  result = (1 << a1) | *(uint32_t *)off_10DB68;
  *(uint32_t *)off_10DB68 = result;
  return result;
}

