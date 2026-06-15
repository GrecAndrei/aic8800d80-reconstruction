// v23 annotated: sub_110114 @ 0x110114
// Original: 110114_sub_110114.c
// Primary struct: <unclustered>
//
// sub_110114 @ 0x110114, size 52 bytes
int sub_110114()
{
  int *v0; // r4
  int v1; // r0
  int result; // r0
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_110148 = 1;
  }
  v0 = (int *)off_11014C;
  v1 = dword_110150;
  ++*(_DWORD *)off_11014C;
  result = sub_12D4F8(v1);
  if ( *v0 )
  {
    v3 = *v0 - 1;
    v4 = *(_DWORD *)off_110148;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
  return result;
}

