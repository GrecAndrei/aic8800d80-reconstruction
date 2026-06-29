// sub_123FB4 @ 0x123fb4, size 16 bytes
int  sub_123FB4(int result)
{
  *(uint32_t *)off_123FC4 = *(uint32_t *)off_123FC4 & 0xF0FFFFFF | (result << 24);
  return result;
}

