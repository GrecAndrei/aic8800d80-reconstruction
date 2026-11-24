// sub_10C750 @ 0x10c750, size 114 bytes
int *sub_10C750()
{
  int v0; // r4
  bool v1; // zf
  unsigned __int8 v2; // r1
  int **v3; // r4

  v0 = *((_DWORD *)off_10C7C4 + 23);
  sub_100200((int *)dword_10C7C8, 0, 0x28u);
  sub_100200((int *)dword_10C7CC, 0, 0x1E6Cu);
  if ( (*(_DWORD *)off_10C7D0 & 8) != 0 )
  {
    while ( (*(_DWORD *)off_10C7D0 & 0x10) == 0 )
      ;
    v3 = (int **)off_10C7D4;
  }
  else
  {
    v2 = v0 & 3;
    v1 = (v0 & 3) == 0;
    v3 = (int **)off_10C7D4;
    *(_DWORD *)off_10C7D0 |= 8u;
    if ( v1 )
      sub_100200(*v3, v2, 0x248u);
    *(_DWORD *)off_10C7D0 |= 0x10u;
  }
  (*v3)[145] = *(_DWORD *)off_10C7D8;
  return sub_10C698();
}

