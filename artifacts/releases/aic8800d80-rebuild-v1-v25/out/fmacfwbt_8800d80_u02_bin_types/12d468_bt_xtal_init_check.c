// bt_xtal_init_check @ 0x12d468, size 8 bytes
// Doc: bt_xtal_init_check [bt]: Initialize structure to zero then check XTAL status flag
// bt_xtal_init_check [bt]: Initialize structure to zero then check XTAL status flag
uint32_t * bt_xtal_init_check(uint32_t *result)
{
  *result = 0;
  result[1] = 0;
  return result;
}

