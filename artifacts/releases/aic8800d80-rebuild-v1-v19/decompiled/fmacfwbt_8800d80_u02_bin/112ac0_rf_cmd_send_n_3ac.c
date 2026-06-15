// rf_cmd_send_n_3ac @ 0x112ac0, size 40 bytes
// Doc: rf_msg_handler_n_49e [rf]: Handles RF subsystem messages from host
// rf_msg_handler_n_49e [rf]: Handles RF subsystem messages from host
_BYTE *__fastcall rf_cmd_send_n_3ac(int a1, int a2, int a3)
{
  _BYTE *result; // r0

  if ( (*((_WORD *)rf_msg_handler_n_478 + 89) & 0x4000) != 0 )
    result = sub_10D60C((_BYTE *)dword_112AF4);
  else
    result = (_BYTE *)sub_12ECB0(rf_msg_handler_n_474, a2, a3);
  *(_BYTE *)rf_msg_handler_n_470 = 1;
  return result;
}

