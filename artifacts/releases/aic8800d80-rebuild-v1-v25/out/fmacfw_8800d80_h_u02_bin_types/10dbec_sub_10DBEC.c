// sub_10DBEC @ 0x10dbec, size 20 bytes
BOOL  sub_10DBEC(char a1)
{
  return ((1 << a1) & *(uint32_t *)off_10DC00) != 0;
}

