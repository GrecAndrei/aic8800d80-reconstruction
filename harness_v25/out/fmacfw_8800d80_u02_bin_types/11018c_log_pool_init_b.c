// log_pool_init_b @ 0x11018c, size 72 bytes
// Doc: log_free_dispatch_n19c [util]: Allocate log dispatch context and free log resources
// log_free_dispatch_n19c [util]: Allocate log dispatch context and free log resources
int log_pool_init_b()
{
  void *v0; // r8
  int result; // r0
  uint32_t *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  unsigned int v6; // r1

  v0 = log_free_pool_dispatch2_n500_01e0;
  result = sub_12D240(log_free_pool_dispatch2_n4f4);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 6) )
  {
    v2 = log_free_dispatch_n1d0;
    v3 = dword_1101DC;
    v4 = log_free_pool_dispatch2_n4f4;
    v5 = 0;
    do
    {
      sub_10FB28(v3, 0x63Cu);
      result = list_push_tail(v4);
      v6 = *(unsigned __int16 *)(*(uint32_t *)v0 + 6);
      ++v5;
      ++*v2;
    }
    while ( v6 > (unsigned __int16)v5 );
  }
  return result;
}

