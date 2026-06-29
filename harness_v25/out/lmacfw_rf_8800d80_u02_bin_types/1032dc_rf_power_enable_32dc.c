// rf_power_enable_32dc @ 0x1032dc, size 78 bytes
// Doc: rf_power_enable_32dc [rf]: Enable RF power via control byte
// rf_power_enable_32dc [rf]: Enable RF power via control byte
unsigned int  rf_power_enable_32dc(unsigned int result)
{
  if ( result )
  {
    if ( *((uint8_t *)off_10332C + 362) )
      result = sub_1029DC(0xB5u);
    *(uint32_t *)off_103330 |= 2u;
  }
  else
  {
    if ( *((uint8_t *)off_10332C + 362) )
      result = sub_1029DC(0xC2u);
    *(uint32_t *)off_103330 &= ~2u;
  }
  return result;
}

