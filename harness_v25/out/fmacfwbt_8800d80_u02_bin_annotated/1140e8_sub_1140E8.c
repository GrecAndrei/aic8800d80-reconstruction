// fwstruct annotate: 1140e8_sub_1140E8.c
// sub_1140E8 @ 0x1140e8, size 72 bytes
int sub_1140E8()
{
  int *v0; // r5
  _DWORD *v1; // r4
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_114130 = 1;
  }
  v0 = (int *)off_114134;
  v1 = off_114138;
  ++*(_DWORD *)off_114134;
  while ( !*v1 )
    ;
  result = sub_12D470(*(_DWORD *)off_11413C + 564);
  *v1 = 1;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_114130;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

