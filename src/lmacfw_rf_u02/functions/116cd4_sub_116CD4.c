// disable_irq_800000 @ 0x116cd4, size 8 bytes
int disable_irq_800000()
{
  return set_busy_flag_alt(0x800000);
}

