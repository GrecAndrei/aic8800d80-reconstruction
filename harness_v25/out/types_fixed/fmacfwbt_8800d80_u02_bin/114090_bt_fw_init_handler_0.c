// bt_fw_init_handler_0 @ 0x114090, size 72 bytes
// Doc: bt_fw_init_handler [bt]: BT firmware init/handler accessing global state offsets 0x234/0x23c
// bt_fw_init_handler [bt]: BT firmware init/handler accessing global state offsets 0x234/0x23c
int bt_fw_init_handler_0()
{
  _DWORD *v0; // r5
  void *v1; // r7
  int result; // r0
  int v3; // r6
  int v4; // r4

  v0 = off_1140D8;
  v1 = off_1140DC;
  bt_xtal_init_check(*(_DWORD *)off_1140D8 + 564);
  result = bt_xtal_init_check(*v0 + 572);
  if ( *(_WORD *)(*(_DWORD *)v1 + 8) )
  {
    v3 = dword_1140E0;
    v4 = 0;
    do
    {
      log_pool_alloc2(v3, 0x6B8u);
      result = list_push_tail(*v0 + 564);
      ++v4;
    }
    while ( *(unsigned __int16 *)(*(_DWORD *)v1 + 8) > (unsigned int)(unsigned __int16)v4 );
  }
  return result;
}

