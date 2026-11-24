// sub_11CA94 @ 0x11ca94, size 40 bytes
int sub_11CA94()
{
  int result; // r0
  _DWORD *v1; // r3

  sub_100200((int *)dword_11CABC, 0, 0xCu);
  result = sub_11E1E4(2);
  v1 = off_11CAC0;
  *(_DWORD *)off_11CAC0 = dword_11CAC4;
  *(_DWORD *)(v1 + 0x8) = v1 + 5;
  *(_DWORD *)(v1 + 0x10) = 0;
  *(_DWORD *)(v1 + 0x4) = 0;
  return result;
}

