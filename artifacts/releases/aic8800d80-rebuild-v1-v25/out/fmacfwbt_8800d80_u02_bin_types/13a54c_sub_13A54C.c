// sub_13A54C @ 0x13a54c, size 36 bytes
uint16_t * sub_13A54C(uint16_t *result)
{
  uint16_t *v1; // r3

  v1 = off_13A570;
  if ( !*((uint8_t *)off_13A570 + 115) )
  {
    *((uint16_t *)off_13A570 + 54) = *result;
    v1[55] = result[1];
    v1[56] = result[2];
    v1[57] = 256;
  }
  return result;
}

