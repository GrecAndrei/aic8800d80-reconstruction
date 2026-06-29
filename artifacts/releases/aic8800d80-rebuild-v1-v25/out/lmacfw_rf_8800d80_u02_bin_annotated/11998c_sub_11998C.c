// fwstruct annotate: 11998c_sub_11998C.c
// sub_11998C @ 0x11998c, size 56 bytes
int __fastcall sub_11998C(int a1, int a2, int a3, int a4)
{
  _BYTE *v4; // r4
  int v5; // r0

  v4 = (_BYTE *)rf_setup_dispatch(133, a4, a3, 1);
  v5 = sub_10EFBC(dword_1199C4, 1);
  *v4 = (BYTE2(v5) ^ 1) & 1;
  msg_parse(dword_1199C8, v5);
  sub_11DE50(v4);
  return 0;
}

