// rf_cmd_send_n_438_4944 @ 0x124944, size 22 bytes
// Doc: rf_cmd_send_n_438_4944 [rf]: Sends RF command toggling control bits in 0x804
// rf_cmd_send_n_438_4944 [rf]: Sends RF command toggling control bits in 0x804
int rf_cmd_send_n_438_4944()
{
  msg_parse(dword_124964, *(uint32_t *)off_12495C, *(uint32_t *)off_124960 + *(uint32_t *)off_12495C);
  return 0;
}

