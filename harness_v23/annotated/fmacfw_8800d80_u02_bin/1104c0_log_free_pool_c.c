// v23 annotated: log_free_pool_c @ 0x1104c0
// Original: 1104c0_log_free_pool_c.c
// Primary struct: <unclustered>
//
// log_free_pool_c @ 0x1104c0, size 54 bytes
// Doc: sub_1204FE0 [unknown]: Helper comparing two pointers/handles with extra arg
// sub_1204FE0 [unknown]: Helper comparing two pointers/handles with extra arg
int log_free_pool_c()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)log_free_dispatch_n4f0 = 1;
  }
  v0 = (int *)log_free_dispatch_n4f4;
  v1 = log_free_dispatch_n4f8;
  ++*(_DWORD *)log_free_dispatch_n4f4;
  result = list_push_tail(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)log_free_dispatch_n4f0;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

