// v23 annotated: rf_stream_dispatch @ 0x121f38
// Original: 121f38_rf_stream_dispatch.c
// Primary struct: <unclustered>
//
// rf_stream_dispatch @ 0x121f38, size 118 bytes
// Doc: rf_stream_dispatch [rf]: Dispatch RF stream events
// rf_stream_dispatch [rf]: Dispatch RF stream events
int __fastcall rf_stream_dispatch(int a1, _BYTE *a2, _BYTE *a3)
{
  int v6; // r4
  int v8; // r5
  int v9; // r9
  int v10; // r3
  _BYTE *v11; // r3

  v6 = sub_11F284((int *)a1, a2);
  if ( v6 )
    return v6;
  v8 = *(unsigned __int8 *)(a1 + 25);
  v9 = dword_121FB0 + 696 * (unsigned __int8)*a2;
  *(_BYTE *)(v9 + 669) = 0;
  *(_WORD *)(v9 + 670) = 0;
  *a3 = sub_1215A0((unsigned __int8)*a2, v8);
  v10 = *(_DWORD *)(v9 + 44);
  if ( v10 )
    sub_1215A0(*(unsigned __int8 *)(v10 + 35), *(unsigned __int8 *)(a1 + 25));
  v11 = (_BYTE *)(dword_121FB4 + 1320 * v8);
  if ( v11[106] )
    return v6;
  v11[116] = *a2;
  v11[117] = *(_BYTE *)(a1 + 29);
  v11[118] = *(_BYTE *)(a1 + 30);
  return 0;
}

