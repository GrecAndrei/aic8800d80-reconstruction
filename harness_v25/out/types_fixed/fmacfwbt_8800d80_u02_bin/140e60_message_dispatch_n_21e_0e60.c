// message_dispatch_n_21e_0e60 @ 0x140e60, size 52 bytes
// Doc: message_dispatch_n_21e_0e60 [ipc]: Dispatch incoming message from 0x192b80 mailbox via handler
// message_dispatch_n_21e_0e60 [ipc]: Dispatch incoming message from 0x192b80 mailbox via handler
int __fastcall message_dispatch_n_21e_0e60(char a1, char a2, char a3, int a4, char a5)
{
  int v5; // r4
  __int16 v6; // r6
  int result; // r0
  _BYTE *(_DWORD *)(v8 + 0x230); // [sp+0h] [bp-8Ch] BYREF

  v5 = dword_140E94;
  *(_DWORD *)(v8 + 0x8) = a5;
  v6 = *(_WORD *)(dword_140E94 + 6488);
  *(_BYTE *)(dword_140E94 + 6488) = a2;
  *(_BYTE *)(v5 + 6489) = a1;
  *(_DWORD *)(v8 + 0x0) = a3;
  result = bt_chan_state_check_n_4b80((int)v8, a4);
  *(_WORD *)(v5 + 6488) = v6;
  return result;
}

