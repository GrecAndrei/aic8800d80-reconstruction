// fwstruct annotate: 137228_ipc_msg_send_0x100b.c
// ipc_msg_send_0x100b @ 0x137228, size 48 bytes
// Doc: ipc_msg_send_0x100b [ipc]: Send IPC message with code 0x100b using message dispatch helper
// ipc_msg_send_0x100b [ipc]: Send IPC message with code 0x100b using message dispatch helper
int __fastcall ipc_msg_send_0x100b(int a1, unsigned __int8 *a2)
{
  unsigned __int16 *v2; // r5
  int v4; // r0

  v2 = (unsigned __int16 *)off_137258;
  v4 = rf_bus_setup_n3a8(4107, *((_WORD *)off_137258 + 1924), 4, 1u);
  sub_12CBB4(v4);
  feature_guard_sdio(8, dword_13725C, v2[1924]);
  bt_init_check_1827f4(*a2);
  return 0;
}

