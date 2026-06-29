// sub_135564 @ 0x135564, size 48 bytes
uint32_t * sub_135564(__int16 a1)
{
  int v2; // r5
  int v3; // r0

  v2 = *((uint32_t *)off_135594 + 4);
  v3 = sub_12C92C(30, 0, 6, 4u);
  *(uint16_t *)v3 = a1;
  *(uint8_t *)(v3 + 2) = 1;
  *(uint8_t *)(v3 + 3) = *(uint8_t *)(v2 + 61);
  sub_12C98C(v3);
  return sub_12CD34(6u, 9);
}

