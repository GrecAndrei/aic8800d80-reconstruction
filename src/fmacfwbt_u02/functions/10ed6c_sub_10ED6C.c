// write_reg_70001408 @ 0x10ed6c, size 12 bytes
// Doc: write_reg_70001408 [unknown]: Unknown helper, dispatches or processes input
// write_reg_70001408 [unknown]: Unknown helper, dispatches or processes input
int write_reg_70001408()
{
  return atomic_reg_write(dword_10ED78, 0, 2, 1);
}

