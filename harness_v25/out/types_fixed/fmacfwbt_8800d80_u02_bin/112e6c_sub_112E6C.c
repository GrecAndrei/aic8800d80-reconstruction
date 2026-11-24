// sub_112E6C @ 0x112e6c, size 100 bytes
// Doc: rf_stream_start2_n_3da [rf]: Start RF streaming after pre-check, gate by mode byte
// rf_stream_start2_n_3da [rf]: Start RF streaming after pre-check, gate by mode byte
int __fastcall sub_112E6C(int a1, unsigned __int16 *a2)
{
  int v4; // r2
  int v5; // r3
  int v6; // r2

  sub_112DCC();
  if ( *(_BYTE *)rf_stream_start2_n_37b != 4 )
    return 1;
  v4 = a1 - 1;
  if ( (unsigned __int8)(a1 - 1) > 5u )
    return 2;
  if ( (*((_DWORD *)&REG_4020_0900 + 8 * a1) & 0x8000) == 0 )
    return 5;
  v5 = 32 * v4 + 0x40000000;
  v6 = rf_stream_start2_alt + 16 * v4;
  *(_DWORD *)(v6 + 4) = *a2;
  *(_BYTE *)(v6 + 11) = 1;
  *(_DWORD *)(v5 + 2099508) = a2;
  *((_DWORD *)&REG_4020_0900 + 8 * a1) |= 0x84000000;
  return 0;
}

