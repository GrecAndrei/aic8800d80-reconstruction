// log_free_dispatch_n2b4 @ 0x110114, size 52 bytes
// Doc: log_free_dispatch_n2ca [util]: Increment counter and call log free helper
// log_free_dispatch_n2ca [util]: Increment counter and call log free helper
int log_free_dispatch_n2b4()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)log_free_dispatch_0148 = 1;
  }
  v0 = (int *)off_11014C;
  v1 = log_free_dispatch_n2f0;
  ++*(uint32_t *)off_11014C;
  result = sub_12D4F8(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)log_free_dispatch_0148;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

