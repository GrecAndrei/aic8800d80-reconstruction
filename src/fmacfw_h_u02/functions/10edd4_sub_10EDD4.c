// write_mmio_register @ 0x10edd4, size 12 bytes
int write_mmio_register()
{
  return mmio_rmw32(dword_10EDE0, 0, 2, 1);
}

