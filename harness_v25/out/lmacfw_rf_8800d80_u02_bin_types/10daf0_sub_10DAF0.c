// sub_10DAF0 @ 0x10daf0, size 16 bytes
int  sub_10DAF0(char a1)
{
  int result; // r0

  result = (1 << a1) | *((uint32_t *)off_10DB00 + 2);
  *((uint32_t *)off_10DB00 + 2) = result;
  return result;
}

