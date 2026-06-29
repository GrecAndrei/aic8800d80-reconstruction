// ipc_msg_dispatch_454 @ 0x12c760, size 60 bytes
// Doc: message_dispatch_n_42a [ipc]: Dispatch a control message to message handler with tag 0x6d
// message_dispatch_n_42a [ipc]: Dispatch a control message to message handler with tag 0x6d
void  ipc_msg_dispatch_454(int a1, int a2, unsigned __int8 *a3)
{
  int v3; // r4
  int v4; // r0

  if ( *((uint8_t *)message_dispatch_n_418_c79c + 197) )
  {
    v3 = *(uint32_t *)(*(uint32_t *)(a2 + 76) + 48);
    v4 = scan_chan_parse_n1bd4((*(uint32_t *)(v3 + 20) >> 11) & 7, *(uint32_t *)(v3 + 20) & 0x7F, a3);
    *(uint32_t *)(v3 + 36) = v4 | (v4 << 8);
  }
  else if ( **(__int16 **)tx_message_dispatch < 0 )
  {
    sub_12F694(message_dispatch_n_40c_c7a8, message_dispatch_n_410, 109);
  }
}

