// v23 annotated: sub_117DF4 @ 0x117df4
// Original: 117df4_sub_117DF4.c
// Primary struct: <unclustered>
//
// sub_117DF4 @ 0x117df4, size 90 bytes
int sub_117DF4()
{
  _BYTE *v0; // r8
  int v1; // r4
  int v2; // r7
  int v3; // r6
  int result; // r0

  v0 = off_117E50;
  sub_100200((int *)off_117E50, 0, 0x14u);
  sub_11E71C(v0);
  v1 = dword_117E54;
  v2 = dword_117E58;
  sub_11E71C(v0 + 8);
  v3 = v1 + 896;
  do
  {
    sub_100200((int *)v1, 0, 0xE0u);
    *(_BYTE *)(v1 + 94) = 5;
    *(_BYTE *)(v1 + 97) = 127;
    *(_DWORD *)(v1 + 52) = v2;
    *(_DWORD *)(v1 + 56) = v1;
    v1 += 224;
    result = list_push_tail(v0);
  }
  while ( v1 != v3 );
  v0[16] = -1;
  return result;
}

