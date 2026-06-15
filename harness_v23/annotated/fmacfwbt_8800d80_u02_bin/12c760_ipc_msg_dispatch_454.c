// v23 annotated: ipc_msg_dispatch_454 @ 0x12c760
// Original: 12c760_ipc_msg_dispatch_454.c
// Primary struct: ke_dispatch_ctx (cluster 8, 4 funcs)
// Fields: msg_id=0x4, task_id=0x6, param=0x8, status=0x6d
//
// ipc_msg_dispatch_454 @ 0x12c760, size 60 bytes
// Doc: message_dispatch_n_42a [ipc]: Dispatch a control message to message handler with tag 0x6d
// message_dispatch_n_42a [ipc]: Dispatch a control message to message handler with tag 0x6d
void __fastcall ipc_msg_dispatch_454(int a1, int a2, unsigned __int8 *a3)
{
  int v3; // r4
  int v4; // r0

  if ( *((_BYTE *)message_dispatch_n_418_c79c + 197) )
  {
    v3 = *(_DWORD *)(*(_DWORD *)(a2 + 76) + 48);
    v4 = scan_chan_parse_n1bd4((*(_DWORD *)(v3 + 20) >> 11) & 7, *(_DWORD *)(v3 + 20) & 0x7F, a3);
    *(_DWORD *)(v3 + 36) = v4 | (v4 << 8);
  }
  else if ( **(__int16 **)tx_message_dispatch < 0 )
  {
    sub_12F694(message_dispatch_n_40c_c7a8, message_dispatch_n_410, 109);
  }
}

