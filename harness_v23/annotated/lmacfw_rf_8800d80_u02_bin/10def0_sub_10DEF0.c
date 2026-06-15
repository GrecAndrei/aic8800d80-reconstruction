// v23 annotated: sub_10DEF0 @ 0x10def0
// Original: 10def0_sub_10DEF0.c
// Primary struct: <unclustered>
//
// sub_10DEF0 @ 0x10def0, size 72 bytes
int sub_10DEF0()
{
  _DWORD *v0; // r3
  __int64 v1; // r0
  __int64 v2; // r0
  __int64 v3; // r0
  int v4; // r0

  while ( *((_DWORD *)off_10DF50 + 7) != 1 )
    ;
  v0 = off_10DF50;
  *((_DWORD *)off_10DF50 + 7) = 1;
  v1 = sub_12752C(v0[4]);
  v2 = sub_127620(v1, HIDWORD(v1), dword_10DF38, dword_10DF3C);
  v3 = sub_127874(v2, HIDWORD(v2), dword_10DF40, dword_10DF44);
  v4 = sub_1272B0(v3, HIDWORD(v3), dword_10DF48, dword_10DF4C);
  return sub_127BE4(v4);
}

