// v23 annotated: sub_12D32C @ 0x12d32c
// Original: 12d32c_sub_12D32C.c
// Primary struct: <unclustered>
//
// sub_12D32C @ 0x12d32c, size 52 bytes
int __fastcall sub_12D32C(int a1)
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
    *(_DWORD *)off_12D360 = 1;
  }
  v1 = off_12D364;
  v2 = (int *)off_12D368;
  v3 = *(_DWORD *)off_12D364;
  v4 = *(_DWORD *)off_12D364 + 1;
  result = a1 | *(_DWORD *)off_12D368;
  *(_DWORD *)off_12D364 = v4;
  *v2 = result;
  if ( v4 )
  {
    v6 = (int *)off_12D360;
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

