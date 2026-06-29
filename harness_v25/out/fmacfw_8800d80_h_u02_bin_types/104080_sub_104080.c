// sub_104080 @ 0x104080, size 214 bytes
uint32_t *sub_104080()
{
  unsigned int *v0; // r4
  unsigned int *v1; // r0
  uint32_t *v2; // r5
  uint32_t *v3; // r1
  uint32_t *v4; // r2
  unsigned int *v5; // r6
  uint32_t *v6; // r1
  uint32_t *result; // r0
  uint32_t *v8; // r2
  int v9; // r4

  v0 = (unsigned int *)off_104158;
  v1 = (unsigned int *)off_10415C;
  v2 = off_104160;
  v3 = off_104164;
  v4 = off_104168;
  v5 = (unsigned int *)off_10416C;
  *(uint32_t *)off_104158 &= ~0x200u;
  *v1 = *v1 & 0xFC000FFF | 0x333000;
  *v2 = 8;
  *v3 |= 0x1000000u;
  v0 -= 136;
  *v4 |= 0x2000000u;
  *v0 &= ~0x20000u;
  sub_100644(2);
  v6 = off_104170;
  result = off_104174;
  v8 = off_104178;
  *v0 |= 0x10000u;
  *v0 |= 0x20000u;
  *v0 = *v0 & 0xFFFF0FFF | 0x6000;
  *v0 |= 0x80000u;
  v9 = dword_10417C;
  *v6 |= 0x80u;
  *result |= 8u;
  *v5 = *v5 & 0xFFFFF3FF | 0x800;
  *(uint32_t *)((char *)v2 + 0xFFFFFFF0) = *(uint32_t *)((char *)v2 + 0xFFFFFFF0) & 0xF8FFFFFF | 0x6000000;
  *v8 |= 0x20000000u;
  *v8 &= ~0x10000000u;
  v6[104] |= 0x80000000;
  *(uint32_t *)((char *)result + 0xFFFFFF68) = v9;
  *(uint32_t *)((char *)v2 + 0xFFFFFFD0) |= 0x1000000u;
  return result;
}

