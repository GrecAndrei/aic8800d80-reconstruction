// clear_config_32 @ 0x115fbc, size 48 bytes
int clear_config_32()
{
  int v0; // r4

  v0 = dword_115FEC;
  sub_100200((int *)dword_115FEC, 0, 0x20u);
  list_init(v0);
  list_init(v0 + 8);
  list_init(v0 + 16);
  return list_init(v0 + 24);
}

