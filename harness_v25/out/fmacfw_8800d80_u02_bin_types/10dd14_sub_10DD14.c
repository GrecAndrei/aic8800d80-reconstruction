// sub_10DD14 @ 0x10dd14, size 18 bytes
int  sub_10DD14(char a1)
{
  int result; // r0

  result = 1 << a1;
  *(uint32_t *)off_10DD28 &= ~result;
  return result;
}

