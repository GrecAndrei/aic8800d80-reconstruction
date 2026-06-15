// sub_1178DC @ 0x1178dc, size 124 bytes
// Doc: sub_12178DE [util]: Helper: save args/lr, set r4=r0; dispatcher stub
// sub_12178DE [util]: Helper: save args/lr, set r4=r0; dispatcher stub
int __fastcall sub_1178DC(int a1)
{
  _DWORD *v2; // r5
  int v3; // r3
  int v4; // r4
  _DWORD *v5; // r2
  int *v6; // r5
  int v7; // r1
  int result; // r0
  int *v9; // r3
  int v10; // r3

  if ( a1 == 5 )
    v2 = (_DWORD *)dword_117970;
  else
    v2 = (_DWORD *)(dword_117958 + 84 * a1);
  sub_118D80(a1, dword_11795C + 8 * a1, 0);
  sub_118D80(a1, v2 + 3, 0);
  *v2 = 0;
  v2[5] = 0;
  sub_116490(a1);
  v3 = *(_DWORD *)off_117960;
  v4 = 1 << a1;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_117964 = 1;
  }
  v5 = off_117968;
  v6 = (int *)off_117960;
  v7 = *(_DWORD *)off_117968;
  result = *(_DWORD *)off_117968 + 1;
  *(_DWORD *)off_117968 = result;
  *v6 = v3 & ~v4;
  if ( result )
  {
    v9 = (int *)off_117964;
    *v5 = v7;
    v10 = *v9;
    if ( !v7 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  *(_DWORD *)off_11796C = v4;
  return result;
}

