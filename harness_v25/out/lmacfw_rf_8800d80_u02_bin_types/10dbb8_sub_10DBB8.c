// sub_10DBB8 @ 0x10dbb8, size 18 bytes
int  sub_10DBB8(char a1)
{
  int result; // r0

  result = 1 << a1;
  *(uint32_t *)off_10DBCC &= ~result;
  return result;
}

