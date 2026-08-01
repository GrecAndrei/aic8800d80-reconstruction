// gpio_write @ 0x10c830, size 14 bytes
int gpio_write()
{
  peripheral_clock_enable();
  return peripheral_config_write();
}

