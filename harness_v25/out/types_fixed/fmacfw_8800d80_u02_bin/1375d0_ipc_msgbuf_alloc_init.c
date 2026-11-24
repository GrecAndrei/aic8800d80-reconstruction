// ipc_msgbuf_alloc_init @ 0x1375d0, size 26 bytes
// Doc: ipc_msgbuf_alloc_init [ipc]: Allocate IPC message buffer of size 0xfc0 with id 4
// ipc_msgbuf_alloc_init [ipc]: Allocate IPC message buffer of size 0xfc0 with id 4
int *ipc_msgbuf_alloc_init()
{
  sub_12CD34(4u, 0);
  return memset_thunk((int *)dword_1375EC, 0, 0xFC0u);
}

