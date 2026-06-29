// sub_119170 @ 0x119170, size 30 bytes
int  sub_119170(int a1)
{
  uint8_t *v2; // r0

  v2 = (uint8_t *)rf_setup_dispatch(67, 4, 0, 1);
  *v2 = *(uint8_t *)(a1 + 95);
  return sub_11DE50(v2);
}

