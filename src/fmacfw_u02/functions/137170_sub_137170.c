// rf_set_config_803 @ 0x137170, size 40 bytes
int rf_set_config_803()
{
  int v0; // r0
  int value; // r0

  v0 = ke_msg_alloc(2051, 2, 4, 1u);
  ke_msg_send(v0);
  value = rx_rate_field_parse(4u);
  check_status_bits(8, dword_137198, value);
  return 0;
}

