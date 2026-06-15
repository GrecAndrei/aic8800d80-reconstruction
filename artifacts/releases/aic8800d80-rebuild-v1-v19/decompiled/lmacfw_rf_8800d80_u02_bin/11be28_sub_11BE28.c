// sub_11BE28 @ 0x11be28, size 136 bytes
int __fastcall sub_11BE28(unsigned __int8 *a1)
{
  int v1; // r4
  int result; // r0
  unsigned __int8 *v3; // r5
  int v4; // r6
  int v5; // r7
  int v6; // r1
  int v7; // r3
  int *v8; // r7
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r3
  int v13; // r2

  v1 = *a1;
  v3 = a1 + 2;
  result = *(_DWORD *)(a1 + 2);
  v4 = dword_11BEB4;
  v5 = *((_DWORD *)off_11BEB0 + 10);
  v6 = *((_DWORD *)v3 + 1);
  v7 = dword_11BEB4 + 28 * v1 + 4;
  *(_DWORD *)v7 = result;
  *(_DWORD *)(v7 + 4) = v6;
  *(_WORD *)(v7 + 8) = *((_WORD *)v3 + 4);
  if ( v5 == v4 + 28 * v1 )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_11BEB8 = 1;
    }
    v8 = (int *)off_11BEBC;
    ++*(_DWORD *)off_11BEBC;
    sub_117A58();
    sub_116EC4(0, v9, v10, v11);
    if ( *v8 )
    {
      v12 = *v8 - 1;
      v13 = *(_DWORD *)off_11BEB8;
      *v8 = v12;
      if ( !v12 )
      {
        if ( v13 )
          __enable_irq();
      }
    }
    sub_102908(v3, 0);
    return sub_11D9F8(*(char *)(v4 + 28 * v1 + 12));
  }
  return result;
}

