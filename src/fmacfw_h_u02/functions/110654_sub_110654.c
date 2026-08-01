// check_hardware_ready @ 0x110654, size 10 bytes
int check_hardware_ready()
{
  mmio_write_reg();
  return 1;
}

