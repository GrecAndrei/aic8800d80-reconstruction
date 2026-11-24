// log_free_pool_a @ 0x110390, size 62 bytes
// Doc: log_free_dispatch_n39d [util]: Dispatches and frees log entry from log ring
// log_free_dispatch_n39d [util]: Dispatches and frees log entry from log ring
int log_free_pool_a()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r3
  int v5; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_1103D0 = 1;
  }
  v0 = (int *)log_free_dispatch_n3cc;
  v1 = log_free_dispatch_n3d0;
  ++*(_DWORD *)log_free_dispatch_n3cc;
  result = list_push_tail(v1);
  v3 = *v0;
  ++*(_DWORD *)log_free_dispatch_n3d4_03dc;
  if ( v3 )
  {
    v4 = v3 - 1;
    v5 = *(_DWORD *)off_1103D0;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  return result;
}

