// sub_1296EC @ 0x1296ec, size 86 bytes
int sub_1296EC()
{
  int v0; // r1
  uint32_t *v1; // r0
  uint32_t *v2; // r1
  uint32_t *v3; // r5
  uint32_t *v4; // r2

  v0 = dword_12974C;
  *(uint32_t *)off_129744 |= 0x2000000u;
  feature_guard_sdio(2, v0);
  if ( !*((uint8_t *)off_129750 + 18) )
    *(uint32_t *)off_129754 &= ~1u;
  v1 = off_12975C;
  v2 = off_129754;
  v3 = off_129760;
  v4 = off_129764;
  *(uint32_t *)off_129758 &= ~0x10000u;
  *v1 &= ~0x40000000u;
  *v2 &= ~0x10000000u;
  *v3 = 0;
  *v4 &= ~1u;
  return 0;
}

