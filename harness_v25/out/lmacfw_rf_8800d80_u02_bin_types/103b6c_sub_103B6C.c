// sub_103B6C @ 0x103b6c, size 214 bytes
uint32_t *sub_103B6C()
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

  v0 = (unsigned int *)off_103C44;
  v1 = (unsigned int *)off_103C48;
  v2 = off_103C4C;
  v3 = off_103C50;
  v4 = off_103C54;
  v5 = (unsigned int *)off_103C58;
  *(uint32_t *)off_103C44 &= ~0x200u;
  *v1 = *v1 & 0xFC000FFF | 0x333000;
  *v2 = 8;
  *v3 |= 0x1000000u;
  v0 -= 136;
  *v4 |= 0x2000000u;
  *v0 &= ~0x20000u;
  sub_100560(2);
  v6 = off_103C5C;
  result = off_103C60;
  v8 = off_103C64;
  *v0 |= 0x10000u;
  *v0 |= 0x20000u;
  *v0 = *v0 & 0xFFFF0FFF | 0x6000;
  *v0 |= 0x80000u;
  v9 = dword_103C68;
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

