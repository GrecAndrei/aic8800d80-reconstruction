// v23 annotated: sub_10D1A8 @ 0x10d1a8
// Original: 10d1a8_sub_10D1A8.c
// Primary struct: <unclustered>
//
// sub_10D1A8 @ 0x10d1a8, size 70 bytes
int sub_10D1A8()
{
  _DWORD *v0; // r1
  _DWORD *v1; // r4
  _DWORD *v2; // r3

  v0 = off_10D1F0;
  v1 = off_10D1F4;
  v2 = off_10D1F8;
  *(_DWORD *)off_10D1F4 = 13369344;
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

