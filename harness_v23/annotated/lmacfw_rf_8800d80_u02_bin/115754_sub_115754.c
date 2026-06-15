// v23 annotated: sub_115754 @ 0x115754
// Original: 115754_sub_115754.c
// Primary struct: <unclustered>
//
// sub_115754 @ 0x115754, size 184 bytes
int *__fastcall sub_115754(int a1, int a2, int a3, int a4)
{
  int v5; // r1
  __int16 **v9; // r8
  int v10; // r7
  int v11; // r3
  int v12; // r3
  bool v13; // zf
  __int16 v14; // r2
  _WORD *v15; // r3
  __int16 v16; // r1

  v5 = *(unsigned __int16 *)(a2 + 4);
  *(_WORD *)(a1 + 38) |= 4u;
  if ( !v5 )
    return rf_init_handler(*(_DWORD *)(a1 + 32) + 8, *(_DWORD *)(a1 + 32) + 8, a4, a4);
  v9 = (__int16 **)off_11581C;
  v10 = *(_DWORD *)(a2 + 32);
  if ( **(__int16 **)off_11581C < 0 )
  {
    if ( *(_DWORD *)(a2 + 28) )
    {
      v11 = *(_DWORD *)(v10 + 24);
      if ( v11 )
        goto LABEL_7;
    }
    else
    {
      rf_cmd_send_n264(dword_115818, dword_11580C, 518);
      v11 = *(_DWORD *)(v10 + 24);
      if ( v11 )
        goto LABEL_7;
      if ( **v9 >= 0 )
        goto LABEL_5;
    }
    v12 = *(_DWORD *)(v10 + 20);
    if ( v12 )
      goto LABEL_6;
    rf_cmd_send_n264(dword_115810, dword_11580C, 525);
LABEL_5:
    v12 = *(_DWORD *)(v10 + 20);
LABEL_6:
    v11 = *(_DWORD *)(v12 + 8);
    goto LABEL_7;
  }
  v11 = *(_DWORD *)(v10 + 24);
  if ( !v11 )
    goto LABEL_5;
LABEL_7:
  if ( *(unsigned __int8 *)(a2 + 14) == 255 )
  {
    v14 = *(_BYTE *)(v11 + 22) & 0xF;
    v13 = (*(_BYTE *)(v11 + 22) & 0xF) == 0;
    v15 = (_WORD *)(v11 + 22);
    if ( v13 )
    {
      v16 = *((_WORD *)off_115814 + 70) + 1;
      *((_WORD *)off_115814 + 70) = v16;
    }
    else
    {
      v16 = *((_WORD *)off_115814 + 70);
    }
    *v15 = v14 | (16 * v16);
  }
  sub_11538C(a2);
  return rf_init_handler(*(_DWORD *)(a1 + 32) + 8, *(_DWORD *)(a1 + 32) + 8, a4, a4);
}

