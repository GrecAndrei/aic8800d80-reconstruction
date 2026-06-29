// log_free_dispatch_n2f2 @ 0x1244f8, size 36 bytes
// Doc: log_free_dispatch_n2f2 [util]: Dispatches log free with rotated value, likely a logger release
// log_free_dispatch_n2f2 [util]: Dispatches log free with rotated value, likely a logger release
int log_free_dispatch_n2f2()
{
  int result; // r0
  int v1; // r3

  result = rf_table_lookup(2u);
  v1 = (unsigned __int16)(*(uint16_t *)off_12451C + 1);
  if ( v1 == 10 )
  {
    *(uint16_t *)off_12451C = 0;
    return rf_init_n_dc(result);
  }
  else
  {
    *(uint16_t *)off_12451C = v1;
  }
  return result;
}

