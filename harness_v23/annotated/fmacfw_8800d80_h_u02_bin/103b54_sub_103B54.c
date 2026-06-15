// v23 annotated: sub_103B54 @ 0x103b54
// Original: 103b54_sub_103B54.c
// Primary struct: <unclustered>
//
// sub_103B54 @ 0x103b54, size 50 bytes
int sub_103B54()
{
  _DWORD *v0; // r4
  int result; // r0

  v0 = off_103B88;
  *(_DWORD *)off_103B88 &= ~0x400000u;
  *v0 &= ~0x200000u;
  sub_100644(2);
  *v0 |= 0x200000u;
  result = sub_100644(2);
  *v0 |= 0x400000u;
  return result;
}

