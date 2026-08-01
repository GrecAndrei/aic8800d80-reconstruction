// rf_get_reg0x1b @ 0x114208, size 6 bytes
// Doc: rf_get_reg0x1b [unknown]: Unknown helper, saves r4/lr
// rf_get_reg0x1b [unknown]: Unknown helper, saves r4/lr
int rf_get_reg0x1b()
{
  return mmio_read32(0x1Bu);
}

