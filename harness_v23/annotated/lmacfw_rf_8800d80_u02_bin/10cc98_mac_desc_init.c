// v23 annotated: mac_desc_init @ 0x10cc98
// Original: 10cc98_mac_desc_init.c
// Primary struct: <unclustered>
//
// mac_desc_init @ 0x10cc98, size 114 bytes
// Doc: mac_desc_init [mac]: Initialize a 0x28-byte MAC descriptor/buffer entry
// mac_desc_init [mac]: Initialize a 0x28-byte MAC descriptor/buffer entry
int *mac_desc_init()
{
  int v0; // r4
  bool v1; // zf
  unsigned __int8 v2; // r1
  int **v3; // r4

  v0 = *((_DWORD *)off_10CD0C + 23);
  sub_100200((int *)dword_10CD10, 0, 0x28u);
  sub_100200((int *)dword_10CD14, 0, 0x17C4u);
  if ( (*(_DWORD *)off_10CD18 & 8) != 0 )
  {
    while ( (*(_DWORD *)off_10CD18 & 0x10) == 0 )
      ;
    v3 = (int **)off_10CD1C;
  }
  else
  {
    v2 = v0 & 3;
    v1 = (v0 & 3) == 0;
    v3 = (int **)off_10CD1C;
    *(_DWORD *)off_10CD18 |= 8u;
    if ( v1 )
      sub_100200(*v3, v2, 0x258u);
    *(_DWORD *)off_10CD18 |= 0x10u;
  }
  (*v3)[149] = *(_DWORD *)off_10CD20;
  return sub_10CBE0();
}

