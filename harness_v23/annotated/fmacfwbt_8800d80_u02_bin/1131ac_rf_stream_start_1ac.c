// v23 annotated: rf_stream_start_1ac @ 0x1131ac
// Original: 1131ac_rf_stream_start_1ac.c
// Primary struct: <unclustered>
//
// rf_stream_start_1ac @ 0x1131ac, size 130 bytes
// Doc: rf_cmd_send_3204 [rf]: Send RF command via bus and store result
// rf_cmd_send_3204 [rf]: Send RF command via bus and store result
int __fastcall rf_stream_start_1ac(int a1, unsigned int a2)
{
  _BYTE *v2; // r4
  _BYTE *v3; // r6
  _DWORD *v4; // r7
  int v5; // r0
  int v6; // r2

  v2 = rf_stream_start2_n_1c;
  if ( *(_BYTE *)rf_stream_start2_n_1c )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = rf_msg_handler_n2d4;
  if ( *(_BYTE *)rf_msg_handler_n2d4 )
  {
    log_printf(rf_cmd_send_n3d8, rf_msg_handler_n2e0, *(unsigned __int8 *)rf_msg_handler_n2d4);
    return -3;
  }
  else
  {
    v4 = sdio_buffer_prepare_n_210;
    *(_BYTE *)rf_msg_handler_n2d4 = 1;
    v4[716] &= 0xE007FFFF;
    v5 = rf_bus_write2_n42c(1, a1, a2);
    v6 = v5;
    if ( v5 )
    {
      log_printf(rf_msg_handler_n2e8, rf_msg_handler_n2e0, v5);
      return -1;
    }
    else
    {
      *(_BYTE *)rf_msg_handler_n2dc = 1;
      if ( *v2 )
      {
        rf_bus_reset2_n3b8(nullptr, 1u);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v6;
}

