// v23 annotated: fmac_subhandler_n_05b4 @ 0x1305b4
// Original: 1305b4_fmac_subhandler_n_05b4.c
// Primary struct: <unclustered>
//
// fmac_subhandler_n_05b4 @ 0x1305b4, size 88 bytes
// Doc: fmac_subhandler_n_05b4 [mac]: FMAC sub-handler/dispatcher
// fmac_subhandler_n_05b4 [mac]: FMAC sub-handler/dispatcher
int fmac_subhandler_n_05b4()
{
  _BYTE *v0; // r4
  int result; // r0
  int v2; // r0
  int v3; // r2
  int v4; // r0

  v0 = off_13060C;
  *((_BYTE *)off_13060C + 1) = 1;
  result = message_dispatch_c8b4(1070, 1);
  if ( !result )
  {
    rf_cmd_send_1();
    v0[6] = sub_10EF24();
    rf_timer_toggle_update();
    v2 = (unsigned __int8)v0[5];
    if ( (unsigned __int8)v0[6] != v2 )
    {
      rf_reg_write_masked(v2);
      v3 = (unsigned __int8)v0[5];
      v4 = dword_130614;
      v0[6] = v3;
      msg_parse(v4, v3);
    }
    return timer_set_relative(1070, 1, 1000 * *((_DWORD *)off_130610 + 91));
  }
  return result;
}

