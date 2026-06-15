// rf_reg_read_cb_efa4 @ 0x10efa4, size 8 bytes
// Doc: rf_reg_read_cb_efa4 [rf]: RF register read callback dispatch table (0x1b0/0x1b4/0x1b8)
// rf_reg_read_cb_efa4 [rf]: RF register read callback dispatch table (0x1b0/0x1b4/0x1b8)
int rf_reg_read_cb_efa4()
{
  return MEMORY[0x1B0]();
}

