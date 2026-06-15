// crypto_hw_reset_seq @ 0x103ff0, size 214 bytes
// Doc: crypto_hw_reset_seq [ke]: Crypto engine hardware reset sequence across MMIO registers
// crypto_hw_reset_seq [ke]: Crypto engine hardware reset sequence across MMIO registers
_DWORD *crypto_hw_reset_seq()
{
  unsigned int *v0; // r4
  unsigned int *v1; // r0
  _DWORD *v2; // r5
  _DWORD *v3; // r1
  _DWORD *v4; // r2
  unsigned int *v5; // r6
  _DWORD *v6; // r1
  _DWORD *result; // r0
  _DWORD *v8; // r2
  int v9; // r4

  v0 = (unsigned int *)off_1040C8;
  v1 = (unsigned int *)off_1040CC;
  v2 = off_1040D0;
  v3 = off_1040D4;
  v4 = off_1040D8;
  v5 = (unsigned int *)off_1040DC;
  *(_DWORD *)off_1040C8 &= ~0x200u;
  *v1 = *v1 & 0xFC000FFF | 0x333000;
  *v2 = 8;
  *v3 |= 0x1000000u;
  v0 -= 136;
  *v4 |= 0x2000000u;
  *v0 &= ~0x20000u;
  delay_us(2);
  v6 = off_1040E0;
  result = off_1040E4;
  v8 = off_1040E8;
  *v0 |= 0x10000u;
  *v0 |= 0x20000u;
  *v0 = *v0 & 0xFFFF0FFF | 0x6000;
  *v0 |= 0x80000u;
  v9 = dword_1040EC;
  *v6 |= 0x80u;
  *result |= 8u;
  *v5 = *v5 & 0xFFFFF3FF | 0x800;
  *(_DWORD *)((char *)v2 + 0xFFFFFFF0) = *(_DWORD *)((char *)v2 + 0xFFFFFFF0) & 0xF8FFFFFF | 0x6000000;
  *v8 |= 0x20000000u;
  *v8 &= ~0x10000000u;
  v6[104] |= 0x80000000;
  *(_DWORD *)((char *)result + 0xFFFFFF68) = v9;
  *(_DWORD *)((char *)v2 + 0xFFFFFFD0) |= 0x1000000u;
  return result;
}

