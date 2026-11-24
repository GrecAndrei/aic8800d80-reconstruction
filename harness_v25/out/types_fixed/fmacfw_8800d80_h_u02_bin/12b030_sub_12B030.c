// sub_12B030 @ 0x12b030, size 40 bytes
int sub_12B030()
{
  int result; // r0
  _DWORD *v1; // r3

  sub_100200((int *)dword_12B058, 0, 0xCu);
  result = sub_12CBF4(2);
  v1 = off_12B05C;
  *(_DWORD *)off_12B05C = dword_12B060;
  *(_DWORD *)(v1 + 0x8) = v1 + 5;
  *(_DWORD *)(v1 + 0x10) = 0;
  *(_DWORD *)(v1 + 0x4) = 0;
  return result;
}

