// v23 annotated: sub_110380 @ 0x110380
// Original: 110380_sub_110380.c
// Primary struct: <unclustered>
//
// sub_110380 @ 0x110380, size 54 bytes
int sub_110380()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_1103B8 = 1;
  }
  v0 = (int *)off_1103BC;
  v1 = dword_1103C0;
  ++*(_DWORD *)off_1103BC;
  result = sub_12D108(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_1103B8;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

