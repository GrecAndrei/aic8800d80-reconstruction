// sub_13A370 @ 0x13a370, size 36 bytes
uint16_t * sub_13A370(uint16_t *result)
{
  uint16_t *v1; // r3

  v1 = off_13A394;
  if ( !*((uint8_t *)off_13A394 + 115) )
  {
    *((uint16_t *)off_13A394 + 54) = *result;
    v1[55] = result[1];
    v1[56] = result[2];
    v1[57] = 256;
  }
  return result;
}

