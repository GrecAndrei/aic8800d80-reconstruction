// sub_123FC8 @ 0x123fc8, size 16 bytes
int  sub_123FC8(int result)
{
  *(uint32_t *)off_123FD8 = *(uint32_t *)off_123FD8 & 0xFFFEFFFF | (result << 16);
  return result;
}

