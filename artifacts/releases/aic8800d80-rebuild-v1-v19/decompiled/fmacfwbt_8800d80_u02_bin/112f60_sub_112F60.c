// sub_112F60 @ 0x112f60, size 360 bytes
// Doc: rf_stream_start2_n_18a [rf]: Start secondary RF streaming/transfer sequence
// rf_stream_start2_n_18a [rf]: Start secondary RF streaming/transfer sequence
int __fastcall sub_112F60(unsigned __int8 *a1, unsigned int a2, int a3)
{
  unsigned __int16 *v3; // r7
  unsigned __int8 *v4; // r6
  _BYTE *v5; // r4
  char v6; // r2
  unsigned __int8 *v7; // r4
  int v9; // r8
  int v10; // r6
  _BYTE *v11; // r8
  char v12; // r5
  int v13; // r0
  unsigned int v14; // r3
  char *v15; // r3
  int v17; // r0

  v3 = (unsigned __int16 *)off_1130C8;
  v4 = (unsigned __int8 *)rf_stream_start_0cc;
  v5 = off_1130D0;
  ++*(_WORD *)off_1130C8;
  if ( a3 )
    v6 = 3;
  else
    v6 = 2;
  *v4 = v6;
  *v5 = 0;
  v7 = a1;
  if ( *v4 != 2 )
  {
    log_printf(rf_stream_start2_n_16c, *v3, *v4);
    sub_114024(dword_1130E4, v7, a2, *v4);
    return 1;
  }
  *v4 = 0;
  if ( a2 <= 3 )
  {
    log_printf(dword_1130E8, *v3, a2);
  }
  else
  {
    v9 = a1[2];
    v10 = *a1 | (a1[1] << 8) & 0xF00;
    if ( *(_BYTE *)rf_msg_process_body_n_14e )
      a1 = (unsigned __int8 *)feature_guard_sdio(512, dword_1130F4);
    if ( v9 == 1 )
    {
      if ( a2 == v10 || v10 + 1 == a2 )
      {
        ((void (*)(void))sub_113F60)();
        rf_msg_process_body_3aa4(v7 + 4);
        irq_nesting_or(512);
        return 1;
      }
      log_printf(dword_1130F8, *v3, v10, a2);
    }
    else if ( v9 == 17 )
    {
      v11 = off_113104;
      if ( *((unsigned __int8 *)off_113104 + 2433) >= (unsigned int)*((unsigned __int8 *)off_113104 + 2434) )
      {
        log_printf(dword_113100);
      }
      else
      {
        if ( v10 + 4 == a2 || a2 == v10 + 5 )
        {
          sub_113F60(a1);
          v12 = v11[2433];
          v13 = dword_1130DC;
          v14 = (unsigned __int8)v11[2432]
              + 1
              - 40
              * ((unsigned int)(((unsigned int)dword_1130D8
                               * (unsigned __int64)((unsigned int)(unsigned __int8)v11[2432] + 1)) >> 32) >> 5);
          v11[2432] = v14;
          v15 = &v11[20 * v14];
          *((_DWORD *)v15 + 409) = v7 + 4;
          *((_DWORD *)v15 + 412) = v10;
          v11[2433] = v12 + 1;
          list_push_tail(v13);
          irq_nesting_or(0x400000);
          return 1;
        }
        log_printf(rf_msg_handler_n19c, *v3, v10, a2);
      }
    }
    else
    {
      log_printf(rf_stream_start2_n_15c, *v3, v9, v10, a2);
    }
  }
  v17 = log_free_dispatch_2(&v7[-*(_DWORD *)rf_mem_scan_bytes]);
  sub_113F60(v17);
  return 1;
}

