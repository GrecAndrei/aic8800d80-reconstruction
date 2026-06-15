// v23 annotated: sub_114298 @ 0x114298
// Original: 114298_sub_114298.c
// Primary struct: <unclustered>
//
// sub_114298 @ 0x114298, size 54 bytes
// Doc: sub_1214298 [unknown]: Unknown helper, small prologue with bit shift
// sub_1214298 [unknown]: Unknown helper, small prologue with bit shift
int sub_114298()
{
  int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_1142D0 = 1;
  }
  v0 = (int *)off_1142D4;
  ++*(_DWORD *)off_1142D4;
  result = MEMORY[0x1D4]();
  if ( *v0 )
  {
    v2 = *v0 - 1;
    v3 = *(_DWORD *)off_1142D0;
    *v0 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  return result;
}

