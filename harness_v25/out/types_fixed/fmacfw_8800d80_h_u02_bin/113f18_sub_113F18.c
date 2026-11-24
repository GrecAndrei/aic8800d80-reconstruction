// sub_113F18 @ 0x113f18, size 56 bytes
int sub_113F18()
{
  int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  sub_11D864();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_113F50 = 1;
  }
  v0 = (int *)off_113F54;
  ++*(_DWORD *)off_113F54;
  result = sub_12D00C(128);
  if ( *v0 )
  {
    v2 = *v0 - 1;
    v3 = *(_DWORD *)off_113F50;
    *v0 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  return result;
}

