// v23 annotated: sub_110430 @ 0x110430
// Original: 110430_sub_110430.c
// Primary struct: <unclustered>
//
// sub_110430 @ 0x110430, size 62 bytes
int sub_110430()
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
    *(_DWORD *)off_110470 = 1;
  }
  v0 = (int *)off_110474;
  v1 = dword_110478;
  ++*(_DWORD *)off_110474;
  result = sub_12D248(v1);
  v3 = *v0;
  ++*(_DWORD *)off_11047C;
  if ( v3 )
  {
    v4 = v3 - 1;
    v5 = *(_DWORD *)off_110470;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  return result;
}

