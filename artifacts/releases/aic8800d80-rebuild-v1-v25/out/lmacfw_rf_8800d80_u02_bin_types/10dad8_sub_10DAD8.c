// sub_10DAD8 @ 0x10dad8, size 18 bytes
int  sub_10DAD8(char a1)
{
  int result; // r0

  result = 1 << a1;
  *((uint32_t *)off_10DAEC + 2) &= ~result;
  return result;
}

