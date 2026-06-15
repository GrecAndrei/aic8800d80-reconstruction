// v23 annotated: sub_10EBDC @ 0x10ebdc
// Original: 10ebdc_sub_10EBDC.c
// Primary struct: <unclustered>
//
// sub_10EBDC @ 0x10ebdc, size 70 bytes
// Doc: sub_120EBDC [util]: helper routine, sets up state in fmacfwbt
// sub_120EBDC [util]: helper routine, sets up state in fmacfwbt
int __fastcall sub_10EBDC(int a1, int a2)
{
  int *v2; // r5
  _DWORD *v3; // r4
  int result; // r0
  int v5; // r3
  int v6; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_10EC24 = 1;
  }
  v2 = (int *)off_10EC28;
  ++*(_DWORD *)off_10EC28;
  if ( a2 )
  {
    v3 = off_10EC2C;
    while ( !*(_DWORD *)off_10EC2C )
      ;
    result = sub_10EBC4();
    *v3 = 1;
  }
  else
  {
    result = sub_10EBC4();
  }
  if ( *v2 )
  {
    v5 = *v2 - 1;
    v6 = *(_DWORD *)off_10EC24;
    *v2 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
  return result;
}

