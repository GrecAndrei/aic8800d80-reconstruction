// v23 annotated: sub_10DCE8 @ 0x10dce8
// Original: 10dce8_sub_10DCE8.c
// Primary struct: rf_subsys (cluster 9, 12 funcs)
// Fields: base=0x8, cfg=0xc
//
// sub_10DCE8 @ 0x10dce8, size 48 bytes
int sub_10DCE8()
{
  int result; // r0
  _DWORD *v1; // r3

  result = sub_10EFB4(dword_10DD18, 4096, 15360);
  v1 = off_10DD1C;
  *((_DWORD *)off_10DD1C + 2) |= 0xFu;
  v1[2] |= 0x10000000u;
  v1[3] &= 0xFFFFF7FE;
  return result;
}

