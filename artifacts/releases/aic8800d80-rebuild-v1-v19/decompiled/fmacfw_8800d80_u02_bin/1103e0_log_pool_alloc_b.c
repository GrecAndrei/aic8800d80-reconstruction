// log_pool_alloc_b @ 0x1103e0, size 62 bytes
// Doc: log_free_dispatch_408 [util]: Dispatches freed log buffers
// log_free_dispatch_408 [util]: Dispatches freed log buffers
int log_pool_alloc_b()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)log_free_dispatch_n418 = 1;
  }
  v0 = (int *)log_free_dispatch_n41c_0424;
  v1 = log_free_dispatch_n420_0428;
  ++*(_DWORD *)log_free_dispatch_n41c_0424;
  result = rf_bus_mark_n100_d2d0(v1);
  if ( result )
    --*(_DWORD *)log_free_dispatch_42c;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)log_free_dispatch_n418;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

