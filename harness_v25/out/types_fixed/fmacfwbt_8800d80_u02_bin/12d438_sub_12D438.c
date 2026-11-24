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
  *(_DWORD *)(v1 + 0xc) = 0;
  *(_DWORD *)(v1 + 0x10) = 0;
  *(_DWORD *)(v1 + 0x4) = 0;
  *(_DWORD *)(v1 + 0x8) = 0;
  *(_DWORD *)(v1 + 0x14) = 0;
  *(_DWORD *)(v1 + 0x18) = 0;
  *(_DWORD *)(v1 + 0x24) = v2;
  return sub_12D374(-1);
}

