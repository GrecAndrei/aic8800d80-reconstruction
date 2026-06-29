// sub_11C3A4 @ 0x11c3a4, size 16 bytes
uint8_t * sub_11C3A4(uint8_t *result)
{
  uint8_t *v1; // r3

  v1 = off_11C3B4;
  *((uint8_t *)off_11C3B4 + 164) = *result;
  v1[165] = result[1];
  return result;
}

