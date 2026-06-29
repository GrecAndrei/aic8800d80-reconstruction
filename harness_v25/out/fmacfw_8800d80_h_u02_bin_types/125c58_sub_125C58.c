// sub_125C58 @ 0x125c58, size 42 bytes
int  sub_125C58(int a1)
{
  uint8_t *v2; // r0
  uint32_t *v3; // r2

  v2 = (uint8_t *)sub_12C7EC(72, *(unsigned __int16 *)(a1 + 14), 0, 2);
  v2[1] = *(uint8_t *)(a1 + 24);
  v3 = off_125C84;
  *v2 = *(uint8_t *)(a1 + 26);
  *v3 &= ~4u;
  return sub_12C84C(v2);
}

