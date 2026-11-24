// sub_1028B0 @ 0x1028b0, size 102 bytes
int sub_1028B0()
{
  int *v0; // r3
  int *v1; // r2
  int *v2; // r1
  int *v3; // r3
  int v4; // r2

  sub_1016A8();
  v0 = (int *)off_102918;
  *(_DWORD *)off_102918 = dword_10291C;
  *v0 |= 0x80000000;
  while ( *v0 < 0 )
    ;
  *v0 = dword_102920;
  v1 = (int *)off_102918;
  *v0 |= 0x80000000;
  while ( *v1 < 0 )
    ;
  *v1 = dword_102924;
  v2 = (int *)off_102918;
  *v1 |= 0x80000000;
  while ( *v2 < 0 )
    ;
  sub_101EC0((unsigned int)*v2 >> 31, 0x985u, 0x985u, (unsigned int)*v2 >> 31, *v2 < 0, *v2 < 0);
  v3 = (int *)off_10292C;
  v4 = dword_102930;
  *(_DWORD *)off_102928 = 12;
  *v3 = v4;
  return 12;
}

