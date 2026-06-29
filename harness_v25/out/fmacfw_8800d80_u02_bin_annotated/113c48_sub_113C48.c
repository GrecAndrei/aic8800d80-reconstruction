// fwstruct annotate: 113c48_sub_113C48.c
// sub_113C48 @ 0x113c48, size 318 bytes
// Doc: rf_msg_process_body_n59 [rf]: Processes RF message body, increments counter and clears state fields
// rf_msg_process_body_n59 [rf]: Processes RF message body, increments counter and clears state fields
int __fastcall sub_113C48(int a1)
{
  unsigned int v1; // r3
  int v2; // r7
  int v4; // r8
  unsigned int v5; // r6
  int v6; // r4
  int v7; // r1
  __int16 v8; // r3
  __int16 v9; // r2
  int v10; // r3
  unsigned int v11; // r3
  unsigned int v12; // r2

  v1 = *(unsigned __int8 *)(a1 + 25);
  v2 = *(unsigned __int8 *)(a1 + 24);
  if ( v1 <= 0x1F && !*(_BYTE *)(rf_msg_process_body_n140 + 696 * v1 + 37) )
  {
    msg_parse(rf_msg_process_body_n160, 696, rf_msg_process_body_n140);
    return log_free_dispatch_2((_DWORD *)(a1 - *(_DWORD *)off_113D94 - 4));
  }
  v4 = dword_113DAC;
  if ( (*(_WORD *)(a1 + 26) & 8) == 0 )
  {
    if ( *(_BYTE *)(dword_113DAC + 1320 * v2 + 108) )
    {
      v5 = *(unsigned __int8 *)(a1 + 22);
      if ( **(__int16 **)rf_msg_process_body_n144 < 0 && v5 > 4 )
        sub_12F46C(rf_msg_process_body_n15c, rf_msg_process_body_n158, 926);
      v6 = sub_116008();
      if ( v6 )
        goto rf_msg_process_body_3c9c;
rf_msg_process_body_nf4:
      sub_10DC24(rf_msg_process_body_3d9c, *(unsigned __int8 *)(rf_msg_process_body_n148 + v5));
      while ( 1 )
        ;
    }
    return log_free_dispatch_2((_DWORD *)(a1 - *(_DWORD *)off_113D94 - 4));
  }
  v5 = 3;
  v6 = sub_116008();
  if ( !v6 )
    goto rf_msg_process_body_nf4;
rf_msg_process_body_3c9c:
  v7 = *(_DWORD *)(v6 + 76);
  v8 = *(_WORD *)(v6 + 30) & 0xFFFE;
  ++*(_BYTE *)(rf_msg_process_body_n148 + v5);
  *(_WORD *)(v6 + 30) = v8;
  *(_DWORD *)(v6 + 68) = 0;
  *(_DWORD *)(v7 + 4) = 0;
  *(_DWORD *)(v7 + 72) = 0;
  *(_DWORD *)(v6 + 44) = 0;
  sub_143770(v6 + 4, a1, 28);
  v9 = *(_WORD *)(v6 + 30);
  v10 = *(_DWORD *)off_113D94;
  *(_WORD *)(v6 + 6) = 0;
  *(_DWORD *)(v6 + 72) = a1 - v10 - 4;
  *(_BYTE *)(v6 + 66) = 0;
  *(_DWORD *)(v6 + 36) = 0;
  *(_DWORD *)(v6 + 84) = 0;
  *(_WORD *)(v6 + 82) = 0;
  *(_WORD *)(v6 + 30) = v9 & 0xFFFD;
  if ( (v9 & 8) != 0 )
    return list_push_tail(v4 + 1320 * v2 + 1312);
  v11 = *(unsigned __int8 *)(v6 + 29);
  if ( v11 <= 0x1F )
  {
    v12 = *(unsigned __int8 *)(v6 + 27);
    if ( v12 <= 8 )
      *(_DWORD *)(dword_113D98 + 4 * (9 * v11 + v12 + 2062)) += *(unsigned __int16 *)(v6 + 4);
  }
  return list_push_tail(v4 + 8 * (v5 + 165 * v2 + 154));
}

