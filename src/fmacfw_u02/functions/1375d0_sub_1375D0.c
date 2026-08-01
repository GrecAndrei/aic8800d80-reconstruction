// clear_1924d0_buffer @ 0x1375d0, size 26 bytes
int *clear_1924d0_buffer()
{
  rx_phy_status_parse(4u, 0);
  return memset((int *)dword_1375EC, 0, 0xFC0u);
}

