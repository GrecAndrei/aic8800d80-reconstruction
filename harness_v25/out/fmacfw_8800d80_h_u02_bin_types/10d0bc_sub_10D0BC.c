// sub_10D0BC @ 0x10d0bc, size 26 bytes
int  sub_10D0BC(int a1, int a2, int a3)
{
  int result; // r0
  uint32_t *v5; // r3

  result = sub_12E948(dword_10D0D8, a1, a3);
  v5 = off_10D0E0;
  *(uint32_t *)off_10D0DC = a1;
  *v5 = 0x1000000;
  return result;
}

