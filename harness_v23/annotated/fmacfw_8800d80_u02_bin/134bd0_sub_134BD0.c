// v23 annotated: sub_134BD0 @ 0x134bd0
// Original: 134bd0_sub_134BD0.c
// Primary struct: <unclustered>
//
// sub_134BD0 @ 0x134bd0, size 428 bytes
_DWORD *sub_134BD0()
{
  int v0; // r10
  int v1; // r5
  _BYTE *v2; // r9
  int v3; // r7
  int v4; // r4
  int v5; // r6
  int v6; // r11
  _BYTE *v7; // r8
  int v8; // r0
  void *v9; // r3
  int v10; // r0
  int v11; // r3
  int v12; // r0
  int v13; // r6
  int v14; // r6
  int v15; // r7
  int *v16; // r10
  int v17; // r0
  int v18; // t1
  int v19; // r0
  int *v21; // r6
  int v22; // [sp+0h] [bp-Ch]

  v0 = dword_134D88;
  v1 = *((_DWORD *)off_134D7C + 4);
  v22 = *(unsigned __int8 *)(v1 + 61);
  v2 = (_BYTE *)sub_12C92C(5145, 5, 6, 2u);
  v3 = sub_12C92C(24, 0, 6, 8u);
  v4 = 1320 * v22;
  v5 = sub_12C92C(22, 0, 6, 8u);
  v6 = sub_12C92C(20, 0, 6, 4u);
  v7 = (_BYTE *)sub_12C92C(5143, 5, 6, 2u);
  sub_1343EC();
  *v2 = 1;
  v2[1] = *(_BYTE *)(v1 + 61);
  list_push_tail((int)off_134D7C + 24, (_DWORD *)v2 - 3);
  v8 = *(_DWORD *)(v0 + 1320 * v22 + 368);
  *(_WORD *)(v3 + 4) = *(_WORD *)(v0 + 1320 * v22 + 372);
  v9 = off_134D7C;
  *(_DWORD *)v3 = v8;
  *(_BYTE *)(v3 + 6) = *(_BYTE *)(v1 + 61);
  list_push_tail((int)v9 + 24, (_DWORD *)(v3 - 12));
  *(_BYTE *)(v5 + 5) = *(_BYTE *)(v0 + 1320 * v22 + 412);
  v10 = task_entry_n794((unsigned __int8 *)(1320 * v22 + 424 + v0), 1);
  v11 = *(unsigned __int8 *)(v5 + 5);
  *(_DWORD *)v5 = v10;
  *(_BYTE *)(v5 + 4) = *(_BYTE *)(v1 + 61);
  if ( !v11 )
  {
    if ( (v10 & 1) != 0 )
    {
      *((_DWORD *)off_134D80 + 5) = 1024;
    }
    else if ( (v10 & 0x10) != 0 )
    {
      *((_DWORD *)off_134D80 + 5) = 4;
    }
  }
  list_push_tail(dword_134D84, (_DWORD *)(v5 - 12));
  v12 = dword_134D84;
  v13 = v0 + 1320 * v22;
  *(_WORD *)v6 = *(_WORD *)(v13 + 422);
  *(_BYTE *)(v6 + 2) = *(_BYTE *)(v1 + 61);
  list_push_tail(v12, (_DWORD *)(v6 - 12));
  if ( (*(_DWORD *)(v13 + 472) & 8) != 0 )
  {
    v21 = (int *)sub_12C92C(113, 0, 6, 4u);
    *v21 = sub_132884(v0 + v4 + 248);
    list_push_tail(dword_134D84, v21 - 3);
  }
  v14 = 0;
  v15 = dword_134D84;
  v16 = (int *)(v0 + v4 + 440);
  do
  {
    v17 = sub_12C92C(26, 0, 6, 8u);
    v18 = *v16++;
    *(_DWORD *)v17 = v18;
    *(_BYTE *)(v17 + 5) = v14;
    *(_BYTE *)(v17 + 6) = *(_BYTE *)(v1 + 61);
    *(_BYTE *)(v17 + 4) = 0;
    ++v14;
    list_push_tail(v15, (_DWORD *)(v17 - 12));
  }
  while ( v14 != 4 );
  *v7 = 1;
  v19 = dword_134D84;
  v7[1] = *(_BYTE *)(v1 + 61);
  list_push_tail(v19, (_DWORD *)v7 - 3);
  sub_1347BC();
  return sub_12CD34(6u, 4);
}

