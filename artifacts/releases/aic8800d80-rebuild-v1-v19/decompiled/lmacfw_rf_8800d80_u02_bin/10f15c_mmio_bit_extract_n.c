// mmio_bit_extract_n @ 0x10f15c, size 16 bytes
// Doc: mmio_bit_extract_n [mmio]: Reads MMIO register 0x7000101c and extracts 5-bit field at bit 11
// mmio_bit_extract_n [mmio]: Reads MMIO register 0x7000101c and extracts 5-bit field at bit 11
int mmio_bit_extract_n()
{
  return (unsigned __int16)sub_10EFBC(dword_10F16C, 1) >> 11;
}

