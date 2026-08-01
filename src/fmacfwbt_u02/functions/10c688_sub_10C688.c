// bt_dispatch @ 0x10c688, size 14 bytes
int bt_dispatch()
{
  sdio_bus_reset();
  return sdio_irq_enable();
}

