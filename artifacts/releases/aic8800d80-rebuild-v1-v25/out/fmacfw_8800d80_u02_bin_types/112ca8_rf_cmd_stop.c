// rf_cmd_stop @ 0x112ca8, size 48 bytes
// Doc: rf_cmd_wait_n_2a6 [rf]: Wait for RF command completion by polling status register
// rf_cmd_wait_n_2a6 [rf]: Wait for RF command completion by polling status register
uint8_t * rf_cmd_stop(int a1, int a2, int a3)
{
  uint8_t *result; // r0
  uint32_t *v4; // r2

  if ( (*((uint16_t *)rf_cmd_wait_cd8 + 89) & 0x4000) != 0 )
    result = uart_puts((uint8_t *)rf_bus_reset_n300);
  else
    result = (uint8_t *)msg_parse(dword_112CDC, a2, a3);
  v4 = rf_bus_reset_n2fc;
  *(uint8_t *)rf_state_check_n2f2 = 0;
  v4[896] &= ~1u;
  return result;
}

