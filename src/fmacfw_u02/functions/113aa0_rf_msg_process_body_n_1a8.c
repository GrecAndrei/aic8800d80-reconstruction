// bt_init @ 0x113aa0, size 18 bytes
// Doc: rf_msg_process_body_n_198 [rf]: Process RF message body variant 198
// rf_msg_process_body_n_198 [rf]: Process RF message body variant 198
int bt_init()
{
  int v0; // r1
  int v1; // r2

  irq_state_load(rf_msg_process_body_alt);
  event_dispatch(rf_msg_process_body_n_18f, v0, v1);
  return 1;
}

