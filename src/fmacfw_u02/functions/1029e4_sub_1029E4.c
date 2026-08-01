// periph_init @ 0x1029e4, size 52 bytes
void __noreturn periph_init()
{
  clock_enable();
  bt_enable(0, 0x96Cu);
  mmio_write_40580020();
}

