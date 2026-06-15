// sub_12B170 @ 0x12b170, size 40 bytes
int sub_12B170()
{
  int result; // r0
  _DWORD *v1; // r3

  memset_thunk((int *)dword_12B198, 0, 0xCu);
  result = sub_12CD34(2);
  v1 = off_12B19C;
  *(_DWORD *)off_12B19C = dword_12B1A0;
  v1[2] = v1 + 5;
  v1[4] = 0;
  v1[1] = 0;
  return result;
}

