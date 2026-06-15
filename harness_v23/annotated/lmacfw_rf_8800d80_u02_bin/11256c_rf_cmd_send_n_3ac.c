// v23 annotated: rf_cmd_send_n_3ac @ 0x11256c
// Original: 11256c_rf_cmd_send_n_3ac.c
// Primary struct: <unclustered>
//
// rf_cmd_send_n_3ac @ 0x11256c, size 40 bytes
// Doc: rf_fault_dump [rf]: Dumps RF fault state for diagnostic logging
// rf_fault_dump [rf]: Dumps RF fault state for diagnostic logging
_BYTE *__fastcall rf_cmd_send_n_3ac(int a1, int a2)
{
  _BYTE *result; // r0

  if ( (*((_WORD *)rf_bus_reset_n2a4 + 89) & 0x4000) != 0 )
    result = uart_puts((_BYTE *)fmac_chan_set_or_init);
  else
    result = (_BYTE *)msg_parse(dword_112598, a2);
  *(_BYTE *)rf_cmd_send_n_37c = 1;
  return result;
}

