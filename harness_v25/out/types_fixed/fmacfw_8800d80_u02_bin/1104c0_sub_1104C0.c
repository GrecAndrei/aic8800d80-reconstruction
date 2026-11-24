// sub_1104C0 @ 0x1104c0, size 54 bytes
int sub_1104C0()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_1104F8 = 1;
  }
  v0 = (int *)off_1104FC;
  v1 = dword_110500;
  ++*(_DWORD *)off_1104FC;
  result = sub_12D248(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_1104F8;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

