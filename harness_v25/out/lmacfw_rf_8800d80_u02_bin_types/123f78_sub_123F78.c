// sub_123F78 @ 0x123f78, size 16 bytes
int  sub_123F78(int result)
{
  *(uint32_t *)off_123F88 = *(uint32_t *)off_123F88 & 0xFFEFFFFF | (result << 20);
  return result;
}

