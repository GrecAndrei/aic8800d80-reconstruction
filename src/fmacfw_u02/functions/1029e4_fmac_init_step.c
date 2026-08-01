// periph_init @ 0x1029e4, size 52 bytes
// Doc: periph_init [util]: FMAC firmware init step
// periph_init [util]: FMAC firmware init step
void __noreturn periph_init()
{
  clock_enable();
  bt_enable(0, 0x96Cu);
  mmio_write_40580020();
}

