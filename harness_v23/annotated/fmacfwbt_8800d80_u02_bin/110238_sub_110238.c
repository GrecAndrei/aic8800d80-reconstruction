// v23 annotated: sub_110238 @ 0x110238
// Original: 110238_sub_110238.c
// Primary struct: <unclustered>
//
// sub_110238 @ 0x110238, size 62 bytes
// Doc: log_free_dispatch_0274 [util]: Dispatch and free log buffer entries
// log_free_dispatch_0274 [util]: Dispatch and free log buffer entries
int sub_110238()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_110278 = 1;
  }
  v0 = (int *)log_free_dispatch_n41c;
  v1 = log_free_dispatch_n420;
  ++*(_DWORD *)log_free_dispatch_n41c;
  result = sub_12D4F8(v1);
  if ( result )
    --*(_DWORD *)off_110284;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_110278;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

