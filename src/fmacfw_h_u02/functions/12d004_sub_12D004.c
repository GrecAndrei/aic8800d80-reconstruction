// set_mmio_base @ 0x12d004, size 8 bytes
int set_mmio_base()
{
  return irq_disable_global_2(0x10000000);
}

