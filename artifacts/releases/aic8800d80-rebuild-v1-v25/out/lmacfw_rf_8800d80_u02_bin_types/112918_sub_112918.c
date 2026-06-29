// sub_112918 @ 0x112918, size 100 bytes
int  sub_112918(int a1, unsigned __int16 *a2)
{
  int v4; // r2
  int v5; // r3
  int v6; // r2

  sub_112878();
  if ( *(uint8_t *)off_11297C != 4 )
    return 1;
  v4 = a1 - 1;
  if ( (unsigned __int8)(a1 - 1) > 5u )
    return 2;
  if ( (*((uint32_t *)&REG_4020_0900 + 8 * a1) & 0x8000) == 0 )
    return 5;
  v5 = 32 * v4 + 0x40000000;
  v6 = dword_112980 + 16 * v4;
  *(uint32_t *)(v6 + 4) = *a2;
  *(uint8_t *)(v6 + 11) = 1;
  *(uint32_t *)(v5 + 2099508) = a2;
  *((uint32_t *)&REG_4020_0900 + 8 * a1) |= 0x84000000;
  return 0;
}

