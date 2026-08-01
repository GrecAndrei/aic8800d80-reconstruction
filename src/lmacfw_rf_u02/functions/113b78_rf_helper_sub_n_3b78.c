// rf_get_reg2 @ 0x113b78, size 6 bytes
// Doc: rf_get_reg2 [rf]: Small RF helper wrapper saving r0 and returning
// rf_get_reg2 [rf]: Small RF helper wrapper saving r0 and returning
int rf_get_reg2()
{
  return mmio_read32(2u);
}

