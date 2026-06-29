// sub_10DB18 @ 0x10db18, size 18 bytes
int  sub_10DB18(char a1)
{
  int result; // r0

  result = 1 << a1;
  *(uint32_t *)off_10DB2C &= ~result;
  return result;
}

