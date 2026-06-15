// ipc_doorbell_handler_n_4b8 @ 0x1154c4, size 12 bytes
// Doc: ipc_doorbell_handler_n_4ae [ipc]: Handle IPC doorbell interrupt with sub-id 0x65 (sign-extended)
// ipc_doorbell_handler_n_4ae [ipc]: Handle IPC doorbell interrupt with sub-id 0x65 (sign-extended)
int __fastcall ipc_doorbell_handler_n_4b8(int a1, int a2)
{
  int v2; // r0

  v2 = ipc_doorbell_handler_n_4a7;
  *(_BYTE *)message_dispatch_n_2ca = 0;
  return msg_parse(v2, a2, 0);
}

