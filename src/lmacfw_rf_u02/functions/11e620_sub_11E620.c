// disable_irq_10000000 @ 0x11e620, size 8 bytes
int disable_irq_10000000()
{
  return set_busy_flag_alt(0x10000000);
}

