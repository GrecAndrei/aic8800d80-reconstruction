// v23 annotated: sub_114058 @ 0x114058
// Original: 114058_sub_114058.c
// Primary struct: <unclustered>
//
// sub_114058 @ 0x114058, size 56 bytes
int sub_114058()
{
  int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  sub_11D9A4();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_114090 = 1;
  }
  v0 = (int *)off_114094;
  ++*(_DWORD *)off_114094;
  result = sub_12D14C(128);
  if ( *v0 )
  {
    v2 = *v0 - 1;
    v3 = *(_DWORD *)off_114090;
    *v0 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  return result;
}

