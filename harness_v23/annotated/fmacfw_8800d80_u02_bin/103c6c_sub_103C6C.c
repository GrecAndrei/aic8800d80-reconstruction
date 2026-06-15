// v23 annotated: sub_103C6C @ 0x103c6c
// Original: 103c6c_sub_103C6C.c
// Primary struct: <unclustered>
//
// sub_103C6C @ 0x103c6c, size 50 bytes
int sub_103C6C()
{
  _DWORD *v0; // r4
  int result; // r0

  v0 = off_103CA0;
  *(_DWORD *)off_103CA0 &= ~0x400000u;
  *v0 &= ~0x200000u;
  sub_100644(2);
  *v0 |= 0x200000u;
  result = sub_100644(2);
  *v0 |= 0x400000u;
  return result;
}

