// fwstruct annotate: 113010_sub_113010.c
// sub_113010 @ 0x113010, size 100 bytes
// Doc: rf_stream_start_n_325 [rf]: Start RF data stream at MMIO base
// rf_stream_start_n_325 [rf]: Start RF data stream at MMIO base
int __fastcall sub_113010(int a1, unsigned __int16 *a2)
{
  int v4; // r2
  int v5; // r3
  int v6; // r2

  rf_cmd_wait_2f70();
  if ( *(_BYTE *)rf_cmd_process_n_4e4 != 4 )
    return 1;
  v4 = a1 - 1;
  if ( (unsigned __int8)(a1 - 1) > 5u )
    return 2;
  if ( (*((_DWORD *)&REG_4020_0900 + 8 * a1) & 0x8000) == 0 )
    return 5;
  v5 = 32 * v4 + 0x40000000;
  v6 = rf_stream_start2_n_378 + 16 * v4;
  *(_DWORD *)(v6 + 4) = *a2;
  *(_BYTE *)(v6 + 11) = 1;
  *(_DWORD *)(v5 + 2099508) = a2;
  *((_DWORD *)&REG_4020_0900 + 8 * a1) |= 0x84000000;
  return 0;
}

