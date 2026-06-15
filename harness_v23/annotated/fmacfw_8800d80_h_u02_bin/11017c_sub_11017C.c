// v23 annotated: sub_11017C @ 0x11017c
// Original: 11017c_sub_11017C.c
// Primary struct: <unclustered>
//
// sub_11017C @ 0x11017c, size 52 bytes
int sub_11017C()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_1101B0 = 1;
  }
  v0 = (int *)off_1101B4;
  v1 = dword_1101B8;
  ++*(_DWORD *)off_1101B4;
  result = sub_12D190(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_1101B0;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

