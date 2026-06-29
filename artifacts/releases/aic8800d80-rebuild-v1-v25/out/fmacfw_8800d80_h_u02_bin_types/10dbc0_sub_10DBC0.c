// sub_10DBC0 @ 0x10dbc0, size 16 bytes
int  sub_10DBC0(char a1)
{
  int result; // r0

  result = (1 << a1) | *(uint32_t *)off_10DBD0;
  *(uint32_t *)off_10DBD0 = result;
  return result;
}

