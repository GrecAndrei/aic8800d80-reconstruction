// ipc_msg_handle_n_884 @ 0x135884, size 144 bytes
// Doc: ipc_msg_handle_n_884 [ipc]: Handle incoming IPC message (id 6) and dispatch
// ipc_msg_handle_n_884 [ipc]: Handle incoming IPC message (id 6) and dispatch
int __fastcall ipc_msg_handle_n_884(int a1)
{
  int v2; // r6
  int result; // r0
  int v4; // r6
  int v5; // r4

  v2 = *(unsigned __int8 *)(a1 + 8);
  if ( msg_get_value(6u) == 10 || msg_get_value(6u) == 9 )
    return 2;
  if ( msg_get_value(6u) )
  {
    if ( *(unsigned __int8 *)(*((_DWORD *)off_135914 + 4) + 61) != *(unsigned __int8 *)(a1 + 8) )
      return 2;
    feature_guard_sdio(256, dword_135920);
    if ( message_dispatch_n_d8(6154, 6) )
      sub_12C964(6154, 6);
    sub_135020(1);
    return 0;
  }
  else
  {
    v4 = dword_135918 + 1320 * v2;
    result = *(unsigned __int8 *)(v4 + 108);
    if ( *(_BYTE *)(v4 + 108) )
    {
      v5 = *(unsigned __int16 *)(a1 + 12);
      feature_guard_sdio(256, dword_13591C, v5);
      sub_134FA8(v4, v5, 0);
      return 0;
    }
  }
  return result;
}

