// set_rf_channel @ 0x102934, size 52 bytes
void __noreturn set_rf_channel()
{
  pll_enable();
  sdio_irq_enable(0, 0x96Cu);
  pll_clock_config();
}

