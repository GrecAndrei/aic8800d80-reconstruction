// ipc_msg_dispatch @ 0x102f4c, size 48 bytes
// Doc: ipc_msg_dispatch [ipc]: Dispatch IPC message to handler via table lookup
// ipc_msg_dispatch [ipc]: Dispatch IPC message to handler via table lookup
int ipc_msg_dispatch()
{
  uint64_t v0; // kr00_8
  int v1; // r4

  v0 = *(QWORD *)((char *)off_102F7C + 4);
  v1 = *(uint32_t *)off_102F7C;
  sub_102EB8(0, 32, 0x10u, SHIDWORD(v0));
  sub_102EB8(0, 48, 0x10u, v0);
  return sub_102EB8(0, 64, 0x10u, v1);
}

