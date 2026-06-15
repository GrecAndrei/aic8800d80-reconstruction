// v23 annotated: mac_cmd_send_status_query @ 0x122248
// Original: 122248_mac_cmd_send_status_query.c
// Primary struct: <unclustered>
//
// mac_cmd_send_status_query @ 0x122248, size 30 bytes
// Doc: mac_cmd_send_status_query [mac]: Send MAC command 0x43 status query
// mac_cmd_send_status_query [mac]: Send MAC command 0x43 status query
int __fastcall mac_cmd_send_status_query(int a1)
{
  _BYTE *v2; // r0

  v2 = (_BYTE *)rf_bus_setup_n3a8(67, 6, 0, 1);
  *v2 = *(_BYTE *)(a1 + 107);
  return sub_12CBB4(v2);
}

