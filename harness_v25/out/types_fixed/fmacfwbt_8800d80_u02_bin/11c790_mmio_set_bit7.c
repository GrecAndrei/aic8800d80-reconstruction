// mmio_set_bit7 @ 0x11c790, size 12 bytes
// Doc: mmio_set_bit7 [mmio]: Set bit 0x80 in MMIO register at 0x40320324
// mmio_set_bit7 [mmio]: Set bit 0x80 in MMIO register at 0x40320324
void mmio_set_bit7()
{
  *(_DWORD *)off_11C79C |= 0x80u;
}

