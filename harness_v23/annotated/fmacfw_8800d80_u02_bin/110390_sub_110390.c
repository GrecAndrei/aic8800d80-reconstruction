// v23 annotated: sub_110390 @ 0x110390
// Original: 110390_sub_110390.c
// Primary struct: <unclustered>
//
// sub_110390 @ 0x110390, size 62 bytes
int sub_110390()
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
    *(_DWORD *)off_1103D0 = 1;
  }
  v0 = (int *)off_1103D4;
  v1 = dword_1103D8;
  ++*(_DWORD *)off_1103D4;
  result = sub_12D248(v1);
  v3 = *v0;
  ++*(_DWORD *)off_1103DC;
  if ( v3 )
  {
    v4 = v3 - 1;
    v5 = *(_DWORD *)off_1103D0;
    *v0 = v4;
    if ( !v4 )
    {
      if ( v5 )
        __enable_irq();
    }
  }
  return result;
}

