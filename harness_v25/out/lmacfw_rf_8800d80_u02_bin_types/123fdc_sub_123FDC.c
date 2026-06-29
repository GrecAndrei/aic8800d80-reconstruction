// sub_123FDC @ 0x123fdc, size 16 bytes
int  sub_123FDC(int result)
{
  *(uint32_t *)off_123FEC = *(uint32_t *)off_123FEC & 0xFC0FFFFF | (result << 20);
  return result;
}

