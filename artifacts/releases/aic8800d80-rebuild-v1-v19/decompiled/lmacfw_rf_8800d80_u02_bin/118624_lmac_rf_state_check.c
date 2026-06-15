// lmac_rf_state_check @ 0x118624, size 76 bytes
// Doc: lmac_rf_state_check [rf]: Checks LMAC RF state flags from shared control struct
// lmac_rf_state_check [rf]: Checks LMAC RF state flags from shared control struct
_DWORD *lmac_rf_state_check()
{
  _BYTE *v0; // r4
  int inited; // r0
  int updated; // r0
  int v3; // r0
  int v4; // r0
  int v5; // r0

  v0 = off_118670;
  if ( !*((_BYTE *)off_118670 + 2) )
    mmio_init_40328050();
  sub_11843C();
  sub_117DF4();
  inited = rf_init_subsystem_7af8();
  sub_11C814(inited);
  rf_lmac_handler_n5820();
  if ( v0[2] )
    updated = accum_update_addr_pair();
  else
    updated = rf_calib_table_init();
  v3 = sub_11AB0C(updated);
  v4 = sub_11CA94(v3);
  v5 = lmac_rf_init_5cbuf(v4);
  sub_11D8D4(v5);
  sub_10F50C();
  return mmio_reg_set_bits();
}

