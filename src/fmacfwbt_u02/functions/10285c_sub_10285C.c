// flash_init @ 0x10285c, size 52 bytes
void __noreturn flash_init()
{
  pll_enable();
  radio_init(0, 0x96Cu);
  flash_cr_unlock();
}

