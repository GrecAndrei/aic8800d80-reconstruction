// fwstruct annotate: 11f3b8_ipc_msg_init_struct.c
// ipc_msg_init_struct @ 0x11f3b8, size 18 bytes
// Doc: ipc_msg_init_struct [ipc]: Initialize IPC/control struct fields to zero/one
// ipc_msg_init_struct [ipc]: Initialize IPC/control struct fields to zero/one
int __fastcall ipc_msg_init_struct(int result)
{
  *(_BYTE *)(result + 52) = 1;
  *(_BYTE *)(result + 163) = 0;
  *(_DWORD *)(result + 184) = 0;
  return result;
}

