// sub_113350 @ 0x113350, size 130 bytes
// Doc: rf_stream_start2_3390 [rf]: Starts an RF stream (variant 2)
// rf_stream_start2_3390 [rf]: Starts an RF stream (variant 2)
int __fastcall sub_113350(int a1, unsigned int a2)
{
  _BYTE *v2; // r4
  _BYTE *v3; // r6
  _DWORD *v4; // r7
  int v5; // r0
  int v6; // r2

  v2 = rf_cmd_wait_n464;
  if ( *(_BYTE *)rf_cmd_wait_n464 )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = rf_cmd_send_n3c8;
  if ( *(_BYTE *)rf_cmd_send_n3c8 )
  {
    sub_10DC24(rf_cmd_process_n_170, rf_msg_handler_n2e0, *(unsigned __int8 *)rf_cmd_send_n3c8);
    return -3;
  }
  else
  {
    v4 = rf_msg_handler_n2d8;
    *(_BYTE *)rf_cmd_send_n3c8 = 1;
    v4[716] &= 0xE007FFFF;
    v5 = rf_bus_setup_n14c(1, a1, a2);
    v6 = v5;
    if ( v5 )
    {
      sub_10DC24(dword_1133EC, rf_msg_handler_n2e0, v5);
      return -1;
    }
    else
    {
      *(_BYTE *)rf_level_apply_n_14e = 1;
      if ( *v2 )
      {
        rf_bus_write_wrapper(nullptr, 1u);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v6;
}

