// sub_136864 @ 0x136864, size 280 bytes
_DWORD *sub_136864()
{
  int v0; // r11
  int v1; // r4
  int v2; // r9
  int v3; // r6
  int v4; // r5
  int v5; // r8
  int v6; // r10
  _BYTE *v7; // r7
  int v8; // r9
  int v9; // r0
  int v10; // r0
  _BYTE *v12; // r0

  v0 = dword_136988;
  v1 = *(_DWORD *)off_13697C;
  v2 = *(unsigned __int8 *)(*(_DWORD *)off_13697C + 51);
  v3 = sub_12C92C(24, 0, 7, 8u);
  v4 = sub_12C92C(22, 0, 7, 8u);
  v5 = sub_12C92C(20, 0, 7, 4u);
  v6 = v0 + 1320 * v2;
  v7 = (_BYTE *)sub_12C92C(5143, 5, 7, 2u);
  sub_136668();
  if ( *(_BYTE *)(v6 + 1224) )
  {
    *(_DWORD *)off_136980 &= ~4u;
    *(_DWORD *)(v6 + 4) |= 0x20u;
  }
  else
  {
    v12 = (_BYTE *)sub_12C92C(5145, 5, 7, 2u);
    *v12 = 1;
    v12[1] = *(_BYTE *)(v6 + 107);
    list_push_tail((int)off_13697C + 4, (_DWORD *)v12 - 3);
  }
  v8 = v0 + 1320 * v2;
  v9 = *(_DWORD *)(v8 + 100);
  *(_WORD *)(v3 + 4) = *(_WORD *)(v8 + 104);
  *(_DWORD *)v3 = v9;
  *(_BYTE *)(v3 + 6) = *(_BYTE *)(v1 + 51);
  list_push_tail(dword_136984, (_DWORD *)(v3 - 12));
  *(_BYTE *)(v4 + 5) = *(_BYTE *)(v1 + 16);
  *(_DWORD *)v4 = task_entry_n794((unsigned __int8 *)v1, 1);
  *(_BYTE *)(v4 + 4) = *(_BYTE *)(v1 + 51);
  list_push_tail(dword_136984, (_DWORD *)(v4 - 12));
  *(_WORD *)v5 = *(_WORD *)(v1 + 40);
  *(_BYTE *)(v5 + 2) = *(_BYTE *)(v1 + 51);
  list_push_tail(dword_136984, (_DWORD *)(v5 - 12));
  *v7 = 1;
  v10 = dword_136984;
  v7[1] = *(_BYTE *)(v1 + 51);
  list_push_tail(v10, (_DWORD *)v7 - 3);
  sub_136820();
  return sub_12CD34(7u, 1);
}

