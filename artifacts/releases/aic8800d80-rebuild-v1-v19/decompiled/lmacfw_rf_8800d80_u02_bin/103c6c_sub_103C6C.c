// sub_103C6C @ 0x103c6c, size 220 bytes
unsigned int *sub_103C6C()
{
  unsigned int *v0; // r1
  _DWORD *v1; // r0
  unsigned int *v2; // r2
  _DWORD *v3; // r6
  _DWORD *v4; // r5
  _DWORD *v5; // r4
  unsigned int *result; // r0

  v0 = (unsigned int *)off_103D48;
  v1 = off_103D4C;
  v2 = (unsigned int *)off_103D50;
  *(_DWORD *)off_103D48 &= ~0x10000000u;
  v3 = off_103D54;
  v4 = off_103D58;
  v5 = off_103D5C;
  *v1 &= ~0x200u;
  *v0 = *v0 & 0xFC000FFF | 0x333000;
  *v3 = 0;
  *v4 &= ~0x1000000u;
  *v2 = *v2 & 0xFFFF0FFF | 0xA000;
  *v2 &= ~0x20000u;
  *v2 &= ~0x10000u;
  *v2 &= ~0x80000u;
  *v5 &= ~0x20000000u;
  result = v1 - 138;
  *v5 &= ~0x10000000u;
  v4 += 2046;
  *result &= 0xE7FFFFFF;
  *v4 &= ~0x2000000u;
  v2[8] = v2[8] & 0xFC00FFFF | 0x100000;
  v5[23] &= ~0x80u;
  v4[48] &= ~8u;
  *v0 = *v0 & 0xFFFFF000 | 0x80;
  *result = *result & 0xF8FFFFFF | 0x5000000;
  *(unsigned int *)((char *)v2 + 0xFFFFFFD8) &= ~0x1000000u;
  return result;
}

