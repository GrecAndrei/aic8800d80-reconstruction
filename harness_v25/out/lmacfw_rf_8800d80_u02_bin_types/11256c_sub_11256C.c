// sub_11256C @ 0x11256c, size 40 bytes
uint8_t * sub_11256C(int a1, int a2)
{
  uint8_t *result; // r0

  if ( (*((uint16_t *)off_112594 + 89) & 0x4000) != 0 )
    result = sub_10D654((uint8_t *)dword_1125A0);
  else
    result = (uint8_t *)sub_11F504(dword_112598, a2);
  *(uint8_t *)off_11259C = 1;
  return result;
}

