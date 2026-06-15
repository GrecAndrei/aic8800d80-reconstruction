// v23 annotated: log_free_pool_b @ 0x110430
// Original: 110430_log_free_pool_b.c
// Primary struct: <unclustered>
//
// log_free_pool_b @ 0x110430, size 62 bytes
// Doc: log_free_dispatch_n464 [util]: Free a log buffer entry and dispatch log processing
// log_free_dispatch_n464 [util]: Free a log buffer entry and dispatch log processing
int log_free_pool_b()
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
    *(_DWORD *)log_free_dispatch_n468 = 1;
  }
  v0 = (int *)log_free_dispatch_n46c;
  v1 = dword_110478;
  ++*(_DWORD *)log_free_dispatch_n46c;
  result = list_push_tail(v1);
  v3 = *v0;
  ++*(_DWORD *)log_free_dispatch_n474_047c;
  if ( v3 )
  {
    v4 = v3 - 1;
    v5 = *(_DWORD *)log_free_dispatch_n468;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  return result;
}

