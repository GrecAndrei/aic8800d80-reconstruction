// fw_event_post_n124 @ 0x137124, size 48 bytes
// Doc: fw_event_post_n124 [ipc]: Posts firmware event with opcode 0x100b to host message queue
// fw_event_post_n124 [ipc]: Posts firmware event with opcode 0x100b to host message queue
int __fastcall fw_event_post_n124(int a1, unsigned __int8 *a2)
{
  unsigned __int16 *v2; // r5
  int v4; // r0

  v2 = (unsigned __int16 *)off_137154;
  v4 = sub_12C92C(4107, *((_WORD *)off_137154 + 1924), 4, 1u);
  sdio_buffer_prepare_n_4e8(v4);
  feature_guard_check(8, dword_137158, v2[1924]);
  sub_1374C8(*a2);
  return 0;
}

