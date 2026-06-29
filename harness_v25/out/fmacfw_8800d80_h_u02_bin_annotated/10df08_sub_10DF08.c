// fwstruct annotate: 10df08_sub_10DF08.c
// sub_10DF08 @ 0x10df08, size 72 bytes
int sub_10DF08()
{
  _DWORD *v0; // r3
  __int64 v1; // r0
  __int64 v2; // r0
  __int64 v3; // r0
  int v4; // r0

  while ( *((_DWORD *)off_10DF68 + 7) != 1 )
    ;
  v0 = off_10DF68;
  *((_DWORD *)off_10DF68 + 7) = 1;
  v1 = sub_142874(v0[4]);
  v2 = sub_142968(v1, HIDWORD(v1), dword_10DF50, dword_10DF54);
  v3 = sub_142BBC(v2, HIDWORD(v2), dword_10DF58, dword_10DF5C);
  v4 = sub_1425F8(v3, HIDWORD(v3), dword_10DF60, dword_10DF64);
  return sub_142F2C(v4);
}

