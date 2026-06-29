// fwstruct annotate: 10ed6c_rf_reg_read_cb.c
// rf_reg_read_cb @ 0x10ed6c, size 8 bytes
// Doc: rf_reg_read_cb [rf]: Indirect call dispatcher jumping via function pointers at 0x1b0/0x1b4/0x1b8
// rf_reg_read_cb [rf]: Indirect call dispatcher jumping via function pointers at 0x1b0/0x1b4/0x1b8
int rf_reg_read_cb()
{
  return MEMORY[0x1B0]();
}

