// v23 annotated: sub_103C14 @ 0x103c14
// Original: 103c14_sub_103C14.c
// Primary struct: <unclustered>
//
// sub_103C14 @ 0x103c14, size 66 bytes
int sub_103C14()
{
  _DWORD *v0; // r0
  _DWORD *v1; // r1
  _DWORD *v2; // r2

  v0 = off_103C5C;
  v1 = off_103C60;
  v2 = off_103C64;
  *(_DWORD *)off_103C58 &= 0xFFFFFA53;
  *v0 &= ~0x20000u;
  *v1 &= ~0x1000000u;
  *v2 &= 0xFFE7FFFF;
  delay_us_0644(10);
  return feature_guard_check(0x2000, dword_103C68);
}

