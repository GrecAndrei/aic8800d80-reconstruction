// rf_stream_dispatch @ 0x121f38, size 118 bytes
// Doc: rf_stream_dispatch [rf]: Dispatch RF stream events
// rf_stream_dispatch [rf]: Dispatch RF stream events
int  rf_stream_dispatch(int a1, uint8_t *a2, uint8_t *a3)
{
  int v6; // r4
  int v8; // r5
  int v9; // r9
  int v10; // r3
  uint8_t *v11; // r3

  v6 = sub_11F284((int *)a1, a2);
  if ( v6 )
    return v6;
  v8 = *(unsigned __int8 *)(a1 + 25);
  v9 = dword_121FB0 + 696 * (unsigned __int8)*a2;
  *(uint8_t *)(v9 + 669) = 0;
  *(uint16_t *)(v9 + 670) = 0;
  *a3 = sub_1215A0((unsigned __int8)*a2, v8);
  v10 = *(uint32_t *)(v9 + 44);
  if ( v10 )
    sub_1215A0(*(unsigned __int8 *)(v10 + 35), *(unsigned __int8 *)(a1 + 25));
  v11 = (uint8_t *)(dword_121FB4 + 1320 * v8);
  if ( v11[106] )
    return v6;
  v11[116] = *a2;
  v11[117] = *(uint8_t *)(a1 + 29);
  v11[118] = *(uint8_t *)(a1 + 30);
  return 0;
}

