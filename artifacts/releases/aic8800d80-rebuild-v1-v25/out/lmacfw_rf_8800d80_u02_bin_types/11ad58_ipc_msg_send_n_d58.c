// ipc_msg_send_n_d58 @ 0x11ad58, size 42 bytes
// Doc: ipc_msg_send_n_d58 [ipc]: Send IPC message (opcode 0x48) with header field from r4+0x18
// ipc_msg_send_n_d58 [ipc]: Send IPC message (opcode 0x48) with header field from r4+0x18
int  ipc_msg_send_n_d58(int a1)
{
  uint8_t *v2; // r0
  uint32_t *v3; // r2

  v2 = (uint8_t *)rf_setup_dispatch(72, *(unsigned __int16 *)(a1 + 14), 0, 2);
  v2[1] = *(uint8_t *)(a1 + 24);
  v3 = off_11AD84;
  *v2 = *(uint8_t *)(a1 + 26);
  *v3 &= ~4u;
  return sub_11DE50(v2);
}

