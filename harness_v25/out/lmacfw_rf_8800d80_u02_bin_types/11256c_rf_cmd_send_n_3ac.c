// rf_cmd_send_n_3ac @ 0x11256c, size 40 bytes
// Doc: rf_fault_dump [rf]: Dumps RF fault state for diagnostic logging
// rf_fault_dump [rf]: Dumps RF fault state for diagnostic logging
uint8_t * rf_cmd_send_n_3ac(int a1, int a2)
{
  uint8_t *result; // r0

  if ( (*((uint16_t *)rf_bus_reset_n2a4 + 89) & 0x4000) != 0 )
    result = uart_puts((uint8_t *)fmac_chan_set_or_init);
  else
    result = (uint8_t *)msg_parse(dword_112598, a2);
  *(uint8_t *)rf_cmd_send_n_37c = 1;
  return result;
}

