// fwstruct annotate: 1132ac_sub_1132AC.c
// sub_1132AC @ 0x1132ac, size 126 bytes
// Doc: rf_stream_start2_3306 [rf]: Start secondary RF stream via IPC and mailbox
// rf_stream_start2_3306 [rf]: Start secondary RF stream via IPC and mailbox
int __fastcall sub_1132AC(int a1)
{
  unsigned __int16 *v2; // r4
  int v3; // r1
  int v4; // r2
  _BYTE *v5; // r1
  _BYTE *v6; // r2
  _DWORD *v7; // r7
  int v8; // r6
  int v9; // r1
  int inited; // r4
  int v11; // r2

  if ( (*(_DWORD *)off_11332C & 0x2000000) != 0 )
  {
    memset_thunk((int *)off_113330, 0xFFu, 4u);
  }
  else
  {
    v2 = (unsigned __int16 *)off_113330;
    memset_thunk((int *)off_113330, 0xFFu, 4u);
    if ( patch_apply_n_33(v2) || (v4 = v2[1], v4 == 0xFFFF) || (v3 = *v2, v3 == 0xFFFF) )
      msg_parse(rf_cmd_send_3334, v3, v4);
    else
      msg_parse(rf_msg_handler_n248, v3, v4);
  }
  v5 = rf_stream_start2_33c;
  v6 = rf_cmd_process_n_218;
  *(_DWORD *)rf_cmd_send_n328 = *(_DWORD *)a1;
  v7 = (_DWORD *)rf_stream_start2_n_ac;
  v8 = dword_113348;
  *v5 = 0;
  *v6 = 0;
  do
  {
    v9 = *(unsigned __int8 *)(a1 + 8);
    if ( *(_BYTE *)(a1 + 8) )
      v9 = 1;
    inited = rf_bus_init_0(v7, v9);
    msg_parse(v8, inited, v11);
  }
  while ( inited );
  return 0;
}

