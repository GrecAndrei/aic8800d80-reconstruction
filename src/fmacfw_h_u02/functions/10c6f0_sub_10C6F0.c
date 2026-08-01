// interrupt_dispatcher @ 0x10c6f0, size 14 bytes
int interrupt_dispatcher()
{
  rf_clock_enable();
  return peripheral_clock_config();
}

