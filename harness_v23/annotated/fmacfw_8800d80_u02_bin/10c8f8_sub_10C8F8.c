// v23 annotated: sub_10C8F8 @ 0x10c8f8
// Original: 10c8f8_sub_10C8F8.c
// Primary struct: <unclustered>
//
// sub_10C8F8 @ 0x10c8f8, size 114 bytes
int *sub_10C8F8()
{
  int v0; // r4
  bool v1; // zf
  unsigned __int8 v2; // r1
  int **v3; // r4

  v0 = *((_DWORD *)off_10C96C + 23);
  sub_100200((int *)dword_10C970, 0, 0x28u);
  sub_100200((int *)dword_10C974, 0, 0x1E6Cu);
  if ( (*(_DWORD *)off_10C978 & 8) != 0 )
  {
    while ( (*(_DWORD *)off_10C978 & 0x10) == 0 )
      ;
    v3 = (int **)off_10C97C;
  }
  else
  {
    v2 = v0 & 3;
    v1 = (v0 & 3) == 0;
    v3 = (int **)off_10C97C;
    *(_DWORD *)off_10C978 |= 8u;
    if ( v1 )
      sub_100200(*v3, v2, 0x288u);
    *(_DWORD *)off_10C978 |= 0x10u;
  }
  (*v3)[161] = *(_DWORD *)off_10C980;
  return sub_10C840();
}

