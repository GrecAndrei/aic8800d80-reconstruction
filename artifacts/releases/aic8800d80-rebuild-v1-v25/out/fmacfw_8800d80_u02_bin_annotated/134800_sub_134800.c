// fwstruct annotate: 134800_sub_134800.c
// sub_134800 @ 0x134800, size 256 bytes
int __fastcall sub_134800(int a1)
{
  int v1; // lr
  int v3; // r7
  _BYTE *v4; // r6
  int v5; // r0
  unsigned int *v6; // r3
  _BYTE *v7; // r5
  int v8; // r0
  _BYTE *v9; // r0
  _BYTE *v10; // r0
  int v12; // r0

  v3 = v1;
  v4 = (_BYTE *)sub_12C92C(5145, 5, 6, 2u);
  v5 = sub_12C92C(5143, 5, 6, 2u);
  v6 = (unsigned int *)off_134900;
  v7 = (_BYTE *)v5;
  if ( (*(_DWORD *)off_134900 & 0x4000000) != 0 )
  {
    *(_DWORD *)off_134900 &= ~0x4000000u;
    *v6 = *v6 & 0xFF3FFFFF | 0x800000;
  }
  v8 = dword_13490C;
  *((_BYTE *)off_134908 + 73) = *(_BYTE *)off_134904;
  msg_parse(v8, v3);
  sub_1343EC();
  fmac_event_init_n_3b2(a1);
  sub_13BE14(*(unsigned __int8 *)(a1 + 116));
  *v4 = 0;
  v4[1] = *(_BYTE *)(a1 + 107);
  list_push_tail(dword_134910, (_DWORD *)v4 - 3);
  if ( *(_BYTE *)(a1 + 108) )
  {
    v12 = sub_12C92C(30, 0, 6, 4u);
    *(_BYTE *)(v12 + 2) = 0;
    *(_BYTE *)(v12 + 3) = *(_BYTE *)(a1 + 107);
    list_push_tail(dword_134910, (_DWORD *)(v12 - 12));
  }
  if ( *(unsigned __int8 *)(a1 + 116) != 255 )
  {
    v9 = (_BYTE *)sub_12C92C(12, 0, 6, 1u);
    *v9 = *(_BYTE *)(a1 + 116);
    list_push_tail(dword_134910, (_DWORD *)v9 - 3);
  }
  if ( *(_DWORD *)(a1 + 72) )
  {
    v10 = (_BYTE *)sub_12C92C(57, 0, 6, 1u);
    *v10 = *(_BYTE *)(a1 + 107);
    list_push_tail(dword_134910, (_DWORD *)v10 - 3);
  }
  *v7 = 0;
  v7[1] = *(_BYTE *)(a1 + 107);
  list_push_tail(dword_134910, (_DWORD *)v7 - 3);
  return sub_1347BC();
}

