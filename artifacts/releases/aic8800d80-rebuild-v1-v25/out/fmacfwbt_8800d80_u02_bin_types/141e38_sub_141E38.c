// sub_141E38 @ 0x141e38, size 50 bytes
int  sub_141E38(char a1, int a2)
{
  int v4; // r0
  __int16 v5; // r2

  v4 = sub_12CB54(12290, 13, 12, 8u);
  v5 = *(uint16_t *)(a2 + 8);
  *(uint32_t *)(v4 + 2) = *(uint32_t *)(a2 + 4);
  *(uint16_t *)(v4 + 6) = v5;
  *(uint8_t *)(v4 + 1) = *(uint8_t *)(a2 + 46);
  *(uint8_t *)v4 = a1;
  return sub_12CBB4(v4);
}

