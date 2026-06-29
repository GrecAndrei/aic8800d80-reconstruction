// sub_11C924 @ 0x11c924, size 16 bytes
uint8_t * sub_11C924(uint8_t *result)
{
  uint8_t *v1; // r3

  v1 = off_11C934;
  *((uint8_t *)off_11C934 + 164) = *result;
  v1[165] = result[1];
  return result;
}

