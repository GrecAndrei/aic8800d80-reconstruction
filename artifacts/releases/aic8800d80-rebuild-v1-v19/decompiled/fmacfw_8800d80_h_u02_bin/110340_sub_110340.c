// sub_110340 @ 0x110340, size 52 bytes
int sub_110340()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_110374 = 1;
  }
  v0 = (int *)off_110378;
  v1 = dword_11037C;
  ++*(_DWORD *)off_110378;
  result = sub_12D190(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_110374;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

