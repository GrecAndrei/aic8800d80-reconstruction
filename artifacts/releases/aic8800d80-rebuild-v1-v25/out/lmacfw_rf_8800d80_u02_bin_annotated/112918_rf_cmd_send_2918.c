// fwstruct annotate: 112918_rf_cmd_send_2918.c
// rf_cmd_send_2918 @ 0x112918, size 100 bytes
// Doc: rf_cmd_send_n56 [rf]: Send RF command variant n56, returns small status codes
// rf_cmd_send_n56 [rf]: Send RF command variant n56, returns small status codes
int __fastcall rf_cmd_send_2918(int a1, unsigned __int16 *a2)
{
  int v4; // r2
  int v5; // r3
  int v6; // r2

  rf_cmd_wait();
  if ( *(_BYTE *)rf_cmd_send_n64 != 4 )
    return 1;
  v4 = a1 - 1;
  if ( (unsigned __int8)(a1 - 1) > 5u )
    return 2;
  if ( (*((_DWORD *)&REG_4020_0900 + 8 * a1) & 0x8000) == 0 )
    return 5;
  v5 = 32 * v4 + 0x40000000;
  v6 = dword_112980 + 16 * v4;
  *(_DWORD *)(v6 + 4) = *a2;
  *(_BYTE *)(v6 + 11) = 1;
  *(_DWORD *)(v5 + 2099508) = a2;
  *((_DWORD *)&REG_4020_0900 + 8 * a1) |= 0x84000000;
  return 0;
}

