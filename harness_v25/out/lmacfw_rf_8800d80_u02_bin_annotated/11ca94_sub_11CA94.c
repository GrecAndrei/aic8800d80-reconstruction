// fwstruct annotate: 11ca94_sub_11CA94.c
// sub_11CA94 @ 0x11ca94, size 40 bytes
int sub_11CA94()
{
  int result; // r0
  _DWORD *v1; // r3

  sub_100200((int *)dword_11CABC, 0, 0xCu);
  result = sub_11E1E4(2);
  v1 = off_11CAC0;
  *(_DWORD *)off_11CAC0 = dword_11CAC4;
  v1[2] = v1 + 5;
  v1[4] = 0;
  v1[1] = 0;
  return result;
}

