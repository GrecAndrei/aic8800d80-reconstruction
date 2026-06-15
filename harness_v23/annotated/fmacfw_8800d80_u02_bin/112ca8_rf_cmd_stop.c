// v23 annotated: rf_cmd_stop @ 0x112ca8
// Original: 112ca8_rf_cmd_stop.c
// Primary struct: <unclustered>
//
// rf_cmd_stop @ 0x112ca8, size 48 bytes
// Doc: rf_cmd_wait_n_2a6 [rf]: Wait for RF command completion by polling status register
// rf_cmd_wait_n_2a6 [rf]: Wait for RF command completion by polling status register
_BYTE *__fastcall rf_cmd_stop(int a1, int a2, int a3)
{
  _BYTE *result; // r0
  _DWORD *v4; // r2

  if ( (*((_WORD *)rf_cmd_wait_cd8 + 89) & 0x4000) != 0 )
    result = uart_puts((_BYTE *)rf_bus_reset_n300);
  else
    result = (_BYTE *)msg_parse(dword_112CDC, a2, a3);
  v4 = rf_bus_reset_n2fc;
  *(_BYTE *)rf_state_check_n2f2 = 0;
  v4[896] &= ~1u;
  return result;
}

