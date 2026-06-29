// mmio_get_bit_30 @ 0x101a78, size 10 bytes
// Doc: mmio_get_bit_30 [mmio]: Reads MMIO register 0x40330000 and returns bit 30
// mmio_get_bit_30 [mmio]: Reads MMIO register 0x40330000 and returns bit 30
int mmio_get_bit_30()
{
  return (*(uint32_t *)off_101A84 >> 30) & 1;
}

