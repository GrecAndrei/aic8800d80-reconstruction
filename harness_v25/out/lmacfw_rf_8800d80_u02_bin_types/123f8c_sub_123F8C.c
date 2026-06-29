// sub_123F8C @ 0x123f8c, size 16 bytes
int  sub_123F8C(int result)
{
  *(uint32_t *)off_123F9C = *(uint32_t *)off_123F9C & 0xFFDFFFFF | (result << 21);
  return result;
}

