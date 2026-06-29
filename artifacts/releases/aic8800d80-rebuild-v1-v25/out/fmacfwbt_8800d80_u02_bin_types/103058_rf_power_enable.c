// rf_power_enable @ 0x103058, size 78 bytes
// Doc: rf_power_enable [rf]: Enable RF power (check/clear bit in power control reg)
// rf_power_enable [rf]: Enable RF power (check/clear bit in power control reg)
unsigned int  rf_power_enable(unsigned int result)
{
  if ( result )
  {
    if ( *((uint8_t *)off_1030A8 + 362) )
      result = rf_power_set(0xB5u);
    *(uint32_t *)off_1030AC |= 2u;
  }
  else
  {
    if ( *((uint8_t *)off_1030A8 + 362) )
      result = rf_power_set(0xC2u);
    *(uint32_t *)off_1030AC &= ~2u;
  }
  return result;
}

