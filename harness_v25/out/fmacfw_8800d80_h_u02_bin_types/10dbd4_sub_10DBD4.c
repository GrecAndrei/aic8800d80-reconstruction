// sub_10DBD4 @ 0x10dbd4, size 18 bytes
int  sub_10DBD4(char a1)
{
  int result; // r0

  result = 1 << a1;
  *(uint32_t *)off_10DBE8 &= ~result;
  return result;
}

