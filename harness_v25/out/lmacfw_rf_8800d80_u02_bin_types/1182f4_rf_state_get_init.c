// rf_state_get_init @ 0x1182f4, size 22 bytes
// Doc: rf_state_get_init [rf]: Get pointer to RF state structure
// rf_state_get_init [rf]: Get pointer to RF state structure
int rf_state_get_init()
{
  uint32_t *i; // r4
  int result; // r0

  for ( i = *((uint32_t **)off_11830C + 2); i; i = (uint32_t *)*i )
    result = rf_init_or_setup_n32c((int)i);
  return result;
}

