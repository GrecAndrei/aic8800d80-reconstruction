// flash_init @ 0x10285c, size 52 bytes
// Doc: flash_init [mac]: Initialize fmac module and dispatch to sub-init routine
// flash_init [mac]: Initialize fmac module and dispatch to sub-init routine
void __noreturn flash_init()
{
  pll_enable();
  radio_init(0, 0x96Cu);
  flash_cr_unlock();
}

