// sub_10DBA4 @ 0x10dba4, size 16 bytes
int  sub_10DBA4(char a1)
{
  int result; // r0

  result = (1 << a1) | *(uint32_t *)off_10DBB4;
  *(uint32_t *)off_10DBB4 = result;
  return result;
}

