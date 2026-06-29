// sub_112CA8 @ 0x112ca8, size 48 bytes
uint8_t * sub_112CA8(int a1, int a2, int a3)
{
  uint8_t *result; // r0
  uint32_t *v4; // r2

  if ( (*((uint16_t *)off_112CD8 + 89) & 0x4000) != 0 )
    result = sub_10D7B4((uint8_t *)dword_112CE8);
  else
    result = (uint8_t *)sub_12EA88(dword_112CDC, a2, a3);
  v4 = off_112CE4;
  *(uint8_t *)off_112CE0 = 0;
  v4[896] &= ~1u;
  return result;
}

