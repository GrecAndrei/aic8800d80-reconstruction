// set_tx_power @ 0x1142e4, size 16 bytes
int set_tx_power()
{
  check_status_bits(256, dword_1142F4);
  return 1;
}

