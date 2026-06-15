// v23 annotated: sub_110AB8 @ 0x110ab8
// Original: 110ab8_sub_110AB8.c
// Primary struct: <unclustered>
//
// sub_110AB8 @ 0x110ab8, size 112 bytes
int __fastcall sub_110AB8(int a1, int a2, int a3)
{
  _DWORD *v3; // r5
  _DWORD *v4; // r4
  int v5; // r6
  int v6; // r7
  _DWORD *v7; // r3
  _DWORD *v8; // r12
  int result; // r0
  int *v10; // r3
  int v11; // r3
  _DWORD *v12; // r4

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_110B28 = 1;
  }
  v3 = off_110B2C;
  v4 = off_110B30;
  v5 = *(_DWORD *)off_110B2C;
  v6 = *(_DWORD *)off_110B2C + 1;
  *(_DWORD *)off_110B2C = v6;
  *v4 = 256;
  while ( (*v4 & 0x200) != 0 )
    ;
  if ( *(_DWORD *)off_110B34 )
  {
    v7 = off_110B38;
    v8 = off_110B40;
    *(_DWORD *)(*((_DWORD *)off_110B38 + 769) + 4) = a1;
    *v8 += a2;
  }
  else
  {
    v12 = off_110B40;
    *(_DWORD *)off_110B34 = a1;
    v7 = off_110B38;
    *v12 += a2;
  }
  result = 256;
  *(_DWORD *)off_110B3C = 256;
  v7[769] = a3;
  if ( v6 )
  {
    v10 = (int *)off_110B28;
    *v3 = v5;
    v11 = *v10;
    if ( !v5 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  return result;
}

