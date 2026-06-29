// mmio_reg_init_n0d08c @ 0x10d08c, size 10 bytes
// Doc: mmio_reg_init_n0d08c [mmio]: Initialize MMIO register at 0x40035000 with 0x4000000
// mmio_reg_init_n0d08c [mmio]: Initialize MMIO register at 0x40035000 with 0x4000000
void mmio_reg_init_n0d08c()
{
  *(uint32_t *)off_10D098 = 0x4000000;
}

