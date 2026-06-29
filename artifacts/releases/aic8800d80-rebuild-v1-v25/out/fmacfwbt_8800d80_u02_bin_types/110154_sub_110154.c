// sub_110154 @ 0x110154, size 54 bytes
// Doc: log_free_dispatch_n31e [util]: Dispatch log buffer free and load next entry header
// log_free_dispatch_n31e [util]: Dispatch log buffer free and load next entry header
int sub_110154()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)off_11018C = 1;
  }
  v0 = (int *)log_free_dispatch_n330;
  v1 = dword_110194;
  ++*(uint32_t *)log_free_dispatch_n330;
  result = list_push_tail(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)off_11018C;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

