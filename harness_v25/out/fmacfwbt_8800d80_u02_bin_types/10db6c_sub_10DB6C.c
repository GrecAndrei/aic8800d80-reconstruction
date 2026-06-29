// sub_10DB6C @ 0x10db6c, size 18 bytes
int  sub_10DB6C(char a1)
{
  int result; // r0

  result = 1 << a1;
  *(uint32_t *)off_10DB80 &= ~result;
  return result;
}

