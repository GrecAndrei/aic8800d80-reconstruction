// v23 annotated: sub_103AC4 @ 0x103ac4
// Original: 103ac4_sub_103AC4.c
// Primary struct: <unclustered>
//
// sub_103AC4 @ 0x103ac4, size 50 bytes
int sub_103AC4()
{
  _DWORD *v0; // r4
  int result; // r0

  v0 = off_103AF8;
  *(_DWORD *)off_103AF8 &= ~0x400000u;
  *v0 &= ~0x200000u;
  sub_100644(2);
  *v0 |= 0x200000u;
  result = sub_100644(2);
  *v0 |= 0x400000u;
  return result;
}

