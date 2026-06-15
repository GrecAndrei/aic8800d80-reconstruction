// v23 annotated: mmio_flag_get_bit1a @ 0x101a38
// Original: 101a38_mmio_flag_get_bit1a.c
// Primary struct: <unclustered>
//
// mmio_flag_get_bit1a @ 0x101a38, size 10 bytes
// Doc: mmio_flag_get_bit1a [mmio]: Read flag bit 0x1a from MMIO register 0x40330000
// mmio_flag_get_bit1a [mmio]: Read flag bit 0x1a from MMIO register 0x40330000
int mmio_flag_get_bit1a()
{
  return (*(_DWORD *)off_101A44 >> 26) & 1;
}

