// v23 annotated: sub_11FA5C @ 0x11fa5c
// Original: 11fa5c_sub_11FA5C.c
// Primary struct: <unclustered>
//
// sub_11FA5C @ 0x11fa5c, size 98 bytes
int sub_11FA5C()
{
  _BYTE *v0; // r8
  int v1; // r4
  int v2; // r7
  int v3; // r6
  int result; // r0

  v0 = off_11FAC0;
  memset_thunk((int *)off_11FAC0, 0, 0x18u);
  bt_xtal_init_check(v0);
  v1 = dword_11FAC4;
  v2 = dword_11FAC8;
  bt_xtal_init_check(v0 + 8);
  v3 = v1 + 5280;
  do
  {
    memset_thunk((int *)v1, 0, 0x528u);
    *(_DWORD *)(v1 + 52) = v2;
    *(_DWORD *)(v1 + 56) = v1;
    *(_BYTE *)(v1 + 106) = 5;
    *(_BYTE *)(v1 + 109) = 127;
    *(_BYTE *)(v1 + 110) = 127;
    v1 += 1320;
    result = list_push_tail(v0);
  }
  while ( v1 != v3 );
  v0[16] = -1;
  return result;
}

