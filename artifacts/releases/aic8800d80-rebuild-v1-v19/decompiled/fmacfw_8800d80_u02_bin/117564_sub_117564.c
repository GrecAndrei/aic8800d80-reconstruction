// sub_117564 @ 0x117564, size 254 bytes
// Doc: sub_1217564 [mac]: Dispatch routine with 5-way case switch
// sub_1217564 [mac]: Dispatch routine with 5-way case switch
int __fastcall sub_117564(int a1, int a2)
{
  char *v4; // r7
  int v5; // r0
  __int16 v6; // r1
  _DWORD *v7; // r3
  int v8; // r3
  _BYTE *v9; // r2
  int *v10; // r6
  int result; // r0
  int v12; // r3
  int v13; // r3
  int v14; // r2

  if ( a2 == 5 )
    v4 = (char *)dword_117688;
  else
    v4 = (char *)off_117664 + 84 * a2;
  v5 = dword_117668;
  v6 = *(_WORD *)(a1 + 30);
  v7 = *(_DWORD **)(a1 + 76);
  v7[9] = *(unsigned __int8 *)(a1 + 51) + *(unsigned __int8 *)(a1 + 53) + *(unsigned __int16 *)(a1 + 4) + 4;
  v7[8] = 0;
  v7[13] = 0;
  v7[14] = 0;
  v7[4] = 0;
  v7[5] = 0;
  v7[6] = 0;
  v7[7] = 0;
  v7[3] = v5;
  v7[15] = 0;
  v7[12] = 0;
  v7[17] = 0;
  v7[10] = 0;
  if ( (v6 & 1) == 0 )
    v7[18] = 0;
  v8 = *((_DWORD *)off_11766C + 8);
  if ( v8 )
  {
    v9 = *(_BYTE **)off_117670;
    *(_DWORD *)off_117674 = 0x80000000;
    if ( *v9 == 3 && v8 == dword_117680 + 1320 * *(unsigned __int8 *)(a1 + 28) )
      *(_DWORD *)(v8 + 120) = *((_DWORD *)off_117684 + 4);
  }
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_117678 = 1;
  }
  v10 = (int *)off_11767C;
  ++*(_DWORD *)off_11767C;
  sub_11A090(a1, a2);
  list_push_tail(v4 + 12);
  sub_12AE74(*(unsigned __int8 *)(a1 + 28), *(unsigned __int8 *)(a1 + 29), 0);
  if ( (*(_WORD *)(a1 + 30) & 1) == 0 )
    ++*((_DWORD *)off_117664 + 126);
  sub_1292D4(a1);
  result = sub_116C4C(a1, a2, 0);
  v12 = *v10;
  *(_WORD *)(a1 + 82) |= 1u;
  if ( v12 )
  {
    v13 = v12 - 1;
    v14 = *(_DWORD *)off_117678;
    *v10 = v13;
    if ( !v13 )
    {
      if ( v14 )
        __enable_irq();
    }
  }
  return result;
}

