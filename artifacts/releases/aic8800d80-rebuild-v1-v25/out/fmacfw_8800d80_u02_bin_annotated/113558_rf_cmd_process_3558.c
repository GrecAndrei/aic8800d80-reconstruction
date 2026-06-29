// fwstruct annotate: 113558_rf_cmd_process_3558.c
// rf_cmd_process_3558 @ 0x113558, size 172 bytes
// Doc: rf_cmd_process_3558 [rf]: Process RF command and set operating mode register
// rf_cmd_process_3558 [rf]: Process RF command and set operating mode register
int __fastcall rf_cmd_process_3558(int eb18, int a2, int a3)
{
  unsigned __int8 *v3; // r5
  char v4; // r3
  _BYTE *v5; // r4
  int v6; // r3
  int v7; // r5
  int v8; // r7
  int v9; // r6
  int v10; // r8
  int v11; // r3
  int v13; // r4

  v3 = (unsigned __int8 *)off_113604;
  if ( a3 )
    v4 = 3;
  else
    v4 = 2;
  *(_BYTE *)off_113604 = v4;
  if ( *v3 == 2 )
  {
    v5 = rf_cmd_queue_next_n154;
    v6 = *(unsigned __int8 *)rf_cmd_queue_next_n154;
    *v3 = 0;
    if ( v6 )
    {
      v7 = rf_stream_start2_360c;
      v8 = rf_cmd_queue_next_n15c;
      v9 = rf_stream_start2_360c - 8;
      do
      {
        while ( 1 )
        {
          v10 = *(_DWORD *)(*(_DWORD *)(rf_bus_mark_n100_d2d0(v7) + 4) + 4);
          --*v5;
          list_push_tail(v9);
          v11 = *(unsigned __int8 *)(v10 + 2) >> 4;
          if ( v11 )
            break;
          ++*(_WORD *)off_113614;
          eb18 = irq_nesting_or_d104(128);
          if ( !*v5 )
            goto LABEL_12;
        }
        if ( v11 == 1 )
        {
          eb18 = log_free_dispatch_2((_DWORD *)v10);
        }
        else
        {
          sub_10DC24(v8);
          eb18 = rf_mem_read_eb18(v10, 32, 1, 0);
        }
      }
      while ( *v5 );
    }
LABEL_12:
    rf_cmd_queue_next_4b4(eb18, a2);
    return 1;
  }
  else
  {
    v13 = eb18;
    sub_10DC24(dword_113618, *v3);
    rf_msg_log_rate(dword_11361C, v13, a2, *v3);
    return 1;
  }
}

