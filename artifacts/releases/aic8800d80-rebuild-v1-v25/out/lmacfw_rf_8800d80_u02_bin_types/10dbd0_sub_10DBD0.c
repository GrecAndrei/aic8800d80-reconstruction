// sub_10DBD0 @ 0x10dbd0, size 20 bytes
BOOL  sub_10DBD0(char a1)
{
  return ((1 << a1) & *(uint32_t *)off_10DBE4) != 0;
}

