// ipc_msg_post_log @ 0x136f84, size 22 bytes
// Doc: ipc_msg_post_log [ipc]: posts message to IPC queue with payload from shared struct
// ipc_msg_post_log [ipc]: posts message to IPC queue with payload from shared struct
int __fastcall ipc_msg_post_log(int a1, int a2, int a3, int a4)
{
  feature_guard_check(8, dword_136FA0, a4, *((unsigned __int16 *)off_136F9C + 1924));
  return 2;
}

