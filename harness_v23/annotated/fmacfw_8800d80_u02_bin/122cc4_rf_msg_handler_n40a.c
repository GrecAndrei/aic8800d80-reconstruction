// v23 annotated: rf_msg_handler_n40a @ 0x122cc4
// Original: 122cc4_rf_msg_handler_n40a.c
// Primary struct: <unclustered>
//
// rf_msg_handler_n40a @ 0x122cc4, size 20 bytes
// Doc: rf_msg_handler_n40a [rf]: Handles RF message parsing, computing offset from header field
// rf_msg_handler_n40a [rf]: Handles RF message parsing, computing offset from header field
int __fastcall rf_msg_handler_n40a(int a1, _DWORD *a2, int a3, int a4)
{
  *(_DWORD *)off_122CD8 = *a2;
  sub_12CA10(114, a4, a3);
  return 0;
}

