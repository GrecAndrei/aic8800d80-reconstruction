// v23 annotated: sub_1322A8 @ 0x1322a8
// Original: 1322a8_sub_1322A8.c
// Primary struct: <unclustered>
//
// sub_1322A8 @ 0x1322a8, size 62 bytes
int __fastcall sub_1322A8(int a1, unsigned __int8 *a2)
{
  int v2; // r6
  int v4; // r0

  v2 = dword_1322E8;
  timestamp_remove_058(696 * *a2 + 672 + dword_1322E8);
  v4 = *a2;
  if ( *(_BYTE *)(v2 + 696 * v4 + 37) )
    ipc_msg_alloc_init(v4);
  else
    message_dispatch_n84(5130, 13, 5);
  return 0;
}

