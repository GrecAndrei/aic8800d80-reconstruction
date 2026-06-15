// v23 annotated: sub_110318 @ 0x110318
// Original: 110318_sub_110318.c
// Primary struct: <unclustered>
//
// sub_110318 @ 0x110318, size 54 bytes
// Doc: log_free_dispatch_n4ec [util]: Dispatch free-list logging routine (variant 4ec)
// log_free_dispatch_n4ec [util]: Dispatch free-list logging routine (variant 4ec)
int sub_110318()
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
  v1 = log_free_dispatch_0358;
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

