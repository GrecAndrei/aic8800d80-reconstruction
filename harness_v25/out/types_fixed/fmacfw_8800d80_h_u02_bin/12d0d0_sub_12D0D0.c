// sub_12D0D0 @ 0x12d0d0, size 40 bytes
int sub_12D0D0()
{
  _DWORD *v0; // r0
  _DWORD *v1; // r3
  void *v2; // r1

  v0 = sub_12C954();
  v1 = off_12D0F8;
  v2 = off_12D0FC;
  *((_DWORD *)off_12D0F8 + 7) = v0;
  *(_DWORD *)(v1 + 0xc) = 0;
  *(_DWORD *)(v1 + 0x10) = 0;
  *(_DWORD *)(v1 + 0x4) = 0;
  *(_DWORD *)(v1 + 0x8) = 0;
  *(_DWORD *)(v1 + 0x14) = 0;
  *(_DWORD *)(v1 + 0x18) = 0;
  *(_DWORD *)(v1 + 0x24) = v2;
  return sub_12D00C(-1);
}

