// sub_11735C @ 0x11735c, size 124 bytes
int __fastcall sub_11735C(int a1)
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
    v2 = (_DWORD *)dword_1173F0;
  else
    v2 = (_DWORD *)(dword_1173D8 + 84 * a1);
  sub_118800(a1, dword_1173DC + 8 * a1, 0);
  sub_118800(a1, v2 + 3, 0);
  *v2 = 0;
  v2[5] = 0;
  sub_115F10(a1);
  v3 = *(_DWORD *)off_1173E0;
  v4 = 1 << a1;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_1173E4 = 1;
  }
  v5 = off_1173E8;
  v6 = (int *)off_1173E0;
  v7 = *(_DWORD *)off_1173E8;
  result = *(_DWORD *)off_1173E8 + 1;
  *(_DWORD *)off_1173E8 = result;
  *v6 = v3 & ~v4;
  if ( result )
  {
    v9 = (int *)off_1173E4;
    *v5 = v7;
    v10 = *v9;
    if ( !v7 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  *(_DWORD *)off_1173EC = v4;
  return result;
}

