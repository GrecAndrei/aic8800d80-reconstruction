// message_dispatch_n_3c4 @ 0x12c7f0, size 26 bytes
// Doc: message_dispatch_n_3c4 [ipc]: Dispatches incoming message based on length/type field
// message_dispatch_n_3c4 [ipc]: Dispatches incoming message based on length/type field
BOOL __fastcall message_dispatch_n_3c4(int a1, unsigned int a2)
{
  return *(unsigned __int16 *)(a1 + 4) == HIWORD(a2) && *(unsigned __int16 *)(a1 + 6) == (unsigned __int16)a2;
}

