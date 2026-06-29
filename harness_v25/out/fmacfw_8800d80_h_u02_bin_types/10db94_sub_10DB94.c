// sub_10DB94 @ 0x10db94, size 18 bytes
int  sub_10DB94(char a1)
{
  int result; // r0

  result = 1 << a1;
  *((uint32_t *)off_10DBA8 + 2) &= ~result;
  return result;
}

