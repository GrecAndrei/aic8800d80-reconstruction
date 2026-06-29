// fwstruct annotate: 123194_sub_123194.c
// sub_123194 @ 0x123194, size 56 bytes
int __fastcall sub_123194(int a1, int a2, int a3, int a4)
{
  _BYTE *v4; // r4
  unsigned int v5; // r0

  v4 = (_BYTE *)sub_12C92C(133, a4, a3, 1);
  v5 = sub_10ED84(dword_1231CC, 1);
  *v4 = (BYTE2(v5) ^ 1) & 1;
  sub_12EA88(dword_1231D0, v5, HIWORD(v5) & 1);
  sub_12C98C(v4);
  return 0;
}

