// v23 annotated: sub_12D374 @ 0x12d374
// Original: 12d374_sub_12D374.c
// Primary struct: <unclustered>
//
// sub_12D374 @ 0x12d374, size 54 bytes
int __fastcall sub_12D374(int a1)
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
    *(_DWORD *)off_12D3AC = 1;
  }
  v1 = off_12D3B0;
  v2 = (int *)off_12D3B4;
  v3 = *(_DWORD *)off_12D3B0;
  v4 = *(_DWORD *)off_12D3B0 + 1;
  result = *(_DWORD *)off_12D3B4 & ~a1;
  *(_DWORD *)off_12D3B0 = v4;
  *v2 = result;
  if ( v4 )
  {
    v6 = (int *)off_12D3AC;
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

