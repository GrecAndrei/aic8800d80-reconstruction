// sub_11C4E4 @ 0x11c4e4, size 16 bytes
uint8_t * sub_11C4E4(uint8_t *result)
{
  uint8_t *v1; // r3

  v1 = off_11C4F4;
  *((uint8_t *)off_11C4F4 + 164) = *result;
  v1[165] = result[1];
  return result;
}

