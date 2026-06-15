// v23 annotated: sub_1102FC @ 0x1102fc
// Original: 1102fc_sub_1102FC.c
// Primary struct: <unclustered>
//
// sub_1102FC @ 0x1102fc, size 54 bytes
int sub_1102FC()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_110334 = 1;
  }
  v0 = (int *)off_110338;
  v1 = dword_11033C;
  ++*(_DWORD *)off_110338;
  result = sub_12D248(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_110334;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

