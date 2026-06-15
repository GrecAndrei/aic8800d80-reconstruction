// sub_1101BC @ 0x1101bc, size 54 bytes
int sub_1101BC()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_1101F4 = 1;
  }
  v0 = (int *)off_1101F8;
  v1 = dword_1101FC;
  ++*(_DWORD *)off_1101F8;
  result = sub_12D108(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_1101F4;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

