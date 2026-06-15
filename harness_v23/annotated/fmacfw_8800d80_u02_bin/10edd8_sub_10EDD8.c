// v23 annotated: sub_10EDD8 @ 0x10edd8
// Original: 10edd8_sub_10EDD8.c
// Primary struct: <unclustered>
//
// sub_10EDD8 @ 0x10edd8, size 70 bytes
int __fastcall sub_10EDD8(int a1, int a2, int a3)
{
  int *v3; // r5
  _DWORD *v4; // r4
  int result; // r0
  int v6; // r3
  int v7; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_10EE20 = 1;
  }
  v3 = (int *)off_10EE24;
  ++*(_DWORD *)off_10EE24;
  if ( a3 )
  {
    v4 = off_10EE28;
    while ( !*(_DWORD *)off_10EE28 )
      ;
    result = sub_10ED74();
    *v4 = 1;
  }
  else
  {
    result = sub_10ED74();
  }
  if ( *v3 )
  {
    v6 = *v3 - 1;
    v7 = *(_DWORD *)off_10EE20;
    *v3 = v6;
    if ( !v6 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}

