// fwstruct annotate: 1103e0_sub_1103E0.c
// sub_1103E0 @ 0x1103e0, size 62 bytes
int sub_1103E0()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_110420 = 1;
  }
  v0 = (int *)off_110424;
  v1 = dword_110428;
  ++*(_DWORD *)off_110424;
  result = sub_12D2D0(v1);
  if ( result )
    --*(_DWORD *)off_11042C;
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_110420;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

