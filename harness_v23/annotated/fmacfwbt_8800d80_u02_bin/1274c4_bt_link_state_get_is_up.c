// v23 annotated: bt_link_state_get_is_up @ 0x1274c4
// Original: 1274c4_bt_link_state_get_is_up.c
// Primary struct: <unclustered>
//
// bt_link_state_get_is_up @ 0x1274c4, size 134 bytes
// Doc: bt_link_state_get_is_up [bt]: Read BT link state flag and return bit 0 (link up status)
// bt_link_state_get_is_up [bt]: Read BT link state flag and return bit 0 (link up status)
int bt_link_state_get_is_up()
{
  _BYTE *v0; // r4
  int v1; // r3
  int result; // r0

  v0 = off_12754C;
  v1 = *((unsigned __int8 *)off_12754C + 88);
  result = v1 << 31;
  if ( (v1 & 1) != 0 )
  {
    if ( **(__int16 **)off_127550 < 0 && (v1 & 4) != 0 )
    {
      sub_12F694(dword_127560, dword_12755C, 1720);
      LOBYTE(v1) = v0[88];
    }
    v0[88] = v1 & 0xFA | 4;
    return rf_init_or_attach_n488(dword_127554);
  }
  else if ( (v1 & 6) == 2 )
  {
    if ( **(__int16 **)off_127550 < 0 && (v1 & 8) != 0 )
    {
      sub_12F694(dword_127564, dword_12755C, 1731);
      LOBYTE(v1) = v0[88];
    }
    v0[88] = v1 & 0xF5 | 8;
    return rf_init_or_attach_n488(dword_127558);
  }
  return result;
}

