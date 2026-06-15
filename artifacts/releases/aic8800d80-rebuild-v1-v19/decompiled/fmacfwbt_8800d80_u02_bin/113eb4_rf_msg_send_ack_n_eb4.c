// rf_msg_send_ack_n_eb4 @ 0x113eb4, size 56 bytes
// Doc: rf_msg_send_ack_n_eb4 [ipc]: Send RF message ack to host via IPC call
// rf_msg_send_ack_n_eb4 [ipc]: Send RF message ack to host via IPC call
int rf_msg_send_ack_n_eb4()
{
  int *v0; // r4
  int result; // r0
  int v2; // r3
  int v3; // r2

  init_alloc_0x200000();
  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)off_113EEC = 1;
  }
  v0 = (int *)off_113EF0;
  ++*(_DWORD *)off_113EF0;
  result = sub_12D374(128);
  if ( *v0 )
  {
    v2 = *v0 - 1;
    v3 = *(_DWORD *)off_113EEC;
    *v0 = v2;
    if ( !v2 )
    {
      if ( v3 )
        __enable_irq();
    }
  }
  return result;
}

