// init_bt_global_0x190310 @ 0x1255f4, size 58 bytes
int init_bt_global_0x190310()
{
  int v0; // r5
  int v1; // r4

  v0 = dword_125630;
  v1 = dword_125634;
  sub_100200((int *)dword_125630, 0, 0x18u);
  clear_stats_buf(v0 + 12);
  init_fixed_packet_header(v1);
  init_fixed_packet_header(v1 + 38);
  init_fixed_packet_header(v1 + 76);
  return init_fixed_packet_header(v1 + 114);
}

