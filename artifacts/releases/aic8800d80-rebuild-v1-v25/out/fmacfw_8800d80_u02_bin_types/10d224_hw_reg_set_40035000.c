// hw_reg_set_40035000 @ 0x10d224, size 10 bytes
// Doc: hw_reg_set_40035000 [mmio]: Write 0x02000000 to MMIO register at 0x40035000
// hw_reg_set_40035000 [mmio]: Write 0x02000000 to MMIO register at 0x40035000
void hw_reg_set_40035000()
{
  *(uint32_t *)off_10D230 = 0x2000000;
}

