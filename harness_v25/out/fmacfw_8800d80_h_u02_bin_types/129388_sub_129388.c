// sub_129388 @ 0x129388, size 86 bytes
int sub_129388()
{
  int v0; // r1
  uint32_t *v1; // r0
  uint32_t *v2; // r1
  uint32_t *v3; // r5
  uint32_t *v4; // r2

  v0 = dword_1293E8;
  *(uint32_t *)off_1293E0 |= 0x2000000u;
  sub_12EB90(2, v0);
  if ( !*((uint8_t *)off_1293EC + 18) )
    *(uint32_t *)off_1293F0 &= ~1u;
  v1 = off_1293F8;
  v2 = off_1293F0;
  v3 = off_1293FC;
  v4 = off_129400;
  *(uint32_t *)off_1293F4 &= ~0x10000u;
  *v1 &= ~0x40000000u;
  *v2 &= ~0x10000000u;
  *v3 = 0;
  *v4 &= ~1u;
  return 0;
}

