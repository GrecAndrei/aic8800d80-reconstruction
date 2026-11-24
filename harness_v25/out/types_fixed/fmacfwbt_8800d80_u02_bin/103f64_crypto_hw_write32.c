// crypto_hw_write32 @ 0x103f64, size 126 bytes
// Doc: crypto_hw_write32 [ke]: Write 32-bit value to hardware crypto engine register with IRQ mask
// crypto_hw_write32 [ke]: Write 32-bit value to hardware crypto engine register with IRQ mask
unsigned int __fastcall crypto_hw_write32(int a1, int a2)
{
  unsigned int *v2; // r2
  unsigned int *v3; // r3
  int v4; // r4
  _DWORD *v5; // r6
  unsigned int result; // r0

  v2 = (unsigned int *)off_103FE4;
  v3 = (unsigned int *)off_103FE8;
  v4 = *(_DWORD *)off_103FE4;
  v5 = off_103FEC;
  *(_DWORD *)off_103FE4 |= 0x1000000u;
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

