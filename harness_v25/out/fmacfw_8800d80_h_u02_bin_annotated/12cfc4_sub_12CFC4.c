// fwstruct annotate: 12cfc4_sub_12CFC4.c
// sub_12CFC4 @ 0x12cfc4, size 52 bytes
int __fastcall sub_12CFC4(int a1)
{
  _DWORD *v1; // r2
  int *v2; // r5
  int v3; // r1
  int v4; // r4
  int result; // r0
  int *v6; // r3
  int v7; // r3

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_12CFF8 = 1;
  }
  v1 = off_12CFFC;
  v2 = (int *)off_12D000;
  v3 = *(_DWORD *)off_12CFFC;
  v4 = *(_DWORD *)off_12CFFC + 1;
  result = a1 | *(_DWORD *)off_12D000;
  *(_DWORD *)off_12CFFC = v4;
  *v2 = result;
  if ( v4 )
  {
    v6 = (int *)off_12CFF8;
    *v1 = v3;
    v7 = *v6;
    if ( !v3 )
    {
      if ( v7 )
        __enable_irq();
    }
  }
  return result;
}

