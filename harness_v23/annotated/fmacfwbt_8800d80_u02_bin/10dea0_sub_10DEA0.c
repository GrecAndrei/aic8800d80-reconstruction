// v23 annotated: sub_10DEA0 @ 0x10dea0
// Original: 10dea0_sub_10DEA0.c
// Primary struct: <unclustered>
//
// sub_10DEA0 @ 0x10dea0, size 72 bytes
int sub_10DEA0()
{
  _DWORD *v0; // r3
  __int64 v1; // r0
  __int64 v2; // r0
  __int64 v3; // r0
  int v4; // r0

  while ( *((_DWORD *)off_10DF00 + 7) != 1 )
    ;
  v0 = off_10DF00;
  *((_DWORD *)off_10DF00 + 7) = 1;
  v1 = sub_142A50(v0[4]);
  v2 = sub_142B44(v1, HIDWORD(v1), dword_10DEE8, dword_10DEEC);
  v3 = sub_142D98(v2, HIDWORD(v2), dword_10DEF0, dword_10DEF4);
  v4 = sub_1427D4(v3, HIDWORD(v3), dword_10DEF8, dword_10DEFC);
  return sub_143108(v4);
}

