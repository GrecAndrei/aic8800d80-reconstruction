// v23 annotated: log_flush @ 0x1136b8
// Original: 1136b8_log_flush.c
// Primary struct: <unclustered>
//
// log_flush @ 0x1136b8, size 294 bytes
// Doc: rf_stream_start2_n314_3704 [rf]: RF stream start: loads callback table and invokes dispatch function
// rf_stream_start2_n314_3704 [rf]: RF stream start: loads callback table and invokes dispatch function
void log_flush()
{
  _BYTE *v0; // r5
  int v1; // r0
  _DWORD *v2; // r4
  _DWORD *v3; // r8
  unsigned int *v4; // r6
  unsigned int v5; // r1
  int v6; // r0
  int v7; // r0
  _BYTE *v8; // r7
  int v9; // r9
  unsigned int v10; // r1
  int v11; // r0
  int v12; // r0
  int v13; // r1

  v0 = off_1137E0;
  if ( *(_BYTE *)off_1137E0 )
  {
    if ( !*(_WORD *)rf_msg_process_body_n_45c )
    {
      feature_guard_check(512, rf_msg_process_body_n_440);
      return;
    }
    if ( *(unsigned __int8 *)rf_stream_start2_n3f8_37e8 >= (unsigned int)*(unsigned __int16 *)rf_msg_process_body_n_45c )
    {
      v13 = rf_cmd_queue_next_n340;
      *(_BYTE *)off_1137E4 = 1;
      feature_guard_check(512, v13);
    }
  }
  else
  {
    if ( *(_BYTE *)off_1137E4 )
      return;
    if ( *(unsigned __int8 *)rf_stream_start2_n3f8_37e8 >= (unsigned int)*(unsigned __int16 *)rf_msg_process_body_n_45c
      && !*(_BYTE *)off_1137E4 )
    {
      *(_BYTE *)off_1137E4 = 1;
      feature_guard_check(512, rf_cmd_queue_next_n340);
      return;
    }
  }
  v1 = (*(int (__fastcall **)(_DWORD))(*((_DWORD *)rf_msg_process_body_n_450 + 2) + 16))(*((_DWORD *)rf_msg_process_body_n_450
                                                                                         + 1));
  v2 = (_DWORD *)v1;
  if ( v1 )
  {
    if ( *v0 )
    {
      v3 = rf_stream_start2_n420;
      v4 = (unsigned int *)off_1137FC;
      v5 = *(_DWORD *)off_1137FC;
      v6 = *(_DWORD *)rf_stream_start2_n420 + v1;
      if ( *(_BYTE *)off_1137E4 )
        v7 = rf_stream_start2_0(v6, v5);
      else
        v7 = sub_113350(v6, v5);
    }
    else
    {
      v3 = rf_stream_start2_n420;
      v4 = (unsigned int *)off_1137FC;
      v7 = sub_113350(*(_DWORD *)rf_stream_start2_n420 + v1, *(_DWORD *)off_1137FC);
    }
    if ( v7 )
    {
      v8 = off_1137E4;
      sub_10DC24(rf_cmd_queue_next_n34c, v7);
      v9 = 5;
      while ( 1 )
      {
        if ( *v0 )
        {
          v10 = *v4;
          v11 = (int)v2 + *v3;
          v12 = *v8 ? rf_stream_start2_0(v11, v10) : sub_113350(v11, v10);
        }
        else
        {
          v12 = sub_113350((int)v2 + *v3, *v4);
        }
        if ( !v12 )
          break;
        if ( !--v9 )
        {
          sub_10DC24(rf_cmd_queue_next_n350, 5);
          log_free_dispatch_2(v2);
          irq_nesting_or_d104(32);
          return;
        }
      }
    }
  }
  else
  {
    irq_nesting_or_d104(32);
    sub_10DC24(rf_cmd_process_n2b4);
  }
}

