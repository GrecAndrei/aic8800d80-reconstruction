// sub_135780 @ 0x135780, size 48 bytes
uint32_t * sub_135780(__int16 a1)
{
  int v2; // r5
  int v3; // r0

  v2 = *((uint32_t *)off_1357B0 + 4);
  v3 = sub_12CB54(30, 0, 6, 4u);
  *(uint16_t *)v3 = a1;
  *(uint8_t *)(v3 + 2) = 1;
  *(uint8_t *)(v3 + 3) = *(uint8_t *)(v2 + 61);
  sub_12CBB4(v3);
  return sub_12CF5C(6u, 9);
}

