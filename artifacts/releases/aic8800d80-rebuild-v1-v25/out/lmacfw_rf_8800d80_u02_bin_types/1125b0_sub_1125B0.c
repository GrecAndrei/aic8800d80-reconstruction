// sub_1125B0 @ 0x1125b0, size 48 bytes
// Doc: rf_cmd_send_n_360 [rf]: Send RF command to hardware queue
// rf_cmd_send_n_360 [rf]: Send RF command to hardware queue
uint8_t * sub_1125B0(int a1, int a2)
{
  uint8_t *result; // r0
  uint32_t *v3; // r2

  if ( (*((uint16_t *)rf_cmd_send_n_338 + 89) & 0x4000) != 0 )
    result = uart_puts((uint8_t *)dword_1125F0);
  else
    result = (uint8_t *)msg_parse(rf_bus_reset_n2f4, a2);
  v3 = rf_cmd_send_n_32c;
  *(uint8_t *)rf_bus_reset_n2f8_0 = 0;
  v3[896] &= ~1u;
  return result;
}

