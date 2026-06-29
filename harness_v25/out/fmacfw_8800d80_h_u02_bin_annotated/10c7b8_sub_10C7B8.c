// fwstruct annotate: 10c7b8_sub_10C7B8.c
// sub_10C7B8 @ 0x10c7b8, size 114 bytes
int *sub_10C7B8()
{
  int v0; // r4
  bool v1; // zf
  unsigned __int8 v2; // r1
  int **v3; // r4

  v0 = *((_DWORD *)off_10C82C + 23);
  sub_100200((int *)dword_10C830, 0, 0x28u);
  sub_100200((int *)dword_10C834, 0, 0x1E6Cu);
  if ( (*(_DWORD *)off_10C838 & 8) != 0 )
  {
    while ( (*(_DWORD *)off_10C838 & 0x10) == 0 )
      ;
    v3 = (int **)off_10C83C;
  }
  else
  {
    v2 = v0 & 3;
    v1 = (v0 & 3) == 0;
    v3 = (int **)off_10C83C;
    *(_DWORD *)off_10C838 |= 8u;
    if ( v1 )
      sub_100200(*v3, v2, 0x288u);
    *(_DWORD *)off_10C838 |= 0x10u;
  }
  (*v3)[161] = *(_DWORD *)off_10C840;
  return sub_10C700();
}

