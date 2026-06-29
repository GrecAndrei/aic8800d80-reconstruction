// fwstruct annotate: 12b030_sub_12B030.c
// sub_12B030 @ 0x12b030, size 40 bytes
int sub_12B030()
{
  int result; // r0
  _DWORD *v1; // r3

  sub_100200((int *)dword_12B058, 0, 0xCu);
  result = sub_12CBF4(2);
  v1 = off_12B05C;
  *(_DWORD *)off_12B05C = dword_12B060;
  v1[2] = v1 + 5;
  v1[4] = 0;
  v1[1] = 0;
  return result;
}

