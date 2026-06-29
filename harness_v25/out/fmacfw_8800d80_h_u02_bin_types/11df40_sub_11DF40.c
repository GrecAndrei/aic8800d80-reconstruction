// sub_11DF40 @ 0x11df40, size 44 bytes
unsigned int  sub_11DF40(int a1)
{
  unsigned int *v1; // r1
  unsigned int result; // r0

  v1 = (unsigned int *)off_11DF70;
  *(uint32_t *)off_11DF6C = (a1 << 10) & 0x400 | *(uint32_t *)off_11DF6C & 0xFFFFFBFF;
  result = (a1 << 19) & 0x80000 | *v1 & 0xFFF7FFFF;
  *v1 = result;
  return result;
}

