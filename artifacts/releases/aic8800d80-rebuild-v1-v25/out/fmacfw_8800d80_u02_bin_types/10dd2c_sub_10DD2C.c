// sub_10DD2C @ 0x10dd2c, size 20 bytes
BOOL  sub_10DD2C(char a1)
{
  return ((1 << a1) & *(uint32_t *)off_10DD40) != 0;
}

