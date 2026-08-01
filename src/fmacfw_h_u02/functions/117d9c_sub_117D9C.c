// init_mac_global_0x188290 @ 0x117d9c, size 56 bytes
int init_mac_global_0x188290()
{
  int v0; // r4

  v0 = dword_117DD4;
  sub_100200((int *)dword_117DD4, 0, 0x28u);
  clear_stats_buf(v0);
  clear_stats_buf(v0 + 8);
  clear_stats_buf(v0 + 16);
  clear_stats_buf(v0 + 24);
  return clear_stats_buf(v0 + 32);
}

