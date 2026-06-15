// mmio_reg_bit0_read @ 0x10d698, size 10 bytes
// Doc: mmio_reg_bit0_read [mmio]: Reads bit 0 of MMIO register at 0x40032014
// mmio_reg_bit0_read [mmio]: Reads bit 0 of MMIO register at 0x40032014
int mmio_reg_bit0_read()
{
  return *(_DWORD *)off_10D6A4 & 1;
}

