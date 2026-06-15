// v23 annotated: rf_cmd_wait @ 0x112878
// Original: 112878_rf_cmd_wait.c
// Primary struct: <unclustered>
//
// rf_cmd_wait @ 0x112878, size 126 bytes
// Doc: rf_stream_start [rf]: Start RF stream, init control byte and config word
// rf_stream_start [rf]: Start RF stream, init control byte and config word
void rf_cmd_wait()
{
  int *v0; // r4
  int v1; // r2
  int v2; // r3
  int v3; // r3
  int v4; // r2

  if ( (__get_CPSR() & 1) == 0 )
  {
    __disable_irq();
    *(_DWORD *)rf_cmd_send_dispatch = 1;
  }
  v0 = (int *)rf_cmd_send_n_1c;
  v1 = *(unsigned __int8 *)rf_cmd_send_n_18;
  v2 = *(_DWORD *)rf_cmd_send_n_1c + 1;
  *(_DWORD *)rf_cmd_send_n_1c = v2;
  if ( v1 )
  {
    *((_DWORD *)rf_cmd_send_n_14 + 513) |= 1u;
    while ( 1 )
      ;
  }
  if ( v2 )
  {
    v3 = v2 - 1;
    v4 = *(_DWORD *)rf_cmd_send_dispatch;
    *v0 = v3;
    if ( !v3 )
    {
      if ( v4 )
        __enable_irq();
    }
  }
}

