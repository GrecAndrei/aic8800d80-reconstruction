// sub_123FA0 @ 0x123fa0, size 14 bytes
int  sub_123FA0(int result)
{
  *(uint32_t *)off_123FB0 = *(uint32_t *)off_123FB0 & 0xFFFFFFFE | result;
  return result;
}

