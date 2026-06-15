// v23 annotated: sub_113C20 @ 0x113c20
// Original: 113c20_sub_113C20.c
// Primary struct: <unclustered>
//
// sub_113C20 @ 0x113c20, size 28 bytes
// Doc: rf_msg_process_body_c22 [rf]: Process RF message body handler
// rf_msg_process_body_c22 [rf]: Process RF message body handler
int __fastcall sub_113C20(int a1)
{
  _BYTE *v1; // r2
  char v2; // r3

  rf_msg_process_init(a1);
  v1 = rf_msg_process_body_n_4;
  v2 = *((_BYTE *)off_113C3C + 352);
  *(_BYTE *)rf_msg_process_body_n_8 = *((_BYTE *)off_113C3C + 326);
  *v1 = v2;
  return 1;
}

