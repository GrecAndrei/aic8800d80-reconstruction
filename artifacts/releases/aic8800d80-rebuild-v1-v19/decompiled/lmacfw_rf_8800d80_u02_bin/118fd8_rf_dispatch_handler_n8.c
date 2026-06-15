// rf_dispatch_handler_n8 @ 0x118fd8, size 116 bytes
// Doc: rf_dispatch_handler_n8 [rf]: RF handler dispatching to internal worker
// rf_dispatch_handler_n8 [rf]: RF handler dispatching to internal worker
int __fastcall rf_dispatch_handler_n8(int a1, _BYTE *a2, _BYTE *a3)
{
  int v6; // r4
  int v8; // r8
  int v9; // r9
  int v10; // r3
  _BYTE *v11; // r8

  v6 = tx_buffer_acquire_or_alloc((int *)a1, a2);
  if ( v6 )
    return v6;
  v8 = *(unsigned __int8 *)(a1 + 25);
  v9 = dword_11904C + 152 * (unsigned __int8)*a2;
  *(_BYTE *)(v9 + 125) = 0;
  *(_WORD *)(v9 + 126) = 0;
  *a3 = rf_table_lookup_n360((unsigned __int8)*a2, v8);
  v10 = *(_DWORD *)(v9 + 44);
  if ( v10 )
    rf_table_lookup_n360(*(unsigned __int8 *)(v10 + 33), *(unsigned __int8 *)(a1 + 25));
  v11 = (_BYTE *)(dword_119050 + 224 * v8);
  if ( v11[94] )
    return v6;
  v11[102] = *a2;
  v11[103] = *(_BYTE *)(a1 + 29);
  v11[104] = *(_BYTE *)(a1 + 30);
  return 0;
}

