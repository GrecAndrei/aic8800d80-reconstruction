// fwstruct annotate: 12048c_ipc_msg_send_n048c.c
// ipc_msg_send_n048c @ 0x12048c, size 26 bytes
// Doc: ipc_msg_send_n048c [ipc]: Allocate IPC message (id 0x8f) and store caller's context pointer
// ipc_msg_send_n048c [ipc]: Allocate IPC message (id 0x8f) and store caller's context pointer
int __fastcall ipc_msg_send_n048c(int a1)
{
  _DWORD *v2; // r0

  v2 = (_DWORD *)sub_12C92C(143, 0, 255, 4);
  *v2 = a1;
  return sdio_buffer_prepare_n_4e8(v2);
}

