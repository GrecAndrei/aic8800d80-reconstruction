// sub_13C140 @ 0x13c140, size 108 bytes
int  sub_13C140(int a1, int a2)
{
  int v3; // r7
  int v5; // r4

  if ( a2 == 255 )
    return 2;
  v3 = dword_13C1AC;
  v5 = *(unsigned __int8 *)(696 * (unsigned __int8)a1 + 12 * (unsigned __int8)a2 + dword_13C1AC + 453);
  return v5 == 33
      || msg_get_value((v5 << 8) | 8) != 1
      || *(unsigned __int16 *)(dword_13C1B0 + 32 * v5 + 20) > ((*(uint16_t *)(v3 + 2 * (a2 + 348 * a1) + 316)
                                                              - *(uint16_t *)(*(uint32_t *)(dword_13C1B0 + 32 * v5 + 28) + 4))
                                                             & 0xFFFu);
}

