// v23 annotated: sub_113A48 @ 0x113a48
// Original: 113a48_sub_113A48.c
// Primary struct: <unclustered>
//
// sub_113A48 @ 0x113a48, size 54 bytes
int sub_113A48()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_113A80 = 1;
  }
  v0 = (int *)off_113A84;
  v1 = dword_113A88;
  ++*(_DWORD *)off_113A84;
  result = sub_12D248(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_113A80;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

