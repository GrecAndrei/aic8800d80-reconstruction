// sub_112B04 @ 0x112b04, size 48 bytes
uint8_t * sub_112B04(int a1, int a2, int a3)
{
  uint8_t *result; // r0
  uint32_t *v4; // r2

  if ( (*((uint16_t *)off_112B34 + 89) & 0x4000) != 0 )
    result = sub_10D60C((uint8_t *)dword_112B44);
  else
    result = (uint8_t *)sub_12ECB0(dword_112B38, a2, a3);
  v4 = off_112B40;
  *(uint8_t *)off_112B3C = 0;
  v4[896] &= ~1u;
  return result;
}

