// sub_112B24 @ 0x112b24, size 40 bytes
uint8_t * sub_112B24(int a1, int a2, int a3)
{
  uint8_t *result; // r0

  if ( (*((uint16_t *)off_112B4C + 89) & 0x4000) != 0 )
    result = sub_10D674((uint8_t *)dword_112B58);
  else
    result = (uint8_t *)sub_12E948(dword_112B50, a2, a3);
  *(uint8_t *)off_112B54 = 1;
  return result;
}

