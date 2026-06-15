// v23 annotated: sub_113EB4 @ 0x113eb4
// Original: 113eb4_sub_113EB4.c
// Primary struct: <unclustered>
//
// sub_113EB4 @ 0x113eb4, size 56 bytes
int sub_113EB4()
{
  int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  sub_11DDE4();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_113EEC = 1;
  }
  v0 = (int *)off_113EF0;
  ++*(_DWORD *)off_113EF0;
  result = sub_12D374(128);
  if ( *v0 )
  {
    v2 = *v0 - 1;
    v3 = *(_DWORD *)off_113EEC;
    *v0 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  return result;
}

