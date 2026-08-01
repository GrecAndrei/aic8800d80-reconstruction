// mmio_write_70001408 @ 0x10ef14, size 12 bytes
int mmio_write_70001408()
{
  return mmio_rmw32(dword_10EF20, 0, 2, 1);
}

