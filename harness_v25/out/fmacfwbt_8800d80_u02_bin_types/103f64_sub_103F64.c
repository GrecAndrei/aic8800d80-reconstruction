// sub_103F64 @ 0x103f64, size 126 bytes
unsigned int  sub_103F64(int a1, int a2)
{
  unsigned int *v2; // r2
  unsigned int *v3; // r3
  int v4; // r4
  uint32_t *v5; // r6
  unsigned int result; // r0

  v2 = (unsigned int *)off_103FE4;
  v3 = (unsigned int *)off_103FE8;
  v4 = *(uint32_t *)off_103FE4;
  v5 = off_103FEC;
  *(uint32_t *)off_103FE4 |= 0x1000000u;
  *v3 |= 0x8000u;
  *v3 &= ~0x400000u;
  *v3 &= ~0x200000u;
  *v3 |= 0x200000u;
  *v5 = a2;
  result = (a1 << 16) & 0x1F0000 | *v3 & 0xFFE0FFFF;
  *v3 = result;
  *v3 &= ~0x200000u;
  *v3 |= 0x200000u;
  *v3 &= ~0x8000u;
  *v3 |= 0x400000u;
  *v3 |= 0x200000u;
  *v2 = v4 & 0x1000000 | *v2 & 0xFEFFFFFF;
  return result;
}

