// v23 annotated: sub_103900 @ 0x103900
// Original: 103900_sub_103900.c
// Primary struct: <unclustered>
//
// sub_103900 @ 0x103900, size 86 bytes
int sub_103900()
{
  int *v0; // r4
  int v1; // r0
  int v2; // r1
  int *v3; // r3
  int v4; // r1
  _DWORD *v5; // r2
  int v6; // r0

  v0 = (int *)off_10395C;
  *(_DWORD *)off_103958 = 777;
  while ( *v0 < 0 )
    sub_100560(1);
  sub_11F504(dword_103960, *(_DWORD *)off_10395C);
  v1 = dword_103964;
  *(_DWORD *)off_103958 = 0;
  sub_11F504(v1, v2);
  v3 = (int *)off_10396C;
  v4 = dword_103970;
  v5 = off_103974;
  *(_DWORD *)off_103968 = 0;
  *v3 = v4;
  v6 = dword_103978;
  *v5 &= 0xFF00FFFF;
  return sub_11F504(v6, 0x4000);
}

