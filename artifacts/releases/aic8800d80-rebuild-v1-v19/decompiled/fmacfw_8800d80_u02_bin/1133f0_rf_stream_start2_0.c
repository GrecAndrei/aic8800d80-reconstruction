// rf_stream_start2_0 @ 0x1133f0, size 164 bytes
// Doc: rf_cmd_process_n_f2 [rf]: Process RF command loading shared data pointers
// rf_cmd_process_n_f2 [rf]: Process RF command loading shared data pointers
int __fastcall rf_stream_start2_0(int a1, unsigned int a2)
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
  v3 = rf_stream_start_498;
  if ( *(_BYTE *)rf_stream_start_498 )
  {
    sub_10DC24(rf_stream_start2_nbc, dword_1134A8, *(unsigned __int8 *)rf_stream_start_498);
    return -3;
  }
  else
  {
    v4 = *(char *)rf_msg_handler_n398;
    *(_BYTE *)rf_stream_start_498 = 1;
    v5 = off_1134A0;
    if ( v4 )
    {
      *((_DWORD *)off_1134A0 + 716) &= 0xE007FFFF;
      v5[512] |= 0x2000u;
    }
    else
    {
      *((_DWORD *)off_1134A0 + 713) |= 1u;
    }
    v6 = rf_state_check_11c(1, a1, a2);
    v7 = v6;
    if ( v6 )
    {
      sub_10DC24(dword_1134B0, dword_1134A8, v6);
      return -1;
    }
    else
    {
      *(_BYTE *)off_1134A4 = 1;
      if ( *v2 )
      {
        rf_bus_write_wrapper(nullptr, 1u);
        *v3 = 0;
        return -14;
      }
    }
  }
  return v7;
}

