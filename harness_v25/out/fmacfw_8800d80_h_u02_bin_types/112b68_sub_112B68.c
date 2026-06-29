// sub_112B68 @ 0x112b68, size 48 bytes
uint8_t * sub_112B68(int a1, int a2, int a3)
{
  uint8_t *result; // r0
  uint32_t *v4; // r2

  if ( (*((uint16_t *)off_112B98 + 89) & 0x4000) != 0 )
    result = sub_10D674((uint8_t *)dword_112BA8);
  else
    result = (uint8_t *)sub_12E948(dword_112B9C, a2, a3);
  v4 = off_112BA4;
  *(uint8_t *)off_112BA0 = 0;
  v4[896] &= ~1u;
  return result;
}

