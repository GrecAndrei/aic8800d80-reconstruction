// sub_13BC20 @ 0x13bc20, size 64 bytes
int  sub_13BC20(char a1, int a2)
{
  int v2; // r4
  int v4; // r0
  int v5; // r1
  int v6; // r2

  v2 = a2;
  v4 = sub_12C7EC(40, 0, ((uint16_t)a2 << 8) | 8, 8u);
  v5 = dword_13BC60 + 32 * v2;
  v6 = *(unsigned __int8 *)(v5 + 17);
  *(uint8_t *)(v4 + 1) = a1;
  *(uint8_t *)v4 = v6 != 1;
  *(uint8_t *)(v4 + 2) = *(uint8_t *)(v5 + 22);
  LOWORD(v2) = *(uint16_t *)(v5 + 20);
  *(uint16_t *)(v4 + 6) = *(uint16_t *)(v5 + 12);
  *(uint16_t *)(v4 + 4) = v2;
  return sub_12C84C(v4);
}

