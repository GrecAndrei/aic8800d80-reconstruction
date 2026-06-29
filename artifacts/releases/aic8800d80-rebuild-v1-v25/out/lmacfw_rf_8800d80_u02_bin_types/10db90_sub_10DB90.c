// sub_10DB90 @ 0x10db90, size 16 bytes
int  sub_10DB90(char a1)
{
  int result; // r0

  result = (1 << a1) | *((uint32_t *)off_10DBA0 + 2);
  *((uint32_t *)off_10DBA0 + 2) = result;
  return result;
}

