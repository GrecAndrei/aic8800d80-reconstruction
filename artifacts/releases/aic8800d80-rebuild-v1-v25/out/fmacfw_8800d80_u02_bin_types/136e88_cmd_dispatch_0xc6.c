// cmd_dispatch_0xc6 @ 0x136e88, size 12 bytes
// Doc: cmd_dispatch_0xc6 [ipc]: Dispatches host command ID 0xC6 handler
// cmd_dispatch_0xc6 [ipc]: Dispatches host command ID 0xC6 handler
int cmd_dispatch_0xc6()
{
  int v0; // r0

  v0 = dword_136E98;
  *(uint8_t *)off_136E94 = 0;
  return msg_parse(v0);
}

