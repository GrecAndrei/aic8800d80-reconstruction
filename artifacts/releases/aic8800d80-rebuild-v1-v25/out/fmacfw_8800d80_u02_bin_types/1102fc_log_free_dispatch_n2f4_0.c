// log_free_dispatch_n2f4_0 @ 0x1102fc, size 54 bytes
// Doc: log_free_dispatch_n30a [util]: Increments free-counter and dispatches a log/free callback
// log_free_dispatch_n30a [util]: Increments free-counter and dispatches a log/free callback
int log_free_dispatch_n2f4_0()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)crypto_hw_write32_core = 1;
  }
  v0 = (int *)log_free_dispatch_n330;
  v1 = dword_11033C;
  ++*(uint32_t *)log_free_dispatch_n330;
  result = list_push_tail(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)crypto_hw_write32_core;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

