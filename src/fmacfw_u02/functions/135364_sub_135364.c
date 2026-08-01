// init_rf_tables @ 0x135364, size 44 bytes
int init_rf_tables()
{
  int v0; // r0

  v0 = check_status_bits(256, dword_13553C, dword_135538);
  return bt_is_conn_flag_set(v0);
}

