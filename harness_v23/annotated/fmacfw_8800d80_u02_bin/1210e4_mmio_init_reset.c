// v23 annotated: mmio_init_reset @ 0x1210e4
// Original: 1210e4_mmio_init_reset.c
// Primary struct: <unclustered>
//
// mmio_init_reset @ 0x1210e4, size 14 bytes
// Doc: mmio_init_reset [mmio]: Initialize MMIO control register 0x40320038
// mmio_init_reset [mmio]: Initialize MMIO control register 0x40320038
int mmio_init_reset()
{
  *(_DWORD *)off_1210F4 = 48;
  return sub_12CD34(0);
}

