// v23 annotated: sub_127108 @ 0x127108
// Original: 127108_sub_127108.c
// Primary struct: <unclustered>
//
// sub_127108 @ 0x127108, size 88 bytes
// Doc: bt_hci_cmd_send_n_c1c [bt]: Send HCI command 0x180a via BT path
// bt_hci_cmd_send_n_c1c [bt]: Send HCI command 0x180a via BT path
int sub_127108()
{
  _BYTE *v0; // r4
  int result; // r0
  int v2; // r0
  int v3; // r2
  int v4; // r0

  v0 = rf_level_apply_n388;
  *((_BYTE *)rf_level_apply_n388 + 1) = 1;
  result = sub_11DDCC(1070, 1);
  if ( !result )
  {
    sub_10DE98();
    v0[6] = mmio_bit_extract_n();
    rf_level_apply_n1b8();
    v2 = (unsigned __int8)v0[5];
    if ( (unsigned __int8)v0[6] != v2 )
    {
      sub_10F170(v2);
      v3 = (unsigned __int8)v0[5];
      v4 = rf_level_apply_168;
      v0[6] = v3;
      msg_parse(v4, v3);
    }
    return timer_set_relative(1070, 1, 1000 * *((_DWORD *)rf_level_apply_n38c + 91));
  }
  return result;
}

