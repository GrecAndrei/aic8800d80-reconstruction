// log_free_dispatch_n274 @ 0x1100d4, size 52 bytes
// Doc: log_free_dispatch_2a6 [util]: Dispatches freed log buffer entries
// log_free_dispatch_2a6 [util]: Dispatches freed log buffer entries
int log_free_dispatch_n274()
{
  void *v0; // r5
  int result; // r0
  int v2; // r7
  int v3; // r6
  int v4; // r4

  v0 = off_110108;
  result = bt_xtal_init_check(log_free_dispatch_n2ac);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 4) )
  {
    v2 = log_free_dispatch_n2b0;
    v3 = log_free_dispatch_n2ac;
    v4 = 0;
    do
    {
      log_pool_alloc2(v2, 0x7Cu);
      result = list_push_tail(v3);
      ++v4;
    }
    while ( *(unsigned __int16 *)(*(uint32_t *)v0 + 4) > (unsigned int)(unsigned __int16)v4 );
  }
  return result;
}

