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
  *(_DWORD *)(v1 + 0xc) = 0;
  *(_DWORD *)(v1 + 0x10) = 0;
  *(_DWORD *)(v1 + 0x4) = 0;
  *(_DWORD *)(v1 + 0x8) = 0;
  *(_DWORD *)(v1 + 0x14) = 0;
  *(_DWORD *)(v1 + 0x18) = 0;
  *(_DWORD *)(v1 + 0x24) = v2;
  return sub_11E628(-1);
}

