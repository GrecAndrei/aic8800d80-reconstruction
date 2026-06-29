// sub_135424 @ 0x135424, size 48 bytes
uint32_t * sub_135424(__int16 a1)
{
  int v2; // r5
  int v3; // r0

  v2 = *((uint32_t *)off_135454 + 4);
  v3 = sub_12C7EC(30, 0, 6, 4u);
  *(uint16_t *)v3 = a1;
  *(uint8_t *)(v3 + 2) = 1;
  *(uint8_t *)(v3 + 3) = *(uint8_t *)(v2 + 61);
  sub_12C84C(v3);
  return sub_12CBF4(6u, 9);
}

