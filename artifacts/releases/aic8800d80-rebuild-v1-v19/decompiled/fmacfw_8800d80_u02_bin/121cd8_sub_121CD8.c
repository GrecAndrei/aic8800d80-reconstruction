// sub_121CD8 @ 0x121cd8, size 156 bytes
// Doc: sub_1221CD8 [unknown]: Generic dispatcher wrapper saving r4-r8,sb,lr and calling sub-function
// sub_1221CD8 [unknown]: Generic dispatcher wrapper saving r4-r8,sb,lr and calling sub-function
int __fastcall sub_121CD8(int a1, _BYTE *a2, _BYTE *a3)
{
  int v6; // r4
  int v8; // r5
  int v9; // r9
  int inited; // r0
  int v11; // r3
  _BYTE *v12; // r3
  int v13; // r1

  v6 = sub_11EF08((int *)a1, a2);
  if ( v6 )
    return v6;
  v8 = *(unsigned __int8 *)(a1 + 25);
  v9 = dword_121D74 + 696 * (unsigned __int8)*a2;
  *(_BYTE *)(v9 + 669) = 0;
  *(_WORD *)(v9 + 670) = 0;
  inited = rf_chan_table_init_n_74((unsigned __int8)*a2, v8);
  *a3 = inited;
  v11 = *(_DWORD *)(v9 + 44);
  if ( v11 )
    inited = rf_chan_table_init_n_74(*(unsigned __int8 *)(v11 + 35), *(unsigned __int8 *)(a1 + 25));
  v12 = (_BYTE *)(dword_121D78 + 1320 * v8);
  if ( v12[106] )
  {
    if ( (unsigned __int8)*a2 <= 0x1Fu && v12[106] == 2 && !v12[1224] )
    {
      v13 = *(unsigned __int8 *)off_121D80;
      ++*(_BYTE *)off_121D7C;
      if ( v13 == 1 )
        cmd_dispatch_0xc6(inited);
    }
    return v6;
  }
  v12[116] = *a2;
  v12[117] = *(_BYTE *)(a1 + 29);
  v12[118] = *(_BYTE *)(a1 + 30);
  return 0;
}

