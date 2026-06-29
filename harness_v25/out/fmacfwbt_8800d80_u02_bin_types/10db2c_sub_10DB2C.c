// sub_10DB2C @ 0x10db2c, size 18 bytes
int  sub_10DB2C(char a1)
{
  int result; // r0

  result = 1 << a1;
  *((uint32_t *)off_10DB40 + 2) &= ~result;
  return result;
}

