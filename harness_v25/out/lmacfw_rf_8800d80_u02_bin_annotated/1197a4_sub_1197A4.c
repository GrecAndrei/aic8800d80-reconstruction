// fwstruct annotate: 1197a4_sub_1197A4.c
// sub_1197A4 @ 0x1197a4, size 50 bytes
// Doc: sub_12197A4 [mac]: Initialize LMAC subsystem, allocate and populate context buffer
// sub_12197A4 [mac]: Initialize LMAC subsystem, allocate and populate context buffer
int __fastcall sub_1197A4(int a1, int a2, int a3, int a4)
{
  _BYTE *v4; // r4
  int v5; // r1
  int v6; // r3

  v4 = (_BYTE *)rf_setup_dispatch(129, a4, a3, 64);
  v5 = dword_1197D8;
  *v4 = 0;
  sub_1282E8(v4 + 1, v5, 36);
  v6 = (unsigned __int8)(*v4 + 36);
  *v4 = v6;
  v4[v6 + 1] = 0;
  sub_11DE50(v4);
  return 0;
}

