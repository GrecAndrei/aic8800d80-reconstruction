// fwstruct annotate: 10d000_sub_10D000.c
// sub_10D000 @ 0x10d000, size 70 bytes
int sub_10D000()
{
  _DWORD *v0; // r1
  _DWORD *v1; // r4
  _DWORD *v2; // r3

  v0 = off_10D048;
  v1 = off_10D04C;
  v2 = off_10D050;
  *(_DWORD *)off_10D04C = 13369344;
  *v0 = 13369344;
  *v2 &= 0xFFFFFFCF;
  *v2 &= 0xFFFFFF3F;
  *v2 &= 0xFFFFCFFF;
  *v2 &= 0xFFFF3FFF;
  *v1 = 0x8000000;
  *v0 = 0x8000000;
  *v2 &= 0xFF3FFFFF;
  return 0x8000000;
}

