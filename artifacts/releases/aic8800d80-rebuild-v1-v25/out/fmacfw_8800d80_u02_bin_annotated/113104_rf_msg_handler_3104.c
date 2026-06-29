// fwstruct annotate: 113104_rf_msg_handler_3104.c
// rf_msg_handler_3104 @ 0x113104, size 360 bytes
// Doc: rf_cmd_queue_next_n_260 [rf]: Process next RF command from queue
// rf_cmd_queue_next_n_260 [rf]: Process next RF command from queue
int __fastcall rf_msg_handler_3104(unsigned __int8 *a1, unsigned int a2, int a3)
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

  v3 = (unsigned __int16 *)off_11326C;
  v4 = (unsigned __int8 *)rf_cmd_send_n260;
  v5 = ipc_doorbell_handler_n17b;
  ++*(_WORD *)off_11326C;
  if ( a3 )
    v6 = 3;
  else
    v6 = 2;
  *v4 = v6;
  *v5 = 0;
  v7 = a1;
  if ( *v4 != 2 )
  {
    sub_10DC24(dword_113284, *v3, *v4);
    rf_msg_log_rate(dword_113288, v7, a2, *v4);
    return 1;
  }
  *v4 = 0;
  if ( a2 <= 3 )
  {
    sub_10DC24(rf_cmd_queue_next_n_228, *v3, a2);
  }
  else
  {
    v9 = a1[2];
    v10 = *a1 | (a1[1] << 8) & 0xF00;
    if ( *(_BYTE *)patch_apply_n_2e )
      a1 = (unsigned __int8 *)feature_guard_check(512, rf_cmd_send_n288);
    if ( v9 == 1 )
    {
      if ( a2 == v10 || v10 + 1 == a2 )
      {
        ((void (*)(void))rf_stream_kick)();
        sub_113C48(v7 + 4);
        irq_nesting_or_d104(512);
        return 1;
      }
      sub_10DC24(rf_stream_start2_n_154, *v3, v10, a2);
    }
    else if ( v9 == 17 )
    {
      v11 = mm_chan_ctxt_unlink_cfm_handler;
      if ( *((unsigned __int8 *)mm_chan_ctxt_unlink_cfm_handler + 2433) >= (unsigned int)*((unsigned __int8 *)mm_chan_ctxt_unlink_cfm_handler
                                                                                         + 2434) )
      {
        sub_10DC24(rf_stream_start2_n_14c);
      }
      else
      {
        if ( v10 + 4 == a2 || a2 == v10 + 5 )
        {
          rf_stream_kick(a1);
          v12 = v11[2433];
          v13 = rf_cmd_send_n270_3280;
          v14 = (unsigned __int8)v11[2432]
              + 1
              - 40
              * ((unsigned int)(((unsigned int)rf_cmd_send_n26c
                               * (unsigned __int64)((unsigned int)(unsigned __int8)v11[2432] + 1)) >> 32) >> 5);
          v11[2432] = v14;
          v15 = &v11[20 * v14];
          *((_DWORD *)v15 + 409) = v7 + 4;
          *((_DWORD *)v15 + 412) = v10;
          v11[2433] = v12 + 1;
          list_push_tail(v13);
          irq_nesting_or_d104(0x400000);
          return 1;
        }
        sub_10DC24(dword_1132A0, *v3, v10, a2);
      }
    }
    else
    {
      sub_10DC24(rf_cmd_process_0, *v3, v9, v10, a2);
    }
  }
  v17 = log_free_dispatch_2(&v7[-*(_DWORD *)rf_cmd_send_n280]);
  rf_stream_kick(v17);
  return 1;
}

