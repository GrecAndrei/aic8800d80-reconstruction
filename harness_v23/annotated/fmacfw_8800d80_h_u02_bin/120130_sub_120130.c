// v23 annotated: sub_120130 @ 0x120130
// Original: 120130_sub_120130.c
// Primary struct: <unclustered>
//
// sub_120130 @ 0x120130, size 144 bytes
int __fastcall sub_120130(int result, unsigned int a2)
{
  _DWORD *v2; // r5
  _BYTE *v3; // r3
  int v4; // r6
  unsigned int v5; // r2
  int v6; // r7
  unsigned int v7; // r4
  int *i; // r3
  unsigned int v9; // r2
  int *v10; // r3
  int v11; // r3

  *(_WORD *)(result + 222) = a2;
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_1201C0 = 1;
  }
  v2 = off_1201C4;
  v3 = off_1201C8;
  v4 = *(_DWORD *)off_1201C4;
  v5 = *((unsigned __int8 *)off_1201C8 + 18);
  v6 = *(_DWORD *)off_1201C4 + 1;
  *(_DWORD *)off_1201C4 = v6;
  if ( v5 <= 1 )
  {
    v3[20] = *(_BYTE *)(result + 107);
    v7 = a2;
    *(_WORD *)(result + 224) = 257;
  }
  else
  {
    v7 = *(unsigned __int16 *)(dword_1201CC + 1320 * (unsigned __int8)v3[20] + 222);
    if ( a2 < v7 )
    {
      v3[20] = *(_BYTE *)(result + 107);
      v7 = a2;
    }
    for ( i = *((int **)v3 + 2); i; i = (int *)*i )
    {
      v9 = *((unsigned __int16 *)i + 111);
      *((_BYTE *)i + 225) = 1;
      *((_BYTE *)i + 224) = v9 / v7;
    }
  }
  *(_DWORD *)off_1201D0 = (HIWORD(*(_DWORD *)off_1201D0) << 16) | v7;
  if ( v6 )
  {
    v10 = (int *)off_1201C0;
    *v2 = v4;
    v11 = *v10;
    if ( !v4 )
    {
      if ( v11 )
        __enable_irq();
    }
  }
  return result;
}

