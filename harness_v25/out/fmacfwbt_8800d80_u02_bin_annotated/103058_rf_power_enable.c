// fwstruct annotate: 103058_rf_power_enable.c
// rf_power_enable @ 0x103058, size 78 bytes
// Doc: rf_power_enable [rf]: Enable RF power (check/clear bit in power control reg)
// rf_power_enable [rf]: Enable RF power (check/clear bit in power control reg)
unsigned int __fastcall rf_power_enable(unsigned int result)
{
  if ( result )
  {
    if ( *((_BYTE *)off_1030A8 + 362) )
      result = rf_power_set(0xB5u);
    *(_DWORD *)off_1030AC |= 2u;
  }
  else
  {
    if ( *((_BYTE *)off_1030A8 + 362) )
      result = rf_power_set(0xC2u);
    *(_DWORD *)off_1030AC &= ~2u;
  }
  return result;
}

