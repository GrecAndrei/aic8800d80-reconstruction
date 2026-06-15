// rf_reg_ack_cb @ 0x10ed74, size 8 bytes
// Doc: rf_reg_ack_cb [rf]: RF register-write acknowledge callback dispatch
// rf_reg_ack_cb [rf]: RF register-write acknowledge callback dispatch
int rf_reg_ack_cb()
{
  return MEMORY[0x1B4]();
}

