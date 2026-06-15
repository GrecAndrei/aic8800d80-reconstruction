// v23 annotated: sub_11F5E4 @ 0x11f5e4
// Original: 11f5e4_sub_11F5E4.c
// Primary struct: <unclustered>
//
// sub_11F5E4 @ 0x11f5e4, size 98 bytes
int sub_11F5E4()
{
  _BYTE *v0; // r8
  int v1; // r4
  int v2; // r7
  int v3; // r6
  int result; // r0

  v0 = off_11F648;
  sub_100200((int *)off_11F648, 0, 0x18u);
  sub_12D100(v0);
  v1 = dword_11F64C;
  v2 = dword_11F650;
  sub_12D100(v0 + 8);
  v3 = v1 + 5280;
  do
  {
    sub_100200((int *)v1, 0, 0x528u);
    *(_DWORD *)(v1 + 52) = v2;
    *(_DWORD *)(v1 + 56) = v1;
    *(_BYTE *)(v1 + 106) = 5;
    *(_BYTE *)(v1 + 109) = 127;
    *(_BYTE *)(v1 + 110) = 127;
    v1 += 1320;
    result = sub_12D108(v0);
  }
  while ( v1 != v3 );
  v0[16] = -1;
  return result;
}

