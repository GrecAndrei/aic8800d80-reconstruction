// sub_10DCD4 @ 0x10dcd4, size 18 bytes
int  sub_10DCD4(char a1)
{
  int result; // r0

  result = 1 << a1;
  *((uint32_t *)off_10DCE8 + 2) &= ~result;
  return result;
}

