// v23 annotated: sub_11176C @ 0x11176c
// Original: 11176c_sub_11176C.c
// Primary struct: <unclustered>
//
// sub_11176C @ 0x11176c, size 74 bytes
int sub_11176C()
{
  _DWORD *v0; // r1
  int v1; // r0
  _DWORD *v2; // r3
  int result; // r0

  v0 = *(_DWORD **)off_1117B8;
  v1 = *(_DWORD *)off_1117BC;
  v2 = off_1117C0;
  *((_WORD *)off_1117C4 + 5) = 0;
  *v0 = 167772160;
  v0[1] = v1;
  v2[4] = v2[4] & 0xFFFFF81F | 0x20;
  do
    result = v2[4] & 0x20;
  while ( result );
  v2[578] = v2[578];
  v2[581] = v0;
  v2[576] |= 0x84000000;
  return result;
}

