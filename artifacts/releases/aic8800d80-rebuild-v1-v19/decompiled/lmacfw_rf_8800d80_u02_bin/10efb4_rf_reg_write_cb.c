// rf_reg_write_cb @ 0x10efb4, size 8 bytes
// Doc: rf_reg_write_cb [rf]: Callback after RF register write
// rf_reg_write_cb [rf]: Callback after RF register write
int rf_reg_write_cb()
{
  return MEMORY[0x1B8]();
}

