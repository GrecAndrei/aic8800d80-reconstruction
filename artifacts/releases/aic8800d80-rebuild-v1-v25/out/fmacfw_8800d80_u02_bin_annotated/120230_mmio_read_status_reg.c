// fwstruct annotate: 120230_mmio_read_status_reg.c
// mmio_read_status_reg @ 0x120230, size 16 bytes
// Doc: mmio_read_status_reg [mmio]: Read status register at 0x40501000+0x2710
// mmio_read_status_reg [mmio]: Read status register at 0x40501000+0x2710
int __fastcall mmio_read_status_reg(int a1)
{
  return timestamp_update(a1 + 48, *((_DWORD *)off_120240 + 4) + 10000);
}

