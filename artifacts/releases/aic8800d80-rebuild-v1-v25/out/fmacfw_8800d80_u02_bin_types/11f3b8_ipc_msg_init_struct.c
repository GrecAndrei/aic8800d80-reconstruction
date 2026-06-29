// ipc_msg_init_struct @ 0x11f3b8, size 18 bytes
// Doc: ipc_msg_init_struct [ipc]: Initialize IPC/control struct fields to zero/one
// ipc_msg_init_struct [ipc]: Initialize IPC/control struct fields to zero/one
int  ipc_msg_init_struct(int result)
{
  *(uint8_t *)(result + 52) = 1;
  *(uint8_t *)(result + 163) = 0;
  *(uint32_t *)(result + 184) = 0;
  return result;
}

