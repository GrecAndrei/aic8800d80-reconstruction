// sub_12C538 @ 0x12c538, size 60 bytes
// Doc: message_dispatch_n_434 [ipc]: Dispatches message event packing bitfield into 16-bit identifier
// message_dispatch_n_434 [ipc]: Dispatches message event packing bitfield into 16-bit identifier
void  sub_12C538(int a1, int a2, unsigned __int8 *a3)
{
  int v3; // r4
  int v4; // r0

  if ( *((uint8_t *)message_dispatch_n_418 + 197) )
  {
    v3 = *(uint32_t *)(*(uint32_t *)(a2 + 76) + 48);
    v4 = sub_101D58((*(uint32_t *)(v3 + 20) >> 11) & 7, *(uint32_t *)(v3 + 20) & 0x7F, a3);
    *(uint32_t *)(v3 + 36) = v4 | (v4 << 8);
  }
  else if ( **(__int16 **)ipc_msg_dispatch_c578 < 0 )
  {
    sub_12F46C(message_dispatch_n_40c, message_dispatch_n_410, 109);
  }
}

