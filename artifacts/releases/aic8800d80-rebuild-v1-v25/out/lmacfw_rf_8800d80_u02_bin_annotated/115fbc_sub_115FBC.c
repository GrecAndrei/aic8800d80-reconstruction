// fwstruct annotate: 115fbc_sub_115FBC.c
// sub_115FBC @ 0x115fbc, size 48 bytes
int sub_115FBC()
{
  int v0; // r4

  v0 = dword_115FEC;
  sub_100200((int *)dword_115FEC, 0, 0x20u);
  sub_11E71C(v0);
  sub_11E71C(v0 + 8);
  sub_11E71C(v0 + 16);
  return sub_11E71C(v0 + 24);
}

