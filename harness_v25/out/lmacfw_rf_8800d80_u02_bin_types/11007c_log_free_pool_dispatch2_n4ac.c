// log_free_pool_dispatch2_n4ac @ 0x11007c, size 72 bytes
// Doc: log_free_pool_dispatch2_n4d0 [util]: Dispatch free pool entry and log release
// log_free_pool_dispatch2_n4d0 [util]: Dispatch free pool entry and log release
int log_free_pool_dispatch2_n4ac()
{
  void *v0; // r8
  int result; // r0
  uint32_t *v2; // r5
  int v3; // r7
  int v4; // r6
  int v5; // r4
  unsigned int v6; // r1

  v0 = log_free_pool_dispatch2_n500;
  result = sub_11E71C(log_free_pool_dispatch2_00c4);
  if ( *(uint16_t *)(*(uint32_t *)v0 + 6) )
  {
    v2 = log_free_pool_dispatch2_n4f8;
    v3 = log_free_pool_dispatch2_n4fc;
    v4 = log_free_pool_dispatch2_00c4;
    v5 = 0;
    do
    {
      log_pool_alloc2_a18(v3, 0x63Cu);
      result = list_push_tail(v4);
      v6 = *(unsigned __int16 *)(*(uint32_t *)v0 + 6);
      ++v5;
      ++*v2;
    }
    while ( v6 > (unsigned __int16)v5 );
  }
  return result;
}

