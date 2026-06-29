// rf_cmd_send_n_3ac @ 0x112ac0, size 40 bytes
// Doc: rf_msg_handler_n_49e [rf]: Handles RF subsystem messages from host
// rf_msg_handler_n_49e [rf]: Handles RF subsystem messages from host
uint8_t * rf_cmd_send_n_3ac(int a1, int a2, int a3)
{
  uint8_t *result; // r0

  if ( (*((uint16_t *)rf_msg_handler_n_478 + 89) & 0x4000) != 0 )
    result = sub_10D60C((uint8_t *)dword_112AF4);
  else
    result = (uint8_t *)sub_12ECB0(rf_msg_handler_n_474, a2, a3);
  *(uint8_t *)rf_msg_handler_n_470 = 1;
  return result;
}

