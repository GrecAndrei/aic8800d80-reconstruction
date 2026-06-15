// v23 annotated: sub_12C538 @ 0x12c538
// Original: 12c538_sub_12C538.c
// Primary struct: ke_dispatch_ctx (cluster 17, 4 funcs)
// Fields: msg_id=0x4, task_id=0x6, param=0x8, status=0x6d
//
// sub_12C538 @ 0x12c538, size 60 bytes
// Doc: message_dispatch_n_434 [ipc]: Dispatches message event packing bitfield into 16-bit identifier
// message_dispatch_n_434 [ipc]: Dispatches message event packing bitfield into 16-bit identifier
void __fastcall sub_12C538(int a1, int a2, unsigned __int8 *a3)
{
  int v3; // r4
  int v4; // r0

  if ( *((_BYTE *)message_dispatch_n_418 + 197) )
  {
    v3 = *(_DWORD *)(*(_DWORD *)(a2 + 76) + 48);
    v4 = sub_101D58((*(_DWORD *)(v3 + 20) >> 11) & 7, *(_DWORD *)(v3 + 20) & 0x7F, a3);
    *(_DWORD *)(v3 + 36) = v4 | (v4 << 8);
  }
  else if ( **(__int16 **)ipc_msg_dispatch_c578 < 0 )
  {
    sub_12F46C(message_dispatch_n_40c, message_dispatch_n_410, 109);
  }
}

