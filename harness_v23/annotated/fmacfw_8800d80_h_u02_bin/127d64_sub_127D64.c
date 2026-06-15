// v23 annotated: sub_127D64 @ 0x127d64
// Original: 127d64_sub_127D64.c
// Primary struct: <unclustered>
//
// sub_127D64 @ 0x127d64, size 136 bytes
int __fastcall sub_127D64(unsigned __int8 *a1)
{
  int v1; // r4
  int result; // r0
  unsigned __int8 *v3; // r5
  int v4; // r6
  int v5; // r7
  int v6; // r1
  int v7; // r3
  int *v8; // r7
  int v9; // r3
  int v10; // r2

  v1 = *a1;
  v3 = a1 + 2;
  result = *(_DWORD *)(a1 + 2);
  v4 = dword_127DF0;
  v5 = *((_DWORD *)off_127DEC + 10);
  v6 = *((_DWORD *)v3 + 1);
  v7 = dword_127DF0 + 28 * v1 + 4;
  *(_DWORD *)v7 = result;
  *(_DWORD *)(v7 + 4) = v6;
  *(_WORD *)(v7 + 8) = *((_WORD *)v3 + 4);
  if ( v5 == v4 + 28 * v1 )
  {
    if ( (__get_CPSR() & 1) == 0 )
    {
      __disable_irq();
      *(_DWORD *)off_127DF4 = 1;
    }
    v8 = (int *)off_127DF8;
    ++*(_DWORD *)off_127DF8;
    sub_11EA84();
    sub_11D930(0);
    if ( *v8 )
    {
      v9 = *v8 - 1;
      v10 = *(_DWORD *)off_127DF4;
      *v8 = v9;
      if ( !v9 )
      {
        if ( v10 )
          __enable_irq();
      }
    }
    sub_102970((unsigned __int16 *)v3, 0);
    return sub_12C344(*(char *)(v4 + 28 * v1 + 12));
  }
  return result;
}

