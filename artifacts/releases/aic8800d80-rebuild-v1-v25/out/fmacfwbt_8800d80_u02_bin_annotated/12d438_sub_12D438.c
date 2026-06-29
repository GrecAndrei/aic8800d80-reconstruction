// fwstruct annotate: 12d438_sub_12D438.c
// sub_12D438 @ 0x12d438, size 40 bytes
int sub_12D438()
{
  _DWORD *v0; // r0
  _DWORD *v1; // r3
  int v2; // r1

  v0 = rf_cmd_dispatch_n_44a();
  v1 = off_12D460;
  v2 = dword_12D464;
  *((_DWORD *)off_12D460 + 7) = v0;
  v1[3] = 0;
  v1[4] = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[9] = v2;
  return sub_12D374(-1);
}

