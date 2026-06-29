// fwstruct annotate: 11749c_category_dispatch_5way.c
// category_dispatch_5way @ 0x11749c, size 124 bytes
// Doc: category_dispatch_5way [util]: Dispatch routine selecting one of 5 categories on input code
// category_dispatch_5way [util]: Dispatch routine selecting one of 5 categories on input code
int __fastcall category_dispatch_5way(int a1)
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
    v2 = (_DWORD *)dword_117530;
  else
    v2 = (_DWORD *)(dword_117518 + 84 * a1);
  sub_118940(a1, dword_11751C + 8 * a1, 0);
  sub_118940(a1, v2 + 3, 0);
  *v2 = 0;
  v2[5] = 0;
  sub_116050(a1);
  v3 = *(_DWORD *)off_117520;
  v4 = 1 << a1;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_117524 = 1;
  }
  v5 = off_117528;
  v6 = (int *)off_117520;
  v7 = *(_DWORD *)off_117528;
  result = *(_DWORD *)off_117528 + 1;
  *(_DWORD *)off_117528 = result;
  *v6 = v3 & ~v4;
  if ( result )
  {
    v9 = (int *)off_117524;
    *v5 = v7;
    v10 = *v9;
    if ( !v7 )
    {
      if ( v10 )
        __enable_irq();
    }
  }
  *(_DWORD *)off_11752C = v4;
  return result;
}

