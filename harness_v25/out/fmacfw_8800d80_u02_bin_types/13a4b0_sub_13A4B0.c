// sub_13A4B0 @ 0x13a4b0, size 36 bytes
uint16_t * sub_13A4B0(uint16_t *result)
{
  uint16_t *v1; // r3

  v1 = off_13A4D4;
  if ( !*((uint8_t *)off_13A4D4 + 115) )
  {
    *((uint16_t *)off_13A4D4 + 54) = *result;
    v1[55] = result[1];
    v1[56] = result[2];
    v1[57] = 256;
  }
  return result;
}

