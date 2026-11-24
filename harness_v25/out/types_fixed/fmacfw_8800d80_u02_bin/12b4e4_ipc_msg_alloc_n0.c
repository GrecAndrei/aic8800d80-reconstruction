// ipc_msg_alloc_n0 @ 0x12b4e4, size 40 bytes
// Doc: ipc_msg_alloc_n0 [ipc]: Allocate/initialize IPC message (id 0x804) and link to queue
// ipc_msg_alloc_n0 [ipc]: Allocate/initialize IPC message (id 0x804) and link to queue
int __fastcall ipc_msg_alloc_n0(char a1, int a2)
{
  _BYTE *v3; // r4

  v3 = (_BYTE *)sub_12C92C(2052, a2, 2, 1);
  feature_guard_check(4, dword_12B510);
  *v3 = a1;
  return sdio_buffer_prepare_n_4e8(v3);
}

