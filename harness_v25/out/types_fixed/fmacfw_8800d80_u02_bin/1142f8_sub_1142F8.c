// sub_1142F8 @ 0x1142f8, size 24 bytes
int __fastcall sub_1142F8(int a1)
{
  _DWORD *v1; // r2
  _WORD *v2; // r1

  v1 = off_114310;
  v2 = off_114314;
  *((_DWORD *)off_114310 + 2) = a1;
  *(_DWORD *)(v1 + 0xc) = 0;
  *(_DWORD *)(v1 + 0x10) = 0;
  *(_DWORD *)(v1 + 0x14) = 0;
  *v1 = 0;
  *(_DWORD *)(v1 + 0x4) = 0;
  *(_DWORD *)(v2 + 0x18) = 0;
  return 1;
}

