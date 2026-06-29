// message_dispatch_n_21e_0e60 @ 0x140e60, size 52 bytes
// Doc: message_dispatch_n_21e_0e60 [ipc]: Dispatch incoming message from 0x192b80 mailbox via handler
// message_dispatch_n_21e_0e60 [ipc]: Dispatch incoming message from 0x192b80 mailbox via handler
int  message_dispatch_n_21e_0e60(char a1, char a2, char a3, int a4, char a5)
{
  int v5; // r4
  __int16 v6; // r6
  int result; // r0
  uint8_t v8[140]; // [sp+0h] [bp-8Ch] BYREF

  v5 = dword_140E94;
  v8[2] = a5;
  v6 = *(uint16_t *)(dword_140E94 + 6488);
  *(uint8_t *)(dword_140E94 + 6488) = a2;
  *(uint8_t *)(v5 + 6489) = a1;
  v8[0] = a3;
  result = bt_chan_state_check_n_4b80((int)v8, a4);
  *(uint16_t *)(v5 + 6488) = v6;
  return result;
}

