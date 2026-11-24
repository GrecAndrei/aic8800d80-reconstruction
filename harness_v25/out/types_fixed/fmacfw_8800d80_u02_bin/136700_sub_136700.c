// sub_136700 @ 0x136700, size 42 bytes
_DWORD *sub_136700()
{
  _BYTE *v0; // r4
  int v1; // r3

  v0 = off_13672C;
  sub_100200((int *)off_13672C, 0, 0x24u);
  v1 = dword_136730;
  *(_DWORD *)(v0 + 0x3c) = 3;
  *((_DWORD *)v0 + 4) = 20000;
  *((_DWORD *)v0 + 6) = v1;
  *(_DWORD *)(v0 + 0x30) = 0;
  return sub_12CD34(7u, 0);
}

