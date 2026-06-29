// fwstruct annotate: 11414c_log_free_pool_e.c
// log_free_pool_e @ 0x11414c, size 72 bytes
// Doc: log_free_pool_e [util]: Return buffer to log free pool variant E
// log_free_pool_e [util]: Return buffer to log free pool variant E
int log_free_pool_e()
{
  int *v0; // r5
  _DWORD *v1; // r4
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_114194 = 1;
  }
  v0 = (int *)off_114198;
  v1 = off_11419C;
  ++*(_DWORD *)off_114198;
  while ( !*v1 )
    ;
  result = sub_12D108(*(_DWORD *)off_1141A0 + 628);
  *v1 = 1;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_114194;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

