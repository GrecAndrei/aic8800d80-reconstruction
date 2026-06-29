// sub_112AC0 @ 0x112ac0, size 40 bytes
uint8_t * sub_112AC0(int a1, int a2, int a3)
{
  uint8_t *result; // r0

  if ( (*((uint16_t *)off_112AE8 + 89) & 0x4000) != 0 )
    result = sub_10D60C((uint8_t *)dword_112AF4);
  else
    result = (uint8_t *)sub_12ECB0(dword_112AEC, a2, a3);
  *(uint8_t *)off_112AF0 = 1;
  return result;
}

