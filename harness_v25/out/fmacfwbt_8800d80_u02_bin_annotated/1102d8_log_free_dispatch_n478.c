// fwstruct annotate: 1102d8_log_free_dispatch_n478.c
// log_free_dispatch_n478 @ 0x1102d8, size 52 bytes
// Doc: log_free_dispatch_n490 [util]: Free a log buffer and re-dispatch logging
// log_free_dispatch_n490 [util]: Free a log buffer and re-dispatch logging
int log_free_dispatch_n478()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_11030C = 1;
  }
  v0 = (int *)log_free_dispatch_n4b0;
  v1 = log_free_dispatch_n4b4;
  ++*(_DWORD *)log_free_dispatch_n4b0;
  result = sub_12D4F8(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_11030C;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

