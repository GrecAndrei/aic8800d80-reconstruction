// sub_1027D8 @ 0x1027d8, size 102 bytes
void __fastcall sub_1027D8()
{
  int *v0; // r3
  int *v1; // r2
  int *v2; // r1
  int *v3; // r3
  int v4; // r2

  sub_101600();
  v0 = (int *)off_102840;
  *(_DWORD *)off_102840 = dword_102844;
  *v0 |= 0x80000000;
  while ( *v0 < 0 )
    ;
  *v0 = dword_102848;
  v1 = (int *)off_102840;
  *v0 |= 0x80000000;
  while ( *v1 < 0 )
    ;
  *v1 = dword_10284C;
  v2 = (int *)off_102840;
  *v1 |= 0x80000000;
  while ( *v2 < 0 )
    ;
  sub_101DE8((unsigned int)*v2 >> 31, 2437, 2437, (unsigned int)*v2 >> 31, (unsigned int)*v2 >> 31, *v2 < 0);
  v3 = (int *)off_102854;
  v4 = dword_102858;
  *(_DWORD *)off_102850 = 12;
  *v3 = v4;
}
