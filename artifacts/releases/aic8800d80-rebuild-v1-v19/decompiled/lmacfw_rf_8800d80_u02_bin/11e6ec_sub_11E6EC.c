// sub_11E6EC @ 0x11e6ec, size 40 bytes
int sub_11E6EC()
{
  _DWORD *v0; // r0
  _DWORD *v1; // r3
  int v2; // r1

  v0 = sub_11DF44();
  v1 = off_11E714;
  v2 = dword_11E718;
  *((_DWORD *)off_11E714 + 7) = v0;
  v1[3] = 0;
  v1[4] = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[9] = v2;
  return sub_11E628(-1);
}

