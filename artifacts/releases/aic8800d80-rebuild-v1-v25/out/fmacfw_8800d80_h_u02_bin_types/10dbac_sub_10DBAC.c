// sub_10DBAC @ 0x10dbac, size 16 bytes
int  sub_10DBAC(char a1)
{
  int result; // r0

  result = (1 << a1) | *((uint32_t *)off_10DBBC + 2);
  *((uint32_t *)off_10DBBC + 2) = result;
  return result;
}

