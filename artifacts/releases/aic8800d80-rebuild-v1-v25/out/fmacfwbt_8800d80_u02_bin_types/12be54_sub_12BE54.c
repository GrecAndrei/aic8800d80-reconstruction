// sub_12BE54 @ 0x12be54, size 110 bytes
unsigned int sub_12BE54()
{
  uint32_t *v0; // r2
  uint32_t *v1; // r0
  __int16 **v2; // r5
  int *v3; // r4
  int v4; // r3
  __int16 *v5; // r2
  unsigned int result; // r0
  uint32_t *v7; // r2

  v0 = off_12BEC4;
  v1 = off_12BEC8;
  *(uint32_t *)off_12BEC4 &= ~1u;
  v2 = (__int16 **)off_12BECC;
  v3 = (int *)off_12BED0;
  v4 = dword_12BED4;
  *v0 &= ~2u;
  *v1 |= 0x700u;
  v5 = *v2;
  *v3 = v4;
  if ( *v5 < 0 && *(uint32_t *)off_12BEDC << 28 )
  {
    sub_12F6C4(dword_12BEE4, dword_12BEE0, 472);
    v4 = *v3;
  }
  *(uint32_t *)off_12BED8 = v4 | v3[1];
  result = sub_11E4C0(1);
  v7 = off_12BEC8;
  *(uint32_t *)off_12BEC8 = *(uint32_t *)off_12BEC8 & 0xFFFE3FFF | 0x10000;
  *v7 |= 0x2000u;
  return result;
}

