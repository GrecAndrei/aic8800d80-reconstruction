// fwstruct annotate: 11324c_rf_stream_start2_324c.c
// rf_stream_start2_324c @ 0x11324c, size 164 bytes
// Doc: rf_cmd_send_n47c [rf]: Send RF command sequence n47c
// rf_cmd_send_n47c [rf]: Send RF command sequence n47c
int __fastcall rf_stream_start2_324c(int a1, unsigned int a2)
{
  _BYTE *v2; // r4
  _BYTE *v3; // r5
  int v4; // r3
  _DWORD *v5; // r2
  int v6; // r0
  int v7; // r2

  v2 = rf_cmd_send_n484;
  if ( *(_BYTE *)rf_cmd_send_n484 )
    return -14;
  if ( !a1 || !a2 )
    return -11;
  v3 = rf_bus_mark_n_250_32f4;
  if ( *(_BYTE *)rf_bus_mark_n_250_32f4 )
  {
    log_printf(rf_stream_start2_nbc, rf_cmd_send_n498, *(unsigned __int8 *)rf_bus_mark_n_250_32f4);
    return -3;
  }
  else
  {
    v4 = *(char *)rf_cmd_send_n48c;
    *(_BYTE *)rf_bus_mark_n_250_32f4 = 1;
    v5 = rf_msg_handler_n39c;
    if ( v4 )
    {
      *((_DWORD *)rf_msg_handler_n39c + 716) &= 0xE007FFFF;
      v5[512] |= 0x2000u;
    }
    else
    {
      *((_DWORD *)rf_msg_handler_n39c + 713) |= 1u;
    }
    v6 = rf_bus_write2_n500(1, a1, a2);
    v7 = v6;
    if ( v6 )
    {
      log_printf(rf_msg_handler_n3ac, rf_cmd_send_n498, v6);
      return -1;
    }
    else
    {
      *(_BYTE *)rf_msg_handler_n3a0 = 1;
      if ( *v2 )
      {
        rf_bus_reset2_n3b8(nullptr, 1u);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v7;
}

