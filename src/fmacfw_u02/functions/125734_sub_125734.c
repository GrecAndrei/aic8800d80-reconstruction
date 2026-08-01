// init_timer @ 0x125734, size 58 bytes
int init_timer()
{
  int v0; // r5
  int v1; // r4

  v0 = dword_125770;
  v1 = dword_125774;
  memset((int *)dword_125770, 0, 0x18u);
  zero_8_bytes(v0 + 12);
  rf_test_packet_fill(v1);
  rf_test_packet_fill(v1 + 38);
  rf_test_packet_fill(v1 + 76);
  return rf_test_packet_fill(v1 + 114);
}

