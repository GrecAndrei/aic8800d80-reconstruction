// log_free_dispatch_n1dc @ 0x11003c, size 52 bytes
// Doc: log_free_dispatch_n20a [util]: Dispatch log buffer free handler with priority threshold
// log_free_dispatch_n20a [util]: Dispatch log buffer free handler with priority threshold
int log_free_dispatch_n1dc()
{
  void *v0; // r5
  int result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4

  v0 = log_free_dispatch_n210;
  result = bt_xtal_init_check(rf_bus_reset2_n3a9);
  if ( *(_WORD *)(*(_DWORD *)v0 + 2) )
  {
    v2 = rf_bus_mark_n_458;
    v3 = rf_bus_reset2_n3a9;
    v4 = 0;
    do
    {
      log_pool_alloc2(v2, 0xCu);
      result = list_push_tail(v3);
      ++v4;
    }
    while ( *(unsigned __int16 *)(*(_DWORD *)v0 + 2) > (unsigned int)(unsigned __int16)v4 );
  }
  return result;
}

