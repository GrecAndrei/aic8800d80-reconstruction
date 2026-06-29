// fwstruct annotate: 122b64_sub_122B64.c
// sub_122B64 @ 0x122b64, size 40 bytes
// Doc: bt_hci_cmd_alloc_2b66 [bt]: Allocate and prepare HCI command buffer (opcode 0xb)
// bt_hci_cmd_alloc_2b66 [bt]: Allocate and prepare HCI command buffer (opcode 0xb)
int __fastcall sub_122B64(int a1, int a2, int a3, int a4)
{
  _BYTE *v5; // r4

  v5 = (_BYTE *)rf_bus_setup_n3a8(11, a4, a3, 3);
  *v5 = rf_stream_dispatch(a2, v5 + 1, v5 + 2);
  sub_12CBB4(v5);
  return 0;
}

