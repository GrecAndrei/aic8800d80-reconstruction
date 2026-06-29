// sub_1294C8 @ 0x1294c8, size 86 bytes
int sub_1294C8()
{
  int v0; // r1
  uint32_t *v1; // r0
  uint32_t *v2; // r1
  uint32_t *v3; // r5
  uint32_t *v4; // r2

  v0 = dword_129528;
  *(uint32_t *)off_129520 |= 0x2000000u;
  feature_guard_check(2, v0);
  if ( !*((uint8_t *)off_12952C + 18) )
    *(uint32_t *)off_129530 &= ~1u;
  v1 = off_129538;
  v2 = off_129530;
  v3 = off_12953C;
  v4 = off_129540;
  *(uint32_t *)off_129534 &= ~0x10000u;
  *v1 &= ~0x40000000u;
  *v2 &= ~0x10000000u;
  *v3 = 0;
  *v4 &= ~1u;
  return 0;
}

