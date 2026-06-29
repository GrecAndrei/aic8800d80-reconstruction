// bt_fw_init_or_handler @ 0x1029c4, size 16 bytes
// Doc: bt_fw_init_or_handler [bt]: Bluetooth firmware init/handler routine
// bt_fw_init_or_handler [bt]: Bluetooth firmware init/handler routine
uint8_t * bt_fw_init_or_handler(uint8_t *result, uint8_t *a2)
{
  uint8_t *v2; // r3

  v2 = off_1029D4;
  *result = *((uint8_t *)off_1029D4 + 294);
  *a2 = v2[295];
  return result;
}

