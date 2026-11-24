// ipc_msg_handler_init @ 0x1163a8, size 132 bytes
// Doc: ipc_msg_handler_init [ipc]: IPC message handler init reading shared config
// ipc_msg_handler_init [ipc]: IPC message handler init reading shared config
int ipc_msg_handler_init()
{
  int **v0; // r5
  _DWORD *v1; // r6
  int *v2; // r0
  void *v3; // r8
  int v4; // r7
  unsigned __int16 v5; // r9
  int result; // r0

  v0 = (int **)off_116430;
  bt_xtal_init_check(dword_11642C);
  if ( **(__int16 **)off_116434 < 0 )
  {
    v2 = *v0;
    v1 = off_116438;
    if ( !*v0 || !*(_DWORD *)off_116438 )
    {
      sub_12F694(dword_11643C, dword_116440, 90);
      v2 = *v0;
    }
  }
  else
  {
    v1 = off_116438;
    v2 = *v0;
  }
  v3 = off_116444;
  v4 = dword_11642C;
  memset_thunk(v2, 0, 88 * *(unsigned __int16 *)(*(_DWORD *)off_116444 + 8) + 88);
  v5 = 0;
  do
  {
    (*v0)[22 * v5 + 19] = *v1 + 80 * v5;
    result = list_push_tail(v4);
    ++v5;
  }
  while ( *(unsigned __int16 *)(*(_DWORD *)v3 + 8) >= (unsigned int)v5 );
  return result;
}

