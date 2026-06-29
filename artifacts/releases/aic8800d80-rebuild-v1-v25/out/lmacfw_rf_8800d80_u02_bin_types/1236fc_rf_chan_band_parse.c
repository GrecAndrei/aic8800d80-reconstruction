// rf_chan_band_parse @ 0x1236fc, size 52 bytes
// Doc: rf_chan_band_parse [rf]: Parse channel/band byte fields from descriptor
// rf_chan_band_parse [rf]: Parse channel/band byte fields from descriptor
uint8_t * rf_chan_band_parse(uint8_t *result)
{
  uint8_t *v1; // r3
  char v2; // r1
  char v3; // r2

  if ( *result == 2 )
  {
    if ( *(unsigned __int8 *)off_123730 == (unsigned __int8)result[1] )
    {
      v1 = off_123734;
      v2 = result[3];
      v3 = result[4];
      *((uint8_t *)off_123734 + 2) = result[2];
      v1[3] = v2;
      v1[4] = v3;
    }
    return (uint8_t *)mmio_write_40320150(*(uint32_t *)off_123738 + 20000);
  }
  return result;
}

