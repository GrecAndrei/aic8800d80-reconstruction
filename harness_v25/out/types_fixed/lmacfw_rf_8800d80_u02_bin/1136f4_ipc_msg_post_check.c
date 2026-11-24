// ipc_msg_post_check @ 0x1136f4, size 82 bytes
// Doc: ipc_msg_post_check [ipc]: Validates and posts IPC message via global queue pointer
// ipc_msg_post_check [ipc]: Validates and posts IPC message via global queue pointer
int __fastcall ipc_msg_post_check(int a1, int a2, int a3, int a4)
{
  int result; // r0

  if ( a1 == *(_DWORD *)off_113748 || a1 == *((_DWORD *)off_113748 + 1) )
    result = msg_parse(dword_11375C, dword_113758);
  else
    result = msg_parse(dword_11374C, a1);
  if ( *((_BYTE *)off_113750 + 353) )
    return timer_set_relative(1068, 1, 1000 * *((unsigned __int8 *)off_113750 + 354), a4);
  return result;
}

