// sub_13684C @ 0x13684c, size 58 bytes
uint32_t *sub_13684C()
{
  int v0; // r4
  int v1; // r0
  __int16 v2; // r1
  __int16 v3; // r2

  v0 = *(uint32_t *)off_136888;
  v1 = sub_12C7EC(63, 0, 7, 0xCu);
  v2 = *(uint16_t *)(v0 + 36);
  v3 = *(uint16_t *)(v0 + 38);
  *(uint32_t *)v1 = *(uint32_t *)(v0 + 32);
  *(uint16_t *)(v1 + 4) = v2;
  *(uint16_t *)(v1 + 6) = v3;
  *(uint8_t *)(v1 + 8) = *(uint8_t *)(v0 + 50);
  *(uint8_t *)(v1 + 9) = *(uint8_t *)(v0 + 51);
  sub_12C84C(v1);
  return sub_12CBF4(7u, 2);
}

