// rf_cmd_wait_2f70 @ 0x112f70, size 126 bytes
// Doc: rf_cmd_send_n_30 [rf]: Dispatch an RF command to the radio
// rf_cmd_send_n_30 [rf]: Dispatch an RF command to the radio
void rf_cmd_wait_2f70()
{
  int *v0; // r4
  int v1; // r2
  int v2; // r3
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)rf_stream_start_n_360 = 1;
  }
  v0 = (int *)off_112FF4;
  v1 = *(unsigned __int8 *)off_112FF8;
  v2 = *(_DWORD *)off_112FF4 + 1;
  *(_DWORD *)off_112FF4 = v2;
  if ( v1 )
  {
    *((_DWORD *)rf_cmd_queue_next_n_4b8 + 513) |= 1u;
    while ( 1 )
      ;
  }
  if ( v2 )
  {
    v3 = v2 - 1;
    v4 = *(_DWORD *)rf_stream_start_n_360;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
}

