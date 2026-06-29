// ke_msg_dispatch_n_5c8 @ 0x12ef78, size 42 bytes
// Doc: ke_msg_dispatch_n_5c8 [ipc]: Dispatch KE message via IPC lookup table
// ke_msg_dispatch_n_5c8 [ipc]: Dispatch KE message via IPC lookup table
int  ke_msg_dispatch_n_5c8(int a1, uint32_t *a2, __int16 a3, __int16 a4)
{
  msg_parse(dword_12EFA4, *a2);
  *((uint32_t *)off_12EFA8 + 1) = *a2;
  sub_12CA10(1031, a4, a3);
  return 0;
}

