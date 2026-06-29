// sub_10DD00 @ 0x10dd00, size 16 bytes
int  sub_10DD00(char a1)
{
  int result; // r0

  result = (1 << a1) | *(uint32_t *)off_10DD10;
  *(uint32_t *)off_10DD10 = result;
  return result;
}

