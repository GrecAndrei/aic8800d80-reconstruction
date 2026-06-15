// v23 annotated: log_free_pool_f_904 @ 0x113904
// Original: 113904_log_free_pool_f_904.c
// Primary struct: <unclustered>
//
// log_free_pool_f_904 @ 0x113904, size 156 bytes
// Doc: rf_msg_handler_0x2f0 [ipc]: RF message body handler for message id 0x2f0
// rf_msg_handler_0x2f0 [ipc]: RF message body handler for message id 0x2f0
void log_free_pool_f_904()
{
  int *v0; // r4
  int v1; // r0
  _BYTE *v2; // r1
  int v3; // r0
  unsigned __int16 v4; // r3
  int v5; // r3
  int v6; // r2
  int v7; // r3

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)rf_cmd_queue_next_n4ec = 1;
  }
  v0 = (int *)off_1139A4;
  v1 = rf_cmd_queue_next_n4f4;
  ++*(_DWORD *)off_1139A4;
  list_push_tail(v1);
  v2 = off_1139B0;
  v3 = *(unsigned __int8 *)off_1139B0;
  v4 = *(_WORD *)rf_cmd_queue_next + 1;
  *(_WORD *)rf_cmd_queue_next = v4;
  if ( v3 && *(unsigned __int8 *)rf_bus_write2_n_2ca <= (unsigned int)v4 )
  {
    v7 = *(unsigned __int8 *)off_1139B8;
    *v2 = 0;
    if ( v7 )
      *((_DWORD *)rf_msg_process_body_n_28c + 512) &= ~0x2000u;
    else
      *((_DWORD *)rf_msg_process_body_n_28c + 713) &= ~1u;
    hw_event_flag_20fc(1);
    event_queue_push(1069, 1);
    feature_guard_check(512, dword_1139C0);
    if ( !*(_BYTE *)rf_cmd_process_n46c )
      log_flush();
  }
  if ( *v0 )
  {
    v5 = *v0 - 1;
    v6 = *(_DWORD *)rf_cmd_queue_next_n4ec;
    *v0 = v5;
    if ( !v5 )
    {
      if ( v6 )
        __enable_irq();
    }
  }
}

