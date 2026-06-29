// sub_113C20 @ 0x113c20, size 28 bytes
// Doc: rf_msg_process_body_c22 [rf]: Process RF message body handler
// rf_msg_process_body_c22 [rf]: Process RF message body handler
int  sub_113C20(int a1)
{
  uint8_t *v1; // r2
  char v2; // r3

  rf_msg_process_init(a1);
  v1 = rf_msg_process_body_n_4;
  v2 = *((uint8_t *)off_113C3C + 352);
  *(uint8_t *)rf_msg_process_body_n_8 = *((uint8_t *)off_113C3C + 326);
  *v1 = v2;
  return 1;
}

