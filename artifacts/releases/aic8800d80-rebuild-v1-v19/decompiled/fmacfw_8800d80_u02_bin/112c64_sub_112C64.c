// sub_112C64 @ 0x112c64, size 40 bytes
// Doc: rf_level_apply_2c86 [rf]: Apply RF TX power level adjustment
// rf_level_apply_2c86 [rf]: Apply RF TX power level adjustment
_BYTE *__fastcall sub_112C64(int a1, int a2, int a3)
{
  _BYTE *result; // r0

  if ( (*((_WORD *)off_112C8C + 89) & 0x4000) != 0 )
    result = uart_puts((_BYTE *)rf_cmd_send_378);
  else
    result = (_BYTE *)msg_parse(dword_112C90, a2, a3);
  *(_BYTE *)rf_msg_handler_n_470_2c94 = 1;
  return result;
}

