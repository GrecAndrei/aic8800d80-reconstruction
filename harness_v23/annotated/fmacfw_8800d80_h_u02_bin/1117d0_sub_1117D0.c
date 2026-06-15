// v23 annotated: sub_1117D0 @ 0x1117d0
// Original: 1117d0_sub_1117D0.c
// Primary struct: <unclustered>
//
// sub_1117D0 @ 0x1117d0, size 74 bytes
int sub_1117D0()
{
  _DWORD *v0; // r1
  int v1; // r0
  _DWORD *v2; // r3
  int result; // r0

  v0 = *(_DWORD **)off_11181C;
  v1 = *(_DWORD *)off_111820;
  v2 = off_111824;
  *((_WORD *)off_111828 + 5) = 0;
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

