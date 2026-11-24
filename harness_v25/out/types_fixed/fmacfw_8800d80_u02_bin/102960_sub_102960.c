// sub_102960 @ 0x102960, size 102 bytes
void __fastcall sub_102960()
{
  int *v0; // r3
  int *v1; // r2
  int *v2; // r1
  int *v3; // r3
  int v4; // r2

  sub_101754();
  v0 = (int *)off_1029C8;
  *(_DWORD *)off_1029C8 = dword_1029CC;
  *v0 |= 0x80000000;
  while ( *v0 < 0 )
    ;
  *v0 = dword_1029D0;
  v1 = (int *)off_1029C8;
  *v0 |= 0x80000000;
  while ( *v1 < 0 )
    ;
  *v1 = dword_1029D4;
  v2 = (int *)off_1029C8;
  *v1 |= 0x80000000;
  while ( *v2 < 0 )
    ;
  sub_101F70((unsigned int)*v2 >> 31, 2437, 2437, (unsigned int)*v2 >> 31);
  v3 = (int *)off_1029DC;
  v4 = dword_1029E0;
  *(_DWORD *)off_1029D8 = 12;
  *v3 = v4;
}
