// log_free_dispatch_1 @ 0x110198, size 62 bytes
// Doc: log_free_dispatch [util]: Free a log buffer entry and dispatch
// log_free_dispatch [util]: Free a log buffer entry and dispatch
int log_free_dispatch_1()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(uint32_t *)rf_bus_write_n4ba = 1;
  }
  v0 = (int *)log_free_dispatch_n37c;
  v1 = log_free_dispatch_n380;
  ++*(uint32_t *)log_free_dispatch_n37c;
  result = sub_12D4F8(v1);
  if ( result )
    --*(uint32_t *)off_1101E4;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(uint32_t *)rf_bus_write_n4ba;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

