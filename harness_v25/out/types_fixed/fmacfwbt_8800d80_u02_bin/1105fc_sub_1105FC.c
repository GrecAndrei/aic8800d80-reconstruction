// sub_1105FC @ 0x1105fc, size 52 bytes
int __fastcall sub_1105FC(int a1)
{
  _DWORD *v1; // r2
  _DWORD *v2; // r1

  v1 = off_110630;
  v2 = off_110634;
  *(_DWORD *)off_110630 = 0;
  *(_DWORD *)(v1 + 0x4) = 0;
  *(_DWORD *)(v1 + 0x8) = a1;
  *(_DWORD *)(v1 + 0xc) = 0;
  *(_DWORD *)(v1 + 0x10) = 0;
  *(_DWORD *)(v1 + 0x14) = 0;
  *v2 = 0;
  *(_DWORD *)(v2 + 0x4) = 0;
  *(_DWORD *)(v2 + 0x10) = 0;
  *(_DWORD *)(v2 + 0x14) = 0;
  *((_WORD *)v2 + 6) = 0;
  *(_DWORD *)(v2 + 0x8) = 0;
  *((_BYTE *)v2 + 14) = 0;
  *((_WORD *)v2 + 14) = 0;
  *(_DWORD *)(v2 + 0x18) = 0;
  *((_BYTE *)v2 + 30) = 0;
  sub_110494((int)v1, (int)v2);
  return 1;
}

