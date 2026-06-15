// v23 annotated: sub_103AFC @ 0x103afc
// Original: 103afc_sub_103AFC.c
// Primary struct: <unclustered>
//
// sub_103AFC @ 0x103afc, size 66 bytes
int sub_103AFC()
{
  _DWORD *v0; // r0
  _DWORD *v1; // r1
  _DWORD *v2; // r2

  v0 = off_103B44;
  v1 = off_103B48;
  v2 = off_103B4C;
  *(_DWORD *)off_103B40 &= 0xFFFFFA53;
  *v0 &= ~0x20000u;
  *v1 &= ~0x1000000u;
  *v2 &= 0xFFE7FFFF;
  sub_100644(10);
  return sub_12EB90(0x2000, dword_103B50);
}

