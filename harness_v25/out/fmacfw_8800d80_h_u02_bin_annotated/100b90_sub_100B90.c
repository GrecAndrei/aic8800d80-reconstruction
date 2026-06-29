// fwstruct annotate: 100b90_sub_100B90.c
// sub_100B90 @ 0x100b90, size 60 bytes
_DWORD *sub_100B90()
{
  _DWORD *v0; // r3
  _DWORD *result; // r0
  _DWORD *v2; // r1
  _BYTE *v3; // r4

  v0 = off_100BD0;
  result = off_100BD4;
  v2 = off_100BD8;
  v3 = off_100BDC;
  *(_DWORD *)off_100BCC &= 0xFFFFF9FF;
  *v0 &= ~0x40000000u;
  *v0 &= ~0x80000000;
  *result &= ~0x1000u;
  *v2 &= 0xCFFFFFFF;
  *v3 = 0;
  return result;
}

