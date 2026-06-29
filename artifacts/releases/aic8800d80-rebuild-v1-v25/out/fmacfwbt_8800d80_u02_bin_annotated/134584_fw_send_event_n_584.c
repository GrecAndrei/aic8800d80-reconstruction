// fwstruct annotate: 134584_fw_send_event_n_584.c
// fw_send_event_n_584 @ 0x134584, size 26 bytes
// Doc: fw_send_event_n_584 [util]: Sends a firmware event/log message with code 0x180b
// fw_send_event_n_584 [util]: Sends a firmware event/log message with code 0x180b
int fw_send_event_n_584()
{
  int result; // r0

  sub_12ECB0(dword_1345A0);
  result = sub_12C964(6155, 6);
  *(_BYTE *)(loc_1345A4 + 0xF) = 0;
  return result;
}

