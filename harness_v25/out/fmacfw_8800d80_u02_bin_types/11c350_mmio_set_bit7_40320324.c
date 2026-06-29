// mmio_set_bit7_40320324 @ 0x11c350, size 12 bytes
// Doc: mmio_set_bit7_40320324 [mmio]: Set bit7 of MMIO 0x40320324 (PHY/RF control)
// mmio_set_bit7_40320324 [mmio]: Set bit7 of MMIO 0x40320324 (PHY/RF control)
void mmio_set_bit7_40320324()
{
  *(uint32_t *)off_11C35C |= 0x80u;
}

